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
#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "efm32_giant_gecko_11_sk.h"
#include "core/net.h"
#include "drivers/mac/efm32gg11_eth_driver.h"
#include "drivers/phy/ksz8091_driver.h"
#include "dhcp/dhcp_client.h"
#include "ipv6/slaac.h"
#include "coap/coap_server.h"
#include "coap/coap_server_request.h"
#include "hardware/efm32gg11/efm32gg11_crypto.h"
#include "rng/trng.h"
#include "rng/yarrow.h"
#include "path.h"
#include "resource_manager.h"
#include "debug.h"

//Ethernet interface configuration
#define APP_IF_NAME "eth0"
#define APP_HOST_NAME "coaps-server-demo"
#define APP_MAC_ADDR "00-AB-CD-EF-32-11"

#define APP_USE_DHCP_CLIENT ENABLED
#define APP_IPV4_HOST_ADDR "192.168.0.20"
#define APP_IPV4_SUBNET_MASK "255.255.255.0"
#define APP_IPV4_DEFAULT_GATEWAY "192.168.0.254"
#define APP_IPV4_PRIMARY_DNS "8.8.8.8"
#define APP_IPV4_SECONDARY_DNS "8.8.4.4"

#define APP_USE_SLAAC ENABLED
#define APP_IPV6_LINK_LOCAL_ADDR "fe80::3211"
#define APP_IPV6_PREFIX "2001:db8::"
#define APP_IPV6_PREFIX_LENGTH 64
#define APP_IPV6_GLOBAL_ADDR "2001:db8::3211"
#define APP_IPV6_ROUTER "fe80::1"
#define APP_IPV6_PRIMARY_DNS "2001:4860:4860::8888"
#define APP_IPV6_SECONDARY_DNS "2001:4860:4860::8844"

//Application configuration
#define APP_COAP_SERVER_PORT 5684
#define APP_COAP_SERVER_CERT "certs/server_cert.pem"
#define APP_COAP_SERVER_KEY "certs/server_key.pem"

//Global variables
DhcpClientSettings dhcpClientSettings;
DhcpClientContext dhcpClientContext;
SlaacSettings slaacSettings;
SlaacContext slaacContext;
CoapServerSettings coapServerSettings;
CoapServerContext coapServerContext;
TlsCache *tlsCache;
YarrowContext yarrowContext;
uint8_t seed[32];

//Forward declaration of functions
error_t coapServerDtlsInitCallback(CoapServerContext *context,
   TlsContext *dtlsContext);

error_t coapServerRequestCallback(CoapServerContext *context,
   CoapCode method, const char_t *uri);


/**
 * @brief I/O initialization
 **/

