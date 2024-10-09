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
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "bsp_api.h"
#include "m13_ra6m4_ek.h"
#include "core/net.h"
#include "drivers/mac/ra6_eth_driver.h"
#include "drivers/phy/ksz8081_driver.h"
#include "dhcp/dhcp_client.h"
#include "ipv6/slaac.h"
#include "http/http_server.h"
#include "http/mime.h"
#include "hardware/ra6/ra6_crypto.h"
#include "rng/trng.h"
#include "rng/yarrow.h"
#include "path.h"
#include "date_time.h"
#include "resource_manager.h"
#include "smi_driver.h"
#include "wsen_itds.h"
#include "debug.h"

//Ethernet interface configuration
#define APP_IF_NAME "eth0"
#define APP_HOST_NAME "https-server-demo"
#define APP_MAC_ADDR "00-AB-CD-EF-00-A6"

#define APP_USE_DHCP_CLIENT ENABLED
#define APP_IPV4_HOST_ADDR "192.168.0.20"
#define APP_IPV4_SUBNET_MASK "255.255.255.0"
#define APP_IPV4_DEFAULT_GATEWAY "192.168.0.254"
#define APP_IPV4_PRIMARY_DNS "8.8.8.8"
#define APP_IPV4_SECONDARY_DNS "8.8.4.4"

#define APP_USE_SLAAC ENABLED
#define APP_IPV6_LINK_LOCAL_ADDR "fe80::a6"
#define APP_IPV6_PREFIX "2001:db8::"
#define APP_IPV6_PREFIX_LENGTH 64
#define APP_IPV6_GLOBAL_ADDR "2001:db8::a6"
#define APP_IPV6_ROUTER "fe80::1"
#define APP_IPV6_PRIMARY_DNS "2001:4860:4860::8888"
#define APP_IPV6_SECONDARY_DNS "2001:4860:4860::8844"

//Application configuration
#define APP_HTTP_MAX_CONNECTIONS 4
#define APP_HTTP_SERVER_CERT "certs/server_cert.pem"
#define APP_HTTP_SERVER_KEY "certs/server_key.pem"

//Global variables
uint_t adcValue = 0;
int8_t ax = 0;
int8_t ay = 0;
int8_t az = 0;

DhcpClientSettings dhcpClientSettings;
DhcpClientContext dhcpClientContext;
SlaacSettings slaacSettings;
SlaacContext slaacContext;
HttpServerSettings httpServerSettings;
HttpServerContext httpServerContext;
HttpConnection httpConnections[APP_HTTP_MAX_CONNECTIONS];
TlsCache *tlsCache;
YarrowContext yarrowContext;
uint8_t seed[32];

//Forward declaration of functions
error_t httpServerTlsInitCallback(HttpConnection *connection,
   TlsContext *tlsContext);

error_t httpServerCgiCallback(HttpConnection *connection,
   const char_t *param);

error_t httpServerRequestCallback(HttpConnection *connection,
   const char_t *uri);

error_t httpServerUriNotFoundCallback(HttpConnection *connection,
   const char_t *uri);


/**
 * @brief I/O initialization
 **/

void ioInit(void)
{
   //Disable protection
   R_SYSTEM->PRCR = 0xA50B;

   //Disable VBATT channel inputs
   R_SYSTEM->VBTICTLR &= ~(R_SYSTEM_VBTICTLR_VCH2INEN_Msk |
      R_SYSTEM_VBTICTLR_VCH1INEN_Msk | R_SYSTEM_VBTICTLR_VCH0INEN_Msk);

   //Enable protection
   R_SYSTEM->PRCR = 0xA500;

   //Unlock PFS registers
   R_PMISC->PWPR &= ~R_PMISC_PWPR_B0WI_Msk;
   R_PMISC->PWPR |= R_PMISC_PWPR_PFSWE_Msk;

   //Configure LED1
   R_PFS->LED1_PFS = R_PFS_PORT_PIN_PmnPFS_PDR_Msk;
   //Configure LED2
   R_PFS->LED2_PFS = R_PFS_PORT_PIN_PmnPFS_PDR_Msk;
   //Configure LED3
   R_PFS->LED3_PFS = R_PFS_PORT_PIN_PmnPFS_PDR_Msk;
   //Configure LED4
   R_PFS->LED4_PFS = R_PFS_PORT_PIN_PmnPFS_PDR_Msk;

   //Configure SW1
   R_PFS->SW1_PFS = 0;
   //Configure SW2
   R_PFS->SW2_PFS = 0;

   //Lock PFS registers
   R_PMISC->PWPR &= ~R_PMISC_PWPR_PFSWE_Msk;
   R_PMISC->PWPR |= R_PMISC_PWPR_B0WI_Msk;

   //Clear LEDs
   LED1_PORT->PCNTR3 = LED1_MASK << R_PORT0_PCNTR3_PORR_Pos;
   LED2_PORT->PCNTR3 = LED2_MASK << R_PORT0_PCNTR3_PORR_Pos;
   LED3_PORT->PCNTR3 = LED3_MASK << R_PORT0_PCNTR3_PORR_Pos;
   LED4_PORT->PCNTR3 = LED4_MASK << R_PORT0_PCNTR3_PORR_Pos;
}


