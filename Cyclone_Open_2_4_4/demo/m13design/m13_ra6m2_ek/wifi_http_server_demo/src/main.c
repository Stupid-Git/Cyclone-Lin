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
#include "m13_ra6m2_ek.h"
#include "core/net.h"
#include "drivers/mac/ra6_eth_driver.h"
#include "drivers/phy/ksz8081_driver.h"
#include "drivers/wifi/wilc1000_driver.h"
#include "dhcp/dhcp_client.h"
#include "dhcp/dhcp_server.h"
#include "ipv6/slaac.h"
#include "ipv6/ndp_router_adv.h"
#include "http/http_server.h"
#include "http/mime.h"
#include "path.h"
#include "date_time.h"
#include "resource_manager.h"
#include "smi_driver.h"
#include "wsen_itds.h"
#include "debug.h"

//Ethernet interface configuration
#define APP_IF0_NAME "eth0"
#define APP_IF0_HOST_NAME "http-server-demo"
#define APP_IF0_MAC_ADDR "00-AB-CD-EF-00-A6"

#define APP_IF0_USE_DHCP_CLIENT ENABLED
#define APP_IF0_IPV4_HOST_ADDR "192.168.0.20"
#define APP_IF0_IPV4_SUBNET_MASK "255.255.255.0"
#define APP_IF0_IPV4_DEFAULT_GATEWAY "192.168.0.254"
#define APP_IF0_IPV4_PRIMARY_DNS "8.8.8.8"
#define APP_IF0_IPV4_SECONDARY_DNS "8.8.4.4"

#define APP_IF0_USE_SLAAC ENABLED
#define APP_IF0_IPV6_LINK_LOCAL_ADDR "fe80::a6:0"

//First Wi-Fi interface (STA mode) configuration
#define APP_IF1_NAME "wlan0"
#define APP_IF1_HOST_NAME "http-server-demo"
#define APP_IF1_MAC_ADDR "00-00-00-00-00-00"

#define APP_IF1_USE_DHCP_CLIENT ENABLED
#define APP_IF1_IPV4_HOST_ADDR "192.168.0.20"
#define APP_IF1_IPV4_SUBNET_MASK "255.255.255.0"
#define APP_IF1_IPV4_DEFAULT_GATEWAY "192.168.0.254"
#define APP_IF1_IPV4_PRIMARY_DNS "8.8.8.8"
#define APP_IF1_IPV4_SECONDARY_DNS "8.8.4.4"

#define APP_IF1_USE_SLAAC ENABLED
#define APP_IF1_IPV6_LINK_LOCAL_ADDR "fe80::a6:1"

//Second Wi-Fi interface (AP mode) configuration
#define APP_IF2_NAME "wlan1"
#define APP_IF2_HOST_NAME "http-server-demo"
#define APP_IF2_MAC_ADDR "00-00-00-00-00-00"

#define APP_IF2_USE_DHCP_SERVER ENABLED
#define APP_IF2_IPV4_HOST_ADDR "192.168.8.1"
#define APP_IF2_IPV4_SUBNET_MASK "255.255.255.0"
#define APP_IF2_IPV4_DEFAULT_GATEWAY "0.0.0.0"
#define APP_IF2_IPV4_PRIMARY_DNS "0.0.0.0"
#define APP_IF2_IPV4_SECONDARY_DNS "0.0.0.0"
#define APP_IF2_IPV4_ADDR_RANGE_MIN "192.168.8.10"
#define APP_IF2_IPV4_ADDR_RANGE_MAX "192.168.8.99"

#define APP_IF2_USE_ROUTER_ADV ENABLED
#define APP_IF2_IPV6_LINK_LOCAL_ADDR "fe80::a6:2"
#define APP_IF2_IPV6_PREFIX "fd00:1:2:3::"
#define APP_IF2_IPV6_PREFIX_LENGTH 64
#define APP_IF2_IPV6_GLOBAL_ADDR "fd00:1:2:3::a6:2"

