/**
  ******************************************************************************
  * @file    stm32u575i_eval_ospi.h
  * @author  MCD Application Team
  * @brief   This file contains the common defines and functions prototypes for
  *          the stm32u575i_eval_ospi.c driver.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef STM32U575I_EVAL_OSPI_H
#define STM32U575I_EVAL_OSPI_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32u575i_eval_conf.h"
#include "stm32u575i_eval_errno.h"
#include "../components/mx25lm51245g/mx25lm51245g.h"

/** @addtogroup BSP
  * @{
  */

/** @addtogroup STM32U575I_EVAL
  * @{
  */

/** @addtogroup STM32U575I_EVAL_OSPI
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup STM32U575I_EVAL_OSPI_Exported_Types OSPI Exported Types
  * @{
  */
typedef enum
{
  OSPI_ACCESS_NONE = 0,          /*!<  Instance not initialized,              */
  OSPI_ACCESS_INDIRECT,          /*!<  Instance use indirect mode access      */
  OSPI_ACCESS_MMP                /*!<  Instance use Memory Mapped Mode read   */
} OSPI_Access_t;

#if (USE_HAL_OSPI_REGISTER_CALLBACKS == 1)
typedef struct
{
  pOSPI_CallbackTypeDef  pMspInitCb;
  pOSPI_CallbackTypeDef  pMspDeInitCb;
} BSP_OSPI_Cb_t;
#endif /* (USE_HAL_OSPI_REGISTER_CALLBACKS == 1) */

typedef struct
{
  uint32_t MemorySize;
  uint32_t ClockPrescaler;
  uint32_t SampleShifting;
  uint32_t TransferRate;
} MX_OSPI_InitTypeDef;
/**
  * @}
  */

#define BSP_OSPI_NOR_Info_t                MX25LM51245G_Info_t
#define BSP_OSPI_NOR_Interface_t           MX25LM51245G_Interface_t
#define BSP_OSPI_NOR_Transfer_t            MX25LM51245G_Transfer_t
#define BSP_OSPI_NOR_Erase_t               MX25LM51245G_Erase_t

typedef struct
{
  OSPI_Access_t              IsInitialized;  /*!<  Instance access Flash method     */
  BSP_OSPI_NOR_Interface_t   InterfaceMode;  /*!<  Flash Interface mode of Instance */
  BSP_OSPI_NOR_Transfer_t    TransferRate;   /*!<  Flash Transfer mode of Instance  */
} OSPI_NOR_Ctx_t;

typedef struct
{
  BSP_OSPI_NOR_Interface_t   InterfaceMode;      /*!<  Current Flash Interface mode */
  BSP_OSPI_NOR_Transfer_t    TransferRate;       /*!<  Current Flash Transfer rate  */
} BSP_OSPI_NOR_Init_t;

/* Exported constants --------------------------------------------------------*/
/** @defgroup STM32U575I_EVAL_OSPI_Exported_Constants OSPI Exported Constants
  * @{
  */
/* Definition for OSPI clock resources */
#define OSPI_CLK_ENABLE()                 __HAL_RCC_OSPI2_CLK_ENABLE()
#define OSPI_CLK_DISABLE()                __HAL_RCC_OSPI2_CLK_DISABLE()

#define OSPI_CLK_GPIO_CLK_ENABLE()        __HAL_RCC_GPIOH_CLK_ENABLE()
#define OSPI_DQS_GPIO_CLK_ENABLE()        __HAL_RCC_GPIOH_CLK_ENABLE()
#define OSPI_CS_GPIO_CLK_ENABLE()         __HAL_RCC_GPIOI_CLK_ENABLE()
#define OSPI_D0_GPIO_CLK_ENABLE()         __HAL_RCC_GPIOI_CLK_ENABLE()
#define OSPI_D1_GPIO_CLK_ENABLE()         __HAL_RCC_GPIOI_CLK_ENABLE()
#define OSPI_D2_GPIO_CLK_ENABLE()         __HAL_RCC_GPIOI_CLK_ENABLE()
#define OSPI_D3_GPIO_CLK_ENABLE()         __HAL_RCC_GPIOH_CLK_ENABLE()
#define OSPI_D4_GPIO_CLK_ENABLE()         __HAL_RCC_GPIOH_CLK_ENABLE()
#define OSPI_D5_GPIO_CLK_ENABLE()         __HAL_RCC_GPIOH_CLK_ENABLE()
#define OSPI_D6_GPIO_CLK_ENABLE()         __HAL_RCC_GPIOH_CLK_ENABLE()
#define OSPI_D7_GPIO_CLK_ENABLE()         __HAL_RCC_GPIOH_CLK_ENABLE()

