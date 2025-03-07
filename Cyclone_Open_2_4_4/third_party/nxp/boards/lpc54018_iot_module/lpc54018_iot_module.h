/**
 * @file lpc54018_iot_module.h
 * @brief LPC54018 IoT Module
 *
 * @section License
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * Copyright (C) 2010-2024 Oryx Embedded SARL. All rights reserved.
 *
 * This file is part of CycloneTCP Open.
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

#ifndef _LPC54018_IOT_MODULE_H
#define _LPC54018_IOT_MODULE_H

//Dependencies
#include "fsl_device_registers.h"

//LED0
#define LED0_PORT  3
#define LED0_PIN   13
#define LED0_MASK  (1 << LED0_PIN)

//LED1
#define LED1_PORT  3
#define LED1_PIN   14
#define LED1_MASK  (1 << LED1_PIN)

//LED2
#define LED2_PORT  3
#define LED2_PIN   3
#define LED2_MASK  (1 << LED2_PIN)

//SW2 button
#define SW2_PORT  0
#define SW2_PIN   6
#define SW2_MASK  (1 << SW2_PIN)

//SW3 button
#define SW3_PORT  0
#define SW3_PIN   5
#define SW3_MASK  (1 << SW3_PIN)

//SW4 button
#define SW4_PORT  0
#define SW4_PIN   4
#define SW4_MASK  (1 << SW4_PIN)

//SW5 button
#define SW5_PORT  1
#define SW5_PIN   1
#define SW5_MASK  (1 << SW5_PIN)

#endif