//Application configuration
#define APP_HTTP_MAX_CONNECTIONS 4

//Global variables
uint_t adcValue = 0;
int8_t ax = 0;
int8_t ay = 0;
int8_t az = 0;

DhcpClientSettings dhcpClientSettings;
DhcpClientContext dhcpClientContext[2];
DhcpServerSettings dhcpServerSettings;
DhcpServerContext dhcpServerContext;
SlaacSettings slaacSettings;
SlaacContext slaacContext[2];
NdpRouterAdvSettings ndpRouterAdvSettings;
NdpRouterAdvPrefixInfo ndpRouterAdvPrefixInfo[1];
NdpRouterAdvContext ndpRouterAdvContext;
HttpServerSettings httpServerSettings;
HttpServerContext httpServerContext;
HttpConnection httpConnections[APP_HTTP_MAX_CONNECTIONS];

//Forward declaration of functions
error_t ethInterfaceInit(void);
error_t wifiStaInterfaceInit(void);
error_t wifiApInterfaceInit(void);

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

   //Configure SW1
   R_PFS->SW1_PFS = 0;

   //Lock PFS registers
   R_PMISC->PWPR &= ~R_PMISC_PWPR_PFSWE_Msk;
   R_PMISC->PWPR |= R_PMISC_PWPR_B0WI_Msk;

   //Clear LEDs
   LED1_PORT->PCNTR3 = LED1_MASK << R_PORT0_PCNTR3_PORR_Pos;
   LED2_PORT->PCNTR3 = LED2_MASK << R_PORT0_PCNTR3_PORR_Pos;
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

   //Initialize kernel
   osInitKernel();
   //Configure debug UART
   debugInit(115200);

   //Start-up message
   TRACE_INFO("\r\n");
   TRACE_INFO("*****************************************\r\n");
   TRACE_INFO("*** CycloneTCP Wi-Fi HTTP Server Demo ***\r\n");
   TRACE_INFO("*****************************************\r\n");
   TRACE_INFO("Copyright: 2010-2024 Oryx Embedded SARL\r\n");
   TRACE_INFO("Compiled: %s %s\r\n", __DATE__, __TIME__);
   TRACE_INFO("Target: RA6M2\r\n");
   TRACE_INFO("\r\n");

   //Configure I/Os
   ioInit();
   //ADC initialization
   adcInit();

   //Initialize WSEN-ITDS sensor
   wsenItdsInit();

   //TCP/IP stack initialization
   error = netInit();
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize TCP/IP stack!\r\n");
   }

   //Configure the first network interface (Ethernet 10/100)
   ethInterfaceInit();

   //Configure the second network interface (Wi-Fi STA mode)
   wifiStaInterfaceInit();

   //Configure the third network interface (Wi-Fi AP mode)
   wifiApInterfaceInit();

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
   strcpy(httpServerSettings.defaultDocument, "index.htm");
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
 * @brief Ethernet interface initialization
 **/

error_t ethInterfaceInit(void)
{
   error_t error;
   NetInterface *interface;
   MacAddr macAddr;
#if (APP_IF0_USE_DHCP_CLIENT == DISABLED)
   Ipv4Addr ipv4Addr;
#endif
#if (APP_IF0_USE_SLAAC == DISABLED)
   Ipv6Addr ipv6Addr;
#endif

   //Configure the first network interface (Ethernet 10/100)
   interface = &netInterface[0];

   //Set interface name
   netSetInterfaceName(interface, APP_IF0_NAME);
   //Set host name
   netSetHostname(interface, APP_IF0_HOST_NAME);
   //Set host MAC address
   macStringToAddr(APP_IF0_MAC_ADDR, &macAddr);
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
      //Exit immediately
      return error;
   }

