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
#include "pic32cx_sg61_curiosity_ultra.h"
#include "core/net.h"
#include "drivers/mac/pic32cx_eth_driver.h"
#include "drivers/phy/ksz8041_driver.h"
#include "drivers/phy/ksz8061_driver.h"
#include "drivers/phy/lan8670_driver.h"
#include "drivers/phy/lan8720_driver.h"
#include "drivers/phy/lan8770_driver.h"
#include "drivers/switch/ksz8863_driver.h"
#include "drivers/switch/lan9303_driver.h"
#include "dhcp/dhcp_client.h"
#include "ipv6/slaac.h"
#include "shell/shell_server.h"
#include "hardware/pic32cx_sg/pic32cx_sg_crypto.h"
#include "rng/trng.h"
#include "rng/yarrow.h"
#include "resource_manager.h"
#include "spi_driver.h"
#include "debug.h"

//Ethernet interface configuration
#define APP_IF_NAME "eth0"
#define APP_HOST_NAME "ssh-server-demo"
#define APP_MAC_ADDR "00-AB-CD-EF-32-61"

#define APP_USE_DHCP_CLIENT ENABLED
#define APP_IPV4_HOST_ADDR "192.168.0.20"
#define APP_IPV4_SUBNET_MASK "255.255.255.0"
#define APP_IPV4_DEFAULT_GATEWAY "192.168.0.254"
#define APP_IPV4_PRIMARY_DNS "8.8.8.8"
#define APP_IPV4_SECONDARY_DNS "8.8.4.4"

#define APP_USE_SLAAC ENABLED
#define APP_IPV6_LINK_LOCAL_ADDR "fe80::3261"
#define APP_IPV6_PREFIX "2001:db8::"
#define APP_IPV6_PREFIX_LENGTH 64
#define APP_IPV6_GLOBAL_ADDR "2001:db8::3261"
#define APP_IPV6_ROUTER "fe80::1"
#define APP_IPV6_PRIMARY_DNS "2001:4860:4860::8888"
#define APP_IPV6_SECONDARY_DNS "2001:4860:4860::8844"

//Application configuration
#define APP_SSH_MAX_CONNECTIONS 3
#define APP_SSH_MAX_CHANNELS 3
#define APP_SHELL_MAX_SESSIONS 3
#define APP_SSH_SERVER_RSA_PUBLIC_KEY "keys/server_rsa_public_key.pem"
#define APP_SSH_SERVER_RSA_PRIVATE_KEY "keys/server_rsa_private_key.pem"
#define APP_SSH_SERVER_DSA_PUBLIC_KEY "keys/server_dsa_public_key.pem"
#define APP_SSH_SERVER_DSA_PRIVATE_KEY "keys/server_dsa_private_key.pem"
#define APP_SSH_SERVER_ECDSA_P256_PUBLIC_KEY "keys/server_ecdsa_p256_public_key.pem"
#define APP_SSH_SERVER_ECDSA_P256_PRIVATE_KEY "keys/server_ecdsa_p256_private_key.pem"

//Global variables
DhcpClientSettings dhcpClientSettings;
DhcpClientContext dhcpClientContext;
SlaacSettings slaacSettings;
SlaacContext slaacContext;
SshServerSettings sshServerSettings;
SshServerContext sshServerContext;
SshConnection sshConnections[APP_SSH_MAX_CONNECTIONS];
SshChannel sshChannels[APP_SSH_MAX_CHANNELS];
ShellServerSettings shellServerSettings;
ShellServerContext shellServerContext;
ShellServerSession shellSessions[APP_SHELL_MAX_SESSIONS];
YarrowContext yarrowContext;
uint8_t seed[32];

//Forward declaration of functions
error_t sshServerImportKeys(SshServerContext *context);

SshAuthStatus sshServerPasswordAuthCallback(SshConnection *connection,
   const char_t *user, const char_t *password, size_t passwordLen);

ShellAccessStatus shellServerCheckUserCallback(ShellServerSession *session,
   const char_t *user);

error_t shellServerCommandLineCallback(ShellServerSession *session,
   char_t *commandLine);


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
   TRACE_INFO("**********************************\r\n");
   TRACE_INFO("*** CycloneSSH SSH Server Demo ***\r\n");
   TRACE_INFO("**********************************\r\n");
   TRACE_INFO("Copyright: 2010-2024 Oryx Embedded SARL\r\n");
   TRACE_INFO("Compiled: %s %s\r\n", __DATE__, __TIME__);
   TRACE_INFO("Target: PIC32CX1025SG61128\r\n");
   TRACE_INFO("\r\n");

   //Configure I/Os
   ioInit();

   //Initialize hardware cryptographic accelerator
   error = pic32cxsgCryptoInit();
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize hardware crypto accelerator!\r\n");
   }

   //Generate a random seed
   error = trngGetRandomData(seed, sizeof(seed));
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to generate random data!\r\n");
   }

   //PRNG initialization
   error = yarrowInit(&yarrowContext);
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize PRNG!\r\n");
   }

   //Properly seed the PRNG
   error = yarrowSeed(&yarrowContext, seed, sizeof(seed));
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to seed PRNG!\r\n");
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

