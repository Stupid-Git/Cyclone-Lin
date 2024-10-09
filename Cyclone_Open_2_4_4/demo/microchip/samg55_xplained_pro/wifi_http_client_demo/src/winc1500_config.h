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
#define CONF_WINC_USE_SPI     1

//Debug logs
#define CONF_WINC_DEBUG       1
//Debug output redirection
#define CONF_WINC_PRINTF      TRACE_PRINTF

//RST pin (PA26)
#define CONF_WINC_RST_PIN     PIO_PA26
#define CONF_WINC_RST_PIO     PIOA_REGS
#define CONF_WINC_RST_ID_PIO  ID_PIOA

//CE pin (PA29)
#define CONF_WINC_CE_PIN      PIO_PA29
#define CONF_WINC_CE_PIO      PIOA_REGS
#define CONF_WINC_CE_ID_PIO   ID_PIOA

//WAKE pin (PA25)
#define CONF_WINC_WAKE_PIN    PIO_PA25
#define CONF_WINC_WAKE_PIO    PIOA_REGS
#define CONF_WINC_WAKE_ID_PIO ID_PIOA

//CS pin (PA11)
#define CONF_WINC_CS_PIN      PIO_PA11
#define CONF_WINC_CS_PIO      PIOA_REGS
#define CONF_WINC_CS_ID_PIO   ID_PIOA

//IRQ pin (PA24)
#define CONF_WINC_IRQ_PIN     PIO_PA24
#define CONF_WINC_IRQ_PIO     PIOA_REGS
#define CONF_WINC_IRQ_ID_PIO  ID_PIOA

//SCK pin (PA14)
#define CONF_WINC_SCK_PIN     PIO_PA14A_SPI5_SPCK

//MOSI pin (PA13)
#define CONF_WINC_MOSI_PIN    PIO_PA13A_SPI5_MOSI

//MISO pin (PA12)
#define CONF_WINC_MISO_PIN    PIO_PA12A_SPI5_MISO

//FLEXCOM instance
#define CONF_WINC_FLEXCOM     FLEXCOM5_REGS
#define CONF_WINC_FLEXCOM_ID  ID_FLEXCOM5

//SPI instance
#define CONF_WINC_SPI         SPI5_REGS
#define CONF_WINC_SPI_PIO     PIOA_REGS
#define CONF_WINC_SPI_ID_PIO  ID_PIOA

//SPI clock
#define CONF_WINC_SPI_CLOCK   24000000

//IRQ number
#define CONF_WINC_IRQn        PIOA_IRQn
//IRQ handler
#define CONF_WINC_IRQHandler  PIOA_Handler

//Interrupt priority grouping
#define CONF_WINC_IRQ_PRIORITY_GROUPING 3
//Interrupt group priority
#define CONF_WINC_IRQ_GROUP_PRIORITY    15
//Interrupt subpriority
#define CONF_WINC_IRQ_SUB_PRIORITY      0

//Forward function declaration
extern void winc1500EventHook(uint8_t msgType, void *msg);

//Callback function that processes Wi-Fi event notifications
#define CONF_WINC_EVENT_HOOK(msgType, msg) winc1500EventHook(msgType, msg)

#endif
