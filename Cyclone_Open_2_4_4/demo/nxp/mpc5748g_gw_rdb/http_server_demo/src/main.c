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
#include "mpc5748g_gw_rdb.h"
#include "core/net.h"
#include "drivers/mac/mpc5748_eth1_driver.h"
#include "drivers/mac/mpc5748_eth2_driver.h"
#include "drivers/phy/dp83848_driver.h"
#include "drivers/phy/ksz9031_driver.h"
#include "drivers/phy/tja1100_driver.h"
#include "drivers/phy/tja1102_driver.h"
#include "drivers/switch/sja1105_driver.h"
#include "smi_driver.h"
#include "spi_driver.h"
#include "dhcp/dhcp_client.h"
#include "ipv6/slaac.h"
#include "http/http_server.h"
#include "http/mime.h"
#include "path.h"
#include "date_time.h"
#include "resource_manager.h"
#include "sja1105_config.h"
#include "debug.h"

//First Ethernet interface configuration
#define APP_IF1_NAME "eth1"
#define APP_IF1_HOST_NAME "http-server-demo-1"
#define APP_IF1_MAC_ADDR "00-AB-CD-57-48-01"

#define APP_IF1_USE_DHCP_CLIENT ENABLED
#define APP_IF1_IPV4_HOST_ADDR "192.168.0.21"
#define APP_IF1_IPV4_SUBNET_MASK "255.255.255.0"
#define APP_IF1_IPV4_DEFAULT_GATEWAY "192.168.0.254"
#define APP_IF1_IPV4_PRIMARY_DNS "8.8.8.8"
#define APP_IF1_IPV4_SECONDARY_DNS "8.8.4.4"

#define APP_IF1_USE_SLAAC ENABLED
#define APP_IF1_IPV6_LINK_LOCAL_ADDR "fe80::5748:1"
#define APP_IF1_IPV6_PREFIX "2001:db8::"
#define APP_IF1_IPV6_PREFIX_LENGTH 64
#define APP_IF1_IPV6_GLOBAL_ADDR "2001:db8::5748:1"
#define APP_IF1_IPV6_ROUTER "fe80::1"
#define APP_IF1_IPV6_PRIMARY_DNS "2001:4860:4860::8888"
#define APP_IF1_IPV6_SECONDARY_DNS "2001:4860:4860::8844"

//Second Ethernet interface configuration
#define APP_IF2_NAME "eth2"
#define APP_IF2_HOST_NAME "http-server-demo-2"
#define APP_IF2_MAC_ADDR "00-AB-CD-57-48-02"

#define APP_IF2_USE_DHCP_CLIENT ENABLED
#define APP_IF2_IPV4_HOST_ADDR "192.168.0.22"
#define APP_IF2_IPV4_SUBNET_MASK "255.255.255.0"
#define APP_IF2_IPV4_DEFAULT_GATEWAY "192.168.0.254"
#define APP_IF2_IPV4_PRIMARY_DNS "8.8.8.8"
#define APP_IF2_IPV4_SECONDARY_DNS "8.8.4.4"

#define APP_IF2_USE_SLAAC ENABLED
#define APP_IF2_IPV6_LINK_LOCAL_ADDR "fe80::5748:2"
#define APP_IF2_IPV6_PREFIX "2001:db8::"
#define APP_IF2_IPV6_PREFIX_LENGTH 64
#define APP_IF2_IPV6_GLOBAL_ADDR "2001:db8::5748:2"
#define APP_IF2_IPV6_ROUTER "fe80::1"
#define APP_IF2_IPV6_PRIMARY_DNS "2001:4860:4860::8888"
#define APP_IF2_IPV6_SECONDARY_DNS "2001:4860:4860::8844"

//Application configuration
#define APP_HTTP_MAX_CONNECTIONS 8

//Global variables
DhcpClientSettings dhcpClientSettings;
DhcpClientContext dhcpClientContext[2];
SlaacSettings slaacSettings;
SlaacContext slaacContext[2];
HttpServerSettings httpServerSettings;
HttpServerContext httpServerContext;
HttpConnection httpConnections[APP_HTTP_MAX_CONNECTIONS];

