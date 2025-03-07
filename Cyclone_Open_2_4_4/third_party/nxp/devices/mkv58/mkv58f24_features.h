/*
** ###################################################################
**     Version:             rev. 0.3, 2015-06-08
**     Build:               b200409
**
**     Abstract:
**         Chip specific module features.
**
**     Copyright 2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2020 NXP
**     All rights reserved.
**
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2015-02-24)
**         Initial version.
**     - rev. 0.2 (2015-05-25)
**         Added FSL_FEATURE_FLASH_PFLASH_START_ADDRESS
**     - rev. 0.3 (2015-06-08)
**         FTM features BUS_CLOCK and FAST_CLOCK removed.
**
** ###################################################################
*/

#ifndef _MKV58F24_FEATURES_H_
#define _MKV58F24_FEATURES_H_

/* SOC module features */

#if defined(CPU_MKV58F1M0VLL24) || defined(CPU_MKV58F512VLL24)
    /* @brief ADC16 availability on the SoC. */
    #define FSL_FEATURE_SOC_ADC16_COUNT (1)
    /* @brief AIPS availability on the SoC. */
    #define FSL_FEATURE_SOC_AIPS_COUNT (2)
    /* @brief AOI availability on the SoC. */
    #define FSL_FEATURE_SOC_AOI_COUNT (1)
    /* @brief AXBS availability on the SoC. */
    #define FSL_FEATURE_SOC_AXBS_COUNT (1)
    /* @brief FLEXCAN availability on the SoC. */
    #define FSL_FEATURE_SOC_FLEXCAN_COUNT (3)
    /* @brief MMCAU availability on the SoC. */
    #define FSL_FEATURE_SOC_MMCAU_COUNT (1)
    /* @brief CMP availability on the SoC. */
    #define FSL_FEATURE_SOC_CMP_COUNT (4)
    /* @brief CRC availability on the SoC. */
    #define FSL_FEATURE_SOC_CRC_COUNT (1)
    /* @brief DAC availability on the SoC. */
    #define FSL_FEATURE_SOC_DAC_COUNT (1)
    /* @brief EDMA availability on the SoC. */
    #define FSL_FEATURE_SOC_EDMA_COUNT (1)
    /* @brief DMAMUX availability on the SoC. */
    #define FSL_FEATURE_SOC_DMAMUX_COUNT (1)
    /* @brief DSPI availability on the SoC. */
    #define FSL_FEATURE_SOC_DSPI_COUNT (3)
    /* @brief ENC availability on the SoC. */
    #define FSL_FEATURE_SOC_ENC_COUNT (1)
    /* @brief ENET availability on the SoC. */
    #define FSL_FEATURE_SOC_ENET_COUNT (1)
    /* @brief EWM availability on the SoC. */
    #define FSL_FEATURE_SOC_EWM_COUNT (1)
    /* @brief FB availability on the SoC. */
    #define FSL_FEATURE_SOC_FB_COUNT (1)
    /* @brief FMC availability on the SoC. */
    #define FSL_FEATURE_SOC_FMC_COUNT (1)
    /* @brief FTFE availability on the SoC. */
    #define FSL_FEATURE_SOC_FTFE_COUNT (1)
    /* @brief FTM availability on the SoC. */
    #define FSL_FEATURE_SOC_FTM_COUNT (4)
    /* @brief GPIO availability on the SoC. */
    #define FSL_FEATURE_SOC_GPIO_COUNT (5)
    /* @brief HSADC availability on the SoC. */
    #define FSL_FEATURE_SOC_HSADC_COUNT (2)
    /* @brief I2C availability on the SoC. */
    #define FSL_FEATURE_SOC_I2C_COUNT (2)
    /* @brief LLWU availability on the SoC. */
    #define FSL_FEATURE_SOC_LLWU_COUNT (1)
    /* @brief LPTMR availability on the SoC. */
    #define FSL_FEATURE_SOC_LPTMR_COUNT (1)
    /* @brief MCG availability on the SoC. */
    #define FSL_FEATURE_SOC_MCG_COUNT (1)
    /* @brief MCM availability on the SoC. */
    #define FSL_FEATURE_SOC_MCM_COUNT (1)
    /* @brief SYSMPU availability on the SoC. */
    #define FSL_FEATURE_SOC_SYSMPU_COUNT (1)
    /* @brief MSCM availability on the SoC. */
    #define FSL_FEATURE_SOC_MSCM_COUNT (1)
    /* @brief OSC availability on the SoC. */
    #define FSL_FEATURE_SOC_OSC_COUNT (1)
    /* @brief PDB availability on the SoC. */
    #define FSL_FEATURE_SOC_PDB_COUNT (2)
    /* @brief PIT availability on the SoC. */
    #define FSL_FEATURE_SOC_PIT_COUNT (1)
    /* @brief PMC availability on the SoC. */
    #define FSL_FEATURE_SOC_PMC_COUNT (1)
    /* @brief PORT availability on the SoC. */
    #define FSL_FEATURE_SOC_PORT_COUNT (5)
    /* @brief PWM availability on the SoC. */
    #define FSL_FEATURE_SOC_PWM_COUNT (2)
    /* @brief RCM availability on the SoC. */
    #define FSL_FEATURE_SOC_RCM_COUNT (1)
    /* @brief RFSYS availability on the SoC. */
    #define FSL_FEATURE_SOC_RFSYS_COUNT (1)
    /* @brief RFVBAT availability on the SoC. */
    #define FSL_FEATURE_SOC_RFVBAT_COUNT (1)
    /* @brief SIM availability on the SoC. */
    #define FSL_FEATURE_SOC_SIM_COUNT (1)
    /* @brief SMC availability on the SoC. */
    #define FSL_FEATURE_SOC_SMC_COUNT (1)
    /* @brief TRNG availability on the SoC. */
    #define FSL_FEATURE_SOC_TRNG_COUNT (1)
    /* @brief UART availability on the SoC. */
    #define FSL_FEATURE_SOC_UART_COUNT (5)
    /* @brief WDOG availability on the SoC. */
    #define FSL_FEATURE_SOC_WDOG_COUNT (1)
    /* @brief XBARA availability on the SoC. */
    #define FSL_FEATURE_SOC_XBARA_COUNT (1)
    /* @brief XBARB availability on the SoC. */
    #define FSL_FEATURE_SOC_XBARB_COUNT (1)
#elif defined(CPU_MKV58F1M0VLQ24) || defined(CPU_MKV58F1M0VMD24) || defined(CPU_MKV58F512VLQ24) || defined(CPU_MKV58F512VMD24)
    /* @brief ADC16 availability on the SoC. */
    #define FSL_FEATURE_SOC_ADC16_COUNT (1)
    /* @brief AIPS availability on the SoC. */
    #define FSL_FEATURE_SOC_AIPS_COUNT (2)
    /* @brief AOI availability on the SoC. */
    #define FSL_FEATURE_SOC_AOI_COUNT (1)
    /* @brief AXBS availability on the SoC. */
    #define FSL_FEATURE_SOC_AXBS_COUNT (1)
    /* @brief FLEXCAN availability on the SoC. */
    #define FSL_FEATURE_SOC_FLEXCAN_COUNT (3)
    /* @brief MMCAU availability on the SoC. */
    #define FSL_FEATURE_SOC_MMCAU_COUNT (1)
    /* @brief CMP availability on the SoC. */
    #define FSL_FEATURE_SOC_CMP_COUNT (4)
    /* @brief CRC availability on the SoC. */
    #define FSL_FEATURE_SOC_CRC_COUNT (1)
    /* @brief DAC availability on the SoC. */
    #define FSL_FEATURE_SOC_DAC_COUNT (1)
    /* @brief EDMA availability on the SoC. */
    #define FSL_FEATURE_SOC_EDMA_COUNT (1)
    /* @brief DMAMUX availability on the SoC. */
    #define FSL_FEATURE_SOC_DMAMUX_COUNT (1)
    /* @brief DSPI availability on the SoC. */
    #define FSL_FEATURE_SOC_DSPI_COUNT (3)
    /* @brief ENC availability on the SoC. */
    #define FSL_FEATURE_SOC_ENC_COUNT (1)
    /* @brief ENET availability on the SoC. */
    #define FSL_FEATURE_SOC_ENET_COUNT (1)
    /* @brief EWM availability on the SoC. */
    #define FSL_FEATURE_SOC_EWM_COUNT (1)
    /* @brief FB availability on the SoC. */
    #define FSL_FEATURE_SOC_FB_COUNT (1)
    /* @brief FMC availability on the SoC. */
    #define FSL_FEATURE_SOC_FMC_COUNT (1)
    /* @brief FTFE availability on the SoC. */
    #define FSL_FEATURE_SOC_FTFE_COUNT (1)
    /* @brief FTM availability on the SoC. */
    #define FSL_FEATURE_SOC_FTM_COUNT (4)
    /* @brief GPIO availability on the SoC. */
    #define FSL_FEATURE_SOC_GPIO_COUNT (5)
    /* @brief HSADC availability on the SoC. */
    #define FSL_FEATURE_SOC_HSADC_COUNT (2)
    /* @brief I2C availability on the SoC. */
    #define FSL_FEATURE_SOC_I2C_COUNT (2)
    /* @brief LLWU availability on the SoC. */
    #define FSL_FEATURE_SOC_LLWU_COUNT (1)
    /* @brief LPTMR availability on the SoC. */
    #define FSL_FEATURE_SOC_LPTMR_COUNT (1)
    /* @brief MCG availability on the SoC. */
    #define FSL_FEATURE_SOC_MCG_COUNT (1)
    /* @brief MCM availability on the SoC. */
    #define FSL_FEATURE_SOC_MCM_COUNT (1)
    /* @brief SYSMPU availability on the SoC. */
    #define FSL_FEATURE_SOC_SYSMPU_COUNT (1)
    /* @brief MSCM availability on the SoC. */
    #define FSL_FEATURE_SOC_MSCM_COUNT (1)
    /* @brief OSC availability on the SoC. */
    #define FSL_FEATURE_SOC_OSC_COUNT (1)
    /* @brief PDB availability on the SoC. */
    #define FSL_FEATURE_SOC_PDB_COUNT (2)
    /* @brief PIT availability on the SoC. */
    #define FSL_FEATURE_SOC_PIT_COUNT (1)
    /* @brief PMC availability on the SoC. */
    #define FSL_FEATURE_SOC_PMC_COUNT (1)
    /* @brief PORT availability on the SoC. */
    #define FSL_FEATURE_SOC_PORT_COUNT (5)
    /* @brief PWM availability on the SoC. */
    #define FSL_FEATURE_SOC_PWM_COUNT (2)
    /* @brief RCM availability on the SoC. */
    #define FSL_FEATURE_SOC_RCM_COUNT (1)
    /* @brief RFSYS availability on the SoC. */
    #define FSL_FEATURE_SOC_RFSYS_COUNT (1)
    /* @brief RFVBAT availability on the SoC. */
    #define FSL_FEATURE_SOC_RFVBAT_COUNT (1)
    /* @brief SIM availability on the SoC. */
    #define FSL_FEATURE_SOC_SIM_COUNT (1)
    /* @brief SMC availability on the SoC. */
    #define FSL_FEATURE_SOC_SMC_COUNT (1)
    /* @brief TRNG availability on the SoC. */
    #define FSL_FEATURE_SOC_TRNG_COUNT (1)
    /* @brief UART availability on the SoC. */
    #define FSL_FEATURE_SOC_UART_COUNT (6)
    /* @brief WDOG availability on the SoC. */
    #define FSL_FEATURE_SOC_WDOG_COUNT (1)
    /* @brief XBARA availability on the SoC. */
    #define FSL_FEATURE_SOC_XBARA_COUNT (1)
    /* @brief XBARB availability on the SoC. */
    #define FSL_FEATURE_SOC_XBARB_COUNT (1)
#endif

/* ADC16 module features */

/* @brief Has Programmable Gain Amplifier (PGA) in ADC (register PGA). */
#define FSL_FEATURE_ADC16_HAS_PGA (0)
/* @brief Has PGA chopping control in ADC (bit PGA[PGACHPb] or PGA[PGACHP]). */
#define FSL_FEATURE_ADC16_HAS_PGA_CHOPPING (0)
/* @brief Has PGA offset measurement mode in ADC (bit PGA[PGAOFSM]). */
#define FSL_FEATURE_ADC16_HAS_PGA_OFFSET_MEASUREMENT (0)
/* @brief Has DMA support (bit SC2[DMAEN] or SC4[DMAEN]). */
#define FSL_FEATURE_ADC16_HAS_DMA (1)
/* @brief Has differential mode (bitfield SC1x[DIFF]). */
#define FSL_FEATURE_ADC16_HAS_DIFF_MODE (1)
/* @brief Has FIFO (bit SC4[AFDEP]). */
#define FSL_FEATURE_ADC16_HAS_FIFO (0)
/* @brief FIFO size if available (bitfield SC4[AFDEP]). */
#define FSL_FEATURE_ADC16_FIFO_SIZE (0)
/* @brief Has channel set a/b multiplexor (bitfield CFG2[MUXSEL]). */
#define FSL_FEATURE_ADC16_HAS_MUX_SELECT (1)
/* @brief Has HW trigger masking (bitfield SC5[HTRGMASKE]. */
#define FSL_FEATURE_ADC16_HAS_HW_TRIGGER_MASK (0)
/* @brief Has calibration feature (bit SC3[CAL] and registers CLPx, CLMx). */
#define FSL_FEATURE_ADC16_HAS_CALIBRATION (1)
/* @brief Has HW averaging (bit SC3[AVGE]). */
#define FSL_FEATURE_ADC16_HAS_HW_AVERAGE (1)
/* @brief Has offset correction (register OFS). */
#define FSL_FEATURE_ADC16_HAS_OFFSET_CORRECTION (1)
/* @brief Maximum ADC resolution. */
#define FSL_FEATURE_ADC16_MAX_RESOLUTION (16)
/* @brief Number of SC1x and Rx register pairs (conversion control and result registers). */
#define FSL_FEATURE_ADC16_CONVERSION_CONTROL_COUNT (2)

/* AOI module features */

/* @brief Maximum value of AOI0 input mux. */
#define FSL_FEATURE_AOI_MODULE_INPUTS (4)
/* @brief Number of AOI0 events (related to number of registers AOI0_BFCRT01n/AOI0_BFCRT23n). */
#define FSL_FEATURE_AOI_EVENT_COUNT (4)

/* FLEXCAN module features */

/* @brief Message buffer size */
#define FSL_FEATURE_FLEXCAN_HAS_MESSAGE_BUFFER_MAX_NUMBERn(x) (16)
/* @brief Has doze mode support (register bit field MCR[DOZE]). */
#define FSL_FEATURE_FLEXCAN_HAS_DOZE_MODE_SUPPORT (1)
/* @brief Insatnce has doze mode support (register bit field MCR[DOZE]). */
#define FSL_FEATURE_FLEXCAN_INSTANCE_HAS_DOZE_MODE_SUPPORTn(x) (1)
/* @brief Has a glitch filter on the receive pin (register bit field MCR[WAKSRC]). */
#define FSL_FEATURE_FLEXCAN_HAS_GLITCH_FILTER (1)
/* @brief Has extended interrupt mask and flag register (register IMASK2, IFLAG2). */
#define FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER (0)
/* @brief Instance has extended bit timing register (register CBT). */
#define FSL_FEATURE_FLEXCAN_INSTANCE_HAS_EXTENDED_TIMING_REGISTERn(x) (1)
/* @brief Has a receive FIFO DMA feature (register bit field MCR[DMA]). */
#define FSL_FEATURE_FLEXCAN_HAS_RX_FIFO_DMA (1)
/* @brief Instance has a receive FIFO DMA feature (register bit field MCR[DMA]). */
#define FSL_FEATURE_FLEXCAN_INSTANCE_HAS_RX_FIFO_DMAn(x) (1)
/* @brief Has separate message buffer 0 interrupt flag (register bit field IFLAG1[BUF0I]). */
#define FSL_FEATURE_FLEXCAN_HAS_SEPARATE_BUFFER_0_FLAG (1)
/* @brief Has bitfield name BUF31TO0M. */
#define FSL_FEATURE_FLEXCAN_HAS_BUF31TO0M (1)
/* @brief Number of interrupt vectors. */
#define FSL_FEATURE_FLEXCAN_INTERRUPT_COUNT (6)
/* @brief Is affected by errata with ID 5641 (Module does not transmit a message that is enabled to be transmitted at a specific moment during the arbitration process). */
#define FSL_FEATURE_FLEXCAN_HAS_ERRATA_5641 (0)

/* CMP module features */

/* @brief Has Trigger mode in CMP (register bit field CR1[TRIGM]). */
#define FSL_FEATURE_CMP_HAS_TRIGGER_MODE (1)
/* @brief Has Window mode in CMP (register bit field CR1[WE]). */
#define FSL_FEATURE_CMP_HAS_WINDOW_MODE (1)
/* @brief Has External sample supported in CMP (register bit field CR1[SE]). */
#define FSL_FEATURE_CMP_HAS_EXTERNAL_SAMPLE_SUPPORT (1)
/* @brief Has DMA support in CMP (register bit field SCR[DMAEN]). */
#define FSL_FEATURE_CMP_HAS_DMA (1)
/* @brief Has Pass Through mode in CMP (register bit field MUXCR[PSTM]). */
#define FSL_FEATURE_CMP_HAS_PASS_THROUGH_MODE (0)
/* @brief Has DAC Test function in CMP (register DACTEST). */
#define FSL_FEATURE_CMP_HAS_DAC_TEST (0)

/* CRC module features */

/* @brief Has data register with name CRC */
#define FSL_FEATURE_CRC_HAS_CRC_REG (0)

/* DAC module features */

/* @brief Define the size of hardware buffer */
#define FSL_FEATURE_DAC_BUFFER_SIZE (16)
/* @brief Define whether the buffer supports watermark event detection or not. */
#define FSL_FEATURE_DAC_HAS_WATERMARK_DETECTION (1)
/* @brief Define whether the buffer supports watermark selection detection or not. */
#define FSL_FEATURE_DAC_HAS_WATERMARK_SELECTION (1)
/* @brief Define whether the buffer supports watermark event 1 word before buffer upper limit. */
#define FSL_FEATURE_DAC_HAS_WATERMARK_1_WORD (1)
/* @brief Define whether the buffer supports watermark event 2 words before buffer upper limit. */
#define FSL_FEATURE_DAC_HAS_WATERMARK_2_WORDS (1)
/* @brief Define whether the buffer supports watermark event 3 words before buffer upper limit. */
#define FSL_FEATURE_DAC_HAS_WATERMARK_3_WORDS (1)
/* @brief Define whether the buffer supports watermark event 4 words before buffer upper limit. */
#define FSL_FEATURE_DAC_HAS_WATERMARK_4_WORDS (1)
/* @brief Define whether FIFO buffer mode is available or not. */
#define FSL_FEATURE_DAC_HAS_BUFFER_FIFO_MODE (1)
/* @brief Define whether swing buffer mode is available or not.. */
#define FSL_FEATURE_DAC_HAS_BUFFER_SWING_MODE (1)

/* EDMA module features */

/* @brief Number of DMA channels (related to number of registers TCD, DCHPRI, bit fields ERQ[ERQn], EEI[EEIn], INT[INTn], ERR[ERRn], HRS[HRSn] and bit field widths ES[ERRCHN], CEEI[CEEI], SEEI[SEEI], CERQ[CERQ], SERQ[SERQ], CDNE[CDNE], SSRT[SSRT], CERR[CERR], CINT[CINT], TCDn_CITER_ELINKYES[LINKCH], TCDn_CSR[MAJORLINKCH], TCDn_BITER_ELINKYES[LINKCH]). (Valid only for eDMA modules.) */
#define FSL_FEATURE_EDMA_MODULE_CHANNEL (32)
/* @brief Total number of DMA channels on all modules. */
#define FSL_FEATURE_EDMA_DMAMUX_CHANNELS (FSL_FEATURE_SOC_EDMA_COUNT * 32)
/* @brief Number of DMA channel groups (register bit fields CR[ERGA], CR[GRPnPRI], ES[GPE], DCHPRIn[GRPPRI]). (Valid only for eDMA modules.) */
#define FSL_FEATURE_EDMA_CHANNEL_GROUP_COUNT (2)
/* @brief Has DMA_Error interrupt vector. */
#define FSL_FEATURE_EDMA_HAS_ERROR_IRQ (1)
/* @brief Number of DMA channels with asynchronous request capability (register EARS). (Valid only for eDMA modules.) */
#define FSL_FEATURE_EDMA_ASYNCHRO_REQUEST_CHANNEL_COUNT (32)
/* @brief Channel IRQ entry shared offset. */
#define FSL_FEATURE_EDMA_MODULE_CHANNEL_IRQ_ENTRY_SHARED_OFFSET (16)
/* @brief If 8 bytes transfer supported. */
#define FSL_FEATURE_EDMA_SUPPORT_8_BYTES_TRANSFER (0)
/* @brief If 16 bytes transfer supported. */
#define FSL_FEATURE_EDMA_SUPPORT_16_BYTES_TRANSFER (1)

/* DMAMUX module features */

/* @brief Number of DMA channels (related to number of register CHCFGn). */
#define FSL_FEATURE_DMAMUX_MODULE_CHANNEL (32)
/* @brief Total number of DMA channels on all modules. */
#define FSL_FEATURE_DMAMUX_DMAMUX_CHANNELS (FSL_FEATURE_SOC_DMAMUX_COUNT * 32)
/* @brief Has the periodic trigger capability for the triggered DMA channel (register bit CHCFG0[TRIG]). */
#define FSL_FEATURE_DMAMUX_HAS_TRIG (1)

/* ENC module features */

/* No feature definitions */

/* ENET module features */

/* @brief Has buffer descriptor byte swapping (register bit field ECR[DBSWP]). */
#define FSL_FEATURE_ENET_DMA_BIG_ENDIAN_ONLY (0)
/* @brief Has precision time protocol (IEEE 1588) support (register bit field ECR[EN1588], registers ATCR, ATVR, ATOFF, ATPER, ATCOR, ATINC, ATSTMP). */
#define FSL_FEATURE_ENET_SUPPORT_PTP (1)
/* @brief Number of associated interrupt vectors. */
#define FSL_FEATURE_ENET_INTERRUPT_COUNT (4)
/* @brief Has threshold for the number of frames in the receive FIFO (register bit field RSEM[STAT_SECTION_EMPTY]). */
#define FSL_FEATURE_ENET_HAS_RECEIVE_STATUS_THRESHOLD (1)
/* @brief Has Extend MDIO Support. */
#define FSL_FEATURE_ENET_HAS_EXTEND_MDIO (1)

/* EWM module features */

/* @brief Has clock select (register CLKCTRL). */
#define FSL_FEATURE_EWM_HAS_CLOCK_SELECT (1)
/* @brief Has clock prescaler (register CLKPRESCALER). */
#define FSL_FEATURE_EWM_HAS_PRESCALER (1)

/* FLEXBUS module features */

/* No feature definitions */

/* FLASH module features */

