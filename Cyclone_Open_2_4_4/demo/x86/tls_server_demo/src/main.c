/**
 * @file main.c
 * @brief TLS server demo
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

//Platform-specific dependencies
#ifdef _WIN32
   #define _CRTDBG_MAP_ALLOC
   #define _WINERROR_
   #include <crtdbg.h>
   #include <winsock2.h>
   #include <ws2tcpip.h>
#else
   #include <sys/random.h>
   #include <sys/types.h>
   #include <sys/socket.h>
   #include <netinet/in.h>
   #include <arpa/inet.h>
   #include <netdb.h>
   #include <unistd.h>
   #include <errno.h>
#endif

//Dependencies
#include <stdlib.h>
#include "tls.h"
#include "tls_cipher_suites.h"
#include "tls_ticket.h"
#include "tls_misc.h"
#include "rng/yarrow.h"
#include "debug.h"

//Libraries
#ifdef _WIN32
   #pragma comment(lib, "ws2_32.lib")
#endif

//Server port
#define APP_SERVER_PORT 4433

//Diffie-Hellman parameters
#define APP_SERVER_DH_PARAMS "../certs/dh_params.pem"

//Server's RSA certificate and private key
#define APP_SERVER_RSA_CERT "../certs/server_rsa_cert.pem"
#define APP_SERVER_RSA_PRIVATE_KEY "../certs/server_rsa_key.pem"

//Server's DSA certificate and private key
#define APP_SERVER_DSA_CERT "../certs/server_dsa_cert.pem"
#define APP_SERVER_DSA_PRIVATE_KEY "../certs/server_dsa_key.pem"

//Server's ECDSA certificate and private key
#define APP_SERVER_ECDSA_CERT "../certs/server_ecdsa_cert.pem"
#define APP_SERVER_ECDSA_PRIVATE_KEY "../certs/server_ecdsa_key.pem"

//Trusted CA bundle
#define APP_CA_CERT_BUNDLE "../certs/ca_cert_bundle.pem"

//Server's PSK identity hint
#define APP_SERVER_PSK_IDENTITY_HINT ""

//Client's PSK identity
#define APP_CLIENT1_PSK_IDENTITY "Client1"
#define APP_CLIENT2_PSK_IDENTITY "Client2"

//Client's PSK
const uint8_t client1Psk[] = {
   0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
   0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF};

const uint8_t client2Psk[] = {
   0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef,
   0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef};

//Credentials
char_t *dhParams = NULL;
size_t dhParamsLength = 0;
char_t *serverRsaCert = NULL;
size_t serverRsaCertLength = 0;
char_t *serverRsaPrivateKey = NULL;
size_t serverRsaPrivateKeyLength = 0;
char_t *serverDsaCert = NULL;
size_t serverDsaCertLength = 0;
char_t *serverDsaPrivateKey = NULL;
size_t serverDsaPrivateKeyLength = 0;
char_t *serverEcdsaCert = NULL;
size_t serverEcdsaCertLength = 0;
char_t *serverEcdsaPrivateKey = NULL;
size_t serverEcdsaPrivateKeyLength = 0;
char_t *trustedCaList = NULL;
size_t trustedCaListLength = 0;

//Pseudo-random number generator
YarrowContext yarrowContext;

//Session cache
TlsCache *tlsCache = NULL;
//Session ticket encryption context
TlsTicketContext tlsTicketContext;

//Hit counter
uint_t hitCounter = 0;

//Forward declaration of functions
error_t processClientRequest(intptr_t clientSocket);
error_t readPemFile(const char_t *filename, char_t **buffer, size_t *length);
const char_t *dumpArray(char_t *buffer, const uint8_t *data, size_t length);

error_t tlsSendCallback(TlsSocketHandle socket, const void *data,
   size_t length, size_t *written, uint_t flags);

error_t tlsReceiveCallback(TlsSocketHandle socket, void *data,
   size_t size, size_t *received, uint_t flags);

error_t tlsPskCallback(TlsContext *context, const uint8_t *pskIdentity,
   size_t pskIdentityLen);


/**
 * @brief Main entry point
 * @return Unused value
 **/

