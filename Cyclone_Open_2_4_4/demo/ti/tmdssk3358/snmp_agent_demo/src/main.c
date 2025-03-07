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
#include "soc_am335x.h"
#include "hw_types.h"
#include "hw_control_am335x.h"
#include "cp15.h"
#include "cache.h"
#include "mmu.h"
#include "interrupt.h"
#include "gpio_v2.h"
#include "dmtimer.h"
#include "watchdog.h"
#include "evmskam335x.h"
#include "core/net.h"
#include "drivers/mac/am335x_eth_driver.h"
#include "drivers/phy/ar8031_driver.h"
#include "dhcp/dhcp_client.h"
#include "ipv6/slaac.h"
#include "snmp/snmp_agent.h"
#include "mibs/mib2_module.h"
#include "mibs/mib2_impl.h"
#include "encoding/oid.h"
#include "private_mib_module.h"
#include "private_mib_impl.h"
#include "debug.h"

//Application configuration
#define APP_IF0_NAME "eth0"
#define APP_IF0_HOST_NAME "snmp-agent-demo-0"
#define APP_IF0_MAC_ADDR "00-00-00-00-00-00"

#define APP_IF0_USE_DHCP_CLIENT ENABLED
#define APP_IF0_IPV4_HOST_ADDR "192.168.0.20"
#define APP_IF0_IPV4_SUBNET_MASK "255.255.255.0"
#define APP_IF0_IPV4_DEFAULT_GATEWAY "192.168.0.254"
#define APP_IF0_IPV4_PRIMARY_DNS "8.8.8.8"
#define APP_IF0_IPV4_SECONDARY_DNS "8.8.4.4"

#define APP_IF0_USE_SLAAC ENABLED
#define APP_IF0_IPV6_LINK_LOCAL_ADDR "fe80::3358"
#define APP_IF0_IPV6_PREFIX "2001:db8::"
#define APP_IF0_IPV6_PREFIX_LENGTH 64
#define APP_IF0_IPV6_GLOBAL_ADDR "2001:db8::3358"
#define APP_IF0_IPV6_ROUTER "fe80::1"
#define APP_IF0_IPV6_PRIMARY_DNS "2001:4860:4860::8888"
#define APP_IF0_IPV6_SECONDARY_DNS "2001:4860:4860::8844"

#define APP_IF1_NAME "eth1"
#define APP_IF1_HOST_NAME "snmp-agent-demo-1"
#define APP_IF1_MAC_ADDR "00-00-00-00-00-00"

#define APP_IF1_USE_DHCP_CLIENT ENABLED
#define APP_IF1_IPV4_HOST_ADDR "192.168.0.21"
#define APP_IF1_IPV4_SUBNET_MASK "255.255.255.0"
#define APP_IF1_IPV4_DEFAULT_GATEWAY "192.168.0.254"
#define APP_IF1_IPV4_PRIMARY_DNS "8.8.8.8"
#define APP_IF1_IPV4_SECONDARY_DNS "8.8.4.4"

#define APP_IF1_USE_SLAAC ENABLED
#define APP_IF1_IPV6_LINK_LOCAL_ADDR "fe80::3359"
#define APP_IF1_IPV6_PREFIX "2001:db8::"
#define APP_IF1_IPV6_PREFIX_LENGTH 64
#define APP_IF1_IPV6_GLOBAL_ADDR "2001:db8::3359"
#define APP_IF1_IPV6_ROUTER "fe80::1"
#define APP_IF1_IPV6_PRIMARY_DNS "2001:4860:4860::8888"
#define APP_IF1_IPV6_SECONDARY_DNS "2001:4860:4860::8844"

//Application configuration
#define APP_SNMP_PRIVATE_ENTERPRISE_NUMBER 8072
#define APP_SNMP_ENTERPRISE_OID "1.3.6.1.4.1.8072.9999.9999"
#define APP_SNMP_TRAP_DEST_IP_ADDR "192.168.0.100"

