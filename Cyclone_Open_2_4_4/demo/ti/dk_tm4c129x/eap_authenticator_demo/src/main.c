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
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "tm4c129xnczad.h"
#include "system_tm4c129.h"
#include "inc/hw_emac.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "grlib/grlib.h"
#include "drivers/pinout.h"
#include "drivers/kentec320x240x16_ssd2119.h"
#include "core/net.h"
#include "drivers/mac/tm4c129_eth_driver.h"
#include "drivers/switch/ksz8895_driver.h"
#include "authenticator/authenticator.h"
#include "dhcp/dhcp_client.h"
#include "ipv6/slaac.h"
#include "snmp/snmp_agent.h"
#include "mibs/snmp_mib_module.h"
#include "mibs/snmp_mib_impl.h"
#include "mibs/ieee8021_pae_mib_module.h"
#include "mibs/ieee8021_pae_mib_impl.h"
#include "rng/yarrow.h"
#include "spi_driver.h"
#include "debug.h"

//Ethernet interface configuration
#define APP_IF_NAME "eth0"
#define APP_HOST_NAME "eap-authenticator-demo"
#define APP_MAC_ADDR "00-AB-CD-41-29-00"

#define APP_USE_DHCP_CLIENT ENABLED
#define APP_IPV4_HOST_ADDR "192.168.0.20"
#define APP_IPV4_SUBNET_MASK "255.255.255.0"
#define APP_IPV4_DEFAULT_GATEWAY "192.168.0.254"
#define APP_IPV4_PRIMARY_DNS "8.8.8.8"
#define APP_IPV4_SECONDARY_DNS "8.8.4.4"

#define APP_USE_SLAAC ENABLED
#define APP_IPV6_LINK_LOCAL_ADDR "fe80::4129"
#define APP_IPV6_PREFIX "2001:db8::"
#define APP_IPV6_PREFIX_LENGTH 64
#define APP_IPV6_GLOBAL_ADDR "2001:db8::4129"
#define APP_IPV6_ROUTER "fe80::1"
#define APP_IPV6_PRIMARY_DNS "2001:4860:4860::8888"
#define APP_IPV6_SECONDARY_DNS "2001:4860:4860::8844"

//802.1X authenticator configuration
#define APP_AUTHENTICATOR_NUM_PORTS 4

//RADIUS server configuration
#define APP_RADIUS_SERVER_IP_ADDR "192.168.0.10"
#define APP_RADIUS_SERVER_PORT 1812
#define APP_RADIUS_SERVER_KEY "testing123"

//Global variables
uint_t lcdLine = 0;
uint_t lcdColumn = 0;

tContext grContext;
AuthenticatorSettings authenticatorSettings;
AuthenticatorContext authenticatorContext;
AuthenticatorPort authenticatorPorts[APP_AUTHENTICATOR_NUM_PORTS];
DhcpClientSettings dhcpClientSettings;
DhcpClientContext dhcpClientContext;
SlaacSettings slaacSettings;
SlaacContext slaacContext;
SnmpAgentSettings snmpAgentSettings;
SnmpAgentContext snmpAgentContext;
YarrowContext yarrowContext;

//Forward declaration of functions
void authenticatorPaeStateChangeCallback(AuthenticatorPort *port,
   AuthenticatorPaeState state);


/**
 * @brief Ethernet GPIO configuration
 * @param[in] interface Underlying network interface
 **/

void tm4c129EthInitGpio(NetInterface *interface)
{
   uint32_t temp;

   //Enable GPIO clocks
   SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
   SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOG);
   SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOM);
   SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOP);
   SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOQ);
   SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOS);

#if 0
   //Configure EN0MDC (PF2)
   GPIOPinConfigure(GPIO_PF2_EN0MDC);
   GPIOPinTypeEthernetMII(GPIO_PORTF_BASE, GPIO_PIN_2);

   //Configure EN0MDIO (PF3)
   GPIOPinConfigure(GPIO_PF3_EN0MDIO);
   GPIOPinTypeEthernetMII(GPIO_PORTF_BASE, GPIO_PIN_3);
