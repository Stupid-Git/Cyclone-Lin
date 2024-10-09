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
#include "sam4e.h"
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

   //Enable PIOA peripheral clock
   PMC->PMC_PCER0 = (1 << ID_PIOA);
   //Enable USART1 peripheral clock
   PMC->PMC_PCER0 = (1 << ID_USART1);

   //Disable interrupts on TXD1 (PA22) and RXD1 (PA21) pins
   PIOA->PIO_IDR = PIO_PA22A_TXD1 | PIO_PA21A_RXD1;
   //Enable pull-up resistors
   PIOA->PIO_PUER = PIO_PA22A_TXD1 | PIO_PA21A_RXD1;
   //Assign corresponding pins to Peripheral A function
   PIOA->PIO_ABCDSR[0] &= ~(PIO_PA22A_TXD1 | PIO_PA21A_RXD1);
   PIOA->PIO_ABCDSR[1] &= ~(PIO_PA22A_TXD1 | PIO_PA21A_RXD1);
   //Disable the PIO from controlling the corresponding pins
   PIOA->PIO_PDR = PIO_PA22A_TXD1 | PIO_PA21A_RXD1;

   //Disable interrupts on RTS1 (PA24) pin
   PIOA->PIO_IDR = PIO_PA24A_RTS1;
   //Configure RTS1 as an output
   PIOA->PIO_PER = PIO_PA24A_RTS1;
   PIOA->PIO_OER = PIO_PA24A_RTS1;
   //Assert RTS1
   PIOA->PIO_CODR = PIO_PA24A_RTS1;

#if (APP_UART_HW_FLOW_CTRL == ENABLED)
   //Disable interrupts on CTS1 (PA25) pin
   PIOA->PIO_IDR = PIO_PA25A_CTS1;
   //Enable pull-down resistor
   PIOA->PIO_PPDER = PIO_PA25A_CTS1;
   //Assign corresponding pin to Peripheral A function
   PIOA->PIO_ABCDSR[0] &= ~PIO_PA25A_CTS1;
   PIOA->PIO_ABCDSR[1] &= ~PIO_PA25A_CTS1;
   //Disable the PIO from controlling the corresponding pin
   PIOA->PIO_PDR = PIO_PA25A_CTS1;
#else
   //Disable interrupts on CTS1 (PA25) pin
   PIOA->PIO_IDR = PIO_PA25A_CTS1;
   //Enable pull-down resistor
   PIOA->PIO_PPDER = PIO_PA25A_CTS1;
   //Configure CTS1 as an input
   PIOA->PIO_PER = PIO_PA25A_CTS1;
   PIOA->PIO_ODR = PIO_PA25A_CTS1;
#endif

   //Reset transmitter and receiver
   USART1->US_CR = US_CR_RSTSTA | US_CR_RSTTX | US_CR_RSTRX;
   //Disable interrupts
   USART1->US_IDR = 0xFFFFFFFF;

   //Configure baud rate
   USART1->US_BRGR = SystemCoreClock / (16 * APP_UART_BAUDRATE);

#if (APP_UART_HW_FLOW_CTRL == ENABLED)
   //Enable hardware flow control
   USART1->US_MR = US_MR_CHMODE_NORMAL | US_MR_CHRL_8_BIT |
      US_MR_PAR_NO | US_MR_USART_MODE_HW_HANDSHAKING;
#else
   //Disable hardware flow control
   USART1->US_MR = US_MR_CHMODE_NORMAL | US_MR_CHRL_8_BIT |
      US_MR_PAR_NO | US_MR_USART_MODE_NORMAL;
#endif

   //Disable DMA channel
   USART1->US_PTCR = US_PTCR_TXTDIS | US_PTCR_RXTDIS;

   //Configure USART1 interrupts
   USART1->US_IER = US_IER_TXRDY | US_IER_RXRDY;

   //Set priority grouping (4 bits for pre-emption priority, no bits
   //for subpriority)
   NVIC_SetPriorityGrouping(3);

   //Configure USART1 interrupt priority
   NVIC_SetPriority(USART1_IRQn, NVIC_EncodePriority(3, 12, 0));

   //Enable transmitter and receiver
   USART1->US_CR = US_CR_TXEN | US_CR_RXEN;

   //Successful processing
   return NO_ERROR;
}


/**
 * @brief Enable UART interrupts
 **/

void uartEnableIrq(void)
{
   //Enable USART1 interrupts
   NVIC_EnableIRQ(USART1_IRQn);
}


/**
 * @brief Disable UART interrupts
 **/

void uartDisableIrq(void)
{
   //Disable USART1 interrupt
   NVIC_DisableIRQ(USART1_IRQn);
}


/**
 * @brief Start transmission
 **/

void uartStartTx(void)
{
   //Enable TXRDY interrupt
   USART1->US_IER = US_IER_TXRDY;
}


/**
 * @brief UART interrupt handler
 **/

void USART1_Handler(void)
{
   int_t c;
   bool_t flag;
   NetInterface *interface;

   //Enter interrupt service routine
   osEnterIsr();

   //This flag will be set if a higher priority task must be woken
   flag = FALSE;

   //Point to the PPP network interface
   interface = &netInterface[1];

   //TXRDY interrupt?
   if(USART1->US_CSR & US_CSR_TXRDY)
   {
      //Get next character
      flag |= pppHdlcDriverReadTxQueue(interface, &c);

      //Valid character read?
      if(c != EOF)
      {
         //Send data byte
         USART1->US_THR = c;
      }
      else
      {
         //Disable TXRDY interrupt
         USART1->US_IDR = US_IDR_TXRDY;
      }
   }

   //RXRDY interrupt?
   if(USART1->US_CSR & US_CSR_RXRDY)
   {
      //Read data byte
      c = USART1->US_RHR;
      //Process incoming character
      flag |= pppHdlcDriverWriteRxQueue(interface, c);
   }

   //OVRE interrupt?
   if(USART1->US_CSR & US_CSR_OVRE)
   {
      //Reset status bits
      USART1->US_CR = US_CR_RSTSTA;
   }

   //Leave interrupt service routine
   osExitIsr(flag);
}
