/**
  ******************************************************************************
  * @file    stm32mp13xx_hal_nand.h
  * @author  MCD Application Team
  * @brief   Header file of NAND HAL module.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef STM32MP13xx_HAL_NAND_H
#define STM32MP13xx_HAL_NAND_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif


/* Includes ------------------------------------------------------------------*/
#include "stm32mp13xx_ll_fmc.h"

/** @addtogroup STM32MP13xx_HAL_Driver
  * @{
  */

/** @addtogroup NAND
  * @{
  */

/* Exported typedef ----------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/** @defgroup NAND_Exported_Types NAND Exported Types
  * @{
  */

/**
  * @brief  HAL NAND State enum definition
  */
typedef enum
{
  HAL_NAND_STATE_RESET     = 0x00U,  /*!< NAND not yet initialized or disabled */
  HAL_NAND_STATE_READY     = 0x01U,  /*!< NAND initialized and ready for use   */
  HAL_NAND_STATE_BUSY      = 0x02U,  /*!< NAND internal process is ongoing     */
  HAL_NAND_STATE_ERROR     = 0x03U   /*!< NAND error state                     */
} HAL_NAND_StateTypeDef;

/**
  * @brief  HAL NAND Error name definition
  */
typedef enum
{
  HAL_NAND_ERROR_NONE      = 0x00U,  /*!< No error                             */
  HAL_NAND_ERROR_TIMEOUT   = 0x01U,  /*!< Timeout error                        */
  HAL_NAND_ERROR_NO_XFER   = 0x02U,  /*!< Abort requested with no Xfer ongoing */
  HAL_NAND_ERROR_DMA       = 0x04U,  /*!< Error when initializing DMA          */
  HAL_NAND_ERROR_BUSY      = 0x08U   /*!< Busy error                           */
} HAL_NAND_ErrorTypeDef;

/**
  * @brief  NAND Memory electronic signature Structure definition
  */
typedef struct
{
  /*<! NAND memory electronic signature maker and device IDs */

  uint8_t Maker_Id;

  uint8_t Device_Id;

  uint8_t Third_Id;

  uint8_t Fourth_Id;
} NAND_IDTypeDef;

/**
  * @brief  NAND Memory address Structure definition
  */
typedef struct
{
  uint16_t Page;   /*!< NAND memory Page address  */

  uint16_t Plane;   /*!< NAND memory Zone address  */

  uint16_t Block;  /*!< NAND memory Block address */

} NAND_AddressTypeDef;

/**
  * @brief  NAND Memory info Structure definition
  */
typedef struct
{
  uint32_t        PageSize;              /*!< NAND memory page (without spare area) size measured in bytes
                                              for 8 bits addressing or words for 16 bits addressing             */

  uint32_t        SpareAreaSize;         /*!< NAND memory spare area size measured in bytes
                                              for 8 bits addressing or words for 16 bits addressing             */

  uint32_t        BlockSize;             /*!< NAND memory block size measured in number of pages               */

  uint32_t        BlockNbr;              /*!< NAND memory number of total blocks                               */

  uint32_t        PlaneNbr;              /*!< NAND memory number of planes                                     */

  uint32_t        PlaneSize;             /*!< NAND memory zone size measured in number of blocks               */

  FunctionalState ExtraCommandEnable;    /*!< NAND extra command needed for Page reading mode. This
                                              parameter is mandatory for some NAND parts after the read
                                              command (NAND_CMD_AREA_TRUE1) and before DATA reading sequence.
                                              This parameter could be ENABLE or DISABLE
                                              Please check the Read Mode sequence in the NAND device datasheet */
} NAND_DeviceConfigTypeDef;

/**
  * @brief  NAND ECC configuration
  */
typedef struct
{
  uint8_t         Offset;         /*!< Offset of the ECC from the beginning of the spare area  measured in
                                       bytes for 8 bits addressing or words for 16 bits addressing */
} NAND_EccConfigTypeDef;

/**
  * @brief  NAND ECC statistics
  */
