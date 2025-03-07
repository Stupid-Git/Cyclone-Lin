/**
 * @file ek_ra6m5.h
 * @brief EK-RA6M5 evaluation kit
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

#ifndef _EK_RA6M5_H
#define _EK_RA6M5_H

//Dependencies
#include "bsp_api.h"

//Blue LED (LED1)
#define LED1_MASK (1U << 6)
#define LED1_PORT R_PORT0
#define LED1_PFS PORT[0].PIN[6].PmnPFS

//Green LED (LED2)
#define LED2_MASK (1U << 7)
#define LED2_PORT R_PORT0
#define LED2_PFS PORT[0].PIN[7].PmnPFS

//Red LED (LED3)
#define LED3_MASK (1U << 8)
#define LED3_PORT R_PORT0
#define LED3_PFS PORT[0].PIN[8].PmnPFS

//Push button (S1)
#define S1_MASK (1U << 5)
#define S1_PORT R_PORT0
#define S1_PFS PORT[0].PIN[5].PmnPFS

//Push button (S2)
#define S2_MASK (1U << 4)
#define S2_PORT R_PORT0
#define S2_PFS PORT[0].PIN[4].PmnPFS

//PHY reset pin
#define PHY_RST_MASK (1U << 3)
#define PHY_RST_PORT R_PORT4
#define PHY_RST_PFS PORT[4].PIN[3].PmnPFS

//PHY IRQ pin
#define PHY_IRQ_MASK (1U << 6)
#define PHY_IRQ_PORT R_PORT7
#define PHY_IRQ_PFS PORT[7].PIN[6].PmnPFS

#endif
