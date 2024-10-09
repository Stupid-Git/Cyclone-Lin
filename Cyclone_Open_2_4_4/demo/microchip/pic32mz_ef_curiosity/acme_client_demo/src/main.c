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
#include "pic32mz_ef_curiosity.h"
#include "core/net.h"
#include "drivers/mac/pic32mz_eth_driver.h"
#include "drivers/phy/lan8720_driver.h"
#include "dhcp/dhcp_client.h"
#include "ipv6/slaac.h"
#include "acme/acme_client.h"
#include "http/http_server.h"
#include "http/mime.h"
#include "tls.h"
#include "tls_cipher_suites.h"
#include "pkix/pem_export.h"
#include "hardware/pic32mz/pic32mz_crypto.h"
#include "rng/trng.h"
#include "rng/yarrow.h"
#include "path.h"
#include "date_time.h"
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
#define APP_HOST_NAME "acme-client-demo"
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

//Application configuration
//#define APP_ACME_SERVER_NAME "acme-v02.api.letsencrypt.org"
#define APP_ACME_SERVER_NAME "acme-staging-v02.api.letsencrypt.org"
#define APP_ACME_SERVER_PORT 443
#define APP_ACME_DIRECTORY_URI "/directory"
#define APP_ACME_ACCOUNT_CONTACT "test@example.com"
#define APP_ACME_DOMAIN_NAME "acme-demo.oryx-embedded.com"
#define APP_ACME_SET_TRUSTED_CA_LIST DISABLED

#define APP_HTTP_MAX_CONNECTIONS 4
#define APP_HTTP_SET_CIPHER_SUITES ENABLED

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
DhcpClientContext dhcpClientContext;
SlaacSettings slaacSettings;
SlaacContext slaacContext;
AcmeClientContext acmeClientContext;
HttpServerSettings httpServerSettings;
HttpServerContext httpServerContext;
HttpConnection httpConnections[APP_HTTP_MAX_CONNECTIONS];
TlsCache *tlsCache;
YarrowContext yarrowContext;
uint8_t seed[32];
char_t accountPublicKey[256];
char_t accountPrivateKey[256];
char_t certPublicKey[256];
char_t certPrivateKey[256];
char_t certChain[6144];

//Forward declaration of functions
error_t httpServerTlsInitCallback(HttpConnection *connection,
   TlsContext *tlsContext);

error_t httpServerAlpnCallback(TlsContext *context,
   const char_t *selectedProtocol);

error_t httpServerCgiCallback(HttpConnection *connection,
   const char_t *param);

error_t httpServerRequestCallback(HttpConnection *connection,
   const char_t *uri);

error_t httpServerUriNotFoundCallback(HttpConnection *connection,
   const char_t *uri);

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
   //Configure LED1 (RE3), LED2 (RE4) and LED3 (RE6)
   TRISECLR = LED1_MASK | LED2_MASK | LED3_MASK;
   //Clear LEDs
   LATECLR = LED1_MASK | LED2_MASK | LED3_MASK;
   //Disable analog pads
   ANSELECLR = LED1_MASK | LED2_MASK | LED3_MASK;

   //Configure LED4_R (RB5), LED4_G (RB1) and LED4_B (RB0)
   TRISBCLR = LED4_R_MASK | LED4_G_MASK | LED4_B_MASK;
   //Clear LEDs
   LATBSET = LED4_R_MASK | LED4_G_MASK | LED4_B_MASK;
   //Disable analog pads
   ANSELBCLR = LED4_R_MASK | LED4_G_MASK | LED4_B_MASK;

   //Configure SW1 (RG12)
   TRISGSET = SW1_MASK;
   //Enable pull-up
   CNPUGSET = SW1_MASK;
   //Disable analog pads
   ANSELGCLR = SW1_MASK;
}


/**
 * @brief TLS initialization callback
 * @param[in] context Pointer to the HTTP client context
 * @param[in] tlsContext Pointer to the TLS context
 * @return Error code
 **/