void ioInit(void)
{
   //Enable high-frequency peripheral clock
   CMU_ClockEnable(cmuClock_HFPER, true);
   //Enable GPIO clock
   CMU_ClockEnable(cmuClock_GPIO, true);

   //Configure LED0
   GPIO_PinModeSet(LED0_R_GPIO_PORT, LED0_R_GPIO_PIN, gpioModePushPull, 1);
   GPIO_PinModeSet(LED0_G_GPIO_PORT, LED0_G_GPIO_PIN, gpioModePushPull, 1);
   GPIO_PinModeSet(LED0_B_GPIO_PORT, LED0_B_GPIO_PIN, gpioModePushPull, 1);

   //Configure LED1
   GPIO_PinModeSet(LED1_R_GPIO_PORT, LED1_R_GPIO_PIN, gpioModePushPull, 1);
   GPIO_PinModeSet(LED1_G_GPIO_PORT, LED1_G_GPIO_PIN, gpioModePushPull, 1);
   GPIO_PinModeSet(LED1_B_GPIO_PORT, LED1_B_GPIO_PIN, gpioModePushPull, 1);

   //Configure BTN0 button
   GPIO_PinModeSet(BTN0_GPIO_PORT, BTN0_GPIO_PIN, gpioModeInput, 0);

   //Configure BTN1 button
   GPIO_PinModeSet(BTN1_GPIO_PORT, BTN1_GPIO_PIN, gpioModeInput, 0);
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
      GPIO_PinOutClear(LED1_R_GPIO_PORT, LED1_R_GPIO_PIN);
      osDelayTask(100);
      GPIO_PinOutSet(LED1_R_GPIO_PORT, LED1_R_GPIO_PIN);
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

   //Default DCDC initialization
   EMU_DCDCInit_TypeDef dcdcInit = EMU_DCDCINIT_DEFAULT;
   //Default HFXO initialization
   CMU_HFXOInit_TypeDef hfxoInit = CMU_HFXOINIT_DEFAULT;

   //Chip initialization (errata workarounds)
   CHIP_Init();
   //Configure DCDC regulator
   EMU_DCDCInit(&dcdcInit);
   //Configure HFXO oscillator
   CMU_HFXOInit(&hfxoInit);
   //Set core frequency
   CMU_HFRCOBandSet(cmuHFRCOFreq_72M0Hz);

   //Initialize kernel
   osInitKernel();
   //Configure debug UART
   debugInit(115200);

   //Start-up message
   TRACE_INFO("\r\n");
   TRACE_INFO("************************************\r\n");
   TRACE_INFO("*** CycloneTCP CoAPs Server Demo ***\r\n");
   TRACE_INFO("************************************\r\n");
   TRACE_INFO("Copyright: 2010-2024 Oryx Embedded SARL\r\n");
   TRACE_INFO("Compiled: %s %s\r\n", __DATE__, __TIME__);
   TRACE_INFO("Target: EFM32GG11B\r\n");
   TRACE_INFO("\r\n");

   //Configure I/Os
   ioInit();

   //Initialize hardware cryptographic accelerator
   error = efm32gg11CryptoInit();
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
   netSetDriver(interface, &efm32gg11EthDriver);
   netSetPhyDriver(interface, &ksz8091PhyDriver);

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
   coapServerGetDefaultSettings(&coapServerSettings);
   //Bind CoAP server to the desired interface
   coapServerSettings.interface = &netInterface[0];
   //Listen to port 80
   coapServerSettings.port = APP_COAP_SERVER_PORT;
   //Callback functions
   coapServerSettings.dtlsInitCallback = coapServerDtlsInitCallback;
   coapServerSettings.requestCallback = coapServerRequestCallback;

   //CoAP server initialization
   error = coapServerInit(&coapServerContext, &coapServerSettings);
   //Failed to initialize CoAP server?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize CoAP server!\r\n");
   }

   //Start CoAP server
   error = coapServerStart(&coapServerContext);
   //Failed to start CoAP server?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start CoAP server!\r\n");
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
 * @brief DTLS initialization callback
 * @param[in] context Pointer to the CoAP server context
 * @param[in] dtlsContext Pointer to the DTLS context
 * @return Error code
 **/

error_t coapServerDtlsInitCallback(CoapServerContext *context,
   TlsContext *dtlsContext)
{
   error_t error;
   const char_t *serverCert;
   size_t serverCertLen;
   const char_t *serverKey;
   size_t serverKeyLen;

   //Debug message
   TRACE_INFO("CoAP Server: DTLS initialization callback\r\n");

   //Set TX and RX buffer size
   error = tlsSetBufferSize(dtlsContext, 2048, 2048);
   //Any error to report?
   if(error)
      return error;

   //Set the PRNG algorithm to be used
   error = tlsSetPrng(dtlsContext, YARROW_PRNG_ALGO, &yarrowContext);
   //Any error to report?
   if(error)
      return error;

   //Session cache that will be used to save/resume TLS sessions
   error = tlsSetCache(dtlsContext, tlsCache);
   //Any error to report?
   if(error)
      return error;

   //Client authentication is not required
   error = tlsSetClientAuthMode(dtlsContext, TLS_CLIENT_AUTH_NONE);
   //Any error to report?
   if(error)
      return error;

   //Get server's certificate
   error = resGetData(APP_COAP_SERVER_CERT, (const uint8_t **) &serverCert,
      &serverCertLen);
   //Any error to report?
   if(error)
      return error;

   //Get server's private key
   error = resGetData(APP_COAP_SERVER_KEY, (const uint8_t **) &serverKey,
      &serverKeyLen);
   //Any error to report?
   if(error)
      return error;

   //Load server's certificate
   error = tlsLoadCertificate(dtlsContext, 0, serverCert, serverCertLen,
      serverKey, serverKeyLen, NULL);
   //Any error to report?
   if(error)
      return error;

   //Successful processing
   return NO_ERROR;
}


