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
#include "pic32mk_mcm_curiosity_pro.h"
#include "core/net.h"
#include "ppp/ppp.h"
#include "http/http_client.h"
#include "tls.h"
#include "tls_cipher_suites.h"
#include "rng/yarrow.h"
#include "modem.h"
#include "uart_driver.h"
#include "debug.h"

#ifndef _CP0_SET_CONFIG
    #define _CP0_SET_CONFIG(val) _mtc0(_CP0_CONFIG, _CP0_CONFIG_SELECT, val)
#endif

//Configuration bits
#pragma config DEBUG = OFF
#pragma config JTAGEN = OFF
#pragma config ICESEL = ICS_PGx1
#pragma config TRCEN = OFF
#pragma config BOOTISA = MIPS32
#pragma config FECCCON = ECC_DECC_DISABLE_ECCON_WRITABLE
#pragma config FSLEEP = OFF
#pragma config DBGPER = PG_ALL
#pragma config SMCLR = MCLR_NORM
#pragma config SOSCGAIN = G3
#pragma config SOSCBOOST = ON
#pragma config POSCGAIN = G3
#pragma config POSCBOOST = ON
#pragma config POSCFGAIN = G3
#pragma config POSCAGCDLY = AGCRNG_x_25ms
#pragma config POSCAGCRNG = ONE_X
#pragma config POSCAGC = Automatic
#pragma config EJTAGBEN = NORMAL
#pragma config FNOSC = SPLL
#pragma config DMTINTV = WIN_127_128
#pragma config FSOSCEN = OFF
#pragma config IESO = ON
#pragma config POSCMOD = OFF
#pragma config OSCIOFNC = OFF
#pragma config FCKSM = CSECME
#pragma config WDTPS = PS1048576
#pragma config WDTSPGM = STOP
#pragma config WINDIS = NORMAL
#pragma config FWDTEN = OFF
#pragma config FWDTWINSZ = WINSZ_25
#pragma config DMTCNT = DMT31
#pragma config FDMTEN = OFF
#pragma config FPLLIDIV = DIV_1
#pragma config FPLLRNG = RANGE_5_10_MHZ
#pragma config FPLLICLK = PLL_FRC
#pragma config FPLLMULT = MUL_60
#pragma config FPLLODIV = DIV_4
#pragma config DSBOREN = ON
#pragma config DSWDTPS = DSPS32
#pragma config DSWDTOSC = LPRC
#pragma config DSWDTEN = OFF
#pragma config FDSEN = ON
#pragma config BORSEL = HIGH
#pragma config UPLLEN = OFF
#pragma config USERID = 0xFFFF
#pragma config PWMLOCK = OFF
#pragma config FUSBIDIO2 = ON
#pragma config FVBUSIO2 = ON
#pragma config PGL1WAY = OFF
#pragma config PMDL1WAY = OFF
#pragma config IOL1WAY = OFF
#pragma config FUSBIDIO1 = ON
#pragma config FVBUSIO1 = ON
#pragma config CP = OFF
#pragma config TSEQ = 0x0000
#pragma config CSEQ = 0xFFFF

//PPP interface configuration
#define APP_IF_NAME "ppp0"

//Application configuration
#define APP_HTTP_SERVER_NAME "www.httpbin.org"
#define APP_HTTP_SERVER_PORT 443
#define APP_HTTP_URI "/anything"

#define APP_SET_CIPHER_SUITES DISABLED
#define APP_SET_SERVER_NAME ENABLED
#define APP_SET_TRUSTED_CA_LIST ENABLED

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

//List of trusted CA certificates
const char_t trustedCaList[] =
   "-----BEGIN CERTIFICATE-----"
   "MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF"
   "ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6"
   "b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL"
   "MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv"
   "b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj"
   "ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM"
   "9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw"
   "IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6"
   "VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L"
   "93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm"
   "jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC"
   "AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA"
   "A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI"
   "U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs"
   "N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv"
   "o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU"
   "5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy"
   "rqXRfboQnoZsG4q5WTP468SQvvG5"
   "-----END CERTIFICATE-----";

//Global variables
PppSettings pppSettings;
PppContext pppContext;
HttpClientContext httpClientContext;
YarrowContext yarrowContext;
uint8_t seed[32];

//UART4 interrupt service routines
void __ISR(_UART4_TX_VECTOR, IPL2AUTO) uart4TxIrqWrapper(void);
void __ISR(_UART4_RX_VECTOR, IPL2AUTO) uart4RxIrqWrapper(void);


/**
 * @brief System initialization
 **/

