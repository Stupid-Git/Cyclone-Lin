/**
 * @file spi_driver.c
 * @brief SPI driver
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
#include "core/net.h"
#include "spi_driver.h"
#include "debug.h"

//SPI bitrate
#define SPI_BITRATE 10000000


/**
 * @brief SPI driver
 **/

const SpiDriver spiDriver =
{
   spiInit,
   spiSetMode,
   spiSetBitrate,
   spiAssertCs,
   spiDeassertCs,
   spiTransfer
};


/**
 * @brief SPI initialization
 * @return Error code
 **/

error_t spiInit(void)
{
   //Disable protection
   R_SYSTEM->PRCR = 0xA50B;
   //Cancel SCI0 module stop state
   R_MSTP->MSTPCRB &= ~(R_MSTP_MSTPCRB_MSTPB_Msk << 31);
   //Enable protection
   R_SYSTEM->PRCR = 0xA500;

   //Reset SCI module
   R_SCI0->SCR = 0;

   //Unlock PFS registers
   R_PMISC->PWPR &= ~R_PMISC_PWPR_B0WI_Msk;
   R_PMISC->PWPR |= R_PMISC_PWPR_PFSWE_Msk;

   //Configure CS pin as an output
   R_PFS->PORT[1].PIN[3].PmnPFS = R_PFS_PORT_PIN_PmnPFS_PDR_Msk;
   R_PORT1->PCNTR3 = (1 << 3) << R_PORT0_PCNTR3_POSR_Pos;

   //Configure SCK pin
   R_PFS->PORT[1].PIN[2].PmnPFS = R_PFS_PORT_PIN_PmnPFS_PMR_Msk |
      (4 << R_PFS_PORT_PIN_PmnPFS_PSEL_Pos);

   //Configure MOSI pin
   R_PFS->PORT[1].PIN[1].PmnPFS = R_PFS_PORT_PIN_PmnPFS_PMR_Msk |
      (4 << R_PFS_PORT_PIN_PmnPFS_PSEL_Pos);

   //Configure MISO pin
   R_PFS->PORT[1].PIN[0].PmnPFS = R_PFS_PORT_PIN_PmnPFS_PMR_Msk |
      (4 << R_PFS_PORT_PIN_PmnPFS_PSEL_Pos);

   //Lock PFS registers
   R_PMISC->PWPR &= ~R_PMISC_PWPR_PFSWE_Msk;
   R_PMISC->PWPR |= R_PMISC_PWPR_B0WI_Msk;

   //Select simple SPI mode
   R_SCI0->SMR = R_SCI0_SMR_CM_Msk;
   //Select master mode
   R_SCI0->SPMR = R_SCI0_SPMR_CKPH_Msk | R_SCI0_SPMR_MSS_Msk;
   //Set data transfer direction (MSB first)
   R_SCI0->SCMR |= R_SCI0_SCMR_SDIR_Msk;
   //Set bit rate
   R_SCI0->BRR = 1;

   //Enable SCI module
   R_SCI0->SCR = R_SCI0_SCR_TE_Msk | R_SCI0_SCR_RE_Msk;

   //Successful processing
   return NO_ERROR;
}


/**
 * @brief Set SPI mode
 * @param mode SPI mode (0, 1, 2 or 3)
 **/

error_t spiSetMode(uint_t mode)
{
   //Not implemented
   return ERROR_NOT_IMPLEMENTED;
}


/**
 * @brief Set SPI bitrate
 * @param bitrate Bitrate value
 **/

error_t spiSetBitrate(uint_t bitrate)
{
   //Not implemented
   return ERROR_NOT_IMPLEMENTED;
}


/**
 * @brief Assert CS
 **/

void spiAssertCs(void)
{
   //Assert CS signal
   R_PORT1->PCNTR3 = (1 << 3) << R_PORT0_PCNTR3_PORR_Pos;
   //CS setup time
   usleep(1);
}


/**
 * @brief Deassert CS
 **/

void spiDeassertCs(void)
{
   //CS hold time
   usleep(1);
   //Deassert CS signal
   R_PORT1->PCNTR3 = (1 << 3) << R_PORT0_PCNTR3_POSR_Pos;
   //CS disable time
   usleep(1);
}


/**
 * @brief Transfer a single byte
 * @param[in] data The data to be written
 * @return The data received from the slave device
 **/

uint8_t spiTransfer(uint8_t data)
{
   //Wait for the transmitter to be ready
   while((R_SCI0->SSR & R_SCI0_SSR_TEND_Msk) == 0)
   {
   }

   //Start to transfer data
   R_SCI0->TDR = data;

   //Wait for the operation to complete
   while((R_SCI0->SSR & R_SCI0_SSR_TEND_Msk) == 0)
   {
   }

   //Get the received character
   data = R_SCI0->RDR;

   //Return the received character
   return data;
}
