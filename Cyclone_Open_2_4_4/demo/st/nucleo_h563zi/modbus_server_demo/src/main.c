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
#include "stm32h5xx.h"
#include "stm32h5xx_hal.h"
#include "stm32h5xx_nucleo.h"
#include "core/net.h"
#include "drivers/mac/stm32h5xx_eth_driver.h"
#include "drivers/phy/lan8742_driver.h"
#include "dhcp/dhcp_client.h"
#include "ipv6/slaac.h"
#include "modbus/modbus_server.h"
#include "debug.h"

//Ethernet interface configuration
#define APP_IF_NAME "eth0"
#define APP_HOST_NAME "modbus-server-demo"
#define APP_MAC_ADDR "00-AB-CD-EF-05-63"

#define APP_USE_DHCP_CLIENT ENABLED
#define APP_IPV4_HOST_ADDR "192.168.0.20"
#define APP_IPV4_SUBNET_MASK "255.255.255.0"
#define APP_IPV4_DEFAULT_GATEWAY "192.168.0.254"
#define APP_IPV4_PRIMARY_DNS "8.8.8.8"
#define APP_IPV4_SECONDARY_DNS "8.8.4.4"

#define APP_USE_SLAAC ENABLED
#define APP_IPV6_LINK_LOCAL_ADDR "fe80::563"
#define APP_IPV6_PREFIX "2001:db8::"
#define APP_IPV6_PREFIX_LENGTH 64
#define APP_IPV6_GLOBAL_ADDR "2001:db8::563"
#define APP_IPV6_ROUTER "fe80::1"
#define APP_IPV6_PRIMARY_DNS "2001:4860:4860::8888"
#define APP_IPV6_SECONDARY_DNS "2001:4860:4860::8844"

//Application configuration
#define APP_MODBUS_SERVER_PORT 502
#define APP_MODBUS_SERVER_TIMEOUT 600000
#define APP_MODBUS_SERVER_KEEP_ALIVE_IDLE 10000
#define APP_MODBUS_SERVER_KEEP_ALIVE_INTERVAL 5000
#define APP_MODBUS_SERVER_KEEP_ALIVE_PROBES 4

//Global variables
uint16_t ledState[2];
DhcpClientSettings dhcpClientSettings;
DhcpClientContext dhcpClientContext;
SlaacSettings slaacSettings;
SlaacContext slaacContext;
ModbusServerSettings modbusServerSettings;
ModbusServerContext modbusServerContext;

//Forward declaration of functions
error_t modbusServerOpenCallback(ModbusClientConnection *connection,
   IpAddr clientIpAddr, uint16_t clientPort);

void modbusServerLockCallback(void);
void modbusServerUnlockCallback(void);

error_t modbusServerReadCoilCallback(const char_t *role, uint16_t address,
   bool_t *state);

error_t modbusServerWriteCoilCallback(const char_t *role, uint16_t address,
   bool_t state, bool_t commit);

error_t modbusServerReadRegCallback(const char_t *role, uint16_t address,
   uint16_t *value);

error_t modbusServerWriteRegCallback(const char_t *role, uint16_t address,
   uint16_t value, bool_t commit);


/**
 * @brief System clock configuration
 **/