#endif

   //Configure EN0RREF_CLK (PM4)
   GPIOPinConfigure(GPIO_PM4_EN0RREF_CLK);
   GPIOPinTypeEthernetMII(GPIO_PORTM_BASE, GPIO_PIN_4);

   //Configure EN0TXEN (PG3)
   GPIOPinConfigure(GPIO_PG3_EN0TXEN);
   GPIOPinTypeEthernetMII(GPIO_PORTG_BASE, GPIO_PIN_3);

   //Configure EN0TXD0 (PG4)
   GPIOPinConfigure(GPIO_PG4_EN0TXD0);
   GPIOPinTypeEthernetMII(GPIO_PORTG_BASE, GPIO_PIN_4);

   //Configure EN0TXD1 (PG5)
   GPIOPinConfigure(GPIO_PG5_EN0TXD1);
   GPIOPinTypeEthernetMII(GPIO_PORTG_BASE, GPIO_PIN_5);

   //Configure EN0RXDV (PG7)
   GPIOPinConfigure(GPIO_PG7_EN0RXDV);
   GPIOPinTypeEthernetMII(GPIO_PORTG_BASE, GPIO_PIN_7);

   //Configure EN0RXD0 (PQ5)
   GPIOPinConfigure(GPIO_PQ5_EN0RXD0);
   GPIOPinTypeEthernetMII(GPIO_PORTQ_BASE, GPIO_PIN_5);

   //Configure EN0RXD1 (PQ6)
   GPIOPinConfigure(GPIO_PQ6_EN0RXD1);
   GPIOPinTypeEthernetMII(GPIO_PORTQ_BASE, GPIO_PIN_6);

#if 0
   //Configure EN0INTRN (PP0)
   GPIOPinConfigure(GPIO_PP0_EN0INTRN);
   GPIOPinTypeEthernetMII(GPIO_PORTP_BASE, GPIO_PIN_0);

   //Enable pull-up resistor
   GPIOPadConfigSet(GPIO_PORTP_BASE, GPIO_PIN_0, GPIO_STRENGTH_10MA,
      GPIO_PIN_TYPE_STD_WPU);
#endif

   //Configure switch reset pin (PS6) as an output
   GPIOPinTypeGPIOOutput(GPIO_PORTS_BASE, GPIO_PIN_6);

   //Set pad configuration
   GPIOPadConfigSet(GPIO_PORTS_BASE, GPIO_PIN_6, GPIO_STRENGTH_10MA,
      GPIO_PIN_TYPE_STD);

   //Reset switch
   GPIOPinWrite(GPIO_PORTS_BASE, GPIO_PIN_6, 0);
   sleep(10);
   GPIOPinWrite(GPIO_PORTS_BASE, GPIO_PIN_6, GPIO_PIN_6);
   sleep(10);

   //Enable the external clock source input
   EMAC0_CC_R |= EMAC_CC_CLKEN;

   //Select external PHY
   EMAC0_PC_R |= EMAC_PC_PHYEXT;

   //Select RMII interface
   temp = EMAC0_PC_R & ~EMAC_PC_PINTFS_M;
   EMAC0_PC_R = temp | EMAC_PC_PINTFS_RMII;
}


/**
 * @brief Set cursor location
 * @param[in] line Line number
 * @param[in] column Column number
 **/

void lcdSetCursor(uint_t line, uint_t column)
{
   lcdLine = MIN(line, 26);
   lcdColumn = MIN(column, 40);
}


/**
 * @brief Write a character to the LCD display
 * @param[in] c Character to be written
 **/

