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
#include "samd21.h"
#include "debug.h"


/**
 * @brief Debug UART initialization
 * @param[in] baudrate UART baudrate
 **/

void debugInit(uint32_t baudrate)
{
   //Enable SERCOM4 core clock
   GCLK->CLKCTRL.reg = GCLK_CLKCTRL_CLKEN | GCLK_CLKCTRL_GEN_GCLK0 |
      GCLK_CLKCTRL_ID_SERCOM4_CORE;

   //Wait for synchronization
   while((GCLK->STATUS.reg & GCLK_STATUS_SYNCBUSY) != 0)
   {
   }

   //Enable PORT bus clock (CLK_PORT_APB)
   PM->APBBMASK.bit.PORT_ = 1;
   //Enable SERCOM4 bus clock (CLK_SERCOM4_APB)
   PM->APBCMASK.bit.SERCOM4_ = 1;

   //Configure TXD pin (PB10)
   PORT->Group[1].PINCFG[10].bit.PMUXEN = 1;
   PORT->Group[1].PMUX[5].bit.PMUXE = MUX_PB10D_SERCOM4_PAD2;

   //Configure RXD pin (PB11)
   PORT->Group[1].PINCFG[11].bit.PULLEN = 1;
   PORT->Group[1].PINCFG[11].bit.PMUXEN = 1;
   PORT->Group[1].PMUX[5].bit.PMUXO = MUX_PB11D_SERCOM4_PAD3;

   //Perform software reset
   SERCOM4->USART.CTRLA.reg = SERCOM_USART_CTRLA_SWRST;

   //Resetting the SERCOM (CTRLA.SWRST) requires synchronization
   while((SERCOM4->USART.SYNCBUSY.reg & SERCOM_USART_SYNCBUSY_SWRST) != 0)
   {
   }

   //Configure SERCOM4
   SERCOM4->USART.CTRLA.reg = SERCOM_USART_CTRLA_DORD |
      SERCOM_USART_CTRLA_RXPO(3) | SERCOM_USART_CTRLA_TXPO(1) |
      SERCOM_USART_CTRLA_SAMPR(0) | SERCOM_USART_CTRLA_MODE(1);

   SERCOM4->USART.CTRLB.reg = SERCOM_USART_CTRLB_TXEN |
      SERCOM_USART_CTRLB_RXEN | SERCOM_USART_CTRLB_CHSIZE(0);

   //Writing to the CTRLB register when the SERCOM is enabled requires
   //synchronization
   while((SERCOM4->USART.SYNCBUSY.reg & SERCOM_USART_SYNCBUSY_CTRLB) != 0)
   {
   }

   //Configure baud rate
   SERCOM4->USART.BAUD.reg = 65535 - ((baudrate * 16384) / (SystemCoreClock / 64));

   //Enable SERCOM4
   SERCOM4->USART.CTRLA.reg |= SERCOM_USART_CTRLA_ENABLE;

   //Enabling and disabling the SERCOM requires synchronization
   while((SERCOM4->USART.SYNCBUSY.reg & SERCOM_USART_SYNCBUSY_ENABLE) != 0)
   {
   }
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
      //Send character
      SERCOM4->USART.DATA.reg = c;
      //Wait for the transfer to complete
      while((SERCOM4->USART.INTFLAG.reg & SERCOM_USART_INTFLAG_TXC) == 0)
      {
      }

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
