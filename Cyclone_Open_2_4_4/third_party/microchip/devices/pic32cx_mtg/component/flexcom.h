/*
 * Component description for FLEXCOM
 *
 * Copyright (c) 2023 Microchip Technology Inc. and its subsidiaries.
 *
 * Subject to your compliance with these terms, you may use Microchip software and any derivatives
 * exclusively with Microchip products. It is your responsibility to comply with third party license
 * terms applicable to your use of third party software (including open source software) that may
 * accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY,
 * APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF
 * MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT
 * EXCEED THE AMOUNT OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 */

/* file generated from device description version 2023-01-20T11:01:01Z */
#ifndef _PIC32CXMTG_FLEXCOM_COMPONENT_H_
#define _PIC32CXMTG_FLEXCOM_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR FLEXCOM                                      */
/* ************************************************************************** */

/* -------- FLEX_MR : (FLEXCOM Offset: 0x00) (R/W 32) FLEXCOM Mode Register -------- */
#define FLEX_MR_OPMODE_Pos                    _UINT32_(0)                                          /* (FLEX_MR) FLEXCOM Operating Mode Position */
#define FLEX_MR_OPMODE_Msk                    (_UINT32_(0x3) << FLEX_MR_OPMODE_Pos)                /* (FLEX_MR) FLEXCOM Operating Mode Mask */
#define FLEX_MR_OPMODE(value)                 (FLEX_MR_OPMODE_Msk & (_UINT32_(value) << FLEX_MR_OPMODE_Pos)) /* Assigment of value for OPMODE in the FLEX_MR register */
#define   FLEX_MR_OPMODE_NO_COM_Val           _UINT32_(0x0)                                        /* (FLEX_MR) No communication  */
#define   FLEX_MR_OPMODE_USART_Val            _UINT32_(0x1)                                        /* (FLEX_MR) All UART related protocols are selected (RS232, RS485, IrDA, ISO7816, LIN,) SPI/TWI related registers are not accessible and have no impact on IOs.  */
#define   FLEX_MR_OPMODE_SPI_Val              _UINT32_(0x2)                                        /* (FLEX_MR) SPI operating mode is selected. USART/TWI related registers are not accessible and have no impact on IOs.  */
#define   FLEX_MR_OPMODE_TWI_Val              _UINT32_(0x3)                                        /* (FLEX_MR) All TWI related protocols are selected (TWI, SMBus). USART/SPI related registers are not accessible and have no impact on IOs.  */
#define FLEX_MR_OPMODE_NO_COM                 (FLEX_MR_OPMODE_NO_COM_Val << FLEX_MR_OPMODE_Pos)    /* (FLEX_MR) No communication Position  */
#define FLEX_MR_OPMODE_USART                  (FLEX_MR_OPMODE_USART_Val << FLEX_MR_OPMODE_Pos)     /* (FLEX_MR) All UART related protocols are selected (RS232, RS485, IrDA, ISO7816, LIN,) SPI/TWI related registers are not accessible and have no impact on IOs. Position  */
#define FLEX_MR_OPMODE_SPI                    (FLEX_MR_OPMODE_SPI_Val << FLEX_MR_OPMODE_Pos)       /* (FLEX_MR) SPI operating mode is selected. USART/TWI related registers are not accessible and have no impact on IOs. Position  */
#define FLEX_MR_OPMODE_TWI                    (FLEX_MR_OPMODE_TWI_Val << FLEX_MR_OPMODE_Pos)       /* (FLEX_MR) All TWI related protocols are selected (TWI, SMBus). USART/SPI related registers are not accessible and have no impact on IOs. Position  */
#define FLEX_MR_Msk                           _UINT32_(0x00000003)                                 /* (FLEX_MR) Register Mask  */


/* -------- FLEX_RHR : (FLEXCOM Offset: 0x10) ( R/ 32) FLEXCOM Receive Holding Register -------- */
#define FLEX_RHR_RXDATA_Pos                   _UINT32_(0)                                          /* (FLEX_RHR) Receive Data Position */
#define FLEX_RHR_RXDATA_Msk                   (_UINT32_(0xFFFF) << FLEX_RHR_RXDATA_Pos)            /* (FLEX_RHR) Receive Data Mask */
#define FLEX_RHR_RXDATA(value)                (FLEX_RHR_RXDATA_Msk & (_UINT32_(value) << FLEX_RHR_RXDATA_Pos)) /* Assigment of value for RXDATA in the FLEX_RHR register */
#define FLEX_RHR_Msk                          _UINT32_(0x0000FFFF)                                 /* (FLEX_RHR) Register Mask  */


/* -------- FLEX_THR : (FLEXCOM Offset: 0x20) (R/W 32) FLEXCOM Transmit Holding Register -------- */
#define FLEX_THR_TXDATA_Pos                   _UINT32_(0)                                          /* (FLEX_THR) Transmit Data Position */
#define FLEX_THR_TXDATA_Msk                   (_UINT32_(0xFFFF) << FLEX_THR_TXDATA_Pos)            /* (FLEX_THR) Transmit Data Mask */
#define FLEX_THR_TXDATA(value)                (FLEX_THR_TXDATA_Msk & (_UINT32_(value) << FLEX_THR_TXDATA_Pos)) /* Assigment of value for TXDATA in the FLEX_THR register */
#define FLEX_THR_Msk                          _UINT32_(0x0000FFFF)                                 /* (FLEX_THR) Register Mask  */


/* -------- FLEX_RPR : (FLEXCOM Offset: 0x100) (R/W 32) Receive Pointer Register -------- */
#define FLEX_RPR_RXPTR_Pos                    _UINT32_(0)                                          /* (FLEX_RPR) Receive Pointer Register Position */
#define FLEX_RPR_RXPTR_Msk                    (_UINT32_(0xFFFFFFFF) << FLEX_RPR_RXPTR_Pos)         /* (FLEX_RPR) Receive Pointer Register Mask */
#define FLEX_RPR_RXPTR(value)                 (FLEX_RPR_RXPTR_Msk & (_UINT32_(value) << FLEX_RPR_RXPTR_Pos)) /* Assigment of value for RXPTR in the FLEX_RPR register */
#define FLEX_RPR_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (FLEX_RPR) Register Mask  */


/* -------- FLEX_RCR : (FLEXCOM Offset: 0x104) (R/W 32) Receive Counter Register -------- */
#define FLEX_RCR_RXCTR_Pos                    _UINT32_(0)                                          /* (FLEX_RCR) Receive Counter Register Position */
#define FLEX_RCR_RXCTR_Msk                    (_UINT32_(0xFFFF) << FLEX_RCR_RXCTR_Pos)             /* (FLEX_RCR) Receive Counter Register Mask */
#define FLEX_RCR_RXCTR(value)                 (FLEX_RCR_RXCTR_Msk & (_UINT32_(value) << FLEX_RCR_RXCTR_Pos)) /* Assigment of value for RXCTR in the FLEX_RCR register */
#define FLEX_RCR_Msk                          _UINT32_(0x0000FFFF)                                 /* (FLEX_RCR) Register Mask  */


/* -------- FLEX_TPR : (FLEXCOM Offset: 0x108) (R/W 32) Transmit Pointer Register -------- */
#define FLEX_TPR_TXPTR_Pos                    _UINT32_(0)                                          /* (FLEX_TPR) Transmit Counter Register Position */
#define FLEX_TPR_TXPTR_Msk                    (_UINT32_(0xFFFFFFFF) << FLEX_TPR_TXPTR_Pos)         /* (FLEX_TPR) Transmit Counter Register Mask */
#define FLEX_TPR_TXPTR(value)                 (FLEX_TPR_TXPTR_Msk & (_UINT32_(value) << FLEX_TPR_TXPTR_Pos)) /* Assigment of value for TXPTR in the FLEX_TPR register */
#define FLEX_TPR_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (FLEX_TPR) Register Mask  */


/* -------- FLEX_TCR : (FLEXCOM Offset: 0x10C) (R/W 32) Transmit Counter Register -------- */
#define FLEX_TCR_TXCTR_Pos                    _UINT32_(0)                                          /* (FLEX_TCR) Transmit Counter Register Position */
#define FLEX_TCR_TXCTR_Msk                    (_UINT32_(0xFFFF) << FLEX_TCR_TXCTR_Pos)             /* (FLEX_TCR) Transmit Counter Register Mask */
#define FLEX_TCR_TXCTR(value)                 (FLEX_TCR_TXCTR_Msk & (_UINT32_(value) << FLEX_TCR_TXCTR_Pos)) /* Assigment of value for TXCTR in the FLEX_TCR register */
#define FLEX_TCR_Msk                          _UINT32_(0x0000FFFF)                                 /* (FLEX_TCR) Register Mask  */


/* -------- FLEX_RNPR : (FLEXCOM Offset: 0x110) (R/W 32) Receive Next Pointer Register -------- */
#define FLEX_RNPR_RXNPTR_Pos                  _UINT32_(0)                                          /* (FLEX_RNPR) Receive Next Pointer Position */
#define FLEX_RNPR_RXNPTR_Msk                  (_UINT32_(0xFFFFFFFF) << FLEX_RNPR_RXNPTR_Pos)       /* (FLEX_RNPR) Receive Next Pointer Mask */
#define FLEX_RNPR_RXNPTR(value)               (FLEX_RNPR_RXNPTR_Msk & (_UINT32_(value) << FLEX_RNPR_RXNPTR_Pos)) /* Assigment of value for RXNPTR in the FLEX_RNPR register */
#define FLEX_RNPR_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (FLEX_RNPR) Register Mask  */


/* -------- FLEX_RNCR : (FLEXCOM Offset: 0x114) (R/W 32) Receive Next Counter Register -------- */
#define FLEX_RNCR_RXNCTR_Pos                  _UINT32_(0)                                          /* (FLEX_RNCR) Receive Next Counter Position */
#define FLEX_RNCR_RXNCTR_Msk                  (_UINT32_(0xFFFF) << FLEX_RNCR_RXNCTR_Pos)           /* (FLEX_RNCR) Receive Next Counter Mask */
#define FLEX_RNCR_RXNCTR(value)               (FLEX_RNCR_RXNCTR_Msk & (_UINT32_(value) << FLEX_RNCR_RXNCTR_Pos)) /* Assigment of value for RXNCTR in the FLEX_RNCR register */
#define FLEX_RNCR_Msk                         _UINT32_(0x0000FFFF)                                 /* (FLEX_RNCR) Register Mask  */


/* -------- FLEX_TNPR : (FLEXCOM Offset: 0x118) (R/W 32) Transmit Next Pointer Register -------- */
#define FLEX_TNPR_TXNPTR_Pos                  _UINT32_(0)                                          /* (FLEX_TNPR) Transmit Next Pointer Position */
#define FLEX_TNPR_TXNPTR_Msk                  (_UINT32_(0xFFFFFFFF) << FLEX_TNPR_TXNPTR_Pos)       /* (FLEX_TNPR) Transmit Next Pointer Mask */
#define FLEX_TNPR_TXNPTR(value)               (FLEX_TNPR_TXNPTR_Msk & (_UINT32_(value) << FLEX_TNPR_TXNPTR_Pos)) /* Assigment of value for TXNPTR in the FLEX_TNPR register */
#define FLEX_TNPR_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (FLEX_TNPR) Register Mask  */


/* -------- FLEX_TNCR : (FLEXCOM Offset: 0x11C) (R/W 32) Transmit Next Counter Register -------- */
#define FLEX_TNCR_TXNCTR_Pos                  _UINT32_(0)                                          /* (FLEX_TNCR) Transmit Counter Next Position */
#define FLEX_TNCR_TXNCTR_Msk                  (_UINT32_(0xFFFF) << FLEX_TNCR_TXNCTR_Pos)           /* (FLEX_TNCR) Transmit Counter Next Mask */
#define FLEX_TNCR_TXNCTR(value)               (FLEX_TNCR_TXNCTR_Msk & (_UINT32_(value) << FLEX_TNCR_TXNCTR_Pos)) /* Assigment of value for TXNCTR in the FLEX_TNCR register */
#define FLEX_TNCR_Msk                         _UINT32_(0x0000FFFF)                                 /* (FLEX_TNCR) Register Mask  */


/* -------- FLEX_PTCR : (FLEXCOM Offset: 0x120) ( /W 32) Transfer Control Register -------- */
#define FLEX_PTCR_RXTEN_Pos                   _UINT32_(0)                                          /* (FLEX_PTCR) Receiver Transfer Enable Position */
#define FLEX_PTCR_RXTEN_Msk                   (_UINT32_(0x1) << FLEX_PTCR_RXTEN_Pos)               /* (FLEX_PTCR) Receiver Transfer Enable Mask */
#define FLEX_PTCR_RXTEN(value)                (FLEX_PTCR_RXTEN_Msk & (_UINT32_(value) << FLEX_PTCR_RXTEN_Pos)) /* Assigment of value for RXTEN in the FLEX_PTCR register */
#define FLEX_PTCR_RXTDIS_Pos                  _UINT32_(1)                                          /* (FLEX_PTCR) Receiver Transfer Disable Position */
#define FLEX_PTCR_RXTDIS_Msk                  (_UINT32_(0x1) << FLEX_PTCR_RXTDIS_Pos)              /* (FLEX_PTCR) Receiver Transfer Disable Mask */
#define FLEX_PTCR_RXTDIS(value)               (FLEX_PTCR_RXTDIS_Msk & (_UINT32_(value) << FLEX_PTCR_RXTDIS_Pos)) /* Assigment of value for RXTDIS in the FLEX_PTCR register */
#define FLEX_PTCR_TXTEN_Pos                   _UINT32_(8)                                          /* (FLEX_PTCR) Transmitter Transfer Enable Position */
#define FLEX_PTCR_TXTEN_Msk                   (_UINT32_(0x1) << FLEX_PTCR_TXTEN_Pos)               /* (FLEX_PTCR) Transmitter Transfer Enable Mask */
#define FLEX_PTCR_TXTEN(value)                (FLEX_PTCR_TXTEN_Msk & (_UINT32_(value) << FLEX_PTCR_TXTEN_Pos)) /* Assigment of value for TXTEN in the FLEX_PTCR register */
#define FLEX_PTCR_TXTDIS_Pos                  _UINT32_(9)                                          /* (FLEX_PTCR) Transmitter Transfer Disable Position */
#define FLEX_PTCR_TXTDIS_Msk                  (_UINT32_(0x1) << FLEX_PTCR_TXTDIS_Pos)              /* (FLEX_PTCR) Transmitter Transfer Disable Mask */
#define FLEX_PTCR_TXTDIS(value)               (FLEX_PTCR_TXTDIS_Msk & (_UINT32_(value) << FLEX_PTCR_TXTDIS_Pos)) /* Assigment of value for TXTDIS in the FLEX_PTCR register */
#define FLEX_PTCR_RXCBEN_Pos                  _UINT32_(16)                                         /* (FLEX_PTCR) Receiver Circular Buffer Enable Position */
#define FLEX_PTCR_RXCBEN_Msk                  (_UINT32_(0x1) << FLEX_PTCR_RXCBEN_Pos)              /* (FLEX_PTCR) Receiver Circular Buffer Enable Mask */
#define FLEX_PTCR_RXCBEN(value)               (FLEX_PTCR_RXCBEN_Msk & (_UINT32_(value) << FLEX_PTCR_RXCBEN_Pos)) /* Assigment of value for RXCBEN in the FLEX_PTCR register */
#define FLEX_PTCR_RXCBDIS_Pos                 _UINT32_(17)                                         /* (FLEX_PTCR) Receiver Circular Buffer Disable Position */
#define FLEX_PTCR_RXCBDIS_Msk                 (_UINT32_(0x1) << FLEX_PTCR_RXCBDIS_Pos)             /* (FLEX_PTCR) Receiver Circular Buffer Disable Mask */
#define FLEX_PTCR_RXCBDIS(value)              (FLEX_PTCR_RXCBDIS_Msk & (_UINT32_(value) << FLEX_PTCR_RXCBDIS_Pos)) /* Assigment of value for RXCBDIS in the FLEX_PTCR register */
#define FLEX_PTCR_TXCBEN_Pos                  _UINT32_(18)                                         /* (FLEX_PTCR) Transmitter Circular Buffer Enable Position */
#define FLEX_PTCR_TXCBEN_Msk                  (_UINT32_(0x1) << FLEX_PTCR_TXCBEN_Pos)              /* (FLEX_PTCR) Transmitter Circular Buffer Enable Mask */
#define FLEX_PTCR_TXCBEN(value)               (FLEX_PTCR_TXCBEN_Msk & (_UINT32_(value) << FLEX_PTCR_TXCBEN_Pos)) /* Assigment of value for TXCBEN in the FLEX_PTCR register */
#define FLEX_PTCR_TXCBDIS_Pos                 _UINT32_(19)                                         /* (FLEX_PTCR) Transmitter Circular Buffer Disable Position */
#define FLEX_PTCR_TXCBDIS_Msk                 (_UINT32_(0x1) << FLEX_PTCR_TXCBDIS_Pos)             /* (FLEX_PTCR) Transmitter Circular Buffer Disable Mask */
#define FLEX_PTCR_TXCBDIS(value)              (FLEX_PTCR_TXCBDIS_Msk & (_UINT32_(value) << FLEX_PTCR_TXCBDIS_Pos)) /* Assigment of value for TXCBDIS in the FLEX_PTCR register */
#define FLEX_PTCR_ERRCLR_Pos                  _UINT32_(24)                                         /* (FLEX_PTCR) Transfer Bus Error Clear Position */
#define FLEX_PTCR_ERRCLR_Msk                  (_UINT32_(0x1) << FLEX_PTCR_ERRCLR_Pos)              /* (FLEX_PTCR) Transfer Bus Error Clear Mask */
#define FLEX_PTCR_ERRCLR(value)               (FLEX_PTCR_ERRCLR_Msk & (_UINT32_(value) << FLEX_PTCR_ERRCLR_Pos)) /* Assigment of value for ERRCLR in the FLEX_PTCR register */
#define FLEX_PTCR_Msk                         _UINT32_(0x010F0303)                                 /* (FLEX_PTCR) Register Mask  */


/* -------- FLEX_PTSR : (FLEXCOM Offset: 0x124) ( R/ 32) Transfer Status Register -------- */
#define FLEX_PTSR_RXTEN_Pos                   _UINT32_(0)                                          /* (FLEX_PTSR) Receiver Transfer Enable Position */
#define FLEX_PTSR_RXTEN_Msk                   (_UINT32_(0x1) << FLEX_PTSR_RXTEN_Pos)               /* (FLEX_PTSR) Receiver Transfer Enable Mask */
#define FLEX_PTSR_RXTEN(value)                (FLEX_PTSR_RXTEN_Msk & (_UINT32_(value) << FLEX_PTSR_RXTEN_Pos)) /* Assigment of value for RXTEN in the FLEX_PTSR register */
#define FLEX_PTSR_TXTEN_Pos                   _UINT32_(8)                                          /* (FLEX_PTSR) Transmitter Transfer Enable Position */
#define FLEX_PTSR_TXTEN_Msk                   (_UINT32_(0x1) << FLEX_PTSR_TXTEN_Pos)               /* (FLEX_PTSR) Transmitter Transfer Enable Mask */
#define FLEX_PTSR_TXTEN(value)                (FLEX_PTSR_TXTEN_Msk & (_UINT32_(value) << FLEX_PTSR_TXTEN_Pos)) /* Assigment of value for TXTEN in the FLEX_PTSR register */
#define FLEX_PTSR_RXCBEN_Pos                  _UINT32_(16)                                         /* (FLEX_PTSR) Receiver Circular Buffer Enable Position */
#define FLEX_PTSR_RXCBEN_Msk                  (_UINT32_(0x1) << FLEX_PTSR_RXCBEN_Pos)              /* (FLEX_PTSR) Receiver Circular Buffer Enable Mask */
#define FLEX_PTSR_RXCBEN(value)               (FLEX_PTSR_RXCBEN_Msk & (_UINT32_(value) << FLEX_PTSR_RXCBEN_Pos)) /* Assigment of value for RXCBEN in the FLEX_PTSR register */
#define FLEX_PTSR_TXCBEN_Pos                  _UINT32_(18)                                         /* (FLEX_PTSR) Transmitter Circular Buffer Enable Position */
#define FLEX_PTSR_TXCBEN_Msk                  (_UINT32_(0x1) << FLEX_PTSR_TXCBEN_Pos)              /* (FLEX_PTSR) Transmitter Circular Buffer Enable Mask */
#define FLEX_PTSR_TXCBEN(value)               (FLEX_PTSR_TXCBEN_Msk & (_UINT32_(value) << FLEX_PTSR_TXCBEN_Pos)) /* Assigment of value for TXCBEN in the FLEX_PTSR register */
#define FLEX_PTSR_ERR_Pos                     _UINT32_(24)                                         /* (FLEX_PTSR) Transfer Bus Error Position */
#define FLEX_PTSR_ERR_Msk                     (_UINT32_(0x1) << FLEX_PTSR_ERR_Pos)                 /* (FLEX_PTSR) Transfer Bus Error Mask */
#define FLEX_PTSR_ERR(value)                  (FLEX_PTSR_ERR_Msk & (_UINT32_(value) << FLEX_PTSR_ERR_Pos)) /* Assigment of value for ERR in the FLEX_PTSR register */
#define FLEX_PTSR_Msk                         _UINT32_(0x01050101)                                 /* (FLEX_PTSR) Register Mask  */


/* -------- FLEX_PWPMR : (FLEXCOM Offset: 0x128) (R/W 32) Write Protection Mode Register -------- */
#define FLEX_PWPMR_WPPTREN_Pos                _UINT32_(0)                                          /* (FLEX_PWPMR) Write Protection Pointer Registers Enable Position */
#define FLEX_PWPMR_WPPTREN_Msk                (_UINT32_(0x1) << FLEX_PWPMR_WPPTREN_Pos)            /* (FLEX_PWPMR) Write Protection Pointer Registers Enable Mask */
#define FLEX_PWPMR_WPPTREN(value)             (FLEX_PWPMR_WPPTREN_Msk & (_UINT32_(value) << FLEX_PWPMR_WPPTREN_Pos)) /* Assigment of value for WPPTREN in the FLEX_PWPMR register */
#define FLEX_PWPMR_WPCTREN_Pos                _UINT32_(1)                                          /* (FLEX_PWPMR) Write Protection Counter Registers Enable Position */
#define FLEX_PWPMR_WPCTREN_Msk                (_UINT32_(0x1) << FLEX_PWPMR_WPCTREN_Pos)            /* (FLEX_PWPMR) Write Protection Counter Registers Enable Mask */
#define FLEX_PWPMR_WPCTREN(value)             (FLEX_PWPMR_WPCTREN_Msk & (_UINT32_(value) << FLEX_PWPMR_WPCTREN_Pos)) /* Assigment of value for WPCTREN in the FLEX_PWPMR register */
#define FLEX_PWPMR_WPCREN_Pos                 _UINT32_(2)                                          /* (FLEX_PWPMR) Write Protection Control Register Enable Position */
#define FLEX_PWPMR_WPCREN_Msk                 (_UINT32_(0x1) << FLEX_PWPMR_WPCREN_Pos)             /* (FLEX_PWPMR) Write Protection Control Register Enable Mask */
#define FLEX_PWPMR_WPCREN(value)              (FLEX_PWPMR_WPCREN_Msk & (_UINT32_(value) << FLEX_PWPMR_WPCREN_Pos)) /* Assigment of value for WPCREN in the FLEX_PWPMR register */
#define FLEX_PWPMR_WPKEY_Pos                  _UINT32_(8)                                          /* (FLEX_PWPMR) Write Protection Key Position */
#define FLEX_PWPMR_WPKEY_Msk                  (_UINT32_(0xFFFFFF) << FLEX_PWPMR_WPKEY_Pos)         /* (FLEX_PWPMR) Write Protection Key Mask */
#define FLEX_PWPMR_WPKEY(value)               (FLEX_PWPMR_WPKEY_Msk & (_UINT32_(value) << FLEX_PWPMR_WPKEY_Pos)) /* Assigment of value for WPKEY in the FLEX_PWPMR register */
#define   FLEX_PWPMR_WPKEY_PASSWD_Val         _UINT32_(0x504443)                                   /* (FLEX_PWPMR) Writing any other value in this field aborts the write operation. Always reads as 0.  */
#define FLEX_PWPMR_WPKEY_PASSWD               (FLEX_PWPMR_WPKEY_PASSWD_Val << FLEX_PWPMR_WPKEY_Pos) /* (FLEX_PWPMR) Writing any other value in this field aborts the write operation. Always reads as 0. Position  */
#define FLEX_PWPMR_Msk                        _UINT32_(0xFFFFFF07)                                 /* (FLEX_PWPMR) Register Mask  */


/* -------- FLEX_US_CR : (FLEXCOM Offset: 0x200) ( /W 32) USART Control Register -------- */
#define FLEX_US_CR_RSTRX_Pos                  _UINT32_(2)                                          /* (FLEX_US_CR) Reset Receiver Position */
#define FLEX_US_CR_RSTRX_Msk                  (_UINT32_(0x1) << FLEX_US_CR_RSTRX_Pos)              /* (FLEX_US_CR) Reset Receiver Mask */
#define FLEX_US_CR_RSTRX(value)               (FLEX_US_CR_RSTRX_Msk & (_UINT32_(value) << FLEX_US_CR_RSTRX_Pos)) /* Assigment of value for RSTRX in the FLEX_US_CR register */
#define FLEX_US_CR_RSTTX_Pos                  _UINT32_(3)                                          /* (FLEX_US_CR) Reset Transmitter Position */
#define FLEX_US_CR_RSTTX_Msk                  (_UINT32_(0x1) << FLEX_US_CR_RSTTX_Pos)              /* (FLEX_US_CR) Reset Transmitter Mask */
#define FLEX_US_CR_RSTTX(value)               (FLEX_US_CR_RSTTX_Msk & (_UINT32_(value) << FLEX_US_CR_RSTTX_Pos)) /* Assigment of value for RSTTX in the FLEX_US_CR register */
#define FLEX_US_CR_RXEN_Pos                   _UINT32_(4)                                          /* (FLEX_US_CR) Receiver Enable Position */
#define FLEX_US_CR_RXEN_Msk                   (_UINT32_(0x1) << FLEX_US_CR_RXEN_Pos)               /* (FLEX_US_CR) Receiver Enable Mask */
#define FLEX_US_CR_RXEN(value)                (FLEX_US_CR_RXEN_Msk & (_UINT32_(value) << FLEX_US_CR_RXEN_Pos)) /* Assigment of value for RXEN in the FLEX_US_CR register */
#define FLEX_US_CR_RXDIS_Pos                  _UINT32_(5)                                          /* (FLEX_US_CR) Receiver Disable Position */
#define FLEX_US_CR_RXDIS_Msk                  (_UINT32_(0x1) << FLEX_US_CR_RXDIS_Pos)              /* (FLEX_US_CR) Receiver Disable Mask */
#define FLEX_US_CR_RXDIS(value)               (FLEX_US_CR_RXDIS_Msk & (_UINT32_(value) << FLEX_US_CR_RXDIS_Pos)) /* Assigment of value for RXDIS in the FLEX_US_CR register */
#define FLEX_US_CR_TXEN_Pos                   _UINT32_(6)                                          /* (FLEX_US_CR) Transmitter Enable Position */
#define FLEX_US_CR_TXEN_Msk                   (_UINT32_(0x1) << FLEX_US_CR_TXEN_Pos)               /* (FLEX_US_CR) Transmitter Enable Mask */
#define FLEX_US_CR_TXEN(value)                (FLEX_US_CR_TXEN_Msk & (_UINT32_(value) << FLEX_US_CR_TXEN_Pos)) /* Assigment of value for TXEN in the FLEX_US_CR register */
#define FLEX_US_CR_TXDIS_Pos                  _UINT32_(7)                                          /* (FLEX_US_CR) Transmitter Disable Position */
#define FLEX_US_CR_TXDIS_Msk                  (_UINT32_(0x1) << FLEX_US_CR_TXDIS_Pos)              /* (FLEX_US_CR) Transmitter Disable Mask */
#define FLEX_US_CR_TXDIS(value)               (FLEX_US_CR_TXDIS_Msk & (_UINT32_(value) << FLEX_US_CR_TXDIS_Pos)) /* Assigment of value for TXDIS in the FLEX_US_CR register */
#define FLEX_US_CR_RSTSTA_Pos                 _UINT32_(8)                                          /* (FLEX_US_CR) Reset Status Bits Position */
#define FLEX_US_CR_RSTSTA_Msk                 (_UINT32_(0x1) << FLEX_US_CR_RSTSTA_Pos)             /* (FLEX_US_CR) Reset Status Bits Mask */
#define FLEX_US_CR_RSTSTA(value)              (FLEX_US_CR_RSTSTA_Msk & (_UINT32_(value) << FLEX_US_CR_RSTSTA_Pos)) /* Assigment of value for RSTSTA in the FLEX_US_CR register */
#define FLEX_US_CR_STTBRK_Pos                 _UINT32_(9)                                          /* (FLEX_US_CR) Start Break Position */
#define FLEX_US_CR_STTBRK_Msk                 (_UINT32_(0x1) << FLEX_US_CR_STTBRK_Pos)             /* (FLEX_US_CR) Start Break Mask */
#define FLEX_US_CR_STTBRK(value)              (FLEX_US_CR_STTBRK_Msk & (_UINT32_(value) << FLEX_US_CR_STTBRK_Pos)) /* Assigment of value for STTBRK in the FLEX_US_CR register */
#define FLEX_US_CR_STPBRK_Pos                 _UINT32_(10)                                         /* (FLEX_US_CR) Stop Break Position */
#define FLEX_US_CR_STPBRK_Msk                 (_UINT32_(0x1) << FLEX_US_CR_STPBRK_Pos)             /* (FLEX_US_CR) Stop Break Mask */
#define FLEX_US_CR_STPBRK(value)              (FLEX_US_CR_STPBRK_Msk & (_UINT32_(value) << FLEX_US_CR_STPBRK_Pos)) /* Assigment of value for STPBRK in the FLEX_US_CR register */
#define FLEX_US_CR_STTTO_Pos                  _UINT32_(11)                                         /* (FLEX_US_CR) Clear TIMEOUT Flag and Start Timeout After Next Character Received Position */
#define FLEX_US_CR_STTTO_Msk                  (_UINT32_(0x1) << FLEX_US_CR_STTTO_Pos)              /* (FLEX_US_CR) Clear TIMEOUT Flag and Start Timeout After Next Character Received Mask */
#define FLEX_US_CR_STTTO(value)               (FLEX_US_CR_STTTO_Msk & (_UINT32_(value) << FLEX_US_CR_STTTO_Pos)) /* Assigment of value for STTTO in the FLEX_US_CR register */
#define FLEX_US_CR_SENDA_Pos                  _UINT32_(12)                                         /* (FLEX_US_CR) Send Address Position */
#define FLEX_US_CR_SENDA_Msk                  (_UINT32_(0x1) << FLEX_US_CR_SENDA_Pos)              /* (FLEX_US_CR) Send Address Mask */
#define FLEX_US_CR_SENDA(value)               (FLEX_US_CR_SENDA_Msk & (_UINT32_(value) << FLEX_US_CR_SENDA_Pos)) /* Assigment of value for SENDA in the FLEX_US_CR register */
#define FLEX_US_CR_RSTIT_Pos                  _UINT32_(13)                                         /* (FLEX_US_CR) Reset Iterations Position */
#define FLEX_US_CR_RSTIT_Msk                  (_UINT32_(0x1) << FLEX_US_CR_RSTIT_Pos)              /* (FLEX_US_CR) Reset Iterations Mask */
#define FLEX_US_CR_RSTIT(value)               (FLEX_US_CR_RSTIT_Msk & (_UINT32_(value) << FLEX_US_CR_RSTIT_Pos)) /* Assigment of value for RSTIT in the FLEX_US_CR register */
#define FLEX_US_CR_RSTNACK_Pos                _UINT32_(14)                                         /* (FLEX_US_CR) Reset Non Acknowledge Position */
#define FLEX_US_CR_RSTNACK_Msk                (_UINT32_(0x1) << FLEX_US_CR_RSTNACK_Pos)            /* (FLEX_US_CR) Reset Non Acknowledge Mask */
#define FLEX_US_CR_RSTNACK(value)             (FLEX_US_CR_RSTNACK_Msk & (_UINT32_(value) << FLEX_US_CR_RSTNACK_Pos)) /* Assigment of value for RSTNACK in the FLEX_US_CR register */
#define FLEX_US_CR_RETTO_Pos                  _UINT32_(15)                                         /* (FLEX_US_CR) Start Timeout Immediately Position */
#define FLEX_US_CR_RETTO_Msk                  (_UINT32_(0x1) << FLEX_US_CR_RETTO_Pos)              /* (FLEX_US_CR) Start Timeout Immediately Mask */
#define FLEX_US_CR_RETTO(value)               (FLEX_US_CR_RETTO_Msk & (_UINT32_(value) << FLEX_US_CR_RETTO_Pos)) /* Assigment of value for RETTO in the FLEX_US_CR register */
#define FLEX_US_CR_RTSEN_Pos                  _UINT32_(18)                                         /* (FLEX_US_CR) Request to Send Enable Position */
#define FLEX_US_CR_RTSEN_Msk                  (_UINT32_(0x1) << FLEX_US_CR_RTSEN_Pos)              /* (FLEX_US_CR) Request to Send Enable Mask */
#define FLEX_US_CR_RTSEN(value)               (FLEX_US_CR_RTSEN_Msk & (_UINT32_(value) << FLEX_US_CR_RTSEN_Pos)) /* Assigment of value for RTSEN in the FLEX_US_CR register */
#define FLEX_US_CR_RTSDIS_Pos                 _UINT32_(19)                                         /* (FLEX_US_CR) Request to Send Disable Position */
#define FLEX_US_CR_RTSDIS_Msk                 (_UINT32_(0x1) << FLEX_US_CR_RTSDIS_Pos)             /* (FLEX_US_CR) Request to Send Disable Mask */
#define FLEX_US_CR_RTSDIS(value)              (FLEX_US_CR_RTSDIS_Msk & (_UINT32_(value) << FLEX_US_CR_RTSDIS_Pos)) /* Assigment of value for RTSDIS in the FLEX_US_CR register */
#define FLEX_US_CR_LINABT_Pos                 _UINT32_(20)                                         /* (FLEX_US_CR) Abort LIN Transmission Position */
#define FLEX_US_CR_LINABT_Msk                 (_UINT32_(0x1) << FLEX_US_CR_LINABT_Pos)             /* (FLEX_US_CR) Abort LIN Transmission Mask */
#define FLEX_US_CR_LINABT(value)              (FLEX_US_CR_LINABT_Msk & (_UINT32_(value) << FLEX_US_CR_LINABT_Pos)) /* Assigment of value for LINABT in the FLEX_US_CR register */
#define FLEX_US_CR_LINWKUP_Pos                _UINT32_(21)                                         /* (FLEX_US_CR) Send LIN Wakeup Signal Position */
#define FLEX_US_CR_LINWKUP_Msk                (_UINT32_(0x1) << FLEX_US_CR_LINWKUP_Pos)            /* (FLEX_US_CR) Send LIN Wakeup Signal Mask */
#define FLEX_US_CR_LINWKUP(value)             (FLEX_US_CR_LINWKUP_Msk & (_UINT32_(value) << FLEX_US_CR_LINWKUP_Pos)) /* Assigment of value for LINWKUP in the FLEX_US_CR register */
#define FLEX_US_CR_TXFCLR_Pos                 _UINT32_(24)                                         /* (FLEX_US_CR) Transmit FIFO Clear Position */
#define FLEX_US_CR_TXFCLR_Msk                 (_UINT32_(0x1) << FLEX_US_CR_TXFCLR_Pos)             /* (FLEX_US_CR) Transmit FIFO Clear Mask */
#define FLEX_US_CR_TXFCLR(value)              (FLEX_US_CR_TXFCLR_Msk & (_UINT32_(value) << FLEX_US_CR_TXFCLR_Pos)) /* Assigment of value for TXFCLR in the FLEX_US_CR register */
#define FLEX_US_CR_RXFCLR_Pos                 _UINT32_(25)                                         /* (FLEX_US_CR) Receive FIFO Clear Position */
#define FLEX_US_CR_RXFCLR_Msk                 (_UINT32_(0x1) << FLEX_US_CR_RXFCLR_Pos)             /* (FLEX_US_CR) Receive FIFO Clear Mask */
#define FLEX_US_CR_RXFCLR(value)              (FLEX_US_CR_RXFCLR_Msk & (_UINT32_(value) << FLEX_US_CR_RXFCLR_Pos)) /* Assigment of value for RXFCLR in the FLEX_US_CR register */
#define FLEX_US_CR_TXFLCLR_Pos                _UINT32_(26)                                         /* (FLEX_US_CR) Transmit FIFO Lock CLEAR Position */
#define FLEX_US_CR_TXFLCLR_Msk                (_UINT32_(0x1) << FLEX_US_CR_TXFLCLR_Pos)            /* (FLEX_US_CR) Transmit FIFO Lock CLEAR Mask */
#define FLEX_US_CR_TXFLCLR(value)             (FLEX_US_CR_TXFLCLR_Msk & (_UINT32_(value) << FLEX_US_CR_TXFLCLR_Pos)) /* Assigment of value for TXFLCLR in the FLEX_US_CR register */
#define FLEX_US_CR_REQCLR_Pos                 _UINT32_(28)                                         /* (FLEX_US_CR) Request to Clear the Comparison Trigger Position */
#define FLEX_US_CR_REQCLR_Msk                 (_UINT32_(0x1) << FLEX_US_CR_REQCLR_Pos)             /* (FLEX_US_CR) Request to Clear the Comparison Trigger Mask */
#define FLEX_US_CR_REQCLR(value)              (FLEX_US_CR_REQCLR_Msk & (_UINT32_(value) << FLEX_US_CR_REQCLR_Pos)) /* Assigment of value for REQCLR in the FLEX_US_CR register */
#define FLEX_US_CR_FIFOEN_Pos                 _UINT32_(30)                                         /* (FLEX_US_CR) FIFO Enable Position */
#define FLEX_US_CR_FIFOEN_Msk                 (_UINT32_(0x1) << FLEX_US_CR_FIFOEN_Pos)             /* (FLEX_US_CR) FIFO Enable Mask */
#define FLEX_US_CR_FIFOEN(value)              (FLEX_US_CR_FIFOEN_Msk & (_UINT32_(value) << FLEX_US_CR_FIFOEN_Pos)) /* Assigment of value for FIFOEN in the FLEX_US_CR register */
#define FLEX_US_CR_FIFODIS_Pos                _UINT32_(31)                                         /* (FLEX_US_CR) FIFO Disable Position */
#define FLEX_US_CR_FIFODIS_Msk                (_UINT32_(0x1) << FLEX_US_CR_FIFODIS_Pos)            /* (FLEX_US_CR) FIFO Disable Mask */
#define FLEX_US_CR_FIFODIS(value)             (FLEX_US_CR_FIFODIS_Msk & (_UINT32_(value) << FLEX_US_CR_FIFODIS_Pos)) /* Assigment of value for FIFODIS in the FLEX_US_CR register */
#define FLEX_US_CR_Msk                        _UINT32_(0xD73CFFFC)                                 /* (FLEX_US_CR) Register Mask  */


/* -------- FLEX_US_MR : (FLEXCOM Offset: 0x204) (R/W 32) USART Mode Register -------- */
#define FLEX_US_MR_USART_MODE_Pos             _UINT32_(0)                                          /* (FLEX_US_MR) USART Mode of Operation Position */
#define FLEX_US_MR_USART_MODE_Msk             (_UINT32_(0xF) << FLEX_US_MR_USART_MODE_Pos)         /* (FLEX_US_MR) USART Mode of Operation Mask */
#define FLEX_US_MR_USART_MODE(value)          (FLEX_US_MR_USART_MODE_Msk & (_UINT32_(value) << FLEX_US_MR_USART_MODE_Pos)) /* Assigment of value for USART_MODE in the FLEX_US_MR register */
#define   FLEX_US_MR_USART_MODE_NORMAL_Val    _UINT32_(0x0)                                        /* (FLEX_US_MR) Normal mode  */
#define   FLEX_US_MR_USART_MODE_RS485_Val     _UINT32_(0x1)                                        /* (FLEX_US_MR) RS485  */
#define   FLEX_US_MR_USART_MODE_HW_HANDSHAKING_Val _UINT32_(0x2)                                        /* (FLEX_US_MR) Hardware handshaking  */
#define   FLEX_US_MR_USART_MODE_IS07816_T_0_Val _UINT32_(0x4)                                        /* (FLEX_US_MR) IS07816 Protocol: T = 0  */
#define   FLEX_US_MR_USART_MODE_IS07816_T_1_Val _UINT32_(0x6)                                        /* (FLEX_US_MR) IS07816 Protocol: T = 1  */
#define   FLEX_US_MR_USART_MODE_IRDA_Val      _UINT32_(0x8)                                        /* (FLEX_US_MR) IrDA  */
#define   FLEX_US_MR_USART_MODE_LIN_MASTER_Val _UINT32_(0xA)                                        /* (FLEX_US_MR) LIN Host mode  */
#define   FLEX_US_MR_USART_MODE_LIN_SLAVE_Val _UINT32_(0xB)                                        /* (FLEX_US_MR) LIN Client mode  */
#define   FLEX_US_MR_USART_MODE_DATA16BIT_MASTER_Val _UINT32_(0xC)                                        /* (FLEX_US_MR) 16-bit data host  */
#define   FLEX_US_MR_USART_MODE_DATA16BIT_SLAVE_Val _UINT32_(0xD)                                        /* (FLEX_US_MR) 16-bit data client  */
#define FLEX_US_MR_USART_MODE_NORMAL          (FLEX_US_MR_USART_MODE_NORMAL_Val << FLEX_US_MR_USART_MODE_Pos) /* (FLEX_US_MR) Normal mode Position  */
#define FLEX_US_MR_USART_MODE_RS485           (FLEX_US_MR_USART_MODE_RS485_Val << FLEX_US_MR_USART_MODE_Pos) /* (FLEX_US_MR) RS485 Position  */
#define FLEX_US_MR_USART_MODE_HW_HANDSHAKING  (FLEX_US_MR_USART_MODE_HW_HANDSHAKING_Val << FLEX_US_MR_USART_MODE_Pos) /* (FLEX_US_MR) Hardware handshaking Position  */
#define FLEX_US_MR_USART_MODE_IS07816_T_0     (FLEX_US_MR_USART_MODE_IS07816_T_0_Val << FLEX_US_MR_USART_MODE_Pos) /* (FLEX_US_MR) IS07816 Protocol: T = 0 Position  */
#define FLEX_US_MR_USART_MODE_IS07816_T_1     (FLEX_US_MR_USART_MODE_IS07816_T_1_Val << FLEX_US_MR_USART_MODE_Pos) /* (FLEX_US_MR) IS07816 Protocol: T = 1 Position  */
#define FLEX_US_MR_USART_MODE_IRDA            (FLEX_US_MR_USART_MODE_IRDA_Val << FLEX_US_MR_USART_MODE_Pos) /* (FLEX_US_MR) IrDA Position  */
#define FLEX_US_MR_USART_MODE_LIN_MASTER      (FLEX_US_MR_USART_MODE_LIN_MASTER_Val << FLEX_US_MR_USART_MODE_Pos) /* (FLEX_US_MR) LIN Host mode Position  */
#define FLEX_US_MR_USART_MODE_LIN_SLAVE       (FLEX_US_MR_USART_MODE_LIN_SLAVE_Val << FLEX_US_MR_USART_MODE_Pos) /* (FLEX_US_MR) LIN Client mode Position  */
#define FLEX_US_MR_USART_MODE_DATA16BIT_MASTER (FLEX_US_MR_USART_MODE_DATA16BIT_MASTER_Val << FLEX_US_MR_USART_MODE_Pos) /* (FLEX_US_MR) 16-bit data host Position  */
#define FLEX_US_MR_USART_MODE_DATA16BIT_SLAVE (FLEX_US_MR_USART_MODE_DATA16BIT_SLAVE_Val << FLEX_US_MR_USART_MODE_Pos) /* (FLEX_US_MR) 16-bit data client Position  */
#define FLEX_US_MR_USCLKS_Pos                 _UINT32_(4)                                          /* (FLEX_US_MR) Clock Selection Position */
#define FLEX_US_MR_USCLKS_Msk                 (_UINT32_(0x3) << FLEX_US_MR_USCLKS_Pos)             /* (FLEX_US_MR) Clock Selection Mask */
#define FLEX_US_MR_USCLKS(value)              (FLEX_US_MR_USCLKS_Msk & (_UINT32_(value) << FLEX_US_MR_USCLKS_Pos)) /* Assigment of value for USCLKS in the FLEX_US_MR register */
#define   FLEX_US_MR_USCLKS_MCK_Val           _UINT32_(0x0)                                        /* (FLEX_US_MR) Peripheral clock is selected  */
#define   FLEX_US_MR_USCLKS_DIV_Val           _UINT32_(0x1)                                        /* (FLEX_US_MR) Peripheral clock divided (DIV = 8) is selected  */
#define   FLEX_US_MR_USCLKS_GCLK_Val          _UINT32_(0x2)                                        /* (FLEX_US_MR) PMC generic clock is selected. If the SCK pin is driven (CLKO = 1), the CD field must be greater than 1.  */
#define   FLEX_US_MR_USCLKS_SCK_Val           _UINT32_(0x3)                                        /* (FLEX_US_MR) External pin SCK is selected  */
#define FLEX_US_MR_USCLKS_MCK                 (FLEX_US_MR_USCLKS_MCK_Val << FLEX_US_MR_USCLKS_Pos) /* (FLEX_US_MR) Peripheral clock is selected Position  */
#define FLEX_US_MR_USCLKS_DIV                 (FLEX_US_MR_USCLKS_DIV_Val << FLEX_US_MR_USCLKS_Pos) /* (FLEX_US_MR) Peripheral clock divided (DIV = 8) is selected Position  */
#define FLEX_US_MR_USCLKS_GCLK                (FLEX_US_MR_USCLKS_GCLK_Val << FLEX_US_MR_USCLKS_Pos) /* (FLEX_US_MR) PMC generic clock is selected. If the SCK pin is driven (CLKO = 1), the CD field must be greater than 1. Position  */
#define FLEX_US_MR_USCLKS_SCK                 (FLEX_US_MR_USCLKS_SCK_Val << FLEX_US_MR_USCLKS_Pos) /* (FLEX_US_MR) External pin SCK is selected Position  */
#define FLEX_US_MR_CHRL_Pos                   _UINT32_(6)                                          /* (FLEX_US_MR) Character Length Position */
#define FLEX_US_MR_CHRL_Msk                   (_UINT32_(0x3) << FLEX_US_MR_CHRL_Pos)               /* (FLEX_US_MR) Character Length Mask */
#define FLEX_US_MR_CHRL(value)                (FLEX_US_MR_CHRL_Msk & (_UINT32_(value) << FLEX_US_MR_CHRL_Pos)) /* Assigment of value for CHRL in the FLEX_US_MR register */
#define   FLEX_US_MR_CHRL_5_BIT_Val           _UINT32_(0x0)                                        /* (FLEX_US_MR) Character length is 5 bits  */
#define   FLEX_US_MR_CHRL_6_BIT_Val           _UINT32_(0x1)                                        /* (FLEX_US_MR) Character length is 6 bits  */
#define   FLEX_US_MR_CHRL_7_BIT_Val           _UINT32_(0x2)                                        /* (FLEX_US_MR) Character length is 7 bits  */
#define   FLEX_US_MR_CHRL_8_BIT_Val           _UINT32_(0x3)                                        /* (FLEX_US_MR) Character length is 8 bits  */
#define FLEX_US_MR_CHRL_5_BIT                 (FLEX_US_MR_CHRL_5_BIT_Val << FLEX_US_MR_CHRL_Pos)   /* (FLEX_US_MR) Character length is 5 bits Position  */
#define FLEX_US_MR_CHRL_6_BIT                 (FLEX_US_MR_CHRL_6_BIT_Val << FLEX_US_MR_CHRL_Pos)   /* (FLEX_US_MR) Character length is 6 bits Position  */
#define FLEX_US_MR_CHRL_7_BIT                 (FLEX_US_MR_CHRL_7_BIT_Val << FLEX_US_MR_CHRL_Pos)   /* (FLEX_US_MR) Character length is 7 bits Position  */
#define FLEX_US_MR_CHRL_8_BIT                 (FLEX_US_MR_CHRL_8_BIT_Val << FLEX_US_MR_CHRL_Pos)   /* (FLEX_US_MR) Character length is 8 bits Position  */
#define FLEX_US_MR_SYNC_Pos                   _UINT32_(8)                                          /* (FLEX_US_MR) Synchronous Mode Select Position */
#define FLEX_US_MR_SYNC_Msk                   (_UINT32_(0x1) << FLEX_US_MR_SYNC_Pos)               /* (FLEX_US_MR) Synchronous Mode Select Mask */
#define FLEX_US_MR_SYNC(value)                (FLEX_US_MR_SYNC_Msk & (_UINT32_(value) << FLEX_US_MR_SYNC_Pos)) /* Assigment of value for SYNC in the FLEX_US_MR register */
#define FLEX_US_MR_PAR_Pos                    _UINT32_(9)                                          /* (FLEX_US_MR) Parity Type Position */
#define FLEX_US_MR_PAR_Msk                    (_UINT32_(0x7) << FLEX_US_MR_PAR_Pos)                /* (FLEX_US_MR) Parity Type Mask */
#define FLEX_US_MR_PAR(value)                 (FLEX_US_MR_PAR_Msk & (_UINT32_(value) << FLEX_US_MR_PAR_Pos)) /* Assigment of value for PAR in the FLEX_US_MR register */
#define   FLEX_US_MR_PAR_EVEN_Val             _UINT32_(0x0)                                        /* (FLEX_US_MR) Even parity  */
#define   FLEX_US_MR_PAR_ODD_Val              _UINT32_(0x1)                                        /* (FLEX_US_MR) Odd parity  */
#define   FLEX_US_MR_PAR_SPACE_Val            _UINT32_(0x2)                                        /* (FLEX_US_MR) Parity forced to 0 (Space)  */
#define   FLEX_US_MR_PAR_MARK_Val             _UINT32_(0x3)                                        /* (FLEX_US_MR) Parity forced to 1 (Mark)  */
#define   FLEX_US_MR_PAR_NO_Val               _UINT32_(0x4)                                        /* (FLEX_US_MR) No parity  */
#define   FLEX_US_MR_PAR_MULTIDROP_Val        _UINT32_(0x6)                                        /* (FLEX_US_MR) Multidrop mode  */
#define FLEX_US_MR_PAR_EVEN                   (FLEX_US_MR_PAR_EVEN_Val << FLEX_US_MR_PAR_Pos)      /* (FLEX_US_MR) Even parity Position  */
#define FLEX_US_MR_PAR_ODD                    (FLEX_US_MR_PAR_ODD_Val << FLEX_US_MR_PAR_Pos)       /* (FLEX_US_MR) Odd parity Position  */
#define FLEX_US_MR_PAR_SPACE                  (FLEX_US_MR_PAR_SPACE_Val << FLEX_US_MR_PAR_Pos)     /* (FLEX_US_MR) Parity forced to 0 (Space) Position  */
#define FLEX_US_MR_PAR_MARK                   (FLEX_US_MR_PAR_MARK_Val << FLEX_US_MR_PAR_Pos)      /* (FLEX_US_MR) Parity forced to 1 (Mark) Position  */
#define FLEX_US_MR_PAR_NO                     (FLEX_US_MR_PAR_NO_Val << FLEX_US_MR_PAR_Pos)        /* (FLEX_US_MR) No parity Position  */
#define FLEX_US_MR_PAR_MULTIDROP              (FLEX_US_MR_PAR_MULTIDROP_Val << FLEX_US_MR_PAR_Pos) /* (FLEX_US_MR) Multidrop mode Position  */
#define FLEX_US_MR_NBSTOP_Pos                 _UINT32_(12)                                         /* (FLEX_US_MR) Number of Stop Bits Position */
#define FLEX_US_MR_NBSTOP_Msk                 (_UINT32_(0x3) << FLEX_US_MR_NBSTOP_Pos)             /* (FLEX_US_MR) Number of Stop Bits Mask */
#define FLEX_US_MR_NBSTOP(value)              (FLEX_US_MR_NBSTOP_Msk & (_UINT32_(value) << FLEX_US_MR_NBSTOP_Pos)) /* Assigment of value for NBSTOP in the FLEX_US_MR register */
#define   FLEX_US_MR_NBSTOP_1_BIT_Val         _UINT32_(0x0)                                        /* (FLEX_US_MR) 1 stop bit  */
#define   FLEX_US_MR_NBSTOP_1_5_BIT_Val       _UINT32_(0x1)                                        /* (FLEX_US_MR) 1.5 stop bit (SYNC = 0) or reserved (SYNC = 1)  */
#define   FLEX_US_MR_NBSTOP_2_BIT_Val         _UINT32_(0x2)                                        /* (FLEX_US_MR) 2 stop bits  */
#define FLEX_US_MR_NBSTOP_1_BIT               (FLEX_US_MR_NBSTOP_1_BIT_Val << FLEX_US_MR_NBSTOP_Pos) /* (FLEX_US_MR) 1 stop bit Position  */
#define FLEX_US_MR_NBSTOP_1_5_BIT             (FLEX_US_MR_NBSTOP_1_5_BIT_Val << FLEX_US_MR_NBSTOP_Pos) /* (FLEX_US_MR) 1.5 stop bit (SYNC = 0) or reserved (SYNC = 1) Position  */
#define FLEX_US_MR_NBSTOP_2_BIT               (FLEX_US_MR_NBSTOP_2_BIT_Val << FLEX_US_MR_NBSTOP_Pos) /* (FLEX_US_MR) 2 stop bits Position  */
#define FLEX_US_MR_CHMODE_Pos                 _UINT32_(14)                                         /* (FLEX_US_MR) Channel Mode Position */
#define FLEX_US_MR_CHMODE_Msk                 (_UINT32_(0x3) << FLEX_US_MR_CHMODE_Pos)             /* (FLEX_US_MR) Channel Mode Mask */
#define FLEX_US_MR_CHMODE(value)              (FLEX_US_MR_CHMODE_Msk & (_UINT32_(value) << FLEX_US_MR_CHMODE_Pos)) /* Assigment of value for CHMODE in the FLEX_US_MR register */
#define   FLEX_US_MR_CHMODE_NORMAL_Val        _UINT32_(0x0)                                        /* (FLEX_US_MR) Normal mode  */
#define   FLEX_US_MR_CHMODE_AUTOMATIC_Val     _UINT32_(0x1)                                        /* (FLEX_US_MR) Automatic Echo. Receiver input is connected to the TXD pin.  */
#define   FLEX_US_MR_CHMODE_LOCAL_LOOPBACK_Val _UINT32_(0x2)                                        /* (FLEX_US_MR) Local Loopback. Transmitter output is connected to the Receiver Input.  */
#define   FLEX_US_MR_CHMODE_REMOTE_LOOPBACK_Val _UINT32_(0x3)                                        /* (FLEX_US_MR) Remote Loopback. RXD pin is internally connected to the TXD pin.  */
#define FLEX_US_MR_CHMODE_NORMAL              (FLEX_US_MR_CHMODE_NORMAL_Val << FLEX_US_MR_CHMODE_Pos) /* (FLEX_US_MR) Normal mode Position  */
#define FLEX_US_MR_CHMODE_AUTOMATIC           (FLEX_US_MR_CHMODE_AUTOMATIC_Val << FLEX_US_MR_CHMODE_Pos) /* (FLEX_US_MR) Automatic Echo. Receiver input is connected to the TXD pin. Position  */
#define FLEX_US_MR_CHMODE_LOCAL_LOOPBACK      (FLEX_US_MR_CHMODE_LOCAL_LOOPBACK_Val << FLEX_US_MR_CHMODE_Pos) /* (FLEX_US_MR) Local Loopback. Transmitter output is connected to the Receiver Input. Position  */
#define FLEX_US_MR_CHMODE_REMOTE_LOOPBACK     (FLEX_US_MR_CHMODE_REMOTE_LOOPBACK_Val << FLEX_US_MR_CHMODE_Pos) /* (FLEX_US_MR) Remote Loopback. RXD pin is internally connected to the TXD pin. Position  */
#define FLEX_US_MR_MSBF_Pos                   _UINT32_(16)                                         /* (FLEX_US_MR) Bit Order Position */
#define FLEX_US_MR_MSBF_Msk                   (_UINT32_(0x1) << FLEX_US_MR_MSBF_Pos)               /* (FLEX_US_MR) Bit Order Mask */
#define FLEX_US_MR_MSBF(value)                (FLEX_US_MR_MSBF_Msk & (_UINT32_(value) << FLEX_US_MR_MSBF_Pos)) /* Assigment of value for MSBF in the FLEX_US_MR register */
#define FLEX_US_MR_MODE9_Pos                  _UINT32_(17)                                         /* (FLEX_US_MR) 9-bit Character Length Position */
#define FLEX_US_MR_MODE9_Msk                  (_UINT32_(0x1) << FLEX_US_MR_MODE9_Pos)              /* (FLEX_US_MR) 9-bit Character Length Mask */
#define FLEX_US_MR_MODE9(value)               (FLEX_US_MR_MODE9_Msk & (_UINT32_(value) << FLEX_US_MR_MODE9_Pos)) /* Assigment of value for MODE9 in the FLEX_US_MR register */
#define FLEX_US_MR_CLKO_Pos                   _UINT32_(18)                                         /* (FLEX_US_MR) Clock Output Select Position */
#define FLEX_US_MR_CLKO_Msk                   (_UINT32_(0x1) << FLEX_US_MR_CLKO_Pos)               /* (FLEX_US_MR) Clock Output Select Mask */
#define FLEX_US_MR_CLKO(value)                (FLEX_US_MR_CLKO_Msk & (_UINT32_(value) << FLEX_US_MR_CLKO_Pos)) /* Assigment of value for CLKO in the FLEX_US_MR register */
#define FLEX_US_MR_OVER_Pos                   _UINT32_(19)                                         /* (FLEX_US_MR) Oversampling Mode Position */
#define FLEX_US_MR_OVER_Msk                   (_UINT32_(0x1) << FLEX_US_MR_OVER_Pos)               /* (FLEX_US_MR) Oversampling Mode Mask */
#define FLEX_US_MR_OVER(value)                (FLEX_US_MR_OVER_Msk & (_UINT32_(value) << FLEX_US_MR_OVER_Pos)) /* Assigment of value for OVER in the FLEX_US_MR register */
#define FLEX_US_MR_INACK_Pos                  _UINT32_(20)                                         /* (FLEX_US_MR) Inhibit Non Acknowledge Position */
#define FLEX_US_MR_INACK_Msk                  (_UINT32_(0x1) << FLEX_US_MR_INACK_Pos)              /* (FLEX_US_MR) Inhibit Non Acknowledge Mask */
#define FLEX_US_MR_INACK(value)               (FLEX_US_MR_INACK_Msk & (_UINT32_(value) << FLEX_US_MR_INACK_Pos)) /* Assigment of value for INACK in the FLEX_US_MR register */
#define FLEX_US_MR_DSNACK_Pos                 _UINT32_(21)                                         /* (FLEX_US_MR) Disable Successive NACK Position */
#define FLEX_US_MR_DSNACK_Msk                 (_UINT32_(0x1) << FLEX_US_MR_DSNACK_Pos)             /* (FLEX_US_MR) Disable Successive NACK Mask */
#define FLEX_US_MR_DSNACK(value)              (FLEX_US_MR_DSNACK_Msk & (_UINT32_(value) << FLEX_US_MR_DSNACK_Pos)) /* Assigment of value for DSNACK in the FLEX_US_MR register */
#define FLEX_US_MR_VAR_SYNC_Pos               _UINT32_(22)                                         /* (FLEX_US_MR) Variable Synchronization of Command/Data Sync Start Frame Delimiter Position */
#define FLEX_US_MR_VAR_SYNC_Msk               (_UINT32_(0x1) << FLEX_US_MR_VAR_SYNC_Pos)           /* (FLEX_US_MR) Variable Synchronization of Command/Data Sync Start Frame Delimiter Mask */
#define FLEX_US_MR_VAR_SYNC(value)            (FLEX_US_MR_VAR_SYNC_Msk & (_UINT32_(value) << FLEX_US_MR_VAR_SYNC_Pos)) /* Assigment of value for VAR_SYNC in the FLEX_US_MR register */
#define FLEX_US_MR_INVDATA_Pos                _UINT32_(23)                                         /* (FLEX_US_MR) Inverted Data Position */
#define FLEX_US_MR_INVDATA_Msk                (_UINT32_(0x1) << FLEX_US_MR_INVDATA_Pos)            /* (FLEX_US_MR) Inverted Data Mask */
#define FLEX_US_MR_INVDATA(value)             (FLEX_US_MR_INVDATA_Msk & (_UINT32_(value) << FLEX_US_MR_INVDATA_Pos)) /* Assigment of value for INVDATA in the FLEX_US_MR register */
#define FLEX_US_MR_MAX_ITERATION_Pos          _UINT32_(24)                                         /* (FLEX_US_MR) Maximum Number of Automatic Iteration Position */
#define FLEX_US_MR_MAX_ITERATION_Msk          (_UINT32_(0x7) << FLEX_US_MR_MAX_ITERATION_Pos)      /* (FLEX_US_MR) Maximum Number of Automatic Iteration Mask */
#define FLEX_US_MR_MAX_ITERATION(value)       (FLEX_US_MR_MAX_ITERATION_Msk & (_UINT32_(value) << FLEX_US_MR_MAX_ITERATION_Pos)) /* Assigment of value for MAX_ITERATION in the FLEX_US_MR register */
#define FLEX_US_MR_FILTER_Pos                 _UINT32_(28)                                         /* (FLEX_US_MR) Receive Line Filter Position */
#define FLEX_US_MR_FILTER_Msk                 (_UINT32_(0x1) << FLEX_US_MR_FILTER_Pos)             /* (FLEX_US_MR) Receive Line Filter Mask */
#define FLEX_US_MR_FILTER(value)              (FLEX_US_MR_FILTER_Msk & (_UINT32_(value) << FLEX_US_MR_FILTER_Pos)) /* Assigment of value for FILTER in the FLEX_US_MR register */
#define FLEX_US_MR_MAN_Pos                    _UINT32_(29)                                         /* (FLEX_US_MR) Manchester Encoder/Decoder Enable Position */
#define FLEX_US_MR_MAN_Msk                    (_UINT32_(0x1) << FLEX_US_MR_MAN_Pos)                /* (FLEX_US_MR) Manchester Encoder/Decoder Enable Mask */
#define FLEX_US_MR_MAN(value)                 (FLEX_US_MR_MAN_Msk & (_UINT32_(value) << FLEX_US_MR_MAN_Pos)) /* Assigment of value for MAN in the FLEX_US_MR register */
#define FLEX_US_MR_MODSYNC_Pos                _UINT32_(30)                                         /* (FLEX_US_MR) Manchester Synchronization Mode Position */
#define FLEX_US_MR_MODSYNC_Msk                (_UINT32_(0x1) << FLEX_US_MR_MODSYNC_Pos)            /* (FLEX_US_MR) Manchester Synchronization Mode Mask */
#define FLEX_US_MR_MODSYNC(value)             (FLEX_US_MR_MODSYNC_Msk & (_UINT32_(value) << FLEX_US_MR_MODSYNC_Pos)) /* Assigment of value for MODSYNC in the FLEX_US_MR register */
#define FLEX_US_MR_ONEBIT_Pos                 _UINT32_(31)                                         /* (FLEX_US_MR) Start Frame Delimiter Selector Position */
#define FLEX_US_MR_ONEBIT_Msk                 (_UINT32_(0x1) << FLEX_US_MR_ONEBIT_Pos)             /* (FLEX_US_MR) Start Frame Delimiter Selector Mask */
#define FLEX_US_MR_ONEBIT(value)              (FLEX_US_MR_ONEBIT_Msk & (_UINT32_(value) << FLEX_US_MR_ONEBIT_Pos)) /* Assigment of value for ONEBIT in the FLEX_US_MR register */
#define FLEX_US_MR_Msk                        _UINT32_(0xF7FFFFFF)                                 /* (FLEX_US_MR) Register Mask  */

/* OOK mode */
#define FLEX_US_MR_OOK_USART_MODE_Pos         _UINT32_(0)                                          /* (FLEX_US_MR) USART Mode of Operation Position */
#define FLEX_US_MR_OOK_USART_MODE_Msk         (_UINT32_(0xF) << FLEX_US_MR_OOK_USART_MODE_Pos)     /* (FLEX_US_MR) USART Mode of Operation Mask */
#define FLEX_US_MR_OOK_USART_MODE(value)      (FLEX_US_MR_OOK_USART_MODE_Msk & (_UINT32_(value) << FLEX_US_MR_OOK_USART_MODE_Pos))
#define   FLEX_US_MR_OOK_USART_MODE_NORMAL_Val _UINT32_(0x0)                                        /* (FLEX_US_MR) Normal mode  */
#define FLEX_US_MR_OOK_USART_MODE_NORMAL      (FLEX_US_MR_OOK_USART_MODE_NORMAL_Val << FLEX_US_MR_OOK_USART_MODE_Pos) /* (FLEX_US_MR) Normal mode Position  */
#define FLEX_US_MR_OOK_USCLKS_Pos             _UINT32_(4)                                          /* (FLEX_US_MR) Clock Selection Position */
#define FLEX_US_MR_OOK_USCLKS_Msk             (_UINT32_(0x3) << FLEX_US_MR_OOK_USCLKS_Pos)         /* (FLEX_US_MR) Clock Selection Mask */
#define FLEX_US_MR_OOK_USCLKS(value)          (FLEX_US_MR_OOK_USCLKS_Msk & (_UINT32_(value) << FLEX_US_MR_OOK_USCLKS_Pos))
#define   FLEX_US_MR_OOK_USCLKS_MCK_Val       _UINT32_(0x0)                                        /* (FLEX_US_MR) Peripheral clock is selected.  */
#define   FLEX_US_MR_OOK_USCLKS_DIV_Val       _UINT32_(0x1)                                        /* (FLEX_US_MR) Peripheral clock divided (DIV=8) is selected.  */
#define   FLEX_US_MR_OOK_USCLKS_PCK_Val       _UINT32_(0x2)                                        /* (FLEX_US_MR) PMC programmable clock (PCK) is selected. If the SCK pin is driven (CLKO = 1), the CD field must be greater than 1.  */
#define   FLEX_US_MR_OOK_USCLKS_SCK_Val       _UINT32_(0x3)                                        /* (FLEX_US_MR) Serial clock (SCK) is selected.  */
#define FLEX_US_MR_OOK_USCLKS_MCK             (FLEX_US_MR_OOK_USCLKS_MCK_Val << FLEX_US_MR_OOK_USCLKS_Pos) /* (FLEX_US_MR) Peripheral clock is selected. Position  */
#define FLEX_US_MR_OOK_USCLKS_DIV             (FLEX_US_MR_OOK_USCLKS_DIV_Val << FLEX_US_MR_OOK_USCLKS_Pos) /* (FLEX_US_MR) Peripheral clock divided (DIV=8) is selected. Position  */
#define FLEX_US_MR_OOK_USCLKS_PCK             (FLEX_US_MR_OOK_USCLKS_PCK_Val << FLEX_US_MR_OOK_USCLKS_Pos) /* (FLEX_US_MR) PMC programmable clock (PCK) is selected. If the SCK pin is driven (CLKO = 1), the CD field must be greater than 1. Position  */
#define FLEX_US_MR_OOK_USCLKS_SCK             (FLEX_US_MR_OOK_USCLKS_SCK_Val << FLEX_US_MR_OOK_USCLKS_Pos) /* (FLEX_US_MR) Serial clock (SCK) is selected. Position  */
#define FLEX_US_MR_OOK_CHRL_Pos               _UINT32_(6)                                          /* (FLEX_US_MR) Character Length Position */
#define FLEX_US_MR_OOK_CHRL_Msk               (_UINT32_(0x3) << FLEX_US_MR_OOK_CHRL_Pos)           /* (FLEX_US_MR) Character Length Mask */
#define FLEX_US_MR_OOK_CHRL(value)            (FLEX_US_MR_OOK_CHRL_Msk & (_UINT32_(value) << FLEX_US_MR_OOK_CHRL_Pos))
#define   FLEX_US_MR_OOK_CHRL_5_BIT_Val       _UINT32_(0x0)                                        /* (FLEX_US_MR) Character length is 5 bits.  */
#define   FLEX_US_MR_OOK_CHRL_6_BIT_Val       _UINT32_(0x1)                                        /* (FLEX_US_MR) Character length is 6 bits.  */
#define   FLEX_US_MR_OOK_CHRL_7_BIT_Val       _UINT32_(0x2)                                        /* (FLEX_US_MR) Character length is 7 bits.  */
#define   FLEX_US_MR_OOK_CHRL_8_BIT_Val       _UINT32_(0x3)                                        /* (FLEX_US_MR) Character length is 8 bits.  */
#define FLEX_US_MR_OOK_CHRL_5_BIT             (FLEX_US_MR_OOK_CHRL_5_BIT_Val << FLEX_US_MR_OOK_CHRL_Pos) /* (FLEX_US_MR) Character length is 5 bits. Position  */
#define FLEX_US_MR_OOK_CHRL_6_BIT             (FLEX_US_MR_OOK_CHRL_6_BIT_Val << FLEX_US_MR_OOK_CHRL_Pos) /* (FLEX_US_MR) Character length is 6 bits. Position  */
#define FLEX_US_MR_OOK_CHRL_7_BIT             (FLEX_US_MR_OOK_CHRL_7_BIT_Val << FLEX_US_MR_OOK_CHRL_Pos) /* (FLEX_US_MR) Character length is 7 bits. Position  */
#define FLEX_US_MR_OOK_CHRL_8_BIT             (FLEX_US_MR_OOK_CHRL_8_BIT_Val << FLEX_US_MR_OOK_CHRL_Pos) /* (FLEX_US_MR) Character length is 8 bits. Position  */
#define FLEX_US_MR_OOK_SYNC_Pos               _UINT32_(8)                                          /* (FLEX_US_MR) Synchronous Mode Select Position */
#define FLEX_US_MR_OOK_SYNC_Msk               (_UINT32_(0x1) << FLEX_US_MR_OOK_SYNC_Pos)           /* (FLEX_US_MR) Synchronous Mode Select Mask */
#define FLEX_US_MR_OOK_SYNC(value)            (FLEX_US_MR_OOK_SYNC_Msk & (_UINT32_(value) << FLEX_US_MR_OOK_SYNC_Pos))
#define FLEX_US_MR_OOK_PAR_Pos                _UINT32_(9)                                          /* (FLEX_US_MR) Parity Type Position */
#define FLEX_US_MR_OOK_PAR_Msk                (_UINT32_(0x7) << FLEX_US_MR_OOK_PAR_Pos)            /* (FLEX_US_MR) Parity Type Mask */
#define FLEX_US_MR_OOK_PAR(value)             (FLEX_US_MR_OOK_PAR_Msk & (_UINT32_(value) << FLEX_US_MR_OOK_PAR_Pos))
#define   FLEX_US_MR_OOK_PAR_EVEN_Val         _UINT32_(0x0)                                        /* (FLEX_US_MR) Even parity  */
#define   FLEX_US_MR_OOK_PAR_ODD_Val          _UINT32_(0x1)                                        /* (FLEX_US_MR) Odd parity  */
#define   FLEX_US_MR_OOK_PAR_SPACE_Val        _UINT32_(0x2)                                        /* (FLEX_US_MR) Parity forced to 0 (Space)  */
#define   FLEX_US_MR_OOK_PAR_MARK_Val         _UINT32_(0x3)                                        /* (FLEX_US_MR) Parity forced to 1 (Mark)  */
#define   FLEX_US_MR_OOK_PAR_NO_Val           _UINT32_(0x4)                                        /* (FLEX_US_MR) No parity  */
#define   FLEX_US_MR_OOK_PAR_MULTIDROP_Val    _UINT32_(0x6)                                        /* (FLEX_US_MR) Multidrop mode  */
#define FLEX_US_MR_OOK_PAR_EVEN               (FLEX_US_MR_OOK_PAR_EVEN_Val << FLEX_US_MR_OOK_PAR_Pos) /* (FLEX_US_MR) Even parity Position  */
#define FLEX_US_MR_OOK_PAR_ODD                (FLEX_US_MR_OOK_PAR_ODD_Val << FLEX_US_MR_OOK_PAR_Pos) /* (FLEX_US_MR) Odd parity Position  */
#define FLEX_US_MR_OOK_PAR_SPACE              (FLEX_US_MR_OOK_PAR_SPACE_Val << FLEX_US_MR_OOK_PAR_Pos) /* (FLEX_US_MR) Parity forced to 0 (Space) Position  */
#define FLEX_US_MR_OOK_PAR_MARK               (FLEX_US_MR_OOK_PAR_MARK_Val << FLEX_US_MR_OOK_PAR_Pos) /* (FLEX_US_MR) Parity forced to 1 (Mark) Position  */
#define FLEX_US_MR_OOK_PAR_NO                 (FLEX_US_MR_OOK_PAR_NO_Val << FLEX_US_MR_OOK_PAR_Pos) /* (FLEX_US_MR) No parity Position  */
#define FLEX_US_MR_OOK_PAR_MULTIDROP          (FLEX_US_MR_OOK_PAR_MULTIDROP_Val << FLEX_US_MR_OOK_PAR_Pos) /* (FLEX_US_MR) Multidrop mode Position  */
#define FLEX_US_MR_OOK_NBSTOP_Pos             _UINT32_(12)                                         /* (FLEX_US_MR) Number of Stop Bits Position */
#define FLEX_US_MR_OOK_NBSTOP_Msk             (_UINT32_(0x3) << FLEX_US_MR_OOK_NBSTOP_Pos)         /* (FLEX_US_MR) Number of Stop Bits Mask */
#define FLEX_US_MR_OOK_NBSTOP(value)          (FLEX_US_MR_OOK_NBSTOP_Msk & (_UINT32_(value) << FLEX_US_MR_OOK_NBSTOP_Pos))
#define   FLEX_US_MR_OOK_NBSTOP_1_BIT_Val     _UINT32_(0x0)                                        /* (FLEX_US_MR) 1 stop bit  */
#define   FLEX_US_MR_OOK_NBSTOP_1_5_BIT_Val   _UINT32_(0x1)                                        /* (FLEX_US_MR) 1.5 stop bit (SYNC = 0) or reserved (SYNC = 1)  */
#define   FLEX_US_MR_OOK_NBSTOP_2_BIT_Val     _UINT32_(0x2)                                        /* (FLEX_US_MR) 2 stop bits  */
#define FLEX_US_MR_OOK_NBSTOP_1_BIT           (FLEX_US_MR_OOK_NBSTOP_1_BIT_Val << FLEX_US_MR_OOK_NBSTOP_Pos) /* (FLEX_US_MR) 1 stop bit Position  */
#define FLEX_US_MR_OOK_NBSTOP_1_5_BIT         (FLEX_US_MR_OOK_NBSTOP_1_5_BIT_Val << FLEX_US_MR_OOK_NBSTOP_Pos) /* (FLEX_US_MR) 1.5 stop bit (SYNC = 0) or reserved (SYNC = 1) Position  */
#define FLEX_US_MR_OOK_NBSTOP_2_BIT           (FLEX_US_MR_OOK_NBSTOP_2_BIT_Val << FLEX_US_MR_OOK_NBSTOP_Pos) /* (FLEX_US_MR) 2 stop bits Position  */
#define FLEX_US_MR_OOK_CHMODE_Pos             _UINT32_(14)                                         /* (FLEX_US_MR) Channel Mode Position */
#define FLEX_US_MR_OOK_CHMODE_Msk             (_UINT32_(0x3) << FLEX_US_MR_OOK_CHMODE_Pos)         /* (FLEX_US_MR) Channel Mode Mask */
#define FLEX_US_MR_OOK_CHMODE(value)          (FLEX_US_MR_OOK_CHMODE_Msk & (_UINT32_(value) << FLEX_US_MR_OOK_CHMODE_Pos))
#define   FLEX_US_MR_OOK_CHMODE_NORMAL_Val    _UINT32_(0x0)                                        /* (FLEX_US_MR) Normal mode  */
#define   FLEX_US_MR_OOK_CHMODE_AUTOMATIC_Val _UINT32_(0x1)                                        /* (FLEX_US_MR) Automatic Echo. Receiver input is connected to the TXD pin.  */
#define   FLEX_US_MR_OOK_CHMODE_LOCAL_LOOPBACK_Val _UINT32_(0x2)                                        /* (FLEX_US_MR) Local Loopback. Transmitter output is connected to the Receiver Input.  */
#define   FLEX_US_MR_OOK_CHMODE_REMOTE_LOOPBACK_Val _UINT32_(0x3)                                        /* (FLEX_US_MR) Remote Loopback. RXD pin is internally connected to the TXD pin.  */
#define FLEX_US_MR_OOK_CHMODE_NORMAL          (FLEX_US_MR_OOK_CHMODE_NORMAL_Val << FLEX_US_MR_OOK_CHMODE_Pos) /* (FLEX_US_MR) Normal mode Position  */
#define FLEX_US_MR_OOK_CHMODE_AUTOMATIC       (FLEX_US_MR_OOK_CHMODE_AUTOMATIC_Val << FLEX_US_MR_OOK_CHMODE_Pos) /* (FLEX_US_MR) Automatic Echo. Receiver input is connected to the TXD pin. Position  */
#define FLEX_US_MR_OOK_CHMODE_LOCAL_LOOPBACK  (FLEX_US_MR_OOK_CHMODE_LOCAL_LOOPBACK_Val << FLEX_US_MR_OOK_CHMODE_Pos) /* (FLEX_US_MR) Local Loopback. Transmitter output is connected to the Receiver Input. Position  */
#define FLEX_US_MR_OOK_CHMODE_REMOTE_LOOPBACK (FLEX_US_MR_OOK_CHMODE_REMOTE_LOOPBACK_Val << FLEX_US_MR_OOK_CHMODE_Pos) /* (FLEX_US_MR) Remote Loopback. RXD pin is internally connected to the TXD pin. Position  */
#define FLEX_US_MR_OOK_MSBF_Pos               _UINT32_(16)                                         /* (FLEX_US_MR) Bit Order Position */
#define FLEX_US_MR_OOK_MSBF_Msk               (_UINT32_(0x1) << FLEX_US_MR_OOK_MSBF_Pos)           /* (FLEX_US_MR) Bit Order Mask */
#define FLEX_US_MR_OOK_MSBF(value)            (FLEX_US_MR_OOK_MSBF_Msk & (_UINT32_(value) << FLEX_US_MR_OOK_MSBF_Pos))
#define FLEX_US_MR_OOK_MODE9_Pos              _UINT32_(17)                                         /* (FLEX_US_MR) 9-bit Character Length Position */
#define FLEX_US_MR_OOK_MODE9_Msk              (_UINT32_(0x1) << FLEX_US_MR_OOK_MODE9_Pos)          /* (FLEX_US_MR) 9-bit Character Length Mask */
#define FLEX_US_MR_OOK_MODE9(value)           (FLEX_US_MR_OOK_MODE9_Msk & (_UINT32_(value) << FLEX_US_MR_OOK_MODE9_Pos))
#define FLEX_US_MR_OOK_CLKO_Pos               _UINT32_(18)                                         /* (FLEX_US_MR) Clock Output Select Position */
#define FLEX_US_MR_OOK_CLKO_Msk               (_UINT32_(0x1) << FLEX_US_MR_OOK_CLKO_Pos)           /* (FLEX_US_MR) Clock Output Select Mask */
#define FLEX_US_MR_OOK_CLKO(value)            (FLEX_US_MR_OOK_CLKO_Msk & (_UINT32_(value) << FLEX_US_MR_OOK_CLKO_Pos))
#define FLEX_US_MR_OOK_OVER_Pos               _UINT32_(19)                                         /* (FLEX_US_MR) Oversampling Mode Position */
#define FLEX_US_MR_OOK_OVER_Msk               (_UINT32_(0x1) << FLEX_US_MR_OOK_OVER_Pos)           /* (FLEX_US_MR) Oversampling Mode Mask */
#define FLEX_US_MR_OOK_OVER(value)            (FLEX_US_MR_OOK_OVER_Msk & (_UINT32_(value) << FLEX_US_MR_OOK_OVER_Pos))
#define FLEX_US_MR_OOK_OOKRXD_Pos             _UINT32_(20)                                         /* (FLEX_US_MR) OOK Demodulation Input Selection Position */
#define FLEX_US_MR_OOK_OOKRXD_Msk             (_UINT32_(0x1) << FLEX_US_MR_OOK_OOKRXD_Pos)         /* (FLEX_US_MR) OOK Demodulation Input Selection Mask */
#define FLEX_US_MR_OOK_OOKRXD(value)          (FLEX_US_MR_OOK_OOKRXD_Msk & (_UINT32_(value) << FLEX_US_MR_OOK_OOKRXD_Pos))
#define FLEX_US_MR_OOK_OOKEN_Pos              _UINT32_(21)                                         /* (FLEX_US_MR) OOK Modulation/Demodulation Enabled Position */
#define FLEX_US_MR_OOK_OOKEN_Msk              (_UINT32_(0x1) << FLEX_US_MR_OOK_OOKEN_Pos)          /* (FLEX_US_MR) OOK Modulation/Demodulation Enabled Mask */
#define FLEX_US_MR_OOK_OOKEN(value)           (FLEX_US_MR_OOK_OOKEN_Msk & (_UINT32_(value) << FLEX_US_MR_OOK_OOKEN_Pos))
#define FLEX_US_MR_OOK_FILTER_Pos             _UINT32_(28)                                         /* (FLEX_US_MR) Receive Line Filter Position */
#define FLEX_US_MR_OOK_FILTER_Msk             (_UINT32_(0x1) << FLEX_US_MR_OOK_FILTER_Pos)         /* (FLEX_US_MR) Receive Line Filter Mask */
#define FLEX_US_MR_OOK_FILTER(value)          (FLEX_US_MR_OOK_FILTER_Msk & (_UINT32_(value) << FLEX_US_MR_OOK_FILTER_Pos))
#define FLEX_US_MR_OOK_Msk                    _UINT32_(0x103FFFFF)                                  /* (FLEX_US_MR_OOK) Register Mask  */


/* -------- FLEX_US_IER : (FLEXCOM Offset: 0x208) ( /W 32) USART Interrupt Enable Register -------- */
#define FLEX_US_IER_RXRDY_Pos                 _UINT32_(0)                                          /* (FLEX_US_IER) RXRDY Interrupt Enable Position */
#define FLEX_US_IER_RXRDY_Msk                 (_UINT32_(0x1) << FLEX_US_IER_RXRDY_Pos)             /* (FLEX_US_IER) RXRDY Interrupt Enable Mask */
#define FLEX_US_IER_RXRDY(value)              (FLEX_US_IER_RXRDY_Msk & (_UINT32_(value) << FLEX_US_IER_RXRDY_Pos)) /* Assigment of value for RXRDY in the FLEX_US_IER register */
#define FLEX_US_IER_TXRDY_Pos                 _UINT32_(1)                                          /* (FLEX_US_IER) TXRDY Interrupt Enable Position */
#define FLEX_US_IER_TXRDY_Msk                 (_UINT32_(0x1) << FLEX_US_IER_TXRDY_Pos)             /* (FLEX_US_IER) TXRDY Interrupt Enable Mask */
#define FLEX_US_IER_TXRDY(value)              (FLEX_US_IER_TXRDY_Msk & (_UINT32_(value) << FLEX_US_IER_TXRDY_Pos)) /* Assigment of value for TXRDY in the FLEX_US_IER register */
#define FLEX_US_IER_RXBRK_Pos                 _UINT32_(2)                                          /* (FLEX_US_IER) Receiver Break Interrupt Enable Position */
#define FLEX_US_IER_RXBRK_Msk                 (_UINT32_(0x1) << FLEX_US_IER_RXBRK_Pos)             /* (FLEX_US_IER) Receiver Break Interrupt Enable Mask */
#define FLEX_US_IER_RXBRK(value)              (FLEX_US_IER_RXBRK_Msk & (_UINT32_(value) << FLEX_US_IER_RXBRK_Pos)) /* Assigment of value for RXBRK in the FLEX_US_IER register */
#define FLEX_US_IER_ENDRX_Pos                 _UINT32_(3)                                          /* (FLEX_US_IER) End of Receive Transfer Interrupt Enable (available in all USART modes of operation) Position */
#define FLEX_US_IER_ENDRX_Msk                 (_UINT32_(0x1) << FLEX_US_IER_ENDRX_Pos)             /* (FLEX_US_IER) End of Receive Transfer Interrupt Enable (available in all USART modes of operation) Mask */
#define FLEX_US_IER_ENDRX(value)              (FLEX_US_IER_ENDRX_Msk & (_UINT32_(value) << FLEX_US_IER_ENDRX_Pos)) /* Assigment of value for ENDRX in the FLEX_US_IER register */
#define FLEX_US_IER_ENDTX_Pos                 _UINT32_(4)                                          /* (FLEX_US_IER) End of Transmit Interrupt Enable (available in all USART modes of operation) Position */
#define FLEX_US_IER_ENDTX_Msk                 (_UINT32_(0x1) << FLEX_US_IER_ENDTX_Pos)             /* (FLEX_US_IER) End of Transmit Interrupt Enable (available in all USART modes of operation) Mask */
#define FLEX_US_IER_ENDTX(value)              (FLEX_US_IER_ENDTX_Msk & (_UINT32_(value) << FLEX_US_IER_ENDTX_Pos)) /* Assigment of value for ENDTX in the FLEX_US_IER register */
#define FLEX_US_IER_OVRE_Pos                  _UINT32_(5)                                          /* (FLEX_US_IER) Overrun Error Interrupt Enable Position */
#define FLEX_US_IER_OVRE_Msk                  (_UINT32_(0x1) << FLEX_US_IER_OVRE_Pos)              /* (FLEX_US_IER) Overrun Error Interrupt Enable Mask */
#define FLEX_US_IER_OVRE(value)               (FLEX_US_IER_OVRE_Msk & (_UINT32_(value) << FLEX_US_IER_OVRE_Pos)) /* Assigment of value for OVRE in the FLEX_US_IER register */
#define FLEX_US_IER_FRAME_Pos                 _UINT32_(6)                                          /* (FLEX_US_IER) Framing Error Interrupt Enable Position */
#define FLEX_US_IER_FRAME_Msk                 (_UINT32_(0x1) << FLEX_US_IER_FRAME_Pos)             /* (FLEX_US_IER) Framing Error Interrupt Enable Mask */
#define FLEX_US_IER_FRAME(value)              (FLEX_US_IER_FRAME_Msk & (_UINT32_(value) << FLEX_US_IER_FRAME_Pos)) /* Assigment of value for FRAME in the FLEX_US_IER register */
#define FLEX_US_IER_PARE_Pos                  _UINT32_(7)                                          /* (FLEX_US_IER) Parity Error Interrupt Enable Position */
#define FLEX_US_IER_PARE_Msk                  (_UINT32_(0x1) << FLEX_US_IER_PARE_Pos)              /* (FLEX_US_IER) Parity Error Interrupt Enable Mask */
#define FLEX_US_IER_PARE(value)               (FLEX_US_IER_PARE_Msk & (_UINT32_(value) << FLEX_US_IER_PARE_Pos)) /* Assigment of value for PARE in the FLEX_US_IER register */
#define FLEX_US_IER_TIMEOUT_Pos               _UINT32_(8)                                          /* (FLEX_US_IER) Timeout Interrupt Enable Position */
#define FLEX_US_IER_TIMEOUT_Msk               (_UINT32_(0x1) << FLEX_US_IER_TIMEOUT_Pos)           /* (FLEX_US_IER) Timeout Interrupt Enable Mask */
#define FLEX_US_IER_TIMEOUT(value)            (FLEX_US_IER_TIMEOUT_Msk & (_UINT32_(value) << FLEX_US_IER_TIMEOUT_Pos)) /* Assigment of value for TIMEOUT in the FLEX_US_IER register */
#define FLEX_US_IER_TXEMPTY_Pos               _UINT32_(9)                                          /* (FLEX_US_IER) TXEMPTY Interrupt Enable Position */
#define FLEX_US_IER_TXEMPTY_Msk               (_UINT32_(0x1) << FLEX_US_IER_TXEMPTY_Pos)           /* (FLEX_US_IER) TXEMPTY Interrupt Enable Mask */
#define FLEX_US_IER_TXEMPTY(value)            (FLEX_US_IER_TXEMPTY_Msk & (_UINT32_(value) << FLEX_US_IER_TXEMPTY_Pos)) /* Assigment of value for TXEMPTY in the FLEX_US_IER register */
#define FLEX_US_IER_ITER_Pos                  _UINT32_(10)                                         /* (FLEX_US_IER) Max number of Repetitions Reached Interrupt Enable Position */
#define FLEX_US_IER_ITER_Msk                  (_UINT32_(0x1) << FLEX_US_IER_ITER_Pos)              /* (FLEX_US_IER) Max number of Repetitions Reached Interrupt Enable Mask */
#define FLEX_US_IER_ITER(value)               (FLEX_US_IER_ITER_Msk & (_UINT32_(value) << FLEX_US_IER_ITER_Pos)) /* Assigment of value for ITER in the FLEX_US_IER register */
#define FLEX_US_IER_TXBUFE_Pos                _UINT32_(11)                                         /* (FLEX_US_IER) Buffer Empty Interrupt Enable (available in all USART modes of operation) Position */
#define FLEX_US_IER_TXBUFE_Msk                (_UINT32_(0x1) << FLEX_US_IER_TXBUFE_Pos)            /* (FLEX_US_IER) Buffer Empty Interrupt Enable (available in all USART modes of operation) Mask */
#define FLEX_US_IER_TXBUFE(value)             (FLEX_US_IER_TXBUFE_Msk & (_UINT32_(value) << FLEX_US_IER_TXBUFE_Pos)) /* Assigment of value for TXBUFE in the FLEX_US_IER register */
#define FLEX_US_IER_RXBUFF_Pos                _UINT32_(12)                                         /* (FLEX_US_IER) Buffer Full Interrupt Enable (available in all USART modes of operation) Position */
#define FLEX_US_IER_RXBUFF_Msk                (_UINT32_(0x1) << FLEX_US_IER_RXBUFF_Pos)            /* (FLEX_US_IER) Buffer Full Interrupt Enable (available in all USART modes of operation) Mask */
#define FLEX_US_IER_RXBUFF(value)             (FLEX_US_IER_RXBUFF_Msk & (_UINT32_(value) << FLEX_US_IER_RXBUFF_Pos)) /* Assigment of value for RXBUFF in the FLEX_US_IER register */
#define FLEX_US_IER_NACK_Pos                  _UINT32_(13)                                         /* (FLEX_US_IER) Non Acknowledge Interrupt Enable Position */
#define FLEX_US_IER_NACK_Msk                  (_UINT32_(0x1) << FLEX_US_IER_NACK_Pos)              /* (FLEX_US_IER) Non Acknowledge Interrupt Enable Mask */
#define FLEX_US_IER_NACK(value)               (FLEX_US_IER_NACK_Msk & (_UINT32_(value) << FLEX_US_IER_NACK_Pos)) /* Assigment of value for NACK in the FLEX_US_IER register */
#define FLEX_US_IER_CTSIC_Pos                 _UINT32_(19)                                         /* (FLEX_US_IER) Clear to Send Input Change Interrupt Enable Position */
#define FLEX_US_IER_CTSIC_Msk                 (_UINT32_(0x1) << FLEX_US_IER_CTSIC_Pos)             /* (FLEX_US_IER) Clear to Send Input Change Interrupt Enable Mask */
#define FLEX_US_IER_CTSIC(value)              (FLEX_US_IER_CTSIC_Msk & (_UINT32_(value) << FLEX_US_IER_CTSIC_Pos)) /* Assigment of value for CTSIC in the FLEX_US_IER register */
#define FLEX_US_IER_CMP_Pos                   _UINT32_(22)                                         /* (FLEX_US_IER) Comparison Interrupt Enable Position */
#define FLEX_US_IER_CMP_Msk                   (_UINT32_(0x1) << FLEX_US_IER_CMP_Pos)               /* (FLEX_US_IER) Comparison Interrupt Enable Mask */
#define FLEX_US_IER_CMP(value)                (FLEX_US_IER_CMP_Msk & (_UINT32_(value) << FLEX_US_IER_CMP_Pos)) /* Assigment of value for CMP in the FLEX_US_IER register */
#define FLEX_US_IER_MANE_Pos                  _UINT32_(24)                                         /* (FLEX_US_IER) Manchester Error Interrupt Enable Position */
#define FLEX_US_IER_MANE_Msk                  (_UINT32_(0x1) << FLEX_US_IER_MANE_Pos)              /* (FLEX_US_IER) Manchester Error Interrupt Enable Mask */
#define FLEX_US_IER_MANE(value)               (FLEX_US_IER_MANE_Msk & (_UINT32_(value) << FLEX_US_IER_MANE_Pos)) /* Assigment of value for MANE in the FLEX_US_IER register */
#define FLEX_US_IER_Msk                       _UINT32_(0x01483FFF)                                 /* (FLEX_US_IER) Register Mask  */

/* LIN mode */
#define FLEX_US_IER_LIN_Msk                   _UINT32_(0x00000000)                                  /* (FLEX_US_IER_LIN) Register Mask  */


/* -------- FLEX_US_IDR : (FLEXCOM Offset: 0x20C) ( /W 32) USART Interrupt Disable Register -------- */
#define FLEX_US_IDR_RXRDY_Pos                 _UINT32_(0)                                          /* (FLEX_US_IDR) RXRDY Interrupt Disable Position */
#define FLEX_US_IDR_RXRDY_Msk                 (_UINT32_(0x1) << FLEX_US_IDR_RXRDY_Pos)             /* (FLEX_US_IDR) RXRDY Interrupt Disable Mask */
#define FLEX_US_IDR_RXRDY(value)              (FLEX_US_IDR_RXRDY_Msk & (_UINT32_(value) << FLEX_US_IDR_RXRDY_Pos)) /* Assigment of value for RXRDY in the FLEX_US_IDR register */
#define FLEX_US_IDR_TXRDY_Pos                 _UINT32_(1)                                          /* (FLEX_US_IDR) TXRDY Interrupt Disable Position */
#define FLEX_US_IDR_TXRDY_Msk                 (_UINT32_(0x1) << FLEX_US_IDR_TXRDY_Pos)             /* (FLEX_US_IDR) TXRDY Interrupt Disable Mask */
#define FLEX_US_IDR_TXRDY(value)              (FLEX_US_IDR_TXRDY_Msk & (_UINT32_(value) << FLEX_US_IDR_TXRDY_Pos)) /* Assigment of value for TXRDY in the FLEX_US_IDR register */
#define FLEX_US_IDR_RXBRK_Pos                 _UINT32_(2)                                          /* (FLEX_US_IDR) Receiver Break Interrupt Disable Position */
#define FLEX_US_IDR_RXBRK_Msk                 (_UINT32_(0x1) << FLEX_US_IDR_RXBRK_Pos)             /* (FLEX_US_IDR) Receiver Break Interrupt Disable Mask */
#define FLEX_US_IDR_RXBRK(value)              (FLEX_US_IDR_RXBRK_Msk & (_UINT32_(value) << FLEX_US_IDR_RXBRK_Pos)) /* Assigment of value for RXBRK in the FLEX_US_IDR register */
#define FLEX_US_IDR_ENDRX_Pos                 _UINT32_(3)                                          /* (FLEX_US_IDR) End of Receive Transfer Interrupt Disable (available in all USART modes of operation) Position */
#define FLEX_US_IDR_ENDRX_Msk                 (_UINT32_(0x1) << FLEX_US_IDR_ENDRX_Pos)             /* (FLEX_US_IDR) End of Receive Transfer Interrupt Disable (available in all USART modes of operation) Mask */
#define FLEX_US_IDR_ENDRX(value)              (FLEX_US_IDR_ENDRX_Msk & (_UINT32_(value) << FLEX_US_IDR_ENDRX_Pos)) /* Assigment of value for ENDRX in the FLEX_US_IDR register */
#define FLEX_US_IDR_ENDTX_Pos                 _UINT32_(4)                                          /* (FLEX_US_IDR) End of Transmit Interrupt Disable (available in all USART modes of operation) Position */
#define FLEX_US_IDR_ENDTX_Msk                 (_UINT32_(0x1) << FLEX_US_IDR_ENDTX_Pos)             /* (FLEX_US_IDR) End of Transmit Interrupt Disable (available in all USART modes of operation) Mask */
#define FLEX_US_IDR_ENDTX(value)              (FLEX_US_IDR_ENDTX_Msk & (_UINT32_(value) << FLEX_US_IDR_ENDTX_Pos)) /* Assigment of value for ENDTX in the FLEX_US_IDR register */
#define FLEX_US_IDR_OVRE_Pos                  _UINT32_(5)                                          /* (FLEX_US_IDR) Overrun Error Interrupt Disable Position */
#define FLEX_US_IDR_OVRE_Msk                  (_UINT32_(0x1) << FLEX_US_IDR_OVRE_Pos)              /* (FLEX_US_IDR) Overrun Error Interrupt Disable Mask */
#define FLEX_US_IDR_OVRE(value)               (FLEX_US_IDR_OVRE_Msk & (_UINT32_(value) << FLEX_US_IDR_OVRE_Pos)) /* Assigment of value for OVRE in the FLEX_US_IDR register */
#define FLEX_US_IDR_FRAME_Pos                 _UINT32_(6)                                          /* (FLEX_US_IDR) Framing Error Interrupt Disable Position */
#define FLEX_US_IDR_FRAME_Msk                 (_UINT32_(0x1) << FLEX_US_IDR_FRAME_Pos)             /* (FLEX_US_IDR) Framing Error Interrupt Disable Mask */
#define FLEX_US_IDR_FRAME(value)              (FLEX_US_IDR_FRAME_Msk & (_UINT32_(value) << FLEX_US_IDR_FRAME_Pos)) /* Assigment of value for FRAME in the FLEX_US_IDR register */
#define FLEX_US_IDR_PARE_Pos                  _UINT32_(7)                                          /* (FLEX_US_IDR) Parity Error Interrupt Disable Position */
#define FLEX_US_IDR_PARE_Msk                  (_UINT32_(0x1) << FLEX_US_IDR_PARE_Pos)              /* (FLEX_US_IDR) Parity Error Interrupt Disable Mask */
#define FLEX_US_IDR_PARE(value)               (FLEX_US_IDR_PARE_Msk & (_UINT32_(value) << FLEX_US_IDR_PARE_Pos)) /* Assigment of value for PARE in the FLEX_US_IDR register */
#define FLEX_US_IDR_TIMEOUT_Pos               _UINT32_(8)                                          /* (FLEX_US_IDR) Timeout Interrupt Disable Position */
#define FLEX_US_IDR_TIMEOUT_Msk               (_UINT32_(0x1) << FLEX_US_IDR_TIMEOUT_Pos)           /* (FLEX_US_IDR) Timeout Interrupt Disable Mask */
#define FLEX_US_IDR_TIMEOUT(value)            (FLEX_US_IDR_TIMEOUT_Msk & (_UINT32_(value) << FLEX_US_IDR_TIMEOUT_Pos)) /* Assigment of value for TIMEOUT in the FLEX_US_IDR register */
#define FLEX_US_IDR_TXEMPTY_Pos               _UINT32_(9)                                          /* (FLEX_US_IDR) TXEMPTY Interrupt Disable Position */
#define FLEX_US_IDR_TXEMPTY_Msk               (_UINT32_(0x1) << FLEX_US_IDR_TXEMPTY_Pos)           /* (FLEX_US_IDR) TXEMPTY Interrupt Disable Mask */
#define FLEX_US_IDR_TXEMPTY(value)            (FLEX_US_IDR_TXEMPTY_Msk & (_UINT32_(value) << FLEX_US_IDR_TXEMPTY_Pos)) /* Assigment of value for TXEMPTY in the FLEX_US_IDR register */
#define FLEX_US_IDR_ITER_Pos                  _UINT32_(10)                                         /* (FLEX_US_IDR) Max Number of Repetitions Reached Interrupt Disable Position */
#define FLEX_US_IDR_ITER_Msk                  (_UINT32_(0x1) << FLEX_US_IDR_ITER_Pos)              /* (FLEX_US_IDR) Max Number of Repetitions Reached Interrupt Disable Mask */
#define FLEX_US_IDR_ITER(value)               (FLEX_US_IDR_ITER_Msk & (_UINT32_(value) << FLEX_US_IDR_ITER_Pos)) /* Assigment of value for ITER in the FLEX_US_IDR register */
#define FLEX_US_IDR_TXBUFE_Pos                _UINT32_(11)                                         /* (FLEX_US_IDR) Buffer Empty Interrupt Disable (available in all USART modes of operation) Position */
#define FLEX_US_IDR_TXBUFE_Msk                (_UINT32_(0x1) << FLEX_US_IDR_TXBUFE_Pos)            /* (FLEX_US_IDR) Buffer Empty Interrupt Disable (available in all USART modes of operation) Mask */
#define FLEX_US_IDR_TXBUFE(value)             (FLEX_US_IDR_TXBUFE_Msk & (_UINT32_(value) << FLEX_US_IDR_TXBUFE_Pos)) /* Assigment of value for TXBUFE in the FLEX_US_IDR register */
#define FLEX_US_IDR_RXBUFF_Pos                _UINT32_(12)                                         /* (FLEX_US_IDR) Buffer Full Interrupt Disable (available in all USART modes of operation) Position */
#define FLEX_US_IDR_RXBUFF_Msk                (_UINT32_(0x1) << FLEX_US_IDR_RXBUFF_Pos)            /* (FLEX_US_IDR) Buffer Full Interrupt Disable (available in all USART modes of operation) Mask */
#define FLEX_US_IDR_RXBUFF(value)             (FLEX_US_IDR_RXBUFF_Msk & (_UINT32_(value) << FLEX_US_IDR_RXBUFF_Pos)) /* Assigment of value for RXBUFF in the FLEX_US_IDR register */
#define FLEX_US_IDR_NACK_Pos                  _UINT32_(13)                                         /* (FLEX_US_IDR) Non Acknowledge Interrupt Disable Position */
#define FLEX_US_IDR_NACK_Msk                  (_UINT32_(0x1) << FLEX_US_IDR_NACK_Pos)              /* (FLEX_US_IDR) Non Acknowledge Interrupt Disable Mask */
#define FLEX_US_IDR_NACK(value)               (FLEX_US_IDR_NACK_Msk & (_UINT32_(value) << FLEX_US_IDR_NACK_Pos)) /* Assigment of value for NACK in the FLEX_US_IDR register */
#define FLEX_US_IDR_CTSIC_Pos                 _UINT32_(19)                                         /* (FLEX_US_IDR) Clear to Send Input Change Interrupt Disable Position */
#define FLEX_US_IDR_CTSIC_Msk                 (_UINT32_(0x1) << FLEX_US_IDR_CTSIC_Pos)             /* (FLEX_US_IDR) Clear to Send Input Change Interrupt Disable Mask */
#define FLEX_US_IDR_CTSIC(value)              (FLEX_US_IDR_CTSIC_Msk & (_UINT32_(value) << FLEX_US_IDR_CTSIC_Pos)) /* Assigment of value for CTSIC in the FLEX_US_IDR register */
#define FLEX_US_IDR_CMP_Pos                   _UINT32_(22)                                         /* (FLEX_US_IDR) Comparison Interrupt Disable Position */
#define FLEX_US_IDR_CMP_Msk                   (_UINT32_(0x1) << FLEX_US_IDR_CMP_Pos)               /* (FLEX_US_IDR) Comparison Interrupt Disable Mask */
#define FLEX_US_IDR_CMP(value)                (FLEX_US_IDR_CMP_Msk & (_UINT32_(value) << FLEX_US_IDR_CMP_Pos)) /* Assigment of value for CMP in the FLEX_US_IDR register */
#define FLEX_US_IDR_MANE_Pos                  _UINT32_(24)                                         /* (FLEX_US_IDR) Manchester Error Interrupt Disable Position */
#define FLEX_US_IDR_MANE_Msk                  (_UINT32_(0x1) << FLEX_US_IDR_MANE_Pos)              /* (FLEX_US_IDR) Manchester Error Interrupt Disable Mask */
#define FLEX_US_IDR_MANE(value)               (FLEX_US_IDR_MANE_Msk & (_UINT32_(value) << FLEX_US_IDR_MANE_Pos)) /* Assigment of value for MANE in the FLEX_US_IDR register */
#define FLEX_US_IDR_Msk                       _UINT32_(0x01483FFF)                                 /* (FLEX_US_IDR) Register Mask  */

/* LIN mode */
#define FLEX_US_IDR_LIN_Msk                   _UINT32_(0x00000000)                                  /* (FLEX_US_IDR_LIN) Register Mask  */


/* -------- FLEX_US_IMR : (FLEXCOM Offset: 0x210) ( R/ 32) USART Interrupt Mask Register -------- */
#define FLEX_US_IMR_RXRDY_Pos                 _UINT32_(0)                                          /* (FLEX_US_IMR) RXRDY Interrupt Mask Position */
#define FLEX_US_IMR_RXRDY_Msk                 (_UINT32_(0x1) << FLEX_US_IMR_RXRDY_Pos)             /* (FLEX_US_IMR) RXRDY Interrupt Mask Mask */
#define FLEX_US_IMR_RXRDY(value)              (FLEX_US_IMR_RXRDY_Msk & (_UINT32_(value) << FLEX_US_IMR_RXRDY_Pos)) /* Assigment of value for RXRDY in the FLEX_US_IMR register */
#define FLEX_US_IMR_TXRDY_Pos                 _UINT32_(1)                                          /* (FLEX_US_IMR) TXRDY Interrupt Mask Position */
#define FLEX_US_IMR_TXRDY_Msk                 (_UINT32_(0x1) << FLEX_US_IMR_TXRDY_Pos)             /* (FLEX_US_IMR) TXRDY Interrupt Mask Mask */
#define FLEX_US_IMR_TXRDY(value)              (FLEX_US_IMR_TXRDY_Msk & (_UINT32_(value) << FLEX_US_IMR_TXRDY_Pos)) /* Assigment of value for TXRDY in the FLEX_US_IMR register */
#define FLEX_US_IMR_RXBRK_Pos                 _UINT32_(2)                                          /* (FLEX_US_IMR) Receiver Break Interrupt Mask Position */
#define FLEX_US_IMR_RXBRK_Msk                 (_UINT32_(0x1) << FLEX_US_IMR_RXBRK_Pos)             /* (FLEX_US_IMR) Receiver Break Interrupt Mask Mask */
#define FLEX_US_IMR_RXBRK(value)              (FLEX_US_IMR_RXBRK_Msk & (_UINT32_(value) << FLEX_US_IMR_RXBRK_Pos)) /* Assigment of value for RXBRK in the FLEX_US_IMR register */
#define FLEX_US_IMR_ENDRX_Pos                 _UINT32_(3)                                          /* (FLEX_US_IMR) End of Receive Transfer Interrupt Mask (available in all USART modes of operation) Position */
#define FLEX_US_IMR_ENDRX_Msk                 (_UINT32_(0x1) << FLEX_US_IMR_ENDRX_Pos)             /* (FLEX_US_IMR) End of Receive Transfer Interrupt Mask (available in all USART modes of operation) Mask */
#define FLEX_US_IMR_ENDRX(value)              (FLEX_US_IMR_ENDRX_Msk & (_UINT32_(value) << FLEX_US_IMR_ENDRX_Pos)) /* Assigment of value for ENDRX in the FLEX_US_IMR register */
#define FLEX_US_IMR_ENDTX_Pos                 _UINT32_(4)                                          /* (FLEX_US_IMR) End of Transmit Interrupt Mask (available in all USART modes of operation) Position */
#define FLEX_US_IMR_ENDTX_Msk                 (_UINT32_(0x1) << FLEX_US_IMR_ENDTX_Pos)             /* (FLEX_US_IMR) End of Transmit Interrupt Mask (available in all USART modes of operation) Mask */
#define FLEX_US_IMR_ENDTX(value)              (FLEX_US_IMR_ENDTX_Msk & (_UINT32_(value) << FLEX_US_IMR_ENDTX_Pos)) /* Assigment of value for ENDTX in the FLEX_US_IMR register */
#define FLEX_US_IMR_OVRE_Pos                  _UINT32_(5)                                          /* (FLEX_US_IMR) Overrun Error Interrupt Mask Position */
#define FLEX_US_IMR_OVRE_Msk                  (_UINT32_(0x1) << FLEX_US_IMR_OVRE_Pos)              /* (FLEX_US_IMR) Overrun Error Interrupt Mask Mask */
#define FLEX_US_IMR_OVRE(value)               (FLEX_US_IMR_OVRE_Msk & (_UINT32_(value) << FLEX_US_IMR_OVRE_Pos)) /* Assigment of value for OVRE in the FLEX_US_IMR register */
#define FLEX_US_IMR_FRAME_Pos                 _UINT32_(6)                                          /* (FLEX_US_IMR) Framing Error Interrupt Mask Position */
#define FLEX_US_IMR_FRAME_Msk                 (_UINT32_(0x1) << FLEX_US_IMR_FRAME_Pos)             /* (FLEX_US_IMR) Framing Error Interrupt Mask Mask */
#define FLEX_US_IMR_FRAME(value)              (FLEX_US_IMR_FRAME_Msk & (_UINT32_(value) << FLEX_US_IMR_FRAME_Pos)) /* Assigment of value for FRAME in the FLEX_US_IMR register */
#define FLEX_US_IMR_PARE_Pos                  _UINT32_(7)                                          /* (FLEX_US_IMR) Parity Error Interrupt Mask Position */
#define FLEX_US_IMR_PARE_Msk                  (_UINT32_(0x1) << FLEX_US_IMR_PARE_Pos)              /* (FLEX_US_IMR) Parity Error Interrupt Mask Mask */
#define FLEX_US_IMR_PARE(value)               (FLEX_US_IMR_PARE_Msk & (_UINT32_(value) << FLEX_US_IMR_PARE_Pos)) /* Assigment of value for PARE in the FLEX_US_IMR register */
#define FLEX_US_IMR_TIMEOUT_Pos               _UINT32_(8)                                          /* (FLEX_US_IMR) Timeout Interrupt Mask Position */
#define FLEX_US_IMR_TIMEOUT_Msk               (_UINT32_(0x1) << FLEX_US_IMR_TIMEOUT_Pos)           /* (FLEX_US_IMR) Timeout Interrupt Mask Mask */
#define FLEX_US_IMR_TIMEOUT(value)            (FLEX_US_IMR_TIMEOUT_Msk & (_UINT32_(value) << FLEX_US_IMR_TIMEOUT_Pos)) /* Assigment of value for TIMEOUT in the FLEX_US_IMR register */
#define FLEX_US_IMR_TXEMPTY_Pos               _UINT32_(9)                                          /* (FLEX_US_IMR) TXEMPTY Interrupt Mask Position */
#define FLEX_US_IMR_TXEMPTY_Msk               (_UINT32_(0x1) << FLEX_US_IMR_TXEMPTY_Pos)           /* (FLEX_US_IMR) TXEMPTY Interrupt Mask Mask */
#define FLEX_US_IMR_TXEMPTY(value)            (FLEX_US_IMR_TXEMPTY_Msk & (_UINT32_(value) << FLEX_US_IMR_TXEMPTY_Pos)) /* Assigment of value for TXEMPTY in the FLEX_US_IMR register */
#define FLEX_US_IMR_ITER_Pos                  _UINT32_(10)                                         /* (FLEX_US_IMR) Max Number of Repetitions Reached Interrupt Mask Position */
#define FLEX_US_IMR_ITER_Msk                  (_UINT32_(0x1) << FLEX_US_IMR_ITER_Pos)              /* (FLEX_US_IMR) Max Number of Repetitions Reached Interrupt Mask Mask */
#define FLEX_US_IMR_ITER(value)               (FLEX_US_IMR_ITER_Msk & (_UINT32_(value) << FLEX_US_IMR_ITER_Pos)) /* Assigment of value for ITER in the FLEX_US_IMR register */
#define FLEX_US_IMR_TXBUFE_Pos                _UINT32_(11)                                         /* (FLEX_US_IMR) Buffer Empty Interrupt Mask (available in all USART modes of operation) Position */
#define FLEX_US_IMR_TXBUFE_Msk                (_UINT32_(0x1) << FLEX_US_IMR_TXBUFE_Pos)            /* (FLEX_US_IMR) Buffer Empty Interrupt Mask (available in all USART modes of operation) Mask */
#define FLEX_US_IMR_TXBUFE(value)             (FLEX_US_IMR_TXBUFE_Msk & (_UINT32_(value) << FLEX_US_IMR_TXBUFE_Pos)) /* Assigment of value for TXBUFE in the FLEX_US_IMR register */
#define FLEX_US_IMR_RXBUFF_Pos                _UINT32_(12)                                         /* (FLEX_US_IMR) Buffer Full Interrupt Mask (available in all USART modes of operation) Position */
#define FLEX_US_IMR_RXBUFF_Msk                (_UINT32_(0x1) << FLEX_US_IMR_RXBUFF_Pos)            /* (FLEX_US_IMR) Buffer Full Interrupt Mask (available in all USART modes of operation) Mask */
#define FLEX_US_IMR_RXBUFF(value)             (FLEX_US_IMR_RXBUFF_Msk & (_UINT32_(value) << FLEX_US_IMR_RXBUFF_Pos)) /* Assigment of value for RXBUFF in the FLEX_US_IMR register */
#define FLEX_US_IMR_NACK_Pos                  _UINT32_(13)                                         /* (FLEX_US_IMR) Non Acknowledge Interrupt Mask Position */
#define FLEX_US_IMR_NACK_Msk                  (_UINT32_(0x1) << FLEX_US_IMR_NACK_Pos)              /* (FLEX_US_IMR) Non Acknowledge Interrupt Mask Mask */
#define FLEX_US_IMR_NACK(value)               (FLEX_US_IMR_NACK_Msk & (_UINT32_(value) << FLEX_US_IMR_NACK_Pos)) /* Assigment of value for NACK in the FLEX_US_IMR register */
#define FLEX_US_IMR_CTSIC_Pos                 _UINT32_(19)                                         /* (FLEX_US_IMR) Clear to Send Input Change Interrupt Mask Position */
#define FLEX_US_IMR_CTSIC_Msk                 (_UINT32_(0x1) << FLEX_US_IMR_CTSIC_Pos)             /* (FLEX_US_IMR) Clear to Send Input Change Interrupt Mask Mask */
#define FLEX_US_IMR_CTSIC(value)              (FLEX_US_IMR_CTSIC_Msk & (_UINT32_(value) << FLEX_US_IMR_CTSIC_Pos)) /* Assigment of value for CTSIC in the FLEX_US_IMR register */
#define FLEX_US_IMR_CMP_Pos                   _UINT32_(22)                                         /* (FLEX_US_IMR) Comparison Interrupt Mask Position */
#define FLEX_US_IMR_CMP_Msk                   (_UINT32_(0x1) << FLEX_US_IMR_CMP_Pos)               /* (FLEX_US_IMR) Comparison Interrupt Mask Mask */
#define FLEX_US_IMR_CMP(value)                (FLEX_US_IMR_CMP_Msk & (_UINT32_(value) << FLEX_US_IMR_CMP_Pos)) /* Assigment of value for CMP in the FLEX_US_IMR register */
#define FLEX_US_IMR_MANE_Pos                  _UINT32_(24)                                         /* (FLEX_US_IMR) Manchester Error Interrupt Mask Position */
#define FLEX_US_IMR_MANE_Msk                  (_UINT32_(0x1) << FLEX_US_IMR_MANE_Pos)              /* (FLEX_US_IMR) Manchester Error Interrupt Mask Mask */
#define FLEX_US_IMR_MANE(value)               (FLEX_US_IMR_MANE_Msk & (_UINT32_(value) << FLEX_US_IMR_MANE_Pos)) /* Assigment of value for MANE in the FLEX_US_IMR register */
#define FLEX_US_IMR_Msk                       _UINT32_(0x01483FFF)                                 /* (FLEX_US_IMR) Register Mask  */

/* LIN mode */
#define FLEX_US_IMR_LIN_Msk                   _UINT32_(0x00000000)                                  /* (FLEX_US_IMR_LIN) Register Mask  */


/* -------- FLEX_US_CSR : (FLEXCOM Offset: 0x214) ( R/ 32) USART Channel Status Register -------- */
#define FLEX_US_CSR_RXRDY_Pos                 _UINT32_(0)                                          /* (FLEX_US_CSR) Receiver Ready (cleared by reading FLEX_US_RHR) Position */
#define FLEX_US_CSR_RXRDY_Msk                 (_UINT32_(0x1) << FLEX_US_CSR_RXRDY_Pos)             /* (FLEX_US_CSR) Receiver Ready (cleared by reading FLEX_US_RHR) Mask */
#define FLEX_US_CSR_RXRDY(value)              (FLEX_US_CSR_RXRDY_Msk & (_UINT32_(value) << FLEX_US_CSR_RXRDY_Pos)) /* Assigment of value for RXRDY in the FLEX_US_CSR register */
#define FLEX_US_CSR_TXRDY_Pos                 _UINT32_(1)                                          /* (FLEX_US_CSR) Transmitter Ready (cleared by writing FLEX_US_THR) Position */
#define FLEX_US_CSR_TXRDY_Msk                 (_UINT32_(0x1) << FLEX_US_CSR_TXRDY_Pos)             /* (FLEX_US_CSR) Transmitter Ready (cleared by writing FLEX_US_THR) Mask */
#define FLEX_US_CSR_TXRDY(value)              (FLEX_US_CSR_TXRDY_Msk & (_UINT32_(value) << FLEX_US_CSR_TXRDY_Pos)) /* Assigment of value for TXRDY in the FLEX_US_CSR register */
#define FLEX_US_CSR_RXBRK_Pos                 _UINT32_(2)                                          /* (FLEX_US_CSR) Break Received/End of Break Position */
#define FLEX_US_CSR_RXBRK_Msk                 (_UINT32_(0x1) << FLEX_US_CSR_RXBRK_Pos)             /* (FLEX_US_CSR) Break Received/End of Break Mask */
#define FLEX_US_CSR_RXBRK(value)              (FLEX_US_CSR_RXBRK_Msk & (_UINT32_(value) << FLEX_US_CSR_RXBRK_Pos)) /* Assigment of value for RXBRK in the FLEX_US_CSR register */
#define FLEX_US_CSR_ENDRX_Pos                 _UINT32_(3)                                          /* (FLEX_US_CSR) End of RX Buffer (cleared by writing FLEX_US_RCR or FLEX_US_RNCR) Position */
#define FLEX_US_CSR_ENDRX_Msk                 (_UINT32_(0x1) << FLEX_US_CSR_ENDRX_Pos)             /* (FLEX_US_CSR) End of RX Buffer (cleared by writing FLEX_US_RCR or FLEX_US_RNCR) Mask */
#define FLEX_US_CSR_ENDRX(value)              (FLEX_US_CSR_ENDRX_Msk & (_UINT32_(value) << FLEX_US_CSR_ENDRX_Pos)) /* Assigment of value for ENDRX in the FLEX_US_CSR register */
#define FLEX_US_CSR_ENDTX_Pos                 _UINT32_(4)                                          /* (FLEX_US_CSR) End of TX Buffer (cleared by writing FLEX_US_TCR or FLEX_US_TNCR) Position */
#define FLEX_US_CSR_ENDTX_Msk                 (_UINT32_(0x1) << FLEX_US_CSR_ENDTX_Pos)             /* (FLEX_US_CSR) End of TX Buffer (cleared by writing FLEX_US_TCR or FLEX_US_TNCR) Mask */
#define FLEX_US_CSR_ENDTX(value)              (FLEX_US_CSR_ENDTX_Msk & (_UINT32_(value) << FLEX_US_CSR_ENDTX_Pos)) /* Assigment of value for ENDTX in the FLEX_US_CSR register */
#define FLEX_US_CSR_OVRE_Pos                  _UINT32_(5)                                          /* (FLEX_US_CSR) Overrun Error Position */
#define FLEX_US_CSR_OVRE_Msk                  (_UINT32_(0x1) << FLEX_US_CSR_OVRE_Pos)              /* (FLEX_US_CSR) Overrun Error Mask */
#define FLEX_US_CSR_OVRE(value)               (FLEX_US_CSR_OVRE_Msk & (_UINT32_(value) << FLEX_US_CSR_OVRE_Pos)) /* Assigment of value for OVRE in the FLEX_US_CSR register */
#define FLEX_US_CSR_FRAME_Pos                 _UINT32_(6)                                          /* (FLEX_US_CSR) Framing Error Position */
#define FLEX_US_CSR_FRAME_Msk                 (_UINT32_(0x1) << FLEX_US_CSR_FRAME_Pos)             /* (FLEX_US_CSR) Framing Error Mask */
#define FLEX_US_CSR_FRAME(value)              (FLEX_US_CSR_FRAME_Msk & (_UINT32_(value) << FLEX_US_CSR_FRAME_Pos)) /* Assigment of value for FRAME in the FLEX_US_CSR register */
#define FLEX_US_CSR_PARE_Pos                  _UINT32_(7)                                          /* (FLEX_US_CSR) Parity Error Position */
#define FLEX_US_CSR_PARE_Msk                  (_UINT32_(0x1) << FLEX_US_CSR_PARE_Pos)              /* (FLEX_US_CSR) Parity Error Mask */
#define FLEX_US_CSR_PARE(value)               (FLEX_US_CSR_PARE_Msk & (_UINT32_(value) << FLEX_US_CSR_PARE_Pos)) /* Assigment of value for PARE in the FLEX_US_CSR register */
#define FLEX_US_CSR_TIMEOUT_Pos               _UINT32_(8)                                          /* (FLEX_US_CSR) Receiver Timeout Position */
#define FLEX_US_CSR_TIMEOUT_Msk               (_UINT32_(0x1) << FLEX_US_CSR_TIMEOUT_Pos)           /* (FLEX_US_CSR) Receiver Timeout Mask */
#define FLEX_US_CSR_TIMEOUT(value)            (FLEX_US_CSR_TIMEOUT_Msk & (_UINT32_(value) << FLEX_US_CSR_TIMEOUT_Pos)) /* Assigment of value for TIMEOUT in the FLEX_US_CSR register */
#define FLEX_US_CSR_TXEMPTY_Pos               _UINT32_(9)                                          /* (FLEX_US_CSR) Transmitter Empty (cleared by writing FLEX_US_THR) Position */
#define FLEX_US_CSR_TXEMPTY_Msk               (_UINT32_(0x1) << FLEX_US_CSR_TXEMPTY_Pos)           /* (FLEX_US_CSR) Transmitter Empty (cleared by writing FLEX_US_THR) Mask */
#define FLEX_US_CSR_TXEMPTY(value)            (FLEX_US_CSR_TXEMPTY_Msk & (_UINT32_(value) << FLEX_US_CSR_TXEMPTY_Pos)) /* Assigment of value for TXEMPTY in the FLEX_US_CSR register */
#define FLEX_US_CSR_ITER_Pos                  _UINT32_(10)                                         /* (FLEX_US_CSR) Max Number of Repetitions Reached Position */
#define FLEX_US_CSR_ITER_Msk                  (_UINT32_(0x1) << FLEX_US_CSR_ITER_Pos)              /* (FLEX_US_CSR) Max Number of Repetitions Reached Mask */
#define FLEX_US_CSR_ITER(value)               (FLEX_US_CSR_ITER_Msk & (_UINT32_(value) << FLEX_US_CSR_ITER_Pos)) /* Assigment of value for ITER in the FLEX_US_CSR register */
#define FLEX_US_CSR_TXBUFE_Pos                _UINT32_(11)                                         /* (FLEX_US_CSR) TX Buffer Empty (cleared by writing FLEX_US_TCR or FLEX_US_TNCR) Position */
#define FLEX_US_CSR_TXBUFE_Msk                (_UINT32_(0x1) << FLEX_US_CSR_TXBUFE_Pos)            /* (FLEX_US_CSR) TX Buffer Empty (cleared by writing FLEX_US_TCR or FLEX_US_TNCR) Mask */
#define FLEX_US_CSR_TXBUFE(value)             (FLEX_US_CSR_TXBUFE_Msk & (_UINT32_(value) << FLEX_US_CSR_TXBUFE_Pos)) /* Assigment of value for TXBUFE in the FLEX_US_CSR register */
#define FLEX_US_CSR_RXBUFF_Pos                _UINT32_(12)                                         /* (FLEX_US_CSR) RX Buffer Full (cleared by writing FLEX_US_RCR or FLEX_US_RNCR) Position */
#define FLEX_US_CSR_RXBUFF_Msk                (_UINT32_(0x1) << FLEX_US_CSR_RXBUFF_Pos)            /* (FLEX_US_CSR) RX Buffer Full (cleared by writing FLEX_US_RCR or FLEX_US_RNCR) Mask */
#define FLEX_US_CSR_RXBUFF(value)             (FLEX_US_CSR_RXBUFF_Msk & (_UINT32_(value) << FLEX_US_CSR_RXBUFF_Pos)) /* Assigment of value for RXBUFF in the FLEX_US_CSR register */
#define FLEX_US_CSR_NACK_Pos                  _UINT32_(13)                                         /* (FLEX_US_CSR) Non Acknowledge Interrupt Position */
#define FLEX_US_CSR_NACK_Msk                  (_UINT32_(0x1) << FLEX_US_CSR_NACK_Pos)              /* (FLEX_US_CSR) Non Acknowledge Interrupt Mask */
#define FLEX_US_CSR_NACK(value)               (FLEX_US_CSR_NACK_Msk & (_UINT32_(value) << FLEX_US_CSR_NACK_Pos)) /* Assigment of value for NACK in the FLEX_US_CSR register */
#define FLEX_US_CSR_CTSIC_Pos                 _UINT32_(19)                                         /* (FLEX_US_CSR) Clear to Send Input Change Flag Position */
#define FLEX_US_CSR_CTSIC_Msk                 (_UINT32_(0x1) << FLEX_US_CSR_CTSIC_Pos)             /* (FLEX_US_CSR) Clear to Send Input Change Flag Mask */
#define FLEX_US_CSR_CTSIC(value)              (FLEX_US_CSR_CTSIC_Msk & (_UINT32_(value) << FLEX_US_CSR_CTSIC_Pos)) /* Assigment of value for CTSIC in the FLEX_US_CSR register */
#define FLEX_US_CSR_CMP_Pos                   _UINT32_(22)                                         /* (FLEX_US_CSR) Comparison Status Position */
#define FLEX_US_CSR_CMP_Msk                   (_UINT32_(0x1) << FLEX_US_CSR_CMP_Pos)               /* (FLEX_US_CSR) Comparison Status Mask */
#define FLEX_US_CSR_CMP(value)                (FLEX_US_CSR_CMP_Msk & (_UINT32_(value) << FLEX_US_CSR_CMP_Pos)) /* Assigment of value for CMP in the FLEX_US_CSR register */
#define FLEX_US_CSR_CTS_Pos                   _UINT32_(23)                                         /* (FLEX_US_CSR) Image of CTS Input Position */
#define FLEX_US_CSR_CTS_Msk                   (_UINT32_(0x1) << FLEX_US_CSR_CTS_Pos)               /* (FLEX_US_CSR) Image of CTS Input Mask */
#define FLEX_US_CSR_CTS(value)                (FLEX_US_CSR_CTS_Msk & (_UINT32_(value) << FLEX_US_CSR_CTS_Pos)) /* Assigment of value for CTS in the FLEX_US_CSR register */
#define FLEX_US_CSR_MANE_Pos                  _UINT32_(24)                                         /* (FLEX_US_CSR) Manchester Error Position */
#define FLEX_US_CSR_MANE_Msk                  (_UINT32_(0x1) << FLEX_US_CSR_MANE_Pos)              /* (FLEX_US_CSR) Manchester Error Mask */
#define FLEX_US_CSR_MANE(value)               (FLEX_US_CSR_MANE_Msk & (_UINT32_(value) << FLEX_US_CSR_MANE_Pos)) /* Assigment of value for MANE in the FLEX_US_CSR register */
#define FLEX_US_CSR_Msk                       _UINT32_(0x01C83FFF)                                 /* (FLEX_US_CSR) Register Mask  */

/* LIN mode */
#define FLEX_US_CSR_LIN_Msk                   _UINT32_(0x00000000)                                  /* (FLEX_US_CSR_LIN) Register Mask  */


/* -------- FLEX_US_RHR : (FLEXCOM Offset: 0x218) ( R/ 32) USART Receive Holding Register -------- */
#define FLEX_US_RHR_RXCHR_Pos                 _UINT32_(0)                                          /* (FLEX_US_RHR) Received Character Position */
#define FLEX_US_RHR_RXCHR_Msk                 (_UINT32_(0x1FF) << FLEX_US_RHR_RXCHR_Pos)           /* (FLEX_US_RHR) Received Character Mask */
#define FLEX_US_RHR_RXCHR(value)              (FLEX_US_RHR_RXCHR_Msk & (_UINT32_(value) << FLEX_US_RHR_RXCHR_Pos)) /* Assigment of value for RXCHR in the FLEX_US_RHR register */
#define FLEX_US_RHR_RXSYNH_Pos                _UINT32_(15)                                         /* (FLEX_US_RHR) Received Sync Position */
#define FLEX_US_RHR_RXSYNH_Msk                (_UINT32_(0x1) << FLEX_US_RHR_RXSYNH_Pos)            /* (FLEX_US_RHR) Received Sync Mask */
#define FLEX_US_RHR_RXSYNH(value)             (FLEX_US_RHR_RXSYNH_Msk & (_UINT32_(value) << FLEX_US_RHR_RXSYNH_Pos)) /* Assigment of value for RXSYNH in the FLEX_US_RHR register */
#define FLEX_US_RHR_Msk                       _UINT32_(0x000081FF)                                 /* (FLEX_US_RHR) Register Mask  */

/* FIFO_MULTI_DATA mode */
#define FLEX_US_RHR_FIFO_MULTI_DATA_RXCHR0_Pos _UINT32_(0)                                          /* (FLEX_US_RHR) Received Characters Position */
#define FLEX_US_RHR_FIFO_MULTI_DATA_RXCHR0_Msk (_UINT32_(0xFF) << FLEX_US_RHR_FIFO_MULTI_DATA_RXCHR0_Pos) /* (FLEX_US_RHR) Received Characters Mask */
#define FLEX_US_RHR_FIFO_MULTI_DATA_RXCHR0(value) (FLEX_US_RHR_FIFO_MULTI_DATA_RXCHR0_Msk & (_UINT32_(value) << FLEX_US_RHR_FIFO_MULTI_DATA_RXCHR0_Pos))
#define FLEX_US_RHR_FIFO_MULTI_DATA_RXCHR1_Pos _UINT32_(8)                                          /* (FLEX_US_RHR) Received Characters Position */
#define FLEX_US_RHR_FIFO_MULTI_DATA_RXCHR1_Msk (_UINT32_(0xFF) << FLEX_US_RHR_FIFO_MULTI_DATA_RXCHR1_Pos) /* (FLEX_US_RHR) Received Characters Mask */
#define FLEX_US_RHR_FIFO_MULTI_DATA_RXCHR1(value) (FLEX_US_RHR_FIFO_MULTI_DATA_RXCHR1_Msk & (_UINT32_(value) << FLEX_US_RHR_FIFO_MULTI_DATA_RXCHR1_Pos))
#define FLEX_US_RHR_FIFO_MULTI_DATA_RXCHR2_Pos _UINT32_(16)                                         /* (FLEX_US_RHR) Received Characters Position */
#define FLEX_US_RHR_FIFO_MULTI_DATA_RXCHR2_Msk (_UINT32_(0xFF) << FLEX_US_RHR_FIFO_MULTI_DATA_RXCHR2_Pos) /* (FLEX_US_RHR) Received Characters Mask */
#define FLEX_US_RHR_FIFO_MULTI_DATA_RXCHR2(value) (FLEX_US_RHR_FIFO_MULTI_DATA_RXCHR2_Msk & (_UINT32_(value) << FLEX_US_RHR_FIFO_MULTI_DATA_RXCHR2_Pos))
#define FLEX_US_RHR_FIFO_MULTI_DATA_RXCHR3_Pos _UINT32_(24)                                         /* (FLEX_US_RHR) Received Characters Position */
#define FLEX_US_RHR_FIFO_MULTI_DATA_RXCHR3_Msk (_UINT32_(0xFF) << FLEX_US_RHR_FIFO_MULTI_DATA_RXCHR3_Pos) /* (FLEX_US_RHR) Received Characters Mask */
#define FLEX_US_RHR_FIFO_MULTI_DATA_RXCHR3(value) (FLEX_US_RHR_FIFO_MULTI_DATA_RXCHR3_Msk & (_UINT32_(value) << FLEX_US_RHR_FIFO_MULTI_DATA_RXCHR3_Pos))
#define FLEX_US_RHR_FIFO_MULTI_DATA_Msk       _UINT32_(0xFFFFFFFF)                                  /* (FLEX_US_RHR_FIFO_MULTI_DATA) Register Mask  */


/* -------- FLEX_US_THR : (FLEXCOM Offset: 0x21C) ( /W 32) USART Transmit Holding Register -------- */
#define FLEX_US_THR_TXCHR_Pos                 _UINT32_(0)                                          /* (FLEX_US_THR) Character to be Transmitted Position */
#define FLEX_US_THR_TXCHR_Msk                 (_UINT32_(0x1FF) << FLEX_US_THR_TXCHR_Pos)           /* (FLEX_US_THR) Character to be Transmitted Mask */
#define FLEX_US_THR_TXCHR(value)              (FLEX_US_THR_TXCHR_Msk & (_UINT32_(value) << FLEX_US_THR_TXCHR_Pos)) /* Assigment of value for TXCHR in the FLEX_US_THR register */
#define FLEX_US_THR_TXSYNH_Pos                _UINT32_(15)                                         /* (FLEX_US_THR) Sync Field to be Transmitted Position */
#define FLEX_US_THR_TXSYNH_Msk                (_UINT32_(0x1) << FLEX_US_THR_TXSYNH_Pos)            /* (FLEX_US_THR) Sync Field to be Transmitted Mask */
#define FLEX_US_THR_TXSYNH(value)             (FLEX_US_THR_TXSYNH_Msk & (_UINT32_(value) << FLEX_US_THR_TXSYNH_Pos)) /* Assigment of value for TXSYNH in the FLEX_US_THR register */
#define FLEX_US_THR_Msk                       _UINT32_(0x000081FF)                                 /* (FLEX_US_THR) Register Mask  */

/* FIFO_MULTI_DATA mode */
#define FLEX_US_THR_FIFO_MULTI_DATA_TXCHR0_Pos _UINT32_(0)                                          /* (FLEX_US_THR) Character to be Transmitted Position */
#define FLEX_US_THR_FIFO_MULTI_DATA_TXCHR0_Msk (_UINT32_(0xFF) << FLEX_US_THR_FIFO_MULTI_DATA_TXCHR0_Pos) /* (FLEX_US_THR) Character to be Transmitted Mask */
#define FLEX_US_THR_FIFO_MULTI_DATA_TXCHR0(value) (FLEX_US_THR_FIFO_MULTI_DATA_TXCHR0_Msk & (_UINT32_(value) << FLEX_US_THR_FIFO_MULTI_DATA_TXCHR0_Pos))
#define FLEX_US_THR_FIFO_MULTI_DATA_TXCHR1_Pos _UINT32_(8)                                          /* (FLEX_US_THR) Character to be Transmitted Position */
#define FLEX_US_THR_FIFO_MULTI_DATA_TXCHR1_Msk (_UINT32_(0xFF) << FLEX_US_THR_FIFO_MULTI_DATA_TXCHR1_Pos) /* (FLEX_US_THR) Character to be Transmitted Mask */
#define FLEX_US_THR_FIFO_MULTI_DATA_TXCHR1(value) (FLEX_US_THR_FIFO_MULTI_DATA_TXCHR1_Msk & (_UINT32_(value) << FLEX_US_THR_FIFO_MULTI_DATA_TXCHR1_Pos))
#define FLEX_US_THR_FIFO_MULTI_DATA_TXCHR2_Pos _UINT32_(16)                                         /* (FLEX_US_THR) Character to be Transmitted Position */
#define FLEX_US_THR_FIFO_MULTI_DATA_TXCHR2_Msk (_UINT32_(0xFF) << FLEX_US_THR_FIFO_MULTI_DATA_TXCHR2_Pos) /* (FLEX_US_THR) Character to be Transmitted Mask */
#define FLEX_US_THR_FIFO_MULTI_DATA_TXCHR2(value) (FLEX_US_THR_FIFO_MULTI_DATA_TXCHR2_Msk & (_UINT32_(value) << FLEX_US_THR_FIFO_MULTI_DATA_TXCHR2_Pos))
#define FLEX_US_THR_FIFO_MULTI_DATA_TXCHR3_Pos _UINT32_(24)                                         /* (FLEX_US_THR) Character to be Transmitted Position */
#define FLEX_US_THR_FIFO_MULTI_DATA_TXCHR3_Msk (_UINT32_(0xFF) << FLEX_US_THR_FIFO_MULTI_DATA_TXCHR3_Pos) /* (FLEX_US_THR) Character to be Transmitted Mask */
#define FLEX_US_THR_FIFO_MULTI_DATA_TXCHR3(value) (FLEX_US_THR_FIFO_MULTI_DATA_TXCHR3_Msk & (_UINT32_(value) << FLEX_US_THR_FIFO_MULTI_DATA_TXCHR3_Pos))
#define FLEX_US_THR_FIFO_MULTI_DATA_Msk       _UINT32_(0xFFFFFFFF)                                  /* (FLEX_US_THR_FIFO_MULTI_DATA) Register Mask  */


/* -------- FLEX_US_BRGR : (FLEXCOM Offset: 0x220) (R/W 32) USART Baud Rate Generator Register -------- */
#define FLEX_US_BRGR_CD_Pos                   _UINT32_(0)                                          /* (FLEX_US_BRGR) Clock Divider Position */
#define FLEX_US_BRGR_CD_Msk                   (_UINT32_(0xFFFF) << FLEX_US_BRGR_CD_Pos)            /* (FLEX_US_BRGR) Clock Divider Mask */
#define FLEX_US_BRGR_CD(value)                (FLEX_US_BRGR_CD_Msk & (_UINT32_(value) << FLEX_US_BRGR_CD_Pos)) /* Assigment of value for CD in the FLEX_US_BRGR register */
#define FLEX_US_BRGR_FP_Pos                   _UINT32_(16)                                         /* (FLEX_US_BRGR) Fractional Part Position */
#define FLEX_US_BRGR_FP_Msk                   (_UINT32_(0x7) << FLEX_US_BRGR_FP_Pos)               /* (FLEX_US_BRGR) Fractional Part Mask */
#define FLEX_US_BRGR_FP(value)                (FLEX_US_BRGR_FP_Msk & (_UINT32_(value) << FLEX_US_BRGR_FP_Pos)) /* Assigment of value for FP in the FLEX_US_BRGR register */
#define FLEX_US_BRGR_Msk                      _UINT32_(0x0007FFFF)                                 /* (FLEX_US_BRGR) Register Mask  */


/* -------- FLEX_US_RTOR : (FLEXCOM Offset: 0x224) (R/W 32) USART Receiver Timeout Register -------- */
#define FLEX_US_RTOR_TO_Pos                   _UINT32_(0)                                          /* (FLEX_US_RTOR) Timeout Value Position */
#define FLEX_US_RTOR_TO_Msk                   (_UINT32_(0x1FFFF) << FLEX_US_RTOR_TO_Pos)           /* (FLEX_US_RTOR) Timeout Value Mask */
#define FLEX_US_RTOR_TO(value)                (FLEX_US_RTOR_TO_Msk & (_UINT32_(value) << FLEX_US_RTOR_TO_Pos)) /* Assigment of value for TO in the FLEX_US_RTOR register */
#define FLEX_US_RTOR_Msk                      _UINT32_(0x0001FFFF)                                 /* (FLEX_US_RTOR) Register Mask  */


/* -------- FLEX_US_TTGR : (FLEXCOM Offset: 0x228) (R/W 32) USART Transmitter Timeguard Register -------- */
#define FLEX_US_TTGR_TG_Pos                   _UINT32_(0)                                          /* (FLEX_US_TTGR) Timeguard Value Position */
#define FLEX_US_TTGR_TG_Msk                   (_UINT32_(0xFF) << FLEX_US_TTGR_TG_Pos)              /* (FLEX_US_TTGR) Timeguard Value Mask */
#define FLEX_US_TTGR_TG(value)                (FLEX_US_TTGR_TG_Msk & (_UINT32_(value) << FLEX_US_TTGR_TG_Pos)) /* Assigment of value for TG in the FLEX_US_TTGR register */
#define FLEX_US_TTGR_Msk                      _UINT32_(0x000000FF)                                 /* (FLEX_US_TTGR) Register Mask  */


/* -------- FLEX_US_FIDI : (FLEXCOM Offset: 0x240) (R/W 32) USART FI DI Ratio Register -------- */
#define FLEX_US_FIDI_FI_DI_RATIO_Pos          _UINT32_(0)                                          /* (FLEX_US_FIDI) FI Over DI Ratio Value Position */
#define FLEX_US_FIDI_FI_DI_RATIO_Msk          (_UINT32_(0xFFFF) << FLEX_US_FIDI_FI_DI_RATIO_Pos)   /* (FLEX_US_FIDI) FI Over DI Ratio Value Mask */
#define FLEX_US_FIDI_FI_DI_RATIO(value)       (FLEX_US_FIDI_FI_DI_RATIO_Msk & (_UINT32_(value) << FLEX_US_FIDI_FI_DI_RATIO_Pos)) /* Assigment of value for FI_DI_RATIO in the FLEX_US_FIDI register */
#define FLEX_US_FIDI_Msk                      _UINT32_(0x0000FFFF)                                 /* (FLEX_US_FIDI) Register Mask  */


/* -------- FLEX_US_NER : (FLEXCOM Offset: 0x244) ( R/ 32) USART Number of Errors Register -------- */
#define FLEX_US_NER_NB_ERRORS_Pos             _UINT32_(0)                                          /* (FLEX_US_NER) Number of Errors Position */
#define FLEX_US_NER_NB_ERRORS_Msk             (_UINT32_(0xFF) << FLEX_US_NER_NB_ERRORS_Pos)        /* (FLEX_US_NER) Number of Errors Mask */
#define FLEX_US_NER_NB_ERRORS(value)          (FLEX_US_NER_NB_ERRORS_Msk & (_UINT32_(value) << FLEX_US_NER_NB_ERRORS_Pos)) /* Assigment of value for NB_ERRORS in the FLEX_US_NER register */
#define FLEX_US_NER_Msk                       _UINT32_(0x000000FF)                                 /* (FLEX_US_NER) Register Mask  */


/* -------- FLEX_US_IF : (FLEXCOM Offset: 0x24C) (R/W 32) USART IrDA Filter Register -------- */
#define FLEX_US_IF_IRDA_FILTER_Pos            _UINT32_(0)                                          /* (FLEX_US_IF) IrDA Filter Position */
#define FLEX_US_IF_IRDA_FILTER_Msk            (_UINT32_(0xFF) << FLEX_US_IF_IRDA_FILTER_Pos)       /* (FLEX_US_IF) IrDA Filter Mask */
#define FLEX_US_IF_IRDA_FILTER(value)         (FLEX_US_IF_IRDA_FILTER_Msk & (_UINT32_(value) << FLEX_US_IF_IRDA_FILTER_Pos)) /* Assigment of value for IRDA_FILTER in the FLEX_US_IF register */
#define FLEX_US_IF_Msk                        _UINT32_(0x000000FF)                                 /* (FLEX_US_IF) Register Mask  */


/* -------- FLEX_US_MAN : (FLEXCOM Offset: 0x250) (R/W 32) USART Manchester Configuration Register -------- */
#define FLEX_US_MAN_TX_PL_Pos                 _UINT32_(0)                                          /* (FLEX_US_MAN) Transmitter Preamble Length Position */
#define FLEX_US_MAN_TX_PL_Msk                 (_UINT32_(0xF) << FLEX_US_MAN_TX_PL_Pos)             /* (FLEX_US_MAN) Transmitter Preamble Length Mask */
#define FLEX_US_MAN_TX_PL(value)              (FLEX_US_MAN_TX_PL_Msk & (_UINT32_(value) << FLEX_US_MAN_TX_PL_Pos)) /* Assigment of value for TX_PL in the FLEX_US_MAN register */
#define FLEX_US_MAN_TX_PP_Pos                 _UINT32_(8)                                          /* (FLEX_US_MAN) Transmitter Preamble Pattern Position */
#define FLEX_US_MAN_TX_PP_Msk                 (_UINT32_(0x3) << FLEX_US_MAN_TX_PP_Pos)             /* (FLEX_US_MAN) Transmitter Preamble Pattern Mask */
#define FLEX_US_MAN_TX_PP(value)              (FLEX_US_MAN_TX_PP_Msk & (_UINT32_(value) << FLEX_US_MAN_TX_PP_Pos)) /* Assigment of value for TX_PP in the FLEX_US_MAN register */
#define   FLEX_US_MAN_TX_PP_ALL_ONE_Val       _UINT32_(0x0)                                        /* (FLEX_US_MAN) The preamble is composed of '1's  */
#define   FLEX_US_MAN_TX_PP_ALL_ZERO_Val      _UINT32_(0x1)                                        /* (FLEX_US_MAN) The preamble is composed of '0's  */
#define   FLEX_US_MAN_TX_PP_ZERO_ONE_Val      _UINT32_(0x2)                                        /* (FLEX_US_MAN) The preamble is composed of '01's  */
#define   FLEX_US_MAN_TX_PP_ONE_ZERO_Val      _UINT32_(0x3)                                        /* (FLEX_US_MAN) The preamble is composed of '10's  */
#define FLEX_US_MAN_TX_PP_ALL_ONE             (FLEX_US_MAN_TX_PP_ALL_ONE_Val << FLEX_US_MAN_TX_PP_Pos) /* (FLEX_US_MAN) The preamble is composed of '1's Position  */
#define FLEX_US_MAN_TX_PP_ALL_ZERO            (FLEX_US_MAN_TX_PP_ALL_ZERO_Val << FLEX_US_MAN_TX_PP_Pos) /* (FLEX_US_MAN) The preamble is composed of '0's Position  */
#define FLEX_US_MAN_TX_PP_ZERO_ONE            (FLEX_US_MAN_TX_PP_ZERO_ONE_Val << FLEX_US_MAN_TX_PP_Pos) /* (FLEX_US_MAN) The preamble is composed of '01's Position  */
#define FLEX_US_MAN_TX_PP_ONE_ZERO            (FLEX_US_MAN_TX_PP_ONE_ZERO_Val << FLEX_US_MAN_TX_PP_Pos) /* (FLEX_US_MAN) The preamble is composed of '10's Position  */
#define FLEX_US_MAN_TX_MPOL_Pos               _UINT32_(12)                                         /* (FLEX_US_MAN) Transmitter Manchester Polarity Position */
#define FLEX_US_MAN_TX_MPOL_Msk               (_UINT32_(0x1) << FLEX_US_MAN_TX_MPOL_Pos)           /* (FLEX_US_MAN) Transmitter Manchester Polarity Mask */
#define FLEX_US_MAN_TX_MPOL(value)            (FLEX_US_MAN_TX_MPOL_Msk & (_UINT32_(value) << FLEX_US_MAN_TX_MPOL_Pos)) /* Assigment of value for TX_MPOL in the FLEX_US_MAN register */
#define FLEX_US_MAN_RX_PL_Pos                 _UINT32_(16)                                         /* (FLEX_US_MAN) Receiver Preamble Length Position */
#define FLEX_US_MAN_RX_PL_Msk                 (_UINT32_(0xF) << FLEX_US_MAN_RX_PL_Pos)             /* (FLEX_US_MAN) Receiver Preamble Length Mask */
#define FLEX_US_MAN_RX_PL(value)              (FLEX_US_MAN_RX_PL_Msk & (_UINT32_(value) << FLEX_US_MAN_RX_PL_Pos)) /* Assigment of value for RX_PL in the FLEX_US_MAN register */
#define FLEX_US_MAN_RX_PP_Pos                 _UINT32_(24)                                         /* (FLEX_US_MAN) Receiver Preamble Pattern detected Position */
#define FLEX_US_MAN_RX_PP_Msk                 (_UINT32_(0x3) << FLEX_US_MAN_RX_PP_Pos)             /* (FLEX_US_MAN) Receiver Preamble Pattern detected Mask */
#define FLEX_US_MAN_RX_PP(value)              (FLEX_US_MAN_RX_PP_Msk & (_UINT32_(value) << FLEX_US_MAN_RX_PP_Pos)) /* Assigment of value for RX_PP in the FLEX_US_MAN register */
#define   FLEX_US_MAN_RX_PP_ALL_ONE_Val       _UINT32_(0x0)                                        /* (FLEX_US_MAN) The preamble is composed of '1's  */
#define   FLEX_US_MAN_RX_PP_ALL_ZERO_Val      _UINT32_(0x1)                                        /* (FLEX_US_MAN) The preamble is composed of '0's  */
#define   FLEX_US_MAN_RX_PP_ZERO_ONE_Val      _UINT32_(0x2)                                        /* (FLEX_US_MAN) The preamble is composed of '01's  */
#define   FLEX_US_MAN_RX_PP_ONE_ZERO_Val      _UINT32_(0x3)                                        /* (FLEX_US_MAN) The preamble is composed of '10's  */
#define FLEX_US_MAN_RX_PP_ALL_ONE             (FLEX_US_MAN_RX_PP_ALL_ONE_Val << FLEX_US_MAN_RX_PP_Pos) /* (FLEX_US_MAN) The preamble is composed of '1's Position  */
#define FLEX_US_MAN_RX_PP_ALL_ZERO            (FLEX_US_MAN_RX_PP_ALL_ZERO_Val << FLEX_US_MAN_RX_PP_Pos) /* (FLEX_US_MAN) The preamble is composed of '0's Position  */
#define FLEX_US_MAN_RX_PP_ZERO_ONE            (FLEX_US_MAN_RX_PP_ZERO_ONE_Val << FLEX_US_MAN_RX_PP_Pos) /* (FLEX_US_MAN) The preamble is composed of '01's Position  */
#define FLEX_US_MAN_RX_PP_ONE_ZERO            (FLEX_US_MAN_RX_PP_ONE_ZERO_Val << FLEX_US_MAN_RX_PP_Pos) /* (FLEX_US_MAN) The preamble is composed of '10's Position  */
#define FLEX_US_MAN_RX_MPOL_Pos               _UINT32_(28)                                         /* (FLEX_US_MAN) Receiver Manchester Polarity Position */
#define FLEX_US_MAN_RX_MPOL_Msk               (_UINT32_(0x1) << FLEX_US_MAN_RX_MPOL_Pos)           /* (FLEX_US_MAN) Receiver Manchester Polarity Mask */
#define FLEX_US_MAN_RX_MPOL(value)            (FLEX_US_MAN_RX_MPOL_Msk & (_UINT32_(value) << FLEX_US_MAN_RX_MPOL_Pos)) /* Assigment of value for RX_MPOL in the FLEX_US_MAN register */
#define FLEX_US_MAN_ONE_Pos                   _UINT32_(29)                                         /* (FLEX_US_MAN) Must Be Set to 1 Position */
#define FLEX_US_MAN_ONE_Msk                   (_UINT32_(0x1) << FLEX_US_MAN_ONE_Pos)               /* (FLEX_US_MAN) Must Be Set to 1 Mask */
#define FLEX_US_MAN_ONE(value)                (FLEX_US_MAN_ONE_Msk & (_UINT32_(value) << FLEX_US_MAN_ONE_Pos)) /* Assigment of value for ONE in the FLEX_US_MAN register */
#define FLEX_US_MAN_DRIFT_Pos                 _UINT32_(30)                                         /* (FLEX_US_MAN) Drift Compensation Position */
#define FLEX_US_MAN_DRIFT_Msk                 (_UINT32_(0x1) << FLEX_US_MAN_DRIFT_Pos)             /* (FLEX_US_MAN) Drift Compensation Mask */
#define FLEX_US_MAN_DRIFT(value)              (FLEX_US_MAN_DRIFT_Msk & (_UINT32_(value) << FLEX_US_MAN_DRIFT_Pos)) /* Assigment of value for DRIFT in the FLEX_US_MAN register */
#define FLEX_US_MAN_RXIDLEV_Pos               _UINT32_(31)                                         /* (FLEX_US_MAN) Receiver Idle Value Position */
#define FLEX_US_MAN_RXIDLEV_Msk               (_UINT32_(0x1) << FLEX_US_MAN_RXIDLEV_Pos)           /* (FLEX_US_MAN) Receiver Idle Value Mask */
#define FLEX_US_MAN_RXIDLEV(value)            (FLEX_US_MAN_RXIDLEV_Msk & (_UINT32_(value) << FLEX_US_MAN_RXIDLEV_Pos)) /* Assigment of value for RXIDLEV in the FLEX_US_MAN register */
#define FLEX_US_MAN_Msk                       _UINT32_(0xF30F130F)                                 /* (FLEX_US_MAN) Register Mask  */


/* -------- FLEX_US_LINMR : (FLEXCOM Offset: 0x254) (R/W 32) USART LIN Mode Register -------- */
#define FLEX_US_LINMR_NACT_Pos                _UINT32_(0)                                          /* (FLEX_US_LINMR) LIN Node Action Position */
#define FLEX_US_LINMR_NACT_Msk                (_UINT32_(0x3) << FLEX_US_LINMR_NACT_Pos)            /* (FLEX_US_LINMR) LIN Node Action Mask */
#define FLEX_US_LINMR_NACT(value)             (FLEX_US_LINMR_NACT_Msk & (_UINT32_(value) << FLEX_US_LINMR_NACT_Pos)) /* Assigment of value for NACT in the FLEX_US_LINMR register */
#define   FLEX_US_LINMR_NACT_PUBLISH_Val      _UINT32_(0x0)                                        /* (FLEX_US_LINMR) The USART transmits the response.  */
#define   FLEX_US_LINMR_NACT_SUBSCRIBE_Val    _UINT32_(0x1)                                        /* (FLEX_US_LINMR) The USART receives the response.  */
#define   FLEX_US_LINMR_NACT_IGNORE_Val       _UINT32_(0x2)                                        /* (FLEX_US_LINMR) The USART does not transmit and does not receive the response.  */
#define FLEX_US_LINMR_NACT_PUBLISH            (FLEX_US_LINMR_NACT_PUBLISH_Val << FLEX_US_LINMR_NACT_Pos) /* (FLEX_US_LINMR) The USART transmits the response. Position  */
#define FLEX_US_LINMR_NACT_SUBSCRIBE          (FLEX_US_LINMR_NACT_SUBSCRIBE_Val << FLEX_US_LINMR_NACT_Pos) /* (FLEX_US_LINMR) The USART receives the response. Position  */
#define FLEX_US_LINMR_NACT_IGNORE             (FLEX_US_LINMR_NACT_IGNORE_Val << FLEX_US_LINMR_NACT_Pos) /* (FLEX_US_LINMR) The USART does not transmit and does not receive the response. Position  */
#define FLEX_US_LINMR_PARDIS_Pos              _UINT32_(2)                                          /* (FLEX_US_LINMR) Parity Disable Position */
#define FLEX_US_LINMR_PARDIS_Msk              (_UINT32_(0x1) << FLEX_US_LINMR_PARDIS_Pos)          /* (FLEX_US_LINMR) Parity Disable Mask */
#define FLEX_US_LINMR_PARDIS(value)           (FLEX_US_LINMR_PARDIS_Msk & (_UINT32_(value) << FLEX_US_LINMR_PARDIS_Pos)) /* Assigment of value for PARDIS in the FLEX_US_LINMR register */
#define FLEX_US_LINMR_CHKDIS_Pos              _UINT32_(3)                                          /* (FLEX_US_LINMR) Checksum Disable Position */
#define FLEX_US_LINMR_CHKDIS_Msk              (_UINT32_(0x1) << FLEX_US_LINMR_CHKDIS_Pos)          /* (FLEX_US_LINMR) Checksum Disable Mask */
#define FLEX_US_LINMR_CHKDIS(value)           (FLEX_US_LINMR_CHKDIS_Msk & (_UINT32_(value) << FLEX_US_LINMR_CHKDIS_Pos)) /* Assigment of value for CHKDIS in the FLEX_US_LINMR register */
#define FLEX_US_LINMR_CHKTYP_Pos              _UINT32_(4)                                          /* (FLEX_US_LINMR) Checksum Type Position */
#define FLEX_US_LINMR_CHKTYP_Msk              (_UINT32_(0x1) << FLEX_US_LINMR_CHKTYP_Pos)          /* (FLEX_US_LINMR) Checksum Type Mask */
#define FLEX_US_LINMR_CHKTYP(value)           (FLEX_US_LINMR_CHKTYP_Msk & (_UINT32_(value) << FLEX_US_LINMR_CHKTYP_Pos)) /* Assigment of value for CHKTYP in the FLEX_US_LINMR register */
#define FLEX_US_LINMR_DLM_Pos                 _UINT32_(5)                                          /* (FLEX_US_LINMR) Data Length Mode Position */
#define FLEX_US_LINMR_DLM_Msk                 (_UINT32_(0x1) << FLEX_US_LINMR_DLM_Pos)             /* (FLEX_US_LINMR) Data Length Mode Mask */
#define FLEX_US_LINMR_DLM(value)              (FLEX_US_LINMR_DLM_Msk & (_UINT32_(value) << FLEX_US_LINMR_DLM_Pos)) /* Assigment of value for DLM in the FLEX_US_LINMR register */
#define FLEX_US_LINMR_FSDIS_Pos               _UINT32_(6)                                          /* (FLEX_US_LINMR) Frame Slot Mode Disable Position */
#define FLEX_US_LINMR_FSDIS_Msk               (_UINT32_(0x1) << FLEX_US_LINMR_FSDIS_Pos)           /* (FLEX_US_LINMR) Frame Slot Mode Disable Mask */
#define FLEX_US_LINMR_FSDIS(value)            (FLEX_US_LINMR_FSDIS_Msk & (_UINT32_(value) << FLEX_US_LINMR_FSDIS_Pos)) /* Assigment of value for FSDIS in the FLEX_US_LINMR register */
#define FLEX_US_LINMR_WKUPTYP_Pos             _UINT32_(7)                                          /* (FLEX_US_LINMR) Wakeup Signal Type Position */
#define FLEX_US_LINMR_WKUPTYP_Msk             (_UINT32_(0x1) << FLEX_US_LINMR_WKUPTYP_Pos)         /* (FLEX_US_LINMR) Wakeup Signal Type Mask */
#define FLEX_US_LINMR_WKUPTYP(value)          (FLEX_US_LINMR_WKUPTYP_Msk & (_UINT32_(value) << FLEX_US_LINMR_WKUPTYP_Pos)) /* Assigment of value for WKUPTYP in the FLEX_US_LINMR register */
#define FLEX_US_LINMR_DLC_Pos                 _UINT32_(8)                                          /* (FLEX_US_LINMR) Data Length Control Position */
#define FLEX_US_LINMR_DLC_Msk                 (_UINT32_(0xFF) << FLEX_US_LINMR_DLC_Pos)            /* (FLEX_US_LINMR) Data Length Control Mask */
#define FLEX_US_LINMR_DLC(value)              (FLEX_US_LINMR_DLC_Msk & (_UINT32_(value) << FLEX_US_LINMR_DLC_Pos)) /* Assigment of value for DLC in the FLEX_US_LINMR register */
#define FLEX_US_LINMR_PDCM_Pos                _UINT32_(16)                                         /* (FLEX_US_LINMR) PDC Mode Position */
#define FLEX_US_LINMR_PDCM_Msk                (_UINT32_(0x1) << FLEX_US_LINMR_PDCM_Pos)            /* (FLEX_US_LINMR) PDC Mode Mask */
#define FLEX_US_LINMR_PDCM(value)             (FLEX_US_LINMR_PDCM_Msk & (_UINT32_(value) << FLEX_US_LINMR_PDCM_Pos)) /* Assigment of value for PDCM in the FLEX_US_LINMR register */
#define FLEX_US_LINMR_SYNCDIS_Pos             _UINT32_(17)                                         /* (FLEX_US_LINMR) Synchronization Disable Position */
#define FLEX_US_LINMR_SYNCDIS_Msk             (_UINT32_(0x1) << FLEX_US_LINMR_SYNCDIS_Pos)         /* (FLEX_US_LINMR) Synchronization Disable Mask */
#define FLEX_US_LINMR_SYNCDIS(value)          (FLEX_US_LINMR_SYNCDIS_Msk & (_UINT32_(value) << FLEX_US_LINMR_SYNCDIS_Pos)) /* Assigment of value for SYNCDIS in the FLEX_US_LINMR register */
#define FLEX_US_LINMR_Msk                     _UINT32_(0x0003FFFF)                                 /* (FLEX_US_LINMR) Register Mask  */


/* -------- FLEX_US_LINIR : (FLEXCOM Offset: 0x258) (R/W 32) USART LIN Identifier Register -------- */
#define FLEX_US_LINIR_IDCHR_Pos               _UINT32_(0)                                          /* (FLEX_US_LINIR) Identifier Character Position */
#define FLEX_US_LINIR_IDCHR_Msk               (_UINT32_(0xFF) << FLEX_US_LINIR_IDCHR_Pos)          /* (FLEX_US_LINIR) Identifier Character Mask */
#define FLEX_US_LINIR_IDCHR(value)            (FLEX_US_LINIR_IDCHR_Msk & (_UINT32_(value) << FLEX_US_LINIR_IDCHR_Pos)) /* Assigment of value for IDCHR in the FLEX_US_LINIR register */
#define FLEX_US_LINIR_Msk                     _UINT32_(0x000000FF)                                 /* (FLEX_US_LINIR) Register Mask  */


/* -------- FLEX_US_LINBRR : (FLEXCOM Offset: 0x25C) ( R/ 32) USART LIN Baud Rate Register -------- */
#define FLEX_US_LINBRR_LINCD_Pos              _UINT32_(0)                                          /* (FLEX_US_LINBRR) Clock Divider after Synchronization Position */
#define FLEX_US_LINBRR_LINCD_Msk              (_UINT32_(0xFFFF) << FLEX_US_LINBRR_LINCD_Pos)       /* (FLEX_US_LINBRR) Clock Divider after Synchronization Mask */
#define FLEX_US_LINBRR_LINCD(value)           (FLEX_US_LINBRR_LINCD_Msk & (_UINT32_(value) << FLEX_US_LINBRR_LINCD_Pos)) /* Assigment of value for LINCD in the FLEX_US_LINBRR register */
#define FLEX_US_LINBRR_LINFP_Pos              _UINT32_(16)                                         /* (FLEX_US_LINBRR) Fractional Part after Synchronization Position */
#define FLEX_US_LINBRR_LINFP_Msk              (_UINT32_(0x7) << FLEX_US_LINBRR_LINFP_Pos)          /* (FLEX_US_LINBRR) Fractional Part after Synchronization Mask */
#define FLEX_US_LINBRR_LINFP(value)           (FLEX_US_LINBRR_LINFP_Msk & (_UINT32_(value) << FLEX_US_LINBRR_LINFP_Pos)) /* Assigment of value for LINFP in the FLEX_US_LINBRR register */
#define FLEX_US_LINBRR_Msk                    _UINT32_(0x0007FFFF)                                 /* (FLEX_US_LINBRR) Register Mask  */


/* -------- FLEX_US_CMPR : (FLEXCOM Offset: 0x290) (R/W 32) USART Comparison Register -------- */
#define FLEX_US_CMPR_VAL1_Pos                 _UINT32_(0)                                          /* (FLEX_US_CMPR) First Comparison Value for Received Character Position */
#define FLEX_US_CMPR_VAL1_Msk                 (_UINT32_(0x1FF) << FLEX_US_CMPR_VAL1_Pos)           /* (FLEX_US_CMPR) First Comparison Value for Received Character Mask */
#define FLEX_US_CMPR_VAL1(value)              (FLEX_US_CMPR_VAL1_Msk & (_UINT32_(value) << FLEX_US_CMPR_VAL1_Pos)) /* Assigment of value for VAL1 in the FLEX_US_CMPR register */
#define FLEX_US_CMPR_CMPMODE_Pos              _UINT32_(12)                                         /* (FLEX_US_CMPR) Comparison Mode Position */
#define FLEX_US_CMPR_CMPMODE_Msk              (_UINT32_(0x3) << FLEX_US_CMPR_CMPMODE_Pos)          /* (FLEX_US_CMPR) Comparison Mode Mask */
#define FLEX_US_CMPR_CMPMODE(value)           (FLEX_US_CMPR_CMPMODE_Msk & (_UINT32_(value) << FLEX_US_CMPR_CMPMODE_Pos)) /* Assigment of value for CMPMODE in the FLEX_US_CMPR register */
#define   FLEX_US_CMPR_CMPMODE_FLAG_ONLY_Val  _UINT32_(0x0)                                        /* (FLEX_US_CMPR) Any character is received and comparison function drives CMP flag.  */
#define   FLEX_US_CMPR_CMPMODE_START_CONDITION_Val _UINT32_(0x1)                                        /* (FLEX_US_CMPR) Comparison condition must be met to start reception.  */
#define   FLEX_US_CMPR_CMPMODE_FILTER_Val     _UINT32_(0x2)                                        /* (FLEX_US_CMPR) Comparison must be met to receive the current data only  */
#define FLEX_US_CMPR_CMPMODE_FLAG_ONLY        (FLEX_US_CMPR_CMPMODE_FLAG_ONLY_Val << FLEX_US_CMPR_CMPMODE_Pos) /* (FLEX_US_CMPR) Any character is received and comparison function drives CMP flag. Position  */
#define FLEX_US_CMPR_CMPMODE_START_CONDITION  (FLEX_US_CMPR_CMPMODE_START_CONDITION_Val << FLEX_US_CMPR_CMPMODE_Pos) /* (FLEX_US_CMPR) Comparison condition must be met to start reception. Position  */
#define FLEX_US_CMPR_CMPMODE_FILTER           (FLEX_US_CMPR_CMPMODE_FILTER_Val << FLEX_US_CMPR_CMPMODE_Pos) /* (FLEX_US_CMPR) Comparison must be met to receive the current data only Position  */
#define FLEX_US_CMPR_CMPPAR_Pos               _UINT32_(14)                                         /* (FLEX_US_CMPR) Compare Parity Position */
#define FLEX_US_CMPR_CMPPAR_Msk               (_UINT32_(0x1) << FLEX_US_CMPR_CMPPAR_Pos)           /* (FLEX_US_CMPR) Compare Parity Mask */
#define FLEX_US_CMPR_CMPPAR(value)            (FLEX_US_CMPR_CMPPAR_Msk & (_UINT32_(value) << FLEX_US_CMPR_CMPPAR_Pos)) /* Assigment of value for CMPPAR in the FLEX_US_CMPR register */
#define FLEX_US_CMPR_VAL2_Pos                 _UINT32_(16)                                         /* (FLEX_US_CMPR) Second Comparison Value for Received Character Position */
#define FLEX_US_CMPR_VAL2_Msk                 (_UINT32_(0x1FF) << FLEX_US_CMPR_VAL2_Pos)           /* (FLEX_US_CMPR) Second Comparison Value for Received Character Mask */
#define FLEX_US_CMPR_VAL2(value)              (FLEX_US_CMPR_VAL2_Msk & (_UINT32_(value) << FLEX_US_CMPR_VAL2_Pos)) /* Assigment of value for VAL2 in the FLEX_US_CMPR register */
#define FLEX_US_CMPR_Msk                      _UINT32_(0x01FF71FF)                                 /* (FLEX_US_CMPR) Register Mask  */


/* -------- FLEX_US_FMR : (FLEXCOM Offset: 0x2A0) (R/W 32) USART FIFO Mode Register -------- */
#define FLEX_US_FMR_TXRDYM_Pos                _UINT32_(0)                                          /* (FLEX_US_FMR) Transmitter Ready Mode Position */
#define FLEX_US_FMR_TXRDYM_Msk                (_UINT32_(0x3) << FLEX_US_FMR_TXRDYM_Pos)            /* (FLEX_US_FMR) Transmitter Ready Mode Mask */
#define FLEX_US_FMR_TXRDYM(value)             (FLEX_US_FMR_TXRDYM_Msk & (_UINT32_(value) << FLEX_US_FMR_TXRDYM_Pos)) /* Assigment of value for TXRDYM in the FLEX_US_FMR register */
#define   FLEX_US_FMR_TXRDYM_ONE_DATA_Val     _UINT32_(0x0)                                        /* (FLEX_US_FMR) TXRDY will be at level '1' when at least one data can be written in the transmit FIFO. When DMA is enabled to transfer data and FLEX_US_MR.MODE9=0 (up to 8 bits to transfer on the line), the chunk of 1 byte must be configured in the DMA. If the transfer is performed by software, the access type must be defined as a byte.  */
#define   FLEX_US_FMR_TXRDYM_TWO_DATA_Val     _UINT32_(0x1)                                        /* (FLEX_US_FMR) TXRDY will be at level '1' when at least two data can be written in the transmit FIFO. To minimize system bus load, when DMA is enabled to transfer data and FLEX_US_MR.MODE9=0 (up to 8 bits to transfer on the line), the chunk of 1 halfword (1 halfword carries 2 bytes) must be configured in the DMA. If the transfer is performed by software, the access type can be defined as byte (1 byte per access, 2 accesses) or halfword (2 bytes per access, 1 single access).  */
#define   FLEX_US_FMR_TXRDYM_FOUR_DATA_Val    _UINT32_(0x2)                                        /* (FLEX_US_FMR) TXRDY will be at level '1' when at least four data can be written in the transmit FIFO. To minimize system bus load, when DMA is enabled to transfer data and FLEX_US_MR.MODE9=0 (up to 8 bits to transfer on the line), the chunk of 1 word (1 word carries 4 bytes) must be configured in the DMA (chunk size=1 and word access). If the transfer is performed by software, the access type can be defined as byte (1 byte per access, 4 accesses), halfword (2 bytes per access, 2 accesses) or word (4 bytes per access, 1 single access).  */
#define FLEX_US_FMR_TXRDYM_ONE_DATA           (FLEX_US_FMR_TXRDYM_ONE_DATA_Val << FLEX_US_FMR_TXRDYM_Pos) /* (FLEX_US_FMR) TXRDY will be at level '1' when at least one data can be written in the transmit FIFO. When DMA is enabled to transfer data and FLEX_US_MR.MODE9=0 (up to 8 bits to transfer on the line), the chunk of 1 byte must be configured in the DMA. If the transfer is performed by software, the access type must be defined as a byte. Position  */
#define FLEX_US_FMR_TXRDYM_TWO_DATA           (FLEX_US_FMR_TXRDYM_TWO_DATA_Val << FLEX_US_FMR_TXRDYM_Pos) /* (FLEX_US_FMR) TXRDY will be at level '1' when at least two data can be written in the transmit FIFO. To minimize system bus load, when DMA is enabled to transfer data and FLEX_US_MR.MODE9=0 (up to 8 bits to transfer on the line), the chunk of 1 halfword (1 halfword carries 2 bytes) must be configured in the DMA. If the transfer is performed by software, the access type can be defined as byte (1 byte per access, 2 accesses) or halfword (2 bytes per access, 1 single access). Position  */
#define FLEX_US_FMR_TXRDYM_FOUR_DATA          (FLEX_US_FMR_TXRDYM_FOUR_DATA_Val << FLEX_US_FMR_TXRDYM_Pos) /* (FLEX_US_FMR) TXRDY will be at level '1' when at least four data can be written in the transmit FIFO. To minimize system bus load, when DMA is enabled to transfer data and FLEX_US_MR.MODE9=0 (up to 8 bits to transfer on the line), the chunk of 1 word (1 word carries 4 bytes) must be configured in the DMA (chunk size=1 and word access). If the transfer is performed by software, the access type can be defined as byte (1 byte per access, 4 accesses), halfword (2 bytes per access, 2 accesses) or word (4 bytes per access, 1 single access). Position  */
#define FLEX_US_FMR_RXRDYM_Pos                _UINT32_(4)                                          /* (FLEX_US_FMR) Receiver Ready Mode Position */
#define FLEX_US_FMR_RXRDYM_Msk                (_UINT32_(0x3) << FLEX_US_FMR_RXRDYM_Pos)            /* (FLEX_US_FMR) Receiver Ready Mode Mask */
#define FLEX_US_FMR_RXRDYM(value)             (FLEX_US_FMR_RXRDYM_Msk & (_UINT32_(value) << FLEX_US_FMR_RXRDYM_Pos)) /* Assigment of value for RXRDYM in the FLEX_US_FMR register */
#define   FLEX_US_FMR_RXRDYM_ONE_DATA_Val     _UINT32_(0x0)                                        /* (FLEX_US_FMR) RXRDY will be at level '1' when at least one unread data is in the receive FIFO. When DMA is enabled to transfer data and FLEX_US_MR.MODE9=0 (up to 8 bits to transfer on the line), the chunk of 1 byte must be configured in the DMA. If the transfer is performed by software, the access type must be defined as a byte.  */
#define   FLEX_US_FMR_RXRDYM_TWO_DATA_Val     _UINT32_(0x1)                                        /* (FLEX_US_FMR) RXRDY will be at level '1' when at least two unread data are in the receive FIFO. To minimize system bus load, when DMA is enabled to transfer data and FLEX_US_MR.MODE9=0 (up to 8 bits to transfer on the line), the chunk of 1 halfword (1 halfword carries 2 bytes) must be configured in the DMA (chunk size=1 and halfword access). If the transfer is performed by software, the access type can be defined as byte (1 byte per access, 2 accesses) or halfword (2 bytes per access, 1 single access).  */
#define   FLEX_US_FMR_RXRDYM_FOUR_DATA_Val    _UINT32_(0x2)                                        /* (FLEX_US_FMR) RXRDY will be at level '1' when at least four unread data are in the receive FIFO. To minimize system bus load, when DMA is enabled to transfer data and FLEX_US_MR.MODE9=0 (up to 8 bits to transfer on the line), the chunk of 1 word (1 word carries 4 bytes) must be configured in the DMA. If the transfer is performed by software, the access type can be defined as byte (1 byte per access, 4 accesses), halfword (2 bytes per access, 2 accesses) or word (4 bytes per access, 1 single access).  */
#define FLEX_US_FMR_RXRDYM_ONE_DATA           (FLEX_US_FMR_RXRDYM_ONE_DATA_Val << FLEX_US_FMR_RXRDYM_Pos) /* (FLEX_US_FMR) RXRDY will be at level '1' when at least one unread data is in the receive FIFO. When DMA is enabled to transfer data and FLEX_US_MR.MODE9=0 (up to 8 bits to transfer on the line), the chunk of 1 byte must be configured in the DMA. If the transfer is performed by software, the access type must be defined as a byte. Position  */
#define FLEX_US_FMR_RXRDYM_TWO_DATA           (FLEX_US_FMR_RXRDYM_TWO_DATA_Val << FLEX_US_FMR_RXRDYM_Pos) /* (FLEX_US_FMR) RXRDY will be at level '1' when at least two unread data are in the receive FIFO. To minimize system bus load, when DMA is enabled to transfer data and FLEX_US_MR.MODE9=0 (up to 8 bits to transfer on the line), the chunk of 1 halfword (1 halfword carries 2 bytes) must be configured in the DMA (chunk size=1 and halfword access). If the transfer is performed by software, the access type can be defined as byte (1 byte per access, 2 accesses) or halfword (2 bytes per access, 1 single access). Position  */
#define FLEX_US_FMR_RXRDYM_FOUR_DATA          (FLEX_US_FMR_RXRDYM_FOUR_DATA_Val << FLEX_US_FMR_RXRDYM_Pos) /* (FLEX_US_FMR) RXRDY will be at level '1' when at least four unread data are in the receive FIFO. To minimize system bus load, when DMA is enabled to transfer data and FLEX_US_MR.MODE9=0 (up to 8 bits to transfer on the line), the chunk of 1 word (1 word carries 4 bytes) must be configured in the DMA. If the transfer is performed by software, the access type can be defined as byte (1 byte per access, 4 accesses), halfword (2 bytes per access, 2 accesses) or word (4 bytes per access, 1 single access). Position  */
#define FLEX_US_FMR_FRTSC_Pos                 _UINT32_(7)                                          /* (FLEX_US_FMR) FIFO RTS Pin Control enable (Hardware Handshaking mode only) Position */
#define FLEX_US_FMR_FRTSC_Msk                 (_UINT32_(0x1) << FLEX_US_FMR_FRTSC_Pos)             /* (FLEX_US_FMR) FIFO RTS Pin Control enable (Hardware Handshaking mode only) Mask */
#define FLEX_US_FMR_FRTSC(value)              (FLEX_US_FMR_FRTSC_Msk & (_UINT32_(value) << FLEX_US_FMR_FRTSC_Pos)) /* Assigment of value for FRTSC in the FLEX_US_FMR register */
#define FLEX_US_FMR_TXFTHRES_Pos              _UINT32_(8)                                          /* (FLEX_US_FMR) Transmit FIFO Threshold Position */
#define FLEX_US_FMR_TXFTHRES_Msk              (_UINT32_(0x3F) << FLEX_US_FMR_TXFTHRES_Pos)         /* (FLEX_US_FMR) Transmit FIFO Threshold Mask */
#define FLEX_US_FMR_TXFTHRES(value)           (FLEX_US_FMR_TXFTHRES_Msk & (_UINT32_(value) << FLEX_US_FMR_TXFTHRES_Pos)) /* Assigment of value for TXFTHRES in the FLEX_US_FMR register */
#define FLEX_US_FMR_RXFTHRES_Pos              _UINT32_(16)                                         /* (FLEX_US_FMR) Receive FIFO Threshold Position */
#define FLEX_US_FMR_RXFTHRES_Msk              (_UINT32_(0x3F) << FLEX_US_FMR_RXFTHRES_Pos)         /* (FLEX_US_FMR) Receive FIFO Threshold Mask */
#define FLEX_US_FMR_RXFTHRES(value)           (FLEX_US_FMR_RXFTHRES_Msk & (_UINT32_(value) << FLEX_US_FMR_RXFTHRES_Pos)) /* Assigment of value for RXFTHRES in the FLEX_US_FMR register */
#define FLEX_US_FMR_RXFTHRES2_Pos             _UINT32_(24)                                         /* (FLEX_US_FMR) Receive FIFO Threshold 2 Position */
#define FLEX_US_FMR_RXFTHRES2_Msk             (_UINT32_(0x3F) << FLEX_US_FMR_RXFTHRES2_Pos)        /* (FLEX_US_FMR) Receive FIFO Threshold 2 Mask */
#define FLEX_US_FMR_RXFTHRES2(value)          (FLEX_US_FMR_RXFTHRES2_Msk & (_UINT32_(value) << FLEX_US_FMR_RXFTHRES2_Pos)) /* Assigment of value for RXFTHRES2 in the FLEX_US_FMR register */
#define FLEX_US_FMR_Msk                       _UINT32_(0x3F3F3FB3)                                 /* (FLEX_US_FMR) Register Mask  */


/* -------- FLEX_US_FLR : (FLEXCOM Offset: 0x2A4) ( R/ 32) USART FIFO Level Register -------- */
#define FLEX_US_FLR_TXFL_Pos                  _UINT32_(0)                                          /* (FLEX_US_FLR) Transmit FIFO Level Position */
#define FLEX_US_FLR_TXFL_Msk                  (_UINT32_(0x3F) << FLEX_US_FLR_TXFL_Pos)             /* (FLEX_US_FLR) Transmit FIFO Level Mask */
#define FLEX_US_FLR_TXFL(value)               (FLEX_US_FLR_TXFL_Msk & (_UINT32_(value) << FLEX_US_FLR_TXFL_Pos)) /* Assigment of value for TXFL in the FLEX_US_FLR register */
#define FLEX_US_FLR_RXFL_Pos                  _UINT32_(16)                                         /* (FLEX_US_FLR) Receive FIFO Level Position */
#define FLEX_US_FLR_RXFL_Msk                  (_UINT32_(0x3F) << FLEX_US_FLR_RXFL_Pos)             /* (FLEX_US_FLR) Receive FIFO Level Mask */
#define FLEX_US_FLR_RXFL(value)               (FLEX_US_FLR_RXFL_Msk & (_UINT32_(value) << FLEX_US_FLR_RXFL_Pos)) /* Assigment of value for RXFL in the FLEX_US_FLR register */
#define FLEX_US_FLR_Msk                       _UINT32_(0x003F003F)                                 /* (FLEX_US_FLR) Register Mask  */


/* -------- FLEX_US_FIER : (FLEXCOM Offset: 0x2A8) ( /W 32) USART FIFO Interrupt Enable Register -------- */
#define FLEX_US_FIER_TXFEF_Pos                _UINT32_(0)                                          /* (FLEX_US_FIER) TXFEF Interrupt Enable Position */
#define FLEX_US_FIER_TXFEF_Msk                (_UINT32_(0x1) << FLEX_US_FIER_TXFEF_Pos)            /* (FLEX_US_FIER) TXFEF Interrupt Enable Mask */
#define FLEX_US_FIER_TXFEF(value)             (FLEX_US_FIER_TXFEF_Msk & (_UINT32_(value) << FLEX_US_FIER_TXFEF_Pos)) /* Assigment of value for TXFEF in the FLEX_US_FIER register */
#define FLEX_US_FIER_TXFFF_Pos                _UINT32_(1)                                          /* (FLEX_US_FIER) TXFFF Interrupt Enable Position */
#define FLEX_US_FIER_TXFFF_Msk                (_UINT32_(0x1) << FLEX_US_FIER_TXFFF_Pos)            /* (FLEX_US_FIER) TXFFF Interrupt Enable Mask */
#define FLEX_US_FIER_TXFFF(value)             (FLEX_US_FIER_TXFFF_Msk & (_UINT32_(value) << FLEX_US_FIER_TXFFF_Pos)) /* Assigment of value for TXFFF in the FLEX_US_FIER register */
#define FLEX_US_FIER_TXFTHF_Pos               _UINT32_(2)                                          /* (FLEX_US_FIER) TXFTHF Interrupt Enable Position */
#define FLEX_US_FIER_TXFTHF_Msk               (_UINT32_(0x1) << FLEX_US_FIER_TXFTHF_Pos)           /* (FLEX_US_FIER) TXFTHF Interrupt Enable Mask */
#define FLEX_US_FIER_TXFTHF(value)            (FLEX_US_FIER_TXFTHF_Msk & (_UINT32_(value) << FLEX_US_FIER_TXFTHF_Pos)) /* Assigment of value for TXFTHF in the FLEX_US_FIER register */
#define FLEX_US_FIER_RXFEF_Pos                _UINT32_(3)                                          /* (FLEX_US_FIER) RXFEF Interrupt Enable Position */
#define FLEX_US_FIER_RXFEF_Msk                (_UINT32_(0x1) << FLEX_US_FIER_RXFEF_Pos)            /* (FLEX_US_FIER) RXFEF Interrupt Enable Mask */
#define FLEX_US_FIER_RXFEF(value)             (FLEX_US_FIER_RXFEF_Msk & (_UINT32_(value) << FLEX_US_FIER_RXFEF_Pos)) /* Assigment of value for RXFEF in the FLEX_US_FIER register */
#define FLEX_US_FIER_RXFFF_Pos                _UINT32_(4)                                          /* (FLEX_US_FIER) RXFFF Interrupt Enable Position */
#define FLEX_US_FIER_RXFFF_Msk                (_UINT32_(0x1) << FLEX_US_FIER_RXFFF_Pos)            /* (FLEX_US_FIER) RXFFF Interrupt Enable Mask */
#define FLEX_US_FIER_RXFFF(value)             (FLEX_US_FIER_RXFFF_Msk & (_UINT32_(value) << FLEX_US_FIER_RXFFF_Pos)) /* Assigment of value for RXFFF in the FLEX_US_FIER register */
#define FLEX_US_FIER_RXFTHF_Pos               _UINT32_(5)                                          /* (FLEX_US_FIER) RXFTHF Interrupt Enable Position */
#define FLEX_US_FIER_RXFTHF_Msk               (_UINT32_(0x1) << FLEX_US_FIER_RXFTHF_Pos)           /* (FLEX_US_FIER) RXFTHF Interrupt Enable Mask */
#define FLEX_US_FIER_RXFTHF(value)            (FLEX_US_FIER_RXFTHF_Msk & (_UINT32_(value) << FLEX_US_FIER_RXFTHF_Pos)) /* Assigment of value for RXFTHF in the FLEX_US_FIER register */
#define FLEX_US_FIER_TXFPTEF_Pos              _UINT32_(6)                                          /* (FLEX_US_FIER) TXFPTEF Interrupt Enable Position */
#define FLEX_US_FIER_TXFPTEF_Msk              (_UINT32_(0x1) << FLEX_US_FIER_TXFPTEF_Pos)          /* (FLEX_US_FIER) TXFPTEF Interrupt Enable Mask */
#define FLEX_US_FIER_TXFPTEF(value)           (FLEX_US_FIER_TXFPTEF_Msk & (_UINT32_(value) << FLEX_US_FIER_TXFPTEF_Pos)) /* Assigment of value for TXFPTEF in the FLEX_US_FIER register */
#define FLEX_US_FIER_RXFPTEF_Pos              _UINT32_(7)                                          /* (FLEX_US_FIER) RXFPTEF Interrupt Enable Position */
#define FLEX_US_FIER_RXFPTEF_Msk              (_UINT32_(0x1) << FLEX_US_FIER_RXFPTEF_Pos)          /* (FLEX_US_FIER) RXFPTEF Interrupt Enable Mask */
#define FLEX_US_FIER_RXFPTEF(value)           (FLEX_US_FIER_RXFPTEF_Msk & (_UINT32_(value) << FLEX_US_FIER_RXFPTEF_Pos)) /* Assigment of value for RXFPTEF in the FLEX_US_FIER register */
#define FLEX_US_FIER_RXFTHF2_Pos              _UINT32_(9)                                          /* (FLEX_US_FIER) RXFTHF2 Interrupt Enable Position */
#define FLEX_US_FIER_RXFTHF2_Msk              (_UINT32_(0x1) << FLEX_US_FIER_RXFTHF2_Pos)          /* (FLEX_US_FIER) RXFTHF2 Interrupt Enable Mask */
#define FLEX_US_FIER_RXFTHF2(value)           (FLEX_US_FIER_RXFTHF2_Msk & (_UINT32_(value) << FLEX_US_FIER_RXFTHF2_Pos)) /* Assigment of value for RXFTHF2 in the FLEX_US_FIER register */
#define FLEX_US_FIER_Msk                      _UINT32_(0x000002FF)                                 /* (FLEX_US_FIER) Register Mask  */


/* -------- FLEX_US_FIDR : (FLEXCOM Offset: 0x2AC) ( /W 32) USART FIFO Interrupt Disable Register -------- */
#define FLEX_US_FIDR_TXFEF_Pos                _UINT32_(0)                                          /* (FLEX_US_FIDR) TXFEF Interrupt Disable Position */
#define FLEX_US_FIDR_TXFEF_Msk                (_UINT32_(0x1) << FLEX_US_FIDR_TXFEF_Pos)            /* (FLEX_US_FIDR) TXFEF Interrupt Disable Mask */
#define FLEX_US_FIDR_TXFEF(value)             (FLEX_US_FIDR_TXFEF_Msk & (_UINT32_(value) << FLEX_US_FIDR_TXFEF_Pos)) /* Assigment of value for TXFEF in the FLEX_US_FIDR register */
#define FLEX_US_FIDR_TXFFF_Pos                _UINT32_(1)                                          /* (FLEX_US_FIDR) TXFFF Interrupt Disable Position */
#define FLEX_US_FIDR_TXFFF_Msk                (_UINT32_(0x1) << FLEX_US_FIDR_TXFFF_Pos)            /* (FLEX_US_FIDR) TXFFF Interrupt Disable Mask */
#define FLEX_US_FIDR_TXFFF(value)             (FLEX_US_FIDR_TXFFF_Msk & (_UINT32_(value) << FLEX_US_FIDR_TXFFF_Pos)) /* Assigment of value for TXFFF in the FLEX_US_FIDR register */
#define FLEX_US_FIDR_TXFTHF_Pos               _UINT32_(2)                                          /* (FLEX_US_FIDR) TXFTHF Interrupt Disable Position */
#define FLEX_US_FIDR_TXFTHF_Msk               (_UINT32_(0x1) << FLEX_US_FIDR_TXFTHF_Pos)           /* (FLEX_US_FIDR) TXFTHF Interrupt Disable Mask */
#define FLEX_US_FIDR_TXFTHF(value)            (FLEX_US_FIDR_TXFTHF_Msk & (_UINT32_(value) << FLEX_US_FIDR_TXFTHF_Pos)) /* Assigment of value for TXFTHF in the FLEX_US_FIDR register */
#define FLEX_US_FIDR_RXFEF_Pos                _UINT32_(3)                                          /* (FLEX_US_FIDR) RXFEF Interrupt Disable Position */
#define FLEX_US_FIDR_RXFEF_Msk                (_UINT32_(0x1) << FLEX_US_FIDR_RXFEF_Pos)            /* (FLEX_US_FIDR) RXFEF Interrupt Disable Mask */
#define FLEX_US_FIDR_RXFEF(value)             (FLEX_US_FIDR_RXFEF_Msk & (_UINT32_(value) << FLEX_US_FIDR_RXFEF_Pos)) /* Assigment of value for RXFEF in the FLEX_US_FIDR register */
#define FLEX_US_FIDR_RXFFF_Pos                _UINT32_(4)                                          /* (FLEX_US_FIDR) RXFFF Interrupt Disable Position */
#define FLEX_US_FIDR_RXFFF_Msk                (_UINT32_(0x1) << FLEX_US_FIDR_RXFFF_Pos)            /* (FLEX_US_FIDR) RXFFF Interrupt Disable Mask */
#define FLEX_US_FIDR_RXFFF(value)             (FLEX_US_FIDR_RXFFF_Msk & (_UINT32_(value) << FLEX_US_FIDR_RXFFF_Pos)) /* Assigment of value for RXFFF in the FLEX_US_FIDR register */
#define FLEX_US_FIDR_RXFTHF_Pos               _UINT32_(5)                                          /* (FLEX_US_FIDR) RXFTHF Interrupt Disable Position */
#define FLEX_US_FIDR_RXFTHF_Msk               (_UINT32_(0x1) << FLEX_US_FIDR_RXFTHF_Pos)           /* (FLEX_US_FIDR) RXFTHF Interrupt Disable Mask */
#define FLEX_US_FIDR_RXFTHF(value)            (FLEX_US_FIDR_RXFTHF_Msk & (_UINT32_(value) << FLEX_US_FIDR_RXFTHF_Pos)) /* Assigment of value for RXFTHF in the FLEX_US_FIDR register */
#define FLEX_US_FIDR_TXFPTEF_Pos              _UINT32_(6)                                          /* (FLEX_US_FIDR) TXFPTEF Interrupt Disable Position */
#define FLEX_US_FIDR_TXFPTEF_Msk              (_UINT32_(0x1) << FLEX_US_FIDR_TXFPTEF_Pos)          /* (FLEX_US_FIDR) TXFPTEF Interrupt Disable Mask */
#define FLEX_US_FIDR_TXFPTEF(value)           (FLEX_US_FIDR_TXFPTEF_Msk & (_UINT32_(value) << FLEX_US_FIDR_TXFPTEF_Pos)) /* Assigment of value for TXFPTEF in the FLEX_US_FIDR register */
#define FLEX_US_FIDR_RXFPTEF_Pos              _UINT32_(7)                                          /* (FLEX_US_FIDR) RXFPTEF Interrupt Disable Position */
#define FLEX_US_FIDR_RXFPTEF_Msk              (_UINT32_(0x1) << FLEX_US_FIDR_RXFPTEF_Pos)          /* (FLEX_US_FIDR) RXFPTEF Interrupt Disable Mask */
#define FLEX_US_FIDR_RXFPTEF(value)           (FLEX_US_FIDR_RXFPTEF_Msk & (_UINT32_(value) << FLEX_US_FIDR_RXFPTEF_Pos)) /* Assigment of value for RXFPTEF in the FLEX_US_FIDR register */
#define FLEX_US_FIDR_RXFTHF2_Pos              _UINT32_(9)                                          /* (FLEX_US_FIDR) RXFTHF2 Interrupt Disable Position */
#define FLEX_US_FIDR_RXFTHF2_Msk              (_UINT32_(0x1) << FLEX_US_FIDR_RXFTHF2_Pos)          /* (FLEX_US_FIDR) RXFTHF2 Interrupt Disable Mask */
#define FLEX_US_FIDR_RXFTHF2(value)           (FLEX_US_FIDR_RXFTHF2_Msk & (_UINT32_(value) << FLEX_US_FIDR_RXFTHF2_Pos)) /* Assigment of value for RXFTHF2 in the FLEX_US_FIDR register */
#define FLEX_US_FIDR_Msk                      _UINT32_(0x000002FF)                                 /* (FLEX_US_FIDR) Register Mask  */


/* -------- FLEX_US_FIMR : (FLEXCOM Offset: 0x2B0) ( R/ 32) USART FIFO Interrupt Mask Register -------- */
#define FLEX_US_FIMR_TXFEF_Pos                _UINT32_(0)                                          /* (FLEX_US_FIMR) TXFEF Interrupt Mask Position */
#define FLEX_US_FIMR_TXFEF_Msk                (_UINT32_(0x1) << FLEX_US_FIMR_TXFEF_Pos)            /* (FLEX_US_FIMR) TXFEF Interrupt Mask Mask */
#define FLEX_US_FIMR_TXFEF(value)             (FLEX_US_FIMR_TXFEF_Msk & (_UINT32_(value) << FLEX_US_FIMR_TXFEF_Pos)) /* Assigment of value for TXFEF in the FLEX_US_FIMR register */
#define FLEX_US_FIMR_TXFFF_Pos                _UINT32_(1)                                          /* (FLEX_US_FIMR) TXFFF Interrupt Mask Position */
#define FLEX_US_FIMR_TXFFF_Msk                (_UINT32_(0x1) << FLEX_US_FIMR_TXFFF_Pos)            /* (FLEX_US_FIMR) TXFFF Interrupt Mask Mask */
#define FLEX_US_FIMR_TXFFF(value)             (FLEX_US_FIMR_TXFFF_Msk & (_UINT32_(value) << FLEX_US_FIMR_TXFFF_Pos)) /* Assigment of value for TXFFF in the FLEX_US_FIMR register */
#define FLEX_US_FIMR_TXFTHF_Pos               _UINT32_(2)                                          /* (FLEX_US_FIMR) TXFTHF Interrupt Mask Position */
#define FLEX_US_FIMR_TXFTHF_Msk               (_UINT32_(0x1) << FLEX_US_FIMR_TXFTHF_Pos)           /* (FLEX_US_FIMR) TXFTHF Interrupt Mask Mask */
#define FLEX_US_FIMR_TXFTHF(value)            (FLEX_US_FIMR_TXFTHF_Msk & (_UINT32_(value) << FLEX_US_FIMR_TXFTHF_Pos)) /* Assigment of value for TXFTHF in the FLEX_US_FIMR register */
#define FLEX_US_FIMR_RXFEF_Pos                _UINT32_(3)                                          /* (FLEX_US_FIMR) RXFEF Interrupt Mask Position */
#define FLEX_US_FIMR_RXFEF_Msk                (_UINT32_(0x1) << FLEX_US_FIMR_RXFEF_Pos)            /* (FLEX_US_FIMR) RXFEF Interrupt Mask Mask */
#define FLEX_US_FIMR_RXFEF(value)             (FLEX_US_FIMR_RXFEF_Msk & (_UINT32_(value) << FLEX_US_FIMR_RXFEF_Pos)) /* Assigment of value for RXFEF in the FLEX_US_FIMR register */
#define FLEX_US_FIMR_RXFFF_Pos                _UINT32_(4)                                          /* (FLEX_US_FIMR) RXFFF Interrupt Mask Position */
#define FLEX_US_FIMR_RXFFF_Msk                (_UINT32_(0x1) << FLEX_US_FIMR_RXFFF_Pos)            /* (FLEX_US_FIMR) RXFFF Interrupt Mask Mask */
#define FLEX_US_FIMR_RXFFF(value)             (FLEX_US_FIMR_RXFFF_Msk & (_UINT32_(value) << FLEX_US_FIMR_RXFFF_Pos)) /* Assigment of value for RXFFF in the FLEX_US_FIMR register */
#define FLEX_US_FIMR_RXFTHF_Pos               _UINT32_(5)                                          /* (FLEX_US_FIMR) RXFTHF Interrupt Mask Position */
#define FLEX_US_FIMR_RXFTHF_Msk               (_UINT32_(0x1) << FLEX_US_FIMR_RXFTHF_Pos)           /* (FLEX_US_FIMR) RXFTHF Interrupt Mask Mask */
#define FLEX_US_FIMR_RXFTHF(value)            (FLEX_US_FIMR_RXFTHF_Msk & (_UINT32_(value) << FLEX_US_FIMR_RXFTHF_Pos)) /* Assigment of value for RXFTHF in the FLEX_US_FIMR register */
#define FLEX_US_FIMR_TXFPTEF_Pos              _UINT32_(6)                                          /* (FLEX_US_FIMR) TXFPTEF Interrupt Mask Position */
#define FLEX_US_FIMR_TXFPTEF_Msk              (_UINT32_(0x1) << FLEX_US_FIMR_TXFPTEF_Pos)          /* (FLEX_US_FIMR) TXFPTEF Interrupt Mask Mask */
#define FLEX_US_FIMR_TXFPTEF(value)           (FLEX_US_FIMR_TXFPTEF_Msk & (_UINT32_(value) << FLEX_US_FIMR_TXFPTEF_Pos)) /* Assigment of value for TXFPTEF in the FLEX_US_FIMR register */
#define FLEX_US_FIMR_RXFPTEF_Pos              _UINT32_(7)                                          /* (FLEX_US_FIMR) RXFPTEF Interrupt Mask Position */
#define FLEX_US_FIMR_RXFPTEF_Msk              (_UINT32_(0x1) << FLEX_US_FIMR_RXFPTEF_Pos)          /* (FLEX_US_FIMR) RXFPTEF Interrupt Mask Mask */
#define FLEX_US_FIMR_RXFPTEF(value)           (FLEX_US_FIMR_RXFPTEF_Msk & (_UINT32_(value) << FLEX_US_FIMR_RXFPTEF_Pos)) /* Assigment of value for RXFPTEF in the FLEX_US_FIMR register */
#define FLEX_US_FIMR_RXFTHF2_Pos              _UINT32_(9)                                          /* (FLEX_US_FIMR) RXFTHF2 Interrupt Mask Position */
#define FLEX_US_FIMR_RXFTHF2_Msk              (_UINT32_(0x1) << FLEX_US_FIMR_RXFTHF2_Pos)          /* (FLEX_US_FIMR) RXFTHF2 Interrupt Mask Mask */
#define FLEX_US_FIMR_RXFTHF2(value)           (FLEX_US_FIMR_RXFTHF2_Msk & (_UINT32_(value) << FLEX_US_FIMR_RXFTHF2_Pos)) /* Assigment of value for RXFTHF2 in the FLEX_US_FIMR register */
#define FLEX_US_FIMR_Msk                      _UINT32_(0x000002FF)                                 /* (FLEX_US_FIMR) Register Mask  */


/* -------- FLEX_US_FESR : (FLEXCOM Offset: 0x2B4) ( R/ 32) USART FIFO Event Status Register -------- */
#define FLEX_US_FESR_TXFEF_Pos                _UINT32_(0)                                          /* (FLEX_US_FESR) Transmit FIFO Empty Flag (cleared by writing the FLEX_US_CR.RSTSTA bit) Position */
#define FLEX_US_FESR_TXFEF_Msk                (_UINT32_(0x1) << FLEX_US_FESR_TXFEF_Pos)            /* (FLEX_US_FESR) Transmit FIFO Empty Flag (cleared by writing the FLEX_US_CR.RSTSTA bit) Mask */
#define FLEX_US_FESR_TXFEF(value)             (FLEX_US_FESR_TXFEF_Msk & (_UINT32_(value) << FLEX_US_FESR_TXFEF_Pos)) /* Assigment of value for TXFEF in the FLEX_US_FESR register */
#define FLEX_US_FESR_TXFFF_Pos                _UINT32_(1)                                          /* (FLEX_US_FESR) Transmit FIFO Full Flag (cleared by writing the FLEX_US_CR.RSTSTA bit) Position */
#define FLEX_US_FESR_TXFFF_Msk                (_UINT32_(0x1) << FLEX_US_FESR_TXFFF_Pos)            /* (FLEX_US_FESR) Transmit FIFO Full Flag (cleared by writing the FLEX_US_CR.RSTSTA bit) Mask */
#define FLEX_US_FESR_TXFFF(value)             (FLEX_US_FESR_TXFFF_Msk & (_UINT32_(value) << FLEX_US_FESR_TXFFF_Pos)) /* Assigment of value for TXFFF in the FLEX_US_FESR register */
#define FLEX_US_FESR_TXFTHF_Pos               _UINT32_(2)                                          /* (FLEX_US_FESR) Transmit FIFO Threshold Flag (cleared by writing the FLEX_US_CR.RSTSTA bit) Position */
#define FLEX_US_FESR_TXFTHF_Msk               (_UINT32_(0x1) << FLEX_US_FESR_TXFTHF_Pos)           /* (FLEX_US_FESR) Transmit FIFO Threshold Flag (cleared by writing the FLEX_US_CR.RSTSTA bit) Mask */
#define FLEX_US_FESR_TXFTHF(value)            (FLEX_US_FESR_TXFTHF_Msk & (_UINT32_(value) << FLEX_US_FESR_TXFTHF_Pos)) /* Assigment of value for TXFTHF in the FLEX_US_FESR register */
#define FLEX_US_FESR_RXFEF_Pos                _UINT32_(3)                                          /* (FLEX_US_FESR) Receive FIFO Empty Flag (cleared by writing the FLEX_US_CR.RSTSTA bit) Position */
#define FLEX_US_FESR_RXFEF_Msk                (_UINT32_(0x1) << FLEX_US_FESR_RXFEF_Pos)            /* (FLEX_US_FESR) Receive FIFO Empty Flag (cleared by writing the FLEX_US_CR.RSTSTA bit) Mask */
#define FLEX_US_FESR_RXFEF(value)             (FLEX_US_FESR_RXFEF_Msk & (_UINT32_(value) << FLEX_US_FESR_RXFEF_Pos)) /* Assigment of value for RXFEF in the FLEX_US_FESR register */
#define FLEX_US_FESR_RXFFF_Pos                _UINT32_(4)                                          /* (FLEX_US_FESR) Receive FIFO Full Flag (cleared by writing the FLEX_US_CR.RSTSTA bit) Position */
#define FLEX_US_FESR_RXFFF_Msk                (_UINT32_(0x1) << FLEX_US_FESR_RXFFF_Pos)            /* (FLEX_US_FESR) Receive FIFO Full Flag (cleared by writing the FLEX_US_CR.RSTSTA bit) Mask */
#define FLEX_US_FESR_RXFFF(value)             (FLEX_US_FESR_RXFFF_Msk & (_UINT32_(value) << FLEX_US_FESR_RXFFF_Pos)) /* Assigment of value for RXFFF in the FLEX_US_FESR register */
#define FLEX_US_FESR_RXFTHF_Pos               _UINT32_(5)                                          /* (FLEX_US_FESR) Receive FIFO Threshold Flag (cleared by writing the FLEX_US_CR.RSTSTA bit) Position */
#define FLEX_US_FESR_RXFTHF_Msk               (_UINT32_(0x1) << FLEX_US_FESR_RXFTHF_Pos)           /* (FLEX_US_FESR) Receive FIFO Threshold Flag (cleared by writing the FLEX_US_CR.RSTSTA bit) Mask */
#define FLEX_US_FESR_RXFTHF(value)            (FLEX_US_FESR_RXFTHF_Msk & (_UINT32_(value) << FLEX_US_FESR_RXFTHF_Pos)) /* Assigment of value for RXFTHF in the FLEX_US_FESR register */
#define FLEX_US_FESR_TXFPTEF_Pos              _UINT32_(6)                                          /* (FLEX_US_FESR) Transmit FIFO Pointer Error Flag Position */
#define FLEX_US_FESR_TXFPTEF_Msk              (_UINT32_(0x1) << FLEX_US_FESR_TXFPTEF_Pos)          /* (FLEX_US_FESR) Transmit FIFO Pointer Error Flag Mask */
#define FLEX_US_FESR_TXFPTEF(value)           (FLEX_US_FESR_TXFPTEF_Msk & (_UINT32_(value) << FLEX_US_FESR_TXFPTEF_Pos)) /* Assigment of value for TXFPTEF in the FLEX_US_FESR register */
#define FLEX_US_FESR_RXFPTEF_Pos              _UINT32_(7)                                          /* (FLEX_US_FESR) Receive FIFO Pointer Error Flag Position */
#define FLEX_US_FESR_RXFPTEF_Msk              (_UINT32_(0x1) << FLEX_US_FESR_RXFPTEF_Pos)          /* (FLEX_US_FESR) Receive FIFO Pointer Error Flag Mask */
#define FLEX_US_FESR_RXFPTEF(value)           (FLEX_US_FESR_RXFPTEF_Msk & (_UINT32_(value) << FLEX_US_FESR_RXFPTEF_Pos)) /* Assigment of value for RXFPTEF in the FLEX_US_FESR register */
#define FLEX_US_FESR_TXFLOCK_Pos              _UINT32_(8)                                          /* (FLEX_US_FESR) Transmit FIFO Lock Position */
#define FLEX_US_FESR_TXFLOCK_Msk              (_UINT32_(0x1) << FLEX_US_FESR_TXFLOCK_Pos)          /* (FLEX_US_FESR) Transmit FIFO Lock Mask */
#define FLEX_US_FESR_TXFLOCK(value)           (FLEX_US_FESR_TXFLOCK_Msk & (_UINT32_(value) << FLEX_US_FESR_TXFLOCK_Pos)) /* Assigment of value for TXFLOCK in the FLEX_US_FESR register */
#define FLEX_US_FESR_RXFTHF2_Pos              _UINT32_(9)                                          /* (FLEX_US_FESR) Receive FIFO Threshold Flag 2 (cleared by writing the FLEX_US_CR.RSTSTA bit) Position */
#define FLEX_US_FESR_RXFTHF2_Msk              (_UINT32_(0x1) << FLEX_US_FESR_RXFTHF2_Pos)          /* (FLEX_US_FESR) Receive FIFO Threshold Flag 2 (cleared by writing the FLEX_US_CR.RSTSTA bit) Mask */
#define FLEX_US_FESR_RXFTHF2(value)           (FLEX_US_FESR_RXFTHF2_Msk & (_UINT32_(value) << FLEX_US_FESR_RXFTHF2_Pos)) /* Assigment of value for RXFTHF2 in the FLEX_US_FESR register */
#define FLEX_US_FESR_Msk                      _UINT32_(0x000003FF)                                 /* (FLEX_US_FESR) Register Mask  */


/* -------- FLEX_US_WPMR : (FLEXCOM Offset: 0x2E4) (R/W 32) USART Write Protection Mode Register -------- */
#define FLEX_US_WPMR_WPEN_Pos                 _UINT32_(0)                                          /* (FLEX_US_WPMR) Write Protection Enable Position */
#define FLEX_US_WPMR_WPEN_Msk                 (_UINT32_(0x1) << FLEX_US_WPMR_WPEN_Pos)             /* (FLEX_US_WPMR) Write Protection Enable Mask */
#define FLEX_US_WPMR_WPEN(value)              (FLEX_US_WPMR_WPEN_Msk & (_UINT32_(value) << FLEX_US_WPMR_WPEN_Pos)) /* Assigment of value for WPEN in the FLEX_US_WPMR register */
#define FLEX_US_WPMR_WPITEN_Pos               _UINT32_(1)                                          /* (FLEX_US_WPMR) Write Protection Interrupt Enable Position */
#define FLEX_US_WPMR_WPITEN_Msk               (_UINT32_(0x1) << FLEX_US_WPMR_WPITEN_Pos)           /* (FLEX_US_WPMR) Write Protection Interrupt Enable Mask */
#define FLEX_US_WPMR_WPITEN(value)            (FLEX_US_WPMR_WPITEN_Msk & (_UINT32_(value) << FLEX_US_WPMR_WPITEN_Pos)) /* Assigment of value for WPITEN in the FLEX_US_WPMR register */
#define FLEX_US_WPMR_WPCREN_Pos               _UINT32_(2)                                          /* (FLEX_US_WPMR) Write Protection Control Enable Position */
#define FLEX_US_WPMR_WPCREN_Msk               (_UINT32_(0x1) << FLEX_US_WPMR_WPCREN_Pos)           /* (FLEX_US_WPMR) Write Protection Control Enable Mask */
#define FLEX_US_WPMR_WPCREN(value)            (FLEX_US_WPMR_WPCREN_Msk & (_UINT32_(value) << FLEX_US_WPMR_WPCREN_Pos)) /* Assigment of value for WPCREN in the FLEX_US_WPMR register */
#define FLEX_US_WPMR_WPKEY_Pos                _UINT32_(8)                                          /* (FLEX_US_WPMR) Write Protection Key Position */
#define FLEX_US_WPMR_WPKEY_Msk                (_UINT32_(0xFFFFFF) << FLEX_US_WPMR_WPKEY_Pos)       /* (FLEX_US_WPMR) Write Protection Key Mask */
#define FLEX_US_WPMR_WPKEY(value)             (FLEX_US_WPMR_WPKEY_Msk & (_UINT32_(value) << FLEX_US_WPMR_WPKEY_Pos)) /* Assigment of value for WPKEY in the FLEX_US_WPMR register */
#define   FLEX_US_WPMR_WPKEY_PASSWD_Val       _UINT32_(0x555341)                                   /* (FLEX_US_WPMR) Writing any other value in this field aborts the write operation of bits WPEN, WPITEN and WPCREN. Always reads as 0.  */
#define FLEX_US_WPMR_WPKEY_PASSWD             (FLEX_US_WPMR_WPKEY_PASSWD_Val << FLEX_US_WPMR_WPKEY_Pos) /* (FLEX_US_WPMR) Writing any other value in this field aborts the write operation of bits WPEN, WPITEN and WPCREN. Always reads as 0. Position  */
#define FLEX_US_WPMR_Msk                      _UINT32_(0xFFFFFF07)                                 /* (FLEX_US_WPMR) Register Mask  */


/* -------- FLEX_US_WPSR : (FLEXCOM Offset: 0x2E8) ( R/ 32) USART Write Protection Status Register -------- */
#define FLEX_US_WPSR_WPVS_Pos                 _UINT32_(0)                                          /* (FLEX_US_WPSR) Write Protection Violation Status Position */
#define FLEX_US_WPSR_WPVS_Msk                 (_UINT32_(0x1) << FLEX_US_WPSR_WPVS_Pos)             /* (FLEX_US_WPSR) Write Protection Violation Status Mask */
#define FLEX_US_WPSR_WPVS(value)              (FLEX_US_WPSR_WPVS_Msk & (_UINT32_(value) << FLEX_US_WPSR_WPVS_Pos)) /* Assigment of value for WPVS in the FLEX_US_WPSR register */
#define FLEX_US_WPSR_WPVSRC_Pos               _UINT32_(8)                                          /* (FLEX_US_WPSR) Write Protection Violation Source Position */
#define FLEX_US_WPSR_WPVSRC_Msk               (_UINT32_(0xFFFF) << FLEX_US_WPSR_WPVSRC_Pos)        /* (FLEX_US_WPSR) Write Protection Violation Source Mask */
#define FLEX_US_WPSR_WPVSRC(value)            (FLEX_US_WPSR_WPVSRC_Msk & (_UINT32_(value) << FLEX_US_WPSR_WPVSRC_Pos)) /* Assigment of value for WPVSRC in the FLEX_US_WPSR register */
#define FLEX_US_WPSR_Msk                      _UINT32_(0x00FFFF01)                                 /* (FLEX_US_WPSR) Register Mask  */


/* -------- FLEX_SPI_CR : (FLEXCOM Offset: 0x400) ( /W 32) SPI Control Register -------- */
#define FLEX_SPI_CR_SPIEN_Pos                 _UINT32_(0)                                          /* (FLEX_SPI_CR) SPI Enable Position */
#define FLEX_SPI_CR_SPIEN_Msk                 (_UINT32_(0x1) << FLEX_SPI_CR_SPIEN_Pos)             /* (FLEX_SPI_CR) SPI Enable Mask */
#define FLEX_SPI_CR_SPIEN(value)              (FLEX_SPI_CR_SPIEN_Msk & (_UINT32_(value) << FLEX_SPI_CR_SPIEN_Pos)) /* Assigment of value for SPIEN in the FLEX_SPI_CR register */
#define FLEX_SPI_CR_SPIDIS_Pos                _UINT32_(1)                                          /* (FLEX_SPI_CR) SPI Disable Position */
#define FLEX_SPI_CR_SPIDIS_Msk                (_UINT32_(0x1) << FLEX_SPI_CR_SPIDIS_Pos)            /* (FLEX_SPI_CR) SPI Disable Mask */
#define FLEX_SPI_CR_SPIDIS(value)             (FLEX_SPI_CR_SPIDIS_Msk & (_UINT32_(value) << FLEX_SPI_CR_SPIDIS_Pos)) /* Assigment of value for SPIDIS in the FLEX_SPI_CR register */
#define FLEX_SPI_CR_SWRST_Pos                 _UINT32_(7)                                          /* (FLEX_SPI_CR) SPI Software Reset Position */
#define FLEX_SPI_CR_SWRST_Msk                 (_UINT32_(0x1) << FLEX_SPI_CR_SWRST_Pos)             /* (FLEX_SPI_CR) SPI Software Reset Mask */
#define FLEX_SPI_CR_SWRST(value)              (FLEX_SPI_CR_SWRST_Msk & (_UINT32_(value) << FLEX_SPI_CR_SWRST_Pos)) /* Assigment of value for SWRST in the FLEX_SPI_CR register */
#define FLEX_SPI_CR_REQCLR_Pos                _UINT32_(12)                                         /* (FLEX_SPI_CR) Request to Clear the Comparison Trigger Position */
#define FLEX_SPI_CR_REQCLR_Msk                (_UINT32_(0x1) << FLEX_SPI_CR_REQCLR_Pos)            /* (FLEX_SPI_CR) Request to Clear the Comparison Trigger Mask */
#define FLEX_SPI_CR_REQCLR(value)             (FLEX_SPI_CR_REQCLR_Msk & (_UINT32_(value) << FLEX_SPI_CR_REQCLR_Pos)) /* Assigment of value for REQCLR in the FLEX_SPI_CR register */
#define FLEX_SPI_CR_TXFCLR_Pos                _UINT32_(16)                                         /* (FLEX_SPI_CR) Transmit FIFO Clear Position */
#define FLEX_SPI_CR_TXFCLR_Msk                (_UINT32_(0x1) << FLEX_SPI_CR_TXFCLR_Pos)            /* (FLEX_SPI_CR) Transmit FIFO Clear Mask */
#define FLEX_SPI_CR_TXFCLR(value)             (FLEX_SPI_CR_TXFCLR_Msk & (_UINT32_(value) << FLEX_SPI_CR_TXFCLR_Pos)) /* Assigment of value for TXFCLR in the FLEX_SPI_CR register */
#define FLEX_SPI_CR_RXFCLR_Pos                _UINT32_(17)                                         /* (FLEX_SPI_CR) Receive FIFO Clear Position */
#define FLEX_SPI_CR_RXFCLR_Msk                (_UINT32_(0x1) << FLEX_SPI_CR_RXFCLR_Pos)            /* (FLEX_SPI_CR) Receive FIFO Clear Mask */
#define FLEX_SPI_CR_RXFCLR(value)             (FLEX_SPI_CR_RXFCLR_Msk & (_UINT32_(value) << FLEX_SPI_CR_RXFCLR_Pos)) /* Assigment of value for RXFCLR in the FLEX_SPI_CR register */
#define FLEX_SPI_CR_LASTXFER_Pos              _UINT32_(24)                                         /* (FLEX_SPI_CR) Last Transfer Position */
#define FLEX_SPI_CR_LASTXFER_Msk              (_UINT32_(0x1) << FLEX_SPI_CR_LASTXFER_Pos)          /* (FLEX_SPI_CR) Last Transfer Mask */
#define FLEX_SPI_CR_LASTXFER(value)           (FLEX_SPI_CR_LASTXFER_Msk & (_UINT32_(value) << FLEX_SPI_CR_LASTXFER_Pos)) /* Assigment of value for LASTXFER in the FLEX_SPI_CR register */
#define FLEX_SPI_CR_FIFOEN_Pos                _UINT32_(30)                                         /* (FLEX_SPI_CR) FIFO Enable Position */
#define FLEX_SPI_CR_FIFOEN_Msk                (_UINT32_(0x1) << FLEX_SPI_CR_FIFOEN_Pos)            /* (FLEX_SPI_CR) FIFO Enable Mask */
#define FLEX_SPI_CR_FIFOEN(value)             (FLEX_SPI_CR_FIFOEN_Msk & (_UINT32_(value) << FLEX_SPI_CR_FIFOEN_Pos)) /* Assigment of value for FIFOEN in the FLEX_SPI_CR register */
#define FLEX_SPI_CR_FIFODIS_Pos               _UINT32_(31)                                         /* (FLEX_SPI_CR) FIFO Disable Position */
#define FLEX_SPI_CR_FIFODIS_Msk               (_UINT32_(0x1) << FLEX_SPI_CR_FIFODIS_Pos)           /* (FLEX_SPI_CR) FIFO Disable Mask */
#define FLEX_SPI_CR_FIFODIS(value)            (FLEX_SPI_CR_FIFODIS_Msk & (_UINT32_(value) << FLEX_SPI_CR_FIFODIS_Pos)) /* Assigment of value for FIFODIS in the FLEX_SPI_CR register */
#define FLEX_SPI_CR_Msk                       _UINT32_(0xC1031083)                                 /* (FLEX_SPI_CR) Register Mask  */


/* -------- FLEX_SPI_MR : (FLEXCOM Offset: 0x404) (R/W 32) SPI Mode Register -------- */
#define FLEX_SPI_MR_MSTR_Pos                  _UINT32_(0)                                          /* (FLEX_SPI_MR) Host/Client Mode Position */
#define FLEX_SPI_MR_MSTR_Msk                  (_UINT32_(0x1) << FLEX_SPI_MR_MSTR_Pos)              /* (FLEX_SPI_MR) Host/Client Mode Mask */
#define FLEX_SPI_MR_MSTR(value)               (FLEX_SPI_MR_MSTR_Msk & (_UINT32_(value) << FLEX_SPI_MR_MSTR_Pos)) /* Assigment of value for MSTR in the FLEX_SPI_MR register */
#define FLEX_SPI_MR_PS_Pos                    _UINT32_(1)                                          /* (FLEX_SPI_MR) Peripheral Select Position */
#define FLEX_SPI_MR_PS_Msk                    (_UINT32_(0x1) << FLEX_SPI_MR_PS_Pos)                /* (FLEX_SPI_MR) Peripheral Select Mask */
#define FLEX_SPI_MR_PS(value)                 (FLEX_SPI_MR_PS_Msk & (_UINT32_(value) << FLEX_SPI_MR_PS_Pos)) /* Assigment of value for PS in the FLEX_SPI_MR register */
#define FLEX_SPI_MR_PCSDEC_Pos                _UINT32_(2)                                          /* (FLEX_SPI_MR) Chip Select Decode Position */
#define FLEX_SPI_MR_PCSDEC_Msk                (_UINT32_(0x1) << FLEX_SPI_MR_PCSDEC_Pos)            /* (FLEX_SPI_MR) Chip Select Decode Mask */
#define FLEX_SPI_MR_PCSDEC(value)             (FLEX_SPI_MR_PCSDEC_Msk & (_UINT32_(value) << FLEX_SPI_MR_PCSDEC_Pos)) /* Assigment of value for PCSDEC in the FLEX_SPI_MR register */
#define FLEX_SPI_MR_BRSRCCLK_Pos              _UINT32_(3)                                          /* (FLEX_SPI_MR) Bit Rate Source Clock Position */
#define FLEX_SPI_MR_BRSRCCLK_Msk              (_UINT32_(0x1) << FLEX_SPI_MR_BRSRCCLK_Pos)          /* (FLEX_SPI_MR) Bit Rate Source Clock Mask */
#define FLEX_SPI_MR_BRSRCCLK(value)           (FLEX_SPI_MR_BRSRCCLK_Msk & (_UINT32_(value) << FLEX_SPI_MR_BRSRCCLK_Pos)) /* Assigment of value for BRSRCCLK in the FLEX_SPI_MR register */
#define   FLEX_SPI_MR_BRSRCCLK_PERIPH_CLK_Val _UINT32_(0x0)                                        /* (FLEX_SPI_MR) The peripheral clock is the source clock for the bit rate generation.  */
#define   FLEX_SPI_MR_BRSRCCLK_GCLK_Val       _UINT32_(0x1)                                        /* (FLEX_SPI_MR) GCLK is the source clock for the bit rate generation, thus the bit rate can be independent of the core/peripheral clock.  */
#define FLEX_SPI_MR_BRSRCCLK_PERIPH_CLK       (FLEX_SPI_MR_BRSRCCLK_PERIPH_CLK_Val << FLEX_SPI_MR_BRSRCCLK_Pos) /* (FLEX_SPI_MR) The peripheral clock is the source clock for the bit rate generation. Position  */
#define FLEX_SPI_MR_BRSRCCLK_GCLK             (FLEX_SPI_MR_BRSRCCLK_GCLK_Val << FLEX_SPI_MR_BRSRCCLK_Pos) /* (FLEX_SPI_MR) GCLK is the source clock for the bit rate generation, thus the bit rate can be independent of the core/peripheral clock. Position  */
#define FLEX_SPI_MR_MODFDIS_Pos               _UINT32_(4)                                          /* (FLEX_SPI_MR) Mode Fault Detection Position */
#define FLEX_SPI_MR_MODFDIS_Msk               (_UINT32_(0x1) << FLEX_SPI_MR_MODFDIS_Pos)           /* (FLEX_SPI_MR) Mode Fault Detection Mask */
#define FLEX_SPI_MR_MODFDIS(value)            (FLEX_SPI_MR_MODFDIS_Msk & (_UINT32_(value) << FLEX_SPI_MR_MODFDIS_Pos)) /* Assigment of value for MODFDIS in the FLEX_SPI_MR register */
#define FLEX_SPI_MR_WDRBT_Pos                 _UINT32_(5)                                          /* (FLEX_SPI_MR) Wait Data Read Before Transfer Position */
#define FLEX_SPI_MR_WDRBT_Msk                 (_UINT32_(0x1) << FLEX_SPI_MR_WDRBT_Pos)             /* (FLEX_SPI_MR) Wait Data Read Before Transfer Mask */
#define FLEX_SPI_MR_WDRBT(value)              (FLEX_SPI_MR_WDRBT_Msk & (_UINT32_(value) << FLEX_SPI_MR_WDRBT_Pos)) /* Assigment of value for WDRBT in the FLEX_SPI_MR register */
#define FLEX_SPI_MR_LLB_Pos                   _UINT32_(7)                                          /* (FLEX_SPI_MR) Local Loopback Enable Position */
#define FLEX_SPI_MR_LLB_Msk                   (_UINT32_(0x1) << FLEX_SPI_MR_LLB_Pos)               /* (FLEX_SPI_MR) Local Loopback Enable Mask */
#define FLEX_SPI_MR_LLB(value)                (FLEX_SPI_MR_LLB_Msk & (_UINT32_(value) << FLEX_SPI_MR_LLB_Pos)) /* Assigment of value for LLB in the FLEX_SPI_MR register */
#define FLEX_SPI_MR_CMPMODE_Pos               _UINT32_(12)                                         /* (FLEX_SPI_MR) Comparison Mode Position */
#define FLEX_SPI_MR_CMPMODE_Msk               (_UINT32_(0x1) << FLEX_SPI_MR_CMPMODE_Pos)           /* (FLEX_SPI_MR) Comparison Mode Mask */
#define FLEX_SPI_MR_CMPMODE(value)            (FLEX_SPI_MR_CMPMODE_Msk & (_UINT32_(value) << FLEX_SPI_MR_CMPMODE_Pos)) /* Assigment of value for CMPMODE in the FLEX_SPI_MR register */
#define   FLEX_SPI_MR_CMPMODE_FLAG_ONLY_Val   _UINT32_(0x0)                                        /* (FLEX_SPI_MR) Any character is received and comparison function drives CMP flag.  */
#define   FLEX_SPI_MR_CMPMODE_START_CONDITION_Val _UINT32_(0x1)                                        /* (FLEX_SPI_MR) Comparison condition must be met to start reception of all incoming characters until REQCLR is set.  */
#define FLEX_SPI_MR_CMPMODE_FLAG_ONLY         (FLEX_SPI_MR_CMPMODE_FLAG_ONLY_Val << FLEX_SPI_MR_CMPMODE_Pos) /* (FLEX_SPI_MR) Any character is received and comparison function drives CMP flag. Position  */
#define FLEX_SPI_MR_CMPMODE_START_CONDITION   (FLEX_SPI_MR_CMPMODE_START_CONDITION_Val << FLEX_SPI_MR_CMPMODE_Pos) /* (FLEX_SPI_MR) Comparison condition must be met to start reception of all incoming characters until REQCLR is set. Position  */
#define FLEX_SPI_MR_PCS_Pos                   _UINT32_(16)                                         /* (FLEX_SPI_MR) Peripheral Chip Select Position */
#define FLEX_SPI_MR_PCS_Msk                   (_UINT32_(0x3) << FLEX_SPI_MR_PCS_Pos)               /* (FLEX_SPI_MR) Peripheral Chip Select Mask */
#define FLEX_SPI_MR_PCS(value)                (FLEX_SPI_MR_PCS_Msk & (_UINT32_(value) << FLEX_SPI_MR_PCS_Pos)) /* Assigment of value for PCS in the FLEX_SPI_MR register */
#define FLEX_SPI_MR_DLYBCS_Pos                _UINT32_(24)                                         /* (FLEX_SPI_MR) Delay Between Chip Selects Position */
#define FLEX_SPI_MR_DLYBCS_Msk                (_UINT32_(0xFF) << FLEX_SPI_MR_DLYBCS_Pos)           /* (FLEX_SPI_MR) Delay Between Chip Selects Mask */
#define FLEX_SPI_MR_DLYBCS(value)             (FLEX_SPI_MR_DLYBCS_Msk & (_UINT32_(value) << FLEX_SPI_MR_DLYBCS_Pos)) /* Assigment of value for DLYBCS in the FLEX_SPI_MR register */
#define FLEX_SPI_MR_Msk                       _UINT32_(0xFF0310BF)                                 /* (FLEX_SPI_MR) Register Mask  */


/* -------- FLEX_SPI_RDR : (FLEXCOM Offset: 0x408) ( R/ 32) SPI Receive Data Register -------- */
#define FLEX_SPI_RDR_RD_Pos                   _UINT32_(0)                                          /* (FLEX_SPI_RDR) Receive Data Position */
#define FLEX_SPI_RDR_RD_Msk                   (_UINT32_(0xFFFF) << FLEX_SPI_RDR_RD_Pos)            /* (FLEX_SPI_RDR) Receive Data Mask */
#define FLEX_SPI_RDR_RD(value)                (FLEX_SPI_RDR_RD_Msk & (_UINT32_(value) << FLEX_SPI_RDR_RD_Pos)) /* Assigment of value for RD in the FLEX_SPI_RDR register */
#define FLEX_SPI_RDR_PCS_Pos                  _UINT32_(16)                                         /* (FLEX_SPI_RDR) Peripheral Chip Select Position */
#define FLEX_SPI_RDR_PCS_Msk                  (_UINT32_(0xF) << FLEX_SPI_RDR_PCS_Pos)              /* (FLEX_SPI_RDR) Peripheral Chip Select Mask */
#define FLEX_SPI_RDR_PCS(value)               (FLEX_SPI_RDR_PCS_Msk & (_UINT32_(value) << FLEX_SPI_RDR_PCS_Pos)) /* Assigment of value for PCS in the FLEX_SPI_RDR register */
#define FLEX_SPI_RDR_Msk                      _UINT32_(0x000FFFFF)                                 /* (FLEX_SPI_RDR) Register Mask  */

/* FIFO_MULTI_DATA_8 mode */
#define FLEX_SPI_RDR_FIFO_MULTI_DATA_8_RD0_Pos _UINT32_(0)                                          /* (FLEX_SPI_RDR) Receive Data Position */
#define FLEX_SPI_RDR_FIFO_MULTI_DATA_8_RD0_Msk (_UINT32_(0xFF) << FLEX_SPI_RDR_FIFO_MULTI_DATA_8_RD0_Pos) /* (FLEX_SPI_RDR) Receive Data Mask */
#define FLEX_SPI_RDR_FIFO_MULTI_DATA_8_RD0(value) (FLEX_SPI_RDR_FIFO_MULTI_DATA_8_RD0_Msk & (_UINT32_(value) << FLEX_SPI_RDR_FIFO_MULTI_DATA_8_RD0_Pos))
#define FLEX_SPI_RDR_FIFO_MULTI_DATA_8_RD1_Pos _UINT32_(8)                                          /* (FLEX_SPI_RDR) Receive Data Position */
#define FLEX_SPI_RDR_FIFO_MULTI_DATA_8_RD1_Msk (_UINT32_(0xFF) << FLEX_SPI_RDR_FIFO_MULTI_DATA_8_RD1_Pos) /* (FLEX_SPI_RDR) Receive Data Mask */
#define FLEX_SPI_RDR_FIFO_MULTI_DATA_8_RD1(value) (FLEX_SPI_RDR_FIFO_MULTI_DATA_8_RD1_Msk & (_UINT32_(value) << FLEX_SPI_RDR_FIFO_MULTI_DATA_8_RD1_Pos))
#define FLEX_SPI_RDR_FIFO_MULTI_DATA_8_RD2_Pos _UINT32_(16)                                         /* (FLEX_SPI_RDR) Receive Data Position */
#define FLEX_SPI_RDR_FIFO_MULTI_DATA_8_RD2_Msk (_UINT32_(0xFF) << FLEX_SPI_RDR_FIFO_MULTI_DATA_8_RD2_Pos) /* (FLEX_SPI_RDR) Receive Data Mask */
#define FLEX_SPI_RDR_FIFO_MULTI_DATA_8_RD2(value) (FLEX_SPI_RDR_FIFO_MULTI_DATA_8_RD2_Msk & (_UINT32_(value) << FLEX_SPI_RDR_FIFO_MULTI_DATA_8_RD2_Pos))
#define FLEX_SPI_RDR_FIFO_MULTI_DATA_8_RD3_Pos _UINT32_(24)                                         /* (FLEX_SPI_RDR) Receive Data Position */
#define FLEX_SPI_RDR_FIFO_MULTI_DATA_8_RD3_Msk (_UINT32_(0xFF) << FLEX_SPI_RDR_FIFO_MULTI_DATA_8_RD3_Pos) /* (FLEX_SPI_RDR) Receive Data Mask */
#define FLEX_SPI_RDR_FIFO_MULTI_DATA_8_RD3(value) (FLEX_SPI_RDR_FIFO_MULTI_DATA_8_RD3_Msk & (_UINT32_(value) << FLEX_SPI_RDR_FIFO_MULTI_DATA_8_RD3_Pos))
#define FLEX_SPI_RDR_FIFO_MULTI_DATA_8_Msk    _UINT32_(0xFFFFFFFF)                                  /* (FLEX_SPI_RDR_FIFO_MULTI_DATA_8) Register Mask  */

/* FIFO_MULTI_DATA_16 mode */
#define FLEX_SPI_RDR_FIFO_MULTI_DATA_16_RD0_Pos _UINT32_(0)                                          /* (FLEX_SPI_RDR) Receive Data Position */
#define FLEX_SPI_RDR_FIFO_MULTI_DATA_16_RD0_Msk (_UINT32_(0xFFFF) << FLEX_SPI_RDR_FIFO_MULTI_DATA_16_RD0_Pos) /* (FLEX_SPI_RDR) Receive Data Mask */
#define FLEX_SPI_RDR_FIFO_MULTI_DATA_16_RD0(value) (FLEX_SPI_RDR_FIFO_MULTI_DATA_16_RD0_Msk & (_UINT32_(value) << FLEX_SPI_RDR_FIFO_MULTI_DATA_16_RD0_Pos))
#define FLEX_SPI_RDR_FIFO_MULTI_DATA_16_RD1_Pos _UINT32_(16)                                         /* (FLEX_SPI_RDR) Receive Data Position */
#define FLEX_SPI_RDR_FIFO_MULTI_DATA_16_RD1_Msk (_UINT32_(0xFFFF) << FLEX_SPI_RDR_FIFO_MULTI_DATA_16_RD1_Pos) /* (FLEX_SPI_RDR) Receive Data Mask */
#define FLEX_SPI_RDR_FIFO_MULTI_DATA_16_RD1(value) (FLEX_SPI_RDR_FIFO_MULTI_DATA_16_RD1_Msk & (_UINT32_(value) << FLEX_SPI_RDR_FIFO_MULTI_DATA_16_RD1_Pos))
#define FLEX_SPI_RDR_FIFO_MULTI_DATA_16_Msk   _UINT32_(0xFFFFFFFF)                                  /* (FLEX_SPI_RDR_FIFO_MULTI_DATA_16) Register Mask  */


/* -------- FLEX_SPI_TDR : (FLEXCOM Offset: 0x40C) ( /W 32) SPI Transmit Data Register -------- */
#define FLEX_SPI_TDR_TD_Pos                   _UINT32_(0)                                          /* (FLEX_SPI_TDR) Transmit Data Position */
#define FLEX_SPI_TDR_TD_Msk                   (_UINT32_(0xFFFF) << FLEX_SPI_TDR_TD_Pos)            /* (FLEX_SPI_TDR) Transmit Data Mask */
#define FLEX_SPI_TDR_TD(value)                (FLEX_SPI_TDR_TD_Msk & (_UINT32_(value) << FLEX_SPI_TDR_TD_Pos)) /* Assigment of value for TD in the FLEX_SPI_TDR register */
#define FLEX_SPI_TDR_PCS_Pos                  _UINT32_(16)                                         /* (FLEX_SPI_TDR) Peripheral Chip Select Position */
#define FLEX_SPI_TDR_PCS_Msk                  (_UINT32_(0xF) << FLEX_SPI_TDR_PCS_Pos)              /* (FLEX_SPI_TDR) Peripheral Chip Select Mask */
#define FLEX_SPI_TDR_PCS(value)               (FLEX_SPI_TDR_PCS_Msk & (_UINT32_(value) << FLEX_SPI_TDR_PCS_Pos)) /* Assigment of value for PCS in the FLEX_SPI_TDR register */
#define FLEX_SPI_TDR_LASTXFER_Pos             _UINT32_(24)                                         /* (FLEX_SPI_TDR) Last Transfer Position */
#define FLEX_SPI_TDR_LASTXFER_Msk             (_UINT32_(0x1) << FLEX_SPI_TDR_LASTXFER_Pos)         /* (FLEX_SPI_TDR) Last Transfer Mask */
#define FLEX_SPI_TDR_LASTXFER(value)          (FLEX_SPI_TDR_LASTXFER_Msk & (_UINT32_(value) << FLEX_SPI_TDR_LASTXFER_Pos)) /* Assigment of value for LASTXFER in the FLEX_SPI_TDR register */
#define FLEX_SPI_TDR_Msk                      _UINT32_(0x010FFFFF)                                 /* (FLEX_SPI_TDR) Register Mask  */

/* FIFO_MULTI_DATA mode */
#define FLEX_SPI_TDR_FIFO_MULTI_DATA_TD0_Pos  _UINT32_(0)                                          /* (FLEX_SPI_TDR) Transmit Data Position */
#define FLEX_SPI_TDR_FIFO_MULTI_DATA_TD0_Msk  (_UINT32_(0xFFFF) << FLEX_SPI_TDR_FIFO_MULTI_DATA_TD0_Pos) /* (FLEX_SPI_TDR) Transmit Data Mask */
#define FLEX_SPI_TDR_FIFO_MULTI_DATA_TD0(value) (FLEX_SPI_TDR_FIFO_MULTI_DATA_TD0_Msk & (_UINT32_(value) << FLEX_SPI_TDR_FIFO_MULTI_DATA_TD0_Pos))
#define FLEX_SPI_TDR_FIFO_MULTI_DATA_TD1_Pos  _UINT32_(16)                                         /* (FLEX_SPI_TDR) Transmit Data Position */
#define FLEX_SPI_TDR_FIFO_MULTI_DATA_TD1_Msk  (_UINT32_(0xFFFF) << FLEX_SPI_TDR_FIFO_MULTI_DATA_TD1_Pos) /* (FLEX_SPI_TDR) Transmit Data Mask */
#define FLEX_SPI_TDR_FIFO_MULTI_DATA_TD1(value) (FLEX_SPI_TDR_FIFO_MULTI_DATA_TD1_Msk & (_UINT32_(value) << FLEX_SPI_TDR_FIFO_MULTI_DATA_TD1_Pos))
#define FLEX_SPI_TDR_FIFO_MULTI_DATA_Msk      _UINT32_(0xFFFFFFFF)                                  /* (FLEX_SPI_TDR_FIFO_MULTI_DATA) Register Mask  */


/* -------- FLEX_SPI_SR : (FLEXCOM Offset: 0x410) ( R/ 32) SPI Status Register -------- */
#define FLEX_SPI_SR_RDRF_Pos                  _UINT32_(0)                                          /* (FLEX_SPI_SR) Receive Data Register Full (cleared by reading FLEX_SPI_RDR) Position */
#define FLEX_SPI_SR_RDRF_Msk                  (_UINT32_(0x1) << FLEX_SPI_SR_RDRF_Pos)              /* (FLEX_SPI_SR) Receive Data Register Full (cleared by reading FLEX_SPI_RDR) Mask */
#define FLEX_SPI_SR_RDRF(value)               (FLEX_SPI_SR_RDRF_Msk & (_UINT32_(value) << FLEX_SPI_SR_RDRF_Pos)) /* Assigment of value for RDRF in the FLEX_SPI_SR register */
#define FLEX_SPI_SR_TDRE_Pos                  _UINT32_(1)                                          /* (FLEX_SPI_SR) Transmit Data Register Empty (cleared by writing FLEX_SPI_TDR) Position */
#define FLEX_SPI_SR_TDRE_Msk                  (_UINT32_(0x1) << FLEX_SPI_SR_TDRE_Pos)              /* (FLEX_SPI_SR) Transmit Data Register Empty (cleared by writing FLEX_SPI_TDR) Mask */
#define FLEX_SPI_SR_TDRE(value)               (FLEX_SPI_SR_TDRE_Msk & (_UINT32_(value) << FLEX_SPI_SR_TDRE_Pos)) /* Assigment of value for TDRE in the FLEX_SPI_SR register */
#define FLEX_SPI_SR_MODF_Pos                  _UINT32_(2)                                          /* (FLEX_SPI_SR) Mode Fault Error (cleared on read) Position */
#define FLEX_SPI_SR_MODF_Msk                  (_UINT32_(0x1) << FLEX_SPI_SR_MODF_Pos)              /* (FLEX_SPI_SR) Mode Fault Error (cleared on read) Mask */
#define FLEX_SPI_SR_MODF(value)               (FLEX_SPI_SR_MODF_Msk & (_UINT32_(value) << FLEX_SPI_SR_MODF_Pos)) /* Assigment of value for MODF in the FLEX_SPI_SR register */
#define FLEX_SPI_SR_OVRES_Pos                 _UINT32_(3)                                          /* (FLEX_SPI_SR) Overrun Error Status (cleared on read) Position */
#define FLEX_SPI_SR_OVRES_Msk                 (_UINT32_(0x1) << FLEX_SPI_SR_OVRES_Pos)             /* (FLEX_SPI_SR) Overrun Error Status (cleared on read) Mask */
#define FLEX_SPI_SR_OVRES(value)              (FLEX_SPI_SR_OVRES_Msk & (_UINT32_(value) << FLEX_SPI_SR_OVRES_Pos)) /* Assigment of value for OVRES in the FLEX_SPI_SR register */
#define FLEX_SPI_SR_ENDRX_Pos                 _UINT32_(4)                                          /* (FLEX_SPI_SR) End of RX Buffer (cleared by writing FLEX_SPI_RCR or FLEX_SPI_RNCR) Position */
#define FLEX_SPI_SR_ENDRX_Msk                 (_UINT32_(0x1) << FLEX_SPI_SR_ENDRX_Pos)             /* (FLEX_SPI_SR) End of RX Buffer (cleared by writing FLEX_SPI_RCR or FLEX_SPI_RNCR) Mask */
#define FLEX_SPI_SR_ENDRX(value)              (FLEX_SPI_SR_ENDRX_Msk & (_UINT32_(value) << FLEX_SPI_SR_ENDRX_Pos)) /* Assigment of value for ENDRX in the FLEX_SPI_SR register */
#define FLEX_SPI_SR_ENDTX_Pos                 _UINT32_(5)                                          /* (FLEX_SPI_SR) End of TX Buffer (cleared by writing FLEX_SPI_TCR or FLEX_SPI_TNCR) Position */
#define FLEX_SPI_SR_ENDTX_Msk                 (_UINT32_(0x1) << FLEX_SPI_SR_ENDTX_Pos)             /* (FLEX_SPI_SR) End of TX Buffer (cleared by writing FLEX_SPI_TCR or FLEX_SPI_TNCR) Mask */
#define FLEX_SPI_SR_ENDTX(value)              (FLEX_SPI_SR_ENDTX_Msk & (_UINT32_(value) << FLEX_SPI_SR_ENDTX_Pos)) /* Assigment of value for ENDTX in the FLEX_SPI_SR register */
#define FLEX_SPI_SR_RXBUFF_Pos                _UINT32_(6)                                          /* (FLEX_SPI_SR) RX Buffer Full (cleared by writing FLEX_SPI_RCR or FLEX_SPI_RNCR) Position */
#define FLEX_SPI_SR_RXBUFF_Msk                (_UINT32_(0x1) << FLEX_SPI_SR_RXBUFF_Pos)            /* (FLEX_SPI_SR) RX Buffer Full (cleared by writing FLEX_SPI_RCR or FLEX_SPI_RNCR) Mask */
#define FLEX_SPI_SR_RXBUFF(value)             (FLEX_SPI_SR_RXBUFF_Msk & (_UINT32_(value) << FLEX_SPI_SR_RXBUFF_Pos)) /* Assigment of value for RXBUFF in the FLEX_SPI_SR register */
#define FLEX_SPI_SR_TXBUFE_Pos                _UINT32_(7)                                          /* (FLEX_SPI_SR) TX Buffer Empty (cleared by writing FLEX_SPI_TCR or FLEX_SPI_TNCR) Position */
#define FLEX_SPI_SR_TXBUFE_Msk                (_UINT32_(0x1) << FLEX_SPI_SR_TXBUFE_Pos)            /* (FLEX_SPI_SR) TX Buffer Empty (cleared by writing FLEX_SPI_TCR or FLEX_SPI_TNCR) Mask */
#define FLEX_SPI_SR_TXBUFE(value)             (FLEX_SPI_SR_TXBUFE_Msk & (_UINT32_(value) << FLEX_SPI_SR_TXBUFE_Pos)) /* Assigment of value for TXBUFE in the FLEX_SPI_SR register */
#define FLEX_SPI_SR_NSSR_Pos                  _UINT32_(8)                                          /* (FLEX_SPI_SR) NSS Rising (cleared on read) Position */
#define FLEX_SPI_SR_NSSR_Msk                  (_UINT32_(0x1) << FLEX_SPI_SR_NSSR_Pos)              /* (FLEX_SPI_SR) NSS Rising (cleared on read) Mask */
#define FLEX_SPI_SR_NSSR(value)               (FLEX_SPI_SR_NSSR_Msk & (_UINT32_(value) << FLEX_SPI_SR_NSSR_Pos)) /* Assigment of value for NSSR in the FLEX_SPI_SR register */
#define FLEX_SPI_SR_TXEMPTY_Pos               _UINT32_(9)                                          /* (FLEX_SPI_SR) Transmission Registers Empty (cleared by writing FLEX_SPI_TDR) Position */
#define FLEX_SPI_SR_TXEMPTY_Msk               (_UINT32_(0x1) << FLEX_SPI_SR_TXEMPTY_Pos)           /* (FLEX_SPI_SR) Transmission Registers Empty (cleared by writing FLEX_SPI_TDR) Mask */
#define FLEX_SPI_SR_TXEMPTY(value)            (FLEX_SPI_SR_TXEMPTY_Msk & (_UINT32_(value) << FLEX_SPI_SR_TXEMPTY_Pos)) /* Assigment of value for TXEMPTY in the FLEX_SPI_SR register */
#define FLEX_SPI_SR_UNDES_Pos                 _UINT32_(10)                                         /* (FLEX_SPI_SR) Underrun Error Status (Client mode only) (cleared on read) Position */
#define FLEX_SPI_SR_UNDES_Msk                 (_UINT32_(0x1) << FLEX_SPI_SR_UNDES_Pos)             /* (FLEX_SPI_SR) Underrun Error Status (Client mode only) (cleared on read) Mask */
#define FLEX_SPI_SR_UNDES(value)              (FLEX_SPI_SR_UNDES_Msk & (_UINT32_(value) << FLEX_SPI_SR_UNDES_Pos)) /* Assigment of value for UNDES in the FLEX_SPI_SR register */
#define FLEX_SPI_SR_CMP_Pos                   _UINT32_(11)                                         /* (FLEX_SPI_SR) Comparison Status (cleared on read) Position */
#define FLEX_SPI_SR_CMP_Msk                   (_UINT32_(0x1) << FLEX_SPI_SR_CMP_Pos)               /* (FLEX_SPI_SR) Comparison Status (cleared on read) Mask */
#define FLEX_SPI_SR_CMP(value)                (FLEX_SPI_SR_CMP_Msk & (_UINT32_(value) << FLEX_SPI_SR_CMP_Pos)) /* Assigment of value for CMP in the FLEX_SPI_SR register */
#define FLEX_SPI_SR_SFERR_Pos                 _UINT32_(12)                                         /* (FLEX_SPI_SR) Client Mode Frame Error (cleared on read) Position */
#define FLEX_SPI_SR_SFERR_Msk                 (_UINT32_(0x1) << FLEX_SPI_SR_SFERR_Pos)             /* (FLEX_SPI_SR) Client Mode Frame Error (cleared on read) Mask */
#define FLEX_SPI_SR_SFERR(value)              (FLEX_SPI_SR_SFERR_Msk & (_UINT32_(value) << FLEX_SPI_SR_SFERR_Pos)) /* Assigment of value for SFERR in the FLEX_SPI_SR register */
#define FLEX_SPI_SR_SPIENS_Pos                _UINT32_(16)                                         /* (FLEX_SPI_SR) SPI Enable Status Position */
#define FLEX_SPI_SR_SPIENS_Msk                (_UINT32_(0x1) << FLEX_SPI_SR_SPIENS_Pos)            /* (FLEX_SPI_SR) SPI Enable Status Mask */
#define FLEX_SPI_SR_SPIENS(value)             (FLEX_SPI_SR_SPIENS_Msk & (_UINT32_(value) << FLEX_SPI_SR_SPIENS_Pos)) /* Assigment of value for SPIENS in the FLEX_SPI_SR register */
#define FLEX_SPI_SR_TXFEF_Pos                 _UINT32_(24)                                         /* (FLEX_SPI_SR) Transmit FIFO Empty Flag (cleared on read) Position */
#define FLEX_SPI_SR_TXFEF_Msk                 (_UINT32_(0x1) << FLEX_SPI_SR_TXFEF_Pos)             /* (FLEX_SPI_SR) Transmit FIFO Empty Flag (cleared on read) Mask */
#define FLEX_SPI_SR_TXFEF(value)              (FLEX_SPI_SR_TXFEF_Msk & (_UINT32_(value) << FLEX_SPI_SR_TXFEF_Pos)) /* Assigment of value for TXFEF in the FLEX_SPI_SR register */
#define FLEX_SPI_SR_TXFFF_Pos                 _UINT32_(25)                                         /* (FLEX_SPI_SR) Transmit FIFO Full Flag (cleared on read) Position */
#define FLEX_SPI_SR_TXFFF_Msk                 (_UINT32_(0x1) << FLEX_SPI_SR_TXFFF_Pos)             /* (FLEX_SPI_SR) Transmit FIFO Full Flag (cleared on read) Mask */
#define FLEX_SPI_SR_TXFFF(value)              (FLEX_SPI_SR_TXFFF_Msk & (_UINT32_(value) << FLEX_SPI_SR_TXFFF_Pos)) /* Assigment of value for TXFFF in the FLEX_SPI_SR register */
#define FLEX_SPI_SR_TXFTHF_Pos                _UINT32_(26)                                         /* (FLEX_SPI_SR) Transmit FIFO Threshold Flag (cleared on read) Position */
#define FLEX_SPI_SR_TXFTHF_Msk                (_UINT32_(0x1) << FLEX_SPI_SR_TXFTHF_Pos)            /* (FLEX_SPI_SR) Transmit FIFO Threshold Flag (cleared on read) Mask */
#define FLEX_SPI_SR_TXFTHF(value)             (FLEX_SPI_SR_TXFTHF_Msk & (_UINT32_(value) << FLEX_SPI_SR_TXFTHF_Pos)) /* Assigment of value for TXFTHF in the FLEX_SPI_SR register */
#define FLEX_SPI_SR_RXFEF_Pos                 _UINT32_(27)                                         /* (FLEX_SPI_SR) Receive FIFO Empty Flag Position */
#define FLEX_SPI_SR_RXFEF_Msk                 (_UINT32_(0x1) << FLEX_SPI_SR_RXFEF_Pos)             /* (FLEX_SPI_SR) Receive FIFO Empty Flag Mask */
#define FLEX_SPI_SR_RXFEF(value)              (FLEX_SPI_SR_RXFEF_Msk & (_UINT32_(value) << FLEX_SPI_SR_RXFEF_Pos)) /* Assigment of value for RXFEF in the FLEX_SPI_SR register */
#define FLEX_SPI_SR_RXFFF_Pos                 _UINT32_(28)                                         /* (FLEX_SPI_SR) Receive FIFO Full Flag Position */
#define FLEX_SPI_SR_RXFFF_Msk                 (_UINT32_(0x1) << FLEX_SPI_SR_RXFFF_Pos)             /* (FLEX_SPI_SR) Receive FIFO Full Flag Mask */
#define FLEX_SPI_SR_RXFFF(value)              (FLEX_SPI_SR_RXFFF_Msk & (_UINT32_(value) << FLEX_SPI_SR_RXFFF_Pos)) /* Assigment of value for RXFFF in the FLEX_SPI_SR register */
#define FLEX_SPI_SR_RXFTHF_Pos                _UINT32_(29)                                         /* (FLEX_SPI_SR) Receive FIFO Threshold Flag Position */
#define FLEX_SPI_SR_RXFTHF_Msk                (_UINT32_(0x1) << FLEX_SPI_SR_RXFTHF_Pos)            /* (FLEX_SPI_SR) Receive FIFO Threshold Flag Mask */
#define FLEX_SPI_SR_RXFTHF(value)             (FLEX_SPI_SR_RXFTHF_Msk & (_UINT32_(value) << FLEX_SPI_SR_RXFTHF_Pos)) /* Assigment of value for RXFTHF in the FLEX_SPI_SR register */
#define FLEX_SPI_SR_TXFPTEF_Pos               _UINT32_(30)                                         /* (FLEX_SPI_SR) Transmit FIFO Pointer Error Flag Position */
#define FLEX_SPI_SR_TXFPTEF_Msk               (_UINT32_(0x1) << FLEX_SPI_SR_TXFPTEF_Pos)           /* (FLEX_SPI_SR) Transmit FIFO Pointer Error Flag Mask */
#define FLEX_SPI_SR_TXFPTEF(value)            (FLEX_SPI_SR_TXFPTEF_Msk & (_UINT32_(value) << FLEX_SPI_SR_TXFPTEF_Pos)) /* Assigment of value for TXFPTEF in the FLEX_SPI_SR register */
#define FLEX_SPI_SR_RXFPTEF_Pos               _UINT32_(31)                                         /* (FLEX_SPI_SR) Receive FIFO Pointer Error Flag Position */
#define FLEX_SPI_SR_RXFPTEF_Msk               (_UINT32_(0x1) << FLEX_SPI_SR_RXFPTEF_Pos)           /* (FLEX_SPI_SR) Receive FIFO Pointer Error Flag Mask */
#define FLEX_SPI_SR_RXFPTEF(value)            (FLEX_SPI_SR_RXFPTEF_Msk & (_UINT32_(value) << FLEX_SPI_SR_RXFPTEF_Pos)) /* Assigment of value for RXFPTEF in the FLEX_SPI_SR register */
#define FLEX_SPI_SR_Msk                       _UINT32_(0xFF011FFF)                                 /* (FLEX_SPI_SR) Register Mask  */


/* -------- FLEX_SPI_IER : (FLEXCOM Offset: 0x414) ( /W 32) SPI Interrupt Enable Register -------- */
#define FLEX_SPI_IER_RDRF_Pos                 _UINT32_(0)                                          /* (FLEX_SPI_IER) Receive Data Register Full Interrupt Enable Position */
#define FLEX_SPI_IER_RDRF_Msk                 (_UINT32_(0x1) << FLEX_SPI_IER_RDRF_Pos)             /* (FLEX_SPI_IER) Receive Data Register Full Interrupt Enable Mask */
#define FLEX_SPI_IER_RDRF(value)              (FLEX_SPI_IER_RDRF_Msk & (_UINT32_(value) << FLEX_SPI_IER_RDRF_Pos)) /* Assigment of value for RDRF in the FLEX_SPI_IER register */
#define FLEX_SPI_IER_TDRE_Pos                 _UINT32_(1)                                          /* (FLEX_SPI_IER) SPI Transmit Data Register Empty Interrupt Enable Position */
#define FLEX_SPI_IER_TDRE_Msk                 (_UINT32_(0x1) << FLEX_SPI_IER_TDRE_Pos)             /* (FLEX_SPI_IER) SPI Transmit Data Register Empty Interrupt Enable Mask */
#define FLEX_SPI_IER_TDRE(value)              (FLEX_SPI_IER_TDRE_Msk & (_UINT32_(value) << FLEX_SPI_IER_TDRE_Pos)) /* Assigment of value for TDRE in the FLEX_SPI_IER register */
#define FLEX_SPI_IER_MODF_Pos                 _UINT32_(2)                                          /* (FLEX_SPI_IER) Mode Fault Error Interrupt Enable Position */
#define FLEX_SPI_IER_MODF_Msk                 (_UINT32_(0x1) << FLEX_SPI_IER_MODF_Pos)             /* (FLEX_SPI_IER) Mode Fault Error Interrupt Enable Mask */
#define FLEX_SPI_IER_MODF(value)              (FLEX_SPI_IER_MODF_Msk & (_UINT32_(value) << FLEX_SPI_IER_MODF_Pos)) /* Assigment of value for MODF in the FLEX_SPI_IER register */
#define FLEX_SPI_IER_OVRES_Pos                _UINT32_(3)                                          /* (FLEX_SPI_IER) Overrun Error Interrupt Enable Position */
#define FLEX_SPI_IER_OVRES_Msk                (_UINT32_(0x1) << FLEX_SPI_IER_OVRES_Pos)            /* (FLEX_SPI_IER) Overrun Error Interrupt Enable Mask */
#define FLEX_SPI_IER_OVRES(value)             (FLEX_SPI_IER_OVRES_Msk & (_UINT32_(value) << FLEX_SPI_IER_OVRES_Pos)) /* Assigment of value for OVRES in the FLEX_SPI_IER register */
#define FLEX_SPI_IER_ENDRX_Pos                _UINT32_(4)                                          /* (FLEX_SPI_IER) End of Receive Buffer Interrupt Enable Position */
#define FLEX_SPI_IER_ENDRX_Msk                (_UINT32_(0x1) << FLEX_SPI_IER_ENDRX_Pos)            /* (FLEX_SPI_IER) End of Receive Buffer Interrupt Enable Mask */
#define FLEX_SPI_IER_ENDRX(value)             (FLEX_SPI_IER_ENDRX_Msk & (_UINT32_(value) << FLEX_SPI_IER_ENDRX_Pos)) /* Assigment of value for ENDRX in the FLEX_SPI_IER register */
#define FLEX_SPI_IER_ENDTX_Pos                _UINT32_(5)                                          /* (FLEX_SPI_IER) End of Transmit Buffer Interrupt Enable Position */
#define FLEX_SPI_IER_ENDTX_Msk                (_UINT32_(0x1) << FLEX_SPI_IER_ENDTX_Pos)            /* (FLEX_SPI_IER) End of Transmit Buffer Interrupt Enable Mask */
#define FLEX_SPI_IER_ENDTX(value)             (FLEX_SPI_IER_ENDTX_Msk & (_UINT32_(value) << FLEX_SPI_IER_ENDTX_Pos)) /* Assigment of value for ENDTX in the FLEX_SPI_IER register */
#define FLEX_SPI_IER_RXBUFF_Pos               _UINT32_(6)                                          /* (FLEX_SPI_IER) Receive Buffer Full Interrupt Enable Position */
#define FLEX_SPI_IER_RXBUFF_Msk               (_UINT32_(0x1) << FLEX_SPI_IER_RXBUFF_Pos)           /* (FLEX_SPI_IER) Receive Buffer Full Interrupt Enable Mask */
#define FLEX_SPI_IER_RXBUFF(value)            (FLEX_SPI_IER_RXBUFF_Msk & (_UINT32_(value) << FLEX_SPI_IER_RXBUFF_Pos)) /* Assigment of value for RXBUFF in the FLEX_SPI_IER register */
#define FLEX_SPI_IER_TXBUFE_Pos               _UINT32_(7)                                          /* (FLEX_SPI_IER) Transmit Buffer Empty Interrupt Enable Position */
#define FLEX_SPI_IER_TXBUFE_Msk               (_UINT32_(0x1) << FLEX_SPI_IER_TXBUFE_Pos)           /* (FLEX_SPI_IER) Transmit Buffer Empty Interrupt Enable Mask */
#define FLEX_SPI_IER_TXBUFE(value)            (FLEX_SPI_IER_TXBUFE_Msk & (_UINT32_(value) << FLEX_SPI_IER_TXBUFE_Pos)) /* Assigment of value for TXBUFE in the FLEX_SPI_IER register */
#define FLEX_SPI_IER_NSSR_Pos                 _UINT32_(8)                                          /* (FLEX_SPI_IER) NSS Rising Interrupt Enable Position */
#define FLEX_SPI_IER_NSSR_Msk                 (_UINT32_(0x1) << FLEX_SPI_IER_NSSR_Pos)             /* (FLEX_SPI_IER) NSS Rising Interrupt Enable Mask */
#define FLEX_SPI_IER_NSSR(value)              (FLEX_SPI_IER_NSSR_Msk & (_UINT32_(value) << FLEX_SPI_IER_NSSR_Pos)) /* Assigment of value for NSSR in the FLEX_SPI_IER register */
#define FLEX_SPI_IER_TXEMPTY_Pos              _UINT32_(9)                                          /* (FLEX_SPI_IER) Transmission Registers Empty Enable Position */
#define FLEX_SPI_IER_TXEMPTY_Msk              (_UINT32_(0x1) << FLEX_SPI_IER_TXEMPTY_Pos)          /* (FLEX_SPI_IER) Transmission Registers Empty Enable Mask */
#define FLEX_SPI_IER_TXEMPTY(value)           (FLEX_SPI_IER_TXEMPTY_Msk & (_UINT32_(value) << FLEX_SPI_IER_TXEMPTY_Pos)) /* Assigment of value for TXEMPTY in the FLEX_SPI_IER register */
#define FLEX_SPI_IER_UNDES_Pos                _UINT32_(10)                                         /* (FLEX_SPI_IER) Underrun Error Interrupt Enable Position */
#define FLEX_SPI_IER_UNDES_Msk                (_UINT32_(0x1) << FLEX_SPI_IER_UNDES_Pos)            /* (FLEX_SPI_IER) Underrun Error Interrupt Enable Mask */
#define FLEX_SPI_IER_UNDES(value)             (FLEX_SPI_IER_UNDES_Msk & (_UINT32_(value) << FLEX_SPI_IER_UNDES_Pos)) /* Assigment of value for UNDES in the FLEX_SPI_IER register */
#define FLEX_SPI_IER_CMP_Pos                  _UINT32_(11)                                         /* (FLEX_SPI_IER) Comparison Interrupt Enable Position */
#define FLEX_SPI_IER_CMP_Msk                  (_UINT32_(0x1) << FLEX_SPI_IER_CMP_Pos)              /* (FLEX_SPI_IER) Comparison Interrupt Enable Mask */
#define FLEX_SPI_IER_CMP(value)               (FLEX_SPI_IER_CMP_Msk & (_UINT32_(value) << FLEX_SPI_IER_CMP_Pos)) /* Assigment of value for CMP in the FLEX_SPI_IER register */
#define FLEX_SPI_IER_SFERR_Pos                _UINT32_(12)                                         /* (FLEX_SPI_IER) Client Mode Frame Error Interrupt Enable Position */
#define FLEX_SPI_IER_SFERR_Msk                (_UINT32_(0x1) << FLEX_SPI_IER_SFERR_Pos)            /* (FLEX_SPI_IER) Client Mode Frame Error Interrupt Enable Mask */
#define FLEX_SPI_IER_SFERR(value)             (FLEX_SPI_IER_SFERR_Msk & (_UINT32_(value) << FLEX_SPI_IER_SFERR_Pos)) /* Assigment of value for SFERR in the FLEX_SPI_IER register */
#define FLEX_SPI_IER_TXFEF_Pos                _UINT32_(24)                                         /* (FLEX_SPI_IER) TXFEF Interrupt Enable Position */
#define FLEX_SPI_IER_TXFEF_Msk                (_UINT32_(0x1) << FLEX_SPI_IER_TXFEF_Pos)            /* (FLEX_SPI_IER) TXFEF Interrupt Enable Mask */
#define FLEX_SPI_IER_TXFEF(value)             (FLEX_SPI_IER_TXFEF_Msk & (_UINT32_(value) << FLEX_SPI_IER_TXFEF_Pos)) /* Assigment of value for TXFEF in the FLEX_SPI_IER register */
#define FLEX_SPI_IER_TXFFF_Pos                _UINT32_(25)                                         /* (FLEX_SPI_IER) TXFFF Interrupt Enable Position */
#define FLEX_SPI_IER_TXFFF_Msk                (_UINT32_(0x1) << FLEX_SPI_IER_TXFFF_Pos)            /* (FLEX_SPI_IER) TXFFF Interrupt Enable Mask */
#define FLEX_SPI_IER_TXFFF(value)             (FLEX_SPI_IER_TXFFF_Msk & (_UINT32_(value) << FLEX_SPI_IER_TXFFF_Pos)) /* Assigment of value for TXFFF in the FLEX_SPI_IER register */
#define FLEX_SPI_IER_TXFTHF_Pos               _UINT32_(26)                                         /* (FLEX_SPI_IER) TXFTHF Interrupt Enable Position */
#define FLEX_SPI_IER_TXFTHF_Msk               (_UINT32_(0x1) << FLEX_SPI_IER_TXFTHF_Pos)           /* (FLEX_SPI_IER) TXFTHF Interrupt Enable Mask */
#define FLEX_SPI_IER_TXFTHF(value)            (FLEX_SPI_IER_TXFTHF_Msk & (_UINT32_(value) << FLEX_SPI_IER_TXFTHF_Pos)) /* Assigment of value for TXFTHF in the FLEX_SPI_IER register */
#define FLEX_SPI_IER_RXFEF_Pos                _UINT32_(27)                                         /* (FLEX_SPI_IER) RXFEF Interrupt Enable Position */
#define FLEX_SPI_IER_RXFEF_Msk                (_UINT32_(0x1) << FLEX_SPI_IER_RXFEF_Pos)            /* (FLEX_SPI_IER) RXFEF Interrupt Enable Mask */
#define FLEX_SPI_IER_RXFEF(value)             (FLEX_SPI_IER_RXFEF_Msk & (_UINT32_(value) << FLEX_SPI_IER_RXFEF_Pos)) /* Assigment of value for RXFEF in the FLEX_SPI_IER register */
#define FLEX_SPI_IER_RXFFF_Pos                _UINT32_(28)                                         /* (FLEX_SPI_IER) RXFFF Interrupt Enable Position */
#define FLEX_SPI_IER_RXFFF_Msk                (_UINT32_(0x1) << FLEX_SPI_IER_RXFFF_Pos)            /* (FLEX_SPI_IER) RXFFF Interrupt Enable Mask */
#define FLEX_SPI_IER_RXFFF(value)             (FLEX_SPI_IER_RXFFF_Msk & (_UINT32_(value) << FLEX_SPI_IER_RXFFF_Pos)) /* Assigment of value for RXFFF in the FLEX_SPI_IER register */
#define FLEX_SPI_IER_RXFTHF_Pos               _UINT32_(29)                                         /* (FLEX_SPI_IER) RXFTHF Interrupt Enable Position */
#define FLEX_SPI_IER_RXFTHF_Msk               (_UINT32_(0x1) << FLEX_SPI_IER_RXFTHF_Pos)           /* (FLEX_SPI_IER) RXFTHF Interrupt Enable Mask */
#define FLEX_SPI_IER_RXFTHF(value)            (FLEX_SPI_IER_RXFTHF_Msk & (_UINT32_(value) << FLEX_SPI_IER_RXFTHF_Pos)) /* Assigment of value for RXFTHF in the FLEX_SPI_IER register */
#define FLEX_SPI_IER_TXFPTEF_Pos              _UINT32_(30)                                         /* (FLEX_SPI_IER) TXFPTEF Interrupt Enable Position */
#define FLEX_SPI_IER_TXFPTEF_Msk              (_UINT32_(0x1) << FLEX_SPI_IER_TXFPTEF_Pos)          /* (FLEX_SPI_IER) TXFPTEF Interrupt Enable Mask */
#define FLEX_SPI_IER_TXFPTEF(value)           (FLEX_SPI_IER_TXFPTEF_Msk & (_UINT32_(value) << FLEX_SPI_IER_TXFPTEF_Pos)) /* Assigment of value for TXFPTEF in the FLEX_SPI_IER register */
#define FLEX_SPI_IER_RXFPTEF_Pos              _UINT32_(31)                                         /* (FLEX_SPI_IER) RXFPTEF Interrupt Enable Position */
#define FLEX_SPI_IER_RXFPTEF_Msk              (_UINT32_(0x1) << FLEX_SPI_IER_RXFPTEF_Pos)          /* (FLEX_SPI_IER) RXFPTEF Interrupt Enable Mask */
#define FLEX_SPI_IER_RXFPTEF(value)           (FLEX_SPI_IER_RXFPTEF_Msk & (_UINT32_(value) << FLEX_SPI_IER_RXFPTEF_Pos)) /* Assigment of value for RXFPTEF in the FLEX_SPI_IER register */
#define FLEX_SPI_IER_Msk                      _UINT32_(0xFF001FFF)                                 /* (FLEX_SPI_IER) Register Mask  */


/* -------- FLEX_SPI_IDR : (FLEXCOM Offset: 0x418) ( /W 32) SPI Interrupt Disable Register -------- */
#define FLEX_SPI_IDR_RDRF_Pos                 _UINT32_(0)                                          /* (FLEX_SPI_IDR) Receive Data Register Full Interrupt Disable Position */
#define FLEX_SPI_IDR_RDRF_Msk                 (_UINT32_(0x1) << FLEX_SPI_IDR_RDRF_Pos)             /* (FLEX_SPI_IDR) Receive Data Register Full Interrupt Disable Mask */
#define FLEX_SPI_IDR_RDRF(value)              (FLEX_SPI_IDR_RDRF_Msk & (_UINT32_(value) << FLEX_SPI_IDR_RDRF_Pos)) /* Assigment of value for RDRF in the FLEX_SPI_IDR register */
#define FLEX_SPI_IDR_TDRE_Pos                 _UINT32_(1)                                          /* (FLEX_SPI_IDR) SPI Transmit Data Register Empty Interrupt Disable Position */
#define FLEX_SPI_IDR_TDRE_Msk                 (_UINT32_(0x1) << FLEX_SPI_IDR_TDRE_Pos)             /* (FLEX_SPI_IDR) SPI Transmit Data Register Empty Interrupt Disable Mask */
#define FLEX_SPI_IDR_TDRE(value)              (FLEX_SPI_IDR_TDRE_Msk & (_UINT32_(value) << FLEX_SPI_IDR_TDRE_Pos)) /* Assigment of value for TDRE in the FLEX_SPI_IDR register */
#define FLEX_SPI_IDR_MODF_Pos                 _UINT32_(2)                                          /* (FLEX_SPI_IDR) Mode Fault Error Interrupt Disable Position */
#define FLEX_SPI_IDR_MODF_Msk                 (_UINT32_(0x1) << FLEX_SPI_IDR_MODF_Pos)             /* (FLEX_SPI_IDR) Mode Fault Error Interrupt Disable Mask */
#define FLEX_SPI_IDR_MODF(value)              (FLEX_SPI_IDR_MODF_Msk & (_UINT32_(value) << FLEX_SPI_IDR_MODF_Pos)) /* Assigment of value for MODF in the FLEX_SPI_IDR register */
#define FLEX_SPI_IDR_OVRES_Pos                _UINT32_(3)                                          /* (FLEX_SPI_IDR) Overrun Error Interrupt Disable Position */
#define FLEX_SPI_IDR_OVRES_Msk                (_UINT32_(0x1) << FLEX_SPI_IDR_OVRES_Pos)            /* (FLEX_SPI_IDR) Overrun Error Interrupt Disable Mask */
#define FLEX_SPI_IDR_OVRES(value)             (FLEX_SPI_IDR_OVRES_Msk & (_UINT32_(value) << FLEX_SPI_IDR_OVRES_Pos)) /* Assigment of value for OVRES in the FLEX_SPI_IDR register */
#define FLEX_SPI_IDR_ENDRX_Pos                _UINT32_(4)                                          /* (FLEX_SPI_IDR) End of Receive Buffer Interrupt Disable Position */
#define FLEX_SPI_IDR_ENDRX_Msk                (_UINT32_(0x1) << FLEX_SPI_IDR_ENDRX_Pos)            /* (FLEX_SPI_IDR) End of Receive Buffer Interrupt Disable Mask */
#define FLEX_SPI_IDR_ENDRX(value)             (FLEX_SPI_IDR_ENDRX_Msk & (_UINT32_(value) << FLEX_SPI_IDR_ENDRX_Pos)) /* Assigment of value for ENDRX in the FLEX_SPI_IDR register */
#define FLEX_SPI_IDR_ENDTX_Pos                _UINT32_(5)                                          /* (FLEX_SPI_IDR) End of Transmit Buffer Interrupt Disable Position */
#define FLEX_SPI_IDR_ENDTX_Msk                (_UINT32_(0x1) << FLEX_SPI_IDR_ENDTX_Pos)            /* (FLEX_SPI_IDR) End of Transmit Buffer Interrupt Disable Mask */
#define FLEX_SPI_IDR_ENDTX(value)             (FLEX_SPI_IDR_ENDTX_Msk & (_UINT32_(value) << FLEX_SPI_IDR_ENDTX_Pos)) /* Assigment of value for ENDTX in the FLEX_SPI_IDR register */
#define FLEX_SPI_IDR_RXBUFF_Pos               _UINT32_(6)                                          /* (FLEX_SPI_IDR) Receive Buffer Full Interrupt Disable Position */
#define FLEX_SPI_IDR_RXBUFF_Msk               (_UINT32_(0x1) << FLEX_SPI_IDR_RXBUFF_Pos)           /* (FLEX_SPI_IDR) Receive Buffer Full Interrupt Disable Mask */
#define FLEX_SPI_IDR_RXBUFF(value)            (FLEX_SPI_IDR_RXBUFF_Msk & (_UINT32_(value) << FLEX_SPI_IDR_RXBUFF_Pos)) /* Assigment of value for RXBUFF in the FLEX_SPI_IDR register */
#define FLEX_SPI_IDR_TXBUFE_Pos               _UINT32_(7)                                          /* (FLEX_SPI_IDR) Transmit Buffer Empty Interrupt Disable Position */
#define FLEX_SPI_IDR_TXBUFE_Msk               (_UINT32_(0x1) << FLEX_SPI_IDR_TXBUFE_Pos)           /* (FLEX_SPI_IDR) Transmit Buffer Empty Interrupt Disable Mask */
#define FLEX_SPI_IDR_TXBUFE(value)            (FLEX_SPI_IDR_TXBUFE_Msk & (_UINT32_(value) << FLEX_SPI_IDR_TXBUFE_Pos)) /* Assigment of value for TXBUFE in the FLEX_SPI_IDR register */
#define FLEX_SPI_IDR_NSSR_Pos                 _UINT32_(8)                                          /* (FLEX_SPI_IDR) NSS Rising Interrupt Disable Position */
#define FLEX_SPI_IDR_NSSR_Msk                 (_UINT32_(0x1) << FLEX_SPI_IDR_NSSR_Pos)             /* (FLEX_SPI_IDR) NSS Rising Interrupt Disable Mask */
#define FLEX_SPI_IDR_NSSR(value)              (FLEX_SPI_IDR_NSSR_Msk & (_UINT32_(value) << FLEX_SPI_IDR_NSSR_Pos)) /* Assigment of value for NSSR in the FLEX_SPI_IDR register */
#define FLEX_SPI_IDR_TXEMPTY_Pos              _UINT32_(9)                                          /* (FLEX_SPI_IDR) Transmission Registers Empty Disable Position */
#define FLEX_SPI_IDR_TXEMPTY_Msk              (_UINT32_(0x1) << FLEX_SPI_IDR_TXEMPTY_Pos)          /* (FLEX_SPI_IDR) Transmission Registers Empty Disable Mask */
#define FLEX_SPI_IDR_TXEMPTY(value)           (FLEX_SPI_IDR_TXEMPTY_Msk & (_UINT32_(value) << FLEX_SPI_IDR_TXEMPTY_Pos)) /* Assigment of value for TXEMPTY in the FLEX_SPI_IDR register */
#define FLEX_SPI_IDR_UNDES_Pos                _UINT32_(10)                                         /* (FLEX_SPI_IDR) Underrun Error Interrupt Disable Position */
#define FLEX_SPI_IDR_UNDES_Msk                (_UINT32_(0x1) << FLEX_SPI_IDR_UNDES_Pos)            /* (FLEX_SPI_IDR) Underrun Error Interrupt Disable Mask */
#define FLEX_SPI_IDR_UNDES(value)             (FLEX_SPI_IDR_UNDES_Msk & (_UINT32_(value) << FLEX_SPI_IDR_UNDES_Pos)) /* Assigment of value for UNDES in the FLEX_SPI_IDR register */
#define FLEX_SPI_IDR_CMP_Pos                  _UINT32_(11)                                         /* (FLEX_SPI_IDR) Comparison Interrupt Disable Position */
#define FLEX_SPI_IDR_CMP_Msk                  (_UINT32_(0x1) << FLEX_SPI_IDR_CMP_Pos)              /* (FLEX_SPI_IDR) Comparison Interrupt Disable Mask */
#define FLEX_SPI_IDR_CMP(value)               (FLEX_SPI_IDR_CMP_Msk & (_UINT32_(value) << FLEX_SPI_IDR_CMP_Pos)) /* Assigment of value for CMP in the FLEX_SPI_IDR register */
#define FLEX_SPI_IDR_SFERR_Pos                _UINT32_(12)                                         /* (FLEX_SPI_IDR) Client Mode Frame Error Interrupt Disable Position */
#define FLEX_SPI_IDR_SFERR_Msk                (_UINT32_(0x1) << FLEX_SPI_IDR_SFERR_Pos)            /* (FLEX_SPI_IDR) Client Mode Frame Error Interrupt Disable Mask */
#define FLEX_SPI_IDR_SFERR(value)             (FLEX_SPI_IDR_SFERR_Msk & (_UINT32_(value) << FLEX_SPI_IDR_SFERR_Pos)) /* Assigment of value for SFERR in the FLEX_SPI_IDR register */
#define FLEX_SPI_IDR_TXFEF_Pos                _UINT32_(24)                                         /* (FLEX_SPI_IDR) TXFEF Interrupt Disable Position */
#define FLEX_SPI_IDR_TXFEF_Msk                (_UINT32_(0x1) << FLEX_SPI_IDR_TXFEF_Pos)            /* (FLEX_SPI_IDR) TXFEF Interrupt Disable Mask */
#define FLEX_SPI_IDR_TXFEF(value)             (FLEX_SPI_IDR_TXFEF_Msk & (_UINT32_(value) << FLEX_SPI_IDR_TXFEF_Pos)) /* Assigment of value for TXFEF in the FLEX_SPI_IDR register */
#define FLEX_SPI_IDR_TXFFF_Pos                _UINT32_(25)                                         /* (FLEX_SPI_IDR) TXFFF Interrupt Disable Position */
#define FLEX_SPI_IDR_TXFFF_Msk                (_UINT32_(0x1) << FLEX_SPI_IDR_TXFFF_Pos)            /* (FLEX_SPI_IDR) TXFFF Interrupt Disable Mask */
#define FLEX_SPI_IDR_TXFFF(value)             (FLEX_SPI_IDR_TXFFF_Msk & (_UINT32_(value) << FLEX_SPI_IDR_TXFFF_Pos)) /* Assigment of value for TXFFF in the FLEX_SPI_IDR register */
#define FLEX_SPI_IDR_TXFTHF_Pos               _UINT32_(26)                                         /* (FLEX_SPI_IDR) TXFTHF Interrupt Disable Position */
#define FLEX_SPI_IDR_TXFTHF_Msk               (_UINT32_(0x1) << FLEX_SPI_IDR_TXFTHF_Pos)           /* (FLEX_SPI_IDR) TXFTHF Interrupt Disable Mask */
#define FLEX_SPI_IDR_TXFTHF(value)            (FLEX_SPI_IDR_TXFTHF_Msk & (_UINT32_(value) << FLEX_SPI_IDR_TXFTHF_Pos)) /* Assigment of value for TXFTHF in the FLEX_SPI_IDR register */
#define FLEX_SPI_IDR_RXFEF_Pos                _UINT32_(27)                                         /* (FLEX_SPI_IDR) RXFEF Interrupt Disable Position */
#define FLEX_SPI_IDR_RXFEF_Msk                (_UINT32_(0x1) << FLEX_SPI_IDR_RXFEF_Pos)            /* (FLEX_SPI_IDR) RXFEF Interrupt Disable Mask */
#define FLEX_SPI_IDR_RXFEF(value)             (FLEX_SPI_IDR_RXFEF_Msk & (_UINT32_(value) << FLEX_SPI_IDR_RXFEF_Pos)) /* Assigment of value for RXFEF in the FLEX_SPI_IDR register */
#define FLEX_SPI_IDR_RXFFF_Pos                _UINT32_(28)                                         /* (FLEX_SPI_IDR) RXFFF Interrupt Disable Position */
#define FLEX_SPI_IDR_RXFFF_Msk                (_UINT32_(0x1) << FLEX_SPI_IDR_RXFFF_Pos)            /* (FLEX_SPI_IDR) RXFFF Interrupt Disable Mask */
#define FLEX_SPI_IDR_RXFFF(value)             (FLEX_SPI_IDR_RXFFF_Msk & (_UINT32_(value) << FLEX_SPI_IDR_RXFFF_Pos)) /* Assigment of value for RXFFF in the FLEX_SPI_IDR register */
#define FLEX_SPI_IDR_RXFTHF_Pos               _UINT32_(29)                                         /* (FLEX_SPI_IDR) RXFTHF Interrupt Disable Position */
#define FLEX_SPI_IDR_RXFTHF_Msk               (_UINT32_(0x1) << FLEX_SPI_IDR_RXFTHF_Pos)           /* (FLEX_SPI_IDR) RXFTHF Interrupt Disable Mask */
#define FLEX_SPI_IDR_RXFTHF(value)            (FLEX_SPI_IDR_RXFTHF_Msk & (_UINT32_(value) << FLEX_SPI_IDR_RXFTHF_Pos)) /* Assigment of value for RXFTHF in the FLEX_SPI_IDR register */
#define FLEX_SPI_IDR_TXFPTEF_Pos              _UINT32_(30)                                         /* (FLEX_SPI_IDR) TXFPTEF Interrupt Disable Position */
#define FLEX_SPI_IDR_TXFPTEF_Msk              (_UINT32_(0x1) << FLEX_SPI_IDR_TXFPTEF_Pos)          /* (FLEX_SPI_IDR) TXFPTEF Interrupt Disable Mask */
#define FLEX_SPI_IDR_TXFPTEF(value)           (FLEX_SPI_IDR_TXFPTEF_Msk & (_UINT32_(value) << FLEX_SPI_IDR_TXFPTEF_Pos)) /* Assigment of value for TXFPTEF in the FLEX_SPI_IDR register */
#define FLEX_SPI_IDR_RXFPTEF_Pos              _UINT32_(31)                                         /* (FLEX_SPI_IDR) RXFPTEF Interrupt Disable Position */
#define FLEX_SPI_IDR_RXFPTEF_Msk              (_UINT32_(0x1) << FLEX_SPI_IDR_RXFPTEF_Pos)          /* (FLEX_SPI_IDR) RXFPTEF Interrupt Disable Mask */
#define FLEX_SPI_IDR_RXFPTEF(value)           (FLEX_SPI_IDR_RXFPTEF_Msk & (_UINT32_(value) << FLEX_SPI_IDR_RXFPTEF_Pos)) /* Assigment of value for RXFPTEF in the FLEX_SPI_IDR register */
#define FLEX_SPI_IDR_Msk                      _UINT32_(0xFF001FFF)                                 /* (FLEX_SPI_IDR) Register Mask  */


/* -------- FLEX_SPI_IMR : (FLEXCOM Offset: 0x41C) ( R/ 32) SPI Interrupt Mask Register -------- */
#define FLEX_SPI_IMR_RDRF_Pos                 _UINT32_(0)                                          /* (FLEX_SPI_IMR) Receive Data Register Full Interrupt Mask Position */
#define FLEX_SPI_IMR_RDRF_Msk                 (_UINT32_(0x1) << FLEX_SPI_IMR_RDRF_Pos)             /* (FLEX_SPI_IMR) Receive Data Register Full Interrupt Mask Mask */
#define FLEX_SPI_IMR_RDRF(value)              (FLEX_SPI_IMR_RDRF_Msk & (_UINT32_(value) << FLEX_SPI_IMR_RDRF_Pos)) /* Assigment of value for RDRF in the FLEX_SPI_IMR register */
#define FLEX_SPI_IMR_TDRE_Pos                 _UINT32_(1)                                          /* (FLEX_SPI_IMR) SPI Transmit Data Register Empty Interrupt Mask Position */
#define FLEX_SPI_IMR_TDRE_Msk                 (_UINT32_(0x1) << FLEX_SPI_IMR_TDRE_Pos)             /* (FLEX_SPI_IMR) SPI Transmit Data Register Empty Interrupt Mask Mask */
#define FLEX_SPI_IMR_TDRE(value)              (FLEX_SPI_IMR_TDRE_Msk & (_UINT32_(value) << FLEX_SPI_IMR_TDRE_Pos)) /* Assigment of value for TDRE in the FLEX_SPI_IMR register */
#define FLEX_SPI_IMR_MODF_Pos                 _UINT32_(2)                                          /* (FLEX_SPI_IMR) Mode Fault Error Interrupt Mask Position */
#define FLEX_SPI_IMR_MODF_Msk                 (_UINT32_(0x1) << FLEX_SPI_IMR_MODF_Pos)             /* (FLEX_SPI_IMR) Mode Fault Error Interrupt Mask Mask */
#define FLEX_SPI_IMR_MODF(value)              (FLEX_SPI_IMR_MODF_Msk & (_UINT32_(value) << FLEX_SPI_IMR_MODF_Pos)) /* Assigment of value for MODF in the FLEX_SPI_IMR register */
#define FLEX_SPI_IMR_OVRES_Pos                _UINT32_(3)                                          /* (FLEX_SPI_IMR) Overrun Error Interrupt Mask Position */
#define FLEX_SPI_IMR_OVRES_Msk                (_UINT32_(0x1) << FLEX_SPI_IMR_OVRES_Pos)            /* (FLEX_SPI_IMR) Overrun Error Interrupt Mask Mask */
#define FLEX_SPI_IMR_OVRES(value)             (FLEX_SPI_IMR_OVRES_Msk & (_UINT32_(value) << FLEX_SPI_IMR_OVRES_Pos)) /* Assigment of value for OVRES in the FLEX_SPI_IMR register */
#define FLEX_SPI_IMR_ENDRX_Pos                _UINT32_(4)                                          /* (FLEX_SPI_IMR) End of Receive Buffer Interrupt Mask Position */
#define FLEX_SPI_IMR_ENDRX_Msk                (_UINT32_(0x1) << FLEX_SPI_IMR_ENDRX_Pos)            /* (FLEX_SPI_IMR) End of Receive Buffer Interrupt Mask Mask */
#define FLEX_SPI_IMR_ENDRX(value)             (FLEX_SPI_IMR_ENDRX_Msk & (_UINT32_(value) << FLEX_SPI_IMR_ENDRX_Pos)) /* Assigment of value for ENDRX in the FLEX_SPI_IMR register */
#define FLEX_SPI_IMR_ENDTX_Pos                _UINT32_(5)                                          /* (FLEX_SPI_IMR) End of Transmit Buffer Interrupt Mask Position */
#define FLEX_SPI_IMR_ENDTX_Msk                (_UINT32_(0x1) << FLEX_SPI_IMR_ENDTX_Pos)            /* (FLEX_SPI_IMR) End of Transmit Buffer Interrupt Mask Mask */
#define FLEX_SPI_IMR_ENDTX(value)             (FLEX_SPI_IMR_ENDTX_Msk & (_UINT32_(value) << FLEX_SPI_IMR_ENDTX_Pos)) /* Assigment of value for ENDTX in the FLEX_SPI_IMR register */
#define FLEX_SPI_IMR_RXBUFF_Pos               _UINT32_(6)                                          /* (FLEX_SPI_IMR) Receive Buffer Full Interrupt Mask Position */
#define FLEX_SPI_IMR_RXBUFF_Msk               (_UINT32_(0x1) << FLEX_SPI_IMR_RXBUFF_Pos)           /* (FLEX_SPI_IMR) Receive Buffer Full Interrupt Mask Mask */
#define FLEX_SPI_IMR_RXBUFF(value)            (FLEX_SPI_IMR_RXBUFF_Msk & (_UINT32_(value) << FLEX_SPI_IMR_RXBUFF_Pos)) /* Assigment of value for RXBUFF in the FLEX_SPI_IMR register */
#define FLEX_SPI_IMR_TXBUFE_Pos               _UINT32_(7)                                          /* (FLEX_SPI_IMR) Transmit Buffer Empty Interrupt Mask Position */
#define FLEX_SPI_IMR_TXBUFE_Msk               (_UINT32_(0x1) << FLEX_SPI_IMR_TXBUFE_Pos)           /* (FLEX_SPI_IMR) Transmit Buffer Empty Interrupt Mask Mask */
#define FLEX_SPI_IMR_TXBUFE(value)            (FLEX_SPI_IMR_TXBUFE_Msk & (_UINT32_(value) << FLEX_SPI_IMR_TXBUFE_Pos)) /* Assigment of value for TXBUFE in the FLEX_SPI_IMR register */
#define FLEX_SPI_IMR_NSSR_Pos                 _UINT32_(8)                                          /* (FLEX_SPI_IMR) NSS Rising Interrupt Mask Position */
#define FLEX_SPI_IMR_NSSR_Msk                 (_UINT32_(0x1) << FLEX_SPI_IMR_NSSR_Pos)             /* (FLEX_SPI_IMR) NSS Rising Interrupt Mask Mask */
#define FLEX_SPI_IMR_NSSR(value)              (FLEX_SPI_IMR_NSSR_Msk & (_UINT32_(value) << FLEX_SPI_IMR_NSSR_Pos)) /* Assigment of value for NSSR in the FLEX_SPI_IMR register */
#define FLEX_SPI_IMR_TXEMPTY_Pos              _UINT32_(9)                                          /* (FLEX_SPI_IMR) Transmission Registers Empty Mask Position */
#define FLEX_SPI_IMR_TXEMPTY_Msk              (_UINT32_(0x1) << FLEX_SPI_IMR_TXEMPTY_Pos)          /* (FLEX_SPI_IMR) Transmission Registers Empty Mask Mask */
#define FLEX_SPI_IMR_TXEMPTY(value)           (FLEX_SPI_IMR_TXEMPTY_Msk & (_UINT32_(value) << FLEX_SPI_IMR_TXEMPTY_Pos)) /* Assigment of value for TXEMPTY in the FLEX_SPI_IMR register */
#define FLEX_SPI_IMR_UNDES_Pos                _UINT32_(10)                                         /* (FLEX_SPI_IMR) Underrun Error Interrupt Mask Position */
#define FLEX_SPI_IMR_UNDES_Msk                (_UINT32_(0x1) << FLEX_SPI_IMR_UNDES_Pos)            /* (FLEX_SPI_IMR) Underrun Error Interrupt Mask Mask */
#define FLEX_SPI_IMR_UNDES(value)             (FLEX_SPI_IMR_UNDES_Msk & (_UINT32_(value) << FLEX_SPI_IMR_UNDES_Pos)) /* Assigment of value for UNDES in the FLEX_SPI_IMR register */
#define FLEX_SPI_IMR_CMP_Pos                  _UINT32_(11)                                         /* (FLEX_SPI_IMR) Comparison Interrupt Mask Position */
#define FLEX_SPI_IMR_CMP_Msk                  (_UINT32_(0x1) << FLEX_SPI_IMR_CMP_Pos)              /* (FLEX_SPI_IMR) Comparison Interrupt Mask Mask */
#define FLEX_SPI_IMR_CMP(value)               (FLEX_SPI_IMR_CMP_Msk & (_UINT32_(value) << FLEX_SPI_IMR_CMP_Pos)) /* Assigment of value for CMP in the FLEX_SPI_IMR register */
#define FLEX_SPI_IMR_SFERR_Pos                _UINT32_(12)                                         /* (FLEX_SPI_IMR) Client Mode Frame Error Interrupt Mask Position */
#define FLEX_SPI_IMR_SFERR_Msk                (_UINT32_(0x1) << FLEX_SPI_IMR_SFERR_Pos)            /* (FLEX_SPI_IMR) Client Mode Frame Error Interrupt Mask Mask */
#define FLEX_SPI_IMR_SFERR(value)             (FLEX_SPI_IMR_SFERR_Msk & (_UINT32_(value) << FLEX_SPI_IMR_SFERR_Pos)) /* Assigment of value for SFERR in the FLEX_SPI_IMR register */
#define FLEX_SPI_IMR_TXFEF_Pos                _UINT32_(24)                                         /* (FLEX_SPI_IMR) TXFEF Interrupt Mask Position */
#define FLEX_SPI_IMR_TXFEF_Msk                (_UINT32_(0x1) << FLEX_SPI_IMR_TXFEF_Pos)            /* (FLEX_SPI_IMR) TXFEF Interrupt Mask Mask */
#define FLEX_SPI_IMR_TXFEF(value)             (FLEX_SPI_IMR_TXFEF_Msk & (_UINT32_(value) << FLEX_SPI_IMR_TXFEF_Pos)) /* Assigment of value for TXFEF in the FLEX_SPI_IMR register */
#define FLEX_SPI_IMR_TXFFF_Pos                _UINT32_(25)                                         /* (FLEX_SPI_IMR) TXFFF Interrupt Mask Position */
#define FLEX_SPI_IMR_TXFFF_Msk                (_UINT32_(0x1) << FLEX_SPI_IMR_TXFFF_Pos)            /* (FLEX_SPI_IMR) TXFFF Interrupt Mask Mask */
#define FLEX_SPI_IMR_TXFFF(value)             (FLEX_SPI_IMR_TXFFF_Msk & (_UINT32_(value) << FLEX_SPI_IMR_TXFFF_Pos)) /* Assigment of value for TXFFF in the FLEX_SPI_IMR register */
#define FLEX_SPI_IMR_TXFTHF_Pos               _UINT32_(26)                                         /* (FLEX_SPI_IMR) TXFTHF Interrupt Mask Position */
#define FLEX_SPI_IMR_TXFTHF_Msk               (_UINT32_(0x1) << FLEX_SPI_IMR_TXFTHF_Pos)           /* (FLEX_SPI_IMR) TXFTHF Interrupt Mask Mask */
#define FLEX_SPI_IMR_TXFTHF(value)            (FLEX_SPI_IMR_TXFTHF_Msk & (_UINT32_(value) << FLEX_SPI_IMR_TXFTHF_Pos)) /* Assigment of value for TXFTHF in the FLEX_SPI_IMR register */
#define FLEX_SPI_IMR_RXFEF_Pos                _UINT32_(27)                                         /* (FLEX_SPI_IMR) RXFEF Interrupt Mask Position */
#define FLEX_SPI_IMR_RXFEF_Msk                (_UINT32_(0x1) << FLEX_SPI_IMR_RXFEF_Pos)            /* (FLEX_SPI_IMR) RXFEF Interrupt Mask Mask */
#define FLEX_SPI_IMR_RXFEF(value)             (FLEX_SPI_IMR_RXFEF_Msk & (_UINT32_(value) << FLEX_SPI_IMR_RXFEF_Pos)) /* Assigment of value for RXFEF in the FLEX_SPI_IMR register */
#define FLEX_SPI_IMR_RXFFF_Pos                _UINT32_(28)                                         /* (FLEX_SPI_IMR) RXFFF Interrupt Mask Position */
#define FLEX_SPI_IMR_RXFFF_Msk                (_UINT32_(0x1) << FLEX_SPI_IMR_RXFFF_Pos)            /* (FLEX_SPI_IMR) RXFFF Interrupt Mask Mask */
#define FLEX_SPI_IMR_RXFFF(value)             (FLEX_SPI_IMR_RXFFF_Msk & (_UINT32_(value) << FLEX_SPI_IMR_RXFFF_Pos)) /* Assigment of value for RXFFF in the FLEX_SPI_IMR register */
#define FLEX_SPI_IMR_RXFTHF_Pos               _UINT32_(29)                                         /* (FLEX_SPI_IMR) RXFTHF Interrupt Mask Position */
#define FLEX_SPI_IMR_RXFTHF_Msk               (_UINT32_(0x1) << FLEX_SPI_IMR_RXFTHF_Pos)           /* (FLEX_SPI_IMR) RXFTHF Interrupt Mask Mask */
#define FLEX_SPI_IMR_RXFTHF(value)            (FLEX_SPI_IMR_RXFTHF_Msk & (_UINT32_(value) << FLEX_SPI_IMR_RXFTHF_Pos)) /* Assigment of value for RXFTHF in the FLEX_SPI_IMR register */
#define FLEX_SPI_IMR_TXFPTEF_Pos              _UINT32_(30)                                         /* (FLEX_SPI_IMR) TXFPTEF Interrupt Mask Position */
#define FLEX_SPI_IMR_TXFPTEF_Msk              (_UINT32_(0x1) << FLEX_SPI_IMR_TXFPTEF_Pos)          /* (FLEX_SPI_IMR) TXFPTEF Interrupt Mask Mask */
#define FLEX_SPI_IMR_TXFPTEF(value)           (FLEX_SPI_IMR_TXFPTEF_Msk & (_UINT32_(value) << FLEX_SPI_IMR_TXFPTEF_Pos)) /* Assigment of value for TXFPTEF in the FLEX_SPI_IMR register */
#define FLEX_SPI_IMR_RXFPTEF_Pos              _UINT32_(31)                                         /* (FLEX_SPI_IMR) RXFPTEF Interrupt Mask Position */
#define FLEX_SPI_IMR_RXFPTEF_Msk              (_UINT32_(0x1) << FLEX_SPI_IMR_RXFPTEF_Pos)          /* (FLEX_SPI_IMR) RXFPTEF Interrupt Mask Mask */
#define FLEX_SPI_IMR_RXFPTEF(value)           (FLEX_SPI_IMR_RXFPTEF_Msk & (_UINT32_(value) << FLEX_SPI_IMR_RXFPTEF_Pos)) /* Assigment of value for RXFPTEF in the FLEX_SPI_IMR register */
#define FLEX_SPI_IMR_Msk                      _UINT32_(0xFF001FFF)                                 /* (FLEX_SPI_IMR) Register Mask  */


/* -------- FLEX_SPI_CSR : (FLEXCOM Offset: 0x430) (R/W 32) SPI Chip Select Register -------- */
#define FLEX_SPI_CSR_CPOL_Pos                 _UINT32_(0)                                          /* (FLEX_SPI_CSR) Clock Polarity Position */
#define FLEX_SPI_CSR_CPOL_Msk                 (_UINT32_(0x1) << FLEX_SPI_CSR_CPOL_Pos)             /* (FLEX_SPI_CSR) Clock Polarity Mask */
#define FLEX_SPI_CSR_CPOL(value)              (FLEX_SPI_CSR_CPOL_Msk & (_UINT32_(value) << FLEX_SPI_CSR_CPOL_Pos)) /* Assigment of value for CPOL in the FLEX_SPI_CSR register */
#define FLEX_SPI_CSR_NCPHA_Pos                _UINT32_(1)                                          /* (FLEX_SPI_CSR) Clock Phase Position */
#define FLEX_SPI_CSR_NCPHA_Msk                (_UINT32_(0x1) << FLEX_SPI_CSR_NCPHA_Pos)            /* (FLEX_SPI_CSR) Clock Phase Mask */
#define FLEX_SPI_CSR_NCPHA(value)             (FLEX_SPI_CSR_NCPHA_Msk & (_UINT32_(value) << FLEX_SPI_CSR_NCPHA_Pos)) /* Assigment of value for NCPHA in the FLEX_SPI_CSR register */
#define FLEX_SPI_CSR_CSNAAT_Pos               _UINT32_(2)                                          /* (FLEX_SPI_CSR) Chip Select Not Active After Transfer (Ignored if CSAAT = 1) Position */
#define FLEX_SPI_CSR_CSNAAT_Msk               (_UINT32_(0x1) << FLEX_SPI_CSR_CSNAAT_Pos)           /* (FLEX_SPI_CSR) Chip Select Not Active After Transfer (Ignored if CSAAT = 1) Mask */
#define FLEX_SPI_CSR_CSNAAT(value)            (FLEX_SPI_CSR_CSNAAT_Msk & (_UINT32_(value) << FLEX_SPI_CSR_CSNAAT_Pos)) /* Assigment of value for CSNAAT in the FLEX_SPI_CSR register */
#define FLEX_SPI_CSR_CSAAT_Pos                _UINT32_(3)                                          /* (FLEX_SPI_CSR) Chip Select Active After Transfer Position */
#define FLEX_SPI_CSR_CSAAT_Msk                (_UINT32_(0x1) << FLEX_SPI_CSR_CSAAT_Pos)            /* (FLEX_SPI_CSR) Chip Select Active After Transfer Mask */
#define FLEX_SPI_CSR_CSAAT(value)             (FLEX_SPI_CSR_CSAAT_Msk & (_UINT32_(value) << FLEX_SPI_CSR_CSAAT_Pos)) /* Assigment of value for CSAAT in the FLEX_SPI_CSR register */
#define FLEX_SPI_CSR_BITS_Pos                 _UINT32_(4)                                          /* (FLEX_SPI_CSR) Bits Per Transfer Position */
#define FLEX_SPI_CSR_BITS_Msk                 (_UINT32_(0xF) << FLEX_SPI_CSR_BITS_Pos)             /* (FLEX_SPI_CSR) Bits Per Transfer Mask */
#define FLEX_SPI_CSR_BITS(value)              (FLEX_SPI_CSR_BITS_Msk & (_UINT32_(value) << FLEX_SPI_CSR_BITS_Pos)) /* Assigment of value for BITS in the FLEX_SPI_CSR register */
#define   FLEX_SPI_CSR_BITS_8_BIT_Val         _UINT32_(0x0)                                        /* (FLEX_SPI_CSR) 8 bits for transfer  */
#define   FLEX_SPI_CSR_BITS_9_BIT_Val         _UINT32_(0x1)                                        /* (FLEX_SPI_CSR) 9 bits for transfer  */
#define   FLEX_SPI_CSR_BITS_10_BIT_Val        _UINT32_(0x2)                                        /* (FLEX_SPI_CSR) 10 bits for transfer  */
#define   FLEX_SPI_CSR_BITS_11_BIT_Val        _UINT32_(0x3)                                        /* (FLEX_SPI_CSR) 11 bits for transfer  */
#define   FLEX_SPI_CSR_BITS_12_BIT_Val        _UINT32_(0x4)                                        /* (FLEX_SPI_CSR) 12 bits for transfer  */
#define   FLEX_SPI_CSR_BITS_13_BIT_Val        _UINT32_(0x5)                                        /* (FLEX_SPI_CSR) 13 bits for transfer  */
#define   FLEX_SPI_CSR_BITS_14_BIT_Val        _UINT32_(0x6)                                        /* (FLEX_SPI_CSR) 14 bits for transfer  */
#define   FLEX_SPI_CSR_BITS_15_BIT_Val        _UINT32_(0x7)                                        /* (FLEX_SPI_CSR) 15 bits for transfer  */
#define   FLEX_SPI_CSR_BITS_16_BIT_Val        _UINT32_(0x8)                                        /* (FLEX_SPI_CSR) 16 bits for transfer  */
#define FLEX_SPI_CSR_BITS_8_BIT               (FLEX_SPI_CSR_BITS_8_BIT_Val << FLEX_SPI_CSR_BITS_Pos) /* (FLEX_SPI_CSR) 8 bits for transfer Position  */
#define FLEX_SPI_CSR_BITS_9_BIT               (FLEX_SPI_CSR_BITS_9_BIT_Val << FLEX_SPI_CSR_BITS_Pos) /* (FLEX_SPI_CSR) 9 bits for transfer Position  */
#define FLEX_SPI_CSR_BITS_10_BIT              (FLEX_SPI_CSR_BITS_10_BIT_Val << FLEX_SPI_CSR_BITS_Pos) /* (FLEX_SPI_CSR) 10 bits for transfer Position  */
#define FLEX_SPI_CSR_BITS_11_BIT              (FLEX_SPI_CSR_BITS_11_BIT_Val << FLEX_SPI_CSR_BITS_Pos) /* (FLEX_SPI_CSR) 11 bits for transfer Position  */
#define FLEX_SPI_CSR_BITS_12_BIT              (FLEX_SPI_CSR_BITS_12_BIT_Val << FLEX_SPI_CSR_BITS_Pos) /* (FLEX_SPI_CSR) 12 bits for transfer Position  */
#define FLEX_SPI_CSR_BITS_13_BIT              (FLEX_SPI_CSR_BITS_13_BIT_Val << FLEX_SPI_CSR_BITS_Pos) /* (FLEX_SPI_CSR) 13 bits for transfer Position  */
#define FLEX_SPI_CSR_BITS_14_BIT              (FLEX_SPI_CSR_BITS_14_BIT_Val << FLEX_SPI_CSR_BITS_Pos) /* (FLEX_SPI_CSR) 14 bits for transfer Position  */
#define FLEX_SPI_CSR_BITS_15_BIT              (FLEX_SPI_CSR_BITS_15_BIT_Val << FLEX_SPI_CSR_BITS_Pos) /* (FLEX_SPI_CSR) 15 bits for transfer Position  */
#define FLEX_SPI_CSR_BITS_16_BIT              (FLEX_SPI_CSR_BITS_16_BIT_Val << FLEX_SPI_CSR_BITS_Pos) /* (FLEX_SPI_CSR) 16 bits for transfer Position  */
#define FLEX_SPI_CSR_SCBR_Pos                 _UINT32_(8)                                          /* (FLEX_SPI_CSR) Serial Clock Bit Rate Position */
#define FLEX_SPI_CSR_SCBR_Msk                 (_UINT32_(0xFF) << FLEX_SPI_CSR_SCBR_Pos)            /* (FLEX_SPI_CSR) Serial Clock Bit Rate Mask */
#define FLEX_SPI_CSR_SCBR(value)              (FLEX_SPI_CSR_SCBR_Msk & (_UINT32_(value) << FLEX_SPI_CSR_SCBR_Pos)) /* Assigment of value for SCBR in the FLEX_SPI_CSR register */
#define FLEX_SPI_CSR_DLYBS_Pos                _UINT32_(16)                                         /* (FLEX_SPI_CSR) Delay Before SPCK Position */
#define FLEX_SPI_CSR_DLYBS_Msk                (_UINT32_(0xFF) << FLEX_SPI_CSR_DLYBS_Pos)           /* (FLEX_SPI_CSR) Delay Before SPCK Mask */
#define FLEX_SPI_CSR_DLYBS(value)             (FLEX_SPI_CSR_DLYBS_Msk & (_UINT32_(value) << FLEX_SPI_CSR_DLYBS_Pos)) /* Assigment of value for DLYBS in the FLEX_SPI_CSR register */
#define FLEX_SPI_CSR_DLYBCT_Pos               _UINT32_(24)                                         /* (FLEX_SPI_CSR) Delay Between Consecutive Transfers Position */
#define FLEX_SPI_CSR_DLYBCT_Msk               (_UINT32_(0xFF) << FLEX_SPI_CSR_DLYBCT_Pos)          /* (FLEX_SPI_CSR) Delay Between Consecutive Transfers Mask */
#define FLEX_SPI_CSR_DLYBCT(value)            (FLEX_SPI_CSR_DLYBCT_Msk & (_UINT32_(value) << FLEX_SPI_CSR_DLYBCT_Pos)) /* Assigment of value for DLYBCT in the FLEX_SPI_CSR register */
#define FLEX_SPI_CSR_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (FLEX_SPI_CSR) Register Mask  */


/* -------- FLEX_SPI_FMR : (FLEXCOM Offset: 0x440) (R/W 32) SPI FIFO Mode Register -------- */
#define FLEX_SPI_FMR_TXRDYM_Pos               _UINT32_(0)                                          /* (FLEX_SPI_FMR) Transmit Data Register Empty Mode Position */
#define FLEX_SPI_FMR_TXRDYM_Msk               (_UINT32_(0x3) << FLEX_SPI_FMR_TXRDYM_Pos)           /* (FLEX_SPI_FMR) Transmit Data Register Empty Mode Mask */
#define FLEX_SPI_FMR_TXRDYM(value)            (FLEX_SPI_FMR_TXRDYM_Msk & (_UINT32_(value) << FLEX_SPI_FMR_TXRDYM_Pos)) /* Assigment of value for TXRDYM in the FLEX_SPI_FMR register */
#define   FLEX_SPI_FMR_TXRDYM_ONE_DATA_Val    _UINT32_(0x0)                                        /* (FLEX_SPI_FMR) TDRE will be at level '1' when at least one data can be written in the transmit FIFO. When DMA is enabled to transfer data, the chunk of 1 data (byte or halfword) must be configured in the DMA depending on FLEX_SPI_CSR0.BITS. If the transfer is performed by software, the access type (byte, halfword) must be defined depending on FLEX_SPI_CSR0.BITS.  */
#define   FLEX_SPI_FMR_TXRDYM_TWO_DATA_Val    _UINT32_(0x1)                                        /* (FLEX_SPI_FMR) TDRE will be at level '1' when at least two data can be written in the transmit FIFO. FIFO. To minimize system bus load, when DMA is enabled to transfer data, the chunk of 1 word (1 word carries 2 data) must be configured in the DMA. If the transfer is performed by software, the access type must be defined as word (2 data per access, 1 access).  */
#define FLEX_SPI_FMR_TXRDYM_ONE_DATA          (FLEX_SPI_FMR_TXRDYM_ONE_DATA_Val << FLEX_SPI_FMR_TXRDYM_Pos) /* (FLEX_SPI_FMR) TDRE will be at level '1' when at least one data can be written in the transmit FIFO. When DMA is enabled to transfer data, the chunk of 1 data (byte or halfword) must be configured in the DMA depending on FLEX_SPI_CSR0.BITS. If the transfer is performed by software, the access type (byte, halfword) must be defined depending on FLEX_SPI_CSR0.BITS. Position  */
#define FLEX_SPI_FMR_TXRDYM_TWO_DATA          (FLEX_SPI_FMR_TXRDYM_TWO_DATA_Val << FLEX_SPI_FMR_TXRDYM_Pos) /* (FLEX_SPI_FMR) TDRE will be at level '1' when at least two data can be written in the transmit FIFO. FIFO. To minimize system bus load, when DMA is enabled to transfer data, the chunk of 1 word (1 word carries 2 data) must be configured in the DMA. If the transfer is performed by software, the access type must be defined as word (2 data per access, 1 access). Position  */
#define FLEX_SPI_FMR_RXRDYM_Pos               _UINT32_(4)                                          /* (FLEX_SPI_FMR) Receive Data Register Full Mode Position */
#define FLEX_SPI_FMR_RXRDYM_Msk               (_UINT32_(0x3) << FLEX_SPI_FMR_RXRDYM_Pos)           /* (FLEX_SPI_FMR) Receive Data Register Full Mode Mask */
#define FLEX_SPI_FMR_RXRDYM(value)            (FLEX_SPI_FMR_RXRDYM_Msk & (_UINT32_(value) << FLEX_SPI_FMR_RXRDYM_Pos)) /* Assigment of value for RXRDYM in the FLEX_SPI_FMR register */
#define   FLEX_SPI_FMR_RXRDYM_ONE_DATA_Val    _UINT32_(0x0)                                        /* (FLEX_SPI_FMR) RDRF will be at level '1' when at least one unread data is in the receive FIFO. When DMA is enabled to transfer data and FLEX_SPI_CSR0.BITS=0 (8 bits transfered on SPI line), the chunk of 1 byte must be configured in the DMA. When FLEX_SPI_CSR0.BITS>0 (9 to 16 bits transfered on SPI line), the chunk of 1 halfword must be configured in the DMA. If the transfer is performed by software, the access type can be defined as byte or halfword depending on FLEX_SPI_CSR0.BITS.  */
#define   FLEX_SPI_FMR_RXRDYM_TWO_DATA_Val    _UINT32_(0x1)                                        /* (FLEX_SPI_FMR) RDRF will be at level '1' when at least two unread data are in the receive FIFO. To minimize system bus load, when DMA is enabled to transfer data and FLEX_SPI_CSR0.BITS=0 (8 bits transfered on SPI line), the chunk of 1 halfword (1 halfword carries 2 bytes) must be configured in the DMA. When FLEX_SPI_CSR0.BITS>0 (9 to 16 bits transfered on SPI line), the chunk of 1 word (1 word carries 2 halfwords) must be configured in the DMA. If the transfer is performed by software, the access type can be defined as halfword (2 bytes per access, 1 access when FLEX_SPI_CSR0.BITS=0), or word (2 halfwords per access, 2 accesses when FLEX_SPI_CSR0.BITS>0).  */
#define   FLEX_SPI_FMR_RXRDYM_FOUR_DATA_Val   _UINT32_(0x2)                                        /* (FLEX_SPI_FMR) RDRF will be at level '1' when at least four unread data are in the receive FIFO. To minimize system bus load, when DMA is enabled to transfer data and FLEX_SPI_CSR0.BITS=0 (8 bits transfered on SPI line), the chunk of 1 word (1 halfword carries 4 bytes) must be configured in the DMA. When FLEX_SPI_CSR0.BITS>0 (9 to 16 bits transfered on SPI line), the chunk of 2 words (1 word carries 4 bytes) must be configured in the DMA. If the transfer is performed by software, the access type can be defined as word (4 bytes per access, 1 access when FLEX_SPI_CSR0.BITS=0 or 2 halfwords per access, 2 accesses when FLEX_SPI_CSR0.BITS>0).  */
#define FLEX_SPI_FMR_RXRDYM_ONE_DATA          (FLEX_SPI_FMR_RXRDYM_ONE_DATA_Val << FLEX_SPI_FMR_RXRDYM_Pos) /* (FLEX_SPI_FMR) RDRF will be at level '1' when at least one unread data is in the receive FIFO. When DMA is enabled to transfer data and FLEX_SPI_CSR0.BITS=0 (8 bits transfered on SPI line), the chunk of 1 byte must be configured in the DMA. When FLEX_SPI_CSR0.BITS>0 (9 to 16 bits transfered on SPI line), the chunk of 1 halfword must be configured in the DMA. If the transfer is performed by software, the access type can be defined as byte or halfword depending on FLEX_SPI_CSR0.BITS. Position  */
#define FLEX_SPI_FMR_RXRDYM_TWO_DATA          (FLEX_SPI_FMR_RXRDYM_TWO_DATA_Val << FLEX_SPI_FMR_RXRDYM_Pos) /* (FLEX_SPI_FMR) RDRF will be at level '1' when at least two unread data are in the receive FIFO. To minimize system bus load, when DMA is enabled to transfer data and FLEX_SPI_CSR0.BITS=0 (8 bits transfered on SPI line), the chunk of 1 halfword (1 halfword carries 2 bytes) must be configured in the DMA. When FLEX_SPI_CSR0.BITS>0 (9 to 16 bits transfered on SPI line), the chunk of 1 word (1 word carries 2 halfwords) must be configured in the DMA. If the transfer is performed by software, the access type can be defined as halfword (2 bytes per access, 1 access when FLEX_SPI_CSR0.BITS=0), or word (2 halfwords per access, 2 accesses when FLEX_SPI_CSR0.BITS>0). Position  */
#define FLEX_SPI_FMR_RXRDYM_FOUR_DATA         (FLEX_SPI_FMR_RXRDYM_FOUR_DATA_Val << FLEX_SPI_FMR_RXRDYM_Pos) /* (FLEX_SPI_FMR) RDRF will be at level '1' when at least four unread data are in the receive FIFO. To minimize system bus load, when DMA is enabled to transfer data and FLEX_SPI_CSR0.BITS=0 (8 bits transfered on SPI line), the chunk of 1 word (1 halfword carries 4 bytes) must be configured in the DMA. When FLEX_SPI_CSR0.BITS>0 (9 to 16 bits transfered on SPI line), the chunk of 2 words (1 word carries 4 bytes) must be configured in the DMA. If the transfer is performed by software, the access type can be defined as word (4 bytes per access, 1 access when FLEX_SPI_CSR0.BITS=0 or 2 halfwords per access, 2 accesses when FLEX_SPI_CSR0.BITS>0). Position  */
#define FLEX_SPI_FMR_TXFTHRES_Pos             _UINT32_(16)                                         /* (FLEX_SPI_FMR) Transmit FIFO Threshold Position */
#define FLEX_SPI_FMR_TXFTHRES_Msk             (_UINT32_(0x3F) << FLEX_SPI_FMR_TXFTHRES_Pos)        /* (FLEX_SPI_FMR) Transmit FIFO Threshold Mask */
#define FLEX_SPI_FMR_TXFTHRES(value)          (FLEX_SPI_FMR_TXFTHRES_Msk & (_UINT32_(value) << FLEX_SPI_FMR_TXFTHRES_Pos)) /* Assigment of value for TXFTHRES in the FLEX_SPI_FMR register */
#define FLEX_SPI_FMR_RXFTHRES_Pos             _UINT32_(24)                                         /* (FLEX_SPI_FMR) Receive FIFO Threshold Position */
#define FLEX_SPI_FMR_RXFTHRES_Msk             (_UINT32_(0x3F) << FLEX_SPI_FMR_RXFTHRES_Pos)        /* (FLEX_SPI_FMR) Receive FIFO Threshold Mask */
#define FLEX_SPI_FMR_RXFTHRES(value)          (FLEX_SPI_FMR_RXFTHRES_Msk & (_UINT32_(value) << FLEX_SPI_FMR_RXFTHRES_Pos)) /* Assigment of value for RXFTHRES in the FLEX_SPI_FMR register */
#define FLEX_SPI_FMR_Msk                      _UINT32_(0x3F3F0033)                                 /* (FLEX_SPI_FMR) Register Mask  */


/* -------- FLEX_SPI_FLR : (FLEXCOM Offset: 0x444) ( R/ 32) SPI FIFO Level Register -------- */
#define FLEX_SPI_FLR_TXFL_Pos                 _UINT32_(0)                                          /* (FLEX_SPI_FLR) Transmit FIFO Level Position */
#define FLEX_SPI_FLR_TXFL_Msk                 (_UINT32_(0x3F) << FLEX_SPI_FLR_TXFL_Pos)            /* (FLEX_SPI_FLR) Transmit FIFO Level Mask */
#define FLEX_SPI_FLR_TXFL(value)              (FLEX_SPI_FLR_TXFL_Msk & (_UINT32_(value) << FLEX_SPI_FLR_TXFL_Pos)) /* Assigment of value for TXFL in the FLEX_SPI_FLR register */
#define FLEX_SPI_FLR_RXFL_Pos                 _UINT32_(16)                                         /* (FLEX_SPI_FLR) Receive FIFO Level Position */
#define FLEX_SPI_FLR_RXFL_Msk                 (_UINT32_(0x3F) << FLEX_SPI_FLR_RXFL_Pos)            /* (FLEX_SPI_FLR) Receive FIFO Level Mask */
#define FLEX_SPI_FLR_RXFL(value)              (FLEX_SPI_FLR_RXFL_Msk & (_UINT32_(value) << FLEX_SPI_FLR_RXFL_Pos)) /* Assigment of value for RXFL in the FLEX_SPI_FLR register */
#define FLEX_SPI_FLR_Msk                      _UINT32_(0x003F003F)                                 /* (FLEX_SPI_FLR) Register Mask  */


/* -------- FLEX_SPI_CMPR : (FLEXCOM Offset: 0x448) (R/W 32) SPI Comparison Register -------- */
#define FLEX_SPI_CMPR_VAL1_Pos                _UINT32_(0)                                          /* (FLEX_SPI_CMPR) First Comparison Value for Received Character Position */
#define FLEX_SPI_CMPR_VAL1_Msk                (_UINT32_(0xFFFF) << FLEX_SPI_CMPR_VAL1_Pos)         /* (FLEX_SPI_CMPR) First Comparison Value for Received Character Mask */
#define FLEX_SPI_CMPR_VAL1(value)             (FLEX_SPI_CMPR_VAL1_Msk & (_UINT32_(value) << FLEX_SPI_CMPR_VAL1_Pos)) /* Assigment of value for VAL1 in the FLEX_SPI_CMPR register */
#define FLEX_SPI_CMPR_VAL2_Pos                _UINT32_(16)                                         /* (FLEX_SPI_CMPR) Second Comparison Value for Received Character Position */
#define FLEX_SPI_CMPR_VAL2_Msk                (_UINT32_(0xFFFF) << FLEX_SPI_CMPR_VAL2_Pos)         /* (FLEX_SPI_CMPR) Second Comparison Value for Received Character Mask */
#define FLEX_SPI_CMPR_VAL2(value)             (FLEX_SPI_CMPR_VAL2_Msk & (_UINT32_(value) << FLEX_SPI_CMPR_VAL2_Pos)) /* Assigment of value for VAL2 in the FLEX_SPI_CMPR register */
#define FLEX_SPI_CMPR_Msk                     _UINT32_(0xFFFFFFFF)                                 /* (FLEX_SPI_CMPR) Register Mask  */


/* -------- FLEX_SPI_WPMR : (FLEXCOM Offset: 0x4E4) (R/W 32) SPI Write Protection Mode Register -------- */
#define FLEX_SPI_WPMR_WPEN_Pos                _UINT32_(0)                                          /* (FLEX_SPI_WPMR) Write Protection Enable Position */
#define FLEX_SPI_WPMR_WPEN_Msk                (_UINT32_(0x1) << FLEX_SPI_WPMR_WPEN_Pos)            /* (FLEX_SPI_WPMR) Write Protection Enable Mask */
#define FLEX_SPI_WPMR_WPEN(value)             (FLEX_SPI_WPMR_WPEN_Msk & (_UINT32_(value) << FLEX_SPI_WPMR_WPEN_Pos)) /* Assigment of value for WPEN in the FLEX_SPI_WPMR register */
#define FLEX_SPI_WPMR_WPITEN_Pos              _UINT32_(1)                                          /* (FLEX_SPI_WPMR) Write Protection Interrupt Enable Position */
#define FLEX_SPI_WPMR_WPITEN_Msk              (_UINT32_(0x1) << FLEX_SPI_WPMR_WPITEN_Pos)          /* (FLEX_SPI_WPMR) Write Protection Interrupt Enable Mask */
#define FLEX_SPI_WPMR_WPITEN(value)           (FLEX_SPI_WPMR_WPITEN_Msk & (_UINT32_(value) << FLEX_SPI_WPMR_WPITEN_Pos)) /* Assigment of value for WPITEN in the FLEX_SPI_WPMR register */
#define FLEX_SPI_WPMR_WPCREN_Pos              _UINT32_(2)                                          /* (FLEX_SPI_WPMR) Write Protection Control Enable Position */
#define FLEX_SPI_WPMR_WPCREN_Msk              (_UINT32_(0x1) << FLEX_SPI_WPMR_WPCREN_Pos)          /* (FLEX_SPI_WPMR) Write Protection Control Enable Mask */
#define FLEX_SPI_WPMR_WPCREN(value)           (FLEX_SPI_WPMR_WPCREN_Msk & (_UINT32_(value) << FLEX_SPI_WPMR_WPCREN_Pos)) /* Assigment of value for WPCREN in the FLEX_SPI_WPMR register */
#define FLEX_SPI_WPMR_WPKEY_Pos               _UINT32_(8)                                          /* (FLEX_SPI_WPMR) Write Protection Key Position */
#define FLEX_SPI_WPMR_WPKEY_Msk               (_UINT32_(0xFFFFFF) << FLEX_SPI_WPMR_WPKEY_Pos)      /* (FLEX_SPI_WPMR) Write Protection Key Mask */
#define FLEX_SPI_WPMR_WPKEY(value)            (FLEX_SPI_WPMR_WPKEY_Msk & (_UINT32_(value) << FLEX_SPI_WPMR_WPKEY_Pos)) /* Assigment of value for WPKEY in the FLEX_SPI_WPMR register */
#define   FLEX_SPI_WPMR_WPKEY_PASSWD_Val      _UINT32_(0x535049)                                   /* (FLEX_SPI_WPMR) Writing any other value in this field aborts the write operation of bits WPEN, WPITEN and WPCREN. Always reads as 0  */
#define FLEX_SPI_WPMR_WPKEY_PASSWD            (FLEX_SPI_WPMR_WPKEY_PASSWD_Val << FLEX_SPI_WPMR_WPKEY_Pos) /* (FLEX_SPI_WPMR) Writing any other value in this field aborts the write operation of bits WPEN, WPITEN and WPCREN. Always reads as 0 Position  */
#define FLEX_SPI_WPMR_Msk                     _UINT32_(0xFFFFFF07)                                 /* (FLEX_SPI_WPMR) Register Mask  */


/* -------- FLEX_SPI_WPSR : (FLEXCOM Offset: 0x4E8) ( R/ 32) SPI Write Protection Status Register -------- */
#define FLEX_SPI_WPSR_WPVS_Pos                _UINT32_(0)                                          /* (FLEX_SPI_WPSR) Write Protection Violation Status Position */
#define FLEX_SPI_WPSR_WPVS_Msk                (_UINT32_(0x1) << FLEX_SPI_WPSR_WPVS_Pos)            /* (FLEX_SPI_WPSR) Write Protection Violation Status Mask */
#define FLEX_SPI_WPSR_WPVS(value)             (FLEX_SPI_WPSR_WPVS_Msk & (_UINT32_(value) << FLEX_SPI_WPSR_WPVS_Pos)) /* Assigment of value for WPVS in the FLEX_SPI_WPSR register */
#define FLEX_SPI_WPSR_WPVSRC_Pos              _UINT32_(8)                                          /* (FLEX_SPI_WPSR) Write Protection Violation Source Position */
#define FLEX_SPI_WPSR_WPVSRC_Msk              (_UINT32_(0xFF) << FLEX_SPI_WPSR_WPVSRC_Pos)         /* (FLEX_SPI_WPSR) Write Protection Violation Source Mask */
#define FLEX_SPI_WPSR_WPVSRC(value)           (FLEX_SPI_WPSR_WPVSRC_Msk & (_UINT32_(value) << FLEX_SPI_WPSR_WPVSRC_Pos)) /* Assigment of value for WPVSRC in the FLEX_SPI_WPSR register */
#define FLEX_SPI_WPSR_Msk                     _UINT32_(0x0000FF01)                                 /* (FLEX_SPI_WPSR) Register Mask  */


/* -------- FLEX_TWI_CR : (FLEXCOM Offset: 0x600) ( /W 32) TWI Control Register -------- */
#define FLEX_TWI_CR_START_Pos                 _UINT32_(0)                                          /* (FLEX_TWI_CR) Send a START Condition Position */
#define FLEX_TWI_CR_START_Msk                 (_UINT32_(0x1) << FLEX_TWI_CR_START_Pos)             /* (FLEX_TWI_CR) Send a START Condition Mask */
#define FLEX_TWI_CR_START(value)              (FLEX_TWI_CR_START_Msk & (_UINT32_(value) << FLEX_TWI_CR_START_Pos)) /* Assigment of value for START in the FLEX_TWI_CR register */
#define FLEX_TWI_CR_STOP_Pos                  _UINT32_(1)                                          /* (FLEX_TWI_CR) Send a STOP Condition Position */
#define FLEX_TWI_CR_STOP_Msk                  (_UINT32_(0x1) << FLEX_TWI_CR_STOP_Pos)              /* (FLEX_TWI_CR) Send a STOP Condition Mask */
#define FLEX_TWI_CR_STOP(value)               (FLEX_TWI_CR_STOP_Msk & (_UINT32_(value) << FLEX_TWI_CR_STOP_Pos)) /* Assigment of value for STOP in the FLEX_TWI_CR register */
#define FLEX_TWI_CR_MSEN_Pos                  _UINT32_(2)                                          /* (FLEX_TWI_CR) TWI Host Mode Enabled Position */
#define FLEX_TWI_CR_MSEN_Msk                  (_UINT32_(0x1) << FLEX_TWI_CR_MSEN_Pos)              /* (FLEX_TWI_CR) TWI Host Mode Enabled Mask */
#define FLEX_TWI_CR_MSEN(value)               (FLEX_TWI_CR_MSEN_Msk & (_UINT32_(value) << FLEX_TWI_CR_MSEN_Pos)) /* Assigment of value for MSEN in the FLEX_TWI_CR register */
#define FLEX_TWI_CR_MSDIS_Pos                 _UINT32_(3)                                          /* (FLEX_TWI_CR) TWI Host Mode Disabled Position */
#define FLEX_TWI_CR_MSDIS_Msk                 (_UINT32_(0x1) << FLEX_TWI_CR_MSDIS_Pos)             /* (FLEX_TWI_CR) TWI Host Mode Disabled Mask */
#define FLEX_TWI_CR_MSDIS(value)              (FLEX_TWI_CR_MSDIS_Msk & (_UINT32_(value) << FLEX_TWI_CR_MSDIS_Pos)) /* Assigment of value for MSDIS in the FLEX_TWI_CR register */
#define FLEX_TWI_CR_SVEN_Pos                  _UINT32_(4)                                          /* (FLEX_TWI_CR) TWI Client Mode Enabled Position */
#define FLEX_TWI_CR_SVEN_Msk                  (_UINT32_(0x1) << FLEX_TWI_CR_SVEN_Pos)              /* (FLEX_TWI_CR) TWI Client Mode Enabled Mask */
#define FLEX_TWI_CR_SVEN(value)               (FLEX_TWI_CR_SVEN_Msk & (_UINT32_(value) << FLEX_TWI_CR_SVEN_Pos)) /* Assigment of value for SVEN in the FLEX_TWI_CR register */
#define FLEX_TWI_CR_SVDIS_Pos                 _UINT32_(5)                                          /* (FLEX_TWI_CR) TWI Client Mode Disabled Position */
#define FLEX_TWI_CR_SVDIS_Msk                 (_UINT32_(0x1) << FLEX_TWI_CR_SVDIS_Pos)             /* (FLEX_TWI_CR) TWI Client Mode Disabled Mask */
#define FLEX_TWI_CR_SVDIS(value)              (FLEX_TWI_CR_SVDIS_Msk & (_UINT32_(value) << FLEX_TWI_CR_SVDIS_Pos)) /* Assigment of value for SVDIS in the FLEX_TWI_CR register */
#define FLEX_TWI_CR_QUICK_Pos                 _UINT32_(6)                                          /* (FLEX_TWI_CR) SMBus Quick Command Position */
#define FLEX_TWI_CR_QUICK_Msk                 (_UINT32_(0x1) << FLEX_TWI_CR_QUICK_Pos)             /* (FLEX_TWI_CR) SMBus Quick Command Mask */
#define FLEX_TWI_CR_QUICK(value)              (FLEX_TWI_CR_QUICK_Msk & (_UINT32_(value) << FLEX_TWI_CR_QUICK_Pos)) /* Assigment of value for QUICK in the FLEX_TWI_CR register */
#define FLEX_TWI_CR_SWRST_Pos                 _UINT32_(7)                                          /* (FLEX_TWI_CR) Software Reset Position */
#define FLEX_TWI_CR_SWRST_Msk                 (_UINT32_(0x1) << FLEX_TWI_CR_SWRST_Pos)             /* (FLEX_TWI_CR) Software Reset Mask */
#define FLEX_TWI_CR_SWRST(value)              (FLEX_TWI_CR_SWRST_Msk & (_UINT32_(value) << FLEX_TWI_CR_SWRST_Pos)) /* Assigment of value for SWRST in the FLEX_TWI_CR register */
#define FLEX_TWI_CR_HSEN_Pos                  _UINT32_(8)                                          /* (FLEX_TWI_CR) TWI High-Speed Mode Enabled Position */
#define FLEX_TWI_CR_HSEN_Msk                  (_UINT32_(0x1) << FLEX_TWI_CR_HSEN_Pos)              /* (FLEX_TWI_CR) TWI High-Speed Mode Enabled Mask */
#define FLEX_TWI_CR_HSEN(value)               (FLEX_TWI_CR_HSEN_Msk & (_UINT32_(value) << FLEX_TWI_CR_HSEN_Pos)) /* Assigment of value for HSEN in the FLEX_TWI_CR register */
#define FLEX_TWI_CR_HSDIS_Pos                 _UINT32_(9)                                          /* (FLEX_TWI_CR) TWI High-Speed Mode Disabled Position */
#define FLEX_TWI_CR_HSDIS_Msk                 (_UINT32_(0x1) << FLEX_TWI_CR_HSDIS_Pos)             /* (FLEX_TWI_CR) TWI High-Speed Mode Disabled Mask */
#define FLEX_TWI_CR_HSDIS(value)              (FLEX_TWI_CR_HSDIS_Msk & (_UINT32_(value) << FLEX_TWI_CR_HSDIS_Pos)) /* Assigment of value for HSDIS in the FLEX_TWI_CR register */
#define FLEX_TWI_CR_SMBEN_Pos                 _UINT32_(10)                                         /* (FLEX_TWI_CR) SMBus Mode Enabled Position */
#define FLEX_TWI_CR_SMBEN_Msk                 (_UINT32_(0x1) << FLEX_TWI_CR_SMBEN_Pos)             /* (FLEX_TWI_CR) SMBus Mode Enabled Mask */
#define FLEX_TWI_CR_SMBEN(value)              (FLEX_TWI_CR_SMBEN_Msk & (_UINT32_(value) << FLEX_TWI_CR_SMBEN_Pos)) /* Assigment of value for SMBEN in the FLEX_TWI_CR register */
#define FLEX_TWI_CR_SMBDIS_Pos                _UINT32_(11)                                         /* (FLEX_TWI_CR) SMBus Mode Disabled Position */
#define FLEX_TWI_CR_SMBDIS_Msk                (_UINT32_(0x1) << FLEX_TWI_CR_SMBDIS_Pos)            /* (FLEX_TWI_CR) SMBus Mode Disabled Mask */
#define FLEX_TWI_CR_SMBDIS(value)             (FLEX_TWI_CR_SMBDIS_Msk & (_UINT32_(value) << FLEX_TWI_CR_SMBDIS_Pos)) /* Assigment of value for SMBDIS in the FLEX_TWI_CR register */
#define FLEX_TWI_CR_PECEN_Pos                 _UINT32_(12)                                         /* (FLEX_TWI_CR) Packet Error Checking Enable Position */
#define FLEX_TWI_CR_PECEN_Msk                 (_UINT32_(0x1) << FLEX_TWI_CR_PECEN_Pos)             /* (FLEX_TWI_CR) Packet Error Checking Enable Mask */
#define FLEX_TWI_CR_PECEN(value)              (FLEX_TWI_CR_PECEN_Msk & (_UINT32_(value) << FLEX_TWI_CR_PECEN_Pos)) /* Assigment of value for PECEN in the FLEX_TWI_CR register */
#define FLEX_TWI_CR_PECDIS_Pos                _UINT32_(13)                                         /* (FLEX_TWI_CR) Packet Error Checking Disable Position */
#define FLEX_TWI_CR_PECDIS_Msk                (_UINT32_(0x1) << FLEX_TWI_CR_PECDIS_Pos)            /* (FLEX_TWI_CR) Packet Error Checking Disable Mask */
#define FLEX_TWI_CR_PECDIS(value)             (FLEX_TWI_CR_PECDIS_Msk & (_UINT32_(value) << FLEX_TWI_CR_PECDIS_Pos)) /* Assigment of value for PECDIS in the FLEX_TWI_CR register */
#define FLEX_TWI_CR_PECRQ_Pos                 _UINT32_(14)                                         /* (FLEX_TWI_CR) PEC Request Position */
#define FLEX_TWI_CR_PECRQ_Msk                 (_UINT32_(0x1) << FLEX_TWI_CR_PECRQ_Pos)             /* (FLEX_TWI_CR) PEC Request Mask */
#define FLEX_TWI_CR_PECRQ(value)              (FLEX_TWI_CR_PECRQ_Msk & (_UINT32_(value) << FLEX_TWI_CR_PECRQ_Pos)) /* Assigment of value for PECRQ in the FLEX_TWI_CR register */
#define FLEX_TWI_CR_CLEAR_Pos                 _UINT32_(15)                                         /* (FLEX_TWI_CR) Bus CLEAR Command Position */
#define FLEX_TWI_CR_CLEAR_Msk                 (_UINT32_(0x1) << FLEX_TWI_CR_CLEAR_Pos)             /* (FLEX_TWI_CR) Bus CLEAR Command Mask */
#define FLEX_TWI_CR_CLEAR(value)              (FLEX_TWI_CR_CLEAR_Msk & (_UINT32_(value) << FLEX_TWI_CR_CLEAR_Pos)) /* Assigment of value for CLEAR in the FLEX_TWI_CR register */
#define FLEX_TWI_CR_ACMEN_Pos                 _UINT32_(16)                                         /* (FLEX_TWI_CR) Alternative Command Mode Enable Position */
#define FLEX_TWI_CR_ACMEN_Msk                 (_UINT32_(0x1) << FLEX_TWI_CR_ACMEN_Pos)             /* (FLEX_TWI_CR) Alternative Command Mode Enable Mask */
#define FLEX_TWI_CR_ACMEN(value)              (FLEX_TWI_CR_ACMEN_Msk & (_UINT32_(value) << FLEX_TWI_CR_ACMEN_Pos)) /* Assigment of value for ACMEN in the FLEX_TWI_CR register */
#define FLEX_TWI_CR_ACMDIS_Pos                _UINT32_(17)                                         /* (FLEX_TWI_CR) Alternative Command Mode Disable Position */
#define FLEX_TWI_CR_ACMDIS_Msk                (_UINT32_(0x1) << FLEX_TWI_CR_ACMDIS_Pos)            /* (FLEX_TWI_CR) Alternative Command Mode Disable Mask */
#define FLEX_TWI_CR_ACMDIS(value)             (FLEX_TWI_CR_ACMDIS_Msk & (_UINT32_(value) << FLEX_TWI_CR_ACMDIS_Pos)) /* Assigment of value for ACMDIS in the FLEX_TWI_CR register */
#define FLEX_TWI_CR_THRCLR_Pos                _UINT32_(24)                                         /* (FLEX_TWI_CR) Transmit Holding Register Clear Position */
#define FLEX_TWI_CR_THRCLR_Msk                (_UINT32_(0x1) << FLEX_TWI_CR_THRCLR_Pos)            /* (FLEX_TWI_CR) Transmit Holding Register Clear Mask */
#define FLEX_TWI_CR_THRCLR(value)             (FLEX_TWI_CR_THRCLR_Msk & (_UINT32_(value) << FLEX_TWI_CR_THRCLR_Pos)) /* Assigment of value for THRCLR in the FLEX_TWI_CR register */
#define FLEX_TWI_CR_LOCKCLR_Pos               _UINT32_(26)                                         /* (FLEX_TWI_CR) Lock Clear Position */
#define FLEX_TWI_CR_LOCKCLR_Msk               (_UINT32_(0x1) << FLEX_TWI_CR_LOCKCLR_Pos)           /* (FLEX_TWI_CR) Lock Clear Mask */
#define FLEX_TWI_CR_LOCKCLR(value)            (FLEX_TWI_CR_LOCKCLR_Msk & (_UINT32_(value) << FLEX_TWI_CR_LOCKCLR_Pos)) /* Assigment of value for LOCKCLR in the FLEX_TWI_CR register */
#define FLEX_TWI_CR_FIFOEN_Pos                _UINT32_(28)                                         /* (FLEX_TWI_CR) FIFO Enable Position */
#define FLEX_TWI_CR_FIFOEN_Msk                (_UINT32_(0x1) << FLEX_TWI_CR_FIFOEN_Pos)            /* (FLEX_TWI_CR) FIFO Enable Mask */
#define FLEX_TWI_CR_FIFOEN(value)             (FLEX_TWI_CR_FIFOEN_Msk & (_UINT32_(value) << FLEX_TWI_CR_FIFOEN_Pos)) /* Assigment of value for FIFOEN in the FLEX_TWI_CR register */
#define FLEX_TWI_CR_FIFODIS_Pos               _UINT32_(29)                                         /* (FLEX_TWI_CR) FIFO Disable Position */
#define FLEX_TWI_CR_FIFODIS_Msk               (_UINT32_(0x1) << FLEX_TWI_CR_FIFODIS_Pos)           /* (FLEX_TWI_CR) FIFO Disable Mask */
#define FLEX_TWI_CR_FIFODIS(value)            (FLEX_TWI_CR_FIFODIS_Msk & (_UINT32_(value) << FLEX_TWI_CR_FIFODIS_Pos)) /* Assigment of value for FIFODIS in the FLEX_TWI_CR register */
#define FLEX_TWI_CR_Msk                       _UINT32_(0x3503FFFF)                                 /* (FLEX_TWI_CR) Register Mask  */

/* FIFO_ENABLED mode */
#define FLEX_TWI_CR_FIFO_ENABLED_START_Pos    _UINT32_(0)                                          /* (FLEX_TWI_CR) Send a START Condition Position */
#define FLEX_TWI_CR_FIFO_ENABLED_START_Msk    (_UINT32_(0x1) << FLEX_TWI_CR_FIFO_ENABLED_START_Pos) /* (FLEX_TWI_CR) Send a START Condition Mask */
#define FLEX_TWI_CR_FIFO_ENABLED_START(value) (FLEX_TWI_CR_FIFO_ENABLED_START_Msk & (_UINT32_(value) << FLEX_TWI_CR_FIFO_ENABLED_START_Pos))
#define FLEX_TWI_CR_FIFO_ENABLED_STOP_Pos     _UINT32_(1)                                          /* (FLEX_TWI_CR) Send a STOP Condition Position */
#define FLEX_TWI_CR_FIFO_ENABLED_STOP_Msk     (_UINT32_(0x1) << FLEX_TWI_CR_FIFO_ENABLED_STOP_Pos) /* (FLEX_TWI_CR) Send a STOP Condition Mask */
#define FLEX_TWI_CR_FIFO_ENABLED_STOP(value)  (FLEX_TWI_CR_FIFO_ENABLED_STOP_Msk & (_UINT32_(value) << FLEX_TWI_CR_FIFO_ENABLED_STOP_Pos))
#define FLEX_TWI_CR_FIFO_ENABLED_MSEN_Pos     _UINT32_(2)                                          /* (FLEX_TWI_CR) TWI Host Mode Enabled Position */
#define FLEX_TWI_CR_FIFO_ENABLED_MSEN_Msk     (_UINT32_(0x1) << FLEX_TWI_CR_FIFO_ENABLED_MSEN_Pos) /* (FLEX_TWI_CR) TWI Host Mode Enabled Mask */
#define FLEX_TWI_CR_FIFO_ENABLED_MSEN(value)  (FLEX_TWI_CR_FIFO_ENABLED_MSEN_Msk & (_UINT32_(value) << FLEX_TWI_CR_FIFO_ENABLED_MSEN_Pos))
#define FLEX_TWI_CR_FIFO_ENABLED_MSDIS_Pos    _UINT32_(3)                                          /* (FLEX_TWI_CR) TWI Host Mode Disabled Position */
#define FLEX_TWI_CR_FIFO_ENABLED_MSDIS_Msk    (_UINT32_(0x1) << FLEX_TWI_CR_FIFO_ENABLED_MSDIS_Pos) /* (FLEX_TWI_CR) TWI Host Mode Disabled Mask */
#define FLEX_TWI_CR_FIFO_ENABLED_MSDIS(value) (FLEX_TWI_CR_FIFO_ENABLED_MSDIS_Msk & (_UINT32_(value) << FLEX_TWI_CR_FIFO_ENABLED_MSDIS_Pos))
#define FLEX_TWI_CR_FIFO_ENABLED_SVEN_Pos     _UINT32_(4)                                          /* (FLEX_TWI_CR) TWI Client Mode Enabled Position */
#define FLEX_TWI_CR_FIFO_ENABLED_SVEN_Msk     (_UINT32_(0x1) << FLEX_TWI_CR_FIFO_ENABLED_SVEN_Pos) /* (FLEX_TWI_CR) TWI Client Mode Enabled Mask */
#define FLEX_TWI_CR_FIFO_ENABLED_SVEN(value)  (FLEX_TWI_CR_FIFO_ENABLED_SVEN_Msk & (_UINT32_(value) << FLEX_TWI_CR_FIFO_ENABLED_SVEN_Pos))
#define FLEX_TWI_CR_FIFO_ENABLED_SVDIS_Pos    _UINT32_(5)                                          /* (FLEX_TWI_CR) TWI Client Mode Disabled Position */
#define FLEX_TWI_CR_FIFO_ENABLED_SVDIS_Msk    (_UINT32_(0x1) << FLEX_TWI_CR_FIFO_ENABLED_SVDIS_Pos) /* (FLEX_TWI_CR) TWI Client Mode Disabled Mask */
#define FLEX_TWI_CR_FIFO_ENABLED_SVDIS(value) (FLEX_TWI_CR_FIFO_ENABLED_SVDIS_Msk & (_UINT32_(value) << FLEX_TWI_CR_FIFO_ENABLED_SVDIS_Pos))
#define FLEX_TWI_CR_FIFO_ENABLED_QUICK_Pos    _UINT32_(6)                                          /* (FLEX_TWI_CR) SMBus Quick Command Position */
#define FLEX_TWI_CR_FIFO_ENABLED_QUICK_Msk    (_UINT32_(0x1) << FLEX_TWI_CR_FIFO_ENABLED_QUICK_Pos) /* (FLEX_TWI_CR) SMBus Quick Command Mask */
#define FLEX_TWI_CR_FIFO_ENABLED_QUICK(value) (FLEX_TWI_CR_FIFO_ENABLED_QUICK_Msk & (_UINT32_(value) << FLEX_TWI_CR_FIFO_ENABLED_QUICK_Pos))
#define FLEX_TWI_CR_FIFO_ENABLED_SWRST_Pos    _UINT32_(7)                                          /* (FLEX_TWI_CR) Software Reset Position */
#define FLEX_TWI_CR_FIFO_ENABLED_SWRST_Msk    (_UINT32_(0x1) << FLEX_TWI_CR_FIFO_ENABLED_SWRST_Pos) /* (FLEX_TWI_CR) Software Reset Mask */
#define FLEX_TWI_CR_FIFO_ENABLED_SWRST(value) (FLEX_TWI_CR_FIFO_ENABLED_SWRST_Msk & (_UINT32_(value) << FLEX_TWI_CR_FIFO_ENABLED_SWRST_Pos))
#define FLEX_TWI_CR_FIFO_ENABLED_HSEN_Pos     _UINT32_(8)                                          /* (FLEX_TWI_CR) TWI High-Speed Mode Enabled Position */
#define FLEX_TWI_CR_FIFO_ENABLED_HSEN_Msk     (_UINT32_(0x1) << FLEX_TWI_CR_FIFO_ENABLED_HSEN_Pos) /* (FLEX_TWI_CR) TWI High-Speed Mode Enabled Mask */
#define FLEX_TWI_CR_FIFO_ENABLED_HSEN(value)  (FLEX_TWI_CR_FIFO_ENABLED_HSEN_Msk & (_UINT32_(value) << FLEX_TWI_CR_FIFO_ENABLED_HSEN_Pos))
#define FLEX_TWI_CR_FIFO_ENABLED_HSDIS_Pos    _UINT32_(9)                                          /* (FLEX_TWI_CR) TWI High-Speed Mode Disabled Position */
#define FLEX_TWI_CR_FIFO_ENABLED_HSDIS_Msk    (_UINT32_(0x1) << FLEX_TWI_CR_FIFO_ENABLED_HSDIS_Pos) /* (FLEX_TWI_CR) TWI High-Speed Mode Disabled Mask */
#define FLEX_TWI_CR_FIFO_ENABLED_HSDIS(value) (FLEX_TWI_CR_FIFO_ENABLED_HSDIS_Msk & (_UINT32_(value) << FLEX_TWI_CR_FIFO_ENABLED_HSDIS_Pos))
#define FLEX_TWI_CR_FIFO_ENABLED_SMBEN_Pos    _UINT32_(10)                                         /* (FLEX_TWI_CR) SMBus Mode Enabled Position */
#define FLEX_TWI_CR_FIFO_ENABLED_SMBEN_Msk    (_UINT32_(0x1) << FLEX_TWI_CR_FIFO_ENABLED_SMBEN_Pos) /* (FLEX_TWI_CR) SMBus Mode Enabled Mask */
#define FLEX_TWI_CR_FIFO_ENABLED_SMBEN(value) (FLEX_TWI_CR_FIFO_ENABLED_SMBEN_Msk & (_UINT32_(value) << FLEX_TWI_CR_FIFO_ENABLED_SMBEN_Pos))
#define FLEX_TWI_CR_FIFO_ENABLED_SMBDIS_Pos   _UINT32_(11)                                         /* (FLEX_TWI_CR) SMBus Mode Disabled Position */
#define FLEX_TWI_CR_FIFO_ENABLED_SMBDIS_Msk   (_UINT32_(0x1) << FLEX_TWI_CR_FIFO_ENABLED_SMBDIS_Pos) /* (FLEX_TWI_CR) SMBus Mode Disabled Mask */
#define FLEX_TWI_CR_FIFO_ENABLED_SMBDIS(value) (FLEX_TWI_CR_FIFO_ENABLED_SMBDIS_Msk & (_UINT32_(value) << FLEX_TWI_CR_FIFO_ENABLED_SMBDIS_Pos))
#define FLEX_TWI_CR_FIFO_ENABLED_PECEN_Pos    _UINT32_(12)                                         /* (FLEX_TWI_CR) Packet Error Checking Enable Position */
#define FLEX_TWI_CR_FIFO_ENABLED_PECEN_Msk    (_UINT32_(0x1) << FLEX_TWI_CR_FIFO_ENABLED_PECEN_Pos) /* (FLEX_TWI_CR) Packet Error Checking Enable Mask */
#define FLEX_TWI_CR_FIFO_ENABLED_PECEN(value) (FLEX_TWI_CR_FIFO_ENABLED_PECEN_Msk & (_UINT32_(value) << FLEX_TWI_CR_FIFO_ENABLED_PECEN_Pos))
#define FLEX_TWI_CR_FIFO_ENABLED_PECDIS_Pos   _UINT32_(13)                                         /* (FLEX_TWI_CR) Packet Error Checking Disable Position */
#define FLEX_TWI_CR_FIFO_ENABLED_PECDIS_Msk   (_UINT32_(0x1) << FLEX_TWI_CR_FIFO_ENABLED_PECDIS_Pos) /* (FLEX_TWI_CR) Packet Error Checking Disable Mask */
#define FLEX_TWI_CR_FIFO_ENABLED_PECDIS(value) (FLEX_TWI_CR_FIFO_ENABLED_PECDIS_Msk & (_UINT32_(value) << FLEX_TWI_CR_FIFO_ENABLED_PECDIS_Pos))
#define FLEX_TWI_CR_FIFO_ENABLED_PECRQ_Pos    _UINT32_(14)                                         /* (FLEX_TWI_CR) PEC Request Position */
#define FLEX_TWI_CR_FIFO_ENABLED_PECRQ_Msk    (_UINT32_(0x1) << FLEX_TWI_CR_FIFO_ENABLED_PECRQ_Pos) /* (FLEX_TWI_CR) PEC Request Mask */
#define FLEX_TWI_CR_FIFO_ENABLED_PECRQ(value) (FLEX_TWI_CR_FIFO_ENABLED_PECRQ_Msk & (_UINT32_(value) << FLEX_TWI_CR_FIFO_ENABLED_PECRQ_Pos))
#define FLEX_TWI_CR_FIFO_ENABLED_CLEAR_Pos    _UINT32_(15)                                         /* (FLEX_TWI_CR) Bus CLEAR Command Position */
#define FLEX_TWI_CR_FIFO_ENABLED_CLEAR_Msk    (_UINT32_(0x1) << FLEX_TWI_CR_FIFO_ENABLED_CLEAR_Pos) /* (FLEX_TWI_CR) Bus CLEAR Command Mask */
#define FLEX_TWI_CR_FIFO_ENABLED_CLEAR(value) (FLEX_TWI_CR_FIFO_ENABLED_CLEAR_Msk & (_UINT32_(value) << FLEX_TWI_CR_FIFO_ENABLED_CLEAR_Pos))
#define FLEX_TWI_CR_FIFO_ENABLED_ACMEN_Pos    _UINT32_(16)                                         /* (FLEX_TWI_CR) Alternative Command Mode Enable Position */
#define FLEX_TWI_CR_FIFO_ENABLED_ACMEN_Msk    (_UINT32_(0x1) << FLEX_TWI_CR_FIFO_ENABLED_ACMEN_Pos) /* (FLEX_TWI_CR) Alternative Command Mode Enable Mask */
#define FLEX_TWI_CR_FIFO_ENABLED_ACMEN(value) (FLEX_TWI_CR_FIFO_ENABLED_ACMEN_Msk & (_UINT32_(value) << FLEX_TWI_CR_FIFO_ENABLED_ACMEN_Pos))
#define FLEX_TWI_CR_FIFO_ENABLED_ACMDIS_Pos   _UINT32_(17)                                         /* (FLEX_TWI_CR) Alternative Command Mode Disable Position */
#define FLEX_TWI_CR_FIFO_ENABLED_ACMDIS_Msk   (_UINT32_(0x1) << FLEX_TWI_CR_FIFO_ENABLED_ACMDIS_Pos) /* (FLEX_TWI_CR) Alternative Command Mode Disable Mask */
#define FLEX_TWI_CR_FIFO_ENABLED_ACMDIS(value) (FLEX_TWI_CR_FIFO_ENABLED_ACMDIS_Msk & (_UINT32_(value) << FLEX_TWI_CR_FIFO_ENABLED_ACMDIS_Pos))
#define FLEX_TWI_CR_FIFO_ENABLED_TXFCLR_Pos   _UINT32_(24)                                         /* (FLEX_TWI_CR) Transmit FIFO Clear Position */
#define FLEX_TWI_CR_FIFO_ENABLED_TXFCLR_Msk   (_UINT32_(0x1) << FLEX_TWI_CR_FIFO_ENABLED_TXFCLR_Pos) /* (FLEX_TWI_CR) Transmit FIFO Clear Mask */
#define FLEX_TWI_CR_FIFO_ENABLED_TXFCLR(value) (FLEX_TWI_CR_FIFO_ENABLED_TXFCLR_Msk & (_UINT32_(value) << FLEX_TWI_CR_FIFO_ENABLED_TXFCLR_Pos))
#define FLEX_TWI_CR_FIFO_ENABLED_RXFCLR_Pos   _UINT32_(25)                                         /* (FLEX_TWI_CR) Receive FIFO Clear Position */
#define FLEX_TWI_CR_FIFO_ENABLED_RXFCLR_Msk   (_UINT32_(0x1) << FLEX_TWI_CR_FIFO_ENABLED_RXFCLR_Pos) /* (FLEX_TWI_CR) Receive FIFO Clear Mask */
#define FLEX_TWI_CR_FIFO_ENABLED_RXFCLR(value) (FLEX_TWI_CR_FIFO_ENABLED_RXFCLR_Msk & (_UINT32_(value) << FLEX_TWI_CR_FIFO_ENABLED_RXFCLR_Pos))
#define FLEX_TWI_CR_FIFO_ENABLED_TXFLCLR_Pos  _UINT32_(26)                                         /* (FLEX_TWI_CR) Transmit FIFO Lock CLEAR Position */
#define FLEX_TWI_CR_FIFO_ENABLED_TXFLCLR_Msk  (_UINT32_(0x1) << FLEX_TWI_CR_FIFO_ENABLED_TXFLCLR_Pos) /* (FLEX_TWI_CR) Transmit FIFO Lock CLEAR Mask */
#define FLEX_TWI_CR_FIFO_ENABLED_TXFLCLR(value) (FLEX_TWI_CR_FIFO_ENABLED_TXFLCLR_Msk & (_UINT32_(value) << FLEX_TWI_CR_FIFO_ENABLED_TXFLCLR_Pos))
#define FLEX_TWI_CR_FIFO_ENABLED_FIFOEN_Pos   _UINT32_(28)                                         /* (FLEX_TWI_CR) FIFO Enable Position */
#define FLEX_TWI_CR_FIFO_ENABLED_FIFOEN_Msk   (_UINT32_(0x1) << FLEX_TWI_CR_FIFO_ENABLED_FIFOEN_Pos) /* (FLEX_TWI_CR) FIFO Enable Mask */
#define FLEX_TWI_CR_FIFO_ENABLED_FIFOEN(value) (FLEX_TWI_CR_FIFO_ENABLED_FIFOEN_Msk & (_UINT32_(value) << FLEX_TWI_CR_FIFO_ENABLED_FIFOEN_Pos))
#define FLEX_TWI_CR_FIFO_ENABLED_FIFODIS_Pos  _UINT32_(29)                                         /* (FLEX_TWI_CR) FIFO Disable Position */
#define FLEX_TWI_CR_FIFO_ENABLED_FIFODIS_Msk  (_UINT32_(0x1) << FLEX_TWI_CR_FIFO_ENABLED_FIFODIS_Pos) /* (FLEX_TWI_CR) FIFO Disable Mask */
#define FLEX_TWI_CR_FIFO_ENABLED_FIFODIS(value) (FLEX_TWI_CR_FIFO_ENABLED_FIFODIS_Msk & (_UINT32_(value) << FLEX_TWI_CR_FIFO_ENABLED_FIFODIS_Pos))
#define FLEX_TWI_CR_FIFO_ENABLED_Msk          _UINT32_(0x3703FFFF)                                  /* (FLEX_TWI_CR_FIFO_ENABLED) Register Mask  */


/* -------- FLEX_TWI_MMR : (FLEXCOM Offset: 0x604) (R/W 32) TWI Host Mode Register -------- */
#define FLEX_TWI_MMR_IADRSZ_Pos               _UINT32_(8)                                          /* (FLEX_TWI_MMR) Internal Device Address Size Position */
#define FLEX_TWI_MMR_IADRSZ_Msk               (_UINT32_(0x3) << FLEX_TWI_MMR_IADRSZ_Pos)           /* (FLEX_TWI_MMR) Internal Device Address Size Mask */
#define FLEX_TWI_MMR_IADRSZ(value)            (FLEX_TWI_MMR_IADRSZ_Msk & (_UINT32_(value) << FLEX_TWI_MMR_IADRSZ_Pos)) /* Assigment of value for IADRSZ in the FLEX_TWI_MMR register */
#define   FLEX_TWI_MMR_IADRSZ_NONE_Val        _UINT32_(0x0)                                        /* (FLEX_TWI_MMR) No internal device address  */
#define   FLEX_TWI_MMR_IADRSZ_1_BYTE_Val      _UINT32_(0x1)                                        /* (FLEX_TWI_MMR) One-byte internal device address  */
#define   FLEX_TWI_MMR_IADRSZ_2_BYTE_Val      _UINT32_(0x2)                                        /* (FLEX_TWI_MMR) Two-byte internal device address  */
#define   FLEX_TWI_MMR_IADRSZ_3_BYTE_Val      _UINT32_(0x3)                                        /* (FLEX_TWI_MMR) Three-byte internal device address  */
#define FLEX_TWI_MMR_IADRSZ_NONE              (FLEX_TWI_MMR_IADRSZ_NONE_Val << FLEX_TWI_MMR_IADRSZ_Pos) /* (FLEX_TWI_MMR) No internal device address Position  */
#define FLEX_TWI_MMR_IADRSZ_1_BYTE            (FLEX_TWI_MMR_IADRSZ_1_BYTE_Val << FLEX_TWI_MMR_IADRSZ_Pos) /* (FLEX_TWI_MMR) One-byte internal device address Position  */
#define FLEX_TWI_MMR_IADRSZ_2_BYTE            (FLEX_TWI_MMR_IADRSZ_2_BYTE_Val << FLEX_TWI_MMR_IADRSZ_Pos) /* (FLEX_TWI_MMR) Two-byte internal device address Position  */
#define FLEX_TWI_MMR_IADRSZ_3_BYTE            (FLEX_TWI_MMR_IADRSZ_3_BYTE_Val << FLEX_TWI_MMR_IADRSZ_Pos) /* (FLEX_TWI_MMR) Three-byte internal device address Position  */
#define FLEX_TWI_MMR_MREAD_Pos                _UINT32_(12)                                         /* (FLEX_TWI_MMR) Host Read Direction Position */
#define FLEX_TWI_MMR_MREAD_Msk                (_UINT32_(0x1) << FLEX_TWI_MMR_MREAD_Pos)            /* (FLEX_TWI_MMR) Host Read Direction Mask */
#define FLEX_TWI_MMR_MREAD(value)             (FLEX_TWI_MMR_MREAD_Msk & (_UINT32_(value) << FLEX_TWI_MMR_MREAD_Pos)) /* Assigment of value for MREAD in the FLEX_TWI_MMR register */
#define FLEX_TWI_MMR_SCLRBL_Pos               _UINT32_(13)                                         /* (FLEX_TWI_MMR) SCL Rise Boost Level Position */
#define FLEX_TWI_MMR_SCLRBL_Msk               (_UINT32_(0x3) << FLEX_TWI_MMR_SCLRBL_Pos)           /* (FLEX_TWI_MMR) SCL Rise Boost Level Mask */
#define FLEX_TWI_MMR_SCLRBL(value)            (FLEX_TWI_MMR_SCLRBL_Msk & (_UINT32_(value) << FLEX_TWI_MMR_SCLRBL_Pos)) /* Assigment of value for SCLRBL in the FLEX_TWI_MMR register */
#define FLEX_TWI_MMR_DADR_Pos                 _UINT32_(16)                                         /* (FLEX_TWI_MMR) Device Address Position */
#define FLEX_TWI_MMR_DADR_Msk                 (_UINT32_(0x7F) << FLEX_TWI_MMR_DADR_Pos)            /* (FLEX_TWI_MMR) Device Address Mask */
#define FLEX_TWI_MMR_DADR(value)              (FLEX_TWI_MMR_DADR_Msk & (_UINT32_(value) << FLEX_TWI_MMR_DADR_Pos)) /* Assigment of value for DADR in the FLEX_TWI_MMR register */
#define FLEX_TWI_MMR_NOAP_Pos                 _UINT32_(24)                                         /* (FLEX_TWI_MMR) No Auto-Stop On NACK Error Position */
#define FLEX_TWI_MMR_NOAP_Msk                 (_UINT32_(0x1) << FLEX_TWI_MMR_NOAP_Pos)             /* (FLEX_TWI_MMR) No Auto-Stop On NACK Error Mask */
#define FLEX_TWI_MMR_NOAP(value)              (FLEX_TWI_MMR_NOAP_Msk & (_UINT32_(value) << FLEX_TWI_MMR_NOAP_Pos)) /* Assigment of value for NOAP in the FLEX_TWI_MMR register */
#define FLEX_TWI_MMR_Msk                      _UINT32_(0x017F7300)                                 /* (FLEX_TWI_MMR) Register Mask  */


/* -------- FLEX_TWI_SMR : (FLEXCOM Offset: 0x608) (R/W 32) TWI Client Mode Register -------- */
#define FLEX_TWI_SMR_NACKEN_Pos               _UINT32_(0)                                          /* (FLEX_TWI_SMR) Client Receiver Data Phase NACK Enable Position */
#define FLEX_TWI_SMR_NACKEN_Msk               (_UINT32_(0x1) << FLEX_TWI_SMR_NACKEN_Pos)           /* (FLEX_TWI_SMR) Client Receiver Data Phase NACK Enable Mask */
#define FLEX_TWI_SMR_NACKEN(value)            (FLEX_TWI_SMR_NACKEN_Msk & (_UINT32_(value) << FLEX_TWI_SMR_NACKEN_Pos)) /* Assigment of value for NACKEN in the FLEX_TWI_SMR register */
#define FLEX_TWI_SMR_SMDA_Pos                 _UINT32_(2)                                          /* (FLEX_TWI_SMR) SMBus Default Address Position */
#define FLEX_TWI_SMR_SMDA_Msk                 (_UINT32_(0x1) << FLEX_TWI_SMR_SMDA_Pos)             /* (FLEX_TWI_SMR) SMBus Default Address Mask */
#define FLEX_TWI_SMR_SMDA(value)              (FLEX_TWI_SMR_SMDA_Msk & (_UINT32_(value) << FLEX_TWI_SMR_SMDA_Pos)) /* Assigment of value for SMDA in the FLEX_TWI_SMR register */
#define FLEX_TWI_SMR_SMHH_Pos                 _UINT32_(3)                                          /* (FLEX_TWI_SMR) SMBus Host Header Position */
#define FLEX_TWI_SMR_SMHH_Msk                 (_UINT32_(0x1) << FLEX_TWI_SMR_SMHH_Pos)             /* (FLEX_TWI_SMR) SMBus Host Header Mask */
#define FLEX_TWI_SMR_SMHH(value)              (FLEX_TWI_SMR_SMHH_Msk & (_UINT32_(value) << FLEX_TWI_SMR_SMHH_Pos)) /* Assigment of value for SMHH in the FLEX_TWI_SMR register */
#define FLEX_TWI_SMR_SADAT_Pos                _UINT32_(4)                                          /* (FLEX_TWI_SMR) Client Address Treated as Data Position */
#define FLEX_TWI_SMR_SADAT_Msk                (_UINT32_(0x1) << FLEX_TWI_SMR_SADAT_Pos)            /* (FLEX_TWI_SMR) Client Address Treated as Data Mask */
#define FLEX_TWI_SMR_SADAT(value)             (FLEX_TWI_SMR_SADAT_Msk & (_UINT32_(value) << FLEX_TWI_SMR_SADAT_Pos)) /* Assigment of value for SADAT in the FLEX_TWI_SMR register */
#define FLEX_TWI_SMR_BSEL_Pos                 _UINT32_(5)                                          /* (FLEX_TWI_SMR) TWI Bus Selection Position */
#define FLEX_TWI_SMR_BSEL_Msk                 (_UINT32_(0x1) << FLEX_TWI_SMR_BSEL_Pos)             /* (FLEX_TWI_SMR) TWI Bus Selection Mask */
#define FLEX_TWI_SMR_BSEL(value)              (FLEX_TWI_SMR_BSEL_Msk & (_UINT32_(value) << FLEX_TWI_SMR_BSEL_Pos)) /* Assigment of value for BSEL in the FLEX_TWI_SMR register */
#define FLEX_TWI_SMR_SCLWSDIS_Pos             _UINT32_(6)                                          /* (FLEX_TWI_SMR) Clock Wait State Disable Position */
#define FLEX_TWI_SMR_SCLWSDIS_Msk             (_UINT32_(0x1) << FLEX_TWI_SMR_SCLWSDIS_Pos)         /* (FLEX_TWI_SMR) Clock Wait State Disable Mask */
#define FLEX_TWI_SMR_SCLWSDIS(value)          (FLEX_TWI_SMR_SCLWSDIS_Msk & (_UINT32_(value) << FLEX_TWI_SMR_SCLWSDIS_Pos)) /* Assigment of value for SCLWSDIS in the FLEX_TWI_SMR register */
#define FLEX_TWI_SMR_SNIFF_Pos                _UINT32_(7)                                          /* (FLEX_TWI_SMR) Client Sniffer Mode Position */
#define FLEX_TWI_SMR_SNIFF_Msk                (_UINT32_(0x1) << FLEX_TWI_SMR_SNIFF_Pos)            /* (FLEX_TWI_SMR) Client Sniffer Mode Mask */
#define FLEX_TWI_SMR_SNIFF(value)             (FLEX_TWI_SMR_SNIFF_Msk & (_UINT32_(value) << FLEX_TWI_SMR_SNIFF_Pos)) /* Assigment of value for SNIFF in the FLEX_TWI_SMR register */
#define FLEX_TWI_SMR_MASK_Pos                 _UINT32_(8)                                          /* (FLEX_TWI_SMR) Client Address Mask Position */
#define FLEX_TWI_SMR_MASK_Msk                 (_UINT32_(0x7F) << FLEX_TWI_SMR_MASK_Pos)            /* (FLEX_TWI_SMR) Client Address Mask Mask */
#define FLEX_TWI_SMR_MASK(value)              (FLEX_TWI_SMR_MASK_Msk & (_UINT32_(value) << FLEX_TWI_SMR_MASK_Pos)) /* Assigment of value for MASK in the FLEX_TWI_SMR register */
#define FLEX_TWI_SMR_SADR_Pos                 _UINT32_(16)                                         /* (FLEX_TWI_SMR) Client Address Position */
#define FLEX_TWI_SMR_SADR_Msk                 (_UINT32_(0x7F) << FLEX_TWI_SMR_SADR_Pos)            /* (FLEX_TWI_SMR) Client Address Mask */
#define FLEX_TWI_SMR_SADR(value)              (FLEX_TWI_SMR_SADR_Msk & (_UINT32_(value) << FLEX_TWI_SMR_SADR_Pos)) /* Assigment of value for SADR in the FLEX_TWI_SMR register */
#define FLEX_TWI_SMR_SADR1EN_Pos              _UINT32_(28)                                         /* (FLEX_TWI_SMR) Client Address 1 Enable Position */
#define FLEX_TWI_SMR_SADR1EN_Msk              (_UINT32_(0x1) << FLEX_TWI_SMR_SADR1EN_Pos)          /* (FLEX_TWI_SMR) Client Address 1 Enable Mask */
#define FLEX_TWI_SMR_SADR1EN(value)           (FLEX_TWI_SMR_SADR1EN_Msk & (_UINT32_(value) << FLEX_TWI_SMR_SADR1EN_Pos)) /* Assigment of value for SADR1EN in the FLEX_TWI_SMR register */
#define FLEX_TWI_SMR_SADR2EN_Pos              _UINT32_(29)                                         /* (FLEX_TWI_SMR) Client Address 2 Enable Position */
#define FLEX_TWI_SMR_SADR2EN_Msk              (_UINT32_(0x1) << FLEX_TWI_SMR_SADR2EN_Pos)          /* (FLEX_TWI_SMR) Client Address 2 Enable Mask */
#define FLEX_TWI_SMR_SADR2EN(value)           (FLEX_TWI_SMR_SADR2EN_Msk & (_UINT32_(value) << FLEX_TWI_SMR_SADR2EN_Pos)) /* Assigment of value for SADR2EN in the FLEX_TWI_SMR register */
#define FLEX_TWI_SMR_SADR3EN_Pos              _UINT32_(30)                                         /* (FLEX_TWI_SMR) Client Address 3 Enable Position */
#define FLEX_TWI_SMR_SADR3EN_Msk              (_UINT32_(0x1) << FLEX_TWI_SMR_SADR3EN_Pos)          /* (FLEX_TWI_SMR) Client Address 3 Enable Mask */
#define FLEX_TWI_SMR_SADR3EN(value)           (FLEX_TWI_SMR_SADR3EN_Msk & (_UINT32_(value) << FLEX_TWI_SMR_SADR3EN_Pos)) /* Assigment of value for SADR3EN in the FLEX_TWI_SMR register */
#define FLEX_TWI_SMR_DATAMEN_Pos              _UINT32_(31)                                         /* (FLEX_TWI_SMR) Data Matching Enable Position */
#define FLEX_TWI_SMR_DATAMEN_Msk              (_UINT32_(0x1) << FLEX_TWI_SMR_DATAMEN_Pos)          /* (FLEX_TWI_SMR) Data Matching Enable Mask */
#define FLEX_TWI_SMR_DATAMEN(value)           (FLEX_TWI_SMR_DATAMEN_Msk & (_UINT32_(value) << FLEX_TWI_SMR_DATAMEN_Pos)) /* Assigment of value for DATAMEN in the FLEX_TWI_SMR register */
#define FLEX_TWI_SMR_Msk                      _UINT32_(0xF07F7FFD)                                 /* (FLEX_TWI_SMR) Register Mask  */


/* -------- FLEX_TWI_IADR : (FLEXCOM Offset: 0x60C) (R/W 32) TWI Internal Address Register -------- */
#define FLEX_TWI_IADR_IADR_Pos                _UINT32_(0)                                          /* (FLEX_TWI_IADR) Internal Address Position */
#define FLEX_TWI_IADR_IADR_Msk                (_UINT32_(0xFFFFFF) << FLEX_TWI_IADR_IADR_Pos)       /* (FLEX_TWI_IADR) Internal Address Mask */
#define FLEX_TWI_IADR_IADR(value)             (FLEX_TWI_IADR_IADR_Msk & (_UINT32_(value) << FLEX_TWI_IADR_IADR_Pos)) /* Assigment of value for IADR in the FLEX_TWI_IADR register */
#define FLEX_TWI_IADR_Msk                     _UINT32_(0x00FFFFFF)                                 /* (FLEX_TWI_IADR) Register Mask  */


/* -------- FLEX_TWI_CWGR : (FLEXCOM Offset: 0x610) (R/W 32) TWI Clock Waveform Generator Register -------- */
#define FLEX_TWI_CWGR_CLDIV_Pos               _UINT32_(0)                                          /* (FLEX_TWI_CWGR) Clock Low Divider Position */
#define FLEX_TWI_CWGR_CLDIV_Msk               (_UINT32_(0xFF) << FLEX_TWI_CWGR_CLDIV_Pos)          /* (FLEX_TWI_CWGR) Clock Low Divider Mask */
#define FLEX_TWI_CWGR_CLDIV(value)            (FLEX_TWI_CWGR_CLDIV_Msk & (_UINT32_(value) << FLEX_TWI_CWGR_CLDIV_Pos)) /* Assigment of value for CLDIV in the FLEX_TWI_CWGR register */
#define FLEX_TWI_CWGR_CHDIV_Pos               _UINT32_(8)                                          /* (FLEX_TWI_CWGR) Clock High Divider Position */
#define FLEX_TWI_CWGR_CHDIV_Msk               (_UINT32_(0xFF) << FLEX_TWI_CWGR_CHDIV_Pos)          /* (FLEX_TWI_CWGR) Clock High Divider Mask */
#define FLEX_TWI_CWGR_CHDIV(value)            (FLEX_TWI_CWGR_CHDIV_Msk & (_UINT32_(value) << FLEX_TWI_CWGR_CHDIV_Pos)) /* Assigment of value for CHDIV in the FLEX_TWI_CWGR register */
#define FLEX_TWI_CWGR_CKDIV_Pos               _UINT32_(16)                                         /* (FLEX_TWI_CWGR) Clock Divider Position */
#define FLEX_TWI_CWGR_CKDIV_Msk               (_UINT32_(0x7) << FLEX_TWI_CWGR_CKDIV_Pos)           /* (FLEX_TWI_CWGR) Clock Divider Mask */
#define FLEX_TWI_CWGR_CKDIV(value)            (FLEX_TWI_CWGR_CKDIV_Msk & (_UINT32_(value) << FLEX_TWI_CWGR_CKDIV_Pos)) /* Assigment of value for CKDIV in the FLEX_TWI_CWGR register */
#define FLEX_TWI_CWGR_BRSRCCLK_Pos            _UINT32_(20)                                         /* (FLEX_TWI_CWGR) Bit Rate Source Clock Position */
#define FLEX_TWI_CWGR_BRSRCCLK_Msk            (_UINT32_(0x1) << FLEX_TWI_CWGR_BRSRCCLK_Pos)        /* (FLEX_TWI_CWGR) Bit Rate Source Clock Mask */
#define FLEX_TWI_CWGR_BRSRCCLK(value)         (FLEX_TWI_CWGR_BRSRCCLK_Msk & (_UINT32_(value) << FLEX_TWI_CWGR_BRSRCCLK_Pos)) /* Assigment of value for BRSRCCLK in the FLEX_TWI_CWGR register */
#define   FLEX_TWI_CWGR_BRSRCCLK_PERIPH_CLK_Val _UINT32_(0x0)                                        /* (FLEX_TWI_CWGR) The peripheral clock is the source clock for the bit rate generation.  */
#define   FLEX_TWI_CWGR_BRSRCCLK_GCLK_Val     _UINT32_(0x1)                                        /* (FLEX_TWI_CWGR) GCLK is the source clock for the bit rate generation, thus the bit rate can be independent of the core/peripheral clock.  */
#define FLEX_TWI_CWGR_BRSRCCLK_PERIPH_CLK     (FLEX_TWI_CWGR_BRSRCCLK_PERIPH_CLK_Val << FLEX_TWI_CWGR_BRSRCCLK_Pos) /* (FLEX_TWI_CWGR) The peripheral clock is the source clock for the bit rate generation. Position  */
#define FLEX_TWI_CWGR_BRSRCCLK_GCLK           (FLEX_TWI_CWGR_BRSRCCLK_GCLK_Val << FLEX_TWI_CWGR_BRSRCCLK_Pos) /* (FLEX_TWI_CWGR) GCLK is the source clock for the bit rate generation, thus the bit rate can be independent of the core/peripheral clock. Position  */
#define FLEX_TWI_CWGR_HOLD_Pos                _UINT32_(24)                                         /* (FLEX_TWI_CWGR) TWD Hold Time Versus TWCK Falling Position */
#define FLEX_TWI_CWGR_HOLD_Msk                (_UINT32_(0x3F) << FLEX_TWI_CWGR_HOLD_Pos)           /* (FLEX_TWI_CWGR) TWD Hold Time Versus TWCK Falling Mask */
#define FLEX_TWI_CWGR_HOLD(value)             (FLEX_TWI_CWGR_HOLD_Msk & (_UINT32_(value) << FLEX_TWI_CWGR_HOLD_Pos)) /* Assigment of value for HOLD in the FLEX_TWI_CWGR register */
#define FLEX_TWI_CWGR_Msk                     _UINT32_(0x3F17FFFF)                                 /* (FLEX_TWI_CWGR) Register Mask  */


/* -------- FLEX_TWI_SR : (FLEXCOM Offset: 0x620) ( R/ 32) TWI Status Register -------- */
#define FLEX_TWI_SR_TXCOMP_Pos                _UINT32_(0)                                          /* (FLEX_TWI_SR) Transmission Completed (cleared by writing FLEX_TWI_THR) Position */
#define FLEX_TWI_SR_TXCOMP_Msk                (_UINT32_(0x1) << FLEX_TWI_SR_TXCOMP_Pos)            /* (FLEX_TWI_SR) Transmission Completed (cleared by writing FLEX_TWI_THR) Mask */
#define FLEX_TWI_SR_TXCOMP(value)             (FLEX_TWI_SR_TXCOMP_Msk & (_UINT32_(value) << FLEX_TWI_SR_TXCOMP_Pos)) /* Assigment of value for TXCOMP in the FLEX_TWI_SR register */
#define FLEX_TWI_SR_RXRDY_Pos                 _UINT32_(1)                                          /* (FLEX_TWI_SR) Receive Holding Register Ready (cleared when reading FLEX_TWI_RHR) Position */
#define FLEX_TWI_SR_RXRDY_Msk                 (_UINT32_(0x1) << FLEX_TWI_SR_RXRDY_Pos)             /* (FLEX_TWI_SR) Receive Holding Register Ready (cleared when reading FLEX_TWI_RHR) Mask */
#define FLEX_TWI_SR_RXRDY(value)              (FLEX_TWI_SR_RXRDY_Msk & (_UINT32_(value) << FLEX_TWI_SR_RXRDY_Pos)) /* Assigment of value for RXRDY in the FLEX_TWI_SR register */
#define FLEX_TWI_SR_TXRDY_Pos                 _UINT32_(2)                                          /* (FLEX_TWI_SR) Transmit Holding Register Ready (cleared by writing FLEX_TWI_THR) Position */
#define FLEX_TWI_SR_TXRDY_Msk                 (_UINT32_(0x1) << FLEX_TWI_SR_TXRDY_Pos)             /* (FLEX_TWI_SR) Transmit Holding Register Ready (cleared by writing FLEX_TWI_THR) Mask */
#define FLEX_TWI_SR_TXRDY(value)              (FLEX_TWI_SR_TXRDY_Msk & (_UINT32_(value) << FLEX_TWI_SR_TXRDY_Pos)) /* Assigment of value for TXRDY in the FLEX_TWI_SR register */
#define FLEX_TWI_SR_SVREAD_Pos                _UINT32_(3)                                          /* (FLEX_TWI_SR) Client Read Position */
#define FLEX_TWI_SR_SVREAD_Msk                (_UINT32_(0x1) << FLEX_TWI_SR_SVREAD_Pos)            /* (FLEX_TWI_SR) Client Read Mask */
#define FLEX_TWI_SR_SVREAD(value)             (FLEX_TWI_SR_SVREAD_Msk & (_UINT32_(value) << FLEX_TWI_SR_SVREAD_Pos)) /* Assigment of value for SVREAD in the FLEX_TWI_SR register */
#define FLEX_TWI_SR_SVACC_Pos                 _UINT32_(4)                                          /* (FLEX_TWI_SR) Client Access Position */
#define FLEX_TWI_SR_SVACC_Msk                 (_UINT32_(0x1) << FLEX_TWI_SR_SVACC_Pos)             /* (FLEX_TWI_SR) Client Access Mask */
#define FLEX_TWI_SR_SVACC(value)              (FLEX_TWI_SR_SVACC_Msk & (_UINT32_(value) << FLEX_TWI_SR_SVACC_Pos)) /* Assigment of value for SVACC in the FLEX_TWI_SR register */
#define FLEX_TWI_SR_GACC_Pos                  _UINT32_(5)                                          /* (FLEX_TWI_SR) General Call Access (cleared on read) Position */
#define FLEX_TWI_SR_GACC_Msk                  (_UINT32_(0x1) << FLEX_TWI_SR_GACC_Pos)              /* (FLEX_TWI_SR) General Call Access (cleared on read) Mask */
#define FLEX_TWI_SR_GACC(value)               (FLEX_TWI_SR_GACC_Msk & (_UINT32_(value) << FLEX_TWI_SR_GACC_Pos)) /* Assigment of value for GACC in the FLEX_TWI_SR register */
#define FLEX_TWI_SR_OVRE_Pos                  _UINT32_(6)                                          /* (FLEX_TWI_SR) Overrun Error (cleared on read) Position */
#define FLEX_TWI_SR_OVRE_Msk                  (_UINT32_(0x1) << FLEX_TWI_SR_OVRE_Pos)              /* (FLEX_TWI_SR) Overrun Error (cleared on read) Mask */
#define FLEX_TWI_SR_OVRE(value)               (FLEX_TWI_SR_OVRE_Msk & (_UINT32_(value) << FLEX_TWI_SR_OVRE_Pos)) /* Assigment of value for OVRE in the FLEX_TWI_SR register */
#define FLEX_TWI_SR_UNRE_Pos                  _UINT32_(7)                                          /* (FLEX_TWI_SR) Underrun Error (cleared on read) Position */
#define FLEX_TWI_SR_UNRE_Msk                  (_UINT32_(0x1) << FLEX_TWI_SR_UNRE_Pos)              /* (FLEX_TWI_SR) Underrun Error (cleared on read) Mask */
#define FLEX_TWI_SR_UNRE(value)               (FLEX_TWI_SR_UNRE_Msk & (_UINT32_(value) << FLEX_TWI_SR_UNRE_Pos)) /* Assigment of value for UNRE in the FLEX_TWI_SR register */
#define FLEX_TWI_SR_NACK_Pos                  _UINT32_(8)                                          /* (FLEX_TWI_SR) Not Acknowledged (cleared on read) Position */
#define FLEX_TWI_SR_NACK_Msk                  (_UINT32_(0x1) << FLEX_TWI_SR_NACK_Pos)              /* (FLEX_TWI_SR) Not Acknowledged (cleared on read) Mask */
#define FLEX_TWI_SR_NACK(value)               (FLEX_TWI_SR_NACK_Msk & (_UINT32_(value) << FLEX_TWI_SR_NACK_Pos)) /* Assigment of value for NACK in the FLEX_TWI_SR register */
#define FLEX_TWI_SR_ARBLST_Pos                _UINT32_(9)                                          /* (FLEX_TWI_SR) Arbitration Lost (cleared on read) Position */
#define FLEX_TWI_SR_ARBLST_Msk                (_UINT32_(0x1) << FLEX_TWI_SR_ARBLST_Pos)            /* (FLEX_TWI_SR) Arbitration Lost (cleared on read) Mask */
#define FLEX_TWI_SR_ARBLST(value)             (FLEX_TWI_SR_ARBLST_Msk & (_UINT32_(value) << FLEX_TWI_SR_ARBLST_Pos)) /* Assigment of value for ARBLST in the FLEX_TWI_SR register */
#define FLEX_TWI_SR_SCLWS_Pos                 _UINT32_(10)                                         /* (FLEX_TWI_SR) Clock Wait State Position */
#define FLEX_TWI_SR_SCLWS_Msk                 (_UINT32_(0x1) << FLEX_TWI_SR_SCLWS_Pos)             /* (FLEX_TWI_SR) Clock Wait State Mask */
#define FLEX_TWI_SR_SCLWS(value)              (FLEX_TWI_SR_SCLWS_Msk & (_UINT32_(value) << FLEX_TWI_SR_SCLWS_Pos)) /* Assigment of value for SCLWS in the FLEX_TWI_SR register */
#define FLEX_TWI_SR_EOSACC_Pos                _UINT32_(11)                                         /* (FLEX_TWI_SR) End Of Client Access (cleared on read) Position */
#define FLEX_TWI_SR_EOSACC_Msk                (_UINT32_(0x1) << FLEX_TWI_SR_EOSACC_Pos)            /* (FLEX_TWI_SR) End Of Client Access (cleared on read) Mask */
#define FLEX_TWI_SR_EOSACC(value)             (FLEX_TWI_SR_EOSACC_Msk & (_UINT32_(value) << FLEX_TWI_SR_EOSACC_Pos)) /* Assigment of value for EOSACC in the FLEX_TWI_SR register */
#define FLEX_TWI_SR_ENDRX_Pos                 _UINT32_(12)                                         /* (FLEX_TWI_SR) End of RX Buffer (cleared by writing FLEX_TWI_RCR or FLEX_TWI_RNCR) Position */
#define FLEX_TWI_SR_ENDRX_Msk                 (_UINT32_(0x1) << FLEX_TWI_SR_ENDRX_Pos)             /* (FLEX_TWI_SR) End of RX Buffer (cleared by writing FLEX_TWI_RCR or FLEX_TWI_RNCR) Mask */
#define FLEX_TWI_SR_ENDRX(value)              (FLEX_TWI_SR_ENDRX_Msk & (_UINT32_(value) << FLEX_TWI_SR_ENDRX_Pos)) /* Assigment of value for ENDRX in the FLEX_TWI_SR register */
#define FLEX_TWI_SR_ENDTX_Pos                 _UINT32_(13)                                         /* (FLEX_TWI_SR) End of TX Buffer (cleared by writing FLEX_TWI_TCR or FLEX_TWI_TNCR) Position */
#define FLEX_TWI_SR_ENDTX_Msk                 (_UINT32_(0x1) << FLEX_TWI_SR_ENDTX_Pos)             /* (FLEX_TWI_SR) End of TX Buffer (cleared by writing FLEX_TWI_TCR or FLEX_TWI_TNCR) Mask */
#define FLEX_TWI_SR_ENDTX(value)              (FLEX_TWI_SR_ENDTX_Msk & (_UINT32_(value) << FLEX_TWI_SR_ENDTX_Pos)) /* Assigment of value for ENDTX in the FLEX_TWI_SR register */
#define FLEX_TWI_SR_RXBUFF_Pos                _UINT32_(14)                                         /* (FLEX_TWI_SR) RX Buffer Full (cleared by writing FLEX_TWI_RCR or FLEX_TWI_RNCR) Position */
#define FLEX_TWI_SR_RXBUFF_Msk                (_UINT32_(0x1) << FLEX_TWI_SR_RXBUFF_Pos)            /* (FLEX_TWI_SR) RX Buffer Full (cleared by writing FLEX_TWI_RCR or FLEX_TWI_RNCR) Mask */
#define FLEX_TWI_SR_RXBUFF(value)             (FLEX_TWI_SR_RXBUFF_Msk & (_UINT32_(value) << FLEX_TWI_SR_RXBUFF_Pos)) /* Assigment of value for RXBUFF in the FLEX_TWI_SR register */
#define FLEX_TWI_SR_TXBUFE_Pos                _UINT32_(15)                                         /* (FLEX_TWI_SR) TX Buffer Empty (cleared by writing FLEX_TWI_TCR or FLEX_TWI_TNCR) Position */
#define FLEX_TWI_SR_TXBUFE_Msk                (_UINT32_(0x1) << FLEX_TWI_SR_TXBUFE_Pos)            /* (FLEX_TWI_SR) TX Buffer Empty (cleared by writing FLEX_TWI_TCR or FLEX_TWI_TNCR) Mask */
#define FLEX_TWI_SR_TXBUFE(value)             (FLEX_TWI_SR_TXBUFE_Msk & (_UINT32_(value) << FLEX_TWI_SR_TXBUFE_Pos)) /* Assigment of value for TXBUFE in the FLEX_TWI_SR register */
#define FLEX_TWI_SR_MCACK_Pos                 _UINT32_(16)                                         /* (FLEX_TWI_SR) Host Code Acknowledge (cleared on read) Position */
#define FLEX_TWI_SR_MCACK_Msk                 (_UINT32_(0x1) << FLEX_TWI_SR_MCACK_Pos)             /* (FLEX_TWI_SR) Host Code Acknowledge (cleared on read) Mask */
#define FLEX_TWI_SR_MCACK(value)              (FLEX_TWI_SR_MCACK_Msk & (_UINT32_(value) << FLEX_TWI_SR_MCACK_Pos)) /* Assigment of value for MCACK in the FLEX_TWI_SR register */
#define FLEX_TWI_SR_SMBAF_Pos                 _UINT32_(17)                                         /* (FLEX_TWI_SR) SMBus Alert Flag Position */
#define FLEX_TWI_SR_SMBAF_Msk                 (_UINT32_(0x1) << FLEX_TWI_SR_SMBAF_Pos)             /* (FLEX_TWI_SR) SMBus Alert Flag Mask */
#define FLEX_TWI_SR_SMBAF(value)              (FLEX_TWI_SR_SMBAF_Msk & (_UINT32_(value) << FLEX_TWI_SR_SMBAF_Pos)) /* Assigment of value for SMBAF in the FLEX_TWI_SR register */
#define FLEX_TWI_SR_TOUT_Pos                  _UINT32_(18)                                         /* (FLEX_TWI_SR) Timeout Error (cleared on read) Position */
#define FLEX_TWI_SR_TOUT_Msk                  (_UINT32_(0x1) << FLEX_TWI_SR_TOUT_Pos)              /* (FLEX_TWI_SR) Timeout Error (cleared on read) Mask */
#define FLEX_TWI_SR_TOUT(value)               (FLEX_TWI_SR_TOUT_Msk & (_UINT32_(value) << FLEX_TWI_SR_TOUT_Pos)) /* Assigment of value for TOUT in the FLEX_TWI_SR register */
#define FLEX_TWI_SR_PECERR_Pos                _UINT32_(19)                                         /* (FLEX_TWI_SR) PEC Error (cleared on read) Position */
#define FLEX_TWI_SR_PECERR_Msk                (_UINT32_(0x1) << FLEX_TWI_SR_PECERR_Pos)            /* (FLEX_TWI_SR) PEC Error (cleared on read) Mask */
#define FLEX_TWI_SR_PECERR(value)             (FLEX_TWI_SR_PECERR_Msk & (_UINT32_(value) << FLEX_TWI_SR_PECERR_Pos)) /* Assigment of value for PECERR in the FLEX_TWI_SR register */
#define FLEX_TWI_SR_SMBDAM_Pos                _UINT32_(20)                                         /* (FLEX_TWI_SR) SMBus Default Address Match (cleared on read) Position */
#define FLEX_TWI_SR_SMBDAM_Msk                (_UINT32_(0x1) << FLEX_TWI_SR_SMBDAM_Pos)            /* (FLEX_TWI_SR) SMBus Default Address Match (cleared on read) Mask */
#define FLEX_TWI_SR_SMBDAM(value)             (FLEX_TWI_SR_SMBDAM_Msk & (_UINT32_(value) << FLEX_TWI_SR_SMBDAM_Pos)) /* Assigment of value for SMBDAM in the FLEX_TWI_SR register */
#define FLEX_TWI_SR_SMBHHM_Pos                _UINT32_(21)                                         /* (FLEX_TWI_SR) SMBus Host Header Address Match (cleared on read) Position */
#define FLEX_TWI_SR_SMBHHM_Msk                (_UINT32_(0x1) << FLEX_TWI_SR_SMBHHM_Pos)            /* (FLEX_TWI_SR) SMBus Host Header Address Match (cleared on read) Mask */
#define FLEX_TWI_SR_SMBHHM(value)             (FLEX_TWI_SR_SMBHHM_Msk & (_UINT32_(value) << FLEX_TWI_SR_SMBHHM_Pos)) /* Assigment of value for SMBHHM in the FLEX_TWI_SR register */
#define FLEX_TWI_SR_LOCK_Pos                  _UINT32_(23)                                         /* (FLEX_TWI_SR) TWI Lock Due to Frame Errors Position */
#define FLEX_TWI_SR_LOCK_Msk                  (_UINT32_(0x1) << FLEX_TWI_SR_LOCK_Pos)              /* (FLEX_TWI_SR) TWI Lock Due to Frame Errors Mask */
#define FLEX_TWI_SR_LOCK(value)               (FLEX_TWI_SR_LOCK_Msk & (_UINT32_(value) << FLEX_TWI_SR_LOCK_Pos)) /* Assigment of value for LOCK in the FLEX_TWI_SR register */
#define FLEX_TWI_SR_SCL_Pos                   _UINT32_(24)                                         /* (FLEX_TWI_SR) SCL Line Value Position */
#define FLEX_TWI_SR_SCL_Msk                   (_UINT32_(0x1) << FLEX_TWI_SR_SCL_Pos)               /* (FLEX_TWI_SR) SCL Line Value Mask */
#define FLEX_TWI_SR_SCL(value)                (FLEX_TWI_SR_SCL_Msk & (_UINT32_(value) << FLEX_TWI_SR_SCL_Pos)) /* Assigment of value for SCL in the FLEX_TWI_SR register */
#define FLEX_TWI_SR_SDA_Pos                   _UINT32_(25)                                         /* (FLEX_TWI_SR) SDA Line Value Position */
#define FLEX_TWI_SR_SDA_Msk                   (_UINT32_(0x1) << FLEX_TWI_SR_SDA_Pos)               /* (FLEX_TWI_SR) SDA Line Value Mask */
#define FLEX_TWI_SR_SDA(value)                (FLEX_TWI_SR_SDA_Msk & (_UINT32_(value) << FLEX_TWI_SR_SDA_Pos)) /* Assigment of value for SDA in the FLEX_TWI_SR register */
#define FLEX_TWI_SR_SR_Pos                    _UINT32_(26)                                         /* (FLEX_TWI_SR) Start Repeated Position */
#define FLEX_TWI_SR_SR_Msk                    (_UINT32_(0x1) << FLEX_TWI_SR_SR_Pos)                /* (FLEX_TWI_SR) Start Repeated Mask */
#define FLEX_TWI_SR_SR(value)                 (FLEX_TWI_SR_SR_Msk & (_UINT32_(value) << FLEX_TWI_SR_SR_Pos)) /* Assigment of value for SR in the FLEX_TWI_SR register */
#define FLEX_TWI_SR_Msk                       _UINT32_(0x07BFFFFF)                                 /* (FLEX_TWI_SR) Register Mask  */

/* FIFO_ENABLED mode */
#define FLEX_TWI_SR_FIFO_ENABLED_TXCOMP_Pos   _UINT32_(0)                                          /* (FLEX_TWI_SR) Transmission Completed (cleared by writing FLEX_TWI_THR) Position */
#define FLEX_TWI_SR_FIFO_ENABLED_TXCOMP_Msk   (_UINT32_(0x1) << FLEX_TWI_SR_FIFO_ENABLED_TXCOMP_Pos) /* (FLEX_TWI_SR) Transmission Completed (cleared by writing FLEX_TWI_THR) Mask */
#define FLEX_TWI_SR_FIFO_ENABLED_TXCOMP(value) (FLEX_TWI_SR_FIFO_ENABLED_TXCOMP_Msk & (_UINT32_(value) << FLEX_TWI_SR_FIFO_ENABLED_TXCOMP_Pos))
#define FLEX_TWI_SR_FIFO_ENABLED_RXRDY_Pos    _UINT32_(1)                                          /* (FLEX_TWI_SR) Receive Holding Register Ready (cleared when reading FLEX_TWI_RHR) Position */
#define FLEX_TWI_SR_FIFO_ENABLED_RXRDY_Msk    (_UINT32_(0x1) << FLEX_TWI_SR_FIFO_ENABLED_RXRDY_Pos) /* (FLEX_TWI_SR) Receive Holding Register Ready (cleared when reading FLEX_TWI_RHR) Mask */
#define FLEX_TWI_SR_FIFO_ENABLED_RXRDY(value) (FLEX_TWI_SR_FIFO_ENABLED_RXRDY_Msk & (_UINT32_(value) << FLEX_TWI_SR_FIFO_ENABLED_RXRDY_Pos))
#define FLEX_TWI_SR_FIFO_ENABLED_TXRDY_Pos    _UINT32_(2)                                          /* (FLEX_TWI_SR) Transmit Holding Register Ready (cleared by writing FLEX_TWI_THR) Position */
#define FLEX_TWI_SR_FIFO_ENABLED_TXRDY_Msk    (_UINT32_(0x1) << FLEX_TWI_SR_FIFO_ENABLED_TXRDY_Pos) /* (FLEX_TWI_SR) Transmit Holding Register Ready (cleared by writing FLEX_TWI_THR) Mask */
#define FLEX_TWI_SR_FIFO_ENABLED_TXRDY(value) (FLEX_TWI_SR_FIFO_ENABLED_TXRDY_Msk & (_UINT32_(value) << FLEX_TWI_SR_FIFO_ENABLED_TXRDY_Pos))
#define FLEX_TWI_SR_FIFO_ENABLED_SVREAD_Pos   _UINT32_(3)                                          /* (FLEX_TWI_SR) Client Read Position */
#define FLEX_TWI_SR_FIFO_ENABLED_SVREAD_Msk   (_UINT32_(0x1) << FLEX_TWI_SR_FIFO_ENABLED_SVREAD_Pos) /* (FLEX_TWI_SR) Client Read Mask */
#define FLEX_TWI_SR_FIFO_ENABLED_SVREAD(value) (FLEX_TWI_SR_FIFO_ENABLED_SVREAD_Msk & (_UINT32_(value) << FLEX_TWI_SR_FIFO_ENABLED_SVREAD_Pos))
#define FLEX_TWI_SR_FIFO_ENABLED_SVACC_Pos    _UINT32_(4)                                          /* (FLEX_TWI_SR) Client Access Position */
#define FLEX_TWI_SR_FIFO_ENABLED_SVACC_Msk    (_UINT32_(0x1) << FLEX_TWI_SR_FIFO_ENABLED_SVACC_Pos) /* (FLEX_TWI_SR) Client Access Mask */
#define FLEX_TWI_SR_FIFO_ENABLED_SVACC(value) (FLEX_TWI_SR_FIFO_ENABLED_SVACC_Msk & (_UINT32_(value) << FLEX_TWI_SR_FIFO_ENABLED_SVACC_Pos))
#define FLEX_TWI_SR_FIFO_ENABLED_GACC_Pos     _UINT32_(5)                                          /* (FLEX_TWI_SR) General Call Access (cleared on read) Position */
#define FLEX_TWI_SR_FIFO_ENABLED_GACC_Msk     (_UINT32_(0x1) << FLEX_TWI_SR_FIFO_ENABLED_GACC_Pos) /* (FLEX_TWI_SR) General Call Access (cleared on read) Mask */
#define FLEX_TWI_SR_FIFO_ENABLED_GACC(value)  (FLEX_TWI_SR_FIFO_ENABLED_GACC_Msk & (_UINT32_(value) << FLEX_TWI_SR_FIFO_ENABLED_GACC_Pos))
#define FLEX_TWI_SR_FIFO_ENABLED_OVRE_Pos     _UINT32_(6)                                          /* (FLEX_TWI_SR) Overrun Error (cleared on read) Position */
#define FLEX_TWI_SR_FIFO_ENABLED_OVRE_Msk     (_UINT32_(0x1) << FLEX_TWI_SR_FIFO_ENABLED_OVRE_Pos) /* (FLEX_TWI_SR) Overrun Error (cleared on read) Mask */
#define FLEX_TWI_SR_FIFO_ENABLED_OVRE(value)  (FLEX_TWI_SR_FIFO_ENABLED_OVRE_Msk & (_UINT32_(value) << FLEX_TWI_SR_FIFO_ENABLED_OVRE_Pos))
#define FLEX_TWI_SR_FIFO_ENABLED_UNRE_Pos     _UINT32_(7)                                          /* (FLEX_TWI_SR) Underrun Error (cleared on read) Position */
#define FLEX_TWI_SR_FIFO_ENABLED_UNRE_Msk     (_UINT32_(0x1) << FLEX_TWI_SR_FIFO_ENABLED_UNRE_Pos) /* (FLEX_TWI_SR) Underrun Error (cleared on read) Mask */
#define FLEX_TWI_SR_FIFO_ENABLED_UNRE(value)  (FLEX_TWI_SR_FIFO_ENABLED_UNRE_Msk & (_UINT32_(value) << FLEX_TWI_SR_FIFO_ENABLED_UNRE_Pos))
#define FLEX_TWI_SR_FIFO_ENABLED_NACK_Pos     _UINT32_(8)                                          /* (FLEX_TWI_SR) Not Acknowledged (cleared on read) Position */
#define FLEX_TWI_SR_FIFO_ENABLED_NACK_Msk     (_UINT32_(0x1) << FLEX_TWI_SR_FIFO_ENABLED_NACK_Pos) /* (FLEX_TWI_SR) Not Acknowledged (cleared on read) Mask */
#define FLEX_TWI_SR_FIFO_ENABLED_NACK(value)  (FLEX_TWI_SR_FIFO_ENABLED_NACK_Msk & (_UINT32_(value) << FLEX_TWI_SR_FIFO_ENABLED_NACK_Pos))
#define FLEX_TWI_SR_FIFO_ENABLED_ARBLST_Pos   _UINT32_(9)                                          /* (FLEX_TWI_SR) Arbitration Lost (cleared on read) Position */
#define FLEX_TWI_SR_FIFO_ENABLED_ARBLST_Msk   (_UINT32_(0x1) << FLEX_TWI_SR_FIFO_ENABLED_ARBLST_Pos) /* (FLEX_TWI_SR) Arbitration Lost (cleared on read) Mask */
#define FLEX_TWI_SR_FIFO_ENABLED_ARBLST(value) (FLEX_TWI_SR_FIFO_ENABLED_ARBLST_Msk & (_UINT32_(value) << FLEX_TWI_SR_FIFO_ENABLED_ARBLST_Pos))
#define FLEX_TWI_SR_FIFO_ENABLED_SCLWS_Pos    _UINT32_(10)                                         /* (FLEX_TWI_SR) Clock Wait State Position */
#define FLEX_TWI_SR_FIFO_ENABLED_SCLWS_Msk    (_UINT32_(0x1) << FLEX_TWI_SR_FIFO_ENABLED_SCLWS_Pos) /* (FLEX_TWI_SR) Clock Wait State Mask */
#define FLEX_TWI_SR_FIFO_ENABLED_SCLWS(value) (FLEX_TWI_SR_FIFO_ENABLED_SCLWS_Msk & (_UINT32_(value) << FLEX_TWI_SR_FIFO_ENABLED_SCLWS_Pos))
#define FLEX_TWI_SR_FIFO_ENABLED_EOSACC_Pos   _UINT32_(11)                                         /* (FLEX_TWI_SR) End Of Client Access (cleared on read) Position */
#define FLEX_TWI_SR_FIFO_ENABLED_EOSACC_Msk   (_UINT32_(0x1) << FLEX_TWI_SR_FIFO_ENABLED_EOSACC_Pos) /* (FLEX_TWI_SR) End Of Client Access (cleared on read) Mask */
#define FLEX_TWI_SR_FIFO_ENABLED_EOSACC(value) (FLEX_TWI_SR_FIFO_ENABLED_EOSACC_Msk & (_UINT32_(value) << FLEX_TWI_SR_FIFO_ENABLED_EOSACC_Pos))
#define FLEX_TWI_SR_FIFO_ENABLED_ENDRX_Pos    _UINT32_(12)                                         /* (FLEX_TWI_SR) End of RX Buffer (cleared by writing FLEX_TWI_RCR or FLEX_TWI_RNCR) Position */
#define FLEX_TWI_SR_FIFO_ENABLED_ENDRX_Msk    (_UINT32_(0x1) << FLEX_TWI_SR_FIFO_ENABLED_ENDRX_Pos) /* (FLEX_TWI_SR) End of RX Buffer (cleared by writing FLEX_TWI_RCR or FLEX_TWI_RNCR) Mask */
#define FLEX_TWI_SR_FIFO_ENABLED_ENDRX(value) (FLEX_TWI_SR_FIFO_ENABLED_ENDRX_Msk & (_UINT32_(value) << FLEX_TWI_SR_FIFO_ENABLED_ENDRX_Pos))
#define FLEX_TWI_SR_FIFO_ENABLED_ENDTX_Pos    _UINT32_(13)                                         /* (FLEX_TWI_SR) End of TX Buffer (cleared by writing FLEX_TWI_TCR or FLEX_TWI_TNCR) Position */
#define FLEX_TWI_SR_FIFO_ENABLED_ENDTX_Msk    (_UINT32_(0x1) << FLEX_TWI_SR_FIFO_ENABLED_ENDTX_Pos) /* (FLEX_TWI_SR) End of TX Buffer (cleared by writing FLEX_TWI_TCR or FLEX_TWI_TNCR) Mask */
#define FLEX_TWI_SR_FIFO_ENABLED_ENDTX(value) (FLEX_TWI_SR_FIFO_ENABLED_ENDTX_Msk & (_UINT32_(value) << FLEX_TWI_SR_FIFO_ENABLED_ENDTX_Pos))
#define FLEX_TWI_SR_FIFO_ENABLED_RXBUFF_Pos   _UINT32_(14)                                         /* (FLEX_TWI_SR) RX Buffer Full (cleared by writing FLEX_TWI_RCR or FLEX_TWI_RNCR) Position */
#define FLEX_TWI_SR_FIFO_ENABLED_RXBUFF_Msk   (_UINT32_(0x1) << FLEX_TWI_SR_FIFO_ENABLED_RXBUFF_Pos) /* (FLEX_TWI_SR) RX Buffer Full (cleared by writing FLEX_TWI_RCR or FLEX_TWI_RNCR) Mask */
#define FLEX_TWI_SR_FIFO_ENABLED_RXBUFF(value) (FLEX_TWI_SR_FIFO_ENABLED_RXBUFF_Msk & (_UINT32_(value) << FLEX_TWI_SR_FIFO_ENABLED_RXBUFF_Pos))
#define FLEX_TWI_SR_FIFO_ENABLED_TXBUFE_Pos   _UINT32_(15)                                         /* (FLEX_TWI_SR) TX Buffer Empty (cleared by writing FLEX_TWI_TCR or FLEX_TWI_TNCR) Position */
#define FLEX_TWI_SR_FIFO_ENABLED_TXBUFE_Msk   (_UINT32_(0x1) << FLEX_TWI_SR_FIFO_ENABLED_TXBUFE_Pos) /* (FLEX_TWI_SR) TX Buffer Empty (cleared by writing FLEX_TWI_TCR or FLEX_TWI_TNCR) Mask */
#define FLEX_TWI_SR_FIFO_ENABLED_TXBUFE(value) (FLEX_TWI_SR_FIFO_ENABLED_TXBUFE_Msk & (_UINT32_(value) << FLEX_TWI_SR_FIFO_ENABLED_TXBUFE_Pos))
#define FLEX_TWI_SR_FIFO_ENABLED_MCACK_Pos    _UINT32_(16)                                         /* (FLEX_TWI_SR) Host Code Acknowledge (cleared on read) Position */
#define FLEX_TWI_SR_FIFO_ENABLED_MCACK_Msk    (_UINT32_(0x1) << FLEX_TWI_SR_FIFO_ENABLED_MCACK_Pos) /* (FLEX_TWI_SR) Host Code Acknowledge (cleared on read) Mask */
#define FLEX_TWI_SR_FIFO_ENABLED_MCACK(value) (FLEX_TWI_SR_FIFO_ENABLED_MCACK_Msk & (_UINT32_(value) << FLEX_TWI_SR_FIFO_ENABLED_MCACK_Pos))
#define FLEX_TWI_SR_FIFO_ENABLED_SMBAF_Pos    _UINT32_(17)                                         /* (FLEX_TWI_SR) SMBus Alert Flag Position */
#define FLEX_TWI_SR_FIFO_ENABLED_SMBAF_Msk    (_UINT32_(0x1) << FLEX_TWI_SR_FIFO_ENABLED_SMBAF_Pos) /* (FLEX_TWI_SR) SMBus Alert Flag Mask */
#define FLEX_TWI_SR_FIFO_ENABLED_SMBAF(value) (FLEX_TWI_SR_FIFO_ENABLED_SMBAF_Msk & (_UINT32_(value) << FLEX_TWI_SR_FIFO_ENABLED_SMBAF_Pos))
#define FLEX_TWI_SR_FIFO_ENABLED_TOUT_Pos     _UINT32_(18)                                         /* (FLEX_TWI_SR) Timeout Error (cleared on read) Position */
#define FLEX_TWI_SR_FIFO_ENABLED_TOUT_Msk     (_UINT32_(0x1) << FLEX_TWI_SR_FIFO_ENABLED_TOUT_Pos) /* (FLEX_TWI_SR) Timeout Error (cleared on read) Mask */
#define FLEX_TWI_SR_FIFO_ENABLED_TOUT(value)  (FLEX_TWI_SR_FIFO_ENABLED_TOUT_Msk & (_UINT32_(value) << FLEX_TWI_SR_FIFO_ENABLED_TOUT_Pos))
#define FLEX_TWI_SR_FIFO_ENABLED_PECERR_Pos   _UINT32_(19)                                         /* (FLEX_TWI_SR) PEC Error (cleared on read) Position */
#define FLEX_TWI_SR_FIFO_ENABLED_PECERR_Msk   (_UINT32_(0x1) << FLEX_TWI_SR_FIFO_ENABLED_PECERR_Pos) /* (FLEX_TWI_SR) PEC Error (cleared on read) Mask */
#define FLEX_TWI_SR_FIFO_ENABLED_PECERR(value) (FLEX_TWI_SR_FIFO_ENABLED_PECERR_Msk & (_UINT32_(value) << FLEX_TWI_SR_FIFO_ENABLED_PECERR_Pos))
#define FLEX_TWI_SR_FIFO_ENABLED_SMBDAM_Pos   _UINT32_(20)                                         /* (FLEX_TWI_SR) SMBus Default Address Match (cleared on read) Position */
#define FLEX_TWI_SR_FIFO_ENABLED_SMBDAM_Msk   (_UINT32_(0x1) << FLEX_TWI_SR_FIFO_ENABLED_SMBDAM_Pos) /* (FLEX_TWI_SR) SMBus Default Address Match (cleared on read) Mask */
#define FLEX_TWI_SR_FIFO_ENABLED_SMBDAM(value) (FLEX_TWI_SR_FIFO_ENABLED_SMBDAM_Msk & (_UINT32_(value) << FLEX_TWI_SR_FIFO_ENABLED_SMBDAM_Pos))
#define FLEX_TWI_SR_FIFO_ENABLED_SMBHHM_Pos   _UINT32_(21)                                         /* (FLEX_TWI_SR) SMBus Host Header Address Match (cleared on read) Position */
#define FLEX_TWI_SR_FIFO_ENABLED_SMBHHM_Msk   (_UINT32_(0x1) << FLEX_TWI_SR_FIFO_ENABLED_SMBHHM_Pos) /* (FLEX_TWI_SR) SMBus Host Header Address Match (cleared on read) Mask */
#define FLEX_TWI_SR_FIFO_ENABLED_SMBHHM(value) (FLEX_TWI_SR_FIFO_ENABLED_SMBHHM_Msk & (_UINT32_(value) << FLEX_TWI_SR_FIFO_ENABLED_SMBHHM_Pos))
#define FLEX_TWI_SR_FIFO_ENABLED_TXFLOCK_Pos  _UINT32_(23)                                         /* (FLEX_TWI_SR) Transmit FIFO Lock Position */
#define FLEX_TWI_SR_FIFO_ENABLED_TXFLOCK_Msk  (_UINT32_(0x1) << FLEX_TWI_SR_FIFO_ENABLED_TXFLOCK_Pos) /* (FLEX_TWI_SR) Transmit FIFO Lock Mask */
#define FLEX_TWI_SR_FIFO_ENABLED_TXFLOCK(value) (FLEX_TWI_SR_FIFO_ENABLED_TXFLOCK_Msk & (_UINT32_(value) << FLEX_TWI_SR_FIFO_ENABLED_TXFLOCK_Pos))
#define FLEX_TWI_SR_FIFO_ENABLED_SCL_Pos      _UINT32_(24)                                         /* (FLEX_TWI_SR) SCL Line Value Position */
#define FLEX_TWI_SR_FIFO_ENABLED_SCL_Msk      (_UINT32_(0x1) << FLEX_TWI_SR_FIFO_ENABLED_SCL_Pos)  /* (FLEX_TWI_SR) SCL Line Value Mask */
#define FLEX_TWI_SR_FIFO_ENABLED_SCL(value)   (FLEX_TWI_SR_FIFO_ENABLED_SCL_Msk & (_UINT32_(value) << FLEX_TWI_SR_FIFO_ENABLED_SCL_Pos))
#define FLEX_TWI_SR_FIFO_ENABLED_SDA_Pos      _UINT32_(25)                                         /* (FLEX_TWI_SR) SDA Line Value Position */
#define FLEX_TWI_SR_FIFO_ENABLED_SDA_Msk      (_UINT32_(0x1) << FLEX_TWI_SR_FIFO_ENABLED_SDA_Pos)  /* (FLEX_TWI_SR) SDA Line Value Mask */
#define FLEX_TWI_SR_FIFO_ENABLED_SDA(value)   (FLEX_TWI_SR_FIFO_ENABLED_SDA_Msk & (_UINT32_(value) << FLEX_TWI_SR_FIFO_ENABLED_SDA_Pos))
#define FLEX_TWI_SR_FIFO_ENABLED_SR_Pos       _UINT32_(26)                                         /* (FLEX_TWI_SR) Start Repeated Position */
#define FLEX_TWI_SR_FIFO_ENABLED_SR_Msk       (_UINT32_(0x1) << FLEX_TWI_SR_FIFO_ENABLED_SR_Pos)   /* (FLEX_TWI_SR) Start Repeated Mask */
#define FLEX_TWI_SR_FIFO_ENABLED_SR(value)    (FLEX_TWI_SR_FIFO_ENABLED_SR_Msk & (_UINT32_(value) << FLEX_TWI_SR_FIFO_ENABLED_SR_Pos))
#define FLEX_TWI_SR_FIFO_ENABLED_Msk          _UINT32_(0x07BFFFFF)                                  /* (FLEX_TWI_SR_FIFO_ENABLED) Register Mask  */


/* -------- FLEX_TWI_IER : (FLEXCOM Offset: 0x624) ( /W 32) TWI Interrupt Enable Register -------- */
#define FLEX_TWI_IER_TXCOMP_Pos               _UINT32_(0)                                          /* (FLEX_TWI_IER) Transmission Completed Interrupt Enable Position */
#define FLEX_TWI_IER_TXCOMP_Msk               (_UINT32_(0x1) << FLEX_TWI_IER_TXCOMP_Pos)           /* (FLEX_TWI_IER) Transmission Completed Interrupt Enable Mask */
#define FLEX_TWI_IER_TXCOMP(value)            (FLEX_TWI_IER_TXCOMP_Msk & (_UINT32_(value) << FLEX_TWI_IER_TXCOMP_Pos)) /* Assigment of value for TXCOMP in the FLEX_TWI_IER register */
#define FLEX_TWI_IER_RXRDY_Pos                _UINT32_(1)                                          /* (FLEX_TWI_IER) Receive Holding Register Ready Interrupt Enable Position */
#define FLEX_TWI_IER_RXRDY_Msk                (_UINT32_(0x1) << FLEX_TWI_IER_RXRDY_Pos)            /* (FLEX_TWI_IER) Receive Holding Register Ready Interrupt Enable Mask */
#define FLEX_TWI_IER_RXRDY(value)             (FLEX_TWI_IER_RXRDY_Msk & (_UINT32_(value) << FLEX_TWI_IER_RXRDY_Pos)) /* Assigment of value for RXRDY in the FLEX_TWI_IER register */
#define FLEX_TWI_IER_TXRDY_Pos                _UINT32_(2)                                          /* (FLEX_TWI_IER) Transmit Holding Register Ready Interrupt Enable Position */
#define FLEX_TWI_IER_TXRDY_Msk                (_UINT32_(0x1) << FLEX_TWI_IER_TXRDY_Pos)            /* (FLEX_TWI_IER) Transmit Holding Register Ready Interrupt Enable Mask */
#define FLEX_TWI_IER_TXRDY(value)             (FLEX_TWI_IER_TXRDY_Msk & (_UINT32_(value) << FLEX_TWI_IER_TXRDY_Pos)) /* Assigment of value for TXRDY in the FLEX_TWI_IER register */
#define FLEX_TWI_IER_SVACC_Pos                _UINT32_(4)                                          /* (FLEX_TWI_IER) Client Access Interrupt Enable Position */
#define FLEX_TWI_IER_SVACC_Msk                (_UINT32_(0x1) << FLEX_TWI_IER_SVACC_Pos)            /* (FLEX_TWI_IER) Client Access Interrupt Enable Mask */
#define FLEX_TWI_IER_SVACC(value)             (FLEX_TWI_IER_SVACC_Msk & (_UINT32_(value) << FLEX_TWI_IER_SVACC_Pos)) /* Assigment of value for SVACC in the FLEX_TWI_IER register */
#define FLEX_TWI_IER_GACC_Pos                 _UINT32_(5)                                          /* (FLEX_TWI_IER) General Call Access Interrupt Enable Position */
#define FLEX_TWI_IER_GACC_Msk                 (_UINT32_(0x1) << FLEX_TWI_IER_GACC_Pos)             /* (FLEX_TWI_IER) General Call Access Interrupt Enable Mask */
#define FLEX_TWI_IER_GACC(value)              (FLEX_TWI_IER_GACC_Msk & (_UINT32_(value) << FLEX_TWI_IER_GACC_Pos)) /* Assigment of value for GACC in the FLEX_TWI_IER register */
#define FLEX_TWI_IER_OVRE_Pos                 _UINT32_(6)                                          /* (FLEX_TWI_IER) Overrun Error Interrupt Enable Position */
#define FLEX_TWI_IER_OVRE_Msk                 (_UINT32_(0x1) << FLEX_TWI_IER_OVRE_Pos)             /* (FLEX_TWI_IER) Overrun Error Interrupt Enable Mask */
#define FLEX_TWI_IER_OVRE(value)              (FLEX_TWI_IER_OVRE_Msk & (_UINT32_(value) << FLEX_TWI_IER_OVRE_Pos)) /* Assigment of value for OVRE in the FLEX_TWI_IER register */
#define FLEX_TWI_IER_UNRE_Pos                 _UINT32_(7)                                          /* (FLEX_TWI_IER) Underrun Error Interrupt Enable Position */
#define FLEX_TWI_IER_UNRE_Msk                 (_UINT32_(0x1) << FLEX_TWI_IER_UNRE_Pos)             /* (FLEX_TWI_IER) Underrun Error Interrupt Enable Mask */
#define FLEX_TWI_IER_UNRE(value)              (FLEX_TWI_IER_UNRE_Msk & (_UINT32_(value) << FLEX_TWI_IER_UNRE_Pos)) /* Assigment of value for UNRE in the FLEX_TWI_IER register */
#define FLEX_TWI_IER_NACK_Pos                 _UINT32_(8)                                          /* (FLEX_TWI_IER) Not Acknowledge Interrupt Enable Position */
#define FLEX_TWI_IER_NACK_Msk                 (_UINT32_(0x1) << FLEX_TWI_IER_NACK_Pos)             /* (FLEX_TWI_IER) Not Acknowledge Interrupt Enable Mask */
#define FLEX_TWI_IER_NACK(value)              (FLEX_TWI_IER_NACK_Msk & (_UINT32_(value) << FLEX_TWI_IER_NACK_Pos)) /* Assigment of value for NACK in the FLEX_TWI_IER register */
#define FLEX_TWI_IER_ARBLST_Pos               _UINT32_(9)                                          /* (FLEX_TWI_IER) Arbitration Lost Interrupt Enable Position */
#define FLEX_TWI_IER_ARBLST_Msk               (_UINT32_(0x1) << FLEX_TWI_IER_ARBLST_Pos)           /* (FLEX_TWI_IER) Arbitration Lost Interrupt Enable Mask */
#define FLEX_TWI_IER_ARBLST(value)            (FLEX_TWI_IER_ARBLST_Msk & (_UINT32_(value) << FLEX_TWI_IER_ARBLST_Pos)) /* Assigment of value for ARBLST in the FLEX_TWI_IER register */
#define FLEX_TWI_IER_SCL_WS_Pos               _UINT32_(10)                                         /* (FLEX_TWI_IER) Clock Wait State Interrupt Enable Position */
#define FLEX_TWI_IER_SCL_WS_Msk               (_UINT32_(0x1) << FLEX_TWI_IER_SCL_WS_Pos)           /* (FLEX_TWI_IER) Clock Wait State Interrupt Enable Mask */
#define FLEX_TWI_IER_SCL_WS(value)            (FLEX_TWI_IER_SCL_WS_Msk & (_UINT32_(value) << FLEX_TWI_IER_SCL_WS_Pos)) /* Assigment of value for SCL_WS in the FLEX_TWI_IER register */
#define FLEX_TWI_IER_EOSACC_Pos               _UINT32_(11)                                         /* (FLEX_TWI_IER) End Of Client Access Interrupt Enable Position */
#define FLEX_TWI_IER_EOSACC_Msk               (_UINT32_(0x1) << FLEX_TWI_IER_EOSACC_Pos)           /* (FLEX_TWI_IER) End Of Client Access Interrupt Enable Mask */
#define FLEX_TWI_IER_EOSACC(value)            (FLEX_TWI_IER_EOSACC_Msk & (_UINT32_(value) << FLEX_TWI_IER_EOSACC_Pos)) /* Assigment of value for EOSACC in the FLEX_TWI_IER register */
#define FLEX_TWI_IER_ENDRX_Pos                _UINT32_(12)                                         /* (FLEX_TWI_IER) End of Receive Buffer Interrupt Enable Position */
#define FLEX_TWI_IER_ENDRX_Msk                (_UINT32_(0x1) << FLEX_TWI_IER_ENDRX_Pos)            /* (FLEX_TWI_IER) End of Receive Buffer Interrupt Enable Mask */
#define FLEX_TWI_IER_ENDRX(value)             (FLEX_TWI_IER_ENDRX_Msk & (_UINT32_(value) << FLEX_TWI_IER_ENDRX_Pos)) /* Assigment of value for ENDRX in the FLEX_TWI_IER register */
#define FLEX_TWI_IER_ENDTX_Pos                _UINT32_(13)                                         /* (FLEX_TWI_IER) End of Transmit Buffer Interrupt Enable Position */
#define FLEX_TWI_IER_ENDTX_Msk                (_UINT32_(0x1) << FLEX_TWI_IER_ENDTX_Pos)            /* (FLEX_TWI_IER) End of Transmit Buffer Interrupt Enable Mask */
#define FLEX_TWI_IER_ENDTX(value)             (FLEX_TWI_IER_ENDTX_Msk & (_UINT32_(value) << FLEX_TWI_IER_ENDTX_Pos)) /* Assigment of value for ENDTX in the FLEX_TWI_IER register */
#define FLEX_TWI_IER_RXBUFF_Pos               _UINT32_(14)                                         /* (FLEX_TWI_IER) Receive Buffer Full Interrupt Enable Position */
#define FLEX_TWI_IER_RXBUFF_Msk               (_UINT32_(0x1) << FLEX_TWI_IER_RXBUFF_Pos)           /* (FLEX_TWI_IER) Receive Buffer Full Interrupt Enable Mask */
#define FLEX_TWI_IER_RXBUFF(value)            (FLEX_TWI_IER_RXBUFF_Msk & (_UINT32_(value) << FLEX_TWI_IER_RXBUFF_Pos)) /* Assigment of value for RXBUFF in the FLEX_TWI_IER register */
#define FLEX_TWI_IER_TXBUFE_Pos               _UINT32_(15)                                         /* (FLEX_TWI_IER) Transmit Buffer Empty Interrupt Enable Position */
#define FLEX_TWI_IER_TXBUFE_Msk               (_UINT32_(0x1) << FLEX_TWI_IER_TXBUFE_Pos)           /* (FLEX_TWI_IER) Transmit Buffer Empty Interrupt Enable Mask */
#define FLEX_TWI_IER_TXBUFE(value)            (FLEX_TWI_IER_TXBUFE_Msk & (_UINT32_(value) << FLEX_TWI_IER_TXBUFE_Pos)) /* Assigment of value for TXBUFE in the FLEX_TWI_IER register */
#define FLEX_TWI_IER_MCACK_Pos                _UINT32_(16)                                         /* (FLEX_TWI_IER) Host Code Acknowledge Interrupt Enable Position */
#define FLEX_TWI_IER_MCACK_Msk                (_UINT32_(0x1) << FLEX_TWI_IER_MCACK_Pos)            /* (FLEX_TWI_IER) Host Code Acknowledge Interrupt Enable Mask */
#define FLEX_TWI_IER_MCACK(value)             (FLEX_TWI_IER_MCACK_Msk & (_UINT32_(value) << FLEX_TWI_IER_MCACK_Pos)) /* Assigment of value for MCACK in the FLEX_TWI_IER register */
#define FLEX_TWI_IER_TOUT_Pos                 _UINT32_(18)                                         /* (FLEX_TWI_IER) Timeout Error Interrupt Enable Position */
#define FLEX_TWI_IER_TOUT_Msk                 (_UINT32_(0x1) << FLEX_TWI_IER_TOUT_Pos)             /* (FLEX_TWI_IER) Timeout Error Interrupt Enable Mask */
#define FLEX_TWI_IER_TOUT(value)              (FLEX_TWI_IER_TOUT_Msk & (_UINT32_(value) << FLEX_TWI_IER_TOUT_Pos)) /* Assigment of value for TOUT in the FLEX_TWI_IER register */
#define FLEX_TWI_IER_PECERR_Pos               _UINT32_(19)                                         /* (FLEX_TWI_IER) PEC Error Interrupt Enable Position */
#define FLEX_TWI_IER_PECERR_Msk               (_UINT32_(0x1) << FLEX_TWI_IER_PECERR_Pos)           /* (FLEX_TWI_IER) PEC Error Interrupt Enable Mask */
#define FLEX_TWI_IER_PECERR(value)            (FLEX_TWI_IER_PECERR_Msk & (_UINT32_(value) << FLEX_TWI_IER_PECERR_Pos)) /* Assigment of value for PECERR in the FLEX_TWI_IER register */
#define FLEX_TWI_IER_SMBDAM_Pos               _UINT32_(20)                                         /* (FLEX_TWI_IER) SMBus Default Address Match Interrupt Enable Position */
#define FLEX_TWI_IER_SMBDAM_Msk               (_UINT32_(0x1) << FLEX_TWI_IER_SMBDAM_Pos)           /* (FLEX_TWI_IER) SMBus Default Address Match Interrupt Enable Mask */
#define FLEX_TWI_IER_SMBDAM(value)            (FLEX_TWI_IER_SMBDAM_Msk & (_UINT32_(value) << FLEX_TWI_IER_SMBDAM_Pos)) /* Assigment of value for SMBDAM in the FLEX_TWI_IER register */
#define FLEX_TWI_IER_SMBHHM_Pos               _UINT32_(21)                                         /* (FLEX_TWI_IER) SMBus Host Header Address Match Interrupt Enable Position */
#define FLEX_TWI_IER_SMBHHM_Msk               (_UINT32_(0x1) << FLEX_TWI_IER_SMBHHM_Pos)           /* (FLEX_TWI_IER) SMBus Host Header Address Match Interrupt Enable Mask */
#define FLEX_TWI_IER_SMBHHM(value)            (FLEX_TWI_IER_SMBHHM_Msk & (_UINT32_(value) << FLEX_TWI_IER_SMBHHM_Pos)) /* Assigment of value for SMBHHM in the FLEX_TWI_IER register */
#define FLEX_TWI_IER_Msk                      _UINT32_(0x003DFFF7)                                 /* (FLEX_TWI_IER) Register Mask  */


/* -------- FLEX_TWI_IDR : (FLEXCOM Offset: 0x628) ( /W 32) TWI Interrupt Disable Register -------- */
#define FLEX_TWI_IDR_TXCOMP_Pos               _UINT32_(0)                                          /* (FLEX_TWI_IDR) Transmission Completed Interrupt Disable Position */
#define FLEX_TWI_IDR_TXCOMP_Msk               (_UINT32_(0x1) << FLEX_TWI_IDR_TXCOMP_Pos)           /* (FLEX_TWI_IDR) Transmission Completed Interrupt Disable Mask */
#define FLEX_TWI_IDR_TXCOMP(value)            (FLEX_TWI_IDR_TXCOMP_Msk & (_UINT32_(value) << FLEX_TWI_IDR_TXCOMP_Pos)) /* Assigment of value for TXCOMP in the FLEX_TWI_IDR register */
#define FLEX_TWI_IDR_RXRDY_Pos                _UINT32_(1)                                          /* (FLEX_TWI_IDR) Receive Holding Register Ready Interrupt Disable Position */
#define FLEX_TWI_IDR_RXRDY_Msk                (_UINT32_(0x1) << FLEX_TWI_IDR_RXRDY_Pos)            /* (FLEX_TWI_IDR) Receive Holding Register Ready Interrupt Disable Mask */
#define FLEX_TWI_IDR_RXRDY(value)             (FLEX_TWI_IDR_RXRDY_Msk & (_UINT32_(value) << FLEX_TWI_IDR_RXRDY_Pos)) /* Assigment of value for RXRDY in the FLEX_TWI_IDR register */
#define FLEX_TWI_IDR_TXRDY_Pos                _UINT32_(2)                                          /* (FLEX_TWI_IDR) Transmit Holding Register Ready Interrupt Disable Position */
#define FLEX_TWI_IDR_TXRDY_Msk                (_UINT32_(0x1) << FLEX_TWI_IDR_TXRDY_Pos)            /* (FLEX_TWI_IDR) Transmit Holding Register Ready Interrupt Disable Mask */
#define FLEX_TWI_IDR_TXRDY(value)             (FLEX_TWI_IDR_TXRDY_Msk & (_UINT32_(value) << FLEX_TWI_IDR_TXRDY_Pos)) /* Assigment of value for TXRDY in the FLEX_TWI_IDR register */
#define FLEX_TWI_IDR_SVACC_Pos                _UINT32_(4)                                          /* (FLEX_TWI_IDR) Client Access Interrupt Disable Position */
#define FLEX_TWI_IDR_SVACC_Msk                (_UINT32_(0x1) << FLEX_TWI_IDR_SVACC_Pos)            /* (FLEX_TWI_IDR) Client Access Interrupt Disable Mask */
#define FLEX_TWI_IDR_SVACC(value)             (FLEX_TWI_IDR_SVACC_Msk & (_UINT32_(value) << FLEX_TWI_IDR_SVACC_Pos)) /* Assigment of value for SVACC in the FLEX_TWI_IDR register */
#define FLEX_TWI_IDR_GACC_Pos                 _UINT32_(5)                                          /* (FLEX_TWI_IDR) General Call Access Interrupt Disable Position */
#define FLEX_TWI_IDR_GACC_Msk                 (_UINT32_(0x1) << FLEX_TWI_IDR_GACC_Pos)             /* (FLEX_TWI_IDR) General Call Access Interrupt Disable Mask */
#define FLEX_TWI_IDR_GACC(value)              (FLEX_TWI_IDR_GACC_Msk & (_UINT32_(value) << FLEX_TWI_IDR_GACC_Pos)) /* Assigment of value for GACC in the FLEX_TWI_IDR register */
#define FLEX_TWI_IDR_OVRE_Pos                 _UINT32_(6)                                          /* (FLEX_TWI_IDR) Overrun Error Interrupt Disable Position */
#define FLEX_TWI_IDR_OVRE_Msk                 (_UINT32_(0x1) << FLEX_TWI_IDR_OVRE_Pos)             /* (FLEX_TWI_IDR) Overrun Error Interrupt Disable Mask */
#define FLEX_TWI_IDR_OVRE(value)              (FLEX_TWI_IDR_OVRE_Msk & (_UINT32_(value) << FLEX_TWI_IDR_OVRE_Pos)) /* Assigment of value for OVRE in the FLEX_TWI_IDR register */
#define FLEX_TWI_IDR_UNRE_Pos                 _UINT32_(7)                                          /* (FLEX_TWI_IDR) Underrun Error Interrupt Disable Position */
#define FLEX_TWI_IDR_UNRE_Msk                 (_UINT32_(0x1) << FLEX_TWI_IDR_UNRE_Pos)             /* (FLEX_TWI_IDR) Underrun Error Interrupt Disable Mask */
#define FLEX_TWI_IDR_UNRE(value)              (FLEX_TWI_IDR_UNRE_Msk & (_UINT32_(value) << FLEX_TWI_IDR_UNRE_Pos)) /* Assigment of value for UNRE in the FLEX_TWI_IDR register */
#define FLEX_TWI_IDR_NACK_Pos                 _UINT32_(8)                                          /* (FLEX_TWI_IDR) Not Acknowledge Interrupt Disable Position */
#define FLEX_TWI_IDR_NACK_Msk                 (_UINT32_(0x1) << FLEX_TWI_IDR_NACK_Pos)             /* (FLEX_TWI_IDR) Not Acknowledge Interrupt Disable Mask */
#define FLEX_TWI_IDR_NACK(value)              (FLEX_TWI_IDR_NACK_Msk & (_UINT32_(value) << FLEX_TWI_IDR_NACK_Pos)) /* Assigment of value for NACK in the FLEX_TWI_IDR register */
#define FLEX_TWI_IDR_ARBLST_Pos               _UINT32_(9)                                          /* (FLEX_TWI_IDR) Arbitration Lost Interrupt Disable Position */
#define FLEX_TWI_IDR_ARBLST_Msk               (_UINT32_(0x1) << FLEX_TWI_IDR_ARBLST_Pos)           /* (FLEX_TWI_IDR) Arbitration Lost Interrupt Disable Mask */
#define FLEX_TWI_IDR_ARBLST(value)            (FLEX_TWI_IDR_ARBLST_Msk & (_UINT32_(value) << FLEX_TWI_IDR_ARBLST_Pos)) /* Assigment of value for ARBLST in the FLEX_TWI_IDR register */
#define FLEX_TWI_IDR_SCL_WS_Pos               _UINT32_(10)                                         /* (FLEX_TWI_IDR) Clock Wait State Interrupt Disable Position */
#define FLEX_TWI_IDR_SCL_WS_Msk               (_UINT32_(0x1) << FLEX_TWI_IDR_SCL_WS_Pos)           /* (FLEX_TWI_IDR) Clock Wait State Interrupt Disable Mask */
#define FLEX_TWI_IDR_SCL_WS(value)            (FLEX_TWI_IDR_SCL_WS_Msk & (_UINT32_(value) << FLEX_TWI_IDR_SCL_WS_Pos)) /* Assigment of value for SCL_WS in the FLEX_TWI_IDR register */
#define FLEX_TWI_IDR_EOSACC_Pos               _UINT32_(11)                                         /* (FLEX_TWI_IDR) End Of Client Access Interrupt Disable Position */
#define FLEX_TWI_IDR_EOSACC_Msk               (_UINT32_(0x1) << FLEX_TWI_IDR_EOSACC_Pos)           /* (FLEX_TWI_IDR) End Of Client Access Interrupt Disable Mask */
#define FLEX_TWI_IDR_EOSACC(value)            (FLEX_TWI_IDR_EOSACC_Msk & (_UINT32_(value) << FLEX_TWI_IDR_EOSACC_Pos)) /* Assigment of value for EOSACC in the FLEX_TWI_IDR register */
#define FLEX_TWI_IDR_ENDRX_Pos                _UINT32_(12)                                         /* (FLEX_TWI_IDR) End of Receive Buffer Interrupt Disable Position */
#define FLEX_TWI_IDR_ENDRX_Msk                (_UINT32_(0x1) << FLEX_TWI_IDR_ENDRX_Pos)            /* (FLEX_TWI_IDR) End of Receive Buffer Interrupt Disable Mask */
#define FLEX_TWI_IDR_ENDRX(value)             (FLEX_TWI_IDR_ENDRX_Msk & (_UINT32_(value) << FLEX_TWI_IDR_ENDRX_Pos)) /* Assigment of value for ENDRX in the FLEX_TWI_IDR register */
#define FLEX_TWI_IDR_ENDTX_Pos                _UINT32_(13)                                         /* (FLEX_TWI_IDR) End of Transmit Buffer Interrupt Disable Position */
#define FLEX_TWI_IDR_ENDTX_Msk                (_UINT32_(0x1) << FLEX_TWI_IDR_ENDTX_Pos)            /* (FLEX_TWI_IDR) End of Transmit Buffer Interrupt Disable Mask */
#define FLEX_TWI_IDR_ENDTX(value)             (FLEX_TWI_IDR_ENDTX_Msk & (_UINT32_(value) << FLEX_TWI_IDR_ENDTX_Pos)) /* Assigment of value for ENDTX in the FLEX_TWI_IDR register */
#define FLEX_TWI_IDR_RXBUFF_Pos               _UINT32_(14)                                         /* (FLEX_TWI_IDR) Receive Buffer Full Interrupt Disable Position */
#define FLEX_TWI_IDR_RXBUFF_Msk               (_UINT32_(0x1) << FLEX_TWI_IDR_RXBUFF_Pos)           /* (FLEX_TWI_IDR) Receive Buffer Full Interrupt Disable Mask */
#define FLEX_TWI_IDR_RXBUFF(value)            (FLEX_TWI_IDR_RXBUFF_Msk & (_UINT32_(value) << FLEX_TWI_IDR_RXBUFF_Pos)) /* Assigment of value for RXBUFF in the FLEX_TWI_IDR register */
#define FLEX_TWI_IDR_TXBUFE_Pos               _UINT32_(15)                                         /* (FLEX_TWI_IDR) Transmit Buffer Empty Interrupt Disable Position */
#define FLEX_TWI_IDR_TXBUFE_Msk               (_UINT32_(0x1) << FLEX_TWI_IDR_TXBUFE_Pos)           /* (FLEX_TWI_IDR) Transmit Buffer Empty Interrupt Disable Mask */
#define FLEX_TWI_IDR_TXBUFE(value)            (FLEX_TWI_IDR_TXBUFE_Msk & (_UINT32_(value) << FLEX_TWI_IDR_TXBUFE_Pos)) /* Assigment of value for TXBUFE in the FLEX_TWI_IDR register */
#define FLEX_TWI_IDR_MCACK_Pos                _UINT32_(16)                                         /* (FLEX_TWI_IDR) Host Code Acknowledge Interrupt Disable Position */
#define FLEX_TWI_IDR_MCACK_Msk                (_UINT32_(0x1) << FLEX_TWI_IDR_MCACK_Pos)            /* (FLEX_TWI_IDR) Host Code Acknowledge Interrupt Disable Mask */
#define FLEX_TWI_IDR_MCACK(value)             (FLEX_TWI_IDR_MCACK_Msk & (_UINT32_(value) << FLEX_TWI_IDR_MCACK_Pos)) /* Assigment of value for MCACK in the FLEX_TWI_IDR register */
#define FLEX_TWI_IDR_TOUT_Pos                 _UINT32_(18)                                         /* (FLEX_TWI_IDR) Timeout Error Interrupt Disable Position */
#define FLEX_TWI_IDR_TOUT_Msk                 (_UINT32_(0x1) << FLEX_TWI_IDR_TOUT_Pos)             /* (FLEX_TWI_IDR) Timeout Error Interrupt Disable Mask */
#define FLEX_TWI_IDR_TOUT(value)              (FLEX_TWI_IDR_TOUT_Msk & (_UINT32_(value) << FLEX_TWI_IDR_TOUT_Pos)) /* Assigment of value for TOUT in the FLEX_TWI_IDR register */
#define FLEX_TWI_IDR_PECERR_Pos               _UINT32_(19)                                         /* (FLEX_TWI_IDR) PEC Error Interrupt Disable Position */
#define FLEX_TWI_IDR_PECERR_Msk               (_UINT32_(0x1) << FLEX_TWI_IDR_PECERR_Pos)           /* (FLEX_TWI_IDR) PEC Error Interrupt Disable Mask */
#define FLEX_TWI_IDR_PECERR(value)            (FLEX_TWI_IDR_PECERR_Msk & (_UINT32_(value) << FLEX_TWI_IDR_PECERR_Pos)) /* Assigment of value for PECERR in the FLEX_TWI_IDR register */
#define FLEX_TWI_IDR_SMBDAM_Pos               _UINT32_(20)                                         /* (FLEX_TWI_IDR) SMBus Default Address Match Interrupt Disable Position */
#define FLEX_TWI_IDR_SMBDAM_Msk               (_UINT32_(0x1) << FLEX_TWI_IDR_SMBDAM_Pos)           /* (FLEX_TWI_IDR) SMBus Default Address Match Interrupt Disable Mask */
#define FLEX_TWI_IDR_SMBDAM(value)            (FLEX_TWI_IDR_SMBDAM_Msk & (_UINT32_(value) << FLEX_TWI_IDR_SMBDAM_Pos)) /* Assigment of value for SMBDAM in the FLEX_TWI_IDR register */
#define FLEX_TWI_IDR_SMBHHM_Pos               _UINT32_(21)                                         /* (FLEX_TWI_IDR) SMBus Host Header Address Match Interrupt Disable Position */
#define FLEX_TWI_IDR_SMBHHM_Msk               (_UINT32_(0x1) << FLEX_TWI_IDR_SMBHHM_Pos)           /* (FLEX_TWI_IDR) SMBus Host Header Address Match Interrupt Disable Mask */
#define FLEX_TWI_IDR_SMBHHM(value)            (FLEX_TWI_IDR_SMBHHM_Msk & (_UINT32_(value) << FLEX_TWI_IDR_SMBHHM_Pos)) /* Assigment of value for SMBHHM in the FLEX_TWI_IDR register */
#define FLEX_TWI_IDR_Msk                      _UINT32_(0x003DFFF7)                                 /* (FLEX_TWI_IDR) Register Mask  */


/* -------- FLEX_TWI_IMR : (FLEXCOM Offset: 0x62C) ( R/ 32) TWI Interrupt Mask Register -------- */
#define FLEX_TWI_IMR_TXCOMP_Pos               _UINT32_(0)                                          /* (FLEX_TWI_IMR) Transmission Completed Interrupt Mask Position */
#define FLEX_TWI_IMR_TXCOMP_Msk               (_UINT32_(0x1) << FLEX_TWI_IMR_TXCOMP_Pos)           /* (FLEX_TWI_IMR) Transmission Completed Interrupt Mask Mask */
#define FLEX_TWI_IMR_TXCOMP(value)            (FLEX_TWI_IMR_TXCOMP_Msk & (_UINT32_(value) << FLEX_TWI_IMR_TXCOMP_Pos)) /* Assigment of value for TXCOMP in the FLEX_TWI_IMR register */
#define FLEX_TWI_IMR_RXRDY_Pos                _UINT32_(1)                                          /* (FLEX_TWI_IMR) Receive Holding Register Ready Interrupt Mask Position */
#define FLEX_TWI_IMR_RXRDY_Msk                (_UINT32_(0x1) << FLEX_TWI_IMR_RXRDY_Pos)            /* (FLEX_TWI_IMR) Receive Holding Register Ready Interrupt Mask Mask */
#define FLEX_TWI_IMR_RXRDY(value)             (FLEX_TWI_IMR_RXRDY_Msk & (_UINT32_(value) << FLEX_TWI_IMR_RXRDY_Pos)) /* Assigment of value for RXRDY in the FLEX_TWI_IMR register */
#define FLEX_TWI_IMR_TXRDY_Pos                _UINT32_(2)                                          /* (FLEX_TWI_IMR) Transmit Holding Register Ready Interrupt Mask Position */
#define FLEX_TWI_IMR_TXRDY_Msk                (_UINT32_(0x1) << FLEX_TWI_IMR_TXRDY_Pos)            /* (FLEX_TWI_IMR) Transmit Holding Register Ready Interrupt Mask Mask */
#define FLEX_TWI_IMR_TXRDY(value)             (FLEX_TWI_IMR_TXRDY_Msk & (_UINT32_(value) << FLEX_TWI_IMR_TXRDY_Pos)) /* Assigment of value for TXRDY in the FLEX_TWI_IMR register */
#define FLEX_TWI_IMR_SVACC_Pos                _UINT32_(4)                                          /* (FLEX_TWI_IMR) Client Access Interrupt Mask Position */
#define FLEX_TWI_IMR_SVACC_Msk                (_UINT32_(0x1) << FLEX_TWI_IMR_SVACC_Pos)            /* (FLEX_TWI_IMR) Client Access Interrupt Mask Mask */
#define FLEX_TWI_IMR_SVACC(value)             (FLEX_TWI_IMR_SVACC_Msk & (_UINT32_(value) << FLEX_TWI_IMR_SVACC_Pos)) /* Assigment of value for SVACC in the FLEX_TWI_IMR register */
#define FLEX_TWI_IMR_GACC_Pos                 _UINT32_(5)                                          /* (FLEX_TWI_IMR) General Call Access Interrupt Mask Position */
#define FLEX_TWI_IMR_GACC_Msk                 (_UINT32_(0x1) << FLEX_TWI_IMR_GACC_Pos)             /* (FLEX_TWI_IMR) General Call Access Interrupt Mask Mask */
#define FLEX_TWI_IMR_GACC(value)              (FLEX_TWI_IMR_GACC_Msk & (_UINT32_(value) << FLEX_TWI_IMR_GACC_Pos)) /* Assigment of value for GACC in the FLEX_TWI_IMR register */
#define FLEX_TWI_IMR_OVRE_Pos                 _UINT32_(6)                                          /* (FLEX_TWI_IMR) Overrun Error Interrupt Mask Position */
#define FLEX_TWI_IMR_OVRE_Msk                 (_UINT32_(0x1) << FLEX_TWI_IMR_OVRE_Pos)             /* (FLEX_TWI_IMR) Overrun Error Interrupt Mask Mask */
#define FLEX_TWI_IMR_OVRE(value)              (FLEX_TWI_IMR_OVRE_Msk & (_UINT32_(value) << FLEX_TWI_IMR_OVRE_Pos)) /* Assigment of value for OVRE in the FLEX_TWI_IMR register */
#define FLEX_TWI_IMR_UNRE_Pos                 _UINT32_(7)                                          /* (FLEX_TWI_IMR) Underrun Error Interrupt Mask Position */
#define FLEX_TWI_IMR_UNRE_Msk                 (_UINT32_(0x1) << FLEX_TWI_IMR_UNRE_Pos)             /* (FLEX_TWI_IMR) Underrun Error Interrupt Mask Mask */
#define FLEX_TWI_IMR_UNRE(value)              (FLEX_TWI_IMR_UNRE_Msk & (_UINT32_(value) << FLEX_TWI_IMR_UNRE_Pos)) /* Assigment of value for UNRE in the FLEX_TWI_IMR register */
#define FLEX_TWI_IMR_NACK_Pos                 _UINT32_(8)                                          /* (FLEX_TWI_IMR) Not Acknowledge Interrupt Mask Position */
#define FLEX_TWI_IMR_NACK_Msk                 (_UINT32_(0x1) << FLEX_TWI_IMR_NACK_Pos)             /* (FLEX_TWI_IMR) Not Acknowledge Interrupt Mask Mask */
#define FLEX_TWI_IMR_NACK(value)              (FLEX_TWI_IMR_NACK_Msk & (_UINT32_(value) << FLEX_TWI_IMR_NACK_Pos)) /* Assigment of value for NACK in the FLEX_TWI_IMR register */
#define FLEX_TWI_IMR_ARBLST_Pos               _UINT32_(9)                                          /* (FLEX_TWI_IMR) Arbitration Lost Interrupt Mask Position */
#define FLEX_TWI_IMR_ARBLST_Msk               (_UINT32_(0x1) << FLEX_TWI_IMR_ARBLST_Pos)           /* (FLEX_TWI_IMR) Arbitration Lost Interrupt Mask Mask */
#define FLEX_TWI_IMR_ARBLST(value)            (FLEX_TWI_IMR_ARBLST_Msk & (_UINT32_(value) << FLEX_TWI_IMR_ARBLST_Pos)) /* Assigment of value for ARBLST in the FLEX_TWI_IMR register */
#define FLEX_TWI_IMR_SCL_WS_Pos               _UINT32_(10)                                         /* (FLEX_TWI_IMR) Clock Wait State Interrupt Mask Position */
#define FLEX_TWI_IMR_SCL_WS_Msk               (_UINT32_(0x1) << FLEX_TWI_IMR_SCL_WS_Pos)           /* (FLEX_TWI_IMR) Clock Wait State Interrupt Mask Mask */
#define FLEX_TWI_IMR_SCL_WS(value)            (FLEX_TWI_IMR_SCL_WS_Msk & (_UINT32_(value) << FLEX_TWI_IMR_SCL_WS_Pos)) /* Assigment of value for SCL_WS in the FLEX_TWI_IMR register */
#define FLEX_TWI_IMR_EOSACC_Pos               _UINT32_(11)                                         /* (FLEX_TWI_IMR) End Of Client Access Interrupt Mask Position */
#define FLEX_TWI_IMR_EOSACC_Msk               (_UINT32_(0x1) << FLEX_TWI_IMR_EOSACC_Pos)           /* (FLEX_TWI_IMR) End Of Client Access Interrupt Mask Mask */
#define FLEX_TWI_IMR_EOSACC(value)            (FLEX_TWI_IMR_EOSACC_Msk & (_UINT32_(value) << FLEX_TWI_IMR_EOSACC_Pos)) /* Assigment of value for EOSACC in the FLEX_TWI_IMR register */
#define FLEX_TWI_IMR_ENDRX_Pos                _UINT32_(12)                                         /* (FLEX_TWI_IMR) End of Receive Buffer Interrupt Mask Position */
#define FLEX_TWI_IMR_ENDRX_Msk                (_UINT32_(0x1) << FLEX_TWI_IMR_ENDRX_Pos)            /* (FLEX_TWI_IMR) End of Receive Buffer Interrupt Mask Mask */
#define FLEX_TWI_IMR_ENDRX(value)             (FLEX_TWI_IMR_ENDRX_Msk & (_UINT32_(value) << FLEX_TWI_IMR_ENDRX_Pos)) /* Assigment of value for ENDRX in the FLEX_TWI_IMR register */
#define FLEX_TWI_IMR_ENDTX_Pos                _UINT32_(13)                                         /* (FLEX_TWI_IMR) End of Transmit Buffer Interrupt Mask Position */
#define FLEX_TWI_IMR_ENDTX_Msk                (_UINT32_(0x1) << FLEX_TWI_IMR_ENDTX_Pos)            /* (FLEX_TWI_IMR) End of Transmit Buffer Interrupt Mask Mask */
#define FLEX_TWI_IMR_ENDTX(value)             (FLEX_TWI_IMR_ENDTX_Msk & (_UINT32_(value) << FLEX_TWI_IMR_ENDTX_Pos)) /* Assigment of value for ENDTX in the FLEX_TWI_IMR register */
#define FLEX_TWI_IMR_RXBUFF_Pos               _UINT32_(14)                                         /* (FLEX_TWI_IMR) Receive Buffer Full Interrupt Mask Position */
#define FLEX_TWI_IMR_RXBUFF_Msk               (_UINT32_(0x1) << FLEX_TWI_IMR_RXBUFF_Pos)           /* (FLEX_TWI_IMR) Receive Buffer Full Interrupt Mask Mask */
#define FLEX_TWI_IMR_RXBUFF(value)            (FLEX_TWI_IMR_RXBUFF_Msk & (_UINT32_(value) << FLEX_TWI_IMR_RXBUFF_Pos)) /* Assigment of value for RXBUFF in the FLEX_TWI_IMR register */
#define FLEX_TWI_IMR_TXBUFE_Pos               _UINT32_(15)                                         /* (FLEX_TWI_IMR) Transmit Buffer Empty Interrupt Mask Position */
#define FLEX_TWI_IMR_TXBUFE_Msk               (_UINT32_(0x1) << FLEX_TWI_IMR_TXBUFE_Pos)           /* (FLEX_TWI_IMR) Transmit Buffer Empty Interrupt Mask Mask */
#define FLEX_TWI_IMR_TXBUFE(value)            (FLEX_TWI_IMR_TXBUFE_Msk & (_UINT32_(value) << FLEX_TWI_IMR_TXBUFE_Pos)) /* Assigment of value for TXBUFE in the FLEX_TWI_IMR register */
#define FLEX_TWI_IMR_MCACK_Pos                _UINT32_(16)                                         /* (FLEX_TWI_IMR) Host Code Acknowledge Interrupt Mask Position */
#define FLEX_TWI_IMR_MCACK_Msk                (_UINT32_(0x1) << FLEX_TWI_IMR_MCACK_Pos)            /* (FLEX_TWI_IMR) Host Code Acknowledge Interrupt Mask Mask */
#define FLEX_TWI_IMR_MCACK(value)             (FLEX_TWI_IMR_MCACK_Msk & (_UINT32_(value) << FLEX_TWI_IMR_MCACK_Pos)) /* Assigment of value for MCACK in the FLEX_TWI_IMR register */
#define FLEX_TWI_IMR_TOUT_Pos                 _UINT32_(18)                                         /* (FLEX_TWI_IMR) Timeout Error Interrupt Mask Position */
#define FLEX_TWI_IMR_TOUT_Msk                 (_UINT32_(0x1) << FLEX_TWI_IMR_TOUT_Pos)             /* (FLEX_TWI_IMR) Timeout Error Interrupt Mask Mask */
#define FLEX_TWI_IMR_TOUT(value)              (FLEX_TWI_IMR_TOUT_Msk & (_UINT32_(value) << FLEX_TWI_IMR_TOUT_Pos)) /* Assigment of value for TOUT in the FLEX_TWI_IMR register */
#define FLEX_TWI_IMR_PECERR_Pos               _UINT32_(19)                                         /* (FLEX_TWI_IMR) PEC Error Interrupt Mask Position */
#define FLEX_TWI_IMR_PECERR_Msk               (_UINT32_(0x1) << FLEX_TWI_IMR_PECERR_Pos)           /* (FLEX_TWI_IMR) PEC Error Interrupt Mask Mask */
#define FLEX_TWI_IMR_PECERR(value)            (FLEX_TWI_IMR_PECERR_Msk & (_UINT32_(value) << FLEX_TWI_IMR_PECERR_Pos)) /* Assigment of value for PECERR in the FLEX_TWI_IMR register */
#define FLEX_TWI_IMR_SMBDAM_Pos               _UINT32_(20)                                         /* (FLEX_TWI_IMR) SMBus Default Address Match Interrupt Mask Position */
#define FLEX_TWI_IMR_SMBDAM_Msk               (_UINT32_(0x1) << FLEX_TWI_IMR_SMBDAM_Pos)           /* (FLEX_TWI_IMR) SMBus Default Address Match Interrupt Mask Mask */
#define FLEX_TWI_IMR_SMBDAM(value)            (FLEX_TWI_IMR_SMBDAM_Msk & (_UINT32_(value) << FLEX_TWI_IMR_SMBDAM_Pos)) /* Assigment of value for SMBDAM in the FLEX_TWI_IMR register */
#define FLEX_TWI_IMR_SMBHHM_Pos               _UINT32_(21)                                         /* (FLEX_TWI_IMR) SMBus Host Header Address Match Interrupt Mask Position */
#define FLEX_TWI_IMR_SMBHHM_Msk               (_UINT32_(0x1) << FLEX_TWI_IMR_SMBHHM_Pos)           /* (FLEX_TWI_IMR) SMBus Host Header Address Match Interrupt Mask Mask */
#define FLEX_TWI_IMR_SMBHHM(value)            (FLEX_TWI_IMR_SMBHHM_Msk & (_UINT32_(value) << FLEX_TWI_IMR_SMBHHM_Pos)) /* Assigment of value for SMBHHM in the FLEX_TWI_IMR register */
#define FLEX_TWI_IMR_Msk                      _UINT32_(0x003DFFF7)                                 /* (FLEX_TWI_IMR) Register Mask  */


/* -------- FLEX_TWI_RHR : (FLEXCOM Offset: 0x630) ( R/ 32) TWI Receive Holding Register -------- */
#define FLEX_TWI_RHR_RXDATA_Pos               _UINT32_(0)                                          /* (FLEX_TWI_RHR) Host or Client Receive Holding Data Position */
#define FLEX_TWI_RHR_RXDATA_Msk               (_UINT32_(0xFF) << FLEX_TWI_RHR_RXDATA_Pos)          /* (FLEX_TWI_RHR) Host or Client Receive Holding Data Mask */
#define FLEX_TWI_RHR_RXDATA(value)            (FLEX_TWI_RHR_RXDATA_Msk & (_UINT32_(value) << FLEX_TWI_RHR_RXDATA_Pos)) /* Assigment of value for RXDATA in the FLEX_TWI_RHR register */
#define FLEX_TWI_RHR_SSTATE_Pos               _UINT32_(8)                                          /* (FLEX_TWI_RHR) Start State (Client Sniffer Mode only) Position */
#define FLEX_TWI_RHR_SSTATE_Msk               (_UINT32_(0x3) << FLEX_TWI_RHR_SSTATE_Pos)           /* (FLEX_TWI_RHR) Start State (Client Sniffer Mode only) Mask */
#define FLEX_TWI_RHR_SSTATE(value)            (FLEX_TWI_RHR_SSTATE_Msk & (_UINT32_(value) << FLEX_TWI_RHR_SSTATE_Pos)) /* Assigment of value for SSTATE in the FLEX_TWI_RHR register */
#define   FLEX_TWI_RHR_SSTATE_NOSTART_Val     _UINT32_(0x0)                                        /* (FLEX_TWI_RHR) No START detected with the logged data  */
#define   FLEX_TWI_RHR_SSTATE_START_Val       _UINT32_(0x1)                                        /* (FLEX_TWI_RHR) START (S) detected with the logged data  */
#define   FLEX_TWI_RHR_SSTATE_RSTART_Val      _UINT32_(0x2)                                        /* (FLEX_TWI_RHR) Repeated START (Sr) detected with the logged data  */
#define   FLEX_TWI_RHR_SSTATE_UNDEF_Val       _UINT32_(0x3)                                        /* (FLEX_TWI_RHR) Not defined  */
#define FLEX_TWI_RHR_SSTATE_NOSTART           (FLEX_TWI_RHR_SSTATE_NOSTART_Val << FLEX_TWI_RHR_SSTATE_Pos) /* (FLEX_TWI_RHR) No START detected with the logged data Position  */
#define FLEX_TWI_RHR_SSTATE_START             (FLEX_TWI_RHR_SSTATE_START_Val << FLEX_TWI_RHR_SSTATE_Pos) /* (FLEX_TWI_RHR) START (S) detected with the logged data Position  */
#define FLEX_TWI_RHR_SSTATE_RSTART            (FLEX_TWI_RHR_SSTATE_RSTART_Val << FLEX_TWI_RHR_SSTATE_Pos) /* (FLEX_TWI_RHR) Repeated START (Sr) detected with the logged data Position  */
#define FLEX_TWI_RHR_SSTATE_UNDEF             (FLEX_TWI_RHR_SSTATE_UNDEF_Val << FLEX_TWI_RHR_SSTATE_Pos) /* (FLEX_TWI_RHR) Not defined Position  */
#define FLEX_TWI_RHR_PSTATE_Pos               _UINT32_(10)                                         /* (FLEX_TWI_RHR) Stop State (Client Sniffer Mode only) Position */
#define FLEX_TWI_RHR_PSTATE_Msk               (_UINT32_(0x1) << FLEX_TWI_RHR_PSTATE_Pos)           /* (FLEX_TWI_RHR) Stop State (Client Sniffer Mode only) Mask */
#define FLEX_TWI_RHR_PSTATE(value)            (FLEX_TWI_RHR_PSTATE_Msk & (_UINT32_(value) << FLEX_TWI_RHR_PSTATE_Pos)) /* Assigment of value for PSTATE in the FLEX_TWI_RHR register */
#define FLEX_TWI_RHR_ASTATE_Pos               _UINT32_(11)                                         /* (FLEX_TWI_RHR) Acknowledge State (Client Sniffer Mode only) Position */
#define FLEX_TWI_RHR_ASTATE_Msk               (_UINT32_(0x3) << FLEX_TWI_RHR_ASTATE_Pos)           /* (FLEX_TWI_RHR) Acknowledge State (Client Sniffer Mode only) Mask */
#define FLEX_TWI_RHR_ASTATE(value)            (FLEX_TWI_RHR_ASTATE_Msk & (_UINT32_(value) << FLEX_TWI_RHR_ASTATE_Pos)) /* Assigment of value for ASTATE in the FLEX_TWI_RHR register */
#define   FLEX_TWI_RHR_ASTATE_NONE_Val        _UINT32_(0x0)                                        /* (FLEX_TWI_RHR) No Acknowledge or Nacknowledge detected after previously logged data  */
#define   FLEX_TWI_RHR_ASTATE_ACK_Val         _UINT32_(0x1)                                        /* (FLEX_TWI_RHR) Acknowledge (A) detected after previously logged data  */
#define   FLEX_TWI_RHR_ASTATE_NACK_Val        _UINT32_(0x2)                                        /* (FLEX_TWI_RHR) Nacknowledge (NA) detected after previously logged data  */
#define   FLEX_TWI_RHR_ASTATE_UNDEF_Val       _UINT32_(0x3)                                        /* (FLEX_TWI_RHR) Not defined  */
#define FLEX_TWI_RHR_ASTATE_NONE              (FLEX_TWI_RHR_ASTATE_NONE_Val << FLEX_TWI_RHR_ASTATE_Pos) /* (FLEX_TWI_RHR) No Acknowledge or Nacknowledge detected after previously logged data Position  */
#define FLEX_TWI_RHR_ASTATE_ACK               (FLEX_TWI_RHR_ASTATE_ACK_Val << FLEX_TWI_RHR_ASTATE_Pos) /* (FLEX_TWI_RHR) Acknowledge (A) detected after previously logged data Position  */
#define FLEX_TWI_RHR_ASTATE_NACK              (FLEX_TWI_RHR_ASTATE_NACK_Val << FLEX_TWI_RHR_ASTATE_Pos) /* (FLEX_TWI_RHR) Nacknowledge (NA) detected after previously logged data Position  */
#define FLEX_TWI_RHR_ASTATE_UNDEF             (FLEX_TWI_RHR_ASTATE_UNDEF_Val << FLEX_TWI_RHR_ASTATE_Pos) /* (FLEX_TWI_RHR) Not defined Position  */
#define FLEX_TWI_RHR_Msk                      _UINT32_(0x00001FFF)                                 /* (FLEX_TWI_RHR) Register Mask  */

/* FIFO_ENABLED mode */
#define FLEX_TWI_RHR_FIFO_ENABLED_RXDATA0_Pos _UINT32_(0)                                          /* (FLEX_TWI_RHR) Host or Client Receive Holding Data 0 Position */
#define FLEX_TWI_RHR_FIFO_ENABLED_RXDATA0_Msk (_UINT32_(0xFF) << FLEX_TWI_RHR_FIFO_ENABLED_RXDATA0_Pos) /* (FLEX_TWI_RHR) Host or Client Receive Holding Data 0 Mask */
#define FLEX_TWI_RHR_FIFO_ENABLED_RXDATA0(value) (FLEX_TWI_RHR_FIFO_ENABLED_RXDATA0_Msk & (_UINT32_(value) << FLEX_TWI_RHR_FIFO_ENABLED_RXDATA0_Pos))
#define FLEX_TWI_RHR_FIFO_ENABLED_RXDATA1_Pos _UINT32_(8)                                          /* (FLEX_TWI_RHR) Host or Client Receive Holding Data 1 Position */
#define FLEX_TWI_RHR_FIFO_ENABLED_RXDATA1_Msk (_UINT32_(0xFF) << FLEX_TWI_RHR_FIFO_ENABLED_RXDATA1_Pos) /* (FLEX_TWI_RHR) Host or Client Receive Holding Data 1 Mask */
#define FLEX_TWI_RHR_FIFO_ENABLED_RXDATA1(value) (FLEX_TWI_RHR_FIFO_ENABLED_RXDATA1_Msk & (_UINT32_(value) << FLEX_TWI_RHR_FIFO_ENABLED_RXDATA1_Pos))
#define FLEX_TWI_RHR_FIFO_ENABLED_RXDATA2_Pos _UINT32_(16)                                         /* (FLEX_TWI_RHR) Host or Client Receive Holding Data 2 Position */
#define FLEX_TWI_RHR_FIFO_ENABLED_RXDATA2_Msk (_UINT32_(0xFF) << FLEX_TWI_RHR_FIFO_ENABLED_RXDATA2_Pos) /* (FLEX_TWI_RHR) Host or Client Receive Holding Data 2 Mask */
#define FLEX_TWI_RHR_FIFO_ENABLED_RXDATA2(value) (FLEX_TWI_RHR_FIFO_ENABLED_RXDATA2_Msk & (_UINT32_(value) << FLEX_TWI_RHR_FIFO_ENABLED_RXDATA2_Pos))
#define FLEX_TWI_RHR_FIFO_ENABLED_RXDATA3_Pos _UINT32_(24)                                         /* (FLEX_TWI_RHR) Host or Client Receive Holding Data 3 Position */
#define FLEX_TWI_RHR_FIFO_ENABLED_RXDATA3_Msk (_UINT32_(0xFF) << FLEX_TWI_RHR_FIFO_ENABLED_RXDATA3_Pos) /* (FLEX_TWI_RHR) Host or Client Receive Holding Data 3 Mask */
#define FLEX_TWI_RHR_FIFO_ENABLED_RXDATA3(value) (FLEX_TWI_RHR_FIFO_ENABLED_RXDATA3_Msk & (_UINT32_(value) << FLEX_TWI_RHR_FIFO_ENABLED_RXDATA3_Pos))
#define FLEX_TWI_RHR_FIFO_ENABLED_Msk         _UINT32_(0xFFFFFFFF)                                  /* (FLEX_TWI_RHR_FIFO_ENABLED) Register Mask  */


/* -------- FLEX_TWI_THR : (FLEXCOM Offset: 0x634) ( /W 32) TWI Transmit Holding Register -------- */
#define FLEX_TWI_THR_TXDATA_Pos               _UINT32_(0)                                          /* (FLEX_TWI_THR) Host or Client Transmit Holding Data Position */
#define FLEX_TWI_THR_TXDATA_Msk               (_UINT32_(0xFF) << FLEX_TWI_THR_TXDATA_Pos)          /* (FLEX_TWI_THR) Host or Client Transmit Holding Data Mask */
#define FLEX_TWI_THR_TXDATA(value)            (FLEX_TWI_THR_TXDATA_Msk & (_UINT32_(value) << FLEX_TWI_THR_TXDATA_Pos)) /* Assigment of value for TXDATA in the FLEX_TWI_THR register */
#define FLEX_TWI_THR_Msk                      _UINT32_(0x000000FF)                                 /* (FLEX_TWI_THR) Register Mask  */

/* FIFO_ENABLED mode */
#define FLEX_TWI_THR_FIFO_ENABLED_TXDATA0_Pos _UINT32_(0)                                          /* (FLEX_TWI_THR) Host or Client Transmit Holding Data 0 Position */
#define FLEX_TWI_THR_FIFO_ENABLED_TXDATA0_Msk (_UINT32_(0xFF) << FLEX_TWI_THR_FIFO_ENABLED_TXDATA0_Pos) /* (FLEX_TWI_THR) Host or Client Transmit Holding Data 0 Mask */
#define FLEX_TWI_THR_FIFO_ENABLED_TXDATA0(value) (FLEX_TWI_THR_FIFO_ENABLED_TXDATA0_Msk & (_UINT32_(value) << FLEX_TWI_THR_FIFO_ENABLED_TXDATA0_Pos))
#define FLEX_TWI_THR_FIFO_ENABLED_TXDATA1_Pos _UINT32_(8)                                          /* (FLEX_TWI_THR) Host or Client Transmit Holding Data 1 Position */
#define FLEX_TWI_THR_FIFO_ENABLED_TXDATA1_Msk (_UINT32_(0xFF) << FLEX_TWI_THR_FIFO_ENABLED_TXDATA1_Pos) /* (FLEX_TWI_THR) Host or Client Transmit Holding Data 1 Mask */
#define FLEX_TWI_THR_FIFO_ENABLED_TXDATA1(value) (FLEX_TWI_THR_FIFO_ENABLED_TXDATA1_Msk & (_UINT32_(value) << FLEX_TWI_THR_FIFO_ENABLED_TXDATA1_Pos))
#define FLEX_TWI_THR_FIFO_ENABLED_TXDATA2_Pos _UINT32_(16)                                         /* (FLEX_TWI_THR) Host or Client Transmit Holding Data 2 Position */
#define FLEX_TWI_THR_FIFO_ENABLED_TXDATA2_Msk (_UINT32_(0xFF) << FLEX_TWI_THR_FIFO_ENABLED_TXDATA2_Pos) /* (FLEX_TWI_THR) Host or Client Transmit Holding Data 2 Mask */
#define FLEX_TWI_THR_FIFO_ENABLED_TXDATA2(value) (FLEX_TWI_THR_FIFO_ENABLED_TXDATA2_Msk & (_UINT32_(value) << FLEX_TWI_THR_FIFO_ENABLED_TXDATA2_Pos))
#define FLEX_TWI_THR_FIFO_ENABLED_TXDATA3_Pos _UINT32_(24)                                         /* (FLEX_TWI_THR) Host or Client Transmit Holding Data 3 Position */
#define FLEX_TWI_THR_FIFO_ENABLED_TXDATA3_Msk (_UINT32_(0xFF) << FLEX_TWI_THR_FIFO_ENABLED_TXDATA3_Pos) /* (FLEX_TWI_THR) Host or Client Transmit Holding Data 3 Mask */
#define FLEX_TWI_THR_FIFO_ENABLED_TXDATA3(value) (FLEX_TWI_THR_FIFO_ENABLED_TXDATA3_Msk & (_UINT32_(value) << FLEX_TWI_THR_FIFO_ENABLED_TXDATA3_Pos))
#define FLEX_TWI_THR_FIFO_ENABLED_Msk         _UINT32_(0xFFFFFFFF)                                  /* (FLEX_TWI_THR_FIFO_ENABLED) Register Mask  */


/* -------- FLEX_TWI_SMBTR : (FLEXCOM Offset: 0x638) (R/W 32) TWI SMBus Timing Register -------- */
#define FLEX_TWI_SMBTR_PRESC_Pos              _UINT32_(0)                                          /* (FLEX_TWI_SMBTR) SMBus Clock Prescaler Position */
#define FLEX_TWI_SMBTR_PRESC_Msk              (_UINT32_(0xF) << FLEX_TWI_SMBTR_PRESC_Pos)          /* (FLEX_TWI_SMBTR) SMBus Clock Prescaler Mask */
#define FLEX_TWI_SMBTR_PRESC(value)           (FLEX_TWI_SMBTR_PRESC_Msk & (_UINT32_(value) << FLEX_TWI_SMBTR_PRESC_Pos)) /* Assigment of value for PRESC in the FLEX_TWI_SMBTR register */
#define FLEX_TWI_SMBTR_TLOWS_Pos              _UINT32_(8)                                          /* (FLEX_TWI_SMBTR) Client Clock Stretch Maximum Cycles Position */
#define FLEX_TWI_SMBTR_TLOWS_Msk              (_UINT32_(0xFF) << FLEX_TWI_SMBTR_TLOWS_Pos)         /* (FLEX_TWI_SMBTR) Client Clock Stretch Maximum Cycles Mask */
#define FLEX_TWI_SMBTR_TLOWS(value)           (FLEX_TWI_SMBTR_TLOWS_Msk & (_UINT32_(value) << FLEX_TWI_SMBTR_TLOWS_Pos)) /* Assigment of value for TLOWS in the FLEX_TWI_SMBTR register */
#define FLEX_TWI_SMBTR_TLOWM_Pos              _UINT32_(16)                                         /* (FLEX_TWI_SMBTR) Host Clock Stretch Maximum Cycles Position */
#define FLEX_TWI_SMBTR_TLOWM_Msk              (_UINT32_(0xFF) << FLEX_TWI_SMBTR_TLOWM_Pos)         /* (FLEX_TWI_SMBTR) Host Clock Stretch Maximum Cycles Mask */
#define FLEX_TWI_SMBTR_TLOWM(value)           (FLEX_TWI_SMBTR_TLOWM_Msk & (_UINT32_(value) << FLEX_TWI_SMBTR_TLOWM_Pos)) /* Assigment of value for TLOWM in the FLEX_TWI_SMBTR register */
#define FLEX_TWI_SMBTR_THMAX_Pos              _UINT32_(24)                                         /* (FLEX_TWI_SMBTR) Clock High Maximum Cycles Position */
#define FLEX_TWI_SMBTR_THMAX_Msk              (_UINT32_(0xFF) << FLEX_TWI_SMBTR_THMAX_Pos)         /* (FLEX_TWI_SMBTR) Clock High Maximum Cycles Mask */
#define FLEX_TWI_SMBTR_THMAX(value)           (FLEX_TWI_SMBTR_THMAX_Msk & (_UINT32_(value) << FLEX_TWI_SMBTR_THMAX_Pos)) /* Assigment of value for THMAX in the FLEX_TWI_SMBTR register */
#define FLEX_TWI_SMBTR_Msk                    _UINT32_(0xFFFFFF0F)                                 /* (FLEX_TWI_SMBTR) Register Mask  */


/* -------- FLEX_TWI_HSR : (FLEXCOM Offset: 0x63C) (R/W 32) TWI High Speed Register -------- */
#define FLEX_TWI_HSR_MCODE_Pos                _UINT32_(0)                                          /* (FLEX_TWI_HSR) TWI High Speed Host Code Position */
#define FLEX_TWI_HSR_MCODE_Msk                (_UINT32_(0xFF) << FLEX_TWI_HSR_MCODE_Pos)           /* (FLEX_TWI_HSR) TWI High Speed Host Code Mask */
#define FLEX_TWI_HSR_MCODE(value)             (FLEX_TWI_HSR_MCODE_Msk & (_UINT32_(value) << FLEX_TWI_HSR_MCODE_Pos)) /* Assigment of value for MCODE in the FLEX_TWI_HSR register */
#define FLEX_TWI_HSR_Msk                      _UINT32_(0x000000FF)                                 /* (FLEX_TWI_HSR) Register Mask  */


/* -------- FLEX_TWI_ACR : (FLEXCOM Offset: 0x640) (R/W 32) TWI Alternative Command Register -------- */
#define FLEX_TWI_ACR_DATAL_Pos                _UINT32_(0)                                          /* (FLEX_TWI_ACR) Data Length Position */
#define FLEX_TWI_ACR_DATAL_Msk                (_UINT32_(0xFF) << FLEX_TWI_ACR_DATAL_Pos)           /* (FLEX_TWI_ACR) Data Length Mask */
#define FLEX_TWI_ACR_DATAL(value)             (FLEX_TWI_ACR_DATAL_Msk & (_UINT32_(value) << FLEX_TWI_ACR_DATAL_Pos)) /* Assigment of value for DATAL in the FLEX_TWI_ACR register */
#define FLEX_TWI_ACR_DIR_Pos                  _UINT32_(8)                                          /* (FLEX_TWI_ACR) Transfer Direction Position */
#define FLEX_TWI_ACR_DIR_Msk                  (_UINT32_(0x1) << FLEX_TWI_ACR_DIR_Pos)              /* (FLEX_TWI_ACR) Transfer Direction Mask */
#define FLEX_TWI_ACR_DIR(value)               (FLEX_TWI_ACR_DIR_Msk & (_UINT32_(value) << FLEX_TWI_ACR_DIR_Pos)) /* Assigment of value for DIR in the FLEX_TWI_ACR register */
#define FLEX_TWI_ACR_PEC_Pos                  _UINT32_(9)                                          /* (FLEX_TWI_ACR) PEC Request (SMBus Mode only) Position */
#define FLEX_TWI_ACR_PEC_Msk                  (_UINT32_(0x1) << FLEX_TWI_ACR_PEC_Pos)              /* (FLEX_TWI_ACR) PEC Request (SMBus Mode only) Mask */
#define FLEX_TWI_ACR_PEC(value)               (FLEX_TWI_ACR_PEC_Msk & (_UINT32_(value) << FLEX_TWI_ACR_PEC_Pos)) /* Assigment of value for PEC in the FLEX_TWI_ACR register */
#define FLEX_TWI_ACR_NDATAL_Pos               _UINT32_(16)                                         /* (FLEX_TWI_ACR) Next Data Length Position */
#define FLEX_TWI_ACR_NDATAL_Msk               (_UINT32_(0xFF) << FLEX_TWI_ACR_NDATAL_Pos)          /* (FLEX_TWI_ACR) Next Data Length Mask */
#define FLEX_TWI_ACR_NDATAL(value)            (FLEX_TWI_ACR_NDATAL_Msk & (_UINT32_(value) << FLEX_TWI_ACR_NDATAL_Pos)) /* Assigment of value for NDATAL in the FLEX_TWI_ACR register */
#define FLEX_TWI_ACR_NDIR_Pos                 _UINT32_(24)                                         /* (FLEX_TWI_ACR) Next Transfer Direction Position */
#define FLEX_TWI_ACR_NDIR_Msk                 (_UINT32_(0x1) << FLEX_TWI_ACR_NDIR_Pos)             /* (FLEX_TWI_ACR) Next Transfer Direction Mask */
#define FLEX_TWI_ACR_NDIR(value)              (FLEX_TWI_ACR_NDIR_Msk & (_UINT32_(value) << FLEX_TWI_ACR_NDIR_Pos)) /* Assigment of value for NDIR in the FLEX_TWI_ACR register */
#define FLEX_TWI_ACR_NPEC_Pos                 _UINT32_(25)                                         /* (FLEX_TWI_ACR) Next PEC Request (SMBus Mode only) Position */
#define FLEX_TWI_ACR_NPEC_Msk                 (_UINT32_(0x1) << FLEX_TWI_ACR_NPEC_Pos)             /* (FLEX_TWI_ACR) Next PEC Request (SMBus Mode only) Mask */
#define FLEX_TWI_ACR_NPEC(value)              (FLEX_TWI_ACR_NPEC_Msk & (_UINT32_(value) << FLEX_TWI_ACR_NPEC_Pos)) /* Assigment of value for NPEC in the FLEX_TWI_ACR register */
#define FLEX_TWI_ACR_Msk                      _UINT32_(0x03FF03FF)                                 /* (FLEX_TWI_ACR) Register Mask  */


/* -------- FLEX_TWI_FILTR : (FLEXCOM Offset: 0x644) (R/W 32) TWI Filter Register -------- */
#define FLEX_TWI_FILTR_FILT_Pos               _UINT32_(0)                                          /* (FLEX_TWI_FILTR) RX Digital Filter Position */
#define FLEX_TWI_FILTR_FILT_Msk               (_UINT32_(0x1) << FLEX_TWI_FILTR_FILT_Pos)           /* (FLEX_TWI_FILTR) RX Digital Filter Mask */
#define FLEX_TWI_FILTR_FILT(value)            (FLEX_TWI_FILTR_FILT_Msk & (_UINT32_(value) << FLEX_TWI_FILTR_FILT_Pos)) /* Assigment of value for FILT in the FLEX_TWI_FILTR register */
#define FLEX_TWI_FILTR_PADFEN_Pos             _UINT32_(1)                                          /* (FLEX_TWI_FILTR) PAD Filter Enable Position */
#define FLEX_TWI_FILTR_PADFEN_Msk             (_UINT32_(0x1) << FLEX_TWI_FILTR_PADFEN_Pos)         /* (FLEX_TWI_FILTR) PAD Filter Enable Mask */
#define FLEX_TWI_FILTR_PADFEN(value)          (FLEX_TWI_FILTR_PADFEN_Msk & (_UINT32_(value) << FLEX_TWI_FILTR_PADFEN_Pos)) /* Assigment of value for PADFEN in the FLEX_TWI_FILTR register */
#define FLEX_TWI_FILTR_THRES_Pos              _UINT32_(8)                                          /* (FLEX_TWI_FILTR) Digital Filter Threshold Position */
#define FLEX_TWI_FILTR_THRES_Msk              (_UINT32_(0x7) << FLEX_TWI_FILTR_THRES_Pos)          /* (FLEX_TWI_FILTR) Digital Filter Threshold Mask */
#define FLEX_TWI_FILTR_THRES(value)           (FLEX_TWI_FILTR_THRES_Msk & (_UINT32_(value) << FLEX_TWI_FILTR_THRES_Pos)) /* Assigment of value for THRES in the FLEX_TWI_FILTR register */
#define FLEX_TWI_FILTR_Msk                    _UINT32_(0x00000703)                                 /* (FLEX_TWI_FILTR) Register Mask  */


/* -------- FLEX_TWI_HSCWGR : (FLEXCOM Offset: 0x648) (R/W 32) TWI High Speed Clock Waveform Generator Register -------- */
#define FLEX_TWI_HSCWGR_HSCLDIV_Pos           _UINT32_(0)                                          /* (FLEX_TWI_HSCWGR) High Speed Clock Low Divider Position */
#define FLEX_TWI_HSCWGR_HSCLDIV_Msk           (_UINT32_(0xFF) << FLEX_TWI_HSCWGR_HSCLDIV_Pos)      /* (FLEX_TWI_HSCWGR) High Speed Clock Low Divider Mask */
#define FLEX_TWI_HSCWGR_HSCLDIV(value)        (FLEX_TWI_HSCWGR_HSCLDIV_Msk & (_UINT32_(value) << FLEX_TWI_HSCWGR_HSCLDIV_Pos)) /* Assigment of value for HSCLDIV in the FLEX_TWI_HSCWGR register */
#define FLEX_TWI_HSCWGR_HSCHDIV_Pos           _UINT32_(8)                                          /* (FLEX_TWI_HSCWGR) High Speed Clock High Divider Position */
#define FLEX_TWI_HSCWGR_HSCHDIV_Msk           (_UINT32_(0xFF) << FLEX_TWI_HSCWGR_HSCHDIV_Pos)      /* (FLEX_TWI_HSCWGR) High Speed Clock High Divider Mask */
#define FLEX_TWI_HSCWGR_HSCHDIV(value)        (FLEX_TWI_HSCWGR_HSCHDIV_Msk & (_UINT32_(value) << FLEX_TWI_HSCWGR_HSCHDIV_Pos)) /* Assigment of value for HSCHDIV in the FLEX_TWI_HSCWGR register */
#define FLEX_TWI_HSCWGR_HSCKDIV_Pos           _UINT32_(16)                                         /* (FLEX_TWI_HSCWGR) High Speed Clock Divider Position */
#define FLEX_TWI_HSCWGR_HSCKDIV_Msk           (_UINT32_(0x7) << FLEX_TWI_HSCWGR_HSCKDIV_Pos)       /* (FLEX_TWI_HSCWGR) High Speed Clock Divider Mask */
#define FLEX_TWI_HSCWGR_HSCKDIV(value)        (FLEX_TWI_HSCWGR_HSCKDIV_Msk & (_UINT32_(value) << FLEX_TWI_HSCWGR_HSCKDIV_Pos)) /* Assigment of value for HSCKDIV in the FLEX_TWI_HSCWGR register */
#define FLEX_TWI_HSCWGR_Msk                   _UINT32_(0x0007FFFF)                                 /* (FLEX_TWI_HSCWGR) Register Mask  */


/* -------- FLEX_TWI_SWMR : (FLEXCOM Offset: 0x64C) (R/W 32) TWI Matching Register -------- */
#define FLEX_TWI_SWMR_SADR1_Pos               _UINT32_(0)                                          /* (FLEX_TWI_SWMR) Client Address 1 Position */
#define FLEX_TWI_SWMR_SADR1_Msk               (_UINT32_(0x7F) << FLEX_TWI_SWMR_SADR1_Pos)          /* (FLEX_TWI_SWMR) Client Address 1 Mask */
#define FLEX_TWI_SWMR_SADR1(value)            (FLEX_TWI_SWMR_SADR1_Msk & (_UINT32_(value) << FLEX_TWI_SWMR_SADR1_Pos)) /* Assigment of value for SADR1 in the FLEX_TWI_SWMR register */
#define FLEX_TWI_SWMR_SADR2_Pos               _UINT32_(8)                                          /* (FLEX_TWI_SWMR) Client Address 2 Position */
#define FLEX_TWI_SWMR_SADR2_Msk               (_UINT32_(0x7F) << FLEX_TWI_SWMR_SADR2_Pos)          /* (FLEX_TWI_SWMR) Client Address 2 Mask */
#define FLEX_TWI_SWMR_SADR2(value)            (FLEX_TWI_SWMR_SADR2_Msk & (_UINT32_(value) << FLEX_TWI_SWMR_SADR2_Pos)) /* Assigment of value for SADR2 in the FLEX_TWI_SWMR register */
#define FLEX_TWI_SWMR_SADR3_Pos               _UINT32_(16)                                         /* (FLEX_TWI_SWMR) Client Address 3 Position */
#define FLEX_TWI_SWMR_SADR3_Msk               (_UINT32_(0x7F) << FLEX_TWI_SWMR_SADR3_Pos)          /* (FLEX_TWI_SWMR) Client Address 3 Mask */
#define FLEX_TWI_SWMR_SADR3(value)            (FLEX_TWI_SWMR_SADR3_Msk & (_UINT32_(value) << FLEX_TWI_SWMR_SADR3_Pos)) /* Assigment of value for SADR3 in the FLEX_TWI_SWMR register */
#define FLEX_TWI_SWMR_DATAM_Pos               _UINT32_(24)                                         /* (FLEX_TWI_SWMR) Data Match Position */
#define FLEX_TWI_SWMR_DATAM_Msk               (_UINT32_(0xFF) << FLEX_TWI_SWMR_DATAM_Pos)          /* (FLEX_TWI_SWMR) Data Match Mask */
#define FLEX_TWI_SWMR_DATAM(value)            (FLEX_TWI_SWMR_DATAM_Msk & (_UINT32_(value) << FLEX_TWI_SWMR_DATAM_Pos)) /* Assigment of value for DATAM in the FLEX_TWI_SWMR register */
#define FLEX_TWI_SWMR_Msk                     _UINT32_(0xFF7F7F7F)                                 /* (FLEX_TWI_SWMR) Register Mask  */


/* -------- FLEX_TWI_FMR : (FLEXCOM Offset: 0x650) (R/W 32) TWI FIFO Mode Register -------- */
#define FLEX_TWI_FMR_TXRDYM_Pos               _UINT32_(0)                                          /* (FLEX_TWI_FMR) Transmitter Ready Mode Position */
#define FLEX_TWI_FMR_TXRDYM_Msk               (_UINT32_(0x3) << FLEX_TWI_FMR_TXRDYM_Pos)           /* (FLEX_TWI_FMR) Transmitter Ready Mode Mask */
#define FLEX_TWI_FMR_TXRDYM(value)            (FLEX_TWI_FMR_TXRDYM_Msk & (_UINT32_(value) << FLEX_TWI_FMR_TXRDYM_Pos)) /* Assigment of value for TXRDYM in the FLEX_TWI_FMR register */
#define   FLEX_TWI_FMR_TXRDYM_ONE_DATA_Val    _UINT32_(0x0)                                        /* (FLEX_TWI_FMR) TXRDY will be at level '1' when at least one data can be written in the transmit FIFO. When DMA is enabled to transfer data, the chunk of 1 byte must be configured in the DMA. If the transfer is performed by software, the access type must be defined as byte.  */
#define   FLEX_TWI_FMR_TXRDYM_TWO_DATA_Val    _UINT32_(0x1)                                        /* (FLEX_TWI_FMR) TXRDY will be at level '1' when at least two data can be written in the transmit FIFO. To minimize system bus load, when DMA is enabled to transfer data, the chunk of 1 halfword (1 halfword carries 2 bytes) must be configured in the DMA. If the transfer is performed by software, the access type can be defined as byte (1 byte per access, 2 accesses) or halfword (2 bytes per access, 1 single access).  */
#define   FLEX_TWI_FMR_TXRDYM_FOUR_DATA_Val   _UINT32_(0x2)                                        /* (FLEX_TWI_FMR) TXRDY will be at level '1' when at least four data can be written in the transmit FIFO. To minimize system bus load, when DMA is enabled to transfer data, the chunk of 1 word (1 word carries 4 bytes) must be configured in the DMA. If the transfer is performed by software, the access type can be defined as byte (1 byte per access, 4 accesses), halfword (2 bytes per access, 2 accesses) or word (4 bytes per access, 1 single access).  */
#define FLEX_TWI_FMR_TXRDYM_ONE_DATA          (FLEX_TWI_FMR_TXRDYM_ONE_DATA_Val << FLEX_TWI_FMR_TXRDYM_Pos) /* (FLEX_TWI_FMR) TXRDY will be at level '1' when at least one data can be written in the transmit FIFO. When DMA is enabled to transfer data, the chunk of 1 byte must be configured in the DMA. If the transfer is performed by software, the access type must be defined as byte. Position  */
#define FLEX_TWI_FMR_TXRDYM_TWO_DATA          (FLEX_TWI_FMR_TXRDYM_TWO_DATA_Val << FLEX_TWI_FMR_TXRDYM_Pos) /* (FLEX_TWI_FMR) TXRDY will be at level '1' when at least two data can be written in the transmit FIFO. To minimize system bus load, when DMA is enabled to transfer data, the chunk of 1 halfword (1 halfword carries 2 bytes) must be configured in the DMA. If the transfer is performed by software, the access type can be defined as byte (1 byte per access, 2 accesses) or halfword (2 bytes per access, 1 single access). Position  */
#define FLEX_TWI_FMR_TXRDYM_FOUR_DATA         (FLEX_TWI_FMR_TXRDYM_FOUR_DATA_Val << FLEX_TWI_FMR_TXRDYM_Pos) /* (FLEX_TWI_FMR) TXRDY will be at level '1' when at least four data can be written in the transmit FIFO. To minimize system bus load, when DMA is enabled to transfer data, the chunk of 1 word (1 word carries 4 bytes) must be configured in the DMA. If the transfer is performed by software, the access type can be defined as byte (1 byte per access, 4 accesses), halfword (2 bytes per access, 2 accesses) or word (4 bytes per access, 1 single access). Position  */
#define FLEX_TWI_FMR_RXRDYM_Pos               _UINT32_(4)                                          /* (FLEX_TWI_FMR) Receiver Ready Mode Position */
#define FLEX_TWI_FMR_RXRDYM_Msk               (_UINT32_(0x3) << FLEX_TWI_FMR_RXRDYM_Pos)           /* (FLEX_TWI_FMR) Receiver Ready Mode Mask */
#define FLEX_TWI_FMR_RXRDYM(value)            (FLEX_TWI_FMR_RXRDYM_Msk & (_UINT32_(value) << FLEX_TWI_FMR_RXRDYM_Pos)) /* Assigment of value for RXRDYM in the FLEX_TWI_FMR register */
#define   FLEX_TWI_FMR_RXRDYM_ONE_DATA_Val    _UINT32_(0x0)                                        /* (FLEX_TWI_FMR) RXRDY will be at level '1' when at least one unread data is in the receive FIFO. When DMA is enabled to transfer data the chunk of 1 byte must be configured in the DMA. If the transfer is performed by software, the access type (byte, halfword) must be defined accordingly.  */
#define   FLEX_TWI_FMR_RXRDYM_TWO_DATA_Val    _UINT32_(0x1)                                        /* (FLEX_TWI_FMR) RXRDY will be at level '1' when at least two unread data are in the receive FIFO. To minimize system bus load, when DMA is enabled to transfer data, the chunk of 1 halfword (1 halfword carries 2 bytes) must be configured in the DMA. If the transfer is performed by software, the access type can be defined as byte (1 byte per access, 2 accesses) or halfword (2 bytes per access, 1 single access).  */
#define   FLEX_TWI_FMR_RXRDYM_FOUR_DATA_Val   _UINT32_(0x2)                                        /* (FLEX_TWI_FMR) RXRDY will be at level '1' when at least four unread data are in the receive FIFO. To minimize system bus load, when DMA is enabled to transfer data, the chunk of 1 word (1 word carries 4 bytes) must be configured in the DMA. If the transfer is performed by software, the access type can be defined as byte (1 byte per access, 4 accesses), halfword (2 bytes per access, 2 accesses) or word (4 bytes per access, 1 single access).  */
#define FLEX_TWI_FMR_RXRDYM_ONE_DATA          (FLEX_TWI_FMR_RXRDYM_ONE_DATA_Val << FLEX_TWI_FMR_RXRDYM_Pos) /* (FLEX_TWI_FMR) RXRDY will be at level '1' when at least one unread data is in the receive FIFO. When DMA is enabled to transfer data the chunk of 1 byte must be configured in the DMA. If the transfer is performed by software, the access type (byte, halfword) must be defined accordingly. Position  */
#define FLEX_TWI_FMR_RXRDYM_TWO_DATA          (FLEX_TWI_FMR_RXRDYM_TWO_DATA_Val << FLEX_TWI_FMR_RXRDYM_Pos) /* (FLEX_TWI_FMR) RXRDY will be at level '1' when at least two unread data are in the receive FIFO. To minimize system bus load, when DMA is enabled to transfer data, the chunk of 1 halfword (1 halfword carries 2 bytes) must be configured in the DMA. If the transfer is performed by software, the access type can be defined as byte (1 byte per access, 2 accesses) or halfword (2 bytes per access, 1 single access). Position  */
#define FLEX_TWI_FMR_RXRDYM_FOUR_DATA         (FLEX_TWI_FMR_RXRDYM_FOUR_DATA_Val << FLEX_TWI_FMR_RXRDYM_Pos) /* (FLEX_TWI_FMR) RXRDY will be at level '1' when at least four unread data are in the receive FIFO. To minimize system bus load, when DMA is enabled to transfer data, the chunk of 1 word (1 word carries 4 bytes) must be configured in the DMA. If the transfer is performed by software, the access type can be defined as byte (1 byte per access, 4 accesses), halfword (2 bytes per access, 2 accesses) or word (4 bytes per access, 1 single access). Position  */
#define FLEX_TWI_FMR_TXFTHRES_Pos             _UINT32_(16)                                         /* (FLEX_TWI_FMR) Transmit FIFO Threshold Position */
#define FLEX_TWI_FMR_TXFTHRES_Msk             (_UINT32_(0x3F) << FLEX_TWI_FMR_TXFTHRES_Pos)        /* (FLEX_TWI_FMR) Transmit FIFO Threshold Mask */
#define FLEX_TWI_FMR_TXFTHRES(value)          (FLEX_TWI_FMR_TXFTHRES_Msk & (_UINT32_(value) << FLEX_TWI_FMR_TXFTHRES_Pos)) /* Assigment of value for TXFTHRES in the FLEX_TWI_FMR register */
#define FLEX_TWI_FMR_RXFTHRES_Pos             _UINT32_(24)                                         /* (FLEX_TWI_FMR) Receive FIFO Threshold Position */
#define FLEX_TWI_FMR_RXFTHRES_Msk             (_UINT32_(0x3F) << FLEX_TWI_FMR_RXFTHRES_Pos)        /* (FLEX_TWI_FMR) Receive FIFO Threshold Mask */
#define FLEX_TWI_FMR_RXFTHRES(value)          (FLEX_TWI_FMR_RXFTHRES_Msk & (_UINT32_(value) << FLEX_TWI_FMR_RXFTHRES_Pos)) /* Assigment of value for RXFTHRES in the FLEX_TWI_FMR register */
#define FLEX_TWI_FMR_Msk                      _UINT32_(0x3F3F0033)                                 /* (FLEX_TWI_FMR) Register Mask  */


/* -------- FLEX_TWI_FLR : (FLEXCOM Offset: 0x654) ( R/ 32) TWI FIFO Level Register -------- */
#define FLEX_TWI_FLR_TXFL_Pos                 _UINT32_(0)                                          /* (FLEX_TWI_FLR) Transmit FIFO Level Position */
#define FLEX_TWI_FLR_TXFL_Msk                 (_UINT32_(0x3F) << FLEX_TWI_FLR_TXFL_Pos)            /* (FLEX_TWI_FLR) Transmit FIFO Level Mask */
#define FLEX_TWI_FLR_TXFL(value)              (FLEX_TWI_FLR_TXFL_Msk & (_UINT32_(value) << FLEX_TWI_FLR_TXFL_Pos)) /* Assigment of value for TXFL in the FLEX_TWI_FLR register */
#define FLEX_TWI_FLR_RXFL_Pos                 _UINT32_(16)                                         /* (FLEX_TWI_FLR) Receive FIFO Level Position */
#define FLEX_TWI_FLR_RXFL_Msk                 (_UINT32_(0x3F) << FLEX_TWI_FLR_RXFL_Pos)            /* (FLEX_TWI_FLR) Receive FIFO Level Mask */
#define FLEX_TWI_FLR_RXFL(value)              (FLEX_TWI_FLR_RXFL_Msk & (_UINT32_(value) << FLEX_TWI_FLR_RXFL_Pos)) /* Assigment of value for RXFL in the FLEX_TWI_FLR register */
#define FLEX_TWI_FLR_Msk                      _UINT32_(0x003F003F)                                 /* (FLEX_TWI_FLR) Register Mask  */


/* -------- FLEX_TWI_FSR : (FLEXCOM Offset: 0x660) ( R/ 32) TWI FIFO Status Register -------- */
#define FLEX_TWI_FSR_TXFEF_Pos                _UINT32_(0)                                          /* (FLEX_TWI_FSR) Transmit FIFO Empty Flag (cleared on read) Position */
#define FLEX_TWI_FSR_TXFEF_Msk                (_UINT32_(0x1) << FLEX_TWI_FSR_TXFEF_Pos)            /* (FLEX_TWI_FSR) Transmit FIFO Empty Flag (cleared on read) Mask */
#define FLEX_TWI_FSR_TXFEF(value)             (FLEX_TWI_FSR_TXFEF_Msk & (_UINT32_(value) << FLEX_TWI_FSR_TXFEF_Pos)) /* Assigment of value for TXFEF in the FLEX_TWI_FSR register */
#define FLEX_TWI_FSR_TXFFF_Pos                _UINT32_(1)                                          /* (FLEX_TWI_FSR) Transmit FIFO Full Flag (cleared on read) Position */
#define FLEX_TWI_FSR_TXFFF_Msk                (_UINT32_(0x1) << FLEX_TWI_FSR_TXFFF_Pos)            /* (FLEX_TWI_FSR) Transmit FIFO Full Flag (cleared on read) Mask */
#define FLEX_TWI_FSR_TXFFF(value)             (FLEX_TWI_FSR_TXFFF_Msk & (_UINT32_(value) << FLEX_TWI_FSR_TXFFF_Pos)) /* Assigment of value for TXFFF in the FLEX_TWI_FSR register */
#define FLEX_TWI_FSR_TXFTHF_Pos               _UINT32_(2)                                          /* (FLEX_TWI_FSR) Transmit FIFO Threshold Flag (cleared on read) Position */
#define FLEX_TWI_FSR_TXFTHF_Msk               (_UINT32_(0x1) << FLEX_TWI_FSR_TXFTHF_Pos)           /* (FLEX_TWI_FSR) Transmit FIFO Threshold Flag (cleared on read) Mask */
#define FLEX_TWI_FSR_TXFTHF(value)            (FLEX_TWI_FSR_TXFTHF_Msk & (_UINT32_(value) << FLEX_TWI_FSR_TXFTHF_Pos)) /* Assigment of value for TXFTHF in the FLEX_TWI_FSR register */
#define FLEX_TWI_FSR_RXFEF_Pos                _UINT32_(3)                                          /* (FLEX_TWI_FSR) Receive FIFO Empty Flag Position */
#define FLEX_TWI_FSR_RXFEF_Msk                (_UINT32_(0x1) << FLEX_TWI_FSR_RXFEF_Pos)            /* (FLEX_TWI_FSR) Receive FIFO Empty Flag Mask */
#define FLEX_TWI_FSR_RXFEF(value)             (FLEX_TWI_FSR_RXFEF_Msk & (_UINT32_(value) << FLEX_TWI_FSR_RXFEF_Pos)) /* Assigment of value for RXFEF in the FLEX_TWI_FSR register */
#define FLEX_TWI_FSR_RXFFF_Pos                _UINT32_(4)                                          /* (FLEX_TWI_FSR) Receive FIFO Full Flag Position */
#define FLEX_TWI_FSR_RXFFF_Msk                (_UINT32_(0x1) << FLEX_TWI_FSR_RXFFF_Pos)            /* (FLEX_TWI_FSR) Receive FIFO Full Flag Mask */
#define FLEX_TWI_FSR_RXFFF(value)             (FLEX_TWI_FSR_RXFFF_Msk & (_UINT32_(value) << FLEX_TWI_FSR_RXFFF_Pos)) /* Assigment of value for RXFFF in the FLEX_TWI_FSR register */
#define FLEX_TWI_FSR_RXFTHF_Pos               _UINT32_(5)                                          /* (FLEX_TWI_FSR) Receive FIFO Threshold Flag Position */
#define FLEX_TWI_FSR_RXFTHF_Msk               (_UINT32_(0x1) << FLEX_TWI_FSR_RXFTHF_Pos)           /* (FLEX_TWI_FSR) Receive FIFO Threshold Flag Mask */
#define FLEX_TWI_FSR_RXFTHF(value)            (FLEX_TWI_FSR_RXFTHF_Msk & (_UINT32_(value) << FLEX_TWI_FSR_RXFTHF_Pos)) /* Assigment of value for RXFTHF in the FLEX_TWI_FSR register */
#define FLEX_TWI_FSR_TXFPTEF_Pos              _UINT32_(6)                                          /* (FLEX_TWI_FSR) Transmit FIFO Pointer Error Flag Position */
#define FLEX_TWI_FSR_TXFPTEF_Msk              (_UINT32_(0x1) << FLEX_TWI_FSR_TXFPTEF_Pos)          /* (FLEX_TWI_FSR) Transmit FIFO Pointer Error Flag Mask */
#define FLEX_TWI_FSR_TXFPTEF(value)           (FLEX_TWI_FSR_TXFPTEF_Msk & (_UINT32_(value) << FLEX_TWI_FSR_TXFPTEF_Pos)) /* Assigment of value for TXFPTEF in the FLEX_TWI_FSR register */
#define FLEX_TWI_FSR_RXFPTEF_Pos              _UINT32_(7)                                          /* (FLEX_TWI_FSR) Receive FIFO Pointer Error Flag Position */
#define FLEX_TWI_FSR_RXFPTEF_Msk              (_UINT32_(0x1) << FLEX_TWI_FSR_RXFPTEF_Pos)          /* (FLEX_TWI_FSR) Receive FIFO Pointer Error Flag Mask */
#define FLEX_TWI_FSR_RXFPTEF(value)           (FLEX_TWI_FSR_RXFPTEF_Msk & (_UINT32_(value) << FLEX_TWI_FSR_RXFPTEF_Pos)) /* Assigment of value for RXFPTEF in the FLEX_TWI_FSR register */
#define FLEX_TWI_FSR_Msk                      _UINT32_(0x000000FF)                                 /* (FLEX_TWI_FSR) Register Mask  */


/* -------- FLEX_TWI_FIER : (FLEXCOM Offset: 0x664) ( /W 32) TWI FIFO Interrupt Enable Register -------- */
#define FLEX_TWI_FIER_TXFEF_Pos               _UINT32_(0)                                          /* (FLEX_TWI_FIER) TXFEF Interrupt Enable Position */
#define FLEX_TWI_FIER_TXFEF_Msk               (_UINT32_(0x1) << FLEX_TWI_FIER_TXFEF_Pos)           /* (FLEX_TWI_FIER) TXFEF Interrupt Enable Mask */
#define FLEX_TWI_FIER_TXFEF(value)            (FLEX_TWI_FIER_TXFEF_Msk & (_UINT32_(value) << FLEX_TWI_FIER_TXFEF_Pos)) /* Assigment of value for TXFEF in the FLEX_TWI_FIER register */
#define FLEX_TWI_FIER_TXFFF_Pos               _UINT32_(1)                                          /* (FLEX_TWI_FIER) TXFFF Interrupt Enable Position */
#define FLEX_TWI_FIER_TXFFF_Msk               (_UINT32_(0x1) << FLEX_TWI_FIER_TXFFF_Pos)           /* (FLEX_TWI_FIER) TXFFF Interrupt Enable Mask */
#define FLEX_TWI_FIER_TXFFF(value)            (FLEX_TWI_FIER_TXFFF_Msk & (_UINT32_(value) << FLEX_TWI_FIER_TXFFF_Pos)) /* Assigment of value for TXFFF in the FLEX_TWI_FIER register */
#define FLEX_TWI_FIER_TXFTHF_Pos              _UINT32_(2)                                          /* (FLEX_TWI_FIER) TXFTHF Interrupt Enable Position */
#define FLEX_TWI_FIER_TXFTHF_Msk              (_UINT32_(0x1) << FLEX_TWI_FIER_TXFTHF_Pos)          /* (FLEX_TWI_FIER) TXFTHF Interrupt Enable Mask */
#define FLEX_TWI_FIER_TXFTHF(value)           (FLEX_TWI_FIER_TXFTHF_Msk & (_UINT32_(value) << FLEX_TWI_FIER_TXFTHF_Pos)) /* Assigment of value for TXFTHF in the FLEX_TWI_FIER register */
#define FLEX_TWI_FIER_RXFEF_Pos               _UINT32_(3)                                          /* (FLEX_TWI_FIER) RXFEF Interrupt Enable Position */
#define FLEX_TWI_FIER_RXFEF_Msk               (_UINT32_(0x1) << FLEX_TWI_FIER_RXFEF_Pos)           /* (FLEX_TWI_FIER) RXFEF Interrupt Enable Mask */
#define FLEX_TWI_FIER_RXFEF(value)            (FLEX_TWI_FIER_RXFEF_Msk & (_UINT32_(value) << FLEX_TWI_FIER_RXFEF_Pos)) /* Assigment of value for RXFEF in the FLEX_TWI_FIER register */
#define FLEX_TWI_FIER_RXFFF_Pos               _UINT32_(4)                                          /* (FLEX_TWI_FIER) RXFFF Interrupt Enable Position */
#define FLEX_TWI_FIER_RXFFF_Msk               (_UINT32_(0x1) << FLEX_TWI_FIER_RXFFF_Pos)           /* (FLEX_TWI_FIER) RXFFF Interrupt Enable Mask */
#define FLEX_TWI_FIER_RXFFF(value)            (FLEX_TWI_FIER_RXFFF_Msk & (_UINT32_(value) << FLEX_TWI_FIER_RXFFF_Pos)) /* Assigment of value for RXFFF in the FLEX_TWI_FIER register */
#define FLEX_TWI_FIER_RXFTHF_Pos              _UINT32_(5)                                          /* (FLEX_TWI_FIER) RXFTHF Interrupt Enable Position */
#define FLEX_TWI_FIER_RXFTHF_Msk              (_UINT32_(0x1) << FLEX_TWI_FIER_RXFTHF_Pos)          /* (FLEX_TWI_FIER) RXFTHF Interrupt Enable Mask */
#define FLEX_TWI_FIER_RXFTHF(value)           (FLEX_TWI_FIER_RXFTHF_Msk & (_UINT32_(value) << FLEX_TWI_FIER_RXFTHF_Pos)) /* Assigment of value for RXFTHF in the FLEX_TWI_FIER register */
#define FLEX_TWI_FIER_TXFPTEF_Pos             _UINT32_(6)                                          /* (FLEX_TWI_FIER) TXFPTEF Interrupt Enable Position */
#define FLEX_TWI_FIER_TXFPTEF_Msk             (_UINT32_(0x1) << FLEX_TWI_FIER_TXFPTEF_Pos)         /* (FLEX_TWI_FIER) TXFPTEF Interrupt Enable Mask */
#define FLEX_TWI_FIER_TXFPTEF(value)          (FLEX_TWI_FIER_TXFPTEF_Msk & (_UINT32_(value) << FLEX_TWI_FIER_TXFPTEF_Pos)) /* Assigment of value for TXFPTEF in the FLEX_TWI_FIER register */
#define FLEX_TWI_FIER_RXFPTEF_Pos             _UINT32_(7)                                          /* (FLEX_TWI_FIER) RXFPTEF Interrupt Enable Position */
#define FLEX_TWI_FIER_RXFPTEF_Msk             (_UINT32_(0x1) << FLEX_TWI_FIER_RXFPTEF_Pos)         /* (FLEX_TWI_FIER) RXFPTEF Interrupt Enable Mask */
#define FLEX_TWI_FIER_RXFPTEF(value)          (FLEX_TWI_FIER_RXFPTEF_Msk & (_UINT32_(value) << FLEX_TWI_FIER_RXFPTEF_Pos)) /* Assigment of value for RXFPTEF in the FLEX_TWI_FIER register */
#define FLEX_TWI_FIER_Msk                     _UINT32_(0x000000FF)                                 /* (FLEX_TWI_FIER) Register Mask  */


/* -------- FLEX_TWI_FIDR : (FLEXCOM Offset: 0x668) ( /W 32) TWI FIFO Interrupt Disable Register -------- */
#define FLEX_TWI_FIDR_TXFEF_Pos               _UINT32_(0)                                          /* (FLEX_TWI_FIDR) TXFEF Interrupt Disable Position */
#define FLEX_TWI_FIDR_TXFEF_Msk               (_UINT32_(0x1) << FLEX_TWI_FIDR_TXFEF_Pos)           /* (FLEX_TWI_FIDR) TXFEF Interrupt Disable Mask */
#define FLEX_TWI_FIDR_TXFEF(value)            (FLEX_TWI_FIDR_TXFEF_Msk & (_UINT32_(value) << FLEX_TWI_FIDR_TXFEF_Pos)) /* Assigment of value for TXFEF in the FLEX_TWI_FIDR register */
#define FLEX_TWI_FIDR_TXFFF_Pos               _UINT32_(1)                                          /* (FLEX_TWI_FIDR) TXFFF Interrupt Disable Position */
#define FLEX_TWI_FIDR_TXFFF_Msk               (_UINT32_(0x1) << FLEX_TWI_FIDR_TXFFF_Pos)           /* (FLEX_TWI_FIDR) TXFFF Interrupt Disable Mask */
#define FLEX_TWI_FIDR_TXFFF(value)            (FLEX_TWI_FIDR_TXFFF_Msk & (_UINT32_(value) << FLEX_TWI_FIDR_TXFFF_Pos)) /* Assigment of value for TXFFF in the FLEX_TWI_FIDR register */
#define FLEX_TWI_FIDR_TXFTHF_Pos              _UINT32_(2)                                          /* (FLEX_TWI_FIDR) TXFTHF Interrupt Disable Position */
#define FLEX_TWI_FIDR_TXFTHF_Msk              (_UINT32_(0x1) << FLEX_TWI_FIDR_TXFTHF_Pos)          /* (FLEX_TWI_FIDR) TXFTHF Interrupt Disable Mask */
#define FLEX_TWI_FIDR_TXFTHF(value)           (FLEX_TWI_FIDR_TXFTHF_Msk & (_UINT32_(value) << FLEX_TWI_FIDR_TXFTHF_Pos)) /* Assigment of value for TXFTHF in the FLEX_TWI_FIDR register */
#define FLEX_TWI_FIDR_RXFEF_Pos               _UINT32_(3)                                          /* (FLEX_TWI_FIDR) RXFEF Interrupt Disable Position */
#define FLEX_TWI_FIDR_RXFEF_Msk               (_UINT32_(0x1) << FLEX_TWI_FIDR_RXFEF_Pos)           /* (FLEX_TWI_FIDR) RXFEF Interrupt Disable Mask */
#define FLEX_TWI_FIDR_RXFEF(value)            (FLEX_TWI_FIDR_RXFEF_Msk & (_UINT32_(value) << FLEX_TWI_FIDR_RXFEF_Pos)) /* Assigment of value for RXFEF in the FLEX_TWI_FIDR register */
#define FLEX_TWI_FIDR_RXFFF_Pos               _UINT32_(4)                                          /* (FLEX_TWI_FIDR) RXFFF Interrupt Disable Position */
#define FLEX_TWI_FIDR_RXFFF_Msk               (_UINT32_(0x1) << FLEX_TWI_FIDR_RXFFF_Pos)           /* (FLEX_TWI_FIDR) RXFFF Interrupt Disable Mask */
#define FLEX_TWI_FIDR_RXFFF(value)            (FLEX_TWI_FIDR_RXFFF_Msk & (_UINT32_(value) << FLEX_TWI_FIDR_RXFFF_Pos)) /* Assigment of value for RXFFF in the FLEX_TWI_FIDR register */
#define FLEX_TWI_FIDR_RXFTHF_Pos              _UINT32_(5)                                          /* (FLEX_TWI_FIDR) RXFTHF Interrupt Disable Position */
#define FLEX_TWI_FIDR_RXFTHF_Msk              (_UINT32_(0x1) << FLEX_TWI_FIDR_RXFTHF_Pos)          /* (FLEX_TWI_FIDR) RXFTHF Interrupt Disable Mask */
#define FLEX_TWI_FIDR_RXFTHF(value)           (FLEX_TWI_FIDR_RXFTHF_Msk & (_UINT32_(value) << FLEX_TWI_FIDR_RXFTHF_Pos)) /* Assigment of value for RXFTHF in the FLEX_TWI_FIDR register */
#define FLEX_TWI_FIDR_TXFPTEF_Pos             _UINT32_(6)                                          /* (FLEX_TWI_FIDR) TXFPTEF Interrupt Disable Position */
#define FLEX_TWI_FIDR_TXFPTEF_Msk             (_UINT32_(0x1) << FLEX_TWI_FIDR_TXFPTEF_Pos)         /* (FLEX_TWI_FIDR) TXFPTEF Interrupt Disable Mask */
#define FLEX_TWI_FIDR_TXFPTEF(value)          (FLEX_TWI_FIDR_TXFPTEF_Msk & (_UINT32_(value) << FLEX_TWI_FIDR_TXFPTEF_Pos)) /* Assigment of value for TXFPTEF in the FLEX_TWI_FIDR register */
#define FLEX_TWI_FIDR_RXFPTEF_Pos             _UINT32_(7)                                          /* (FLEX_TWI_FIDR) RXFPTEF Interrupt Disable Position */
#define FLEX_TWI_FIDR_RXFPTEF_Msk             (_UINT32_(0x1) << FLEX_TWI_FIDR_RXFPTEF_Pos)         /* (FLEX_TWI_FIDR) RXFPTEF Interrupt Disable Mask */
#define FLEX_TWI_FIDR_RXFPTEF(value)          (FLEX_TWI_FIDR_RXFPTEF_Msk & (_UINT32_(value) << FLEX_TWI_FIDR_RXFPTEF_Pos)) /* Assigment of value for RXFPTEF in the FLEX_TWI_FIDR register */
#define FLEX_TWI_FIDR_Msk                     _UINT32_(0x000000FF)                                 /* (FLEX_TWI_FIDR) Register Mask  */


/* -------- FLEX_TWI_FIMR : (FLEXCOM Offset: 0x66C) ( R/ 32) TWI FIFO Interrupt Mask Register -------- */
#define FLEX_TWI_FIMR_TXFEF_Pos               _UINT32_(0)                                          /* (FLEX_TWI_FIMR) TXFEF Interrupt Mask Position */
#define FLEX_TWI_FIMR_TXFEF_Msk               (_UINT32_(0x1) << FLEX_TWI_FIMR_TXFEF_Pos)           /* (FLEX_TWI_FIMR) TXFEF Interrupt Mask Mask */
#define FLEX_TWI_FIMR_TXFEF(value)            (FLEX_TWI_FIMR_TXFEF_Msk & (_UINT32_(value) << FLEX_TWI_FIMR_TXFEF_Pos)) /* Assigment of value for TXFEF in the FLEX_TWI_FIMR register */
#define FLEX_TWI_FIMR_TXFFF_Pos               _UINT32_(1)                                          /* (FLEX_TWI_FIMR) TXFFF Interrupt Mask Position */
#define FLEX_TWI_FIMR_TXFFF_Msk               (_UINT32_(0x1) << FLEX_TWI_FIMR_TXFFF_Pos)           /* (FLEX_TWI_FIMR) TXFFF Interrupt Mask Mask */
#define FLEX_TWI_FIMR_TXFFF(value)            (FLEX_TWI_FIMR_TXFFF_Msk & (_UINT32_(value) << FLEX_TWI_FIMR_TXFFF_Pos)) /* Assigment of value for TXFFF in the FLEX_TWI_FIMR register */
#define FLEX_TWI_FIMR_TXFTHF_Pos              _UINT32_(2)                                          /* (FLEX_TWI_FIMR) TXFTHF Interrupt Mask Position */
#define FLEX_TWI_FIMR_TXFTHF_Msk              (_UINT32_(0x1) << FLEX_TWI_FIMR_TXFTHF_Pos)          /* (FLEX_TWI_FIMR) TXFTHF Interrupt Mask Mask */
#define FLEX_TWI_FIMR_TXFTHF(value)           (FLEX_TWI_FIMR_TXFTHF_Msk & (_UINT32_(value) << FLEX_TWI_FIMR_TXFTHF_Pos)) /* Assigment of value for TXFTHF in the FLEX_TWI_FIMR register */
#define FLEX_TWI_FIMR_RXFEF_Pos               _UINT32_(3)                                          /* (FLEX_TWI_FIMR) RXFEF Interrupt Mask Position */
#define FLEX_TWI_FIMR_RXFEF_Msk               (_UINT32_(0x1) << FLEX_TWI_FIMR_RXFEF_Pos)           /* (FLEX_TWI_FIMR) RXFEF Interrupt Mask Mask */
#define FLEX_TWI_FIMR_RXFEF(value)            (FLEX_TWI_FIMR_RXFEF_Msk & (_UINT32_(value) << FLEX_TWI_FIMR_RXFEF_Pos)) /* Assigment of value for RXFEF in the FLEX_TWI_FIMR register */
#define FLEX_TWI_FIMR_RXFFF_Pos               _UINT32_(4)                                          /* (FLEX_TWI_FIMR) RXFFF Interrupt Mask Position */
#define FLEX_TWI_FIMR_RXFFF_Msk               (_UINT32_(0x1) << FLEX_TWI_FIMR_RXFFF_Pos)           /* (FLEX_TWI_FIMR) RXFFF Interrupt Mask Mask */
#define FLEX_TWI_FIMR_RXFFF(value)            (FLEX_TWI_FIMR_RXFFF_Msk & (_UINT32_(value) << FLEX_TWI_FIMR_RXFFF_Pos)) /* Assigment of value for RXFFF in the FLEX_TWI_FIMR register */
#define FLEX_TWI_FIMR_RXFTHF_Pos              _UINT32_(5)                                          /* (FLEX_TWI_FIMR) RXFTHF Interrupt Mask Position */
#define FLEX_TWI_FIMR_RXFTHF_Msk              (_UINT32_(0x1) << FLEX_TWI_FIMR_RXFTHF_Pos)          /* (FLEX_TWI_FIMR) RXFTHF Interrupt Mask Mask */
#define FLEX_TWI_FIMR_RXFTHF(value)           (FLEX_TWI_FIMR_RXFTHF_Msk & (_UINT32_(value) << FLEX_TWI_FIMR_RXFTHF_Pos)) /* Assigment of value for RXFTHF in the FLEX_TWI_FIMR register */
#define FLEX_TWI_FIMR_TXFPTEF_Pos             _UINT32_(6)                                          /* (FLEX_TWI_FIMR) TXFPTEF Interrupt Mask Position */
#define FLEX_TWI_FIMR_TXFPTEF_Msk             (_UINT32_(0x1) << FLEX_TWI_FIMR_TXFPTEF_Pos)         /* (FLEX_TWI_FIMR) TXFPTEF Interrupt Mask Mask */
#define FLEX_TWI_FIMR_TXFPTEF(value)          (FLEX_TWI_FIMR_TXFPTEF_Msk & (_UINT32_(value) << FLEX_TWI_FIMR_TXFPTEF_Pos)) /* Assigment of value for TXFPTEF in the FLEX_TWI_FIMR register */
#define FLEX_TWI_FIMR_RXFPTEF_Pos             _UINT32_(7)                                          /* (FLEX_TWI_FIMR) RXFPTEF Interrupt Mask Position */
#define FLEX_TWI_FIMR_RXFPTEF_Msk             (_UINT32_(0x1) << FLEX_TWI_FIMR_RXFPTEF_Pos)         /* (FLEX_TWI_FIMR) RXFPTEF Interrupt Mask Mask */
#define FLEX_TWI_FIMR_RXFPTEF(value)          (FLEX_TWI_FIMR_RXFPTEF_Msk & (_UINT32_(value) << FLEX_TWI_FIMR_RXFPTEF_Pos)) /* Assigment of value for RXFPTEF in the FLEX_TWI_FIMR register */
#define FLEX_TWI_FIMR_Msk                     _UINT32_(0x000000FF)                                 /* (FLEX_TWI_FIMR) Register Mask  */


/* -------- FLEX_TWI_WPMR : (FLEXCOM Offset: 0x6E4) (R/W 32) TWI Write Protection Mode Register -------- */
#define FLEX_TWI_WPMR_WPEN_Pos                _UINT32_(0)                                          /* (FLEX_TWI_WPMR) Write Protection Enable Position */
#define FLEX_TWI_WPMR_WPEN_Msk                (_UINT32_(0x1) << FLEX_TWI_WPMR_WPEN_Pos)            /* (FLEX_TWI_WPMR) Write Protection Enable Mask */
#define FLEX_TWI_WPMR_WPEN(value)             (FLEX_TWI_WPMR_WPEN_Msk & (_UINT32_(value) << FLEX_TWI_WPMR_WPEN_Pos)) /* Assigment of value for WPEN in the FLEX_TWI_WPMR register */
#define FLEX_TWI_WPMR_WPITEN_Pos              _UINT32_(1)                                          /* (FLEX_TWI_WPMR) Write Protection Interrupt Enable Position */
#define FLEX_TWI_WPMR_WPITEN_Msk              (_UINT32_(0x1) << FLEX_TWI_WPMR_WPITEN_Pos)          /* (FLEX_TWI_WPMR) Write Protection Interrupt Enable Mask */
#define FLEX_TWI_WPMR_WPITEN(value)           (FLEX_TWI_WPMR_WPITEN_Msk & (_UINT32_(value) << FLEX_TWI_WPMR_WPITEN_Pos)) /* Assigment of value for WPITEN in the FLEX_TWI_WPMR register */
#define FLEX_TWI_WPMR_WPCREN_Pos              _UINT32_(2)                                          /* (FLEX_TWI_WPMR) Write Protection Control Enable Position */
#define FLEX_TWI_WPMR_WPCREN_Msk              (_UINT32_(0x1) << FLEX_TWI_WPMR_WPCREN_Pos)          /* (FLEX_TWI_WPMR) Write Protection Control Enable Mask */
#define FLEX_TWI_WPMR_WPCREN(value)           (FLEX_TWI_WPMR_WPCREN_Msk & (_UINT32_(value) << FLEX_TWI_WPMR_WPCREN_Pos)) /* Assigment of value for WPCREN in the FLEX_TWI_WPMR register */
#define FLEX_TWI_WPMR_WPKEY_Pos               _UINT32_(8)                                          /* (FLEX_TWI_WPMR) Write Protection Key Position */
#define FLEX_TWI_WPMR_WPKEY_Msk               (_UINT32_(0xFFFFFF) << FLEX_TWI_WPMR_WPKEY_Pos)      /* (FLEX_TWI_WPMR) Write Protection Key Mask */
#define FLEX_TWI_WPMR_WPKEY(value)            (FLEX_TWI_WPMR_WPKEY_Msk & (_UINT32_(value) << FLEX_TWI_WPMR_WPKEY_Pos)) /* Assigment of value for WPKEY in the FLEX_TWI_WPMR register */
#define   FLEX_TWI_WPMR_WPKEY_PASSWD_Val      _UINT32_(0x545749)                                   /* (FLEX_TWI_WPMR) Writing any other value in this field aborts the write operation of bits WPEN, WPITEN and WPCREN. Always reads as 0  */
#define FLEX_TWI_WPMR_WPKEY_PASSWD            (FLEX_TWI_WPMR_WPKEY_PASSWD_Val << FLEX_TWI_WPMR_WPKEY_Pos) /* (FLEX_TWI_WPMR) Writing any other value in this field aborts the write operation of bits WPEN, WPITEN and WPCREN. Always reads as 0 Position  */
#define FLEX_TWI_WPMR_Msk                     _UINT32_(0xFFFFFF07)                                 /* (FLEX_TWI_WPMR) Register Mask  */


/* -------- FLEX_TWI_WPSR : (FLEXCOM Offset: 0x6E8) ( R/ 32) TWI Write Protection Status Register -------- */
#define FLEX_TWI_WPSR_WPVS_Pos                _UINT32_(0)                                          /* (FLEX_TWI_WPSR) Write Protect Violation Status (cleared on read) Position */
#define FLEX_TWI_WPSR_WPVS_Msk                (_UINT32_(0x1) << FLEX_TWI_WPSR_WPVS_Pos)            /* (FLEX_TWI_WPSR) Write Protect Violation Status (cleared on read) Mask */
#define FLEX_TWI_WPSR_WPVS(value)             (FLEX_TWI_WPSR_WPVS_Msk & (_UINT32_(value) << FLEX_TWI_WPSR_WPVS_Pos)) /* Assigment of value for WPVS in the FLEX_TWI_WPSR register */
#define FLEX_TWI_WPSR_WPVSRC_Pos              _UINT32_(8)                                          /* (FLEX_TWI_WPSR) Write Protection Violation Source Position */
#define FLEX_TWI_WPSR_WPVSRC_Msk              (_UINT32_(0xFFFFFF) << FLEX_TWI_WPSR_WPVSRC_Pos)     /* (FLEX_TWI_WPSR) Write Protection Violation Source Mask */
#define FLEX_TWI_WPSR_WPVSRC(value)           (FLEX_TWI_WPSR_WPVSRC_Msk & (_UINT32_(value) << FLEX_TWI_WPSR_WPVSRC_Pos)) /* Assigment of value for WPVSRC in the FLEX_TWI_WPSR register */
#define FLEX_TWI_WPSR_Msk                     _UINT32_(0xFFFFFF01)                                 /* (FLEX_TWI_WPSR) Register Mask  */


/** \brief FLEXCOM register offsets definitions */
#define FLEX_MR_REG_OFST               _UINT32_(0x00)      /* (FLEX_MR) FLEXCOM Mode Register Offset */
#define FLEX_RHR_REG_OFST              _UINT32_(0x10)      /* (FLEX_RHR) FLEXCOM Receive Holding Register Offset */
#define FLEX_THR_REG_OFST              _UINT32_(0x20)      /* (FLEX_THR) FLEXCOM Transmit Holding Register Offset */
#define FLEX_RPR_REG_OFST              _UINT32_(0x100)     /* (FLEX_RPR) Receive Pointer Register Offset */
#define FLEX_RCR_REG_OFST              _UINT32_(0x104)     /* (FLEX_RCR) Receive Counter Register Offset */
#define FLEX_TPR_REG_OFST              _UINT32_(0x108)     /* (FLEX_TPR) Transmit Pointer Register Offset */
#define FLEX_TCR_REG_OFST              _UINT32_(0x10C)     /* (FLEX_TCR) Transmit Counter Register Offset */
#define FLEX_RNPR_REG_OFST             _UINT32_(0x110)     /* (FLEX_RNPR) Receive Next Pointer Register Offset */
#define FLEX_RNCR_REG_OFST             _UINT32_(0x114)     /* (FLEX_RNCR) Receive Next Counter Register Offset */
#define FLEX_TNPR_REG_OFST             _UINT32_(0x118)     /* (FLEX_TNPR) Transmit Next Pointer Register Offset */
#define FLEX_TNCR_REG_OFST             _UINT32_(0x11C)     /* (FLEX_TNCR) Transmit Next Counter Register Offset */
#define FLEX_PTCR_REG_OFST             _UINT32_(0x120)     /* (FLEX_PTCR) Transfer Control Register Offset */
#define FLEX_PTSR_REG_OFST             _UINT32_(0x124)     /* (FLEX_PTSR) Transfer Status Register Offset */
#define FLEX_PWPMR_REG_OFST            _UINT32_(0x128)     /* (FLEX_PWPMR) Write Protection Mode Register Offset */
#define FLEX_US_CR_REG_OFST            _UINT32_(0x200)     /* (FLEX_US_CR) USART Control Register Offset */
#define FLEX_US_MR_REG_OFST            _UINT32_(0x204)     /* (FLEX_US_MR) USART Mode Register Offset */
#define FLEX_US_IER_REG_OFST           _UINT32_(0x208)     /* (FLEX_US_IER) USART Interrupt Enable Register Offset */
#define FLEX_US_IDR_REG_OFST           _UINT32_(0x20C)     /* (FLEX_US_IDR) USART Interrupt Disable Register Offset */
#define FLEX_US_IMR_REG_OFST           _UINT32_(0x210)     /* (FLEX_US_IMR) USART Interrupt Mask Register Offset */
#define FLEX_US_CSR_REG_OFST           _UINT32_(0x214)     /* (FLEX_US_CSR) USART Channel Status Register Offset */
#define FLEX_US_RHR_REG_OFST           _UINT32_(0x218)     /* (FLEX_US_RHR) USART Receive Holding Register Offset */
#define FLEX_US_THR_REG_OFST           _UINT32_(0x21C)     /* (FLEX_US_THR) USART Transmit Holding Register Offset */
#define FLEX_US_BRGR_REG_OFST          _UINT32_(0x220)     /* (FLEX_US_BRGR) USART Baud Rate Generator Register Offset */
#define FLEX_US_RTOR_REG_OFST          _UINT32_(0x224)     /* (FLEX_US_RTOR) USART Receiver Timeout Register Offset */
#define FLEX_US_TTGR_REG_OFST          _UINT32_(0x228)     /* (FLEX_US_TTGR) USART Transmitter Timeguard Register Offset */
#define FLEX_US_FIDI_REG_OFST          _UINT32_(0x240)     /* (FLEX_US_FIDI) USART FI DI Ratio Register Offset */
#define FLEX_US_NER_REG_OFST           _UINT32_(0x244)     /* (FLEX_US_NER) USART Number of Errors Register Offset */
#define FLEX_US_IF_REG_OFST            _UINT32_(0x24C)     /* (FLEX_US_IF) USART IrDA Filter Register Offset */
#define FLEX_US_MAN_REG_OFST           _UINT32_(0x250)     /* (FLEX_US_MAN) USART Manchester Configuration Register Offset */
#define FLEX_US_LINMR_REG_OFST         _UINT32_(0x254)     /* (FLEX_US_LINMR) USART LIN Mode Register Offset */
#define FLEX_US_LINIR_REG_OFST         _UINT32_(0x258)     /* (FLEX_US_LINIR) USART LIN Identifier Register Offset */
#define FLEX_US_LINBRR_REG_OFST        _UINT32_(0x25C)     /* (FLEX_US_LINBRR) USART LIN Baud Rate Register Offset */
#define FLEX_US_CMPR_REG_OFST          _UINT32_(0x290)     /* (FLEX_US_CMPR) USART Comparison Register Offset */
#define FLEX_US_FMR_REG_OFST           _UINT32_(0x2A0)     /* (FLEX_US_FMR) USART FIFO Mode Register Offset */
#define FLEX_US_FLR_REG_OFST           _UINT32_(0x2A4)     /* (FLEX_US_FLR) USART FIFO Level Register Offset */
#define FLEX_US_FIER_REG_OFST          _UINT32_(0x2A8)     /* (FLEX_US_FIER) USART FIFO Interrupt Enable Register Offset */
#define FLEX_US_FIDR_REG_OFST          _UINT32_(0x2AC)     /* (FLEX_US_FIDR) USART FIFO Interrupt Disable Register Offset */
#define FLEX_US_FIMR_REG_OFST          _UINT32_(0x2B0)     /* (FLEX_US_FIMR) USART FIFO Interrupt Mask Register Offset */
#define FLEX_US_FESR_REG_OFST          _UINT32_(0x2B4)     /* (FLEX_US_FESR) USART FIFO Event Status Register Offset */
#define FLEX_US_WPMR_REG_OFST          _UINT32_(0x2E4)     /* (FLEX_US_WPMR) USART Write Protection Mode Register Offset */
#define FLEX_US_WPSR_REG_OFST          _UINT32_(0x2E8)     /* (FLEX_US_WPSR) USART Write Protection Status Register Offset */
#define FLEX_SPI_CR_REG_OFST           _UINT32_(0x400)     /* (FLEX_SPI_CR) SPI Control Register Offset */
#define FLEX_SPI_MR_REG_OFST           _UINT32_(0x404)     /* (FLEX_SPI_MR) SPI Mode Register Offset */
#define FLEX_SPI_RDR_REG_OFST          _UINT32_(0x408)     /* (FLEX_SPI_RDR) SPI Receive Data Register Offset */
#define FLEX_SPI_TDR_REG_OFST          _UINT32_(0x40C)     /* (FLEX_SPI_TDR) SPI Transmit Data Register Offset */
#define FLEX_SPI_SR_REG_OFST           _UINT32_(0x410)     /* (FLEX_SPI_SR) SPI Status Register Offset */
#define FLEX_SPI_IER_REG_OFST          _UINT32_(0x414)     /* (FLEX_SPI_IER) SPI Interrupt Enable Register Offset */
#define FLEX_SPI_IDR_REG_OFST          _UINT32_(0x418)     /* (FLEX_SPI_IDR) SPI Interrupt Disable Register Offset */
#define FLEX_SPI_IMR_REG_OFST          _UINT32_(0x41C)     /* (FLEX_SPI_IMR) SPI Interrupt Mask Register Offset */
#define FLEX_SPI_CSR_REG_OFST          _UINT32_(0x430)     /* (FLEX_SPI_CSR) SPI Chip Select Register Offset */
#define FLEX_SPI_CSR0_REG_OFST         _UINT32_(0x430)     /* (FLEX_SPI_CSR0) SPI Chip Select Register Offset */
#define FLEX_SPI_CSR1_REG_OFST         _UINT32_(0x434)     /* (FLEX_SPI_CSR1) SPI Chip Select Register Offset */
#define FLEX_SPI_FMR_REG_OFST          _UINT32_(0x440)     /* (FLEX_SPI_FMR) SPI FIFO Mode Register Offset */
#define FLEX_SPI_FLR_REG_OFST          _UINT32_(0x444)     /* (FLEX_SPI_FLR) SPI FIFO Level Register Offset */
#define FLEX_SPI_CMPR_REG_OFST         _UINT32_(0x448)     /* (FLEX_SPI_CMPR) SPI Comparison Register Offset */
#define FLEX_SPI_WPMR_REG_OFST         _UINT32_(0x4E4)     /* (FLEX_SPI_WPMR) SPI Write Protection Mode Register Offset */
#define FLEX_SPI_WPSR_REG_OFST         _UINT32_(0x4E8)     /* (FLEX_SPI_WPSR) SPI Write Protection Status Register Offset */
#define FLEX_TWI_CR_REG_OFST           _UINT32_(0x600)     /* (FLEX_TWI_CR) TWI Control Register Offset */
#define FLEX_TWI_MMR_REG_OFST          _UINT32_(0x604)     /* (FLEX_TWI_MMR) TWI Host Mode Register Offset */
#define FLEX_TWI_SMR_REG_OFST          _UINT32_(0x608)     /* (FLEX_TWI_SMR) TWI Client Mode Register Offset */
#define FLEX_TWI_IADR_REG_OFST         _UINT32_(0x60C)     /* (FLEX_TWI_IADR) TWI Internal Address Register Offset */
#define FLEX_TWI_CWGR_REG_OFST         _UINT32_(0x610)     /* (FLEX_TWI_CWGR) TWI Clock Waveform Generator Register Offset */
#define FLEX_TWI_SR_REG_OFST           _UINT32_(0x620)     /* (FLEX_TWI_SR) TWI Status Register Offset */
#define FLEX_TWI_IER_REG_OFST          _UINT32_(0x624)     /* (FLEX_TWI_IER) TWI Interrupt Enable Register Offset */
#define FLEX_TWI_IDR_REG_OFST          _UINT32_(0x628)     /* (FLEX_TWI_IDR) TWI Interrupt Disable Register Offset */
#define FLEX_TWI_IMR_REG_OFST          _UINT32_(0x62C)     /* (FLEX_TWI_IMR) TWI Interrupt Mask Register Offset */
#define FLEX_TWI_RHR_REG_OFST          _UINT32_(0x630)     /* (FLEX_TWI_RHR) TWI Receive Holding Register Offset */
#define FLEX_TWI_THR_REG_OFST          _UINT32_(0x634)     /* (FLEX_TWI_THR) TWI Transmit Holding Register Offset */
#define FLEX_TWI_SMBTR_REG_OFST        _UINT32_(0x638)     /* (FLEX_TWI_SMBTR) TWI SMBus Timing Register Offset */
#define FLEX_TWI_HSR_REG_OFST          _UINT32_(0x63C)     /* (FLEX_TWI_HSR) TWI High Speed Register Offset */
#define FLEX_TWI_ACR_REG_OFST          _UINT32_(0x640)     /* (FLEX_TWI_ACR) TWI Alternative Command Register Offset */
#define FLEX_TWI_FILTR_REG_OFST        _UINT32_(0x644)     /* (FLEX_TWI_FILTR) TWI Filter Register Offset */
#define FLEX_TWI_HSCWGR_REG_OFST       _UINT32_(0x648)     /* (FLEX_TWI_HSCWGR) TWI High Speed Clock Waveform Generator Register Offset */
#define FLEX_TWI_SWMR_REG_OFST         _UINT32_(0x64C)     /* (FLEX_TWI_SWMR) TWI Matching Register Offset */
#define FLEX_TWI_FMR_REG_OFST          _UINT32_(0x650)     /* (FLEX_TWI_FMR) TWI FIFO Mode Register Offset */
#define FLEX_TWI_FLR_REG_OFST          _UINT32_(0x654)     /* (FLEX_TWI_FLR) TWI FIFO Level Register Offset */
#define FLEX_TWI_FSR_REG_OFST          _UINT32_(0x660)     /* (FLEX_TWI_FSR) TWI FIFO Status Register Offset */
#define FLEX_TWI_FIER_REG_OFST         _UINT32_(0x664)     /* (FLEX_TWI_FIER) TWI FIFO Interrupt Enable Register Offset */
#define FLEX_TWI_FIDR_REG_OFST         _UINT32_(0x668)     /* (FLEX_TWI_FIDR) TWI FIFO Interrupt Disable Register Offset */
#define FLEX_TWI_FIMR_REG_OFST         _UINT32_(0x66C)     /* (FLEX_TWI_FIMR) TWI FIFO Interrupt Mask Register Offset */
#define FLEX_TWI_WPMR_REG_OFST         _UINT32_(0x6E4)     /* (FLEX_TWI_WPMR) TWI Write Protection Mode Register Offset */
#define FLEX_TWI_WPSR_REG_OFST         _UINT32_(0x6E8)     /* (FLEX_TWI_WPSR) TWI Write Protection Status Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief FLEXCOM register API structure */
typedef struct
{
  __IO  uint32_t                       FLEX_MR;            /**< Offset: 0x00 (R/W  32) FLEXCOM Mode Register */
  __I   uint8_t                        Reserved1[0x0C];
  __I   uint32_t                       FLEX_RHR;           /**< Offset: 0x10 (R/   32) FLEXCOM Receive Holding Register */
  __I   uint8_t                        Reserved2[0x0C];
  __IO  uint32_t                       FLEX_THR;           /**< Offset: 0x20 (R/W  32) FLEXCOM Transmit Holding Register */
  __I   uint8_t                        Reserved3[0xDC];
  __IO  uint32_t                       FLEX_RPR;           /**< Offset: 0x100 (R/W  32) Receive Pointer Register */
  __IO  uint32_t                       FLEX_RCR;           /**< Offset: 0x104 (R/W  32) Receive Counter Register */
  __IO  uint32_t                       FLEX_TPR;           /**< Offset: 0x108 (R/W  32) Transmit Pointer Register */
  __IO  uint32_t                       FLEX_TCR;           /**< Offset: 0x10C (R/W  32) Transmit Counter Register */
  __IO  uint32_t                       FLEX_RNPR;          /**< Offset: 0x110 (R/W  32) Receive Next Pointer Register */
  __IO  uint32_t                       FLEX_RNCR;          /**< Offset: 0x114 (R/W  32) Receive Next Counter Register */
  __IO  uint32_t                       FLEX_TNPR;          /**< Offset: 0x118 (R/W  32) Transmit Next Pointer Register */
  __IO  uint32_t                       FLEX_TNCR;          /**< Offset: 0x11C (R/W  32) Transmit Next Counter Register */
  __O   uint32_t                       FLEX_PTCR;          /**< Offset: 0x120 ( /W  32) Transfer Control Register */
  __I   uint32_t                       FLEX_PTSR;          /**< Offset: 0x124 (R/   32) Transfer Status Register */
  __IO  uint32_t                       FLEX_PWPMR;         /**< Offset: 0x128 (R/W  32) Write Protection Mode Register */
  __I   uint8_t                        Reserved4[0xD4];
  __O   uint32_t                       FLEX_US_CR;         /**< Offset: 0x200 ( /W  32) USART Control Register */
  __IO  uint32_t                       FLEX_US_MR;         /**< Offset: 0x204 (R/W  32) USART Mode Register */
  __O   uint32_t                       FLEX_US_IER;        /**< Offset: 0x208 ( /W  32) USART Interrupt Enable Register */
  __O   uint32_t                       FLEX_US_IDR;        /**< Offset: 0x20C ( /W  32) USART Interrupt Disable Register */
  __I   uint32_t                       FLEX_US_IMR;        /**< Offset: 0x210 (R/   32) USART Interrupt Mask Register */
  __I   uint32_t                       FLEX_US_CSR;        /**< Offset: 0x214 (R/   32) USART Channel Status Register */
  __I   uint32_t                       FLEX_US_RHR;        /**< Offset: 0x218 (R/   32) USART Receive Holding Register */
  __O   uint32_t                       FLEX_US_THR;        /**< Offset: 0x21C ( /W  32) USART Transmit Holding Register */
  __IO  uint32_t                       FLEX_US_BRGR;       /**< Offset: 0x220 (R/W  32) USART Baud Rate Generator Register */
  __IO  uint32_t                       FLEX_US_RTOR;       /**< Offset: 0x224 (R/W  32) USART Receiver Timeout Register */
  __IO  uint32_t                       FLEX_US_TTGR;       /**< Offset: 0x228 (R/W  32) USART Transmitter Timeguard Register */
  __I   uint8_t                        Reserved5[0x14];
  __IO  uint32_t                       FLEX_US_FIDI;       /**< Offset: 0x240 (R/W  32) USART FI DI Ratio Register */
  __I   uint32_t                       FLEX_US_NER;        /**< Offset: 0x244 (R/   32) USART Number of Errors Register */
  __I   uint8_t                        Reserved6[0x04];
  __IO  uint32_t                       FLEX_US_IF;         /**< Offset: 0x24C (R/W  32) USART IrDA Filter Register */
  __IO  uint32_t                       FLEX_US_MAN;        /**< Offset: 0x250 (R/W  32) USART Manchester Configuration Register */
  __IO  uint32_t                       FLEX_US_LINMR;      /**< Offset: 0x254 (R/W  32) USART LIN Mode Register */
  __IO  uint32_t                       FLEX_US_LINIR;      /**< Offset: 0x258 (R/W  32) USART LIN Identifier Register */
  __I   uint32_t                       FLEX_US_LINBRR;     /**< Offset: 0x25C (R/   32) USART LIN Baud Rate Register */
  __I   uint8_t                        Reserved7[0x30];
  __IO  uint32_t                       FLEX_US_CMPR;       /**< Offset: 0x290 (R/W  32) USART Comparison Register */
  __I   uint8_t                        Reserved8[0x0C];
  __IO  uint32_t                       FLEX_US_FMR;        /**< Offset: 0x2A0 (R/W  32) USART FIFO Mode Register */
  __I   uint32_t                       FLEX_US_FLR;        /**< Offset: 0x2A4 (R/   32) USART FIFO Level Register */
  __O   uint32_t                       FLEX_US_FIER;       /**< Offset: 0x2A8 ( /W  32) USART FIFO Interrupt Enable Register */
  __O   uint32_t                       FLEX_US_FIDR;       /**< Offset: 0x2AC ( /W  32) USART FIFO Interrupt Disable Register */
  __I   uint32_t                       FLEX_US_FIMR;       /**< Offset: 0x2B0 (R/   32) USART FIFO Interrupt Mask Register */
  __I   uint32_t                       FLEX_US_FESR;       /**< Offset: 0x2B4 (R/   32) USART FIFO Event Status Register */
  __I   uint8_t                        Reserved9[0x2C];
  __IO  uint32_t                       FLEX_US_WPMR;       /**< Offset: 0x2E4 (R/W  32) USART Write Protection Mode Register */
  __I   uint32_t                       FLEX_US_WPSR;       /**< Offset: 0x2E8 (R/   32) USART Write Protection Status Register */
  __I   uint8_t                        Reserved10[0x114];
  __O   uint32_t                       FLEX_SPI_CR;        /**< Offset: 0x400 ( /W  32) SPI Control Register */
  __IO  uint32_t                       FLEX_SPI_MR;        /**< Offset: 0x404 (R/W  32) SPI Mode Register */
  __I   uint32_t                       FLEX_SPI_RDR;       /**< Offset: 0x408 (R/   32) SPI Receive Data Register */
  __O   uint32_t                       FLEX_SPI_TDR;       /**< Offset: 0x40C ( /W  32) SPI Transmit Data Register */
  __I   uint32_t                       FLEX_SPI_SR;        /**< Offset: 0x410 (R/   32) SPI Status Register */
  __O   uint32_t                       FLEX_SPI_IER;       /**< Offset: 0x414 ( /W  32) SPI Interrupt Enable Register */
  __O   uint32_t                       FLEX_SPI_IDR;       /**< Offset: 0x418 ( /W  32) SPI Interrupt Disable Register */
  __I   uint32_t                       FLEX_SPI_IMR;       /**< Offset: 0x41C (R/   32) SPI Interrupt Mask Register */
  __I   uint8_t                        Reserved11[0x10];
  __IO  uint32_t                       FLEX_SPI_CSR[2];    /**< Offset: 0x430 (R/W  32) SPI Chip Select Register */
  __I   uint8_t                        Reserved12[0x08];
  __IO  uint32_t                       FLEX_SPI_FMR;       /**< Offset: 0x440 (R/W  32) SPI FIFO Mode Register */
  __I   uint32_t                       FLEX_SPI_FLR;       /**< Offset: 0x444 (R/   32) SPI FIFO Level Register */
  __IO  uint32_t                       FLEX_SPI_CMPR;      /**< Offset: 0x448 (R/W  32) SPI Comparison Register */
  __I   uint8_t                        Reserved13[0x98];
  __IO  uint32_t                       FLEX_SPI_WPMR;      /**< Offset: 0x4E4 (R/W  32) SPI Write Protection Mode Register */
  __I   uint32_t                       FLEX_SPI_WPSR;      /**< Offset: 0x4E8 (R/   32) SPI Write Protection Status Register */
  __I   uint8_t                        Reserved14[0x114];
  __O   uint32_t                       FLEX_TWI_CR;        /**< Offset: 0x600 ( /W  32) TWI Control Register */
  __IO  uint32_t                       FLEX_TWI_MMR;       /**< Offset: 0x604 (R/W  32) TWI Host Mode Register */
  __IO  uint32_t                       FLEX_TWI_SMR;       /**< Offset: 0x608 (R/W  32) TWI Client Mode Register */
  __IO  uint32_t                       FLEX_TWI_IADR;      /**< Offset: 0x60C (R/W  32) TWI Internal Address Register */
  __IO  uint32_t                       FLEX_TWI_CWGR;      /**< Offset: 0x610 (R/W  32) TWI Clock Waveform Generator Register */
  __I   uint8_t                        Reserved15[0x0C];
  __I   uint32_t                       FLEX_TWI_SR;        /**< Offset: 0x620 (R/   32) TWI Status Register */
  __O   uint32_t                       FLEX_TWI_IER;       /**< Offset: 0x624 ( /W  32) TWI Interrupt Enable Register */
  __O   uint32_t                       FLEX_TWI_IDR;       /**< Offset: 0x628 ( /W  32) TWI Interrupt Disable Register */
  __I   uint32_t                       FLEX_TWI_IMR;       /**< Offset: 0x62C (R/   32) TWI Interrupt Mask Register */
  __I   uint32_t                       FLEX_TWI_RHR;       /**< Offset: 0x630 (R/   32) TWI Receive Holding Register */
  __O   uint32_t                       FLEX_TWI_THR;       /**< Offset: 0x634 ( /W  32) TWI Transmit Holding Register */
  __IO  uint32_t                       FLEX_TWI_SMBTR;     /**< Offset: 0x638 (R/W  32) TWI SMBus Timing Register */
  __IO  uint32_t                       FLEX_TWI_HSR;       /**< Offset: 0x63C (R/W  32) TWI High Speed Register */
  __IO  uint32_t                       FLEX_TWI_ACR;       /**< Offset: 0x640 (R/W  32) TWI Alternative Command Register */
  __IO  uint32_t                       FLEX_TWI_FILTR;     /**< Offset: 0x644 (R/W  32) TWI Filter Register */
  __IO  uint32_t                       FLEX_TWI_HSCWGR;    /**< Offset: 0x648 (R/W  32) TWI High Speed Clock Waveform Generator Register */
  __IO  uint32_t                       FLEX_TWI_SWMR;      /**< Offset: 0x64C (R/W  32) TWI Matching Register */
  __IO  uint32_t                       FLEX_TWI_FMR;       /**< Offset: 0x650 (R/W  32) TWI FIFO Mode Register */
  __I   uint32_t                       FLEX_TWI_FLR;       /**< Offset: 0x654 (R/   32) TWI FIFO Level Register */
  __I   uint8_t                        Reserved16[0x08];
  __I   uint32_t                       FLEX_TWI_FSR;       /**< Offset: 0x660 (R/   32) TWI FIFO Status Register */
  __O   uint32_t                       FLEX_TWI_FIER;      /**< Offset: 0x664 ( /W  32) TWI FIFO Interrupt Enable Register */
  __O   uint32_t                       FLEX_TWI_FIDR;      /**< Offset: 0x668 ( /W  32) TWI FIFO Interrupt Disable Register */
  __I   uint32_t                       FLEX_TWI_FIMR;      /**< Offset: 0x66C (R/   32) TWI FIFO Interrupt Mask Register */
  __I   uint8_t                        Reserved17[0x74];
  __IO  uint32_t                       FLEX_TWI_WPMR;      /**< Offset: 0x6E4 (R/W  32) TWI Write Protection Mode Register */
  __I   uint32_t                       FLEX_TWI_WPSR;      /**< Offset: 0x6E8 (R/   32) TWI Write Protection Status Register */
} flexcom_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CXMTG_FLEXCOM_COMPONENT_H_ */