#if (IPV4_SUPPORT == ENABLED)
#if (APP_IF0_USE_DHCP_CLIENT == ENABLED)
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
   ipv4StringToAddr(APP_IF0_IPV4_HOST_ADDR, &ipv4Addr);
   ipv4SetHostAddr(interface, ipv4Addr);

   //Set subnet mask
   ipv4StringToAddr(APP_IF0_IPV4_SUBNET_MASK, &ipv4Addr);
   ipv4SetSubnetMask(interface, ipv4Addr);

   //Set default gateway
   ipv4StringToAddr(APP_IF0_IPV4_DEFAULT_GATEWAY, &ipv4Addr);
   ipv4SetDefaultGateway(interface, ipv4Addr);

   //Set primary and secondary DNS servers
   ipv4StringToAddr(APP_IF0_IPV4_PRIMARY_DNS, &ipv4Addr);
   ipv4SetDnsServer(interface, 0, ipv4Addr);
   ipv4StringToAddr(APP_IF0_IPV4_SECONDARY_DNS, &ipv4Addr);
   ipv4SetDnsServer(interface, 1, ipv4Addr);
#endif
#endif

#if (IPV6_SUPPORT == ENABLED)
#if (APP_IF0_USE_SLAAC == ENABLED)
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
   ipv6StringToAddr(APP_IF0_IPV6_LINK_LOCAL_ADDR, &ipv6Addr);
   ipv6SetLinkLocalAddr(interface, &ipv6Addr);
#endif
#endif

   //Successful initialization
   return NO_ERROR;
}


/**
 * @brief Wi-Fi STA interface initialization
 **/

error_t wifiStaInterfaceInit(void)
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

   //Configure the second network interface (Wi-Fi STA mode)
   interface = &netInterface[1];

   //Set interface name
   netSetInterfaceName(interface, APP_IF1_NAME);
   //Set host name
   netSetHostname(interface, APP_IF1_HOST_NAME);
   //Set host MAC address
   macStringToAddr(APP_IF1_MAC_ADDR, &macAddr);
   netSetMacAddr(interface, &macAddr);
   //Select the relevant network adapter
   netSetDriver(interface, &wilc1000StaDriver);

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
   ipv6StringToAddr(APP_IF1_IPV6_LINK_LOCAL_ADDR, &ipv6Addr);
   ipv6SetLinkLocalAddr(interface, &ipv6Addr);
#endif
#endif

   //Successful initialization
   return NO_ERROR;
}


/**
 * @brief Wi-Fi AP interface initialization
 **/

error_t wifiApInterfaceInit(void)
{
   error_t error;
   NetInterface *interface;
   MacAddr macAddr;
   Ipv4Addr ipv4Addr;
   Ipv6Addr ipv6Addr;

   //Configure the third network interface (Wi-Fi AP mode)
   interface = &netInterface[2];

   //Set interface name
   netSetInterfaceName(interface, APP_IF2_NAME);
   //Set host name
   netSetHostname(interface, APP_IF2_HOST_NAME);
   //Set host MAC address
   macStringToAddr(APP_IF2_MAC_ADDR, &macAddr);
   netSetMacAddr(interface, &macAddr);
   //Select the relevant network adapter
   netSetDriver(interface, &wilc1000ApDriver);

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

#if (APP_IF2_USE_DHCP_SERVER == ENABLED)
   //Get default settings
   dhcpServerGetDefaultSettings(&dhcpServerSettings);
   //Set the network interface to be configured by DHCP
   dhcpServerSettings.interface = interface;
   //Lease time, in seconds, assigned to the DHCP clients
   dhcpServerSettings.leaseTime = 3600;

   //Lowest and highest IP addresses in the pool that are available
   //for dynamic address assignment
   ipv4StringToAddr(APP_IF2_IPV4_ADDR_RANGE_MIN, &dhcpServerSettings.ipAddrRangeMin);
   ipv4StringToAddr(APP_IF2_IPV4_ADDR_RANGE_MAX, &dhcpServerSettings.ipAddrRangeMax);

   //Subnet mask
   ipv4StringToAddr(APP_IF2_IPV4_SUBNET_MASK, &dhcpServerSettings.subnetMask);
   //Default gateway
   ipv4StringToAddr(APP_IF2_IPV4_DEFAULT_GATEWAY, &dhcpServerSettings.defaultGateway);
   //DNS servers
   ipv4StringToAddr(APP_IF2_IPV4_PRIMARY_DNS, &dhcpServerSettings.dnsServer[0]);
   ipv4StringToAddr(APP_IF2_IPV4_SECONDARY_DNS, &dhcpServerSettings.dnsServer[1]);

   //DHCP server initialization
   error = dhcpServerInit(&dhcpServerContext, &dhcpServerSettings);
   //Failed to initialize DHCP client?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize DHCP server!\r\n");
      //Exit immediately
      return error;
   }

   //Start DHCP server
   error = dhcpServerStart(&dhcpServerContext);
   //Failed to start DHCP client?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start DHCP server!\r\n");
      //Exit immediately
      return error;
   }