typedef struct
{
  uint16_t        CorrectibleErrorTotal;    /*!< Total number of correctible errors found during the last page read */
  uint8_t         CorrectibleErrorMax;      /*!< Maximum number of correctible errors found in a single sector during the last page read */
  uint8_t         CorrectibleSectorCount;   /*!< Number of sector with at least one correctible error found during the last page read */
  uint8_t         BadSectorCount;           /*!< Number of sector with too many errors found during the last page read */
} NAND_EccStatisticsTypeDef;

/**
  * @brief  NAND ECC state
  */
typedef struct
{
  uint16_t        SectorSize;               /*!< Sector size for ECC measured in
                                                 bytes for 8 bits addressing or words for 16 bits addressing */
  uint8_t         SectorCount;              /*!< Number of sectors in a page */

  uint8_t         EccLength;                /*!< Length of ECC in bits for a sector */
  uint8_t         EccSize;                  /*!< Size of ECC in bytes for a sector */
} NAND_EccStateTypeDef;

#ifdef HAL_MDMA_MODULE_ENABLED

/**
  * @brief  NAND sequencer configuration
  */
typedef struct
{
  MDMA_HandleTypeDef *HdmaRead;
  MDMA_HandleTypeDef *HdmaWrite;
  MDMA_HandleTypeDef *HdmaReadEcc;
  uint32_t          *EccBuffer;
} NAND_SequencerConfigTypeDef;

/**
  * @brief  NAND sequencer state
  */
typedef struct
{
  uint16_t EccBufferSize;
  bool TransferPending;
  bool WriteFlag;
  bool RawFlag;
  void *Data;
} NAND_SequencerStateTypeDef;

#endif /* HAL_MDMA_MODULE_ENABLED  */

/**
  * @brief  NAND handle Structure definition
  */
#if (USE_HAL_NAND_REGISTER_CALLBACKS == 1)
typedef struct __NAND_HandleTypeDef
#else
typedef struct
#endif /* USE_HAL_NAND_REGISTER_CALLBACKS  */
{
  FMC_NAND_TypeDef         *Instance;  /*!< Register base address                                 */

  FMC_NAND_InitTypeDef     Init;       /*!< NAND device control configuration parameters          */

  HAL_LockTypeDef            Lock;              /*!< NAND locking object                                   */

  __IO HAL_NAND_StateTypeDef State;             /*!< NAND device access state                              */

  __IO HAL_NAND_ErrorTypeDef ErrorCode;         /*!< NAND device last error                                */

  NAND_DeviceConfigTypeDef   Config;            /*!< NAND physical characteristic information structure    */

  NAND_EccConfigTypeDef      EccConfig;         /*!< NAND ECC configuration                                */

  NAND_EccStateTypeDef       EccState;          /*!< NAND ECC state                                        */

  NAND_EccStatisticsTypeDef  EccStatistics;     /*!< NAND ECC statistics                                   */

#ifdef HAL_MDMA_MODULE_ENABLED
  NAND_SequencerConfigTypeDef SequencerConfig;  /*!< NAND sequencer configuration                          */

  NAND_SequencerStateTypeDef SequencerState;    /*!< NAND sequencer state                                  */
#endif /* HAL_MDMA_MODULE_ENABLED  */

  uint32_t                   TimeOut;           /*!< Default time out value                                */

  uint32_t                   ChipSelect;        /*!< NAND chip select                                      */

  uint32_t                   DeviceAddress;     /*!< Device address for the current bank and chip select   */

#if (USE_HAL_NAND_REGISTER_CALLBACKS == 1)
  void (* MspInitCallback)(struct __NAND_HandleTypeDef *hnand);           /*!< NAND Msp Init callback              */
  void (* MspDeInitCallback)(struct __NAND_HandleTypeDef *hnand);         /*!< NAND Msp DeInit callback            */
  void (* ItCallback)(struct __NAND_HandleTypeDef *hnand);                /*!< NAND IT callback                    */
#endif /* USE_HAL_NAND_REGISTER_CALLBACKS */
} NAND_HandleTypeDef;

