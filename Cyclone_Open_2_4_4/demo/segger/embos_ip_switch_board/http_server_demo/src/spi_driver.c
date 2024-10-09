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
#include "mk66f18.h"
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
   //Enable PORTB peripheral clock
   SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK;
   //Enable SPI1 peripheral clock
   SIM->SCGC6 |= SIM_SCGC6_SPI1_MASK;

   //Configure SPI_CS (PTB10) as an output
   PORTB->PCR[10] = PORT_PCR_MUX(1);
   PTB->PDDR |= (1 << 10);
   PTB->PCOR = (1 << 10);

   //Configure SPI_SCK (PTB11)
   PORTB->PCR[11] = PORT_PCR_MUX(2);
   //Configure SPI_MOSI (PTB16)
   PORTB->PCR[16] = PORT_PCR_MUX(2);
   //Configure SPI_MISO (PTB17)
   PORTB->PCR[17] = PORT_PCR_MUX(2);

   //Select master mode operation
   SPI1->MCR = SPI_MCR_MSTR_MASK | SPI_MCR_DIS_TXF_MASK | SPI_MCR_DIS_RXF_MASK;

   //Configure SPI parameters
   SPI1->CTAR[0] = SPI_CTAR_FMSZ(7) | SPI_CTAR_CPOL(0) | SPI_CTAR_CPHA(0) |
      SPI_CTAR_BR(3);

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
   //Assert SPI_CS
   PTB->PCOR = (1 << 10);
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
   //Deassert SPI_CS
   PTB->PSOR = (1 << 10);
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
   //Start to transfer data
   SPI1->PUSHR = data;
   //Wait for the operation to complete
   while(!(SPI1->SR & SPI_SR_TCF_MASK));

   //Clear TCF mask
   SPI1->SR = SPI_SR_TCF_MASK;

   //Return the received character
   return SPI1->POPR;
}
