/**
 * @file main.c
 * @brief Main routine
 *
 * @section License
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * Copyright (C) 2010-2024 Oryx Embedded SARL. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * @author Oryx Embedded SARL (www.oryx-embedded.com)
 * @version 2.4.4
 **/

//Dependencies
#include <stdlib.h>
#include "sam.h"
#include "samv71_xplained_ultra.h"
#include "core/net.h"
#include "drivers/mac/samv71_eth_driver.h"
#include "drivers/phy/ksz8061_driver.h"
#include "dhcp/dhcp_client.h"
#include "ipv6/slaac.h"
#include "tls.h"
#include "tls_cipher_suites.h"
#include "tls_ticket.h"
#include "tls_misc.h"
#include "hardware/samv71/samv71_crypto.h"
#include "rng/trng.h"
#include "rng/yarrow.h"
#include "resource_manager.h"
#include "ext_int_driver.h"
#include "debug.h"

//Ethernet interface configuration
#define APP_IF_NAME "eth0"
#define APP_HOST_NAME "tls-server-demo"
#define APP_MAC_ADDR "00-AB-CD-EF-71-21"

#define APP_USE_DHCP_CLIENT ENABLED
#define APP_IPV4_HOST_ADDR "192.168.0.20"
#define APP_IPV4_SUBNET_MASK "255.255.255.0"
#define APP_IPV4_DEFAULT_GATEWAY "192.168.0.254"
#define APP_IPV4_PRIMARY_DNS "8.8.8.8"
#define APP_IPV4_SECONDARY_DNS "8.8.4.4"

#define APP_USE_SLAAC ENABLED
#define APP_IPV6_LINK_LOCAL_ADDR "fe80::7121"
#define APP_IPV6_PREFIX "2001:db8::"
#define APP_IPV6_PREFIX_LENGTH 64
#define APP_IPV6_GLOBAL_ADDR "2001:db8::7121"
#define APP_IPV6_ROUTER "fe80::1"
#define APP_IPV6_PRIMARY_DNS "2001:4860:4860::8888"
#define APP_IPV6_SECONDARY_DNS "2001:4860:4860::8844"

//Application configuration
#define APP_SERVER_PORT 443
#define APP_SERVER_MAX_CONNECTIONS 4
#define APP_SERVER_TIMEOUT 10000
#define APP_SERVER_CERT "certs/server_cert.pem"
#define APP_SERVER_KEY "certs/server_key.pem"
#define APP_CA_CERT "certs/ca_cert.pem"

//Global variables
uint_t hitCounter = 0;

OsSemaphore connectionSemaphore;
DhcpClientSettings dhcpClientSettings;
DhcpClientContext dhcpClientContext;
SlaacSettings slaacSettings;
SlaacContext slaacContext;
TlsCache *tlsCache;
TlsTicketContext tlsTicketContext;
YarrowContext yarrowContext;
uint8_t seed[32];

//Forward declaration of functions
void tlsServerTask(void *param);
void tlsClientTask(void *param);
size_t dumpArray(char_t *buffer, const uint8_t *data, size_t length);


/**
 * @brief MPU configuration
 **/