void lcdPutChar(char_t c)
{
   if(c == '\r')
   {
      lcdColumn = 0;
   }
   else if(c == '\n')
   {
      lcdColumn = 0;
      lcdLine++;
   }
   else if(lcdLine < 26 && lcdColumn < 40)
   {
      char_t buffer[2];
      buffer[0] = c;
      buffer[1] = '\0';

      //Display current character
      GrStringDraw(&grContext, buffer, 1, lcdColumn * 6, lcdLine * 12, TRUE);

      //Advance the cursor position
      if(++lcdColumn >= 40)
      {
         lcdColumn = 0;
         lcdLine++;
      }
   }
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
#if (IPV6_SUPPORT == ENABLED)
   Ipv6Addr ipv6Addr;
#endif

   //Point to the network interface
   NetInterface *interface = &netInterface[0];

   lcdSetCursor(2, 0);
   printf("IPv4 Address\r\n");
   lcdSetCursor(5, 0);
   printf("IPv6 Link-Local Address\r\n");
   lcdSetCursor(8, 0);
   printf("IPv6 Global Address\r\n");

   //Endless loop
   while(1)
   {
#if (IPV4_SUPPORT == ENABLED)
      //Display IPv4 host address
      lcdSetCursor(3, 0);
      ipv4GetHostAddr(interface, &ipv4Addr);
      printf("%-16s\r\n", ipv4AddrToString(ipv4Addr, buffer));
#endif

#if (IPV6_SUPPORT == ENABLED)
      //Display IPv6 link-local address
      lcdSetCursor(6, 0);
      ipv6GetLinkLocalAddr(interface, &ipv6Addr);
      printf("%-40s\r\n", ipv6AddrToString(&ipv6Addr, buffer));

      //Display IPv6 global address
      lcdSetCursor(9, 0);
      ipv6GetGlobalAddr(interface, 0, &ipv6Addr);
      printf("%-40s\r\n", ipv6AddrToString(&ipv6Addr, buffer));
#endif

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
      GPIOPinWrite(GPIO_PORTQ_BASE, GPIO_PIN_7, GPIO_PIN_7);
      osDelayTask(100);
      GPIOPinWrite(GPIO_PORTQ_BASE, GPIO_PIN_7, 0);
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

#ifdef __TI_ARM__
   //System initialization
   SystemInit();
#endif

   //Initialize kernel
   osInitKernel();
   //Configure debug UART
   debugInit(115200);

   //Start-up message
   TRACE_INFO("\r\n");
   TRACE_INFO("********************************************\r\n");
   TRACE_INFO("*** CycloneEAP 802.1X Authenticator Demo ***\r\n");
   TRACE_INFO("********************************************\r\n");
   TRACE_INFO("Copyright: 2010-2024 Oryx Embedded SARL\r\n");
   TRACE_INFO("Compiled: %s %s\r\n", __DATE__, __TIME__);
   TRACE_INFO("Target: TM4C129X\r\n");
   TRACE_INFO("\r\n");

   //Configure I/Os
   PinoutSet();

   //Initialize LCD display
   Kentec320x240x16_SSD2119Init(SystemCoreClock);
   //Initialize drawing context
   GrContextInit(&grContext, &g_sKentec320x240x16_SSD2119);
   GrContextForegroundSet(&grContext, ClrWhite);
   //GrContextFontSet(&grContext, g_psFontCmss18b);
   GrContextFontSet(&grContext, g_psFontFixed6x8);

   //Welcome message
   lcdSetCursor(0, 0);
   printf("EAP Authenticator Demo\r\n");

   //SNMPv2-MIB initialization
   error = snmpMibInit();
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize SNMPv2-MIB!\r\n");
   }

   //IEEE8021-PAE-MIB initialization
   error = ieee8021PaeMibInit();
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize IEEE8021-PAE-MIB!\r\n");
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
   //Select the relevant MAC driver
   netSetDriver(interface, &tm4c129EthDriver);
   //Select the relevant switch driver
   netSetSwitchDriver(interface, &ksz8895SwitchDriver);
   //Underlying SPI driver
   netSetSpiDriver(interface, &spiDriver);

   //Initialize network interface
   error = netConfigInterface(interface);
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to configure interface %s!\r\n", interface->name);
   }

   //Get default settings
   authenticatorGetDefaultSettings(&authenticatorSettings);
   //Underlying network interface
   authenticatorSettings.interface = interface;
   //Number of ports
   authenticatorSettings.numPorts = arraysize(authenticatorPorts);
   //Ports
   authenticatorSettings.ports = authenticatorPorts;
   //RADIUS server's IP address
   ipStringToAddr(APP_RADIUS_SERVER_IP_ADDR, &authenticatorSettings.serverIpAddr);
   //RADIUS server's port
   authenticatorSettings.serverPort = APP_RADIUS_SERVER_PORT;
   //Pseudo-random number generator
   authenticatorSettings.prngAlgo = YARROW_PRNG_ALGO;
   authenticatorSettings.prngContext = &yarrowContext;
   //Authenticator PAE state change callback function
   authenticatorSettings.paeStateChangeCallback = authenticatorPaeStateChangeCallback;

   //802.1X authenticator initialization
   error = authenticatorInit(&authenticatorContext, &authenticatorSettings);
   //Failed to initialize 802.1X authenticator?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize 802.1X authenticator!\r\n");
   }

   //Set RADIUS server's key
   error = authenticatorSetServerKey(&authenticatorContext,
      (uint8_t *) APP_RADIUS_SERVER_KEY, osStrlen(APP_RADIUS_SERVER_KEY));
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to set RADIUS server's key!\r\n");
   }

   //Configure ports
   authenticatorSetPortControl(&authenticatorContext, 1, AUTHENTICATOR_PORT_MODE_AUTO);
   authenticatorSetPortControl(&authenticatorContext, 2, AUTHENTICATOR_PORT_MODE_AUTO);
   authenticatorSetPortControl(&authenticatorContext, 3, AUTHENTICATOR_PORT_MODE_AUTO);
   authenticatorSetPortControl(&authenticatorContext, 4, AUTHENTICATOR_PORT_MODE_FORCE_AUTH);

   //Start 802.1X authenticator
   error = authenticatorStart(&authenticatorContext);
   //Failed to start 802.1X authenticator?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start 802.1X authenticator!\r\n");
   }

   //Attach the 802.1X authenticator context to the IEEE8021-PAE-MIB
   ieee8021PaeMibSetAuthenticatorContext(&authenticatorContext);

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
   snmpAgentGetDefaultSettings(&snmpAgentSettings);
   //Bind SNMP agent to the desired network interface
   snmpAgentSettings.interface = interface;
   //Minimum version accepted by the SNMP agent
   snmpAgentSettings.versionMin = SNMP_VERSION_1;
   //Maximum version accepted by the SNMP agent
   snmpAgentSettings.versionMax = SNMP_VERSION_2C;
   //SNMP port number
   snmpAgentSettings.port = SNMP_PORT;
   //SNMP trap port number
   snmpAgentSettings.trapPort = SNMP_TRAP_PORT;

   //SNMP agent initialization
   error = snmpAgentInit(&snmpAgentContext, &snmpAgentSettings);
   //Failed to initialize SNMP agent?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize SNMP agent!\r\n");
   }

   //Load SNMPv2-MIB
   snmpAgentLoadMib(&snmpAgentContext, &snmpMibModule);
   //Load IEEE8021-PAE-MIB
   snmpAgentLoadMib(&snmpAgentContext, &ieee8021PaeMibModule);

   //Set read-only community string
   snmpAgentCreateCommunity(&snmpAgentContext, "public",
      SNMP_ACCESS_READ_ONLY);

   //Set read-write community string
   snmpAgentCreateCommunity(&snmpAgentContext, "private",
      SNMP_ACCESS_READ_WRITE);

   //Start SNMP agent
   error = snmpAgentStart(&snmpAgentContext);
   //Failed to start SNMP agent?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start SNMP agent!\r\n");
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
 * @brief Authenticator PAE state change callback function
 * @param[in] port Pointer to the port context
 * @param[in] state Authenticator PAE state
 **/

