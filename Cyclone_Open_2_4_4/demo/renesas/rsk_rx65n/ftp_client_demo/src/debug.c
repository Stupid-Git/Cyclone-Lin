/**
 * @file debug.c
 * @brief Debugging facilities
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
#include <iorx65n.h>
#include "debug.h"

//Function declaration
void lcdPutChar(char_t c);


/**
 * @brief Debug UART initialization
 * @param[in] baudrate UART baudrate
 **/

void debugInit(uint32_t baudrate)
{
   //All-module clock stop mode is disabled
   SYSTEM.MSTPCRA.BIT.ACSE = 0;

   //Disable protection
   SYSTEM.PRCR.WORD = 0xA50B;
   //Cancel SCI2 module stop state
   MSTP(SCI2) = 0;
   //Enable protection
   SYSTEM.PRCR.WORD = 0xA500;

   //Disable SCI2 module
   SCI2.SCR.BYTE = 0x00;

   //Unlock MPC registers
   MPC.PWPR.BIT.B0WI = 0;
   MPC.PWPR.BIT.PFSWE = 1;

   //Configure TXD2 (P50)
   PORT5.PMR.BIT.B0 = 1;
   MPC.P50PFS.BYTE = 0x0A;

   //Configure RXD2 (P52)
   PORT5.PMR.BIT.B2 = 1;
   MPC.P52PFS.BYTE = 0x0A;

   //Lock MPC registers
   MPC.PWPR.BIT.PFSWE = 0;
   MPC.PWPR.BIT.B0WI = 0;

   //Configure UART (8 bits, no parity, 1 stop bit)
   SCI2.SMR.BYTE = 0;
   //Select serial communication mode
   SCI2.SCMR.BIT.SMIF = 0;
   //Enable double-speed mode
   SCI2.SEMR.BIT.ABCS = 1;
   //Set baudrate
   SCI2.BRR = configPERIPHERAL_CLOCK_HZ / (16 * baudrate) - 1;

   //Enable transmission and reception
   SCI2.SCR.BYTE |= 0x30;
}


/**
 * @brief Display the contents of an array
 * @param[in] stream Pointer to a FILE object that identifies an output stream
 * @param[in] prepend String to prepend to the left of each line
 * @param[in] data Pointer to the data array
 * @param[in] length Number of bytes to display
 **/

void debugDisplayArray(FILE *stream,
   const char_t *prepend, const void *data, size_t length)
{
   uint_t i;

   for(i = 0; i < length; i++)
   {
      //Beginning of a new line?
      if((i % 16) == 0)
         fprintf(stream, "%s", prepend);
      //Display current data byte
      fprintf(stream, "%02" PRIX8 " ", *((uint8_t *) data + i));
      //End of current line?
      if((i % 16) == 15 || i == (length - 1))
         fprintf(stream, "\r\n");
   }
}


/**
 * @brief Write character to stream
 * @param[in] c The character to be written
 * @param[in] stream Pointer to a FILE object that identifies an output stream
 * @return On success, the character written is returned. If a writing
 *   error occurs, EOF is returned
 **/

int_t fputc(int_t c, FILE *stream)
{
   //Standard output?
   if(stream == stdout)
   {
      //Display current character
      lcdPutChar(c);

      //On success, the character written is returned
      return c;
   }
   //Standard error output?
   else if(stream == stderr)
   {
      //Wait for the transmitter to be ready
      while(!SCI2.SSR.BIT.TEND);
      //Send character
      SCI2.TDR = c;
      //Wait for the transfer to complete
      while(!SCI2.SSR.BIT.TEND);

      //On success, the character written is returned
      return c;
   }
   //Unknown output?
   else
   {
      //If a writing error occurs, EOF is returned
      return EOF;
   }
}
