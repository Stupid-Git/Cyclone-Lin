/**
 * @file ext_int_driver.c
 * @brief External interrupt line driver
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
#include "bsp_api.h"
#include "ek_ra6m4.h"
#include "core/net.h"
#include "ext_int_driver.h"
#include "debug.h"


/**
 * @brief External interrupt line driver
 **/

const ExtIntDriver extIntDriver =
{
   extIntInit,
   extIntEnableIrq,
   extIntDisableIrq
};


/**
 * @brief EXTI configuration
 * @return Error code
 **/

error_t extIntInit(void)
{
   //Disable digital filter
   R_ICU->IRQCR_b[8].FLTEN = 0;

   //Unlock PFS registers
   R_PMISC->PWPR &= ~R_PMISC_PWPR_B0WI_Msk;
   R_PMISC->PWPR |= R_PMISC_PWPR_PFSWE_Msk;

   //Configure PHY IRQ pin as an input
   R_PFS->PHY_IRQ_PFS = R_PFS_PORT_PIN_PmnPFS_ISEL_Msk;

   //Lock PFS registers
   R_PMISC->PWPR &= ~R_PMISC_PWPR_PFSWE_Msk;
   R_PMISC->PWPR |= R_PMISC_PWPR_B0WI_Msk;

   //Set digital filter sampling clock (PCLK)
   R_ICU->IRQCR_b[8].FCLKSEL = 0;
   //Enable digital filter
   R_ICU->IRQCR_b[8].FLTEN = 1;
   //Configure IRQ8 polarity (falling edge)
   R_ICU->IRQCR_b[8].IRQMD = 0;

   //Redirect the event to the NVIC
   R_ICU->IELSR_b[ICU_IRQ8_IRQn].DTCE = 0;

   //Configure IRQ8 interrupt priority
   NVIC_SetPriority(ICU_IRQ8_IRQn, NVIC_EncodePriority(3, 15, 0));

   //Successful processing
   return NO_ERROR;
}


/**
 * @brief Enable external interrupts
 **/

void extIntEnableIrq(void)
{
   //Enable IRQ8 interrupt
   NVIC_EnableIRQ(ICU_IRQ8_IRQn);
}


/**
 * @brief Disable external interrupts
 **/

void extIntDisableIrq(void)
{
   //Disable IRQ8 interrupt
   NVIC_DisableIRQ(ICU_IRQ8_IRQn);
}


/**
 * @brief External interrupt handler
 **/

void ICU_IRQ8_IRQHandler(void)
{
   bool_t flag;
   NetInterface *interface;

   //Enter interrupt service routine
   osEnterIsr();

   //Clear interrupt flag
   R_ICU->IELSR_b[ICU_IRQ8_IRQn].IR = 0;

   //Point to the structure describing the network interface
   interface = &netInterface[0];

   //Set event flag
   interface->phyEvent = TRUE;
   //Notify the TCP/IP stack of the event
   flag = osSetEventFromIsr(&netEvent);

   //Leave interrupt service routine
   osExitIsr(flag);
}