void SystemClock_Config(void)
{
   RCC_OscInitTypeDef RCC_OscInitStruct = {0};
   RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
   RCC_PeriphCLKInitTypeDef RCC_PeriphClkInitStruct = {0};

   //Configure the main internal regulator output voltage
   __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE0);

   //Wait for the voltage scaling ready flag to be set
   while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY))
   {
   }

   //Configure PLL with HSI as source
   RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI | RCC_OSCILLATORTYPE_HSI48;
   RCC_OscInitStruct.HSIState = RCC_HSI_ON;
   RCC_OscInitStruct.HSIDiv = RCC_HSI_DIV1;
   RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
   RCC_OscInitStruct.HSI48State = RCC_HSI48_ON;
   RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
   RCC_OscInitStruct.PLL.PLLSource = RCC_PLL1_SOURCE_HSI;
   RCC_OscInitStruct.PLL.PLLM = 8;
   RCC_OscInitStruct.PLL.PLLN = 60;
   RCC_OscInitStruct.PLL.PLLP = 2;
   RCC_OscInitStruct.PLL.PLLQ = 2;
   RCC_OscInitStruct.PLL.PLLR = 2;
   RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1_VCIRANGE_3;
   RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1_VCORANGE_WIDE;
   RCC_OscInitStruct.PLL.PLLFRACN = 0;
   HAL_RCC_OscConfig(&RCC_OscInitStruct);

   //Select PLL as system clock source and configure bus clocks dividers
   RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK |
      RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2 | RCC_CLOCKTYPE_PCLK3;
   RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
   RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
   RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
   RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
   RCC_ClkInitStruct.APB3CLKDivider = RCC_HCLK_DIV1;
   HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5);

   //Select clock source for RNG peripheral
   RCC_PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_RNG;
   RCC_PeriphClkInitStruct.RngClockSelection = RCC_RNGCLKSOURCE_HSI48;
   HAL_RCCEx_PeriphCLKConfig(&RCC_PeriphClkInitStruct);
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
      BSP_LED_On(LED1);
      osDelayTask(100);
      BSP_LED_Off(LED1);
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
   //Configure the system clock
   SystemClock_Config();

   //Enable instruction cache
   HAL_ICACHE_ConfigAssociativityMode(ICACHE_2WAYS);
   HAL_ICACHE_Enable();

   //Initialize kernel
   osInitKernel();
   //Configure debug UART
   debugInit(115200);

   //Start-up message
   TRACE_INFO("\r\n");
   TRACE_INFO("*****************************************\r\n");
   TRACE_INFO("*** CycloneTCP Modbus/TCP Server Demo ***\r\n");
   TRACE_INFO("*****************************************\r\n");
   TRACE_INFO("Copyright: 2010-2024 Oryx Embedded SARL\r\n");
   TRACE_INFO("Compiled: %s %s\r\n", __DATE__, __TIME__);
   TRACE_INFO("Target: STM32H563\r\n");
   TRACE_INFO("\r\n");

   //LED configuration
   BSP_LED_Init(LED1);
   BSP_LED_Init(LED2);
   BSP_LED_Init(LED3);

   //Clear LEDs
   BSP_LED_Off(LED1);
   BSP_LED_Off(LED2);
   BSP_LED_Off(LED3);

   //Initialize user button
   BSP_PB_Init(BUTTON_USER, BUTTON_MODE_GPIO);

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
   netSetDriver(interface, &stm32h5xxEthDriver);
   netSetPhyDriver(interface, &lan8742PhyDriver);

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

   //Get default settings
   modbusServerGetDefaultSettings(&modbusServerSettings);
   //Bind Modbus/TCP server to the desired interface
   modbusServerSettings.interface = &netInterface[0];
   //Listen to port 502
   modbusServerSettings.port = APP_MODBUS_SERVER_PORT;
   //Idle connection timeout
   modbusServerSettings.timeout = APP_MODBUS_SERVER_TIMEOUT;
   //Callback functions
   modbusServerSettings.openCallback = modbusServerOpenCallback;
   modbusServerSettings.lockCallback = modbusServerLockCallback;
   modbusServerSettings.unlockCallback = modbusServerUnlockCallback;
   modbusServerSettings.readCoilCallback = modbusServerReadCoilCallback;
   modbusServerSettings.writeCoilCallback = modbusServerWriteCoilCallback;
   modbusServerSettings.readRegCallback = modbusServerReadRegCallback;
   modbusServerSettings.writeRegCallback = modbusServerWriteRegCallback;

   //Modbus/TCP server initialization
   error = modbusServerInit(&modbusServerContext, &modbusServerSettings);
   //Failed to initialize Modbus/TCP server?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize Modbus/TCP server!\r\n");
   }

   //Start Modbus/TCP server
   error = modbusServerStart(&modbusServerContext);
   //Failed to start Modbus/TCP server?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start Modbus/TCP server!\r\n");
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
 * @brief TCP connection open callback function
 * @param[in] clientIpAddr IP address of the client
 * @param[in] clientPort Port number used by the client
 * @return Error code
 **/

error_t modbusServerOpenCallback(ModbusClientConnection *connection,
   IpAddr clientIpAddr, uint16_t clientPort)
{
   error_t error;

   //Set TCP keep-alive parameters
   error = socketSetKeepAliveParams(connection->socket,
      APP_MODBUS_SERVER_KEEP_ALIVE_IDLE, APP_MODBUS_SERVER_KEEP_ALIVE_INTERVAL,
      APP_MODBUS_SERVER_KEEP_ALIVE_PROBES);
   //Any error to report?
   if(error)
      return error;

   //Enable TCP keep-alive
   error = socketEnableKeepAlive(connection->socket, TRUE);
   //Any error to report?
   if(error)
      return error;

   //Successful processing
   return NO_ERROR;
}


/**
 * @brief Lock Modbus table callback function
 **/

void modbusServerLockCallback(void)
{
}


/**
 * @brief Unlock Modbus table callback function
 **/

void modbusServerUnlockCallback(void)
{
}


/**
 * @brief Get coil state callback function
 * @param[in] role Client role (NULL-terminated string)
 * @param[in] address Coil address
 * @param[out] state Current coil state
 * @return Error code
 **/

