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
#include "coap/coap_client.h"
#include "hardware/efm32gg11/efm32gg11_crypto.h"
#include "rng/trng.h"
#include "rng/yarrow.h"
#include "debug.h"

//Ethernet interface configuration
#define APP_IF_NAME "eth0"
#define APP_HOST_NAME "coaps-client-demo"
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
#define APP_COAP_SERVER_NAME "californium.eclipseprojects.io"
#define APP_COAP_SERVER_PORT 5684

//Client's certificate
const char_t clientCert[] =
   "-----BEGIN CERTIFICATE-----"
   "MIIB/TCCAaOgAwIBAgIIVNrVgKT9OE8wCgYIKoZIzj0EAwIwWjEOMAwGA1UEAxMF"
   "Y2YtY2ExFDASBgNVBAsTC0NhbGlmb3JuaXVtMRQwEgYDVQQKEwtFY2xpcHNlIElv"
   "VDEPMA0GA1UEBxMGT3R0YXdhMQswCQYDVQQGEwJDQTAeFw0yMzEwMjYwODA4MjJa"
   "Fw0yNTEwMjUwODA4MjJaMF4xEjAQBgNVBAMTCWNmLWNsaWVudDEUMBIGA1UECxML"
   "Q2FsaWZvcm5pdW0xFDASBgNVBAoTC0VjbGlwc2UgSW9UMQ8wDQYDVQQHEwZPdHRh"
   "d2ExCzAJBgNVBAYTAkNBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEQxYO5/M5"
   "ie6+3QPOaAy5MD6CkFILZwIb2rOBCX/EWPaocX1H+eynUnaEEbmqxeN6rnI/pH19"
   "j4PtsegfHLrzzaNPME0wHQYDVR0OBBYEFKwEDLTJ+5cQoZfbjWN1vJ2ssgK+MAsG"
   "A1UdDwQEAwIHgDAfBgNVHSMEGDAWgBSxVzoI1TL87++hsUb9vQwqODzgUTAKBggq"
   "hkjOPQQDAgNIADBFAiA2KCOw3n2AK9Vm8u2u1bQREIEs3tKAU7eFjpNFn929NwIh"
   "AInhBGoEwS2Xlu5bdZSfWnujoRrEQiIiQpStmLxVcIsH"
   "-----END CERTIFICATE-----";

//Client's private key
const char_t clientKey[] =
   "-----BEGIN PRIVATE KEY-----"
   "MEECAQAwEwYHKoZIzj0CAQYIKoZIzj0DAQcEJzAlAgEBBCDn0+4CuLeX7xwBs0ts"
   "UUEDB3+HRwRKdIPeJlIbKuvvEQ=="
   "-----END PRIVATE KEY-----";

//List of trusted CA certificates
const char_t trustedCaList[] =
   "-----BEGIN CERTIFICATE-----"
   "MIICDDCCAbKgAwIBAgIIPKO8L7vZoqAwCgYIKoZIzj0EAwIwXDEQMA4GA1UEAxMH"
   "Y2Ytcm9vdDEUMBIGA1UECxMLQ2FsaWZvcm5pdW0xFDASBgNVBAoTC0VjbGlwc2Ug"
   "SW9UMQ8wDQYDVQQHEwZPdHRhd2ExCzAJBgNVBAYTAkNBMB4XDTIzMTAyNjA4MDgx"
   "NVoXDTI1MTAyNTA4MDgxNVowWjEOMAwGA1UEAxMFY2YtY2ExFDASBgNVBAsTC0Nh"
   "bGlmb3JuaXVtMRQwEgYDVQQKEwtFY2xpcHNlIElvVDEPMA0GA1UEBxMGT3R0YXdh"
   "MQswCQYDVQQGEwJDQTBZMBMGByqGSM49AgEGCCqGSM49AwEHA0IABLCbJjxIS4hI"
   "AnRFTlx23gkd4zyFd50zdpTnoUPz19oQ1o1youavC5Go9vrYoWxyx+zpph8T4brB"
   "C/mZGIgPVMOjYDBeMB0GA1UdDgQWBBSxVzoI1TL87++hsUb9vQwqODzgUTALBgNV"
   "HQ8EBAMCAQYwDwYDVR0TBAgwBgEB/wIBATAfBgNVHSMEGDAWgBTqNhC1fqOTsHRn"
   "IVZ9OabfWsxpcTAKBggqhkjOPQQDAgNIADBFAiBSEn3egc31JhhHTVYi5uhl0t4d"
   "ewujkEmwzBuruzf/xAIhAK/fXy2tsNoyLitFQ97x6LYV25jKmLKUlhL2mC/PwQdO"
   "-----END CERTIFICATE-----";

