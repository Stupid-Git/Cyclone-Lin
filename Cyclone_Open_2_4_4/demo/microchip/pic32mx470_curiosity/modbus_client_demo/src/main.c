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
#include <p32xxxx.h>
#include <sys/attribs.h>
#include "pic32mx470_curiosity.h"
#include "core/net.h"
#include "drivers/eth/lan8651_driver.h"
#include "drivers/eth/lan9250_driver.h"
#include "dhcp/dhcp_client.h"
#include "ipv6/slaac.h"
#include "modbus/modbus_client.h"
#include "spi_driver.h"
#include "ext_int_driver.h"
#include "debug.h"

#ifndef _CP0_SET_CONFIG
    #define _CP0_SET_CONFIG(val) _mtc0(_CP0_CONFIG, _CP0_CONFIG_SELECT, val)
#endif

//Configuration bits
#pragma config USERID = 0xFFFF
#pragma config FSRSSEL = PRIORITY_7
#pragma config PMDL1WAY = OFF
#pragma config IOL1WAY = OFF
#pragma config FUSBIDIO = OFF
#pragma config FVBUSONIO = OFF
#pragma config FPLLIDIV = DIV_4
#pragma config FPLLMUL = MUL_20
#pragma config UPLLIDIV = DIV_5
#pragma config UPLLEN = OFF
#pragma config FPLLODIV = DIV_1
#pragma config FNOSC = PRIPLL
#pragma config FSOSCEN = ON
#pragma config IESO = ON
#pragma config POSCMOD = XT
#pragma config OSCIOFNC = OFF
#pragma config FPBDIV = DIV_2
#pragma config FCKSM = CSDCMD
#pragma config WDTPS = PS1048576
#pragma config WINDIS = OFF
#pragma config FWDTEN = OFF
#pragma config FWDTWINSZ = WINSZ_25
//#pragma config DEBUG = ON
#pragma config JTAGEN = OFF
#pragma config ICESEL = ICS_PGx2
#pragma config PWP = OFF
#pragma config BWP = OFF
#pragma config CP = OFF

//Ethernet interface configuration
#define APP_IF_NAME "eth0"
#define APP_HOST_NAME "modbus-client-demo"
#define APP_MAC_ADDR "00-AB-CD-EF-28-60"

#define APP_USE_DHCP_CLIENT ENABLED
#define APP_IPV4_HOST_ADDR "192.168.0.20"
#define APP_IPV4_SUBNET_MASK "255.255.255.0"
#define APP_IPV4_DEFAULT_GATEWAY "192.168.0.254"
#define APP_IPV4_PRIMARY_DNS "8.8.8.8"
#define APP_IPV4_SECONDARY_DNS "8.8.4.4"

#define APP_USE_SLAAC ENABLED
#define APP_IPV6_LINK_LOCAL_ADDR "fe80::2860"
#define APP_IPV6_PREFIX "2001:db8::"
#define APP_IPV6_PREFIX_LENGTH 64
#define APP_IPV6_GLOBAL_ADDR "2001:db8::2860"
#define APP_IPV6_ROUTER "fe80::1"
#define APP_IPV6_PRIMARY_DNS "2001:4860:4860::8888"
#define APP_IPV6_SECONDARY_DNS "2001:4860:4860::8844"

//Application configuration
#define APP_MODBUS_SERVER_NAME "192.168.0.100"
#define APP_MODBUS_SERVER_PORT 502

//Global variables
DhcpClientSettings dhcpClientSettings;
DhcpClientContext dhcpClientContext;
SlaacSettings slaacSettings;
SlaacContext slaacContext;
ModbusClientContext modbusClientContext;

//External 1 interrupt service routine
void __ISR(_EXTERNAL_1_VECTOR, IPL1AUTO) ext1IrqWrapper(void);


/**
 * @brief System initialization
 **/