void systemInit(void)
{
   uint32_t temp;

   //Configure wait states and prefetch
   CHECONbits.PFMWS = 2;
   CHECONbits.PREFEN = 1;

   //Enable KSEG0 cache
   temp = _CP0_GET_CONFIG() & ~_CP0_CONFIG_K0_MASK;
   temp |= (3 << _CP0_CONFIG_K0_POSITION);
   _CP0_SET_CONFIG(temp);

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
   //Configure LED1 (RG12), LED2 (RG13) and LED3 (RG14)
   TRISGCLR = LED1_MASK | LED2_MASK | LED3_MASK;
   //Clear LEDs
   LATGCLR = LED1_MASK | LED2_MASK | LED3_MASK;
   //Disable analog pads
   ANSELGCLR = LED1_MASK | LED2_MASK | LED3_MASK;

   //Configure SW1 (RG11)
   TRISGSET = SW1_MASK;
   //Enable pull-up
   CNPUGSET = SW1_MASK;
   //Disable analog pads
   ANSELGCLR = SW1_MASK;

   //Configure SW2 (RF12) and SW3 (RF13)
   TRISFSET = SW2_MASK | SW3_MASK;
   //Enable pull-up
   CNPUFSET = SW2_MASK | SW3_MASK;
   //Disable analog pads
   ANSELFCLR = SW2_MASK | SW3_MASK;
}


/**
 * @brief TLS initialization callback
 * @param[in] context Pointer to the HTTP client context
 * @param[in] tlsContext Pointer to the TLS context
 * @return Error code
 **/