#if defined(USE_KSZ8041)
   //Select the relevant PHY driver
   netSetPhyDriver(interface, &ksz8041PhyDriver);
   //Set PHY address
   netSetPhyAddr(interface, 0);
#elif defined(USE_KSZ8061)
   //Select the relevant PHY driver
   netSetPhyDriver(interface, &ksz8061PhyDriver);
   //Set PHY address
   netSetPhyAddr(interface, 0);
#elif defined(USE_LAN8670)
   //Select the relevant PHY driver
   netSetPhyDriver(interface, &lan8670PhyDriver);
   //Set PHY address
   netSetPhyAddr(interface, 0);
#elif defined(USE_LAN8720)
   //Select the relevant PHY driver
   netSetPhyDriver(interface, &lan8720PhyDriver);
   //Set PHY address
   netSetPhyAddr(interface, 0);
#elif defined(USE_LAN8770)
   //Select the relevant PHY driver
   netSetPhyDriver(interface, &lan8770PhyDriver);
   //Set PHY address
   netSetPhyAddr(interface, 4);
#elif defined(USE_KSZ8863)
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
   sshServerGetDefaultSettings(&sshServerSettings);
   //Bind SSH server to the desired interface
   sshServerSettings.interface = NULL;
   //Listen to port 22
   sshServerSettings.port = SSH_PORT;
   //SSH connections
   sshServerSettings.numConnections = APP_SSH_MAX_CONNECTIONS;
   sshServerSettings.connections = sshConnections;
   //SSH channels
   sshServerSettings.numChannels = APP_SSH_MAX_CHANNELS;
   sshServerSettings.channels = sshChannels;
   //Pseudo-random number generator
   sshServerSettings.prngAlgo = YARROW_PRNG_ALGO;
   sshServerSettings.prngContext = &yarrowContext;
   //Password authentication callback function
   sshServerSettings.passwordAuthCallback = sshServerPasswordAuthCallback;

   //SSH server initialization
   error = sshServerInit(&sshServerContext, &sshServerSettings);
   //Failed to initialize SSH server?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize SSH server!\r\n");
   }

   //Load keys
   error = sshServerImportKeys(&sshServerContext);
   //Failed to load keys?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to load keys!\r\n");
   }

   //Start SSH server
   error = sshServerStart(&sshServerContext);
   //Failed to start SSH server?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start SSH server!\r\n");
   }

   //Get default settings
   shellServerGetDefaultSettings(&shellServerSettings);
   //SSH server context
   shellServerSettings.sshServerContext = &sshServerContext;
   //Shell sessions
   shellServerSettings.numSessions = APP_SHELL_MAX_SESSIONS;
   shellServerSettings.sessions = shellSessions;
   //User verification callback function
   shellServerSettings.checkUserCallback = shellServerCheckUserCallback;
   //Command line processing callback function
   shellServerSettings.commandLineCallback = shellServerCommandLineCallback;

   //Shell server initialization
   error = shellServerInit(&shellServerContext, &shellServerSettings);
   //Failed to initialize shell server?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize shell server!\r\n");
   }

   //Start shell server
   error = shellServerStart(&shellServerContext);
   //Failed to start shell server?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start shell server!\r\n");
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
 * @brief Load SSH server's keys
 * @param[in] context Pointer to the SSH server context
 * @return Error code
 **/