int_t main(void)
{
   error_t error;
   int_t ret;
   socklen_t clientAddrLen;
   struct sockaddr_in serverAddr;
   struct sockaddr_in clientAddr;
#ifdef _WIN32
   WSADATA wsaData;
   HCRYPTPROV hProvider;
#endif
   uint8_t seed[32];

   //Server socket descriptor
   intptr_t serverSocket = -1;
   //Client socket descriptor
   intptr_t clientSocket = -1;

   //Start-up message
   TRACE_INFO("**********************************\r\n");
   TRACE_INFO("*** CycloneSSL TLS Server Demo ***\r\n");
   TRACE_INFO("**********************************\r\n");
   TRACE_INFO("\r\n");

#ifdef _WIN32
   //Acquire cryptographic context
   ret = CryptAcquireContext(&hProvider, 0, 0, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT | CRYPT_SILENT);
   //Any error to report?
   if(!ret)
   {
      //Debug message
      TRACE_ERROR("Error: Cannot acquire cryptographic context (%d)\r\n", GetLastError());
      //Exit immediately
      return ERROR_FAILURE;
   }

   //Generate a random seed
   ret = CryptGenRandom(hProvider, sizeof(seed), seed);
   //Any error to report?
   if(!ret)
   {
      //Debug message
      TRACE_ERROR("Error: Failed to generate random data (%d)\r\n", GetLastError());
      //Exit immediately
      return ERROR_FAILURE;
   }

   //Release cryptographic context
   CryptReleaseContext(hProvider, 0);
#else
   //Generate a random seed
   ret = getrandom(seed, sizeof(seed), GRND_RANDOM);
   //Any error to report?
   if(ret < 0)
   {
      //Debug message
      TRACE_ERROR("Error: Failed to generate random data (%d)\r\n", errno);
      //Exit immediately
      return ERROR_FAILURE;
   }
#endif

   //PRNG initialization
   error = yarrowInit(&yarrowContext);
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Error: PRNG initialization failed (%d)\r\n", error);
      //Exit immediately
      return ERROR_FAILURE;
   }

   //Properly seed the PRNG
   error = yarrowSeed(&yarrowContext, seed, sizeof(seed));
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Error: Failed to seed PRNG (%d)\r\n", error);
      //Exit immediately
      return error;
   }

#ifdef _WIN32
   //Winsock initialization
   ret = WSAStartup(MAKEWORD(2, 2), &wsaData);
   //Any error to report?
   if(ret)
   {
      //Debug message
      TRACE_ERROR("Error: Winsock initialization failed (%d)\r\n", ret);
      //Exit immediately
      return ERROR_FAILURE;
   }