//Forward declaration of functions
error_t eth1InterfaceInit(void);
error_t eth2InterfaceInit(void);

error_t httpServerCgiCallback(HttpConnection *connection,
   const char_t *param);

error_t httpServerRequestCallback(HttpConnection *connection,
   const char_t *uri);

error_t httpServerUriNotFoundCallback(HttpConnection *connection,
   const char_t *uri);


/**
 * @brief System initialization
 **/

void systemInit(void)
{
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
}


/**
 * @brief I/O initialization
 **/

void ioInit(void)
{
   //Set ON-OFF-CAN signal
   SIUL2->MSCR[ON_OFF_CAN] = SIUL2_MSCR_OBE_MASK | SIUL2_MSCR_SMC_MASK;
   SIUL2->GPDO[ON_OFF_CAN] = 1;

   //Set ON-OFF-ETH signal
   SIUL2->MSCR[ON_OFF_ETH] = SIUL2_MSCR_OBE_MASK | SIUL2_MSCR_SMC_MASK;
   SIUL2->GPDO[ON_OFF_ETH] = 1;

   //Clear DoIP-PowerON signal
   SIUL2->MSCR[DOIP_POWER_ON] = SIUL2_MSCR_OBE_MASK | SIUL2_MSCR_SMC_MASK;
   SIUL2->GPDO[DOIP_POWER_ON] = 0;
}


/**
 * @brief SJA1105 custom configuration
 * @param[in] interface Underlying network interface
 * @return Error code
 **/

error_t sja1105InitHook(NetInterface *interface)
{
   error_t error;
   uint16_t value;

   //Load the static configuration into the device
   error = sja1105LoadStaticConfig(interface, sja1105Config,
      osStrlen(sja1105Config));

   //Check status code
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to load static configuration!\r\n");
      //Exit immediately
      return error;
   }

   //Dump switch registers for debugging purpose
   sja1105DumpReg(interface);

   //Configure IO pads
   sja1105WriteSingleReg(interface, SJA1105_CFG_PAD_MII0_RX,
      SJA1105_CFG_PAD_MIIx_RX_D32_IPUD_PLAIN |
      SJA1105_CFG_PAD_MIIx_RX_D10_IPUD_PLAIN |
      SJA1105_CFG_PAD_MIIx_RX_CTRL_IPUD_PULL_DOWN |
      SJA1105_CFG_PAD_MIIx_RX_CLK_OS_FAST |
      SJA1105_CFG_PAD_MIIx_RX_CLK_IPUD_PLAIN);

   //Program the clock generation unit (CGU)
   sja1105ConfigureCgu(interface, SJA1105_PORT0);
   sja1105ConfigureCgu(interface, SJA1105_PORT1);
   sja1105ConfigureCgu(interface, SJA1105_PORT2);
   sja1105ConfigureCgu(interface, SJA1105_PORT3);
   sja1105ConfigureCgu(interface, SJA1105_PORT4);

   //Dump switch registers for debugging purpose
   sja1105DumpReg(interface);

   //Specify the address of the 1st PHY
   interface->phyAddr = 4;

   //Configure the PHY
   error = tja1100Init(interface);
   //Any error to report?
   if(error)
      return error;

   //Specify the address of the 2nd PHY
   interface->phyAddr = 5;

   //Configure the PHY
   error = tja1100Init(interface);
   //Any error to report?
   if(error)
      return error;

   //Specify the address of the 3rd PHY
   interface->phyAddr = 12;

   //Configure the PHY
   error = tja1102Init(interface);
   //Any error to report?
   if(error)
      return error;

   //Specify the address of the 4th PHY
   interface->phyAddr = 13;

   //Configure the PHY
   error = tja1102Init(interface);
   //Any error to report?
   if(error)
      return error;

   //Successful processing
   return NO_ERROR;
}


/**
 * @brief Get link state
 * @param[in] interface Underlying network interface
 * @param[in] port Port number
 * @return Link state
 **/

