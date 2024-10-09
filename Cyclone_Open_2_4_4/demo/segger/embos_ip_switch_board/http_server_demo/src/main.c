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
#include "fsl_device_registers.h"
#include "fsl_cache.h"
#include "fsl_clock.h"
#include "fsl_gpio.h"
#include "fsl_port.h"
#include "fsl_smc.h"
#include "embos_ip_switch_board.h"
#include "core/net.h"
#include "drivers/mac/mk6x_eth_driver.h"
#include "drivers/switch/ksz8794_driver.h"
#include "dhcp/dhcp_client.h"
#include "ipv6/slaac.h"
#include "http/http_server.h"
#include "http/mime.h"
#include "path.h"
#include "date_time.h"
#include "resource_manager.h"
#include "spi_driver.h"
#include "debug.h"

//First Ethernet interface configuration
#define APP_IF1_NAME "eth1"
#define APP_IF1_HOST_NAME "http-server-demo-1"
#define APP_IF1_MAC_ADDR "00-AB-CD-66-18-01"

#define APP_IF1_USE_DHCP_CLIENT ENABLED
#define APP_IF1_IPV4_HOST_ADDR "192.168.0.21"
#define APP_IF1_IPV4_SUBNET_MASK "255.255.255.0"
#define APP_IF1_IPV4_DEFAULT_GATEWAY "192.168.0.254"
#define APP_IF1_IPV4_PRIMARY_DNS "8.8.8.8"
#define APP_IF1_IPV4_SECONDARY_DNS "8.8.4.4"

#define APP_IF1_USE_SLAAC ENABLED
#define APP_IF1_IPV6_LINK_LOCAL_ADDR "fe80::6618:1"

//Second Ethernet interface configuration
#define APP_IF2_NAME "eth2"
#define APP_IF2_HOST_NAME "http-server-demo-2"
#define APP_IF2_MAC_ADDR "00-AB-CD-66-18-02"

#define APP_IF2_USE_DHCP_CLIENT ENABLED
#define APP_IF2_IPV4_HOST_ADDR "192.168.0.22"
#define APP_IF2_IPV4_SUBNET_MASK "255.255.255.0"
#define APP_IF2_IPV4_DEFAULT_GATEWAY "192.168.0.254"
#define APP_IF2_IPV4_PRIMARY_DNS "8.8.8.8"
#define APP_IF2_IPV4_SECONDARY_DNS "8.8.4.4"

#define APP_IF2_USE_SLAAC ENABLED
#define APP_IF2_IPV6_LINK_LOCAL_ADDR "fe80::6618:3"

//Third Ethernet interface configuration
#define APP_IF3_NAME "eth3"
#define APP_IF3_HOST_NAME "http-server-demo-3"
#define APP_IF3_MAC_ADDR "00-AB-CD-66-18-03"

#define APP_IF3_USE_DHCP_CLIENT ENABLED
#define APP_IF3_IPV4_HOST_ADDR "192.168.0.23"
#define APP_IF3_IPV4_SUBNET_MASK "255.255.255.0"
#define APP_IF3_IPV4_DEFAULT_GATEWAY "192.168.0.254"
#define APP_IF3_IPV4_PRIMARY_DNS "8.8.8.8"
#define APP_IF3_IPV4_SECONDARY_DNS "8.8.4.4"

#define APP_IF3_USE_SLAAC ENABLED
#define APP_IF3_IPV6_LINK_LOCAL_ADDR "fe80::6618:3"

//Application configuration
#define APP_HTTP_MAX_CONNECTIONS 4

//Global variables
DhcpClientSettings dhcpClientSettings;
DhcpClientContext dhcpClientContext[3];
SlaacSettings slaacSettings;
SlaacContext slaacContext[3];
HttpServerSettings httpServerSettings;
HttpServerContext httpServerContext;
HttpConnection httpConnections[APP_HTTP_MAX_CONNECTIONS];

//Forward declaration of functions
error_t eth1InterfaceInit(void);
error_t eth2InterfaceInit(void);
error_t eth3InterfaceInit(void);

