/**
 * @file private_mib_impl.c
 * @brief Private MIB module implementation
 *
 * @section License
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * Copyright (C) 2010-2024 Oryx Embedded SARL. All rights reserved.
 *
 * This file is part of CycloneTCP Open.
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
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <intrinsics.h>
#include <iorx63n.h>
#include "yrdkrx63n.h"
#include "core/net.h"
#include "private_mib_module.h"
#include "private_mib_impl.h"
#include "core/crypto.h"
#include "encoding/asn1.h"
#include "encoding/oid.h"
#include "debug.h"

//Mutex preventing simultaneous access to the private MIB base
static OsMutex privateMibMutex;


/**
 * @brief Private MIB module initialization
 * @return Error code
 **/

error_t privateMibInit(void)
{
   //Debug message
   TRACE_INFO("Initializing private MIB base...\r\n");

   //Clear private MIB base
   memset(&privateMibBase, 0, sizeof(privateMibBase));

   //Default value for testString object
   strcpy(privateMibBase.testString, "Hello World!");
   privateMibBase.testStringLen = strlen(privateMibBase.testString);

   //Default value for testInteger object
   privateMibBase.testInteger = 123;

   //Number of LEDs
   privateMibBase.ledCount = PRIVATE_MIB_LED_COUNT;

   //LED1 color
   strcpy(privateMibBase.ledTable[0].ledColor, "green");
   privateMibBase.ledTable[0].ledColorLen = strlen(privateMibBase.ledTable[0].ledColor);
   //LED1 state
   privateMibBase.ledTable[0].ledState = 0;

   //LED2 color
   strcpy(privateMibBase.ledTable[1].ledColor, "orange");
   privateMibBase.ledTable[1].ledColorLen = strlen(privateMibBase.ledTable[1].ledColor);
   //LED2 state
   privateMibBase.ledTable[1].ledState = 0;

   //LED3 color
   strcpy(privateMibBase.ledTable[2].ledColor, "red");
   privateMibBase.ledTable[2].ledColorLen = strlen(privateMibBase.ledTable[2].ledColor);
   //LED3 state
   privateMibBase.ledTable[2].ledState = 0;

   //Create a mutex to prevent simultaneous access to the private MIB base
   if(!osCreateMutex(&privateMibMutex))
   {
      //Failed to create mutex
      return ERROR_OUT_OF_RESOURCES;
   }

   //Successful processing
   return NO_ERROR;
}


/**
 * @brief Load private MIB module
 * @param[in] context Pointer to the SNMP agent context
 * @return Error code
 **/

error_t privateMibLoad(void *context)
{
   //Successful processing
   return NO_ERROR;
}


/**
 * @brief Unload private MIB module
 * @param[in] context Pointer to the SNMP agent context
 **/

void privateMibUnload(void *context)
{
}


/**
 * @brief Lock private MIB base
 **/

void privateMibLock(void)
{
   //Enter critical section
   osAcquireMutex(&privateMibMutex);
}


/**
 * @brief Unlock private MIB base
 **/

void privateMibUnlock(void)
{
   //Leave critical section
   osReleaseMutex(&privateMibMutex);
}


/**
 * @brief Get currentTime object value
 * @param[in] object Pointer to the MIB object descriptor
 * @param[in] oid Object identifier (object name and instance identifier)
 * @param[in] oidLen Length of the OID, in bytes
 * @param[out] value Object value
 * @param[in,out] valueLen Length of the object value, in bytes
 * @return Error code
 **/

error_t privateMibGetCurrentTime(const MibObject *object, const uint8_t *oid,
   size_t oidLen, MibVariant *value, size_t *valueLen)
{
   //Get object value
   value->timeTicks = osGetSystemTime64() / 10;
   //Successful processing
   return NO_ERROR;
}


/**
 * @brief Set ledEntry object value
 * @param[in] object Pointer to the MIB object descriptor
 * @param[in] oid Object identifier (object name and instance identifier)
 * @param[in] oidLen Length of the OID, in bytes
 * @param[in] value Object value
 * @param[in] valueLen Length of the object value, in bytes
 * @param[in] commit This flag tells whether the changes shall be committed
 *   to the MIB base
 * @return Error code
 **/

