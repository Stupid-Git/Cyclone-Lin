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
#include "ek_ra6m3.h"
#include "core/net.h"
#include "drivers/mac/ra6_eth_driver.h"
#include "drivers/switch/ksz8895_driver.h"
#include "rstp/rstp.h"
#include "dhcp/dhcp_client.h"
#include "ipv6/slaac.h"
#include "snmp/snmp_agent.h"
#include "mibs/snmp_mib_module.h"
#include "mibs/snmp_mib_impl.h"
#include "mibs/bridge_mib_module.h"
#include "mibs/bridge_mib_impl.h"
#include "mibs/rstp_mib_module.h"
#include "mibs/rstp_mib_impl.h"
#include "spi_driver.h"
#include "debug.h"

//Ethernet interface configuration
#define APP_IF_NAME "eth0"
#define APP_HOST_NAME "rstp-bridge-demo"
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
#define RSTP_BRIDGE_NUM_PORTS 4

//Global variables
RstpBridgeSettings rstpBridgeSettings;
RstpBridgeContext rstpBridgeContext;
RstpBridgePort rstpBridgePorts[RSTP_BRIDGE_NUM_PORTS];
DhcpClientSettings dhcpClientSettings;
DhcpClientContext dhcpClientContext;
SlaacSettings slaacSettings;
SlaacContext slaacContext;
SnmpAgentSettings snmpAgentSettings;
SnmpAgentContext snmpAgentContext;


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

   //Lock PFS registers
   R_PMISC->PWPR &= ~R_PMISC_PWPR_PFSWE_Msk;
   R_PMISC->PWPR |= R_PMISC_PWPR_B0WI_Msk;

   //Clear LEDs
   LED1_PORT->PCNTR3 = LED1_MASK << R_PORT0_PCNTR3_PORR_Pos;
   LED2_PORT->PCNTR3 = LED2_MASK << R_PORT0_PCNTR3_PORR_Pos;
   LED3_PORT->PCNTR3 = LED3_MASK << R_PORT0_PCNTR3_PORR_Pos;
}


/**
 * @brief Ethernet GPIO configuration
 * @param[in] interface Underlying network interface
 **/

