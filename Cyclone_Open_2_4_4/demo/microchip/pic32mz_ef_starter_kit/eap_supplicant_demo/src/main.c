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
#include "pic32mz_ef_starter_kit.h"
#include "core/net.h"
#include "drivers/mac/pic32mz_eth_driver.h"
#include "drivers/phy/lan8740_driver.h"
#include "supplicant/supplicant.h"
#include "dhcp/dhcp_client.h"
#include "ipv6/slaac.h"
#include "hardware/pic32mz/pic32mz_crypto.h"
#include "rng/trng.h"
#include "rng/yarrow.h"
#include "resource_manager.h"
#include "debug.h"

//Configuration bits
#pragma config USERID = 0xFFFF
#pragma config FMIIEN = OFF
#pragma config FETHIO = ON
#pragma config PGL1WAY = OFF
#pragma config PMDL1WAY = OFF
#pragma config IOL1WAY = OFF
#pragma config FUSBIDIO = OFF
#pragma config FPLLIDIV = DIV_3
#pragma config FPLLRNG = RANGE_5_10_MHZ
#pragma config FPLLICLK = PLL_POSC
#pragma config FPLLMULT = MUL_50
#pragma config FPLLODIV = DIV_2
#pragma config UPLLFSEL = FREQ_24MHZ
#pragma config FNOSC = SPLL
#pragma config DMTINTV = WIN_127_128
#pragma config FSOSCEN = OFF
#pragma config IESO = OFF
#pragma config POSCMOD = EC
#pragma config OSCIOFNC = OFF
#pragma config FCKSM = CSECMD
#pragma config WDTPS = PS1048576
#pragma config WDTSPGM = STOP
#pragma config WINDIS= NORMAL
#pragma config FWDTEN = OFF
#pragma config FWDTWINSZ = WINSZ_25
#pragma config DMTCNT = DMT31
#pragma config FDMTEN = OFF
//#pragma config DEBUG = ON
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
#pragma config EJTAGBEN = NORMAL
#pragma config CP = OFF

//Ethernet interface configuration
#define APP_IF_NAME "eth0"
#define APP_HOST_NAME "eap-supplicant-demo"
#define APP_USE_DEFAULT_MAC_ADDR ENABLED
#define APP_MAC_ADDR "00-AB-CD-EF-20-48"

#define APP_USE_DHCP_CLIENT ENABLED
#define APP_IPV4_HOST_ADDR "192.168.0.20"
#define APP_IPV4_SUBNET_MASK "255.255.255.0"
#define APP_IPV4_DEFAULT_GATEWAY "192.168.0.254"
#define APP_IPV4_PRIMARY_DNS "8.8.8.8"
#define APP_IPV4_SECONDARY_DNS "8.8.4.4"

#define APP_USE_SLAAC ENABLED
#define APP_IPV6_LINK_LOCAL_ADDR "fe80::2048"
#define APP_IPV6_PREFIX "2001:db8::"
#define APP_IPV6_PREFIX_LENGTH 64
#define APP_IPV6_GLOBAL_ADDR "2001:db8::2048"
#define APP_IPV6_ROUTER "fe80::1"
#define APP_IPV6_PRIMARY_DNS "2001:4860:4860::8888"
#define APP_IPV6_SECONDARY_DNS "2001:4860:4860::8844"

//802.1X supplicant configuration
#define APP_SUPPLICANT_IDENTITY "user@example.org"
#define APP_SUPPLICANT_PASSWORD ""
#define APP_SUPPLICANT_CERT "/certs/supplicant_cert.pem"
#define APP_SUPPLICANT_KEY "/certs/supplicant_key.pem"
#define APP_SUPPLICANT_KEY_PASSWORD ""
#define APP_SUPPLICANT_CA_CERT_BUNDLE "/certs/ca_cert.pem"

//Global variables
SupplicantSettings supplicantSettings;
SupplicantContext supplicantContext;
DhcpClientSettings dhcpClientSettings;
DhcpClientContext dhcpClientContext;
SlaacSettings slaacSettings;
SlaacContext slaacContext;
YarrowContext yarrowContext;
uint8_t seed[32];

//Forward declaration of functions
error_t supplicantTlsInitCallback(SupplicantContext *context,
   TlsContext *tlsContext);

void supplicantPaeStateChangeCallback(SupplicantContext *context,
   SupplicantPaeState state);

//Ethernet interrupt service routine
void __ISR(_ETHERNET_VECTOR, IPL1AUTO) ethIrqWrapper(void);


/**
 * @brief System initialization
 **/

