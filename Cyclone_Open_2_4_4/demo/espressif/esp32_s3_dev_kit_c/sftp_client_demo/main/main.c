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
#include "esp_wifi.h"
#include "esp_event.h"
#include "nvs_flash.h"
#include "driver/gpio.h"
#include "rom/gpio.h"
#include "core/net.h"
#include "drivers/wifi/esp32_wifi_driver.h"
#include "dhcp/dhcp_client.h"
#include "ipv6/slaac.h"
#include "sftp/sftp_client.h"
#include "ssh/ssh_key_verify.h"
#include "hardware/esp32_s3/esp32_s3_crypto.h"
#include "rng/trng.h"
#include "rng/yarrow.h"
#include "led_strip.h"
#include "debug.h"

//First Wi-Fi interface (STA mode) configuration
#define APP_IF0_NAME "wlan0"
#define APP_IF0_HOST_NAME "sftp-client-demo"
#define APP_IF0_MAC_ADDR "00-00-00-00-00-00"

#define APP_IF0_USE_DHCP_CLIENT ENABLED
#define APP_IF0_IPV4_HOST_ADDR "192.168.0.20"
#define APP_IF0_IPV4_SUBNET_MASK "255.255.255.0"
#define APP_IF0_IPV4_DEFAULT_GATEWAY "192.168.0.254"
#define APP_IF0_IPV4_PRIMARY_DNS "8.8.8.8"
#define APP_IF0_IPV4_SECONDARY_DNS "8.8.4.4"

#define APP_IF0_USE_SLAAC ENABLED
#define APP_IF0_IPV6_LINK_LOCAL_ADDR "fe80::32:1"

//Second Wi-Fi interface (AP mode) configuration
#define APP_IF1_NAME "wlan1"
#define APP_IF1_HOST_NAME "sftp-client-demo"
#define APP_IF1_MAC_ADDR "00-00-00-00-00-00"

#define APP_IF1_USE_DHCP_SERVER ENABLED
#define APP_IF1_IPV4_HOST_ADDR "192.168.8.1"
#define APP_IF1_IPV4_SUBNET_MASK "255.255.255.0"
#define APP_IF1_IPV4_DEFAULT_GATEWAY "0.0.0.0"
#define APP_IF1_IPV4_PRIMARY_DNS "0.0.0.0"
#define APP_IF1_IPV4_SECONDARY_DNS "0.0.0.0"
#define APP_IF1_IPV4_ADDR_RANGE_MIN "192.168.8.10"
#define APP_IF1_IPV4_ADDR_RANGE_MAX "192.168.8.99"

#define APP_IF1_USE_ROUTER_ADV ENABLED
#define APP_IF1_IPV6_LINK_LOCAL_ADDR "fe80::32:2"
#define APP_IF1_IPV6_PREFIX "fd00:1:2:3::"
#define APP_IF1_IPV6_PREFIX_LENGTH 64
#define APP_IF1_IPV6_GLOBAL_ADDR "fd00:1:2:3::32:2"

//Wi-Fi parameters (STA mode)
#define APP_WIFI_STA_SSID "TEST_ESP32_STA"
#define APP_WIFI_STA_PASSWORD "12345678"

//Wi-Fi parameters (AP mode)
#define APP_WIFI_AP_SSID "TEST_ESP32_AP"
#define APP_WIFI_AP_PASSWORD "1122334455"

//Application configuration
#define APP_SFTP_SERVER_NAME "test.rebex.net"
#define APP_SFTP_SERVER_PORT 22
#define APP_SFTP_USERNAME "demo"
#define APP_SFTP_PASSWORD "password"
#define APP_SFTP_FILENAME "readme.txt"

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
led_strip_t *ledStrip;
DhcpClientSettings dhcpClientSettings;
DhcpClientContext dhcpClientContext;
DhcpServerSettings dhcpServerSettings;
DhcpServerContext dhcpServerContext;
SlaacSettings slaacSettings;
SlaacContext slaacContext;
NdpRouterAdvSettings ndpRouterAdvSettings;
NdpRouterAdvPrefixInfo ndpRouterAdvPrefixInfo[1];
NdpRouterAdvContext ndpRouterAdvContext;
SftpClientContext sftpClientContext;
YarrowContext yarrowContext;
uint8_t seed[32];

//Forward declaration of functions
error_t wifiStaInterfaceInit(void);
error_t wifiApInterfaceInit(void);

esp_err_t wifiConnect(void);
esp_err_t wifiEnableAp(void);

