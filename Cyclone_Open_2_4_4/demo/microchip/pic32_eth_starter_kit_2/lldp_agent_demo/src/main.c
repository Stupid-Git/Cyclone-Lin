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
#include "pic32_eth_starter_kit_2.h"
#include "core/net.h"
#include "drivers/mac/pic32mx_eth_driver.h"
#include "drivers/phy/lan8740_driver.h"
#include "lldp/lldp.h"
#include "lldp/lldp_ext_dot1.h"
#include "lldp/lldp_ext_dot3.h"
#include "lldp/lldp_ext_med.h"
#include "dhcp/dhcp_client.h"
#include "ipv6/slaac.h"
#include "snmp/snmp_agent.h"
#include "mibs/snmp_mib_module.h"
#include "mibs/snmp_mib_impl.h"
#include "mibs/lldp_mib_module.h"
#include "mibs/lldp_mib_impl.h"
#include "debug.h"

#ifndef _CP0_SET_CONFIG
    #define _CP0_SET_CONFIG(val) _mtc0(_CP0_CONFIG, _CP0_CONFIG_SELECT, val)
#endif

//Configuration bits
#pragma config USERID = 0xFFFF
#pragma config FSRSSEL = PRIORITY_7
#pragma config FMIIEN = OFF
#pragma config FETHIO = OFF
#pragma config FCANIO = OFF
#pragma config FUSBIDIO = OFF
#pragma config FVBUSONIO = OFF
#pragma config FPLLIDIV = DIV_2
#pragma config FPLLMUL = MUL_20
#pragma config UPLLIDIV = DIV_2
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
#pragma config FWDTEN = OFF
//#pragma config DEBUG = ON
#pragma config ICESEL = ICS_PGx2
#pragma config PWP = OFF
#pragma config BWP = OFF
#pragma config CP = OFF

//Ethernet interface configuration
#define APP_IF_NAME "eth0"
#define APP_HOST_NAME "lldp-agent-demo"
#define APP_USE_DEFAULT_MAC_ADDR ENABLED
#define APP_MAC_ADDR "00-AB-CD-EF-07-95"

#define APP_USE_DHCP_CLIENT ENABLED
#define APP_IPV4_HOST_ADDR "192.168.0.20"
#define APP_IPV4_SUBNET_MASK "255.255.255.0"
#define APP_IPV4_DEFAULT_GATEWAY "192.168.0.254"
#define APP_IPV4_PRIMARY_DNS "8.8.8.8"
#define APP_IPV4_SECONDARY_DNS "8.8.4.4"

#define APP_USE_SLAAC ENABLED
#define APP_IPV6_LINK_LOCAL_ADDR "fe80::795"
#define APP_IPV6_PREFIX "2001:db8::"
#define APP_IPV6_PREFIX_LENGTH 64
#define APP_IPV6_GLOBAL_ADDR "2001:db8::795"
#define APP_IPV6_ROUTER "fe80::1"
#define APP_IPV6_PRIMARY_DNS "2001:4860:4860::8888"
#define APP_IPV6_SECONDARY_DNS "2001:4860:4860::8844"

//Application configuration
#define LLDP_AGENT_NUM_PORTS 1

//Global variables
LldpAgentSettings lldpAgentSettings;
LldpAgentContext lldpAgentContext;
LldpPortEntry lldpPorts[LLDP_AGENT_NUM_PORTS];
DhcpClientSettings dhcpClientSettings;
DhcpClientContext dhcpClientContext;
SlaacSettings slaacSettings;
SlaacContext slaacContext;
SnmpAgentSettings snmpAgentSettings;
SnmpAgentContext snmpAgentContext;

//Forward declaration of functions
void dhcpClientLinkChangeCallback (DhcpClientCtx *context,
   NetInterface *interface, bool_t linkState);

void dhcpClientStateChangeCallback(DhcpClientContext *context,
   NetInterface *interface, DhcpState state);