#if defined(CPU_MKV58F1M0VLL24) || defined(CPU_MKV58F1M0VLQ24) || defined(CPU_MKV58F1M0VMD24)
    /* @brief Is of type FTFA. */
    #define FSL_FEATURE_FLASH_IS_FTFA (0)
    /* @brief Is of type FTFE. */
    #define FSL_FEATURE_FLASH_IS_FTFE (1)
    /* @brief Is of type FTFL. */
    #define FSL_FEATURE_FLASH_IS_FTFL (0)
    /* @brief Has flags indicating the status of the FlexRAM (register bits FCNFG[EEERDY], FCNFG[RAMRDY] and FCNFG[PFLSH]). */
    #define FSL_FEATURE_FLASH_HAS_FLEX_RAM_FLAGS (1)
    /* @brief Has program flash swapping status flag (register bit FCNFG[SWAP]). */
    #define FSL_FEATURE_FLASH_HAS_PFLASH_SWAPPING_STATUS_FLAG (0)
    /* @brief Has EEPROM region protection (register FEPROT). */
    #define FSL_FEATURE_FLASH_HAS_EEROM_REGION_PROTECTION (0)
    /* @brief Has data flash region protection (register FDPROT). */
    #define FSL_FEATURE_FLASH_HAS_DATA_FLASH_REGION_PROTECTION (0)
    /* @brief Has flash access control (registers XACCHn, SACCHn, where n is a number, FACSS and FACSN). */
    #define FSL_FEATURE_FLASH_HAS_ACCESS_CONTROL (0)
    /* @brief Has flash cache control in FMC module. */
    #define FSL_FEATURE_FLASH_HAS_FMC_FLASH_CACHE_CONTROLS (0)
    /* @brief Has flash cache control in MCM module. */
    #define FSL_FEATURE_FLASH_HAS_MCM_FLASH_CACHE_CONTROLS (0)
    /* @brief Has flash cache control in MSCM module. */
    #define FSL_FEATURE_FLASH_HAS_MSCM_FLASH_CACHE_CONTROLS (0)
    /* @brief Has prefetch speculation control in flash, such as kv5x. */
    #define FSL_FEATURE_FLASH_PREFETCH_SPECULATION_CONTROL_IN_FLASH (1)
    /* @brief P-Flash flash size coding rule version, value 0 for K1 and K2, value 1 for K3. */
    #define FSL_FEATURE_FLASH_SIZE_ENCODING_RULE_VERSION (0)
    /* @brief P-Flash start address. */
    #define FSL_FEATURE_FLASH_PFLASH_START_ADDRESS (0x10000000)
    /* @brief P-Flash block count. */
    #define FSL_FEATURE_FLASH_PFLASH_BLOCK_COUNT (1)
    /* @brief P-Flash block size. */
    #define FSL_FEATURE_FLASH_PFLASH_BLOCK_SIZE (1048576)
    /* @brief P-Flash sector size. */
    #define FSL_FEATURE_FLASH_PFLASH_BLOCK_SECTOR_SIZE (8192)
    /* @brief P-Flash write unit size. */
    #define FSL_FEATURE_FLASH_PFLASH_BLOCK_WRITE_UNIT_SIZE (8)
    /* @brief P-Flash data path width. */
    #define FSL_FEATURE_FLASH_PFLASH_BLOCK_DATA_PATH_WIDTH (32)
    /* @brief P-Flash block swap feature. */
    #define FSL_FEATURE_FLASH_HAS_PFLASH_BLOCK_SWAP (0)
    /* @brief P-Flash protection region count. */
    #define FSL_FEATURE_FLASH_PFLASH_PROTECTION_REGION_COUNT (32)
    /* @brief Has FlexNVM memory. */
    #define FSL_FEATURE_FLASH_HAS_FLEX_NVM (0)
    /* @brief Has FlexNVM alias. */
    #define FSL_FEATURE_FLASH_HAS_FLEX_NVM_ALIAS (0)
    /* @brief FlexNVM start address. (Valid only if FlexNVM is available.) */
    #define FSL_FEATURE_FLASH_FLEX_NVM_START_ADDRESS (0x00000000)
    /* @brief FlexNVM alias start address. (Valid only if FlexNVM alias is available.) */
    #define FSL_FEATURE_FLASH_FLEX_NVM_ALIAS_START_ADDRESS (0x00000000)
    /* @brief FlexNVM block count. */
    #define FSL_FEATURE_FLASH_FLEX_NVM_BLOCK_COUNT (0)
    /* @brief FlexNVM block size. */
    #define FSL_FEATURE_FLASH_FLEX_NVM_BLOCK_SIZE (0)
    /* @brief FlexNVM sector size. */
    #define FSL_FEATURE_FLASH_FLEX_NVM_BLOCK_SECTOR_SIZE (0)
    /* @brief FlexNVM write unit size. */
    #define FSL_FEATURE_FLASH_FLEX_NVM_BLOCK_WRITE_UNIT_SIZE (0)
    /* @brief FlexNVM data path width. */
    #define FSL_FEATURE_FLASH_FLEX_BLOCK_DATA_PATH_WIDTH (0)
    /* @brief Has FlexRAM memory. */
    #define FSL_FEATURE_FLASH_HAS_FLEX_RAM (1)
    /* @brief FlexRAM start address. (Valid only if FlexRAM is available.) */
    #define FSL_FEATURE_FLASH_FLEX_RAM_START_ADDRESS (0x18000000)
    /* @brief FlexRAM size. */
    #define FSL_FEATURE_FLASH_FLEX_RAM_SIZE (4096)
    /* @brief Has 0x00 Read 1s Block command. */
    #define FSL_FEATURE_FLASH_HAS_READ_1S_BLOCK_CMD (0)
    /* @brief Has 0x01 Read 1s Section command. */
    #define FSL_FEATURE_FLASH_HAS_READ_1S_SECTION_CMD (1)
    /* @brief Has 0x02 Program Check command. */
    #define FSL_FEATURE_FLASH_HAS_PROGRAM_CHECK_CMD (1)
    /* @brief Has 0x03 Read Resource command. */
    #define FSL_FEATURE_FLASH_HAS_READ_RESOURCE_CMD (1)
    /* @brief Has 0x06 Program Longword command. */
    #define FSL_FEATURE_FLASH_HAS_PROGRAM_LONGWORD_CMD (0)
    /* @brief Has 0x07 Program Phrase command. */
    #define FSL_FEATURE_FLASH_HAS_PROGRAM_PHRASE_CMD (1)
    /* @brief Has 0x08 Erase Flash Block command. */
    #define FSL_FEATURE_FLASH_HAS_ERASE_FLASH_BLOCK_CMD (0)
    /* @brief Has 0x09 Erase Flash Sector command. */
    #define FSL_FEATURE_FLASH_HAS_ERASE_FLASH_SECTOR_CMD (1)
    /* @brief Has 0x0B Program Section command. */
    #define FSL_FEATURE_FLASH_HAS_PROGRAM_SECTION_CMD (1)
    /* @brief Has 0x40 Read 1s All Blocks command. */
    #define FSL_FEATURE_FLASH_HAS_READ_1S_ALL_BLOCKS_CMD (1)
    /* @brief Has 0x41 Read Once command. */
    #define FSL_FEATURE_FLASH_HAS_READ_ONCE_CMD (1)
    /* @brief Has 0x43 Program Once command. */
    #define FSL_FEATURE_FLASH_HAS_PROGRAM_ONCE_CMD (1)
    /* @brief Has 0x44 Erase All Blocks command. */
    #define FSL_FEATURE_FLASH_HAS_ERASE_ALL_BLOCKS_CMD (1)
    /* @brief Has 0x45 Verify Backdoor Access Key command. */
    #define FSL_FEATURE_FLASH_HAS_VERIFY_BACKDOOR_ACCESS_KEY_CMD (1)
    /* @brief Has 0x46 Swap Control command. */
    #define FSL_FEATURE_FLASH_HAS_SWAP_CONTROL_CMD (0)
    /* @brief Has 0x49 Erase All Blocks Unsecure command. */
    #define FSL_FEATURE_FLASH_HAS_ERASE_ALL_BLOCKS_UNSECURE_CMD (1)
    /* @brief Has 0x4A Read 1s All Execute-only Segments command. */
    #define FSL_FEATURE_FLASH_HAS_READ_1S_ALL_EXECUTE_ONLY_SEGMENTS_CMD (0)
    /* @brief Has 0x4B Erase All Execute-only Segments command. */
    #define FSL_FEATURE_FLASH_HAS_ERASE_ALL_EXECUTE_ONLY_SEGMENTS_CMD (0)
    /* @brief Has 0x80 Program Partition command. */
    #define FSL_FEATURE_FLASH_HAS_PROGRAM_PARTITION_CMD (0)
    /* @brief Has 0x81 Set FlexRAM Function command. */
    #define FSL_FEATURE_FLASH_HAS_SET_FLEXRAM_FUNCTION_CMD (0)
    /* @brief P-Flash Erase/Read 1st all block command address alignment. */
    #define FSL_FEATURE_FLASH_PFLASH_BLOCK_CMD_ADDRESS_ALIGMENT (32)
    /* @brief P-Flash Erase sector command address alignment. */
    #define FSL_FEATURE_FLASH_PFLASH_SECTOR_CMD_ADDRESS_ALIGMENT (32)
    /* @brief P-Flash Rrogram/Verify section command address alignment. */
    #define FSL_FEATURE_FLASH_PFLASH_SECTION_CMD_ADDRESS_ALIGMENT (32)
    /* @brief P-Flash Read resource command address alignment. */
    #define FSL_FEATURE_FLASH_PFLASH_RESOURCE_CMD_ADDRESS_ALIGMENT (8)
    /* @brief P-Flash Program check command address alignment. */
    #define FSL_FEATURE_FLASH_PFLASH_CHECK_CMD_ADDRESS_ALIGMENT (4)
    /* @brief P-Flash Program check command address alignment. */
    #define FSL_FEATURE_FLASH_PFLASH_SWAP_CONTROL_CMD_ADDRESS_ALIGMENT (0)
    /* @brief FlexNVM Erase/Read 1st all block command address alignment. */
    #define FSL_FEATURE_FLASH_FLEX_NVM_BLOCK_CMD_ADDRESS_ALIGMENT (0)
    /* @brief FlexNVM Erase sector command address alignment. */
    #define FSL_FEATURE_FLASH_FLEX_NVM_SECTOR_CMD_ADDRESS_ALIGMENT (0)
    /* @brief FlexNVM Rrogram/Verify section command address alignment. */
    #define FSL_FEATURE_FLASH_FLEX_NVM_SECTION_CMD_ADDRESS_ALIGMENT (0)
    /* @brief FlexNVM Read resource command address alignment. */
    #define FSL_FEATURE_FLASH_FLEX_NVM_RESOURCE_CMD_ADDRESS_ALIGMENT (0)
    /* @brief FlexNVM Program check command address alignment. */
    #define FSL_FEATURE_FLASH_FLEX_NVM_CHECK_CMD_ADDRESS_ALIGMENT (0)
    /* @brief FlexNVM partition code 0000 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_0000 (0xFFFFFFFFU)
    /* @brief FlexNVM partition code 0001 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_0001 (0xFFFFFFFFU)
    /* @brief FlexNVM partition code 0010 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_0010 (0xFFFFFFFFU)
    /* @brief FlexNVM partition code 0011 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_0011 (0xFFFFFFFFU)
    /* @brief FlexNVM partition code 0100 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_0100 (0xFFFFFFFFU)
    /* @brief FlexNVM partition code 0101 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_0101 (0xFFFFFFFFU)
    /* @brief FlexNVM partition code 0110 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_0110 (0xFFFFFFFFU)
    /* @brief FlexNVM partition code 0111 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_0111 (0xFFFFFFFFU)
    /* @brief FlexNVM partition code 1000 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_1000 (0xFFFFFFFFU)
    /* @brief FlexNVM partition code 1001 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_1001 (0xFFFFFFFFU)
    /* @brief FlexNVM partition code 1010 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_1010 (0xFFFFFFFFU)
    /* @brief FlexNVM partition code 1011 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_1011 (0xFFFFFFFFU)
    /* @brief FlexNVM partition code 1100 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_1100 (0xFFFFFFFFU)
    /* @brief FlexNVM partition code 1101 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_1101 (0xFFFFFFFFU)
    /* @brief FlexNVM partition code 1110 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_1110 (0xFFFFFFFFU)
    /* @brief FlexNVM partition code 1111 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_1111 (0xFFFFFFFFU)
    /* @brief Emulated eeprom size code 0000 mapping to emulated eeprom size in bytes (0xFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_0000 (0xFFFF)
    /* @brief Emulated eeprom size code 0001 mapping to emulated eeprom size in bytes (0xFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_0001 (0xFFFF)
    /* @brief Emulated eeprom size code 0010 mapping to emulated eeprom size in bytes (0xFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_0010 (0x1000)
    /* @brief Emulated eeprom size code 0011 mapping to emulated eeprom size in bytes (0xFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_0011 (0x0800)
    /* @brief Emulated eeprom size code 0100 mapping to emulated eeprom size in bytes (0xFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_0100 (0x0400)
    /* @brief Emulated eeprom size code 0101 mapping to emulated eeprom size in bytes (0xFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_0101 (0x0200)
    /* @brief Emulated eeprom size code 0110 mapping to emulated eeprom size in bytes (0xFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_0110 (0x0100)
    /* @brief Emulated eeprom size code 0111 mapping to emulated eeprom size in bytes (0xFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_0111 (0x0080)
    /* @brief Emulated eeprom size code 1000 mapping to emulated eeprom size in bytes (0xFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_1000 (0x0040)
    /* @brief Emulated eeprom size code 1001 mapping to emulated eeprom size in bytes (0xFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_1001 (0x0020)
    /* @brief Emulated eeprom size code 1010 mapping to emulated eeprom size in bytes (0xFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_1010 (0xFFFF)
    /* @brief Emulated eeprom size code 1011 mapping to emulated eeprom size in bytes (0xFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_1011 (0xFFFF)
    /* @brief Emulated eeprom size code 1100 mapping to emulated eeprom size in bytes (0xFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_1100 (0xFFFF)
    /* @brief Emulated eeprom size code 1101 mapping to emulated eeprom size in bytes (0xFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_1101 (0xFFFF)
    /* @brief Emulated eeprom size code 1110 mapping to emulated eeprom size in bytes (0xFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_1110 (0xFFFF)
    /* @brief Emulated eeprom size code 1111 mapping to emulated eeprom size in bytes (0xFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_1111 (0x0000)
#elif defined(CPU_MKV58F512VLL24) || defined(CPU_MKV58F512VLQ24) || defined(CPU_MKV58F512VMD24)
    /* @brief Is of type FTFA. */
    #define FSL_FEATURE_FLASH_IS_FTFA (0)
    /* @brief Is of type FTFE. */
    #define FSL_FEATURE_FLASH_IS_FTFE (1)
    /* @brief Is of type FTFL. */
    #define FSL_FEATURE_FLASH_IS_FTFL (0)
    /* @brief Has flags indicating the status of the FlexRAM (register bits FCNFG[EEERDY], FCNFG[RAMRDY] and FCNFG[PFLSH]). */
    #define FSL_FEATURE_FLASH_HAS_FLEX_RAM_FLAGS (1)
    /* @brief Has program flash swapping status flag (register bit FCNFG[SWAP]). */
    #define FSL_FEATURE_FLASH_HAS_PFLASH_SWAPPING_STATUS_FLAG (0)
    /* @brief Has EEPROM region protection (register FEPROT). */
    #define FSL_FEATURE_FLASH_HAS_EEROM_REGION_PROTECTION (0)
    /* @brief Has data flash region protection (register FDPROT). */
    #define FSL_FEATURE_FLASH_HAS_DATA_FLASH_REGION_PROTECTION (0)
    /* @brief Has flash access control (registers XACCHn, SACCHn, where n is a number, FACSS and FACSN). */
    #define FSL_FEATURE_FLASH_HAS_ACCESS_CONTROL (0)
    /* @brief Has flash cache control in FMC module. */
    #define FSL_FEATURE_FLASH_HAS_FMC_FLASH_CACHE_CONTROLS (0)
    /* @brief Has flash cache control in MCM module. */
    #define FSL_FEATURE_FLASH_HAS_MCM_FLASH_CACHE_CONTROLS (0)
    /* @brief Has flash cache control in MSCM module. */
    #define FSL_FEATURE_FLASH_HAS_MSCM_FLASH_CACHE_CONTROLS (0)
    /* @brief Has prefetch speculation control in flash, such as kv5x. */
    #define FSL_FEATURE_FLASH_PREFETCH_SPECULATION_CONTROL_IN_FLASH (1)
    /* @brief P-Flash flash size coding rule version, value 0 for K1 and K2, value 1 for K3. */
    #define FSL_FEATURE_FLASH_SIZE_ENCODING_RULE_VERSION (0)
    /* @brief P-Flash start address. */
    #define FSL_FEATURE_FLASH_PFLASH_START_ADDRESS (0x10000000)
    /* @brief P-Flash block count. */
    #define FSL_FEATURE_FLASH_PFLASH_BLOCK_COUNT (1)
    /* @brief P-Flash block size. */
    #define FSL_FEATURE_FLASH_PFLASH_BLOCK_SIZE (524288)
    /* @brief P-Flash sector size. */
    #define FSL_FEATURE_FLASH_PFLASH_BLOCK_SECTOR_SIZE (8192)
    /* @brief P-Flash write unit size. */
    #define FSL_FEATURE_FLASH_PFLASH_BLOCK_WRITE_UNIT_SIZE (8)
    /* @brief P-Flash data path width. */
    #define FSL_FEATURE_FLASH_PFLASH_BLOCK_DATA_PATH_WIDTH (32)
    /* @brief P-Flash block swap feature. */
    #define FSL_FEATURE_FLASH_HAS_PFLASH_BLOCK_SWAP (0)
    /* @brief P-Flash protection region count. */
    #define FSL_FEATURE_FLASH_PFLASH_PROTECTION_REGION_COUNT (32)
    /* @brief Has FlexNVM memory. */
    #define FSL_FEATURE_FLASH_HAS_FLEX_NVM (0)
    /* @brief Has FlexNVM alias. */
    #define FSL_FEATURE_FLASH_HAS_FLEX_NVM_ALIAS (0)
    /* @brief FlexNVM start address. (Valid only if FlexNVM is available.) */
    #define FSL_FEATURE_FLASH_FLEX_NVM_START_ADDRESS (0x00000000)
    /* @brief FlexNVM alias start address. (Valid only if FlexNVM alias is available.) */
    #define FSL_FEATURE_FLASH_FLEX_NVM_ALIAS_START_ADDRESS (0x00000000)
    /* @brief FlexNVM block count. */
    #define FSL_FEATURE_FLASH_FLEX_NVM_BLOCK_COUNT (0)
    /* @brief FlexNVM block size. */
    #define FSL_FEATURE_FLASH_FLEX_NVM_BLOCK_SIZE (0)
    /* @brief FlexNVM sector size. */
    #define FSL_FEATURE_FLASH_FLEX_NVM_BLOCK_SECTOR_SIZE (0)
    /* @brief FlexNVM write unit size. */
    #define FSL_FEATURE_FLASH_FLEX_NVM_BLOCK_WRITE_UNIT_SIZE (0)
    /* @brief FlexNVM data path width. */
    #define FSL_FEATURE_FLASH_FLEX_BLOCK_DATA_PATH_WIDTH (0)
    /* @brief Has FlexRAM memory. */
    #define FSL_FEATURE_FLASH_HAS_FLEX_RAM (1)
    /* @brief FlexRAM start address. (Valid only if FlexRAM is available.) */
    #define FSL_FEATURE_FLASH_FLEX_RAM_START_ADDRESS (0x18000000)
    /* @brief FlexRAM size. */
    #define FSL_FEATURE_FLASH_FLEX_RAM_SIZE (4096)
    /* @brief Has 0x00 Read 1s Block command. */
    #define FSL_FEATURE_FLASH_HAS_READ_1S_BLOCK_CMD (0)
    /* @brief Has 0x01 Read 1s Section command. */
    #define FSL_FEATURE_FLASH_HAS_READ_1S_SECTION_CMD (1)
    /* @brief Has 0x02 Program Check command. */
    #define FSL_FEATURE_FLASH_HAS_PROGRAM_CHECK_CMD (1)
    /* @brief Has 0x03 Read Resource command. */
    #define FSL_FEATURE_FLASH_HAS_READ_RESOURCE_CMD (1)
    /* @brief Has 0x06 Program Longword command. */
    #define FSL_FEATURE_FLASH_HAS_PROGRAM_LONGWORD_CMD (0)
    /* @brief Has 0x07 Program Phrase command. */
    #define FSL_FEATURE_FLASH_HAS_PROGRAM_PHRASE_CMD (1)
    /* @brief Has 0x08 Erase Flash Block command. */
    #define FSL_FEATURE_FLASH_HAS_ERASE_FLASH_BLOCK_CMD (0)
    /* @brief Has 0x09 Erase Flash Sector command. */
    #define FSL_FEATURE_FLASH_HAS_ERASE_FLASH_SECTOR_CMD (1)
    /* @brief Has 0x0B Program Section command. */
    #define FSL_FEATURE_FLASH_HAS_PROGRAM_SECTION_CMD (1)
    /* @brief Has 0x40 Read 1s All Blocks command. */
    #define FSL_FEATURE_FLASH_HAS_READ_1S_ALL_BLOCKS_CMD (1)
    /* @brief Has 0x41 Read Once command. */
    #define FSL_FEATURE_FLASH_HAS_READ_ONCE_CMD (1)
    /* @brief Has 0x43 Program Once command. */
    #define FSL_FEATURE_FLASH_HAS_PROGRAM_ONCE_CMD (1)
    /* @brief Has 0x44 Erase All Blocks command. */
    #define FSL_FEATURE_FLASH_HAS_ERASE_ALL_BLOCKS_CMD (1)
    /* @brief Has 0x45 Verify Backdoor Access Key command. */
    #define FSL_FEATURE_FLASH_HAS_VERIFY_BACKDOOR_ACCESS_KEY_CMD (1)
    /* @brief Has 0x46 Swap Control command. */
    #define FSL_FEATURE_FLASH_HAS_SWAP_CONTROL_CMD (0)
    /* @brief Has 0x49 Erase All Blocks Unsecure command. */
    #define FSL_FEATURE_FLASH_HAS_ERASE_ALL_BLOCKS_UNSECURE_CMD (1)
    /* @brief Has 0x4A Read 1s All Execute-only Segments command. */
    #define FSL_FEATURE_FLASH_HAS_READ_1S_ALL_EXECUTE_ONLY_SEGMENTS_CMD (0)
    /* @brief Has 0x4B Erase All Execute-only Segments command. */
    #define FSL_FEATURE_FLASH_HAS_ERASE_ALL_EXECUTE_ONLY_SEGMENTS_CMD (0)
    /* @brief Has 0x80 Program Partition command. */
    #define FSL_FEATURE_FLASH_HAS_PROGRAM_PARTITION_CMD (0)
    /* @brief Has 0x81 Set FlexRAM Function command. */
    #define FSL_FEATURE_FLASH_HAS_SET_FLEXRAM_FUNCTION_CMD (0)
    /* @brief P-Flash Erase/Read 1st all block command address alignment. */
    #define FSL_FEATURE_FLASH_PFLASH_BLOCK_CMD_ADDRESS_ALIGMENT (32)
    /* @brief P-Flash Erase sector command address alignment. */
    #define FSL_FEATURE_FLASH_PFLASH_SECTOR_CMD_ADDRESS_ALIGMENT (32)
    /* @brief P-Flash Rrogram/Verify section command address alignment. */
    #define FSL_FEATURE_FLASH_PFLASH_SECTION_CMD_ADDRESS_ALIGMENT (32)
    /* @brief P-Flash Read resource command address alignment. */
    #define FSL_FEATURE_FLASH_PFLASH_RESOURCE_CMD_ADDRESS_ALIGMENT (8)
    /* @brief P-Flash Program check command address alignment. */
    #define FSL_FEATURE_FLASH_PFLASH_CHECK_CMD_ADDRESS_ALIGMENT (4)
    /* @brief P-Flash Program check command address alignment. */
    #define FSL_FEATURE_FLASH_PFLASH_SWAP_CONTROL_CMD_ADDRESS_ALIGMENT (0)
    /* @brief FlexNVM Erase/Read 1st all block command address alignment. */
    #define FSL_FEATURE_FLASH_FLEX_NVM_BLOCK_CMD_ADDRESS_ALIGMENT (0)
    /* @brief FlexNVM Erase sector command address alignment. */
    #define FSL_FEATURE_FLASH_FLEX_NVM_SECTOR_CMD_ADDRESS_ALIGMENT (0)
    /* @brief FlexNVM Rrogram/Verify section command address alignment. */
    #define FSL_FEATURE_FLASH_FLEX_NVM_SECTION_CMD_ADDRESS_ALIGMENT (0)
    /* @brief FlexNVM Read resource command address alignment. */
    #define FSL_FEATURE_FLASH_FLEX_NVM_RESOURCE_CMD_ADDRESS_ALIGMENT (0)
    /* @brief FlexNVM Program check command address alignment. */
    #define FSL_FEATURE_FLASH_FLEX_NVM_CHECK_CMD_ADDRESS_ALIGMENT (0)
    /* @brief FlexNVM partition code 0000 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_0000 (0xFFFFFFFFU)
    /* @brief FlexNVM partition code 0001 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_0001 (0xFFFFFFFFU)
    /* @brief FlexNVM partition code 0010 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_0010 (0xFFFFFFFFU)
    /* @brief FlexNVM partition code 0011 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_0011 (0xFFFFFFFFU)
    /* @brief FlexNVM partition code 0100 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_0100 (0xFFFFFFFFU)
    /* @brief FlexNVM partition code 0101 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_0101 (0xFFFFFFFFU)
    /* @brief FlexNVM partition code 0110 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_0110 (0xFFFFFFFFU)
    /* @brief FlexNVM partition code 0111 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_0111 (0xFFFFFFFFU)
    /* @brief FlexNVM partition code 1000 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_1000 (0xFFFFFFFFU)
    /* @brief FlexNVM partition code 1001 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_1001 (0xFFFFFFFFU)
    /* @brief FlexNVM partition code 1010 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_1010 (0xFFFFFFFFU)
    /* @brief FlexNVM partition code 1011 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_1011 (0xFFFFFFFFU)
    /* @brief FlexNVM partition code 1100 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_1100 (0xFFFFFFFFU)
    /* @brief FlexNVM partition code 1101 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_1101 (0xFFFFFFFFU)
    /* @brief FlexNVM partition code 1110 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_1110 (0xFFFFFFFFU)
    /* @brief FlexNVM partition code 1111 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_1111 (0xFFFFFFFFU)
    /* @brief Emulated eeprom size code 0000 mapping to emulated eeprom size in bytes (0xFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_0000 (0xFFFF)
    /* @brief Emulated eeprom size code 0001 mapping to emulated eeprom size in bytes (0xFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_0001 (0xFFFF)
    /* @brief Emulated eeprom size code 0010 mapping to emulated eeprom size in bytes (0xFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_0010 (0x1000)
    /* @brief Emulated eeprom size code 0011 mapping to emulated eeprom size in bytes (0xFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_0011 (0x0800)
    /* @brief Emulated eeprom size code 0100 mapping to emulated eeprom size in bytes (0xFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_0100 (0x0400)
    /* @brief Emulated eeprom size code 0101 mapping to emulated eeprom size in bytes (0xFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_0101 (0x0200)
    /* @brief Emulated eeprom size code 0110 mapping to emulated eeprom size in bytes (0xFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_0110 (0x0100)
    /* @brief Emulated eeprom size code 0111 mapping to emulated eeprom size in bytes (0xFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_0111 (0x0080)
    /* @brief Emulated eeprom size code 1000 mapping to emulated eeprom size in bytes (0xFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_1000 (0x0040)
    /* @brief Emulated eeprom size code 1001 mapping to emulated eeprom size in bytes (0xFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_1001 (0x0020)
    /* @brief Emulated eeprom size code 1010 mapping to emulated eeprom size in bytes (0xFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_1010 (0xFFFF)
    /* @brief Emulated eeprom size code 1011 mapping to emulated eeprom size in bytes (0xFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_1011 (0xFFFF)
    /* @brief Emulated eeprom size code 1100 mapping to emulated eeprom size in bytes (0xFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_1100 (0xFFFF)
    /* @brief Emulated eeprom size code 1101 mapping to emulated eeprom size in bytes (0xFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_1101 (0xFFFF)
    /* @brief Emulated eeprom size code 1110 mapping to emulated eeprom size in bytes (0xFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_1110 (0xFFFF)
    /* @brief Emulated eeprom size code 1111 mapping to emulated eeprom size in bytes (0xFFFF = reserved). */
    #define FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_1111 (0x0000)
#endif /* defined(CPU_MKV58F1M0VLL24) || defined(CPU_MKV58F1M0VLQ24) || defined(CPU_MKV58F1M0VMD24) */

/* FTM module features */

/* @brief Number of channels. */
#define FSL_FEATURE_FTM_CHANNEL_COUNTn(x) \
    (((x) == FTM0) ? (8) : \
    (((x) == FTM1) ? (2) : \
    (((x) == FTM2) ? (2) : \
    (((x) == FTM3) ? (8) : (-1)))))
/* @brief Has counter reset by the selected input capture event (register bits C0SC[ICRST], C1SC[ICRST], ...). */
#define FSL_FEATURE_FTM_HAS_COUNTER_RESET_BY_CAPTURE_EVENT (1)
/* @brief Has extended deadtime value. */
#define FSL_FEATURE_FTM_HAS_EXTENDED_DEADTIME_VALUE (0)
/* @brief Enable pwm output for the module. */
#define FSL_FEATURE_FTM_HAS_ENABLE_PWM_OUTPUT (0)
/* @brief Has half-cycle reload for the module. */
#define FSL_FEATURE_FTM_HAS_HALFCYCLE_RELOAD (0)
/* @brief Has reload interrupt. */
#define FSL_FEATURE_FTM_HAS_RELOAD_INTERRUPT (0)
/* @brief Has reload initialization trigger. */
#define FSL_FEATURE_FTM_HAS_RELOAD_INITIALIZATION_TRIGGER (0)
/* @brief Has DMA support, bitfield CnSC[DMA]. */
#define FSL_FEATURE_FTM_HAS_DMA_SUPPORT (1)
/* @brief If channel 6 is used to generate channel trigger, bitfield EXTTRIG[CH6TRIG]. */
#define FSL_FEATURE_FTM_HAS_CHANNEL6_TRIGGER (0)
/* @brief If channel 7 is used to generate channel trigger, bitfield EXTTRIG[CH7TRIG]. */
#define FSL_FEATURE_FTM_HAS_CHANNEL7_TRIGGER (0)
/* @brief Has no QDCTRL. */
#define FSL_FEATURE_FTM_HAS_NO_QDCTRL (0)
/* @brief If instance has only TPM function. */
#define FSL_FEATURE_FTM_IS_TPM_ONLY_INSTANCEn(x) (0)

/* GPIO module features */

/* @brief Has GPIO attribute checker register (GACR). */
#define FSL_FEATURE_GPIO_HAS_ATTRIBUTE_CHECKER (0)

/* I2C module features */

/* @brief Has System Management Bus support (registers SMB, A2, SLTL and SLTH). */
#define FSL_FEATURE_I2C_HAS_SMBUS (1)
/* @brief Maximum supported baud rate in kilobit per second. */
#define FSL_FEATURE_I2C_MAX_BAUD_KBPS (100)
/* @brief Is affected by errata with ID 6070 (repeat start cannot be generated if the F[MULT] bit field is set to a non-zero value). */
#define FSL_FEATURE_I2C_HAS_ERRATA_6070 (0)
/* @brief Has DMA support (register bit C1[DMAEN]). */
#define FSL_FEATURE_I2C_HAS_DMA_SUPPORT (1)
/* @brief Has I2C bus start and stop detection (register bits FLT[SSIE], FLT[STARTF] and FLT[STOPF]). */
#define FSL_FEATURE_I2C_HAS_START_STOP_DETECT (1)
/* @brief Has I2C bus stop detection (register bits FLT[STOPIE] and FLT[STOPF]). */
#define FSL_FEATURE_I2C_HAS_STOP_DETECT (0)
/* @brief Has I2C bus stop hold off (register bit FLT[SHEN]). */
#define FSL_FEATURE_I2C_HAS_STOP_HOLD_OFF (1)
/* @brief Maximum width of the glitch filter in number of bus clocks. */
#define FSL_FEATURE_I2C_MAX_GLITCH_FILTER_WIDTH (15)
/* @brief Has control of the drive capability of the I2C pins. */
#define FSL_FEATURE_I2C_HAS_HIGH_DRIVE_SELECTION (1)
/* @brief Has double buffering support (register S2). */
#define FSL_FEATURE_I2C_HAS_DOUBLE_BUFFERING (0)
/* @brief Has double buffer enable. */
#define FSL_FEATURE_I2C_HAS_DOUBLE_BUFFER_ENABLE (0)

/* LLWU module features */

#if defined(CPU_MKV58F1M0VLL24) || defined(CPU_MKV58F512VLL24)
    /* @brief Maximum number of pins (maximal index plus one) connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN (22)
    /* @brief Has pins 8-15 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_EXTERNAL_PIN_GROUP2 (1)
    /* @brief Maximum number of internal modules connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_INTERNAL_MODULE (4)
    /* @brief Number of digital filters. */
    #define FSL_FEATURE_LLWU_HAS_PIN_FILTER (2)
    /* @brief Has MF register. */
    #define FSL_FEATURE_LLWU_HAS_MF (1)
    /* @brief Has PF register. */
    #define FSL_FEATURE_LLWU_HAS_PF (1)
    /* @brief Has possibility to enable reset in low leakage power mode and enable digital filter for RESET pin (register LLWU_RST). */
    #define FSL_FEATURE_LLWU_HAS_RESET_ENABLE (0)
    /* @brief Has no internal module wakeup flag register. */
    #define FSL_FEATURE_LLWU_HAS_NO_INTERNAL_MODULE_WAKEUP_FLAG_REG (0)
    /* @brief Has external pin 0 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN0 (1)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN0_GPIO_IDX (GPIOE_IDX)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN0_GPIO_PIN (1)
    /* @brief Has external pin 1 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN1 (1)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN1_GPIO_IDX (GPIOE_IDX)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN1_GPIO_PIN (2)
    /* @brief Has external pin 2 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN2 (1)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN2_GPIO_IDX (GPIOE_IDX)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN2_GPIO_PIN (4)
    /* @brief Has external pin 3 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN3 (1)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN3_GPIO_IDX (GPIOA_IDX)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN3_GPIO_PIN (4)
    /* @brief Has external pin 4 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN4 (1)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN4_GPIO_IDX (GPIOA_IDX)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN4_GPIO_PIN (13)
    /* @brief Has external pin 5 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN5 (1)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN5_GPIO_IDX (GPIOB_IDX)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN5_GPIO_PIN (0)
    /* @brief Has external pin 6 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN6 (1)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN6_GPIO_IDX (GPIOC_IDX)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN6_GPIO_PIN (1)
    /* @brief Has external pin 7 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN7 (1)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN7_GPIO_IDX (GPIOC_IDX)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN7_GPIO_PIN (3)
    /* @brief Has external pin 8 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN8 (1)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN8_GPIO_IDX (GPIOC_IDX)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN8_GPIO_PIN (4)
    /* @brief Has external pin 9 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN9 (1)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN9_GPIO_IDX (GPIOC_IDX)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN9_GPIO_PIN (5)
    /* @brief Has external pin 10 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN10 (1)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN10_GPIO_IDX (GPIOC_IDX)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN10_GPIO_PIN (6)
    /* @brief Has external pin 11 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN11 (1)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN11_GPIO_IDX (GPIOC_IDX)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN11_GPIO_PIN (11)
    /* @brief Has external pin 12 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN12 (1)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN12_GPIO_IDX (GPIOD_IDX)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN12_GPIO_PIN (0)
    /* @brief Has external pin 13 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN13 (1)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN13_GPIO_IDX (GPIOD_IDX)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN13_GPIO_PIN (2)
    /* @brief Has external pin 14 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN14 (1)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN14_GPIO_IDX (GPIOD_IDX)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN14_GPIO_PIN (4)
    /* @brief Has external pin 15 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN15 (1)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN15_GPIO_IDX (GPIOD_IDX)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN15_GPIO_PIN (6)
    /* @brief Has external pin 16 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN16 (1)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN16_GPIO_IDX (GPIOE_IDX)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN16_GPIO_PIN (6)
    /* @brief Has external pin 17 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN17 (0)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN17_GPIO_IDX (0)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN17_GPIO_PIN (0)
    /* @brief Has external pin 18 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN18 (0)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN18_GPIO_IDX (0)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN18_GPIO_PIN (0)
    /* @brief Has external pin 19 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN19 (1)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN19_GPIO_IDX (GPIOE_IDX)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN19_GPIO_PIN (17)
    /* @brief Has external pin 20 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN20 (1)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN20_GPIO_IDX (GPIOE_IDX)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN20_GPIO_PIN (18)
    /* @brief Has external pin 21 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN21 (1)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN21_GPIO_IDX (GPIOE_IDX)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN21_GPIO_PIN (25)
    /* @brief Has external pin 22 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN22 (0)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN22_GPIO_IDX (0)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN22_GPIO_PIN (0)
    /* @brief Has external pin 23 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN23 (0)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN23_GPIO_IDX (0)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN23_GPIO_PIN (0)
    /* @brief Has external pin 24 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN24 (0)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN24_GPIO_IDX (0)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN24_GPIO_PIN (0)
    /* @brief Has external pin 25 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN25 (0)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN25_GPIO_IDX (0)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN25_GPIO_PIN (0)
    /* @brief Has external pin 26 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN26 (0)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN26_GPIO_IDX (0)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN26_GPIO_PIN (0)
    /* @brief Has external pin 27 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN27 (0)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN27_GPIO_IDX (0)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN27_GPIO_PIN (0)
    /* @brief Has external pin 28 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN28 (0)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN28_GPIO_IDX (0)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN28_GPIO_PIN (0)
    /* @brief Has external pin 29 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN29 (0)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN29_GPIO_IDX (0)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN29_GPIO_PIN (0)
    /* @brief Has external pin 30 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN30 (0)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN30_GPIO_IDX (0)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN30_GPIO_PIN (0)
    /* @brief Has external pin 31 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN31 (0)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN31_GPIO_IDX (0)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN31_GPIO_PIN (0)
    /* @brief Has internal module 0 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_INTERNAL_MODULE0 (1)
    /* @brief Has internal module 1 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_INTERNAL_MODULE1 (1)
    /* @brief Has internal module 2 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_INTERNAL_MODULE2 (1)
    /* @brief Has internal module 3 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_INTERNAL_MODULE3 (1)
    /* @brief Has internal module 4 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_INTERNAL_MODULE4 (0)
    /* @brief Has internal module 5 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_INTERNAL_MODULE5 (0)
    /* @brief Has internal module 6 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_INTERNAL_MODULE6 (0)
    /* @brief Has internal module 7 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_INTERNAL_MODULE7 (0)
    /* @brief Has Version ID Register (LLWU_VERID). */
    #define FSL_FEATURE_LLWU_HAS_VERID (0)
    /* @brief Has Parameter Register (LLWU_PARAM). */
    #define FSL_FEATURE_LLWU_HAS_PARAM (0)
    /* @brief Width of registers of the LLWU. */
    #define FSL_FEATURE_LLWU_REG_BITWIDTH (8)
    /* @brief Has DMA Enable register (LLWU_DE). */
    #define FSL_FEATURE_LLWU_HAS_DMA_ENABLE_REG (0)