error_t modbusServerReadCoilCallback(const char_t *role, uint16_t address,
   bool_t *state)
{
   error_t error;

   //Initialize status code
   error = NO_ERROR;

   //Check register address
   if(address == 0)
   {
      //Retrieve the state of the LED
      *state = ledState[0];
   }
   else if(address == 1)
   {
      //Retrieve the state of the LED
      *state = ledState[1];
   }
   else if(address >= 2 && address <= 9)
   {
      //Coils 2 to 9 always read as zero
      *state = 0;
   }
   else if(address == 10000)
   {
      //Retrieve the state of the user button
      *state = BSP_PB_GetState(BUTTON_USER);
   }
   else if(address >= 10001 && address <= 10009)
   {
      //Coils 10001 to 10009 always read as zero
      *state = 0;
   }
   else
   {
      //The register address is not acceptable
      error = ERROR_INVALID_ADDRESS;
   }

   //Return status code
   return error;
}


/**
 * @brief Set coil state callback function
 * @param[in] role Client role (NULL-terminated string)
 * @param[in] address Address of the coil
 * @param[in] state Desired coil state
 * @param[in] commit This flag indicates the current phase (validation phase
 *   or write phase if the validation was successful)
 * @return Error code
 **/

error_t modbusServerWriteCoilCallback(const char_t *role, uint16_t address,
   bool_t state, bool_t commit)
{
   error_t error;

   //Initialize status code
   error = NO_ERROR;

   //Check register address
   if(address == 0)
   {
      //Write phase?
      if(commit)
      {
         //Update the state of the LED
         if(state)
            BSP_LED_On(LED2);
         else
            BSP_LED_Off(LED2);

         //Save the state of the LED
         ledState[0] = state;
      }
   }
   else if(address == 1)
   {
      //Write phase?
      if(commit)
      {
         //Update the state of the LED
         if(state)
            BSP_LED_On(LED3);
         else
            BSP_LED_Off(LED3);

         //Save the state of the LED
         ledState[1] = state;
      }
   }
   else if(address >= 2 && address <= 9)
   {
      //Writes to coils 2 to 9 are ignored
   }
   else
   {
      //The register address is not acceptable
      error = ERROR_INVALID_ADDRESS;
   }

   //Return status code
   return error;
}


/**
 * @brief Get register value callback function
 * @param[in] role Client role (NULL-terminated string)
 * @param[in] address Register address
 * @param[out] state Current register value
 * @return Error code
 **/

error_t modbusServerReadRegCallback(const char_t *role, uint16_t address,
   uint16_t *value)
{
   error_t error;

   //Initialize status code
   error = NO_ERROR;

   //Check register address
   if(address == 30000)
   {
      //Retrieve the state of the user button
      *value = BSP_PB_GetState(BUTTON_USER);
   }
   else if(address >= 30001 && address <= 30009)
   {
      //Registers 30001 to 30009 always read as zero
      *value = 0;
   }
   else if(address == 40000)
   {
      //Retrieve the state of the LED
      *value = ledState[0];
   }
   else if(address == 40001)
   {
      //Retrieve the state of the LED
      *value = ledState[1];
   }
   else if(address >= 40002 && address <= 40009)
   {
      //Registers 40002 to 40009 always read as zero
      *value = 0;
   }
   else
   {
      //The register address is not acceptable
      error = ERROR_INVALID_ADDRESS;
   }

   //Return status code
   return error;
}


/**
 * @brief Set register value callback function
 * @param[in] role Client role (NULL-terminated string)
 * @param[in] address Register address
 * @param[in] state Desired register value
 * @param[in] commit This flag indicates the current phase (validation phase
 *   or write phase if the validation was successful)
 * @return Error code
 **/

error_t modbusServerWriteRegCallback(const char_t *role, uint16_t address,
   uint16_t value, bool_t commit)
{
   error_t error;

   //Initialize status code
   error = NO_ERROR;

   //Check register address
   if(address == 40000)
   {
      //Write phase?
      if(commit)
      {
         //Update the state of the LED
         if(value & 1)
            BSP_LED_On(LED2);
         else
            BSP_LED_Off(LED2);

         //Save the state of the LED
         ledState[0] = value;
      }
   }
   else if(address == 40001)
   {
      //Write phase?
      if(commit)
      {
         //Update the state of the LED
         if(value & 1)
            BSP_LED_On(LED3);
         else
            BSP_LED_Off(LED3);

         //Save the state of the LED
         ledState[1] = value;
      }
   }
   else if(address >= 40002 && address <= 40009)
   {
      //Writes to registers 40002 to 40009 are ignored
   }
   else
   {
      //The register address is not acceptable
      error = ERROR_INVALID_ADDRESS;
   }

   //Return status code
   return error;
}
