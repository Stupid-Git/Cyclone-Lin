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
#include "samv71_xplained_ultra.h"
#include "core/net.h"
#include "drivers/mac/samv71_eth_driver.h"
#include "drivers/phy/ksz8061_driver.h"
#include "dhcp/dhcp_client.h"
#include "ipv6/slaac.h"
#include "tftp/tftp_client.h"
#include "ext_int_driver.h"
#include "debug.h"

//Ethernet interface configuration
#define APP_IF_NAME "eth0"
#define APP_HOST_NAME "tftp-client-demo"
#define APP_MAC_ADDR "00-AB-CD-EF-71-21"

#define APP_USE_DHCP_CLIENT ENABLED
#define APP_IPV4_HOST_ADDR "192.168.0.20"
#define APP_IPV4_SUBNET_MASK "255.255.255.0"
#define APP_IPV4_DEFAULT_GATEWAY "192.168.0.254"
#define APP_IPV4_PRIMARY_DNS "8.8.8.8"
#define APP_IPV4_SECONDARY_DNS "8.8.4.4"

#define APP_USE_SLAAC ENABLED
#define APP_IPV6_LINK_LOCAL_ADDR "fe80::7121"
#define APP_IPV6_PREFIX "2001:db8::"
#define APP_IPV6_PREFIX_LENGTH 64
#define APP_IPV6_GLOBAL_ADDR "2001:db8::7121"
#define APP_IPV6_ROUTER "fe80::1"
#define APP_IPV6_PRIMARY_DNS "2001:4860:4860::8888"
#define APP_IPV6_SECONDARY_DNS "2001:4860:4860::8844"

//Application configuration
#define APP_TFTP_SERVER_NAME "192.168.0.100"
#define APP_TFTP_SERVER_PORT 69
#define APP_TFTP_FILENAME "test.txt"

//Global variables
DhcpClientSettings dhcpClientSettings;
DhcpClientContext dhcpClientContext;
SlaacSettings slaacSettings;
SlaacContext slaacContext;
TftpClientContext tftpClientContext;


/**
 * @brief MPU configuration
 **/

void mpuConfig(void)
{
   //Disable fault exceptions
   SCB->SHCSR &= ~SCB_SHCSR_MEMFAULTENA_Msk;
   //Disable the MPU
   MPU->CTRL &= ~MPU_CTRL_ENABLE_Msk;

   //Configure the first region (SRAM)
   MPU->RNR = 0;
   //Set region base address
   MPU->RBAR = 0x20400000;

   //Set MPU region attributes
   MPU->RASR = (0 << MPU_RASR_XN_Pos) | //Instruction fetches enabled
      (3 << MPU_RASR_AP_Pos) |          //Full access permission
      (1 << MPU_RASR_TEX_Pos) |         //TEX level 1
      (0 << MPU_RASR_S_Pos) |           //Not shareable
      (1 << MPU_RASR_C_Pos) |           //Cacheable
      (1 << MPU_RASR_B_Pos) |           //Bufferable
      (0 << MPU_RASR_SRD_Pos) |         //All sub-regions enabled
      (18 << MPU_RASR_SIZE_Pos) |       //Region size (512KB)
      (1 << MPU_RASR_ENABLE_Pos);       //Region enabled

   //Configure the second region (non-cacheable SRAM)
   MPU->RNR = 1;
   //Set region base address
   MPU->RBAR = 0x20458000;

   //Set MPU region attributes
   MPU->RASR = (1 << MPU_RASR_XN_Pos) | //Instruction fetches disabled
      (3 << MPU_RASR_AP_Pos) |          //Full access permission
      (1 << MPU_RASR_TEX_Pos) |         //TEX level 1
      (1 << MPU_RASR_S_Pos) |           //Shareable
      (0 << MPU_RASR_C_Pos) |           //Not cacheable
      (0 << MPU_RASR_B_Pos) |           //Not bufferable
      (0 << MPU_RASR_SRD_Pos) |         //All sub-regions enabled
      (14 << MPU_RASR_SIZE_Pos) |       //Region size (32KB)
      (1 << MPU_RASR_ENABLE_Pos);       //Region enabled

   //Enable the MPU
   MPU->CTRL = MPU_CTRL_PRIVDEFENA_Msk | MPU_CTRL_ENABLE_Msk;
   //Enable fault exceptions
   SCB->SHCSR |= SCB_SHCSR_MEMFAULTENA_Msk;
}


/**
 * @brief I/O initialization
 **/

