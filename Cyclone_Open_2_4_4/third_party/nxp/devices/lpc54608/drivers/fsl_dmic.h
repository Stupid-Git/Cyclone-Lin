/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FSL_DMIC_H_
#define _FSL_DMIC_H_

#include "fsl_common.h"

/*!
 * @addtogroup dmic_driver
 * @{
 */

/*! @file*/

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @name DMIC version
 * @{
 */

/*! @brief DMIC driver version 2.2.1. */
#define FSL_DMIC_DRIVER_VERSION (MAKE_VERSION(2, 2, 1))
/*@}*/

/*! @brief _dmic_status DMIC transfer status.*/
enum
{
    kStatus_DMIC_Busy          = MAKE_STATUS(kStatusGroup_DMIC, 0), /*!< DMIC is busy */
    kStatus_DMIC_Idle          = MAKE_STATUS(kStatusGroup_DMIC, 1), /*!< DMIC is idle */
    kStatus_DMIC_OverRunError  = MAKE_STATUS(kStatusGroup_DMIC, 2), /*!< DMIC  over run Error */
    kStatus_DMIC_UnderRunError = MAKE_STATUS(kStatusGroup_DMIC, 3), /*!< DMIC under run Error */
};

/*! @brief DMIC different operation modes. */
typedef enum _operation_mode
{
    kDMIC_OperationModeInterrupt = 1U, /*!< Interrupt mode */
    kDMIC_OperationModeDma       = 2U, /*!< DMA mode */
} operation_mode_t;

/*! @brief DMIC left/right values. */
typedef enum _stereo_side
{
    kDMIC_Left  = 0U, /*!< Left Stereo channel */
    kDMIC_Right = 1U, /*!< Right Stereo channel */
} stereo_side_t;

/*! @brief DMIC Clock pre-divider values. */
typedef enum
{
    kDMIC_PdmDiv1   = 0U,  /*!< DMIC pre-divider set in divide by 1 */
    kDMIC_PdmDiv2   = 1U,  /*!< DMIC pre-divider set in divide by 2 */
    kDMIC_PdmDiv3   = 2U,  /*!< DMIC pre-divider set in divide by 3 */
    kDMIC_PdmDiv4   = 3U,  /*!< DMIC pre-divider set in divide by 4 */
    kDMIC_PdmDiv6   = 4U,  /*!< DMIC pre-divider set in divide by 6 */
    kDMIC_PdmDiv8   = 5U,  /*!< DMIC pre-divider set in divide by 8 */
    kDMIC_PdmDiv12  = 6U,  /*!< DMIC pre-divider set in divide by 12 */
    kDMIC_PdmDiv16  = 7U,  /*!< DMIC pre-divider set in divide by 16*/
    kDMIC_PdmDiv24  = 8U,  /*!< DMIC pre-divider set in divide by 24*/
    kDMIC_PdmDiv32  = 9U,  /*!< DMIC pre-divider set in divide by 32 */
    kDMIC_PdmDiv48  = 10U, /*!< DMIC pre-divider set in divide by 48 */
    kDMIC_PdmDiv64  = 11U, /*!< DMIC pre-divider set in divide by 64*/
    kDMIC_PdmDiv96  = 12U, /*!< DMIC pre-divider set in divide by 96*/
    kDMIC_PdmDiv128 = 13U, /*!< DMIC pre-divider set in divide by 128 */
} pdm_div_t;

/*! @brief Pre-emphasis Filter coefficient value for 2FS and 4FS modes. */
typedef enum _compensation
{
    kDMIC_CompValueZero            = 0U, /*!< Compensation 0 */
    kDMIC_CompValueNegativePoint16 = 1U, /*!< Compensation -0.16 */
    kDMIC_CompValueNegativePoint15 = 2U, /*!< Compensation -0.15 */
    kDMIC_CompValueNegativePoint13 = 3U, /*!< Compensation -0.13 */
} compensation_t;

/*! @brief DMIC DC filter control values. */
typedef enum _dc_removal
{
    kDMIC_DcNoRemove = 0U, /*!< Flat response no filter */
    kDMIC_DcCut155   = 1U, /*!< Cut off Frequency is 155 Hz  */
    kDMIC_DcCut78    = 2U, /*!< Cut off Frequency is 78 Hz  */
    kDMIC_DcCut39    = 3U, /*!< Cut off Frequency is 39 Hz  */
} dc_removal_t;

#if !(defined(FSL_FEATURE_DMIC_HAS_NO_IOCFG) && FSL_FEATURE_DMIC_HAS_NO_IOCFG)
/*! @brief DMIC IO configiration. */
typedef enum _dmic_io
{
    kDMIC_PdmDual   = 0, /*!< Two separate pairs of PDM wires */
    kDMIC_PdmStereo = 4, /*!< Stereo data0 */

#if !(defined(FSL_FEATURE_DMIC_IO_HAS_NO_BYPASS) && (FSL_FEATURE_DMIC_IO_HAS_NO_BYPASS))
    kDMIC_PdmBypass     = 3, /*!< Clk Bypass clocks both channels */
    kDMIC_PdmBypassClk0 = 1, /*!< Clk Bypass clocks only channel0 */
    kDMIC_PdmBypassClk1 = 2, /*!< Clk Bypas clocks only channel1 */
#endif

#if defined(FSL_FEATURE_DMIC_IO_HAS_STEREO_2_4_6) && (FSL_FEATURE_DMIC_IO_HAS_STEREO_2_4_6)
    kDMIC_PdmStereo2 = 8,  /*!< Stereo data2 */
    kDMIC_PdmStereo4 = 16, /*!< Stereo data4 */
    kDMIC_PdmStereo6 = 32, /*!< Stereo data6 */
#endif
} dmic_io_t;
#endif

/*! @brief DMIC Channel number. */
typedef enum _dmic_channel
{
    kDMIC_Channel0 = 0U, /*!< DMIC channel 0 */
    kDMIC_Channel1 = 1U, /*!< DMIC channel 1 */
#if defined(FSL_FEATURE_DMIC_CHANNEL_NUM) && (FSL_FEATURE_DMIC_CHANNEL_NUM == 8U)
    kDMIC_Channel2 = 2U, /*!< DMIC channel 2 */
    kDMIC_Channel3 = 3U, /*!< DMIC channel 3 */
    kDMIC_Channel4 = 4U, /*!< DMIC channel 4 */
    kDMIC_Channel5 = 5U, /*!< DMIC channel 5 */
    kDMIC_Channel6 = 6U, /*!< DMIC channel 6 */
    kDMIC_Channel7 = 7U, /*!< DMIC channel 7 */
#endif
} dmic_channel_t;

/*! @brief _dmic_channel_mask DMIC Channel mask. */
enum
{
    kDMIC_EnableChannel0 = 1 << 0U, /*!< DMIC channel 0 mask */
    kDMIC_EnableChannel1 = 1 << 1U, /*!< DMIC channel 1 mask */
#if defined(FSL_FEATURE_DMIC_CHANNEL_NUM) && (FSL_FEATURE_DMIC_CHANNEL_NUM == 8U)
    kDMIC_EnableChannel2 = 1 << 2U, /*!< DMIC channel 2 mask */
    kDMIC_EnableChannel3 = 1 << 3U, /*!< DMIC channel 3 mask */
    kDMIC_EnableChannel4 = 1 << 4U, /*!< DMIC channel 4 mask */
    kDMIC_EnableChannel5 = 1 << 5U, /*!< DMIC channel 5 mask */
    kDMIC_EnableChannel6 = 1 << 6U, /*!< DMIC channel 6 mask */
    kDMIC_EnableChannel7 = 1 << 7U, /*!< DMIC channel 7 mask */
#endif
};

/*! @brief DMIC and decimator sample rates. */
typedef enum _dmic_phy_sample_rate
{
    kDMIC_PhyFullSpeed = 0U, /*!< Decimator gets one sample per each chosen clock edge of PDM interface */
    kDMIC_PhyHalfSpeed = 1U, /*!< PDM clock to Microphone is halved, decimator receives each sample twice */
} dmic_phy_sample_rate_t;

/*! @brief DMIC Channel configuration structure. */
typedef struct _dmic_channel_config
{
    pdm_div_t divhfclk;                 /*!< DMIC Clock pre-divider values */
    uint32_t osr;                       /*!< oversampling rate(CIC decimation rate) for PCM */
    int32_t gainshft;                   /*!< 4FS PCM data gain control */
    compensation_t preac2coef;          /*!< Pre-emphasis Filter coefficient value for 2FS */
    compensation_t preac4coef;          /*!< Pre-emphasis Filter coefficient value for 4FS */
    dc_removal_t dc_cut_level;          /*!< DMIC DC filter control values. */
    uint32_t post_dc_gain_reduce;       /*!< Fine gain adjustment in the form of a number of bits to downshift */
    dmic_phy_sample_rate_t sample_rate; /*!< DMIC and decimator sample rates */
    bool saturate16bit; /*!< Selects 16-bit saturation. 0 means results roll over if out range and do not saturate.
                1 means if the result overflows, it saturates at 0xFFFF for positive overflow and
                0x8000 for negative overflow.*/
#if defined(FSL_FEATURE_DMIC_CHANNEL_HAS_SIGNEXTEND) && (FSL_FEATURE_DMIC_CHANNEL_HAS_SIGNEXTEND)
    bool enableSignExtend; /*!< sign extend feature which allows processing of 24bit audio data on 32bit machine */
#endif
} dmic_channel_config_t;

/*! @brief DMIC Callback function. */
typedef void (*dmic_callback_t)(void);

/*! @brief HWVAD Callback function. */
typedef void (*dmic_hwvad_callback_t)(void);

/*******************************************************************************
 * API
 ******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/*!
 * @name Initialization and deinitialization
 * @{
 */

/*!
 * @brief Get the DMIC instance from peripheral base address.
 *
 * @param base DMIC peripheral base address.
 * @return DMIC instance.
 */
uint32_t DMIC_GetInstance(DMIC_Type *base);

/*!
 * @brief	Turns DMIC Clock on
 * @param	base	: DMIC base
 * @return	Nothing
 */
void DMIC_Init(DMIC_Type *base);

/*!
 * @brief	Turns DMIC Clock off
 * @param	base	: DMIC base
 * @return	Nothing
 */
void DMIC_DeInit(DMIC_Type *base);

#if !(defined(FSL_FEATURE_DMIC_HAS_NO_IOCFG) && FSL_FEATURE_DMIC_HAS_NO_IOCFG)
/*!
 * @brief	Configure DMIC io
 * @deprecated Do not use this function.  It has been superceded by @ref DMIC_SetIOCFG
 * @param	base	: The base address of DMIC interface
 * @param	config		: DMIC io configuration
 * @return	Nothing
 */
void DMIC_ConfigIO(DMIC_Type *base, dmic_io_t config);

/*!
 * @brief   Stereo PDM select.
 * @param   base    : The base address of DMIC interface
 * @param   sel    : Reference dmic_io_t, can be a single or combination value of dmic_io_t.
 * @return  Nothing
 */
static inline void DMIC_SetIOCFG(DMIC_Type *base, uint32_t sel)
{
    base->IOCFG = sel;
}
#endif

/*!
 * @brief	Set DMIC operating mode
 * @deprecated Do not use this function.  It has been superceded by @ref
 * DMIC_EnbleChannelInterrupt/DMIC_EnbleChannelDma.
 * @param	base	: The base address of DMIC interface
 * @param	mode	: DMIC mode
 * @return	Nothing
 */
void DMIC_SetOperationMode(DMIC_Type *base, operation_mode_t mode);

/*!
 * @brief	Configure Clock scaling
 * @param	base		: The base address of DMIC interface
 * @param	use2fs		: clock scaling
 * @return	Nothing
 */
void DMIC_Use2fs(DMIC_Type *base, bool use2fs);

/*! @} */

/*!
 * @name Channel configuration
 * @{
 */

/*!
 * @brief   Configure DMIC channel
 * @param   base        : The base address of DMIC interface
 * @param   channel     : DMIC channel
 * @param   dc_cut_level  : dc_removal_t, Cut off Frequency
 * @param   post_dc_gain_reduce : Fine gain adjustment in the form of a number of bits to downshift.
 * @param   saturate16bit : If selects 16-bit saturation.
 */
void DMIC_CfgChannelDc(DMIC_Type *base,
                       dmic_channel_t channel,
                       dc_removal_t dc_cut_level,
                       uint32_t post_dc_gain_reduce,
                       bool saturate16bit);

#if defined(FSL_FEATURE_DMIC_CHANNEL_HAS_SIGNEXTEND) && (FSL_FEATURE_DMIC_CHANNEL_HAS_SIGNEXTEND)
/*!
 * @brief   Enbale channel sign extend which allows processing of 24bit audio data on 32bit machines.
 * @param   base        : The base address of DMIC interface
 * @param   channel     : DMIC channel
 * @param   enable  : true is enable sign extend, false is disable sign extend
 */
static inline void DMIC_EnableChannelSignExtend(DMIC_Type *base, dmic_channel_t channel, bool enable)
{
    if (enable)
    {
        base->CHANNEL[channel].DC_CTRL |= DMIC_CHANNEL_DC_CTRL_SIGNEXTEND_MASK;
    }
    else
    {
        base->CHANNEL[channel].DC_CTRL &= ~DMIC_CHANNEL_DC_CTRL_SIGNEXTEND_MASK;
    }
}
#endif

/*!
 * @brief   Configure DMIC channel
 *
 * @param   base        : The base address of DMIC interface
 * @param   channel     : DMIC channel
 * @param side     : stereo_side_t, choice of left or right
 * @param   channel_config  : Channel configuration
 * @return  Nothing
 */
void DMIC_ConfigChannel(DMIC_Type *base,
                        dmic_channel_t channel,
                        stereo_side_t side,
                        dmic_channel_config_t *channel_config);

/*!
 * @brief   Enable a particualr channel
 * @param   base        : The base address of DMIC interface
 * @param   channelmask, reference _dmic_channel_mask
 * @return  Nothing
 */
void DMIC_EnableChannnel(DMIC_Type *base, uint32_t channelmask);

/*!
 * @brief   Configure fifo settings for DMIC channel
 * @param   base        : The base address of DMIC interface
 * @param   channel     : DMIC channel
 * @param   trig_level  : FIFO trigger level
 * @param   enable      : FIFO level
 * @param   resetn      : FIFO reset
 * @return  Nothing
 */
void DMIC_FifoChannel(DMIC_Type *base, uint32_t channel, uint32_t trig_level, uint32_t enable, uint32_t resetn);

/*!
 * @brief   Enable a particualr channel interrupt request.
 * @param   base        : The base address of DMIC interface
 * @param   channel : Channel selection
 */
static inline void DMIC_EnableChannelInterrupt(DMIC_Type *base, dmic_channel_t channel, bool enable)
{
    if (enable)
    {
        base->CHANNEL[channel].FIFO_CTRL |= DMIC_CHANNEL_FIFO_CTRL_INTEN_MASK;
    }
    else
    {
        base->CHANNEL[channel].FIFO_CTRL &= ~DMIC_CHANNEL_FIFO_CTRL_INTEN_MASK;
    }
}

/*!
 * @brief   Enable a particualr channel dma request.
 * @param   base        : The base address of DMIC interface
 * @param   channel : Channel selection
 * @param   enable : true is enable, false is disable
 */
static inline void DMIC_EnableChannelDma(DMIC_Type *base, dmic_channel_t channel, bool enable)
{
    if (enable)
    {
        base->CHANNEL[channel].FIFO_CTRL |= DMIC_CHANNEL_FIFO_CTRL_DMAEN_MASK;
    }
    else
    {
        base->CHANNEL[channel].FIFO_CTRL &= DMIC_CHANNEL_FIFO_CTRL_DMAEN_MASK;
    }
}

/*!
 * @brief   Enable a particualr channel fifo.
 * @param   base        : The base address of DMIC interface
 * @param   channel : Channel selection
 * @param   enable : true is enable, false is disable
 */
static inline void DMIC_EnableChannelFifo(DMIC_Type *base, dmic_channel_t channel, bool enable)
{
    if (enable)
    {
        base->CHANNEL[channel].FIFO_CTRL |= DMIC_CHANNEL_FIFO_CTRL_ENABLE_MASK;
    }
    else
    {
        base->CHANNEL[channel].FIFO_CTRL &= DMIC_CHANNEL_FIFO_CTRL_ENABLE_MASK;
    }
}

/*!
 * @brief   Channel fifo reset.
 * @param   base        : The base address of DMIC interface
 * @param   channel : Channel selection
 */
static inline void DMIC_DoFifoReset(DMIC_Type *base, dmic_channel_t channel)
{
    /* reset FIFO */
    base->CHANNEL[channel].FIFO_CTRL &= ~DMIC_CHANNEL_FIFO_CTRL_RESETN_MASK;
    /* normal operation */
    base->CHANNEL[channel].FIFO_CTRL |= DMIC_CHANNEL_FIFO_CTRL_RESETN_MASK;
}

/*!
 * @brief	Get FIFO status
 * @param	base		: The base address of DMIC interface
 * @param	channel		: DMIC channel
 * @return	FIFO status
 */
static inline uint32_t DMIC_FifoGetStatus(DMIC_Type *base, uint32_t channel)
{
    return base->CHANNEL[channel].FIFO_STATUS;
}

/*!
 * @brief	Clear FIFO status
 * @param	base		: The base address of DMIC interface
 * @param	channel		: DMIC channel
 * @param	mask		: Bits to be cleared
 * @return	FIFO status
 */
static inline void DMIC_FifoClearStatus(DMIC_Type *base, uint32_t channel, uint32_t mask)
{
    base->CHANNEL[channel].FIFO_STATUS = mask;
}

/*!
 * @brief	Get FIFO data
 * @param	base		: The base address of DMIC interface
 * @param	channel		: DMIC channel
 * @return	FIFO data
 */
static inline uint32_t DMIC_FifoGetData(DMIC_Type *base, uint32_t channel)
{
    return base->CHANNEL[channel].FIFO_DATA;
}

/*!
 * @brief	Get FIFO address
 * @param	base		: The base address of DMIC interface
 * @param	channel		: DMIC channel
 * @return	FIFO data
 */
static inline uint32_t DMIC_FifoGetAddress(DMIC_Type *base, uint32_t channel)
{
    return (uint32_t)(&(base->CHANNEL[channel].FIFO_DATA));
}

/*! @} */

/*!
 * @name Register callback.
 * @{
 */

/*!
 * @brief	Enable callback.

 * This function enables the interrupt for the selected DMIC peripheral.
 * The callback function is not enabled until this function is called.
 *
 * @param base Base address of the DMIC peripheral.
 * @param cb callback Pointer to store callback function.
 * @retval None.
 */
void DMIC_EnableIntCallback(DMIC_Type *base, dmic_callback_t cb);

/*!
 * @brief	Disable callback.

 * This function disables the interrupt for the selected DMIC peripheral.
 *
 * @param base Base address of the DMIC peripheral.
 * @param cb callback Pointer to store callback function..
 * @retval None.
 */
void DMIC_DisableIntCallback(DMIC_Type *base, dmic_callback_t cb);
/*! @} */

/*!
 * @name HWVAD
 * @{
 */

/*!
 * @brief Sets the gain value for the noise estimator.
 *
 * @param base DMIC base pointer
 * @param value gain value for the noise estimator.
 * @retval None.
 */
static inline void DMIC_SetGainNoiseEstHwvad(DMIC_Type *base, uint32_t value)
{
    assert(NULL != base);
    base->HWVADTHGN = value & 0xFUL;
}

/*!
 * @brief Sets the gain value for the signal estimator.
 *
 * @param base DMIC base pointer
 * @param value gain value for the signal estimator.
 * @retval None.
 */
static inline void DMIC_SetGainSignalEstHwvad(DMIC_Type *base, uint32_t value)
{
    assert(NULL != base);
    base->HWVADTHGS = value & 0xFUL;
}

/*!
 * @brief Sets the hwvad filter cutoff frequency parameter.
 *
 * @param base DMIC base pointer
 * @param value cut off frequency value.
 * @retval None.
 */
static inline void DMIC_SetFilterCtrlHwvad(DMIC_Type *base, uint32_t value)
{
    assert(NULL != base);
    base->HWVADHPFS = value & 0x3UL;
}

/*!
 * @brief Sets the input gain of hwvad.
 *
 * @param base DMIC base pointer
 * @param value input gain value for hwvad.
 * @retval None.
 */
static inline void DMIC_SetInputGainHwvad(DMIC_Type *base, uint32_t value)
{
    assert(NULL != base);
    base->HWVADGAIN = value & 0xFUL;
}

/*!
 * @brief Clears hwvad internal interrupt flag.
 *
 * @param base DMIC base pointer
 * @param st10 bit value.
 * @retval None.
 */
static inline void DMIC_CtrlClrIntrHwvad(DMIC_Type *base, bool st10)
{
    assert(NULL != base);
    base->HWVADST10 = (st10) ? 0x1UL : 0x0UL;
}

/*!
 * @brief Resets hwvad filters.
 *
 * @param base DMIC base pointer
 * @param rstt Reset bit value.
 * @retval None.
 */
static inline void DMIC_FilterResetHwvad(DMIC_Type *base, bool rstt)
{
    assert(NULL != base);
    base->HWVADRSTT = (rstt) ? 0x1UL : 0x0UL;
}

/*!
 * @brief Gets the value from output of the filter z7.
 *
 * @param base DMIC base pointer
 * @retval output of filter z7.
 */
static inline uint16_t DMIC_GetNoiseEnvlpEst(DMIC_Type *base)
{
    assert(NULL != base);
    return (uint16_t)(base->HWVADLOWZ & 0xFFFFU);
}

/*!
 * @brief	Enable hwvad callback.

 * This function enables the hwvad interrupt for the selected DMIC  peripheral.
 * The callback function is not enabled until this function is called.
 *
 * @param base Base address of the DMIC peripheral.
 * @param vadcb callback Pointer to store callback function.
 * @retval None.
 */
void DMIC_HwvadEnableIntCallback(DMIC_Type *base, dmic_hwvad_callback_t vadcb);

/*!
 * @brief	Disable callback.

 * This function disables the hwvad interrupt for the selected DMIC peripheral.
 *
 * @param base Base address of the DMIC peripheral.
 * @param vadcb callback Pointer to store callback function..
 * @retval None.
 */
void DMIC_HwvadDisableIntCallback(DMIC_Type *base, dmic_hwvad_callback_t vadcb);

/*! @} */

#ifdef __cplusplus
}
#endif

/*! @}*/

#endif /* __FSL_DMIC_H */
