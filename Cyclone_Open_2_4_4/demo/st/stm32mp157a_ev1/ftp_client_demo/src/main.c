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
#include "stm32mp1xx.h"
#include "stm32mp1xx_hal.h"
#include "stm32mp15xx_eval.h"
#include "core/net.h"
#include "drivers/mac/stm32mp1xx_eth_driver.h"
#include "drivers/phy/rtl8211e_driver.h"
#include "dhcp/dhcp_client.h"
#include "ipv6/slaac.h"
#include "ftp/ftp_client.h"
#include "debug.h"

//Ethernet interface configuration
#define APP_IF_NAME "eth0"
#define APP_HOST_NAME "ftp-client-demo"
#define APP_MAC_ADDR "00-AB-CD-EF-01-57"

#define APP_USE_DHCP_CLIENT ENABLED
#define APP_IPV4_HOST_ADDR "192.168.0.20"
#define APP_IPV4_SUBNET_MASK "255.255.255.0"
#define APP_IPV4_DEFAULT_GATEWAY "192.168.0.254"
#define APP_IPV4_PRIMARY_DNS "8.8.8.8"
#define APP_IPV4_SECONDARY_DNS "8.8.4.4"

#define APP_USE_SLAAC ENABLED
#define APP_IPV6_LINK_LOCAL_ADDR "fe80::157"
#define APP_IPV6_PREFIX "2001:db8::"
#define APP_IPV6_PREFIX_LENGTH 64
#define APP_IPV6_GLOBAL_ADDR "2001:db8::157"
#define APP_IPV6_ROUTER "fe80::1"
#define APP_IPV6_PRIMARY_DNS "2001:4860:4860::8888"
#define APP_IPV6_SECONDARY_DNS "2001:4860:4860::8844"

//Application configuration
#define APP_FTP_SERVER_NAME "test.rebex.net"
#define APP_FTP_SERVER_PORT 21
#define APP_FTP_LOGIN "demo"
#define APP_FTP_PASSWORD "password"
#define APP_FTP_FILENAME "readme.txt"

//Global variables
DhcpClientSettings dhcpClientSettings;
DhcpClientContext dhcpClientContext;
SlaacSettings slaacSettings;
SlaacContext slaacContext;
FtpClientContext ftpClientContext;


/**
 * @brief System clock configuration
 **/

