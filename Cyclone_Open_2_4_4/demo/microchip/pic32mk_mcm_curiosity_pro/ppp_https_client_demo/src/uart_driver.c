/**
 * @file uart_driver.c
 * @brief UART driver
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
#include <stdio.h>
#include <p32xxxx.h>
#include "core/net.h"
#include "ppp/ppp_hdlc.h"
#include "uart_driver.h"
#include "debug.h"

//UART baudrate
#define APP_UART_BAUDRATE 115200
//Hardware flow control
#define APP_UART_HW_FLOW_CTRL DISABLED


/**
 * @brief UART driver
 **/

const UartDriver uartDriver =
{
   uartInit,
   uartEnableIrq,
   uartDisableIrq,
   uartStartTx
};


/**
 * @brief UART configuration
 * @return Error code
 **/

error_t uartInit(void)
{
   //Debug message
   TRACE_INFO("Initializing UART...\r\n");

   //Disable analog pad on U4TX (AN10/RA12)
   ANSELACLR = _ANSELA_ANSA12_MASK;

   //Remap U4TX to RPA12
   RPA12R = 2;
   //Remap U4RX to RPD3
   U4RXR = 13;

   //Disable analog pad on RC0
   ANSELCCLR = _ANSELC_ANSC0_MASK;

#if (APP_UART_HW_FLOW_CTRL == ENABLED)
   //Remap U4RTS to RPD4
   RPD4R = 2;
   //Remap U4CTS to RPC0
   U4CTSR = 6;
#else
   //Configure RTS (RC0) as an output
   TRISCCLR = _TRISC_TRISC0_MASK;
   //Assert RTS1
   LATCCLR = _LATC_LATC0_MASK;

   //Configure CTS (RD4) as an input
   TRISDSET = _TRISD_TRISD4_MASK;
   //Enable pull-down resistor on CTS pin
   CNPDDSET = _CNPDD_CNPDD4_MASK;
#endif

   //Configure UART4 (8 bits, no parity, 1 stop bit)
   U4STA = 0;
   //Enable high-speed mode
   U4MODE = _U4MODE_BRGH_MASK;
   //Set baudrate
   U4BRG = ((60000000 / 4) / APP_UART_BAUDRATE) - 1;

#if (APP_UART_HW_FLOW_CTRL == ENABLED)
   //Enable hardware flow control
   U4MODESET = _U4MODE_UEN1_MASK;
#else
   //Disable hardware flow control
   U4MODECLR = _U4MODE_UEN1_MASK | _U4MODE_UEN0_MASK;
#endif

   //Set UART4 TX interrupt priority
   IPC16CLR = _IPC16_U4TXIP_MASK;
   IPC16SET = (2 << _IPC16_U4TXIP_POSITION);
   //Set UART4 TX interrupt subpriority
   IPC16CLR = _IPC16_U4TXIS_MASK;
   IPC16SET = (0 << _IPC16_U4TXIS_POSITION);

   //Set UART4 RX interrupt priority
   IPC16CLR = _IPC16_U4RXIP_MASK;
   IPC16SET = (2 << _IPC16_U4RXIP_POSITION);
   //Set UART4 RX interrupt subpriority
   IPC16CLR = _IPC16_U4RXIS_MASK;
   IPC16SET = (0 << _IPC16_U4RXIS_POSITION);

   //Enable UART4
   U4MODESET = _U4MODE_ON_MASK;
   //Enable transmitter and receiver
   U4STASET = _U4STA_UTXEN_MASK | _U4STA_URXEN_MASK;

   //Successful processing
   return NO_ERROR;
}


/**
 * @brief Enable UART interrupts
 **/

void uartEnableIrq(void)
{
   //Enable UART4 interrupts
   IEC2SET = _IEC2_U4TXIE_MASK | _IEC2_U4RXIE_MASK;
}


/**
 * @brief Disable UART interrupts
 **/

void uartDisableIrq(void)
{
   //Disable UART4 interrupts
   IEC2CLR = _IEC2_U4TXIE_MASK | _IEC2_U4RXIE_MASK;
}


/**
 * @brief Start transmission
 **/

void uartStartTx(void)
{
   //Enable UART4 TX interrupts
   IEC2SET = _IEC2_U4TXIE_MASK;
}


/**
 * @brief UART TX interrupt handler
 **/

void uartTxIrqHandler(void)
{
   int_t c;
   bool_t flag;
   NetInterface *interface;

   //Enter interrupt service routine
   osEnterIsr();

   //This flag will be set if a higher priority task must be woken
   flag = FALSE;

   //Point to the PPP network interface
   interface = &netInterface[0];

   //Check status
   if((U4STA & _U4STA_UTXBF_MASK) == 0)
   {
      //Get next character
      flag |= pppHdlcDriverReadTxQueue(interface, &c);

      //Valid character read?
      if(c != EOF)
      {
         //Send data byte
         U4TXREG = c;
         //Clear interrupt flag
         IFS2CLR = _IFS2_U4TXIF_MASK;
      }
      else
      {
         //Disable TXRDY interrupt
         IEC2CLR = _IEC2_U4TXIE_MASK;
      }
   }

   //Leave interrupt service routine
   osExitIsr(flag);
}


/**
 * @brief UART RX interrupt handler
 **/

void uartRxIrqHandler(void)
{
   int_t c;
   bool_t flag;
   NetInterface *interface;

   //Enter interrupt service routine
   osEnterIsr();

   //This flag will be set if a higher priority task must be woken
   flag = FALSE;

   //Point to the PPP network interface
   interface = &netInterface[0];

   //Check status
   if((U4STA & _U4STA_URXDA_MASK) != 0)
   {
      //Read data byte
      c = U4RXREG;
      //Clear interrupt flag
      IFS2CLR = _IFS2_U4RXIF_MASK;
      //Process incoming character
      flag |= pppHdlcDriverWriteRxQueue(interface, c);
   }
   else
   {
      //Clear interrupt flag
      IFS2CLR = _IFS2_U4RXIF_MASK;
   }

   //Leave interrupt service routine
   osExitIsr(flag);
}