#if (USE_HAL_NAND_REGISTER_CALLBACKS == 1)
/**
  * @brief  HAL NAND Callback ID enumeration definition
  */
typedef enum
{
  HAL_NAND_MSP_INIT_CB_ID       = 0x00U,  /*!< NAND MspInit Callback ID          */
  HAL_NAND_MSP_DEINIT_CB_ID     = 0x01U,  /*!< NAND MspDeInit Callback ID        */
  HAL_NAND_IT_CB_ID             = 0x02U   /*!< NAND IT Callback ID               */
} HAL_NAND_CallbackIDTypeDef;

/**
  * @brief  HAL NAND Callback pointer definition
  */
typedef void (*pNAND_CallbackTypeDef)(NAND_HandleTypeDef *hnand);
#endif /* USE_HAL_NAND_REGISTER_CALLBACKS */

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/** @defgroup NAND_Exported_Macros NAND Exported Macros
  *  @{
  */

/** @brief Reset NAND handle state
  * @param  __HANDLE__ specifies the NAND handle.
  * @retval None
  */
#if (USE_HAL_NAND_REGISTER_CALLBACKS == 1)
#define __HAL_NAND_RESET_HANDLE_STATE(__HANDLE__)         do {                                             \
                                                               (__HANDLE__)->State = HAL_NAND_STATE_RESET; \
                                                               (__HANDLE__)->MspInitCallback = NULL;       \
                                                               (__HANDLE__)->MspDeInitCallback = NULL;     \
                                                             } while(0)
#else
#define __HAL_NAND_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_NAND_STATE_RESET)
#endif /* USE_HAL_NAND_REGISTER_CALLBACKS */

