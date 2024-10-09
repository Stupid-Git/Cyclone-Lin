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
#include "bsp_api.h"
#include "debug.h"


/**
 * @brief Debug UART initialization
 * @param[in] baudrate UART baudrate
 **/

void debugInit(uint32_t baudrate)
{
#if 1
   //Disable protection
   R_SYSTEM->PRCR = 0xA50B;
   //Cancel SCI1 module stop state
   R_MSTP->MSTPCRB &= ~(R_MSTP_MSTPCRB_MSTPB_Msk << 30);
   //Enable protection
   R_SYSTEM->PRCR = 0xA500;

   //Disable SCI1 module
   R_SCI1->SCR = 0x00;

   //Unlock PFS registers
   R_PMISC->PWPR &= ~R_PMISC_PWPR_B0WI_Msk;
   R_PMISC->PWPR |= R_PMISC_PWPR_PFSWE_Msk;

   //Configure TXD1 (P7_9)
   R_PFS->PORT[7].PIN[9].PmnPFS = (5 << R_PFS_PORT_PIN_PmnPFS_PSEL_Pos) |
      R_PFS_PORT_PIN_PmnPFS_PMR_Msk | R_PFS_PORT_PIN_PmnPFS_PCR_Msk;

   //Configure RXD1 (P7_8)
   R_PFS->PORT[7].PIN[8].PmnPFS = (5 << R_PFS_PORT_PIN_PmnPFS_PSEL_Pos) |
      R_PFS_PORT_PIN_PmnPFS_PMR_Msk | R_PFS_PORT_PIN_PmnPFS_PCR_Msk;

   //Lock PFS registers
   R_PMISC->PWPR &= ~R_PMISC_PWPR_PFSWE_Msk;
   R_PMISC->PWPR |= R_PMISC_PWPR_B0WI_Msk;

   //Configure UART (8 bits, no parity, 1 stop bit)
   R_SCI1->SMR = 0;
   //Configure prescaler for baud rate generator
   R_SCI1->SEMR = R_SCI0_SEMR_BGDM_Msk | R_SCI0_SEMR_ABCS_Msk;
   //Set baudrate
   R_SCI1->BRR = (SystemCoreClock / 2) / (8 * baudrate) - 1;

   //Enable transmission and reception
   R_SCI1->SCR |= R_SCI0_SCR_TE_Msk | R_SCI0_SCR_RE_Msk;
#else
   //Disable protection
   R_SYSTEM->PRCR = 0xA50B;
   //Cancel SCI6 module stop state
   R_MSTP->MSTPCRB &= ~(R_MSTP_MSTPCRB_MSTPB_Msk << 25);
   //Enable protection
   R_SYSTEM->PRCR = 0xA500;

   //Disable SCI6 module
   R_SCI6->SCR = 0x00;

   //Unlock PFS registers
   R_PMISC->PWPR &= ~R_PMISC_PWPR_B0WI_Msk;
   R_PMISC->PWPR |= R_PMISC_PWPR_PFSWE_Msk;

   //Configure TXD6 (P3_5)
   R_PFS->PORT[3].PIN[5].PmnPFS = (4 << R_PFS_PORT_PIN_PmnPFS_PSEL_Pos) |
      R_PFS_PORT_PIN_PmnPFS_PMR_Msk | R_PFS_PORT_PIN_PmnPFS_PCR_Msk;

   //Configure RXD6 (P3_4)
   R_PFS->PORT[3].PIN[4].PmnPFS = (4 << R_PFS_PORT_PIN_PmnPFS_PSEL_Pos) |
      R_PFS_PORT_PIN_PmnPFS_PMR_Msk | R_PFS_PORT_PIN_PmnPFS_PCR_Msk;

   //Lock PFS registers
   R_PMISC->PWPR &= ~R_PMISC_PWPR_PFSWE_Msk;
   R_PMISC->PWPR |= R_PMISC_PWPR_B0WI_Msk;

   //Configure UART (8 bits, no parity, 1 stop bit)
   R_SCI6->SMR = 0;
   //Configure prescaler for baud rate generator
   R_SCI6->SEMR = R_SCI0_SEMR_BGDM_Msk | R_SCI0_SEMR_ABCS_Msk;
   //Set baudrate
   R_SCI6->BRR = (SystemCoreClock / 2) / (8 * baudrate) - 1;

   //Enable transmission and reception
   R_SCI6->SCR |= R_SCI0_SCR_TE_Msk | R_SCI0_SCR_RE_Msk;
#endif
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
#if 1
      //Wait for the transmitter to be ready
      while((R_SCI1->SSR & R_SCI0_SSR_TEND_Msk) == 0)
      {
      }

      //Send character
      R_SCI1->TDR = c;

      //Wait for the transfer to complete
      while((R_SCI1->SSR & R_SCI0_SSR_TEND_Msk) == 0)
      {
      }
#else
      //Wait for the transmitter to be ready
      while((R_SCI6->SSR & R_SCI0_SSR_TEND_Msk) == 0)
      {
      }

      //Send character
      R_SCI6->TDR = c;

      //Wait for the transfer to complete
      while((R_SCI6->SSR & R_SCI0_SSR_TEND_Msk) == 0)
      {
      }
#endif

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
