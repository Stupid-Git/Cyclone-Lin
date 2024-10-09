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
#include "sam.h"
#include "core/net.h"
#include "spi_driver.h"
#include "debug.h"

//SPI bitrate
#define SPI_BITRATE 5000000


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
   uint32_t div;

   //Enable PIO peripheral clocks
   PMC_REGS->PMC_PCER0 = (1 << ID_PIOC) | (1 << ID_PIOD);
   //Enable SPI0 peripheral clock
   PMC_REGS->PMC_PCER0 = (1 << ID_SPI0);

   //Disable MDIO and MDC pins in SPI slave mode
   PIOD_REGS->PIO_PER = PIO_PD9A_GMAC_GMDIO | PIO_PD8A_GMAC_GMDC;
   PIOD_REGS->PIO_ODR = PIO_PD9A_GMAC_GMDIO | PIO_PD8A_GMAC_GMDC;

   //Configure CS pin as an output
   PIOC_REGS->PIO_PER = PIO_PC19;
   PIOC_REGS->PIO_OER = PIO_PC19;
   PIOC_REGS->PIO_SODR = PIO_PC19;

   //Disable interrupts on SPI pins
   PIOD_REGS->PIO_IDR = PIO_PD22B_SPI0_SPCK | PIO_PD21B_SPI0_MOSI | PIO_PD20B_SPI0_MISO;
   //Internal pull-up resistors
   PIOD_REGS->PIO_PUER = PIO_PD22B_SPI0_SPCK | PIO_PD21B_SPI0_MOSI | PIO_PD20B_SPI0_MISO;
   //Assign corresponding pins to Peripheral B function
   PIOD_REGS->PIO_ABCDSR[0] |= PIO_PD22B_SPI0_SPCK | PIO_PD21B_SPI0_MOSI | PIO_PD20B_SPI0_MISO;
   PIOD_REGS->PIO_ABCDSR[1] &= ~(PIO_PD22B_SPI0_SPCK | PIO_PD21B_SPI0_MOSI | PIO_PD20B_SPI0_MISO);
   //Disable the PIO from controlling the corresponding pins
   PIOD_REGS->PIO_PDR = PIO_PD22B_SPI0_SPCK | PIO_PD21B_SPI0_MOSI | PIO_PD20B_SPI0_MISO;

   //Disable SPI module
   SPI0_REGS->SPI_CR = SPI_CR_SPIDIS_Msk;
   //Reset SPI module
   SPI0_REGS->SPI_CR = SPI_CR_SWRST_Msk;
   SPI0_REGS->SPI_CR = SPI_CR_SWRST_Msk;

   //Master mode operation
   SPI0_REGS->SPI_MR = SPI_MR_MODFDIS_Msk | SPI_MR_MSTR_Msk;

   //Calculate clock divider
   div = SystemCoreClock / (2 * SPI_BITRATE);

   //SPI configuration (8-bit words, clock phase = 1, clock polarity = 0)
   SPI0_REGS->SPI_CSR[0] = SPI_CSR_SCBR(div) | SPI_CSR_BITS_8_BIT |
      SPI_CSR_NCPHA_Msk;

   //Enable SPI module
   SPI0_REGS->SPI_CR = SPI_CR_SPIEN_Msk;

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
   PIOC_REGS->PIO_CODR = PIO_PC19;
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
   PIOC_REGS->PIO_SODR = PIO_PC19;
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
   while(!(SPI0_REGS->SPI_SR & SPI_SR_TDRE_Msk))
   {
   }

   //Start to transfer data
   SPI0_REGS->SPI_TDR = data;

   //Wait for the operation to complete
   while(!(SPI0_REGS->SPI_SR & SPI_SR_RDRF_Msk))
   {
   }

   //Return the received character
   return SPI0_REGS->SPI_RDR;
}