bool_t sja1105GetLinkState(NetInterface *interface, uint8_t port)
{
   uint16_t value;
   bool_t linkState;

   //Check port number
   if(port == SJA1105_PORT1)
   {
      //Read status register
      value = sja1105ReadPhyReg(interface, 4, TJA1100_BASIC_STAT);
      //Retrieve current link state
      linkState = (value & TJA1100_BASIC_STAT_LINK_STATUS) ? TRUE : FALSE;
   }
   else if(port == SJA1105_PORT2)
   {
      //Read status register
      value = sja1105ReadPhyReg(interface, 5, TJA1100_BASIC_STAT);
      //Retrieve current link state
      linkState = (value & TJA1100_BASIC_STAT_LINK_STATUS) ? TRUE : FALSE;
   }
   else if(port == SJA1105_PORT3)
   {
      //Read status register
      value = sja1105ReadPhyReg(interface, 12, TJA1102_BASIC_STAT);
      //Retrieve current link state
      linkState = (value & TJA1102_BASIC_STAT_LINK_STATUS) ? TRUE : FALSE;
   }
   else if(port == SJA1105_PORT4)
   {
      //Read status register
      value = sja1105ReadPhyReg(interface, 13, TJA1102_BASIC_STAT);
      //Retrieve current link state
      linkState = (value & TJA1102_BASIC_STAT_LINK_STATUS) ? TRUE : FALSE;
   }
   else
   {
      //The specified port number is not valid
      linkState = FALSE;
   }

   //Return link status
   return linkState;
}


/**
 * @brief Get link speed
 * @param[in] interface Underlying network interface
 * @param[in] port Port number
 * @return Link speed
 **/

uint32_t sja1105GetLinkSpeed(NetInterface *interface, uint8_t port)
{
   uint32_t linkSpeed;

   //Check port number
   if(port >= SJA1105_PORT0 && port <= SJA1105_PORT4)
   {
      linkSpeed = NIC_LINK_SPEED_100MBPS;
   }
   else
   {
      linkSpeed = NIC_LINK_SPEED_UNKNOWN;
   }

   //Return link speed
   return linkSpeed;
}


/**
 * @brief Main entry point
 * @return Unused value
 **/

int_t main(void)
{
   error_t error;

   //System initialization
   systemInit();
   //Update system core clock
   SystemCoreClockUpdate();

   //Configure I/Os
   ioInit();

   //Initialize kernel
   osInitKernel();
   //Configure debug UART
   debugInit(19200);

   //Start-up message
   TRACE_INFO("\r\n");
   TRACE_INFO("***********************************\r\n");
   TRACE_INFO("*** CycloneTCP HTTP Server Demo ***\r\n");
   TRACE_INFO("***********************************\r\n");
   TRACE_INFO("Copyright: 2010-2024 Oryx Embedded SARL\r\n");
   TRACE_INFO("Compiled: %s %s\r\n", __DATE__, __TIME__);
   TRACE_INFO("Target: MPC5748G\r\n");
   TRACE_INFO("\r\n");

   //TCP/IP stack initialization
   error = netInit();
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize TCP/IP stack!\r\n");
   }

   //Configure network interfaces
   eth1InterfaceInit();
   eth2InterfaceInit();

   //Get default settings
   httpServerGetDefaultSettings(&httpServerSettings);
   //Bind HTTP server to the desired interface
   httpServerSettings.interface = NULL;
   //Listen to port 80
   httpServerSettings.port = HTTP_PORT;
   //Client connections
   httpServerSettings.maxConnections = APP_HTTP_MAX_CONNECTIONS;
   httpServerSettings.connections = httpConnections;
   //Specify the server's root directory
   strcpy(httpServerSettings.rootDirectory, "/www/");
   //Set default home page
   strcpy(httpServerSettings.defaultDocument, "index.shtm");
   //Callback functions
   httpServerSettings.cgiCallback = httpServerCgiCallback;
   httpServerSettings.requestCallback = httpServerRequestCallback;
   httpServerSettings.uriNotFoundCallback = httpServerUriNotFoundCallback;

   //HTTP server initialization
   error = httpServerInit(&httpServerContext, &httpServerSettings);
   //Failed to initialize HTTP server?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize HTTP server!\r\n");
   }

   //Start HTTP server
   error = httpServerStart(&httpServerContext);
   //Failed to start HTTP server?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start HTTP server!\r\n");
   }

   //Start the execution of tasks
   osStartKernel();

   //This function should never return
   return 0;
}


