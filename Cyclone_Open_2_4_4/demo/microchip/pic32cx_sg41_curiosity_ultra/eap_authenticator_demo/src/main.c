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
#include "pic32c.h"
#include "pic32cx_sg41_curiosity_ultra.h"
#include "core/net.h"
#include "drivers/mac/pic32cx_eth_driver.h"
#include "drivers/switch/ksz8863_driver.h"
#include "drivers/switch/lan9303_driver.h"
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
#define APP_MAC_ADDR "00-AB-CD-32-41-00"

#define APP_USE_DHCP_CLIENT ENABLED
#define APP_IPV4_HOST_ADDR "192.168.0.20"
#define APP_IPV4_SUBNET_MASK "255.255.255.0"
#define APP_IPV4_DEFAULT_GATEWAY "192.168.0.254"
#define APP_IPV4_PRIMARY_DNS "8.8.8.8"
#define APP_IPV4_SECONDARY_DNS "8.8.4.4"

#define APP_USE_SLAAC ENABLED
#define APP_IPV6_LINK_LOCAL_ADDR "fe80::3241"
#define APP_IPV6_PREFIX "2001:db8::"
#define APP_IPV6_PREFIX_LENGTH 64
#define APP_IPV6_GLOBAL_ADDR "2001:db8::3241"
#define APP_IPV6_ROUTER "fe80::1"
#define APP_IPV6_PRIMARY_DNS "2001:4860:4860::8888"
#define APP_IPV6_SECONDARY_DNS "2001:4860:4860::8844"

//802.1X authenticator configuration
#define APP_AUTHENTICATOR_NUM_PORTS 2

//RADIUS server configuration
#define APP_RADIUS_SERVER_IP_ADDR "192.168.0.10"
#define APP_RADIUS_SERVER_PORT 1812
#define APP_RADIUS_SERVER_KEY "testing123"

//Global variables
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
 * @brief I/O initialization
 **/

void ioInit(void)
{
   //Enable PORT bus clock (CLK_PORT_APB)
   MCLK_REGS->MCLK_APBBMASK |= MCLK_APBBMASK_PORT_Msk;

   //Configure LED1
   PORT_REGS->GROUP[LED1_GROUP].PORT_DIRSET = LED1_MASK;
   PORT_REGS->GROUP[LED1_GROUP].PORT_OUTSET = LED1_MASK;

   //Configure LED2
   PORT_REGS->GROUP[LED2_GROUP].PORT_DIRSET = LED2_MASK;
   PORT_REGS->GROUP[LED2_GROUP].PORT_OUTSET = LED2_MASK;

   //Configure SW1 button
   PORT_REGS->GROUP[SW1_GROUP].PORT_DIRCLR = SW1_MASK;
   PORT_REGS->GROUP[SW1_GROUP].PORT_OUTSET = SW1_PIN;
   PORT_REGS->GROUP[SW1_GROUP].PORT_PINCFG[SW1_PIN] |= PORT_PINCFG_PULLEN_Msk |
      PORT_PINCFG_INEN_Msk;

   //Configure SW2 button
   PORT_REGS->GROUP[SW2_GROUP].PORT_DIRCLR = SW2_MASK;
   PORT_REGS->GROUP[SW2_GROUP].PORT_OUTSET = SW2_PIN;
   PORT_REGS->GROUP[SW2_GROUP].PORT_PINCFG[SW2_PIN] |= PORT_PINCFG_PULLEN_Msk |
      PORT_PINCFG_INEN_Msk;
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
      PORT_REGS->GROUP[LED1_GROUP].PORT_OUTCLR = LED1_MASK;
      osDelayTask(100);
      PORT_REGS->GROUP[LED1_GROUP].PORT_OUTSET = LED1_MASK;
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

   //Update system core clock
   SystemCoreClockUpdate();

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
   TRACE_INFO("Target: PIC32CX1025SG41128\r\n");
   TRACE_INFO("\r\n");

   //Configure I/Os
   ioInit();

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
   netSetDriver(interface, &pic32cxEthDriver);

#if defined(USE_KSZ8863)
   //Select the relevant switch driver
   netSetSwitchDriver(interface, &ksz8863SwitchDriver);
   //Underlying SPI driver
   netSetSpiDriver(interface, &spiDriver);
#elif defined(USE_LAN9303)
   //Select the relevant switch driver
   netSetSwitchDriver(interface, &lan9303SwitchDriver);
#endif

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
   authenticatorSetPortControl(&authenticatorContext, 2, AUTHENTICATOR_PORT_MODE_FORCE_AUTH);

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