//Ethernet interrupt service routine
void __ISR(_ETH_VECTOR, IPL1AUTO) ethIrqWrapper(void);


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
   //Disable analog inputs
   AD1PCFG = 0xFFFF;

   //Configure LED1 (RD0), LED2 (RD1) and LED3 (RD3)
   TRISDCLR = LED1_MASK | LED2_MASK | LED3_MASK;
   LATDCLR = LED1_MASK | LED2_MASK | LED3_MASK;

   //Configure SW1 (RD6), SW2 (RD7) and SW3 (RD13)
   TRISDSET = SW1_MASK | SW2_MASK | SW3_MASK;
   //Enable pull-ups on CN15 (RD6), CN16 (RD7) and CN19 (RD13)
   CNPUESET = _CNPUE_CNPUE15_MASK | _CNPUE_CNPUE16_MASK | _CNPUE_CNPUE19_MASK;

   //Configure MEB_LED1 (RD1), MEB_LED2 (RD2) and MEB_LED3 (RD3))
   TRISDCLR = MEB_LED1_MASK | MEB_LED2_MASK | MEB_LED3_MASK;
   LATDCLR = MEB_LED1_MASK | MEB_LED2_MASK | MEB_LED3_MASK;

   //Configure MEB_LED4 (RC2) and MEB_LED5 (RC1)
   TRISCCLR = MEB_LED4_MASK | MEB_LED5_MASK;
   LATCCLR = MEB_LED4_MASK | MEB_LED5_MASK;

   //Configure MEB_JOY_LEFT (RB0), MEB_JOY_RIGHT (RB4), MEB_JOY_UP (RB1),
   //MEB_JOY_DOWN (RB3) and MEB_JOY_FIRE (RB15)
   TRISBSET = MEB_JOY_LEFT_MASK | MEB_JOY_RIGHT_MASK |
      MEB_JOY_UP_MASK | MEB_JOY_DOWN_MASK | MEB_JOY_FIRE_MASK;

   //Enable pull-ups on CN2 (RB0), CN3 (RB1), CN5 (RB3), CN6 (RB4) and CN12 (RB15)
   CNPUESET = _CNPUE_CNPUE2_MASK | _CNPUE_CNPUE3_MASK |
      _CNPUE_CNPUE5_MASK | _CNPUE_CNPUE6_MASK | _CNPUE_CNPUE12_MASK;
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
      LATDSET = MEB_LED1_MASK;
      osDelayTask(100);
      LATDCLR = MEB_LED1_MASK;
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
   TRACE_INFO("**********************************\r\n");
   TRACE_INFO("*** CycloneTCP LLDP Agent Demo ***\r\n");
   TRACE_INFO("**********************************\r\n");
   TRACE_INFO("Copyright: 2010-2024 Oryx Embedded SARL\r\n");
   TRACE_INFO("Compiled: %s %s\r\n", __DATE__, __TIME__);
   TRACE_INFO("Target: PIC32MX795F512L\r\n");
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

   //LLDP-MIB initialization
   error = lldpMibInit();
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize LLDP-MIB!\r\n");
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

#if (APP_USE_DEFAULT_MAC_ADDR == ENABLED)
   //Use the factory preprogrammed MAC address
   macStringToAddr("00-00-00-00-00-00", &macAddr);
   netSetMacAddr(interface, &macAddr);
#else
   //Override the factory preprogrammed address
   macStringToAddr(APP_MAC_ADDR, &macAddr);
   netSetMacAddr(interface, &macAddr);