#define OSPI_FORCE_RESET()                __HAL_RCC_OSPI2_FORCE_RESET()
#define OSPI_RELEASE_RESET()              __HAL_RCC_OSPI2_RELEASE_RESET()

/* Definition for OSPI Pins */
/* OSPI_CLK */
#define OSPI_CLK_PIN                      GPIO_PIN_6
#define OSPI_CLK_GPIO_PORT                GPIOH
#define OSPI_CLK_PIN_AF                   GPIO_AF5_OCTOSPI2
/* OSPI_DQS */
#define OSPI_DQS_PIN                      GPIO_PIN_4
#define OSPI_DQS_GPIO_PORT                GPIOH
#define OSPI_DQS_PIN_AF                   GPIO_AF5_OCTOSPI2
/* OSPI_CS */
#define OSPI_CS_PIN                       GPIO_PIN_5
#define OSPI_CS_GPIO_PORT                 GPIOI
#define OSPI_CS_PIN_AF                    GPIO_AF5_OCTOSPI2
/* OSPI_D0 */
#define OSPI_D0_PIN                       GPIO_PIN_3
#define OSPI_D0_GPIO_PORT                 GPIOI
#define OSPI_D0_PIN_AF                    GPIO_AF6_OCTOSPI2
/* OSPI_D1 */
#define OSPI_D1_PIN                       GPIO_PIN_2
#define OSPI_D1_GPIO_PORT                 GPIOI
#define OSPI_D1_PIN_AF                    GPIO_AF6_OCTOSPI2
/* OSPI_D2 */
#define OSPI_D2_PIN                       GPIO_PIN_1
#define OSPI_D2_GPIO_PORT                 GPIOI
#define OSPI_D2_PIN_AF                    GPIO_AF6_OCTOSPI2
/* OSPI_D3 */
#define OSPI_D3_PIN                       GPIO_PIN_8
#define OSPI_D3_GPIO_PORT                 GPIOH
#define OSPI_D3_PIN_AF                    GPIO_AF5_OCTOSPI2
/* OSPI_D4 */
#define OSPI_D4_PIN                       GPIO_PIN_9
#define OSPI_D4_GPIO_PORT                 GPIOH
#define OSPI_D4_PIN_AF                    GPIO_AF5_OCTOSPI2
/* OSPI_D5 */
#define OSPI_D5_PIN                       GPIO_PIN_10
#define OSPI_D5_GPIO_PORT                 GPIOH
#define OSPI_D5_PIN_AF                    GPIO_AF5_OCTOSPI2
/* OSPI_D6 */
#define OSPI_D6_PIN                       GPIO_PIN_11
#define OSPI_D6_GPIO_PORT                 GPIOH
#define OSPI_D6_PIN_AF                    GPIO_AF5_OCTOSPI2
/* OSPI_D7 */
#define OSPI_D7_PIN                       GPIO_PIN_12
#define OSPI_D7_GPIO_PORT                 GPIOH
#define OSPI_D7_PIN_AF                    GPIO_AF5_OCTOSPI2

/* OSPI NOR instances number */
#define OSPI_NOR_INSTANCES_NUMBER         1U

/* Definition for OSPI modes */
#define BSP_OSPI_NOR_SPI_MODE (BSP_OSPI_NOR_Interface_t)MX25LM51245G_SPI_MODE /* 1 Cmd, 1 Address and 1 Data Line  */
#define BSP_OSPI_NOR_OPI_MODE (BSP_OSPI_NOR_Interface_t)MX25LM51245G_OPI_MODE /* 8 Cmd, 8 Address and 8 Data Lines */