void wifiEventHandler(void *arg, esp_event_base_t eventBase,
   int32_t eventId, void *eventData);


/**
 * @brief I/O initialization
 **/

void ioInit(void)
{
   //Configure RGB LED (GPIO48)
   ledStrip = led_strip_init(0, 48, 1);
   //Clear RGB LED
   ledStrip->clear(ledStrip, 10);

   //Configure user button (GPIO0)
   gpio_pad_select_gpio(0);
   gpio_set_direction(0, GPIO_MODE_INPUT);
}


/**
 * @brief Server's host key verification callback
 * @param[in] connection Pointer to the SSH connection
 * @param[in] hostKey Pointer to the server's host key
 * @param[in] hostKeyLen Length of the host key, in bytes
 * @return Error code
 **/

error_t sftpClientHostKeyVerifyCallback(SshConnection *connection,
   const uint8_t *hostKey, size_t hostKeyLen)
{
   error_t error;
   uint_t i;

   //Debug message
   TRACE_INFO("SFTP Client: Public key verification callback\r\n");

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
 * @param[in] context Pointer to the SFTP client context
 * @param[in] sshContext Pointer to the SSH context
 * @return Error code
 **/

error_t sftpClientSshInitCallback(SftpClientContext *context,
   SshContext *sshContext)
{
   error_t error;

   //Debug message
   TRACE_INFO("SFTP Client: SSH initialization callback\r\n");

   //Set the PRNG algorithm to be used
   error = sshSetPrng(sshContext, YARROW_PRNG_ALGO, &yarrowContext);
   //Any error to report?
   if(error)
      return error;

   //Set the user name to be used for authentication
   error = sshSetUsername(sshContext, APP_SFTP_USERNAME);
   //Any error to report?
   if(error)
      return error;

   //Set the password to be used for authentication
   error = sshSetPassword(sshContext, APP_SFTP_PASSWORD);
   //Any error to report?
   if(error)
      return error;

   //Register host key verification callback function
   error = sshRegisterHostKeyVerifyCallback(sshContext,
      sftpClientHostKeyVerifyCallback);
   //Any error to report?
   if(error)
      return error;

   //Successful processing
   return NO_ERROR;
}


/**
 * @brief SFTP client test routine
 * @return Error code
 **/

error_t sftpClientTest(void)
{
   error_t error;
   size_t n;
   IpAddr ipAddr;
   char_t buffer[128];

   //Initialize SFTP client context
   sftpClientInit(&sftpClientContext);

   //Start of exception handling block
   do
   {
      //Debug message
      TRACE_INFO("\r\n\r\nResolving server name...\r\n");

      //Resolve SFTP server name
      error = getHostByName(NULL, APP_SFTP_SERVER_NAME, &ipAddr, 0);
      //Any error to report?
      if(error)
      {
         //Debug message
         TRACE_INFO("Failed to resolve server name!\r\n");
         break;
      }

      //Register SSH initialization callback
      error = sftpClientRegisterSshInitCallback(&sftpClientContext,
         sftpClientSshInitCallback);
      //Any error to report?
      if(error)
         break;

      //Set timeout value for blocking operations
      error = sftpClientSetTimeout(&sftpClientContext, 20000);
      //Any error to report?
      if(error)
         break;

      //Debug message
      TRACE_INFO("Connecting to SFTP server %s...\r\n",
         ipAddrToString(&ipAddr, NULL));

      //Connect to the SFTP server
      error = sftpClientConnect(&sftpClientContext, &ipAddr,
         APP_SFTP_SERVER_PORT);
      //Any error to report?
      if(error)
      {
         //Debug message
         TRACE_INFO("Failed to connect to SFTP server!\r\n");
         break;
      }

      //Open the specified file for reading
      error = sftpClientOpenFile(&sftpClientContext, APP_SFTP_FILENAME,
         SSH_FXF_READ);
      //Any error to report?
      if(error)
         break;

      //Read the contents of the file
      while(!error)
      {
         //Read data
         error = sftpClientReadFile(&sftpClientContext, buffer,
            sizeof(buffer) - 1, &n, 0);

         //Check status code
         if(!error)
         {
            //Properly terminate the string with a NULL character
            buffer[n] = '\0';
            //Dump the contents of the file
            TRACE_INFO("%s", buffer);
         }
      }

      //Terminate the string with a line feed
      TRACE_INFO("\r\n");

      //Any error to report?
      if(error != ERROR_END_OF_STREAM)
         break;

      //Close file
      error = sftpClientCloseFile(&sftpClientContext);
      //Any error to report?
      if(error)
         break;

      //Gracefully disconnect from the SFTP server
      sftpClientDisconnect(&sftpClientContext);

      //Debug message
      TRACE_INFO("Connection closed\r\n");

      //End of exception handling block
   } while(0);

   //Release SFTP client context
   sftpClientDeinit(&sftpClientContext);

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
      //User button pressed?
      if(!gpio_get_level(0))
      {
         //SFTP client test routine
         sftpClientTest();

         //Wait for the user button to be released
         while(!gpio_get_level(0));
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
      //Set green LED
      ledStrip->set_pixel(ledStrip, 0, 0, 16, 0);
      ledStrip->refresh(ledStrip, 10);
      osDelayTask(100);

      //Clear RGB LED
      ledStrip->clear(ledStrip, 10);
      osDelayTask(900);
   }
}


/**
 * @brief Main entry point
 **/

void app_main(void)
{
   esp_err_t ret;
   error_t error;
   OsTaskId taskId;
   OsTaskParameters taskParams;

   //Start-up message
   TRACE_INFO("\r\n");
   TRACE_INFO("***********************************\r\n");
   TRACE_INFO("*** CycloneSSH SFTP Client Demo ***\r\n");
   TRACE_INFO("***********************************\r\n");
   TRACE_INFO("Copyright: 2010-2024 Oryx Embedded SARL\r\n");
   TRACE_INFO("Compiled: %s %s\r\n", __DATE__, __TIME__);
   TRACE_INFO("Target: ESP32-S3\r\n");
   TRACE_INFO("\r\n");

   //Configure I/Os
   ioInit();

   //Initialize NVS memory
   ret = nvs_flash_init();

   //Check status code
   if(ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
   {
      ret = nvs_flash_erase();

      if(ret == ESP_OK)
      {
         ret = nvs_flash_init();
      }
   }

   //Failed to initialize NVS memory?
   if(ret != ESP_OK)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize NVS memory!\r\n");
   }

   //Create default event loop
   esp_event_loop_create_default();

   //Register Wi-Fi event handler
   esp_event_handler_register(WIFI_EVENT, ESP_EVENT_ANY_ID,
      wifiEventHandler, NULL);

   //Initialize hardware cryptographic accelerator
   error = esp32s3CryptoInit();
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

   //Configure the first network interface (Wi-Fi STA mode)
   wifiStaInterfaceInit();

   //Configure the second network interface (Wi-Fi AP mode)
   wifiApInterfaceInit();

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
   taskParams.stackSize = 250;
   taskParams.priority = OS_TASK_PRIORITY_NORMAL;

   //Create a task to blink the LED
   taskId = osCreateTask("LED", ledTask, NULL, &taskParams);
   //Failed to create the task?
   if(taskId == OS_INVALID_TASK_ID)
   {
      //Debug message
      TRACE_ERROR("Failed to create task!\r\n");
   }

   //Connect to Wi-Fi network (STA mode)
   wifiConnect();
}


/**
 * @brief Wi-Fi STA interface initialization
 **/

error_t wifiStaInterfaceInit(void)
{
   error_t error;
   NetInterface *interface;
   MacAddr macAddr;
#if (APP_IF0_USE_DHCP_CLIENT == DISABLED)
   Ipv4Addr ipv4Addr;
#endif
#if (APP_IF0_USE_SLAAC == DISABLED)
   Ipv6Addr ipv6Addr;
#endif

   //Configure the first network interface (Wi-Fi STA mode)
   interface = &netInterface[0];

   //Set interface name
   netSetInterfaceName(interface, APP_IF0_NAME);
   //Set host name
   netSetHostname(interface, APP_IF0_HOST_NAME);
   //Set host MAC address
   macStringToAddr(APP_IF0_MAC_ADDR, &macAddr);
   netSetMacAddr(interface, &macAddr);
   //Select the relevant network adapter
   netSetDriver(interface, &esp32WifiStaDriver);

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
#if (APP_IF0_USE_DHCP_CLIENT == ENABLED)
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
      //Exit immediately
      return error;
   }

   //Start DHCP client
   error = dhcpClientStart(&dhcpClientContext);
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
   error = slaacInit(&slaacContext, &slaacSettings);
   //Failed to initialize SLAAC?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize SLAAC!\r\n");
      //Exit immediately
      return error;
   }

   //Start IPv6 address autoconfiguration process
   error = slaacStart(&slaacContext);
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
   ipv6StringToAddr(APP_IF0_IPV6_LINK_LOCAL_ADDR, &ipv6Addr);
   ipv6SetLinkLocalAddr(interface, &ipv6Addr);
