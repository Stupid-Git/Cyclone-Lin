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
#include "fsl_gpio.h"
#include "fsl_iomuxc.h"
#include "board.h"
#include "core/net.h"
#include "drivers/mac/mimxrt1170_eth1_driver.h"
#include "drivers/mac/mimxrt1170_eth2_driver.h"
#include "drivers/mac/mimxrt1170_eth3_driver.h"
#include "drivers/phy/ksz8081_driver.h"
#include "drivers/phy/rtl8211f_driver.h"
#include "dhcp/dhcp_client.h"
#include "ipv6/slaac.h"
#include "smtp/smtp_client.h"
#include "tls.h"
#include "tls_cipher_suites.h"
#include "hardware/mimxrt1170/mimxrt1170_crypto.h"
#include "rng/trng.h"
#include "rng/yarrow.h"
#include "debug.h"

//First Ethernet interface configuration
#define APP_IF1_NAME "eth1"
#define APP_IF1_HOST_NAME "smtp-client-demo-1"
#define APP_IF1_MAC_ADDR "00-AB-CD-11-76-01"

#define APP_IF1_USE_DHCP_CLIENT ENABLED
#define APP_IF1_IPV4_HOST_ADDR "192.168.0.21"
#define APP_IF1_IPV4_SUBNET_MASK "255.255.255.0"
#define APP_IF1_IPV4_DEFAULT_GATEWAY "192.168.0.254"
#define APP_IF1_IPV4_PRIMARY_DNS "8.8.8.8"
#define APP_IF1_IPV4_SECONDARY_DNS "8.8.4.4"

#define APP_IF1_USE_SLAAC ENABLED
#define APP_IF1_IPV6_LINK_LOCAL_ADDR "fe80::1176:1"
#define APP_IF1_IPV6_PREFIX "2001:db8::"
#define APP_IF1_IPV6_PREFIX_LENGTH 64
#define APP_IF1_IPV6_GLOBAL_ADDR "2001:db8::1176:1"
#define APP_IF1_IPV6_ROUTER "fe80::1"
#define APP_IF1_IPV6_PRIMARY_DNS "2001:4860:4860::8888"
#define APP_IF1_IPV6_SECONDARY_DNS "2001:4860:4860::8844"

//Second Ethernet interface configuration
#define APP_IF2_NAME "eth2"
#define APP_IF2_HOST_NAME "smtp-client-demo-2"
#define APP_IF2_MAC_ADDR "00-AB-CD-11-76-02"

#define APP_IF2_USE_DHCP_CLIENT ENABLED
#define APP_IF2_IPV4_HOST_ADDR "192.168.0.22"
#define APP_IF2_IPV4_SUBNET_MASK "255.255.255.0"
#define APP_IF2_IPV4_DEFAULT_GATEWAY "192.168.0.254"
#define APP_IF2_IPV4_PRIMARY_DNS "8.8.8.8"
#define APP_IF2_IPV4_SECONDARY_DNS "8.8.4.4"

#define APP_IF2_USE_SLAAC ENABLED
#define APP_IF2_IPV6_LINK_LOCAL_ADDR "fe80::1176:2"
#define APP_IF2_IPV6_PREFIX "2001:db8::"
#define APP_IF2_IPV6_PREFIX_LENGTH 64
#define APP_IF2_IPV6_GLOBAL_ADDR "2001:db8::1176:2"
#define APP_IF2_IPV6_ROUTER "fe80::1"
#define APP_IF2_IPV6_PRIMARY_DNS "2001:4860:4860::8888"
#define APP_IF2_IPV6_SECONDARY_DNS "2001:4860:4860::8844"

//Application configuration
#define APP_SMTP_SERVER_NAME "smtp.gmail.com"
#define APP_SMTP_IMPLICIT_TLS DISABLED
#define APP_SMTP_EXPLICIT_TLS ENABLED
#define APP_SMTP_LOGIN "username"
#define APP_SMTP_PASSWORD "password"

#define APP_SET_CIPHER_SUITES DISABLED
#define APP_SET_SERVER_NAME DISABLED
#define APP_SET_TRUSTED_CA_LIST DISABLED

