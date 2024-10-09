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
#include "pic32mz_da_curiosity.h"
#include "core/net.h"
#include "drivers/mac/pic32mz_eth_driver.h"
#include "drivers/phy/lan8720_driver.h"
#include "dhcp/dhcp_client.h"
#include "ipv6/slaac.h"
#include "shell/shell_client.h"
#include "ssh/ssh_key_verify.h"
#include "rng/yarrow.h"
#include "debug.h"

//Configuration bits
#pragma config DEBUG = OFF
#pragma config JTAGEN = OFF
#pragma config ICESEL = ICS_PGx2
#pragma config TRCEN = OFF
#pragma config BOOTISA = MIPS32
#pragma config FECCCON = OFF_UNLOCKED
#pragma config FSLEEP = OFF
#pragma config DBGPER = PG_ALL
#pragma config SMCLR = MCLR_NORM
#pragma config SOSCGAIN = GAIN_2X
#pragma config SOSCBOOST = ON
#pragma config POSCGAIN = GAIN_2X
#pragma config POSCBOOST = ON
#pragma config POSCFGAIN = GAIN_G3
#pragma config POSCAGCDLY = POSCAGCDLY1
#pragma config POSCAGC = OFF
#pragma config EJTAGBEN = NORMAL
#pragma config FNOSC = SPLL
#pragma config DMTINTV = WIN_127_128
#pragma config FSOSCEN = OFF
#pragma config IESO = ON
#pragma config POSCMOD = EC
#pragma config OSCIOFNC = OFF
#pragma config FCKSM = CSECME
#pragma config WDTPS = PS1048576
#pragma config WDTSPGM = STOP
#pragma config WINDIS = NORMAL
#pragma config FWDTEN = OFF
#pragma config FWDTWINSZ = WINSZ_25
#pragma config DMTCNT = DMT31
#pragma config FDMTEN = OFF
#pragma config FPLLIDIV = DIV_3
#pragma config FPLLRNG = RANGE_5_10_MHZ
#pragma config FPLLICLK = PLL_POSC
#pragma config FPLLMULT = MUL_50
#pragma config FPLLODIV = DIV_2
#pragma config VBATBOREN = ON
#pragma config DSBOREN = ON
#pragma config DSWDTPS = DSPS32
#pragma config DSWDTOSC = LPRC
#pragma config DSWDTEN = OFF
#pragma config FDSEN = ON
#pragma config UPLLFSEL = FREQ_24MHZ
#pragma config USERID = 0xFFFF
#pragma config FMIIEN = OFF
#pragma config FETHIO = ON
#pragma config PGL1WAY = OFF
#pragma config PMDL1WAY = OFF
#pragma config IOL1WAY = OFF
#pragma config SWDTPS = SPS1048576
#pragma config TSEQ = 0x0000
#pragma config CSEQ = 0xFFFF

//Ethernet interface configuration
#define APP_IF_NAME "eth0"
#define APP_HOST_NAME "ssh-client-demo"
#define APP_USE_DEFAULT_MAC_ADDR ENABLED
#define APP_MAC_ADDR "00-AB-CD-EF-20-64"

#define APP_USE_DHCP_CLIENT ENABLED
#define APP_IPV4_HOST_ADDR "192.168.0.20"
#define APP_IPV4_SUBNET_MASK "255.255.255.0"
#define APP_IPV4_DEFAULT_GATEWAY "192.168.0.254"
#define APP_IPV4_PRIMARY_DNS "8.8.8.8"
#define APP_IPV4_SECONDARY_DNS "8.8.4.4"

#define APP_USE_SLAAC ENABLED
#define APP_IPV6_LINK_LOCAL_ADDR "fe80::2064"
#define APP_IPV6_PREFIX "2001:db8::"
#define APP_IPV6_PREFIX_LENGTH 64
#define APP_IPV6_GLOBAL_ADDR "2001:db8::2064"
#define APP_IPV6_ROUTER "fe80::1"
#define APP_IPV6_PRIMARY_DNS "2001:4860:4860::8888"
#define APP_IPV6_SECONDARY_DNS "2001:4860:4860::8844"

