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
#include "mpc5748g.h"
#include "core/net.h"
#include "spi_driver.h"
#include "debug.h"


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
   //Configure CS0_5 (PF7)
   SIUL2->MSCR[87] = SIUL2_MSCR_OBE_MASK | SIUL2_MSCR_SMC_MASK;
   //Deassert CS pin
   SIUL2->GPDO[87] = 1;

   //Configure SCLK_5 (PF6)
   SIUL2->MSCR[86] = SIUL2_MSCR_SRC(3) | SIUL2_MSCR_OBE_MASK |
      SIUL2_MSCR_SMC_MASK | SIUL2_MSCR_SSS(3);

   //Configure SOUT_5 (PF4)
   SIUL2->MSCR[84] = SIUL2_MSCR_SRC(3) | SIUL2_MSCR_OBE_MASK |
      SIUL2_MSCR_SMC_MASK | SIUL2_MSCR_SSS(3);

   //Configure SIN_5 (PF5)
   SIUL2->MSCR[85] = SIUL2_MSCR_SMC_MASK | SIUL2_MSCR_IBE_MASK;
   SIUL2->IMCR[315] = SIUL2_IMCR_SSS(1);

   //Select master mode of operation
   SPI_5->MCR = SPI_MCR_MSTR_MASK | SPI_MCR_PCSIS(1) | SPI_MCR_CLR_TXF_MASK |
      SPI_MCR_CLR_RXF_MASK | SPI_MCR_HALT_MASK;

   //Configure SPI mode and baud rate
   SPI_5->MODE.CTAR[0] = SPI_CTAR_FMSZ(7) | SPI_CTAR_CPOL(0) | SPI_CTAR_CPHA(1) |
      SPI_CTAR_CSSCK(4) | SPI_CTAR_ASC(4) | SPI_CTAR_DT(4) | SPI_CTAR_BR(3);

   //Exit HALT mode
   SPI_5->MCR &= ~SPI_MCR_HALT_MASK;

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
   SIUL2->GPDO[87] = 0;
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
   SIUL2->GPDO[87] = 1;
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
   uint8_t temp;

   //Start to transfer data
   SPI_5->PUSHR.PUSHR = data;

   //Wait for the operation to complete
   while((SPI_5->SR & SPI_SR_RFDF_MASK) == 0)
   {
   }

   //Get the received character
   temp = SPI_5->POPR;

   //Clear RFDF flag
   SPI_5->SR = SPI_SR_RFDF_MASK;

   //Return the received character
   return temp;
}