void SystemClock_Config(void)
{
   RCC_OscInitTypeDef RCC_OscInitStruct = {0};
   RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
   RCC_PeriphCLKInitTypeDef RCC_PeriphClkInitStruct = {0};

   //Enable access to the backup domain
   HAL_PWR_EnableBkUpAccess();

   //Configure LSE drive capability
   __HAL_RCC_LSEDRIVE_CONFIG(RCC_LSEDRIVE_MEDIUMHIGH);

   //Initialize CPU, AHB and APB clocks
   RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI |
      RCC_OSCILLATORTYPE_HSE | RCC_OSCILLATORTYPE_LSE;

   RCC_OscInitStruct.HSEState = RCC_HSE_ON;
   RCC_OscInitStruct.LSEState = RCC_LSE_ON;
   RCC_OscInitStruct.HSIState = RCC_HSI_ON;
   RCC_OscInitStruct.HSICalibrationValue = 16;
   RCC_OscInitStruct.HSIDivValue = RCC_HSI_DIV1;

   //PLL1 configuration
   RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
   RCC_OscInitStruct.PLL.PLLSource = RCC_PLL12SOURCE_HSE;
   RCC_OscInitStruct.PLL.PLLM = 3;
   RCC_OscInitStruct.PLL.PLLN = 81;
   RCC_OscInitStruct.PLL.PLLP = 1;
   RCC_OscInitStruct.PLL.PLLQ = 1;
   RCC_OscInitStruct.PLL.PLLR = 1;
   RCC_OscInitStruct.PLL.PLLFRACV = 0x800;
   RCC_OscInitStruct.PLL.PLLMODE = RCC_PLL_FRACTIONAL;
   RCC_OscInitStruct.PLL.RPDFN_DIS = RCC_RPDFN_DIS_DISABLED;
   RCC_OscInitStruct.PLL.TPDFN_DIS = RCC_TPDFN_DIS_DISABLED;

   //PLL2 configuration
   RCC_OscInitStruct.PLL2.PLLState = RCC_PLL_ON;
   RCC_OscInitStruct.PLL2.PLLSource = RCC_PLL12SOURCE_HSE;
   RCC_OscInitStruct.PLL2.PLLM = 3;
   RCC_OscInitStruct.PLL2.PLLN = 66;
   RCC_OscInitStruct.PLL2.PLLP = 2;
   RCC_OscInitStruct.PLL2.PLLQ = 1;
   RCC_OscInitStruct.PLL2.PLLR = 1;
   RCC_OscInitStruct.PLL2.PLLFRACV = 0x1400;
   RCC_OscInitStruct.PLL2.PLLMODE = RCC_PLL_FRACTIONAL;
   RCC_OscInitStruct.PLL2.RPDFN_DIS = RCC_RPDFN_DIS_DISABLED;
   RCC_OscInitStruct.PLL2.TPDFN_DIS = RCC_TPDFN_DIS_DISABLED;

   //PLL3 configuration
   RCC_OscInitStruct.PLL3.PLLState = RCC_PLL_ON;
   RCC_OscInitStruct.PLL3.PLLSource = RCC_PLL3SOURCE_HSE;
   RCC_OscInitStruct.PLL3.PLLM = 2;
   RCC_OscInitStruct.PLL3.PLLN = 34;
   RCC_OscInitStruct.PLL3.PLLP = 2;
   RCC_OscInitStruct.PLL3.PLLQ = 17;
   RCC_OscInitStruct.PLL3.PLLR = 37;
   RCC_OscInitStruct.PLL3.PLLRGE = RCC_PLL3IFRANGE_1;
   RCC_OscInitStruct.PLL3.PLLFRACV = 0x1A04;
   RCC_OscInitStruct.PLL3.PLLMODE = RCC_PLL_FRACTIONAL;
   RCC_OscInitStruct.PLL3.RPDFN_DIS = RCC_RPDFN_DIS_DISABLED;
   RCC_OscInitStruct.PLL3.TPDFN_DIS = RCC_TPDFN_DIS_DISABLED;

   //PLL4 configuration
   RCC_OscInitStruct.PLL4.PLLState = RCC_PLL_ON;
   RCC_OscInitStruct.PLL4.PLLSource = RCC_PLL4SOURCE_HSE;
   RCC_OscInitStruct.PLL4.PLLM = 4;
   RCC_OscInitStruct.PLL4.PLLN = 99;
   RCC_OscInitStruct.PLL4.PLLP = 6;
   RCC_OscInitStruct.PLL4.PLLQ = 8;
   RCC_OscInitStruct.PLL4.PLLR = 8;
   RCC_OscInitStruct.PLL4.PLLRGE = RCC_PLL4IFRANGE_0;
   RCC_OscInitStruct.PLL4.PLLFRACV = 0;
   RCC_OscInitStruct.PLL4.PLLMODE = RCC_PLL_INTEGER;
   RCC_OscInitStruct.PLL4.RPDFN_DIS = RCC_RPDFN_DIS_DISABLED;
   RCC_OscInitStruct.PLL4.TPDFN_DIS = RCC_TPDFN_DIS_DISABLED;

   HAL_RCC_OscConfig(&RCC_OscInitStruct);

   //Select PLL1 as system clock source and configure bus clocks dividers
   RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_ACLK |
      RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2 | RCC_CLOCKTYPE_PCLK3 |
      RCC_CLOCKTYPE_PCLK4 | RCC_CLOCKTYPE_PCLK5 | RCC_CLOCKTYPE_MPU;

   RCC_ClkInitStruct.MPUInit.MPU_Clock = RCC_MPUSOURCE_PLL1;
   RCC_ClkInitStruct.MPUInit.MPU_Div = RCC_MPU_DIV2;
   RCC_ClkInitStruct.AXISSInit.AXI_Clock = RCC_AXISSOURCE_PLL2;
   RCC_ClkInitStruct.AXISSInit.AXI_Div = RCC_AXI_DIV1;
   RCC_ClkInitStruct.MCUInit.MCU_Clock = RCC_MCUSSOURCE_PLL3;
   RCC_ClkInitStruct.MCUInit.MCU_Div = RCC_MCU_DIV1;
   RCC_ClkInitStruct.APB4_Div = RCC_APB4_DIV2;
   RCC_ClkInitStruct.APB5_Div = RCC_APB5_DIV4;
   RCC_ClkInitStruct.APB1_Div = RCC_APB1_DIV2;
   RCC_ClkInitStruct.APB2_Div = RCC_APB2_DIV2;
   RCC_ClkInitStruct.APB3_Div = RCC_APB3_DIV2;

   HAL_RCC_ClockConfig(&RCC_ClkInitStruct);

   //Select clock source for RNG2 peripheral
   RCC_PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_RNG2;
   RCC_PeriphClkInitStruct.Rng2ClockSelection = RCC_RNG1CLKSOURCE_CSI;

   HAL_RCCEx_PeriphCLKConfig(&RCC_PeriphClkInitStruct);

   //Enable CSI clock
   __HAL_RCC_CSI_ENABLE();
   //Enable SYSCFG clock
   __HAL_RCC_SYSCFG_CLK_ENABLE() ;

   //Set the HSE division factor for RTC clock
   __HAL_RCC_RTC_HSEDIV(24);
}


/**
 * @brief FTP client test routine
 * @return Error code
 **/

