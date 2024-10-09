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
#include "samd21.h"
#include "samw25_xplained_pro.h"
#include "driver/include/m2m_wifi.h"
#include "os/include/m2m_wifi_ex.h"
#include "core/net.h"
#include "drivers/wifi/winc1500_driver.h"
#include "dhcp/dhcp_server.h"
#include "ipv6/ndp_router_adv.h"
#include "snmp/snmp_agent.h"
#include "mibs/mib2_module.h"
#include "mibs/mib2_impl.h"
#include "encoding/oid.h"
#include "private_mib_module.h"
#include "private_mib_impl.h"
#include "debug.h"

//Wi-Fi interface configuration
#define APP_IF_NAME "wlan0"
#define APP_HOST_NAME "snmp-agent-demo"
#define APP_MAC_ADDR "00-00-00-00-00-00"

#define APP_USE_DHCP_SERVER ENABLED
#define APP_IPV4_HOST_ADDR "192.168.8.1"
#define APP_IPV4_SUBNET_MASK "255.255.255.0"
#define APP_IPV4_DEFAULT_GATEWAY "0.0.0.0"
#define APP_IPV4_PRIMARY_DNS "0.0.0.0"
#define APP_IPV4_SECONDARY_DNS "0.0.0.0"
#define APP_IPV4_ADDR_RANGE_MIN "192.168.8.10"
#define APP_IPV4_ADDR_RANGE_MAX "192.168.8.99"

#define APP_USE_ROUTER_ADV ENABLED
#define APP_IPV6_LINK_LOCAL_ADDR "fe80::1500"
#define APP_IPV6_PREFIX "fd00:1:2:3::"
#define APP_IPV6_PREFIX_LENGTH 64
#define APP_IPV6_GLOBAL_ADDR "fd00:1:2:3::1500"

#define APP_WIFI_SSID "TEST_SAMW25_AP"
#define APP_WIFI_SECURITY M2M_WIFI_SEC_WPA_PSK
#define APP_WIFI_KEY "1122334455"
#define APP_WIFI_CHANNEL M2M_WIFI_CH_6

//Application configuration
#define APP_SNMP_PRIVATE_ENTERPRISE_NUMBER 8072
#define APP_SNMP_ENTERPRISE_OID "1.3.6.1.4.1.8072.9999.9999"
#define APP_SNMP_TRAP_DEST_IP_ADDR "192.168.0.100"

//Global variables
bool_t ledState = FALSE;
systime_t ledTime = 0;
DhcpState dhcpPrevState = DHCP_STATE_INIT;

DhcpServerSettings dhcpServerSettings;
DhcpServerContext dhcpServerContext;
NdpRouterAdvSettings ndpRouterAdvSettings;
NdpRouterAdvPrefixInfo ndpRouterAdvPrefixInfo[1];
NdpRouterAdvContext ndpRouterAdvContext;
SnmpAgentSettings snmpAgentSettings;
SnmpAgentContext snmpAgentContext;

//Forward declaration of functions
error_t snmpAgentRandCallback(uint8_t *data, size_t length);
void winc1500EnableAp(void);


/**
 * @brief I/O initialization
 **/

void ioInit(void)
{
   //Enable PORT bus clock (CLK_PORT_APB)
   PM->APBBMASK.bit.PORT_ = 1;

   //Configure LED0
   PORT->Group[LED0_GROUP].DIRSET.reg = LED0_MASK;
   PORT->Group[LED0_GROUP].OUTSET.reg = LED0_MASK;

   //Configure SW0 button
   PORT->Group[SW0_GROUP].DIRCLR.reg = SW0_MASK;
   PORT->Group[SW0_GROUP].PINCFG[SW0_PIN].bit.INEN = 1;
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
         PORT->Group[LED0_GROUP].OUTCLR.reg = LED0_MASK;
         ledState = 1;
         ledTime = systemTicks + 100;
      }
      else
      {
         PORT->Group[LED0_GROUP].OUTSET.reg = LED0_MASK;
         ledState = 0;
         ledTime = systemTicks + 900;
      }
   }
}


/**
 * @brief SysTick handler
 **/

