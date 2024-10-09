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
#include "fsl_device_registers.h"
#include "debug.h"


/**
 * @brief Debug UART initialization
 * @param[in] baudrate UART baudrate
 **/

void debugInit(uint32_t baudrate)
{
   uint32_t div;
   uint32_t moduleClockFreq;

   //LPUART1 module clock frequency
   moduleClockFreq = SystemCoreClock / 2;
   //Compute baudrate divisor
   div = (moduleClockFreq / 8) / baudrate;

   //Enable PORTC peripheral clock
   PCC->PCCn[PCC_PORTC_INDEX] = PCC_PCCn_CGC_MASK;
   //Enable LPUART1 peripheral clock (SPLLDIV2_CLK clock source)
   PCC->PCCn[PCC_LPUART1_INDEX] = PCC_PCCn_CGC_MASK | PCC_PCCn_PCS(6);

   //Configure PTC6 (LPUART1_RX) and PTC7 (LPUART1_TX)
   PORTC->PCR[6] = PORT_PCR_MUX(2);
   PORTC->PCR[7] = PORT_PCR_MUX(2);

   //Reset LPUART1 module
   LPUART1->GLOBAL |= LPUART_GLOBAL_RST_MASK;
   LPUART1->GLOBAL &= ~LPUART_GLOBAL_RST_MASK;

   //Configure LPUART1 (8-bit mode, no parity)
   LPUART1->CTRL = LPUART_CTRL_M(0) | LPUART_CTRL_PE(0);

   //Select oversampling ratio and baudrate
   LPUART1->BAUD = LPUART_BAUD_OSR(7) | LPUART_BAUD_SBR(div);

   //Set transmit and receive FIFO watermark
   LPUART1->WATER = LPUART_WATER_RXWATER(1) | LPUART_WATER_TXWATER(0);

   //Enable transmitter and receiver
   LPUART1->CTRL |= LPUART_CTRL_TE_MASK | LPUART_CTRL_RE_MASK;
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
      while(!(LPUART1->STAT & LPUART_STAT_TDRE_MASK));
      //Send character
      LPUART1->DATA = c;
      //Wait for the transfer to complete
      while(!(LPUART1->STAT & LPUART_STAT_TDRE_MASK));

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
