/**
 * @file spi0_driver.c
 * @brief SPI0 driver
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
#include "sama5d3x.h"
#include "sama5d3_eds.h"
#include "core/net.h"
#include "spi0_driver.h"
#include "debug.h"

//SPI bitrate
#define SPI_BITRATE 10000000


/**
 * @brief SPI0 driver
 **/

const SpiDriver spi0Driver =
{
   spi0Init,
   spi0SetMode,
   spi0SetBitrate,
   spi0AssertCs,
   spi0DeassertCs,
   spi0Transfer
};


/**
 * @brief SPI initialization
 * @return Error code
 **/

error_t spi0Init(void)
{
   uint32_t div;

   //Enable PIOD peripheral clock
   PMC->PMC_PCER0 = (1 << ID_PIOD);
   //Enable SPI0 peripheral clock
   PMC->PMC_PCER0 = (1 << ID_SPI0);

   //Configure SPI0_NPCS0 as an output
   PIOD->PIO_PER = PIO_PD13;
   PIOD->PIO_OER = PIO_PD13;
   PIOD->PIO_SODR = PIO_PD13;

   //Disable interrupts on SPI pins
   PIOD->PIO_IDR = PIO_PD12A_SPI0_SPCK | PIO_PD11A_SPI0_MOSI | PIO_PD10A_SPI0_MISO;
   //Internal pull-up resistors
   PIOD->PIO_PUER = PIO_PD12A_SPI0_SPCK | PIO_PD11A_SPI0_MOSI | PIO_PD10A_SPI0_MISO;
   //Assign corresponding pins to Peripheral A function
   PIOD->PIO_ABCDSR[0] &= ~(PIO_PD12A_SPI0_SPCK | PIO_PD11A_SPI0_MOSI | PIO_PD10A_SPI0_MISO);
   PIOD->PIO_ABCDSR[1] &= ~(PIO_PD12A_SPI0_SPCK | PIO_PD11A_SPI0_MOSI | PIO_PD10A_SPI0_MISO);
   //Disable the PIO from controlling the corresponding pins
   PIOD->PIO_PDR = PIO_PD12A_SPI0_SPCK | PIO_PD11A_SPI0_MOSI | PIO_PD10A_SPI0_MISO;

   //Disable SPI module
   SPI0->SPI_CR = SPI_CR_SPIDIS;
   //Reset SPI module
   SPI0->SPI_CR = SPI_CR_SWRST;
   SPI0->SPI_CR = SPI_CR_SWRST;

   //Master mode operation
   SPI0->SPI_MR = SPI_MR_MODFDIS | SPI_MR_MSTR;

   //Calculate clock divider
   div = BOARD_MCK / SPI_BITRATE;

   //SPI configuration (8-bit words, clock phase = 1, clock polarity = 0)
   SPI0->SPI_CSR[0] = SPI_CSR_SCBR(div) | SPI_CSR_BITS_8_BIT | SPI_CSR_NCPHA;

   //Enable SPI module
   SPI0->SPI_CR = SPI_CR_SPIEN;

   //Successful processing
   return NO_ERROR;
}


/**
 * @brief Set SPI mode
 * @param mode SPI mode (0, 1, 2 or 3)
 **/

error_t spi0SetMode(uint_t mode)
{
   //Not implemented
   return ERROR_NOT_IMPLEMENTED;
}


/**
 * @brief Set SPI bitrate
 * @param bitrate Bitrate value
 **/

error_t spi0SetBitrate(uint_t bitrate)
{
   //Not implemented
   return ERROR_NOT_IMPLEMENTED;
}


/**
 * @brief Assert CS
 **/

void spi0AssertCs(void)
{
   //Assert SPI0_NPCS0
   PIOD->PIO_CODR = PIO_PD13;
   //CS setup time
   usleep(1);
}


/**
 * @brief Deassert CS
 **/

void spi0DeassertCs(void)
{
   //CS hold time
   usleep(1);
   //Deassert SPI0_NPCS0
   PIOD->PIO_SODR = PIO_PD13;
   //CS disable time
   usleep(1);
}


/**
 * @brief Transfer a single byte
 * @param[in] data The data to be written
 * @return The data received from the slave device
 **/

uint8_t spi0Transfer(uint8_t data)
{
   //Ensure the TX buffer is empty
   while(!(SPI0->SPI_SR & SPI_SR_TDRE));
   //Start to transfer data
   SPI0->SPI_TDR = data;
   //Wait for the operation to complete
   while(!(SPI0->SPI_SR & SPI_SR_RDRF));

   //Return the received character
   return SPI0->SPI_RDR;
}
