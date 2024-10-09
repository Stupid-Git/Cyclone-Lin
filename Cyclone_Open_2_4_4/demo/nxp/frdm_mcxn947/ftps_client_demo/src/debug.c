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
#include "fsl_reset.h"
#include "fsl_lpuart.h"
#include "debug.h"


/**
 * @brief Debug UART initialization
 * @param[in] baudrate UART baudrate
 **/

void debugInit(uint32_t baudrate)
{
   port_pin_config_t portPinConfig;
   lpuart_config_t lpuartConfig;

   //Enable PORT1 clock
   CLOCK_EnableClock(kCLOCK_Port1);

   //Initialize port pin attributes
   portPinConfig.pullSelect = kPORT_PullDisable;
   portPinConfig.pullValueSelect = kPORT_LowPullResistor;
   portPinConfig.slewRate = kPORT_FastSlewRate;
   portPinConfig.passiveFilterEnable = kPORT_PassiveFilterDisable;
   portPinConfig.openDrainEnable = kPORT_OpenDrainDisable;
   portPinConfig.driveStrength = kPORT_LowDriveStrength;
   portPinConfig.mux = kPORT_MuxAlt2;
   portPinConfig.inputBuffer = kPORT_InputBufferEnable;
   portPinConfig.invertInput = kPORT_InputNormal;
   portPinConfig.lockRegister = kPORT_UnlockRegister;

   //Configure P1_8 pin as FC4_P0_UART_RXD
   PORT_SetPinConfig(PORT1, 8, &portPinConfig);
   //Configure P1_9 pin as FC4_P1_UART_TXD
   PORT_SetPinConfig(PORT1, 9, &portPinConfig);

   //Set FLEXCOMM4 clock source
   CLOCK_SetClkDiv(kCLOCK_DivFlexcom4Clk, 1);
   CLOCK_AttachClk(kFRO12M_to_FLEXCOMM4);

   //Reset FLEXCOMM4 peripheral
   RESET_PeripheralReset(kFC4_RST_SHIFT_RSTn);

   //Get default UART configuration
   LPUART_GetDefaultConfig(&lpuartConfig);
   //Adjust baudrate
   lpuartConfig.baudRate_Bps = baudrate;

   //Configure UART module
   LPUART_Init(LPUART4, &lpuartConfig, CLOCK_GetLPFlexCommClkFreq(4));

   //Enable transmitter and receiver
   LPUART_EnableTx(LPUART4, true);
   LPUART_EnableRx(LPUART4, true);
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
      LPUART_WriteBlocking(LPUART4, &ch, 1);

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
