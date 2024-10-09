/**
 * @file wilc1000_config.h
 * @brief WILC1000 configuration
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

#ifndef _WILC1000_CONFIG_H
#define _WILC1000_CONFIG_H

//Dependencies
#include <stdint.h>

//WILC1000 chip revision
#define CONF_WILC_USE_1000_REV_B

//SPI interface
#define CONF_WILC_USE_SPI       1

//Debug logs
#define CONF_WILC_DEBUG         1
//Debug output redirection
#define CONF_WILC_PRINTF        TRACE_PRINTF

//RST pin (P4_13)
#define CONF_WILC_RST_MASK      (1 << 13)
#define CONF_WILC_RST_PORT      R_PORT4
#define CONF_WILC_RST_PFS       PORT[4].PIN[13].PmnPFS

//CE pin (P4_15)
#define CONF_WILC_CE_MASK       (1 << 15)
#define CONF_WILC_CE_PORT       R_PORT4
#define CONF_WILC_CE_PFS        PORT[4].PIN[15].PmnPFS

//WAKE pin (unused)
#define CONF_WILC_WAKE_MASK     (1 << 15)
#define CONF_WILC_WAKE_PORT     R_PORT4
#define CONF_WILC_WAKE_PFS      PORT[4].PIN[15].PmnPFS

//CS pin (P4_14)
#define CONF_WILC_CS_MASK       (1 << 14)
#define CONF_WILC_CS_PORT       R_PORT4
#define CONF_WILC_CS_PFS        PORT[4].PIN[14].PmnPFS

//IRQ pin (P5_5)
#define CONF_WILC_IRQ_MASK      (1 << 5)
#define CONF_WILC_IRQ_PORT      R_PORT5
#define CONF_WILC_IRQ_PFS       PORT[5].PIN[5].PmnPFS

//SCK pin (P4_12)
#define CONF_WILC_SCK_PFS       PORT[4].PIN[12].PmnPFS
#define CONF_WILC_SCK_PSEL      6

//MOSI pin (P4_11)
#define CONF_WILC_MOSI_PFS      PORT[4].PIN[11].PmnPFS
#define CONF_WILC_MOSI_PSEL     6

//MISO pin (P4_10)
#define CONF_WILC_MISO_PFS      PORT[4].PIN[10].PmnPFS
#define CONF_WILC_MISO_PSEL     6

//SPI instance
#define CONF_WILC_SPI           R_SPI0
#define CONF_WILC_SPI_MSTPCR    MSTPCRB
#define CONF_WILC_SPI_MSTP_MASK (R_MSTP_MSTPCRB_MSTPB_Msk << 19)

//SPI bitrate
#define CONF_WILC_SPI_SPBR      4

//IRQ number
#define CONF_WILC_IRQ_NUM       14
#define CONF_WILC_IRQn          ICU_IRQ14_IRQn

//IRQ handler
#define CONF_WILC_IRQHandler    ICU_IRQ14_IRQHandler

//Interrupt priority grouping
#define CONF_WILC_IRQ_PRIORITY_GROUPING 3
//Interrupt group priority
#define CONF_WILC_IRQ_GROUP_PRIORITY    15
//Interrupt subpriority
#define CONF_WILC_IRQ_SUB_PRIORITY      0

//Forward function declaration
extern void wilc1000EventHook(uint8_t msgType, void *msg);

//Callback function that processes Wi-Fi event notifications
#define CONF_WILC_EVENT_HOOK(msgType, msg) wilc1000EventHook(msgType, msg)

#endif
