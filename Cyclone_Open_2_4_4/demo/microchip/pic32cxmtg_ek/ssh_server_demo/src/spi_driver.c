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
#include "pic32c.h"
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
   uint32_t temp;

   //Enable PIOA peripheral clock
   PMC_REGS->PMC_PCR = PMC_PCR_PID(ID_PIOA);
   temp = PMC_REGS->PMC_PCR;
   PMC_REGS->PMC_PCR = temp | PMC_PCR_CMD_Msk | PMC_PCR_EN_Msk;

   //Enable FLEXCOM3 peripheral clock
   PMC_REGS->PMC_PCR = PMC_PCR_PID(ID_FLEXCOM3);
   temp = PMC_REGS->PMC_PCR;
   PMC_REGS->PMC_PCR = temp | PMC_PCR_CMD_Msk | PMC_PCR_EN_Msk;

   //Set FLEXCOM operation mode
   FLEXCOM3_REGS->FLEX_MR = FLEX_MR_OPMODE_SPI;

   //Configure PA16 pin (FLEXCOM3_IO0)
   PIO0_REGS->PIO_GROUP[0].PIO_MSKR = PIO_PA16;
   PIO0_REGS->PIO_GROUP[0].PIO_CFGR = PIO_CFGR_FUNC_PERIPH_A;

   //Configure PA17 pin (FLEXCOM3_IO1)
   PIO0_REGS->PIO_GROUP[0].PIO_MSKR = PIO_PA17;
   PIO0_REGS->PIO_GROUP[0].PIO_CFGR = PIO_CFGR_FUNC_PERIPH_A;

   //Configure PA18 pin (FLEXCOM3_IO2)
   PIO0_REGS->PIO_GROUP[0].PIO_MSKR = PIO_PA18;
   PIO0_REGS->PIO_GROUP[0].PIO_CFGR = PIO_CFGR_FUNC_PERIPH_A;

   //Configure CS pin (PA19)
   PIO0_REGS->PIO_GROUP[0].PIO_MSKR = PIO_PA19;
   PIO0_REGS->PIO_GROUP[0].PIO_CFGR = PIO_CFGR_DIR_OUTPUT | PIO_CFGR_FUNC_GPIO;
   PIO0_REGS->PIO_GROUP[0].PIO_SODR = PIO_PA19;

   //Perform software reset
   FLEXCOM3_REGS->FLEX_SPI_CR = FLEX_SPI_CR_SPIDIS_Msk | FLEX_SPI_CR_SWRST_Msk;

   //Select master mode operation
   FLEXCOM3_REGS->FLEX_SPI_MR = FLEX_SPI_MR_DLYBCS(0) | FLEX_SPI_MR_PCS(0) |
      FLEX_SPI_MR_MODFDIS_Msk | FLEX_SPI_MR_BRSRCCLK_PERIPH_CLK |
      FLEX_SPI_MR_MSTR_Msk;

   //Configure SPI mode
   FLEXCOM3_REGS->FLEX_SPI_CSR[0] = FLEX_SPI_CSR_DLYBCT(0) |
      FLEX_SPI_CSR_DLYBS(0) | FLEX_SPI_CSR_SCBR(10) |
      FLEX_SPI_CSR_BITS_8_BIT | FLEX_SPI_CSR_NCPHA(1) |
      FLEX_SPI_CSR_CPOL(0);

   //Enable FLEXCOM3
   FLEXCOM3_REGS->FLEX_SPI_CR = FLEX_SPI_CR_SPIEN_Msk;

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
   PIO0_REGS->PIO_GROUP[0].PIO_CODR = PIO_PA19;
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
   PIO0_REGS->PIO_GROUP[0].PIO_SODR = PIO_PA19;
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
   //Ensure the TX buffer is empty
   while((FLEXCOM3_REGS->FLEX_SPI_SR & FLEX_SPI_SR_TXEMPTY_Msk) == 0)
   {
   }

   //Write character
   FLEXCOM3_REGS->FLEX_SPI_TDR = data;

   //Wait for the operation to complete
   while((FLEXCOM3_REGS->FLEX_SPI_SR & FLEX_SPI_SR_TXEMPTY_Msk) == 0)
   {
   }

   //Return the received character
   return FLEXCOM3_REGS->FLEX_SPI_RDR;
}
