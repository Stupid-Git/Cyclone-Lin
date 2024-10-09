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

//Global variables
static uint_t spiSlaveSel = 0;


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
   //Configure CS0_1 (PK14)
   SIUL2->MSCR[174] = SIUL2_MSCR_OBE_MASK | SIUL2_MSCR_SMC_MASK;
   //Deassert CS pin
   SIUL2->GPDO[174] = 1;

   //Configure CS1_1 (PJ3)
   SIUL2->MSCR[147] = SIUL2_MSCR_OBE_MASK | SIUL2_MSCR_SMC_MASK;
   //Deassert CS pin
   SIUL2->GPDO[147] = 1;

   //Configure SCLK_1 (PK13)
   SIUL2->MSCR[173] = SIUL2_MSCR_SRC(3) | SIUL2_MSCR_OBE_MASK |
      SIUL2_MSCR_SMC_MASK | SIUL2_MSCR_SSS(3);

   //Configure SOUT_1 (PL0)
   SIUL2->MSCR[176] = SIUL2_MSCR_SRC(3) | SIUL2_MSCR_OBE_MASK |
      SIUL2_MSCR_SMC_MASK | SIUL2_MSCR_SSS(1);

   //Configure SIN_1 (PK15)
   SIUL2->MSCR[175] = SIUL2_MSCR_SMC_MASK | SIUL2_MSCR_IBE_MASK;
   SIUL2->IMCR[303] = SIUL2_IMCR_SSS(2);

   //Select master mode of operation
   SPI_1->MCR = SPI_MCR_MSTR_MASK | SPI_MCR_PCSIS(1) | SPI_MCR_CLR_TXF_MASK |
      SPI_MCR_CLR_RXF_MASK | SPI_MCR_HALT_MASK;

   //Configure SPI mode and baud rate
   SPI_1->MODE.CTAR[0] = SPI_CTAR_FMSZ(7) | SPI_CTAR_CPOL(0) | SPI_CTAR_CPHA(1) |
      SPI_CTAR_CSSCK(4) | SPI_CTAR_ASC(4) | SPI_CTAR_DT(4) | SPI_CTAR_BR(3);

   //Exit HALT mode
   SPI_1->MCR &= ~SPI_MCR_HALT_MASK;

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
 * @brief Select slave device
 * @param slave Slave device identifier
 **/

void spiSelectSlave(uint_t slave)
{
   //Select the relevant slave device
   spiSlaveSel = slave;
}


/**
 * @brief Assert CS
 **/

void spiAssertCs(void)
{
   //Assert CS signal
   if(spiSlaveSel == 0)
   {
      SIUL2->GPDO[174] = 0;
   }
   else
   {
      SIUL2->GPDO[147] = 0;
   }

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
   if(spiSlaveSel == 0)
   {
      SIUL2->GPDO[174] = 1;
   }
   else
   {
      SIUL2->GPDO[147] = 1;
   }

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
   SPI_1->PUSHR.PUSHR = data;

   //Wait for the operation to complete
   while((SPI_1->SR & SPI_SR_RFDF_MASK) == 0)
   {
   }

   //Get the received character
   temp = SPI_1->POPR;

   //Clear RFDF flag
   SPI_1->SR = SPI_SR_RFDF_MASK;

   //Return the received character
   return temp;
}
