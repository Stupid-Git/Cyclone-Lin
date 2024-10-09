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
#define CONF_WINC_USE_SPI                1

//Debug logs
#define CONF_WINC_DEBUG                  1
//Debug output redirection
#define CONF_WINC_PRINTF                 TRACE_PRINTF

//RST pin (PP4)
#define CONF_WINC_RST_PORT               GPIO_PORTP_BASE
#define CONF_WINC_RST_PIN                GPIO_PIN_4
#define CONF_WINC_RST_PERIPH             SYSCTL_PERIPH_GPIOP
#define CONF_WINC_RST_STRENGTH           GPIO_STRENGTH_10MA

//CE pin (PN5)
#define CONF_WINC_CE_PORT                GPIO_PORTN_BASE
#define CONF_WINC_CE_PIN                 GPIO_PIN_5
#define CONF_WINC_CE_PERIPH              SYSCTL_PERIPH_GPION
#define CONF_WINC_CE_STRENGTH            GPIO_STRENGTH_10MA

//WAKE pin (PN4)
#define CONF_WINC_WAKE_PORT              GPIO_PORTN_BASE
#define CONF_WINC_WAKE_PIN               GPIO_PIN_4
#define CONF_WINC_WAKE_PERIPH            SYSCTL_PERIPH_GPION
#define CONF_WINC_WAKE_STRENGTH          GPIO_STRENGTH_10MA

//CS pin (PQ1)
#define CONF_WINC_CS_PORT                GPIO_PORTQ_BASE
#define CONF_WINC_CS_PIN                 GPIO_PIN_1
#define CONF_WINC_CS_PERIPH              SYSCTL_PERIPH_GPIOQ
#define CONF_WINC_CS_STRENGTH            GPIO_STRENGTH_10MA

//IRQ pin (PM6)
#define CONF_WINC_IRQ_PORT               GPIO_PORTM_BASE
#define CONF_WINC_IRQ_PIN                GPIO_PIN_6
#define CONF_WINC_IRQ_INT_PIN            GPIO_INT_PIN_6
#define CONF_WINC_IRQ_PERIPH             SYSCTL_PERIPH_GPIOM
#define CONF_WINC_IRQ_STRENGTH           GPIO_STRENGTH_10MA

//SCK pin (PQ0)
#define CONF_WINC_SCK_PORT               GPIO_PORTQ_BASE
#define CONF_WINC_SCK_PIN                GPIO_PIN_0
#define CONF_WINC_SCK_PERIPH             SYSCTL_PERIPH_GPIOQ
#define CONF_WINC_SCK_STRENGTH           GPIO_STRENGTH_10MA
#define CONF_WINC_SCK_CONFIG             GPIO_PQ0_SSI3CLK

//MOSI pin (PQ2)
#define CONF_WINC_MOSI_PORT              GPIO_PORTQ_BASE
#define CONF_WINC_MOSI_PIN               GPIO_PIN_2
#define CONF_WINC_MOSI_PERIPH            SYSCTL_PERIPH_GPIOQ
#define CONF_WINC_MOSI_STRENGTH          GPIO_STRENGTH_10MA
#define CONF_WINC_MOSI_CONFIG            GPIO_PQ2_SSI3XDAT0

//MISO pin (PQ3)
#define CONF_WINC_MISO_PORT              GPIO_PORTQ_BASE
#define CONF_WINC_MISO_PIN               GPIO_PIN_3
#define CONF_WINC_MISO_PERIPH            SYSCTL_PERIPH_GPIOQ
#define CONF_WINC_MISO_STRENGTH          GPIO_STRENGTH_10MA
#define CONF_WINC_MISO_CONFIG            GPIO_PQ3_SSI3XDAT1

//SSI instance
#define CONF_WINC_SSI                    SSI3_BASE
#define CONF_WINC_SSI_PERIPH             SYSCTL_PERIPH_SSI3

//SPI clock
#define CONF_WINC_SPI_CLOCK              10000000

//IRQ number
#define CONF_WINC_IRQn                   INT_GPIOM
//IRQ handler
#define CONF_WINC_IRQHandler             GPIOM_Handler

//Interrupt priority grouping
#define CONF_WINC_IRQ_PRIORITY_GROUPING  3
//Interrupt priority
#define CONF_WINC_IRQ_PRIORITY           192

//Forward function declaration
extern void winc1500EventHook(uint8_t msgType, void *msg);

//Callback function that processes Wi-Fi event notifications
#define CONF_WINC_EVENT_HOOK(msgType, msg) winc1500EventHook(msgType, msg)

#endif