#endif
#endif

   //Successful initialization
   return NO_ERROR;
}


/**
 * @brief Wi-Fi AP interface initialization
 **/

error_t wifiApInterfaceInit(void)
{
   error_t error;
   NetInterface *interface;
   MacAddr macAddr;
   Ipv4Addr ipv4Addr;
   Ipv6Addr ipv6Addr;

   //Configure the second network interface (Wi-Fi AP mode)
   interface = &netInterface[1];

   //Set interface name
   netSetInterfaceName(interface, APP_IF1_NAME);
   //Set host name
   netSetHostname(interface, APP_IF1_HOST_NAME);
   //Set host MAC address
   macStringToAddr(APP_IF1_MAC_ADDR, &macAddr);
   netSetMacAddr(interface, &macAddr);
   //Select the relevant network adapter
   netSetDriver(interface, &esp32WifiApDriver);

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

#if (APP_IF1_USE_DHCP_SERVER == ENABLED)
   //Get default settings
   dhcpServerGetDefaultSettings(&dhcpServerSettings);
   //Set the network interface to be configured by DHCP
   dhcpServerSettings.interface = interface;
   //Lease time, in seconds, assigned to the DHCP clients
   dhcpServerSettings.leaseTime = 3600;

   //Lowest and highest IP addresses in the pool that are available
   //for dynamic address assignment
   ipv4StringToAddr(APP_IF1_IPV4_ADDR_RANGE_MIN, &dhcpServerSettings.ipAddrRangeMin);
   ipv4StringToAddr(APP_IF1_IPV4_ADDR_RANGE_MAX, &dhcpServerSettings.ipAddrRangeMax);

   //Subnet mask
   ipv4StringToAddr(APP_IF1_IPV4_SUBNET_MASK, &dhcpServerSettings.subnetMask);
   //Default gateway
   ipv4StringToAddr(APP_IF1_IPV4_DEFAULT_GATEWAY, &dhcpServerSettings.defaultGateway);
   //DNS servers
   ipv4StringToAddr(APP_IF1_IPV4_PRIMARY_DNS, &dhcpServerSettings.dnsServer[0]);
   ipv4StringToAddr(APP_IF1_IPV4_SECONDARY_DNS, &dhcpServerSettings.dnsServer[1]);

   //DHCP server initialization
   error = dhcpServerInit(&dhcpServerContext, &dhcpServerSettings);
   //Failed to initialize DHCP client?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize DHCP server!\r\n");
      //Exit immediately
      return error;
   }

   //Start DHCP server
   error = dhcpServerStart(&dhcpServerContext);
   //Failed to start DHCP client?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start DHCP server!\r\n");
      //Exit immediately
      return error;
   }