void SysTick_Handler(void)
{
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

   //Update system core clock
   SystemCoreClockUpdate();

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
   TRACE_INFO("Target: SAMD21\r\n");
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

   //Configure Wi-Fi interface
   interface = &netInterface[0];

   //Set interface name
   netSetInterfaceName(interface, APP_IF_NAME);
   //Set host name
   netSetHostname(interface, APP_HOST_NAME);
   //Set host MAC address
   macStringToAddr(APP_MAC_ADDR, &macAddr);
   netSetMacAddr(interface, &macAddr);
   //Select the relevant network adapter
   netSetDriver(interface, &winc1500Driver);

   //Initialize network interface
   error = netConfigInterface(interface);
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to configure interface %s!\r\n", interface->name);
   }

#if (IPV4_SUPPORT == ENABLED)
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

#if (APP_USE_DHCP_SERVER == ENABLED)
   //Get default settings
   dhcpServerGetDefaultSettings(&dhcpServerSettings);
   //Set the network interface to be configured by DHCP
   dhcpServerSettings.interface = interface;
   //Lease time, in seconds, assigned to the DHCP clients
   dhcpServerSettings.leaseTime = 3600;

   //Lowest and highest IP addresses in the pool that are available
   //for dynamic address assignment
   ipv4StringToAddr(APP_IPV4_ADDR_RANGE_MIN, &dhcpServerSettings.ipAddrRangeMin);
   ipv4StringToAddr(APP_IPV4_ADDR_RANGE_MAX, &dhcpServerSettings.ipAddrRangeMax);

   //Subnet mask
   ipv4StringToAddr(APP_IPV4_SUBNET_MASK, &dhcpServerSettings.subnetMask);
   //Default gateway
   ipv4StringToAddr(APP_IPV4_DEFAULT_GATEWAY, &dhcpServerSettings.defaultGateway);
   //DNS servers
   ipv4StringToAddr(APP_IPV4_PRIMARY_DNS, &dhcpServerSettings.dnsServer[0]);
   ipv4StringToAddr(APP_IPV4_SECONDARY_DNS, &dhcpServerSettings.dnsServer[1]);

   //DHCP server initialization
   error = dhcpServerInit(&dhcpServerContext, &dhcpServerSettings);
   //Failed to initialize DHCP client?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize DHCP server!\r\n");
   }

   //Start DHCP server
   error = dhcpServerStart(&dhcpServerContext);
   //Failed to start DHCP client?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start DHCP server!\r\n");
   }
#endif
#endif

#if (IPV6_SUPPORT == ENABLED)
   //Set link-local address
   ipv6StringToAddr(APP_IPV6_LINK_LOCAL_ADDR, &ipv6Addr);
   ipv6SetLinkLocalAddr(interface, &ipv6Addr);

   //Set IPv6 prefix
   ipv6StringToAddr(APP_IPV6_PREFIX, &ipv6Addr);
   ipv6SetPrefix(interface, 0, &ipv6Addr, APP_IPV6_PREFIX_LENGTH);

   //Set global address
   ipv6StringToAddr(APP_IPV6_GLOBAL_ADDR, &ipv6Addr);
   ipv6SetGlobalAddr(interface, 0, &ipv6Addr);

#if (APP_USE_ROUTER_ADV == ENABLED)
   //List of IPv6 prefixes to be advertised
   ipv6StringToAddr(APP_IPV6_PREFIX, &ndpRouterAdvPrefixInfo[0].prefix);
   ndpRouterAdvPrefixInfo[0].length = APP_IPV6_PREFIX_LENGTH;
   ndpRouterAdvPrefixInfo[0].onLinkFlag = TRUE;
   ndpRouterAdvPrefixInfo[0].autonomousFlag = TRUE;
   ndpRouterAdvPrefixInfo[0].validLifetime = 3600;
   ndpRouterAdvPrefixInfo[0].preferredLifetime = 1800;

   //Get default settings
   ndpRouterAdvGetDefaultSettings(&ndpRouterAdvSettings);
   //Set the underlying network interface
   ndpRouterAdvSettings.interface = interface;
   //Maximum time interval between unsolicited Router Advertisements
   ndpRouterAdvSettings.maxRtrAdvInterval = 60000;
   //Minimum time interval between unsolicited Router Advertisements
   ndpRouterAdvSettings.minRtrAdvInterval = 20000;
   //Router lifetime
   ndpRouterAdvSettings.defaultLifetime = 0;
   //List of IPv6 prefixes
   ndpRouterAdvSettings.prefixList = ndpRouterAdvPrefixInfo;
   ndpRouterAdvSettings.prefixListLength = arraysize(ndpRouterAdvPrefixInfo);

   //RA service initialization
   error = ndpRouterAdvInit(&ndpRouterAdvContext, &ndpRouterAdvSettings);
   //Failed to initialize DHCPv6 client?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize RA service!\r\n");
   }

   //Start RA service
   error = ndpRouterAdvStart(&ndpRouterAdvContext);
   //Failed to start RA service?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start RA service!\r\n");
   }
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

   //Configure SysTick
   SysTick_Config(SystemCoreClock / 1000);

   //Create a Wi-Fi network
   winc1500EnableAp();

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


