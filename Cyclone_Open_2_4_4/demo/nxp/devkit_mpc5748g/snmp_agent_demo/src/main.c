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
#include "mpc5748g.h"
#include "system_mpc5748g.h"
#include "devkit_mpc5748g.h"
#include "core/net.h"
#include "drivers/mac/mpc5748_eth1_driver.h"
#include "drivers/phy/ksz8081_driver.h"
#include "dhcp/dhcp_client.h"
#include "ipv6/slaac.h"
#include "snmp/snmp_agent.h"
#include "mibs/mib2_module.h"
#include "mibs/mib2_impl.h"
#include "encoding/oid.h"
#include "private_mib_module.h"
#include "private_mib_impl.h"
#include "debug.h"

//Ethernet interface configuration
#define APP_IF_NAME "eth0"
#define APP_HOST_NAME "snmp-agent-demo"
#define APP_MAC_ADDR "00-AB-CD-EF-57-48"

#define APP_USE_DHCP_CLIENT ENABLED
#define APP_IPV4_HOST_ADDR "192.168.0.20"
#define APP_IPV4_SUBNET_MASK "255.255.255.0"
#define APP_IPV4_DEFAULT_GATEWAY "192.168.0.254"
#define APP_IPV4_PRIMARY_DNS "8.8.8.8"
#define APP_IPV4_SECONDARY_DNS "8.8.4.4"

#define APP_USE_SLAAC ENABLED
#define APP_IPV6_LINK_LOCAL_ADDR "fe80::5748"
#define APP_IPV6_PREFIX "2001:db8::"
#define APP_IPV6_PREFIX_LENGTH 64
#define APP_IPV6_GLOBAL_ADDR "2001:db8::5748"
#define APP_IPV6_ROUTER "fe80::1"
#define APP_IPV6_PRIMARY_DNS "2001:4860:4860::8888"
#define APP_IPV6_SECONDARY_DNS "2001:4860:4860::8844"

//Application configuration
#define APP_SNMP_PRIVATE_ENTERPRISE_NUMBER 8072
#define APP_SNMP_ENTERPRISE_OID "1.3.6.1.4.1.8072.9999.9999"
#define APP_SNMP_TRAP_DEST_IP_ADDR "192.168.0.100"

//Global variables
bool_t ledState = FALSE;
systime_t ledTime = 0;
DhcpState dhcpPrevState = DHCP_STATE_INIT;

DhcpClientSettings dhcpClientSettings;
DhcpClientContext dhcpClientContext;
SlaacSettings slaacSettings;
SlaacContext slaacContext;
SnmpAgentSettings snmpAgentSettings;
SnmpAgentContext snmpAgentContext;

//Forward declaration of functions
void dhcpClientStateChangeCallback(DhcpClientContext *context,
   NetInterface *interface, DhcpState state);

error_t snmpAgentRandCallback(uint8_t *data, size_t length);


/**
 * @brief System initialization
 **/