//Global variables
DhcpClientSettings dhcpClientSettings;
DhcpClientContext dhcpClientContext;
SlaacSettings slaacSettings;
SlaacContext slaacContext;
CoapClientContext coapClientContext;
YarrowContext yarrowContext;
uint8_t seed[32];


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
 * @brief DTLS initialization callback
 * @param[in] context Pointer to the CoAP client context
 * @param[in] dtlsContext Pointer to the DTLS context
 * @return Error code
 **/

error_t coapTestDtlsInitCallback(CoapClientContext *context,
   TlsContext *dtlsContext)
{
   error_t error;

   //Debug message
   TRACE_INFO("CoAP Client: DTLS initialization callback\r\n");

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

   //Load client's certificate
   error = tlsLoadCertificate(dtlsContext, 0, clientCert, strlen(clientCert),
      clientKey, strlen(clientKey), NULL);
   //Any error to report?
   if(error)
      return error;

   //Import trusted CA certificates
   error = tlsSetTrustedCaList(dtlsContext, trustedCaList, strlen(trustedCaList));
   //Any error to report?
   if(error)
      return error;

   //Successful processing
   return NO_ERROR;
}


/**
 * @brief CoAP observe callback
 * @param[in] context Pointer to the CoAP client context
 * @param[in] request CoAP request handle
 * @param[in] status CoAP request status
 * @param[in] param Callback function parameter
 * @return Error code
 **/

error_t coapTestObserveCallback(CoapClientContext *context,
   CoapClientRequest *request, CoapRequestStatus status, void *param)
{
   error_t error;
   CoapMessage *message;
   CoapCode responseCode;
   size_t payloadLen;
   const uint8_t *payload;

   //Check request status
   if(status == COAP_REQUEST_STATUS_SUCCESS)
   {
      //Debug message
      TRACE_INFO("CoAP notification received...\r\n");

      //Point to the response message
      message = coapClientGetResponseMessage(request);

      //Retrieve response code
      error = coapClientGetResponseCode(message, &responseCode);

      //Check status code
      if(!error)
      {
         //Debug message
         TRACE_INFO("  Response Code: %" PRIu8 ".%02" PRIu8 "\r\n",
            responseCode / 32, responseCode & 31);
      }

      //Get payload data
      error = coapClientGetPayload(message, &payload, &payloadLen);

      //Check status code
      if(!error)
      {
         //Debug message
         TRACE_INFO("  Payload (%u bytes):\r\n%s\r\n", payloadLen, payload);
      }
   }
   else
   {
      //Debug message
      TRACE_INFO("CoAP observation canceled!\r\n");
   }

   //Successful processing
   return NO_ERROR;
}


/**
 * @brief Observable resource registration
 * @param[in] context Pointer to the CoAP client context
 * @return Error code
 **/

error_t coapTestObserve(CoapClientContext *context)
{
   error_t error;
   CoapClientRequest *request;
   CoapMessage *message;

   //Create a new CoAP request
   request = coapClientCreateRequest(context);

   //Valid request handle?
   if(request != NULL)
   {
      //Set request timeout
      coapClientSetRequestTimeout(request, 10000);

      //Point to the request message
      message = coapClientGetRequestMessage(request);

      //Format request message
      coapClientSetType(message, COAP_TYPE_CON);
      coapClientSetMethodCode(message, COAP_CODE_GET);
      coapClientSetUriPath(message, "/obs");

      //A client registers its interest in a resource by issuing a GET
      //request with an Observe option set to 0
      coapClientSetUintOption(message, COAP_OPT_OBSERVE, 0,
         COAP_OBSERVE_REGISTER);

      //Send CoAP request
      error = coapClientSendRequest(request, coapTestObserveCallback, NULL);

      //Any error to report?
      if(error)
      {
         //Clean up side effects
         coapClientDeleteRequest(request);
      }
   }
   else
   {
      //Debug message
      TRACE_ERROR("Failed to create CoAP request!\r\n");
      //Report an error
      error = ERROR_FAILURE;
   }

   //Return status code
   return error;
}


