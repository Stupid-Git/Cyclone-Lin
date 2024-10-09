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
#include "pic32c.h"
#include "debug.h"


/**
 * @brief Debug UART initialization
 * @param[in] baudrate UART baudrate
 **/

void debugInit(uint32_t baudrate)
{
   uint32_t temp;

   //Enable SERCOM5 core clock
   GCLK_REGS->GCLK_PCHCTRL[SERCOM5_GCLK_ID_CORE] = GCLK_PCHCTRL_GEN_GCLK1 |
      GCLK_PCHCTRL_CHEN_Msk;

   //Wait for synchronization
   while((GCLK_REGS->GCLK_PCHCTRL[SERCOM5_GCLK_ID_CORE] & GCLK_PCHCTRL_CHEN_Msk) == 0)
   {
   }

   //Enable PORT bus clock (CLK_PORT_APB)
   MCLK_REGS->MCLK_CLKMSK[PORT_MCLK_ID_APB / 32] |= (1U << (PORT_MCLK_ID_APB % 32));
   //Enable SERCOM5 bus clock (CLK_SERCOM5_APB)
   MCLK_REGS->MCLK_CLKMSK[SERCOM5_MCLK_ID_APB / 32] |= (1U << (SERCOM5_MCLK_ID_APB % 32));

   //Configure TXD pin (PA24)
   PORT_REGS->GROUP[0].PORT_PINCFG[24] |= PORT_PINCFG_PMUXEN_Msk;
   temp = PORT_REGS->GROUP[0].PORT_PMUX[12] & ~PORT_PMUX_PMUXE_Msk;
   PORT_REGS->GROUP[0].PORT_PMUX[12] = temp | PORT_PMUX_PMUXE(MUX_PA24C_SERCOM5_PAD0);

   //Configure RXD pin (PA25)
   PORT_REGS->GROUP[0].PORT_PINCFG[25] |= PORT_PINCFG_PULLEN_Msk;
   PORT_REGS->GROUP[0].PORT_PINCFG[25] |= PORT_PINCFG_PMUXEN_Msk;
   temp = PORT_REGS->GROUP[0].PORT_PMUX[12] & ~PORT_PMUX_PMUXO_Msk;
   PORT_REGS->GROUP[0].PORT_PMUX[12] = temp | PORT_PMUX_PMUXO(MUX_PA25C_SERCOM5_PAD1);

   //Perform software reset
   SERCOM5_REGS->USART_INT.SERCOM_CTRLA = SERCOM_USART_INT_CTRLA_SWRST_Msk;

   //Resetting the SERCOM (CTRLA.SWRST) requires synchronization
   while((SERCOM5_REGS->USART_INT.SERCOM_SYNCBUSY & SERCOM_USART_INT_SYNCBUSY_SWRST_Msk) != 0)
   {
   }

   //Configure SERCOM5
   SERCOM5_REGS->USART_INT.SERCOM_CTRLA = SERCOM_USART_INT_CTRLA_DORD_Msk |
      SERCOM_USART_INT_CTRLA_RXPO_PAD1 | SERCOM_USART_INT_CTRLA_TXPO_PAD0 |
      SERCOM_USART_INT_CTRLA_SAMPR_ARITHM16X |
      SERCOM_USART_INT_CTRLA_MODE_USART_INT_CLK;

   SERCOM5_REGS->USART_INT.SERCOM_CTRLB = SERCOM_USART_INT_CTRLB_TXEN_Msk |
      SERCOM_USART_INT_CTRLB_RXEN_Msk | SERCOM_USART_INT_CTRLB_CHSIZE_8_BIT;

   //Writing to the CTRLB register when the SERCOM is enabled requires
   //synchronization
   while((SERCOM5_REGS->USART_INT.SERCOM_SYNCBUSY & SERCOM_USART_INT_SYNCBUSY_CTRLB_Msk) != 0)
   {
   }

   //Configure baud rate
   SERCOM5_REGS->USART_INT.SERCOM_BAUD = 65535 - ((baudrate * 16384) / (SystemCoreClock / 128));

   //Enable SERCOM5
   SERCOM5_REGS->USART_INT.SERCOM_CTRLA |= SERCOM_USART_INT_CTRLA_ENABLE_Msk;

   //Enabling and disabling the SERCOM requires synchronization
   while((SERCOM5_REGS->USART_INT.SERCOM_SYNCBUSY & SERCOM_USART_INT_SYNCBUSY_ENABLE_Msk) != 0)
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
      SERCOM5_REGS->USART_INT.SERCOM_DATA = c;

      //Wait for the transfer to complete
      while((SERCOM5_REGS->USART_INT.SERCOM_INTFLAG & SERCOM_USART_INT_INTFLAG_TXC_Msk) == 0)
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