#endif
#endif

#if (IPV6_SUPPORT == ENABLED)
   //Set link-local address
   ipv6StringToAddr(APP_IF1_IPV6_LINK_LOCAL_ADDR, &ipv6Addr);
   ipv6SetLinkLocalAddr(interface, &ipv6Addr);

   //Set IPv6 prefix
   ipv6StringToAddr(APP_IF1_IPV6_PREFIX, &ipv6Addr);
   ipv6SetPrefix(interface, 0, &ipv6Addr, APP_IF1_IPV6_PREFIX_LENGTH);

   //Set global address
   ipv6StringToAddr(APP_IF1_IPV6_GLOBAL_ADDR, &ipv6Addr);
   ipv6SetGlobalAddr(interface, 0, &ipv6Addr);

#if (APP_IF1_USE_ROUTER_ADV == ENABLED)
   //List of IPv6 prefixes to be advertised
   ipv6StringToAddr(APP_IF1_IPV6_PREFIX, &ndpRouterAdvPrefixInfo[0].prefix);
   ndpRouterAdvPrefixInfo[0].length = APP_IF1_IPV6_PREFIX_LENGTH;
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
      //Exit immediately
      return error;
   }

   //Start RA service
   error = ndpRouterAdvStart(&ndpRouterAdvContext);
   //Failed to start RA service?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start RA service!\r\n");
      //Exit immediately
      return error;
   }
#endif
#endif

   //Successful initialization
   return NO_ERROR;
}


/**
 * @brief Connect to Wi-Fi network (STA mode)
 * @return Error code
 **/

