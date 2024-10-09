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

//RST pin (PA6)
#define CONF_WINC_RST_PIN               PIN_PA06
#define CONF_WINC_RST_MASK              PORT_PA06

//CE pin (PA27)
#define CONF_WINC_CE_PIN                PIN_PA27
#define CONF_WINC_CE_MASK               PORT_PA27

//WAKE pin (PA7)
#define CONF_WINC_WAKE_PIN              PIN_PA07
#define CONF_WINC_WAKE_MASK             PORT_PA07

//CS pin (PB28)
#define CONF_WINC_CS_PIN                PIN_PB28
#define CONF_WINC_CS_MASK               PORT_PB28

//IRQ pin (PB7)
#define CONF_WINC_IRQ_PIN               PIN_PB07
#define CONF_WINC_IRQ_MASK              PORT_PB07
#define CONF_WINC_IRQ_MUX()             PORT_REGS->GROUP[1].PORT_PMUX[3] = \
                                           (PORT_REGS->GROUP[1].PORT_PMUX[3] & ~PORT_PMUX_PMUXO_Msk) | \
                                           PORT_PMUX_PMUXO(MUX_PB07A_EIC_EXTINT7)
#define CONF_WINC_IRQ_CONFIG()          EIC_REGS->EIC_CONFIG[0] = \
                                           (EIC_REGS->EIC_CONFIG[0] & ~EIC_CONFIG_SENSE7_Msk) | \
                                           EIC_CONFIG_SENSE7_LOW

//SCK pin (PB26)
#define CONF_WINC_SCK_PIN               PIN_PB26
#define CONF_WINC_SCK_MASK              PORT_PB26
#define CONF_WINC_SCK_PAD               1
#define CONF_WINC_SCK_MUX()             PORT_REGS->GROUP[1].PORT_PMUX[13] = \
                                           (PORT_REGS->GROUP[1].PORT_PMUX[13] & ~PORT_PMUX_PMUXE_Msk) | \
                                           PORT_PMUX_PMUXE(MUX_PB26D_SERCOM4_PAD1)

//MOSI pin (PB27)
#define CONF_WINC_MOSI_PIN              PIN_PB27
#define CONF_WINC_MOSI_MASK             PORT_PB27
#define CONF_WINC_MOSI_PAD              0
#define CONF_WINC_MOSI_MUX()            PORT_REGS->GROUP[1].PORT_PMUX[13] = \
                                           (PORT_REGS->GROUP[1].PORT_PMUX[13] & ~PORT_PMUX_PMUXO_Msk) | \
                                           PORT_PMUX_PMUXO(MUX_PB27D_SERCOM4_PAD0)

//MISO pin (PB29)
#define CONF_WINC_MISO_PIN              PIN_PB29
#define CONF_WINC_MISO_MASK             PORT_PB29
#define CONF_WINC_MISO_PAD              3
#define CONF_WINC_MISO_MUX()            PORT_REGS->GROUP[1].PORT_PMUX[14] = \
                                           (PORT_REGS->GROUP[1].PORT_PMUX[14] & ~PORT_PMUX_PMUXO_Msk) | \
                                           PORT_PMUX_PMUXO(MUX_PB29D_SERCOM4_PAD3)

//SERCOM instance
#define CONF_WINC_SERCOM                SERCOM4_REGS
#define CONF_WINC_SERCOM_GCLK_ID_CORE   SERCOM4_GCLK_ID_CORE
#define CONF_WINC_SERCOM_APB_CLK_EN()   MCLK_REGS->MCLK_APBDMASK |= MCLK_APBDMASK_SERCOM4_Msk

//SPI clock
#define CONF_WINC_SPI_CLOCK             20000000

//IRQ number
#define CONF_WINC_IRQn                  EIC_EXTINT_7_IRQn
//IRQ handler
#define CONF_WINC_IRQHandler            EIC_EXTINT_7_Handler

//Interrupt priority grouping
#define CONF_WINC_IRQ_PRIORITY_GROUPING 4
//Interrupt group priority
#define CONF_WINC_IRQ_GROUP_PRIORITY    7
//Interrupt subpriority
#define CONF_WINC_IRQ_SUB_PRIORITY      0

//Forward function declaration
extern void winc1500EventHook(uint8_t msgType, void *msg);

//Callback function that processes Wi-Fi event notifications
#define CONF_WINC_EVENT_HOOK(msgType, msg) winc1500EventHook(msgType, msg)

#endif
