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
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "tm4c129xnczad.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/ssi.h"
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
   //Enable GPIO clocks
   SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
   SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOS);

   //Enable SSI0 clock
   SysCtlPeripheralEnable(SYSCTL_PERIPH_SSI0);

   //Configure CS pin (PS7) as an output
   GPIOPinTypeGPIOOutput(GPIO_PORTS_BASE, GPIO_PIN_7);

   //Set pad configuration
   GPIOPadConfigSet(GPIO_PORTS_BASE, GPIO_PIN_7, GPIO_STRENGTH_10MA,
      GPIO_PIN_TYPE_STD);

   //Set default value of CS signal
   GPIOPinWrite(GPIO_PORTS_BASE, GPIO_PIN_7, GPIO_PIN_7);

   //Configure SCK (PA2)
   GPIOPinConfigure(GPIO_PA2_SSI0CLK);
   GPIOPinTypeSSI(GPIO_PORTA_BASE, GPIO_PIN_2);

   //Set pad configuration
   GPIOPadConfigSet(GPIO_PORTA_BASE, GPIO_PIN_2, GPIO_STRENGTH_10MA,
      GPIO_PIN_TYPE_STD);

   //Configure MOSI (PA4)
   GPIOPinConfigure(GPIO_PA4_SSI0XDAT0);
   GPIOPinTypeSSI(GPIO_PORTA_BASE, GPIO_PIN_4);

   //Set pad configuration
   GPIOPadConfigSet(GPIO_PORTA_BASE, GPIO_PIN_4, GPIO_STRENGTH_10MA,
      GPIO_PIN_TYPE_STD);

   //Configure MISO (PA5)
   GPIOPinConfigure(GPIO_PA5_SSI0XDAT1);
   GPIOPinTypeSSI(GPIO_PORTA_BASE, GPIO_PIN_5);

   //Set pad configuration
   GPIOPadConfigSet(GPIO_PORTA_BASE, GPIO_PIN_5, GPIO_STRENGTH_10MA,
      GPIO_PIN_TYPE_STD_WPU);

   //Configure SSI0 module
   SSIConfigSetExpClk(SSI0_BASE, SystemCoreClock, SSI_FRF_MOTO_MODE_0,
      SSI_MODE_MASTER, SPI_BITRATE, 8);

   //Enable SSI0 module
   SSIEnable(SSI0_BASE);

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
   GPIOPinWrite(GPIO_PORTS_BASE, GPIO_PIN_7, 0);
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
   GPIOPinWrite(GPIO_PORTS_BASE, GPIO_PIN_7, GPIO_PIN_7);
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
   uint32_t temp;

   //Write character
   SSIDataPut(SSI0_BASE, data);
   //Read character
   SSIDataGet(SSI0_BASE, &temp);

   //Return the received character
   return (uint8_t) temp;
}
