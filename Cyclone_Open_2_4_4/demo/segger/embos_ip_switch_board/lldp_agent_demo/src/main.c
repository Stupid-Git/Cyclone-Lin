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
#include "fsl_device_registers.h"
#include "fsl_cache.h"
#include "fsl_clock.h"
#include "fsl_gpio.h"
#include "fsl_port.h"
#include "fsl_smc.h"
#include "embos_ip_switch_board.h"
#include "core/net.h"
#include "drivers/mac/mk6x_eth_driver.h"
#include "drivers/switch/ksz8794_driver.h"
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
#include "spi_driver.h"
#include "debug.h"

//Ethernet interface configuration
#define APP_IF_NAME "eth0"
#define APP_HOST_NAME "lldp-agent-demo"
#define APP_MAC_ADDR "00-AB-CD-66-18-00"

#define APP_USE_DHCP_CLIENT ENABLED
#define APP_IPV4_HOST_ADDR "192.168.0.20"
#define APP_IPV4_SUBNET_MASK "255.255.255.0"
#define APP_IPV4_DEFAULT_GATEWAY "192.168.0.254"
#define APP_IPV4_PRIMARY_DNS "8.8.8.8"
#define APP_IPV4_SECONDARY_DNS "8.8.4.4"

#define APP_USE_SLAAC ENABLED
#define APP_IPV6_LINK_LOCAL_ADDR "fe80::6618"
#define APP_IPV6_PREFIX "2001:db8::"
#define APP_IPV6_PREFIX_LENGTH 64
#define APP_IPV6_GLOBAL_ADDR "2001:db8::6618"
#define APP_IPV6_ROUTER "fe80::1"
#define APP_IPV6_PRIMARY_DNS "2001:4860:4860::8888"
#define APP_IPV6_SECONDARY_DNS "2001:4860:4860::8844"

//Application configuration
#define LLDP_AGENT_NUM_PORTS 3
#define LLDP_AGENT_NUM_NEIGHBORS 6

//Global variables
LldpAgentSettings lldpAgentSettings;
LldpAgentContext lldpAgentContext;
LldpPortEntry lldpPorts[LLDP_AGENT_NUM_PORTS];
LldpNeighborEntry lldpNeighbors[LLDP_AGENT_NUM_NEIGHBORS];
DhcpClientSettings dhcpClientSettings;
DhcpClientContext dhcpClientContext;
SlaacSettings slaacSettings;
SlaacContext slaacContext;
SnmpAgentSettings snmpAgentSettings;
SnmpAgentContext snmpAgentContext;

//Forward declaration of functions
void dhcpClientStateChangeCallback(DhcpClientContext *context,
   NetInterface *interface, DhcpState state);


/**
 * @brief System clock initialization
 **/

void systemClockInit(void)
{
   osc_config_t oscConfig;
   mcg_config_t mcgConfig;
   sim_clock_config_t simConfig;

   //Set HSRUN power mode
   SMC_SetPowerModeProtection(SMC, kSMC_AllowPowerModeAll);
   SMC_SetPowerModeHsrun(SMC);

   while (SMC_GetPowerModeState(SMC) != kSMC_PowerStateHsrun)
   {
   }

   //Set the system clock dividers in SIM to safe value
   CLOCK_SetSimSafeDivs();

   //Initialize OSC0
   oscConfig.freq = 12000000;
   oscConfig.capLoad = 0;
   oscConfig.workMode = kOSC_ModeOscLowPower;
   oscConfig.oscerConfig.enableMode = kOSC_ErClkEnable;
   oscConfig.oscerConfig.erclkDiv = 0;

   CLOCK_InitOsc0(&oscConfig);
   CLOCK_SetXtal0Freq(oscConfig.freq);

   //Configure internal reference clock
   mcgConfig.mcgMode = kMCG_ModePEE;
   mcgConfig.irclkEnableMode = kMCG_IrclkEnable;
   mcgConfig.ircs = kMCG_IrcSlow;
   mcgConfig.fcrdiv = 1;
   mcgConfig.frdiv = 0;
   mcgConfig.drs = kMCG_DrsLow;
   mcgConfig.dmx32 = kMCG_Dmx32Default;
   mcgConfig.oscsel = kMCG_OscselOsc;
   mcgConfig.pll0Config.enableMode = 0;
   mcgConfig.pll0Config.prdiv = 0;
   mcgConfig.pll0Config.vdiv = 15;
   mcgConfig.pllcs = kMCG_PllClkSelPll0;

   CLOCK_SetInternalRefClkConfig(mcgConfig.irclkEnableMode, mcgConfig.ircs,
      mcgConfig.fcrdiv);

   CLOCK_BootToPeeMode(mcgConfig.oscsel, mcgConfig.pllcs,
      &mcgConfig.pll0Config);

   //Set clock configuration of SIM module
   simConfig.pllFllSel = 3;
   simConfig.pllFllDiv = 0;
   simConfig.pllFllFrac = 0;
   simConfig.er32kSrc = 2;
   simConfig.clkdiv1 = 0x2260000;

   CLOCK_SetSimConfig(&simConfig);

   //Set system core clock value
   SystemCoreClock = 180000000;

   //Configure peripheral clocks
   CLOCK_SetRtcClkOutClock(0);
   CLOCK_EnableUsbfs0Clock(kCLOCK_UsbSrcIrc48M, 48000000);
   CLOCK_SetEnetTime0Clock(0);
   CLOCK_SetRmii0Clock(1);
   CLOCK_SetSdhc0Clock(2);
   CLOCK_SetLpuartClock(2);
   CLOCK_SetTpmClock(1);
   CLOCK_SetClkOutClock(0);
   CLOCK_SetTraceClock(0, 1, 0);
}