//List of preferred ciphersuites
const uint16_t cipherSuites[] =
{
   TLS_CHACHA20_POLY1305_SHA256,
   TLS_AES_128_GCM_SHA256,
   TLS_AES_256_GCM_SHA384,
   TLS_ECDHE_ECDSA_WITH_CHACHA20_POLY1305_SHA256,
   TLS_ECDHE_RSA_WITH_CHACHA20_POLY1305_SHA256,
   TLS_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256,
   TLS_ECDHE_RSA_WITH_AES_128_GCM_SHA256,
   TLS_ECDHE_ECDSA_WITH_AES_256_GCM_SHA384,
   TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384,
   TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA,
   TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA,
   TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA,
   TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA,
   TLS_DHE_RSA_WITH_AES_128_GCM_SHA256,
   TLS_DHE_RSA_WITH_AES_256_GCM_SHA384,
   TLS_DHE_RSA_WITH_AES_128_CBC_SHA,
   TLS_DHE_RSA_WITH_AES_256_CBC_SHA,
   TLS_RSA_WITH_AES_128_GCM_SHA256,
   TLS_RSA_WITH_AES_256_GCM_SHA384,
   TLS_RSA_WITH_AES_128_CBC_SHA,
   TLS_RSA_WITH_AES_256_CBC_SHA,
   TLS_RSA_WITH_3DES_EDE_CBC_SHA
};

//Global variables
DhcpClientSettings dhcpClientSettings;
DhcpClientContext dhcpClientContext[2];
SlaacSettings slaacSettings;
SlaacContext slaacContext[2];
SmtpClientContext smtpClientContext;
YarrowContext yarrowContext;
uint8_t seed[32];

//Forward declaration of functions
error_t eth1InterfaceInit(void);
error_t eth2InterfaceInit(void);


/**
 * @brief MPU configuration
 **/

