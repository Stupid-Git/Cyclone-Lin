/**
 * @file sam4s_xplained_pro.h
 * @brief SAM4S-Xplained-Pro evaluation kit
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

#ifndef _SAM4S_XPLAINED_PRO_H
#define _SAM4S_XPLAINED_PRO_H

//Dependencies
#include "sam4s.h"

//LED0
#define LED0        PIO_PC23
#define PIO_LED0    PIOC
#define ID_PIO_LED0 ID_PIOC

//SW0 button
#define SW0         PIO_PA2
#define PIO_SW0     PIOA
#define ID_PIO_SW0  ID_PIOA

#endif