/**
 * @brief First Ethernet interface initialization
 **/

error_t eth1InterfaceInit(void)
{
   error_t error;
   NetInterface *interface;
   MacAddr macAddr;
#if (APP_IF1_USE_DHCP_CLIENT == DISABLED)
   Ipv4Addr ipv4Addr;
#endif
#if (APP_IF1_USE_SLAAC == DISABLED)
   Ipv6Addr ipv6Addr;
#endif

   //Configure the first network interface
   interface = &netInterface[0];

   //Set interface name
   netSetInterfaceName(interface, APP_IF1_NAME);
   //Set host name
   netSetHostname(interface, APP_IF1_HOST_NAME);
   //Set host MAC address
   macStringToAddr(APP_IF1_MAC_ADDR, &macAddr);
   netSetMacAddr(interface, &macAddr);
   //Select the relevant MAC driver
   netSetDriver(interface, &mpc5748Eth1Driver);
   //Select the relevant switch driver
   netSetSwitchDriver(interface, &sja1105SwitchDriver);
   //Underlying SPI driver
   netSetSpiDriver(interface, &spiDriver);

   //Initialize network interface
   error = netConfigInterface(interface);
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to configure interface %s!\r\n", interface->name);
      //Exit immediately
      return error;
   }

#if (IPV4_SUPPORT == ENABLED)
#if (APP_IF1_USE_DHCP_CLIENT == ENABLED)
   //Get default settings
   dhcpClientGetDefaultSettings(&dhcpClientSettings);
   //Set the network interface to be configured by DHCP
   dhcpClientSettings.interface = interface;
   //Disable rapid commit option
   dhcpClientSettings.rapidCommit = FALSE;

   //DHCP client initialization
   error = dhcpClientInit(&dhcpClientContext[0], &dhcpClientSettings);
   //Failed to initialize DHCP client?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize DHCP client!\r\n");
      //Exit immediately
      return error;
   }

   //Start DHCP client
   error = dhcpClientStart(&dhcpClientContext[0]);
   //Failed to start DHCP client?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start DHCP client!\r\n");
      //Exit immediately
      return error;
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
   error = slaacInit(&slaacContext[0], &slaacSettings);
   //Failed to initialize SLAAC?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize SLAAC!\r\n");
      //Exit immediately
      return error;
   }

   //Start IPv6 address autoconfiguration process
   error = slaacStart(&slaacContext[0]);
   //Failed to start SLAAC process?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start SLAAC!\r\n");
      //Exit immediately
      return error;
   }
#else
   //Set link-local address
   ipv6StringToAddr(APP_IF1_IPV6_LINK_LOCAL_ADDR, &ipv6Addr);
   ipv6SetLinkLocalAddr(interface, &ipv6Addr);
#endif
#endif

   //Successful initialization
   return NO_ERROR;
}


/**
 * @brief Second Ethernet interface initialization
 **/

error_t eth2InterfaceInit(void)
{
   error_t error;
   NetInterface *interface;
   MacAddr macAddr;
#if (APP_IF2_USE_DHCP_CLIENT == DISABLED)
   Ipv4Addr ipv4Addr;
#endif
#if (APP_IF2_USE_SLAAC == DISABLED)
   Ipv6Addr ipv6Addr;
#endif

   //Configure the second network interface
   interface = &netInterface[1];

   //Set interface name
   netSetInterfaceName(interface, APP_IF2_NAME);
   //Set host name
   netSetHostname(interface, APP_IF2_HOST_NAME);
   //Set host MAC address
   macStringToAddr(APP_IF2_MAC_ADDR, &macAddr);
   netSetMacAddr(interface, &macAddr);
   //Select the relevant MAC driver
   netSetDriver(interface, &mpc5748Eth2Driver);
   //Select the relevant PHY driver
   netSetPhyDriver(interface, &dp83848PhyDriver);
   //Set PHY address
   netSetPhyAddr(interface, 1);
   //The PHY is managed via the MDC/MDIO interface of ENET0 instance
   netSetSmiDriver(interface, &smiDriver);

   //Initialize network interface
   error = netConfigInterface(interface);
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to configure interface %s!\r\n", interface->name);
      //Exit immediately
      return error;
   }

