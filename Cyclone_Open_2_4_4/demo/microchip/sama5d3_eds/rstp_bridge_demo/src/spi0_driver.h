/**
 * @file spi0_driver.h
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

#ifndef _SPI0_DRIVER_H
#define _SPI0_DRIVER_H

//SPI0 driver
extern const SpiDriver spi0Driver;

//SPI0 related functions
error_t spi0Init(void);
error_t spi0SetMode(uint_t mode);
error_t spi0SetBitrate(uint_t bitrate);
void spi0AssertCs(void);
void spi0DeassertCs(void);
uint8_t spi0Transfer(uint8_t data);

#endif
