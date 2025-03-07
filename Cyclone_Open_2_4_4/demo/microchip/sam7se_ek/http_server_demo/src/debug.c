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
#include "sam7se_ek.h"
#include "debug.h"


/**
 * @brief Debug UART initialization
 * @param[in] baudrate UART baudrate
 **/

void debugInit(uint32_t baudrate)
{
   //Disable interrupts on DTXD and DRXD pins
   AT91C_BASE_PIOA->PIO_IDR = AT91C_PA10_DTXD | AT91C_PA9_DRXD;
   //No pull-up resistors
   AT91C_BASE_PIOA->PIO_PPUDR = AT91C_PA10_DTXD | AT91C_PA9_DRXD;
   //Assign corresponding pins to Peripheral A function
   AT91C_BASE_PIOA->PIO_ASR = AT91C_PA10_DTXD | AT91C_PA9_DRXD;
   //Disable the PIO from controlling the corresponding pins
   AT91C_BASE_PIOA->PIO_PDR = AT91C_PA10_DTXD | AT91C_PA9_DRXD;

   //Reset transmitter and receiver
   AT91C_BASE_DBGU->DBGU_CR = AT91C_US_RSTTX | AT91C_US_RSTRX;
   //Disable interrupts
   AT91C_BASE_DBGU->DBGU_IDR = 0xFFFFFFFF;

   //Configure baud rate
   AT91C_BASE_DBGU->DBGU_BRGR = AT91B_MCK / (16 * baudrate);

   //Configure mode register
   AT91C_BASE_DBGU->DBGU_MR = AT91C_US_CHMODE_NORMAL | AT91C_US_PAR_NONE;

   //Disable DMA channel
   AT91C_BASE_DBGU->DBGU_PTCR = AT91C_PDC_TXTDIS | AT91C_PDC_RXTDIS;

   //Enable transmitter and receiver
   AT91C_BASE_DBGU->DBGU_CR = AT91C_US_TXEN | AT91C_US_RXEN;
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
      while(!(AT91C_BASE_DBGU->DBGU_CSR & AT91C_US_TXEMPTY));
      //Send character
      AT91C_BASE_DBGU->DBGU_THR = c;
      //Wait for the transfer to complete
      while(!(AT91C_BASE_DBGU->DBGU_CSR & AT91C_US_TXEMPTY));

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