void mpuConfig(void)
{
   //Disable MPU
   ARM_MPU_Disable();

   //Region 0 setting
   MPU->RBAR = ARM_MPU_RBAR(0, 0x00000000U);
   MPU->RASR = ARM_MPU_RASR(1, ARM_MPU_AP_NONE, 0, 0, 0, 0, 0, ARM_MPU_REGION_SIZE_4GB);

   //Region 1 setting
   MPU->RBAR = ARM_MPU_RBAR(1, 0x80000000U);
   MPU->RASR = ARM_MPU_RASR(0, ARM_MPU_AP_FULL, 2, 0, 0, 0, 0, ARM_MPU_REGION_SIZE_512MB);

   //Region 2 setting
   MPU->RBAR = ARM_MPU_RBAR(2, 0x60000000U);
   MPU->RASR = ARM_MPU_RASR(0, ARM_MPU_AP_FULL, 2, 0, 0, 0, 0, ARM_MPU_REGION_SIZE_512MB);

   //Region 3 setting
   MPU->RBAR = ARM_MPU_RBAR(3, 0x00000000U);
   MPU->RASR = ARM_MPU_RASR(0, ARM_MPU_AP_FULL, 2, 0, 0, 0, 0, ARM_MPU_REGION_SIZE_1GB);

   //Region 4 setting
   MPU->RBAR = ARM_MPU_RBAR(4, 0x00000000U);
   MPU->RASR = ARM_MPU_RASR(0, ARM_MPU_AP_FULL, 0, 0, 1, 1, 0, ARM_MPU_REGION_SIZE_256KB);

   //Region 5 setting
   MPU->RBAR = ARM_MPU_RBAR(5, 0x20000000U);
   MPU->RASR = ARM_MPU_RASR(0, ARM_MPU_AP_FULL, 0, 0, 1, 1, 0, ARM_MPU_REGION_SIZE_256KB);

#if defined(CACHE_MODE_WRITE_THROUGH) && CACHE_MODE_WRITE_THROUGH
   //Region 6 setting
   MPU->RBAR = ARM_MPU_RBAR(6, 0x20200000U);
   MPU->RASR = ARM_MPU_RASR(0, ARM_MPU_AP_FULL, 0, 0, 1, 0, 0, ARM_MPU_REGION_SIZE_1MB);

   //Region 7 setting
   MPU->RBAR = ARM_MPU_RBAR(7, 0x20300000U);
   MPU->RASR = ARM_MPU_RASR(0, ARM_MPU_AP_FULL, 0, 0, 1, 0, 0, ARM_MPU_REGION_SIZE_512KB);
#else
   //Region 6 setting
   MPU->RBAR = ARM_MPU_RBAR(6, 0x20200000U);
   MPU->RASR = ARM_MPU_RASR(0, ARM_MPU_AP_FULL, 0, 0, 1, 1, 0, ARM_MPU_REGION_SIZE_1MB);

   //Region 7 setting
   MPU->RBAR = ARM_MPU_RBAR(7, 0x20300000U);
   MPU->RASR = ARM_MPU_RASR(0, ARM_MPU_AP_FULL, 0, 0, 1, 1, 0, ARM_MPU_REGION_SIZE_512KB);
#endif

#if defined(XIP_EXTERNAL_FLASH) && (XIP_EXTERNAL_FLASH == 1)
   //Region 8 setting
   MPU->RBAR = ARM_MPU_RBAR(8, 0x30000000U);
   MPU->RASR = ARM_MPU_RASR(0, ARM_MPU_AP_RO, 0, 0, 1, 1, 0, ARM_MPU_REGION_SIZE_16MB);
#endif

#if defined(CACHE_MODE_WRITE_THROUGH) && CACHE_MODE_WRITE_THROUGH
   //Region 9 setting
   MPU->RBAR = ARM_MPU_RBAR(9, 0x80000000U);
   MPU->RASR = ARM_MPU_RASR(0, ARM_MPU_AP_FULL, 0, 0, 1, 0, 0, ARM_MPU_REGION_SIZE_64MB);
#else
   //Region 9 setting
   MPU->RBAR = ARM_MPU_RBAR(9, 0x80000000U);
   MPU->RASR = ARM_MPU_RASR(0, ARM_MPU_AP_FULL, 0, 0, 1, 1, 0, ARM_MPU_REGION_SIZE_64MB);
#endif

   //Region 10 setting (non-cacheable SRAM)
   MPU->RBAR = ARM_MPU_RBAR(10, 0x20330000);
   MPU->RASR = ARM_MPU_RASR(0, ARM_MPU_AP_FULL, 1, 0, 0, 0, 0, ARM_MPU_REGION_SIZE_64KB);

   //Region 11 setting
   MPU->RBAR = ARM_MPU_RBAR(11, 0x40000000);
   MPU->RASR = ARM_MPU_RASR(0, ARM_MPU_AP_FULL, 2, 0, 0, 0, 0, ARM_MPU_REGION_SIZE_16MB);

   //Region 12 setting
   MPU->RBAR = ARM_MPU_RBAR(12, 0x41000000);
   MPU->RASR = ARM_MPU_RASR(0, ARM_MPU_AP_FULL, 2, 0, 0, 0, 0, ARM_MPU_REGION_SIZE_2MB);

   //Region 13 setting
   MPU->RBAR = ARM_MPU_RBAR(13, 0x41400000);
   MPU->RASR = ARM_MPU_RASR(0, ARM_MPU_AP_FULL, 2, 0, 0, 0, 0, ARM_MPU_REGION_SIZE_1MB);

   //Region 14 setting
   MPU->RBAR = ARM_MPU_RBAR(14, 0x41800000);
   MPU->RASR = ARM_MPU_RASR(0, ARM_MPU_AP_FULL, 2, 0, 0, 0, 0, ARM_MPU_REGION_SIZE_2MB);

   //Region 15 setting
   MPU->RBAR = ARM_MPU_RBAR(15, 0x42000000);
   MPU->RASR = ARM_MPU_RASR(0, ARM_MPU_AP_FULL, 2, 0, 0, 0, 0, ARM_MPU_REGION_SIZE_1MB);

   //Enable MPU
   ARM_MPU_Enable(MPU_CTRL_PRIVDEFENA_Msk);
}


/**
 * @brief I/O initialization
 **/