error_t acmeTestTlsInitCallback(HttpClientContext *context,
   TlsContext *tlsContext)
{
   error_t error;

   //Check parameters
   if(context == NULL || tlsContext == NULL)
      return ERROR_INVALID_PARAMETER;

   //Debug message
   TRACE_INFO("ACME Client: TLS initialization callback\r\n");

   //Set the PRNG algorithm to be used
   error = tlsSetPrng(tlsContext, YARROW_PRNG_ALGO, &yarrowContext);
   //Any error to report?
   if(error)
      return error;

   //Set the fully qualified domain name of the server
   error = tlsSetServerName(tlsContext, APP_ACME_SERVER_NAME);
   //Any error to report?
   if(error)
      return error;

#if (APP_ACME_SET_TRUSTED_CA_LIST == ENABLED)
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
 * @brief ACME account key pair generation
 * @return Error code
 **/

error_t acmeTestGenerateAccountKeys(void)
{
   error_t error;
   size_t n;
   EcDomainParameters params;
   EcPrivateKey privateKey;
   EcPublicKey publicKey;

   //Initialize EC key pair
   ecInitDomainParameters(&params);
   ecInitPrivateKey(&privateKey);
   ecInitPublicKey(&publicKey);

   //Start of exception handling block
   do
   {
      //Load EC domain parameters
      error = ecLoadDomainParameters(&params, SECP256R1_CURVE);
      //Any error to report?
      if(error)
         break;

      //Generate an EC key pair
      error = ecGenerateKeyPair(YARROW_PRNG_ALGO, &yarrowContext, &params,
         &privateKey, &publicKey);
      //Any error to report?
      if(error)
         break;

      //Export the EC private key to PEM format
      error = pemExportEcPrivateKey(SECP256R1_CURVE, &privateKey, &publicKey,
         accountPrivateKey, &n);
      //Any error to report?
      if(error)
         break;

      //Dump private key (for debugging purpose only)
      TRACE_INFO("Account private key (%" PRIuSIZE " bytes):\r\n", n);
      TRACE_INFO("%s\r\n", accountPrivateKey);

      //Export the EC public key to PEM format
      error = pemExportEcPublicKey(SECP256R1_CURVE, &publicKey, accountPublicKey, &n);
      //Any error to report?
      if(error)
         break;

      //Dump public key
      TRACE_INFO("Account public key (%" PRIuSIZE " bytes):\r\n", n);
      TRACE_INFO("%s\r\n", accountPublicKey);

      //End of exception handling block
   } while(0);

   //Release EC key pair
   ecFreeDomainParameters(&params);
   ecFreePrivateKey(&privateKey);
   ecFreePublicKey(&publicKey);

   //Return status code
   return error;
}


/**
 * @brief Certificate key pair generation
 * @return Error code
 **/

error_t acmeTestGenerateCertKeys(void)
{
   error_t error;
   size_t n;
   EcDomainParameters params;
   EcPrivateKey privateKey;
   EcPublicKey publicKey;

   //Initialize EC key pair
   ecInitDomainParameters(&params);
   ecInitPrivateKey(&privateKey);
   ecInitPublicKey(&publicKey);

   //Start of exception handling block
   do
   {
      //Load EC domain parameters
      error = ecLoadDomainParameters(&params, SECP256R1_CURVE);
      //Any error to report?
      if(error)
         break;

      //Generate an EC key pair
      error = ecGenerateKeyPair(YARROW_PRNG_ALGO, &yarrowContext, &params,
         &privateKey, &publicKey);
      //Any error to report?
      if(error)
         break;

      //Export the EC private key to PEM format
      error = pemExportEcPrivateKey(SECP256R1_CURVE, &privateKey, &publicKey,
         certPrivateKey, &n);
      //Any error to report?
      if(error)
         break;

      //Dump private key (for debugging purpose only)
      TRACE_INFO("Certificate private key (%" PRIuSIZE " bytes):\r\n", n);
      TRACE_INFO("%s\r\n", certPrivateKey);

      //Export the EC public key to PEM format
      error = pemExportEcPublicKey(SECP256R1_CURVE, &publicKey, certPublicKey, &n);
      //Any error to report?
      if(error)
         break;

      //Dump public key
      TRACE_INFO("Certificate public key (%" PRIuSIZE " bytes):\r\n", n);
      TRACE_INFO("%s\r\n", certPublicKey);

      //End of exception handling block
   } while(0);

   //Release EC key pair
   ecFreeDomainParameters(&params);
   ecFreePrivateKey(&privateKey);
   ecFreePublicKey(&publicKey);

   //Return status code
   return error;
}


/**
 * @brief Create a new ACME account
 * @return Error code
 **/

error_t acmeTestCreateAccount(void)
{
   error_t error;
   IpAddr serverIpAddr;
   AcmeAccountParams accountParams;

   //Start of exception handling block
   do
   {
      //Resolve ACME server host name
      error = getHostByName(NULL, APP_ACME_SERVER_NAME, &serverIpAddr, 0);
      //Any error to report?
      if(error)
         break;

      //Establish connection with the ACME server
      error = acmeClientConnect(&acmeClientContext, &serverIpAddr,
         APP_ACME_SERVER_PORT);
      //Any error to report?
      if(error)
         break;

      //Initialize account parameters
      memset(&accountParams, 0, sizeof(AcmeAccountParams));

      //Set ACME account parameters
      accountParams.numContacts = 1;
      accountParams.contacts[0] = APP_ACME_ACCOUNT_CONTACT;
      accountParams.termsOfServiceAgreed = TRUE;
      accountParams.publicKey = accountPublicKey;
      accountParams.publicKeyLen = strlen(accountPublicKey);
      accountParams.privateKey = accountPrivateKey;
      accountParams.privateKeyLen = strlen(accountPrivateKey);

      //Create a new ACME account
      error = acmeClientCreateAccount(&acmeClientContext, &accountParams);
      //Any error to report?
      if(error)
         break;

      //Gracefully disconnect from the ACME server
      error = acmeClientDisconnect(&acmeClientContext);
      //Any error to report?
      if(error)
         break;

      //End of exception handling block
   } while(0);

   //Close the connection with the ACME server
   acmeClientClose(&acmeClientContext);

   //Return status code
   return error;
}


/**
 * @brief Order a new certificate
 * @return Error code
 **/

error_t acmeTestOrderCert(void)
{
   error_t error;
   uint_t i;
   size_t n;
   IpAddr serverIpAddr;
   AcmeOrderParams orderParams;
   AcmeOrderStatus orderStatus;

   //Start of exception handling block
   do
   {
      //Resolve ACME server host name
      error = getHostByName(NULL, APP_ACME_SERVER_NAME, &serverIpAddr, 0);
      //Any error to report?
      if(error)
         break;

      //Establish connection with the ACME server
      error = acmeClientConnect(&acmeClientContext, &serverIpAddr,
         APP_ACME_SERVER_PORT);
      //Any error to report?
      if(error)
         break;

      //Initialize certificate order parameters
      memset(&orderParams, 0, sizeof(AcmeOrderParams));

      //Set certificate order parameters
      orderParams.numDomains = 1;
      orderParams.domains[0].name = APP_ACME_DOMAIN_NAME;
      orderParams.domains[0].challengeType = ACME_CHALLENGE_TYPE_TLS_ALPN_01;
      orderParams.publicKey = certPublicKey;
      orderParams.publicKeyLen = strlen(certPublicKey);
      orderParams.privateKey = certPrivateKey;
      orderParams.privateKeyLen = strlen(certPrivateKey);

      //Create a new certificate
      error = acmeClientCreateOrder(&acmeClientContext, &orderParams);
      //Any error to report?
      if(error)
         break;

      //Default order status
      orderStatus = ACME_ORDER_STATUS_NONE;

      //Poll the status of the order
      for(i = 0; i < 30; i++)
      {
         //Get the current status of the order
         error = acmeClientPollOrderStatus(&acmeClientContext, &orderStatus);
         //Any error to report?
         if(error)
            break;

         //Once the certificate is issued, the order enters the "valid" state.
         //If an error occurs, the order moves to the "invalid" state
         if(orderStatus == ACME_ORDER_STATUS_VALID ||
            orderStatus == ACME_ORDER_STATUS_INVALID)
         {
            break;
         }

         //Polling delay
         osDelayTask(2000);
      }

      //Check the status of the order
      if(orderStatus != ACME_ORDER_STATUS_VALID)
      {
         error = ERROR_INVALID_STATUS;
         break;
      }

      //Download the certificate from the ACME server
      error = acmeClientDownloadCertificate(&acmeClientContext, certChain,
         sizeof(certChain) - 1, &n);
      //Any error to report?
      if(error)
         break;

      //Properly terminate the certificate chain with a NULL character
      certChain[n] = '\0';

      //Debug message
      TRACE_INFO("Certificate chain (%" PRIuSIZE " bytes):\r\n", n);
      TRACE_INFO("%s\r\n\r\n", certChain);

      //Gracefully disconnect from the ACME server
      error = acmeClientDisconnect(&acmeClientContext);
      //Any error to report?
      if(error)
         break;

      //End of exception handling block
   } while(0);

   //Close the connection with the ACME server
   acmeClientClose(&acmeClientContext);

   //Return status code
   return error;
}


/**
 * @brief ACME task
 * @param[in] param Unused parameter
 **/

void acmeTestTask(void *param)
{
   error_t error;
   uint_t i;

   //Debug message
   TRACE_INFO("Generating account key pair...\r\n");

   //Generate account key pair
   error = acmeTestGenerateAccountKeys();
   //Check status code
   if(error)
   {
      //Debug message
      TRACE_INFO("Failed to generate account key pair!\r\n");
   }

   //Debug message
   TRACE_INFO("Generating certificate key pair...\r\n");

   //Generate certificate key pair
   error = acmeTestGenerateCertKeys();
   //Check status code
   if(error)
   {
      //Debug message
      TRACE_INFO("Failed to generate certificate key pair!\r\n");
   }

   //Initialize ACME client context
   acmeClientInit(&acmeClientContext);

   //Register TLS initialization callback
   acmeClientRegisterTlsInitCallback(&acmeClientContext,
      acmeTestTlsInitCallback);

   //Set the PRNG algorithm to be used
   acmeClientSetPrng(&acmeClientContext, YARROW_PRNG_ALGO, &yarrowContext);

   //Set communication timeout
   acmeClientSetTimeout(&acmeClientContext, 30000);
   //Set the domain name of the ACME server
   acmeClientSetHost(&acmeClientContext, APP_ACME_SERVER_NAME);
   //Set the URI of the directory object
   acmeClientSetDirectoryUri(&acmeClientContext, APP_ACME_DIRECTORY_URI);

   //Account creation process
   do
   {
      //Create a new ACME account
      error = acmeTestCreateAccount();

      //Check status code
      if(error)
      {
         //Delay between unsuccessful attempts
         osDelayTask(10 * 1000);
      }

      //Check whether the ACME account has been successfully created
   } while(error);

   //Certificate order process
   while(1)
   {
      //Order a new certificate
      error = acmeTestOrderCert();

      //Check status code
      if(!error)
      {
         //The certificate is renewed every month
         for(i = 0; i < 30; i++)
         {
            osDelayTask(86400 * 1000);
         }
      }
      else
      {
         //Delay between unsuccessful attempts
         osDelayTask(86400 * 1000);
      }
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
      LATESET = LED1_MASK;
      osDelayTask(100);
      LATECLR = LED1_MASK;
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
   TRACE_INFO("************************************\r\n");
   TRACE_INFO("*** CycloneACME ACME Client Demo ***\r\n");
   TRACE_INFO("************************************\r\n");
   TRACE_INFO("Copyright: 2010-2024 Oryx Embedded SARL\r\n");
   TRACE_INFO("Compiled: %s %s\r\n", __DATE__, __TIME__);
   TRACE_INFO("Target: PIC32MZ2048EFM100\r\n");
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

   //TLS session cache initialization
   tlsCache = tlsInitCache(8);
   //Any error to report?
   if(tlsCache == NULL)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize TLS session cache!\r\n");
   }

   //Get default settings
   httpServerGetDefaultSettings(&httpServerSettings);
   //Bind HTTP server to the desired interface
   httpServerSettings.interface = &netInterface[0];
   //Listen to port 443
   httpServerSettings.port = HTTPS_PORT;
   //Maximum length of the pending connection queue
   httpServerSettings.backlog = 2;
   //Client connections
   httpServerSettings.maxConnections = APP_HTTP_MAX_CONNECTIONS;
   httpServerSettings.connections = httpConnections;
   //Specify the server's root directory
   strcpy(httpServerSettings.rootDirectory, "/www/");
   //Set default home page
   strcpy(httpServerSettings.defaultDocument, "index.shtm");
   //Callback functions
   httpServerSettings.tlsInitCallback = httpServerTlsInitCallback;
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

   //Set task parameters
   taskParams = OS_TASK_DEFAULT_PARAMS;
   taskParams.stackSize = 500;
   taskParams.priority = OS_TASK_PRIORITY_NORMAL;

   //Create ACME task
   taskId = osCreateTask("ACME", acmeTestTask, NULL, &taskParams);
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
 * @brief TLS initialization callback
 * @param[in] connection Handle referencing a client connection
 * @param[in] tlsContext Pointer to the TLS context
 * @return Error code
 **/

error_t httpServerTlsInitCallback(HttpConnection *connection,
   TlsContext *tlsContext)
{
   error_t error;

   //Set TX and RX buffer size
   error = tlsSetBufferSize(tlsContext, 6144, 2048);
   //Any error to report?
   if(error)
      return error;

   //Set the PRNG algorithm to be used
   error = tlsSetPrng(tlsContext, YARROW_PRNG_ALGO, &yarrowContext);
   //Any error to report?
   if(error)
      return error;

   //Session cache that will be used to save/resume TLS sessions
   error = tlsSetCache(tlsContext, tlsCache);
   //Any error to report?
   if(error)
      return error;

   //Client authentication is not required
   error = tlsSetClientAuthMode(tlsContext, TLS_CLIENT_AUTH_NONE);
   //Any error to report?
   if(error)
      return error;

   //Enable secure renegotiation
   error = tlsEnableSecureRenegotiation(tlsContext, TRUE);
   //Any error to report?
   if(error)
      return error;

   //Set the list of supported ALPN protocols
   error = tlsSetAlpnProtocolList(tlsContext, "acme-tls/1");
   //Any error to report?
   if(error)
      return error;

   //Allow unknown ALPN protocols
   error = tlsAllowUnknownAlpnProtocols(tlsContext, TRUE);
   //Any error to report?
   if(error)
      return error;

   //Register ALPN callback function
   error = tlsSetAlpnCallback(tlsContext, httpServerAlpnCallback);
   //Any error to report?
   if(error)
      return error;

#if (APP_HTTP_SET_CIPHER_SUITES == ENABLED)
   //Preferred cipher suite list
   error = tlsSetCipherSuites(tlsContext, cipherSuites, arraysize(cipherSuites));
   //Any error to report?
   if(error)
      return error;
#endif

   //Successful processing
   return NO_ERROR;
}


/**
 * @brief TLS ALPN callback function
 * @param[in] context Pointer to the TLS context
 * @param[in] selectedProtocol Pointer to the selected ALPN protocol
 * @return Error code
 **/

error_t httpServerAlpnCallback(TlsContext *context,
   const char_t *selectedProtocol)
{
   error_t error;
   size_t certLen;
   size_t privateKeyLen;
   const char_t *cert;
   const char_t *privateKey;
   const char_t *serverName;

   //Initialize pointer
   cert = NULL;

   //Check whether the "acme-tls/1" application-layer protocol has been
   //negotiated
   if(selectedProtocol != NULL && !strcmp(selectedProtocol, "acme-tls/1"))
   {
      //The ACME server must provide a SNI extension containing the domain name
      //being validated
      serverName = tlsGetServerName(context);

      //Valid domain name?
      if(serverName != NULL)
      {
         //Debug message
         TRACE_INFO("### TLS-ALPN challenge validation (%s) ###\r\n",
            serverName);

         //Get the TLS-ALPN certificate that matches the specified identifier
         cert = acmeClientGetTlsAlpnCertificate(&acmeClientContext, serverName);
      }
   }

   //Select the relevant certificate
   if(cert != NULL)
   {
      //Select the TLS-ALPN certificate
      certLen = strlen(cert);
      privateKey = certPrivateKey;
      privateKeyLen = strlen(certPrivateKey);
   }
   else
   {
      //Select the active certificate
      cert = certChain;
      certLen = strlen(certChain);
      privateKey = certPrivateKey;
      privateKeyLen = strlen(certPrivateKey);
   }

   //Load server's certificate
   error = tlsLoadCertificate(context, 0, cert, certLen, privateKey,
      privateKeyLen, NULL);
   //Any error to report?
   if(error)
      return error;

   //Successful processing
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
      strcpy(connection->buffer, "PIC32MZ EF Curiosity");
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