error_t sshServerImportKeys(SshServerContext *context)
{
   error_t error;
   const char_t *publicKey;
   size_t publicKeyLen;
   const char_t *privateKey;
   size_t privateKeyLen;

   //Get server's RSA public key
   error = resGetData(APP_SSH_SERVER_RSA_PUBLIC_KEY,
      (const uint8_t **) &publicKey, &publicKeyLen);
   //Any error to report?
   if(error)
      return error;

   //Get server's RSA private key
   error = resGetData(APP_SSH_SERVER_RSA_PRIVATE_KEY,
      (const uint8_t **) &privateKey, &privateKeyLen);
   //Any error to report?
   if(error)
      return error;

   //Load RSA key pair
   error = sshServerLoadHostKey(context, 0, publicKey, publicKeyLen,
      privateKey, privateKeyLen, NULL);
   //Any error to report?
   if(error)
      return error;

   //Get server's DSA public key
   error = resGetData(APP_SSH_SERVER_DSA_PUBLIC_KEY,
      (const uint8_t **) &publicKey, &publicKeyLen);
   //Any error to report?
   if(error)
      return error;

   //Get server's DSA private key
   error = resGetData(APP_SSH_SERVER_DSA_PRIVATE_KEY,
      (const uint8_t **) &privateKey, &privateKeyLen);
   //Any error to report?
   if(error)
      return error;

   //Load DSA key pair
   error = sshServerLoadHostKey(context, 1, publicKey, publicKeyLen,
      privateKey, privateKeyLen, NULL);
   //Any error to report?
   if(error)
      return error;

   //Get server's ECDSA P-256 public key
   error = resGetData(APP_SSH_SERVER_ECDSA_P256_PUBLIC_KEY,
      (const uint8_t **) &publicKey, &publicKeyLen);
   //Any error to report?
   if(error)
      return error;

   //Get server's ECDSA P-256 private key
   error = resGetData(APP_SSH_SERVER_ECDSA_P256_PRIVATE_KEY,
      (const uint8_t **) &privateKey, &privateKeyLen);
   //Any error to report?
   if(error)
      return error;

   //Load ECDSA P-256 key pair
   error = sshServerLoadHostKey(context, 2, publicKey, publicKeyLen,
      privateKey, privateKeyLen, NULL);
   //Any error to report?
   if(error)
      return error;

   //Successful processing
   return NO_ERROR;
}


/**
 * @brief Password authentication callback function
 * @param[in] connection Handle referencing a client connection
 * @param[in] user NULL-terminated string that contains the user name
 * @param[in] password NULL-terminated string that contains the corresponding password
 * @return Authentication status (SSH_AUTH_STATUS_SUCCESS, SSH_AUTH_STATUS_FAILURE or
 *   SSH_AUTH_STATUS_PASSWORD_EXPIRED)
 **/

SshAuthStatus sshServerPasswordAuthCallback(SshConnection *connection,
   const char_t *user, const char_t *password, size_t passwordLen)
{
   SshAuthStatus status;

   //Debug message
   TRACE_INFO("SSH server: Password verification\r\n");

   //Manage authentication policy
   if(!strcmp(user, "admin"))
   {
      //Check password
      if(passwordLen == 8 && !strncmp(password, "password", 8))
      {
         //The provided password is valid
         status = SSH_AUTH_STATUS_SUCCESS;
      }
      else
      {
         //The provided password is not valid
         status = SSH_AUTH_STATUS_FAILURE;
      }
   }
   else
   {
      //Unknown user name
      status = SSH_AUTH_STATUS_FAILURE;
   }

   //Return access status
   return status;
}


/**
 * @brief User verification callback function
 * @param[in] session Handle referencing a shell session
 * @param[in] user NULL-terminated string that contains the user name
 * @return Access status
 **/

ShellAccessStatus shellServerCheckUserCallback(ShellServerSession *session,
   const char_t *user)
{
   //Debug message
   TRACE_INFO("Shell server: User verification\r\n");

   //Set welcome banner
   shellServerSetBanner(session,
      "You are connected to \x1b[32mCycloneSSH\x1b[39m Server\r\n");

   //Set shell prompt
   shellServerSetPrompt(session, ">");

   //All SSH users are granted access to the shell service
   return SHELL_ACCESS_ALLOWED;
}


/**
 * @brief Command line processing callback function
 * @param[in] session Handle referencing an SCP session
 * @param[in] user NULL-terminated string that contains the user name
 * @param[in] path Canonical path of the file
 * @return Permissions for the specified file
 **/

error_t shellServerCommandLineCallback(ShellServerSession *session,
   char_t *commandLine)
{
   error_t error;

   //Debug message
   TRACE_INFO("Shell server: Command line received\r\n");
   TRACE_INFO("  %s\r\n", commandLine);

   //Check command name
   if(!strcasecmp(commandLine, "hello"))
   {
      //Send response to the client
      error = shellServerWriteStream(session, "Hello World!\r\n", 14,
         NULL, 0);
   }
   else if(!strcasecmp(commandLine, "exit") ||
      !strcasecmp(commandLine, "quit"))
   {
      //Close shell session
      error = ERROR_END_OF_STREAM;
   }
   else
   {
      //Unknown command received
      error = shellServerWriteStream(session, "Unknown command!\r\n", 18,
         NULL, 0);
   }

   //Return status code
   return error;
}
