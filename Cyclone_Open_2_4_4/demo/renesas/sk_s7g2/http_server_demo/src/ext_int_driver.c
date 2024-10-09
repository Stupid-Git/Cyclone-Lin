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
#include "bsp_irq_cfg.h"
#include "s7g2.h"
#include "sk_s7g2.h"
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
   R_ICU->IRQCRn_b[14].FLTEN = 0;

   //Unlock PFS registers
   R_PMISC->PWPR_b.BOWI = 0;
   R_PMISC->PWPR_b.PFSWE = 1;

   //Configure PHY IRQ pin as an input
   R_PFS->PHY_IRQ_PFS_b.PMR = 0;
   R_PFS->PHY_IRQ_PFS_b.PDR = 0;
   R_PFS->PHY_IRQ_PFS_b.ISEL = 1;

   //Lock PFS registers
   R_PMISC->PWPR_b.PFSWE = 0;
   R_PMISC->PWPR_b.BOWI = 1;

   //Set digital filter sampling clock (PCLK)
   R_ICU->IRQCRn_b[14].FCLKSEL = 0;
   //Enable digital filter
   R_ICU->IRQCRn_b[14].FLTEN = 1;
   //Configure IRQ14 polarity (falling edge)
   R_ICU->IRQCRn_b[14].IRQMD = 0;

   //Redirect the event to the NVIC
   R_ICU->IELSRn_b[ICU_IRQ14_IRQn].DTCE = 0;

   //Configure IRQ14 interrupt priority
   NVIC_SetPriority(ICU_IRQ14_IRQn, NVIC_EncodePriority(3, 15, 0));

   //Successful processing
   return NO_ERROR;
}


/**
 * @brief Enable external interrupts
 **/

void extIntEnableIrq(void)
{
   //Enable IRQ14 interrupt
   NVIC_EnableIRQ(ICU_IRQ14_IRQn);
}


/**
 * @brief Disable external interrupts
 **/

void extIntDisableIrq(void)
{
   //Disable IRQ14 interrupt
   NVIC_DisableIRQ(ICU_IRQ14_IRQn);
}


/**
 * @brief External interrupt handler
 **/

void ICU_IRQ14_IRQHandler(void)
{
   bool_t flag;
   NetInterface *interface;

   //Enter interrupt service routine
   osEnterIsr();

   //Clear interrupt flag
   R_ICU->IELSRn_b[ICU_IRQ14_IRQn].IR = 0;

   //Point to the structure describing the network interface
   interface = &netInterface[0];

   //Set event flag
   interface->phyEvent = TRUE;
   //Notify the TCP/IP stack of the event
   flag = osSetEventFromIsr(&netEvent);

   //Leave interrupt service routine
   osExitIsr(flag);
}