//DMTimer2 input clock frequency
#define DMTIMER2_INPUT_CLK 24000000
//DMTimer2 tick frequency
#define DMTIMER2_TICK_FREQ 1000
//DMTimer2 reload value
#define DMTIMER2_RELOAD_VALUE (0xFFFFFFFF - (DMTIMER2_INPUT_CLK / DMTIMER2_TICK_FREQ))

//SRAM memory region
#define SRAM_START_ADDR 0x40200000
#define SRAM_NUM_SECTIONS 1
//OCMC memory region
#define OCMC_START_ADDR 0x40300000
#define OCMC_NUM_SECTIONS 1
//Device memory region
#define DEV_START_ADDR 0x44000000
#define DEV_NUM_SECTIONS 960
//DDR memory region
#define DDR_START_ADDR 0x80000000
#define DDR_NUM_SECTIONS 240
//DDR memory region (no cache)
#define DDR_NO_CACHE_START_ADDR 0x8F000000
#define DDR_NO_CACHE_NUM_SECTIONS 16

//Page table
static volatile uint32_t pageTable[4 * 1024] __attribute__((aligned(16 * 1024)));

//Global variables
bool_t ledState = FALSE;
systime_t ledTime = 0;
DhcpState dhcpPrevState = DHCP_STATE_INIT;

DhcpClientSettings dhcpClientSettings;
DhcpClientContext dhcpClientContext[2];
SlaacSettings slaacSettings;
SlaacContext slaacContext[2];
SnmpAgentSettings snmpAgentSettings;
SnmpAgentContext snmpAgentContext;

//Forward declaration of functions
void dhcpClientStateChangeCallback(DhcpClientContext *context,
   NetInterface *interface, DhcpState state);

error_t snmpAgentRandCallback(uint8_t *data, size_t length);


/**
 * @brief MMU configuration
 **/

void mmuInit(void)
{
   //SRAM memory region
   REGION sramRegion =
   {
      MMU_PGTYPE_SECTION,
      SRAM_START_ADDR,
      SRAM_NUM_SECTIONS,
      MMU_MEMTYPE_NORMAL_NON_SHAREABLE(MMU_CACHE_WT_NOWA, MMU_CACHE_WB_WA),
      MMU_REGION_NON_SECURE,
      MMU_AP_PRV_RW_USR_RW,
      (uint32_t *) pageTable
   };

   //OCMC memory region
   REGION ocmcRegion =
   {
      MMU_PGTYPE_SECTION,
      OCMC_START_ADDR,
      OCMC_NUM_SECTIONS,
      MMU_MEMTYPE_NORMAL_NON_SHAREABLE(MMU_CACHE_WT_NOWA, MMU_CACHE_WB_WA),
      MMU_REGION_NON_SECURE,
      MMU_AP_PRV_RW_USR_RW,
      (uint32_t *) pageTable
   };

   //Device memory region
   REGION devRegion =
   {
      MMU_PGTYPE_SECTION,
      DEV_START_ADDR,
      DEV_NUM_SECTIONS,
      MMU_MEMTYPE_DEVICE_SHAREABLE,
      MMU_REGION_NON_SECURE,
      MMU_AP_PRV_RW_USR_RW | MMU_SECTION_EXEC_NEVER,
      (uint32_t *) pageTable
   };

   //DDR memory region
   REGION ddrRegion =
   {
      MMU_PGTYPE_SECTION,
      DDR_START_ADDR,
      DDR_NUM_SECTIONS,
      MMU_MEMTYPE_NORMAL_NON_SHAREABLE(MMU_CACHE_WT_NOWA, MMU_CACHE_WB_WA),
      MMU_REGION_NON_SECURE,
      MMU_AP_PRV_RW_USR_RW,
      (uint32_t *) pageTable
   };

   //DDR memory region (no cache)
   REGION ddrNoCacheRegion =
   {
      MMU_PGTYPE_SECTION,
      DDR_NO_CACHE_START_ADDR,
      DDR_NO_CACHE_NUM_SECTIONS,
      MMU_MEMTYPE_DEVICE_SHAREABLE,
      MMU_REGION_NON_SECURE,
      MMU_AP_PRV_RW_USR_RW | MMU_SECTION_EXEC_NEVER,
      (uint32_t *) pageTable
   };

   //Disable cache
   CacheDisable(CACHE_ALL);
   //Disable MMU
   CP15MMUDisable();

   //Initialize the page table
   MMUInit((uint32_t *) pageTable);

   //Map the defined regions
   MMUMemRegionMap(&sramRegion);
   MMUMemRegionMap(&ocmcRegion);
   MMUMemRegionMap(&devRegion);
   MMUMemRegionMap(&ddrRegion);
   MMUMemRegionMap(&ddrNoCacheRegion);

   //Enable the MMU
   MMUEnable((uint32_t *) pageTable);
   //Enable cache
   CacheEnable(CACHE_ALL);
}