void systemInit(void)
{
   uint32_t __attribute__((unused)) temp;
   extern const uint32_t __isr_vector[];

   //Set S160 clock divider
   MC_CGM->SC_DC0 = MC_CGM_SC_DC0_DE_MASK | MC_CGM_SC_DC0_DIV(0);
   //Set S80 clock divider
   MC_CGM->SC_DC1 = MC_CGM_SC_DC1_DE_MASK | MC_CGM_SC_DC1_DIV(1);
   //Set S40 clock divider
   MC_CGM->SC_DC2 = MC_CGM_SC_DC2_DE_MASK | MC_CGM_SC_DC2_DIV(3);
   //Set FS80 clock divider
   MC_CGM->SC_DC5 = MC_CGM_SC_DC5_DE_MASK | MC_CGM_SC_DC5_DIV(1);

   //Enable all modes
   MC_ME->ME |= MC_ME_ME_STANDBY0_MASK | MC_ME_ME_STOP0_MASK |
      MC_ME_ME_RUN3_MASK | MC_ME_ME_RUN2_MASK | MC_ME_ME_RUN1_MASK;

   //Set run modes
   MC_ME->RUN_PC[0] = MC_ME_RUN_PC_RUN3_MASK | MC_ME_RUN_PC_RUN2_MASK |
      MC_ME_RUN_PC_RUN1_MASK | MC_ME_RUN_PC_RUN0_MASK |
      MC_ME_RUN_PC_DRUN_MASK | MC_ME_RUN_PC_SAFE_MASK;

   //Connect FXOSC as source clock
   MC_CGM->AC5_SC = MC_CGM_AC5_SC_SELCTL_MASK;

   //Configure PLL divide register
   PLLDIG->PLLDV = PLLDIG_PLLDV_RFDPHI1(6) | PLLDIG_PLLDV_RFDPHI(1) |
      PLLDIG_PLLDV_PREDIV(2) | PLLDIG_PLLDV_MFD(32);

   //Set PLL calibration register
   PLLDIG->PLLCAL3 = PLLDIG_PLLCAL3_MFDEN(9999);

   //Enable sigma delta modulation
   PLLDIG->PLLFD |= PLLDIG_PLLFD_SMDEN_MASK;

   //Configures system behavior during DRUN mode
   MC_ME->DRUN_MC = MC_ME_DRUN_MC_MVRON_MASK | MC_ME_DRUN_MC_FLAON(3) |
      MC_ME_DRUN_MC_SXOSCON_MASK | MC_ME_DRUN_MC_PLLON_MASK |
      MC_ME_DRUN_MC_FXOSCON_MASK | MC_ME_DRUN_MC_SYSCLK(2);

   //Switch to DRUN mode
   MC_ME->MCTL = MC_ME_MCTL_TARGET_MODE(3) | MC_ME_MCTL_KEY(0x5AF0);
   MC_ME->MCTL = MC_ME_MCTL_TARGET_MODE(3) | MC_ME_MCTL_KEY(0xA50F);

   //Wait for the mode transition to complete
   while((MC_ME->GS & MC_ME_GS_S_MTRANS_MASK) != 0)
   {
   }

   //Initialize Core IVPR
   MTSPR(63, (uint32_t) &VTABLE);

   //Select software vector mode
   INTC->BCR  &= ~INTC_BCR_HVEN0_MASK;

   //Read INTC_IACKR0 register
   temp = INTC->IACKR0;

   //Set ISR vector table base address
   INTC->IACKR0 = (uint32_t) __isr_vector;

   //Set ISR priority to the lowest priority
   INTC->CPR0 = INTC_CPR0_PRI(0);
}


/**
 * @brief I/O initialization
 **/

void ioInit(void)
{
   //Configure LEDs
   SIUL2->MSCR[USR_LED1] = SIUL2_MSCR_OBE_MASK | SIUL2_MSCR_SMC_MASK;
   SIUL2->MSCR[USR_LED2] = SIUL2_MSCR_OBE_MASK | SIUL2_MSCR_SMC_MASK;
   SIUL2->MSCR[USR_LED3] = SIUL2_MSCR_OBE_MASK | SIUL2_MSCR_SMC_MASK;
   SIUL2->MSCR[USR_LED4] = SIUL2_MSCR_OBE_MASK | SIUL2_MSCR_SMC_MASK;
   SIUL2->MSCR[USR_LED5] = SIUL2_MSCR_OBE_MASK | SIUL2_MSCR_SMC_MASK;
   SIUL2->MSCR[USR_LED6] = SIUL2_MSCR_OBE_MASK | SIUL2_MSCR_SMC_MASK;
   SIUL2->MSCR[USR_LED7] = SIUL2_MSCR_OBE_MASK | SIUL2_MSCR_SMC_MASK;
   SIUL2->MSCR[USR_LED8] = SIUL2_MSCR_OBE_MASK | SIUL2_MSCR_SMC_MASK;

   //Clear LEDs
   SIUL2->GPDO[USR_LED1] = 1;
   SIUL2->GPDO[USR_LED2] = 1;
   SIUL2->GPDO[USR_LED3] = 1;
   SIUL2->GPDO[USR_LED4] = 1;
   SIUL2->GPDO[USR_LED5] = 1;
   SIUL2->GPDO[USR_LED6] = 1;
   SIUL2->GPDO[USR_LED7] = 1;
   SIUL2->GPDO[USR_LED8] = 1;

   //Configure push buttons
   SIUL2->MSCR[PB_SW1] = SIUL2_MSCR_SMC_MASK | SIUL2_MSCR_IBE_MASK;
   SIUL2->MSCR[PB_SW2] = SIUL2_MSCR_SMC_MASK | SIUL2_MSCR_IBE_MASK;
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
         SIUL2->GPDO[USR_LED1] = 0;
         ledState = 1;
         ledTime = systemTicks + 100;
      }
      else
      {
         SIUL2->GPDO[USR_LED1] = 1;
         ledState = 0;
         ledTime = systemTicks + 900;
      }
   }
}


