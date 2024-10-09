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

   //Enable EIC core clock
   GCLK_REGS->GCLK_PCHCTRL[EIC_GCLK_ID] = GCLK_PCHCTRL_GEN_GCLK0 |
      GCLK_PCHCTRL_CHEN_Msk;

   //Enable PORT bus clock (CLK_PORT_APB)
   MCLK_REGS->MCLK_APBBMASK |= MCLK_APBBMASK_PORT_Msk;
   //Enable EIC bus clock (CLK_EIC_APB)
   MCLK_REGS->MCLK_APBAMASK |= MCLK_APBAMASK_EIC_Msk;

   //Configure IRQ pin (PA4)
   PORT_REGS->GROUP[0].PORT_DIRCLR = PORT_PA04;
   PORT_REGS->GROUP[0].PORT_OUTSET = PORT_PA04;
   PORT_REGS->GROUP[0].PORT_PINCFG[4] |= PORT_PINCFG_PULLEN_Msk;
   PORT_REGS->GROUP[0].PORT_PINCFG[4] |= PORT_PINCFG_INEN_Msk;
   PORT_REGS->GROUP[0].PORT_PINCFG[4] |= PORT_PINCFG_PMUXEN_Msk;

   //Select peripheral function  (EXTINT4)
   temp = PORT_REGS->GROUP[0].PORT_PMUX[4] & ~PORT_PMUX_PMUXO_Msk;
   PORT_REGS->GROUP[0].PORT_PMUX[4] = temp | PORT_PMUX_PMUXO(MUX_PA04A_EIC_EXTINT4);

   //Configure the EIC input sense and filtering
   EIC_REGS->EIC_CONFIG[0] = (EIC_REGS->EIC_CONFIG[0] & ~EIC_CONFIG_SENSE4_Msk) |
      EIC_CONFIG_SENSE4_FALL;

   //Enable the EIC
   EIC_REGS->EIC_CTRLA |= EIC_CTRLA_ENABLE_Msk;

   //Enabling and disabling the EIC requires synchronization
   while((EIC_REGS->EIC_SYNCBUSY & EIC_SYNCBUSY_ENABLE_Msk) != 0)
   {
   }

   //Enable external interrupts
   EIC_REGS->EIC_INTENSET = EIC_INTENSET_EXTINT(1 << 4);

   //Set priority grouping
   NVIC_SetPriorityGrouping(4);

   //Configure EIC interrupt priority
   NVIC_SetPriority(EIC_EXTINT_4_IRQn, NVIC_EncodePriority(4, 7, 0));

   //Set EIC interrupt to pending
   NVIC_SetPendingIRQ(EIC_EXTINT_4_IRQn);

   //Successful processing
   return NO_ERROR;
}


/**
 * @brief Enable external interrupts
 **/

void extIntEnableIrq(void)
{
   //Enable interrupts
   NVIC_EnableIRQ(EIC_EXTINT_4_IRQn);
}


/**
 * @brief Disable external interrupts
 **/

void extIntDisableIrq(void)
{
   //Disable interrupts
   NVIC_DisableIRQ(EIC_EXTINT_4_IRQn);
}


/**
 * @brief External interrupt handler
 **/

void EIC_EXTINT_4_Handler(void)
{
   bool_t flag;
   NetInterface *interface;

   //Enter interrupt service routine
   osEnterIsr();

   //Point to the structure describing the network interface
   interface = &netInterface[0];
   //This flag will be set if a higher priority task must be woken
   flag = FALSE;

   //Clear interrupt flag
   EIC_REGS->EIC_INTFLAG = EIC_INTFLAG_EXTINT(1 << 4);

   //Ensure the IRQ pin is asserted
   if(!(PORT_REGS->GROUP[0].PORT_IN & PORT_PA04))
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