#if (IPV4_SUPPORT == ENABLED)
#if (APP_IF2_USE_DHCP_CLIENT == ENABLED)
   //Get default settings
   dhcpClientGetDefaultSettings(&dhcpClientSettings);
   //Set the network interface to be configured by DHCP
   dhcpClientSettings.interface = interface;
   //Disable rapid commit option
   dhcpClientSettings.rapidCommit = FALSE;

   //DHCP client initialization
   error = dhcpClientInit(&dhcpClientContext[1], &dhcpClientSettings);
   //Failed to initialize DHCP client?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize DHCP client!\r\n");
      //Exit immediately
      return error;
   }

   //Start DHCP client
   error = dhcpClientStart(&dhcpClientContext[1]);
   //Failed to start DHCP client?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start DHCP client!\r\n");
      //Exit immediately
      return error;
   }
#else
   //Set IPv4 host address
   ipv4StringToAddr(APP_IF2_IPV4_HOST_ADDR, &ipv4Addr);
   ipv4SetHostAddr(interface, ipv4Addr);

   //Set subnet mask
   ipv4StringToAddr(APP_IF2_IPV4_SUBNET_MASK, &ipv4Addr);
   ipv4SetSubnetMask(interface, ipv4Addr);

   //Set default gateway
   ipv4StringToAddr(APP_IF2_IPV4_DEFAULT_GATEWAY, &ipv4Addr);
   ipv4SetDefaultGateway(interface, ipv4Addr);

   //Set primary and secondary DNS servers
   ipv4StringToAddr(APP_IF2_IPV4_PRIMARY_DNS, &ipv4Addr);
   ipv4SetDnsServer(interface, 0, ipv4Addr);
   ipv4StringToAddr(APP_IF2_IPV4_SECONDARY_DNS, &ipv4Addr);
   ipv4SetDnsServer(interface, 1, ipv4Addr);
#endif
#endif

#if (IPV6_SUPPORT == ENABLED)
#if (APP_IF2_USE_SLAAC == ENABLED)
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
      //Exit immediately
      return error;
   }

   //Start IPv6 address autoconfiguration process
   error = slaacStart(&slaacContext[1]);
   //Failed to start SLAAC process?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start SLAAC!\r\n");
      //Exit immediately
      return error;
   }
#else
   //Set link-local address
   ipv6StringToAddr(APP_IF2_IPV6_LINK_LOCAL_ADDR, &ipv6Addr);
   ipv6SetLinkLocalAddr(interface, &ipv6Addr);
#endif
#endif

   //Successful initialization
   return NO_ERROR;
}


/**
 * @brief CGI callback function
 * @param[in] connection Handle referencing a client connection
 * @param[in] param NULL-terminated string that contains the CGI parameter
 * @return Error code
 **/