/* Definition for OSPI transfer rates */
#define BSP_OSPI_NOR_STR_TRANSFER (BSP_OSPI_NOR_Transfer_t)MX25LM51245G_STR_TRANSFER   /* Single Transfer Rate */
#define BSP_OSPI_NOR_DTR_TRANSFER (BSP_OSPI_NOR_Transfer_t)MX25LM51245G_DTR_TRANSFER   /* Double Transfer Rate */

/* OSPI erase types */
#define BSP_OSPI_NOR_ERASE_4K             MX25LM51245G_ERASE_4K
#define BSP_OSPI_NOR_ERASE_64K            MX25LM51245G_ERASE_64K
#define BSP_OSPI_NOR_ERASE_CHIP           MX25LM51245G_ERASE_BULK

/* OSPI block sizes */
#define BSP_OSPI_NOR_BLOCK_4K             MX25LM51245G_SUBSECTOR_4K
#define BSP_OSPI_NOR_BLOCK_64K            MX25LM51245G_SECTOR_64K
/**
  * @}
  */

/* Exported variables --------------------------------------------------------*/
/** @defgroup STM32U575I_EVAL_OSPI_NOR_Exported_Variables OSPI Exported Variables
  * @{
  */
extern OSPI_HandleTypeDef hospi_nor[OSPI_NOR_INSTANCES_NUMBER];
extern OSPI_NOR_Ctx_t Ospi_Nor_Ctx[OSPI_NOR_INSTANCES_NUMBER];
/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup STM32U575I_EVAL_OSPI_NOR_Exported_Functions OSPI Exported Functions
  * @{
  */
int32_t BSP_OSPI_NOR_Init(uint32_t Instance, BSP_OSPI_NOR_Init_t *Init);
int32_t BSP_OSPI_NOR_DeInit(uint32_t Instance);
#if (USE_HAL_OSPI_REGISTER_CALLBACKS == 1)
int32_t BSP_OSPI_NOR_RegisterMspCallbacks(uint32_t Instance, BSP_OSPI_Cb_t *CallBacks);
int32_t BSP_OSPI_NOR_RegisterDefaultMspCallbacks(uint32_t Instance);
#endif /* (USE_HAL_OSPI_REGISTER_CALLBACKS == 1) */
int32_t BSP_OSPI_NOR_Read(uint32_t Instance, uint8_t *pData, uint32_t ReadAddr, uint32_t Size);
int32_t BSP_OSPI_NOR_Write(uint32_t Instance, uint8_t *pData, uint32_t WriteAddr, uint32_t Size);
int32_t BSP_OSPI_NOR_Erase_Block(uint32_t Instance, uint32_t BlockAddress, BSP_OSPI_NOR_Erase_t BlockSize);
int32_t BSP_OSPI_NOR_Erase_Chip(uint32_t Instance);
int32_t BSP_OSPI_NOR_GetStatus(uint32_t Instance);
int32_t BSP_OSPI_NOR_GetInfo(uint32_t Instance, BSP_OSPI_NOR_Info_t *pInfo);
int32_t BSP_OSPI_NOR_EnableMemoryMappedMode(uint32_t Instance);
int32_t BSP_OSPI_NOR_DisableMemoryMappedMode(uint32_t Instance);
int32_t BSP_OSPI_NOR_ReadID(uint32_t Instance, uint8_t *Id);
int32_t BSP_OSPI_NOR_ConfigFlash(uint32_t Instance, BSP_OSPI_NOR_Interface_t Mode, BSP_OSPI_NOR_Transfer_t Rate);
int32_t BSP_OSPI_NOR_SuspendErase(uint32_t Instance);
int32_t BSP_OSPI_NOR_ResumeErase(uint32_t Instance);
int32_t BSP_OSPI_NOR_EnterDeepPowerDown(uint32_t Instance);
int32_t BSP_OSPI_NOR_LeaveDeepPowerDown(uint32_t Instance);

/* These functions can be modified in case the current settings
   need to be changed for specific application needs */
HAL_StatusTypeDef MX_OSPI_NOR_Init(OSPI_HandleTypeDef *hospi, MX_OSPI_InitTypeDef *Init);

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

#endif /* STM32U575I_EVAL_OSPI_H */