/**
 * @brief Timer initialization
 **/

void timerInit(void)
{
   //Enable PIT timer module
   PIT->MCR &= ~PIT_MCR_MDIS_MASK;
   //Freeze timer in debug mode
   PIT->MCR |= PIT_MCR_FRZ_MASK;

   //Set period register
   PIT->TIMER[0].LDVAL = (SystemCoreClock / 4) / 1000;

   //Set interrupt priority
   INTC->PSR[PIT_Ch0_IRQn] = INTC_PSR_PRC_SELN0_MASK | INTC_PSR_PRIN(15);

   //Enable timer interrupts
   PIT->TIMER[0].TCTRL |= PIT_TCTRL_TIE_MASK;
   //Start timer
   PIT->TIMER[0].TCTRL |= PIT_TCTRL_TEN_MASK;
}


/**
 * @brief Timer interrupt service routine
 **/

void PIT_Ch0_IRQHandler(void)
{
   //Clear interrupt flag
   PIT->TIMER[0].TFLG = PIT_TFLG_TIF_MASK;
   //Increment tick counter
   systemTicks++;
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
#if (APP_USE_DHCP_CLIENT == DISABLED)
   Ipv4Addr ipv4Addr;
#endif
#if (APP_USE_SLAAC == DISABLED)
   Ipv6Addr ipv6Addr;
#endif
#if (SNMP_V3_SUPPORT == ENABLED)
   uint8_t contextEngine[11];
#endif

   //System initialization
   systemInit();
   //Update system core clock
   SystemCoreClockUpdate();

   //Initialize kernel
   osInitKernel();
   //Configure debug UART
   debugInit(19200);

   //Start-up message
   TRACE_INFO("\r\n");
   TRACE_INFO("**********************************\r\n");
   TRACE_INFO("*** CycloneTCP SNMP Agent Demo ***\r\n");
   TRACE_INFO("**********************************\r\n");
   TRACE_INFO("Copyright: 2010-2024 Oryx Embedded SARL\r\n");
   TRACE_INFO("Compiled: %s %s\r\n", __DATE__, __TIME__);
   TRACE_INFO("Target: MPC5748G\r\n");
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
   netSetInterfaceName(interface, APP_IF_NAME);
   //Set host name
   netSetHostname(interface, APP_HOST_NAME);
   //Set host MAC address
   macStringToAddr(APP_MAC_ADDR, &macAddr);
   netSetMacAddr(interface, &macAddr);
   //Select the relevant network adapter
   netSetDriver(interface, &mpc5748Eth1Driver);
   netSetPhyDriver(interface, &ksz8081PhyDriver);

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

   //Initialize timer
   timerInit();

   //Enable interrupts
   ENABLE_INTERRUPTS();

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

      //Add the ifDescr.1 object to the variable binding list of the message
      oidFromString("1.3.6.1.2.1.2.2.1.2.1", trapObjects[0].oid,
         SNMP_MAX_OID_SIZE, &trapObjects[0].oidLen);

      //Add the ifPhysAddress.1 object to the variable binding list of the message
      oidFromString("1.3.6.1.2.1.2.2.1.6.1", trapObjects[1].oid,
         SNMP_MAX_OID_SIZE, &trapObjects[1].oidLen);

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