/**
 * @brief I/O initialization
 **/

void ioInit(void)
{
   //Enable clocks for GPIO instances
   GPIO0ModuleClkConfig();
   GPIO1ModuleClkConfig();
   GPIO2ModuleClkConfig();

   //Enable GPIO modules
   GPIOModuleEnable(SOC_GPIO_0_REGS);
   GPIOModuleEnable(SOC_GPIO_1_REGS);
   GPIOModuleEnable(SOC_GPIO_2_REGS);

   //Configure LED1 as a GPIO (GPIO1_4/GPMC_AD4)
   HWREG(SOC_CONTROL_REGS + CONTROL_CONF_GPMC_AD(4)) = CONTROL_CONF_MUXMODE(7);
   //Configure LED2 as a GPIO (GPIO1_5/GPMC_AD5)
   HWREG(SOC_CONTROL_REGS + CONTROL_CONF_GPMC_AD(5)) = CONTROL_CONF_MUXMODE(7);
   //Configure LED3 as a GPIO (GPIO1_7/GPMC_AD7)
   HWREG(SOC_CONTROL_REGS + CONTROL_CONF_GPMC_AD(7)) = CONTROL_CONF_MUXMODE(7);
   //Configure LED4 as a GPIO (GPIO1_6/GPMC_AD6)
   HWREG(SOC_CONTROL_REGS + CONTROL_CONF_GPMC_AD(6)) = CONTROL_CONF_MUXMODE(7);

   //Configure LED1 as an output
   GPIODirModeSet(SOC_GPIO_1_REGS, 4, GPIO_DIR_OUTPUT);
   //Configure LED2 as an output
   GPIODirModeSet(SOC_GPIO_1_REGS, 5, GPIO_DIR_OUTPUT);
   //Configure LED3 as an output
   GPIODirModeSet(SOC_GPIO_1_REGS, 7, GPIO_DIR_OUTPUT);
   //Configure LED4 as an output
   GPIODirModeSet(SOC_GPIO_1_REGS, 6, GPIO_DIR_OUTPUT);

   //Configure SW1 as a GPIO (GPIO2_3/GPMC_OEN_REN)
   HWREG(SOC_CONTROL_REGS + CONTROL_CONF_GPMC_OEN_REN) = CONTROL_CONF_RXACTIVE |
      CONTROL_CONF_MUXMODE(7);
   //Configure SW2 as a GPIO (GPIO2_2/GPMC_ADVN_ALE)
   HWREG(SOC_CONTROL_REGS + CONTROL_CONF_GPMC_ADVN_ALE) = CONTROL_CONF_RXACTIVE |
      CONTROL_CONF_MUXMODE(7);
   //Configure SW3 as a GPIO (GPIO0_30/GPMC_WAIT0)
   HWREG(SOC_CONTROL_REGS + CONTROL_CONF_GPMC_WAIT0) = CONTROL_CONF_RXACTIVE |
      CONTROL_CONF_MUXMODE(7);
   //Configure SW4 as a GPIO (GPIO2_5/GPMC_BE0N_CLE)
   HWREG(SOC_CONTROL_REGS + CONTROL_CONF_GPMC_BE0N_CLE) =  CONTROL_CONF_RXACTIVE |
      CONTROL_CONF_MUXMODE(7);

   //Configure SW1 as an input
   GPIODirModeSet(SOC_GPIO_2_REGS, 3, GPIO_DIR_INPUT);
   //Configure SW2 as an input
   GPIODirModeSet(SOC_GPIO_2_REGS, 2, GPIO_DIR_INPUT);
   //Configure SW3 as an input
   GPIODirModeSet(SOC_GPIO_0_REGS, 30, GPIO_DIR_INPUT);
   //Configure SW4 as an input
   GPIODirModeSet(SOC_GPIO_2_REGS, 5, GPIO_DIR_INPUT);
}