error_t ftpClientTest(void)
{
   error_t error;
   size_t n;
   IpAddr ipAddr;
   char_t buffer[128];

   //Initialize FTP client context
   ftpClientInit(&ftpClientContext);

   //Start of exception handling block
   do
   {
      //Debug message
      TRACE_INFO("\r\n\r\nResolving server name...\r\n");

      //Resolve FTP server name
      error = getHostByName(NULL, APP_FTP_SERVER_NAME, &ipAddr, 0);
      //Any error to report?
      if(error)
      {
         //Debug message
         TRACE_INFO("Failed to resolve server name!\r\n");
         break;
      }

      //Set timeout value for blocking operations
      error = ftpClientSetTimeout(&ftpClientContext, 20000);
      //Any error to report?
      if(error)
         break;

      //Debug message
      TRACE_INFO("Connecting to FTP server %s...\r\n",
         ipAddrToString(&ipAddr, NULL));

      //Connect to the FTP server
      error = ftpClientConnect(&ftpClientContext, &ipAddr, APP_FTP_SERVER_PORT,
         FTP_MODE_PLAINTEXT | FTP_MODE_PASSIVE);
      //Any error to report?
      if(error)
      {
         //Debug message
         TRACE_INFO("Failed to connect to FTP server!\r\n");
         break;
      }

      //Login to the FTP server using the provided username and password
      error = ftpClientLogin(&ftpClientContext, APP_FTP_LOGIN, APP_FTP_PASSWORD);
      //Any error to report?
      if(error)
         break;

      //Open the specified file for reading
      error = ftpClientOpenFile(&ftpClientContext, APP_FTP_FILENAME,
         FTP_FILE_MODE_READ | FTP_FILE_MODE_BINARY);
      //Any error to report?
      if(error)
         break;

      //Read the contents of the file
      while(!error)
      {
         //Read data
         error = ftpClientReadFile(&ftpClientContext, buffer, sizeof(buffer) - 1, &n, 0);

         //Check status code
         if(!error)
         {
            //Properly terminate the string with a NULL character
            buffer[n] = '\0';
            //Dump the contents of the file
            TRACE_INFO("%s", buffer);
         }
      }

      //Terminate the string with a line feed
      TRACE_INFO("\r\n");

      //Any error to report?
      if(error != ERROR_END_OF_STREAM)
         break;

      //Close file
      error = ftpClientCloseFile(&ftpClientContext);
      //Any error to report?
      if(error)
         break;

      //Gracefully disconnect from the FTP server
      ftpClientDisconnect(&ftpClientContext);

      //Debug message
      TRACE_INFO("Connection closed\r\n");

      //End of exception handling block
   } while(0);

   //Release FTP client context
   ftpClientDeinit(&ftpClientContext);

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
      //User button pressed?
      if(!BSP_PB_GetState(BUTTON_USER))
      {
         //FTP client test routine
         ftpClientTest();

         //Wait for the user button to be released
         while(!BSP_PB_GetState(BUTTON_USER));
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
      BSP_LED_On(LED2);
      osDelayTask(100);
      BSP_LED_Off(LED2);
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

   //HAL library initialization
   HAL_Init();

   //Engineering boot mode?
   if(IS_ENGINEERING_BOOT_MODE())
   {
      //Configure the system clock
      SystemClock_Config();
   }

   //Update system core clock
   SystemCoreClockUpdate();

   //Enable hardware semaphore clock
   __HAL_RCC_HSEM_CLK_ENABLE();

   //Initialize kernel
   osInitKernel();
   //Configure debug UART
   debugInit(115200);

   //Start-up message
   TRACE_INFO("\r\n");
   TRACE_INFO("**********************************\r\n");
   TRACE_INFO("*** CycloneTCP FTP Client Demo ***\r\n");
   TRACE_INFO("**********************************\r\n");
   TRACE_INFO("Copyright: 2010-2024 Oryx Embedded SARL\r\n");
   TRACE_INFO("Compiled: %s %s\r\n", __DATE__, __TIME__);
   TRACE_INFO("Target: STM32MP157A\r\n");
   TRACE_INFO("\r\n");

   //LED configuration
   BSP_LED_Init(LED2);
   BSP_LED_Init(LED3);
   BSP_LED_Init(LED4);
   BSP_LED_Init(LED5);

   //Clear LEDs
   BSP_LED_Off(LED2);
   BSP_LED_Off(LED3);
   BSP_LED_Off(LED4);
   BSP_LED_Off(LED5);

   //Initialize buttons
   BSP_PB_Init(BUTTON_WAKEUP, BUTTON_MODE_GPIO);
   BSP_PB_Init(BUTTON_USER, BUTTON_MODE_GPIO);
   BSP_PB_Init(BUTTON_USER2, BUTTON_MODE_GPIO);

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
   netSetDriver(interface, &stm32mp1xxEthDriver);
   netSetPhyDriver(interface, &rtl8211ePhyDriver);

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
