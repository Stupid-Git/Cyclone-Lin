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
#include "samg55_xplained_pro.h"
#include "driver/include/m2m_wifi.h"
#include "os/include/m2m_wifi_ex.h"
#include "core/net.h"
#include "drivers/wifi/winc1500_driver.h"
#include "dhcp/dhcp_client.h"
#include "ipv6/slaac.h"
#include "http/http_client.h"
#include "tls.h"
#include "tls_cipher_suites.h"
#include "rng/yarrow.h"
#include "debug.h"

//Wi-Fi interface configuration
#define APP_IF_NAME "wlan0"
#define APP_HOST_NAME "https-client-demo"
#define APP_MAC_ADDR "00-00-00-00-00-00"

#define APP_USE_DHCP_CLIENT ENABLED
#define APP_IPV4_HOST_ADDR "192.168.0.20"
#define APP_IPV4_SUBNET_MASK "255.255.255.0"
#define APP_IPV4_DEFAULT_GATEWAY "192.168.0.254"
#define APP_IPV4_PRIMARY_DNS "8.8.8.8"
#define APP_IPV4_SECONDARY_DNS "8.8.4.4"

#define APP_USE_SLAAC ENABLED
#define APP_IPV6_LINK_LOCAL_ADDR "fe80::1500"
#define APP_IPV6_PREFIX "2001:db8::"
#define APP_IPV6_PREFIX_LENGTH 64
#define APP_IPV6_GLOBAL_ADDR "2001:db8::1500"
#define APP_IPV6_ROUTER "fe80::1"
#define APP_IPV6_PRIMARY_DNS "2001:4860:4860::8888"
#define APP_IPV6_SECONDARY_DNS "2001:4860:4860::8844"

//Wi-Fi parameters
#define APP_WIFI_SSID "TEST_WINC1500_STA"
#define APP_WIFI_SECURITY M2M_WIFI_SEC_WPA_PSK
#define APP_WIFI_KEY "12345678"
#define APP_WIFI_CHANNEL M2M_WIFI_CH_ALL

//Application configuration
#define APP_HTTP_SERVER_NAME "www.httpbin.org"
#define APP_HTTP_SERVER_PORT 443
#define APP_HTTP_URI "/anything"

#define APP_SET_CIPHER_SUITES DISABLED
#define APP_SET_SERVER_NAME ENABLED
#define APP_SET_TRUSTED_CA_LIST ENABLED

//List of preferred ciphersuites
const uint16_t cipherSuites[] =
{
   TLS_CHACHA20_POLY1305_SHA256,
   TLS_AES_128_GCM_SHA256,
   TLS_AES_256_GCM_SHA384,
   TLS_ECDHE_ECDSA_WITH_CHACHA20_POLY1305_SHA256,
   TLS_ECDHE_RSA_WITH_CHACHA20_POLY1305_SHA256,
   TLS_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256,
   TLS_ECDHE_RSA_WITH_AES_128_GCM_SHA256,
   TLS_ECDHE_ECDSA_WITH_AES_256_GCM_SHA384,
   TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384,
   TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA,
   TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA,
   TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA,
   TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA,
   TLS_DHE_RSA_WITH_AES_128_GCM_SHA256,
   TLS_DHE_RSA_WITH_AES_256_GCM_SHA384,
   TLS_DHE_RSA_WITH_AES_128_CBC_SHA,
   TLS_DHE_RSA_WITH_AES_256_CBC_SHA,
   TLS_RSA_WITH_AES_128_GCM_SHA256,
   TLS_RSA_WITH_AES_256_GCM_SHA384,
   TLS_RSA_WITH_AES_128_CBC_SHA,
   TLS_RSA_WITH_AES_256_CBC_SHA,
   TLS_RSA_WITH_3DES_EDE_CBC_SHA
};

//List of trusted CA certificates
const char_t trustedCaList[] =
   "-----BEGIN CERTIFICATE-----"
   "MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF"
   "ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6"
   "b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL"
   "MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv"
   "b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj"
   "ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM"
   "9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw"
   "IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6"
   "VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L"
   "93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm"
   "jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC"
   "AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA"
   "A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI"
   "U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs"
   "N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv"
   "o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU"
   "5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy"
   "rqXRfboQnoZsG4q5WTP468SQvvG5"
   "-----END CERTIFICATE-----";