void systemInit(void)
{
   uint32_t temp;

   //Execute system unlock sequence
   SYSKEY = 0xAA996655;
   SYSKEY = 0x556699AA;

   //Configure PBCLK clock divisor (SYSCLK / 2);
   temp = OSCCON & ~_OSCCON_PBDIV_MASK;
   OSCCON = temp | (1 << _OSCCON_PBDIV_POSITION);

   //Configure RAM wait states (0)
   BMXCONCLR = _BMXCON_BMXWSDRM_MASK;

   //Configure FLASH wait states (2)
   temp = CHECON & ~_CHECON_PFMWS_MASK;
   CHECON = temp | (2 << _CHECON_PFMWS_POSITION);

   //Enable predictive prefetch for both cacheable and non-cacheable regions
   temp = CHECON & ~_CHECON_PREFEN_MASK;
   CHECON = temp | (3 << _CHECON_PREFEN_POSITION);

   //Enable data caching (4 lines)
   temp = CHECON & ~_CHECON_DCSZ_MASK;
   CHECON = temp | (3 << _CHECON_DCSZ_POSITION);

   //Enable KSEG0 cache
   temp = _CP0_GET_CONFIG() & ~_CP0_CONFIG_K0_MASK;
   temp |= (3 << _CP0_CONFIG_K0_POSITION);
   _CP0_SET_CONFIG(temp);

   //Relock the SYSKEY
   SYSKEY = 0;

   //Disable interrupts
   __builtin_disable_interrupts();

   //Set IV
   _CP0_BIS_CAUSE(_CP0_CAUSE_IV_MASK);
   //Enable multi-vectored mode
   INTCONSET = _INTCON_MVEC_MASK;
}


/**
 * @brief I/O initialization
 **/

void ioInit(void)
{
   //Configure LED1 (RE4), LED2 (RE6) and LED3 (RE7)
   TRISECLR = LED1_MASK | LED2_MASK | LED3_MASK;
   //Clear LEDs
   LATECLR = LED1_MASK | LED2_MASK | LED3_MASK;
   //Disable analog pads
   ANSELECLR = LED1_MASK | LED2_MASK | LED3_MASK;

   //Configure LED4_R (RB10), LED4_G (RB3) and LED4_B (RB2)
   TRISBCLR = LED4_R_MASK | LED4_G_MASK | LED4_B_MASK;
   //Clear LEDs
   LATBSET = LED4_R_MASK | LED4_G_MASK | LED4_B_MASK;
   //Disable analog pads
   ANSELBCLR = LED4_R_MASK | LED4_G_MASK | LED4_B_MASK;

   //Configure SW1 (RD6)
   TRISDSET = SW1_MASK;
   //Enable pull-up
   CNPUDSET = SW1_MASK;
   //Disable analog pads
   ANSELDCLR = SW1_MASK;

   //Configure LAN9250 CS (RD4)
   TRISDCLR = _TRISD_TRISD4_MASK;
   //Deassert CS
   LATDSET = _LATD_LATD4_MASK;

   //Configure LAN9250 RST (RE3)
   TRISECLR = _TRISE_TRISE3_MASK;

   //Reset LAN9250 Ethernet controller
   LATECLR = _LATE_LATE3_MASK;
   sleep(100);
   LATESET = _LATE_LATE3_MASK;
   sleep(100);
}


/**
 * @brief Modbus/TCP client test routine
 * @return Error code
 **/