error_t httpClientTlsInitCallback(HttpClientContext *context,
   TlsContext *tlsContext)
{
   error_t error;

   //Debug message
   TRACE_INFO("HTTP Client: TLS initialization callback\r\n");

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
   error = tlsSetServerName(tlsContext, APP_HTTP_SERVER_NAME);
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
 * @brief HTTP client test routine
 * @return Error code
 **/

error_t httpClientTest(void)
{
   error_t error;
   size_t length;
   uint_t status;
   const char_t *value;
   IpAddr ipAddr;
   char_t buffer[128];

   //Initialize HTTP client context
   httpClientInit(&httpClientContext);

   //Start of exception handling block
   do
   {
      //Debug message
      TRACE_INFO("\r\n\r\nResolving server name...\r\n");

      //Resolve HTTP server name
      error = getHostByName(NULL, APP_HTTP_SERVER_NAME, &ipAddr, 0);
      //Any error to report?
      if(error)
      {
         //Debug message
         TRACE_INFO("Failed to resolve server name!\r\n");
         break;
      }

#if (APP_HTTP_SERVER_PORT == 443)
      //Register TLS initialization callback
      error = httpClientRegisterTlsInitCallback(&httpClientContext,
         httpClientTlsInitCallback);
      //Any error to report?
      if(error)
         break;
#endif

      //Select HTTP protocol version
      error = httpClientSetVersion(&httpClientContext, HTTP_VERSION_1_1);
      //Any error to report?
      if(error)
         break;

      //Set timeout value for blocking operations
      error = httpClientSetTimeout(&httpClientContext, 20000);
      //Any error to report?
      if(error)
         break;

      //Debug message
      TRACE_INFO("Connecting to HTTP server %s...\r\n",
         ipAddrToString(&ipAddr, NULL));

      //Connect to the HTTP server
      error = httpClientConnect(&httpClientContext, &ipAddr,
         APP_HTTP_SERVER_PORT);
      //Any error to report?
      if(error)
      {
         //Debug message
         TRACE_INFO("Failed to connect to HTTP server!\r\n");
         break;
      }

      //Create an HTTP request
      httpClientCreateRequest(&httpClientContext);
      httpClientSetMethod(&httpClientContext, "POST");
      httpClientSetUri(&httpClientContext, APP_HTTP_URI);

      //Set query string
      httpClientAddQueryParam(&httpClientContext, "param1", "value1");
      httpClientAddQueryParam(&httpClientContext, "param2", "value2");

      //Add HTTP header fields
      httpClientAddHeaderField(&httpClientContext, "Host", APP_HTTP_SERVER_NAME);
      httpClientAddHeaderField(&httpClientContext, "User-Agent", "Mozilla/5.0");
      httpClientAddHeaderField(&httpClientContext, "Content-Type", "text/plain");
      httpClientAddHeaderField(&httpClientContext, "Transfer-Encoding", "chunked");

      //Send HTTP request header
      error = httpClientWriteHeader(&httpClientContext);
      //Any error to report?
      if(error)
      {
         //Debug message
         TRACE_INFO("Failed to write HTTP request header!\r\n");
         break;
      }

      //Send HTTP request body
      error = httpClientWriteBody(&httpClientContext, "Hello World!", 12,
         NULL, 0);
      //Any error to report?
      if(error)
      {
         //Debug message
         TRACE_INFO("Failed to write HTTP request body!\r\n");
         break;
      }

      //Receive HTTP response header
      error = httpClientReadHeader(&httpClientContext);
      //Any error to report?
      if(error)
      {
         //Debug message
         TRACE_INFO("Failed to read HTTP response header!\r\n");
         break;
      }

      //Retrieve HTTP status code
      status = httpClientGetStatus(&httpClientContext);
      //Debug message
      TRACE_INFO("HTTP status code: %u\r\n", status);

      //Retrieve the value of the Content-Type header field
      value = httpClientGetHeaderField(&httpClientContext, "Content-Type");

      //Header field found?
      if(value != NULL)
      {
         //Debug message
         TRACE_INFO("Content-Type header field value: %s\r\n", value);
      }
      else
      {
         //Debug message
         TRACE_INFO("Content-Type header field not found!\r\n");
      }

      //Receive HTTP response body
      while(!error)
      {
         //Read data
         error = httpClientReadBody(&httpClientContext, buffer,
            sizeof(buffer) - 1, &length, 0);

         //Check status code
         if(!error)
         {
            //Properly terminate the string with a NULL character
            buffer[length] = '\0';
            //Dump HTTP response body
            TRACE_INFO("%s", buffer);
         }
      }

      //Terminate the HTTP response body with a CRLF
      TRACE_INFO("\r\n");

      //Any error to report?
      if(error != ERROR_END_OF_STREAM)
         break;

      //Close HTTP response body
      error = httpClientCloseBody(&httpClientContext);
      //Any error to report?
      if(error)
      {
         //Debug message
         TRACE_INFO("Failed to read HTTP response trailer!\r\n");
         break;
      }

      //Gracefully disconnect from the HTTP server
      httpClientDisconnect(&httpClientContext);

      //Debug message
      TRACE_INFO("Connection closed\r\n");

      //End of exception handling block
   } while(0);

   //Release HTTP client context
   httpClientDeinit(&httpClientContext);

   //Return status code
   return error;
}


/**
 * @brief PPP test task
 **/

void pppTestTask(void *param)
{
   error_t error;
   bool_t initialized;
   bool_t connected;
   NetInterface *interface;

   //Initialize variables
   initialized = FALSE;
   connected = FALSE;

   //Point to the PPP network interface
   interface = &netInterface[0];

   //Endless loop
   while(1)
   {
      //SW1 button pressed?
      if(!(PORTG & SW1_MASK))
      {
         //Modem initialization is performed only once
         if(!initialized)
         {
            //Modem initialization
            error = modemInit(interface);

            //Check status code
            if(error)
            {
               //Debug message
               TRACE_WARNING("Modem initialization failed!\r\n");
            }
            else
            {
               //Successful initialization
               initialized = TRUE;
            }
         }
         else
         {
            //Modem is already initialized
            error = NO_ERROR;
         }

         //Check status code
         if(!error)
         {
            //Check whether the modem is connected
            if(!connected)
            {
               //Establish PPP connection
               error = modemConnect(interface);

               //Check status code
               if(!error)
               {
                  //Update connection state
                  connected = TRUE;
                  //Debug message
                  TRACE_WARNING("PPP connection established\r\n");
               }
               else
               {
                  //Debug message
                  TRACE_WARNING("Failed to established PPP connection!\r\n");
               }
            }
            else
            {
               //Close PPP connetion
               modemDisconnect(interface);
               //Update connection state
               connected = FALSE;

               //Debug message
               TRACE_WARNING("PPP connection closed\r\n");
            }
         }

         //Wait for the SW1 button to be released
         while(!(PORTG & SW1_MASK));
      }

      //SW2 button pressed?
      if(!(PORTF & SW2_MASK))
      {
         //Make sure the PPP connection is established
         if(connected)
         {
            //HTTP client test routine
            httpClientTest();
         }

         //Wait for the SW2 button to be released
         while(!(PORTF & SW2_MASK));
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
      LATGSET = LED1_MASK;
      osDelayTask(100);
      LATGCLR = LED1_MASK;
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

   //System initialization
   systemInit();

   //Initialize kernel
   osInitKernel();
   //Configure debug UART
   debugInit(115200);

   //Start-up message
   TRACE_INFO("\r\n");
   TRACE_INFO("************************************\r\n");
   TRACE_INFO("*** CycloneTCP HTTPS Client Demo ***\r\n");
   TRACE_INFO("************************************\r\n");
   TRACE_INFO("Copyright: 2010-2024 Oryx Embedded SARL\r\n");
   TRACE_INFO("Compiled: %s %s\r\n", __DATE__, __TIME__);
   TRACE_INFO("Target: PIC32MK1024MCM100\r\n");
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

   //Configure the first network interface
   interface = &netInterface[0];

   //Get default PPP settings
   pppGetDefaultSettings(&pppSettings);
   //Select the underlying interface
   pppSettings.interface = interface;
   //Default async control character map
   pppSettings.accm = 0x00000000;
   //Allowed authentication protocols
   pppSettings.authProtocol = PPP_AUTH_PROTOCOL_PAP | PPP_AUTH_PROTOCOL_CHAP_MD5;

   //Initialize PPP
   error = pppInit(&pppContext, &pppSettings);
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize PPP!\r\n");
   }

   //Set interface name
   netSetInterfaceName(interface, APP_IF_NAME);
   //Select the relevant UART driver
   netSetUartDriver(interface, &uartDriver);

   //Initialize network interface
   error = netConfigInterface(interface);
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to configure interface %s!\r\n", interface->name);
   }

   //Set task parameters
   taskParams = OS_TASK_DEFAULT_PARAMS;
   taskParams.stackSize = 500;
   taskParams.priority = OS_TASK_PRIORITY_NORMAL;

   //Create user task
   taskId = osCreateTask("PPP", pppTestTask, NULL, &taskParams);
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
