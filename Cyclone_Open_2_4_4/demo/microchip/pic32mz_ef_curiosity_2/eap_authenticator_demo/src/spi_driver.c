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
#include <p32xxxx.h>
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
   //Configure SCK pin (RB14)
   ANSELBCLR = _ANSELB_ANSB14_MASK;
   RPB14R = 0;

   //Configure MOSI pin (RB3)
   ANSELBCLR = _ANSELB_ANSB3_MASK;
   RPB3R = 7;

   //Configure MISO pin (RB5)
   ANSELBCLR = _ANSELB_ANSB5_MASK;
   SDI3R = 8;

   //Configure CS pin (RH3)
   TRISHCLR = _TRISH_TRISH3_MASK;
   LATHSET = _LATH_LATH3_MASK;

   //Select master mode operation
   SPI3CON = _SPI3CON_CKE_MASK | _SPI3CON_MSTEN_MASK;
   //Set SCK clock frequency
   SPI3BRG = ((40000000 / 2) / SPI_BITRATE) - 1;
   //Enable SPI module
   SPI3CONSET = _SPI3CON_ON_MASK;

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
   LATHCLR = _LATH_LATH3_MASK;
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
   LATHSET = _LATH_LATH3_MASK;
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
   while(!(SPI3STAT & _SPI1STAT_SPITBE_MASK));
   //Write character
   SPI3BUF = data;
   //Wait for the operation to complete
   while(!(SPI3STAT & _SPI1STAT_SPIRBF_MASK));

   //Return the received character
   return SPI3BUF;
}