//Global variables
DhcpClientSettings dhcpClientSettings;
DhcpClientContext dhcpClientContext;
SlaacSettings slaacSettings;
SlaacContext slaacContext;
HttpClientContext httpClientContext;
YarrowContext yarrowContext;
uint8_t seed[32];

//Forward declaration of functions
void winc1500Connect(void);


/**
 * @brief I/O initialization
 **/

void ioInit(void)
{
   //Enable PIO peripheral clocks
   PMC_REGS->PMC_PCER0 = (1 << ID_PIOA);

   //Configure LED0
   PIO_LED0->PIO_PER = LED0;
   PIO_LED0->PIO_OER = LED0;
   PIO_LED0->PIO_SODR = LED0;

   //Configure SW0 button
   PIO_SW0->PIO_PER = SW0;
   PIO_SW0->PIO_ODR = SW0;
   PIO_SW0->PIO_PUER = SW0;
}


/**
 * @brief TLS initialization callback
 * @param[in] context Pointer to the HTTP client context
 * @param[in] tlsContext Pointer to the TLS context
 * @return Error code
 **/

error_t httpClientTlsInitCallback(HttpClientContext *context,
   TlsContext *tlsContext)
{
   error_t error;

   //Debug message
   TRACE_INFO("HTTP Client: TLS initialization callback\r\n");

   //Set the PRNG algorithm to be used
   error = tlsSetPrng(tlsContext, YARROW_PRNG_ALGO, &yarrowContext);
   //Any error to report?
   if(error)
      return error;

#if (APP_SET_CIPHER_SUITES == ENABLED)
   //Preferred cipher suite list
   error = tlsSetCipherSuites(tlsContext, cipherSuites, arraysize(cipherSuites));
   //Any error to report?
   if(error)
      return error;
#endif

#if (APP_SET_SERVER_NAME == ENABLED)
   //Set the fully qualified domain name of the server
   error = tlsSetServerName(tlsContext, APP_HTTP_SERVER_NAME);
   //Any error to report?
   if(error)
      return error;
#endif

#if (APP_SET_TRUSTED_CA_LIST == ENABLED)
   //Import the list of trusted CA certificates
   error = tlsSetTrustedCaList(tlsContext, trustedCaList, strlen(trustedCaList));
   //Any error to report?
   if(error)
      return error;
#endif

   //Successful processing
   return NO_ERROR;
}


/**
 * @brief HTTP client test routine
 * @return Error code
 **/