void authenticatorPaeStateChangeCallback(AuthenticatorPort *port,
   AuthenticatorPaeState state)
{
   //Check current state
   if(state == AUTHENTICATOR_PAE_STATE_INITIALIZE)
   {
      TRACE_INFO("\r\n");
      TRACE_INFO("***************************\r\n");
      TRACE_INFO("*** Port %u: INITIALIZE ***\r\n", port->portIndex);
      TRACE_INFO("***************************\r\n");
      TRACE_INFO("\r\n");
   }
   else if(state == AUTHENTICATOR_PAE_STATE_DISCONNECTED)
   {
      TRACE_INFO("\r\n");
      TRACE_INFO("****************************\r\n");
      TRACE_INFO("*** Port %u: DISCONNECTED ***\r\n", port->portIndex);
      TRACE_INFO("****************************\r\n");
      TRACE_INFO("\r\n");
   }
   else if(state == AUTHENTICATOR_PAE_STATE_RESTART)
   {
      TRACE_INFO("\r\n");
      TRACE_INFO("***********************\r\n");
      TRACE_INFO("*** Port %u: RESTART ***\r\n", port->portIndex);
      TRACE_INFO("***********************\r\n");
      TRACE_INFO("\r\n");
   }
   else if(state == AUTHENTICATOR_PAE_STATE_CONNECTING)
   {
      TRACE_INFO("\r\n");
      TRACE_INFO("**************************\r\n");
      TRACE_INFO("*** Port %u: CONNECTING ***\r\n", port->portIndex);
      TRACE_INFO("**************************\r\n");
      TRACE_INFO("\r\n");
   }
   else if(state == AUTHENTICATOR_PAE_STATE_AUTHENTICATING)
   {
      TRACE_INFO("\r\n");
      TRACE_INFO("******************************\r\n");
      TRACE_INFO("*** Port %u: AUTHENTICATING ***\r\n", port->portIndex);
      TRACE_INFO("******************************\r\n");
      TRACE_INFO("\r\n");
   }
   else if(state == AUTHENTICATOR_PAE_STATE_AUTHENTICATED)
   {
      TRACE_INFO("\r\n");
      TRACE_INFO("*****************************\r\n");
      TRACE_INFO("*** Port %u: AUTHENTICATED ***\r\n", port->portIndex);
      TRACE_INFO("*****************************\r\n");
      TRACE_INFO("\r\n");
   }
   else if(state == AUTHENTICATOR_PAE_STATE_ABORTING)
   {
      TRACE_INFO("\r\n");
      TRACE_INFO("*************************\r\n");
      TRACE_INFO("*** Port %u: ABORTING ***\r\n", port->portIndex);
      TRACE_INFO("*************************\r\n");
      TRACE_INFO("\r\n");
   }
   else if(state == AUTHENTICATOR_PAE_STATE_HELD)
   {
      TRACE_INFO("\r\n");
      TRACE_INFO("*********************\r\n");
      TRACE_INFO("*** Port %u: HELD ***\r\n", port->portIndex);
      TRACE_INFO("*********************\r\n");
      TRACE_INFO("\r\n");
   }
   else if(state == AUTHENTICATOR_PAE_STATE_FORCE_AUTH)
   {
      TRACE_INFO("\r\n");
      TRACE_INFO("***************************\r\n");
      TRACE_INFO("*** Port %u: FORCE_AUTH ***\r\n", port->portIndex);
      TRACE_INFO("***************************\r\n");
      TRACE_INFO("\r\n");
   }
   else if(state == AUTHENTICATOR_PAE_STATE_FORCE_UNAUTH)
   {
      TRACE_INFO("\r\n");
      TRACE_INFO("*****************************\r\n");
      TRACE_INFO("*** Port %u: FORCE_UNAUTH ***\r\n", port->portIndex);
      TRACE_INFO("*****************************\r\n");
      TRACE_INFO("\r\n");
   }  
   else
   {
   }
}
