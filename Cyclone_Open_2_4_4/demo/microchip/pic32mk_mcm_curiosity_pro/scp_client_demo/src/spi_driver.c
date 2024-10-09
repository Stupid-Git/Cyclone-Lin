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
   //Configure CS pin (RC0) as an output
   LATCSET = _LATC_LATC0_MASK;
   TRISCCLR = _TRISC_TRISC0_MASK;
   //Disable analog pad
   ANSELCCLR = _ANSELC_ANSC0_MASK;

   //Disable analog pad on SCK6 (AN1/RA1)
   ANSELACLR = _ANSELA_ANSA1_MASK;

   //Disable analog pad on SDO6 (AN2/RB0)
   ANSELBCLR = _ANSELB_ANSB0_MASK;

   //Disable analog pad on SDI6 (AN16/RG9)
   ANSELGCLR = _ANSELG_ANSG9_MASK;
   //Enable pull-up
   CNPUGSET = _CNPUG_CNPUG9_MASK;

   //Remap SCK6 to RPA1
   RPA1R = 17;
   //Remap SDO6 to RPB0
   RPB0R = 17;
   //Remap SDI6 to RPG9
   SDI6R = 10;

   //Select master mode operation
   SPI6CON = _SPI6CON_CKE_MASK | _SPI6CON_MSTEN_MASK;
   //Set SCK clock frequency
   SPI6BRG = ((60000000 / 2) / 6000000) - 1;
   //Enable SPI6 module
   SPI6CONSET = _SPI6CON_ON_MASK;

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
   //Assert CS pin
   LATCCLR = _LATC_LATC0_MASK;
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
   //Deassert CS pin
   LATCSET = _LATC_LATC0_MASK;
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
   while(!(SPI6STAT & _SPI6STAT_SPITBE_MASK));
   //Start to transfer data
   SPI6BUF = data;
   //Wait for the operation to complete
   while(!(SPI6STAT & _SPI6STAT_SPIRBF_MASK));

   //Return the received character
   return SPI6BUF;
}