void mpuConfig(void)
{
   //Disable fault exceptions
   SCB->SHCSR &= ~SCB_SHCSR_MEMFAULTENA_Msk;
   //Disable the MPU
   MPU->CTRL &= ~MPU_CTRL_ENABLE_Msk;

   //Configure the first region (SRAM)
   MPU->RNR = 0;
   //Set region base address
   MPU->RBAR = 0x20400000;

   //Set MPU region attributes
   MPU->RASR = (0 << MPU_RASR_XN_Pos) | //Instruction fetches enabled
      (3 << MPU_RASR_AP_Pos) |          //Full access permission
      (1 << MPU_RASR_TEX_Pos) |         //TEX level 1
      (0 << MPU_RASR_S_Pos) |           //Not shareable
      (1 << MPU_RASR_C_Pos) |           //Cacheable
      (1 << MPU_RASR_B_Pos) |           //Bufferable
      (0 << MPU_RASR_SRD_Pos) |         //All sub-regions enabled
      (18 << MPU_RASR_SIZE_Pos) |       //Region size (512KB)
      (1 << MPU_RASR_ENABLE_Pos);       //Region enabled

   //Configure the second region (non-cacheable SRAM)
   MPU->RNR = 1;
   //Set region base address
   MPU->RBAR = 0x20458000;

   //Set MPU region attributes
   MPU->RASR = (1 << MPU_RASR_XN_Pos) | //Instruction fetches disabled
      (3 << MPU_RASR_AP_Pos) |          //Full access permission
      (1 << MPU_RASR_TEX_Pos) |         //TEX level 1
      (1 << MPU_RASR_S_Pos) |           //Shareable
      (0 << MPU_RASR_C_Pos) |           //Not cacheable
      (0 << MPU_RASR_B_Pos) |           //Not bufferable
      (0 << MPU_RASR_SRD_Pos) |         //All sub-regions enabled
      (14 << MPU_RASR_SIZE_Pos) |       //Region size (32KB)
      (1 << MPU_RASR_ENABLE_Pos);       //Region enabled

   //Enable the MPU
   MPU->CTRL = MPU_CTRL_PRIVDEFENA_Msk | MPU_CTRL_ENABLE_Msk;
   //Enable fault exceptions
   SCB->SHCSR |= SCB_SHCSR_MEMFAULTENA_Msk;
}


/**
 * @brief I/O initialization
 **/

void ioInit(void)
{
   //Disable write protection
   MATRIX_REGS->MATRIX_WPMR = MATRIX_WPMR_WPKEY_PASSWD;
   //Select PB12 function rather than ERASE function
   MATRIX_REGS->CCFG_SYSIO |= CCFG_SYSIO_SYSIO12_Msk;

   //Enable PIO peripheral clocks
   PMC_REGS->PMC_PCER0 = (1 << ID_PIOA) | (1 << ID_PIOB) | (1 << ID_PIOC);

   //Configure LED0
   PIO_LED0->PIO_PER = LED0;
   PIO_LED0->PIO_OER = LED0;
   PIO_LED0->PIO_SODR = LED0;

   //Configure LED1
   PIO_LED1->PIO_PER = LED1;
   PIO_LED1->PIO_OER = LED1;
   PIO_LED1->PIO_SODR = LED1;

   //Configure SW0 button
   PIO_SW0->PIO_PER = SW0;
   PIO_SW0->PIO_ODR = SW0;
   PIO_SW0->PIO_PUER = SW0;

   //Configure SW1 button
   PIO_SW1->PIO_PER = SW1;
   PIO_SW1->PIO_ODR = SW1;
   PIO_SW1->PIO_PUER = SW1;
}


/**
 * @brief LED task
 * @param[in] param Unused parameter
 **/

void ledTask(void *param)
{
   //Endless loop
   while(1)
   {
      PIO_LED0->PIO_CODR = LED0;
      osDelayTask(100);
      PIO_LED0->PIO_SODR = LED0;
      osDelayTask(900);
   }
}


/**
 * @brief Main entry point
 * @return Unused value
 **/