#elif defined(CPU_MKV58F1M0VLQ24) || defined(CPU_MKV58F1M0VMD24) || defined(CPU_MKV58F512VLQ24) || defined(CPU_MKV58F512VMD24)
    /* @brief Maximum number of pins (maximal index plus one) connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN (26)
    /* @brief Has pins 8-15 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_EXTERNAL_PIN_GROUP2 (1)
    /* @brief Maximum number of internal modules connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_INTERNAL_MODULE (4)
    /* @brief Number of digital filters. */
    #define FSL_FEATURE_LLWU_HAS_PIN_FILTER (2)
    /* @brief Has MF register. */
    #define FSL_FEATURE_LLWU_HAS_MF (1)
    /* @brief Has PF register. */
    #define FSL_FEATURE_LLWU_HAS_PF (1)
    /* @brief Has possibility to enable reset in low leakage power mode and enable digital filter for RESET pin (register LLWU_RST). */
    #define FSL_FEATURE_LLWU_HAS_RESET_ENABLE (0)
    /* @brief Has no internal module wakeup flag register. */
    #define FSL_FEATURE_LLWU_HAS_NO_INTERNAL_MODULE_WAKEUP_FLAG_REG (0)
    /* @brief Has external pin 0 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN0 (1)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN0_GPIO_IDX (GPIOE_IDX)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN0_GPIO_PIN (1)
    /* @brief Has external pin 1 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN1 (1)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN1_GPIO_IDX (GPIOE_IDX)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN1_GPIO_PIN (2)
    /* @brief Has external pin 2 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN2 (1)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN2_GPIO_IDX (GPIOE_IDX)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN2_GPIO_PIN (4)
    /* @brief Has external pin 3 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN3 (1)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN3_GPIO_IDX (GPIOA_IDX)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN3_GPIO_PIN (4)
    /* @brief Has external pin 4 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN4 (1)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN4_GPIO_IDX (GPIOA_IDX)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN4_GPIO_PIN (13)
    /* @brief Has external pin 5 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN5 (1)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN5_GPIO_IDX (GPIOB_IDX)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN5_GPIO_PIN (0)
    /* @brief Has external pin 6 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN6 (1)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN6_GPIO_IDX (GPIOC_IDX)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN6_GPIO_PIN (1)
    /* @brief Has external pin 7 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN7 (1)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN7_GPIO_IDX (GPIOC_IDX)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN7_GPIO_PIN (3)
    /* @brief Has external pin 8 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN8 (1)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN8_GPIO_IDX (GPIOC_IDX)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN8_GPIO_PIN (4)
    /* @brief Has external pin 9 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN9 (1)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN9_GPIO_IDX (GPIOC_IDX)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN9_GPIO_PIN (5)
    /* @brief Has external pin 10 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN10 (1)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN10_GPIO_IDX (GPIOC_IDX)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN10_GPIO_PIN (6)
    /* @brief Has external pin 11 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN11 (1)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN11_GPIO_IDX (GPIOC_IDX)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN11_GPIO_PIN (11)
    /* @brief Has external pin 12 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN12 (1)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN12_GPIO_IDX (GPIOD_IDX)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN12_GPIO_PIN (0)
    /* @brief Has external pin 13 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN13 (1)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN13_GPIO_IDX (GPIOD_IDX)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN13_GPIO_PIN (2)
    /* @brief Has external pin 14 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN14 (1)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN14_GPIO_IDX (GPIOD_IDX)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN14_GPIO_PIN (4)
    /* @brief Has external pin 15 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN15 (1)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN15_GPIO_IDX (GPIOD_IDX)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN15_GPIO_PIN (6)
    /* @brief Has external pin 16 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN16 (1)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN16_GPIO_IDX (GPIOE_IDX)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN16_GPIO_PIN (6)
    /* @brief Has external pin 17 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN17 (1)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN17_GPIO_IDX (GPIOE_IDX)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN17_GPIO_PIN (9)
    /* @brief Has external pin 18 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN18 (1)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN18_GPIO_IDX (GPIOE_IDX)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN18_GPIO_PIN (10)
    /* @brief Has external pin 19 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN19 (1)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN19_GPIO_IDX (GPIOE_IDX)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN19_GPIO_PIN (17)
    /* @brief Has external pin 20 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN20 (1)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN20_GPIO_IDX (GPIOE_IDX)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN20_GPIO_PIN (18)
    /* @brief Has external pin 21 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN21 (1)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN21_GPIO_IDX (GPIOE_IDX)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN21_GPIO_PIN (25)
    /* @brief Has external pin 22 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN22 (1)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN22_GPIO_IDX (GPIOA_IDX)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN22_GPIO_PIN (10)
    /* @brief Has external pin 23 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN23 (1)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN23_GPIO_IDX (GPIOA_IDX)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN23_GPIO_PIN (11)
    /* @brief Has external pin 24 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN24 (1)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN24_GPIO_IDX (GPIOD_IDX)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN24_GPIO_PIN (8)
    /* @brief Has external pin 25 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN25 (1)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN25_GPIO_IDX (GPIOD_IDX)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN25_GPIO_PIN (11)
    /* @brief Has external pin 26 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN26 (0)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN26_GPIO_IDX (0)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN26_GPIO_PIN (0)
    /* @brief Has external pin 27 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN27 (0)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN27_GPIO_IDX (0)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN27_GPIO_PIN (0)
    /* @brief Has external pin 28 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN28 (0)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN28_GPIO_IDX (0)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN28_GPIO_PIN (0)
    /* @brief Has external pin 29 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN29 (0)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN29_GPIO_IDX (0)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN29_GPIO_PIN (0)
    /* @brief Has external pin 30 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN30 (0)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN30_GPIO_IDX (0)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN30_GPIO_PIN (0)
    /* @brief Has external pin 31 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_EXTERNAL_PIN31 (0)
    /* @brief Index of port of external pin. */
    #define FSL_FEATURE_LLWU_PIN31_GPIO_IDX (0)
    /* @brief Number of external pin port on specified port. */
    #define FSL_FEATURE_LLWU_PIN31_GPIO_PIN (0)
    /* @brief Has internal module 0 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_INTERNAL_MODULE0 (1)
    /* @brief Has internal module 1 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_INTERNAL_MODULE1 (1)
    /* @brief Has internal module 2 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_INTERNAL_MODULE2 (1)
    /* @brief Has internal module 3 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_INTERNAL_MODULE3 (1)
    /* @brief Has internal module 4 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_INTERNAL_MODULE4 (0)
    /* @brief Has internal module 5 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_INTERNAL_MODULE5 (0)
    /* @brief Has internal module 6 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_INTERNAL_MODULE6 (0)
    /* @brief Has internal module 7 connected to LLWU device. */
    #define FSL_FEATURE_LLWU_HAS_INTERNAL_MODULE7 (0)
    /* @brief Has Version ID Register (LLWU_VERID). */
    #define FSL_FEATURE_LLWU_HAS_VERID (0)
    /* @brief Has Parameter Register (LLWU_PARAM). */
    #define FSL_FEATURE_LLWU_HAS_PARAM (0)
    /* @brief Width of registers of the LLWU. */
    #define FSL_FEATURE_LLWU_REG_BITWIDTH (8)
    /* @brief Has DMA Enable register (LLWU_DE). */
    #define FSL_FEATURE_LLWU_HAS_DMA_ENABLE_REG (0)
#endif /* defined(CPU_MKV58F1M0VLL24) || defined(CPU_MKV58F512VLL24) */

/* LPTMR module features */

/* @brief Has shared interrupt handler with another LPTMR module. */
#define FSL_FEATURE_LPTMR_HAS_SHARED_IRQ_HANDLER (0)
/* @brief Whether LPTMR counter is 32 bits width. */
#define FSL_FEATURE_LPTMR_CNR_WIDTH_IS_32B (0)
/* @brief Has timer DMA request enable (register bit CSR[TDRE]). */
#define FSL_FEATURE_LPTMR_HAS_CSR_TDRE (0)

/* MCG module features */

/* @brief PRDIV base value (divider of register bit field [PRDIV] zero value). */
#define FSL_FEATURE_MCG_PLL_PRDIV_BASE (1)
/* @brief Maximum PLL external reference divider value (max. value of register bit field C5[PRVDIV]). */
#define FSL_FEATURE_MCG_PLL_PRDIV_MAX (7)
/* @brief VCO divider base value (multiply factor of register bit field C6[VDIV] zero value). */
#define FSL_FEATURE_MCG_PLL_VDIV_BASE (16)
/* @brief PLL reference clock low range. OSCCLK/PLL_R. */
#define FSL_FEATURE_MCG_PLL_REF_MIN (8000000)
/* @brief PLL reference clock high range. OSCCLK/PLL_R. */
#define FSL_FEATURE_MCG_PLL_REF_MAX (16000000)
/* @brief The PLL clock is divided by 2 before VCO divider. */
#define FSL_FEATURE_MCG_HAS_PLL_INTERNAL_DIV (1)
/* @brief FRDIV supports 1280. */
#define FSL_FEATURE_MCG_FRDIV_SUPPORT_1280 (1)
/* @brief FRDIV supports 1536. */
#define FSL_FEATURE_MCG_FRDIV_SUPPORT_1536 (1)
/* @brief MCGFFCLK divider. */
#define FSL_FEATURE_MCG_FFCLK_DIV (1)
/* @brief Is PLL clock divided by 2 before MCG PLL/FLL clock selection in the SIM module. */
#define FSL_FEATURE_MCG_HAS_PLL_EXTRA_DIV (1)
/* @brief Has 32kHz RTC external reference clock (register bits C8[LOCS1], C8[CME1], C8[LOCRE1] and RTC module are present). */
#define FSL_FEATURE_MCG_HAS_RTC_32K (0)
/* @brief Has PLL1 external reference clock (registers C10, C11, C12, S2). */
#define FSL_FEATURE_MCG_HAS_PLL1 (0)
/* @brief Has 48MHz internal oscillator. */
#define FSL_FEATURE_MCG_HAS_IRC_48M (0)
/* @brief Has OSC1 external oscillator (registers C10, C11, C12, S2). */
#define FSL_FEATURE_MCG_HAS_OSC1 (0)
/* @brief Has fast internal reference clock fine trim (register bit C2[FCFTRIM]). */
#define FSL_FEATURE_MCG_HAS_FCFTRIM (1)
/* @brief Has PLL loss of lock reset (register bit C8[LOLRE]). */
#define FSL_FEATURE_MCG_HAS_LOLRE (1)
/* @brief Has MCG OSC clock selection (register bit C7[OSCSEL]). */
#define FSL_FEATURE_MCG_USE_OSCSEL (0)
/* @brief Has PLL external reference selection (register bits C5[PLLREFSEL0] and C11[PLLREFSEL1]). */
#define FSL_FEATURE_MCG_USE_PLLREFSEL (0)
/* @brief TBD */
#define FSL_FEATURE_MCG_USE_SYSTEM_CLOCK (0)
/* @brief Has phase-locked loop (PLL) (register C5 and bits C6[VDIV], C6[PLLS], C6[LOLIE0], S[PLLST], S[LOCK0], S[LOLS0]). */
#define FSL_FEATURE_MCG_HAS_PLL (1)
/* @brief Has phase-locked loop (PLL) PRDIV (register C5[PRDIV]. */
#define FSL_FEATURE_MCG_HAS_PLL_PRDIV (1)
/* @brief Has phase-locked loop (PLL) VDIV (register C6[VDIV]. */
#define FSL_FEATURE_MCG_HAS_PLL_VDIV (1)
/* @brief PLL/OSC related register bit fields have PLL/OSC index in their name. */
#define FSL_FEATURE_MCG_HAS_PLL_OSC_INDEX (0)
/* @brief Has frequency-locked loop (FLL) (register ATCVH, ATCVL and bits C1[IREFS], C1[FRDIV]). */
#define FSL_FEATURE_MCG_HAS_FLL (1)
/* @brief Has PLL external to MCG (C9[PLL_CME], C9[PLL_LOCRE], C9[EXT_PLL_LOCS]). */
#define FSL_FEATURE_MCG_HAS_EXTERNAL_PLL (0)
/* @brief Has crystal oscillator or external reference clock low power controls (register bits C2[HGO], C2[RANGE]). */
#define FSL_FEATURE_MCG_HAS_EXT_REF_LOW_POWER_CONTROL (1)
/* @brief Has PLL/FLL selection as MCG output (register bit C6[PLLS]). */
#define FSL_FEATURE_MCG_HAS_PLL_FLL_SELECTION (1)
/* @brief Has PLL output selection (PLL0/PLL1, PLL/external PLL) (register bit C11[PLLCS]). */
#define FSL_FEATURE_MCG_HAS_PLL_OUTPUT_SELECTION (0)
/* @brief Has automatic trim machine (registers ATCVH, ATCVL and bits SC[ATMF], SC[ATMS], SC[ATME]). */
#define FSL_FEATURE_MCG_HAS_AUTO_TRIM_MACHINE (1)
/* @brief Has external clock monitor (register bit C6[CME]). */
#define FSL_FEATURE_MCG_HAS_EXTERNAL_CLOCK_MONITOR (1)
/* @brief Has low frequency internal reference clock (IRC) (registers LTRIMRNG, LFRIM, LSTRIM and bit MC[LIRC_DIV2]). */
#define FSL_FEATURE_MCG_HAS_LOW_FREQ_IRC (0)
/* @brief Has high frequency internal reference clock (IRC) (registers HCTRIM, HTTRIM, HFTRIM and bit MC[HIRCEN]). */
#define FSL_FEATURE_MCG_HAS_HIGH_FREQ_IRC (0)
/* @brief Has PEI mode or PBI mode. */
#define FSL_FEATURE_MCG_HAS_PLL_INTERNAL_MODE (0)
/* @brief Reset clock mode is BLPI. */
#define FSL_FEATURE_MCG_RESET_IS_BLPI (0)

/* MSCM module features */

/* @brief Number of configuration information for processors. */
#define FSL_FEATURE_MSCM_HAS_CP_COUNT (2)
/* @brief Has data cache. */
#define FSL_FEATURE_MSCM_HAS_DATACACHE (0)

/* interrupt module features */

/* @brief Lowest interrupt request number. */
#define FSL_FEATURE_INTERRUPT_IRQ_MIN (-14)
/* @brief Highest interrupt request number. */
#define FSL_FEATURE_INTERRUPT_IRQ_MAX (120)

/* OSC module features */

/* @brief Has OSC1 external oscillator. */
#define FSL_FEATURE_OSC_HAS_OSC1 (0)
/* @brief Has OSC0 external oscillator. */
#define FSL_FEATURE_OSC_HAS_OSC0 (0)
/* @brief Has OSC external oscillator (without index). */
#define FSL_FEATURE_OSC_HAS_OSC (0)
/* @brief Number of OSC external oscillators. */
#define FSL_FEATURE_OSC_OSC_COUNT (0)
/* @brief Has external reference clock divider (register bit field DIV[ERPS]). */
#define FSL_FEATURE_OSC_HAS_EXT_REF_CLOCK_DIVIDER (1)

/* PDB module features */

/* @brief Has DAC support. */
#define FSL_FEATURE_PDB_HAS_DAC (1)
/* @brief Has shared interrupt handler (has not individual interrupt handler for each channel). */
#define FSL_FEATURE_PDB_HAS_SHARED_IRQ_HANDLER (0)
/* @brief PDB channel number). */
#define FSL_FEATURE_PDB_CHANNEL_COUNT (2)
/* @brief Channel pre-trigger nunmber (related to number of registers CHmDLYn). */
#define FSL_FEATURE_PDB_CHANNEL_PRE_TRIGGER_COUNT (2)
/* @brief DAC interval trigger number). */
#define FSL_FEATURE_PDB_DAC_INTERVAL_TRIGGER_COUNT (1)
/* @brief Pulse out number). */
#define FSL_FEATURE_PDB_PULSE_OUT_COUNT (2)

/* PIT module features */

/* @brief Number of channels (related to number of registers LDVALn, CVALn, TCTRLn, TFLGn). */
#define FSL_FEATURE_PIT_TIMER_COUNT (4)
/* @brief Has lifetime timer (related to existence of registers LTMR64L and LTMR64H). */
#define FSL_FEATURE_PIT_HAS_LIFETIME_TIMER (1)
/* @brief Has chain mode (related to existence of register bit field TCTRLn[CHN]). */
#define FSL_FEATURE_PIT_HAS_CHAIN_MODE (1)
/* @brief Has shared interrupt handler (has not individual interrupt handler for each channel). */
#define FSL_FEATURE_PIT_HAS_SHARED_IRQ_HANDLER (0)
/* @brief Has timer enable control. */
#define FSL_FEATURE_PIT_HAS_MDIS (1)

/* PMC module features */

/* @brief Has Bandgap Enable In VLPx Operation support. */
#define FSL_FEATURE_PMC_HAS_BGEN (1)
/* @brief Has Bandgap Buffer Enable. */
#define FSL_FEATURE_PMC_HAS_BGBE (1)
/* @brief Has Bandgap Buffer Drive Select. */
#define FSL_FEATURE_PMC_HAS_BGBDS (0)
/* @brief Has Low-Voltage Detect Voltage Select support. */
#define FSL_FEATURE_PMC_HAS_LVDV (1)
/* @brief Has Low-Voltage Warning Voltage Select support. */
#define FSL_FEATURE_PMC_HAS_LVWV (1)
/* @brief Has LPO. */
#define FSL_FEATURE_PMC_HAS_LPO (0)
/* @brief Has VLPx option PMC_REGSC[VLPO]. */
#define FSL_FEATURE_PMC_HAS_VLPO (0)
/* @brief Has acknowledge isolation support. */
#define FSL_FEATURE_PMC_HAS_ACKISO (1)
/* @brief Has Regulator In Full Performance Mode Status Bit PMC_REGSC[REGFPM]. */
#define FSL_FEATURE_PMC_HAS_REGFPM (0)
/* @brief Has Regulator In Run Regulation Status Bit PMC_REGSC[REGONS]. */
#define FSL_FEATURE_PMC_HAS_REGONS (1)
/* @brief Has PMC_HVDSC1. */
#define FSL_FEATURE_PMC_HAS_HVDSC1 (1)
/* @brief Has PMC_PARAM. */
#define FSL_FEATURE_PMC_HAS_PARAM (0)
/* @brief Has PMC_VERID. */
#define FSL_FEATURE_PMC_HAS_VERID (0)

/* PORT module features */

/* @brief Has control lock (register bit PCR[LK]). */
#define FSL_FEATURE_PORT_HAS_PIN_CONTROL_LOCK (1)
/* @brief Has open drain control (register bit PCR[ODE]). */
#define FSL_FEATURE_PORT_HAS_OPEN_DRAIN (1)
/* @brief Has digital filter (registers DFER, DFCR and DFWR). */
#define FSL_FEATURE_PORT_HAS_DIGITAL_FILTER (1)
/* @brief Has DMA request (register bit field PCR[IRQC] values). */
#define FSL_FEATURE_PORT_HAS_DMA_REQUEST (1)
/* @brief Has pull resistor selection available. */
#define FSL_FEATURE_PORT_HAS_PULL_SELECTION (1)
/* @brief Has pull resistor enable (register bit PCR[PE]). */
#define FSL_FEATURE_PORT_HAS_PULL_ENABLE (1)
/* @brief Has slew rate control (register bit PCR[SRE]). */
#define FSL_FEATURE_PORT_HAS_SLEW_RATE (1)
/* @brief Has passive filter (register bit field PCR[PFE]). */
#define FSL_FEATURE_PORT_HAS_PASSIVE_FILTER (1)
/* @brief Has drive strength control (register bit PCR[DSE]). */
#define FSL_FEATURE_PORT_HAS_DRIVE_STRENGTH (1)
/* @brief Has separate drive strength register (HDRVE). */
#define FSL_FEATURE_PORT_HAS_DRIVE_STRENGTH_REGISTER (0)
/* @brief Has glitch filter (register IOFLT). */
#define FSL_FEATURE_PORT_HAS_GLITCH_FILTER (0)
/* @brief Defines width of PCR[MUX] field. */
#define FSL_FEATURE_PORT_PCR_MUX_WIDTH (4)
/* @brief Has dedicated interrupt vector. */
#define FSL_FEATURE_PORT_HAS_INTERRUPT_VECTOR (1)
/* @brief Has multiple pin IRQ configuration (register GICLR and GICHR). */
#define FSL_FEATURE_PORT_HAS_MULTIPLE_IRQ_CONFIG (0)
/* @brief Defines whether PCR[IRQC] bit-field has flag states. */
#define FSL_FEATURE_PORT_HAS_IRQC_FLAG (0)
/* @brief Defines whether PCR[IRQC] bit-field has trigger states. */
#define FSL_FEATURE_PORT_HAS_IRQC_TRIGGER (0)

/* PWM module features */

/* @brief If EflexPWM has module A channels (outputs). */
#define FSL_FEATURE_PWM_HAS_CHANNELA (1)
/* @brief If EflexPWM has module B channels (outputs). */
#define FSL_FEATURE_PWM_HAS_CHANNELB (1)
/* @brief If EflexPWM has module X channels (outputs). */
#define FSL_FEATURE_PWM_HAS_CHANNELX (1)
/* @brief Number of submodules in each EflexPWM module. */
#define FSL_FEATURE_PWM_SUBMODULE_COUNT (4U)

/* RCM module features */

/* @brief Has Loss-of-Lock Reset support. */
#define FSL_FEATURE_RCM_HAS_LOL (1)
/* @brief Has Loss-of-Clock Reset support. */
#define FSL_FEATURE_RCM_HAS_LOC (1)
/* @brief Has JTAG generated Reset support. */
#define FSL_FEATURE_RCM_HAS_JTAG (1)
/* @brief Has EzPort generated Reset support. */
#define FSL_FEATURE_RCM_HAS_EZPORT (0)
/* @brief Has bit-field indicating EZP_MS_B pin state during last reset. */
#define FSL_FEATURE_RCM_HAS_EZPMS (0)
/* @brief Has boot ROM configuration, MR[BOOTROM], FM[FORCEROM] */
#define FSL_FEATURE_RCM_HAS_BOOTROM (0)
/* @brief Has sticky system reset status register RCM_SSRS0 and RCM_SSRS1. */
#define FSL_FEATURE_RCM_HAS_SSRS (1)
/* @brief Has Version ID Register (RCM_VERID). */
#define FSL_FEATURE_RCM_HAS_VERID (0)
/* @brief Has Parameter Register (RCM_PARAM). */
#define FSL_FEATURE_RCM_HAS_PARAM (0)
/* @brief Has Reset Interrupt Enable Register RCM_SRIE. */
#define FSL_FEATURE_RCM_HAS_SRIE (0)
/* @brief Width of registers of the RCM. */
#define FSL_FEATURE_RCM_REG_WIDTH (8)
/* @brief Has Core 1 generated Reset support RCM_SRS[CORE1] */
#define FSL_FEATURE_RCM_HAS_CORE1 (0)
/* @brief Has MDM-AP system reset support RCM_SRS1[MDM_AP] */
#define FSL_FEATURE_RCM_HAS_MDM_AP (1)
/* @brief Has wakeup reset feature. Register bit SRS[WAKEUP]. */
#define FSL_FEATURE_RCM_HAS_WAKEUP (1)

/* SIM module features */