void ioInit(void)
{
   gpio_pin_config_t pinConfig;

   //Enable IOMUXC clock
   CLOCK_EnableClock(kCLOCK_Iomuxc);

   //Configure GPIO_AD_B0_09 pin as GPIO9_IO03
   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_04_GPIO9_IO03, 0);

   //Set GPIO_AD_B0_09 pad properties
   IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_04_GPIO9_IO03,
      IOMUXC_SW_PAD_CTL_PAD_DWP_LOCK(0) |
      IOMUXC_SW_PAD_CTL_PAD_DWP(0) |
      IOMUXC_SW_PAD_CTL_PAD_ODE(0) |
      IOMUXC_SW_PAD_CTL_PAD_PUS(0) |
      IOMUXC_SW_PAD_CTL_PAD_PUE(0) |
      IOMUXC_SW_PAD_CTL_PAD_DSE(1) |
      IOMUXC_SW_PAD_CTL_PAD_SRE(0));

   //Configure GPIO_AD_26 pin as GPIO9_IO25
   IOMUXC_SetPinMux(IOMUXC_GPIO_AD_26_GPIO9_IO25, 0);

   //Set GPIO_AD_26 pad properties
   IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_26_GPIO9_IO25,
      IOMUXC_SW_PAD_CTL_PAD_DWP_LOCK(0) |
      IOMUXC_SW_PAD_CTL_PAD_DWP(0) |
      IOMUXC_SW_PAD_CTL_PAD_ODE(0) |
      IOMUXC_SW_PAD_CTL_PAD_PUS(0) |
      IOMUXC_SW_PAD_CTL_PAD_PUE(0) |
      IOMUXC_SW_PAD_CTL_PAD_DSE(1) |
      IOMUXC_SW_PAD_CTL_PAD_SRE(0));

   //Configure WAKEUP pin as GPIO13_IO00
   IOMUXC_SetPinMux(IOMUXC_WAKEUP_DIG_GPIO13_IO00, 0);

   //Set WAKEUP pad properties
   IOMUXC_SetPinConfig(IOMUXC_WAKEUP_DIG_GPIO13_IO00,
      IOMUXC_SW_PAD_CTL_PAD_DWP_LOCK(0) |
      IOMUXC_SW_PAD_CTL_PAD_DWP(0) |
      IOMUXC_SW_PAD_CTL_PAD_ODE(0) |
      IOMUXC_SW_PAD_CTL_PAD_PUS(1) |
      IOMUXC_SW_PAD_CTL_PAD_PUE(1) |
      IOMUXC_SW_PAD_CTL_PAD_DSE(0) |
      IOMUXC_SW_PAD_CTL_PAD_SRE(0));

   //Configure user LED1
   pinConfig.direction = kGPIO_DigitalOutput;
   pinConfig.outputLogic = 0;
   pinConfig.interruptMode = kGPIO_NoIntmode;
   GPIO_PinInit(BOARD_USER_LED_GPIO, BOARD_USER_LED_GPIO_PIN, &pinConfig);

   //Configure user LED2
   pinConfig.direction = kGPIO_DigitalOutput;
   pinConfig.outputLogic = 0;
   pinConfig.interruptMode = kGPIO_NoIntmode;
   GPIO_PinInit(GPIO9, 25, &pinConfig);

   //Configure user button
   pinConfig.direction = kGPIO_DigitalInput;
   pinConfig.outputLogic = 0;
   pinConfig.interruptMode = kGPIO_NoIntmode;
   GPIO_PinInit(BOARD_USER_BUTTON_GPIO, BOARD_USER_BUTTON_GPIO_PIN, &pinConfig);
}


/**
 * @brief TLS initialization callback
 * @param[in] context Pointer to the SMTP client context
 * @param[in] tlsContext Pointer to the TLS context
 * @return Error code
 **/

