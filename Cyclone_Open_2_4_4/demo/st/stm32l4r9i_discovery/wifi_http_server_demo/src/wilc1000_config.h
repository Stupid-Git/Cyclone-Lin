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
#define CONF_WILC_USE_SPI                1

//Debug logs
#define CONF_WILC_DEBUG                  1
//Debug output redirection
#define CONF_WILC_PRINTF                 TRACE_PRINTF

//RST pin (PI7)
#define CONF_WILC_RST_GPIO               GPIOI
#define CONF_WILC_RST_PIN                GPIO_PIN_7
#define CONF_WILC_RST_SPEED              GPIO_SPEED_FREQ_MEDIUM
#define CONF_WILC_RST_GPIO_CLK_ENABLE()  __HAL_RCC_GPIOI_CLK_ENABLE()

//CE pin (PA5)
#define CONF_WILC_CE_GPIO                GPIOA
#define CONF_WILC_CE_PIN                 GPIO_PIN_5
#define CONF_WILC_CE_SPEED               GPIO_SPEED_FREQ_MEDIUM
#define CONF_WILC_CE_GPIO_CLK_ENABLE()   __HAL_RCC_GPIOA_CLK_ENABLE()

//WAKE pin (unused)
#define CONF_WILC_WAKE_GPIO              GPIOA
#define CONF_WILC_WAKE_PIN               GPIO_PIN_5
#define CONF_WILC_WAKE_SPEED             GPIO_SPEED_FREQ_MEDIUM
#define CONF_WILC_WAKE_GPIO_CLK_ENABLE() __HAL_RCC_GPIOA_CLK_ENABLE()

//CS pin (PA6)
#define CONF_WILC_CS_GPIO                GPIOA
#define CONF_WILC_CS_PIN                 GPIO_PIN_6
#define CONF_WILC_CS_SPEED               GPIO_SPEED_FREQ_VERY_HIGH
#define CONF_WILC_CS_GPIO_CLK_ENABLE()   __HAL_RCC_GPIOA_CLK_ENABLE()

//IRQ pin (PC6)
#define CONF_WILC_IRQ_GPIO               GPIOC
#define CONF_WILC_IRQ_PIN                GPIO_PIN_6
#define CONF_WILC_IRQ_GPIO_CLK_ENABLE()  __HAL_RCC_GPIOC_CLK_ENABLE()

//SCK pin (PB13)
#define CONF_WILC_SCK_GPIO               GPIOB
#define CONF_WILC_SCK_PIN                GPIO_PIN_13
#define CONF_WILC_SCK_SPEED              GPIO_SPEED_FREQ_VERY_HIGH
#define CONF_WILC_SCK_GPIO_CLK_ENABLE()  __HAL_RCC_GPIOB_CLK_ENABLE();

//MOSI pin (PI3)
#define CONF_WILC_MOSI_GPIO              GPIOI
#define CONF_WILC_MOSI_PIN               GPIO_PIN_3
#define CONF_WILC_MOSI_SPEED             GPIO_SPEED_FREQ_VERY_HIGH
#define CONF_WILC_MOSI_GPIO_CLK_ENABLE() __HAL_RCC_GPIOI_CLK_ENABLE()

//MISO pin (PI2)
#define CONF_WILC_MISO_GPIO              GPIOI
#define CONF_WILC_MISO_PIN               GPIO_PIN_2
#define CONF_WILC_MISO_SPEED             GPIO_SPEED_FREQ_VERY_HIGH
#define CONF_WILC_MISO_GPIO_CLK_ENABLE() __HAL_RCC_GPIOI_CLK_ENABLE()

//SPI instance
#define CONF_WILC_SPI                    SPI2
#define CONF_WILC_SPI_ALTERNATE          GPIO_AF5_SPI2
#define CONF_WILC_SPI_CLK_ENABLE()       __HAL_RCC_SPI2_CLK_ENABLE()

//SPI clock prescaler
#define CONF_WILC_SPI_BAUDRATE_PRE       SPI_BAUDRATEPRESCALER_4

//IRQ number
#define CONF_WILC_IRQn                   EXTI9_5_IRQn
//IRQ handler
#define CONF_WILC_IRQHandler             EXTI9_5_IRQHandler

//Interrupt priority grouping
#define CONF_WILC_IRQ_PRIORITY_GROUPING  3
//Interrupt group priority
#define CONF_WILC_IRQ_GROUP_PRIORITY     15
//Interrupt subpriority
#define CONF_WILC_IRQ_SUB_PRIORITY       0

//Forward function declaration
extern void wilc1000EventHook(uint8_t msgType, void *msg);

//Callback function that processes Wi-Fi event notifications
#define CONF_WILC_EVENT_HOOK(msgType, msg) wilc1000EventHook(msgType, msg)

#endif