void systemInit(void)
{
   //Execute system unlock sequence
   SYSKEY = 0xAA996655;
   SYSKEY = 0x556699AA;

   //Check PBDIVRDY bit
   while(!(PB2DIV & _PB2DIV_PBDIVRDY_MASK));
   //Configure PBCLK2 clock divisor (SYSCLK / 5);
   PB2DIV = _PB2DIV_ON_MASK | 4;

   //Check PBDIVRDY bit
   while(!(PB3DIV & _PB3DIV_PBDIVRDY_MASK));
   //Configure PBCLK3 clock divisor (SYSCLK / 5);
   PB3DIV = _PB3DIV_ON_MASK | 4;

   //Check PBDIVRDY bit
   while(!(PB4DIV & _PB4DIV_PBDIVRDY_MASK));
   //Configure PBCLK4 clock divisor (SYSCLK / 1);
   PB4DIV = _PB4DIV_ON_MASK | 0;

   //Check PBDIVRDY bit
   while(!(PB5DIV & _PB5DIV_PBDIVRDY_MASK));
   //Configure PBCLK5 clock divisor (SYSCLK / 2);
   PB5DIV = _PB5DIV_ON_MASK | 1;

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
   //Configure LED1 (RH0), LED2 (RH1) and LED3 (RH2)
   TRISHCLR = LED1_MASK | LED2_MASK | LED3_MASK;
   //Clear LEDs
   LATHCLR = LED1_MASK | LED2_MASK | LED3_MASK;
   //Disable analog pads
   ANSELHCLR = LED1_MASK | LED2_MASK | LED3_MASK;

   //Configure SW1 (RB12), SW2 (RB13) and SW3 (RB14)
   TRISBSET = SW1_MASK | SW2_MASK | SW3_MASK;
   //Enable pull-ups
   CNPUBSET = SW1_MASK | SW2_MASK | SW3_MASK;
   //Disable analog pads
   ANSELBCLR = SW1_MASK | SW2_MASK | SW3_MASK;
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
      LATHSET = LED1_MASK;
      osDelayTask(100);
      LATHCLR = LED1_MASK;
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
   TRACE_INFO("*****************************************\r\n");
   TRACE_INFO("*** CycloneEAP 802.1X Supplicant Demo ***\r\n");
   TRACE_INFO("*****************************************\r\n");
   TRACE_INFO("Copyright: 2010-2024 Oryx Embedded SARL\r\n");
   TRACE_INFO("Compiled: %s %s\r\n", __DATE__, __TIME__);
   TRACE_INFO("Target: PIC32MZ2048EFM144\r\n");
   TRACE_INFO("\r\n");

   //Configure I/Os
   ioInit();

   //Initialize hardware cryptographic accelerator
   error = pic32mzCryptoInit();
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
   supplicantGetDefaultSettings(&supplicantSettings);
   //Bind 802.1X supplicant to the desired interface
   supplicantSettings.interface = interface;
   //Supplicant PAE state change callback function
   supplicantSettings.paeStateChangeCallback = supplicantPaeStateChangeCallback;
   //TLS initialization callback function (only for EAP-TLS)
   supplicantSettings.tlsInitCallback = supplicantTlsInitCallback;

   //802.1X supplicant initialization
   error = supplicantInit(&supplicantContext, &supplicantSettings);
   //Failed to initialize 802.1X supplicant?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize 802.1X supplicant!\r\n");
   }

   //Set user name
   error = supplicantSetUsername(&supplicantContext, APP_SUPPLICANT_IDENTITY);
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to set username!\r\n");
   }

   //Set password (only for EAP-MD5)
   error = supplicantSetPassword(&supplicantContext, APP_SUPPLICANT_PASSWORD);
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to set password!\r\n");
   }

   //Start 802.1X supplicant
   error = supplicantStart(&supplicantContext);
   //Failed to start 802.1X supplicant?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start 802.1X supplicant!\r\n");
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
 * @brief TLS initialization callback
 * @param[in] context Pointer to the 802.1X supplicant context
 * @param[in] tlsContext Pointer to the TLS context
 * @return Error code
 **/