error_t httpServerCgiCallback(HttpConnection *connection,
   const char_t *param);

error_t httpServerRequestCallback(HttpConnection *connection,
   const char_t *uri);

error_t httpServerUriNotFoundCallback(HttpConnection *connection,
   const char_t *uri);


/**
 * @brief System clock initialization
 **/

void systemClockInit(void)
{
   osc_config_t oscConfig;
   mcg_config_t mcgConfig;
   sim_clock_config_t simConfig;

   //Set HSRUN power mode
   SMC_SetPowerModeProtection(SMC, kSMC_AllowPowerModeAll);
   SMC_SetPowerModeHsrun(SMC);

   while (SMC_GetPowerModeState(SMC) != kSMC_PowerStateHsrun)
   {
   }

   //Set the system clock dividers in SIM to safe value
   CLOCK_SetSimSafeDivs();

   //Initialize OSC0
   oscConfig.freq = 12000000;
   oscConfig.capLoad = 0;
   oscConfig.workMode = kOSC_ModeOscLowPower;
   oscConfig.oscerConfig.enableMode = kOSC_ErClkEnable;
   oscConfig.oscerConfig.erclkDiv = 0;

   CLOCK_InitOsc0(&oscConfig);
   CLOCK_SetXtal0Freq(oscConfig.freq);

   //Configure internal reference clock
   mcgConfig.mcgMode = kMCG_ModePEE;
   mcgConfig.irclkEnableMode = kMCG_IrclkEnable;
   mcgConfig.ircs = kMCG_IrcSlow;
   mcgConfig.fcrdiv = 1;
   mcgConfig.frdiv = 0;
   mcgConfig.drs = kMCG_DrsLow;
   mcgConfig.dmx32 = kMCG_Dmx32Default;
   mcgConfig.oscsel = kMCG_OscselOsc;
   mcgConfig.pll0Config.enableMode = 0;
   mcgConfig.pll0Config.prdiv = 0;
   mcgConfig.pll0Config.vdiv = 15;
   mcgConfig.pllcs = kMCG_PllClkSelPll0;

   CLOCK_SetInternalRefClkConfig(mcgConfig.irclkEnableMode, mcgConfig.ircs,
      mcgConfig.fcrdiv);

   CLOCK_BootToPeeMode(mcgConfig.oscsel, mcgConfig.pllcs,
      &mcgConfig.pll0Config);

   //Set clock configuration of SIM module
   simConfig.pllFllSel = 3;
   simConfig.pllFllDiv = 0;
   simConfig.pllFllFrac = 0;
   simConfig.er32kSrc = 2;
   simConfig.clkdiv1 = 0x2260000;

   CLOCK_SetSimConfig(&simConfig);

   //Set system core clock value
   SystemCoreClock = 180000000;

   //Configure peripheral clocks
   CLOCK_SetRtcClkOutClock(0);
   CLOCK_EnableUsbfs0Clock(kCLOCK_UsbSrcIrc48M, 48000000);
   CLOCK_SetEnetTime0Clock(0);
   CLOCK_SetRmii0Clock(1);
   CLOCK_SetSdhc0Clock(2);
   CLOCK_SetLpuartClock(2);
   CLOCK_SetTpmClock(1);
   CLOCK_SetClkOutClock(0);
   CLOCK_SetTraceClock(0, 1, 0);
}


/**
 * @brief I/O initialization
 **/

