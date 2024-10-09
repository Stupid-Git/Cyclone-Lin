/**
 * @file debug.c
 * @brief Debugging facilities
 *
 * @section License
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * Copyright (C) 2010-2020 Oryx Embedded SARL. All rights reserved.
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
#include "tc_inc_path.h"
#include TC_INCLUDE(TCPATH/Ifx_reg.h)
#include TC_INCLUDE(TCPATH/IfxAsclin_bf.h)
#include "debug.h"

//Set baudrate generation parameters
#define UART_FSYS 100000000
#define UART_PRESCALER 10
#define UART_OVERSAMPLING 16
#define UART_DENOMINATOR 3125

//Function declaration
void lcdPutChar(char_t c);


/**
 * @brief Debug UART initialization
 * @param[in] baudrate UART baudrate
 **/

void debugInit(uint32_t baudrate)
{
   uint32_t numerator;

   //Calculate the numerator of the fractional divider
   numerator = baudrate / (UART_FSYS / (UART_PRESCALER * UART_DENOMINATOR * UART_OVERSAMPLING));

   //Configure TXD pin (P14.0/ATX0)
   MODULE_P14.IOCR0.B.PC0 = 18;
   //Configure RXD pin (P14.1/ARX0A)
   MODULE_P14.IOCR0.B.PC1 = 2;

   //Unlock sequence
   unlock_wdtcon();

   //Enable ASCLIN module
   MODULE_ASCLIN0.CLC.U = 0;

   //Set speed grade for TXD and RXD pins
   MODULE_P14.PDR0.B.PD0 = 0;
   MODULE_P14.PDR0.B.PD1 = 0;

   //Lock sequence
   lock_wdtcon();

   //Deactivate the clock source
   MODULE_ASCLIN0.CSR.U = 0;

   //Select P14.1/ARX0A as RXD pin
   MODULE_ASCLIN0.IOCR.B.ALTI = 0;

   //Configure TX FIFO
   MODULE_ASCLIN0.TXFIFOCON.U = 0;
   MODULE_ASCLIN0.TXFIFOCON.B.INTLEVEL = 15;
   MODULE_ASCLIN0.TXFIFOCON.B.INW = 1;
   MODULE_ASCLIN0.TXFIFOCON.B.ENO = 1;
   MODULE_ASCLIN0.TXFIFOCON.B.FLUSH = 1;

   //Configure RX FIFO
   MODULE_ASCLIN0.RXFIFOCON.U = 0;
   MODULE_ASCLIN0.RXFIFOCON.B.OUTW = 1;
   MODULE_ASCLIN0.RXFIFOCON.B.ENI = 1;
   MODULE_ASCLIN0.RXFIFOCON.B.FLUSH = 1;

   //Set prescaler and oversampling factor
   MODULE_ASCLIN0.BITCON.U = 0;
   MODULE_ASCLIN0.BITCON.B.SM = 1;
   MODULE_ASCLIN0.BITCON.B.SAMPLEPOINT = (UART_OVERSAMPLING / 2);
   MODULE_ASCLIN0.BITCON.B.OVERSAMPLING = UART_OVERSAMPLING - 1;
   MODULE_ASCLIN0.BITCON.B.PRESCALER = UART_PRESCALER - 1;

   //Set frame format (1 stop bit, no parity)
   MODULE_ASCLIN0.FRAMECON.U = 0;
   MODULE_ASCLIN0.FRAMECON.B.STOP = 1;
   MODULE_ASCLIN0.FRAMECON.B.PEN = 0;

   //Set character width (8 bits)
   MODULE_ASCLIN0.DATCON.B.DATLEN = 7;

   //Set baudrate value
   MODULE_ASCLIN0.BRG.B.NUMERATOR = numerator;
   MODULE_ASCLIN0.BRG.B.DENOMINATOR = UART_DENOMINATOR;

   //Select ASC mode
   MODULE_ASCLIN0.FRAMECON.B.MODE = 1;

   //Select FCLC as clock source
   MODULE_ASCLIN0.CSR.B.CLKSEL = 1;

   //Set TXFIFO refill interrupt flag
   MODULE_ASCLIN0.FLAGSSET.U = (IFX_ASCLIN_FLAGSCLEAR_TFLC_MSK << IFX_ASCLIN_FLAGSCLEAR_TFLC_OFF);
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
       //Wait until TXFIFO level falls to INTLEVEL or below
       while(MODULE_ASCLIN0.FLAGS.B.TFL == 0)
       {
       }

       //Clear TXFIFO refill interrupt flag
       MODULE_ASCLIN0.FLAGSCLEAR.U = (IFX_ASCLIN_FLAGSCLEAR_TFLC_MSK << IFX_ASCLIN_FLAGSCLEAR_TFLC_OFF);

       //Send character
       MODULE_ASCLIN0.TXDATA.U = (uint8_t) c;

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