void ioInit(void)
{
   //Disable write protection
   MATRIX_REGS->MATRIX_WPMR = MATRIX_WPMR_WPKEY_PASSWD;
   //Select PB12 function rather than ERASE function
   MATRIX_REGS->CCFG_SYSIO |= CCFG_SYSIO_SYSIO12_Msk;

   //Enable PIO peripheral clocks
   PMC_REGS->PMC_PCER0 = (1 << ID_PIOA) | (1 << ID_PIOB) | (1 << ID_PIOC);

   //Configure LED0
   PIO_LED0->PIO_PER = LED0;
   PIO_LED0->PIO_OER = LED0;
   PIO_LED0->PIO_SODR = LED0;

   //Configure LED1
   PIO_LED1->PIO_PER = LED1;
   PIO_LED1->PIO_OER = LED1;
   PIO_LED1->PIO_SODR = LED1;

   //Configure SW0 button
   PIO_SW0->PIO_PER = SW0;
   PIO_SW0->PIO_ODR = SW0;
   PIO_SW0->PIO_PUER = SW0;

   //Configure SW1 button
   PIO_SW1->PIO_PER = SW1;
   PIO_SW1->PIO_ODR = SW1;
   PIO_SW1->PIO_PUER = SW1;
}


/**
 * @brief TFTP client test routine
 * @return Error code
 **/

error_t tftpClientTest(void)
{
   error_t error;
   uint_t i;
   size_t n;
   char_t buffer[64];
   IpAddr ipAddr;

   //Initialize TFTP client context
   tftpClientInit(&tftpClientContext);

   //Start of exception handling block
   do
   {
      //Debug message
      TRACE_INFO("\r\n\r\nResolving server name...\r\n");

      //Resolve TFTP server name
      error = getHostByName(NULL, APP_TFTP_SERVER_NAME, &ipAddr, 0);
      //Any error to report?
      if(error)
      {
         //Debug message
         TRACE_INFO("Failed to resolve server name!\r\n");
         break;
      }

      //Set TFTP server address and port number
      error = tftpClientConnect(&tftpClientContext, &ipAddr,
         APP_TFTP_SERVER_PORT);
      //Any error to report?
      if(error)
         break;

      //Debug message
      TRACE_INFO("\r\nWriting file...\r\n");

      //Open file for writing
      error = tftpClientOpenFile(&tftpClientContext,
         APP_TFTP_FILENAME, TFTP_FILE_MODE_WRITE);
      //Any error to report?
      if(error)
      {
         //Debug message
         TRACE_INFO("Failed to open file for writing!\r\n");
         break;
      }

      //Write file contents
      for(i = 1; i < 100; i++)
      {
         //Format string
         sprintf(buffer, "Hello World %u!\r\n", i);
         //Debug message
         TRACE_INFO("%s", buffer);

         //Write data
         error = tftpClientWriteFile(&tftpClientContext, buffer,
            strlen(buffer), &n, 0);
         //Any error to report?
         if(error)
            break;
      }

      //Check status code
      if(!error)
      {
         //Flush pending data
         error = tftpClientFlushFile(&tftpClientContext);
      }

      //Any error to report?
      if(error)
      {
         //Debug message
         TRACE_INFO("Failed to write file!\r\n");
         break;
      }

      //Close file
      tftpClientCloseFile(&tftpClientContext);

      //Debug message
      TRACE_INFO("\r\nReading file...\r\n");

      //Open file for reading
      error = tftpClientOpenFile(&tftpClientContext,
         APP_TFTP_FILENAME, TFTP_FILE_MODE_READ);

      //Check status code
      if(error)
      {
         //Debug message
         TRACE_INFO("Failed to open file for reading!\r\n");
         break;
      }

      //Read file contents
      while(1)
      {
         //Read data
         error = tftpClientReadFile(&tftpClientContext, buffer,
            sizeof(buffer) - 1, &n, 0);
         //Any error to report?
         if(error)
            break;

         //Properly terminate the string
         buffer[n] = '\0';
         //Debug message
         TRACE_INFO("%s", buffer);
      }

      //Check status code
      if(error != ERROR_END_OF_STREAM)
      {
         //Debug message
         TRACE_INFO("Failed to read file!\r\n");
         break;
      }

      //Close file
      tftpClientCloseFile(&tftpClientContext);

      //End of exception handling block
   } while(0);

   //Release TFTP client context
   tftpClientDeinit(&tftpClientContext);

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
      //SW0 button pressed?
      if(!(PIO_SW0->PIO_PDSR & SW0))
      {
         //TFTP client test routine
         tftpClientTest();

         //Wait for the SW0 button to be released
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

   //Disable watchdog timer
   WDT_REGS->WDT_MR = WDT_MR_WDDIS_Msk;

   //MPU configuration
   mpuConfig();

   //Enable I-cache and D-cache
   SCB_EnableICache();
   SCB_EnableDCache();

   //Update system core clock
   SystemCoreClockUpdate();

   //Initialize kernel
   osInitKernel();
   //Configure debug UART
   debugInit(115200);

   //Start-up message
   TRACE_INFO("\r\n");
   TRACE_INFO("***********************************\r\n");
   TRACE_INFO("*** CycloneTCP TFTP Client Demo ***\r\n");
   TRACE_INFO("***********************************\r\n");
   TRACE_INFO("Copyright: 2010-2024 Oryx Embedded SARL\r\n");
   TRACE_INFO("Compiled: %s %s\r\n", __DATE__, __TIME__);
   TRACE_INFO("Target: SAMV71\r\n");
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
   netSetDriver(interface, &samv71EthDriver);
   netSetPhyDriver(interface, &ksz8061PhyDriver);
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
