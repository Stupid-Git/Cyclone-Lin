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

//RST pin (P5_7)
#define CONF_WILC_RST_MASK      (1 << 7)
#define CONF_WILC_RST_PORT      R_PORT5
#define CONF_WILC_RST_PFS       PORT[5].PIN[7].PmnPFS

//CE pin (P4_0)
#define CONF_WILC_CE_MASK       (1 << 0)
#define CONF_WILC_CE_PORT       R_PORT4
#define CONF_WILC_CE_PFS        PORT[4].PIN[0].PmnPFS

//WAKE pin (unused)
#define CONF_WILC_WAKE_MASK     (1 << 0)
#define CONF_WILC_WAKE_PORT     R_PORT4
#define CONF_WILC_WAKE_PFS      PORT[4].PIN[0].PmnPFS

//CS pin (P3_7)
#define CONF_WILC_CS_MASK       (1 << 7)
#define CONF_WILC_CS_PORT       R_PORT3
#define CONF_WILC_CS_PFS        PORT[3].PIN[7].PmnPFS

//IRQ pin (P0_1)
#define CONF_WILC_IRQ_MASK      (1 << 1)
#define CONF_WILC_IRQ_PORT      R_PORT0
#define CONF_WILC_IRQ_PFS       PORT[0].PIN[1].PmnPFS

//SCK pin (P2_4)
#define CONF_WILC_SCK_PFS       PORT[2].PIN[4].PmnPFS
#define CONF_WILC_SCK_PSEL      6

//MOSI pin (P2_3)
#define CONF_WILC_MOSI_PFS      PORT[2].PIN[3].PmnPFS
#define CONF_WILC_MOSI_PSEL     6

//MISO pin (P2_2)
#define CONF_WILC_MISO_PFS      PORT[2].PIN[2].PmnPFS
#define CONF_WILC_MISO_PSEL     6

//SPI instance
#define CONF_WILC_SPI           R_SPI0
#define CONF_WILC_SPI_MSTPCR    MSTPCRB
#define CONF_WILC_SPI_MSTP_MASK (R_MSTP_MSTPCRB_MSTPB_Msk << 19)

//SPI bitrate
#define CONF_WILC_SPI_SPBR      4

//IRQ number
#define CONF_WILC_IRQ_NUM       7
#define CONF_WILC_IRQn          ICU_IRQ7_IRQn

//IRQ handler
#define CONF_WILC_IRQHandler    ICU_IRQ7_IRQHandler

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