/**
 * @brief CoAP request callback (asynchronous mode)
 * @param[in] context Pointer to the CoAP client context
 * @param[in] request CoAP request handle
 * @param[in] status CoAP request status
 * @param[in] param Callback function parameter
 * @return Error code
 **/

error_t coapTestRequestAsyncCallback(CoapClientContext *context,
   CoapClientRequest *request, CoapRequestStatus status, void *param)
{
   error_t error;
   CoapMessage *message;
   CoapCode responseCode;
   size_t payloadLen;
   const uint8_t *payload;

   //Check request status
   if(status == COAP_REQUEST_STATUS_SUCCESS)
   {
      //Debug message
      TRACE_INFO("CoAP response received...\r\n");

      //Point to the response message
      message = coapClientGetResponseMessage(request);

      //Retrieve response code
      error = coapClientGetResponseCode(message, &responseCode);

      //Check status code
      if(!error)
      {
         //Debug message
         TRACE_INFO("  Response Code: %" PRIu8 ".%02" PRIu8 "\r\n",
            responseCode / 32, responseCode & 31);
      }

      //Get payload data
      error = coapClientGetPayload(message, &payload, &payloadLen);

      //Check status code
      if(!error)
      {
         //Debug message
         TRACE_INFO("  Payload (%u bytes):\r\n%s\r\n", payloadLen, payload);
      }
   }
   else
   {
      //Debug message
      TRACE_INFO("CoAP request failed!\r\n");
   }

   //Successful processing
   return NO_ERROR;
}


/**
 * @brief Send CoAP request (asynchronous mode)
 * @param[in] context Pointer to the CoAP client context
 * @return Error code
 **/

error_t coapTestRequestAsync(CoapClientContext *context)
{
   error_t error;
   CoapClientRequest *request;
   CoapMessage *message;

   //Create a new CoAP request
   request = coapClientCreateRequest(context);

   //Valid request handle?
   if(request != NULL)
   {
      //Set request timeout
      coapClientSetRequestTimeout(request, 10000);

      //Point to the request message
      message = coapClientGetRequestMessage(request);

      //Format request message
      coapClientSetType(message, COAP_TYPE_CON);
      coapClientSetMethodCode(message, COAP_CODE_GET);
      coapClientSetUriPath(message, "/separate");

      //Send CoAP request without blocking. The specified callback function
      //will be called upon request completion
      error = coapClientSendRequest(request, coapTestRequestAsyncCallback,
         NULL);

      //Any error to report?
      if(error)
      {
         //Clean up side effects
         coapClientDeleteRequest(request);
      }
   }
   else
   {
      //Debug message
      TRACE_ERROR("Failed to create CoAP request!\r\n");
      //Report an error
      error = ERROR_FAILURE;
   }

   //Return status code
   return error;
}


/**
 * @brief Send CoAP request (synchronous mode)
 * @param[in] context Pointer to the CoAP client context
 * @return Error code
 **/

error_t coapTestRequestSync(CoapClientContext *context)
{
   error_t error;
   CoapClientRequest *request;
   CoapMessage *message;
   CoapCode responseCode;
   size_t payloadLen;
   const uint8_t *payload;

   //Create a new CoAP request
   request = coapClientCreateRequest(context);

   //Valid request handle?
   if(request != NULL)
   {
      //Set request timeout
      coapClientSetRequestTimeout(request, 10000);

      //Point to the request message
      message = coapClientGetRequestMessage(request);

      //Format request message
      coapClientSetType(message, COAP_TYPE_CON);
      coapClientSetMethodCode(message, COAP_CODE_POST);
      coapClientSetUriPath(message, "/test");

      //Set Content-Format option
      coapClientSetUintOption(message, COAP_OPT_CONTENT_FORMAT, 0,
         COAP_CONTENT_FORMAT_TEXT_PLAIN);

      //Set request payload
      coapClientSetPayload(message, "Hello World!", 12);

      //Send CoAP request and wait for completion
      error = coapClientSendRequest(request, NULL, NULL);

      //Any response received?
      if(!error)
      {
         //Point to the response message
         message = coapClientGetResponseMessage(request);

         //Retrieve response code
         error = coapClientGetResponseCode(message, &responseCode);

         //Check status code
         if(!error)
         {
            //Debug message
            TRACE_INFO("  Response Code: %" PRIu8 ".%02" PRIu8 "\r\n",
               responseCode / 32, responseCode & 31);
         }

         //Get response payload
         error = coapClientGetPayload(message, &payload, &payloadLen);

         //Check status code
         if(!error)
         {
            //Debug message
            TRACE_INFO("  Payload (%u bytes):\r\n%s\r\n", payloadLen, payload);
         }
      }
      else
      {
         //Debug message
         TRACE_WARNING("No CoAP response received!\r\n");
      }

      //Release CoAP request
      coapClientDeleteRequest(request);
   }
   else
   {
      //Debug message
      TRACE_ERROR("Failed to create CoAP request!\r\n");
      //Report an error
      error = ERROR_FAILURE;
   }

   //Return status code
   return error;
}