error_t httpServerCgiCallback(HttpConnection *connection,
   const char_t *param)
{
   static uint_t pageCounter = 0;
   uint_t length;
   MacAddr macAddr;
#if (IPV4_SUPPORT == ENABLED)
   Ipv4Addr ipv4Addr;
#endif
#if (IPV6_SUPPORT == ENABLED)
   uint_t n;
   Ipv6Addr ipv6Addr;
#endif

   //Underlying network interface
   NetInterface *interface = connection->socket->interface;

   //Check parameter name
   if(!strcasecmp(param, "PAGE_COUNTER"))
   {
      pageCounter++;
      sprintf(connection->buffer, "%u time%s", pageCounter, (pageCounter >= 2) ? "s" : "");
   }
   else if(!strcasecmp(param, "BOARD_NAME"))
   {
      strcpy(connection->buffer, "MPC5748G-GW-RDB");
   }
   else if(!strcasecmp(param, "SYSTEM_TIME"))
   {
      systime_t time = osGetSystemTime();
      formatSystemTime(time, connection->buffer);
   }
   else if(!strcasecmp(param, "MAC_ADDR"))
   {
      netGetMacAddr(interface, &macAddr);
      macAddrToString(&macAddr, connection->buffer);
   }
   else if(!strcasecmp(param, "IPV4_ADDR"))
   {
      ipv4GetHostAddr(interface, &ipv4Addr);
      ipv4AddrToString(ipv4Addr, connection->buffer);
   }
   else if(!strcasecmp(param, "SUBNET_MASK"))
   {
      ipv4GetSubnetMask(interface, &ipv4Addr);
      ipv4AddrToString(ipv4Addr, connection->buffer);
   }
   else if(!strcasecmp(param, "DEFAULT_GATEWAY"))
   {
      ipv4GetDefaultGateway(interface, &ipv4Addr);
      ipv4AddrToString(ipv4Addr, connection->buffer);
   }
   else if(!strcasecmp(param, "IPV4_PRIMARY_DNS"))
   {
      ipv4GetDnsServer(interface, 0, &ipv4Addr);
      ipv4AddrToString(ipv4Addr, connection->buffer);
   }
   else if(!strcasecmp(param, "IPV4_SECONDARY_DNS"))
   {
      ipv4GetDnsServer(interface, 1, &ipv4Addr);
      ipv4AddrToString(ipv4Addr, connection->buffer);
   }
#if (IPV6_SUPPORT == ENABLED)
   else if(!strcasecmp(param, "LINK_LOCAL_ADDR"))
   {
      ipv6GetLinkLocalAddr(interface, &ipv6Addr);
      ipv6AddrToString(&ipv6Addr, connection->buffer);
   }
   else if(!strcasecmp(param, "GLOBAL_ADDR"))
   {
      ipv6GetGlobalAddr(interface, 0, &ipv6Addr);
      ipv6AddrToString(&ipv6Addr, connection->buffer);
   }
   else if(!strcasecmp(param, "IPV6_PREFIX"))
   {
      ipv6GetPrefix(interface, 0, &ipv6Addr, &n);
      ipv6AddrToString(&ipv6Addr, connection->buffer);
      length = strlen(connection->buffer);
      sprintf(connection->buffer + length, "/%u", n);
   }
   else if(!strcasecmp(param, "ROUTER"))
   {
      ipv6GetDefaultRouter(interface, 0, &ipv6Addr);
      ipv6AddrToString(&ipv6Addr, connection->buffer);
   }
   else if(!strcasecmp(param, "IPV6_PRIMARY_DNS"))
   {
      ipv6GetDnsServer(interface, 0, &ipv6Addr);
      ipv6AddrToString(&ipv6Addr, connection->buffer);
   }
   else if(!strcasecmp(param, "IPV6_SECONDARY_DNS"))
   {
      ipv6GetDnsServer(interface, 1, &ipv6Addr);
      ipv6AddrToString(&ipv6Addr, connection->buffer);
   }
#endif
   else
   {
      return ERROR_INVALID_TAG;
   }

   //Get the length of the resulting string
   length = strlen(connection->buffer);

   //Send the contents of the specified environment variable
   return httpWriteStream(connection, connection->buffer, length);
}


/**
 * @brief HTTP request callback
 * @param[in] connection Handle referencing a client connection
 * @param[in] uri NULL-terminated string containing the path to the requested resource
 * @return Error code
 **/

error_t httpServerRequestCallback(HttpConnection *connection,
   const char_t *uri)
{
   //Not implemented
   return ERROR_NOT_FOUND;
}


/**
 * @brief URI not found callback
 * @param[in] connection Handle referencing a client connection
 * @param[in] uri NULL-terminated string containing the path to the requested resource
 * @return Error code
 **/

error_t httpServerUriNotFoundCallback(HttpConnection *connection,
   const char_t *uri)
{
   //Not implemented
   return ERROR_NOT_FOUND;
}