error_t privateMibSetLedEntry(const MibObject *object, const uint8_t *oid,
   size_t oidLen, const MibVariant *value, size_t valueLen, bool_t commit)
{
   error_t error;
   size_t n;
   uint_t index;
   PrivateMibLedEntry *entry;

   //Point to the end of the OID prefix
   n = object->oidLen;

   //Get the instance identifier
   error = mibDecodeIndex(oid, oidLen, &n, &index);
   //Invalid instance identifier?
   if(error)
      return error;

   //Check index range
   if(index < 1 || index > PRIVATE_MIB_LED_COUNT)
      return ERROR_INSTANCE_NOT_FOUND;

   //Point to the LED table entry
   entry = &privateMibBase.ledTable[index - 1];

   //ledState object?
   if(!strcmp(object->name, "ledState"))
   {
      //Check whether the changes shall be committed to the MIB base
      if(commit)
      {
         //Set object value
         entry->ledState = value->integer;

         //Update LED state
         if(index == 1)
         {
            if(entry->ledState)
               LED11 = LED_ON;
            else
               LED11 = LED_OFF;
         }
         else if(index == 2)
         {
            if(entry->ledState)
               LED10 = LED_ON;
            else
               LED10 = LED_OFF;
         }
         else if(index == 3)
         {
            if(entry->ledState)
               LED9 = LED_ON;
            else
               LED9 = LED_OFF;
         }
      }
   }
   //Unknown object?
   else
   {
      //The specified object does not exist
      return ERROR_OBJECT_NOT_FOUND;
   }

   //Successful processing
   return NO_ERROR;
}


/**
 * @brief Get ledEntry object value
 * @param[in] object Pointer to the MIB object descriptor
 * @param[in] oid Object identifier (object name and instance identifier)
 * @param[in] oidLen Length of the OID, in bytes
 * @param[out] value Object value
 * @param[in,out] valueLen Length of the object value, in bytes
 * @return Error code
 **/

error_t privateMibGetLedEntry(const MibObject *object, const uint8_t *oid,
   size_t oidLen, MibVariant *value, size_t *valueLen)
{
   error_t error;
   size_t n;
   uint_t index;
   PrivateMibLedEntry *entry;

   //Point to the end of the OID prefix
   n = object->oidLen;

   //Get the instance identifier
   error = mibDecodeIndex(oid, oidLen, &n, &index);
   //Invalid instance identifier?
   if(error)
      return error;

   //Check index range
   if(index < 1 || index > PRIVATE_MIB_LED_COUNT)
      return ERROR_INSTANCE_NOT_FOUND;

   //Point to the LED table entry
   entry = &privateMibBase.ledTable[index - 1];

   //ledColor object?
   if(!strcmp(object->name, "ledColor"))
   {
      //Make sure the buffer is large enough to hold the entire object
      if(*valueLen < entry->ledColorLen)
         return ERROR_BUFFER_OVERFLOW;

      //Copy object value
      memcpy(value->octetString, entry->ledColor, entry->ledColorLen);
      //Return object length
      *valueLen = entry->ledColorLen;
   }
   //ledState object?
   else if(!strcmp(object->name, "ledState"))
   {
      //Get object value
      value->integer = entry->ledState;
   }
   //Unknown object?
   else
   {
      //The specified object does not exist
      return ERROR_OBJECT_NOT_FOUND;
   }

   //Successful processing
   return NO_ERROR;
}


/**
 * @brief Get next ledEntry object
 * @param[in] object Pointer to the MIB object descriptor
 * @param[in] oid Object identifier
 * @param[in] oidLen Length of the OID, in bytes
 * @param[out] nextOid OID of the next object in the MIB
 * @param[out] nextOidLen Length of the next object identifier, in bytes
 * @return Error code
 **/

error_t privateMibGetNextLedEntry(const MibObject *object, const uint8_t *oid,
   size_t oidLen, uint8_t *nextOid, size_t *nextOidLen)
{
   error_t error;
   size_t n;
   uint_t index;

   //Make sure the buffer is large enough to hold the OID prefix
   if(*nextOidLen < object->oidLen)
      return ERROR_BUFFER_OVERFLOW;

   //Copy OID prefix
   memcpy(nextOid, object->oid, object->oidLen);

   //Loop through LED table
   for(index = 1; index <= PRIVATE_MIB_LED_COUNT; index++)
   {
      //Point to the end of the OID prefix
      n = object->oidLen;

      //Append the instance identifier to the OID prefix
      error = mibEncodeIndex(nextOid, *nextOidLen, &n, index);
      //Any error to report?
      if(error)
         return error;

      //Check whether the resulting object identifier lexicographically
      //follows the specified OID
      if(oidComp(nextOid, n, oid, oidLen) > 0)
      {
         //Save the length of the resulting object identifier
         *nextOidLen = n;
         //Next object found
         return NO_ERROR;
      }
   }

   //The specified OID does not lexicographically precede the name
   //of some object
   return ERROR_OBJECT_NOT_FOUND;
}