void ra6EthInitGpio(NetInterface *interface)
{
   //Disable protection
   R_SYSTEM->PRCR = 0xA50B;
   //Disable VBATT channel 0 input (P4_2)
   R_SYSTEM->VBTICTLR &= ~R_SYSTEM_VBTICTLR_VCH0INEN_Msk;
   //Enable protection
   R_SYSTEM->PRCR = 0xA500;

   //Unlock PFS registers
   R_PMISC->PWPR &= ~R_PMISC_PWPR_B0WI_Msk;
   R_PMISC->PWPR |= R_PMISC_PWPR_PFSWE_Msk;

   //Select RMII interface mode
   R_PMISC->PFENET &= ~R_PMISC_PFENET_PHYMODE0_Msk;

   //Configure RMII0_CRS_DV_A (P4_8)
   R_PFS->PORT[4].PIN[8].PmnPFS = (23 << R_PFS_PORT_PIN_PmnPFS_PSEL_Pos) |
      R_PFS_PORT_PIN_PmnPFS_PMR_Msk | (3 << R_PFS_PORT_PIN_PmnPFS_DSCR_Pos);

   //Configure RMII0_RXD1_A (P4_10)
   R_PFS->PORT[4].PIN[10].PmnPFS = (23 << R_PFS_PORT_PIN_PmnPFS_PSEL_Pos) |
      R_PFS_PORT_PIN_PmnPFS_PMR_Msk | (3 << R_PFS_PORT_PIN_PmnPFS_DSCR_Pos);

   //Configure RMII0_RXD0_A (P4_11)
   R_PFS->PORT[4].PIN[11].PmnPFS = (23 << R_PFS_PORT_PIN_PmnPFS_PSEL_Pos) |
      R_PFS_PORT_PIN_PmnPFS_PMR_Msk | (3 << R_PFS_PORT_PIN_PmnPFS_DSCR_Pos);

   //Configure REF50CK0_A (P4_12)
   R_PFS->PORT[4].PIN[12].PmnPFS = (23 << R_PFS_PORT_PIN_PmnPFS_PSEL_Pos) |
      R_PFS_PORT_PIN_PmnPFS_PMR_Msk | (3 << R_PFS_PORT_PIN_PmnPFS_DSCR_Pos);

   //Configure RMII0_TXD0_A (P4_13)
   R_PFS->PORT[4].PIN[13].PmnPFS = (23 << R_PFS_PORT_PIN_PmnPFS_PSEL_Pos) |
      R_PFS_PORT_PIN_PmnPFS_PMR_Msk | (3 << R_PFS_PORT_PIN_PmnPFS_DSCR_Pos);

   //Configure RMII0_TXD1_A (P4_14)
   R_PFS->PORT[4].PIN[14].PmnPFS = (23 << R_PFS_PORT_PIN_PmnPFS_PSEL_Pos) |
      R_PFS_PORT_PIN_PmnPFS_PMR_Msk | (3 << R_PFS_PORT_PIN_PmnPFS_DSCR_Pos);

   //Configure RMII0_TXD_EN_A (P4_15)
   R_PFS->PORT[4].PIN[15].PmnPFS = (23 << R_PFS_PORT_PIN_PmnPFS_PSEL_Pos) |
      R_PFS_PORT_PIN_PmnPFS_PMR_Msk | (3 << R_PFS_PORT_PIN_PmnPFS_DSCR_Pos);

   //Configure switch reset pin
   R_PFS->PORT[2].PIN[7].PmnPFS = R_PFS_PORT_PIN_PmnPFS_PDR_Msk;

   //Lock PFS registers
   R_PMISC->PWPR &= ~R_PMISC_PWPR_PFSWE_Msk;
   R_PMISC->PWPR |= R_PMISC_PWPR_B0WI_Msk;

   //Reset switch
   R_PORT2->PCNTR3 = (1 << 7) << R_PORT0_PCNTR3_PORR_Pos;
   sleep(10);
   R_PORT2->PCNTR3 = (1 << 7) << R_PORT0_PCNTR3_POSR_Pos;
   sleep(10);
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
   uint_t i;
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
   TRACE_INFO("*** CycloneSTP RSTP Bridge Demo ***\r\n");
   TRACE_INFO("***********************************\r\n");
   TRACE_INFO("Copyright: 2010-2024 Oryx Embedded SARL\r\n");
   TRACE_INFO("Compiled: %s %s\r\n", __DATE__, __TIME__);
   TRACE_INFO("Target: RA6M3\r\n");
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

   //BRIDGE-MIB initialization
   error = bridgeMibInit();
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize BRIDGE-MIB!\r\n");
   }

   //RSTP-MIB initialization
   error = rstpMibInit();
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize RSTP-MIB!\r\n");
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
   netSetDriver(interface, &ra6EthDriver);
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
   rstpGetDefaultSettings(&rstpBridgeSettings);
   //Underlying network interface
   rstpBridgeSettings.interface = interface;
   //Bridge ports
   rstpBridgeSettings.numPorts = RSTP_BRIDGE_NUM_PORTS;
   rstpBridgeSettings.ports = rstpBridgePorts;

   //RSTP bridge initialization
   error = rstpInit(&rstpBridgeContext, &rstpBridgeSettings);
   //Failed to initialize RSTP bridge?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize RSTP bridge!\r\n");
   }

   //Configure bridge ports
   for(i = 1; i <= rstpBridgeContext.numPorts; i++)
   {
      rstpSetAdminPointToPointMac(&rstpBridgeContext, i, RSTP_ADMIN_P2P_MAC_FORCE_TRUE);
      rstpSetAutoEdgePort(&rstpBridgeContext, i, TRUE);
      rstpSetAdminPortState(&rstpBridgeContext, i, TRUE);
   }

   //Start RSTP bridge
   error = rstpStart(&rstpBridgeContext);
   //Failed to start RSTP bridge?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start RSTP bridge!\r\n");
   }

   //Attach the RSTP bridge context to the BRIDGE-MIB and RSTP-MIB
   bridgeMibSetRstpBridgeContext(&rstpBridgeContext);
   rstpMibSetRstpBridgeContext(&rstpBridgeContext);

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
   //Load BRIDGE-MIB
   snmpAgentLoadMib(&snmpAgentContext, &bridgeMibModule);
   //Load RSTP-MIB
   snmpAgentLoadMib(&snmpAgentContext, &rstpMibModule);

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