error_t smtpClientTlsInitCallback(SmtpClientContext *context,
   TlsContext *tlsContext)
{
   error_t error;

   //Debug message
   TRACE_INFO("SMTP Client: TLS initialization callback\r\n");

   //Set the PRNG algorithm to be used
   error = tlsSetPrng(tlsContext, YARROW_PRNG_ALGO, &yarrowContext);
   //Any error to report?
   if(error)
      return error;

#if (APP_SET_CIPHER_SUITES == ENABLED)
   //Preferred cipher suite list
   error = tlsSetCipherSuites(tlsContext, cipherSuites, arraysize(cipherSuites));
   //Any error to report?
   if(error)
      return error;
#endif

#if (APP_SET_SERVER_NAME == ENABLED)
   //Set the fully qualified domain name of the server
   error = tlsSetServerName(tlsContext, APP_SMTP_SERVER_NAME);
   //Any error to report?
   if(error)
      return error;
#endif

#if (APP_SET_TRUSTED_CA_LIST == ENABLED)
   //Import the list of trusted CA certificates
   error = tlsSetTrustedCaList(tlsContext, trustedCaList, strlen(trustedCaList));
   //Any error to report?
   if(error)
      return error;
#endif

   //Successful processing
   return NO_ERROR;
}


/**
 * @brief SMTP client test routine
 * @param interface Underlying network interface
 * @return Error code
 **/

