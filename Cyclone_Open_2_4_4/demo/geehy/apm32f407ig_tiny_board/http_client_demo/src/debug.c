/**
 * @file debug.c
 * @brief Debugging facilities
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
#include "apm32f4xx.h"
#include "apm32f4xx_rcm.h"
#include "apm32f4xx_gpio.h"
#include "apm32f4xx_usart.h"
#include "debug.h"


/**
 * @brief Debug UART initialization
 * @param[in] baudrate UART baudrate
 **/

void debugInit(uint32_t baudrate)
{
   GPIO_Config_T gpioConfig;
   USART_Config_T usartConfig;

   //Enable GPIOA clock
   RCM_EnableAHB1PeriphClock(RCM_AHB1_PERIPH_GPIOA);
   //Enable USART1 clock
   RCM_EnableAPB2PeriphClock(RCM_APB2_PERIPH_USART1);

   //Configure USART1_TX (PA9)
   gpioConfig.pin = GPIO_PIN_9;
   gpioConfig.mode = GPIO_MODE_AF;
   gpioConfig.otype = GPIO_OTYPE_PP;
   gpioConfig.pupd = GPIO_PUPD_UP;
   gpioConfig.speed = GPIO_SPEED_2MHz;
   GPIO_Config(GPIOA, &gpioConfig);

   //Configure USART1_RX (PA10)
   gpioConfig.pin = GPIO_PIN_10;
   gpioConfig.mode = GPIO_MODE_AF;
   gpioConfig.pupd = GPIO_PUPD_UP;
   gpioConfig.speed = GPIO_SPEED_2MHz;
   GPIO_Config(GPIOA, &gpioConfig);

   //Remap USART1 pins
   GPIO_ConfigPinAF(GPIOA, GPIO_PIN_SOURCE_9, GPIO_AF_USART1);
   GPIO_ConfigPinAF(GPIOA, GPIO_PIN_SOURCE_10, GPIO_AF_USART1);

   //Configure USART1
   usartConfig.baudRate = baudrate;
   usartConfig.wordLength = USART_WORD_LEN_8B;
   usartConfig.stopBits = USART_STOP_BIT_1;
   usartConfig.parity = USART_PARITY_NONE;
   usartConfig.mode = USART_MODE_TX_RX;
   usartConfig.hardwareFlow = USART_HARDWARE_FLOW_NONE;
   USART_Config(USART1, &usartConfig);

   //Enable USART1
   USART_Enable(USART1);
}


/**
 * @brief Display the contents of an array
 * @param[in] stream Pointer to a FILE object that identifies an output stream
 * @param[in] prepend String to prepend to the left of each line
 * @param[in] data Pointer to the data array
 * @param[in] length Number of bytes to display
 **/

void debugDisplayArray(FILE *stream,
   const char_t *prepend, const void *data, size_t length)
{
   uint_t i;

   for(i = 0; i < length; i++)
   {
      //Beginning of a new line?
      if((i % 16) == 0)
         fprintf(stream, "%s", prepend);
      //Display current data byte
      fprintf(stream, "%02" PRIX8 " ", *((uint8_t *) data + i));
      //End of current line?
      if((i % 16) == 15 || i == (length - 1))
         fprintf(stream, "\r\n");
   }
}


/**
 * @brief Write character to stream
 * @param[in] c The character to be written
 * @param[in] stream Pointer to a FILE object that identifies an output stream
 * @return On success, the character written is returned. If a writing
 *   error occurs, EOF is returned
 **/

int_t fputc(int_t c, FILE *stream)
{
   //Standard output or error output?
   if(stream == stdout || stream == stderr)
   {
      //Wait for the transmitter to be ready
      while(USART_ReadStatusFlag(USART1, USART_FLAG_TXBE) == RESET)
      {
      }

      //Transmit data
      USART_TxData(USART1, (uint8_t) c);

      //Wait for the transfer to complete
      while(USART_ReadStatusFlag(USART1, USART_FLAG_TXBE) == RESET)
      {
      }

      //On success, the character written is returned
      return c;
   }
   //Unknown output?
   else
   {
      //If a writing error occurs, EOF is returned
      return EOF;
   }
}
