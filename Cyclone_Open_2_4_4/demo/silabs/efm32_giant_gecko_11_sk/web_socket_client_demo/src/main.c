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
#include "web_socket/web_socket.h"
#include "hardware/efm32gg11/efm32gg11_crypto.h"
#include "rng/trng.h"
#include "rng/yarrow.h"
#include "debug.h"

//Ethernet interface configuration
#define APP_IF_NAME "eth0"
#define APP_HOST_NAME "websocket-client-demo"
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
#define APP_WS_SERVER_NAME "socketsbay.com"
#define APP_WS_SERVER_PORT 443
#define APP_WS_SERVER_URI "/wss/v2/1/demo/"

#define APP_SET_CIPHER_SUITES DISABLED
#define APP_SET_SERVER_NAME DISABLED
#define APP_SET_TRUSTED_CA_LIST DISABLED

//Global variables
OsEvent appEvent;
bool_t buttonEventFlag;

DhcpClientSettings dhcpClientSettings;
DhcpClientContext dhcpClientContext;
SlaacSettings slaacSettings;
SlaacContext slaacContext;
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
 * @brief Random data generation callback function
 * @param[out] data Buffer where to store the random data
 * @param[in] length Number of bytes that are required
 * @return Error code
 **/

error_t webSocketClientRngCallback(uint8_t *data, size_t length)
{
   error_t error;

   //Generate some random data
   error = yarrowRead(&yarrowContext, data, length);
   //Return status code
   return error;
}


/**
 * @brief TLS initialization callback
 * @param[in] webSocket Handle referencing a WebSocket
 * @param[in] tlsContext Pointer to the TLS context
 * @return Error code
 **/

error_t webSocketClientTlsInitCallback(WebSocket *webSocket,
   TlsContext *tlsContext)
{
   error_t error;

   //Debug message
   TRACE_INFO("WebSocket: TLS initialization callback\r\n");

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
   error = tlsSetServerName(tlsContext, APP_WS_SERVER_NAME);
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
 * @brief WebSocket client test routine
 * @return Error code
 **/

error_t webSocketClientTest(void)
{
   error_t error;
   size_t length;
   systime_t timestamp;
   systime_t currentTime;
   WebSocket *webSocket;
   WebSocketFrameType type;
   IpAddr serverIpAddr;
   SocketEventDesc eventDesc[1];
   char_t buffer[256];

   //Debug message
   TRACE_INFO("\r\n\r\nWebSocket: Resolving server name...\r\n");

   //Resolve server name
   error = getHostByName(NULL, APP_WS_SERVER_NAME, &serverIpAddr, 0);

   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_INFO("WebSocket: Failed to resolve server name!\r\n");
      //Exit immediately
      return error;
   }

   //Open a new WebSocket
   webSocket = webSocketOpen();
   //Failed to open WebSocket?
   if(webSocket == NULL)
      return ERROR_OPEN_FAILED;

   //Start of exception handling block
   do
   {
      //Set timeout value for blocking operations
      error = webSocketSetTimeout(webSocket, 30000);
      //Any error to report?
      if(error)
         break;

      //Set the hostname of the remote server
      error = webSocketSetHost(webSocket, APP_WS_SERVER_NAME);
      //Any error to report?
      if(error)
         break;

#if (APP_WS_SERVER_PORT == 443)
      //Register TLS initialization callback
      error = webSocketRegisterTlsInitCallback(webSocket,
         webSocketClientTlsInitCallback);
      //Any error to report?
      if(error)
         return error;
#endif

      //Debug message
      TRACE_INFO("\r\nWebSocket: Connecting to server...\r\n");

      //Establish the WebSocket connection
      error = webSocketConnect(webSocket, &serverIpAddr,
         APP_WS_SERVER_PORT, APP_WS_SERVER_URI);
      //Any error to report?
      if(error)
         break;

      //Debug message
      TRACE_INFO("WebSocket: Connected to server\r\n");

      //Format message
      length = sprintf(buffer, "Hello World!");

      //Debug message
      TRACE_INFO("WebSocket: Sending message (%" PRIuSIZE " bytes)...\r\n", length);
      TRACE_INFO("  %s\r\n", buffer);

      //Send data to the WebSocket server
      error = webSocketSend(webSocket, buffer, length,
         WS_FRAME_TYPE_TEXT, NULL);
      //Any error to report?
      if(error)
         break;

      //Save current time
      timestamp = osGetSystemTime();

      //Process events
      while(1)
      {
         //Set the events the application is interested in
         eventDesc[0].socket = webSocket->socket;
         eventDesc[0].eventMask = SOCKET_EVENT_RX_READY;

         //Check whether application data are pending in the receive buffer
         if(webSocketIsRxReady(webSocket))
         {
            //No need to poll the underlying socket for incoming traffic...
            eventDesc[0].eventFlags = SOCKET_EVENT_RX_READY;
            error = NO_ERROR;
         }
         else
         {
            //Wait for incoming traffic from the remote host. A non-infinite timeout is provided
            //to manage the idle timeout (60s). refer to the end of the loop
            error = socketPoll(eventDesc, arraysize(eventDesc), &appEvent, 1000);
         }

         //Check status code
         if(error == NO_ERROR || error == ERROR_WAIT_CANCELED)
         {
            if(eventDesc[0].eventFlags & SOCKET_EVENT_RX_READY)
            {
               //Receive data from the remote WebSocket server
               error = webSocketReceive(webSocket, buffer,
                  sizeof(buffer) - 1, &type, &length);
               //Any error to report?
               if(error)
                  break;

               //Check the type of received data
               if(type == WS_FRAME_TYPE_TEXT ||
                  type == WS_FRAME_TYPE_BINARY)
               {
                  //Properly terminate the string with a NULL character
                  buffer[length] = '\0';

                  //Debug message
                  TRACE_INFO("WebSocket: Message received (%" PRIuSIZE " bytes)...\r\n", length);
                  TRACE_INFO("  %s\r\n", buffer);
               }
               else if(type == WS_FRAME_TYPE_PING)
               {
                  //Debug message
                  TRACE_INFO("WebSocket: Ping message received (%" PRIuSIZE " bytes)...\r\n", length);
                  //Debug message
                  TRACE_INFO("WebSocket: Sending pong message (%" PRIuSIZE " bytes)...\r\n", length);

                  //Send a Pong frame in response
                  error = webSocketSend(webSocket, buffer, length,
                     WS_FRAME_TYPE_PONG, NULL);
                  //Any error to report?
                  if(error)
                     break;
               }

               //Save current time
               timestamp = osGetSystemTime();
            }
         }

         //Check user button state
         if(buttonEventFlag)
         {
            //Clear flag
            buttonEventFlag = FALSE;

            //Format event message
            length = sprintf(buffer, "User button pressed!");

            //Debug message
            TRACE_INFO("WebSocket: Sending message (%" PRIuSIZE " bytes)...\r\n", length);
            TRACE_INFO("  %s\r\n", buffer);

            //Send a message to the WebSocket server
            error = webSocketSend(webSocket, buffer, length,
               WS_FRAME_TYPE_TEXT, NULL);
            //Any error to report?
            if(error)
               break;

            //Save current time
            timestamp = osGetSystemTime();
         }

         //Get current time
         currentTime = osGetSystemTime();

         //Manage idle timeout (if applicable)
         if(timeCompare(currentTime, timestamp + 60000) >= 0)
         {
            //Close WebSocket connection
            error = NO_ERROR;
            break;
         }
      }

      //Properly close the WebSocket connection
      webSocketShutdown(webSocket);

      //End of exception handling block
   } while(0);

   //Release the WebSocket
   webSocketClose(webSocket);

   //Return error code
   return error;
}