//Application configuration
#define APP_SSH_SERVER_NAME "test.rebex.net"
#define APP_SSH_SERVER_PORT 22
#define APP_SSH_USERNAME "demo"
#define APP_SSH_PASSWORD "password"

//List of trusted host keys
const char_t *trustedHostKeys[] =
{
   //Rebex 1024-bit RSA host key
   "ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAAAgQC+6dRUWPl1iar2X3BT51cD0/Hr"
   "lXd3UTuSctj2bvRwJxKRt7iG8H/b5xUjplsbenEzVDHzlz+PliivDMhHd4kv0gFg"
   "Bj4YrAWyau4MR/2ZIbHzPf+S1ma0u9n6cyv8dsYjvRtHj7iAkHmzhMKJBOgJeMrR"
   "clbqlKAz/fSYUQH18w==",

   //Rebex 2048-bit RSA host key
   "ssh-rsa AAAAB3NzaC1yc2EAAAABJQAAAQEAkRM6RxDdi3uAGogR3nsQMpmt43X4"
   "WnwgMzs8VkwUCqikewxqk4U7EyUSOUeT3CoUNOtywrkNbH83e6/yQgzc3M8i/eDz"
   "YtXaNGcKyLfy3Ci6XOwiLLOx1z2AGvvTXln1RXtve+Tn1RTr1BhXVh2cUYbiuVtT"
   "WqbEgErT20n4GWD4wv7FhkDbLXNi8DX07F9v7+jH67i0kyGm+E3rE+SaCMRo3zXE"
   "6VO+ijcm9HdVxfltQwOYLfuPXM2t5aUSfa96KJcA0I4RCMzA/8Dl9hXGfbWdbD2h"
   "K1ZQ1pLvvpNPPyKKjPZcMpOznprbg+jIlsZMWIHt7mq2OJXSdruhRrGzZw==",

   //Rebex NIST P-256 host key
   "ecdsa-sha2-nistp256 AAAAE2VjZHNhLXNoYTItbmlzdHAyNTYAAAAIbmlzdHAy"
   "NTYAAABBBLZcZopPvkxYERubWeSrWOSHpxJdR14WFVES/Q3hFguTn6L+0EANqYcb"
   "RXhGBUV6SjR7SaxZACXSxOzgCtG4kwc=",

   //Rebex Ed25519 host key
   "ssh-ed25519 AAAAC3NzaC1lZDI1NTE5AAAAIOdXzF+Jx/wvEBun5fxi8FQK30mi"
   "LZFND0rxkYwNcYlE"
};

//Global variables
DhcpClientSettings dhcpClientSettings;
DhcpClientContext dhcpClientContext;
SlaacSettings slaacSettings;
SlaacContext slaacContext;
ShellClientContext shellClientContext;
YarrowContext yarrowContext;
uint8_t seed[32];

//Ethernet interrupt service routine
void __ISR(_ETHERNET_VECTOR, IPL1AUTO) ethIrqWrapper(void);


/**
 * @brief System initialization
 **/

