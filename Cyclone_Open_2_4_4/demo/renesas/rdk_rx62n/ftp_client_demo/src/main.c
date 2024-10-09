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
#include <intrinsics.h>
#include <iorx62n.h>
#include "yrdkrx62n.h"
#include "mcu_info.h"
#include "lcd.h"
#include "r_rspi_rx600.h"
#include "core/net.h"
#include "drivers/mac/rx62n_eth_driver.h"
#include "drivers/phy/dp83640_driver.h"
#include "dhcp/dhcp_client.h"
#include "ipv6/slaac.h"
#include "ftp/ftp_client.h"
#include "debug.h"

//Ethernet interface configuration
#define APP_IF_NAME "eth0"
#define APP_HOST_NAME "ftp-client-demo"
#define APP_MAC_ADDR "00-AB-CD-EF-00-62"

#define APP_USE_DHCP_CLIENT ENABLED
#define APP_IPV4_HOST_ADDR "192.168.0.20"
#define APP_IPV4_SUBNET_MASK "255.255.255.0"
#define APP_IPV4_DEFAULT_GATEWAY "192.168.0.254"
#define APP_IPV4_PRIMARY_DNS "8.8.8.8"
#define APP_IPV4_SECONDARY_DNS "8.8.4.4"

#define APP_USE_SLAAC ENABLED
#define APP_IPV6_LINK_LOCAL_ADDR "fe80::62"
#define APP_IPV6_PREFIX "2001:db8::"
#define APP_IPV6_PREFIX_LENGTH 64
#define APP_IPV6_GLOBAL_ADDR "2001:db8::62"
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
uint_t lcdLine = 0;
uint_t lcdColumn = 0;

DhcpClientSettings dhcpClientSettings;
DhcpClientContext dhcpClientContext;
SlaacSettings slaacSettings;
SlaacContext slaacContext;
FtpClientContext ftpClientContext;


/**
 * @brief Set cursor location
 * @param[in] line Line number
 * @param[in] column Column number
 **/

void lcdSetCursor(uint_t line, uint_t column)
{
   lcdLine = MIN(line, 8);
   lcdColumn = MIN(column, 12);
}


/**
 * @brief Write a character to the LCD display
 * @param[in] c Character to be written
 **/

void lcdPutChar(char_t c)
{
   uint8_t buffer[2];

   if(c == '\r')
   {
      lcdColumn = 0;
   }
   else if(c == '\n')
   {
      lcdColumn = 0;
      lcdLine++;
   }
   else if(lcdLine < 8 && lcdColumn < 12)
   {
      buffer[0] = c;
      buffer[1] = '\0';

      //Display current character
      lcd_display(lcdColumn * 8, lcdLine * 8, buffer);

      //Advance the cursor position
      if(++lcdColumn >= 12)
      {
         lcdColumn = 0;
         lcdLine++;
      }
   }
}


/**
 * @brief I/O initialization
 **/

void ioInit(void)
{
   //Configure LEDs
   LED4_DDR = 1;
   LED5_DDR = 1;
   LED6_DDR = 1;
   LED7_DDR = 1;
   LED8_DDR = 1;
   LED9_DDR = 1;
   LED10_DDR = 1;
   LED11_DDR = 1;
   LED12_DDR = 1;
   LED13_DDR = 1;
   LED14_DDR = 1;
   LED15_DDR = 1;

   //Clear LEDs
   LED4 = LED_OFF;
   LED5 = LED_OFF;
   LED6 = LED_OFF;
   LED7 = LED_OFF;
   LED8 = LED_OFF;
   LED9 = LED_OFF;
   LED10 = LED_OFF;
   LED11 = LED_OFF;
   LED12 = LED_OFF;
   LED13 = LED_OFF;
   LED14 = LED_OFF;
   LED15 = LED_OFF;

   //Configure push buttons
   SW1_DDR = 0;
   SW2_DDR = 0;
   SW3_DDR = 0;

   //Configure LCD_CS as an output
   LCD_CS_DDR = 1;
   //Configure LCD_RS as an output
   LCD_RS_DDR = 1;
   //Configure reset pin as an output
   LCD_RESET_DDR = 1;

   //Perform hardware reset
   PORTC.DR.BIT.B3 = 1;
   sleep(10);
   PORTC.DR.BIT.B3 = 0;
   sleep(10);
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
   char_t buffer[40];
#if (IPV4_SUPPORT == ENABLED)
   Ipv4Addr ipv4Addr;
#endif

   //Point to the network interface
   NetInterface *interface = &netInterface[0];

   //Initialize LCD display
   lcdSetCursor(3, 0);
   printf("IPv4 Addr\r\n");
   lcdSetCursor(6, 0);
   printf("Press SW1 to\r\n");
   lcdSetCursor(7, 0);
   printf("run test\r\n");

   //Endless loop
   while(1)
   {
#if (IPV4_SUPPORT == ENABLED)
      //Display IPv4 host address
      lcdSetCursor(4, 0);
      ipv4GetHostAddr(interface, &ipv4Addr);
      printf("%-16s\r\n", ipv4AddrToString(ipv4Addr, buffer));
#endif

      //SW1 button pressed?
      if(!SW1)
      {
         //FTP client test routine
         ftpClientTest();

         //Wait for the SW1 button to be released
         while(!SW1);
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
      LED4 = LED_ON;
      osDelayTask(100);
      LED4 = LED_OFF;
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
   TRACE_INFO("**********************************\r\n");
   TRACE_INFO("*** CycloneTCP FTP Client Demo ***\r\n");
   TRACE_INFO("**********************************\r\n");
   TRACE_INFO("Copyright: 2010-2024 Oryx Embedded SARL\r\n");
   TRACE_INFO("Compiled: %s %s\r\n", __DATE__, __TIME__);
   TRACE_INFO("Target: RX62N\r\n");
   TRACE_INFO("\r\n");

   //Configure I/Os
   ioInit();

   //Initialize SPI bus
   R_RSPI_Init(RSPI_CHANNEL_0);
   //Initialize LCD display
   lcd_initialize();
   //Clear display
   lcd_clear();

   //Welcome message
   lcdSetCursor(0, 0);
   printf("FTP Client\r\nDemo\r\n");

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
   netSetDriver(interface, &rx62nEthDriver);
   netSetPhyDriver(interface, &dp83640PhyDriver);

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

   //Enable interrupts
   __enable_interrupt();

   //Start the execution of tasks
   osStartKernel();

   //This function should never return
   return 0;
}


/**
 * @brief Set up the timer that will generate the tick interrupt
 **/

void vApplicationSetupTimerInterrupt(void)
{
   //Cancel CMT0 module stop state
   MSTP(CMT0) = 0;

   //Select PCLK/8 clock
   CMT0.CMCR.BIT.CKS = 0;
   //Set the compare match value
   CMT0.CMCOR = ((PCLK_HZ / configTICK_RATE_HZ) - 1) / 8;

   //Interrupt on compare match
   CMT0.CMCR.BIT.CMIE = 1;

   //Set interrupt priority
   _IPR(_CMT0_CMI0) = configKERNEL_INTERRUPT_PRIORITY;
   //Enable compare match interrupt
   _IEN(_CMT0_CMI0) = 1;

   //Start timer
   CMT.CMSTR0.BIT.STR0 = 1;
}