/**
 * @brief DMTimer2 interrupt handler
 **/

void timer2IrqHandler(void)
{
   //Clear interrupt flag
   DMTimerIntStatusClear(SOC_DMTIMER_2_REGS, DMTIMER_INT_OVF_IT_FLAG);
   //Increment tick counter
   systemTicks++;
}


/**
 * @brief DMTimer2 initialization
 **/

void timer2Init(void)
{
   //Enable clocks for DMTimer2 instance
   DMTimer2ModuleClkConfig();

   //Disable timer
   DMTimerDisable(SOC_DMTIMER_2_REGS);
   //Disable prescaler
   DMTimerPreScalerClkDisable(SOC_DMTIMER_2_REGS);

   //Configure DMTimer2 for auto-reload and compare mode
   DMTimerModeConfigure(SOC_DMTIMER_2_REGS, DMTIMER_AUTORLD_CMP_ENABLE);
   //Set reload value
   DMTimerReloadSet(SOC_DMTIMER_2_REGS, DMTIMER2_RELOAD_VALUE);
   //Initialize counter value
   DMTimerCounterSet(SOC_DMTIMER_2_REGS, DMTIMER2_RELOAD_VALUE);

   //Enable DMTimer2 interrupts
   DMTimerIntEnable(SOC_DMTIMER_2_REGS, DMTIMER_INT_OVF_EN_FLAG);

   //Register interrupt handler
   IntRegister(SYS_INT_TINT2, timer2IrqHandler);
   //Configure interrupt priority
   IntPrioritySet(SYS_INT_TINT2, 0, AINTC_HOSTINT_ROUTE_IRQ);
   //Enable system interrupts
   IntSystemEnable(SYS_INT_TINT2);

   //Enable timer
   DMTimerEnable(SOC_DMTIMER_2_REGS);
}


/**
 * @brief LED task
 **/

void ledTask(void)
{
   //Check current time
   if((int32_t)(systemTicks - ledTime) > 0)
   {
      //Toggle LED state
      if(ledState == 0)
      {
         GPIOPinWrite(SOC_GPIO_1_REGS, 6, GPIO_PIN_HIGH);
         ledState = 1;
         ledTime = systemTicks + 100;
      }
      else
      {
         GPIOPinWrite(SOC_GPIO_1_REGS, 6, GPIO_PIN_LOW);
         ledState = 0;
         ledTime = systemTicks + 900;
      }
   }
}


/**
 * @brief Main entry point
 * @return Unused value
 **/