error_t httpClientTest(void)
{
   error_t error;
   size_t length;
   uint_t status;
   const char_t *value;
   IpAddr ipAddr;
   char_t buffer[128];

   //Initialize HTTP client context
   httpClientInit(&httpClientContext);

   //Start of exception handling block
   do
   {
      //Debug message
      TRACE_INFO("\r\n\r\nResolving server name...\r\n");

      //Resolve HTTP server name
      error = getHostByName(NULL, APP_HTTP_SERVER_NAME, &ipAddr, 0);
      //Any error to report?
      if(error)
      {
         //Debug message
         TRACE_INFO("Failed to resolve server name!\r\n");
         break;
      }

#if (APP_HTTP_SERVER_PORT == 443)
      //Register TLS initialization callback
      error = httpClientRegisterTlsInitCallback(&httpClientContext,
         httpClientTlsInitCallback);
      //Any error to report?
      if(error)
         break;
#endif

      //Select HTTP protocol version
      error = httpClientSetVersion(&httpClientContext, HTTP_VERSION_1_1);
      //Any error to report?
      if(error)
         break;

      //Set timeout value for blocking operations
      error = httpClientSetTimeout(&httpClientContext, 20000);
      //Any error to report?
      if(error)
         break;

      //Debug message
      TRACE_INFO("Connecting to HTTP server %s...\r\n",
         ipAddrToString(&ipAddr, NULL));

      //Connect to the HTTP server
      error = httpClientConnect(&httpClientContext, &ipAddr,
         APP_HTTP_SERVER_PORT);
      //Any error to report?
      if(error)
      {
         //Debug message
         TRACE_INFO("Failed to connect to HTTP server!\r\n");
         break;
      }

      //Create an HTTP request
      httpClientCreateRequest(&httpClientContext);
      httpClientSetMethod(&httpClientContext, "POST");
      httpClientSetUri(&httpClientContext, APP_HTTP_URI);

      //Set query string
      httpClientAddQueryParam(&httpClientContext, "param1", "value1");
      httpClientAddQueryParam(&httpClientContext, "param2", "value2");

      //Add HTTP header fields
      httpClientAddHeaderField(&httpClientContext, "Host", APP_HTTP_SERVER_NAME);
      httpClientAddHeaderField(&httpClientContext, "User-Agent", "Mozilla/5.0");
      httpClientAddHeaderField(&httpClientContext, "Content-Type", "text/plain");
      httpClientAddHeaderField(&httpClientContext, "Transfer-Encoding", "chunked");

      //Send HTTP request header
      error = httpClientWriteHeader(&httpClientContext);
      //Any error to report?
      if(error)
      {
         //Debug message
         TRACE_INFO("Failed to write HTTP request header!\r\n");
         break;
      }

      //Send HTTP request body
      error = httpClientWriteBody(&httpClientContext, "Hello World!", 12,
         NULL, 0);
      //Any error to report?
      if(error)
      {
         //Debug message
         TRACE_INFO("Failed to write HTTP request body!\r\n");
         break;
      }

      //Receive HTTP response header
      error = httpClientReadHeader(&httpClientContext);
      //Any error to report?
      if(error)
      {
         //Debug message
         TRACE_INFO("Failed to read HTTP response header!\r\n");
         break;
      }

      //Retrieve HTTP status code
      status = httpClientGetStatus(&httpClientContext);
      //Debug message
      TRACE_INFO("HTTP status code: %u\r\n", status);

      //Retrieve the value of the Content-Type header field
      value = httpClientGetHeaderField(&httpClientContext, "Content-Type");

      //Header field found?
      if(value != NULL)
      {
         //Debug message
         TRACE_INFO("Content-Type header field value: %s\r\n", value);
      }
      else
      {
         //Debug message
         TRACE_INFO("Content-Type header field not found!\r\n");
      }

      //Receive HTTP response body
      while(!error)
      {
         //Read data
         error = httpClientReadBody(&httpClientContext, buffer,
            sizeof(buffer) - 1, &length, 0);

         //Check status code
         if(!error)
         {
            //Properly terminate the string with a NULL character
            buffer[length] = '\0';
            //Dump HTTP response body
            TRACE_INFO("%s", buffer);
         }
      }

      //Terminate the HTTP response body with a CRLF
      TRACE_INFO("\r\n");

      //Any error to report?
      if(error != ERROR_END_OF_STREAM)
         break;

      //Close HTTP response body
      error = httpClientCloseBody(&httpClientContext);
      //Any error to report?
      if(error)
      {
         //Debug message
         TRACE_INFO("Failed to read HTTP response trailer!\r\n");
         break;
      }

      //Gracefully disconnect from the HTTP server
      httpClientDisconnect(&httpClientContext);

      //Debug message
      TRACE_INFO("Connection closed\r\n");

      //End of exception handling block
   } while(0);

   //Release HTTP client context
   httpClientDeinit(&httpClientContext);

   //Return status code
   return error;
}


/**
 * @brief User task
 * @param[in] param Unused parameter
 **/

