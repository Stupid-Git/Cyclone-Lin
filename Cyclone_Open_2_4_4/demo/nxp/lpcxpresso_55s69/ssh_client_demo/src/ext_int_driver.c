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
#include "fsl_device_registers.h"
#include "fsl_inputmux.h"
#include "fsl_pint.h"
#include "core/net.h"
#include "drivers/eth/lan9250_driver.h"
#include "ext_int_driver.h"
#include "debug.h"

//Forward declaration of functions
void extIntHandler(pint_pin_int_t pintr, uint32_t pmatch_status);


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
   //Enable GPIO1 clock
   CLOCK_EnableClock(kCLOCK_Gpio1);

   //Connect trigger sources to PINT1
   INPUTMUX_Init(INPUTMUX);
   INPUTMUX_AttachSignal(INPUTMUX, kPINT_PinInt1, kINPUTMUX_GpioPort1Pin18ToPintsel);
   INPUTMUX_Deinit(INPUTMUX);

   //Initialize PINT
   PINT_Init(PINT);

   //Configure PINT1 interrupt
   PINT_PinInterruptConfig(PINT, kPINT_PinInt1, kPINT_PinIntEnableLowLevel,
      extIntHandler);

   //Enable callbacks for PINT1 by index
   PINT_EnableCallbackByIndex(PINT, kPINT_PinInt1);

   //Set priority grouping
   NVIC_SetPriorityGrouping(4);

   //Configure PINT1 interrupt priority
   NVIC_SetPriority(PIN_INT1_IRQn, NVIC_EncodePriority(4, 7, 0));

   //Successful processing
   return NO_ERROR;
}


/**
 * @brief Enable external interrupts
 **/

void extIntEnableIrq(void)
{
   //Enable interrupts
   NVIC_EnableIRQ(PIN_INT1_IRQn);
}


/**
 * @brief Disable external interrupts
 **/

void extIntDisableIrq(void)
{
   //Disable interrupts
   NVIC_DisableIRQ(PIN_INT1_IRQn);
}


/**
 * @brief External interrupt handler
 **/

void extIntHandler(pint_pin_int_t pintr, uint32_t pmatch_status)
{
   bool_t flag;
   NetInterface *interface;

   //Enter interrupt service routine
   osEnterIsr();

   //Point to the structure describing the network interface
   interface = &netInterface[0];
   //Call interrupt handler
   flag = lan9250IrqHandler(interface);

   //Leave interrupt service routine
   osExitIsr(flag);
}
