/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_I2C_DMA_H_
#define FSL_I2C_DMA_H_

#include "fsl_i2c.h"
#include "fsl_dma.h"

/*!
 * @addtogroup i2c_dma_driver
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief I2C DMA driver version. */
#define FSL_I2C_DMA_DRIVER_VERSION (MAKE_VERSION(2, 3, 1))
/*! @} */

/*! @brief Maximum lenght of single DMA transfer (determined by capability of the DMA engine) */
#define I2C_MAX_DMA_TRANSFER_COUNT 1024

/*! @brief I2C master dma handle typedef. */
typedef struct _i2c_master_dma_handle i2c_master_dma_handle_t;

/*! @brief I2C master dma transfer callback typedef. */
typedef void (*i2c_master_dma_transfer_callback_t)(I2C_Type *base,
                                                   i2c_master_dma_handle_t *handle,
                                                   status_t status,
                                                   void *userData);

/*! @brief Typedef for master dma handler. */
typedef void (*flexcomm_i2c_dma_master_irq_handler_t)(I2C_Type *base, i2c_master_dma_handle_t *handle);

/*! @brief I2C master dma transfer structure. */
struct _i2c_master_dma_handle
{
    uint8_t state;              /*!< Transfer state machine current state. */
    uint32_t transferCount;     /*!< Indicates progress of the transfer */
    uint32_t remainingBytesDMA; /*!< Remaining byte count to be transferred using DMA. */
    uint8_t *buf;               /*!< Buffer pointer for current state. */
    uint32_t remainingSubaddr;
    uint8_t subaddrBuf[4];
    bool checkAddrNack;             /*!< Whether to check the nack signal is detected during addressing. */
    dma_handle_t *dmaHandle;        /*!< The DMA handler used. */
    i2c_master_transfer_t transfer; /*!< Copy of the current transfer info. */
    i2c_master_dma_transfer_callback_t completionCallback; /*!< Callback function called after dma transfer finished. */
    void *userData;                                        /*!< Callback parameter passed to callback function. */
};

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /*_cplusplus. */

/*!
 * @name I2C Block DMA Transfer Operation
 * @{
 */

/*!
 * @brief Init the I2C handle which is used in transactional functions
 *
 * @param base I2C peripheral base address
 * @param handle pointer to i2c_master_dma_handle_t structure
 * @param callback pointer to user callback function
 * @param userData user param passed to the callback function
 * @param dmaHandle DMA handle pointer
 */
void I2C_MasterTransferCreateHandleDMA(I2C_Type *base,
                                       i2c_master_dma_handle_t *handle,
                                       i2c_master_dma_transfer_callback_t callback,
                                       void *userData,
                                       dma_handle_t *dmaHandle);

/*!
 * @brief Performs a master dma non-blocking transfer on the I2C bus
 *
 * @param base I2C peripheral base address
 * @param handle pointer to i2c_master_dma_handle_t structure
 * @param xfer pointer to transfer structure of i2c_master_transfer_t
 * @retval kStatus_Success Sucessully complete the data transmission.
 * @retval kStatus_I2C_Busy Previous transmission still not finished.
 * @retval kStatus_I2C_Timeout Transfer error, wait signal timeout.
 * @retval kStatus_I2C_ArbitrationLost Transfer error, arbitration lost.
 * @retval kStataus_I2C_Nak Transfer error, receive Nak during transfer.
 */
status_t I2C_MasterTransferDMA(I2C_Type *base, i2c_master_dma_handle_t *handle, i2c_master_transfer_t *xfer);

/*!
 * @brief Get master transfer status during a dma non-blocking transfer
 *
 * @param base I2C peripheral base address
 * @param handle pointer to i2c_master_dma_handle_t structure
 * @param count Number of bytes transferred so far by the non-blocking transaction.
 */
status_t I2C_MasterTransferGetCountDMA(I2C_Type *base, i2c_master_dma_handle_t *handle, size_t *count);

/*!
 * @brief Abort a master dma non-blocking transfer in a early time
 *
 * @param base I2C peripheral base address
 * @param handle pointer to i2c_master_dma_handle_t structure
 */
void I2C_MasterTransferAbortDMA(I2C_Type *base, i2c_master_dma_handle_t *handle);

/*! @} */
#if defined(__cplusplus)
}
#endif /*_cplusplus. */
/*! @} */
#endif /*FSL_I2C_DMA_H_*/