/* @brief Has USB FS divider. */
#define FSL_FEATURE_SIM_USBFS_USE_SPECIAL_DIVIDER (0)
/* @brief Is PLL clock divided by 2 before MCG PLL/FLL clock selection. */
#define FSL_FEATURE_SIM_PLLCLK_USE_SPECIAL_DIVIDER (0)
/* @brief Has RAM size specification (register bit field SOPT1[RAMSIZE]). */
#define FSL_FEATURE_SIM_OPT_HAS_RAMSIZE (1)
/* @brief Has 32k oscillator clock output (register bit SOPT1[OSC32KOUT]). */
#define FSL_FEATURE_SIM_OPT_HAS_OSC32K_OUT (0)
/* @brief Has 32k oscillator clock selection (register bit field SOPT1[OSC32KSEL]). */
#define FSL_FEATURE_SIM_OPT_HAS_OSC32K_SELECTION (1)
/* @brief 32k oscillator clock selection width (width of register bit field SOPT1[OSC32KSEL]). */
#define FSL_FEATURE_SIM_OPT_OSC32K_SELECTION_WIDTH (2)
/* @brief Has RTC clock output selection (register bit SOPT2[RTCCLKOUTSEL]). */
#define FSL_FEATURE_SIM_OPT_HAS_RTC_CLOCK_OUT_SELECTION (0)
/* @brief Has USB voltage regulator (register bits SOPT1[USBVSTBY], SOPT1[USBSSTBY], SOPT1[USBREGEN], SOPT1CFG[URWE], SOPT1CFG[UVSWE], SOPT1CFG[USSWE]). */
#define FSL_FEATURE_SIM_OPT_HAS_USB_VOLTAGE_REGULATOR (0)
/* @brief USB has integrated PHY (register bits USBPHYCTL[USBVREGSEL], USBPHYCTL[USBVREGPD], USBPHYCTL[USB3VOUTTRG], USBPHYCTL[USBDISILIM], SOPT2[USBSLSRC], SOPT2[USBREGEN]). */
#define FSL_FEATURE_SIM_OPT_HAS_USB_PHY (0)
/* @brief Has PTD7 pad drive strength control (register bit SOPT2[PTD7PAD]). */
#define FSL_FEATURE_SIM_OPT_HAS_PTD7PAD (0)
/* @brief Has FlexBus security level selection (register bit SOPT2[FBSL]). */
#define FSL_FEATURE_SIM_OPT_HAS_FBSL (1)
/* @brief Has number of FlexBus hold cycle before FlexBus can release bus (register bit SOPT6[PCR]). */
#define FSL_FEATURE_SIM_OPT_HAS_PCR (0)
/* @brief Has number of NFC hold cycle in case of FlexBus request (register bit SOPT6[MCC]). */
#define FSL_FEATURE_SIM_OPT_HAS_MCC (0)
/* @brief Has UART open drain enable (register bits UARTnODE, where n is a number, in register SOPT5). */
#define FSL_FEATURE_SIM_OPT_HAS_ODE (0)
/* @brief Number of LPUART modules (number of register bits LPUARTn, where n is a number, in register SCGC5). */
#define FSL_FEATURE_SIM_OPT_LPUART_COUNT (0)
/* @brief Number of UART modules (number of register bits UARTn, where n is a number, in register SCGC4). */
#define FSL_FEATURE_SIM_OPT_UART_COUNT (4)
/* @brief Has UART0 open drain enable (register bit SOPT5[UART0ODE]). */
#define FSL_FEATURE_SIM_OPT_HAS_UART0_ODE (0)
/* @brief Has UART1 open drain enable (register bit SOPT5[UART1ODE]). */
#define FSL_FEATURE_SIM_OPT_HAS_UART1_ODE (0)
/* @brief Has UART2 open drain enable (register bit SOPT5[UART2ODE]). */
#define FSL_FEATURE_SIM_OPT_HAS_UART2_ODE (0)
/* @brief Has LPUART0 open drain enable (register bit SOPT5[LPUART0ODE]). */
#define FSL_FEATURE_SIM_OPT_HAS_LPUART0_ODE (0)
/* @brief Has LPUART1 open drain enable (register bit SOPT5[LPUART1ODE]). */
#define FSL_FEATURE_SIM_OPT_HAS_LPUART1_ODE (0)
/* @brief Has CMT/UART pad drive strength control (register bit SOPT2[CMTUARTPAD]). */
#define FSL_FEATURE_SIM_OPT_HAS_CMTUARTPAD (0)
/* @brief Has LPUART0 transmit data source selection (register bit SOPT5[LPUART0TXSRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_LPUART0_TX_SRC (0)
/* @brief Has LPUART0 receive data source selection (register bit SOPT5[LPUART0RXSRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_LPUART0_RX_SRC (0)
/* @brief Has LPUART1 transmit data source selection (register bit SOPT5[LPUART1TXSRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_LPUART1_TX_SRC (0)
/* @brief Has LPUART1 receive data source selection (register bit SOPT5[LPUART1RXSRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_LPUART1_RX_SRC (0)
/* @brief Has UART0 transmit data source selection (register bit SOPT5[UART0TXSRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_UART0_TX_SRC (1)
/* @brief UART0 transmit data source selection width (width of register bit SOPT5[UART0TXSRC]). */
#define FSL_FEATURE_SIM_OPT_UART0_TX_SRC_WIDTH (2)
/* @brief Has UART0 receive data source selection (register bit SOPT5[UART0RXSRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_UART0_RX_SRC (1)
/* @brief UART0 receive data source selection width (width of register bit SOPT5[UART0RXSRC]). */
#define FSL_FEATURE_SIM_OPT_UART0_RX_SRC_WIDTH (2)
/* @brief Has UART1 transmit data source selection (register bit SOPT5[UART1TXSRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_UART1_TX_SRC (1)
/* @brief Has UART1 receive data source selection (register bit SOPT5[UART1RXSRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_UART1_RX_SRC (1)
/* @brief UART1 receive data source selection width (width of register bit SOPT5[UART1RXSRC]). */
#define FSL_FEATURE_SIM_OPT_UART1_RX_SRC_WIDTH (2)
/* @brief Has FTM module(s) configuration. */
#define FSL_FEATURE_SIM_OPT_HAS_FTM (1)
/* @brief Number of FTM modules. */
#define FSL_FEATURE_SIM_OPT_FTM_COUNT (3)
/* @brief Number of FTM triggers with selectable source. */
#define FSL_FEATURE_SIM_OPT_FTM_TRIGGER_COUNT (3)
/* @brief Has FTM0 triggers source selection (register bits SOPT4[FTM0TRGnSRC], where n is a number). */
#define FSL_FEATURE_SIM_OPT_HAS_FTM0_TRIGGER (1)
/* @brief Has FTM3 triggers source selection (register bits SOPT4[FTM3TRGnSRC], where n is a number). */
#define FSL_FEATURE_SIM_OPT_HAS_FTM3_TRIGGER (1)
/* @brief Has FTM1 channel 0 input capture source selection (register bit SOPT4[FTM1CH0SRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_FTM1_CHANNELS (0)
/* @brief Has FTM2 channel 0 input capture source selection (register bit SOPT4[FTM2CH0SRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_FTM2_CHANNELS (0)
/* @brief Has FTM3 channel 0 input capture source selection (register bit SOPT4[FTM3CH0SRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_FTM3_CHANNELS (0)
/* @brief Has FTM2 channel 1 input capture source selection (register bit SOPT4[FTM2CH1SRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_FTM2_CHANNEL1 (0)
/* @brief Number of configurable FTM0 fault detection input (number of register bits SOPT4[FTM0FLTn], where n is a number starting from zero). */
#define FSL_FEATURE_SIM_OPT_FTM0_FAULT_COUNT (4)
/* @brief Number of configurable FTM1 fault detection input (number of register bits SOPT4[FTM1FLTn], where n is a number starting from zero). */
#define FSL_FEATURE_SIM_OPT_FTM1_FAULT_COUNT (1)
/* @brief Number of configurable FTM2 fault detection input (number of register bits SOPT4[FTM2FLTn], where n is a number starting from zero). */
#define FSL_FEATURE_SIM_OPT_FTM2_FAULT_COUNT (1)
/* @brief Number of configurable FTM3 fault detection input (number of register bits SOPT4[FTM3FLTn], where n is a number starting from zero). */
#define FSL_FEATURE_SIM_OPT_FTM3_FAULT_COUNT (1)
/* @brief Has FTM hardware trigger 0 software synchronization (register bit SOPT8[FTMnSYNCBIT], where n is a module instance index). */
#define FSL_FEATURE_SIM_OPT_HAS_FTM_TRIGGER_SYNC (1)
/* @brief Has FTM channels output source selection (register bit SOPT8[FTMxOCHnSRC], where x is a module instance index and n is a channel index). */
#define FSL_FEATURE_SIM_OPT_HAS_FTM_CHANNELS_OUTPUT_SRC (1)
/* @brief Has TPM module(s) configuration. */
#define FSL_FEATURE_SIM_OPT_HAS_TPM (0)
/* @brief The highest TPM module index. */
#define FSL_FEATURE_SIM_OPT_MAX_TPM_INDEX (0)
/* @brief Has TPM module with index 0. */
#define FSL_FEATURE_SIM_OPT_HAS_TPM0 (0)
/* @brief Has TPM0 clock selection (register bit field SOPT4[TPM0CLKSEL]). */
#define FSL_FEATURE_SIM_OPT_HAS_TPM0_CLK_SEL (0)
/* @brief Is TPM channels configuration in the SOPT4 (not SOPT9) register (register bits TPMnCH0SRC, TPMnCLKSEL, where n is a module instance index). */
#define FSL_FEATURE_SIM_OPT_HAS_TPM_CHANNELS_CONFIG_IN_SOPT4_REG (0)
/* @brief Has TPM1 channel 0 input capture source selection (register bit field SOPT4[TPM1CH0SRC] or SOPT9[TPM1CH0SRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_TPM1_CH0_SRC_SELECTION (0)
/* @brief Has TPM1 clock selection (register bit field SOPT4[TPM1CLKSEL]). */
#define FSL_FEATURE_SIM_OPT_HAS_TPM1_CLK_SEL (0)
/* @brief TPM1 channel 0 input capture source selection width (width of register bit field SOPT4[TPM1CH0SRC] or SOPT9[TPM1CH0SRC]). */
#define FSL_FEATURE_SIM_OPT_TPM1_CH0_SRC_SELECTION_WIDTH (0)
/* @brief Has TPM2 channel 0 input capture source selection (register bit field SOPT4[TPM2CH0SRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_TPM2_CH0_SRC_SELECTION (0)
/* @brief Has TPM2 clock selection (register bit field SOPT4[TPM2CLKSEL]). */
#define FSL_FEATURE_SIM_OPT_HAS_TPM2_CLK_SEL (0)
/* @brief Has PLL/FLL clock selection (register bit field SOPT2[PLLFLLSEL]). */
#define FSL_FEATURE_SIM_OPT_HAS_PLL_FLL_SELECTION (1)
/* @brief PLL/FLL clock selection width (width of register bit field SOPT2[PLLFLLSEL]). */
#define FSL_FEATURE_SIM_OPT_PLL_FLL_SELECTION_WIDTH (1)
/* @brief Has NFC clock source selection (register bit SOPT2[NFCSRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_NFCSRC (0)
/* @brief Has eSDHC clock source selection (register bit SOPT2[ESDHCSRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_ESDHCSRC (0)
/* @brief Has SDHC clock source selection (register bit SOPT2[SDHCSRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_SDHCSRC (0)
/* @brief Has LCDC clock source selection (register bits SOPT2[LCDCSRC], SOPT2[LCDC_CLKSEL]). */
#define FSL_FEATURE_SIM_OPT_HAS_LCDCSRC (0)
/* @brief Has ENET timestamp clock source selection (register bit SOPT2[TIMESRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_TIMESRC (1)
/* @brief Has ENET RMII clock source selection (register bit SOPT2[RMIISRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_RMIISRC (1)
/* @brief Has USB clock source selection (register bit SOPT2[USBSRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_USBSRC (0)
/* @brief Has USB FS clock source selection (register bit SOPT2[USBFSRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_USBFSRC (0)
/* @brief Has USB HS clock source selection (register bit SOPT2[USBHSRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_USBHSRC (0)
/* @brief Has LPUART clock source selection (register bit SOPT2[LPUARTSRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_LPUARTSRC (0)
/* @brief Has LPUART0 clock source selection (register bit SOPT2[LPUART0SRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_LPUART0SRC (0)
/* @brief Has LPUART1 clock source selection (register bit SOPT2[LPUART1SRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_LPUART1SRC (0)
/* @brief Has FLEXIOSRC clock source selection (register bit SOPT2[FLEXIOSRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_FLEXIOSRC (0)
/* @brief Has UART0 clock source selection (register bit SOPT2[UART0SRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_UART0SRC (0)
/* @brief Has TPM clock source selection (register bit SOPT2[TPMSRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_TPMSRC (0)
/* @brief Has debug trace clock selection (register bit SOPT2[TRACECLKSEL]). */
#define FSL_FEATURE_SIM_OPT_HAS_TRACE_CLKSEL (1)
/* @brief Number of ADC modules (register bits SOPT7[ADCnTRGSEL], SOPT7[ADCnPRETRGSEL], SOPT7[ADCnALTTRGSEL], where n is a module instance index). */
#define FSL_FEATURE_SIM_OPT_ADC_COUNT (0)
/* @brief ADC0 alternate trigger enable width (width of bit field ADC0ALTTRGEN of register ADCOPT). */
#define FSL_FEATURE_SIM_OPT_ADC0ALTTRGEN_WIDTH (2)
/* @brief ADC1 alternate trigger enable width (width of bit field ADC1ALTTRGEN of register ADCOPT). */
#define FSL_FEATURE_SIM_OPT_ADC1ALTTRGEN_WIDTH (0)
/* @brief ADC2 alternate trigger enable width (width of bit field ADC2ALTTRGEN of register ADCOPT). */
#define FSL_FEATURE_SIM_OPT_ADC2ALTTRGEN_WIDTH (0)
/* @brief ADC3 alternate trigger enable width (width of bit field ADC3ALTTRGEN of register ADCOPT). */
#define FSL_FEATURE_SIM_OPT_ADC3ALTTRGEN_WIDTH (0)
/* @brief HSADC0 converter A alternate trigger enable width (width of bit field HSADC0AALTTRGEN of register SOPT7). */
#define FSL_FEATURE_SIM_OPT_HSADC0AALTTRGEN_WIDTH (2)
/* @brief HSADC1 converter A alternate trigger enable width (width of bit field HSADC1AALTTRGEN of register SOPT7). */
#define FSL_FEATURE_SIM_OPT_HSADC1AALTTRGEN_WIDTH (2)
/* @brief ADC converter A alternate trigger enable width (width of bit field ADCAALTTRGEN of register SOPT7). */
#define FSL_FEATURE_SIM_OPT_ADCAALTTRGEN_WIDTH (0)
/* @brief HSADC0 converter B alternate trigger enable width (width of bit field HSADC0BALTTRGEN of register SOPT7). */
#define FSL_FEATURE_SIM_OPT_HSADC0BALTTRGEN_WIDTH (2)
/* @brief HSADC1 converter B alternate trigger enable width (width of bit field HSADC1BALTTRGEN of register SOPT7). */
#define FSL_FEATURE_SIM_OPT_HSADC1BALTTRGEN_WIDTH (2)
/* @brief ADC converter B alternate trigger enable width (width of bit field ADCBALTTRGEN of register SOPT7). */
#define FSL_FEATURE_SIM_OPT_ADCBALTTRGEN_WIDTH (0)
/* @brief Has clock 2 output divider (register bit field CLKDIV1[OUTDIV2]). */
#define FSL_FEATURE_SIM_DIVIDER_HAS_OUTDIV2 (1)
/* @brief Has clock 3 output divider (register bit field CLKDIV1[OUTDIV3]). */
#define FSL_FEATURE_SIM_DIVIDER_HAS_OUTDIV3 (1)
/* @brief Has clock 4 output divider (register bit field CLKDIV1[OUTDIV4]). */
#define FSL_FEATURE_SIM_DIVIDER_HAS_OUTDIV4 (1)
/* @brief Clock 4 output divider width (width of register bit field CLKDIV1[OUTDIV4]). */
#define FSL_FEATURE_SIM_DIVIDER_OUTDIV4_WIDTH (4)
/* @brief Has clock 5 output divider (register bit field CLKDIV1[OUTDIV5]). */
#define FSL_FEATURE_SIM_DIVIDER_HAS_OUTDIV5 (0)
/* @brief Has USB clock divider (register bit field CLKDIV2[USBDIV] and CLKDIV2[USBFRAC]). */
#define FSL_FEATURE_SIM_DIVIDER_HAS_USBDIV (0)
/* @brief Has USB FS clock divider (register bit field CLKDIV2[USBFSDIV] and CLKDIV2[USBFSFRAC]). */
#define FSL_FEATURE_SIM_DIVIDER_HAS_USBFSDIV (0)
/* @brief Has USB HS clock divider (register bit field CLKDIV2[USBHSDIV] and CLKDIV2[USBHSFRAC]). */
#define FSL_FEATURE_SIM_DIVIDER_HAS_USBHSDIV (0)
/* @brief Has PLL/FLL clock divider (register bit field CLKDIV3[PLLFLLDIV] and CLKDIV3[PLLFLLFRAC]). */
#define FSL_FEATURE_SIM_DIVIDER_HAS_PLLFLLDIV (0)
/* @brief Has LCDC clock divider (register bit field CLKDIV3[LCDCDIV] and CLKDIV3[LCDCFRAC]). */
#define FSL_FEATURE_SIM_DIVIDER_HAS_LCDCDIV (0)
/* @brief Has trace clock divider (register bit field CLKDIV4[TRACEDIV] and CLKDIV4[TRACEFRAC]). */
#define FSL_FEATURE_SIM_DIVIDER_HAS_TRACEDIV (1)
/* @brief Has NFC clock divider (register bit field CLKDIV4[NFCDIV] and CLKDIV4[NFCFRAC]). */
#define FSL_FEATURE_SIM_DIVIDER_HAS_NFCDIV (0)
/* @brief Has Kinetis family ID (register bit field SDID[FAMILYID]). */
#define FSL_FEATURE_SIM_SDID_HAS_FAMILYID (1)
/* @brief Has Kinetis family ID (register bit field SDID[FAMID]). */
#define FSL_FEATURE_SIM_SDID_HAS_FAMID (0)
/* @brief Has Kinetis sub-family ID (register bit field SDID[SUBFAMID]). */
#define FSL_FEATURE_SIM_SDID_HAS_SUBFAMID (1)
/* @brief Has Kinetis series ID (register bit field SDID[SERIESID]). */
#define FSL_FEATURE_SIM_SDID_HAS_SERIESID (1)
/* @brief Has device die ID (register bit field SDID[DIEID]). */
#define FSL_FEATURE_SIM_SDID_HAS_DIEID (1)
/* @brief Has system SRAM size specifier (register bit field SDID[SRAMSIZE]). */
#define FSL_FEATURE_SIM_SDID_HAS_SRAMSIZE (0)
/* @brief Has flash mode (register bit FCFG1[FLASHDOZE]). */
#define FSL_FEATURE_SIM_FCFG_HAS_FLASHDOZE (1)
/* @brief Has flash disable (register bit FCFG1[FLASHDIS]). */
#define FSL_FEATURE_SIM_FCFG_HAS_FLASHDIS (1)
/* @brief Has FTFE disable (register bit FCFG1[FTFDIS]). */
#define FSL_FEATURE_SIM_FCFG_HAS_FTFDIS (0)
/* @brief Has FlexNVM size specifier (register bit field FCFG1[NVMSIZE]). */
#define FSL_FEATURE_SIM_FCFG_HAS_NVMSIZE (0)
/* @brief Has EEPROM size specifier (register bit field FCFG1[EESIZE]). */
#define FSL_FEATURE_SIM_FCFG_HAS_EESIZE (0)
/* @brief Has FlexNVM partition (register bit field FCFG1[DEPART]). */
#define FSL_FEATURE_SIM_FCFG_HAS_DEPART (0)
/* @brief Maximum flash address block 0 address specifier (register bit field FCFG2[MAXADDR0]). */
#define FSL_FEATURE_SIM_FCFG_HAS_MAXADDR0 (1)
/* @brief Maximum flash address block 1 address specifier (register bit field FCFG2[MAXADDR1]). */
#define FSL_FEATURE_SIM_FCFG_HAS_MAXADDR1 (0)
/* @brief Maximum flash address block 0 or 1 address specifier (register bit field FCFG2[MAXADDR01]). */
#define FSL_FEATURE_SIM_FCFG_HAS_MAXADDR01 (0)
/* @brief Maximum flash address block 2 or 3 address specifier (register bit field FCFG2[MAXADDR23]). */
#define FSL_FEATURE_SIM_FCFG_HAS_MAXADDR23 (0)
/* @brief Has program flash availability specifier (register bit FCFG2[PFLSH]). */
#define FSL_FEATURE_SIM_FCFG_HAS_PFLSH (0)
/* @brief Has program flash swapping (register bit FCFG2[SWAPPFLSH]). */
#define FSL_FEATURE_SIM_FCFG_HAS_PFLSH_SWAP (0)
/* @brief Has miscellanious control register (register MCR). */
#define FSL_FEATURE_SIM_HAS_MISC_CONTROLS (0)
/* @brief Has COP watchdog (registers COPC and SRVCOP). */
#define FSL_FEATURE_SIM_HAS_COP_WATCHDOG (0)
/* @brief Has COP watchdog stop (register bits COPC[COPSTPEN], COPC[COPDBGEN] and COPC[COPCLKSEL]). */
#define FSL_FEATURE_SIM_HAS_COP_STOP (0)
/* @brief Has LLWU clock gate bit (e.g SIM_SCGC4). */
#define FSL_FEATURE_SIM_HAS_SCGC_LLWU (0)

/* SMC module features */

/* @brief Has partial stop option (register bit STOPCTRL[PSTOPO]). */
#define FSL_FEATURE_SMC_HAS_PSTOPO (1)
/* @brief Has LPO power option (register bit STOPCTRL[LPOPO]). */
#define FSL_FEATURE_SMC_HAS_LPOPO (1)
/* @brief Has POR power option (register bit STOPCTRL[PORPO] or VLLSCTRL[PORPO]). */
#define FSL_FEATURE_SMC_HAS_PORPO (1)
/* @brief Has low power wakeup on interrupt (register bit PMCTRL[LPWUI]). */
#define FSL_FEATURE_SMC_HAS_LPWUI (0)
/* @brief Has LLS or VLLS mode control (register bit STOPCTRL[LLSM]). */
#define FSL_FEATURE_SMC_HAS_LLS_SUBMODE (0)
/* @brief Has VLLS mode control (register bit VLLSCTRL[VLLSM]). */
#define FSL_FEATURE_SMC_USE_VLLSCTRL_REG (0)
/* @brief Has VLLS mode control (register bit STOPCTRL[VLLSM]). */
#define FSL_FEATURE_SMC_USE_STOPCTRL_VLLSM (1)
/* @brief Has RAM partition 2 power option (register bit STOPCTRL[RAM2PO]). */
#define FSL_FEATURE_SMC_HAS_RAM2_POWER_OPTION (1)
/* @brief Has high speed run mode (register bit PMPROT[AHSRUN]). */
#define FSL_FEATURE_SMC_HAS_HIGH_SPEED_RUN_MODE (1)
/* @brief Has low leakage stop mode (register bit PMPROT[ALLS]). */
#define FSL_FEATURE_SMC_HAS_LOW_LEAKAGE_STOP_MODE (0)
/* @brief Has very low leakage stop mode (register bit PMPROT[AVLLS]). */
#define FSL_FEATURE_SMC_HAS_VERY_LOW_LEAKAGE_STOP_MODE (1)
/* @brief Has stop submode. */
#define FSL_FEATURE_SMC_HAS_SUB_STOP_MODE (1)
/* @brief Has stop submode 0(VLLS0). */
#define FSL_FEATURE_SMC_HAS_STOP_SUBMODE0 (1)
/* @brief Has stop submode 1(VLLS1). */
#define FSL_FEATURE_SMC_HAS_STOP_SUBMODE1 (1)
/* @brief Has stop submode 2(VLLS2). */
#define FSL_FEATURE_SMC_HAS_STOP_SUBMODE2 (1)
/* @brief Has SMC_PARAM. */
#define FSL_FEATURE_SMC_HAS_PARAM (0)
/* @brief Has SMC_VERID. */
#define FSL_FEATURE_SMC_HAS_VERID (0)
/* @brief Has stop abort flag (register bit PMCTRL[STOPA]). */
#define FSL_FEATURE_SMC_HAS_PMCTRL_STOPA (1)
/* @brief Has tamper reset (register bit SRS[TAMPER]). */
#define FSL_FEATURE_SMC_HAS_SRS_TAMPER (0)
/* @brief Has security violation reset (register bit SRS[SECVIO]). */
#define FSL_FEATURE_SMC_HAS_SRS_SECVIO (0)
/* @brief Width of SMC registers. */
#define FSL_FEATURE_SMC_REG_WIDTH (8)

/* DSPI module features */

/* @brief Receive/transmit FIFO size in number of items. */
#define FSL_FEATURE_DSPI_FIFO_SIZEn(x) (4)
/* @brief Maximum transfer data width in bits. */
#define FSL_FEATURE_DSPI_MAX_DATA_WIDTH (16)
/* @brief Maximum number of chip select pins. (Reflects the width of register bit field PUSHR[PCS].) */
#define FSL_FEATURE_DSPI_MAX_CHIP_SELECT_COUNT (6)
/* @brief Number of chip select pins. */
#define FSL_FEATURE_DSPI_CHIP_SELECT_COUNT (6)
/* @brief Number of CTAR registers. */
#define FSL_FEATURE_DSPI_CTAR_COUNT (2)
/* @brief Has chip select strobe capability on the PCS5 pin. */
#define FSL_FEATURE_DSPI_HAS_CHIP_SELECT_STROBE (1)
/* @brief Has separated TXDATA and CMD FIFOs (register SREX). */
#define FSL_FEATURE_DSPI_HAS_SEPARATE_TXDATA_CMD_FIFO (0)
/* @brief Has 16-bit data transfer support. */
#define FSL_FEATURE_DSPI_16BIT_TRANSFERS (1)
/* @brief Has separate DMA RX and TX requests. */
#define FSL_FEATURE_DSPI_HAS_SEPARATE_DMA_RX_TX_REQn(x) (1)

/* SYSMPU module features */

/* @brief Specifies number of descriptors available. */
#define FSL_FEATURE_SYSMPU_DESCRIPTOR_COUNT (12)
/* @brief Has process identifier support. */
#define FSL_FEATURE_SYSMPU_HAS_PROCESS_IDENTIFIER (1)
/* @brief Total number of MPU slave. */
#define FSL_FEATURE_SYSMPU_SLAVE_COUNT (5)
/* @brief Total number of MPU master. */
#define FSL_FEATURE_SYSMPU_MASTER_COUNT (4)

/* SysTick module features */

/* @brief Systick has external reference clock. */
#define FSL_FEATURE_SYSTICK_HAS_EXT_REF (0)
/* @brief Systick external reference clock is core clock divided by this value. */
#define FSL_FEATURE_SYSTICK_EXT_REF_CORE_DIV (0)

/* SCB module features */

/* @brief L1 ICACHE line size in byte. */
#define FSL_FEATURE_L1ICACHE_LINESIZE_BYTE (32)
/* @brief L1 DCACHE line size in byte. */
#define FSL_FEATURE_L1DCACHE_LINESIZE_BYTE (32)

/* UART module features */

#if defined(CPU_MKV58F1M0VLL24) || defined(CPU_MKV58F512VLL24)
    /* @brief Has receive FIFO overflow detection (bit field CFIFO[RXOFE]). */
    #define FSL_FEATURE_UART_HAS_IRQ_EXTENDED_FUNCTIONS (1)
    /* @brief Has low power features (can be enabled in wait mode via register bit C1[DOZEEN] or CTRL[DOZEEN] if the registers are 32-bit wide). */
    #define FSL_FEATURE_UART_HAS_LOW_POWER_UART_SUPPORT (0)
    /* @brief Has extended data register ED (or extra flags in the DATA register if the registers are 32-bit wide). */
    #define FSL_FEATURE_UART_HAS_EXTENDED_DATA_REGISTER_FLAGS (1)
    /* @brief Capacity (number of entries) of the transmit/receive FIFO (or zero if no FIFO is available). */
    #define FSL_FEATURE_UART_HAS_FIFO (1)
    /* @brief Hardware flow control (RTS, CTS) is supported. */
    #define FSL_FEATURE_UART_HAS_MODEM_SUPPORT (1)
    /* @brief Infrared (modulation) is supported. */
    #define FSL_FEATURE_UART_HAS_IR_SUPPORT (1)
    /* @brief 2 bits long stop bit is available. */
    #define FSL_FEATURE_UART_HAS_STOP_BIT_CONFIG_SUPPORT (1)
    /* @brief If 10-bit mode is supported. */
    #define FSL_FEATURE_UART_HAS_10BIT_DATA_SUPPORT (1)
    /* @brief Baud rate fine adjustment is available. */
    #define FSL_FEATURE_UART_HAS_BAUD_RATE_FINE_ADJUST_SUPPORT (1)
    /* @brief Baud rate oversampling is available (has bit fields C4[OSR], C5[BOTHEDGE], C5[RESYNCDIS] or BAUD[OSR], BAUD[BOTHEDGE], BAUD[RESYNCDIS] if the registers are 32-bit wide). */
    #define FSL_FEATURE_UART_HAS_BAUD_RATE_OVER_SAMPLING_SUPPORT (0)
    /* @brief Baud rate oversampling is available. */
    #define FSL_FEATURE_UART_HAS_RX_RESYNC_SUPPORT (0)
    /* @brief Baud rate oversampling is available. */
    #define FSL_FEATURE_UART_HAS_BOTH_EDGE_SAMPLING_SUPPORT (0)
    /* @brief Peripheral type. */
    #define FSL_FEATURE_UART_IS_SCI (0)
    /* @brief Capacity (number of entries) of the transmit/receive FIFO (or zero if no FIFO is available). */
    #define FSL_FEATURE_UART_FIFO_SIZEn(x) \
        (((x) == UART0) ? (8) : \
        (((x) == UART1) ? (8) : \
        (((x) == UART2) ? (1) : \
        (((x) == UART3) ? (1) : \
        (((x) == UART4) ? (1) : (-1))))))
    /* @brief Maximal data width without parity bit. */
    #define FSL_FEATURE_UART_MAX_DATA_WIDTH_WITH_NO_PARITY (9)
    /* @brief Maximal data width with parity bit. */
    #define FSL_FEATURE_UART_MAX_DATA_WIDTH_WITH_PARITY (10)
    /* @brief Supports two match addresses to filter incoming frames. */
    #define FSL_FEATURE_UART_HAS_ADDRESS_MATCHING (1)
    /* @brief Has transmitter/receiver DMA enable bits C5[TDMAE]/C5[RDMAE] (or BAUD[TDMAE]/BAUD[RDMAE] if the registers are 32-bit wide). */
    #define FSL_FEATURE_UART_HAS_DMA_ENABLE (0)
    /* @brief Has transmitter/receiver DMA select bits C4[TDMAS]/C4[RDMAS], resp. C5[TDMAS]/C5[RDMAS] if IS_SCI = 0. */
    #define FSL_FEATURE_UART_HAS_DMA_SELECT (1)
    /* @brief Data character bit order selection is supported (bit field S2[MSBF] or STAT[MSBF] if the registers are 32-bit wide). */
    #define FSL_FEATURE_UART_HAS_BIT_ORDER_SELECT (1)
    /* @brief Has smart card (ISO7816 protocol) support and no improved smart card support. */
    #define FSL_FEATURE_UART_HAS_SMART_CARD_SUPPORT (1)
    /* @brief Has improved smart card (ISO7816 protocol) support. */
    #define FSL_FEATURE_UART_HAS_IMPROVED_SMART_CARD_SUPPORT (1)
    /* @brief Has local operation network (CEA709.1-B protocol) support. */
    #define FSL_FEATURE_UART_HAS_LOCAL_OPERATION_NETWORK_SUPPORT (0)
    /* @brief Has 32-bit registers (BAUD, STAT, CTRL, DATA, MATCH, MODIR) instead of 8-bit (BDH, BDL, C1, S1, D, etc.). */
    #define FSL_FEATURE_UART_HAS_32BIT_REGISTERS (0)
    /* @brief Lin break detect available (has bit BDH[LBKDIE]). */
    #define FSL_FEATURE_UART_HAS_LIN_BREAK_DETECT (1)
    /* @brief UART stops in Wait mode available (has bit C1[UARTSWAI]). */
    #define FSL_FEATURE_UART_HAS_WAIT_MODE_OPERATION (1)
    /* @brief Has separate DMA RX and TX requests. */
    #define FSL_FEATURE_UART_HAS_SEPARATE_DMA_RX_TX_REQn(x) (1)
#elif defined(CPU_MKV58F1M0VLQ24) || defined(CPU_MKV58F1M0VMD24) || defined(CPU_MKV58F512VLQ24) || defined(CPU_MKV58F512VMD24)
    /* @brief Has receive FIFO overflow detection (bit field CFIFO[RXOFE]). */
    #define FSL_FEATURE_UART_HAS_IRQ_EXTENDED_FUNCTIONS (1)
    /* @brief Has low power features (can be enabled in wait mode via register bit C1[DOZEEN] or CTRL[DOZEEN] if the registers are 32-bit wide). */
    #define FSL_FEATURE_UART_HAS_LOW_POWER_UART_SUPPORT (0)
    /* @brief Has extended data register ED (or extra flags in the DATA register if the registers are 32-bit wide). */
    #define FSL_FEATURE_UART_HAS_EXTENDED_DATA_REGISTER_FLAGS (1)
    /* @brief Capacity (number of entries) of the transmit/receive FIFO (or zero if no FIFO is available). */
    #define FSL_FEATURE_UART_HAS_FIFO (1)
    /* @brief Hardware flow control (RTS, CTS) is supported. */
    #define FSL_FEATURE_UART_HAS_MODEM_SUPPORT (1)
    /* @brief Infrared (modulation) is supported. */
    #define FSL_FEATURE_UART_HAS_IR_SUPPORT (1)
    /* @brief 2 bits long stop bit is available. */
    #define FSL_FEATURE_UART_HAS_STOP_BIT_CONFIG_SUPPORT (1)
    /* @brief If 10-bit mode is supported. */
    #define FSL_FEATURE_UART_HAS_10BIT_DATA_SUPPORT (1)
    /* @brief Baud rate fine adjustment is available. */
    #define FSL_FEATURE_UART_HAS_BAUD_RATE_FINE_ADJUST_SUPPORT (1)
    /* @brief Baud rate oversampling is available (has bit fields C4[OSR], C5[BOTHEDGE], C5[RESYNCDIS] or BAUD[OSR], BAUD[BOTHEDGE], BAUD[RESYNCDIS] if the registers are 32-bit wide). */
    #define FSL_FEATURE_UART_HAS_BAUD_RATE_OVER_SAMPLING_SUPPORT (0)
    /* @brief Baud rate oversampling is available. */
    #define FSL_FEATURE_UART_HAS_RX_RESYNC_SUPPORT (0)
    /* @brief Baud rate oversampling is available. */
    #define FSL_FEATURE_UART_HAS_BOTH_EDGE_SAMPLING_SUPPORT (0)
    /* @brief Peripheral type. */
    #define FSL_FEATURE_UART_IS_SCI (0)
    /* @brief Capacity (number of entries) of the transmit/receive FIFO (or zero if no FIFO is available). */
    #define FSL_FEATURE_UART_FIFO_SIZEn(x) \
        (((x) == UART0) ? (8) : \
        (((x) == UART1) ? (8) : \
        (((x) == UART2) ? (1) : \
        (((x) == UART3) ? (1) : \
        (((x) == UART4) ? (1) : \
        (((x) == UART5) ? (1) : (-1)))))))
    /* @brief Maximal data width without parity bit. */
    #define FSL_FEATURE_UART_MAX_DATA_WIDTH_WITH_NO_PARITY (9)
    /* @brief Maximal data width with parity bit. */
    #define FSL_FEATURE_UART_MAX_DATA_WIDTH_WITH_PARITY (10)
    /* @brief Supports two match addresses to filter incoming frames. */
    #define FSL_FEATURE_UART_HAS_ADDRESS_MATCHING (1)
    /* @brief Has transmitter/receiver DMA enable bits C5[TDMAE]/C5[RDMAE] (or BAUD[TDMAE]/BAUD[RDMAE] if the registers are 32-bit wide). */
    #define FSL_FEATURE_UART_HAS_DMA_ENABLE (0)
    /* @brief Has transmitter/receiver DMA select bits C4[TDMAS]/C4[RDMAS], resp. C5[TDMAS]/C5[RDMAS] if IS_SCI = 0. */
    #define FSL_FEATURE_UART_HAS_DMA_SELECT (1)
    /* @brief Data character bit order selection is supported (bit field S2[MSBF] or STAT[MSBF] if the registers are 32-bit wide). */
    #define FSL_FEATURE_UART_HAS_BIT_ORDER_SELECT (1)
    /* @brief Has smart card (ISO7816 protocol) support and no improved smart card support. */
    #define FSL_FEATURE_UART_HAS_SMART_CARD_SUPPORT (1)
    /* @brief Has improved smart card (ISO7816 protocol) support. */
    #define FSL_FEATURE_UART_HAS_IMPROVED_SMART_CARD_SUPPORT (1)
    /* @brief Has local operation network (CEA709.1-B protocol) support. */
    #define FSL_FEATURE_UART_HAS_LOCAL_OPERATION_NETWORK_SUPPORT (0)
    /* @brief Has 32-bit registers (BAUD, STAT, CTRL, DATA, MATCH, MODIR) instead of 8-bit (BDH, BDL, C1, S1, D, etc.). */
    #define FSL_FEATURE_UART_HAS_32BIT_REGISTERS (0)
    /* @brief Lin break detect available (has bit BDH[LBKDIE]). */
    #define FSL_FEATURE_UART_HAS_LIN_BREAK_DETECT (1)
    /* @brief UART stops in Wait mode available (has bit C1[UARTSWAI]). */
    #define FSL_FEATURE_UART_HAS_WAIT_MODE_OPERATION (1)
    /* @brief Has separate DMA RX and TX requests. */
    #define FSL_FEATURE_UART_HAS_SEPARATE_DMA_RX_TX_REQn(x) (1)
