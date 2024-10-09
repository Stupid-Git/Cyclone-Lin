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
#include "sam.h"
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
   PMC_REGS->PMC_PCER0 = (1 << ID_PIOA);
   //Enable FLEXCOM0 peripheral clock
   PMC_REGS->PMC_PCER0 = (1 << ID_FLEXCOM0);

   //Set FLEXCOM operation mode
   FLEXCOM0_REGS->FLEXCOM_MR = FLEXCOM_MR_OPMODE_USART;

   //Disable interrupts on TXD0 (PA10) and RXD0 (PA9) pins
   PIOA_REGS->PIO_IDR = PIO_PA10A_USART0_TXD | PIO_PA9A_USART0_RXD;
   //Enable pull-up resistors
   PIOA_REGS->PIO_PUER = PIO_PA10A_USART0_TXD | PIO_PA9A_USART0_RXD;
   //Assign corresponding pins to Peripheral A function
   PIOA_REGS->PIO_ABCDSR[0] &= ~(PIO_PA10A_USART0_TXD | PIO_PA9A_USART0_RXD);
   PIOA_REGS->PIO_ABCDSR[1] &= ~(PIO_PA10A_USART0_TXD | PIO_PA9A_USART0_RXD);
   //Disable the PIO from controlling the corresponding pins
   PIOA_REGS->PIO_PDR = PIO_PA10A_USART0_TXD | PIO_PA9A_USART0_RXD;

   //Disable interrupts on RTS0 (PA11) pin
   PIOA_REGS->PIO_IDR = PIO_PA11;
   //Configure RTS0 as an output
   PIOA_REGS->PIO_PER = PIO_PA11;
   PIOA_REGS->PIO_OER = PIO_PA11;
   //Assert RTS0
   PIOA_REGS->PIO_CODR = PIO_PA11;

#if (APP_UART_HW_FLOW_CTRL == ENABLED)
   //Disable interrupts on CTS0 (PA25) pin
   PIOA_REGS->PIO_IDR = PIO_PA25A_CTS0;
   //Enable pull-down resistor
   PIOA_REGS->PIO_PPDER = PIO_PA25A_CTS0;
   //Assign corresponding pin to Peripheral A function
   PIOA_REGS->PIO_ABCDSR[0] &= ~PIO_PA25A_CTS0;
   PIOA_REGS->PIO_ABCDSR[1] &= ~PIO_PA25A_CTS0;
   //Disable the PIO from controlling the corresponding pin
   PIOA_REGS->PIO_PDR = PIO_PA25A_CTS0;
#else
   //Disable interrupts on CTS0 (PA24) pin
   PIOA_REGS->PIO_IDR = PIO_PA24;
   //Enable pull-down resistor
   PIOA_REGS->PIO_PPDER = PIO_PA24;
   //Configure CTS0 as an input
   PIOA_REGS->PIO_PER = PIO_PA24;
   PIOA_REGS->PIO_ODR = PIO_PA24;
#endif

   //Reset transmitter and receiver
   USART0_REGS->US_CR = US_CR_RSTSTA_Msk | US_CR_RSTTX_Msk | US_CR_RSTRX_Msk;
   //Disable interrupts
   USART0_REGS->US_IDR = 0xFFFFFFFF;

   //Configure baud rate
   USART0_REGS->US_BRGR = SystemCoreClock / (16 * APP_UART_BAUDRATE);

#if (APP_UART_HW_FLOW_CTRL == ENABLED)
   //Enable hardware flow control
   USART0_REGS->US_MR = US_MR_CHMODE_NORMAL | US_MR_CHRL_8_BIT |
      US_MR_PAR_NO | US_MR_USART_MODE_HW_HANDSHAKING;
#else
   //Disable hardware flow control
   USART0_REGS->US_MR = US_MR_CHMODE_NORMAL | US_MR_CHRL_8_BIT |
      US_MR_PAR_NO | US_MR_USART_MODE_NORMAL;
#endif

   //Disable DMA channel
   USART0_REGS->US_PTCR = US_PTCR_TXTDIS_Msk | US_PTCR_RXTDIS_Msk;

   //Configure USART0 interrupts
   USART0_REGS->US_IER = US_IER_TXRDY_Msk | US_IER_RXRDY_Msk;

   //Set priority grouping (4 bits for pre-emption priority, no bits
   //for subpriority)
   NVIC_SetPriorityGrouping(3);

   //Configure FLEXCOM0 interrupt priority
   NVIC_SetPriority(FLEXCOM0_IRQn, NVIC_EncodePriority(3, 12, 0));

   //Enable transmitter and receiver
   USART0_REGS->US_CR = US_CR_TXEN_Msk | US_CR_RXEN_Msk;

   //Successful processing
   return NO_ERROR;
}


/**
 * @brief Enable UART interrupts
 **/

void uartEnableIrq(void)
{
   //Enable FLEXCOM0 interrupts
   NVIC_EnableIRQ(FLEXCOM0_IRQn);
}


/**
 * @brief Disable UART interrupts
 **/

void uartDisableIrq(void)
{
   //Disable FLEXCOM0 interrupt
   NVIC_DisableIRQ(FLEXCOM0_IRQn);
}


/**
 * @brief Start transmission
 **/

void uartStartTx(void)
{
   //Enable TXRDY interrupt
   USART0_REGS->US_IER = US_IER_TXRDY_Msk;
}


/**
 * @brief FLEXCOM0 interrupt handler
 **/

void FLEXCOM0_Handler(void)
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

   //TXRDY interrupt?
   if(USART0_REGS->US_CSR & US_CSR_TXRDY_Msk)
   {
      //Get next character
      flag |= pppHdlcDriverReadTxQueue(interface, &c);

      //Valid character read?
      if(c != EOF)
      {
         //Send data byte
         USART0_REGS->US_THR = c;
      }
      else
      {
         //Disable TXRDY interrupt
         USART0_REGS->US_IDR = US_IDR_TXRDY_Msk;
      }
   }

   //RXRDY interrupt?
   if(USART0_REGS->US_CSR & US_CSR_RXRDY_Msk)
   {
      //Read data byte
      c = USART0_REGS->US_RHR;
      //Process incoming character
      flag |= pppHdlcDriverWriteRxQueue(interface, c);
   }

   //OVRE interrupt?
   if(USART0_REGS->US_CSR & US_CSR_OVRE_Msk)
   {
      //Reset status bits
      USART0_REGS->US_CR = US_CR_RSTSTA_Msk;
   }

   //Leave interrupt service routine
   osExitIsr(flag);
}
