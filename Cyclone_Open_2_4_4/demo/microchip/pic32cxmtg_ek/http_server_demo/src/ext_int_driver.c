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
#include "pic32c.h"
#include "core/net.h"
#include "drivers/eth/lan8651_driver.h"
#include "drivers/eth/lan9250_driver.h"
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
   uint32_t temp;

   //Enable PIOC peripheral clock
   PMC_REGS->PMC_PCR = PMC_PCR_PID(ID_PIOC);
   temp = PMC_REGS->PMC_PCR;
   PMC_REGS->PMC_PCR = temp | PMC_PCR_CMD_Msk | PMC_PCR_EN_Msk;

   //Configure IRQ pin (PC7)
   PIO0_REGS->PIO_GROUP[2].PIO_MSKR = PIO_PC7;
   PIO0_REGS->PIO_GROUP[2].PIO_CFGR = PIO_CFGR_EVTSEL_FALLING |
      PIO_CFGR_PUEN_ENABLED | PIO_CFGR_DIR_INPUT | PIO_CFGR_FUNC_GPIO;

   //Enable PIO interrupts
   PIO0_REGS->PIO_GROUP[2].PIO_IER = PIO_PC7;

   //Set priority grouping
   NVIC_SetPriorityGrouping(4);
   //Configure EIC interrupt priority
   NVIC_SetPriority(PIOC_IRQn, NVIC_EncodePriority(3, 15, 0));
   //Set EIC interrupt to pending
   NVIC_SetPendingIRQ(PIOC_IRQn);

   //Successful processing
   return NO_ERROR;
}


/**
 * @brief Enable external interrupts
 **/

void extIntEnableIrq(void)
{
   //Enable interrupts
   NVIC_EnableIRQ(PIOC_IRQn);
}


/**
 * @brief Disable external interrupts
 **/

void extIntDisableIrq(void)
{
   //Disable interrupts
   NVIC_DisableIRQ(PIOC_IRQn);
}


/**
 * @brief External interrupt handler
 **/

void PIOC_Handler(void)
{
   bool_t flag;
   volatile uint32_t isr;
   NetInterface *interface;

   //Enter interrupt service routine
   osEnterIsr();

   //Point to the structure describing the network interface
   interface = &netInterface[0];
   //This flag will be set if a higher priority task must be woken
   flag = FALSE;

   //Read PIO_ISR register to clear interrupt flag
   isr = PIO0_REGS->PIO_GROUP[2].PIO_ISR;
   (void) isr;

   //Ensure the IRQ pin is asserted
   if(!(PIO0_REGS->PIO_GROUP[2].PIO_PDSR & PIO_PC7))
   {
#if defined(USE_LAN8651)
      //Call interrupt handler
      flag = lan8651IrqHandler(interface);
#elif defined(USE_LAN9250)
      //Call interrupt handler
      flag = lan9250IrqHandler(interface);
#endif
   }

   //Leave interrupt service routine
   osExitIsr(flag);
}