int_t main(void)
{
   error_t error;
   size_t oidLen;
   uint8_t oid[SNMP_MAX_OID_SIZE];
   NetInterface *interface;
   MacAddr macAddr;
#if (APP_IF0_USE_DHCP_CLIENT == DISABLED || APP_IF1_USE_DHCP_CLIENT == DISABLED)
   Ipv4Addr ipv4Addr;
#endif
#if (APP_IF0_USE_SLAAC == DISABLED || APP_IF1_USE_SLAAC == DISABLED)
   Ipv6Addr ipv6Addr;
#endif

   //Configure MMU
   mmuInit();

   //Disable watchdog timer
   WatchdogTimerDisable(SOC_WDT_1_REGS);

   //Initialize interrupt controller
   IntAINTCInit();

   //Initialize kernel
   osInitKernel();
   //Configure debug UART
   debugInit(115200);

   //Start-up message
   TRACE_INFO("\r\n");
   TRACE_INFO("**********************************\r\n");
   TRACE_INFO("*** CycloneTCP SNMP Agent Demo ***\r\n");
   TRACE_INFO("**********************************\r\n");
   TRACE_INFO("Copyright: 2010-2024 Oryx Embedded SARL\r\n");
   TRACE_INFO("Compiled: %s %s\r\n", __DATE__, __TIME__);
   TRACE_INFO("Target: AM335x\r\n");
   TRACE_INFO("\r\n");

   //Configure I/Os
   ioInit();

   //Standard MIB-II initialization
   error = mib2Init();
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize MIB!\r\n");
   }

   //Private MIB initialization
   error = privateMibInit();
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize MIB!\r\n");
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
   netSetInterfaceName(interface, APP_IF0_NAME);
   //Set host name
   netSetHostname(interface, APP_IF0_HOST_NAME);
   //Set host MAC address
   macStringToAddr(APP_IF0_MAC_ADDR, &macAddr);
   netSetMacAddr(interface, &macAddr);
   //Select the relevant MAC driver
   netSetDriver(interface, &am335xEthPort1Driver);
   //Select the relevant PHY driver
   netSetPhyDriver(interface, &ar8031PhyDriver);
   //Set PHY address
   netSetPhyAddr(interface, 0);

   //Initialize network interface
   error = netConfigInterface(interface);
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to configure interface %s!\r\n", interface->name);
   }

#if (IPV4_SUPPORT == ENABLED)
#if (APP_IF0_USE_DHCP_CLIENT == ENABLED)
   //Get default settings
   dhcpClientGetDefaultSettings(&dhcpClientSettings);
   //Set the network interface to be configured by DHCP
   dhcpClientSettings.interface = interface;
   //Disable rapid commit option
   dhcpClientSettings.rapidCommit = FALSE;
   //FSM state change event
   dhcpClientSettings.stateChangeEvent = dhcpClientStateChangeCallback;

   //DHCP client initialization
   error = dhcpClientInit(&dhcpClientContext[0], &dhcpClientSettings);
   //Failed to initialize DHCP client?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize DHCP client!\r\n");
   }

   //Start DHCP client
   error = dhcpClientStart(&dhcpClientContext[0]);
   //Failed to start DHCP client?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start DHCP client!\r\n");
   }
#else
   //Set IPv4 host address
   ipv4StringToAddr(APP_IF0_IPV4_HOST_ADDR, &ipv4Addr);
   ipv4SetHostAddr(interface, ipv4Addr);

   //Set subnet mask
   ipv4StringToAddr(APP_IF0_IPV4_SUBNET_MASK, &ipv4Addr);
   ipv4SetSubnetMask(interface, ipv4Addr);

   //Set default gateway
   ipv4StringToAddr(APP_IF0_IPV4_DEFAULT_GATEWAY, &ipv4Addr);
   ipv4SetDefaultGateway(interface, ipv4Addr);

   //Set primary and secondary DNS servers
   ipv4StringToAddr(APP_IF0_IPV4_PRIMARY_DNS, &ipv4Addr);
   ipv4SetDnsServer(interface, 0, ipv4Addr);
   ipv4StringToAddr(APP_IF0_IPV4_SECONDARY_DNS, &ipv4Addr);
   ipv4SetDnsServer(interface, 1, ipv4Addr);
#endif
#endif

#if (IPV6_SUPPORT == ENABLED)
#if (APP_IF0_USE_SLAAC == ENABLED)
   //Get default settings
   slaacGetDefaultSettings(&slaacSettings);
   //Set the network interface to be configured
   slaacSettings.interface = interface;

   //SLAAC initialization
   error = slaacInit(&slaacContext[0], &slaacSettings);
   //Failed to initialize SLAAC?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize SLAAC!\r\n");
   }

   //Start IPv6 address autoconfiguration process
   error = slaacStart(&slaacContext[0]);
   //Failed to start SLAAC process?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start SLAAC!\r\n");
   }