void ioInit(void)
{
   port_pin_config_t portPinConfig;
   gpio_pin_config_t gpioPinConfig;

   //Enable PORTA peripheral clock
   CLOCK_EnableClock(kCLOCK_PortA);

   //Set port pin configuration
   portPinConfig.pullSelect = kPORT_PullDisable;
   portPinConfig.slewRate = kPORT_FastSlewRate;
   portPinConfig.passiveFilterEnable = kPORT_PassiveFilterDisable;
   portPinConfig.openDrainEnable = kPORT_OpenDrainDisable;
   portPinConfig.driveStrength = kPORT_HighDriveStrength;
   portPinConfig.mux = kPORT_MuxAsGpio;
   portPinConfig.lockRegister = kPORT_UnlockRegister;

   //Set GPIO pin configuration
   gpioPinConfig.pinDirection = kGPIO_DigitalOutput;
   gpioPinConfig.outputLogic = 1;

   //Configure LED0
   PORT_SetPinConfig(LED0_PORT, LED0_PIN, &portPinConfig);
   GPIO_PinInit(LED0_GPIO, LED0_PIN, &gpioPinConfig);

   //Configure LED1
   PORT_SetPinConfig(LED1_PORT, LED1_PIN, &portPinConfig);
   GPIO_PinInit(LED1_GPIO, LED1_PIN, &gpioPinConfig);

   //Configure LED2
   PORT_SetPinConfig(LED2_PORT, LED2_PIN, &portPinConfig);
   GPIO_PinInit(LED2_GPIO, LED2_PIN, &gpioPinConfig);

   //Configure LED3
   PORT_SetPinConfig(LED3_PORT, LED3_PIN, &portPinConfig);
   GPIO_PinInit(LED3_GPIO, LED3_PIN, &gpioPinConfig);
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
      GPIO_PinWrite(LED1_GPIO, LED1_PIN, 0);
      osDelayTask(100);
      GPIO_PinWrite(LED1_GPIO, LED1_PIN, 1);
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

   //Initialize system core clock
   systemClockInit();
   //Enable code cache
   L1CACHE_EnableCodeCache();

   //Initialize kernel
   osInitKernel();
   //Configure debug UART
   debugInit(115200);

   //Start-up message
   TRACE_INFO("\r\n");
   TRACE_INFO("***********************************\r\n");
   TRACE_INFO("*** CycloneTCP HTTP Server Demo ***\r\n");
   TRACE_INFO("***********************************\r\n");
   TRACE_INFO("Copyright: 2010-2024 Oryx Embedded SARL\r\n");
   TRACE_INFO("Compiled: %s %s\r\n", __DATE__, __TIME__);
   TRACE_INFO("Target: MK66F18\r\n");
   TRACE_INFO("\r\n");

   //Configure I/Os
   ioInit();

   //TCP/IP stack initialization
   error = netInit();
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize TCP/IP stack!\r\n");
   }

   //Configure network interfaces
   eth1InterfaceInit();
#if (ETH_PORT_TAGGING_SUPPORT == ENABLED)
   eth2InterfaceInit();
   eth3InterfaceInit();
#endif

   //Get default settings
   httpServerGetDefaultSettings(&httpServerSettings);
   //Bind HTTP server to the desired interface
   httpServerSettings.interface = NULL;
   //Listen to port 80
   httpServerSettings.port = HTTP_PORT;
   //Client connections
   httpServerSettings.maxConnections = APP_HTTP_MAX_CONNECTIONS;
   httpServerSettings.connections = httpConnections;
   //Specify the server's root directory
   strcpy(httpServerSettings.rootDirectory, "/www/");
   //Set default home page
   strcpy(httpServerSettings.defaultDocument, "index.shtm");
   //Callback functions
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
 * @brief Initialization of the first Ethernet interface
 * @return Error code
 **/

error_t eth1InterfaceInit(void)
{
   error_t error;
   NetInterface *interface;
   MacAddr macAddr;
#if (APP_IF1_USE_DHCP_CLIENT == DISABLED)
   Ipv4Addr ipv4Addr;
#endif
#if (APP_IF1_USE_SLAAC == DISABLED)
   Ipv6Addr ipv6Addr;
#endif

   //Configure the first Ethernet interface
   interface = &netInterface[0];

   //Set interface name
   netSetInterfaceName(interface, APP_IF1_NAME);
   //Set host name
   netSetHostname(interface, APP_IF1_HOST_NAME);
   //Set host MAC address
   macStringToAddr(APP_IF1_MAC_ADDR, &macAddr);
   netSetMacAddr(interface, &macAddr);
   //Select the relevant network adapter
   netSetDriver(interface, &mk6xEthDriver);
   netSetSwitchDriver(interface, &ksz8794SwitchDriver);
   //Underlying SPI driver
   netSetSpiDriver(interface, &spiDriver);

#if (ETH_PORT_TAGGING_SUPPORT == ENABLED)
   //Enable tail tagging mode
   netSetSwitchPort(interface, KSZ8794_PORT1);
#endif

   //Initialize network interface
   error = netConfigInterface(interface);
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to configure interface %s!\r\n", interface->name);
      //Exit immediately
      return error;
   }