#endif

   //Start of exception handling block
   do
   {
      //Debug message
      TRACE_INFO("Loading credentials...\r\n");

      //Load Diffie-Hellman parameters
      error = readPemFile(APP_SERVER_DH_PARAMS,  &dhParams, &dhParamsLength);
      //Any error to report?
      if(error)
         break;

      //Load server's RSA certificate
      error = readPemFile(APP_SERVER_RSA_CERT, &serverRsaCert, &serverRsaCertLength);
      //Any error to report?
      if(error)
         break;

      //Load server's RSA private key
      error = readPemFile(APP_SERVER_RSA_PRIVATE_KEY, &serverRsaPrivateKey, &serverRsaPrivateKeyLength);
      //Any error to report?
      if(error)
         break;

      //Load server's DSA certificate
      error = readPemFile(APP_SERVER_DSA_CERT, &serverDsaCert, &serverDsaCertLength);
      //Any error to report?
      if(error)
         break;

      //Load server's DSA private key
      error = readPemFile(APP_SERVER_DSA_PRIVATE_KEY, &serverDsaPrivateKey, &serverDsaPrivateKeyLength);
      //Any error to report?
      if(error)
         break;

      //Load server's ECDSA certificate
      error = readPemFile(APP_SERVER_ECDSA_CERT, &serverEcdsaCert, &serverEcdsaCertLength);
      //Any error to report?
      if(error)
         break;

      //Load server's ECDSA private key
      error = readPemFile(APP_SERVER_ECDSA_PRIVATE_KEY, &serverEcdsaPrivateKey, &serverEcdsaPrivateKeyLength);
      //Any error to report?
      if(error)
         break;

      //Load trusted CA certificates
      error = readPemFile(APP_CA_CERT_BUNDLE, &trustedCaList, &trustedCaListLength);
      //Any error to report?
      if(error)
         break;

      //TLS session cache initialization
      tlsCache = tlsInitCache(16);
      //Any error to report?
      if(!tlsCache)
      {
         //Debug message
         TRACE_ERROR("Error: TLS cache initialization failed\r\n");
         //Report an error
         error = ERROR_FAILURE;
         //Exit immediately
         break;
      }

#if (TLS_TICKET_SUPPORT == ENABLED)
      //Initialize ticket encryption context
      error = tlsInitTicketContext(&tlsTicketContext);
      //Any error to report?
      if(error)
         break;
#endif

      //Open a socket
      serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
      //Failed to open socket?
      if(serverSocket < 0)
      {
         //Debug message
         TRACE_ERROR("Error: Cannot open socket\r\n");
         //Report an error
         error = ERROR_FAILURE;
         //Exit immediately
         break;
      }

      //Server port
      serverAddr.sin_family = AF_INET;
      serverAddr.sin_addr.s_addr = INADDR_ANY;
      serverAddr.sin_port = htons(APP_SERVER_PORT);

      //Bind the socket to the relevant port number
      ret = bind(serverSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));
      //Any error to report?
      if(ret < 0)
      {
         //Debug message
         TRACE_ERROR("Error: Failed to bind socket\r\n");
         //Report an error
         error = ERROR_FAILURE;
         //Exit immediately
         break;
      }

      //Place the socket in the listening state
      ret = listen(serverSocket, 10);
      //Any error to report?
      if(ret < 0)
      {
         //Debug message
         TRACE_ERROR("Error: Failed to enter listening state\r\n");
         //Report an error
         error = ERROR_FAILURE;
         //Exit immediately
         break;
      }

      //Main loop
      while(1)
      {
         //Debug message
         TRACE_INFO("\r\n\r\n");
         TRACE_INFO("Waiting for an incoming connection...\r\n\r\n");

         //Initialize address length
         clientAddrLen = sizeof(clientAddr);

         //Accept a new connection request
         clientSocket = accept(serverSocket, (struct sockaddr *) &clientAddr, &clientAddrLen);
         //Any error to report?
         if(clientSocket < 0)
         {
            //Debug message
            TRACE_ERROR("Error: Cannot accept new connection request\r\n");
            //Report an error
            error = ERROR_FAILURE;
            //Exit immediately
            break;
         }

         //Increment hit counter
         hitCounter++;

         //Debug message
         TRACE_INFO("Connection #%u established with client %s port %u...\r\n",
            hitCounter, inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));

         //Process incoming request
         error = processClientRequest(clientSocket);

         //Failed to service client request?
         if(error)
         {
            //Debug message
            TRACE_ERROR("Error: Failed to process client request (%d)\r\n", error);
         }

         //Debug message
         TRACE_INFO("Closing connection...\r\n");

         //Close socket
#ifdef _WIN32
         closesocket(clientSocket);
#else
         close(clientSocket);
#endif
      }

   //End of exception handling block
   } while(0);

   //Close server socket if necessary
   if(serverSocket >= 0)
   {
#ifdef _WIN32
         closesocket(serverSocket);
#else
         close(serverSocket);
#endif
   }

   //Release session cache
   tlsFreeCache(tlsCache);

#if (TLS_TICKET_SUPPORT == ENABLED)
   //Release ticket encryption context
   tlsFreeTicketContext(&tlsTicketContext);
#endif

   //Free previously allocated resources
   free(dhParams);
   free(serverRsaCert);
   free(serverRsaPrivateKey);
   free(serverDsaCert);
   free(serverDsaPrivateKey);
   free(serverEcdsaCert);
   free(serverEcdsaPrivateKey);
   free(trustedCaList);

   //Release PRNG context
   yarrowRelease(&yarrowContext);