#else
   //Set link-local address
   ipv6StringToAddr(APP_IF0_IPV6_LINK_LOCAL_ADDR, &ipv6Addr);
   ipv6SetLinkLocalAddr(interface, &ipv6Addr);

   //Set IPv6 prefix
   ipv6StringToAddr(APP_IF0_IPV6_PREFIX, &ipv6Addr);
   ipv6SetPrefix(interface, 0, &ipv6Addr, APP_IF0_IPV6_PREFIX_LENGTH);

   //Set global address
   ipv6StringToAddr(APP_IF0_IPV6_GLOBAL_ADDR, &ipv6Addr);
   ipv6SetGlobalAddr(interface, 0, &ipv6Addr);

   //Set default router
   ipv6StringToAddr(APP_IF0_IPV6_ROUTER, &ipv6Addr);
   ipv6SetDefaultRouter(interface, 0, &ipv6Addr);

   //Set primary and secondary DNS servers
   ipv6StringToAddr(APP_IF0_IPV6_PRIMARY_DNS, &ipv6Addr);
   ipv6SetDnsServer(interface, 0, &ipv6Addr);
   ipv6StringToAddr(APP_IF0_IPV6_SECONDARY_DNS, &ipv6Addr);
   ipv6SetDnsServer(interface, 1, &ipv6Addr);
#endif
#endif

   //Configure the second Ethernet interface
   interface = &netInterface[1];

   //Set interface name
   netSetInterfaceName(interface, APP_IF1_NAME);
   //Set host name
   netSetHostname(interface, APP_IF1_HOST_NAME);
   //Set host MAC address
   macStringToAddr(APP_IF1_MAC_ADDR, &macAddr);
   netSetMacAddr(interface, &macAddr);
   //Select the relevant MAC driver
   netSetDriver(interface, &am335xEthPort2Driver);
   //Select the relevant PHY driver
   netSetPhyDriver(interface, &ar8031PhyDriver);
   //Set PHY address
   netSetPhyAddr(interface, 1);

   //Initialize network interface
   error = netConfigInterface(interface);
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to configure interface %s!\r\n", interface->name);
   }

#if (IPV4_SUPPORT == ENABLED)
#if (APP_IF1_USE_DHCP_CLIENT == ENABLED)
   //Get default settings
   dhcpClientGetDefaultSettings(&dhcpClientSettings);
   //Set the network interface to be configured by DHCP
   dhcpClientSettings.interface = interface;
   //Disable rapid commit option
   dhcpClientSettings.rapidCommit = FALSE;
   //FSM state change event
   dhcpClientSettings.stateChangeEvent = dhcpClientStateChangeCallback;

   //DHCP client initialization
   error = dhcpClientInit(&dhcpClientContext[1], &dhcpClientSettings);
   //Failed to initialize DHCP client?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize DHCP client!\r\n");
   }

   //Start DHCP client
   error = dhcpClientStart(&dhcpClientContext[1]);
   //Failed to start DHCP client?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start DHCP client!\r\n");
   }
#else
   //Set IPv4 host address
   ipv4StringToAddr(APP_IF1_IPV4_HOST_ADDR, &ipv4Addr);
   ipv4SetHostAddr(interface, ipv4Addr);

   //Set subnet mask
   ipv4StringToAddr(APP_IF1_IPV4_SUBNET_MASK, &ipv4Addr);
   ipv4SetSubnetMask(interface, ipv4Addr);

   //Set default gateway
   ipv4StringToAddr(APP_IF1_IPV4_DEFAULT_GATEWAY, &ipv4Addr);
   ipv4SetDefaultGateway(interface, ipv4Addr);

   //Set primary and secondary DNS servers
   ipv4StringToAddr(APP_IF1_IPV4_PRIMARY_DNS, &ipv4Addr);
   ipv4SetDnsServer(interface, 0, ipv4Addr);
   ipv4StringToAddr(APP_IF1_IPV4_SECONDARY_DNS, &ipv4Addr);
   ipv4SetDnsServer(interface, 1, ipv4Addr);
#endif
#endif

