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
#include "system_pic32cxmtg.h"
#include "debug.h"


/**
 * @brief Debug UART initialization
 * @param[in] baudrate UART baudrate
 **/

void debugInit(uint32_t baudrate)
{
   uint32_t temp;

   //Enable PIOA peripheral clock
   PMC_REGS->PMC_PCR = PMC_PCR_PID(ID_PIOA);
   temp = PMC_REGS->PMC_PCR;
   PMC_REGS->PMC_PCR = temp | PMC_PCR_CMD_Msk | PMC_PCR_EN_Msk;
   
   //Enable FLEXCOM0 peripheral clock
   PMC_REGS->PMC_PCR = PMC_PCR_PID(ID_FLEXCOM0);
   temp = PMC_REGS->PMC_PCR;
   PMC_REGS->PMC_PCR = temp | PMC_PCR_CMD_Msk | PMC_PCR_EN_Msk;

   //Set FLEXCOM operation mode
   FLEXCOM0_REGS->FLEX_MR = FLEX_MR_OPMODE_USART;

   //Configure PA4 pin (FLEXCOM0_IO0)
   PIO0_REGS->PIO_GROUP[0].PIO_MSKR = PIO_PA4;
   PIO0_REGS->PIO_GROUP[0].PIO_CFGR = PIO_CFGR_FUNC_PERIPH_A;

   //Configure PA5 pin (FLEXCOM0_IO1)
   PIO0_REGS->PIO_GROUP[0].PIO_MSKR = PIO_PA5;
   PIO0_REGS->PIO_GROUP[0].PIO_CFGR = PIO_CFGR_FUNC_PERIPH_A;

   //Reset transmitter and receiver
   FLEXCOM0_REGS->FLEX_US_CR = FLEX_US_CR_RSTSTA_Msk | FLEX_US_CR_RSTTX_Msk | FLEX_US_CR_RSTRX_Msk;
   //Disable interrupts
   FLEXCOM0_REGS->FLEX_US_IDR = 0xFFFFFFFF;

   //Configure baud rate
   FLEXCOM0_REGS->FLEX_US_BRGR = FLEX_US_BRGR_CD(SystemCoreClock / (32 * baudrate));

   //Configure mode register
   FLEXCOM0_REGS->FLEX_US_MR = FLEX_US_MR_USART_MODE_NORMAL |
      FLEX_US_MR_CHRL_8_BIT | FLEX_US_MR_PAR_NO;

   //Enable transmitter and receiver
   FLEXCOM0_REGS->FLEX_US_CR = FLEX_US_CR_TXEN_Msk | FLEX_US_CR_RXEN_Msk;
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
      while((FLEXCOM0_REGS->FLEX_US_CSR & FLEX_US_CSR_TXEMPTY_Msk) == 0)
      {
      }

      //Send character
      FLEXCOM0_REGS->FLEX_US_THR = c;

      //Wait for the transfer to complete
      while((FLEXCOM0_REGS->FLEX_US_CSR & FLEX_US_CSR_TXEMPTY_Msk) == 0)
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
