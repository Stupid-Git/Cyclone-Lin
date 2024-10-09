/**
 * @file winc1500_config.h
 * @brief WINC1500 configuration
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

#ifndef _WINC1500_CONFIG_H
#define _WINC1500_CONFIG_H

//Dependencies
#include <stdint.h>

//SPI interface
#define CONF_WINC_USE_SPI               1

//Debug logs
#define CONF_WINC_DEBUG                 1
//Debug output redirection
#define CONF_WINC_PRINTF                TRACE_PRINTF

//RST pin (PA27)
#define CONF_WINC_RST_PIN               PIN_PA27
#define CONF_WINC_RST_MASK              PORT_PA27

//CE pin (PA28)
#define CONF_WINC_CE_PIN                PIN_PA28
#define CONF_WINC_CE_MASK               PORT_PA28

//WAKE pin (PB8)
#define CONF_WINC_WAKE_PIN              PIN_PB08
#define CONF_WINC_WAKE_MASK             PORT_PB08

//CS pin (PA14)
#define CONF_WINC_CS_PIN                PIN_PA14
#define CONF_WINC_CS_MASK               PORT_PA14

//IRQ pin (PB9)
#define CONF_WINC_IRQ_PIN               PIN_PB09
#define CONF_WINC_IRQ_MASK              PORT_PB09
#define CONF_WINC_IRQ_MUX()             PORT->Group[1].PMUX[4].bit.PMUXO = MUX_PB09A_EIC_EXTINT9
#define CONF_WINC_IRQ_CONFIG()          EIC->CONFIG[1].bit.SENSE1 = EIC_CONFIG_SENSE1_LOW_Val

//SCK pin (PA13)
#define CONF_WINC_SCK_PIN               PIN_PA13
#define CONF_WINC_SCK_MASK              PORT_PA13
#define CONF_WINC_SCK_PAD               1
#define CONF_WINC_SCK_MUX()             PORT->Group[0].PMUX[6].bit.PMUXO = MUX_PA13C_SERCOM2_PAD1

//MOSI pin (PA12)
#define CONF_WINC_MOSI_PIN              PIN_PA12
#define CONF_WINC_MOSI_MASK             PORT_PA12
#define CONF_WINC_MOSI_PAD              0
#define CONF_WINC_MOSI_MUX()            PORT->Group[0].PMUX[6].bit.PMUXE = MUX_PA12C_SERCOM2_PAD0

//MISO pin (PA15)
#define CONF_WINC_MISO_PIN              PIN_PA15
#define CONF_WINC_MISO_MASK             PORT_PA15
#define CONF_WINC_MISO_PAD              3
#define CONF_WINC_MISO_MUX()            PORT->Group[0].PMUX[7].bit.PMUXO = MUX_PA15C_SERCOM2_PAD3

//SERCOM instance
#define CONF_WINC_SERCOM                SERCOM2
#define CONF_WINC_SERCOM_GCLK_ID_CORE   GCLK_CLKCTRL_ID_SERCOM2_CORE
#define CONF_WINC_SERCOM_APB_CLK_EN()   PM->APBCMASK.bit.SERCOM2_ = 1

//SPI clock
#define CONF_WINC_SPI_CLOCK             12000000

//IRQ number
#define CONF_WINC_IRQn                  EIC_IRQn
//IRQ handler
#define CONF_WINC_IRQHandler            EIC_Handler

//Interrupt group priority
#define CONF_WINC_IRQ_PRIORITY          2

//Forward function declaration
extern void winc1500EventHook(uint8_t msgType, void *msg);

//Callback function that processes Wi-Fi event notifications
#define CONF_WINC_EVENT_HOOK(msgType, msg) winc1500EventHook(msgType, msg)

#endif
