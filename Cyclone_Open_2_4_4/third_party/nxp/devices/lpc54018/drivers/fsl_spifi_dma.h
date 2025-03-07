/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef _FSL_SPIFI_DMA_H_
#define _FSL_SPIFI_DMA_H_

#include "fsl_dma.h"
#include "fsl_spifi.h"

/*!
 * @addtogroup spifi
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*@{*/
/*! @brief SPIFI DMA driver version 2.0.3. */
#define FSL_SPIFI_DMA_DRIVER_VERSION (MAKE_VERSION(2, 0, 3))
/*@}*/

typedef struct _spifi_dma_handle spifi_dma_handle_t;

/*! @brief SPIFI DMA transfer callback function for finish and error */
typedef void (*spifi_dma_callback_t)(SPIFI_Type *base, spifi_dma_handle_t *handle, status_t status, void *userData);

/*! @brief SPIFI DMA transfer handle, users should not touch the content of the handle.*/
struct _spifi_dma_handle
{
    dma_handle_t *dmaHandle;       /*!< DMA handler for SPIFI send */
    size_t transferSize;           /*!< Bytes need to transfer. */
    uint32_t state;                /*!< Internal state for SPIFI DMA transfer */
    spifi_dma_callback_t callback; /*!< Callback for users while transfer finish or error occurred */
    void *userData;                /*!< User callback parameter */
};

/*******************************************************************************
 * APIs
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name DMA Transactional
 * @{
 */

/*!
 * @brief Initializes the SPIFI handle for send which is used in transactional functions and set the callback.
 *
 * @param base SPIFI peripheral base address
 * @param handle Pointer to spifi_dma_handle_t structure
 * @param callback SPIFI callback, NULL means no callback.
 * @param userData User callback function data.
 * @param dmaHandle User requested DMA handle for DMA transfer
 */
void SPIFI_TransferTxCreateHandleDMA(SPIFI_Type *base,
                                     spifi_dma_handle_t *handle,
                                     spifi_dma_callback_t callback,
                                     void *userData,
                                     dma_handle_t *dmaHandle);

/*!
 * @brief Initializes the SPIFI handle for receive which is used in transactional functions and set the callback.
 *
 * @param base SPIFI peripheral base address
 * @param handle Pointer to spifi_dma_handle_t structure
 * @param callback SPIFI callback, NULL means no callback.
 * @param userData User callback function data.
 * @param dmaHandle User requested DMA handle for DMA transfer
 */
void SPIFI_TransferRxCreateHandleDMA(SPIFI_Type *base,
                                     spifi_dma_handle_t *handle,
                                     spifi_dma_callback_t callback,
                                     void *userData,
                                     dma_handle_t *dmaHandle);

/*!
 * @brief Transfers SPIFI data using an DMA non-blocking method.
 *
 * This function writes data to the SPIFI transmit FIFO. This function is non-blocking.
 * @param base Pointer to QuadSPI Type.
 * @param handle Pointer to spifi_dma_handle_t structure
 * @param xfer SPIFI transfer structure.
 */
status_t SPIFI_TransferSendDMA(SPIFI_Type *base, spifi_dma_handle_t *handle, spifi_transfer_t *xfer);

/*!
 * @brief Receives data using an DMA non-blocking method.
 *
 * This function receive data from the SPIFI receive buffer/FIFO. This function is non-blocking.
 * @param base Pointer to QuadSPI Type.
 * @param handle Pointer to spifi_dma_handle_t structure
 * @param xfer SPIFI transfer structure.
 */
status_t SPIFI_TransferReceiveDMA(SPIFI_Type *base, spifi_dma_handle_t *handle, spifi_transfer_t *xfer);

/*!
 * @brief Aborts the sent data using DMA.
 *
 * This function aborts the sent data using DMA.
 *
 * @param base SPIFI peripheral base address.
 * @param handle Pointer to spifi_dma_handle_t structure
 */
void SPIFI_TransferAbortSendDMA(SPIFI_Type *base, spifi_dma_handle_t *handle);

/*!
 * @brief Aborts the receive data using DMA.
 *
 * This function abort receive data which using DMA.
 *
 * @param base SPIFI peripheral base address.
 * @param handle Pointer to spifi_dma_handle_t structure
 */
void SPIFI_TransferAbortReceiveDMA(SPIFI_Type *base, spifi_dma_handle_t *handle);

/*!
 * @brief Gets the transferred counts of send.
 *
 * @param base Pointer to QuadSPI Type.
 * @param handle Pointer to spifi_dma_handle_t structure.
 * @param count Bytes sent.
 * @retval kStatus_Success Succeed get the transfer count.
 * @retval kStatus_NoTransferInProgress There is not a non-blocking transaction currently in progress.
 */
status_t SPIFI_TransferGetSendCountDMA(SPIFI_Type *base, spifi_dma_handle_t *handle, size_t *count);

/*!
 * @brief Gets the status of the receive transfer.
 *
 * @param base Pointer to QuadSPI Type.
 * @param handle Pointer to spifi_dma_handle_t structure
 * @param count Bytes received.
 * @retval kStatus_Success Succeed get the transfer count.
 * @retval kStatus_NoTransferInProgress There is not a non-blocking transaction currently in progress.
 */
status_t SPIFI_TransferGetReceiveCountDMA(SPIFI_Type *base, spifi_dma_handle_t *handle, size_t *count);

/* @} */

#if defined(__cplusplus)
}
#endif

/* @} */

#endif /* _FSL_SPIFI_DMA_H_ */