#endif
#endif

#if (IPV6_SUPPORT == ENABLED)
   //Set link-local address
   ipv6StringToAddr(APP_IF2_IPV6_LINK_LOCAL_ADDR, &ipv6Addr);
   ipv6SetLinkLocalAddr(interface, &ipv6Addr);

   //Set IPv6 prefix
   ipv6StringToAddr(APP_IF2_IPV6_PREFIX, &ipv6Addr);
   ipv6SetPrefix(interface, 0, &ipv6Addr, APP_IF2_IPV6_PREFIX_LENGTH);

   //Set global address
   ipv6StringToAddr(APP_IF2_IPV6_GLOBAL_ADDR, &ipv6Addr);
   ipv6SetGlobalAddr(interface, 0, &ipv6Addr);

#if (APP_IF2_USE_ROUTER_ADV == ENABLED)
   //List of IPv6 prefixes to be advertised
   ipv6StringToAddr(APP_IF2_IPV6_PREFIX, &ndpRouterAdvPrefixInfo[0].prefix);
   ndpRouterAdvPrefixInfo[0].length = APP_IF2_IPV6_PREFIX_LENGTH;
   ndpRouterAdvPrefixInfo[0].onLinkFlag = TRUE;
   ndpRouterAdvPrefixInfo[0].autonomousFlag = TRUE;
   ndpRouterAdvPrefixInfo[0].validLifetime = 3600;
   ndpRouterAdvPrefixInfo[0].preferredLifetime = 1800;

   //Get default settings
   ndpRouterAdvGetDefaultSettings(&ndpRouterAdvSettings);
   //Set the underlying network interface
   ndpRouterAdvSettings.interface = interface;
   //Maximum time interval between unsolicited Router Advertisements
   ndpRouterAdvSettings.maxRtrAdvInterval = 60000;
   //Minimum time interval between unsolicited Router Advertisements
   ndpRouterAdvSettings.minRtrAdvInterval = 20000;
   //Router lifetime
   ndpRouterAdvSettings.defaultLifetime = 0;
   //List of IPv6 prefixes
   ndpRouterAdvSettings.prefixList = ndpRouterAdvPrefixInfo;
   ndpRouterAdvSettings.prefixListLength = arraysize(ndpRouterAdvPrefixInfo);

   //RA service initialization
   error = ndpRouterAdvInit(&ndpRouterAdvContext, &ndpRouterAdvSettings);
   //Failed to initialize DHCPv6 client?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize RA service!\r\n");
      //Exit immediately
      return error;
   }

   //Start RA service
   error = ndpRouterAdvStart(&ndpRouterAdvContext);
   //Failed to start RA service?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start RA service!\r\n");
      //Exit immediately
      return error;
   }
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