/**
 * @brief I/O initialization
 **/

void ioInit(void)
{
   port_pin_config_t portPinConfig;
   gpio_pin_config_t gpioPinConfig;

   //Enable PORTA peripheral clock
   CLOCK_EnableClock(kCLOCK_PortA);

   //Set port pin configuration
   portPinConfig.pullSelect = kPORT_PullDisable;
   portPinConfig.slewRate = kPORT_FastSlewRate;
   portPinConfig.passiveFilterEnable = kPORT_PassiveFilterDisable;
   portPinConfig.openDrainEnable = kPORT_OpenDrainDisable;
   portPinConfig.driveStrength = kPORT_HighDriveStrength;
   portPinConfig.mux = kPORT_MuxAsGpio;
   portPinConfig.lockRegister = kPORT_UnlockRegister;

   //Set GPIO pin configuration
   gpioPinConfig.pinDirection = kGPIO_DigitalOutput;
   gpioPinConfig.outputLogic = 1;

   //Configure LED0
   PORT_SetPinConfig(LED0_PORT, LED0_PIN, &portPinConfig);
   GPIO_PinInit(LED0_GPIO, LED0_PIN, &gpioPinConfig);

   //Configure LED1
   PORT_SetPinConfig(LED1_PORT, LED1_PIN, &portPinConfig);
   GPIO_PinInit(LED1_GPIO, LED1_PIN, &gpioPinConfig);

   //Configure LED2
   PORT_SetPinConfig(LED2_PORT, LED2_PIN, &portPinConfig);
   GPIO_PinInit(LED2_GPIO, LED2_PIN, &gpioPinConfig);

   //Configure LED3
   PORT_SetPinConfig(LED3_PORT, LED3_PIN, &portPinConfig);
   GPIO_PinInit(LED3_GPIO, LED3_PIN, &gpioPinConfig);
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
      GPIO_PinWrite(LED1_GPIO, LED1_PIN, 0);
      osDelayTask(100);
      GPIO_PinWrite(LED1_GPIO, LED1_PIN, 1);
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
   char_t buffer[32];

   //Initialize system core clock
   systemClockInit();
   //Enable code cache
   L1CACHE_EnableCodeCache();

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
   TRACE_INFO("Target: MK66F18\r\n");
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
   //Set host MAC address
   macStringToAddr(APP_MAC_ADDR, &macAddr);
   netSetMacAddr(interface, &macAddr);
   //Select the relevant MAC driver
   netSetDriver(interface, &mk6xEthDriver);
   //Select the relevant switch driver
   netSetSwitchDriver(interface, &ksz8794SwitchDriver);
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
   lldpGetDefaultSettings(&lldpAgentSettings);
   //Bind the LLDP agent to the desired interface
   lldpAgentSettings.interface = interface;
   //Number of ports
   lldpAgentSettings.numPorts = LLDP_AGENT_NUM_PORTS;
   //Port table
   lldpAgentSettings.ports = lldpPorts;
   //Maximum number of neighbors
   lldpAgentSettings.numNeighbors = LLDP_AGENT_NUM_NEIGHBORS;
   //Neighbor table
   lldpAgentSettings.neighbors = lldpNeighbors;

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

   //Configure ports
   for(i = 1; i <= LLDP_AGENT_NUM_PORTS; i++)
   {
      //Format port identifier
      osSprintf(buffer, "%u", i);

      //Set Port ID TLV
      lldpSetLocalPortId(&lldpAgentContext, i,
         LLDP_PORT_ID_SUBTYPE_LOCALLY_ASSIGNED, buffer, osStrlen(buffer));

      //Format port description
      osSprintf(buffer, "Port %u description", i);

      //Set Port Description TLV
      lldpSetLocalPortDesc(&lldpAgentContext, i, buffer);
   }

   //Set System Name TLV
   lldpSetLocalSysName(&lldpAgentContext, APP_HOST_NAME);
   //Set System Description TLV
   lldpSetLocalSysDesc(&lldpAgentContext, "System description");

   //Set System Capabilities TLV
   lldpSetLocalSysCap(&lldpAgentContext, LLDP_SYS_CAP_STATION_ONLY,
      LLDP_SYS_CAP_STATION_ONLY);

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