error_t smtpClientTest(NetInterface *interface)
{
   error_t error;
   IpAddr ipAddr;

   //Email address of the sender
   const SmtpMailAddr from =
   {
      "Charlie", "charlie@gmail.com"
   };

   //Email addresses of the recipients
   const SmtpMailAddr recipients[2] =
   {
      {"Alice", "alice@example.com", SMTP_ADDR_TYPE_TO},
      {"Bob", "bob@example.com", SMTP_ADDR_TYPE_CC}
   };

   //Email body
   const char_t message[] =
      "<h2>Hello World!</h2>"
      "<p>This e-mail contains a CSV attachment.</p>";

   //Attachment
   const char_t attachment[] =
      "Name,Age\r\n"
      "Alice,31\r\n"
      "Bob,45\r\n"
      "Charlie,29\r\n"
      "Daniel,53\r\n"
      "Emily,38\r\n";

   //Initialize SMTP client context
   smtpClientInit(&smtpClientContext);

   //Start of exception handling block
   do
   {
      //Debug message
      TRACE_INFO("\r\n\r\nResolving server name...\r\n");

      //Resolve SMTP server name
      error = getHostByName(interface, APP_SMTP_SERVER_NAME, &ipAddr, 0);
      //Any error to report?
      if(error)
      {
         //Debug message
         TRACE_INFO("Failed to resolve server name!\r\n");
         break;
      }

#if (APP_SMTP_IMPLICIT_TLS == ENABLED || APP_SMTP_EXPLICIT_TLS == ENABLED)
      //Register TLS initialization callback
      error = smtpClientRegisterTlsInitCallback(&smtpClientContext,
         smtpClientTlsInitCallback);
      //Any error to report?
      if(error)
         break;
#endif

      //Set timeout value for blocking operations
      error = smtpClientSetTimeout(&smtpClientContext, 20000);
      //Any error to report?
      if(error)
         break;

      //Bind the SMTP client to the relevant network interface
      error = smtpClientBindToInterface(&smtpClientContext, interface);
      //Any error to report?
      if(error)
         break;

      //Debug message
      TRACE_INFO("Connecting to SMTP server %s...\r\n",
         ipAddrToString(&ipAddr, NULL));

#if (APP_SMTP_IMPLICIT_TLS == ENABLED)
      //Connect to the SMTP server (implicit TLS)
      error = smtpClientConnect(&smtpClientContext, &ipAddr, 465,
         SMTP_MODE_IMPLICIT_TLS);
#elif (APP_SMTP_EXPLICIT_TLS == ENABLED)
      //Connect to the SMTP server (explicit TLS using STARTTLS)
      error = smtpClientConnect(&smtpClientContext, &ipAddr, 587,
         SMTP_MODE_EXPLICIT_TLS);
#else
      //Connect to the SMTP server (no security)
      error = smtpClientConnect(&smtpClientContext, &ipAddr, 587,
         SMTP_MODE_PLAINTEXT);
#endif

      //Any error to report?
      if(error)
      {
         //Debug message
         TRACE_INFO("Failed to connect to SMTP server!\r\n");
         break;
      }

      //Login to the SMTP server using the provided username and password
      error = smtpClientLogin(&smtpClientContext, APP_SMTP_LOGIN,
         APP_SMTP_PASSWORD);
      //Any error to report?
      if(error)
         break;

      //Use multipart encoding
      error = smtpClientSetContentType(&smtpClientContext,
         "multipart/mixed");
      //Any error to report?
      if(error)
         break;

      //Send email header
      error = smtpClientWriteMailHeader(&smtpClientContext, &from,
         recipients, arraysize(recipients), "SMTP Client Test");
      //Any error to report?
      if(error)
         break;

      //Write first multipart header
      error = smtpClientWriteMultipartHeader(&smtpClientContext,
         NULL, "text/html", "8bit", FALSE);
      //Any error to report?
      if(error)
         break;

      //Send email body
      error = smtpClientWriteMultipartBody(&smtpClientContext,
         message, strlen(message), NULL, 0);
      //Any error to report?
      if(error)
         break;

      //Write intermediate multipart header
      error = smtpClientWriteMultipartHeader(&smtpClientContext,
         "data.csv", "text/csv", "base64", FALSE);
      //Any error to report?
      if(error)
         break;

      //Send attachment
      error = smtpClientWriteMultipartBody(&smtpClientContext,
         attachment, strlen(attachment), NULL, 0);
      //Any error to report?
      if(error)
         break;

      //Write last multipart header
      error = smtpClientWriteMultipartHeader(&smtpClientContext,
         NULL, NULL, NULL, TRUE);
      //Any error to report?
      if(error)
         break;

      //Complete email sending process and wait for server's status
      error = smtpClientCloseMailBody(&smtpClientContext);
      //Any error to report?
      if(error)
         break;

      //Gracefully disconnect from the SMTP server
      smtpClientDisconnect(&smtpClientContext);

      //Debug message
      TRACE_INFO("Connection closed\r\n");

      //End of exception handling block
   } while(0);

   //Release SMTP client context
   smtpClientDeinit(&smtpClientContext);

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
      if(!GPIO_PinRead(BOARD_USER_BUTTON_GPIO, BOARD_USER_BUTTON_GPIO_PIN))
      {
         if(netGetLinkState(&netInterface[0]))
         {
            //SMTP client test routine
            smtpClientTest(&netInterface[0]);
         }
         else if(netGetLinkState(&netInterface[1]))
         {
            //SMTP client test routine
            smtpClientTest(&netInterface[1]);
         }

         //Wait for the user button to be released
         while(!GPIO_PinRead(BOARD_USER_BUTTON_GPIO, BOARD_USER_BUTTON_GPIO_PIN));
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
      GPIO_PinWrite(BOARD_USER_LED_GPIO, BOARD_USER_LED_GPIO_PIN, 1);
      osDelayTask(100);
      GPIO_PinWrite(BOARD_USER_LED_GPIO, BOARD_USER_LED_GPIO_PIN, 0);
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

   //Configure the system clock
   BOARD_InitBootClocks();

   //Disable I-cache and D-cache
   SCB_DisableICache();
   SCB_DisableDCache();

   //MPU configuration
   mpuConfig();

   //Enable I-cache and D-cache
   SCB_EnableICache();
   SCB_EnableDCache();

   //Initialize kernel
   osInitKernel();
   //Configure debug UART
   debugInit(115200);

   //Start-up message
   TRACE_INFO("\r\n");
   TRACE_INFO("***********************************\r\n");
   TRACE_INFO("*** CycloneTCP SMTP Client Demo ***\r\n");
   TRACE_INFO("***********************************\r\n");
   TRACE_INFO("Copyright: 2010-2024 Oryx Embedded SARL\r\n");
   TRACE_INFO("Compiled: %s %s\r\n", __DATE__, __TIME__);
   TRACE_INFO("Target: i.MX RT1176\r\n");
   TRACE_INFO("\r\n");

   //Configure I/Os
   ioInit();

   //Initialize hardware cryptographic accelerator
   error = mimxrt1170CryptoInit();
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

   //Configure network interfaces
   eth1InterfaceInit();
   eth2InterfaceInit();

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
   netSetDriver(interface, &mimxrt1170Eth1Driver);
   //Select the relevant PHY driver
   netSetPhyDriver(interface, &ksz8081PhyDriver);

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
   netSetDriver(interface, &mimxrt1170Eth2Driver);
   //Select the relevant PHY driver
   netSetPhyDriver(interface, &rtl8211fPhyDriver);

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