int_t main(void)
{
   error_t error;
   OsTaskId taskId;
   OsTaskParameters taskParams;
   NetInterface *interface;
   MacAddr macAddr;
#if (APP_USE_DHCP_CLIENT == DISABLED)
   Ipv4Addr ipv4Addr;
#endif
#if (APP_USE_SLAAC == DISABLED)
   Ipv6Addr ipv6Addr;
#endif

   //Disable watchdog timer
   WDT_REGS->WDT_MR = WDT_MR_WDDIS_Msk;

   //MPU configuration
   mpuConfig();

   //Enable I-cache and D-cache
   SCB_EnableICache();
   SCB_EnableDCache();

   //Update system core clock
   SystemCoreClockUpdate();

   //Initialize kernel
   osInitKernel();
   //Configure debug UART
   debugInit(115200);

   //Start-up message
   TRACE_INFO("\r\n");
   TRACE_INFO("**********************************\r\n");
   TRACE_INFO("*** CycloneSSL TLS Server Demo ***\r\n");
   TRACE_INFO("**********************************\r\n");
   TRACE_INFO("Copyright: 2010-2024 Oryx Embedded SARL\r\n");
   TRACE_INFO("Compiled: %s %s\r\n", __DATE__, __TIME__);
   TRACE_INFO("Target: SAMV71\r\n");
   TRACE_INFO("\r\n");

   //Configure I/Os
   ioInit();

   //Initialize hardware cryptographic accelerator
   error = samv71CryptoInit();
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize hardware crypto accelerator!\r\n");
   }

   //Generate a random seed
   error = trngGetRandomData(seed, sizeof(seed));
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to generate random data!\r\n");
   }

   //PRNG initialization
   error = yarrowInit(&yarrowContext);
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize PRNG!\r\n");
   }

   //Properly seed the PRNG
   error = yarrowSeed(&yarrowContext, seed, sizeof(seed));
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to seed PRNG!\r\n");
   }

   //TCP/IP stack initialization
   error = netInit();
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize TCP/IP stack!\r\n");
   }

   //Configure the first Ethernet interface
   interface = &netInterface[0];

   //Set interface name
   netSetInterfaceName(interface, APP_IF_NAME);
   //Set host name
   netSetHostname(interface, APP_HOST_NAME);
   //Set host MAC address
   macStringToAddr(APP_MAC_ADDR, &macAddr);
   netSetMacAddr(interface, &macAddr);
   //Select the relevant network adapter
   netSetDriver(interface, &samv71EthDriver);
   netSetPhyDriver(interface, &ksz8061PhyDriver);
   //Set external interrupt line driver
   netSetExtIntDriver(interface, &extIntDriver);

   //Initialize network interface
   error = netConfigInterface(interface);
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to configure interface %s!\r\n", interface->name);
   }

#if (IPV4_SUPPORT == ENABLED)
#if (APP_USE_DHCP_CLIENT == ENABLED)
   //Get default settings
   dhcpClientGetDefaultSettings(&dhcpClientSettings);
   //Set the network interface to be configured by DHCP
   dhcpClientSettings.interface = interface;
   //Disable rapid commit option
   dhcpClientSettings.rapidCommit = FALSE;

   //DHCP client initialization
   error = dhcpClientInit(&dhcpClientContext, &dhcpClientSettings);
   //Failed to initialize DHCP client?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize DHCP client!\r\n");
   }

   //Start DHCP client
   error = dhcpClientStart(&dhcpClientContext);
   //Failed to start DHCP client?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start DHCP client!\r\n");
   }
#else
   //Set IPv4 host address
   ipv4StringToAddr(APP_IPV4_HOST_ADDR, &ipv4Addr);
   ipv4SetHostAddr(interface, ipv4Addr);

   //Set subnet mask
   ipv4StringToAddr(APP_IPV4_SUBNET_MASK, &ipv4Addr);
   ipv4SetSubnetMask(interface, ipv4Addr);

   //Set default gateway
   ipv4StringToAddr(APP_IPV4_DEFAULT_GATEWAY, &ipv4Addr);
   ipv4SetDefaultGateway(interface, ipv4Addr);

   //Set primary and secondary DNS servers
   ipv4StringToAddr(APP_IPV4_PRIMARY_DNS, &ipv4Addr);
   ipv4SetDnsServer(interface, 0, ipv4Addr);
   ipv4StringToAddr(APP_IPV4_SECONDARY_DNS, &ipv4Addr);
   ipv4SetDnsServer(interface, 1, ipv4Addr);
#endif
#endif

#if (IPV6_SUPPORT == ENABLED)
#if (APP_USE_SLAAC == ENABLED)
   //Get default settings
   slaacGetDefaultSettings(&slaacSettings);
   //Set the network interface to be configured
   slaacSettings.interface = interface;

   //SLAAC initialization
   error = slaacInit(&slaacContext, &slaacSettings);
   //Failed to initialize SLAAC?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize SLAAC!\r\n");
   }

   //Start IPv6 address autoconfiguration process
   error = slaacStart(&slaacContext);
   //Failed to start SLAAC process?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start SLAAC!\r\n");
   }