void systemInit(void)
{
   //Execute system unlock sequence
   SYSKEY = 0;
   SYSKEY = 0xAA996655;
   SYSKEY = 0x556699AA;

   //Enable MPLL voltage regulator
   CFGMPLLbits.MPLLVREGDIS = 0;
   //Wait for the MPLL voltage regulator to be ready for use
   while(CFGMPLLbits.MPLLVREGRDY == 0)
   {
   }

   //Configure MPLL
   CFGMPLL = (1 << _CFGMPLL_MPLLODIV2_POSITION) |
      (3 << _CFGMPLL_MPLLODIV1_POSITION) |
      (25 << _CFGMPLL_MPLLMULT_POSITION) |
      (1 << _CFGMPLL_MPLLIDIV_POSITION);

   //Wait for the MPLL clock to be stable
   while(CFGMPLLbits.MPLLRDY == 0)
   {
   }

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
   //Configure LED1_R (RC1), LED1_G (RC4)
   TRISCCLR = LED1_R_MASK | LED1_G_MASK;
   //Clear LEDs
   LATCSET = LED1_R_MASK | LED1_G_MASK;
   //Disable analog pads
   ANSELCCLR = LED1_R_MASK | LED1_G_MASK;

   //Configure LED1_B (RB1)
   TRISBCLR = LED1_B_MASK;
   //Clear LED
   LATBSET = LED1_B_MASK;
   //Disable analog pad
   ANSELBCLR = LED1_B_MASK;

   //Configure SW1 (RB11) and SW4 (RB13)
   TRISBSET = SW1_MASK | SW4_MASK;
   //Enable pull-up
   CNPUBSET = SW1_MASK | SW4_MASK;
   //Disable analog pads
   ANSELBCLR = SW1_MASK | SW4_MASK;

   //Configure SW2 (RG15)
   TRISGSET = SW2_MASK;
   //Enable pull-up
   CNPUGSET = SW2_MASK;
   //Disable analog pad
   ANSELGCLR = SW2_MASK;

   //Configure SW3 (RH12)
   TRISHSET = SW3_MASK;
   //Enable pull-up
   CNPUHSET = SW3_MASK;
   //Disable analog pad
   ANSELHCLR = SW3_MASK;
}


/**
 * @brief Server's host key verification callback
 * @param[in] connection Pointer to the SSH connection
 * @param[in] hostKey Pointer to the server's host key
 * @param[in] hostKeyLen Length of the host key, in bytes
 * @return Error code
 **/

error_t shellClientHostKeyVerifyCallback(SshConnection *connection,
   const uint8_t *hostKey, size_t hostKeyLen)
{
   error_t error;
   uint_t i;

   //Debug message
   TRACE_INFO("Shell Client: Public key verification callback\r\n");

   //Initialize status code
   error = ERROR_INVALID_KEY;

   //Loop through the list of known host keys
   for(i = 0; i < arraysize(trustedHostKeys) && error; i++)
   {
      //Check whether the host key is trusted
      error = sshVerifyHostKey(hostKey, hostKeyLen, trustedHostKeys[i],
         strlen(trustedHostKeys[i]));
   }

   //Return status code
   return error;
}


/**
 * @brief SSH initialization callback
 * @param[in] context Pointer to the shell client context
 * @param[in] sshContext Pointer to the SSH context
 * @return Error code
 **/

error_t shellClientSshInitCallback(ShellClientContext *context,
   SshContext *sshContext)
{
   error_t error;

   //Debug message
   TRACE_INFO("Shell Client: SSH initialization callback\r\n");

   //Set the PRNG algorithm to be used
   error = sshSetPrng(sshContext, YARROW_PRNG_ALGO, &yarrowContext);
   //Any error to report?
   if(error)
      return error;

   //Set the user name to be used for authentication
   error = sshSetUsername(sshContext, APP_SSH_USERNAME);
   //Any error to report?
   if(error)
      return error;

   //Set the password to be used for authentication
   error = sshSetPassword(sshContext, APP_SSH_PASSWORD);
   //Any error to report?
   if(error)
      return error;

   //Register host key verification callback function
   error = sshRegisterHostKeyVerifyCallback(sshContext,
      shellClientHostKeyVerifyCallback);
   //Any error to report?
   if(error)
      return error;

   //Successful processing
   return NO_ERROR;
}


/**
 * @brief Shell client test routine
 * @return Error code
 **/

