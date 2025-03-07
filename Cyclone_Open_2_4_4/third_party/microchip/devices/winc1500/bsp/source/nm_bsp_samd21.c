/**
 * @file nm_bsp_samd21.c
 * @brief BSP for SAMD21 microcontrollers
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
#include "samd21.h"
#include "bsp/include/nm_bsp.h"
#include "common/include/nm_common.h"
#include "core/net.h"
#include "drivers/wifi/winc1500_driver.h"

//IRQ handler
static tpfNmBspIsr gpfIsr;


/**
 * @brief GPIO initialization
 **/

static void init_chip_pins(void)
{
   //Enable PORT bus clock (CLK_PORT_APB)
   PM->APBBMASK.bit.PORT_ = 1;

   //Configure RST pin
   PORT->Group[CONF_WINC_RST_PIN / 32].DIRSET.reg = CONF_WINC_RST_MASK;
   PORT->Group[CONF_WINC_RST_PIN / 32].OUTCLR.reg = CONF_WINC_RST_MASK;

   //Configure CE pin
   PORT->Group[CONF_WINC_CE_PIN / 32].DIRSET.reg = CONF_WINC_CE_MASK;
   PORT->Group[CONF_WINC_CE_PIN / 32].OUTCLR.reg = CONF_WINC_CE_MASK;

   //Configure WAKE pin
   PORT->Group[CONF_WINC_WAKE_PIN / 32].DIRSET.reg = CONF_WINC_WAKE_MASK;
   PORT->Group[CONF_WINC_WAKE_PIN / 32].OUTCLR.reg = CONF_WINC_WAKE_MASK;

   //Configure CS pin
   PORT->Group[CONF_WINC_CS_PIN / 32].DIRSET.reg = CONF_WINC_CS_MASK;
   PORT->Group[CONF_WINC_CS_PIN / 32].OUTSET.reg = CONF_WINC_CS_MASK;
   PORT->Group[CONF_WINC_CS_PIN / 32].PINCFG[CONF_WINC_CS_PIN % 32].bit.DRVSTR = 1;

   //Configure IRQ pin
   PORT->Group[CONF_WINC_IRQ_PIN / 32].DIRCLR.reg = CONF_WINC_IRQ_MASK;
   PORT->Group[CONF_WINC_IRQ_PIN / 32].OUTSET.reg = CONF_WINC_IRQ_MASK;
   PORT->Group[CONF_WINC_IRQ_PIN / 32].PINCFG[CONF_WINC_IRQ_PIN % 32].bit.PULLEN = 1;
   PORT->Group[CONF_WINC_IRQ_PIN / 32].PINCFG[CONF_WINC_IRQ_PIN % 32].bit.INEN = 1;
   PORT->Group[CONF_WINC_IRQ_PIN / 32].PINCFG[CONF_WINC_IRQ_PIN % 32].bit.PMUXEN = 1;
   CONF_WINC_IRQ_MUX();
}


/**
 * @brief BSP initialization
 * @return Status code
 **/

sint8 nm_bsp_init(void)
{
   //Initialize IRQ handler
   gpfIsr = NULL;

   //Initialize WINC1500 pins
   init_chip_pins();

   //Reset WINC1500 chip
   nm_bsp_reset();

   //No error to report
   return M2M_SUCCESS;
}


/**
 * @brief Reset chip
 **/

void nm_bsp_reset(void)
{
   //Debug message
   M2M_PRINT("nm_bsp_reset\r\n");

   //Set CE and RST pins low
   PORT->Group[CONF_WINC_CE_PIN / 32].OUTCLR.reg = CONF_WINC_CE_MASK;
   PORT->Group[CONF_WINC_RST_PIN / 32].OUTCLR.reg = CONF_WINC_RST_MASK;
   nm_bsp_sleep(100);

   //Set CE pin high
   PORT->Group[CONF_WINC_CE_PIN / 32].OUTSET.reg = CONF_WINC_CE_MASK;
   nm_bsp_sleep(100);

   //Set RST pin high
   PORT->Group[CONF_WINC_RST_PIN / 32].OUTSET.reg = CONF_WINC_RST_MASK;
   nm_bsp_sleep(100);
}


/**
 * @brief Delay routine
 * @param[in] u32TimeMsec Time interval in milliseconds
 **/

void nm_bsp_sleep(uint32 u32TimeMsec)
{
   while(u32TimeMsec--)
   {
      sleep(1);
   }
}

/**
 * @brief Register interrupt service routine
 * @param[in] pfIsr ISR handler
 **/

void nm_bsp_register_isr(tpfNmBspIsr pfIsr)
{
   //Save ISR handler
   gpfIsr = pfIsr;

   //Enable EIC core clock
   GCLK->CLKCTRL.reg = GCLK_CLKCTRL_CLKEN | GCLK_CLKCTRL_GEN_GCLK0 |
      GCLK_CLKCTRL_ID_EIC;

   //Wait for synchronization
   while(GCLK->STATUS.reg & GCLK_STATUS_SYNCBUSY);

   //Enable EIC bus clock (CLK_EIC_APB)
   PM->APBAMASK.bit.EIC_ = 1;

   //Configure the EIC input sense and filtering
   CONF_WINC_IRQ_CONFIG();

   //Enable the EIC
   EIC->CTRL.bit.ENABLE = 1;

   //Enabling and disabling the EIC requires synchronization
   while(EIC->STATUS.bit.SYNCBUSY);

   //Enable external interrupts
   EIC->INTENSET.reg = CONF_WINC_IRQ_MASK;

   //Configure EIC interrupt priority
   NVIC_SetPriority(CONF_WINC_IRQn, CONF_WINC_IRQ_PRIORITY);

   //Enable EIC interrupt
   NVIC_EnableIRQ(CONF_WINC_IRQn);
   NVIC_SetPendingIRQ(CONF_WINC_IRQn);
}


/**
 * @brief Enable/disable interrupts
 * @param[in] u8Enable Interrupt enable state
 **/

void nm_bsp_interrupt_ctrl(uint8 u8Enable)
{
   if(u8Enable)
   {
      //Enable external interrupt
      NVIC_EnableIRQ(CONF_WINC_IRQn);
   }
   else
   {
      //Disable external interrupt
      NVIC_DisableIRQ(CONF_WINC_IRQn);
   }
}


/**
 * @brief IRQ handler
 **/

void CONF_WINC_IRQHandler(void)
{
   bool_t flag;

   //Enter interrupt service routine
   osEnterIsr();

   //This flag will be set if a higher priority task must be woken
   flag = FALSE;

   //Clear interrupt flag
   EIC->INTFLAG.reg = CONF_WINC_IRQ_MASK;

   //Ensure the IRQ pin is asserted
   if(!(PORT->Group[CONF_WINC_IRQ_PIN / 32].IN.reg & CONF_WINC_IRQ_MASK))
   {
      //WINC1500 interrupt processing
      if(gpfIsr != NULL)
         gpfIsr();

      //Call interrupt handler
      flag = winc1500IrqHandler();
   }

   //Leave interrupt service routine
   osExitIsr(flag);
}