/**
 * @brief Create Wi-Fi network (AP mode)
 **/

void winc1500EnableAp(void)
{
   int8_t status;
   tstrM2MAPConfig apConfig;

   //Debug message
   TRACE_INFO("WINC1500: Creating Wi-Fi network (%s)...\r\n", APP_WIFI_SSID);

   //Initialize AP configuration parameters
   memset(&apConfig, 0, sizeof(apConfig));

   //Set SSID
   strcpy((char_t *) apConfig.au8SSID, APP_WIFI_SSID);
   //Make the SSID visible
   apConfig.u8SsidHide = SSID_MODE_VISIBLE;
   //Set Wi-Fi channel
   apConfig.u8ListenChannel = APP_WIFI_CHANNEL;

   //Set dummy IP Address
   apConfig.au8DHCPServerIP[0] = 192;
   apConfig.au8DHCPServerIP[1] = 168;
   apConfig.au8DHCPServerIP[2] = 0;
   apConfig.au8DHCPServerIP[3] = 1;

   //Security scheme?
   if(APP_WIFI_SECURITY == M2M_WIFI_SEC_OPEN)
   {
      //Set security mode (open)
      apConfig.u8SecType = M2M_WIFI_SEC_OPEN;
   }
   else if(APP_WIFI_SECURITY == M2M_WIFI_SEC_WEP)
   {
      //Set security mode (WEP)
      apConfig.u8SecType = M2M_WIFI_SEC_WEP;

      //Set WEP key
      apConfig.u8KeyIndx = M2M_WIFI_WEP_KEY_INDEX_1;
      apConfig.u8KeySz = strlen(APP_WIFI_KEY);
      strcpy((char_t *) apConfig.au8WepKey, APP_WIFI_KEY);
   }
   else if(APP_WIFI_SECURITY == M2M_WIFI_SEC_WPA_PSK)
   {
      //Set security mode (WPA/WPA2 personal)
      apConfig.u8SecType = M2M_WIFI_SEC_WPA_PSK;

      //Set WPA/WPA2 pre-shared key
      apConfig.u8KeySz = strlen(APP_WIFI_KEY);
      strcpy((char_t *) apConfig.au8Key, APP_WIFI_KEY);
   }

   //Enable AP
   status = os_m2m_wifi_enable_ap(&apConfig);

   //Debug message
   TRACE_INFO("  os_m2m_wifi_enable_ap = %d\r\n", status);

   //Delay required before sending a new command
   osDelayTask(200);
}


/**
 * @brief Callback function that processes Wi-Fi event notifications
 * @param[in] msgType Type of notification
 * @param[in] msg Pointer to the buffer containing the notification parameters
 **/

void winc1500EventHook(uint8_t msgType, void *msg)
{
   tstrM2mWifiStateChanged *stateChangedMsg;

   //Debug message
   TRACE_INFO("WINC1500: Wi-Fi event hook\r\n");

   //Check message type
   if(msgType == M2M_WIFI_RESP_CON_STATE_CHANGED)
   {
      //Connection state
      stateChangedMsg = (tstrM2mWifiStateChanged *) msg;

      //Check link state
      if(stateChangedMsg->u8CurrState == M2M_WIFI_CONNECTED)
      {
      }
      else
      {
      }
   }
}