esp_err_t wifiConnect(void)
{
   esp_err_t ret;
   wifi_config_t config;

   //Debug message
   TRACE_INFO("ESP32: Connecting to Wi-Fi network (%s)...\r\n", APP_WIFI_STA_SSID);

   //Initialize configuration structure
   memset(&config, 0, sizeof(wifi_config_t));

   //Set Wi-Fi parameters
   strcpy((char_t *) config.sta.ssid, APP_WIFI_STA_SSID);
   strcpy((char_t *) config.sta.password, APP_WIFI_STA_PASSWORD);
   config.sta.threshold.authmode = WIFI_AUTH_WPA_PSK;

   //Set Wi-Fi operating mode
   ret = esp_wifi_set_mode(WIFI_MODE_STA);

   //Check status code
   if(ret == ESP_OK)
   {
      //Configure STA interface
      ret = esp_wifi_set_config(ESP_IF_WIFI_STA, &config);
   }

   //Check status code
   if(ret == ESP_OK)
   {
      //Start STA interface
      ret = esp_wifi_start();
   }

   //Return status code
   return ret;
}


/**
 * @brief Create Wi-Fi network (AP mode)
 * @return Error code
 **/

esp_err_t wifiEnableAp(void)
{
   esp_err_t ret;
   wifi_config_t config;

   //Debug message
   TRACE_INFO("ESP32: Creating Wi-Fi network (%s)...\r\n", APP_WIFI_AP_SSID);

   //Initialize configuration structure
   memset(&config, 0, sizeof(wifi_config_t));

   //Set Wi-Fi parameters
   strcpy((char_t *) config.ap.ssid, APP_WIFI_AP_SSID);
   strcpy((char_t *) config.ap.password, APP_WIFI_AP_PASSWORD);
   config.ap.authmode = WIFI_AUTH_WPA_WPA2_PSK;
   config.ap.max_connection = 4;

   //Set Wi-Fi operating mode
   ret = esp_wifi_set_mode(WIFI_MODE_AP);

   //Check status code
   if(ret == ESP_OK)
   {
      //Configure AP interface
      ret = esp_wifi_set_config(ESP_IF_WIFI_AP, &config);
   }

   //Check status code
   if(ret == ESP_OK)
   {
      //Start AP interface
      ret = esp_wifi_start();
   }

   //Return status code
   return ret;
}


/**
 * @brief Wi-Fi event handler
 * @param[in] arg User-specific parameter
 * @param[in] eventBase Event base
 * @param[in] eventId Event identifier
 * @param[in] eventData Event-specific data
 **/

void wifiEventHandler(void *arg, esp_event_base_t eventBase,
   int32_t eventId, void *eventData)
{
   //Debug message
   TRACE_INFO("ESP32: Wi-Fi event handler (event = %d)\r\n", eventId);

   //Check event identifier
   if(eventId == WIFI_EVENT_STA_START)
   {
      //Debug message
      TRACE_INFO("ESP32: Station started\r\n");

      //Connect station to the AP
      esp_wifi_connect();
   }
   else if(eventId == WIFI_EVENT_STA_CONNECTED)
   {
      //Debug message
      TRACE_INFO("ESP32: Station connected\r\n");
   }
   else if(eventId == WIFI_EVENT_STA_DISCONNECTED)
   {
      wifi_event_sta_disconnected_t *event;

      //Point the event-specific data
      event = (wifi_event_sta_disconnected_t *) eventData;

      //Debug message
      TRACE_INFO("ESP32: Station disconnected (reason = %d)\r\n",
         event->reason);

      //Reconnect station to the AP
      esp_wifi_connect();
   }
   else if(eventId == WIFI_EVENT_AP_STACONNECTED)
   {
      MacAddr macAddr;
      wifi_event_ap_staconnected_t *event;

      //Point the event-specific data
      event = (wifi_event_ap_staconnected_t *) eventData;
      //Retrieve the MAC address of the station
      macCopyAddr(&macAddr, event->mac);

      //Debug message
      TRACE_INFO("ESP32: Station %s joining AP\r\n",
         macAddrToString(&macAddr, NULL));
   }
   else if(eventId == WIFI_EVENT_AP_STADISCONNECTED)
   {
      MacAddr macAddr;
      wifi_event_ap_stadisconnected_t *event;

      //Point the event-specific data
      event = (wifi_event_ap_stadisconnected_t *) eventData;
      //Retrieve the MAC address of the station
      macCopyAddr(&macAddr, event->mac);

      //Debug message
      TRACE_INFO("ESP32: Station %s leaving AP\r\n",
         macAddrToString(&macAddr, NULL));
   }
}
