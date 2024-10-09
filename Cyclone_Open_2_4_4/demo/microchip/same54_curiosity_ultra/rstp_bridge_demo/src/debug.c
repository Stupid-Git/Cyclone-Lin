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
#include "sam.h"
#include "debug.h"


/**
 * @brief Debug UART initialization
 * @param[in] baudrate UART baudrate
 **/

void debugInit(uint32_t baudrate)
{
   uint32_t temp;

   //Enable SERCOM1 core clock
   GCLK_REGS->GCLK_PCHCTRL[SERCOM1_GCLK_ID_CORE] = GCLK_PCHCTRL_GEN_GCLK0 |
      GCLK_PCHCTRL_CHEN_Msk;

   //Enable PORT bus clock (CLK_PORT_APB)
   MCLK_REGS->MCLK_APBBMASK |= MCLK_APBBMASK_PORT_Msk;
   //Enable SERCOM1 bus clock (CLK_SERCOM1_APB)
   MCLK_REGS->MCLK_APBAMASK |= MCLK_APBAMASK_SERCOM1_Msk;

   //Configure TXD pin (PC27)
   PORT_REGS->GROUP[2].PORT_PINCFG[27] |= PORT_PINCFG_PMUXEN_Msk;
   temp = PORT_REGS->GROUP[2].PORT_PMUX[13] & ~PORT_PMUX_PMUXO_Msk;
   PORT_REGS->GROUP[2].PORT_PMUX[13] = temp | PORT_PMUX_PMUXO(MUX_PC27C_SERCOM1_PAD0);

   //Configure RXD pin (PC28)
   PORT_REGS->GROUP[2].PORT_PINCFG[28] |= PORT_PINCFG_PULLEN_Msk;
   PORT_REGS->GROUP[2].PORT_PINCFG[28] |= PORT_PINCFG_PMUXEN_Msk;
   temp = PORT_REGS->GROUP[2].PORT_PMUX[14] & ~PORT_PMUX_PMUXE_Msk;
   PORT_REGS->GROUP[2].PORT_PMUX[14] = temp | PORT_PMUX_PMUXE(MUX_PC28C_SERCOM1_PAD1);

   //Perform software reset
   SERCOM1_REGS->USART_INT.SERCOM_CTRLA = SERCOM_USART_INT_CTRLA_SWRST_Msk;

   //Resetting the SERCOM (CTRLA.SWRST) requires synchronization
   while((SERCOM1_REGS->USART_INT.SERCOM_SYNCBUSY & SERCOM_USART_INT_SYNCBUSY_SWRST_Msk) != 0)
   {
   }

   //Configure SERCOM1
   SERCOM1_REGS->USART_INT.SERCOM_CTRLA = SERCOM_USART_INT_CTRLA_DORD_Msk |
      SERCOM_USART_INT_CTRLA_RXPO(1) | SERCOM_USART_INT_CTRLA_TXPO(0) |
      SERCOM_USART_INT_CTRLA_SAMPR(0) | SERCOM_USART_INT_CTRLA_MODE(1);

   SERCOM1_REGS->USART_INT.SERCOM_CTRLB = SERCOM_USART_INT_CTRLB_TXEN_Msk |
      SERCOM_USART_INT_CTRLB_RXEN_Msk | SERCOM_USART_INT_CTRLB_CHSIZE(0);

   //Writing to the CTRLB register when the SERCOM is enabled requires
   //synchronization
   while((SERCOM1_REGS->USART_INT.SERCOM_SYNCBUSY & SERCOM_USART_INT_SYNCBUSY_CTRLB_Msk) != 0)
   {
   }

   //Configure baud rate
   SERCOM1_REGS->USART_INT.SERCOM_BAUD = 65535 - ((baudrate * 16384) / (SystemCoreClock / 64));

   //Enable SERCOM1
   SERCOM1_REGS->USART_INT.SERCOM_CTRLA |= SERCOM_USART_INT_CTRLA_ENABLE_Msk;

   //Enabling and disabling the SERCOM requires synchronization
   while((SERCOM1_REGS->USART_INT.SERCOM_SYNCBUSY & SERCOM_USART_INT_SYNCBUSY_ENABLE_Msk) != 0)
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
      SERCOM1_REGS->USART_INT.SERCOM_DATA = c;

      //Wait for the transfer to complete
      while((SERCOM1_REGS->USART_INT.SERCOM_INTFLAG & SERCOM_USART_INT_INTFLAG_TXC_Msk) == 0)
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