/**
 * @brief User task
 * @param[in] param Unused parameter
 **/

void userTask(void *param)
{
   //Endless loop
   while(1)
   {
      //Wait for the user button to be pressed
      osWaitForEvent(&appEvent, INFINITE_DELAY);

      //Clear flag
      buttonEventFlag = FALSE;

      //WebSocket client test routine
      webSocketClientTest();
   }
}


/**
 * @brief Button task
 **/

void buttonTask(void *param)
{
   bool_t state = FALSE;
   bool_t prevState = FALSE;

   //Endless loop
   while(1)
   {
      //Retrieve user button state
      state = !GPIO_PinInGet(BTN1_GPIO_PORT, BTN1_GPIO_PIN);

      //User button pressed?
      if(state && !prevState)
      {
         //Notify the WebSocket task of the event
         buttonEventFlag = TRUE;
         osSetEvent(&appEvent);
      }

      //Save current state
      prevState = state;

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
   TRACE_INFO("****************************************\r\n");
   TRACE_INFO("*** CycloneTCP WebSocket Client Demo ***\r\n");
   TRACE_INFO("****************************************\r\n");
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

   //Register RNG callback
   webSocketRegisterRandCallback(webSocketClientRngCallback);

   //Create an event object
   if(!osCreateEvent(&appEvent))
   {
      //Debug message
      TRACE_ERROR("Failed to create event!\r\n");
   }

   //Set task parameters
   taskParams = OS_TASK_DEFAULT_PARAMS;
   taskParams.stackSize = 500;
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
   taskParams.stackSize = 500;
   taskParams.priority = OS_TASK_PRIORITY_NORMAL;

   //Create a task to manage button events
   taskId = osCreateTask("Button", buttonTask, NULL, &taskParams);
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
