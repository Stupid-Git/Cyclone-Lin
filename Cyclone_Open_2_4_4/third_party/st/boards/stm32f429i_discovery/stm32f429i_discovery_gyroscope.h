/**
  ******************************************************************************
  * @file    stm32f429i_discovery_gyroscope.h
  * @author  MCD Application Team
  * @brief   This file contains definitions for stm32f429i_discovery_gyroscope.c 
  *          firmware driver.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F429I_DISCOVERY_GYROSCOPE_H
#define __STM32F429I_DISCOVERY_GYROSCOPE_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f429i_discovery.h"
/* Include Gyroscope component driver */
#include "../components/l3gd20/l3gd20.h"
#if defined(USE_STM32F429I_DISCOVERY_REVD)
#include "../components/i3g4250d/i3g4250d.h"
#endif /* USE_STM32F429I_DISCOVERY_REVD */
/** @addtogroup BSP
  * @{
  */
  
/** @addtogroup STM32F429I_DISCOVERY
  * @{
  */ 

/** @addtogroup STM32F429I_DISCOVERY_GYROSCOPE
  * @{
  */
  
/** @defgroup STM32F429I_DISCOVERY_GYROSCOPE_Exported_Types STM32F429I DISCOVERY GYROSCOPE Exported Types
  * @{
  */
typedef enum 
{
  GYRO_OK = 0,
  GYRO_ERROR = 1,
  GYRO_TIMEOUT = 2
}GYRO_StatusTypeDef;
/**
  * @}
  */
  
/** @defgroup STM32F429I_DISCOVERY_GYROSCOPE_Exported_Constants STM32F429I DISCOVERY GYROSCOPE Exported Constants
  * @{
  */
/**
  * @}
  */

/** @defgroup STM32F429I_DISCOVERY_GYROSCOPE_Exported_Macros STM32F429I DISCOVERY GYROSCOPE Exported Macros
  * @{
  */
/**
  * @}
  */
 
/** @defgroup STM32F429I_DISCOVERY_GYROSCOPE_Exported_Functions STM32F429I DISCOVERY GYROSCOPE Exported Functions
  * @{
  */
/* Gyroscope Functions */ 
uint8_t BSP_GYRO_Init(void);
void    BSP_GYRO_Reset(void);
uint8_t BSP_GYRO_ReadID(void);
void    BSP_GYRO_ITConfig(GYRO_InterruptConfigTypeDef *pIntConfigStruct);
void    BSP_GYRO_EnableIT(uint8_t IntPin);
void    BSP_GYRO_DisableIT(uint8_t IntPin);
void    BSP_GYRO_GetXYZ(float* pfData);

/**
  * @}
  */

/**
  * @}
  */ 

/**
  * @}
  */ 

/**
  * @}
  */ 

#ifdef __cplusplus
}
#endif

#endif /* __STM32F429I_DISCOVERY_GYROSCOPE_H */