#else
   //Set link-local address
   ipv6StringToAddr(APP_IPV6_LINK_LOCAL_ADDR, &ipv6Addr);
   ipv6SetLinkLocalAddr(interface, &ipv6Addr);

   //Set IPv6 prefix
   ipv6StringToAddr(APP_IPV6_PREFIX, &ipv6Addr);
   ipv6SetPrefix(interface, 0, &ipv6Addr, APP_IPV6_PREFIX_LENGTH);

   //Set global address
   ipv6StringToAddr(APP_IPV6_GLOBAL_ADDR, &ipv6Addr);
   ipv6SetGlobalAddr(interface, 0, &ipv6Addr);

   //Set default router
   ipv6StringToAddr(APP_IPV6_ROUTER, &ipv6Addr);
   ipv6SetDefaultRouter(interface, 0, &ipv6Addr);

   //Set primary and secondary DNS servers
   ipv6StringToAddr(APP_IPV6_PRIMARY_DNS, &ipv6Addr);
   ipv6SetDnsServer(interface, 0, &ipv6Addr);
   ipv6StringToAddr(APP_IPV6_SECONDARY_DNS, &ipv6Addr);
   ipv6SetDnsServer(interface, 1, &ipv6Addr);
#endif
#endif

   //Set task parameters
   taskParams = OS_TASK_DEFAULT_PARAMS;
   taskParams.stackSize = 500;
   taskParams.priority = OS_TASK_PRIORITY_NORMAL;

   //Create a task to handle incoming requests
   taskId = osCreateTask("TLS Server", tlsServerTask, NULL, &taskParams);
   //Failed to create the task?
   if(taskId == OS_INVALID_TASK_ID)
   {
      //Debug message
      TRACE_ERROR("Failed to create task!\r\n");
   }

   //Set task parameters
   taskParams = OS_TASK_DEFAULT_PARAMS;
   taskParams.stackSize = 200;
   taskParams.priority = OS_TASK_PRIORITY_NORMAL;

   //Create a task to blink the LED
   taskId = osCreateTask("LED", ledTask, NULL, &taskParams);
   //Failed to create the task?
   if(taskId == OS_INVALID_TASK_ID)
   {
      //Debug message
      TRACE_ERROR("Failed to create task!\r\n");
   }

   //Start the execution of tasks
   osStartKernel();

   //This function should never return
   return 0;
}


/**
 * @brief TLS server task
 * @param param[in] Not used
 **/

void tlsServerTask(void *param)
{
   error_t error;
   uint_t counter;
   uint16_t clientPort;
   IpAddr clientIpAddr;
   Socket *serverSocket;
   Socket *clientSocket;
   OsTaskId taskId;
   OsTaskParameters taskParams;

   //Create a semaphore to limit the number of simultaneous connections
   if(!osCreateSemaphore(&connectionSemaphore, APP_SERVER_MAX_CONNECTIONS))
   {
      //Debug message
      TRACE_ERROR("Failed to create semaphore!\r\n");
   }

   //TLS session cache initialization
   tlsCache = tlsInitCache(16);
   //Failed to initialize TLS cache?
   if(tlsCache == NULL)
   {
      //Debug message
      TRACE_ERROR("TLS cache initialization failed!\r\n");
   }

#if (TLS_TICKET_SUPPORT == ENABLED)
   //Initialize ticket encryption context
   error = tlsInitTicketContext(&tlsTicketContext);
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to bind socket!\r\n");
   }
#endif

   //Open a socket
   serverSocket = socketOpen(SOCKET_TYPE_STREAM, SOCKET_IP_PROTO_TCP);
   //Failed to open socket?
   if(!serverSocket)
   {
      //Debug message
      TRACE_ERROR("Cannot open socket!\r\n");
   }

   //Bind newly created socket to port 443
   error = socketBind(serverSocket, &IP_ADDR_ANY, APP_SERVER_PORT);
   //Failed to bind socket to port 443?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to bind socket!\r\n");
   }

   //Place socket in listening state
   error = socketListen(serverSocket, 0);
   //Any failure to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to enter listening state!\r\n");
   }

   //Process incoming connections to the server
   for(counter = 1; ; counter++)
   {
      //Debug message
      TRACE_INFO("\r\n\r\n");
      TRACE_INFO("Waiting for an incoming connection...\r\n\r\n");

      //Limit the number of simultaneous connections to the HTTP server
      osWaitForSemaphore(&connectionSemaphore, INFINITE_DELAY);

      //Accept an incoming connection
      clientSocket = socketAccept(serverSocket, &clientIpAddr, &clientPort);

      //Make sure the socket handle is valid
      if(clientSocket != NULL)
      {
         //Debug message
         TRACE_INFO("Connection #%u established with client %s port %" PRIu16 "...\r\n",
            counter, ipAddrToString(&clientIpAddr, NULL), clientPort);

         //Set task parameters
         taskParams = OS_TASK_DEFAULT_PARAMS;
         taskParams.stackSize = 800;
         taskParams.priority = OS_TASK_PRIORITY_NORMAL;

         //Create a task to service the client connection
         taskId = osCreateTask("TLS Client", tlsClientTask, clientSocket, &taskParams);

         //Did we encounter an error?
         if(taskId == OS_INVALID_TASK_ID)
         {
            //Debug message
            TRACE_ERROR("Failed to create task!\r\n");

            //Close socket
            socketClose(clientSocket);
            //Release semaphore
            osReleaseSemaphore(&connectionSemaphore);
         }
      }
   }
}