#if (IPV4_SUPPORT == ENABLED)
#if (APP_IF1_USE_DHCP_CLIENT == ENABLED)
   //Get default settings
   dhcpClientGetDefaultSettings(&dhcpClientSettings);
   //Set the network interface to be configured by DHCP
   dhcpClientSettings.interface = interface;
   //Disable rapid commit option
   dhcpClientSettings.rapidCommit = FALSE;

   //DHCP client initialization
   error = dhcpClientInit(&dhcpClientContext[0], &dhcpClientSettings);
   //Failed to initialize DHCP client?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize DHCP client!\r\n");
      //Exit immediately
      return error;
   }

   //Start DHCP client
   error = dhcpClientStart(&dhcpClientContext[0]);
   //Failed to start DHCP client?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start DHCP client!\r\n");
      //Exit immediately
      return error;
   }
#else
   //Set IPv4 host address
   ipv4StringToAddr(APP_IF1_IPV4_HOST_ADDR, &ipv4Addr);
   ipv4SetHostAddr(interface, ipv4Addr);

   //Set subnet mask
   ipv4StringToAddr(APP_IF1_IPV4_SUBNET_MASK, &ipv4Addr);
   ipv4SetSubnetMask(interface, ipv4Addr);

   //Set default gateway
   ipv4StringToAddr(APP_IF1_IPV4_DEFAULT_GATEWAY, &ipv4Addr);
   ipv4SetDefaultGateway(interface, ipv4Addr);

   //Set primary and secondary DNS servers
   ipv4StringToAddr(APP_IF1_IPV4_PRIMARY_DNS, &ipv4Addr);
   ipv4SetDnsServer(interface, 0, ipv4Addr);
   ipv4StringToAddr(APP_IF1_IPV4_SECONDARY_DNS, &ipv4Addr);
   ipv4SetDnsServer(interface, 1, ipv4Addr);
#endif
#endif

#if (IPV6_SUPPORT == ENABLED)
#if (APP_IF1_USE_SLAAC == ENABLED)
   //Get default settings
   slaacGetDefaultSettings(&slaacSettings);
   //Set the network interface to be configured
   slaacSettings.interface = interface;

   //SLAAC initialization
   error = slaacInit(&slaacContext[0], &slaacSettings);
   //Failed to initialize SLAAC?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize SLAAC!\r\n");
      //Exit immediately
      return error;
   }

   //Start IPv6 address autoconfiguration process
   error = slaacStart(&slaacContext[0]);
   //Failed to start SLAAC process?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start SLAAC!\r\n");
      //Exit immediately
      return error;
   }
#else
   //Set link-local address
   ipv6StringToAddr(APP_IF1_IPV6_LINK_LOCAL_ADDR, &ipv6Addr);
   ipv6SetLinkLocalAddr(interface, &ipv6Addr);
#endif
#endif

   //Successful initialization
   return NO_ERROR;
}


/**
 * @brief Initialization of the second Ethernet interface
 * @return Error code
 **/

