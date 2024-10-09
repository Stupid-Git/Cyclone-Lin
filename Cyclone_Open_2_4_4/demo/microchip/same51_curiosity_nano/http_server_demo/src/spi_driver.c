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
   uint32_t temp;

   //Enable SERCOM1 core clock
   GCLK_REGS->GCLK_PCHCTRL[SERCOM1_GCLK_ID_CORE] = GCLK_PCHCTRL_GEN_GCLK0 |
      GCLK_PCHCTRL_CHEN_Msk;

   //Enable PORT bus clock (CLK_PORT_APB)
   MCLK_REGS->MCLK_APBBMASK |= MCLK_APBBMASK_PORT_Msk;
   //Enable SERCOM1 bus clock (CLK_SERCOM_APB)
   MCLK_REGS->MCLK_APBAMASK |= MCLK_APBAMASK_SERCOM1_Msk;

   //Configure SCK pin (PA17)
   PORT_REGS->GROUP[0].PORT_PINCFG[17] |= PORT_PINCFG_DRVSTR_Msk;
   PORT_REGS->GROUP[0].PORT_PINCFG[17] |= PORT_PINCFG_PMUXEN_Msk;
   temp = PORT_REGS->GROUP[0].PORT_PMUX[8] & ~PORT_PMUX_PMUXO_Msk;
   PORT_REGS->GROUP[0].PORT_PMUX[8] = temp | PORT_PMUX_PMUXO(MUX_PA17C_SERCOM1_PAD1);

   //Configure MOSI pin (PA16)
   PORT_REGS->GROUP[0].PORT_PINCFG[16] |= PORT_PINCFG_DRVSTR_Msk;
   PORT_REGS->GROUP[0].PORT_PINCFG[16] |= PORT_PINCFG_PMUXEN_Msk;
   temp = PORT_REGS->GROUP[0].PORT_PMUX[8] & ~PORT_PMUX_PMUXE_Msk;
   PORT_REGS->GROUP[0].PORT_PMUX[8] = temp | PORT_PMUX_PMUXE(MUX_PA16C_SERCOM1_PAD0);

   //Configure MISO pin (PA19)
   PORT_REGS->GROUP[0].PORT_PINCFG[19] |= PORT_PINCFG_DRVSTR_Msk;
   PORT_REGS->GROUP[0].PORT_PINCFG[19] |= PORT_PINCFG_PMUXEN_Msk;
   temp = PORT_REGS->GROUP[0].PORT_PMUX[9] & ~PORT_PMUX_PMUXO_Msk;
   PORT_REGS->GROUP[0].PORT_PMUX[9] = temp | PORT_PMUX_PMUXO(MUX_PA19C_SERCOM1_PAD3);

   //Configure CS pin (PA18)
   PORT_REGS->GROUP[0].PORT_PINCFG[18] |= PORT_PINCFG_DRVSTR_Msk;
   PORT_REGS->GROUP[0].PORT_DIRSET = PORT_PA18;
   PORT_REGS->GROUP[0].PORT_OUTSET = PORT_PA18;

   //Perform software reset
   SERCOM1_REGS->SPIM.SERCOM_CTRLA = SERCOM_SPIM_CTRLA_SWRST_Msk;

   //Resetting the SERCOM1 (CTRLA.SWRST) requires synchronization
   while((SERCOM1_REGS->SPIM.SERCOM_SYNCBUSY & SERCOM_SPIM_SYNCBUSY_SWRST_Msk) != 0)
   {
   }

   //Select master mode operation
   SERCOM1_REGS->SPIM.SERCOM_CTRLA = SERCOM_SPIM_CTRLA_DIPO(3) |
      SERCOM_SPIM_CTRLA_DOPO(0) | SERCOM_SPIM_CTRLA_MODE(3);

   //Configure clock divider
   SERCOM1_REGS->SPIM.SERCOM_BAUD = SystemCoreClock / (2 * SPI_BITRATE) - 1;

   //Enable the receiver
   SERCOM1_REGS->SPIM.SERCOM_CTRLB = SERCOM_SPIM_CTRLB_RXEN_Msk;

   //Writing to the CTRLB register when the SERCOM is enabled requires
   //synchronization
   while((SERCOM1_REGS->SPIM.SERCOM_SYNCBUSY & SERCOM_SPIM_SYNCBUSY_CTRLB_Msk) != 0)
   {
   }

   //Enable SERCOM1
   SERCOM1_REGS->SPIM.SERCOM_CTRLA |= SERCOM_SPIM_CTRLA_ENABLE_Msk;

   //Enabling and disabling the SERCOM requires synchronization
   while((SERCOM1_REGS->SPIM.SERCOM_SYNCBUSY & SERCOM_SPIM_SYNCBUSY_ENABLE_Msk) != 0)
   {
   }

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
   PORT_REGS->GROUP[0].PORT_OUTCLR = PORT_PA18;
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
   PORT_REGS->GROUP[0].PORT_OUTSET = PORT_PA18;
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
   while((SERCOM1_REGS->SPIM.SERCOM_INTFLAG & SERCOM_SPIM_INTFLAG_DRE_Msk) == 0)
   {
   }

   //Write character
   SERCOM1_REGS->SPIM.SERCOM_DATA = data;

   //Wait for the operation to complete
   while((SERCOM1_REGS->SPIM.SERCOM_INTFLAG & SERCOM_SPIM_INTFLAG_RXC_Msk) == 0)
   {
   }

   //Return the received character
   return SERCOM1_REGS->SPIM.SERCOM_DATA;
}