#endif /* defined(CPU_MKV58F1M0VLL24) || defined(CPU_MKV58F512VLL24) */

/* WDOG module features */

/* @brief Watchdog is available. */
#define FSL_FEATURE_WDOG_HAS_WATCHDOG (1)
/* @brief Has Wait mode support. */
#define FSL_FEATURE_WDOG_HAS_WAITEN (1)

/* XBARA module features */

/* @brief Has single XBAR module. */
#define FSL_FEATURE_XBARA_HAS_SINGLE_MODULE (0)
/* @brief Maximum value of XBARA input. */
#define FSL_FEATURE_XBARA_MODULE_INPUTS (58)
/* @brief Maximum value of XBARA output. */
#define FSL_FEATURE_XBARA_MODULE_OUTPUTS (59)
/* @brief Half register position. */
#define FSL_FEATURE_XBARA_HALF_REGISTER_SHIFT (BP_XBARA_SEL0_SEL1)
/* @brief Offset of the control register. */
#define FSL_FEATURE_XBARA_CONTROL_REGISTER_OFFSET (HW_XBARA_CTRL0_ADDR(0))
/* @brief Number of controled outputs. */
#define FSL_FEATURE_XBARA_CONTROL_OUTPUTS_NUMBER (4U)
/* @brief Number of interrupt requests. */
#define FSL_FEATURE_XBARA_INTERRUPT_COUNT (4)
/* @brief Number of controled outputs. */
#define FSL_FEATURE_XBARA_OUTPUT_COUNT (4U)
/* @brief XBARA has input 0. */
#define FSL_FEATURE_XBARA_HAS_INPUT0 (1)
/* @brief XBARA has input 1. */
#define FSL_FEATURE_XBARA_HAS_INPUT1 (1)
/* @brief XBARA has input 2. */
#define FSL_FEATURE_XBARA_HAS_INPUT2 (1)
/* @brief XBARA has input 3. */
#define FSL_FEATURE_XBARA_HAS_INPUT3 (1)
/* @brief XBARA has input 4. */
#define FSL_FEATURE_XBARA_HAS_INPUT4 (1)
/* @brief XBARA has input 5. */
#define FSL_FEATURE_XBARA_HAS_INPUT5 (1)
/* @brief XBARA has input 6. */
#define FSL_FEATURE_XBARA_HAS_INPUT6 (1)
/* @brief XBARA has input 7. */
#define FSL_FEATURE_XBARA_HAS_INPUT7 (1)
/* @brief XBARA has input 8. */
#define FSL_FEATURE_XBARA_HAS_INPUT8 (1)
/* @brief XBARA has input 9. */
#define FSL_FEATURE_XBARA_HAS_INPUT9 (1)
/* @brief XBARA has input 10. */
#define FSL_FEATURE_XBARA_HAS_INPUT10 (1)
/* @brief XBARA has input 11. */
#define FSL_FEATURE_XBARA_HAS_INPUT11 (1)
/* @brief XBARA has input 12. */
#define FSL_FEATURE_XBARA_HAS_INPUT12 (1)
/* @brief XBARA has input 13. */
#define FSL_FEATURE_XBARA_HAS_INPUT13 (1)
/* @brief XBARA has input 14. */
#define FSL_FEATURE_XBARA_HAS_INPUT14 (1)
/* @brief XBARA has input 15. */
#define FSL_FEATURE_XBARA_HAS_INPUT15 (1)
/* @brief XBARA has input 16. */
#define FSL_FEATURE_XBARA_HAS_INPUT16 (1)
/* @brief XBARA has input 17. */
#define FSL_FEATURE_XBARA_HAS_INPUT17 (1)
/* @brief XBARA has input 18. */
#define FSL_FEATURE_XBARA_HAS_INPUT18 (1)
/* @brief XBARA has input 19. */
#define FSL_FEATURE_XBARA_HAS_INPUT19 (1)
/* @brief XBARA has input 20. */
#define FSL_FEATURE_XBARA_HAS_INPUT20 (1)
/* @brief XBARA has input 21. */
#define FSL_FEATURE_XBARA_HAS_INPUT21 (1)
/* @brief XBARA has input 22. */
#define FSL_FEATURE_XBARA_HAS_INPUT22 (1)
/* @brief XBARA has input 23. */
#define FSL_FEATURE_XBARA_HAS_INPUT23 (1)
/* @brief XBARA has input 24. */
#define FSL_FEATURE_XBARA_HAS_INPUT24 (1)
/* @brief XBARA has input 25. */
#define FSL_FEATURE_XBARA_HAS_INPUT25 (1)
/* @brief XBARA has input 26. */
#define FSL_FEATURE_XBARA_HAS_INPUT26 (1)
/* @brief XBARA has input 27. */
#define FSL_FEATURE_XBARA_HAS_INPUT27 (1)
/* @brief XBARA has input 28. */
#define FSL_FEATURE_XBARA_HAS_INPUT28 (1)
/* @brief XBARA has input 29. */
#define FSL_FEATURE_XBARA_HAS_INPUT29 (1)
/* @brief XBARA has input 30. */
#define FSL_FEATURE_XBARA_HAS_INPUT30 (1)
/* @brief XBARA has input 31. */
#define FSL_FEATURE_XBARA_HAS_INPUT31 (1)
/* @brief XBARA has input 32. */
#define FSL_FEATURE_XBARA_HAS_INPUT32 (1)
/* @brief XBARA has input 33. */
#define FSL_FEATURE_XBARA_HAS_INPUT33 (1)
/* @brief XBARA has input 34. */
#define FSL_FEATURE_XBARA_HAS_INPUT34 (1)
/* @brief XBARA has input 35. */
#define FSL_FEATURE_XBARA_HAS_INPUT35 (1)
/* @brief XBARA has input 36. */
#define FSL_FEATURE_XBARA_HAS_INPUT36 (1)
/* @brief XBARA has input 37. */
#define FSL_FEATURE_XBARA_HAS_INPUT37 (1)
/* @brief XBARA has input 38. */
#define FSL_FEATURE_XBARA_HAS_INPUT38 (1)
/* @brief XBARA has input 39. */
#define FSL_FEATURE_XBARA_HAS_INPUT39 (1)
/* @brief XBARA has input 40. */
#define FSL_FEATURE_XBARA_HAS_INPUT40 (1)
/* @brief XBARA has input 41. */
#define FSL_FEATURE_XBARA_HAS_INPUT41 (1)
/* @brief XBARA has input 42. */
#define FSL_FEATURE_XBARA_HAS_INPUT42 (1)
/* @brief XBARA has input 43. */
#define FSL_FEATURE_XBARA_HAS_INPUT43 (1)
/* @brief XBARA has input 44. */
#define FSL_FEATURE_XBARA_HAS_INPUT44 (1)
/* @brief XBARA has input 45. */
#define FSL_FEATURE_XBARA_HAS_INPUT45 (1)
/* @brief XBARA has input 46. */
#define FSL_FEATURE_XBARA_HAS_INPUT46 (1)
/* @brief XBARA has input 47. */
#define FSL_FEATURE_XBARA_HAS_INPUT47 (1)
/* @brief XBARA has input 48. */
#define FSL_FEATURE_XBARA_HAS_INPUT48 (1)
/* @brief XBARA has input 49. */
#define FSL_FEATURE_XBARA_HAS_INPUT49 (1)
/* @brief XBARA has input 50. */
#define FSL_FEATURE_XBARA_HAS_INPUT50 (1)
/* @brief XBARA has input 51. */
#define FSL_FEATURE_XBARA_HAS_INPUT51 (1)
/* @brief XBARA has input 52. */
#define FSL_FEATURE_XBARA_HAS_INPUT52 (1)
/* @brief XBARA has input 53. */
#define FSL_FEATURE_XBARA_HAS_INPUT53 (1)
/* @brief XBARA has input 54. */
#define FSL_FEATURE_XBARA_HAS_INPUT54 (1)
/* @brief XBARA has input 55. */
#define FSL_FEATURE_XBARA_HAS_INPUT55 (1)
/* @brief XBARA has input 56. */
#define FSL_FEATURE_XBARA_HAS_INPUT56 (1)
/* @brief XBARA has input 57. */
#define FSL_FEATURE_XBARA_HAS_INPUT57 (1)
/* @brief XBARA has input 58. */
#define FSL_FEATURE_XBARA_HAS_INPUT58 (0)
/* @brief XBARA has input 59. */
#define FSL_FEATURE_XBARA_HAS_INPUT59 (0)
/* @brief XBARA has input 60. */
#define FSL_FEATURE_XBARA_HAS_INPUT60 (0)
/* @brief XBARA has input 61. */
#define FSL_FEATURE_XBARA_HAS_INPUT61 (0)
/* @brief XBARA has input 62. */
#define FSL_FEATURE_XBARA_HAS_INPUT62 (0)
/* @brief XBARA has input 63. */
#define FSL_FEATURE_XBARA_HAS_INPUT63 (0)
/* @brief XBARA has input 64. */
#define FSL_FEATURE_XBARA_HAS_INPUT64 (0)
/* @brief XBARA has input 65. */
#define FSL_FEATURE_XBARA_HAS_INPUT65 (0)
/* @brief XBARA has input 66. */
#define FSL_FEATURE_XBARA_HAS_INPUT66 (0)
/* @brief XBARA has input 67. */
#define FSL_FEATURE_XBARA_HAS_INPUT67 (0)
/* @brief XBARA has input 68. */
#define FSL_FEATURE_XBARA_HAS_INPUT68 (0)
/* @brief XBARA has input 69. */
#define FSL_FEATURE_XBARA_HAS_INPUT69 (0)
/* @brief XBARA has input 70. */
#define FSL_FEATURE_XBARA_HAS_INPUT70 (0)
/* @brief XBARA has input 71. */
#define FSL_FEATURE_XBARA_HAS_INPUT71 (0)
/* @brief XBARA has input 72. */
#define FSL_FEATURE_XBARA_HAS_INPUT72 (0)
/* @brief XBARA has input 73. */
#define FSL_FEATURE_XBARA_HAS_INPUT73 (0)
/* @brief XBARA has input 74. */
#define FSL_FEATURE_XBARA_HAS_INPUT74 (0)
/* @brief XBARA has input 75. */
#define FSL_FEATURE_XBARA_HAS_INPUT75 (0)
/* @brief XBARA has input 76. */
#define FSL_FEATURE_XBARA_HAS_INPUT76 (0)
/* @brief XBARA has input 77. */
#define FSL_FEATURE_XBARA_HAS_INPUT77 (0)
/* @brief XBARA has input 78. */
#define FSL_FEATURE_XBARA_HAS_INPUT78 (0)
/* @brief XBARA has input 79. */
#define FSL_FEATURE_XBARA_HAS_INPUT79 (0)
/* @brief XBARA has input 80. */
#define FSL_FEATURE_XBARA_HAS_INPUT80 (0)
/* @brief XBARA has input 81. */
#define FSL_FEATURE_XBARA_HAS_INPUT81 (0)
/* @brief XBARA has input 82. */
#define FSL_FEATURE_XBARA_HAS_INPUT82 (0)
/* @brief XBARA has input 83. */
#define FSL_FEATURE_XBARA_HAS_INPUT83 (0)
/* @brief XBARA has input 84. */
#define FSL_FEATURE_XBARA_HAS_INPUT84 (0)
/* @brief XBARA has input 85. */
#define FSL_FEATURE_XBARA_HAS_INPUT85 (0)
/* @brief XBARA has input 86. */
#define FSL_FEATURE_XBARA_HAS_INPUT86 (0)
/* @brief XBARA has input 87. */
#define FSL_FEATURE_XBARA_HAS_INPUT87 (0)
/* @brief XBARA has input 88. */
#define FSL_FEATURE_XBARA_HAS_INPUT88 (0)
/* @brief XBARA has input 89. */
#define FSL_FEATURE_XBARA_HAS_INPUT89 (0)
/* @brief XBARA has input 90. */
#define FSL_FEATURE_XBARA_HAS_INPUT90 (0)
/* @brief XBARA has input 91. */
#define FSL_FEATURE_XBARA_HAS_INPUT91 (0)
/* @brief XBARA has input 92. */
#define FSL_FEATURE_XBARA_HAS_INPUT92 (0)
/* @brief XBARA has input 93. */
#define FSL_FEATURE_XBARA_HAS_INPUT93 (0)
/* @brief XBARA has input 94. */
#define FSL_FEATURE_XBARA_HAS_INPUT94 (0)
/* @brief XBARA has input 95. */
#define FSL_FEATURE_XBARA_HAS_INPUT95 (0)
/* @brief XBARA has input 96. */
#define FSL_FEATURE_XBARA_HAS_INPUT96 (0)
/* @brief XBARA has input 97. */
#define FSL_FEATURE_XBARA_HAS_INPUT97 (0)
/* @brief XBARA has input 98. */
#define FSL_FEATURE_XBARA_HAS_INPUT98 (0)
/* @brief XBARA has input 99. */
#define FSL_FEATURE_XBARA_HAS_INPUT99 (0)
/* @brief XBARA has input 100. */
#define FSL_FEATURE_XBARA_HAS_INPUT100 (0)
/* @brief XBARA has input 101. */
#define FSL_FEATURE_XBARA_HAS_INPUT101 (0)
/* @brief XBARA has input 102. */
#define FSL_FEATURE_XBARA_HAS_INPUT102 (0)
/* @brief XBARA has input 103. */
#define FSL_FEATURE_XBARA_HAS_INPUT103 (0)
/* @brief XBARA has input 104. */
#define FSL_FEATURE_XBARA_HAS_INPUT104 (0)
/* @brief XBARA has input 105. */
#define FSL_FEATURE_XBARA_HAS_INPUT105 (0)
/* @brief XBARA has input 106. */
#define FSL_FEATURE_XBARA_HAS_INPUT106 (0)
/* @brief XBARA has input 107. */
#define FSL_FEATURE_XBARA_HAS_INPUT107 (0)
/* @brief XBARA has input 108. */
#define FSL_FEATURE_XBARA_HAS_INPUT108 (0)
/* @brief XBARA has input 109. */
#define FSL_FEATURE_XBARA_HAS_INPUT109 (0)
/* @brief XBARA has input 110. */
#define FSL_FEATURE_XBARA_HAS_INPUT110 (0)
/* @brief XBARA has input 111. */
#define FSL_FEATURE_XBARA_HAS_INPUT111 (0)
/* @brief XBARA has input 112. */
#define FSL_FEATURE_XBARA_HAS_INPUT112 (0)
/* @brief XBARA has input 113. */
#define FSL_FEATURE_XBARA_HAS_INPUT113 (0)
/* @brief XBARA has input 114. */
#define FSL_FEATURE_XBARA_HAS_INPUT114 (0)
/* @brief XBARA has input 115. */
#define FSL_FEATURE_XBARA_HAS_INPUT115 (0)
/* @brief XBARA has input 116. */
#define FSL_FEATURE_XBARA_HAS_INPUT116 (0)
/* @brief XBARA has input 117. */
#define FSL_FEATURE_XBARA_HAS_INPUT117 (0)
/* @brief XBARA has input 118. */
#define FSL_FEATURE_XBARA_HAS_INPUT118 (0)
/* @brief XBARA has input 119. */
#define FSL_FEATURE_XBARA_HAS_INPUT119 (0)
/* @brief XBARA has input 120. */
#define FSL_FEATURE_XBARA_HAS_INPUT120 (0)
/* @brief XBARA has input 121. */
#define FSL_FEATURE_XBARA_HAS_INPUT121 (0)
/* @brief XBARA has input 122. */
#define FSL_FEATURE_XBARA_HAS_INPUT122 (0)
/* @brief XBARA has input 123. */
#define FSL_FEATURE_XBARA_HAS_INPUT123 (0)
/* @brief XBARA has input 124. */
#define FSL_FEATURE_XBARA_HAS_INPUT124 (0)
/* @brief XBARA has input 125. */
#define FSL_FEATURE_XBARA_HAS_INPUT125 (0)
/* @brief XBARA has input 126. */
#define FSL_FEATURE_XBARA_HAS_INPUT126 (0)
/* @brief XBARA has input 127. */
#define FSL_FEATURE_XBARA_HAS_INPUT127 (0)
/* @brief XBARA has output 0. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT0 (1)
/* @brief XBARA has output 1. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT1 (1)
/* @brief XBARA has output 2. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT2 (1)
/* @brief XBARA has output 3. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT3 (1)
/* @brief XBARA has output 4. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT4 (1)
/* @brief XBARA has output 5. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT5 (1)
/* @brief XBARA has output 6. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT6 (1)
/* @brief XBARA has output 7. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT7 (1)
/* @brief XBARA has output 8. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT8 (1)
/* @brief XBARA has output 9. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT9 (1)
/* @brief XBARA has output 10. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT10 (1)
/* @brief XBARA has output 11. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT11 (1)
/* @brief XBARA has output 12. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT12 (1)
/* @brief XBARA has output 13. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT13 (1)
/* @brief XBARA has output 14. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT14 (0)
/* @brief XBARA has output 15. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT15 (1)
/* @brief XBARA has output 16. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT16 (1)
/* @brief XBARA has output 17. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT17 (1)
/* @brief XBARA has output 18. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT18 (1)
/* @brief XBARA has output 19. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT19 (1)
/* @brief XBARA has output 20. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT20 (1)
/* @brief XBARA has output 21. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT21 (1)
/* @brief XBARA has output 22. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT22 (1)
/* @brief XBARA has output 23. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT23 (1)
/* @brief XBARA has output 24. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT24 (1)
/* @brief XBARA has output 25. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT25 (1)
/* @brief XBARA has output 26. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT26 (1)
/* @brief XBARA has output 27. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT27 (1)
/* @brief XBARA has output 28. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT28 (1)
/* @brief XBARA has output 29. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT29 (1)
/* @brief XBARA has output 30. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT30 (1)
/* @brief XBARA has output 31. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT31 (1)
/* @brief XBARA has output 32. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT32 (1)
/* @brief XBARA has output 33. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT33 (1)
/* @brief XBARA has output 34. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT34 (1)
/* @brief XBARA has output 35. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT35 (1)
/* @brief XBARA has output 36. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT36 (1)
/* @brief XBARA has output 37. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT37 (1)
/* @brief XBARA has output 38. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT38 (1)
/* @brief XBARA has output 39. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT39 (1)
/* @brief XBARA has output 40. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT40 (0)
/* @brief XBARA has output 41. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT41 (1)
/* @brief XBARA has output 42. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT42 (1)
/* @brief XBARA has output 43. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT43 (1)
/* @brief XBARA has output 44. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT44 (1)
/* @brief XBARA has output 45. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT45 (1)
/* @brief XBARA has output 46. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT46 (1)
/* @brief XBARA has output 47. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT47 (1)
/* @brief XBARA has output 48. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT48 (1)
/* @brief XBARA has output 49. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT49 (1)
/* @brief XBARA has output 50. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT50 (1)
/* @brief XBARA has output 51. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT51 (1)
/* @brief XBARA has output 52. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT52 (1)
/* @brief XBARA has output 53. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT53 (1)
/* @brief XBARA has output 54. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT54 (1)
/* @brief XBARA has output 55. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT55 (1)
/* @brief XBARA has output 56. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT56 (1)
/* @brief XBARA has output 57. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT57 (1)
/* @brief XBARA has output 58. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT58 (1)
/* @brief XBARA has output 59. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT59 (0)
/* @brief XBARA has output 60. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT60 (0)
/* @brief XBARA has output 61. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT61 (0)
/* @brief XBARA has output 62. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT62 (0)
/* @brief XBARA has output 63. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT63 (0)
/* @brief XBARA has output 64. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT64 (0)
/* @brief XBARA has output 65. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT65 (0)
/* @brief XBARA has output 66. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT66 (0)
/* @brief XBARA has output 67. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT67 (0)
/* @brief XBARA has output 68. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT68 (0)
/* @brief XBARA has output 69. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT69 (0)
/* @brief XBARA has output 70. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT70 (0)
/* @brief XBARA has output 71. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT71 (0)
/* @brief XBARA has output 72. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT72 (0)
/* @brief XBARA has output 73. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT73 (0)
/* @brief XBARA has output 74. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT74 (0)
/* @brief XBARA has output 75. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT75 (0)
/* @brief XBARA has output 76. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT76 (0)
/* @brief XBARA has output 77. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT77 (0)
/* @brief XBARA has output 78. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT78 (0)
/* @brief XBARA has output 79. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT79 (0)
/* @brief XBARA has output 80. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT80 (0)
/* @brief XBARA has output 81. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT81 (0)
/* @brief XBARA has output 82. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT82 (0)
/* @brief XBARA has output 83. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT83 (0)
/* @brief XBARA has output 84. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT84 (0)
/* @brief XBARA has output 85. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT85 (0)
/* @brief XBARA has output 86. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT86 (0)
/* @brief XBARA has output 87. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT87 (0)
/* @brief XBARA has output 88. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT88 (0)
/* @brief XBARA has output 89. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT89 (0)
/* @brief XBARA has output 90. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT90 (0)
/* @brief XBARA has output 91. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT91 (0)
/* @brief XBARA has output 92. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT92 (0)
/* @brief XBARA has output 93. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT93 (0)
/* @brief XBARA has output 94. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT94 (0)
/* @brief XBARA has output 95. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT95 (0)
/* @brief XBARA has output 96. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT96 (0)
/* @brief XBARA has output 97. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT97 (0)
/* @brief XBARA has output 98. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT98 (0)
/* @brief XBARA has output 99. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT99 (0)
/* @brief XBARA has output 100. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT100 (0)
/* @brief XBARA has output 101. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT101 (0)
/* @brief XBARA has output 102. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT102 (0)
/* @brief XBARA has output 103. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT103 (0)
/* @brief XBARA has output 104. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT104 (0)
/* @brief XBARA has output 105. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT105 (0)
/* @brief XBARA has output 106. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT106 (0)
/* @brief XBARA has output 107. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT107 (0)
/* @brief XBARA has output 108. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT108 (0)
/* @brief XBARA has output 109. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT109 (0)
/* @brief XBARA has output 110. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT110 (0)
/* @brief XBARA has output 111. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT111 (0)
/* @brief XBARA has output 112. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT112 (0)
/* @brief XBARA has output 113. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT113 (0)
/* @brief XBARA has output 114. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT114 (0)
/* @brief XBARA has output 115. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT115 (0)
/* @brief XBARA has output 116. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT116 (0)
/* @brief XBARA has output 117. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT117 (0)
/* @brief XBARA has output 118. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT118 (0)
/* @brief XBARA has output 119. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT119 (0)
/* @brief XBARA has output 120. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT120 (0)
/* @brief XBARA has output 121. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT121 (0)
/* @brief XBARA has output 122. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT122 (0)
/* @brief XBARA has output 123. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT123 (0)
/* @brief XBARA has output 124. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT124 (0)
/* @brief XBARA has output 125. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT125 (0)
/* @brief XBARA has output 126. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT126 (0)
/* @brief XBARA has output 127. */
#define FSL_FEATURE_XBARA_HAS_OUTPUT127 (0)
/* @brief XBARA input 0 ID. */
#define FSL_FEATURE_XBARA_INPUT0_ID (Vss)
/* @brief XBARA input 1 ID. */
#define FSL_FEATURE_XBARA_INPUT1_ID (Vdd)
/* @brief XBARA input 2 ID. */
#define FSL_FEATURE_XBARA_INPUT2_ID (XbarIn2)
/* @brief XBARA input 3 ID. */
#define FSL_FEATURE_XBARA_INPUT3_ID (XbarIn3)
/* @brief XBARA input 4 ID. */
#define FSL_FEATURE_XBARA_INPUT4_ID (XbarIn4)
/* @brief XBARA input 5 ID. */
#define FSL_FEATURE_XBARA_INPUT5_ID (XbarIn5)
/* @brief XBARA input 6 ID. */
#define FSL_FEATURE_XBARA_INPUT6_ID (XbarIn6)
/* @brief XBARA input 7 ID. */
#define FSL_FEATURE_XBARA_INPUT7_ID (XbarIn7)
/* @brief XBARA input 8 ID. */
#define FSL_FEATURE_XBARA_INPUT8_ID (XbarIn8)
/* @brief XBARA input 9 ID. */
#define FSL_FEATURE_XBARA_INPUT9_ID (XbarIn9)
/* @brief XBARA input 10 ID. */
#define FSL_FEATURE_XBARA_INPUT10_ID (XbarIn10)
/* @brief XBARA input 11 ID. */
#define FSL_FEATURE_XBARA_INPUT11_ID (XbarIn11)
/* @brief XBARA input 12 ID. */
#define FSL_FEATURE_XBARA_INPUT12_ID (Cmp0Output)
/* @brief XBARA input 13 ID. */
#define FSL_FEATURE_XBARA_INPUT13_ID (Cmp1Output)
/* @brief XBARA input 14 ID. */
#define FSL_FEATURE_XBARA_INPUT14_ID (Cmp2Output)
/* @brief XBARA input 15 ID. */
#define FSL_FEATURE_XBARA_INPUT15_ID (Cmp3Output)
/* @brief XBARA input 16 ID. */
#define FSL_FEATURE_XBARA_INPUT16_ID (Ftm0Match)
/* @brief XBARA input 17 ID. */
#define FSL_FEATURE_XBARA_INPUT17_ID (Ftm0Extrig)
/* @brief XBARA input 18 ID. */
#define FSL_FEATURE_XBARA_INPUT18_ID (Ftm3Match)
/* @brief XBARA input 19 ID. */
#define FSL_FEATURE_XBARA_INPUT19_ID (Ftm3Extrig)
/* @brief XBARA input 20 ID. */
#define FSL_FEATURE_XBARA_INPUT20_ID (Pwm0Ch0Trg0)
/* @brief XBARA input 21 ID. */
#define FSL_FEATURE_XBARA_INPUT21_ID (Pwm0Ch0Trg1)
/* @brief XBARA input 22 ID. */
#define FSL_FEATURE_XBARA_INPUT22_ID (Pwm0Ch1Trg0)
/* @brief XBARA input 23 ID. */
#define FSL_FEATURE_XBARA_INPUT23_ID (Pwm0Ch1Trg1)
/* @brief XBARA input 24 ID. */
#define FSL_FEATURE_XBARA_INPUT24_ID (Pwm0Ch2Trg0)
/* @brief XBARA input 25 ID. */
#define FSL_FEATURE_XBARA_INPUT25_ID (Pwm0Ch2Trg1)
/* @brief XBARA input 26 ID. */
#define FSL_FEATURE_XBARA_INPUT26_ID (Pwm0Ch3Trg0)
/* @brief XBARA input 27 ID. */
#define FSL_FEATURE_XBARA_INPUT27_ID (Pwm0Ch3Trg1)
/* @brief XBARA input 28 ID. */
#define FSL_FEATURE_XBARA_INPUT28_ID (Pdb0Ch1Output)
/* @brief XBARA input 29 ID. */
#define FSL_FEATURE_XBARA_INPUT29_ID (Pdb0Ch0Output)
/* @brief XBARA input 30 ID. */
#define FSL_FEATURE_XBARA_INPUT30_ID (Pdb1Ch1Output)
/* @brief XBARA input 31 ID. */
#define FSL_FEATURE_XBARA_INPUT31_ID (Pdb1Ch0Output)
/* @brief XBARA input 32 ID. */
#define FSL_FEATURE_XBARA_INPUT32_ID (Hsadc1Cca)
/* @brief XBARA input 33 ID. */
#define FSL_FEATURE_XBARA_INPUT33_ID (Hsadc0Cca)
/* @brief XBARA input 34 ID. */
#define FSL_FEATURE_XBARA_INPUT34_ID (Hsadc1Ccb)
/* @brief XBARA input 35 ID. */
#define FSL_FEATURE_XBARA_INPUT35_ID (Hsadc0Ccb)
/* @brief XBARA input 36 ID. */
#define FSL_FEATURE_XBARA_INPUT36_ID (Ftm1Match)
/* @brief XBARA input 37 ID. */
#define FSL_FEATURE_XBARA_INPUT37_ID (Ftm1Extrig)
/* @brief XBARA input 38 ID. */
#define FSL_FEATURE_XBARA_INPUT38_ID (DmaCh0Done)
/* @brief XBARA input 39 ID. */
#define FSL_FEATURE_XBARA_INPUT39_ID (DmaCh1Done)
/* @brief XBARA input 40 ID. */
#define FSL_FEATURE_XBARA_INPUT40_ID (DmaCh6Done)
/* @brief XBARA input 41 ID. */
#define FSL_FEATURE_XBARA_INPUT41_ID (DmaCh7Done)
/* @brief XBARA input 42 ID. */
#define FSL_FEATURE_XBARA_INPUT42_ID (PitTrigger0)
/* @brief XBARA input 43 ID. */
#define FSL_FEATURE_XBARA_INPUT43_ID (PitTrigger1)
/* @brief XBARA input 44 ID. */
#define FSL_FEATURE_XBARA_INPUT44_ID (Adc0Coco)
/* @brief XBARA input 45 ID. */
#define FSL_FEATURE_XBARA_INPUT45_ID (Enc0CmpPosMatch)
/* @brief XBARA input 46 ID. */
#define FSL_FEATURE_XBARA_INPUT46_ID (AndOrInvert0)
/* @brief XBARA input 47 ID. */
#define FSL_FEATURE_XBARA_INPUT47_ID (AndOrInvert1)
/* @brief XBARA input 48 ID. */
#define FSL_FEATURE_XBARA_INPUT48_ID (AndOrInvert2)
/* @brief XBARA input 49 ID. */
#define FSL_FEATURE_XBARA_INPUT49_ID (AndOrInvert3)
/* @brief XBARA input 50 ID. */
#define FSL_FEATURE_XBARA_INPUT50_ID (PitTrigger2)
/* @brief XBARA input 51 ID. */
#define FSL_FEATURE_XBARA_INPUT51_ID (PitTrigger3)
/* @brief XBARA input 52 ID. */
#define FSL_FEATURE_XBARA_INPUT52_ID (Pwm1Ch0Trg0OrTrg1)
/* @brief XBARA input 53 ID. */
#define FSL_FEATURE_XBARA_INPUT53_ID (Pwm1Ch1Trg0OrTrg1)
/* @brief XBARA input 54 ID. */
#define FSL_FEATURE_XBARA_INPUT54_ID (Pwm1Ch2Trg0OrTrg1)
/* @brief XBARA input 55 ID. */
#define FSL_FEATURE_XBARA_INPUT55_ID (Pwm1Ch3Trg0OrTrg1)
/* @brief XBARA input 56 ID. */
#define FSL_FEATURE_XBARA_INPUT56_ID (Ftm2Match)
/* @brief XBARA input 57 ID. */
#define FSL_FEATURE_XBARA_INPUT57_ID (Ftm2Extrig)
/* @brief XBARA input 58 ID. */
#define FSL_FEATURE_XBARA_INPUT58_ID (XBARA_IN_RESERVED58)
/* @brief XBARA input 59 ID. */
#define FSL_FEATURE_XBARA_INPUT59_ID (XBARA_IN_RESERVED59)
/* @brief XBARA input 60 ID. */
#define FSL_FEATURE_XBARA_INPUT60_ID (XBARA_IN_RESERVED60)
/* @brief XBARA input 61 ID. */
#define FSL_FEATURE_XBARA_INPUT61_ID (XBARA_IN_RESERVED61)
/* @brief XBARA input 62 ID. */
#define FSL_FEATURE_XBARA_INPUT62_ID (XBARA_IN_RESERVED62)
/* @brief XBARA input 63 ID. */
#define FSL_FEATURE_XBARA_INPUT63_ID (XBARA_IN_RESERVED63)
/* @brief XBARA input 64 ID. */
#define FSL_FEATURE_XBARA_INPUT64_ID (XBARA_IN_RESERVED64)
/* @brief XBARA input 65 ID. */
#define FSL_FEATURE_XBARA_INPUT65_ID (XBARA_IN_RESERVED65)
/* @brief XBARA input 66 ID. */
#define FSL_FEATURE_XBARA_INPUT66_ID (XBARA_IN_RESERVED66)
/* @brief XBARA input 67 ID. */
#define FSL_FEATURE_XBARA_INPUT67_ID (XBARA_IN_RESERVED67)
/* @brief XBARA input 68 ID. */
#define FSL_FEATURE_XBARA_INPUT68_ID (XBARA_IN_RESERVED68)
/* @brief XBARA input 69 ID. */
#define FSL_FEATURE_XBARA_INPUT69_ID (XBARA_IN_RESERVED69)
/* @brief XBARA input 70 ID. */
#define FSL_FEATURE_XBARA_INPUT70_ID (XBARA_IN_RESERVED70)
/* @brief XBARA input 71 ID. */
#define FSL_FEATURE_XBARA_INPUT71_ID (XBARA_IN_RESERVED71)
/* @brief XBARA input 72 ID. */
#define FSL_FEATURE_XBARA_INPUT72_ID (XBARA_IN_RESERVED72)
/* @brief XBARA input 73 ID. */
#define FSL_FEATURE_XBARA_INPUT73_ID (XBARA_IN_RESERVED73)
/* @brief XBARA input 74 ID. */
#define FSL_FEATURE_XBARA_INPUT74_ID (XBARA_IN_RESERVED74)
/* @brief XBARA input 75 ID. */
#define FSL_FEATURE_XBARA_INPUT75_ID (XBARA_IN_RESERVED75)
/* @brief XBARA input 76 ID. */
#define FSL_FEATURE_XBARA_INPUT76_ID (XBARA_IN_RESERVED76)
/* @brief XBARA input 77 ID. */
#define FSL_FEATURE_XBARA_INPUT77_ID (XBARA_IN_RESERVED77)
/* @brief XBARA input 78 ID. */
#define FSL_FEATURE_XBARA_INPUT78_ID (XBARA_IN_RESERVED78)
/* @brief XBARA input 79 ID. */
#define FSL_FEATURE_XBARA_INPUT79_ID (XBARA_IN_RESERVED79)
/* @brief XBARA input 80 ID. */
#define FSL_FEATURE_XBARA_INPUT80_ID (XBARA_IN_RESERVED80)
/* @brief XBARA input 81 ID. */
#define FSL_FEATURE_XBARA_INPUT81_ID (XBARA_IN_RESERVED81)
/* @brief XBARA input 82 ID. */
#define FSL_FEATURE_XBARA_INPUT82_ID (XBARA_IN_RESERVED82)
/* @brief XBARA input 83 ID. */
#define FSL_FEATURE_XBARA_INPUT83_ID (XBARA_IN_RESERVED83)
/* @brief XBARA input 84 ID. */
#define FSL_FEATURE_XBARA_INPUT84_ID (XBARA_IN_RESERVED84)
/* @brief XBARA input 85 ID. */
#define FSL_FEATURE_XBARA_INPUT85_ID (XBARA_IN_RESERVED85)
/* @brief XBARA input 86 ID. */
#define FSL_FEATURE_XBARA_INPUT86_ID (XBARA_IN_RESERVED86)
/* @brief XBARA input 87 ID. */
#define FSL_FEATURE_XBARA_INPUT87_ID (XBARA_IN_RESERVED87)
/* @brief XBARA input 88 ID. */
#define FSL_FEATURE_XBARA_INPUT88_ID (XBARA_IN_RESERVED88)
/* @brief XBARA input 89 ID. */
#define FSL_FEATURE_XBARA_INPUT89_ID (XBARA_IN_RESERVED89)
/* @brief XBARA input 90 ID. */
#define FSL_FEATURE_XBARA_INPUT90_ID (XBARA_IN_RESERVED90)
/* @brief XBARA input 91 ID. */
#define FSL_FEATURE_XBARA_INPUT91_ID (XBARA_IN_RESERVED91)
/* @brief XBARA input 92 ID. */
#define FSL_FEATURE_XBARA_INPUT92_ID (XBARA_IN_RESERVED92)
/* @brief XBARA input 93 ID. */
#define FSL_FEATURE_XBARA_INPUT93_ID (XBARA_IN_RESERVED93)
/* @brief XBARA input 94 ID. */
#define FSL_FEATURE_XBARA_INPUT94_ID (XBARA_IN_RESERVED94)
/* @brief XBARA input 95 ID. */
#define FSL_FEATURE_XBARA_INPUT95_ID (XBARA_IN_RESERVED95)
/* @brief XBARA input 96 ID. */
#define FSL_FEATURE_XBARA_INPUT96_ID (XBARA_IN_RESERVED96)
/* @brief XBARA input 97 ID. */
#define FSL_FEATURE_XBARA_INPUT97_ID (XBARA_IN_RESERVED97)
/* @brief XBARA input 98 ID. */
#define FSL_FEATURE_XBARA_INPUT98_ID (XBARA_IN_RESERVED98)
/* @brief XBARA input 99 ID. */
#define FSL_FEATURE_XBARA_INPUT99_ID (XBARA_IN_RESERVED99)
/* @brief XBARA input 100 ID. */
#define FSL_FEATURE_XBARA_INPUT100_ID (XBARA_IN_RESERVED100)
/* @brief XBARA input 101 ID. */
#define FSL_FEATURE_XBARA_INPUT101_ID (XBARA_IN_RESERVED101)
/* @brief XBARA input 102 ID. */
#define FSL_FEATURE_XBARA_INPUT102_ID (XBARA_IN_RESERVED102)
/* @brief XBARA input 103 ID. */
#define FSL_FEATURE_XBARA_INPUT103_ID (XBARA_IN_RESERVED103)
/* @brief XBARA input 104 ID. */
#define FSL_FEATURE_XBARA_INPUT104_ID (XBARA_IN_RESERVED104)
/* @brief XBARA input 105 ID. */
#define FSL_FEATURE_XBARA_INPUT105_ID (XBARA_IN_RESERVED105)
/* @brief XBARA input 106 ID. */
#define FSL_FEATURE_XBARA_INPUT106_ID (XBARA_IN_RESERVED106)
/* @brief XBARA input 107 ID. */
#define FSL_FEATURE_XBARA_INPUT107_ID (XBARA_IN_RESERVED107)
/* @brief XBARA input 108 ID. */
#define FSL_FEATURE_XBARA_INPUT108_ID (XBARA_IN_RESERVED108)
/* @brief XBARA input 109 ID. */
#define FSL_FEATURE_XBARA_INPUT109_ID (XBARA_IN_RESERVED109)
/* @brief XBARA input 110 ID. */
#define FSL_FEATURE_XBARA_INPUT110_ID (XBARA_IN_RESERVED110)
/* @brief XBARA input 111 ID. */
#define FSL_FEATURE_XBARA_INPUT111_ID (XBARA_IN_RESERVED111)
/* @brief XBARA input 112 ID. */
#define FSL_FEATURE_XBARA_INPUT112_ID (XBARA_IN_RESERVED112)
/* @brief XBARA input 113 ID. */
#define FSL_FEATURE_XBARA_INPUT113_ID (XBARA_IN_RESERVED113)
/* @brief XBARA input 114 ID. */
#define FSL_FEATURE_XBARA_INPUT114_ID (XBARA_IN_RESERVED114)
/* @brief XBARA input 115 ID. */
#define FSL_FEATURE_XBARA_INPUT115_ID (XBARA_IN_RESERVED115)
/* @brief XBARA input 116 ID. */
#define FSL_FEATURE_XBARA_INPUT116_ID (XBARA_IN_RESERVED116)
/* @brief XBARA input 117 ID. */
#define FSL_FEATURE_XBARA_INPUT117_ID (XBARA_IN_RESERVED117)
/* @brief XBARA input 118 ID. */
#define FSL_FEATURE_XBARA_INPUT118_ID (XBARA_IN_RESERVED118)
/* @brief XBARA input 119 ID. */
#define FSL_FEATURE_XBARA_INPUT119_ID (XBARA_IN_RESERVED119)
/* @brief XBARA input 120 ID. */
#define FSL_FEATURE_XBARA_INPUT120_ID (XBARA_IN_RESERVED120)
/* @brief XBARA input 121 ID. */
#define FSL_FEATURE_XBARA_INPUT121_ID (XBARA_IN_RESERVED121)
/* @brief XBARA input 122 ID. */
#define FSL_FEATURE_XBARA_INPUT122_ID (XBARA_IN_RESERVED122)
/* @brief XBARA input 123 ID. */
#define FSL_FEATURE_XBARA_INPUT123_ID (XBARA_IN_RESERVED123)
/* @brief XBARA input 124 ID. */
#define FSL_FEATURE_XBARA_INPUT124_ID (XBARA_IN_RESERVED124)
/* @brief XBARA input 125 ID. */
#define FSL_FEATURE_XBARA_INPUT125_ID (XBARA_IN_RESERVED125)
/* @brief XBARA input 126 ID. */
#define FSL_FEATURE_XBARA_INPUT126_ID (XBARA_IN_RESERVED126)
/* @brief XBARA input 127 ID. */
#define FSL_FEATURE_XBARA_INPUT127_ID (XBARA_IN_RESERVED127)
/* @brief XBARA output 0 ID. */
#define FSL_FEATURE_XBARA_OUTPUT0_ID (Dmamux18)
/* @brief XBARA output 1 ID. */
#define FSL_FEATURE_XBARA_OUTPUT1_ID (Dmamux19)
/* @brief XBARA output 2 ID. */
#define FSL_FEATURE_XBARA_OUTPUT2_ID (Dmamux20)
/* @brief XBARA output 3 ID. */
#define FSL_FEATURE_XBARA_OUTPUT3_ID (Dmamux21)
/* @brief XBARA output 4 ID. */
#define FSL_FEATURE_XBARA_OUTPUT4_ID (XbOut4)
/* @brief XBARA output 5 ID. */
#define FSL_FEATURE_XBARA_OUTPUT5_ID (XbOut5)
/* @brief XBARA output 6 ID. */
#define FSL_FEATURE_XBARA_OUTPUT6_ID (XbOut6)
/* @brief XBARA output 7 ID. */
#define FSL_FEATURE_XBARA_OUTPUT7_ID (XbOut7)
/* @brief XBARA output 8 ID. */
#define FSL_FEATURE_XBARA_OUTPUT8_ID (XbOut8)
/* @brief XBARA output 9 ID. */
#define FSL_FEATURE_XBARA_OUTPUT9_ID (XbOut9)
/* @brief XBARA output 10 ID. */
#define FSL_FEATURE_XBARA_OUTPUT10_ID (XbOut10)
/* @brief XBARA output 11 ID. */
#define FSL_FEATURE_XBARA_OUTPUT11_ID (XbOut11)
/* @brief XBARA output 12 ID. */
#define FSL_FEATURE_XBARA_OUTPUT12_ID (Hsadc0ATrig)
/* @brief XBARA output 13 ID. */
#define FSL_FEATURE_XBARA_OUTPUT13_ID (Hsadc0BTrig)
/* @brief XBARA output 14 ID. */
#define FSL_FEATURE_XBARA_OUTPUT14_ID (XBARA_OUT_RESERVED14)
/* @brief XBARA output 15 ID. */
#define FSL_FEATURE_XBARA_OUTPUT15_ID (Dac12bSync)
/* @brief XBARA output 16 ID. */
#define FSL_FEATURE_XBARA_OUTPUT16_ID (Cmp0)
/* @brief XBARA output 17 ID. */
#define FSL_FEATURE_XBARA_OUTPUT17_ID (Cmp1)
/* @brief XBARA output 18 ID. */
#define FSL_FEATURE_XBARA_OUTPUT18_ID (Cmp2)
/* @brief XBARA output 19 ID. */
#define FSL_FEATURE_XBARA_OUTPUT19_ID (Cmp3)
/* @brief XBARA output 20 ID. */
#define FSL_FEATURE_XBARA_OUTPUT20_ID (PwmCh0ExtA)
/* @brief XBARA output 21 ID. */
#define FSL_FEATURE_XBARA_OUTPUT21_ID (PwmCh1ExtA)
/* @brief XBARA output 22 ID. */
#define FSL_FEATURE_XBARA_OUTPUT22_ID (PwmCh2ExtA)
/* @brief XBARA output 23 ID. */
#define FSL_FEATURE_XBARA_OUTPUT23_ID (PwmCh3ExtA)
/* @brief XBARA output 24 ID. */
#define FSL_FEATURE_XBARA_OUTPUT24_ID (Pwm0Ch0ExtSync)
/* @brief XBARA output 25 ID. */
#define FSL_FEATURE_XBARA_OUTPUT25_ID (Pwm0Ch1ExtSync)
/* @brief XBARA output 26 ID. */
#define FSL_FEATURE_XBARA_OUTPUT26_ID (Pwm0Ch2ExtSync)
/* @brief XBARA output 27 ID. */
#define FSL_FEATURE_XBARA_OUTPUT27_ID (Pwm0Ch3ExtSync)
/* @brief XBARA output 28 ID. */
#define FSL_FEATURE_XBARA_OUTPUT28_ID (PwmExtClk)
/* @brief XBARA output 29 ID. */
#define FSL_FEATURE_XBARA_OUTPUT29_ID (Pwm0Fault0)
/* @brief XBARA output 30 ID. */
#define FSL_FEATURE_XBARA_OUTPUT30_ID (Pwm0Fault1)
/* @brief XBARA output 31 ID. */
#define FSL_FEATURE_XBARA_OUTPUT31_ID (Pwm0Fault2)
/* @brief XBARA output 32 ID. */
#define FSL_FEATURE_XBARA_OUTPUT32_ID (Pwm0Fault3)
/* @brief XBARA output 33 ID. */
#define FSL_FEATURE_XBARA_OUTPUT33_ID (Pwm0Force)
/* @brief XBARA output 34 ID. */
#define FSL_FEATURE_XBARA_OUTPUT34_ID (Ftm0Trig2)
/* @brief XBARA output 35 ID. */
#define FSL_FEATURE_XBARA_OUTPUT35_ID (Ftm1Trig2)
/* @brief XBARA output 36 ID. */
#define FSL_FEATURE_XBARA_OUTPUT36_ID (Ftm2Trig2)
/* @brief XBARA output 37 ID. */
#define FSL_FEATURE_XBARA_OUTPUT37_ID (Ftm3Trig2)
/* @brief XBARA output 38 ID. */
#define FSL_FEATURE_XBARA_OUTPUT38_ID (Pdb0InCh12)
/* @brief XBARA output 39 ID. */
#define FSL_FEATURE_XBARA_OUTPUT39_ID (Adc0Hdwt)
/* @brief XBARA output 40 ID. */
#define FSL_FEATURE_XBARA_OUTPUT40_ID (XBARA_OUT_RESERVED40)
/* @brief XBARA output 41 ID. */
#define FSL_FEATURE_XBARA_OUTPUT41_ID (Pdb1InCh12)
/* @brief XBARA output 42 ID. */
#define FSL_FEATURE_XBARA_OUTPUT42_ID (Hsadc1ATrig)
/* @brief XBARA output 43 ID. */
#define FSL_FEATURE_XBARA_OUTPUT43_ID (Hsadc1BTrig)
/* @brief XBARA output 44 ID. */
#define FSL_FEATURE_XBARA_OUTPUT44_ID (EncPhA)
/* @brief XBARA output 45 ID. */
#define FSL_FEATURE_XBARA_OUTPUT45_ID (EncPhB)
/* @brief XBARA output 46 ID. */
#define FSL_FEATURE_XBARA_OUTPUT46_ID (EncIndex)
/* @brief XBARA output 47 ID. */
#define FSL_FEATURE_XBARA_OUTPUT47_ID (EncHome)
/* @brief XBARA output 48 ID. */
#define FSL_FEATURE_XBARA_OUTPUT48_ID (EncCapTrigger)
/* @brief XBARA output 49 ID. */
#define FSL_FEATURE_XBARA_OUTPUT49_ID (Ftm0Fault3)
/* @brief XBARA output 50 ID. */
#define FSL_FEATURE_XBARA_OUTPUT50_ID (Ftm1Fault1)
/* @brief XBARA output 51 ID. */
#define FSL_FEATURE_XBARA_OUTPUT51_ID (Ftm2Fault1)
/* @brief XBARA output 52 ID. */
#define FSL_FEATURE_XBARA_OUTPUT52_ID (Ftm3Fault3)
/* @brief XBARA output 53 ID. */
#define FSL_FEATURE_XBARA_OUTPUT53_ID (Pwm1Ch0ExtSync)
/* @brief XBARA output 54 ID. */
#define FSL_FEATURE_XBARA_OUTPUT54_ID (Pwm1Ch1ExtSync)
/* @brief XBARA output 55 ID. */
#define FSL_FEATURE_XBARA_OUTPUT55_ID (Pwm1Ch2ExtSync)
/* @brief XBARA output 56 ID. */
#define FSL_FEATURE_XBARA_OUTPUT56_ID (Pwm1Ch3ExtSync)
/* @brief XBARA output 57 ID. */
#define FSL_FEATURE_XBARA_OUTPUT57_ID (Pwm1Force)
/* @brief XBARA output 58 ID. */
#define FSL_FEATURE_XBARA_OUTPUT58_ID (EwmIn)
/* @brief XBARA output 59 ID. */
#define FSL_FEATURE_XBARA_OUTPUT59_ID (XBARA_OUT_RESERVED59)
/* @brief XBARA output 60 ID. */
#define FSL_FEATURE_XBARA_OUTPUT60_ID (XBARA_OUT_RESERVED60)
/* @brief XBARA output 61 ID. */
#define FSL_FEATURE_XBARA_OUTPUT61_ID (XBARA_OUT_RESERVED61)
/* @brief XBARA output 62 ID. */
#define FSL_FEATURE_XBARA_OUTPUT62_ID (XBARA_OUT_RESERVED62)
/* @brief XBARA output 63 ID. */
#define FSL_FEATURE_XBARA_OUTPUT63_ID (XBARA_OUT_RESERVED63)
/* @brief XBARA output 64 ID. */
#define FSL_FEATURE_XBARA_OUTPUT64_ID (XBARA_OUT_RESERVED64)
/* @brief XBARA output 65 ID. */
#define FSL_FEATURE_XBARA_OUTPUT65_ID (XBARA_OUT_RESERVED65)
/* @brief XBARA output 66 ID. */
#define FSL_FEATURE_XBARA_OUTPUT66_ID (XBARA_OUT_RESERVED66)
/* @brief XBARA output 67 ID. */
#define FSL_FEATURE_XBARA_OUTPUT67_ID (XBARA_OUT_RESERVED67)
/* @brief XBARA output 68 ID. */
#define FSL_FEATURE_XBARA_OUTPUT68_ID (XBARA_OUT_RESERVED68)
/* @brief XBARA output 69 ID. */
#define FSL_FEATURE_XBARA_OUTPUT69_ID (XBARA_OUT_RESERVED69)
/* @brief XBARA output 70 ID. */
#define FSL_FEATURE_XBARA_OUTPUT70_ID (XBARA_OUT_RESERVED70)
/* @brief XBARA output 71 ID. */
#define FSL_FEATURE_XBARA_OUTPUT71_ID (XBARA_OUT_RESERVED71)
/* @brief XBARA output 72 ID. */
#define FSL_FEATURE_XBARA_OUTPUT72_ID (XBARA_OUT_RESERVED72)
/* @brief XBARA output 73 ID. */
#define FSL_FEATURE_XBARA_OUTPUT73_ID (XBARA_OUT_RESERVED73)
/* @brief XBARA output 74 ID. */
#define FSL_FEATURE_XBARA_OUTPUT74_ID (XBARA_OUT_RESERVED74)
/* @brief XBARA output 75 ID. */
#define FSL_FEATURE_XBARA_OUTPUT75_ID (XBARA_OUT_RESERVED75)
/* @brief XBARA output 76 ID. */
#define FSL_FEATURE_XBARA_OUTPUT76_ID (XBARA_OUT_RESERVED76)
/* @brief XBARA output 77 ID. */
#define FSL_FEATURE_XBARA_OUTPUT77_ID (XBARA_OUT_RESERVED77)
/* @brief XBARA output 78 ID. */
#define FSL_FEATURE_XBARA_OUTPUT78_ID (XBARA_OUT_RESERVED78)
/* @brief XBARA output 79 ID. */
#define FSL_FEATURE_XBARA_OUTPUT79_ID (XBARA_OUT_RESERVED79)
/* @brief XBARA output 80 ID. */
#define FSL_FEATURE_XBARA_OUTPUT80_ID (XBARA_OUT_RESERVED80)
/* @brief XBARA output 81 ID. */
#define FSL_FEATURE_XBARA_OUTPUT81_ID (XBARA_OUT_RESERVED81)
/* @brief XBARA output 82 ID. */
#define FSL_FEATURE_XBARA_OUTPUT82_ID (XBARA_OUT_RESERVED82)
/* @brief XBARA output 83 ID. */
#define FSL_FEATURE_XBARA_OUTPUT83_ID (XBARA_OUT_RESERVED83)
/* @brief XBARA output 84 ID. */
#define FSL_FEATURE_XBARA_OUTPUT84_ID (XBARA_OUT_RESERVED84)
/* @brief XBARA output 85 ID. */
#define FSL_FEATURE_XBARA_OUTPUT85_ID (XBARA_OUT_RESERVED85)
/* @brief XBARA output 86 ID. */
#define FSL_FEATURE_XBARA_OUTPUT86_ID (XBARA_OUT_RESERVED86)
/* @brief XBARA output 87 ID. */
#define FSL_FEATURE_XBARA_OUTPUT87_ID (XBARA_OUT_RESERVED87)
/* @brief XBARA output 88 ID. */
#define FSL_FEATURE_XBARA_OUTPUT88_ID (XBARA_OUT_RESERVED88)
/* @brief XBARA output 89 ID. */
#define FSL_FEATURE_XBARA_OUTPUT89_ID (XBARA_OUT_RESERVED89)
/* @brief XBARA output 90 ID. */
#define FSL_FEATURE_XBARA_OUTPUT90_ID (XBARA_OUT_RESERVED90)
/* @brief XBARA output 91 ID. */
#define FSL_FEATURE_XBARA_OUTPUT91_ID (XBARA_OUT_RESERVED91)
/* @brief XBARA output 92 ID. */
#define FSL_FEATURE_XBARA_OUTPUT92_ID (XBARA_OUT_RESERVED92)
/* @brief XBARA output 93 ID. */
#define FSL_FEATURE_XBARA_OUTPUT93_ID (XBARA_OUT_RESERVED93)
/* @brief XBARA output 94 ID. */
#define FSL_FEATURE_XBARA_OUTPUT94_ID (XBARA_OUT_RESERVED94)
/* @brief XBARA output 95 ID. */
#define FSL_FEATURE_XBARA_OUTPUT95_ID (XBARA_OUT_RESERVED95)
/* @brief XBARA output 96 ID. */
#define FSL_FEATURE_XBARA_OUTPUT96_ID (XBARA_OUT_RESERVED96)
/* @brief XBARA output 97 ID. */
#define FSL_FEATURE_XBARA_OUTPUT97_ID (XBARA_OUT_RESERVED97)
/* @brief XBARA output 98 ID. */
#define FSL_FEATURE_XBARA_OUTPUT98_ID (XBARA_OUT_RESERVED98)
/* @brief XBARA output 99 ID. */
#define FSL_FEATURE_XBARA_OUTPUT99_ID (XBARA_OUT_RESERVED99)
/* @brief XBARA output 100 ID. */
#define FSL_FEATURE_XBARA_OUTPUT100_ID (XBARA_OUT_RESERVED100)
/* @brief XBARA output 101 ID. */
#define FSL_FEATURE_XBARA_OUTPUT101_ID (XBARA_OUT_RESERVED101)
/* @brief XBARA output 102 ID. */
#define FSL_FEATURE_XBARA_OUTPUT102_ID (XBARA_OUT_RESERVED102)
/* @brief XBARA output 103 ID. */
#define FSL_FEATURE_XBARA_OUTPUT103_ID (XBARA_OUT_RESERVED103)
/* @brief XBARA output 104 ID. */
#define FSL_FEATURE_XBARA_OUTPUT104_ID (XBARA_OUT_RESERVED104)
/* @brief XBARA output 105 ID. */
#define FSL_FEATURE_XBARA_OUTPUT105_ID (XBARA_OUT_RESERVED105)
/* @brief XBARA output 106 ID. */
#define FSL_FEATURE_XBARA_OUTPUT106_ID (XBARA_OUT_RESERVED106)
/* @brief XBARA output 107 ID. */
#define FSL_FEATURE_XBARA_OUTPUT107_ID (XBARA_OUT_RESERVED107)
/* @brief XBARA output 108 ID. */
#define FSL_FEATURE_XBARA_OUTPUT108_ID (XBARA_OUT_RESERVED108)
/* @brief XBARA output 109 ID. */
#define FSL_FEATURE_XBARA_OUTPUT109_ID (XBARA_OUT_RESERVED109)
/* @brief XBARA output 110 ID. */
#define FSL_FEATURE_XBARA_OUTPUT110_ID (XBARA_OUT_RESERVED110)
/* @brief XBARA output 111 ID. */
#define FSL_FEATURE_XBARA_OUTPUT111_ID (XBARA_OUT_RESERVED111)
/* @brief XBARA output 112 ID. */
#define FSL_FEATURE_XBARA_OUTPUT112_ID (XBARA_OUT_RESERVED112)
/* @brief XBARA output 113 ID. */
#define FSL_FEATURE_XBARA_OUTPUT113_ID (XBARA_OUT_RESERVED113)
/* @brief XBARA output 114 ID. */
#define FSL_FEATURE_XBARA_OUTPUT114_ID (XBARA_OUT_RESERVED114)
/* @brief XBARA output 115 ID. */
#define FSL_FEATURE_XBARA_OUTPUT115_ID (XBARA_OUT_RESERVED115)
/* @brief XBARA output 116 ID. */
#define FSL_FEATURE_XBARA_OUTPUT116_ID (XBARA_OUT_RESERVED116)
/* @brief XBARA output 117 ID. */
#define FSL_FEATURE_XBARA_OUTPUT117_ID (XBARA_OUT_RESERVED117)
/* @brief XBARA output 118 ID. */
#define FSL_FEATURE_XBARA_OUTPUT118_ID (XBARA_OUT_RESERVED118)
/* @brief XBARA output 119 ID. */
#define FSL_FEATURE_XBARA_OUTPUT119_ID (XBARA_OUT_RESERVED119)
/* @brief XBARA output 120 ID. */
#define FSL_FEATURE_XBARA_OUTPUT120_ID (XBARA_OUT_RESERVED120)
/* @brief XBARA output 121 ID. */
#define FSL_FEATURE_XBARA_OUTPUT121_ID (XBARA_OUT_RESERVED121)
/* @brief XBARA output 122 ID. */
#define FSL_FEATURE_XBARA_OUTPUT122_ID (XBARA_OUT_RESERVED122)
/* @brief XBARA output 123 ID. */
#define FSL_FEATURE_XBARA_OUTPUT123_ID (XBARA_OUT_RESERVED123)
/* @brief XBARA output 124 ID. */
#define FSL_FEATURE_XBARA_OUTPUT124_ID (XBARA_OUT_RESERVED124)
/* @brief XBARA output 125 ID. */
#define FSL_FEATURE_XBARA_OUTPUT125_ID (XBARA_OUT_RESERVED125)
/* @brief XBARA output 126 ID. */
#define FSL_FEATURE_XBARA_OUTPUT126_ID (XBARA_OUT_RESERVED126)
/* @brief XBARA output 127 ID. */
#define FSL_FEATURE_XBARA_OUTPUT127_ID (XBARA_OUT_RESERVED127)