/**
 * @brief Establish connection with a remote CoAP server
 * @param[in] context Pointer to the CoAP client context
 * @return Error code
 **/

error_t coapTestConnect(CoapClientContext *context)
{
   error_t error;
   IpAddr ipAddr;

   //Debug message
   TRACE_INFO("\r\n\r\nResolving server name...\r\n");

   //Resolve CoAP server name
   error = getHostByName(NULL, APP_COAP_SERVER_NAME, &ipAddr, 0);
   //Any error to report?
   if(error)
      return error;

   //CoAP over DTLS
   coapClientSetTransportProtocol(context, COAP_TRANSPORT_PROTOCOL_DTLS);
   //Register DTLS initialization callback
   coapClientRegisterDtlsInitCallback(context, coapTestDtlsInitCallback);

   //Set default timeout
   coapClientSetTimeout(context, 20000);

   //Debug message
   TRACE_INFO("Connecting to CoAP server %s...\r\n",
      ipAddrToString(&ipAddr, NULL));

   //Establish connection with the CoAP server
   error = coapClientConnect(context, &ipAddr, APP_COAP_SERVER_PORT);
   //Return status code
   return error;
}


/**
 * @brief CoAP test task
 * @param[in] param Unused parameter
 **/

void coapTestTask(void *param)
{
   error_t error;
   bool_t connectionState;
   uint_t buttonState;
   uint_t prevButtonState;
   Ipv4Addr ipv4Addr;

   //Initialize variables
   connectionState = FALSE;
   prevButtonState = 0;

   //Initialize CoAP client context
   coapClientInit(&coapClientContext);

   //Endless loop
   while(1)
   {
      //Check connection state
      if(!connectionState)
      {
         //Make sure the link is up
         if(netGetLinkState(&netInterface[0]))
         {
            //Retrieve host address
            ipv4GetHostAddr(&netInterface[0], &ipv4Addr);

            //Valid IP address assigned to the interface?
            if(ipv4Addr != IPV4_UNSPECIFIED_ADDR)
            {
               //Connect to the CoAP server
               error = coapTestConnect(&coapClientContext);

               //Successful connection?
               if(!error)
               {
                  //The CoAP client is connected to the server
                  connectionState = TRUE;
                  //Observable resource registration
                  coapTestObserve(&coapClientContext);
               }
               else
               {
                  //Delay between subsequent connection attempts
                  osDelayTask(2000);
               }
            }
            else
            {
               //No IP address assigned to the interface
               osDelayTask(1000);
            }
         }
         else
         {
            //The link is down
            osDelayTask(1000);
         }
      }
      else
      {
         //Initialize status code
         error = NO_ERROR;

         //Get BTN1 button state
         buttonState = !GPIO_PinInGet(BTN1_GPIO_PORT, BTN1_GPIO_PIN);

         //BTN1 button pressed?
         if(buttonState && !prevButtonState)
         {
#if 1
            //Send CoAP request (synchronous mode)
            coapTestRequestSync(&coapClientContext);
#else
            //Send CoAP request (asynchronous mode)
            coapTestRequestAsync(&coapClientContext);
#endif
         }

         //Save current state
         prevButtonState = buttonState;

         //Process events
         error = coapClientTask(&coapClientContext, 100);

         //Connection to CoAP server lost?
         if(error)
         {
            //Close connection
            coapClientDisconnect(&coapClientContext);
            //Update connection state
            connectionState = FALSE;
            //Recovery delay
            osDelayTask(2000);
         }
      }
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
   TRACE_INFO("*** CycloneTCP CoAPs Client Demo ***\r\n");
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

   //Set task parameters
   taskParams = OS_TASK_DEFAULT_PARAMS;
   taskParams.stackSize = 750;
   taskParams.priority = OS_TASK_PRIORITY_NORMAL;

   //Create CoAP test task
   taskId = osCreateTask("CoAP", coapTestTask, NULL, &taskParams);
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