#define HAL_NAND_DEFAULT_TIMEOUT 100
#define HAL_NAND_DEFAULT_SEQUENCER_TIMEOUT 5000

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup NAND_Exported_Functions NAND Exported Functions
  * @{
  */

/** @addtogroup NAND_Exported_Functions_Group1 Initialization and de-initialization functions
  * @{
  */

/* Initialization/de-initialization functions  ********************************/
HAL_StatusTypeDef  HAL_NAND_Init(NAND_HandleTypeDef *hnand, FMC_NAND_PCC_TimingTypeDef *ComSpace_Timing,
                                 FMC_NAND_PCC_TimingTypeDef *AttSpace_Timing);
HAL_StatusTypeDef  HAL_NAND_DeInit(NAND_HandleTypeDef *hnand);

HAL_StatusTypeDef  HAL_NAND_ConfigDevice(NAND_HandleTypeDef *hnand, NAND_DeviceConfigTypeDef *pDeviceConfig);

HAL_StatusTypeDef  HAL_NAND_Read_ID(NAND_HandleTypeDef *hnand, NAND_IDTypeDef *pNAND_ID);

void               HAL_NAND_MspInit(NAND_HandleTypeDef *hnand);
void               HAL_NAND_MspDeInit(NAND_HandleTypeDef *hnand);
void               HAL_NAND_IRQHandler(NAND_HandleTypeDef *hnand);
void               HAL_NAND_ITCallback(NAND_HandleTypeDef *hnand);

/**
  * @}
  */

/** @addtogroup NAND_Exported_Functions_Group2 Input and Output functions
  * @{
  */

/* IO operation functions  ****************************************************/
HAL_StatusTypeDef  HAL_NAND_Reset(NAND_HandleTypeDef *hnand);

HAL_StatusTypeDef  HAL_NAND_Read_Page_8b(NAND_HandleTypeDef *hnand, NAND_AddressTypeDef *pAddress, uint8_t *pBuffer,
                                         uint32_t NumPagesToRead);
HAL_StatusTypeDef  HAL_NAND_Write_Page_8b(NAND_HandleTypeDef *hnand, NAND_AddressTypeDef *pAddress, uint8_t *pBuffer,
                                          uint32_t NumPagesToWrite);
HAL_StatusTypeDef  HAL_NAND_Read_SinglePage_8b(NAND_HandleTypeDef *hnand, NAND_AddressTypeDef *pAddress,
                                               uint8_t *pBuffer, uint32_t Offset, uint32_t Length);
HAL_StatusTypeDef  HAL_NAND_Write_SinglePage_8b(NAND_HandleTypeDef *hnand, NAND_AddressTypeDef *pAddress,
                                                uint8_t *pBuffer, uint32_t Offset, uint32_t Length);
HAL_StatusTypeDef  HAL_NAND_Read_SpareArea_8b(NAND_HandleTypeDef *hnand, NAND_AddressTypeDef *pAddress,
                                              uint8_t *pBuffer, uint32_t NumSpareAreasToRead);
HAL_StatusTypeDef  HAL_NAND_Write_SpareArea_8b(NAND_HandleTypeDef *hnand, NAND_AddressTypeDef *pAddress,
                                               uint8_t *pBuffer, uint32_t NumSpareAreasTowrite);
HAL_StatusTypeDef  HAL_NAND_Read_SingleSpareArea_8b(NAND_HandleTypeDef *hnand, NAND_AddressTypeDef *pAddress,
                                                    uint8_t *pBuffer, uint32_t Offset, uint32_t Length);
HAL_StatusTypeDef  HAL_NAND_Write_SingleSpareArea_8b(NAND_HandleTypeDef *hnand, NAND_AddressTypeDef *pAddress,
                                                     uint8_t *pBuffer, uint32_t Offset, uint32_t Length);

HAL_StatusTypeDef  HAL_NAND_Read_Page_16b(NAND_HandleTypeDef *hnand, NAND_AddressTypeDef *pAddress, uint16_t *pBuffer,
                                          uint32_t NumPagesToRead);
HAL_StatusTypeDef  HAL_NAND_Write_Page_16b(NAND_HandleTypeDef *hnand, NAND_AddressTypeDef *pAddress, uint16_t *pBuffer,
                                           uint32_t NumPagesToWrite);
HAL_StatusTypeDef  HAL_NAND_Read_SinglePage_16b(NAND_HandleTypeDef *hnand, NAND_AddressTypeDef *pAddress,
                                                uint16_t *pBuffer, uint32_t Offset, uint32_t Length);
HAL_StatusTypeDef  HAL_NAND_Write_SinglePage_16b(NAND_HandleTypeDef *hnand, NAND_AddressTypeDef *pAddress,
                                                 uint16_t *pBuffer, uint32_t Offset, uint32_t Length);
HAL_StatusTypeDef  HAL_NAND_Read_SpareArea_16b(NAND_HandleTypeDef *hnand, NAND_AddressTypeDef *pAddress,
                                               uint16_t *pBuffer, uint32_t NumSpareAreasToRead);
HAL_StatusTypeDef  HAL_NAND_Write_SpareArea_16b(NAND_HandleTypeDef *hnand, NAND_AddressTypeDef *pAddress,
                                                uint16_t *pBuffer, uint32_t NumSpareAreasTowrite);
HAL_StatusTypeDef  HAL_NAND_Read_SingleSpareArea_16b(NAND_HandleTypeDef *hnand, NAND_AddressTypeDef *pAddress,
                                                     uint16_t *pBuffer, uint32_t Offset, uint32_t Length);
HAL_StatusTypeDef  HAL_NAND_Write_SingleSpareArea_16b(NAND_HandleTypeDef *hnand, NAND_AddressTypeDef *pAddress,
                                                      uint16_t *pBuffer, uint32_t Offset, uint32_t Length);

HAL_StatusTypeDef  HAL_NAND_Erase_Block(NAND_HandleTypeDef *hnand, NAND_AddressTypeDef *pAddress);

uint32_t           HAL_NAND_Address_Inc(NAND_HandleTypeDef *hnand, NAND_AddressTypeDef *pAddress);

#if (USE_HAL_NAND_REGISTER_CALLBACKS == 1)
/* NAND callback registering/unregistering */
HAL_StatusTypeDef  HAL_NAND_RegisterCallback(NAND_HandleTypeDef *hnand, HAL_NAND_CallbackIDTypeDef CallbackId,
                                             pNAND_CallbackTypeDef pCallback);
HAL_StatusTypeDef  HAL_NAND_UnRegisterCallback(NAND_HandleTypeDef *hnand, HAL_NAND_CallbackIDTypeDef CallbackId);
#endif /* USE_HAL_NAND_REGISTER_CALLBACKS */

/**
  * @}
  */

/** @addtogroup NAND_Exported_Functions_Group3 Peripheral Control functions
  * @{
  */

/* NAND Control functions  ****************************************************/
HAL_StatusTypeDef  HAL_NAND_ECC_Enable(NAND_HandleTypeDef *hnand);
HAL_StatusTypeDef  HAL_NAND_ECC_Disable(NAND_HandleTypeDef *hnand);
HAL_StatusTypeDef  HAL_NAND_GetECC(NAND_HandleTypeDef *hnand, uint32_t *ECCval, uint32_t Timeout);
HAL_StatusTypeDef  HAL_NAND_ECC_SetAlgorithm(NAND_HandleTypeDef *hnand, uint32_t Algorithm);
HAL_StatusTypeDef  HAL_NAND_ECC_SetBCHMode(NAND_HandleTypeDef *hnand, uint32_t Mode);
HAL_StatusTypeDef  HAL_NAND_ECC_SetAccessMode(NAND_HandleTypeDef *Device, uint32_t Mode);
HAL_StatusTypeDef  HAL_NAND_ECC_GetBCH(NAND_HandleTypeDef *hnand, uint32_t *ECCval, uint32_t Timeout);
HAL_StatusTypeDef  HAL_NAND_ECC_GetErrorsBCH(NAND_HandleTypeDef *hnand, uint16_t *Positions, int32_t *ErrorCount,
                                             uint32_t Timeout);

/**
  * @}
  */

/** @addtogroup NAND_Exported_Functions_Group4 Peripheral State functions
  * @{
  */
/* NAND State functions *******************************************************/
HAL_NAND_StateTypeDef HAL_NAND_GetState(NAND_HandleTypeDef *hnand);
HAL_StatusTypeDef     HAL_NAND_Read_Status(NAND_HandleTypeDef *hnand, uint32_t *NandStatus);
/**
  * @}
  */

/** @addtogroup NAND_Exported_Functions_Group5 Input and Output functions with error correction
  * @{
  */

HAL_StatusTypeDef  HAL_NAND_ECC_Init(NAND_HandleTypeDef *hnand, const NAND_EccConfigTypeDef *Config);
HAL_StatusTypeDef  HAL_NAND_ECC_DeInit(NAND_HandleTypeDef *hnand);

HAL_StatusTypeDef  HAL_NAND_ECC_Read_Page_8b(NAND_HandleTypeDef *hnand, NAND_AddressTypeDef *pAddress,
                                             uint8_t *pBuffer, uint32_t NumPagesToRead, uint32_t *NumPagesRead);
HAL_StatusTypeDef  HAL_NAND_ECC_Write_Page_8b(NAND_HandleTypeDef *hnand, NAND_AddressTypeDef *pAddress,
                                              uint8_t *pBuffer, uint32_t NumPagesToWrite, uint32_t *NumPagesWritten);

HAL_StatusTypeDef  HAL_NAND_ECC_Read_Page_16b(NAND_HandleTypeDef *hnand, NAND_AddressTypeDef *pAddress,
                                              uint16_t *pBuffer, uint32_t NumPagesToRead, uint32_t *NumPagesRead);
HAL_StatusTypeDef  HAL_NAND_ECC_Write_Page_16b(NAND_HandleTypeDef *hnand, NAND_AddressTypeDef *pAddress,
                                               uint16_t *pBuffer, uint32_t NumPagesToWrite, uint32_t *NumPagesWritten);

void               HAL_NAND_ECC_GetStatistics(NAND_HandleTypeDef *hnand, NAND_EccStatisticsTypeDef *Stat);

/**
  * @}
  */

/** @addtogroup NAND_Exported_Functions_Group6 Functions with error correction
  * @{
  */

#ifdef HAL_MDMA_MODULE_ENABLED

uint32_t           HAL_NAND_Sequencer_GetEccWordsPerSector(NAND_HandleTypeDef *hnand);
uint32_t           HAL_NAND_Sequencer_ComputeEccBufferSize(NAND_HandleTypeDef *hnand);

HAL_StatusTypeDef  HAL_NAND_Sequencer_Init(NAND_HandleTypeDef *hnand, const NAND_SequencerConfigTypeDef *Config);
HAL_StatusTypeDef  HAL_NAND_Sequencer_DeInit(NAND_HandleTypeDef *hnand);

HAL_StatusTypeDef  HAL_NAND_Sequencer_MspInit(NAND_HandleTypeDef *hnand);
void               HAL_NAND_Sequencer_MspDeInit(NAND_HandleTypeDef *hnand);

HAL_StatusTypeDef  HAL_NAND_Sequencer_Read_Page_8b(NAND_HandleTypeDef *hnand, NAND_AddressTypeDef *pAddress,
                                                   uint8_t *pBuffer);
HAL_StatusTypeDef  HAL_NAND_Sequencer_Write_Page_8b(NAND_HandleTypeDef *hnand, NAND_AddressTypeDef *pAddress,
                                                    uint8_t *pBuffer);

HAL_StatusTypeDef  HAL_NAND_Sequencer_Read_Page_16b(NAND_HandleTypeDef *hnand, NAND_AddressTypeDef *pAddress,
                                                    uint16_t *pBuffer);
HAL_StatusTypeDef  HAL_NAND_Sequencer_Write_Page_16b(NAND_HandleTypeDef *hnand, NAND_AddressTypeDef *pAddress,
                                                     uint16_t *pBuffer);

HAL_StatusTypeDef  HAL_NAND_Sequencer_ECC_Read_Page_8b(NAND_HandleTypeDef *hnand, NAND_AddressTypeDef *pAddress,
                                                       uint8_t *pBuffer);
HAL_StatusTypeDef  HAL_NAND_Sequencer_ECC_Write_Page_8b(NAND_HandleTypeDef *hnand, NAND_AddressTypeDef *pAddress,
                                                        uint8_t *pBuffer);

HAL_StatusTypeDef  HAL_NAND_Sequencer_ECC_Read_Page_16b(NAND_HandleTypeDef *hnand, NAND_AddressTypeDef *pAddress,
                                                        uint16_t *pBuffer);
HAL_StatusTypeDef  HAL_NAND_Sequencer_ECC_Write_Page_16b(NAND_HandleTypeDef *hnand, NAND_AddressTypeDef *pAddress,
                                                         uint16_t *pBuffer);

HAL_StatusTypeDef HAL_NAND_Sequencer_Abort(NAND_HandleTypeDef *hnand);

HAL_StatusTypeDef HAL_NAND_Sequencer_WaitCompletion(NAND_HandleTypeDef *hnand, uint32_t TimeOut);

#endif /* HAL_MDMA_MODULE_ENABLED  */

/**
  * @}
  */


/**
  * @}
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/** @defgroup NAND_Private_Constants NAND Private Constants
  * @{
  */
#define NAND_DEVICE                0x80000000UL

#define NAND_RESET_TIMEOUT         0x20UL
#define NAND_READ_BEGIN_TIMEOUT    0x20UL
#define NAND_WRITE_END_TIMEOUT     0x20UL
#define NAND_ERASE_BLOCK_TIMEOUT   0x20UL


#define NAND_DATA_OFFSET          (0UL<<16U)
#define NAND_CMD_OFFSET           (1UL<<16U)  /* A16 = CLE high */
#define NAND_ADDR_OFFSET          (2UL<<16U)  /* A17 = ALE high */

#define NAND_MEM_OFFSET           (0UL<<27U)
#define NAND_ATT_OFFSET           (1UL<<27U)

#define NAND_NCE1_OFFSET          (0x0UL<<24U)
#define NAND_NCE2_OFFSET          (0x1UL<<24U)


#define NAND_CMD_AREA_A            0x00U
#define NAND_CMD_AREA_B            0x01U
#define NAND_CMD_AREA_C            0x50U
#define NAND_CMD_AREA_TRUE1        0x30U
#define NAND_CMD_RANDOM_OUTPUT_0   0x05U
#define NAND_CMD_RANDOM_OUTPUT_1   0xE0U

#define NAND_CMD_WRITE0            0x80U
#define NAND_CMD_WRITE_TRUE1       0x10U
#define NAND_CMD_RANDOM_INPUT      0x85U

#define NAND_CMD_ERASE0            0x60U
#define NAND_CMD_ERASE1            0xD0U
#define NAND_CMD_READID            0x90U
#define NAND_CMD_STATUS            0x70U
#define NAND_CMD_LOCK_STATUS       0x7AU
#define NAND_CMD_RESET             0xFFU

/* NAND memory status */
#define NAND_VALID_ADDRESS         0x00000100UL
#define NAND_INVALID_ADDRESS       0x00000200UL
#define NAND_TIMEOUT_ERROR         0x00000400UL
#define NAND_BUSY                  0x00000000UL
#define NAND_ERROR                 0x00000001UL
#define NAND_READY                 0x00000040UL
/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/** @defgroup NAND_Private_Macros NAND Private Macros
  * @{
  */

/**
  * @brief  NAND memory address computation.
  * @param  __ADDRESS__ NAND memory address.
  * @param  __HANDLE__  NAND handle.
  * @retval NAND Raw address value
  */
#define ARRAY_ADDRESS(__ADDRESS__ , __HANDLE__) ((__ADDRESS__)->Page + \
                                                 (((__ADDRESS__)->Block + \
                                                   (((__ADDRESS__)->Plane) * \
                                                    ((__HANDLE__)->Config.PlaneSize)))* \
                                                  ((__HANDLE__)->Config.BlockSize)))