/* XBARB module features */

/* @brief Has single XBAR module. */
#define FSL_FEATURE_XBARB_HAS_SINGLE_MODULE (0)
/* @brief Maximum value of XBARB input. */
#define FSL_FEATURE_XBARB_MODULE_INPUTS (39)
/* @brief Maximum value of XBARB output. */
#define FSL_FEATURE_XBARB_MODULE_OUTPUTS (16)
/* @brief Half register position. */
#define FSL_FEATURE_XBARB_HALF_REGISTER_SHIFT (BP_XBARB_SEL0_SEL1)
/* @brief Number of interrupt requests. */
#define FSL_FEATURE_XBARB_INTERRUPT_COUNT (0)
/* @brief XBARB has input 0. */
#define FSL_FEATURE_XBARB_HAS_INPUT0 (1)
/* @brief XBARB has input 1. */
#define FSL_FEATURE_XBARB_HAS_INPUT1 (1)
/* @brief XBARB has input 2. */
#define FSL_FEATURE_XBARB_HAS_INPUT2 (1)
/* @brief XBARB has input 3. */
#define FSL_FEATURE_XBARB_HAS_INPUT3 (1)
/* @brief XBARB has input 4. */
#define FSL_FEATURE_XBARB_HAS_INPUT4 (1)
/* @brief XBARB has input 5. */
#define FSL_FEATURE_XBARB_HAS_INPUT5 (1)
/* @brief XBARB has input 6. */
#define FSL_FEATURE_XBARB_HAS_INPUT6 (1)
/* @brief XBARB has input 7. */
#define FSL_FEATURE_XBARB_HAS_INPUT7 (1)
/* @brief XBARB has input 8. */
#define FSL_FEATURE_XBARB_HAS_INPUT8 (1)
/* @brief XBARB has input 9. */
#define FSL_FEATURE_XBARB_HAS_INPUT9 (1)
/* @brief XBARB has input 10. */
#define FSL_FEATURE_XBARB_HAS_INPUT10 (1)
/* @brief XBARB has input 11. */
#define FSL_FEATURE_XBARB_HAS_INPUT11 (1)
/* @brief XBARB has input 12. */
#define FSL_FEATURE_XBARB_HAS_INPUT12 (1)
/* @brief XBARB has input 13. */
#define FSL_FEATURE_XBARB_HAS_INPUT13 (1)
/* @brief XBARB has input 14. */
#define FSL_FEATURE_XBARB_HAS_INPUT14 (1)
/* @brief XBARB has input 15. */
#define FSL_FEATURE_XBARB_HAS_INPUT15 (1)
/* @brief XBARB has input 16. */
#define FSL_FEATURE_XBARB_HAS_INPUT16 (1)
/* @brief XBARB has input 17. */
#define FSL_FEATURE_XBARB_HAS_INPUT17 (1)
/* @brief XBARB has input 18. */
#define FSL_FEATURE_XBARB_HAS_INPUT18 (1)
/* @brief XBARB has input 19. */
#define FSL_FEATURE_XBARB_HAS_INPUT19 (1)
/* @brief XBARB has input 20. */
#define FSL_FEATURE_XBARB_HAS_INPUT20 (1)
/* @brief XBARB has input 21. */
#define FSL_FEATURE_XBARB_HAS_INPUT21 (1)
/* @brief XBARB has input 22. */
#define FSL_FEATURE_XBARB_HAS_INPUT22 (1)
/* @brief XBARB has input 23. */
#define FSL_FEATURE_XBARB_HAS_INPUT23 (1)
/* @brief XBARB has input 24. */
#define FSL_FEATURE_XBARB_HAS_INPUT24 (1)
/* @brief XBARB has input 25. */
#define FSL_FEATURE_XBARB_HAS_INPUT25 (1)
/* @brief XBARB has input 26. */
#define FSL_FEATURE_XBARB_HAS_INPUT26 (1)
/* @brief XBARB has input 27. */
#define FSL_FEATURE_XBARB_HAS_INPUT27 (1)
/* @brief XBARB has input 28. */
#define FSL_FEATURE_XBARB_HAS_INPUT28 (1)
/* @brief XBARB has input 29. */
#define FSL_FEATURE_XBARB_HAS_INPUT29 (1)
/* @brief XBARB has input 30. */
#define FSL_FEATURE_XBARB_HAS_INPUT30 (1)
/* @brief XBARB has input 31. */
#define FSL_FEATURE_XBARB_HAS_INPUT31 (1)
/* @brief XBARB has input 32. */
#define FSL_FEATURE_XBARB_HAS_INPUT32 (1)
/* @brief XBARB has input 33. */
#define FSL_FEATURE_XBARB_HAS_INPUT33 (1)
/* @brief XBARB has input 34. */
#define FSL_FEATURE_XBARB_HAS_INPUT34 (1)
/* @brief XBARB has input 35. */
#define FSL_FEATURE_XBARB_HAS_INPUT35 (1)
/* @brief XBARB has input 36. */
#define FSL_FEATURE_XBARB_HAS_INPUT36 (1)
/* @brief XBARB has input 37. */
#define FSL_FEATURE_XBARB_HAS_INPUT37 (1)
/* @brief XBARB has input 38. */
#define FSL_FEATURE_XBARB_HAS_INPUT38 (1)
/* @brief XBARB has input 39. */
#define FSL_FEATURE_XBARB_HAS_INPUT39 (0)
/* @brief XBARB has input 40. */
#define FSL_FEATURE_XBARB_HAS_INPUT40 (0)
/* @brief XBARB has input 41. */
#define FSL_FEATURE_XBARB_HAS_INPUT41 (0)
/* @brief XBARB has input 42. */
#define FSL_FEATURE_XBARB_HAS_INPUT42 (0)
/* @brief XBARB has input 43. */
#define FSL_FEATURE_XBARB_HAS_INPUT43 (0)
/* @brief XBARB has input 44. */
#define FSL_FEATURE_XBARB_HAS_INPUT44 (0)
/* @brief XBARB has input 45. */
#define FSL_FEATURE_XBARB_HAS_INPUT45 (0)
/* @brief XBARB has input 46. */
#define FSL_FEATURE_XBARB_HAS_INPUT46 (0)
/* @brief XBARB has input 47. */
#define FSL_FEATURE_XBARB_HAS_INPUT47 (0)
/* @brief XBARB has input 48. */
#define FSL_FEATURE_XBARB_HAS_INPUT48 (0)
/* @brief XBARB has input 49. */
#define FSL_FEATURE_XBARB_HAS_INPUT49 (0)
/* @brief XBARB has input 50. */
#define FSL_FEATURE_XBARB_HAS_INPUT50 (0)
/* @brief XBARB has input 51. */
#define FSL_FEATURE_XBARB_HAS_INPUT51 (0)
/* @brief XBARB has input 52. */
#define FSL_FEATURE_XBARB_HAS_INPUT52 (0)
/* @brief XBARB has input 53. */
#define FSL_FEATURE_XBARB_HAS_INPUT53 (0)
/* @brief XBARB has input 54. */
#define FSL_FEATURE_XBARB_HAS_INPUT54 (0)
/* @brief XBARB has input 55. */
#define FSL_FEATURE_XBARB_HAS_INPUT55 (0)
/* @brief XBARB has input 56. */
#define FSL_FEATURE_XBARB_HAS_INPUT56 (0)
/* @brief XBARB has input 57. */
#define FSL_FEATURE_XBARB_HAS_INPUT57 (0)
/* @brief XBARB has input 58. */
#define FSL_FEATURE_XBARB_HAS_INPUT58 (0)
/* @brief XBARB has input 59. */
#define FSL_FEATURE_XBARB_HAS_INPUT59 (0)
/* @brief XBARB has input 60. */
#define FSL_FEATURE_XBARB_HAS_INPUT60 (0)
/* @brief XBARB has input 61. */
#define FSL_FEATURE_XBARB_HAS_INPUT61 (0)
/* @brief XBARB has input 62. */
#define FSL_FEATURE_XBARB_HAS_INPUT62 (0)
/* @brief XBARB has input 63. */
#define FSL_FEATURE_XBARB_HAS_INPUT63 (0)
/* @brief XBARB has input 64. */
#define FSL_FEATURE_XBARB_HAS_INPUT64 (0)
/* @brief XBARB has input 65. */
#define FSL_FEATURE_XBARB_HAS_INPUT65 (0)
/* @brief XBARB has input 66. */
#define FSL_FEATURE_XBARB_HAS_INPUT66 (0)
/* @brief XBARB has input 67. */
#define FSL_FEATURE_XBARB_HAS_INPUT67 (0)
/* @brief XBARB has input 68. */
#define FSL_FEATURE_XBARB_HAS_INPUT68 (0)
/* @brief XBARB has input 69. */
#define FSL_FEATURE_XBARB_HAS_INPUT69 (0)
/* @brief XBARB has input 70. */
#define FSL_FEATURE_XBARB_HAS_INPUT70 (0)
/* @brief XBARB has input 71. */
#define FSL_FEATURE_XBARB_HAS_INPUT71 (0)
/* @brief XBARB has input 72. */
#define FSL_FEATURE_XBARB_HAS_INPUT72 (0)
/* @brief XBARB has input 73. */
#define FSL_FEATURE_XBARB_HAS_INPUT73 (0)
/* @brief XBARB has input 74. */
#define FSL_FEATURE_XBARB_HAS_INPUT74 (0)
/* @brief XBARB has input 75. */
#define FSL_FEATURE_XBARB_HAS_INPUT75 (0)
/* @brief XBARB has input 76. */
#define FSL_FEATURE_XBARB_HAS_INPUT76 (0)
/* @brief XBARB has input 77. */
#define FSL_FEATURE_XBARB_HAS_INPUT77 (0)
/* @brief XBARB has input 78. */
#define FSL_FEATURE_XBARB_HAS_INPUT78 (0)
/* @brief XBARB has input 79. */
#define FSL_FEATURE_XBARB_HAS_INPUT79 (0)
/* @brief XBARB has input 80. */
#define FSL_FEATURE_XBARB_HAS_INPUT80 (0)
/* @brief XBARB has input 81. */
#define FSL_FEATURE_XBARB_HAS_INPUT81 (0)
/* @brief XBARB has input 82. */
#define FSL_FEATURE_XBARB_HAS_INPUT82 (0)
/* @brief XBARB has input 83. */
#define FSL_FEATURE_XBARB_HAS_INPUT83 (0)
/* @brief XBARB has input 84. */
#define FSL_FEATURE_XBARB_HAS_INPUT84 (0)
/* @brief XBARB has input 85. */
#define FSL_FEATURE_XBARB_HAS_INPUT85 (0)
/* @brief XBARB has input 86. */
#define FSL_FEATURE_XBARB_HAS_INPUT86 (0)
/* @brief XBARB has input 87. */
#define FSL_FEATURE_XBARB_HAS_INPUT87 (0)
/* @brief XBARB has input 88. */
#define FSL_FEATURE_XBARB_HAS_INPUT88 (0)
/* @brief XBARB has input 89. */
#define FSL_FEATURE_XBARB_HAS_INPUT89 (0)
/* @brief XBARB has input 90. */
#define FSL_FEATURE_XBARB_HAS_INPUT90 (0)
/* @brief XBARB has input 91. */
#define FSL_FEATURE_XBARB_HAS_INPUT91 (0)
/* @brief XBARB has input 92. */
#define FSL_FEATURE_XBARB_HAS_INPUT92 (0)
/* @brief XBARB has input 93. */
#define FSL_FEATURE_XBARB_HAS_INPUT93 (0)
/* @brief XBARB has input 94. */
#define FSL_FEATURE_XBARB_HAS_INPUT94 (0)
/* @brief XBARB has input 95. */
#define FSL_FEATURE_XBARB_HAS_INPUT95 (0)
/* @brief XBARB has input 96. */
#define FSL_FEATURE_XBARB_HAS_INPUT96 (0)
/* @brief XBARB has input 97. */
#define FSL_FEATURE_XBARB_HAS_INPUT97 (0)
/* @brief XBARB has input 98. */
#define FSL_FEATURE_XBARB_HAS_INPUT98 (0)
/* @brief XBARB has input 99. */
#define FSL_FEATURE_XBARB_HAS_INPUT99 (0)
/* @brief XBARB has input 100. */
#define FSL_FEATURE_XBARB_HAS_INPUT100 (0)
/* @brief XBARB has input 101. */
#define FSL_FEATURE_XBARB_HAS_INPUT101 (0)
/* @brief XBARB has input 102. */
#define FSL_FEATURE_XBARB_HAS_INPUT102 (0)
/* @brief XBARB has input 103. */
#define FSL_FEATURE_XBARB_HAS_INPUT103 (0)
/* @brief XBARB has input 104. */
#define FSL_FEATURE_XBARB_HAS_INPUT104 (0)
/* @brief XBARB has input 105. */
#define FSL_FEATURE_XBARB_HAS_INPUT105 (0)
/* @brief XBARB has input 106. */
#define FSL_FEATURE_XBARB_HAS_INPUT106 (0)
/* @brief XBARB has input 107. */
#define FSL_FEATURE_XBARB_HAS_INPUT107 (0)
/* @brief XBARB has input 108. */
#define FSL_FEATURE_XBARB_HAS_INPUT108 (0)
/* @brief XBARB has input 109. */
#define FSL_FEATURE_XBARB_HAS_INPUT109 (0)
/* @brief XBARB has input 110. */
#define FSL_FEATURE_XBARB_HAS_INPUT110 (0)
/* @brief XBARB has input 111. */
#define FSL_FEATURE_XBARB_HAS_INPUT111 (0)
/* @brief XBARB has input 112. */
#define FSL_FEATURE_XBARB_HAS_INPUT112 (0)
/* @brief XBARB has input 113. */
#define FSL_FEATURE_XBARB_HAS_INPUT113 (0)
/* @brief XBARB has input 114. */
#define FSL_FEATURE_XBARB_HAS_INPUT114 (0)
/* @brief XBARB has input 115. */
#define FSL_FEATURE_XBARB_HAS_INPUT115 (0)
/* @brief XBARB has input 116. */
#define FSL_FEATURE_XBARB_HAS_INPUT116 (0)
/* @brief XBARB has input 117. */
#define FSL_FEATURE_XBARB_HAS_INPUT117 (0)
/* @brief XBARB has input 118. */
#define FSL_FEATURE_XBARB_HAS_INPUT118 (0)
/* @brief XBARB has input 119. */
#define FSL_FEATURE_XBARB_HAS_INPUT119 (0)
/* @brief XBARB has input 120. */
#define FSL_FEATURE_XBARB_HAS_INPUT120 (0)
/* @brief XBARB has input 121. */
#define FSL_FEATURE_XBARB_HAS_INPUT121 (0)
/* @brief XBARB has input 122. */
#define FSL_FEATURE_XBARB_HAS_INPUT122 (0)
/* @brief XBARB has input 123. */
#define FSL_FEATURE_XBARB_HAS_INPUT123 (0)
/* @brief XBARB has input 124. */
#define FSL_FEATURE_XBARB_HAS_INPUT124 (0)
/* @brief XBARB has input 125. */
#define FSL_FEATURE_XBARB_HAS_INPUT125 (0)
/* @brief XBARB has input 126. */
#define FSL_FEATURE_XBARB_HAS_INPUT126 (0)
/* @brief XBARB has input 127. */
#define FSL_FEATURE_XBARB_HAS_INPUT127 (0)
/* @brief XBARB has output 0. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT0 (1)
/* @brief XBARB has output 1. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT1 (1)
/* @brief XBARB has output 2. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT2 (1)
/* @brief XBARB has output 3. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT3 (1)
/* @brief XBARB has output 4. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT4 (1)
/* @brief XBARB has output 5. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT5 (1)
/* @brief XBARB has output 6. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT6 (1)
/* @brief XBARB has output 7. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT7 (1)
/* @brief XBARB has output 8. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT8 (1)
/* @brief XBARB has output 9. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT9 (1)
/* @brief XBARB has output 10. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT10 (1)
/* @brief XBARB has output 11. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT11 (1)
/* @brief XBARB has output 12. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT12 (1)
/* @brief XBARB has output 13. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT13 (1)
/* @brief XBARB has output 14. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT14 (1)
/* @brief XBARB has output 15. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT15 (1)
/* @brief XBARB has output 16. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT16 (0)
/* @brief XBARB has output 17. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT17 (0)
/* @brief XBARB has output 18. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT18 (0)
/* @brief XBARB has output 19. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT19 (0)
/* @brief XBARB has output 20. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT20 (0)
/* @brief XBARB has output 21. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT21 (0)
/* @brief XBARB has output 22. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT22 (0)
/* @brief XBARB has output 23. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT23 (0)
/* @brief XBARB has output 24. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT24 (0)
/* @brief XBARB has output 25. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT25 (0)
/* @brief XBARB has output 26. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT26 (0)
/* @brief XBARB has output 27. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT27 (0)
/* @brief XBARB has output 28. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT28 (0)
/* @brief XBARB has output 29. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT29 (0)
/* @brief XBARB has output 30. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT30 (0)
/* @brief XBARB has output 31. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT31 (0)
/* @brief XBARB has output 32. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT32 (0)
/* @brief XBARB has output 33. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT33 (0)
/* @brief XBARB has output 34. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT34 (0)
/* @brief XBARB has output 35. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT35 (0)
/* @brief XBARB has output 36. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT36 (0)
/* @brief XBARB has output 37. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT37 (0)
/* @brief XBARB has output 38. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT38 (0)
/* @brief XBARB has output 39. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT39 (0)
/* @brief XBARB has output 40. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT40 (0)
/* @brief XBARB has output 41. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT41 (0)
/* @brief XBARB has output 42. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT42 (0)
/* @brief XBARB has output 43. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT43 (0)
/* @brief XBARB has output 44. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT44 (0)
/* @brief XBARB has output 45. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT45 (0)
/* @brief XBARB has output 46. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT46 (0)
/* @brief XBARB has output 47. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT47 (0)
/* @brief XBARB has output 48. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT48 (0)
/* @brief XBARB has output 49. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT49 (0)
/* @brief XBARB has output 50. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT50 (0)
/* @brief XBARB has output 51. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT51 (0)
/* @brief XBARB has output 52. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT52 (0)
/* @brief XBARB has output 53. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT53 (0)
/* @brief XBARB has output 54. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT54 (0)
/* @brief XBARB has output 55. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT55 (0)
/* @brief XBARB has output 56. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT56 (0)
/* @brief XBARB has output 57. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT57 (0)
/* @brief XBARB has output 58. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT58 (0)
/* @brief XBARB has output 59. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT59 (0)
/* @brief XBARB has output 60. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT60 (0)
/* @brief XBARB has output 61. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT61 (0)
/* @brief XBARB has output 62. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT62 (0)
/* @brief XBARB has output 63. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT63 (0)
/* @brief XBARB has output 64. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT64 (0)
/* @brief XBARB has output 65. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT65 (0)
/* @brief XBARB has output 66. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT66 (0)
/* @brief XBARB has output 67. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT67 (0)
/* @brief XBARB has output 68. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT68 (0)
/* @brief XBARB has output 69. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT69 (0)
/* @brief XBARB has output 70. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT70 (0)
/* @brief XBARB has output 71. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT71 (0)
/* @brief XBARB has output 72. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT72 (0)
/* @brief XBARB has output 73. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT73 (0)
/* @brief XBARB has output 74. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT74 (0)
/* @brief XBARB has output 75. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT75 (0)
/* @brief XBARB has output 76. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT76 (0)
/* @brief XBARB has output 77. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT77 (0)
/* @brief XBARB has output 78. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT78 (0)
/* @brief XBARB has output 79. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT79 (0)
/* @brief XBARB has output 80. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT80 (0)
/* @brief XBARB has output 81. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT81 (0)
/* @brief XBARB has output 82. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT82 (0)
/* @brief XBARB has output 83. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT83 (0)
/* @brief XBARB has output 84. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT84 (0)
/* @brief XBARB has output 85. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT85 (0)
/* @brief XBARB has output 86. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT86 (0)
/* @brief XBARB has output 87. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT87 (0)
/* @brief XBARB has output 88. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT88 (0)
/* @brief XBARB has output 89. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT89 (0)
/* @brief XBARB has output 90. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT90 (0)
/* @brief XBARB has output 91. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT91 (0)
/* @brief XBARB has output 92. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT92 (0)
/* @brief XBARB has output 93. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT93 (0)
/* @brief XBARB has output 94. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT94 (0)
/* @brief XBARB has output 95. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT95 (0)
/* @brief XBARB has output 96. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT96 (0)
/* @brief XBARB has output 97. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT97 (0)
/* @brief XBARB has output 98. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT98 (0)
/* @brief XBARB has output 99. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT99 (0)
/* @brief XBARB has output 100. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT100 (0)
/* @brief XBARB has output 101. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT101 (0)
/* @brief XBARB has output 102. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT102 (0)
/* @brief XBARB has output 103. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT103 (0)
/* @brief XBARB has output 104. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT104 (0)
/* @brief XBARB has output 105. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT105 (0)
/* @brief XBARB has output 106. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT106 (0)
/* @brief XBARB has output 107. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT107 (0)
/* @brief XBARB has output 108. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT108 (0)
/* @brief XBARB has output 109. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT109 (0)
/* @brief XBARB has output 110. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT110 (0)
/* @brief XBARB has output 111. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT111 (0)
/* @brief XBARB has output 112. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT112 (0)
/* @brief XBARB has output 113. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT113 (0)
/* @brief XBARB has output 114. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT114 (0)
/* @brief XBARB has output 115. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT115 (0)
/* @brief XBARB has output 116. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT116 (0)
/* @brief XBARB has output 117. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT117 (0)
/* @brief XBARB has output 118. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT118 (0)
/* @brief XBARB has output 119. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT119 (0)
/* @brief XBARB has output 120. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT120 (0)
/* @brief XBARB has output 121. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT121 (0)
/* @brief XBARB has output 122. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT122 (0)
/* @brief XBARB has output 123. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT123 (0)
/* @brief XBARB has output 124. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT124 (0)
/* @brief XBARB has output 125. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT125 (0)
/* @brief XBARB has output 126. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT126 (0)
/* @brief XBARB has output 127. */
#define FSL_FEATURE_XBARB_HAS_OUTPUT127 (0)
/* @brief XBARB input 0 ID. */
#define FSL_FEATURE_XBARB_INPUT0_ID (Cmp0Output)
/* @brief XBARB input 1 ID. */
#define FSL_FEATURE_XBARB_INPUT1_ID (Cmp1Output)
/* @brief XBARB input 2 ID. */
#define FSL_FEATURE_XBARB_INPUT2_ID (Cmp2Output)
/* @brief XBARB input 3 ID. */
#define FSL_FEATURE_XBARB_INPUT3_ID (Cmp3Output)
/* @brief XBARB input 4 ID. */
#define FSL_FEATURE_XBARB_INPUT4_ID (Ftm0Match)
/* @brief XBARB input 5 ID. */
#define FSL_FEATURE_XBARB_INPUT5_ID (Ftm0Extrig)
/* @brief XBARB input 6 ID. */
#define FSL_FEATURE_XBARB_INPUT6_ID (Ftm3Match)
/* @brief XBARB input 7 ID. */
#define FSL_FEATURE_XBARB_INPUT7_ID (Ftm3Extrig)
/* @brief XBARB input 8 ID. */
#define FSL_FEATURE_XBARB_INPUT8_ID (Pwm0Ch0Trg0)
/* @brief XBARB input 9 ID. */
#define FSL_FEATURE_XBARB_INPUT9_ID (Pwm0Ch1Trg0)
/* @brief XBARB input 10 ID. */
#define FSL_FEATURE_XBARB_INPUT10_ID (Pwm0Ch2Trg0)
/* @brief XBARB input 11 ID. */
#define FSL_FEATURE_XBARB_INPUT11_ID (Pwm0Ch3Trg0)
/* @brief XBARB input 12 ID. */
#define FSL_FEATURE_XBARB_INPUT12_ID (Pdb0Ch0Output)
/* @brief XBARB input 13 ID. */
#define FSL_FEATURE_XBARB_INPUT13_ID (Hsadc0Cca)
/* @brief XBARB input 14 ID. */
#define FSL_FEATURE_XBARB_INPUT14_ID (XbarIn2)
/* @brief XBARB input 15 ID. */
#define FSL_FEATURE_XBARB_INPUT15_ID (XbarIn3)
/* @brief XBARB input 16 ID. */
#define FSL_FEATURE_XBARB_INPUT16_ID (Ftm1Match)
/* @brief XBARB input 17 ID. */
#define FSL_FEATURE_XBARB_INPUT17_ID (Ftm1Extrig)
/* @brief XBARB input 18 ID. */
#define FSL_FEATURE_XBARB_INPUT18_ID (DmaCh0Done)
/* @brief XBARB input 19 ID. */
#define FSL_FEATURE_XBARB_INPUT19_ID (DmaCh1Done)
/* @brief XBARB input 20 ID. */
#define FSL_FEATURE_XBARB_INPUT20_ID (XbarIn10)
/* @brief XBARB input 21 ID. */
#define FSL_FEATURE_XBARB_INPUT21_ID (XbarIn11)
/* @brief XBARB input 22 ID. */
#define FSL_FEATURE_XBARB_INPUT22_ID (DmaCh6Done)
/* @brief XBARB input 23 ID. */
#define FSL_FEATURE_XBARB_INPUT23_ID (DmaCh7Done)
/* @brief XBARB input 24 ID. */
#define FSL_FEATURE_XBARB_INPUT24_ID (PitTrigger0)
/* @brief XBARB input 25 ID. */
#define FSL_FEATURE_XBARB_INPUT25_ID (PitTrigger1)
/* @brief XBARB input 26 ID. */
#define FSL_FEATURE_XBARB_INPUT26_ID (Pdb1Ch0Output)
/* @brief XBARB input 27 ID. */
#define FSL_FEATURE_XBARB_INPUT27_ID (Hsadc0Ccb)
/* @brief XBARB input 28 ID. */
#define FSL_FEATURE_XBARB_INPUT28_ID (Pwm1Ch0Trg0OrTrg1)
/* @brief XBARB input 29 ID. */
#define FSL_FEATURE_XBARB_INPUT29_ID (Pwm1Ch1Trg0OrTrg1)
/* @brief XBARB input 30 ID. */
#define FSL_FEATURE_XBARB_INPUT30_ID (Pwm1Ch2Trg0OrTrg1)
/* @brief XBARB input 31 ID. */
#define FSL_FEATURE_XBARB_INPUT31_ID (Pwm1Ch3Trg0OrTrg1)
/* @brief XBARB input 32 ID. */
#define FSL_FEATURE_XBARB_INPUT32_ID (Ftm2Match)
/* @brief XBARB input 33 ID. */
#define FSL_FEATURE_XBARB_INPUT33_ID (Ftm2Extrig)
/* @brief XBARB input 34 ID. */
#define FSL_FEATURE_XBARB_INPUT34_ID (Pdb0Ch1Output)
/* @brief XBARB input 35 ID. */
#define FSL_FEATURE_XBARB_INPUT35_ID (Pdb1Ch1Output)
/* @brief XBARB input 36 ID. */
#define FSL_FEATURE_XBARB_INPUT36_ID (Hsadc1Cca)
/* @brief XBARB input 37 ID. */
#define FSL_FEATURE_XBARB_INPUT37_ID (Hsadc1Ccb)
/* @brief XBARB input 38 ID. */
#define FSL_FEATURE_XBARB_INPUT38_ID (Adc0Coco)
/* @brief XBARB input 39 ID. */
#define FSL_FEATURE_XBARB_INPUT39_ID (XBARB_IN_RESERVED39)
/* @brief XBARB input 40 ID. */
#define FSL_FEATURE_XBARB_INPUT40_ID (XBARB_IN_RESERVED40)
/* @brief XBARB input 41 ID. */
#define FSL_FEATURE_XBARB_INPUT41_ID (XBARB_IN_RESERVED41)
/* @brief XBARB input 42 ID. */
#define FSL_FEATURE_XBARB_INPUT42_ID (XBARB_IN_RESERVED42)
/* @brief XBARB input 43 ID. */
#define FSL_FEATURE_XBARB_INPUT43_ID (XBARB_IN_RESERVED43)
/* @brief XBARB input 44 ID. */
#define FSL_FEATURE_XBARB_INPUT44_ID (XBARB_IN_RESERVED44)
/* @brief XBARB input 45 ID. */
#define FSL_FEATURE_XBARB_INPUT45_ID (XBARB_IN_RESERVED45)
/* @brief XBARB input 46 ID. */
#define FSL_FEATURE_XBARB_INPUT46_ID (XBARB_IN_RESERVED46)
/* @brief XBARB input 47 ID. */
#define FSL_FEATURE_XBARB_INPUT47_ID (XBARB_IN_RESERVED47)
/* @brief XBARB input 48 ID. */
#define FSL_FEATURE_XBARB_INPUT48_ID (XBARB_IN_RESERVED48)
/* @brief XBARB input 49 ID. */
#define FSL_FEATURE_XBARB_INPUT49_ID (XBARB_IN_RESERVED49)
/* @brief XBARB input 50 ID. */
#define FSL_FEATURE_XBARB_INPUT50_ID (XBARB_IN_RESERVED50)
/* @brief XBARB input 51 ID. */
#define FSL_FEATURE_XBARB_INPUT51_ID (XBARB_IN_RESERVED51)
/* @brief XBARB input 52 ID. */
#define FSL_FEATURE_XBARB_INPUT52_ID (XBARB_IN_RESERVED52)
/* @brief XBARB input 53 ID. */
#define FSL_FEATURE_XBARB_INPUT53_ID (XBARB_IN_RESERVED53)
/* @brief XBARB input 54 ID. */
#define FSL_FEATURE_XBARB_INPUT54_ID (XBARB_IN_RESERVED54)
/* @brief XBARB input 55 ID. */
#define FSL_FEATURE_XBARB_INPUT55_ID (XBARB_IN_RESERVED55)
/* @brief XBARB input 56 ID. */
#define FSL_FEATURE_XBARB_INPUT56_ID (XBARB_IN_RESERVED56)
/* @brief XBARB input 57 ID. */
#define FSL_FEATURE_XBARB_INPUT57_ID (XBARB_IN_RESERVED57)
/* @brief XBARB input 58 ID. */
#define FSL_FEATURE_XBARB_INPUT58_ID (XBARB_IN_RESERVED58)
/* @brief XBARB input 59 ID. */
#define FSL_FEATURE_XBARB_INPUT59_ID (XBARB_IN_RESERVED59)
/* @brief XBARB input 60 ID. */
#define FSL_FEATURE_XBARB_INPUT60_ID (XBARB_IN_RESERVED60)
/* @brief XBARB input 61 ID. */
#define FSL_FEATURE_XBARB_INPUT61_ID (XBARB_IN_RESERVED61)
/* @brief XBARB input 62 ID. */
#define FSL_FEATURE_XBARB_INPUT62_ID (XBARB_IN_RESERVED62)
/* @brief XBARB input 63 ID. */
#define FSL_FEATURE_XBARB_INPUT63_ID (XBARB_IN_RESERVED63)
/* @brief XBARB input 64 ID. */
#define FSL_FEATURE_XBARB_INPUT64_ID (XBARB_IN_RESERVED64)
/* @brief XBARB input 65 ID. */
#define FSL_FEATURE_XBARB_INPUT65_ID (XBARB_IN_RESERVED65)
/* @brief XBARB input 66 ID. */
#define FSL_FEATURE_XBARB_INPUT66_ID (XBARB_IN_RESERVED66)
/* @brief XBARB input 67 ID. */
#define FSL_FEATURE_XBARB_INPUT67_ID (XBARB_IN_RESERVED67)
/* @brief XBARB input 68 ID. */
#define FSL_FEATURE_XBARB_INPUT68_ID (XBARB_IN_RESERVED68)
/* @brief XBARB input 69 ID. */
#define FSL_FEATURE_XBARB_INPUT69_ID (XBARB_IN_RESERVED69)
/* @brief XBARB input 70 ID. */
#define FSL_FEATURE_XBARB_INPUT70_ID (XBARB_IN_RESERVED70)
/* @brief XBARB input 71 ID. */
#define FSL_FEATURE_XBARB_INPUT71_ID (XBARB_IN_RESERVED71)
/* @brief XBARB input 72 ID. */
#define FSL_FEATURE_XBARB_INPUT72_ID (XBARB_IN_RESERVED72)
/* @brief XBARB input 73 ID. */
#define FSL_FEATURE_XBARB_INPUT73_ID (XBARB_IN_RESERVED73)
/* @brief XBARB input 74 ID. */
#define FSL_FEATURE_XBARB_INPUT74_ID (XBARB_IN_RESERVED74)
/* @brief XBARB input 75 ID. */
#define FSL_FEATURE_XBARB_INPUT75_ID (XBARB_IN_RESERVED75)
/* @brief XBARB input 76 ID. */
#define FSL_FEATURE_XBARB_INPUT76_ID (XBARB_IN_RESERVED76)
/* @brief XBARB input 77 ID. */
#define FSL_FEATURE_XBARB_INPUT77_ID (XBARB_IN_RESERVED77)
/* @brief XBARB input 78 ID. */
#define FSL_FEATURE_XBARB_INPUT78_ID (XBARB_IN_RESERVED78)
/* @brief XBARB input 79 ID. */
#define FSL_FEATURE_XBARB_INPUT79_ID (XBARB_IN_RESERVED79)
/* @brief XBARB input 80 ID. */
#define FSL_FEATURE_XBARB_INPUT80_ID (XBARB_IN_RESERVED80)
/* @brief XBARB input 81 ID. */
#define FSL_FEATURE_XBARB_INPUT81_ID (XBARB_IN_RESERVED81)
/* @brief XBARB input 82 ID. */
#define FSL_FEATURE_XBARB_INPUT82_ID (XBARB_IN_RESERVED82)
/* @brief XBARB input 83 ID. */
#define FSL_FEATURE_XBARB_INPUT83_ID (XBARB_IN_RESERVED83)
/* @brief XBARB input 84 ID. */
#define FSL_FEATURE_XBARB_INPUT84_ID (XBARB_IN_RESERVED84)
/* @brief XBARB input 85 ID. */
#define FSL_FEATURE_XBARB_INPUT85_ID (XBARB_IN_RESERVED85)
/* @brief XBARB input 86 ID. */
#define FSL_FEATURE_XBARB_INPUT86_ID (XBARB_IN_RESERVED86)
/* @brief XBARB input 87 ID. */
#define FSL_FEATURE_XBARB_INPUT87_ID (XBARB_IN_RESERVED87)
/* @brief XBARB input 88 ID. */
#define FSL_FEATURE_XBARB_INPUT88_ID (XBARB_IN_RESERVED88)
/* @brief XBARB input 89 ID. */
#define FSL_FEATURE_XBARB_INPUT89_ID (XBARB_IN_RESERVED89)
/* @brief XBARB input 90 ID. */
#define FSL_FEATURE_XBARB_INPUT90_ID (XBARB_IN_RESERVED90)
/* @brief XBARB input 91 ID. */
#define FSL_FEATURE_XBARB_INPUT91_ID (XBARB_IN_RESERVED91)
/* @brief XBARB input 92 ID. */
#define FSL_FEATURE_XBARB_INPUT92_ID (XBARB_IN_RESERVED92)
/* @brief XBARB input 93 ID. */
#define FSL_FEATURE_XBARB_INPUT93_ID (XBARB_IN_RESERVED93)
/* @brief XBARB input 94 ID. */
#define FSL_FEATURE_XBARB_INPUT94_ID (XBARB_IN_RESERVED94)
/* @brief XBARB input 95 ID. */
#define FSL_FEATURE_XBARB_INPUT95_ID (XBARB_IN_RESERVED95)
/* @brief XBARB input 96 ID. */
#define FSL_FEATURE_XBARB_INPUT96_ID (XBARB_IN_RESERVED96)
/* @brief XBARB input 97 ID. */
#define FSL_FEATURE_XBARB_INPUT97_ID (XBARB_IN_RESERVED97)
/* @brief XBARB input 98 ID. */
#define FSL_FEATURE_XBARB_INPUT98_ID (XBARB_IN_RESERVED98)
/* @brief XBARB input 99 ID. */
#define FSL_FEATURE_XBARB_INPUT99_ID (XBARB_IN_RESERVED99)
/* @brief XBARB input 100 ID. */
#define FSL_FEATURE_XBARB_INPUT100_ID (XBARB_IN_RESERVED100)
/* @brief XBARB input 101 ID. */
#define FSL_FEATURE_XBARB_INPUT101_ID (XBARB_IN_RESERVED101)
/* @brief XBARB input 102 ID. */
#define FSL_FEATURE_XBARB_INPUT102_ID (XBARB_IN_RESERVED102)
/* @brief XBARB input 103 ID. */
#define FSL_FEATURE_XBARB_INPUT103_ID (XBARB_IN_RESERVED103)
/* @brief XBARB input 104 ID. */
#define FSL_FEATURE_XBARB_INPUT104_ID (XBARB_IN_RESERVED104)
/* @brief XBARB input 105 ID. */
#define FSL_FEATURE_XBARB_INPUT105_ID (XBARB_IN_RESERVED105)
/* @brief XBARB input 106 ID. */
#define FSL_FEATURE_XBARB_INPUT106_ID (XBARB_IN_RESERVED106)
/* @brief XBARB input 107 ID. */
#define FSL_FEATURE_XBARB_INPUT107_ID (XBARB_IN_RESERVED107)
/* @brief XBARB input 108 ID. */
#define FSL_FEATURE_XBARB_INPUT108_ID (XBARB_IN_RESERVED108)
/* @brief XBARB input 109 ID. */
#define FSL_FEATURE_XBARB_INPUT109_ID (XBARB_IN_RESERVED109)
/* @brief XBARB input 110 ID. */
#define FSL_FEATURE_XBARB_INPUT110_ID (XBARB_IN_RESERVED110)
/* @brief XBARB input 111 ID. */
#define FSL_FEATURE_XBARB_INPUT111_ID (XBARB_IN_RESERVED111)
/* @brief XBARB input 112 ID. */
#define FSL_FEATURE_XBARB_INPUT112_ID (XBARB_IN_RESERVED112)
/* @brief XBARB input 113 ID. */
#define FSL_FEATURE_XBARB_INPUT113_ID (XBARB_IN_RESERVED113)
/* @brief XBARB input 114 ID. */
#define FSL_FEATURE_XBARB_INPUT114_ID (XBARB_IN_RESERVED114)
/* @brief XBARB input 115 ID. */
#define FSL_FEATURE_XBARB_INPUT115_ID (XBARB_IN_RESERVED115)
/* @brief XBARB input 116 ID. */
#define FSL_FEATURE_XBARB_INPUT116_ID (XBARB_IN_RESERVED116)
/* @brief XBARB input 117 ID. */
#define FSL_FEATURE_XBARB_INPUT117_ID (XBARB_IN_RESERVED117)
/* @brief XBARB input 118 ID. */
#define FSL_FEATURE_XBARB_INPUT118_ID (XBARB_IN_RESERVED118)
/* @brief XBARB input 119 ID. */
#define FSL_FEATURE_XBARB_INPUT119_ID (XBARB_IN_RESERVED119)
/* @brief XBARB input 120 ID. */
#define FSL_FEATURE_XBARB_INPUT120_ID (XBARB_IN_RESERVED120)
/* @brief XBARB input 121 ID. */
#define FSL_FEATURE_XBARB_INPUT121_ID (XBARB_IN_RESERVED121)
/* @brief XBARB input 122 ID. */
#define FSL_FEATURE_XBARB_INPUT122_ID (XBARB_IN_RESERVED122)
/* @brief XBARB input 123 ID. */
#define FSL_FEATURE_XBARB_INPUT123_ID (XBARB_IN_RESERVED123)
/* @brief XBARB input 124 ID. */
#define FSL_FEATURE_XBARB_INPUT124_ID (XBARB_IN_RESERVED124)
/* @brief XBARB input 125 ID. */
#define FSL_FEATURE_XBARB_INPUT125_ID (XBARB_IN_RESERVED125)
/* @brief XBARB input 126 ID. */
#define FSL_FEATURE_XBARB_INPUT126_ID (XBARB_IN_RESERVED126)
/* @brief XBARB input 127 ID. */
#define FSL_FEATURE_XBARB_INPUT127_ID (XBARB_IN_RESERVED127)
/* @brief XBARB output 0 ID. */
#define FSL_FEATURE_XBARB_OUTPUT0_ID (AoiIn0)
/* @brief XBARB output 1 ID. */
#define FSL_FEATURE_XBARB_OUTPUT1_ID (AoiIn1)
/* @brief XBARB output 2 ID. */
#define FSL_FEATURE_XBARB_OUTPUT2_ID (AoiIn2)
/* @brief XBARB output 3 ID. */
#define FSL_FEATURE_XBARB_OUTPUT3_ID (AoiIn3)
/* @brief XBARB output 4 ID. */
#define FSL_FEATURE_XBARB_OUTPUT4_ID (AoiIn4)
/* @brief XBARB output 5 ID. */
#define FSL_FEATURE_XBARB_OUTPUT5_ID (AoiIn5)
/* @brief XBARB output 6 ID. */
#define FSL_FEATURE_XBARB_OUTPUT6_ID (AoiIn6)
/* @brief XBARB output 7 ID. */
#define FSL_FEATURE_XBARB_OUTPUT7_ID (AoiIn7)
/* @brief XBARB output 8 ID. */
#define FSL_FEATURE_XBARB_OUTPUT8_ID (AoiIn8)
/* @brief XBARB output 9 ID. */
#define FSL_FEATURE_XBARB_OUTPUT9_ID (AoiIn9)
/* @brief XBARB output 10 ID. */
#define FSL_FEATURE_XBARB_OUTPUT10_ID (AoiIn10)
/* @brief XBARB output 11 ID. */
#define FSL_FEATURE_XBARB_OUTPUT11_ID (AoiIn11)
/* @brief XBARB output 12 ID. */
#define FSL_FEATURE_XBARB_OUTPUT12_ID (AoiIn12)
/* @brief XBARB output 13 ID. */
#define FSL_FEATURE_XBARB_OUTPUT13_ID (AoiIn13)
/* @brief XBARB output 14 ID. */
#define FSL_FEATURE_XBARB_OUTPUT14_ID (AoiIn14)
/* @brief XBARB output 15 ID. */
#define FSL_FEATURE_XBARB_OUTPUT15_ID (AoiIn15)
/* @brief XBARB output 16 ID. */
#define FSL_FEATURE_XBARB_OUTPUT16_ID (XBARB_OUT_RESERVED16)
/* @brief XBARB output 17 ID. */
#define FSL_FEATURE_XBARB_OUTPUT17_ID (XBARB_OUT_RESERVED17)
/* @brief XBARB output 18 ID. */
#define FSL_FEATURE_XBARB_OUTPUT18_ID (XBARB_OUT_RESERVED18)
/* @brief XBARB output 19 ID. */
#define FSL_FEATURE_XBARB_OUTPUT19_ID (XBARB_OUT_RESERVED19)
/* @brief XBARB output 20 ID. */
#define FSL_FEATURE_XBARB_OUTPUT20_ID (XBARB_OUT_RESERVED20)
/* @brief XBARB output 21 ID. */
#define FSL_FEATURE_XBARB_OUTPUT21_ID (XBARB_OUT_RESERVED21)
/* @brief XBARB output 22 ID. */
#define FSL_FEATURE_XBARB_OUTPUT22_ID (XBARB_OUT_RESERVED22)
/* @brief XBARB output 23 ID. */
#define FSL_FEATURE_XBARB_OUTPUT23_ID (XBARB_OUT_RESERVED23)
/* @brief XBARB output 24 ID. */
#define FSL_FEATURE_XBARB_OUTPUT24_ID (XBARB_OUT_RESERVED24)
/* @brief XBARB output 25 ID. */
#define FSL_FEATURE_XBARB_OUTPUT25_ID (XBARB_OUT_RESERVED25)
/* @brief XBARB output 26 ID. */
#define FSL_FEATURE_XBARB_OUTPUT26_ID (XBARB_OUT_RESERVED26)
/* @brief XBARB output 27 ID. */
#define FSL_FEATURE_XBARB_OUTPUT27_ID (XBARB_OUT_RESERVED27)
/* @brief XBARB output 28 ID. */
#define FSL_FEATURE_XBARB_OUTPUT28_ID (XBARB_OUT_RESERVED28)
/* @brief XBARB output 29 ID. */
#define FSL_FEATURE_XBARB_OUTPUT29_ID (XBARB_OUT_RESERVED29)
/* @brief XBARB output 30 ID. */
#define FSL_FEATURE_XBARB_OUTPUT30_ID (XBARB_OUT_RESERVED30)
/* @brief XBARB output 31 ID. */
#define FSL_FEATURE_XBARB_OUTPUT31_ID (XBARB_OUT_RESERVED31)
/* @brief XBARB output 32 ID. */
#define FSL_FEATURE_XBARB_OUTPUT32_ID (XBARB_OUT_RESERVED32)
/* @brief XBARB output 33 ID. */
#define FSL_FEATURE_XBARB_OUTPUT33_ID (XBARB_OUT_RESERVED33)
/* @brief XBARB output 34 ID. */
#define FSL_FEATURE_XBARB_OUTPUT34_ID (XBARB_OUT_RESERVED34)
/* @brief XBARB output 35 ID. */
#define FSL_FEATURE_XBARB_OUTPUT35_ID (XBARB_OUT_RESERVED35)
/* @brief XBARB output 36 ID. */
#define FSL_FEATURE_XBARB_OUTPUT36_ID (XBARB_OUT_RESERVED36)
/* @brief XBARB output 37 ID. */
#define FSL_FEATURE_XBARB_OUTPUT37_ID (XBARB_OUT_RESERVED37)
/* @brief XBARB output 38 ID. */
#define FSL_FEATURE_XBARB_OUTPUT38_ID (XBARB_OUT_RESERVED38)
/* @brief XBARB output 39 ID. */
#define FSL_FEATURE_XBARB_OUTPUT39_ID (XBARB_OUT_RESERVED39)
/* @brief XBARB output 40 ID. */
#define FSL_FEATURE_XBARB_OUTPUT40_ID (XBARB_OUT_RESERVED40)
/* @brief XBARB output 41 ID. */
#define FSL_FEATURE_XBARB_OUTPUT41_ID (XBARB_OUT_RESERVED41)
/* @brief XBARB output 42 ID. */
#define FSL_FEATURE_XBARB_OUTPUT42_ID (XBARB_OUT_RESERVED42)
/* @brief XBARB output 43 ID. */
#define FSL_FEATURE_XBARB_OUTPUT43_ID (XBARB_OUT_RESERVED43)
/* @brief XBARB output 44 ID. */
#define FSL_FEATURE_XBARB_OUTPUT44_ID (XBARB_OUT_RESERVED44)
/* @brief XBARB output 45 ID. */
#define FSL_FEATURE_XBARB_OUTPUT45_ID (XBARB_OUT_RESERVED45)
/* @brief XBARB output 46 ID. */
#define FSL_FEATURE_XBARB_OUTPUT46_ID (XBARB_OUT_RESERVED46)
/* @brief XBARB output 47 ID. */
#define FSL_FEATURE_XBARB_OUTPUT47_ID (XBARB_OUT_RESERVED47)
/* @brief XBARB output 48 ID. */
#define FSL_FEATURE_XBARB_OUTPUT48_ID (XBARB_OUT_RESERVED48)
/* @brief XBARB output 49 ID. */
#define FSL_FEATURE_XBARB_OUTPUT49_ID (XBARB_OUT_RESERVED49)
/* @brief XBARB output 50 ID. */
#define FSL_FEATURE_XBARB_OUTPUT50_ID (XBARB_OUT_RESERVED50)
/* @brief XBARB output 51 ID. */
#define FSL_FEATURE_XBARB_OUTPUT51_ID (XBARB_OUT_RESERVED51)
/* @brief XBARB output 52 ID. */
#define FSL_FEATURE_XBARB_OUTPUT52_ID (XBARB_OUT_RESERVED52)
/* @brief XBARB output 53 ID. */
#define FSL_FEATURE_XBARB_OUTPUT53_ID (XBARB_OUT_RESERVED53)
/* @brief XBARB output 54 ID. */
#define FSL_FEATURE_XBARB_OUTPUT54_ID (XBARB_OUT_RESERVED54)
/* @brief XBARB output 55 ID. */
#define FSL_FEATURE_XBARB_OUTPUT55_ID (XBARB_OUT_RESERVED55)
/* @brief XBARB output 56 ID. */
#define FSL_FEATURE_XBARB_OUTPUT56_ID (XBARB_OUT_RESERVED56)
/* @brief XBARB output 57 ID. */
#define FSL_FEATURE_XBARB_OUTPUT57_ID (XBARB_OUT_RESERVED57)
/* @brief XBARB output 58 ID. */
#define FSL_FEATURE_XBARB_OUTPUT58_ID (XBARB_OUT_RESERVED58)
/* @brief XBARB output 59 ID. */
#define FSL_FEATURE_XBARB_OUTPUT59_ID (XBARB_OUT_RESERVED59)
/* @brief XBARB output 60 ID. */
#define FSL_FEATURE_XBARB_OUTPUT60_ID (XBARB_OUT_RESERVED60)
/* @brief XBARB output 61 ID. */
#define FSL_FEATURE_XBARB_OUTPUT61_ID (XBARB_OUT_RESERVED61)
/* @brief XBARB output 62 ID. */
#define FSL_FEATURE_XBARB_OUTPUT62_ID (XBARB_OUT_RESERVED62)
/* @brief XBARB output 63 ID. */
#define FSL_FEATURE_XBARB_OUTPUT63_ID (XBARB_OUT_RESERVED63)
/* @brief XBARB output 64 ID. */
#define FSL_FEATURE_XBARB_OUTPUT64_ID (XBARB_OUT_RESERVED64)
/* @brief XBARB output 65 ID. */
#define FSL_FEATURE_XBARB_OUTPUT65_ID (XBARB_OUT_RESERVED65)
/* @brief XBARB output 66 ID. */
#define FSL_FEATURE_XBARB_OUTPUT66_ID (XBARB_OUT_RESERVED66)
/* @brief XBARB output 67 ID. */
#define FSL_FEATURE_XBARB_OUTPUT67_ID (XBARB_OUT_RESERVED67)
/* @brief XBARB output 68 ID. */
#define FSL_FEATURE_XBARB_OUTPUT68_ID (XBARB_OUT_RESERVED68)
/* @brief XBARB output 69 ID. */
#define FSL_FEATURE_XBARB_OUTPUT69_ID (XBARB_OUT_RESERVED69)
/* @brief XBARB output 70 ID. */
#define FSL_FEATURE_XBARB_OUTPUT70_ID (XBARB_OUT_RESERVED70)
/* @brief XBARB output 71 ID. */
#define FSL_FEATURE_XBARB_OUTPUT71_ID (XBARB_OUT_RESERVED71)
/* @brief XBARB output 72 ID. */
#define FSL_FEATURE_XBARB_OUTPUT72_ID (XBARB_OUT_RESERVED72)
/* @brief XBARB output 73 ID. */
#define FSL_FEATURE_XBARB_OUTPUT73_ID (XBARB_OUT_RESERVED73)
/* @brief XBARB output 74 ID. */
#define FSL_FEATURE_XBARB_OUTPUT74_ID (XBARB_OUT_RESERVED74)
/* @brief XBARB output 75 ID. */
#define FSL_FEATURE_XBARB_OUTPUT75_ID (XBARB_OUT_RESERVED75)
/* @brief XBARB output 76 ID. */
#define FSL_FEATURE_XBARB_OUTPUT76_ID (XBARB_OUT_RESERVED76)
/* @brief XBARB output 77 ID. */
#define FSL_FEATURE_XBARB_OUTPUT77_ID (XBARB_OUT_RESERVED77)
/* @brief XBARB output 78 ID. */
#define FSL_FEATURE_XBARB_OUTPUT78_ID (XBARB_OUT_RESERVED78)
/* @brief XBARB output 79 ID. */
#define FSL_FEATURE_XBARB_OUTPUT79_ID (XBARB_OUT_RESERVED79)
/* @brief XBARB output 80 ID. */
#define FSL_FEATURE_XBARB_OUTPUT80_ID (XBARB_OUT_RESERVED80)
/* @brief XBARB output 81 ID. */
#define FSL_FEATURE_XBARB_OUTPUT81_ID (XBARB_OUT_RESERVED81)
/* @brief XBARB output 82 ID. */
#define FSL_FEATURE_XBARB_OUTPUT82_ID (XBARB_OUT_RESERVED82)
/* @brief XBARB output 83 ID. */
#define FSL_FEATURE_XBARB_OUTPUT83_ID (XBARB_OUT_RESERVED83)
/* @brief XBARB output 84 ID. */
#define FSL_FEATURE_XBARB_OUTPUT84_ID (XBARB_OUT_RESERVED84)
/* @brief XBARB output 85 ID. */
#define FSL_FEATURE_XBARB_OUTPUT85_ID (XBARB_OUT_RESERVED85)
/* @brief XBARB output 86 ID. */
#define FSL_FEATURE_XBARB_OUTPUT86_ID (XBARB_OUT_RESERVED86)
/* @brief XBARB output 87 ID. */
#define FSL_FEATURE_XBARB_OUTPUT87_ID (XBARB_OUT_RESERVED87)
/* @brief XBARB output 88 ID. */
#define FSL_FEATURE_XBARB_OUTPUT88_ID (XBARB_OUT_RESERVED88)
/* @brief XBARB output 89 ID. */
#define FSL_FEATURE_XBARB_OUTPUT89_ID (XBARB_OUT_RESERVED89)
/* @brief XBARB output 90 ID. */
#define FSL_FEATURE_XBARB_OUTPUT90_ID (XBARB_OUT_RESERVED90)
/* @brief XBARB output 91 ID. */
#define FSL_FEATURE_XBARB_OUTPUT91_ID (XBARB_OUT_RESERVED91)
/* @brief XBARB output 92 ID. */
#define FSL_FEATURE_XBARB_OUTPUT92_ID (XBARB_OUT_RESERVED92)
/* @brief XBARB output 93 ID. */
#define FSL_FEATURE_XBARB_OUTPUT93_ID (XBARB_OUT_RESERVED93)
/* @brief XBARB output 94 ID. */
#define FSL_FEATURE_XBARB_OUTPUT94_ID (XBARB_OUT_RESERVED94)
/* @brief XBARB output 95 ID. */
#define FSL_FEATURE_XBARB_OUTPUT95_ID (XBARB_OUT_RESERVED95)
/* @brief XBARB output 96 ID. */
#define FSL_FEATURE_XBARB_OUTPUT96_ID (XBARB_OUT_RESERVED96)
/* @brief XBARB output 97 ID. */
#define FSL_FEATURE_XBARB_OUTPUT97_ID (XBARB_OUT_RESERVED97)
/* @brief XBARB output 98 ID. */
#define FSL_FEATURE_XBARB_OUTPUT98_ID (XBARB_OUT_RESERVED98)
/* @brief XBARB output 99 ID. */
#define FSL_FEATURE_XBARB_OUTPUT99_ID (XBARB_OUT_RESERVED99)
/* @brief XBARB output 100 ID. */
#define FSL_FEATURE_XBARB_OUTPUT100_ID (XBARB_OUT_RESERVED100)
/* @brief XBARB output 101 ID. */
#define FSL_FEATURE_XBARB_OUTPUT101_ID (XBARB_OUT_RESERVED101)
/* @brief XBARB output 102 ID. */
#define FSL_FEATURE_XBARB_OUTPUT102_ID (XBARB_OUT_RESERVED102)
/* @brief XBARB output 103 ID. */
#define FSL_FEATURE_XBARB_OUTPUT103_ID (XBARB_OUT_RESERVED103)
/* @brief XBARB output 104 ID. */
#define FSL_FEATURE_XBARB_OUTPUT104_ID (XBARB_OUT_RESERVED104)
/* @brief XBARB output 105 ID. */
#define FSL_FEATURE_XBARB_OUTPUT105_ID (XBARB_OUT_RESERVED105)
/* @brief XBARB output 106 ID. */
#define FSL_FEATURE_XBARB_OUTPUT106_ID (XBARB_OUT_RESERVED106)
/* @brief XBARB output 107 ID. */
#define FSL_FEATURE_XBARB_OUTPUT107_ID (XBARB_OUT_RESERVED107)
/* @brief XBARB output 108 ID. */
#define FSL_FEATURE_XBARB_OUTPUT108_ID (XBARB_OUT_RESERVED108)
/* @brief XBARB output 109 ID. */
#define FSL_FEATURE_XBARB_OUTPUT109_ID (XBARB_OUT_RESERVED109)
/* @brief XBARB output 110 ID. */
#define FSL_FEATURE_XBARB_OUTPUT110_ID (XBARB_OUT_RESERVED110)
/* @brief XBARB output 111 ID. */
#define FSL_FEATURE_XBARB_OUTPUT111_ID (XBARB_OUT_RESERVED111)
/* @brief XBARB output 112 ID. */
#define FSL_FEATURE_XBARB_OUTPUT112_ID (XBARB_OUT_RESERVED112)
/* @brief XBARB output 113 ID. */
#define FSL_FEATURE_XBARB_OUTPUT113_ID (XBARB_OUT_RESERVED113)
/* @brief XBARB output 114 ID. */
#define FSL_FEATURE_XBARB_OUTPUT114_ID (XBARB_OUT_RESERVED114)
/* @brief XBARB output 115 ID. */
#define FSL_FEATURE_XBARB_OUTPUT115_ID (XBARB_OUT_RESERVED115)
/* @brief XBARB output 116 ID. */
#define FSL_FEATURE_XBARB_OUTPUT116_ID (XBARB_OUT_RESERVED116)
/* @brief XBARB output 117 ID. */
#define FSL_FEATURE_XBARB_OUTPUT117_ID (XBARB_OUT_RESERVED117)
/* @brief XBARB output 118 ID. */
#define FSL_FEATURE_XBARB_OUTPUT118_ID (XBARB_OUT_RESERVED118)
/* @brief XBARB output 119 ID. */
#define FSL_FEATURE_XBARB_OUTPUT119_ID (XBARB_OUT_RESERVED119)
/* @brief XBARB output 120 ID. */
#define FSL_FEATURE_XBARB_OUTPUT120_ID (XBARB_OUT_RESERVED120)
/* @brief XBARB output 121 ID. */
#define FSL_FEATURE_XBARB_OUTPUT121_ID (XBARB_OUT_RESERVED121)
/* @brief XBARB output 122 ID. */
#define FSL_FEATURE_XBARB_OUTPUT122_ID (XBARB_OUT_RESERVED122)
/* @brief XBARB output 123 ID. */
#define FSL_FEATURE_XBARB_OUTPUT123_ID (XBARB_OUT_RESERVED123)
/* @brief XBARB output 124 ID. */
#define FSL_FEATURE_XBARB_OUTPUT124_ID (XBARB_OUT_RESERVED124)
/* @brief XBARB output 125 ID. */
#define FSL_FEATURE_XBARB_OUTPUT125_ID (XBARB_OUT_RESERVED125)
/* @brief XBARB output 126 ID. */
#define FSL_FEATURE_XBARB_OUTPUT126_ID (XBARB_OUT_RESERVED126)
/* @brief XBARB output 127 ID. */
#define FSL_FEATURE_XBARB_OUTPUT127_ID (XBARB_OUT_RESERVED127)

#endif /* _MKV58F24_FEATURES_H_ */