error_t eth2InterfaceInit(void)
{
   error_t error;
   NetInterface *interface;
   NetInterface *physicalInterface;
   MacAddr macAddr;
#if (APP_IF2_USE_DHCP_CLIENT == DISABLED)
   Ipv4Addr ipv4Addr;
#endif
#if (APP_IF2_USE_SLAAC == DISABLED)
   Ipv6Addr ipv6Addr;
#endif

   //Configure the second Ethernet interface
   interface = &netInterface[1];
   //Point to the physical interface
   physicalInterface = &netInterface[0];

   //Set interface name
   netSetInterfaceName(interface, APP_IF2_NAME);
   //Set host name
   netSetHostname(interface, APP_IF2_HOST_NAME);
   //Set host MAC address
   macStringToAddr(APP_IF2_MAC_ADDR, &macAddr);
   netSetMacAddr(interface, &macAddr);

   //Enable tail tagging mode
   netSetSwitchPort(interface, KSZ8794_PORT2);
   //Attach the virtual interface to the relevant physical interface
   netSetParentInterface(interface, physicalInterface);

   //Initialize network interface
   error = netConfigInterface(interface);
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to configure interface %s!\r\n", interface->name);
      //Exit immediately
      return error;
   }

#if (IPV4_SUPPORT == ENABLED)
#if (APP_IF2_USE_DHCP_CLIENT == ENABLED)
   //Get default settings
   dhcpClientGetDefaultSettings(&dhcpClientSettings);
   //Set the network interface to be configured by DHCP
   dhcpClientSettings.interface = interface;
   //Disable rapid commit option
   dhcpClientSettings.rapidCommit = FALSE;

   //DHCP client initialization
   error = dhcpClientInit(&dhcpClientContext[1], &dhcpClientSettings);
   //Failed to initialize DHCP client?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize DHCP client!\r\n");
      //Exit immediately
      return error;
   }

   //Start DHCP client
   error = dhcpClientStart(&dhcpClientContext[1]);
   //Failed to start DHCP client?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start DHCP client!\r\n");
      //Exit immediately
      return error;
   }
#else
   //Set IPv4 host address
   ipv4StringToAddr(APP_IF2_IPV4_HOST_ADDR, &ipv4Addr);
   ipv4SetHostAddr(interface, ipv4Addr);

   //Set subnet mask
   ipv4StringToAddr(APP_IF2_IPV4_SUBNET_MASK, &ipv4Addr);
   ipv4SetSubnetMask(interface, ipv4Addr);

   //Set default gateway
   ipv4StringToAddr(APP_IF2_IPV4_DEFAULT_GATEWAY, &ipv4Addr);
   ipv4SetDefaultGateway(interface, ipv4Addr);

   //Set primary and secondary DNS servers
   ipv4StringToAddr(APP_IF2_IPV4_PRIMARY_DNS, &ipv4Addr);
   ipv4SetDnsServer(interface, 0, ipv4Addr);
   ipv4StringToAddr(APP_IF2_IPV4_SECONDARY_DNS, &ipv4Addr);
   ipv4SetDnsServer(interface, 1, ipv4Addr);
#endif
#endif

#if (IPV6_SUPPORT == ENABLED)
#if (APP_IF2_USE_SLAAC == ENABLED)
   //Get default settings
   slaacGetDefaultSettings(&slaacSettings);
   //Set the network interface to be configured
   slaacSettings.interface = interface;

   //SLAAC initialization
   error = slaacInit(&slaacContext[1], &slaacSettings);
   //Failed to initialize SLAAC?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize SLAAC!\r\n");
      //Exit immediately
      return error;
   }

   //Start IPv6 address autoconfiguration process
   error = slaacStart(&slaacContext[1]);
   //Failed to start SLAAC process?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start SLAAC!\r\n");
      //Exit immediately
      return error;
   }
#else
   //Set link-local address
   ipv6StringToAddr(APP_IF2_IPV6_LINK_LOCAL_ADDR, &ipv6Addr);
   ipv6SetLinkLocalAddr(interface, &ipv6Addr);
#endif
#endif

   //Successful initialization
   return NO_ERROR;
}


/**
 * @brief Initialization of the third Ethernet interface
 * @return Error code
 **/

