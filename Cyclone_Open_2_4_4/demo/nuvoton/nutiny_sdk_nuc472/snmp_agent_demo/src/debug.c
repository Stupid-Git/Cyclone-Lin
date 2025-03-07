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
#include "nuc472_442.h"
#include "debug.h"


/**
 * @brief Debug UART initialization
 * @param[in] baudrate UART baudrate
 **/

void debugInit(uint32_t baudrate)
{
   uint32_t temp;

   //Enable UART0 clock
   CLK_EnableModuleClock(UART0_MODULE);

   //Select UART0 clock source
   CLK_SetModuleClock(UART0_MODULE, CLK_CLKSEL1_UARTSEL_HXT,
      CLK_CLKDIV0_UART(1));

   //Configure UART0_RXD (PG.1) and UART0_TXD (PG.2)
   temp = SYS->GPG_MFPL;
   temp = (temp & ~SYS_GPG_MFPL_PG1MFP_Msk) | SYS_GPG_MFPL_PG1MFP_UART0_RXD;
   temp = (temp & ~SYS_GPG_MFPL_PG2MFP_Msk) | SYS_GPG_MFPL_PG2MFP_UART0_TXD;
   SYS->GPG_MFPL = temp;

   //Configure UART0
   UART_Open(UART0, baudrate);
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
   //Standard output or error output?
   if(stream == stdout || stream == stderr)
   {
       //Wait for the transmitter to be ready
      while(UART0->FIFOSTS & UART_FIFOSTS_TXFULL_Msk);
      //Send character
      UART0->DAT = c;
      //Wait for the transfer to complete
      while(!(UART0->FIFOSTS & UART_FIFOSTS_TXEMPTY_Msk));

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