#if (IPV6_SUPPORT == ENABLED)
#if (APP_IF1_USE_SLAAC == ENABLED)
   //Get default settings
   slaacGetDefaultSettings(&slaacSettings);
   //Set the network interface to be configured
   slaacSettings.interface = interface;

   //SLAAC initialization
   error = slaacInit(&slaacContext[1], &slaacSettings);
   //Failed to initialize SLAAC?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize SLAAC!\r\n");
   }

   //Start IPv6 address autoconfiguration process
   error = slaacStart(&slaacContext[1]);
   //Failed to start SLAAC process?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start SLAAC!\r\n");
   }
#else
   //Set link-local address
   ipv6StringToAddr(APP_IF1_IPV6_LINK_LOCAL_ADDR, &ipv6Addr);
   ipv6SetLinkLocalAddr(interface, &ipv6Addr);

   //Set IPv6 prefix
   ipv6StringToAddr(APP_IF1_IPV6_PREFIX, &ipv6Addr);
   ipv6SetPrefix(interface, 0, &ipv6Addr, APP_IF1_IPV6_PREFIX_LENGTH);

   //Set global address
   ipv6StringToAddr(APP_IF1_IPV6_GLOBAL_ADDR, &ipv6Addr);
   ipv6SetGlobalAddr(interface, 0, &ipv6Addr);

   //Set default router
   ipv6StringToAddr(APP_IF1_IPV6_ROUTER, &ipv6Addr);
   ipv6SetDefaultRouter(interface, 0, &ipv6Addr);

   //Set primary and secondary DNS servers
   ipv6StringToAddr(APP_IF1_IPV6_PRIMARY_DNS, &ipv6Addr);
   ipv6SetDnsServer(interface, 0, &ipv6Addr);
   ipv6StringToAddr(APP_IF1_IPV6_SECONDARY_DNS, &ipv6Addr);
   ipv6SetDnsServer(interface, 1, &ipv6Addr);
#endif
#endif

   //Get default settings
   snmpAgentGetDefaultSettings(&snmpAgentSettings);
   //Bind SNMP agent to both network interfaces
   snmpAgentSettings.interface = NULL;
   //Minimum version accepted by the SNMP agent
   snmpAgentSettings.versionMin = SNMP_VERSION_1;
   //Maximum version accepted by the SNMP agent
   snmpAgentSettings.versionMax = SNMP_VERSION_2C;

#if (SNMP_V3_SUPPORT == ENABLED)
   //Maximum version accepted by the SNMP agent
   snmpAgentSettings.versionMax = SNMP_VERSION_3;
   //Random data generation callback function
   snmpAgentSettings.randCallback = snmpAgentRandCallback;
#endif

   //SNMP agent initialization
   error = snmpAgentInit(&snmpAgentContext, &snmpAgentSettings);
   //Failed to initialize SNMP agent?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize SNMP agent!\r\n");
   }

   //Load standard MIB-II
   snmpAgentLoadMib(&snmpAgentContext, &mib2Module);
   //Load private MIB
   snmpAgentLoadMib(&snmpAgentContext, &privateMibModule);

   //Convert enterprise OID from string representation
   oidFromString(APP_SNMP_ENTERPRISE_OID, oid, sizeof(oid), &oidLen);
   //Set enterprise OID
   snmpAgentSetEnterpriseOid(&snmpAgentContext, oid, oidLen);

   //Set read-only community string
   snmpAgentCreateCommunity(&snmpAgentContext, "public",
      SNMP_ACCESS_READ_ONLY);

   //Set read-write community string
   snmpAgentCreateCommunity(&snmpAgentContext, "private",
      SNMP_ACCESS_READ_WRITE);

