/**
 * @file sk_s7g2.h
 * @brief SK-S7G2 Starter Kit
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

#ifndef _SK_S7G2_H
#define _SK_S7G2_H

//Dependencies
#include "bsp_irq_cfg.h"
#include "s7g2.h"

//Green LED (LED1)
#define LED1_MASK (1U << 0)
#define LED1_IOPORT R_IOPORT6
#define LED1_PFS_b P600PFS_b

//Red LED (LED2)
#define LED2_MASK (1U << 1)
#define LED2_IOPORT R_IOPORT6
#define LED2_PFS_b P601PFS_b

//Yellow LED (LED3)
#define LED3_MASK (1U << 2)
#define LED3_IOPORT R_IOPORT6
#define LED3_PFS_b P602PFS_b

//Push button (S4)
#define S4_MASK (1U << 6)
#define S4_IOPORT R_IOPORT0
#define S4_PFS_b P006PFS_b

//Push button (S5)
#define S5_MASK (1U << 5)
#define S5_IOPORT R_IOPORT0
#define S5_PFS_b P005PFS_b

//PHY reset pin
#define PHY_RST_MASK (1U << 6)
#define PHY_RST_IOPORT R_IOPORT8
#define PHY_RST_PFS_b P806PFS_b

//PHY IRQ pin
#define PHY_IRQ_MASK (1U << 10)
#define PHY_IRQ_IOPORT R_IOPORT0
#define PHY_IRQ_PFS_b P010PFS_b

#endif