#ifdef _WIN32
   //Winsock related cleanup
   WSACleanup();
   //Dumps all the memory blocks in the heap when a memory leak has occurred
   _CrtDumpMemoryLeaks();

   //Wait for the user to press a key
   system("pause");
#else
   //Debug message
   TRACE_INFO("Press any key to continue...\r\n");
   //Wait for the user to press a key
   getchar();
#endif

   //Return status code
   return error;
}


/**
 * @brief Process incoming request
 * @param[in] clientSocket Socket descriptor
 * @return Error code
 **/

error_t processClientRequest(intptr_t clientSocket)
{
   error_t error;
   size_t n;
   char_t *p;
   char_t buffer[512];
   char_t response[2048];
   TlsContext *tlsContext;

   //Start of exception handling block
   do
   {
      //Initialize TLS context
      tlsContext = tlsInit();
      //Initialization failed?
      if(tlsContext == NULL)
      {
         //Report an error
         error = ERROR_OUT_OF_MEMORY;
         //Exit immediately
         break;
      }

      //Select server operation mode
      error = tlsSetConnectionEnd(tlsContext, TLS_CONNECTION_END_SERVER);
      //Any error to report?
      if(error)
         break;

      //Set send and receive callbacks (I/O abstraction layer)
      error = tlsSetSocketCallbacks(tlsContext, tlsSendCallback,
         tlsReceiveCallback, (TlsSocketHandle) clientSocket);
      //Any error to report?
      if(error)
         break;

      //Set the PRNG algorithm to be used
      error = tlsSetPrng(tlsContext, YARROW_PRNG_ALGO, &yarrowContext);
      //Any error to report?
      if(error)
         break;

      //Session cache that will be used to save/resume TLS sessions
      error = tlsSetCache(tlsContext, tlsCache);
      //Any error to report?
      if(error)
         break;

      //Client authentication is optional
      error = tlsSetClientAuthMode(tlsContext, TLS_CLIENT_AUTH_OPTIONAL);
      //Any error to report?
      if(error)
         break;

      //Enable secure renegotiation
      error = tlsEnableSecureRenegotiation(tlsContext, TRUE);
      //Any error to report?
      if(error)
         break;

#if (TLS_DHE_RSA_KE_SUPPORT == ENABLED || TLS_DHE_DSS_KE_SUPPORT == ENABLED || TLS_DH_ANON_KE_SUPPORT == ENABLED)
      //Import Diffie-Hellman parameters
      error = tlsSetDhParameters(tlsContext, dhParams, dhParamsLength);
      //Any error to report?
      if(error)
         break;
#endif

      //Load server's RSA certificate
      error = tlsLoadCertificate(tlsContext, 0, serverRsaCert,
         serverRsaCertLength, serverRsaPrivateKey,
         serverRsaPrivateKeyLength, NULL);
      //Any error to report?
      if(error)
         break;

#if (TLS_DHE_DSS_KE_SUPPORT == ENABLED)
      //Load server's DSA certificate
      error = tlsLoadCertificate(tlsContext, 1, serverDsaCert,
         serverDsaCertLength, serverDsaPrivateKey,
         serverDsaPrivateKeyLength, NULL);
      //Any error to report?
      if(error)
         break;
#endif

      //Load server's ECDSA certificate
      error = tlsLoadCertificate(tlsContext, 2, serverEcdsaCert,
         serverEcdsaCertLength, serverEcdsaPrivateKey,
         serverEcdsaPrivateKeyLength, NULL);
      //Any error to report?
      if(error)
         break;

      //Import the list of trusted CA certificates
      error = tlsSetTrustedCaList(tlsContext, trustedCaList, strlen(trustedCaList));
      //Any error to report?
      if(error)
         break;

#if (TLS_PSK_SUPPORT == ENABLED)
      //Set the PSK identity hint to be used by the server
      error = tlsSetPskIdentityHint(tlsContext, APP_SERVER_PSK_IDENTITY_HINT);
      //Any error to report?
      if(error)
         break;

      //Register PSK callback function
      error = tlsSetPskCallback(tlsContext, tlsPskCallback);
      //Any error to report?
      if(error)
         break;
#endif

#if (TLS_TICKET_SUPPORT == ENABLED)
      //Enable session ticket mechanism
      error = tlsEnableSessionTickets(tlsContext, TRUE);
      //Any error to report?
      if(error)
         break;

      //Register ticket encryption/decryption callbacks
      error = tlsSetTicketCallbacks(tlsContext, tlsEncryptTicket,
         tlsDecryptTicket, &tlsTicketContext);
      //Any error to report?
      if(error)
         break;
#endif

      //Establish a secure session
      error = tlsConnect(tlsContext);
      //TLS handshake failure?
      if(error)
         break;

      //Debug message
      TRACE_INFO("\r\n");
      TRACE_INFO("HTTP request:\r\n");

      //Read HTTP request
      while(1)
      {
         //Read a complete line
         error = tlsRead(tlsContext, buffer, sizeof(buffer) - 1, &n, TLS_FLAG_BREAK_CRLF);
         //Any error to report?
         if(error)
            break;

         //Properly terminate the string with a NULL character
         buffer[n] = '\0';
         //Dump HTTP request
         TRACE_INFO("%s", buffer);

         //The end of the header has been reached?
         if(!strcmp(buffer, "\r\n"))
            break;
      }

      //Propagate exception if necessary...
      if(error)
         break;

      //Point to the beginning of the response
      p = response;

      //Format response
      p += sprintf(p, "HTTP/1.0 200 OK\r\n");
      p += sprintf(p, "Content-Type: text/html\r\n");
      p += sprintf(p, "\r\n");

      p += sprintf(p, "<!DOCTYPE html>\r\n");
      p += sprintf(p, "<html>\r\n");
      p += sprintf(p, "<head>\r\n");
      p += sprintf(p, "  <title>Oryx Embedded - CycloneSSL Server Demo</title>\r\n");
      p += sprintf(p, "  <style>\r\n");
      p += sprintf(p, "    body {font-family: monospace; font-size: 13px;}\r\n");
      p += sprintf(p, "    table {border-width: 1px; border-style: ouset; border-collapse: collapse;}\r\n");
      p += sprintf(p, "    td {border-width: 1px; border-style: inset; padding: 3px;}\r\n");
      p += sprintf(p, "  </style>\r\n");
      p += sprintf(p, "</head>\r\n");
      p += sprintf(p, "<body>\r\n");
      p += sprintf(p, "  <p>Welcome to the CycloneSSL demo server!</p>\r\n");
      p += sprintf(p, "  <table>\r\n");

      p += sprintf(p, "  <tr>\r\n");
      p += sprintf(p, "    <td>Hit counter</td>\r\n");
      p += sprintf(p, "    <td>%d</td>\r\n", hitCounter);
      p += sprintf(p, "  </tr>\r\n");

      p += sprintf(p, "  <tr>\r\n");
      p += sprintf(p, "    <td>Server version</td>\r\n");
      p += sprintf(p, "    <td>%s</td>\r\n", tlsGetVersionName(tlsContext->versionMax));
      p += sprintf(p, "  </tr>\r\n");

      p += sprintf(p, "  <tr>\r\n");
      p += sprintf(p, "    <td>Client version</td>\r\n");
      p += sprintf(p, "    <td>%s</td>\r\n",
         tlsGetVersionName(MAX(tlsContext->clientVersion, tlsContext->version)));
      p += sprintf(p, "  </tr>\r\n");

      p += sprintf(p, "  <tr>\r\n");
      p += sprintf(p, "    <td>Negotiated version</td>\r\n");
      p += sprintf(p, "    <td>%s</td>\r\n", tlsGetVersionName(tlsContext->version));
      p += sprintf(p, "  </tr>\r\n");

      p += sprintf(p, "  <tr>\r\n");
      p += sprintf(p, "    <td>Cipher suite</td>\r\n");
      p += sprintf(p, "    <td>%s</td>\r\n", tlsGetCipherSuiteName(tlsContext->cipherSuite.identifier));
      p += sprintf(p, "  </tr>\r\n");

      p += sprintf(p, "  <tr>\r\n");
      p += sprintf(p, "    <td>Client random</td>\r\n");
      p += sprintf(p, "      <td>\r\n");
      p += sprintf(p, "        %s\r\n", dumpArray(buffer, (uint8_t *) &tlsContext->clientRandom, 32));
      p += sprintf(p, "      </td>\r\n");
      p += sprintf(p, "  </tr>\r\n");

      p += sprintf(p, "  <tr>\r\n");
      p += sprintf(p, "    <td>Server random</td>\r\n");
      p += sprintf(p, "      <td>\r\n");
      p += sprintf(p, "        %s\r\n", dumpArray(buffer, (uint8_t *) &tlsContext->serverRandom, 32));
      p += sprintf(p, "      </td>\r\n");
      p += sprintf(p, "  </tr>\r\n");

      p += sprintf(p, "  <tr>\r\n");
      p += sprintf(p, "    <td>Session ID</td>\r\n");
      p += sprintf(p, "      <td>\r\n");
      p += sprintf(p, "        %s\r\n", dumpArray(buffer, tlsContext->sessionId, tlsContext->sessionIdLen));
      p += sprintf(p, "      </td>\r\n");
      p += sprintf(p, "  </tr>\r\n");

      p += sprintf(p, "  </table>\r\n");
      p += sprintf(p, "</body>\r\n");
      p += sprintf(p, "</html>\r\n");

      //Dump HTTP response
      TRACE_INFO("HTTP response:\r\n");
      TRACE_INFO("%s\r\n", response);

      //Send response to the client
      error = tlsWrite(tlsContext, response, strlen(response), NULL, 0);
      //Any error to report?
      if(error)
         break;

      //Terminate TLS session
      error = tlsShutdown(tlsContext);
      //Any error to report?
      if(error)
         break;

      //End of exception handling block
   } while(0);

   //Release TLS context
   tlsFree(tlsContext);

   //Return status code
   return error;
}