error_t eth3InterfaceInit(void)
{
   error_t error;
   NetInterface *interface;
   NetInterface *physicalInterface;
   MacAddr macAddr;
#if (APP_IF3_USE_DHCP_CLIENT == DISABLED)
   Ipv4Addr ipv4Addr;
#endif
#if (APP_IF3_USE_SLAAC == DISABLED)
   Ipv6Addr ipv6Addr;
#endif

   //Configure the third Ethernet interface
   interface = &netInterface[2];
   //Point to the physical interface
   physicalInterface = &netInterface[0];

   //Set interface name
   netSetInterfaceName(interface, APP_IF3_NAME);
   //Set host name
   netSetHostname(interface, APP_IF3_HOST_NAME);
   //Set host MAC address
   macStringToAddr(APP_IF3_MAC_ADDR, &macAddr);
   netSetMacAddr(interface, &macAddr);

   //Enable tail tagging mode
   netSetSwitchPort(interface, KSZ8794_PORT3);
   //Attach the virtual interface to the relevant physical interface
   netSetParentInterface(interface, physicalInterface);

   //Initialize network interface
   error = netConfigInterface(interface);
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to configure interface %s!\r\n", interface->name);
      //Exit immediately
      return error;
   }

#if (IPV4_SUPPORT == ENABLED)
#if (APP_IF3_USE_DHCP_CLIENT == ENABLED)
   //Get default settings
   dhcpClientGetDefaultSettings(&dhcpClientSettings);
   //Set the network interface to be configured by DHCP
   dhcpClientSettings.interface = interface;
   //Disable rapid commit option
   dhcpClientSettings.rapidCommit = FALSE;

   //DHCP client initialization
   error = dhcpClientInit(&dhcpClientContext[2], &dhcpClientSettings);
   //Failed to initialize DHCP client?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize DHCP client!\r\n");
      //Exit immediately
      return error;
   }

   //Start DHCP client
   error = dhcpClientStart(&dhcpClientContext[2]);
   //Failed to start DHCP client?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start DHCP client!\r\n");
      //Exit immediately
      return error;
   }
#else
   //Set IPv4 host address
   ipv4StringToAddr(APP_IF3_IPV4_HOST_ADDR, &ipv4Addr);
   ipv4SetHostAddr(interface, ipv4Addr);

   //Set subnet mask
   ipv4StringToAddr(APP_IF3_IPV4_SUBNET_MASK, &ipv4Addr);
   ipv4SetSubnetMask(interface, ipv4Addr);

   //Set default gateway
   ipv4StringToAddr(APP_IF3_IPV4_DEFAULT_GATEWAY, &ipv4Addr);
   ipv4SetDefaultGateway(interface, ipv4Addr);

   //Set primary and secondary DNS servers
   ipv4StringToAddr(APP_IF3_IPV4_PRIMARY_DNS, &ipv4Addr);
   ipv4SetDnsServer(interface, 0, ipv4Addr);
   ipv4StringToAddr(APP_IF3_IPV4_SECONDARY_DNS, &ipv4Addr);
   ipv4SetDnsServer(interface, 1, ipv4Addr);
#endif
#endif

#if (IPV6_SUPPORT == ENABLED)
#if (APP_IF3_USE_SLAAC == ENABLED)
   //Get default settings
   slaacGetDefaultSettings(&slaacSettings);
   //Set the network interface to be configured
   slaacSettings.interface = interface;

   //SLAAC initialization
   error = slaacInit(&slaacContext[2], &slaacSettings);
   //Failed to initialize SLAAC?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize SLAAC!\r\n");
      //Exit immediately
      return error;
   }

   //Start IPv6 address autoconfiguration process
   error = slaacStart(&slaacContext[2]);
   //Failed to start SLAAC process?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start SLAAC!\r\n");
      //Exit immediately
      return error;
   }
#else
   //Set link-local address
   ipv6StringToAddr(APP_IF3_IPV6_LINK_LOCAL_ADDR, &ipv6Addr);
   ipv6SetLinkLocalAddr(interface, &ipv6Addr);
#endif
#endif

   //Successful initialization
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
   static uint_t pageCounter = 0;
   uint_t length;
   MacAddr macAddr;
#if (IPV4_SUPPORT == ENABLED)
   Ipv4Addr ipv4Addr;