error_t modbusClientTest(void)
{
   error_t error;
   IpAddr ipAddr;
   uint8_t coilState[2];
   uint16_t regValue[5];
   ModbusExceptionCode exceptionCode;

   //Initialize Modbus/TCP client context
   modbusClientInit(&modbusClientContext);

   //Start of exception handling block
   do
   {
      //Debug message
      TRACE_INFO("\r\n\r\nResolving server name...\r\n");

      //Resolve Modbus/TCP server name
      error = getHostByName(NULL, APP_MODBUS_SERVER_NAME, &ipAddr, 0);
      //Any error to report?
      if(error)
      {
         //Debug message
         TRACE_ERROR("Failed to resolve server name!\r\n");
         break;
      }

      //Set timeout value for blocking operations
      error = modbusClientSetTimeout(&modbusClientContext, 15000);
      //Any error to report?
      if(error)
         break;

      //Debug message
      TRACE_INFO("Connecting to Modbus/TCP server %s...\r\n",
         ipAddrToString(&ipAddr, NULL));

      //Establish connection with the Modbus/TCP server
      error = modbusClientConnect(&modbusClientContext, &ipAddr,
         APP_MODBUS_SERVER_PORT);
      //Any error to report?
      if(error)
      {
         //Debug message
         TRACE_ERROR("Failed to connect to Modbus/TCP server!\r\n");
         break;
      }

      //Read coils
      error = modbusClientReadCoils(&modbusClientContext, 10000, 2, coilState);

      //Check status code
      if(error == NO_ERROR)
      {
         //Debug message
         TRACE_INFO("Coil 10000: %s\r\n", MODBUS_TEST_COIL(coilState, 0) ? "ON" : "OFF");
         TRACE_INFO("Coil 10001: %s\r\n", MODBUS_TEST_COIL(coilState, 1) ? "ON" : "OFF");
      }
      else if(error == ERROR_EXCEPTION_RECEIVED)
      {
         //Retrieve exception code
         modbusClientGetExceptionCode(&modbusClientContext, &exceptionCode);
         //Debug message
         TRACE_WARNING("Exception %u received!\r\n", exceptionCode);
      }
      else
      {
         //A protocol error has occurred
         break;
      }

      //Set coils 0 to 9 to the desired state
      MODBUS_SET_COIL(coilState, 0);
      MODBUS_RESET_COIL(coilState, 1);
      MODBUS_SET_COIL(coilState, 2);
      MODBUS_RESET_COIL(coilState, 3);
      MODBUS_SET_COIL(coilState, 4);
      MODBUS_RESET_COIL(coilState, 5);
      MODBUS_SET_COIL(coilState, 6);
      MODBUS_RESET_COIL(coilState, 7);
      MODBUS_SET_COIL(coilState, 8);
      MODBUS_RESET_COIL(coilState, 9);

      //Write multiple coils
      error = modbusClientWriteMultipleCoils(&modbusClientContext, 0, 10, coilState);

      //Check status code
      if(error == NO_ERROR)
      {
         //Successful write operation
      }
      else if(error == ERROR_EXCEPTION_RECEIVED)
      {
         //Retrieve exception code
         modbusClientGetExceptionCode(&modbusClientContext, &exceptionCode);
         //Debug message
         TRACE_WARNING("Exception %u received!\r\n", exceptionCode);
      }
      else
      {
         //A protocol error has occurred
         break;
      }

      //Read holding registers
      error = modbusClientReadHoldingRegs(&modbusClientContext, 30000, 2, regValue);

      //Check status code
      if(error == NO_ERROR)
      {
         //Debug message
         TRACE_INFO("Register 30000: 0x%04" PRIX16 "\r\n", regValue[0]);
         TRACE_INFO("Register 30001: 0x%04" PRIX16 "\r\n", regValue[1]);
      }
      else if(error == ERROR_EXCEPTION_RECEIVED)
      {
         //Retrieve exception code
         modbusClientGetExceptionCode(&modbusClientContext, &exceptionCode);
         //Debug message
         TRACE_WARNING("Exception %u received!\r\n", exceptionCode);
      }
      else
      {
         //A protocol error has occurred
         break;
      }

      //Set registers 40000 to 40004 to the desired state
      regValue[0] = 0x1111;
      regValue[1] = 0x2222;
      regValue[2] = 0x3333;
      regValue[3] = 0x4444;
      regValue[4] = 0x5555;

      //Write multiple registers
      error = modbusClientWriteMultipleRegs(&modbusClientContext, 40000, 5, regValue);

      //Check status code
      if(error == NO_ERROR)
      {
         //Successful write operation
      }
      else if(error == ERROR_EXCEPTION_RECEIVED)
      {
         //Retrieve exception code
         modbusClientGetExceptionCode(&modbusClientContext, &exceptionCode);
         //Debug message
         TRACE_WARNING("Exception %u received!\r\n", exceptionCode);
      }
      else
      {
         //A protocol error has occurred
         break;
      }

      //Close Modbus/TCP connection
      modbusClientDisconnect(&modbusClientContext);

      //End of exception handling block
   } while(0);

   //Release Modbus/TCP client context
   modbusClientDeinit(&modbusClientContext);

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
      //SW1 button pressed?
      if(!(PORTD & SW1_MASK))
      {
         //Modbus/TCP client test routine
         modbusClientTest();

         //Wait for the SW1 button to be released
         while(!(PORTD & SW1_MASK));
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
      LATESET = LED1_MASK;
      osDelayTask(100);
      LATECLR = LED1_MASK;
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

   //System initialization
   systemInit();

   //Initialize kernel
   osInitKernel();
   //Configure debug UART
   debugInit(115200);

   //Start-up message
   TRACE_INFO("\r\n");
   TRACE_INFO("*****************************************\r\n");
   TRACE_INFO("*** CycloneTCP Modbus/TCP Client Demo ***\r\n");
   TRACE_INFO("*****************************************\r\n");
   TRACE_INFO("Copyright: 2010-2024 Oryx Embedded SARL\r\n");
   TRACE_INFO("Compiled: %s %s\r\n", __DATE__, __TIME__);
   TRACE_INFO("Target: PIC32MX470F512H\r\n");
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

#if defined(USE_LAN8651)
   //Select the relevant network adapter
   netSetDriver(interface, &lan8651Driver);
#elif defined(USE_LAN9250)
   //Select the relevant network adapter
   netSetDriver(interface, &lan9250Driver);
#endif

   //Underlying SPI driver
   netSetSpiDriver(interface, &spiDriver);
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
