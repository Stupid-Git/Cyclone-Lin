/**
 * @file twr_k70f120m.h
 * @brief TWR-K70F120M module
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

#ifndef _TWR_K70F120M_H
#define _TWR_K70F120M_H

//Dependencies
#include "mk70f12.h"

//LED1
#define LED1_POS     11
#define LED1_MASK    (1 << LED1_POS)
#define PORT_LED1    PORTA
#define GPIO_LED1    PTA

//LED2
#define LED2_POS     28
#define LED2_MASK    (1 << LED2_POS)
#define PORT_LED2    PORTA
#define GPIO_LED2    PTA

//LED3
#define LED3_POS     29
#define LED3_MASK    (1 << LED3_POS)
#define PORT_LED3    PORTA
#define GPIO_LED3    PTA

//LED4
#define LED4_POS     10
#define LED4_MASK    (1 << LED4_POS)
#define PORT_LED4    PORTA
#define GPIO_LED4    PTA

//SW1
#define SW1_POS      0
#define SW1_MASK     (1 << SW1_POS)
#define PORT_SW1     PORTD
#define GPIO_SW1     PTD

//SW2
#define SW2_POS      26
#define SW2_MASK     (1 << SW2_POS)
#define PORT_SW2     PORTE
#define GPIO_SW2     PTE

#endif
