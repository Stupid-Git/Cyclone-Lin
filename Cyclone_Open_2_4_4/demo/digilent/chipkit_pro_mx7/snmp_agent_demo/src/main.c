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
#include "chipkit_pro_mx7.h"
#include "core/net.h"
#include "drivers/mac/pic32mx_eth_driver.h"
#include "drivers/phy/lan8720_driver.h"
#include "dhcp/dhcp_client.h"
#include "ipv6/slaac.h"
#include "snmp/snmp_agent.h"
#include "mibs/mib2_module.h"
#include "mibs/mib2_impl.h"
#include "encoding/oid.h"
#include "private_mib_module.h"
#include "private_mib_impl.h"
#include "debug.h"

#ifndef _CP0_SET_CONFIG
    #define _CP0_SET_CONFIG(val) _mtc0(_CP0_CONFIG, _CP0_CONFIG_SELECT, val)
#endif

//Configuration bits
#pragma config USERID = 0xFFFF
#pragma config FSRSSEL = PRIORITY_7
#pragma config FMIIEN = OFF
#pragma config FETHIO = ON
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
#pragma config POSCMOD = EC
#pragma config OSCIOFNC = OFF
#pragma config FPBDIV = DIV_2
#pragma config FCKSM = CSDCMD
#pragma config WDTPS = PS1048576
#pragma config FWDTEN = OFF
//#pragma config DEBUG = ON
#pragma config ICESEL = ICS_PGx1
#pragma config PWP = OFF
#pragma config BWP = OFF
#pragma config CP = OFF

//Ethernet interface configuration
#define APP_IF_NAME "eth0"
#define APP_HOST_NAME "snmp-agent-demo"
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
 * @brief Timer 1 interrupt service routine
 **/

void __ISR(_TIMER_1_VECTOR, IPL4SOFT) timer1IrqHandler(void)
{
   //Clear interrupt flag
   IFS0CLR = _IFS0_T1IF_MASK;
   //Increment tick counter
   systemTicks++;
}


/**
 * @brief Ethernet interrupt service routine
 **/

void __ISR(_ETH_VECTOR, IPL2SOFT) ethIrqHandler(void)
{
   //Call interrupt handler
   pic32mxEthIrqHandler();
}


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
   //Disable JTAG
   DDPCONbits.JTAGEN = 0;

   //Disable analog inputs
   AD1PCFG = 0xFFFF;

   //Configure LED1 (RG12), LED2 (RG13), LED3 (RG14) and LED4 (RG15)
   TRISGCLR = LED1_MASK | LED2_MASK | LED3_MASK | LED4_MASK;
   LATGCLR = LED1_MASK | LED2_MASK | LED3_MASK | LED4_MASK;

   //Configure BTN1 (RG6) and BTN2 (RG7)
   TRISGSET = BTN1_MASK | BTN2_MASK;

   //Configure BTN3 (RA0)
   TRISASET = BTN3_MASK;

   //Configure PHY_RST (RA6) as an output
   TRISACLR = PHY_RST_MASK;

   //Reset PHY transceiver (hard reset)
   LATACLR = PHY_RST_MASK;
   sleep(10);
   LATASET = PHY_RST_MASK;
   sleep(10);
}


/**
 * @brief Timer1 initialization
 **/

void timer1Init(void)
{
   //Disable timer
   T1CON = 0;

   //Configure prescaler (1:8)
   T1CONSET = _T1CON_TCKPS0_MASK;
   //Set period register
   PR1 = ((40000000 / 8) / 1000) - 1;
   //Clear timer register
   TMR1 = 0;

   //Set interrupt priority
   IPC1CLR = _IPC1_T1IP_MASK;
   IPC1SET = (4 << _IPC1_T1IP_POSITION);
   //Set interrupt subpriority
   IPC1CLR = _IPC1_T1IS_MASK;
   IPC1SET = (0 << _IPC1_T1IS_POSITION);

   //Clear interrupt flag
   IFS0CLR = _IFS0_T1IF_MASK;
   //Enable timer interrupts
   IEC0SET = _IEC0_T1IE_MASK;

   //Start timer
   T1CONSET = _T1CON_TON_MASK;
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
         LATGSET = LED1_MASK;
         ledState = 1;
         ledTime = systemTicks + 100;
      }
      else
      {
         LATGCLR = LED1_MASK;
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
   TRACE_INFO("Target: PIC32MX795F512L\r\n");
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
   netSetPhyDriver(interface, &lan8720PhyDriver);

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

   //Initialize Timer1
   timer1Init();

   //Enable interrupts
   __builtin_enable_interrupts();

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
