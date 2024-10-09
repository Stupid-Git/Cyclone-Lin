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
#include "fsl_device_registers.h"
#include "fsl_power.h"
#include "fsl_reset.h"
#include "fsl_clock.h"
#include "fsl_gpio.h"
#include "fsl_iocon.h"
#include "fsl_spi.h"
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
   gpio_pin_config_t pinConfig;
   spi_master_config_t spiMasterConfig;

   //Enable IOCON clock
   CLOCK_EnableClock(kCLOCK_Iocon);

   //Enable GPIO0 and GPIO1 clocks
   CLOCK_EnableClock(kCLOCK_Gpio0);
   CLOCK_EnableClock(kCLOCK_Gpio1);

   //Configure PIO1_2 pin as HS_SPI_SCK
   IOCON_PinMuxSet(IOCON, 1, 2, IOCON_FUNC6 | IOCON_SLEW_FAST |
      IOCON_DIGITAL_EN | IOCON_INPFILT_OFF);

   //Configure PIO0_26 as HS_SPI_MOSI
   IOCON_PinMuxSet(IOCON, 0, 26, IOCON_FUNC9 | IOCON_SLEW_FAST |
      IOCON_DIGITAL_EN | IOCON_INPFILT_OFF);

   //Configure PIO1_3 as HS_SPI_MISO
   IOCON_PinMuxSet(IOCON, 1, 3, IOCON_FUNC6 | IOCON_SLEW_FAST |
      IOCON_DIGITAL_EN | IOCON_INPFILT_OFF);

   //Configure CS (PIO1_1) as an output
   pinConfig.pinDirection = kGPIO_DigitalOutput;
   pinConfig.outputLogic = 1;
   GPIO_PinInit(GPIO, 1, 1, &pinConfig);

   //Configure PLL0 clock divider
   CLOCK_SetClkDiv(kCLOCK_DivPll0Clk, 0U, true);
   CLOCK_SetClkDiv(kCLOCK_DivPll0Clk, 3U, false);

   //Set HSLSPI clock source
   CLOCK_AttachClk(kPLL0_DIV_to_HSLSPI);

   //Reset HSLSPI peripheral
   RESET_PeripheralReset(kHSLSPI_RST_SHIFT_RSTn);

   //Get default SPI configuration
   SPI_MasterGetDefaultConfig(&spiMasterConfig);

   //Configure SPI parameters
   spiMasterConfig.polarity = kSPI_ClockPolarityActiveLow;
   spiMasterConfig.phase = kSPI_ClockPhaseSecondEdge;
   spiMasterConfig.baudRate_Bps = 10000000;

   //Configure HSLSPI module
   SPI_MasterInit(SPI8, &spiMasterConfig, CLOCK_GetHsLspiClkFreq());

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
   GPIO_PinWrite(GPIO, 1, 1, 0);
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
   GPIO_PinWrite(GPIO, 1, 1, 1);
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
   spi_transfer_t spiTransfer;

   //Configure SPI transfer
   spiTransfer.txData = &data;
   spiTransfer.rxData = &temp;
   spiTransfer.dataSize = 1;
   spiTransfer.configFlags = 0;

   //Perform SPI transfer
   SPI_MasterTransferBlocking(SPI8, &spiTransfer);

   //Return the received character
   return temp;
}