#if (SNMP_V3_SUPPORT == ENABLED)
   //The first part of the context engine ID is the enterprise number
   contextEngine[0] = 0x80 | ((APP_SNMP_PRIVATE_ENTERPRISE_NUMBER >> 24) & 0x7F);
   contextEngine[1] = (APP_SNMP_PRIVATE_ENTERPRISE_NUMBER >> 16) & 0xFF;
   contextEngine[2] = (APP_SNMP_PRIVATE_ENTERPRISE_NUMBER >> 8) & 0xFF;
   contextEngine[3] = APP_SNMP_PRIVATE_ENTERPRISE_NUMBER & 0xFF;

   //The format value 3 indicates a MAC address
   contextEngine[4] = 0x03;
   //Append MAC address
   macCopyAddr(contextEngine + 5, &macAddr);

   //Set context engine ID
   snmpAgentSetContextEngine(&snmpAgentContext, contextEngine,
      sizeof(contextEngine));

   //Add a new user
   snmpAgentCreateUser(&snmpAgentContext, "usr-md5-none",
      SNMP_ACCESS_READ_WRITE, SNMP_KEY_FORMAT_TEXT,
      SNMP_AUTH_PROTOCOL_MD5, "authkey1",
      SNMP_PRIV_PROTOCOL_NONE, "");

   //Add a new user
   snmpAgentCreateUser(&snmpAgentContext, "usr-md5-des",
      SNMP_ACCESS_READ_WRITE, SNMP_KEY_FORMAT_TEXT,
      SNMP_AUTH_PROTOCOL_MD5, "authkey1",
      SNMP_PRIV_PROTOCOL_DES, "privkey1");
#endif

   //Start SNMP agent
   error = snmpAgentStart(&snmpAgentContext);
   //Failed to start SNMP agent?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start SNMP agent!\r\n");
   }

   //Initialize DMTimer2
   timer2Init();

   //Enable processor IRQ
   IntMasterIRQEnable();

   //Endless loop
   while(1)
   {
      //Handle TCP/IP events
      netTask();
      //Handle SNMP agent events
      snmpAgentTask(&snmpAgentContext);
      //LED blinking task
      ledTask();
   }
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
   IpAddr destIpAddr;
   SnmpTrapObject trapObjects[2];

   //DHCP process complete?
   if(state == DHCP_STATE_BOUND && dhcpPrevState == DHCP_STATE_ANNOUNCING)
   {
      //Destination IP address
      ipStringToAddr(APP_SNMP_TRAP_DEST_IP_ADDR, &destIpAddr);

      //First Ethernet interface?
      if(context == &dhcpClientContext[0])
      {
         //Add the ifDescr.1 object to the variable binding list of the message
         oidFromString("1.3.6.1.2.1.2.2.1.2.1", trapObjects[0].oid,
            SNMP_MAX_OID_SIZE, &trapObjects[0].oidLen);

         //Add the ifPhysAddress.1 object to the variable binding list of the message
         oidFromString("1.3.6.1.2.1.2.2.1.6.1", trapObjects[1].oid,
            SNMP_MAX_OID_SIZE, &trapObjects[1].oidLen);
      }
      //Second Ethernet interface?
      else if(context == &dhcpClientContext[1])
      {
         //Add the ifDescr.2 object to the variable binding list of the message
         oidFromString("1.3.6.1.2.1.2.2.1.2.2", trapObjects[0].oid,
            SNMP_MAX_OID_SIZE, &trapObjects[0].oidLen);

         //Add the ifPhysAddress.2 object to the variable binding list of the message
         oidFromString("1.3.6.1.2.1.2.2.1.6.2", trapObjects[1].oid,
            SNMP_MAX_OID_SIZE, &trapObjects[1].oidLen);
      }

      //Send a SNMP trap
      error = snmpAgentSendTrap(&snmpAgentContext, &destIpAddr, SNMP_VERSION_2C,
         "public", SNMP_TRAP_LINK_UP, 0, trapObjects, 2);

      //Failed to send trap message?
      if(error)
      {
         //Debug message
         TRACE_ERROR("Failed to send SNMP trap message!\r\n");
      }
   }

   //Save current state
   dhcpPrevState = state;
}


/**
 * @brief Random data generation callback function
 * @param[out] data Buffer where to store the random data
 * @param[in] length Number of bytes that are required
 * @return Error code
 **/

error_t snmpAgentRandCallback(uint8_t *data, size_t length)
{
   size_t i;

   //Generate some random data
   for(i = 0; i < length; i++)
      data[i] = rand();

   //No error to report
   return NO_ERROR;
}