/**
 * @brief Load the specified PEM file
 * @param[in] filename Name of the PEM file to load
 * @param[out] buffer Memory buffer that holds the contents of the file
 * @param[out] length Length of the file in bytes
 * @return Error code
 **/

error_t readPemFile(const char_t *filename, char_t **buffer, size_t *length)
{
   int_t ret;
   error_t error;
   FILE *fp;

   //Initialize output parameters
   *buffer = NULL;
   *length = 0;

   //Start of exception handling block
   do
   {
      //Open the specified file
      fp = fopen(filename, "rb");

      //Failed to open the file?
      if(fp == NULL)
      {
         error = ERROR_OPEN_FAILED;
         break;
      }

      //Jump to the end of the file
      ret = fseek(fp, 0, SEEK_END);

      //Any error to report?
      if(ret != 0)
      {
         error = ERROR_FAILURE;
         break;
      }

      //Retrieve the length of the file
      *length = ftell(fp);
      //Allocate a buffer to hold the contents of the file
      *buffer = malloc(*length);

      //Failed to allocate memory?
      if(*buffer == NULL)
      {
         error = ERROR_OUT_OF_MEMORY;
         break;
      }

      //Rewind to the beginning of the file
      rewind(fp);
      //Read file contents
      ret = fread(*buffer, 1, *length, fp);

      //Failed to read data?
      if(ret != *length)
      {
         error = ERROR_READ_FAILED;
         break;
      }

      //Successful processing
      error = NO_ERROR;

      //End of exception handling block
   } while(0);

   //Close file
   if(fp != NULL)
      fclose(fp);

   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Error: Cannot load file %s\r\n", filename);
      //Clean up side effects
      free(*buffer);
   }

   //Return status code
   return error;
}


