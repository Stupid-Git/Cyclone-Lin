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
#include "sam.h"
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
   volatile uint32_t status;

   //Enable PIO peripheral clock
   PMC_REGS->PMC_PCER0 = (1 << ID_PIOA);

   //Enable pull-up resistor on PHY_INT pin
   PIOA_REGS->PIO_PUER = PIO_PA19;
   //Configure the corresponding pin as an input
   PIOA_REGS->PIO_ODR = PIO_PA19;
   PIOA_REGS->PIO_PER = PIO_PA19;
   //Enable interrupts-on-change
   PIOA_REGS->PIO_IDR = 0xFFFFFFFF;
   PIOA_REGS->PIO_IER = PIO_PA19;

   //Read PIO ISR register to clear any pending interrupt
   status = PIOA_REGS->PIO_ISR;
   (void) status;

   //Configure PIOA interrupt priority
   NVIC_SetPriority(PIOA_IRQn, NVIC_EncodePriority(4, 7, 0));

   //Successful processing
   return NO_ERROR;
}


/**
 * @brief Enable external interrupts
 **/

void extIntEnableIrq(void)
{
   //Enable PIOA interrupts
   NVIC_EnableIRQ(PIOA_IRQn);
}


/**
 * @brief Disable external interrupts
 **/

void extIntDisableIrq(void)
{
   //Disable PIOA interrupts
   NVIC_DisableIRQ(PIOA_IRQn);
}


/**
 * @brief External interrupt handler
 **/

void PIOA_Handler(void)
{
   bool_t flag;
   volatile uint32_t status;
   NetInterface *interface;

   //Enter interrupt service routine
   osEnterIsr();

   //Point to the structure describing the network interface
   interface = &netInterface[0];
   //This flag will be set if a higher priority task must be woken
   flag = FALSE;

   //Read status register to clear interrupt
   status = PIOA_REGS->PIO_ISR;
   (void) status;

   //Ensure the EXT3_IRQ pin is asserted
   if(!(PIOA_REGS->PIO_PDSR & PIO_PA19))
   {
      //Set event flag
      interface->phyEvent = TRUE;
      //Notify the TCP/IP stack of the event
      flag = osSetEventFromIsr(&netEvent);
   }

   //Leave interrupt service routine
   osExitIsr(flag);
}