/**
 * @brief CoAP request callback
 * @param[in] context Pointer to the CoAP server context
 * @param[in] method CoAP method code
 * @param[in] uri NULL-terminated string containing the path to the requested resource
 * @return Error code
 **/

error_t coapServerRequestCallback(CoapServerContext *context,
   CoapCode method, const char_t *uri)
{
   error_t error;

   //Check method code
   if(method == COAP_CODE_GET)
   {
      //Check URI path
      if(!strcasecmp(uri, "/.well-known/core"))
      {
         //A client can access the /.well-known/core URI in order to discover
         //available resources
         const char_t coreResourceDir[] =
            "</test>;title=\"Default test resource\","
            "</echo>;title=\"Echo test resource\"";

         //Return a 2.05 response code
         error = coapServerSetResponseCode(context, COAP_CODE_CONTENT);

         //Check status code
         if(!error)
         {
            //Set the content format of the response body
            error = coapServerSetUintOption(context, COAP_OPT_CONTENT_FORMAT,
               0, COAP_CONTENT_FORMAT_APP_LINK_FORMAT);
         }

         //Check status code
         if(!error)
         {
            //Write the response body
            error = coapServerSetPayload(context, coreResourceDir,
               strlen(coreResourceDir));
         }
      }
      else if(!strcasecmp(uri, "/test"))
      {
         //Return a 2.05 response code
         error = coapServerSetResponseCode(context, COAP_CODE_CONTENT);

         //Check status code
         if(!error)
         {
            //Set the content format of the response body
            error = coapServerSetUintOption(context, COAP_OPT_CONTENT_FORMAT,
               0, COAP_CONTENT_FORMAT_TEXT_PLAIN);
         }

         //Check status code
         if(!error)
         {
            //Write the response body
            error = coapServerSetPayload(context, "Hello World!", 12);
         }
      }
      else
      {
         //The requested resource cannot be found
         error = coapServerSetResponseCode(context, COAP_CODE_NOT_FOUND);
      }
   }
   else if(method == COAP_CODE_POST)
   {
      //Check URI path
      if(!strcasecmp(uri, "/echo"))
      {
         size_t n;
         uint32_t contentFormat;
         bool_t contentFormatFound;
         const uint8_t *p;

         //Get the content format of the request body
         error = coapServerGetUintOption(context, COAP_OPT_CONTENT_FORMAT, 0,
            &contentFormat);

         //Check whether the option has been found
         contentFormatFound = (error == NO_ERROR) ? TRUE : FALSE;

         //Get the body of the request
         error = coapServerGetPayload(context, &p, &n);

         //Check status code
         if(!error)
         {
            //Return a 2.04 response code
            error = coapServerSetResponseCode(context, COAP_CODE_CHANGED);
         }

         //Check status code
         if(!error)
         {
            //Set the content format of the response body
            if(contentFormatFound)
            {
               error = coapServerSetUintOption(context, COAP_OPT_CONTENT_FORMAT,
                  0, contentFormat);
            }
         }

         //Check status code
         if(!error)
         {
            //Write the response body
            error = coapServerSetPayload(context, p, n);
         }
      }
      else
      {
         //The requested resource cannot be found
         error = coapServerSetResponseCode(context, COAP_CODE_NOT_FOUND);
      }
   }
   else
   {
      //Unknown method code
      error = coapServerSetResponseCode(context, COAP_CODE_METHOD_NOT_ALLOWED);
   }

   //Return status code
   return error;
}