/**
 * @brief Display the contents of an array
 * @param[out] buffer Output buffer where to format the resulting string
 * @param[in] data Pointer to the data array
 * @param[in] length Number of bytes in the array
 * @return Pointer to the output buffer
 **/

const char_t *dumpArray(char_t *buffer, const uint8_t *data, size_t length)
{
   size_t i;
   char_t *p;

   //Point to the output buffer
   p = buffer;
   //Properly terminate the string
   p[0] = '\0';

   //Process input data
   for(i = 0; i < length; i++)
   {
      //Beginning of a new line?
      if(i != 0 && (i % 16) == 0)
         p += sprintf(p, "\r\n        ");
      //Display current data byte
      p += sprintf(p, "%02X ", data[i]);
   }

   //Return a pointer the output string
   return buffer;
}


/**
 * @brief TLS send callback (I/O abstraction layer)
 * @param[in] socket Handle that identifies a socket
 * @param[in] data Pointer to a buffer containing the data to be transmitted
 * @param[in] length Number of data bytes to send
 * @param[out] written Number of bytes that have been transmitted
 * @param[in] flags Unused parameter
 * @return Error code
 **/

error_t tlsSendCallback(TlsSocketHandle socket, const void *data,
   size_t length, size_t *written, uint_t flags)
{
   int_t n;
   error_t error;

   //Send data
   n = send((intptr_t) socket, data, length, 0);

   //Check return value
   if(n > 0)
   {
      //Total number of data that have been written
      *written = n;
      //Successful write operation
      error = NO_ERROR;
   }
   else
   {
#ifdef _WIN32
      //Timeout error?
      if(WSAGetLastError() == WSAEWOULDBLOCK)
      {
         error = ERROR_TIMEOUT;
      }
      else
      {
         error = ERROR_WRITE_FAILED;
      }
#else
      //Timeout error?
      if(errno == EAGAIN || errno == EWOULDBLOCK)
      {
         error = ERROR_TIMEOUT;
      }
      else
      {
         error = ERROR_WRITE_FAILED;
      }
#endif
   }

   //Return status code
   return error;
}


