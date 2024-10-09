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
#include "fsl_device_registers.h"
#include "fsl_clock.h"
#include "fsl_port.h"
#include "fsl_uart.h"
#include "debug.h"


/**
 * @brief Debug UART initialization
 * @param[in] baudrate UART baudrate
 **/

void debugInit(uint32_t baudrate)
{
   uint32_t freq;
   uint32_t temp;
   port_pin_config_t portPinConfig;
   uart_config_t uartConfig;

   //Enable PORTB peripheral clock
   CLOCK_EnableClock(kCLOCK_PortB);
   //Enable UART0 peripheral clock
   CLOCK_EnableClock(kCLOCK_Uart0);

   //Configure UART0_RX (PORTB16)
   portPinConfig.pullSelect = kPORT_PullUp;
   portPinConfig.slewRate = kPORT_FastSlewRate;
   portPinConfig.passiveFilterEnable = kPORT_PassiveFilterDisable;
   portPinConfig.openDrainEnable = kPORT_OpenDrainDisable;
   portPinConfig.driveStrength = kPORT_LowDriveStrength;
   portPinConfig.mux = kPORT_MuxAlt3;
   portPinConfig.lockRegister = kPORT_UnlockRegister;
   PORT_SetPinConfig(PORTB, 16, &portPinConfig);

   //Configure UART0_TX (PORTB17)
   portPinConfig.pullSelect = kPORT_PullDisable;
   portPinConfig.slewRate = kPORT_FastSlewRate;
   portPinConfig.passiveFilterEnable = kPORT_PassiveFilterDisable;
   portPinConfig.openDrainEnable = kPORT_OpenDrainDisable;
   portPinConfig.driveStrength = kPORT_LowDriveStrength;
   portPinConfig.mux = kPORT_MuxAlt3;
   portPinConfig.lockRegister = kPORT_UnlockRegister;
   PORT_SetPinConfig(PORTB, 17, &portPinConfig);

   //Select the source for the UART0 transmit data
   temp = SIM->SOPT5 & ~SIM_SOPT5_UART0TXSRC_MASK;
   SIM->SOPT5 = temp | SIM_SOPT5_UART0TXSRC(0);

   //Select the source for the UART0 receive data
   temp = SIM->SOPT5 & ~SIM_SOPT5_UART0RXSRC_MASK;
   SIM->SOPT5 = temp | SIM_SOPT5_UART0RXSRC(0);

   //Get UART module clock frequency
   freq = CLOCK_GetCoreSysClkFreq();

   //Get default UART configuration
   UART_GetDefaultConfig(&uartConfig);
   //Adjust baudrate
   uartConfig.baudRate_Bps = baudrate;

   //Configure UART module
   UART_Init(UART0, &uartConfig, freq);

   //Enable transmitter and receiver
   UART_EnableTx(UART0, true);
   UART_EnableRx(UART0, true);
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
      //Character to be written
      uint8_t ch = c;

      //Transmit data
      UART_WriteBlocking(UART0, &ch, 1);

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
