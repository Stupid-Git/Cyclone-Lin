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
#include "fsl_device_registers.h"
#include "fsl_gpio.h"
#include "fsl_port.h"
#include "board.h"
#include "core/net.h"
#include "drivers/mac/mcxn547_eth_driver.h"
#include "drivers/phy/lan8741_driver.h"
#include "supplicant/supplicant.h"
#include "dhcp/dhcp_client.h"
#include "ipv6/slaac.h"
#include "rng/yarrow.h"
#include "resource_manager.h"
#include "debug.h"

//Ethernet interface configuration
#define APP_IF_NAME "eth0"
#define APP_HOST_NAME "eap-supplicant-demo"
#define APP_MAC_ADDR "00-AB-CD-EF-05-47"

#define APP_USE_DHCP_CLIENT ENABLED
#define APP_IPV4_HOST_ADDR "192.168.0.20"
#define APP_IPV4_SUBNET_MASK "255.255.255.0"
#define APP_IPV4_DEFAULT_GATEWAY "192.168.0.254"
#define APP_IPV4_PRIMARY_DNS "8.8.8.8"
#define APP_IPV4_SECONDARY_DNS "8.8.4.4"

#define APP_USE_SLAAC ENABLED
#define APP_IPV6_LINK_LOCAL_ADDR "fe80::547"
#define APP_IPV6_PREFIX "2001:db8::"
#define APP_IPV6_PREFIX_LENGTH 64
#define APP_IPV6_GLOBAL_ADDR "2001:db8::547"
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


/**
 * @brief I/O initialization
 **/

void ioInit(void)
{
   port_pin_config_t portPinConfig;
   gpio_pin_config_t gpioPinConfig;

   //Enable PORT clocks
   CLOCK_EnableClock(kCLOCK_Port0);
   CLOCK_EnableClock(kCLOCK_Port1);

   //Enable GPIO clocks
   CLOCK_EnableClock(kCLOCK_Gpio0);
   CLOCK_EnableClock(kCLOCK_Gpio1);

   //Initialize port pin attributes
   portPinConfig.pullSelect = kPORT_PullUp;
   portPinConfig.pullValueSelect = kPORT_LowPullResistor;
   portPinConfig.slewRate = kPORT_SlowSlewRate;
   portPinConfig.passiveFilterEnable = kPORT_PassiveFilterDisable;
   portPinConfig.openDrainEnable = kPORT_OpenDrainDisable;
   portPinConfig.driveStrength = kPORT_LowDriveStrength;
   portPinConfig.mux = kPORT_MuxAlt0;
   portPinConfig.inputBuffer = kPORT_InputBufferEnable;
   portPinConfig.invertInput = kPORT_InputNormal;
   portPinConfig.lockRegister = kPORT_UnlockRegister;

   //Configure PORT0_6 as PIO0_6
   PORT_SetPinConfig(PORT0, 6, &portPinConfig);
   //Configure PORT0_29 as PIO0_29
   PORT_SetPinConfig(PORT0, 29, &portPinConfig);
   //Configure PORT1_3 as PIO1_3
   PORT_SetPinConfig(PORT1, 3, &portPinConfig);

   //Configure LEDs as outputs
   gpioPinConfig.pinDirection = kGPIO_DigitalOutput;
   gpioPinConfig.outputLogic = 1;
   GPIO_PinInit(BOARD_LED_RED_GPIO, BOARD_LED_RED_GPIO_PIN, &gpioPinConfig);
   GPIO_PinInit(BOARD_LED_GREEN_GPIO, BOARD_LED_GREEN_GPIO_PIN, &gpioPinConfig);
   GPIO_PinInit(BOARD_LED_BLUE_GPIO, BOARD_LED_BLUE_GPIO_PIN, &gpioPinConfig);

   //Configure SW2, SW3 and SW4 as inputs
   gpioPinConfig.pinDirection = kGPIO_DigitalInput;
   GPIO_PinInit(BOARD_SW2_GPIO, BOARD_SW2_GPIO_PIN, &gpioPinConfig);
   GPIO_PinInit(BOARD_SW3_GPIO, BOARD_SW3_GPIO_PIN, &gpioPinConfig);
   GPIO_PinInit(BOARD_SW4_GPIO, BOARD_SW4_GPIO_PIN, &gpioPinConfig);
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
      GPIO_PinWrite(BOARD_LED_GREEN_GPIO, BOARD_LED_GREEN_GPIO_PIN, 0);
      osDelayTask(100);
      GPIO_PinWrite(BOARD_LED_GREEN_GPIO, BOARD_LED_GREEN_GPIO_PIN, 1);
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

   //Configure the system clock
   BOARD_InitBootClocks();

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
   TRACE_INFO("Target: MCX N547\r\n");
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
   //Set host MAC address
   macStringToAddr(APP_MAC_ADDR, &macAddr);
   netSetMacAddr(interface, &macAddr);
   //Select the relevant network adapter
   netSetDriver(interface, &mcxn547EthDriver);
   netSetPhyDriver(interface, &lan8741PhyDriver);

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