error_t shellClientTest(void)
{
   error_t error;
   size_t n;
   uint32_t exitStatus;
   IpAddr ipAddr;
   char_t buffer[128];

   //Initialize shell client context
   shellClientInit(&shellClientContext);

   //Start of exception handling block
   do
   {
      //Debug message
      TRACE_INFO("\r\n\r\nResolving server name...\r\n");

      //Resolve SSH server name
      error = getHostByName(NULL, APP_SSH_SERVER_NAME, &ipAddr, 0);
      //Any error to report?
      if(error)
      {
         //Debug message
         TRACE_INFO("Failed to resolve server name!\r\n");
         break;
      }

      //Register SSH initialization callback
      error = shellClientRegisterSshInitCallback(&shellClientContext,
         shellClientSshInitCallback);
      //Any error to report?
      if(error)
         break;

      //Set timeout value for blocking operations
      error = shellClientSetTimeout(&shellClientContext, 20000);
      //Any error to report?
      if(error)
         break;

      //Debug message
      TRACE_INFO("Connecting to SSH server %s...\r\n",
         ipAddrToString(&ipAddr, NULL));

      //Connect to the SSH server
      error = shellClientConnect(&shellClientContext, &ipAddr,
         APP_SSH_SERVER_PORT);
      //Any error to report?
      if(error)
      {
         //Debug message
         TRACE_INFO("Failed to connect to SSH server!\r\n");
         break;
      }

      //Execute command line
      error = shellClientExecuteCommand(&shellClientContext, "ls -a");
      //Any error to report?
      if(error)
         break;

      //Read command output stream
      while(!error)
      {
         //Read data from output stream
         error = shellClientReadStream(&shellClientContext, buffer,
            sizeof(buffer) - 1, &n, 0);

         //Check status code
         if(!error)
         {
            //Properly terminate the string with a NULL character
            buffer[n] = '\0';
            //Dump output stream
            TRACE_INFO("%s", buffer);
         }
      }

      //Terminate the string with a line feed
      TRACE_INFO("\r\n");

      //Any error to report?
      if(error != ERROR_END_OF_STREAM)
         break;

      //Close stream
      error = shellClientCloseStream(&shellClientContext);
      //Any error to report?
      if(error)
         break;

      //Retrieve the exit status of the command
      exitStatus = shellClientGetExitStatus(&shellClientContext);
      //Debug message
      TRACE_INFO("Command exit status: %" PRIu32 "\r\n", exitStatus);

      //Gracefully disconnect from the SSH server
      shellClientDisconnect(&shellClientContext);

      //Debug message
      TRACE_INFO("Connection closed\r\n");

      //End of exception handling block
   } while(0);

   //Release shell client context
   shellClientDeinit(&shellClientContext);

   //Return status code
   return error;
}


/**
 * @brief User task
 * @param[in] param Unused parameter
 **/

void userTask(void *param)
{
   //Endless loop
   while(1)
   {
      //SW1 button pressed?
      if(!(PORTB & SW1_MASK))
      {
         //Shell client test routine
         shellClientTest();

         //Wait for the SW1 button to be released
         while(!(PORTB & SW1_MASK));
      }

      //Loop delay
      osDelayTask(100);
   }
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
      LATCCLR = LED1_G_MASK;
      osDelayTask(100);
      LATCSET = LED1_G_MASK;
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
   TRACE_INFO("*** CycloneSSH SSH Client Demo ***\r\n");
   TRACE_INFO("**********************************\r\n");
   TRACE_INFO("Copyright: 2010-2024 Oryx Embedded SARL\r\n");
   TRACE_INFO("Compiled: %s %s\r\n", __DATE__, __TIME__);
   TRACE_INFO("Target: PIC32MZ2064DAR176\r\n");
   TRACE_INFO("\r\n");

   //Configure I/Os
   ioInit();

   //Generate a random seed

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
   netSetDriver(interface, &pic32mzEthDriver);
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

   //Set task parameters
   taskParams = OS_TASK_DEFAULT_PARAMS;
   taskParams.stackSize = 750;
   taskParams.priority = OS_TASK_PRIORITY_NORMAL;

   //Create user task
   taskId = osCreateTask("User", userTask, NULL, &taskParams);
   //Failed to create the task?
   if(taskId == OS_INVALID_TASK_ID)
   {
      //Debug message
      TRACE_ERROR("Failed to create task!\r\n");
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