error_t supplicantTlsInitCallback(SupplicantContext *context,
   TlsContext *tlsContext)
{
   error_t error;
   const char_t *clientCert;
   size_t clientCertLen;
   const char_t *clientPrivateKey;
   size_t clientPrivateKeyLen;
   const char_t *trustedCaList;
   size_t trustedCaListLen;

   //Debug message
   TRACE_INFO("802.1X Supplicant: TLS initialization callback\r\n");

   //Set TX and RX buffer size
   error = tlsSetBufferSize(tlsContext, 3072, 3072);
   //Any error to report?
   if(error)
      return error;

   //Set the PRNG algorithm to be used
   error = tlsSetPrng(tlsContext, YARROW_PRNG_ALGO, &yarrowContext);
   //Any error to report?
   if(error)
      return error;

   //Get supplicant's certificate
   error = resGetData(APP_SUPPLICANT_CERT,
      (const uint8_t **) &clientCert, &clientCertLen);
   //Any error to report?
   if(error)
      return error;

   //Get supplicant's private key
   error = resGetData(APP_SUPPLICANT_KEY,
      (const uint8_t **) &clientPrivateKey, &clientPrivateKeyLen);
   //Any error to report?
   if(error)
      return error;

   //Load supplicant's certificate
   error = tlsLoadCertificate(tlsContext, 0, clientCert, clientCertLen,
      clientPrivateKey, clientPrivateKeyLen, APP_SUPPLICANT_KEY_PASSWORD);
   //Any error to report?
   if(error)
      return error;

   //Get the list of trusted CA certificates
   error = resGetData(APP_SUPPLICANT_CA_CERT_BUNDLE,
      (const uint8_t **) &trustedCaList, &trustedCaListLen);
   //Any error to report?
   if(error)
      return error;

   //Import the list of trusted CA certificates
   error = tlsSetTrustedCaList(tlsContext, trustedCaList, trustedCaListLen);
   //Any error to report?
   if(error)
      return error;

   //Successful processing
   return NO_ERROR;
}


/**
 * @brief Supplicant PAE state change callback function
 * @param[in] context Pointer to the 802.1X supplicant context
 * @param[in] state Supplicant PAE state
 **/

void supplicantPaeStateChangeCallback(SupplicantContext *context,
   SupplicantPaeState state)
{
   //Check current state
   if(state == SUPPLICANT_PAE_STATE_LOGOFF)
   {
      TRACE_INFO("\r\n");
      TRACE_INFO("**************\r\n");
      TRACE_INFO("*** LOGOFF ***\r\n");
      TRACE_INFO("**************\r\n");
      TRACE_INFO("\r\n");
   }
   else if(state == SUPPLICANT_PAE_STATE_DISCONNECTED)
   {
      TRACE_INFO("\r\n");
      TRACE_INFO("**********************\r\n");
      TRACE_INFO("*** DISCONNECTED ***\r\n");
      TRACE_INFO("**********************\r\n");
      TRACE_INFO("\r\n");
   }
   else if(state == SUPPLICANT_PAE_STATE_CONNECTING)
   {
      TRACE_INFO("\r\n");
      TRACE_INFO("******************\r\n");
      TRACE_INFO("*** CONNECTING ***\r\n");
      TRACE_INFO("******************\r\n");
      TRACE_INFO("\r\n");
   }
   else if(state == SUPPLICANT_PAE_STATE_AUTHENTICATING)
   {
      TRACE_INFO("\r\n");
      TRACE_INFO("**********************\r\n");
      TRACE_INFO("*** AUTHENTICATING ***\r\n");
      TRACE_INFO("**********************\r\n");
      TRACE_INFO("\r\n");
   }
   else if(state == SUPPLICANT_PAE_STATE_AUTHENTICATED)
   {
      TRACE_INFO("\r\n");
      TRACE_INFO("*********************\r\n");
      TRACE_INFO("*** AUTHENTICATED ***\r\n");
      TRACE_INFO("*********************\r\n");
      TRACE_INFO("\r\n");
   }
   else if(state == SUPPLICANT_PAE_STATE_HELD)
   {
      TRACE_INFO("\r\n");
      TRACE_INFO("************\r\n");
      TRACE_INFO("*** HELD ***\r\n");
      TRACE_INFO("************\r\n");
      TRACE_INFO("\r\n");
   }
   else if(state == SUPPLICANT_PAE_STATE_RESTART)
   {
      TRACE_INFO("\r\n");
      TRACE_INFO("***************\r\n");
      TRACE_INFO("*** RESTART ***\r\n");
      TRACE_INFO("***************\r\n");
      TRACE_INFO("\r\n");
   }
   else if(state == SUPPLICANT_PAE_STATE_S_FORCE_AUTH)
   {
      TRACE_INFO("\r\n");
      TRACE_INFO("********************\r\n");
      TRACE_INFO("*** S_FORCE_AUTH ***\r\n");
      TRACE_INFO("********************\r\n");
      TRACE_INFO("\r\n");
   }
   else if(state == SUPPLICANT_PAE_STATE_S_FORCE_UNAUTH)
   {
      TRACE_INFO("\r\n");
      TRACE_INFO("**********************\r\n");
      TRACE_INFO("*** S_FORCE_UNAUTH ***\r\n");
      TRACE_INFO("**********************\r\n");
      TRACE_INFO("\r\n");
   }
   else
   {
   }
}