#endif

   //Select the relevant network adapter
   netSetDriver(interface, &pic32mxEthDriver);
   netSetPhyDriver(interface, &lan8740PhyDriver);

   //Initialize network interface
   error = netConfigInterface(interface);
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to configure interface %s!\r\n", interface->name);
   }

   //Get default settings
   lldpGetDefaultSettings(&lldpAgentSettings);
   //Bind the LLDP agent to the desired interface
   lldpAgentSettings.interface = interface;
   //Number of ports
   lldpAgentSettings.numPorts = LLDP_AGENT_NUM_PORTS;
   //Port table
   lldpAgentSettings.ports = lldpPorts;

   //LLDP agent initialization
   error = lldpInit(&lldpAgentContext, &lldpAgentSettings);
   //Failed to initialize DHCP client?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize LLDP agent!\r\n");
   }

   //Set Chassis ID TLV
   lldpSetLocalChassisId(&lldpAgentContext,
      LLDP_CHASSIS_ID_SUBTYPE_MAC_ADDR, &macAddr, sizeof(MacAddr));

   //Set Port ID TLV
   lldpSetLocalPortId(&lldpAgentContext, 1,
      LLDP_PORT_ID_SUBTYPE_LOCALLY_ASSIGNED, "1", 1);

   //Set Port Description TLV
   lldpSetLocalPortDesc(&lldpAgentContext, 1, "Port description");
   //Set System Name TLV
   lldpSetLocalSysName(&lldpAgentContext, APP_HOST_NAME);
   //Set System Description TLV
   lldpSetLocalSysDesc(&lldpAgentContext, "System description");

   //Set System Capabilities TLV
   lldpSetLocalSysCap(&lldpAgentContext, LLDP_SYS_CAP_STATION_ONLY,
      LLDP_SYS_CAP_STATION_ONLY);

   //Set MAC/PHY Configuration/Status TLV
   lldpDot3SetLocalMacPhyConfigStatus(&lldpAgentContext, 1,
      LLDP_DOT3_AN_FLAG_SUPPORT | LLDP_DOT3_AN_FLAG_STATUS,
      LLDP_DOT3_PMD_AN_ADV_CAP_10BT_HD | LLDP_DOT3_PMD_AN_ADV_CAP_10BT_FD |
      LLDP_DOT3_PMD_AN_ADV_CAP_100BT_HD | LLDP_DOT3_PMD_AN_ADV_CAP_100BT_FD,
      LLDP_DOT3_MAU_TYPE_INVALID);

   //Set LLDP-MED Capabilities TLV
   lldpMedSetLocalCap(&lldpAgentContext, LLDP_MED_CAP | LLDP_MED_CAP_INVENTORY,
      LLDP_MED_DEVICE_TYPE_ENDPOINT_CLASS_1);

   //Set LLDP-MED Hardware Revision TLV
   lldpMedSetLocalHardwareRevision(&lldpAgentContext, "Hardware revision");
   //Set LLDP-MED Firmware Revision TLV
   lldpMedSetLocalFirmwareRevision(&lldpAgentContext, "Firmware revision");
   //Set LLDP-MED Software Revision TLV
   lldpMedSetLocalSoftwareRevision(&lldpAgentContext, "Software revision");
   //Set LLDP-MED Serial Number TLV
   lldpMedSetLocalSerialNumber(&lldpAgentContext, "Serial number");
   //Set LLDP-MED Manufacturer Name TLV
   lldpMedSetLocalManufacturerName(&lldpAgentContext, "Manufacturer name");
   //Set LLDP-MED Model Name TLV
   lldpMedSetLocalModelName(&lldpAgentContext, "Model name");

   //Start LLDP agent
   error = lldpStart(&lldpAgentContext);
   //Failed to start LLDP agent?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start LLDP agent!\r\n");
   }

   //Attach the LLDP agent context to the LLDP-MIB
   lldpMibSetLldpAgentContext(&lldpAgentContext);

#if (IPV4_SUPPORT == ENABLED)
#if (APP_USE_DHCP_CLIENT == ENABLED)
   //Get default settings
   dhcpClientGetDefaultSettings(&dhcpClientSettings);
   //Set the network interface to be configured by DHCP
   dhcpClientSettings.interface = interface;
   //Disable rapid commit option
   dhcpClientSettings.rapidCommit = FALSE;
   //Link state change event
   dhcpClientSettings.linkChangeEvent = dhcpClientLinkChangeCallback;
   //FSM state change event
   dhcpClientSettings.stateChangeEvent = dhcpClientStateChangeCallback;

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
   //Load LLDP-MIB
   snmpAgentLoadMib(&snmpAgentContext, &lldpMibModule);

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
 * @brief Link state change callback
 * @param[in] context Pointer to the DHCP client context
 * @param[in] interface interface Underlying network interface
 * @param[in] linkState Current link state
 **/

