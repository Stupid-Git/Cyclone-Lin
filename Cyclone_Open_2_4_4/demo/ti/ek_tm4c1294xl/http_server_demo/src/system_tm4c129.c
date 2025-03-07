/**
 * @file system_tm4c129.c
 * @brief System configuration for TM4C129 device
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

#include <stdint.h>
#include <stdbool.h>
#include "tm4c129xnczad.h"
#include "inc/hw_types.h"
#include "driverlib/fpu.h"
#include "driverlib/sysctl.h"
#include "system_tm4c129.h"

//System clock frequency (120MHz)
uint32_t SystemCoreClock = 120000000;


/**
 * @brief Setup the system clock
 **/

void SystemInit(void)
{
   //Enable floating-point unit
   FPUEnable();

   //Run from the PLL at 120MHz
   SysCtlClockFreqSet(SYSCTL_XTAL_25MHZ | SYSCTL_OSC_MAIN |
      SYSCTL_USE_PLL | SYSCTL_CFG_VCO_480, 120000000);
}


/**
 * @brief Update the variable SystemCoreClock
 **/

void SystemCoreClockUpdate(void)
{
}