void userTask(void *param)
{
   //Connect to the Wi-Fi network
   winc1500Connect();

   //Endless loop
   while(1)
   {
      //User button pressed?
      if(!(PIO_SW0->PIO_PDSR & SW0))
      {
         //HTTP client test routine
         httpClientTest();

         //Wait for the user button to be released
         while(!(PIO_SW0->PIO_PDSR & SW0));
      }

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

   //Update system core clock
   SystemCoreClockUpdate();

   //Initialize kernel
   osInitKernel();
   //Configure debug UART
   debugInit(115200);

   //Start-up message
   TRACE_INFO("\r\n");
   TRACE_INFO("******************************************\r\n");
   TRACE_INFO("*** CycloneTCP Wi-Fi HTTPS Client Demo ***\r\n");
   TRACE_INFO("******************************************\r\n");
   TRACE_INFO("Copyright: 2010-2024 Oryx Embedded SARL\r\n");
   TRACE_INFO("Compiled: %s %s\r\n", __DATE__, __TIME__);
   TRACE_INFO("Target: SAMG55\r\n");
   TRACE_INFO("\r\n");

   //Configure I/Os
   ioInit();

   //Generate a random seed

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

   //Configure Wi-Fi interface
   interface = &netInterface[0];

   //Set interface name
   netSetInterfaceName(interface, APP_IF_NAME);
   //Set host name
   netSetHostname(interface, APP_HOST_NAME);
   //Set host MAC address
   macStringToAddr(APP_MAC_ADDR, &macAddr);
   netSetMacAddr(interface, &macAddr);
   //Select the relevant network adapter
   netSetDriver(interface, &winc1500Driver);

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

   //Create user task
   taskId = osCreateTask("User", userTask, NULL, &taskParams);
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
 * @brief Connect to Wi-Fi network (STA mode)
 **/

void winc1500Connect(void)
{
   int8_t status;

   //Debug message
   TRACE_INFO("WINC1500: Connecting to Wi-Fi network (%s)...\r\n", APP_WIFI_SSID);

   //Security scheme?
   if(APP_WIFI_SECURITY == M2M_WIFI_SEC_OPEN)
   {
      //Connect to the specified network (open)
      status = os_m2m_wifi_connect(APP_WIFI_SSID, strlen(APP_WIFI_SSID),
         M2M_WIFI_SEC_OPEN, NULL, APP_WIFI_CHANNEL);
   }
   else if(APP_WIFI_SECURITY == M2M_WIFI_SEC_WEP)
   {
      tstrM2mWifiWepParams wepParams;

      //Set WEP parameters
      wepParams.u8KeyIndx = M2M_WIFI_WEP_KEY_INDEX_1;
      wepParams.u8KeySz = strlen(APP_WIFI_KEY) + 1;
      strcpy((char_t *) wepParams.au8WepKey, APP_WIFI_KEY);

      //Connect to the specified network (WEP)
      status = os_m2m_wifi_connect(APP_WIFI_SSID, strlen(APP_WIFI_SSID),
         M2M_WIFI_SEC_WEP, &wepParams, APP_WIFI_CHANNEL);
   }
   else if(APP_WIFI_SECURITY == M2M_WIFI_SEC_WPA_PSK)
   {
      //Connect to the specified network (WPA/WPA2 personnal)
      status = os_m2m_wifi_connect(APP_WIFI_SSID, strlen(APP_WIFI_SSID),
         M2M_WIFI_SEC_WPA_PSK, APP_WIFI_KEY, APP_WIFI_CHANNEL);
   }

   //Debug message
   TRACE_INFO("  os_m2m_wifi_connect = %d\r\n", status);

   //Delay required before sending a new command
   osDelayTask(200);
}


/**
 * @brief Callback function that processes Wi-Fi event notifications
 * @param[in] msgType Type of notification
 * @param[in] msg Pointer to the buffer containing the notification parameters
 **/

void winc1500EventHook(uint8_t msgType, void *msg)
{
   tstrM2mWifiStateChanged *stateChangedMsg;

   //Debug message
   TRACE_INFO("WINC1500: Wi-Fi event hook\r\n");

   //Check message type
   if(msgType == M2M_WIFI_RESP_CON_STATE_CHANGED)
   {
      //Connection state
      stateChangedMsg = (tstrM2mWifiStateChanged *) msg;

      //Check link state
      if(stateChangedMsg->u8CurrState == M2M_WIFI_CONNECTED)
      {
      }
      else
      {
         //Reconnect to the specified Wi-Fi network
         winc1500Connect();
      }
   }
}