/**
  * @brief  NAND memory spare area column address computation.
  * @param  __HANDLE__ NAND handle.
  * @retval NAND Raw address value
  */
#define SPARE_AREA_COLUMN_ADDRESS( __HANDLE__) ((__HANDLE__)->Config.PageSize)

/**
  * @brief  NAND memory address cycling.
  * @param  __ADDRESS__ NAND memory address.
  * @retval NAND address cycling value.
  */
#define ADDR_1ST_CYCLE(__ADDRESS__)       (uint8_t)(__ADDRESS__)              /* 1st addressing cycle */
#define ADDR_2ND_CYCLE(__ADDRESS__)       (uint8_t)((__ADDRESS__) >> 8)       /* 2nd addressing cycle */
#define ADDR_3RD_CYCLE(__ADDRESS__)       (uint8_t)((__ADDRESS__) >> 16)      /* 3rd addressing cycle */
#define ADDR_4TH_CYCLE(__ADDRESS__)       (uint8_t)((__ADDRESS__) >> 24)      /* 4th addressing cycle */

/**
  * @brief  NAND memory Columns cycling.
  * @param  __ADDRESS__ NAND memory address.
  * @retval NAND Column address cycling value.
  */
#define COLUMN_1ST_CYCLE(__ADDRESS__)       (uint8_t)((__ADDRESS__) & 0xFFU)    /* 1st Column addressing cycle */
#define COLUMN_2ND_CYCLE(__ADDRESS__)       (uint8_t)((__ADDRESS__) >> 8)       /* 2nd Column addressing cycle */

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

#endif /* STM32MP13xx_HAL_NAND_H */

