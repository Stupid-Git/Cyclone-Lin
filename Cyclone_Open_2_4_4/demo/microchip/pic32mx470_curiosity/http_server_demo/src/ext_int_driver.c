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
#include <p32xxxx.h>
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
   //Enable pull-up on INT1 (AN24/RD1)
   CNPUDSET = _CNPUD_CNPUD1_MASK;
   //Disable analog pad
   ANSELDCLR = _ANSELD_ANSD1_MASK;

   //Remap INT1 to RPD1
   INT1R = 0;

   //Configure edge polarity for INT1 interrupt (falling edge)
   INTCONCLR = _INTCON_INT1EP_MASK;

   //Set interrupt priority
   IPC1CLR = _IPC1_INT1IP_MASK;
   IPC1SET = (2 << _IPC1_INT1IP_POSITION);

   //Set interrupt subpriority
   IPC1CLR = _IPC1_INT1IS_MASK;
   IPC1SET = (0 << _IPC1_INT1IS_POSITION);

   //Successful processing
   return NO_ERROR;
}


/**
 * @brief Enable external interrupts
 **/

void extIntEnableIrq(void)
{
   //Enable interrupts
   IEC0SET = _IEC0_INT1IE_MASK;
}


/**
 * @brief Disable external interrupts
 **/

void extIntDisableIrq(void)
{
   //Disable interrupts
   IEC0CLR = _IEC0_INT1IE_MASK;
}


/**
 * @brief External interrupt handler
 **/

void extIntHandler(void)
{
   bool_t flag;
   NetInterface *interface;

   //Enter interrupt service routine
   osEnterIsr();

   //Point to the structure describing the network interface
   interface = &netInterface[0];
   //This flag will be set if a higher priority task must be woken
   flag = FALSE;

   //Check interrupt status
   if(IFS0 & _IFS0_INT1IF_MASK)
   {
      //Clear interrupt flag
      IFS0CLR = _IFS0_INT1IF_MASK;
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