/**
 * @brief A/D converter initialization
 **/

void adcInit(void)
{
   //Disable protection
   R_SYSTEM->PRCR = 0xA50B;
   //Cancel ADC120 module stop state
   R_MSTP->MSTPCRD &= ~(R_MSTP_MSTPCRD_MSTPD_Msk << 16);
   //Enable protection
   R_SYSTEM->PRCR = 0xA500;

   //Unlock PFS registers
   R_PMISC->PWPR &= ~R_PMISC_PWPR_B0WI_Msk;
   R_PMISC->PWPR |= R_PMISC_PWPR_PFSWE_Msk;

   //Configure P002/AN002 as an analog input
   R_PFS->PORT[0].PIN[2].PmnPFS = R_PFS_PORT_PIN_PmnPFS_ASEL_Msk;

   //Lock PFS registers
   R_PMISC->PWPR &= ~R_PMISC_PWPR_PFSWE_Msk;
   R_PMISC->PWPR |= R_PMISC_PWPR_B0WI_Msk;

   //Disable differential inputs
   R_ADC0->ADPGADCR0 = 0;
   //Select AN002 channel
   R_ADC0->ADANSA[0] = R_ADC0_ADANSA_ANSA_Msk << 2;
}


/**
 * @brief Perform A/D conversion
 * @return A/D conversion result
 **/

uint16_t adcGetValue(void)
{
   //Start A/D conversion process
   R_ADC0->ADCSR |= R_ADC0_ADCSR_ADST_Msk;

   //Wait for the conversion to complete
   while((R_ADC0->ADCSR & R_ADC0_ADCSR_ADST_Msk) != 0)
   {
   }

   //Return A/D conversion result
   return R_ADC0->ADDR[2];
}


/**
 * @brief Sensor task
 * @param[in] param Unused parameter
 **/

void sensorTask(void *param)
{
   //Endless loop
   while(1)
   {
      //Perform A/D conversion
      adcValue = adcGetValue();

      //Retrieve acceleration along the 3 axis
      wsenItdsGetAcc(&ax, &ay, &az);

      //Loop delay
      osDelayTask(100);
   }
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
      LED1_PORT->PCNTR3 = LED1_MASK << R_PORT0_PCNTR3_POSR_Pos;
      osDelayTask(100);
      LED1_PORT->PCNTR3 = LED1_MASK << R_PORT0_PCNTR3_PORR_Pos;
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

   //Initialize kernel
   osInitKernel();
   //Configure debug UART
   debugInit(115200);

   //Start-up message
   TRACE_INFO("\r\n");
   TRACE_INFO("************************************\r\n");
   TRACE_INFO("*** CycloneTCP HTTPS Server Demo ***\r\n");
   TRACE_INFO("************************************\r\n");
   TRACE_INFO("Copyright: 2010-2024 Oryx Embedded SARL\r\n");
   TRACE_INFO("Compiled: %s %s\r\n", __DATE__, __TIME__);
   TRACE_INFO("Target: RA6M4\r\n");
   TRACE_INFO("\r\n");

   //Configure I/Os
   ioInit();
   //ADC initialization
   adcInit();

   //Initialize WSEN-ITDS sensor
   wsenItdsInit();

   //Initialize hardware cryptographic accelerator
   error = ra6CryptoInit();
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
   netSetDriver(interface, &ra6EthDriver);
   netSetPhyDriver(interface, &ksz8081PhyDriver);
   //MDIO and MDC are managed by software
   netSetSmiDriver(interface, &smiDriver);

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

   //TLS session cache initialization
   tlsCache = tlsInitCache(8);
   //Any error to report?
   if(tlsCache == NULL)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize TLS session cache!\r\n");
   }

   //Get default settings
   httpServerGetDefaultSettings(&httpServerSettings);
   //Bind HTTP server to the desired interface
   httpServerSettings.interface = &netInterface[0];
   //Listen to port 443
   httpServerSettings.port = HTTPS_PORT;
   //Maximum length of the pending connection queue
   httpServerSettings.backlog = 2;
   //Client connections
   httpServerSettings.maxConnections = APP_HTTP_MAX_CONNECTIONS;
   httpServerSettings.connections = httpConnections;
   //Specify the server's root directory
   strcpy(httpServerSettings.rootDirectory, "/www/");
   //Set default home page
   strcpy(httpServerSettings.defaultDocument, "index.htm");
   //Callback functions
   httpServerSettings.tlsInitCallback = httpServerTlsInitCallback;
   httpServerSettings.cgiCallback = httpServerCgiCallback;
   httpServerSettings.requestCallback = httpServerRequestCallback;
   httpServerSettings.uriNotFoundCallback = httpServerUriNotFoundCallback;

   //HTTP server initialization
   error = httpServerInit(&httpServerContext, &httpServerSettings);
   //Failed to initialize HTTP server?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize HTTP server!\r\n");
   }

   //Start HTTP server
   error = httpServerStart(&httpServerContext);
   //Failed to start HTTP server?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start HTTP server!\r\n");
   }

   //Set task parameters
   taskParams = OS_TASK_DEFAULT_PARAMS;
   taskParams.stackSize = 500;
   taskParams.priority = OS_TASK_PRIORITY_NORMAL;

   //Create a task to manage the accelerometer sensor
   taskId = osCreateTask("Sensor", sensorTask, NULL, &taskParams);
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
 * @brief TLS initialization callback
 * @param[in] connection Handle referencing a client connection
 * @param[in] tlsContext Pointer to the TLS context
 * @return Error code
 **/

