/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * TEXT BELOW IS USED AS SETTING FOR THE PINS TOOL *****************************
PinsProfile:
- !!product 'Pins v2.0'
- !!processor 'MK60DN512xxx10'
- !!package 'MK60DN512VMD10'
- !!mcu_data 'ksdk2_0'
- !!processor_version '1.0.0'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR THE PINS TOOL ***
 */

#include "fsl_common.h"
#include "fsl_gpio.h"
#include "fsl_port.h"
#include "board.h"
#include "pin_mux.h"

#define PIN8_IDX                         8u   /*!< Pin number for pin 8 in a port */
#define PIN9_IDX                         9u   /*!< Pin number for pin 9 in a port */
#define PIN11_IDX                       11u   /*!< Pin number for pin 11 in a port */
#define PIN19_IDX                       19u   /*!< Pin number for pin 19 in a port */

/*
 * TEXT BELOW IS USED AS SETTING FOR THE PINS TOOL *****************************
BOARD_InitPins:
- options: {coreID: singlecore, enableClock: 'true'}
- pin_list:
  - {pin_num: F3, peripheral: UART5, signal: TX, pin_signal: PTE8/I2S0_RXD1/UART5_TX/I2S0_RX_FS}
  - {pin_num: F2, peripheral: UART5, signal: RX, pin_signal: PTE9/I2S0_TXD1/UART5_RX/I2S0_RX_BCLK}
  - {pin_num: L9, peripheral: GPIOA, signal: 'GPIO, 11', pin_signal: PTA11/FTM2_CH1/MII0_RXCLK/FTM2_QD_PHB}
  - {pin_num: M11, peripheral: GPIOA, signal: 'GPIO, 19', pin_signal: XTAL0/PTA19/FTM1_FLT0/FTM_CLKIN1/LPTMR0_ALT1, slew_rate: fast, open_drain: disable, pull_select: up,
    pull_enable: enable, passive_filter: disable, drive_strength: low}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR THE PINS TOOL ***
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void BOARD_InitPins(void) {
  CLOCK_EnableClock(kCLOCK_PortA);                           /* Port A Clock Gate Control: Clock enabled */
  CLOCK_EnableClock(kCLOCK_PortE);                           /* Port E Clock Gate Control: Clock enabled */

  PORT_SetPinMux(PORTA, PIN11_IDX, kPORT_MuxAsGpio);         /* PORTA11 (pin L9) is configured as PTA11 */
  const port_pin_config_t porta19_pinM11_config = {
    kPORT_PullUp,                                            /* Internal pull-up resistor is enabled */
    kPORT_FastSlewRate,                                      /* Fast slew rate is configured */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_OpenDrainDisable,                                  /* Open drain is disabled */
    kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
    kPORT_MuxAsGpio,                                         /* Pin is configured as PTA19 */
    kPORT_UnlockRegister                                     /* Pin Control Register fields [15:0] are not locked */
  };
  PORT_SetPinConfig(PORTA, PIN19_IDX, &porta19_pinM11_config); /* PORTA19 (pin M11) is configured as PTA19 */
  PORT_SetPinMux(PORTE, PIN8_IDX, kPORT_MuxAlt3);            /* PORTE8 (pin F3) is configured as UART5_TX */
  PORT_SetPinMux(PORTE, PIN9_IDX, kPORT_MuxAlt3);            /* PORTE9 (pin F2) is configured as UART5_RX */
}

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitBUTTONsPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitButtonsPins(void)
{
  port_pin_config_t portPinConfig;
  gpio_pin_config_t gpioPinConfig;

  CLOCK_EnableClock(kCLOCK_PortA);
  CLOCK_EnableClock(kCLOCK_PortE);

  portPinConfig.pullSelect = kPORT_PullUp;
  portPinConfig.slewRate = kPORT_FastSlewRate;
  portPinConfig.passiveFilterEnable = kPORT_PassiveFilterDisable;
  portPinConfig.openDrainEnable = kPORT_OpenDrainDisable;
  portPinConfig.driveStrength = kPORT_HighDriveStrength;
  portPinConfig.mux = kPORT_MuxAsGpio;
  portPinConfig.lockRegister = kPORT_UnlockRegister;

  gpioPinConfig.pinDirection = kGPIO_DigitalInput;
  gpioPinConfig.outputLogic = 0;

  PORT_SetPinConfig(BOARD_SW1_PORT, BOARD_SW1_GPIO_PIN, &portPinConfig);
  GPIO_PinInit(BOARD_SW1_GPIO, BOARD_SW1_GPIO_PIN, &gpioPinConfig);

  PORT_SetPinConfig(BOARD_SW2_PORT, BOARD_SW2_GPIO_PIN, &portPinConfig);
  GPIO_PinInit(BOARD_SW2_GPIO, BOARD_SW2_GPIO_PIN, &gpioPinConfig);
}

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitLEDsPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitLEDsPins(void)
{
  port_pin_config_t portPinConfig;
  gpio_pin_config_t gpioPinConfig;

  CLOCK_EnableClock(kCLOCK_PortA);

  portPinConfig.pullSelect = kPORT_PullDisable;
  portPinConfig.slewRate = kPORT_FastSlewRate;
  portPinConfig.passiveFilterEnable = kPORT_PassiveFilterDisable;
  portPinConfig.openDrainEnable = kPORT_OpenDrainDisable;
  portPinConfig.driveStrength = kPORT_HighDriveStrength;
  portPinConfig.mux = kPORT_MuxAsGpio;
  portPinConfig.lockRegister = kPORT_UnlockRegister;

  gpioPinConfig.pinDirection = kGPIO_DigitalOutput;
  gpioPinConfig.outputLogic = 1;

  PORT_SetPinConfig(BOARD_LED_ORANGE_PORT, BOARD_LED_ORANGE_GPIO_PIN, &portPinConfig);
  GPIO_PinInit(BOARD_LED_ORANGE_GPIO, BOARD_LED_ORANGE_GPIO_PIN, &gpioPinConfig);

  PORT_SetPinConfig(BOARD_LED_YELLOW_PORT, BOARD_LED_YELLOW_GPIO_PIN, &portPinConfig);
  GPIO_PinInit(BOARD_LED_YELLOW_GPIO, BOARD_LED_YELLOW_GPIO_PIN, &gpioPinConfig);

  PORT_SetPinConfig(BOARD_LED_GREEN_PORT, BOARD_LED_GREEN_GPIO_PIN, &portPinConfig);
  GPIO_PinInit(BOARD_LED_GREEN_GPIO, BOARD_LED_GREEN_GPIO_PIN, &gpioPinConfig);

  PORT_SetPinConfig(BOARD_LED_BLUE_PORT, BOARD_LED_BLUE_GPIO_PIN, &portPinConfig);
  GPIO_PinInit(BOARD_LED_BLUE_GPIO, BOARD_LED_BLUE_GPIO_PIN, &gpioPinConfig);
}

/*******************************************************************************
 * EOF
 ******************************************************************************/