#endif
#if (IPV6_SUPPORT == ENABLED)
   uint_t n;
   Ipv6Addr ipv6Addr;
#endif

   //Underlying network interface
   NetInterface *interface = connection->socket->interface;

   //Check parameter name
   if(!strcasecmp(param, "PAGE_COUNTER"))
   {
      pageCounter++;
      sprintf(connection->buffer, "%u time%s", pageCounter, (pageCounter >= 2) ? "s" : "");
   }
   else if(!strcasecmp(param, "BOARD_NAME"))
   {
      strcpy(connection->buffer, "embOS/IP Switch Board");
   }
   else if(!strcasecmp(param, "SYSTEM_TIME"))
   {
      systime_t time = osGetSystemTime();
      formatSystemTime(time, connection->buffer);
   }
   else if(!strcasecmp(param, "MAC_ADDR"))
   {
      netGetMacAddr(interface, &macAddr);
      macAddrToString(&macAddr, connection->buffer);
   }
   else if(!strcasecmp(param, "IPV4_ADDR"))
   {
      ipv4GetHostAddr(interface, &ipv4Addr);
      ipv4AddrToString(ipv4Addr, connection->buffer);
   }
   else if(!strcasecmp(param, "SUBNET_MASK"))
   {
      ipv4GetSubnetMask(interface, &ipv4Addr);
      ipv4AddrToString(ipv4Addr, connection->buffer);
   }
   else if(!strcasecmp(param, "DEFAULT_GATEWAY"))
   {
      ipv4GetDefaultGateway(interface, &ipv4Addr);
      ipv4AddrToString(ipv4Addr, connection->buffer);
   }
   else if(!strcasecmp(param, "IPV4_PRIMARY_DNS"))
   {
      ipv4GetDnsServer(interface, 0, &ipv4Addr);
      ipv4AddrToString(ipv4Addr, connection->buffer);
   }
   else if(!strcasecmp(param, "IPV4_SECONDARY_DNS"))
   {
      ipv4GetDnsServer(interface, 1, &ipv4Addr);
      ipv4AddrToString(ipv4Addr, connection->buffer);
   }
#if (IPV6_SUPPORT == ENABLED)
   else if(!strcasecmp(param, "LINK_LOCAL_ADDR"))
   {
      ipv6GetLinkLocalAddr(interface, &ipv6Addr);
      ipv6AddrToString(&ipv6Addr, connection->buffer);
   }
   else if(!strcasecmp(param, "GLOBAL_ADDR"))
   {
      ipv6GetGlobalAddr(interface, 0, &ipv6Addr);
      ipv6AddrToString(&ipv6Addr, connection->buffer);
   }
   else if(!strcasecmp(param, "IPV6_PREFIX"))
   {
      ipv6GetPrefix(interface, 0, &ipv6Addr, &n);
      ipv6AddrToString(&ipv6Addr, connection->buffer);
      length = strlen(connection->buffer);
      sprintf(connection->buffer + length, "/%u", n);
   }
   else if(!strcasecmp(param, "ROUTER"))
   {
      ipv6GetDefaultRouter(interface, 0, &ipv6Addr);
      ipv6AddrToString(&ipv6Addr, connection->buffer);
   }
   else if(!strcasecmp(param, "IPV6_PRIMARY_DNS"))
   {
      ipv6GetDnsServer(interface, 0, &ipv6Addr);
      ipv6AddrToString(&ipv6Addr, connection->buffer);
   }
   else if(!strcasecmp(param, "IPV6_SECONDARY_DNS"))
   {
      ipv6GetDnsServer(interface, 1, &ipv6Addr);
      ipv6AddrToString(&ipv6Addr, connection->buffer);
   }
#endif
   else
   {
      return ERROR_INVALID_TAG;
   }

   //Get the length of the resulting string
   length = strlen(connection->buffer);

   //Send the contents of the specified environment variable
   return httpWriteStream(connection, connection->buffer, length);
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
   //Not implemented
   return ERROR_NOT_FOUND;
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