error_t httpServerTlsInitCallback(HttpConnection *connection,
   TlsContext *tlsContext)
{
   error_t error;
   const char_t *serverCert;
   size_t serverCertLen;
   const char_t *serverKey;
   size_t serverKeyLen;

   //Set TX and RX buffer size
   error = tlsSetBufferSize(tlsContext, 2048, 2048);
   //Any error to report?
   if(error)
      return error;

   //Set the PRNG algorithm to be used
   error = tlsSetPrng(tlsContext, YARROW_PRNG_ALGO, &yarrowContext);
   //Any error to report?
   if(error)
      return error;

   //Session cache that will be used to save/resume TLS sessions
   error = tlsSetCache(tlsContext, tlsCache);
   //Any error to report?
   if(error)
      return error;

   //Client authentication is not required
   error = tlsSetClientAuthMode(tlsContext, TLS_CLIENT_AUTH_NONE);
   //Any error to report?
   if(error)
      return error;

   //Enable secure renegotiation
   error = tlsEnableSecureRenegotiation(tlsContext, TRUE);
   //Any error to report?
   if(error)
      return error;

   //Get server's certificate
   error = resGetData(APP_HTTP_SERVER_CERT, (const uint8_t **) &serverCert,
      &serverCertLen);
   //Any error to report?
   if(error)
      return error;

   //Get server's private key
   error = resGetData(APP_HTTP_SERVER_KEY, (const uint8_t **) &serverKey,
      &serverKeyLen);
   //Any error to report?
   if(error)
      return error;

   //Load server's certificate
   error = tlsLoadCertificate(tlsContext, 0, serverCert, serverCertLen,
      serverKey, serverKeyLen, NULL);
   //Any error to report?
   if(error)
      return error;

   //Successful processing
   return NO_ERROR;
}


/**
 * @brief CGI callback function
 * @param[in] connection Handle referencing a client connection
 * @param[in] param NULL-terminated string that contains the CGI parameter
 * @return Error code
 **/

error_t httpServerCgiCallback(HttpConnection *connection,
   const char_t *param)
{
   //Not implemented
   return ERROR_INVALID_TAG;
}


/**
 * @brief HTTP request callback
 * @param[in] connection Handle referencing a client connection
 * @param[in] uri NULL-terminated string containing the path to the requested resource
 * @return Error code
 **/

error_t httpServerRequestCallback(HttpConnection *connection,
   const char_t *uri)
{
   error_t error;
   uint_t n;
   char_t buffer[128];

   //Process data.xml file?
   if(!strcasecmp(uri, "/data.xml"))
   {
      //Format XML data
      n = sprintf(buffer, "<data>\r\n");
      n += sprintf(buffer + n, "  <ax>%d</ax>\r\n", ax);
      n += sprintf(buffer + n, "  <ay>%d</ay>\r\n", ay);
      n += sprintf(buffer + n, "  <az>%d</az>\r\n", az);
      n += sprintf(buffer + n, "  <adc>%u</adc>\r\n", adcValue);
      n += sprintf(buffer + n, "</data>\r\n");

      //Format HTTP response header
      connection->response.version = connection->request.version;
      connection->response.statusCode = 200;
      connection->response.keepAlive = connection->request.keepAlive;
      connection->response.noCache = TRUE;
      connection->response.contentType = mimeGetType(".xml");
      connection->response.chunkedEncoding = FALSE;
      connection->response.contentLength = n;

      //Send the header to the client
      error = httpWriteHeader(connection);
      //Any error to report?
      if(error)
         return error;

      //Send response body
      error = httpWriteStream(connection, buffer, n);
      //Any error to report?
      if(error)
         return error;

      //Properly close output stream
      error = httpCloseStream(connection);
      //Return status code
      return error;
   }
   else
   {
      //The requested resource cannot be found
      return ERROR_NOT_FOUND;
   }
}


/**
 * @brief URI not found callback
 * @param[in] connection Handle referencing a client connection
 * @param[in] uri NULL-terminated string containing the path to the requested resource
 * @return Error code
 **/

error_t httpServerUriNotFoundCallback(HttpConnection *connection,
   const char_t *uri)
{
   //Not implemented
   return ERROR_NOT_FOUND;
}