void dhcpClientLinkChangeCallback (DhcpClientCtx *context,
   NetInterface *interface, bool_t linkState)
{
   uint_t linkSpeed;
   NicDuplexMode duplexMode;
   LldpDot3MauType operationalMauType;

   //Check whether the link is up or down
   if(linkState)
   {
      //Retrieve link speed and duplex mode
      linkSpeed = netGetLinkSpeed(interface);
      duplexMode = netGetDuplexMode(interface);

      //Check current operation mode
      if(linkSpeed == NIC_LINK_SPEED_10MBPS &&
         duplexMode == NIC_HALF_DUPLEX_MODE)
      {
         //10BASE-T half-duplex
         operationalMauType = LLDP_DOT3_MAU_TYPE_10BT_HD;
      }
      else if(linkSpeed == NIC_LINK_SPEED_10MBPS &&
         duplexMode == NIC_FULL_DUPLEX_MODE)
      {
         //10BASE-T full-duplex
         operationalMauType = LLDP_DOT3_MAU_TYPE_10BT_FD;
      }
      else if(linkSpeed == NIC_LINK_SPEED_100MBPS &&
         duplexMode == NIC_HALF_DUPLEX_MODE)
      {
         //100BASE-TX half-duplex
         operationalMauType = LLDP_DOT3_MAU_TYPE_100BTX_HD;
      }
      else if(linkSpeed == NIC_LINK_SPEED_100MBPS &&
         duplexMode == NIC_FULL_DUPLEX_MODE)
      {
         //100BASE-TX full-duplex
         operationalMauType = LLDP_DOT3_MAU_TYPE_100BTX_FD;
      }
      else
      {
         //Unknown operation mode
         operationalMauType = LLDP_DOT3_MAU_TYPE_INVALID;
      }
   }
   else
   {
      //The link is down
      operationalMauType = LLDP_DOT3_MAU_TYPE_INVALID;
   }

   //Update MAC/PHY Configuration/Status TLV
   lldpDot3SetLocalMacPhyConfigStatus(&lldpAgentContext, 1,
      LLDP_DOT3_AN_FLAG_SUPPORT | LLDP_DOT3_AN_FLAG_STATUS,
      LLDP_DOT3_PMD_AN_ADV_CAP_10BT_HD | LLDP_DOT3_PMD_AN_ADV_CAP_10BT_FD |
      LLDP_DOT3_PMD_AN_ADV_CAP_100BT_HD | LLDP_DOT3_PMD_AN_ADV_CAP_100BT_FD,
      operationalMauType);
}


/**
 * @brief FSM state change callback
 * @param[in] context Pointer to the DHCP client context
 * @param[in] interface interface Underlying network interface
 * @param[in] state New DHCP state
 **/

void dhcpClientStateChangeCallback(DhcpClientContext *context,
   NetInterface *interface, DhcpState state)
{
   error_t error;
   Ipv4Addr ipv4Addr;

   //DHCP process complete?
   if(state == DHCP_STATE_BOUND)
   {
      //Retrieve IPv4 host address
      error = ipv4GetHostAddr(interface, &ipv4Addr);

      //Check status code
      if(!error)
      {
         //Update Management Address TLV
         lldpSetLocalMgmtAddr(&lldpAgentContext, 0,
            LLDP_MGMT_ADDR_SUBTYPE_IPV4, &ipv4Addr, sizeof(Ipv4Addr),
            LLDP_IF_NUM_SUBTYPE_IF_INDEX, 1, NULL, 0);
      }
   }
}
