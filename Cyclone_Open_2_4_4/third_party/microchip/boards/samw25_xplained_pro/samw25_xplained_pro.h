/**
 * @file samw25_xplained_pro.h
 * @brief SAMW25-Xplained-Pro evaluation kit
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

#ifndef _SAMW25_XPLAINED_PRO_H
#define _SAMW25_XPLAINED_PRO_H

//Dependencies
#include "samd21.h"

//LED0 (PA23)
#define LED0_GROUP 0
#define LED0_PIN   23
#define LED0_MASK  (1U << 23)

//SW0 button (PB23)
#define SW0_GROUP  1
#define SW0_PIN    23
#define SW0_MASK   (1U << 23)

#endif
