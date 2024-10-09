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
#include "em_device.h"
#include "em_cmu.h"
#include "em_gpio.h"
#include "em_usart.h"
#include "debug.h"


/**
 * @brief Debug UART initialization
 * @param[in] baudrate UART baudrate
 **/

void debugInit(uint32_t baudrate)
{
   uint32_t temp;

   //Default USART initialization
   USART_InitAsync_TypeDef usartInit = USART_INITASYNC_DEFAULT;

   //Enable high-frequency peripheral clock
   CMU_ClockEnable(cmuClock_HFPER, true);
   //Enable GPIO clock
   CMU_ClockEnable(cmuClock_GPIO, true);
   //Enable USART4 clock
   CMU_ClockEnable(cmuClock_USART4, true);

   //Configure USART4 TX pin (PH4)
   GPIO_PinModeSet(gpioPortH, 4, gpioModePushPull, 1);
   //Configure USART4 RX pin (PH5)
   GPIO_PinModeSet(gpioPortH, 5, gpioModeInput, 1);
   //Configure EFM_BC_EN pin (PE1)
   GPIO_PinModeSet(gpioPortE, 1, gpioModePushPull, 1);

   //Set baudrate
   usartInit.baudrate = baudrate;
   //Configure USART4
   USART_InitAsync(USART4, &usartInit);

   //Remap USART4 pins
   temp = USART4->ROUTELOC0 & ~(_USART_ROUTELOC0_TXLOC_MASK | _USART_ROUTELOC0_RXLOC_MASK);
   USART4->ROUTELOC0 = temp | (USART_ROUTELOC0_TXLOC_LOC4 | USART_ROUTELOC0_RXLOC_LOC4);

   //Enable USART4 pins
   USART4->ROUTEPEN = USART_ROUTEPEN_TXPEN | USART_ROUTEPEN_RXPEN;
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
      while (!(USART4->STATUS & USART_STATUS_TXBL));
      //Send character
      USART4->TXDATA = (uint32_t) c;
      //Wait for the transfer to complete
      while (!(USART4->STATUS & USART_STATUS_TXBL));

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
