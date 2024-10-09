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
#include "ek_ra6m5.h"
#include "core/net.h"
#include "drivers/mac/ra6_eth_driver.h"
#include "drivers/phy/ksz8091_driver.h"
#include "dhcp/dhcp_client.h"
#include "ipv6/slaac.h"
#include "sntp/sntp_client.h"
#include "date_time.h"
#include "ext_int_driver.h"
#include "debug.h"

//Ethernet interface configuration
#define APP_IF_NAME "eth0"
#define APP_HOST_NAME "sntp-client-demo"
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
#define APP_NTP_SERVER_NAME "time.google.com"

//Global variables
DhcpClientSettings dhcpClientSettings;
DhcpClientContext dhcpClientContext;
SlaacSettings slaacSettings;
SlaacContext slaacContext;
SntpClientContext sntpClientContext;


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

   //Configure S1
   R_PFS->S1_PFS = 0;
   //Configure S2
   R_PFS->S2_PFS = 0;

   //Configure PHY reset pin
   R_PFS->PHY_RST_PFS = R_PFS_PORT_PIN_PmnPFS_PDR_Msk;

   //Lock PFS registers
   R_PMISC->PWPR &= ~R_PMISC_PWPR_PFSWE_Msk;
   R_PMISC->PWPR |= R_PMISC_PWPR_B0WI_Msk;

   //Clear LEDs
   LED1_PORT->PCNTR3 = LED1_MASK << R_PORT0_PCNTR3_PORR_Pos;
   LED2_PORT->PCNTR3 = LED2_MASK << R_PORT0_PCNTR3_PORR_Pos;
   LED3_PORT->PCNTR3 = LED3_MASK << R_PORT0_PCNTR3_PORR_Pos;

   //Reset PHY transceiver
   PHY_RST_PORT->PCNTR3 = PHY_RST_MASK << R_PORT0_PCNTR3_PORR_Pos;
   sleep(10);

   //Take the PHY transceiver out of reset
   PHY_RST_PORT->PCNTR3 = PHY_RST_MASK << R_PORT0_PCNTR3_POSR_Pos;
   sleep(10);
}


/**
 * @brief SNTP client test routine
 * @return Error code
 **/

error_t sntpClientTest(void)
{
   error_t error;
   uint32_t kissCode;
   time_t unixTime;
   DateTime date;
   IpAddr ipAddr;
   NtpTimestamp timestamp;

   //Initialize SNTP client context
   sntpClientInit(&sntpClientContext);

   //Start of exception handling block
   do
   {
      //Debug message
      TRACE_INFO("\r\n\r\nResolving server name...\r\n");

      //Resolve NTP server name
      error = getHostByName(NULL, APP_NTP_SERVER_NAME, &ipAddr, 0);
      //Any error to report?
      if(error)
      {
         //Debug message
         TRACE_INFO("Failed to resolve server name!\r\n");
         break;
      }

      //Set timeout value for blocking operations
      error = sntpClientSetTimeout(&sntpClientContext, 20000);
      //Any error to report?
      if(error)
         break;

      //Specify the IP address of the NTP server
      error = sntpClientSetServerAddr(&sntpClientContext, &ipAddr, NTP_PORT);
      //Any error to report?
      if(error)
         break;

      //Retrieve current time from NTP server
      error = sntpClientGetTimestamp(&sntpClientContext, &timestamp);

      //Check status code
      if(error == NO_ERROR)
      {
         //Unix time starts on January 1st, 1970
         unixTime = timestamp.seconds - NTP_UNIX_EPOCH;
         //Convert Unix timestamp to date
         convertUnixTimeToDate(unixTime, &date);

         //Debug message
         TRACE_INFO("Current date/time: %s\r\n", formatDate(&date, NULL));
      }
      else if(error == ERROR_REQUEST_REJECTED)
      {
         //Retrieve kiss code
         kissCode = sntpClientGetKissCode(&sntpClientContext);

         //Debug message
         TRACE_INFO("Kiss code: '%c%c%c%c'\r\n", (kissCode >> 24) & 0xFF,
            (kissCode >> 16) & 0xFF, (kissCode >> 8) & 0xFF, kissCode & 0xFF);
      }
      else
      {
         //Debug message
         TRACE_INFO("Failed to retrieve NTP timestamp!\r\n");
      }

      //End of exception handling block
   } while(0);

   //Release SNTP client context
   sntpClientDeinit(&sntpClientContext);

   //Return status code
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
      //S1 button pressed?
      if(!(S1_PORT->PCNTR2 & S1_MASK))
      {
         //SNTP client test routine
         sntpClientTest();

         //Wait for the S1 button to be released
         while(!(S1_PORT->PCNTR2 & S1_MASK));
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
   TRACE_INFO("***********************************\r\n");
   TRACE_INFO("*** CycloneTCP SNTP Client Demo ***\r\n");
   TRACE_INFO("***********************************\r\n");
   TRACE_INFO("Copyright: 2010-2024 Oryx Embedded SARL\r\n");
   TRACE_INFO("Compiled: %s %s\r\n", __DATE__, __TIME__);
   TRACE_INFO("Target: RA6M5\r\n");
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
   netSetPhyDriver(interface, &ksz8091PhyDriver);
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