/**
 * @brief TLS client task
 * @param param[in] Client socket
 **/

void tlsClientTask(void *param)
{
   error_t error;
   size_t n;
   const char_t *serverCert;
   size_t serverCertLen;
   const char_t *serverKey;
   size_t serverKeyLen;
   const char_t *trustedCaList;
   size_t trustedCaListLen;
   Socket *clientSocket;
   TlsContext *tlsContext;
   char_t buffer[512];

   //Variable initialization
   tlsContext = NULL;

   //Retrieve socket handle
   clientSocket = (Socket *) param;

   //Start of exception handling block
   do
   {
      //Set timeout
      error = socketSetTimeout(clientSocket, APP_SERVER_TIMEOUT);
      //Any error to report?
      if(error)
         break;

      //TLS context initialization
      tlsContext = tlsInit();
      //Failed to initialize TLS context?
      if(tlsContext == NULL)
      {
         //Report an error
         error = ERROR_OUT_OF_MEMORY;
         //Exit immediately
         break;
      }

      //Select server operation mode
      error = tlsSetConnectionEnd(tlsContext, TLS_CONNECTION_END_SERVER);
      //Any error to report?
      if(error)
         break;

      //Bind TLS to the relevant socket
      error = tlsSetSocket(tlsContext, clientSocket);
      //Any error to report?
      if(error)
         break;

      //Set TX and RX buffer size
      error = tlsSetBufferSize(tlsContext, 4096, 4096);
      //Any error to report?
      if(error)
         break;

      //Set the PRNG algorithm to be used
      error = tlsSetPrng(tlsContext, YARROW_PRNG_ALGO, &yarrowContext);
      //Any error to report?
      if(error)
         break;

      //Session cache that will be used to save/resume TLS sessions
      error = tlsSetCache(tlsContext, tlsCache);
      //Any error to report?
      if(error)
         break;

#if (TLS_TICKET_SUPPORT == ENABLED)
      //Enable session ticket mechanism
      error = tlsSetTicketCallbacks(tlsContext, tlsEncryptTicket,
         tlsDecryptTicket, &tlsTicketContext);
      //Any error to report?
      if(error)
         break;
#endif

      //Client authentication is not required
      error = tlsSetClientAuthMode(tlsContext, TLS_CLIENT_AUTH_NONE);
      //Any error to report?
      if(error)
         break;

      //Enable secure renegotiation
      error = tlsEnableSecureRenegotiation(tlsContext, TRUE);
      //Any error to report?
      if(error)
         break;

      //Get server's certificate
      error = resGetData(APP_SERVER_CERT, (const uint8_t **) &serverCert,
         &serverCertLen);
      //Any error to report?
      if(error)
         break;

      //Get server's private key
      error = resGetData(APP_SERVER_KEY, (const uint8_t **) &serverKey,
         &serverKeyLen);
      //Any error to report?
      if(error)
         break;

      //Load server's certificate
      error = tlsLoadCertificate(tlsContext, 0, serverCert, serverCertLen,
         serverKey, serverKeyLen, NULL);
      //Any error to report?
      if(error)
         break;

      //Get the list of trusted CA certificates
      error = resGetData(APP_CA_CERT, (const uint8_t **) &trustedCaList,
         &trustedCaListLen);
      //Any error to report?
      if(error)
         break;

      //Import the list of trusted CA certificates
      error = tlsSetTrustedCaList(tlsContext, trustedCaList, trustedCaListLen);
      //Any error to report?
      if(error)
         break;

      //Establish a secure session
      error = tlsConnect(tlsContext);
      //TLS handshake failure?
      if(error)
         break;

      //Debug message
      TRACE_INFO("\r\n");
      TRACE_INFO("HTTP request:\r\n");

      //Read HTTP request
      while(1)
      {
         //Read a complete line
         error = tlsRead(tlsContext, buffer, sizeof(buffer) - 1, &n,
            TLS_FLAG_BREAK_CRLF);
         //Any error to report?
         if(error)
            break;

         //Properly terminate the string with a NULL character
         buffer[n] = '\0';
         //Dump HTTP request
         TRACE_INFO("%s", buffer);

         //The end of the header has been reached?
         if(!strcmp(buffer, "\r\n"))
            break;
      }

      //Propagate exception if necessary
      if(error)
         break;

      //Debug message
      TRACE_INFO("HTTP response:\r\n");

      //Format response
      n = 0;
      n += sprintf(buffer + n, "HTTP/1.0 200 OK\r\n");
      n += sprintf(buffer + n, "Content-Type: text/html\r\n");
      n += sprintf(buffer + n, "\r\n");

      n += sprintf(buffer + n, "<!DOCTYPE html>\r\n");
      n += sprintf(buffer + n, "<html>\r\n");
      n += sprintf(buffer + n, "<head>\r\n");
      n += sprintf(buffer + n, "  <title>Oryx Embedded - CycloneSSL TLS Server Demo</title>\r\n");
      n += sprintf(buffer + n, "  <style>\r\n");
      n += sprintf(buffer + n, "    body {font-family: monospace; font-size: 13px;}\r\n");
      n += sprintf(buffer + n, "    table {border-width: 1px; border-style: ouset; border-collapse: collapse;}\r\n");
      n += sprintf(buffer + n, "    td {border-width: 1px; border-style: inset; padding: 3px;}\r\n");
      n += sprintf(buffer + n, "  </style>\r\n");
      n += sprintf(buffer + n, "</head>\r\n");
      n += sprintf(buffer + n, "<body>\r\n");
      n += sprintf(buffer + n, "  <p>Welcome to the CycloneSSL TLS server!</p>\r\n");
      n += sprintf(buffer + n, "  <table>\r\n");

      //Debug message
      TRACE_INFO("%s\r\n", buffer);

      //Send response to the client
      error = tlsWrite(tlsContext, buffer, n, NULL, 0);
      //Any error to report?
      if(error)
         break;

      //Format response
      n = 0;
      n += sprintf(buffer + n, "  <tr>\r\n");
      n += sprintf(buffer + n, "    <td>Hit counter</td>\r\n");
      n += sprintf(buffer + n, "    <td>%d</td>\r\n", ++hitCounter);
      n += sprintf(buffer + n, "  </tr>\r\n");

      n += sprintf(buffer + n, "  <tr>\r\n");
      n += sprintf(buffer + n, "    <td>Server version</td>\r\n");
      n += sprintf(buffer + n, "    <td>%s</td>\r\n",
         tlsGetVersionName(tlsContext->versionMax));
      n += sprintf(buffer + n, "  </tr>\r\n");

      n += sprintf(buffer + n, "  <tr>\r\n");
      n += sprintf(buffer + n, "    <td>Client version</td>\r\n");
      n += sprintf(buffer + n, "    <td>%s</td>\r\n",
         tlsGetVersionName(MAX(tlsContext->clientVersion, tlsContext->version)));
      n += sprintf(buffer + n, "  </tr>\r\n");

      n += sprintf(buffer + n, "  <tr>\r\n");
      n += sprintf(buffer + n, "    <td>Negotiated version</td>\r\n");
      n += sprintf(buffer + n, "    <td>%s</td>\r\n",
         tlsGetVersionName(tlsContext->version));
      n += sprintf(buffer + n, "  </tr>\r\n");

      n += sprintf(buffer + n, "  <tr>\r\n");
      n += sprintf(buffer + n, "    <td>Cipher suite</td>\r\n");
      n += sprintf(buffer + n, "    <td>%s</td>\r\n",
         tlsGetCipherSuiteName(tlsContext->cipherSuite.identifier));
      n += sprintf(buffer + n, "  </tr>\r\n");

      //Debug message
      TRACE_INFO("%s\r\n", buffer);

      //Send response to the client
      error = tlsWrite(tlsContext, buffer, n, NULL, 0);
      //Any error to report?
      if(error)
         break;

      //Format response
      n = 0;
      n += sprintf(buffer + n, "  <tr>\r\n");
      n += sprintf(buffer + n, "    <td>Client random</td>\r\n");
      n += sprintf(buffer + n, "      <td>\r\n");
      n += sprintf(buffer + n, "        ");
      n += dumpArray(buffer + n, (uint8_t *) &tlsContext->clientRandom, 32);
      n += sprintf(buffer + n, "\r\n");
      n += sprintf(buffer + n, "      </td>\r\n");
      n += sprintf(buffer + n, "  </tr>\r\n");

      n += sprintf(buffer + n, "  <tr>\r\n");
      n += sprintf(buffer + n, "    <td>Server random</td>\r\n");
      n += sprintf(buffer + n, "      <td>\r\n");
      n += sprintf(buffer + n, "        ");
      n += dumpArray(buffer + n, (uint8_t *) &tlsContext->serverRandom, 32);
      n += sprintf(buffer + n, "\r\n");
      n += sprintf(buffer + n, "      </td>\r\n");
      n += sprintf(buffer + n, "  </tr>\r\n");

      //Debug message
      TRACE_INFO("%s\r\n", buffer);

      //Send response to the client
      error = tlsWrite(tlsContext, buffer, n, NULL, 0);
      //Any error to report?
      if(error)
         break;

      //Format response
      n = 0;
      n += sprintf(buffer + n, "  <tr>\r\n");
      n += sprintf(buffer + n, "    <td>Session ID</td>\r\n");
      n += sprintf(buffer + n, "      <td>\r\n");
      n += sprintf(buffer + n, "        ");
      n += dumpArray(buffer + n, tlsContext->sessionId, tlsContext->sessionIdLen);
      n += sprintf(buffer + n, "\r\n");
      n += sprintf(buffer + n, "      </td>\r\n");
      n += sprintf(buffer + n, "  </tr>\r\n");

      n += sprintf(buffer + n, "  </table>\r\n");
      n += sprintf(buffer + n, "</body>\r\n");
      n += sprintf(buffer + n, "</html>\r\n");

      //Debug message
      TRACE_INFO("%s\r\n", buffer);

      //Send response to the client
      error = tlsWrite(tlsContext, buffer, n, NULL, 0);
      //Any error to report?
      if(error)
         break;

      //Terminate TLS session
      error = tlsShutdown(tlsContext);
      //Any error to report?
      if(error)
         break;

      //Graceful shutdown
      error = socketShutdown(clientSocket, SOCKET_SD_BOTH);
      //Any error to report?
      if(error)
         break;

      //End of exception handling block
   } while(0);

   //Release TLS context
   if(tlsContext != NULL)
   {
      tlsFree(tlsContext);
   }

   //Close socket
   if(clientSocket != NULL)
   {
      socketClose(clientSocket);
   }

   //Debug message
   TRACE_INFO("Connection closed...\r\n");

   //Release semaphore
   osReleaseSemaphore(&connectionSemaphore);

   //Kill ourselves
   osDeleteTask(OS_SELF_TASK_ID);
}


/**
 * @brief Display the contents of an array
 * @param[out] buffer Output buffer where to format the resulting string
 * @param[in] data Pointer to the data array
 * @param[in] length Number of bytes in the array
 * @return Length of the resulting string
 **/

size_t dumpArray(char_t *buffer, const uint8_t *data, size_t length)
{
   size_t i;
   size_t n;

   //Variable initialization
   n = 0;

   //Properly terminate the string
   buffer[0] = '\0';

   //Process input data
   for(i = 0; i < length; i++)
   {
      //Beginning of a new line?
      if(i != 0 && (i % 16) == 0)
      {
         n += sprintf(buffer + n, "\r\n        ");
      }

      //Display current data byte
      n += sprintf(buffer + n, "%02" PRIX8 " ", data[i]);
   }

   //Return the length of the resulting string
   return n;
}
