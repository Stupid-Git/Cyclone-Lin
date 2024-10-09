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
#include "ftp/ftp_client.h"
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
#define APP_FTP_SERVER_NAME "test.rebex.net"
#define APP_FTP_IMPLICIT_TLS ENABLED
#define APP_FTP_EXPLICIT_TLS DISABLED
#define APP_FTP_LOGIN "demo"
#define APP_FTP_PASSWORD "password"
#define APP_FTP_FILENAME "readme.txt"

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
PppSettings pppSettings;
PppContext pppContext;
FtpClientContext ftpClientContext;
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
 * @param[in] context Pointer to the FTP client context
 * @param[in] tlsContext Pointer to the TLS context
 * @return Error code
 **/

error_t ftpClientTlsInitCallback(FtpClientContext *context,
   TlsContext *tlsContext)
{
   error_t error;

   //Debug message
   TRACE_INFO("FTP Client: TLS initialization callback\r\n");

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
   error = tlsSetServerName(tlsContext, APP_FTP_SERVER_NAME);
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
 * @brief FTP client test routine
 * @return Error code
 **/

error_t ftpClientTest(void)
{
   error_t error;
   size_t n;
   IpAddr ipAddr;
   char_t buffer[128];

   //Initialize FTP client context
   ftpClientInit(&ftpClientContext);

   //Start of exception handling block
   do
   {
      //Debug message
      TRACE_INFO("\r\n\r\nResolving server name...\r\n");

      //Resolve FTP server name
      error = getHostByName(NULL, APP_FTP_SERVER_NAME, &ipAddr, 0);
      //Any error to report?
      if(error)
      {
         //Debug message
         TRACE_INFO("Failed to resolve server name!\r\n");
         break;
      }

#if (APP_FTP_IMPLICIT_TLS == ENABLED || APP_FTP_EXPLICIT_TLS == ENABLED)
      //Register TLS initialization callback
      error = ftpClientRegisterTlsInitCallback(&ftpClientContext,
         ftpClientTlsInitCallback);
      //Any error to report?
      if(error)
         break;
#endif

      //Set timeout value for blocking operations
      error = ftpClientSetTimeout(&ftpClientContext, 20000);
      //Any error to report?
      if(error)
         break;

      //Debug message
      TRACE_INFO("Connecting to FTP server %s...\r\n",
         ipAddrToString(&ipAddr, NULL));

#if (APP_FTP_IMPLICIT_TLS == ENABLED)
      //Connect to the FTP server (implicit FTPS)
      error = ftpClientConnect(&ftpClientContext, &ipAddr, 990,
         FTP_MODE_IMPLICIT_TLS | FTP_MODE_PASSIVE);
#elif (APP_FTP_EXPLICIT_TLS == ENABLED)
      //Connect to the FTP server (explicit FTPS)
      error = ftpClientConnect(&ftpClientContext, &ipAddr, 21,
         FTP_MODE_EXPLICIT_TLS | FTP_MODE_PASSIVE);
#else
      //Connect to the FTP server (no security)
      error = ftpClientConnect(&ftpClientContext, &ipAddr, 21,
         FTP_MODE_PLAINTEXT | FTP_MODE_PASSIVE);
#endif

      //Any error to report?
      if(error)
      {
         //Debug message
         TRACE_INFO("Failed to connect to FTP server!\r\n");
         break;
      }

      //Login to the FTP server using the provided username and password
      error = ftpClientLogin(&ftpClientContext, APP_FTP_LOGIN, APP_FTP_PASSWORD);
      //Any error to report?
      if(error)
         break;

      //Open the specified file for reading
      error = ftpClientOpenFile(&ftpClientContext, APP_FTP_FILENAME,
         FTP_FILE_MODE_READ | FTP_FILE_MODE_BINARY);
      //Any error to report?
      if(error)
         break;

      //Read the contents of the file
      while(!error)
      {
         //Read data
         error = ftpClientReadFile(&ftpClientContext, buffer, sizeof(buffer) - 1, &n, 0);

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
      error = ftpClientCloseFile(&ftpClientContext);
      //Any error to report?
      if(error)
         break;

      //Gracefully disconnect from the FTP server
      ftpClientDisconnect(&ftpClientContext);

      //Debug message
      TRACE_INFO("Connection closed\r\n");

      //End of exception handling block
   } while(0);

   //Release FTP client context
   ftpClientDeinit(&ftpClientContext);

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
            //FTP client test routine
            ftpClientTest();
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
   TRACE_INFO("***********************************\r\n");
   TRACE_INFO("*** CycloneTCP FTPS Client Demo ***\r\n");
   TRACE_INFO("***********************************\r\n");
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