/**
 * @brief TLS receive callback (I/O abstraction layer)
 * @param[in] socket Handle that identifies a socket
 * @param[out] data Buffer where to store the incoming data
 * @param[in] size Maximum number of bytes that can be received
 * @param[out] received Number of bytes that have been received
 * @param[in] flags Unused parameter
 * @return Error code
 **/

error_t tlsReceiveCallback(TlsSocketHandle socket, void *data,
   size_t size, size_t *received, uint_t flags)
{
   int_t n;
   error_t error;

   //Receive data
   n = recv((intptr_t) socket, data, size, 0);

   //Check return value
   if(n > 0)
   {
      //Total number of data that have been received
      *received = n;
      //Successful write operation
      error = NO_ERROR;
   }
   else
   {
#ifdef _WIN32
      //Timeout error?
      if(WSAGetLastError() == WSAEWOULDBLOCK)
      {
         error = ERROR_TIMEOUT;
      }
      else
      {
         error = ERROR_READ_FAILED;
      }
#else
      //Timeout error?
      if(errno == EAGAIN || errno == EWOULDBLOCK)
      {
         error = ERROR_TIMEOUT;
      }
      else
      {
         error = ERROR_READ_FAILED;
      }
#endif
   }

   //Return status code
   return error;
}


/**
 * @brief PSK callback function
 * @param[in] context Pointer to the TLS context
 * @param[in] pskIdentity PSK identity of the client
 * @param[in] pskIdentityLen Length of the PSK identity, in bytes
 * @return Error code
 **/

error_t tlsPskCallback(TlsContext *context, const uint8_t *pskIdentity,
   size_t pskIdentityLen)
{
   error_t error;

   //Check PSK identity
   if(pskIdentityLen == strlen(APP_CLIENT1_PSK_IDENTITY) &&
      !memcmp(pskIdentity, APP_CLIENT1_PSK_IDENTITY, pskIdentityLen))
   {
      //Set the pre-shared key to be used
      error = tlsSetPsk(context, client1Psk, sizeof(client1Psk));
   }
   else if(pskIdentityLen == strlen(APP_CLIENT2_PSK_IDENTITY) &&
      !memcmp(pskIdentity, APP_CLIENT2_PSK_IDENTITY, pskIdentityLen))
   {
      //Set the pre-shared key to be used
      error = tlsSetPsk(context, client2Psk, sizeof(client2Psk));
   }
   else
   {
      //Unknown PSK identity
      error = ERROR_UNKNOWN_IDENTITY;
   }

   //Return status code
   return error;
}
