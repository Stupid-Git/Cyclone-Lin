/*
 * Component description for AES
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
#ifndef _PIC32CXMTG_AES_COMPONENT_H_
#define _PIC32CXMTG_AES_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR AES                                          */
/* ************************************************************************** */

/* -------- AES_CR : (AES Offset: 0x00) ( /W 32) Control Register -------- */
#define AES_CR_START_Pos                      _UINT32_(0)                                          /* (AES_CR) Start Processing Position */
#define AES_CR_START_Msk                      (_UINT32_(0x1) << AES_CR_START_Pos)                  /* (AES_CR) Start Processing Mask */
#define AES_CR_START(value)                   (AES_CR_START_Msk & (_UINT32_(value) << AES_CR_START_Pos)) /* Assigment of value for START in the AES_CR register */
#define AES_CR_KSWP_Pos                       _UINT32_(1)                                          /* (AES_CR) Key Swap Position */
#define AES_CR_KSWP_Msk                       (_UINT32_(0x1) << AES_CR_KSWP_Pos)                   /* (AES_CR) Key Swap Mask */
#define AES_CR_KSWP(value)                    (AES_CR_KSWP_Msk & (_UINT32_(value) << AES_CR_KSWP_Pos)) /* Assigment of value for KSWP in the AES_CR register */
#define AES_CR_SWRST_Pos                      _UINT32_(8)                                          /* (AES_CR) Software Reset Position */
#define AES_CR_SWRST_Msk                      (_UINT32_(0x1) << AES_CR_SWRST_Pos)                  /* (AES_CR) Software Reset Mask */
#define AES_CR_SWRST(value)                   (AES_CR_SWRST_Msk & (_UINT32_(value) << AES_CR_SWRST_Pos)) /* Assigment of value for SWRST in the AES_CR register */
#define AES_CR_UNLOCK_Pos                     _UINT32_(24)                                         /* (AES_CR) Unlock Processing Position */
#define AES_CR_UNLOCK_Msk                     (_UINT32_(0x1) << AES_CR_UNLOCK_Pos)                 /* (AES_CR) Unlock Processing Mask */
#define AES_CR_UNLOCK(value)                  (AES_CR_UNLOCK_Msk & (_UINT32_(value) << AES_CR_UNLOCK_Pos)) /* Assigment of value for UNLOCK in the AES_CR register */
#define AES_CR_Msk                            _UINT32_(0x01000103)                                 /* (AES_CR) Register Mask  */


/* -------- AES_MR : (AES Offset: 0x04) (R/W 32) Mode Register -------- */
#define AES_MR_CIPHER_Pos                     _UINT32_(0)                                          /* (AES_MR) Processing Mode Position */
#define AES_MR_CIPHER_Msk                     (_UINT32_(0x1) << AES_MR_CIPHER_Pos)                 /* (AES_MR) Processing Mode Mask */
#define AES_MR_CIPHER(value)                  (AES_MR_CIPHER_Msk & (_UINT32_(value) << AES_MR_CIPHER_Pos)) /* Assigment of value for CIPHER in the AES_MR register */
#define AES_MR_GTAGEN_Pos                     _UINT32_(1)                                          /* (AES_MR) GCM Automatic Tag Generation Enable Position */
#define AES_MR_GTAGEN_Msk                     (_UINT32_(0x1) << AES_MR_GTAGEN_Pos)                 /* (AES_MR) GCM Automatic Tag Generation Enable Mask */
#define AES_MR_GTAGEN(value)                  (AES_MR_GTAGEN_Msk & (_UINT32_(value) << AES_MR_GTAGEN_Pos)) /* Assigment of value for GTAGEN in the AES_MR register */
#define AES_MR_DUALBUFF_Pos                   _UINT32_(3)                                          /* (AES_MR) Dual Input Buffer Position */
#define AES_MR_DUALBUFF_Msk                   (_UINT32_(0x1) << AES_MR_DUALBUFF_Pos)               /* (AES_MR) Dual Input Buffer Mask */
#define AES_MR_DUALBUFF(value)                (AES_MR_DUALBUFF_Msk & (_UINT32_(value) << AES_MR_DUALBUFF_Pos)) /* Assigment of value for DUALBUFF in the AES_MR register */
#define   AES_MR_DUALBUFF_INACTIVE_Val        _UINT32_(0x0)                                        /* (AES_MR) AES_IDATARx cannot be written during processing of previous block.  */
#define   AES_MR_DUALBUFF_ACTIVE_Val          _UINT32_(0x1)                                        /* (AES_MR) AES_IDATARx can be written during processing of previous block when SMOD = 2. It speeds up the overall runtime of large files.  */
#define AES_MR_DUALBUFF_INACTIVE              (AES_MR_DUALBUFF_INACTIVE_Val << AES_MR_DUALBUFF_Pos) /* (AES_MR) AES_IDATARx cannot be written during processing of previous block. Position  */
#define AES_MR_DUALBUFF_ACTIVE                (AES_MR_DUALBUFF_ACTIVE_Val << AES_MR_DUALBUFF_Pos)  /* (AES_MR) AES_IDATARx can be written during processing of previous block when SMOD = 2. It speeds up the overall runtime of large files. Position  */
#define AES_MR_PROCDLY_Pos                    _UINT32_(4)                                          /* (AES_MR) Processing Delay Position */
#define AES_MR_PROCDLY_Msk                    (_UINT32_(0xF) << AES_MR_PROCDLY_Pos)                /* (AES_MR) Processing Delay Mask */
#define AES_MR_PROCDLY(value)                 (AES_MR_PROCDLY_Msk & (_UINT32_(value) << AES_MR_PROCDLY_Pos)) /* Assigment of value for PROCDLY in the AES_MR register */
#define AES_MR_SMOD_Pos                       _UINT32_(8)                                          /* (AES_MR) Start Mode Position */
#define AES_MR_SMOD_Msk                       (_UINT32_(0x3) << AES_MR_SMOD_Pos)                   /* (AES_MR) Start Mode Mask */
#define AES_MR_SMOD(value)                    (AES_MR_SMOD_Msk & (_UINT32_(value) << AES_MR_SMOD_Pos)) /* Assigment of value for SMOD in the AES_MR register */
#define   AES_MR_SMOD_MANUAL_START_Val        _UINT32_(0x0)                                        /* (AES_MR) Manual Mode  */
#define   AES_MR_SMOD_AUTO_START_Val          _UINT32_(0x1)                                        /* (AES_MR) Auto Mode  */
#define   AES_MR_SMOD_IDATAR0_START_Val       _UINT32_(0x2)                                        /* (AES_MR) AES_IDATAR0 access only Auto Mode (PDC)  */
#define AES_MR_SMOD_MANUAL_START              (AES_MR_SMOD_MANUAL_START_Val << AES_MR_SMOD_Pos)    /* (AES_MR) Manual Mode Position  */
#define AES_MR_SMOD_AUTO_START                (AES_MR_SMOD_AUTO_START_Val << AES_MR_SMOD_Pos)      /* (AES_MR) Auto Mode Position  */
#define AES_MR_SMOD_IDATAR0_START             (AES_MR_SMOD_IDATAR0_START_Val << AES_MR_SMOD_Pos)   /* (AES_MR) AES_IDATAR0 access only Auto Mode (PDC) Position  */
#define AES_MR_KEYSIZE_Pos                    _UINT32_(10)                                         /* (AES_MR) Key Size Position */
#define AES_MR_KEYSIZE_Msk                    (_UINT32_(0x3) << AES_MR_KEYSIZE_Pos)                /* (AES_MR) Key Size Mask */
#define AES_MR_KEYSIZE(value)                 (AES_MR_KEYSIZE_Msk & (_UINT32_(value) << AES_MR_KEYSIZE_Pos)) /* Assigment of value for KEYSIZE in the AES_MR register */
#define   AES_MR_KEYSIZE_AES128_Val           _UINT32_(0x0)                                        /* (AES_MR) AES Key Size is 128 bits  */
#define   AES_MR_KEYSIZE_AES192_Val           _UINT32_(0x1)                                        /* (AES_MR) AES Key Size is 192 bits  */
#define   AES_MR_KEYSIZE_AES256_Val           _UINT32_(0x2)                                        /* (AES_MR) AES Key Size is 256 bits  */
#define AES_MR_KEYSIZE_AES128                 (AES_MR_KEYSIZE_AES128_Val << AES_MR_KEYSIZE_Pos)    /* (AES_MR) AES Key Size is 128 bits Position  */
#define AES_MR_KEYSIZE_AES192                 (AES_MR_KEYSIZE_AES192_Val << AES_MR_KEYSIZE_Pos)    /* (AES_MR) AES Key Size is 192 bits Position  */
#define AES_MR_KEYSIZE_AES256                 (AES_MR_KEYSIZE_AES256_Val << AES_MR_KEYSIZE_Pos)    /* (AES_MR) AES Key Size is 256 bits Position  */
#define AES_MR_OPMOD_Pos                      _UINT32_(12)                                         /* (AES_MR) Operating Mode Position */
#define AES_MR_OPMOD_Msk                      (_UINT32_(0x7) << AES_MR_OPMOD_Pos)                  /* (AES_MR) Operating Mode Mask */
#define AES_MR_OPMOD(value)                   (AES_MR_OPMOD_Msk & (_UINT32_(value) << AES_MR_OPMOD_Pos)) /* Assigment of value for OPMOD in the AES_MR register */
#define   AES_MR_OPMOD_ECB_Val                _UINT32_(0x0)                                        /* (AES_MR) ECB: Electronic Codebook mode  */
#define   AES_MR_OPMOD_CBC_Val                _UINT32_(0x1)                                        /* (AES_MR) CBC: Cipher Block Chaining mode  */
#define   AES_MR_OPMOD_OFB_Val                _UINT32_(0x2)                                        /* (AES_MR) OFB: Output Feedback mode  */
#define   AES_MR_OPMOD_CFB_Val                _UINT32_(0x3)                                        /* (AES_MR) CFB: Cipher Feedback mode  */
#define   AES_MR_OPMOD_CTR_Val                _UINT32_(0x4)                                        /* (AES_MR) CTR: Counter mode (16-bit internal counter)  */
#define   AES_MR_OPMOD_GCM_Val                _UINT32_(0x5)                                        /* (AES_MR) GCM: Galois/Counter mode  */
#define AES_MR_OPMOD_ECB                      (AES_MR_OPMOD_ECB_Val << AES_MR_OPMOD_Pos)           /* (AES_MR) ECB: Electronic Codebook mode Position  */
#define AES_MR_OPMOD_CBC                      (AES_MR_OPMOD_CBC_Val << AES_MR_OPMOD_Pos)           /* (AES_MR) CBC: Cipher Block Chaining mode Position  */
#define AES_MR_OPMOD_OFB                      (AES_MR_OPMOD_OFB_Val << AES_MR_OPMOD_Pos)           /* (AES_MR) OFB: Output Feedback mode Position  */
#define AES_MR_OPMOD_CFB                      (AES_MR_OPMOD_CFB_Val << AES_MR_OPMOD_Pos)           /* (AES_MR) CFB: Cipher Feedback mode Position  */
#define AES_MR_OPMOD_CTR                      (AES_MR_OPMOD_CTR_Val << AES_MR_OPMOD_Pos)           /* (AES_MR) CTR: Counter mode (16-bit internal counter) Position  */
#define AES_MR_OPMOD_GCM                      (AES_MR_OPMOD_GCM_Val << AES_MR_OPMOD_Pos)           /* (AES_MR) GCM: Galois/Counter mode Position  */
#define AES_MR_LOD_Pos                        _UINT32_(15)                                         /* (AES_MR) Last Output Data Mode Position */
#define AES_MR_LOD_Msk                        (_UINT32_(0x1) << AES_MR_LOD_Pos)                    /* (AES_MR) Last Output Data Mode Mask */
#define AES_MR_LOD(value)                     (AES_MR_LOD_Msk & (_UINT32_(value) << AES_MR_LOD_Pos)) /* Assigment of value for LOD in the AES_MR register */
#define AES_MR_CFBS_Pos                       _UINT32_(16)                                         /* (AES_MR) Cipher Feedback Data Size Position */
#define AES_MR_CFBS_Msk                       (_UINT32_(0x7) << AES_MR_CFBS_Pos)                   /* (AES_MR) Cipher Feedback Data Size Mask */
#define AES_MR_CFBS(value)                    (AES_MR_CFBS_Msk & (_UINT32_(value) << AES_MR_CFBS_Pos)) /* Assigment of value for CFBS in the AES_MR register */
#define   AES_MR_CFBS_SIZE_128BIT_Val         _UINT32_(0x0)                                        /* (AES_MR) 128-bit  */
#define   AES_MR_CFBS_SIZE_64BIT_Val          _UINT32_(0x1)                                        /* (AES_MR) 64-bit  */
#define   AES_MR_CFBS_SIZE_32BIT_Val          _UINT32_(0x2)                                        /* (AES_MR) 32-bit  */
#define   AES_MR_CFBS_SIZE_16BIT_Val          _UINT32_(0x3)                                        /* (AES_MR) 16-bit  */
#define   AES_MR_CFBS_SIZE_8BIT_Val           _UINT32_(0x4)                                        /* (AES_MR) 8-bit  */
#define AES_MR_CFBS_SIZE_128BIT               (AES_MR_CFBS_SIZE_128BIT_Val << AES_MR_CFBS_Pos)     /* (AES_MR) 128-bit Position  */
#define AES_MR_CFBS_SIZE_64BIT                (AES_MR_CFBS_SIZE_64BIT_Val << AES_MR_CFBS_Pos)      /* (AES_MR) 64-bit Position  */
#define AES_MR_CFBS_SIZE_32BIT                (AES_MR_CFBS_SIZE_32BIT_Val << AES_MR_CFBS_Pos)      /* (AES_MR) 32-bit Position  */
#define AES_MR_CFBS_SIZE_16BIT                (AES_MR_CFBS_SIZE_16BIT_Val << AES_MR_CFBS_Pos)      /* (AES_MR) 16-bit Position  */
#define AES_MR_CFBS_SIZE_8BIT                 (AES_MR_CFBS_SIZE_8BIT_Val << AES_MR_CFBS_Pos)       /* (AES_MR) 8-bit Position  */
#define AES_MR_CKEY_Pos                       _UINT32_(20)                                         /* (AES_MR) Key Position */
#define AES_MR_CKEY_Msk                       (_UINT32_(0xF) << AES_MR_CKEY_Pos)                   /* (AES_MR) Key Mask */
#define AES_MR_CKEY(value)                    (AES_MR_CKEY_Msk & (_UINT32_(value) << AES_MR_CKEY_Pos)) /* Assigment of value for CKEY in the AES_MR register */
#define   AES_MR_CKEY_PASSWD_Val              _UINT32_(0xE)                                        /* (AES_MR) This field must be written with 0xE the first time AES_MR is programmed. For subsequent programming of AES_MR, any value can be written, including that of 0xE. Always reads as 0.  */
#define AES_MR_CKEY_PASSWD                    (AES_MR_CKEY_PASSWD_Val << AES_MR_CKEY_Pos)          /* (AES_MR) This field must be written with 0xE the first time AES_MR is programmed. For subsequent programming of AES_MR, any value can be written, including that of 0xE. Always reads as 0. Position  */
#define AES_MR_TAMPCLR_Pos                    _UINT32_(31)                                         /* (AES_MR) Tamper Clear Enable Position */
#define AES_MR_TAMPCLR_Msk                    (_UINT32_(0x1) << AES_MR_TAMPCLR_Pos)                /* (AES_MR) Tamper Clear Enable Mask */
#define AES_MR_TAMPCLR(value)                 (AES_MR_TAMPCLR_Msk & (_UINT32_(value) << AES_MR_TAMPCLR_Pos)) /* Assigment of value for TAMPCLR in the AES_MR register */
#define AES_MR_Msk                            _UINT32_(0x80F7FFFB)                                 /* (AES_MR) Register Mask  */


/* -------- AES_IER : (AES Offset: 0x10) ( /W 32) Interrupt Enable Register -------- */
#define AES_IER_DATRDY_Pos                    _UINT32_(0)                                          /* (AES_IER) Data Ready Interrupt Enable Position */
#define AES_IER_DATRDY_Msk                    (_UINT32_(0x1) << AES_IER_DATRDY_Pos)                /* (AES_IER) Data Ready Interrupt Enable Mask */
#define AES_IER_DATRDY(value)                 (AES_IER_DATRDY_Msk & (_UINT32_(value) << AES_IER_DATRDY_Pos)) /* Assigment of value for DATRDY in the AES_IER register */
#define AES_IER_ENDRX_Pos                     _UINT32_(1)                                          /* (AES_IER) End of Receive Buffer Interrupt Enable Position */
#define AES_IER_ENDRX_Msk                     (_UINT32_(0x1) << AES_IER_ENDRX_Pos)                 /* (AES_IER) End of Receive Buffer Interrupt Enable Mask */
#define AES_IER_ENDRX(value)                  (AES_IER_ENDRX_Msk & (_UINT32_(value) << AES_IER_ENDRX_Pos)) /* Assigment of value for ENDRX in the AES_IER register */
#define AES_IER_ENDTX_Pos                     _UINT32_(2)                                          /* (AES_IER) End of Transmit Buffer Interrupt Enable Position */
#define AES_IER_ENDTX_Msk                     (_UINT32_(0x1) << AES_IER_ENDTX_Pos)                 /* (AES_IER) End of Transmit Buffer Interrupt Enable Mask */
#define AES_IER_ENDTX(value)                  (AES_IER_ENDTX_Msk & (_UINT32_(value) << AES_IER_ENDTX_Pos)) /* Assigment of value for ENDTX in the AES_IER register */
#define AES_IER_RXBUFF_Pos                    _UINT32_(3)                                          /* (AES_IER) Receive Buffer Full Interrupt Enable Position */
#define AES_IER_RXBUFF_Msk                    (_UINT32_(0x1) << AES_IER_RXBUFF_Pos)                /* (AES_IER) Receive Buffer Full Interrupt Enable Mask */
#define AES_IER_RXBUFF(value)                 (AES_IER_RXBUFF_Msk & (_UINT32_(value) << AES_IER_RXBUFF_Pos)) /* Assigment of value for RXBUFF in the AES_IER register */
#define AES_IER_TXBUFE_Pos                    _UINT32_(4)                                          /* (AES_IER) Transmit Buffer Empty Interrupt Enable Position */
#define AES_IER_TXBUFE_Msk                    (_UINT32_(0x1) << AES_IER_TXBUFE_Pos)                /* (AES_IER) Transmit Buffer Empty Interrupt Enable Mask */
#define AES_IER_TXBUFE(value)                 (AES_IER_TXBUFE_Msk & (_UINT32_(value) << AES_IER_TXBUFE_Pos)) /* Assigment of value for TXBUFE in the AES_IER register */
#define AES_IER_URAD_Pos                      _UINT32_(8)                                          /* (AES_IER) Unspecified Register Access Detection Interrupt Enable Position */
#define AES_IER_URAD_Msk                      (_UINT32_(0x1) << AES_IER_URAD_Pos)                  /* (AES_IER) Unspecified Register Access Detection Interrupt Enable Mask */
#define AES_IER_URAD(value)                   (AES_IER_URAD_Msk & (_UINT32_(value) << AES_IER_URAD_Pos)) /* Assigment of value for URAD in the AES_IER register */
#define AES_IER_TAGRDY_Pos                    _UINT32_(16)                                         /* (AES_IER) GCM Tag Ready Interrupt Enable Position */
#define AES_IER_TAGRDY_Msk                    (_UINT32_(0x1) << AES_IER_TAGRDY_Pos)                /* (AES_IER) GCM Tag Ready Interrupt Enable Mask */
#define AES_IER_TAGRDY(value)                 (AES_IER_TAGRDY_Msk & (_UINT32_(value) << AES_IER_TAGRDY_Pos)) /* Assigment of value for TAGRDY in the AES_IER register */
#define AES_IER_EOPAD_Pos                     _UINT32_(17)                                         /* (AES_IER) End of Padding Interrupt Enable Position */
#define AES_IER_EOPAD_Msk                     (_UINT32_(0x1) << AES_IER_EOPAD_Pos)                 /* (AES_IER) End of Padding Interrupt Enable Mask */
#define AES_IER_EOPAD(value)                  (AES_IER_EOPAD_Msk & (_UINT32_(value) << AES_IER_EOPAD_Pos)) /* Assigment of value for EOPAD in the AES_IER register */
#define AES_IER_PLENERR_Pos                   _UINT32_(18)                                         /* (AES_IER) Padding Length Error Interrupt Enable Position */
#define AES_IER_PLENERR_Msk                   (_UINT32_(0x1) << AES_IER_PLENERR_Pos)               /* (AES_IER) Padding Length Error Interrupt Enable Mask */
#define AES_IER_PLENERR(value)                (AES_IER_PLENERR_Msk & (_UINT32_(value) << AES_IER_PLENERR_Pos)) /* Assigment of value for PLENERR in the AES_IER register */
#define AES_IER_SECE_Pos                      _UINT32_(19)                                         /* (AES_IER) Security and/or Safety Event Interrupt Enable Position */
#define AES_IER_SECE_Msk                      (_UINT32_(0x1) << AES_IER_SECE_Pos)                  /* (AES_IER) Security and/or Safety Event Interrupt Enable Mask */
#define AES_IER_SECE(value)                   (AES_IER_SECE_Msk & (_UINT32_(value) << AES_IER_SECE_Pos)) /* Assigment of value for SECE in the AES_IER register */
#define AES_IER_Msk                           _UINT32_(0x000F011F)                                 /* (AES_IER) Register Mask  */


/* -------- AES_IDR : (AES Offset: 0x14) ( /W 32) Interrupt Disable Register -------- */
#define AES_IDR_DATRDY_Pos                    _UINT32_(0)                                          /* (AES_IDR) Data Ready Interrupt Disable Position */
#define AES_IDR_DATRDY_Msk                    (_UINT32_(0x1) << AES_IDR_DATRDY_Pos)                /* (AES_IDR) Data Ready Interrupt Disable Mask */
#define AES_IDR_DATRDY(value)                 (AES_IDR_DATRDY_Msk & (_UINT32_(value) << AES_IDR_DATRDY_Pos)) /* Assigment of value for DATRDY in the AES_IDR register */
#define AES_IDR_ENDRX_Pos                     _UINT32_(1)                                          /* (AES_IDR) End of Receive Buffer Interrupt Disable Position */
#define AES_IDR_ENDRX_Msk                     (_UINT32_(0x1) << AES_IDR_ENDRX_Pos)                 /* (AES_IDR) End of Receive Buffer Interrupt Disable Mask */
#define AES_IDR_ENDRX(value)                  (AES_IDR_ENDRX_Msk & (_UINT32_(value) << AES_IDR_ENDRX_Pos)) /* Assigment of value for ENDRX in the AES_IDR register */
#define AES_IDR_ENDTX_Pos                     _UINT32_(2)                                          /* (AES_IDR) End of Transmit Buffer Interrupt Disable Position */
#define AES_IDR_ENDTX_Msk                     (_UINT32_(0x1) << AES_IDR_ENDTX_Pos)                 /* (AES_IDR) End of Transmit Buffer Interrupt Disable Mask */
#define AES_IDR_ENDTX(value)                  (AES_IDR_ENDTX_Msk & (_UINT32_(value) << AES_IDR_ENDTX_Pos)) /* Assigment of value for ENDTX in the AES_IDR register */
#define AES_IDR_RXBUFF_Pos                    _UINT32_(3)                                          /* (AES_IDR) Receive Buffer Full Interrupt Disable Position */
#define AES_IDR_RXBUFF_Msk                    (_UINT32_(0x1) << AES_IDR_RXBUFF_Pos)                /* (AES_IDR) Receive Buffer Full Interrupt Disable Mask */
#define AES_IDR_RXBUFF(value)                 (AES_IDR_RXBUFF_Msk & (_UINT32_(value) << AES_IDR_RXBUFF_Pos)) /* Assigment of value for RXBUFF in the AES_IDR register */
#define AES_IDR_TXBUFE_Pos                    _UINT32_(4)                                          /* (AES_IDR) Transmit Buffer Empty Interrupt Disable Position */
#define AES_IDR_TXBUFE_Msk                    (_UINT32_(0x1) << AES_IDR_TXBUFE_Pos)                /* (AES_IDR) Transmit Buffer Empty Interrupt Disable Mask */
#define AES_IDR_TXBUFE(value)                 (AES_IDR_TXBUFE_Msk & (_UINT32_(value) << AES_IDR_TXBUFE_Pos)) /* Assigment of value for TXBUFE in the AES_IDR register */
#define AES_IDR_URAD_Pos                      _UINT32_(8)                                          /* (AES_IDR) Unspecified Register Access Detection Interrupt Disable Position */
#define AES_IDR_URAD_Msk                      (_UINT32_(0x1) << AES_IDR_URAD_Pos)                  /* (AES_IDR) Unspecified Register Access Detection Interrupt Disable Mask */
#define AES_IDR_URAD(value)                   (AES_IDR_URAD_Msk & (_UINT32_(value) << AES_IDR_URAD_Pos)) /* Assigment of value for URAD in the AES_IDR register */
#define AES_IDR_TAGRDY_Pos                    _UINT32_(16)                                         /* (AES_IDR) GCM Tag Ready Interrupt Disable Position */
#define AES_IDR_TAGRDY_Msk                    (_UINT32_(0x1) << AES_IDR_TAGRDY_Pos)                /* (AES_IDR) GCM Tag Ready Interrupt Disable Mask */
#define AES_IDR_TAGRDY(value)                 (AES_IDR_TAGRDY_Msk & (_UINT32_(value) << AES_IDR_TAGRDY_Pos)) /* Assigment of value for TAGRDY in the AES_IDR register */
#define AES_IDR_EOPAD_Pos                     _UINT32_(17)                                         /* (AES_IDR) End of Padding Interrupt Disable Position */
#define AES_IDR_EOPAD_Msk                     (_UINT32_(0x1) << AES_IDR_EOPAD_Pos)                 /* (AES_IDR) End of Padding Interrupt Disable Mask */
#define AES_IDR_EOPAD(value)                  (AES_IDR_EOPAD_Msk & (_UINT32_(value) << AES_IDR_EOPAD_Pos)) /* Assigment of value for EOPAD in the AES_IDR register */
#define AES_IDR_PLENERR_Pos                   _UINT32_(18)                                         /* (AES_IDR) Padding Length Error Interrupt Disable Position */
#define AES_IDR_PLENERR_Msk                   (_UINT32_(0x1) << AES_IDR_PLENERR_Pos)               /* (AES_IDR) Padding Length Error Interrupt Disable Mask */
#define AES_IDR_PLENERR(value)                (AES_IDR_PLENERR_Msk & (_UINT32_(value) << AES_IDR_PLENERR_Pos)) /* Assigment of value for PLENERR in the AES_IDR register */
#define AES_IDR_SECE_Pos                      _UINT32_(19)                                         /* (AES_IDR) Security and/or Safety Event Interrupt Disable Position */
#define AES_IDR_SECE_Msk                      (_UINT32_(0x1) << AES_IDR_SECE_Pos)                  /* (AES_IDR) Security and/or Safety Event Interrupt Disable Mask */
#define AES_IDR_SECE(value)                   (AES_IDR_SECE_Msk & (_UINT32_(value) << AES_IDR_SECE_Pos)) /* Assigment of value for SECE in the AES_IDR register */
#define AES_IDR_Msk                           _UINT32_(0x000F011F)                                 /* (AES_IDR) Register Mask  */


/* -------- AES_IMR : (AES Offset: 0x18) ( R/ 32) Interrupt Mask Register -------- */
#define AES_IMR_DATRDY_Pos                    _UINT32_(0)                                          /* (AES_IMR) Data Ready Interrupt Mask Position */
#define AES_IMR_DATRDY_Msk                    (_UINT32_(0x1) << AES_IMR_DATRDY_Pos)                /* (AES_IMR) Data Ready Interrupt Mask Mask */
#define AES_IMR_DATRDY(value)                 (AES_IMR_DATRDY_Msk & (_UINT32_(value) << AES_IMR_DATRDY_Pos)) /* Assigment of value for DATRDY in the AES_IMR register */
#define AES_IMR_ENDRX_Pos                     _UINT32_(1)                                          /* (AES_IMR) End of Receive Buffer Interrupt Mask Position */
#define AES_IMR_ENDRX_Msk                     (_UINT32_(0x1) << AES_IMR_ENDRX_Pos)                 /* (AES_IMR) End of Receive Buffer Interrupt Mask Mask */
#define AES_IMR_ENDRX(value)                  (AES_IMR_ENDRX_Msk & (_UINT32_(value) << AES_IMR_ENDRX_Pos)) /* Assigment of value for ENDRX in the AES_IMR register */
#define AES_IMR_ENDTX_Pos                     _UINT32_(2)                                          /* (AES_IMR) End of Transmit Buffer Interrupt Mask Position */
#define AES_IMR_ENDTX_Msk                     (_UINT32_(0x1) << AES_IMR_ENDTX_Pos)                 /* (AES_IMR) End of Transmit Buffer Interrupt Mask Mask */
#define AES_IMR_ENDTX(value)                  (AES_IMR_ENDTX_Msk & (_UINT32_(value) << AES_IMR_ENDTX_Pos)) /* Assigment of value for ENDTX in the AES_IMR register */
#define AES_IMR_RXBUFF_Pos                    _UINT32_(3)                                          /* (AES_IMR) Receive Buffer Full Interrupt Mask Position */
#define AES_IMR_RXBUFF_Msk                    (_UINT32_(0x1) << AES_IMR_RXBUFF_Pos)                /* (AES_IMR) Receive Buffer Full Interrupt Mask Mask */
#define AES_IMR_RXBUFF(value)                 (AES_IMR_RXBUFF_Msk & (_UINT32_(value) << AES_IMR_RXBUFF_Pos)) /* Assigment of value for RXBUFF in the AES_IMR register */
#define AES_IMR_TXBUFE_Pos                    _UINT32_(4)                                          /* (AES_IMR) Transmit Buffer Empty Interrupt Mask Position */
#define AES_IMR_TXBUFE_Msk                    (_UINT32_(0x1) << AES_IMR_TXBUFE_Pos)                /* (AES_IMR) Transmit Buffer Empty Interrupt Mask Mask */
#define AES_IMR_TXBUFE(value)                 (AES_IMR_TXBUFE_Msk & (_UINT32_(value) << AES_IMR_TXBUFE_Pos)) /* Assigment of value for TXBUFE in the AES_IMR register */
#define AES_IMR_URAD_Pos                      _UINT32_(8)                                          /* (AES_IMR) Unspecified Register Access Detection Interrupt Mask Position */
#define AES_IMR_URAD_Msk                      (_UINT32_(0x1) << AES_IMR_URAD_Pos)                  /* (AES_IMR) Unspecified Register Access Detection Interrupt Mask Mask */
#define AES_IMR_URAD(value)                   (AES_IMR_URAD_Msk & (_UINT32_(value) << AES_IMR_URAD_Pos)) /* Assigment of value for URAD in the AES_IMR register */
#define AES_IMR_TAGRDY_Pos                    _UINT32_(16)                                         /* (AES_IMR) GCM Tag Ready Interrupt Mask Position */
#define AES_IMR_TAGRDY_Msk                    (_UINT32_(0x1) << AES_IMR_TAGRDY_Pos)                /* (AES_IMR) GCM Tag Ready Interrupt Mask Mask */
#define AES_IMR_TAGRDY(value)                 (AES_IMR_TAGRDY_Msk & (_UINT32_(value) << AES_IMR_TAGRDY_Pos)) /* Assigment of value for TAGRDY in the AES_IMR register */
#define AES_IMR_EOPAD_Pos                     _UINT32_(17)                                         /* (AES_IMR) End of Padding Interrupt Mask Position */
#define AES_IMR_EOPAD_Msk                     (_UINT32_(0x1) << AES_IMR_EOPAD_Pos)                 /* (AES_IMR) End of Padding Interrupt Mask Mask */
#define AES_IMR_EOPAD(value)                  (AES_IMR_EOPAD_Msk & (_UINT32_(value) << AES_IMR_EOPAD_Pos)) /* Assigment of value for EOPAD in the AES_IMR register */
#define AES_IMR_PLENERR_Pos                   _UINT32_(18)                                         /* (AES_IMR) Padding Length Error Interrupt Mask Position */
#define AES_IMR_PLENERR_Msk                   (_UINT32_(0x1) << AES_IMR_PLENERR_Pos)               /* (AES_IMR) Padding Length Error Interrupt Mask Mask */
#define AES_IMR_PLENERR(value)                (AES_IMR_PLENERR_Msk & (_UINT32_(value) << AES_IMR_PLENERR_Pos)) /* Assigment of value for PLENERR in the AES_IMR register */
#define AES_IMR_SECE_Pos                      _UINT32_(19)                                         /* (AES_IMR) Security and/or Safety Event Interrupt Mask Position */
#define AES_IMR_SECE_Msk                      (_UINT32_(0x1) << AES_IMR_SECE_Pos)                  /* (AES_IMR) Security and/or Safety Event Interrupt Mask Mask */
#define AES_IMR_SECE(value)                   (AES_IMR_SECE_Msk & (_UINT32_(value) << AES_IMR_SECE_Pos)) /* Assigment of value for SECE in the AES_IMR register */
#define AES_IMR_Msk                           _UINT32_(0x000F011F)                                 /* (AES_IMR) Register Mask  */


/* -------- AES_ISR : (AES Offset: 0x1C) ( R/ 32) Interrupt Status Register -------- */
#define AES_ISR_DATRDY_Pos                    _UINT32_(0)                                          /* (AES_ISR) Data Ready (cleared by setting bit START or bit SWRST in AES_CR or by reading AES_ODATARx) Position */
#define AES_ISR_DATRDY_Msk                    (_UINT32_(0x1) << AES_ISR_DATRDY_Pos)                /* (AES_ISR) Data Ready (cleared by setting bit START or bit SWRST in AES_CR or by reading AES_ODATARx) Mask */
#define AES_ISR_DATRDY(value)                 (AES_ISR_DATRDY_Msk & (_UINT32_(value) << AES_ISR_DATRDY_Pos)) /* Assigment of value for DATRDY in the AES_ISR register */
#define AES_ISR_ENDRX_Pos                     _UINT32_(1)                                          /* (AES_ISR) End of RX Buffer (cleared by writing AES_RCR or AES_RNCR) Position */
#define AES_ISR_ENDRX_Msk                     (_UINT32_(0x1) << AES_ISR_ENDRX_Pos)                 /* (AES_ISR) End of RX Buffer (cleared by writing AES_RCR or AES_RNCR) Mask */
#define AES_ISR_ENDRX(value)                  (AES_ISR_ENDRX_Msk & (_UINT32_(value) << AES_ISR_ENDRX_Pos)) /* Assigment of value for ENDRX in the AES_ISR register */
#define AES_ISR_ENDTX_Pos                     _UINT32_(2)                                          /* (AES_ISR) End of TX Buffer (cleared by writing AES_TCR or AES_TNCR) Position */
#define AES_ISR_ENDTX_Msk                     (_UINT32_(0x1) << AES_ISR_ENDTX_Pos)                 /* (AES_ISR) End of TX Buffer (cleared by writing AES_TCR or AES_TNCR) Mask */
#define AES_ISR_ENDTX(value)                  (AES_ISR_ENDTX_Msk & (_UINT32_(value) << AES_ISR_ENDTX_Pos)) /* Assigment of value for ENDTX in the AES_ISR register */
#define AES_ISR_RXBUFF_Pos                    _UINT32_(3)                                          /* (AES_ISR) RX Buffer Full (cleared by writing AES_RCR or AES_RNCR) Position */
#define AES_ISR_RXBUFF_Msk                    (_UINT32_(0x1) << AES_ISR_RXBUFF_Pos)                /* (AES_ISR) RX Buffer Full (cleared by writing AES_RCR or AES_RNCR) Mask */
#define AES_ISR_RXBUFF(value)                 (AES_ISR_RXBUFF_Msk & (_UINT32_(value) << AES_ISR_RXBUFF_Pos)) /* Assigment of value for RXBUFF in the AES_ISR register */
#define AES_ISR_TXBUFE_Pos                    _UINT32_(4)                                          /* (AES_ISR) TX Buffer Empty (cleared by writing AES_TCR or AES_TNCR) Position */
#define AES_ISR_TXBUFE_Msk                    (_UINT32_(0x1) << AES_ISR_TXBUFE_Pos)                /* (AES_ISR) TX Buffer Empty (cleared by writing AES_TCR or AES_TNCR) Mask */
#define AES_ISR_TXBUFE(value)                 (AES_ISR_TXBUFE_Msk & (_UINT32_(value) << AES_ISR_TXBUFE_Pos)) /* Assigment of value for TXBUFE in the AES_ISR register */
#define AES_ISR_URAD_Pos                      _UINT32_(8)                                          /* (AES_ISR) Unspecified Register Access Detection Status (cleared by writing SWRST in AES_CR) Position */
#define AES_ISR_URAD_Msk                      (_UINT32_(0x1) << AES_ISR_URAD_Pos)                  /* (AES_ISR) Unspecified Register Access Detection Status (cleared by writing SWRST in AES_CR) Mask */
#define AES_ISR_URAD(value)                   (AES_ISR_URAD_Msk & (_UINT32_(value) << AES_ISR_URAD_Pos)) /* Assigment of value for URAD in the AES_ISR register */
#define AES_ISR_URAT_Pos                      _UINT32_(12)                                         /* (AES_ISR) Unspecified Register Access (cleared by writing SWRST in AES_CR) Position */
#define AES_ISR_URAT_Msk                      (_UINT32_(0xF) << AES_ISR_URAT_Pos)                  /* (AES_ISR) Unspecified Register Access (cleared by writing SWRST in AES_CR) Mask */
#define AES_ISR_URAT(value)                   (AES_ISR_URAT_Msk & (_UINT32_(value) << AES_ISR_URAT_Pos)) /* Assigment of value for URAT in the AES_ISR register */
#define   AES_ISR_URAT_IDR_WR_PROCESSING_Val  _UINT32_(0x0)                                        /* (AES_ISR) Input Data register written during the data processing when SMOD = 2 mode.  */
#define   AES_ISR_URAT_ODR_RD_PROCESSING_Val  _UINT32_(0x1)                                        /* (AES_ISR) Output Data register read during the data processing.  */
#define   AES_ISR_URAT_MR_WR_PROCESSING_Val   _UINT32_(0x2)                                        /* (AES_ISR) Mode register written during the data processing.  */
#define   AES_ISR_URAT_ODR_RD_SUBKGEN_Val     _UINT32_(0x3)                                        /* (AES_ISR) Output Data register read during the sub-keys generation.  */
#define   AES_ISR_URAT_MR_WR_SUBKGEN_Val      _UINT32_(0x4)                                        /* (AES_ISR) Mode register written during the sub-keys generation.  */
#define   AES_ISR_URAT_WOR_RD_ACCESS_Val      _UINT32_(0x5)                                        /* (AES_ISR) Write-only register read access.  */
#define AES_ISR_URAT_IDR_WR_PROCESSING        (AES_ISR_URAT_IDR_WR_PROCESSING_Val << AES_ISR_URAT_Pos) /* (AES_ISR) Input Data register written during the data processing when SMOD = 2 mode. Position  */
#define AES_ISR_URAT_ODR_RD_PROCESSING        (AES_ISR_URAT_ODR_RD_PROCESSING_Val << AES_ISR_URAT_Pos) /* (AES_ISR) Output Data register read during the data processing. Position  */
#define AES_ISR_URAT_MR_WR_PROCESSING         (AES_ISR_URAT_MR_WR_PROCESSING_Val << AES_ISR_URAT_Pos) /* (AES_ISR) Mode register written during the data processing. Position  */
#define AES_ISR_URAT_ODR_RD_SUBKGEN           (AES_ISR_URAT_ODR_RD_SUBKGEN_Val << AES_ISR_URAT_Pos) /* (AES_ISR) Output Data register read during the sub-keys generation. Position  */
#define AES_ISR_URAT_MR_WR_SUBKGEN            (AES_ISR_URAT_MR_WR_SUBKGEN_Val << AES_ISR_URAT_Pos) /* (AES_ISR) Mode register written during the sub-keys generation. Position  */
#define AES_ISR_URAT_WOR_RD_ACCESS            (AES_ISR_URAT_WOR_RD_ACCESS_Val << AES_ISR_URAT_Pos) /* (AES_ISR) Write-only register read access. Position  */
#define AES_ISR_TAGRDY_Pos                    _UINT32_(16)                                         /* (AES_ISR) GCM Tag Ready Position */
#define AES_ISR_TAGRDY_Msk                    (_UINT32_(0x1) << AES_ISR_TAGRDY_Pos)                /* (AES_ISR) GCM Tag Ready Mask */
#define AES_ISR_TAGRDY(value)                 (AES_ISR_TAGRDY_Msk & (_UINT32_(value) << AES_ISR_TAGRDY_Pos)) /* Assigment of value for TAGRDY in the AES_ISR register */
#define AES_ISR_EOPAD_Pos                     _UINT32_(17)                                         /* (AES_ISR) End of Padding Position */
#define AES_ISR_EOPAD_Msk                     (_UINT32_(0x1) << AES_ISR_EOPAD_Pos)                 /* (AES_ISR) End of Padding Mask */
#define AES_ISR_EOPAD(value)                  (AES_ISR_EOPAD_Msk & (_UINT32_(value) << AES_ISR_EOPAD_Pos)) /* Assigment of value for EOPAD in the AES_ISR register */
#define AES_ISR_PLENERR_Pos                   _UINT32_(18)                                         /* (AES_ISR) Padding Length Error Position */
#define AES_ISR_PLENERR_Msk                   (_UINT32_(0x1) << AES_ISR_PLENERR_Pos)               /* (AES_ISR) Padding Length Error Mask */
#define AES_ISR_PLENERR(value)                (AES_ISR_PLENERR_Msk & (_UINT32_(value) << AES_ISR_PLENERR_Pos)) /* Assigment of value for PLENERR in the AES_ISR register */
#define AES_ISR_SECE_Pos                      _UINT32_(19)                                         /* (AES_ISR) Security and/or Safety Event (cleared on read) Position */
#define AES_ISR_SECE_Msk                      (_UINT32_(0x1) << AES_ISR_SECE_Pos)                  /* (AES_ISR) Security and/or Safety Event (cleared on read) Mask */
#define AES_ISR_SECE(value)                   (AES_ISR_SECE_Msk & (_UINT32_(value) << AES_ISR_SECE_Pos)) /* Assigment of value for SECE in the AES_ISR register */
#define AES_ISR_Msk                           _UINT32_(0x000FF11F)                                 /* (AES_ISR) Register Mask  */


/* -------- AES_KEYWR : (AES Offset: 0x20) ( /W 32) Key Word Register -------- */
#define AES_KEYWR_KEYW_Pos                    _UINT32_(0)                                          /* (AES_KEYWR) Key Word Position */
#define AES_KEYWR_KEYW_Msk                    (_UINT32_(0xFFFFFFFF) << AES_KEYWR_KEYW_Pos)         /* (AES_KEYWR) Key Word Mask */
#define AES_KEYWR_KEYW(value)                 (AES_KEYWR_KEYW_Msk & (_UINT32_(value) << AES_KEYWR_KEYW_Pos)) /* Assigment of value for KEYW in the AES_KEYWR register */
#define AES_KEYWR_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (AES_KEYWR) Register Mask  */


/* -------- AES_IDATAR : (AES Offset: 0x40) ( /W 32) Input Data Register -------- */
#define AES_IDATAR_IDATA_Pos                  _UINT32_(0)                                          /* (AES_IDATAR) Input Data Word Position */
#define AES_IDATAR_IDATA_Msk                  (_UINT32_(0xFFFFFFFF) << AES_IDATAR_IDATA_Pos)       /* (AES_IDATAR) Input Data Word Mask */
#define AES_IDATAR_IDATA(value)               (AES_IDATAR_IDATA_Msk & (_UINT32_(value) << AES_IDATAR_IDATA_Pos)) /* Assigment of value for IDATA in the AES_IDATAR register */
#define AES_IDATAR_Msk                        _UINT32_(0xFFFFFFFF)                                 /* (AES_IDATAR) Register Mask  */


/* -------- AES_ODATAR : (AES Offset: 0x50) ( R/ 32) Output Data Register -------- */
#define AES_ODATAR_ODATA_Pos                  _UINT32_(0)                                          /* (AES_ODATAR) Output Data Position */
#define AES_ODATAR_ODATA_Msk                  (_UINT32_(0xFFFFFFFF) << AES_ODATAR_ODATA_Pos)       /* (AES_ODATAR) Output Data Mask */
#define AES_ODATAR_ODATA(value)               (AES_ODATAR_ODATA_Msk & (_UINT32_(value) << AES_ODATAR_ODATA_Pos)) /* Assigment of value for ODATA in the AES_ODATAR register */
#define AES_ODATAR_Msk                        _UINT32_(0xFFFFFFFF)                                 /* (AES_ODATAR) Register Mask  */


/* -------- AES_IVR : (AES Offset: 0x60) ( /W 32) Initialization Vector Register -------- */
#define AES_IVR_IV_Pos                        _UINT32_(0)                                          /* (AES_IVR) Initialization Vector Position */
#define AES_IVR_IV_Msk                        (_UINT32_(0xFFFFFFFF) << AES_IVR_IV_Pos)             /* (AES_IVR) Initialization Vector Mask */
#define AES_IVR_IV(value)                     (AES_IVR_IV_Msk & (_UINT32_(value) << AES_IVR_IV_Pos)) /* Assigment of value for IV in the AES_IVR register */
#define AES_IVR_Msk                           _UINT32_(0xFFFFFFFF)                                 /* (AES_IVR) Register Mask  */


/* -------- AES_AADLENR : (AES Offset: 0x70) (R/W 32) Additional Authenticated Data Length Register -------- */
#define AES_AADLENR_AADLEN_Pos                _UINT32_(0)                                          /* (AES_AADLENR) Additional Authenticated Data Length Position */
#define AES_AADLENR_AADLEN_Msk                (_UINT32_(0xFFFFFFFF) << AES_AADLENR_AADLEN_Pos)     /* (AES_AADLENR) Additional Authenticated Data Length Mask */
#define AES_AADLENR_AADLEN(value)             (AES_AADLENR_AADLEN_Msk & (_UINT32_(value) << AES_AADLENR_AADLEN_Pos)) /* Assigment of value for AADLEN in the AES_AADLENR register */
#define AES_AADLENR_Msk                       _UINT32_(0xFFFFFFFF)                                 /* (AES_AADLENR) Register Mask  */


/* -------- AES_CLENR : (AES Offset: 0x74) (R/W 32) Plaintext/Ciphertext Length Register -------- */
#define AES_CLENR_CLEN_Pos                    _UINT32_(0)                                          /* (AES_CLENR) Plaintext/Ciphertext Length Position */
#define AES_CLENR_CLEN_Msk                    (_UINT32_(0xFFFFFFFF) << AES_CLENR_CLEN_Pos)         /* (AES_CLENR) Plaintext/Ciphertext Length Mask */
#define AES_CLENR_CLEN(value)                 (AES_CLENR_CLEN_Msk & (_UINT32_(value) << AES_CLENR_CLEN_Pos)) /* Assigment of value for CLEN in the AES_CLENR register */
#define AES_CLENR_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (AES_CLENR) Register Mask  */


/* -------- AES_GHASHR : (AES Offset: 0x78) (R/W 32) GCM Intermediate Hash Word Register -------- */
#define AES_GHASHR_GHASH_Pos                  _UINT32_(0)                                          /* (AES_GHASHR) Intermediate GCM Hash Word x Position */
#define AES_GHASHR_GHASH_Msk                  (_UINT32_(0xFFFFFFFF) << AES_GHASHR_GHASH_Pos)       /* (AES_GHASHR) Intermediate GCM Hash Word x Mask */
#define AES_GHASHR_GHASH(value)               (AES_GHASHR_GHASH_Msk & (_UINT32_(value) << AES_GHASHR_GHASH_Pos)) /* Assigment of value for GHASH in the AES_GHASHR register */
#define AES_GHASHR_Msk                        _UINT32_(0xFFFFFFFF)                                 /* (AES_GHASHR) Register Mask  */


/* -------- AES_TAGR : (AES Offset: 0x88) ( R/ 32) GCM Authentication Tag Word Register -------- */
#define AES_TAGR_TAG_Pos                      _UINT32_(0)                                          /* (AES_TAGR) GCM Authentication Tag x Position */
#define AES_TAGR_TAG_Msk                      (_UINT32_(0xFFFFFFFF) << AES_TAGR_TAG_Pos)           /* (AES_TAGR) GCM Authentication Tag x Mask */
#define AES_TAGR_TAG(value)                   (AES_TAGR_TAG_Msk & (_UINT32_(value) << AES_TAGR_TAG_Pos)) /* Assigment of value for TAG in the AES_TAGR register */
#define AES_TAGR_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (AES_TAGR) Register Mask  */


/* -------- AES_CTRR : (AES Offset: 0x98) ( R/ 32) GCM Encryption Counter Value Register -------- */
#define AES_CTRR_CTR_Pos                      _UINT32_(0)                                          /* (AES_CTRR) GCM Encryption Counter Position */
#define AES_CTRR_CTR_Msk                      (_UINT32_(0xFFFFFFFF) << AES_CTRR_CTR_Pos)           /* (AES_CTRR) GCM Encryption Counter Mask */
#define AES_CTRR_CTR(value)                   (AES_CTRR_CTR_Msk & (_UINT32_(value) << AES_CTRR_CTR_Pos)) /* Assigment of value for CTR in the AES_CTRR register */
#define AES_CTRR_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (AES_CTRR) Register Mask  */


/* -------- AES_GCMHR : (AES Offset: 0x9C) (R/W 32) GCM H Word Register -------- */
#define AES_GCMHR_H_Pos                       _UINT32_(0)                                          /* (AES_GCMHR) GCM H Word x Position */
#define AES_GCMHR_H_Msk                       (_UINT32_(0xFFFFFFFF) << AES_GCMHR_H_Pos)            /* (AES_GCMHR) GCM H Word x Mask */
#define AES_GCMHR_H(value)                    (AES_GCMHR_H_Msk & (_UINT32_(value) << AES_GCMHR_H_Pos)) /* Assigment of value for H in the AES_GCMHR register */
#define AES_GCMHR_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (AES_GCMHR) Register Mask  */


/* -------- AES_EMR : (AES Offset: 0xB0) (R/W 32) Extended Mode Register -------- */
#define AES_EMR_APEN_Pos                      _UINT32_(0)                                          /* (AES_EMR) Auto Padding Enable Position */
#define AES_EMR_APEN_Msk                      (_UINT32_(0x1) << AES_EMR_APEN_Pos)                  /* (AES_EMR) Auto Padding Enable Mask */
#define AES_EMR_APEN(value)                   (AES_EMR_APEN_Msk & (_UINT32_(value) << AES_EMR_APEN_Pos)) /* Assigment of value for APEN in the AES_EMR register */
#define AES_EMR_APM_Pos                       _UINT32_(1)                                          /* (AES_EMR) Auto Padding Mode Position */
#define AES_EMR_APM_Msk                       (_UINT32_(0x1) << AES_EMR_APM_Pos)                   /* (AES_EMR) Auto Padding Mode Mask */
#define AES_EMR_APM(value)                    (AES_EMR_APM_Msk & (_UINT32_(value) << AES_EMR_APM_Pos)) /* Assigment of value for APM in the AES_EMR register */
#define AES_EMR_KSEL_Pos                      _UINT32_(2)                                          /* (AES_EMR) Key Selection Position */
#define AES_EMR_KSEL_Msk                      (_UINT32_(0x1) << AES_EMR_KSEL_Pos)                  /* (AES_EMR) Key Selection Mask */
#define AES_EMR_KSEL(value)                   (AES_EMR_KSEL_Msk & (_UINT32_(value) << AES_EMR_KSEL_Pos)) /* Assigment of value for KSEL in the AES_EMR register */
#define AES_EMR_PLIPEN_Pos                    _UINT32_(4)                                          /* (AES_EMR) Protocol Layer Improved Performance Enable Position */
#define AES_EMR_PLIPEN_Msk                    (_UINT32_(0x1) << AES_EMR_PLIPEN_Pos)                /* (AES_EMR) Protocol Layer Improved Performance Enable Mask */
#define AES_EMR_PLIPEN(value)                 (AES_EMR_PLIPEN_Msk & (_UINT32_(value) << AES_EMR_PLIPEN_Pos)) /* Assigment of value for PLIPEN in the AES_EMR register */
#define AES_EMR_PLIPD_Pos                     _UINT32_(5)                                          /* (AES_EMR) Protocol Layer Improved Performance Decipher Position */
#define AES_EMR_PLIPD_Msk                     (_UINT32_(0x1) << AES_EMR_PLIPD_Pos)                 /* (AES_EMR) Protocol Layer Improved Performance Decipher Mask */
#define AES_EMR_PLIPD(value)                  (AES_EMR_PLIPD_Msk & (_UINT32_(value) << AES_EMR_PLIPD_Pos)) /* Assigment of value for PLIPD in the AES_EMR register */
#define AES_EMR_PKWL_Pos                      _UINT32_(6)                                          /* (AES_EMR) Private Key Write Lock Position */
#define AES_EMR_PKWL_Msk                      (_UINT32_(0x1) << AES_EMR_PKWL_Pos)                  /* (AES_EMR) Private Key Write Lock Mask */
#define AES_EMR_PKWL(value)                   (AES_EMR_PKWL_Msk & (_UINT32_(value) << AES_EMR_PKWL_Pos)) /* Assigment of value for PKWL in the AES_EMR register */
#define AES_EMR_PKRS_Pos                      _UINT32_(7)                                          /* (AES_EMR) Private Key Internal Register Select Position */
#define AES_EMR_PKRS_Msk                      (_UINT32_(0x1) << AES_EMR_PKRS_Pos)                  /* (AES_EMR) Private Key Internal Register Select Mask */
#define AES_EMR_PKRS(value)                   (AES_EMR_PKRS_Msk & (_UINT32_(value) << AES_EMR_PKRS_Pos)) /* Assigment of value for PKRS in the AES_EMR register */
#define AES_EMR_PADLEN_Pos                    _UINT32_(8)                                          /* (AES_EMR) Auto Padding Length Position */
#define AES_EMR_PADLEN_Msk                    (_UINT32_(0xFF) << AES_EMR_PADLEN_Pos)               /* (AES_EMR) Auto Padding Length Mask */
#define AES_EMR_PADLEN(value)                 (AES_EMR_PADLEN_Msk & (_UINT32_(value) << AES_EMR_PADLEN_Pos)) /* Assigment of value for PADLEN in the AES_EMR register */
#define AES_EMR_NHEAD_Pos                     _UINT32_(16)                                         /* (AES_EMR) IPSec Next Header Position */
#define AES_EMR_NHEAD_Msk                     (_UINT32_(0xFF) << AES_EMR_NHEAD_Pos)                /* (AES_EMR) IPSec Next Header Mask */
#define AES_EMR_NHEAD(value)                  (AES_EMR_NHEAD_Msk & (_UINT32_(value) << AES_EMR_NHEAD_Pos)) /* Assigment of value for NHEAD in the AES_EMR register */
#define AES_EMR_ALGO_Pos                      _UINT32_(24)                                         /* (AES_EMR) Encryption Algorithm Position */
#define AES_EMR_ALGO_Msk                      (_UINT32_(0x1) << AES_EMR_ALGO_Pos)                  /* (AES_EMR) Encryption Algorithm Mask */
#define AES_EMR_ALGO(value)                   (AES_EMR_ALGO_Msk & (_UINT32_(value) << AES_EMR_ALGO_Pos)) /* Assigment of value for ALGO in the AES_EMR register */
#define   AES_EMR_ALGO_AES_Val                _UINT32_(0x0)                                        /* (AES_EMR) The AES algorithm is used for encryption.  */
#define   AES_EMR_ALGO_ARIA_Val               _UINT32_(0x1)                                        /* (AES_EMR) The ARIA algorithm is used for encryption.  */
#define AES_EMR_ALGO_AES                      (AES_EMR_ALGO_AES_Val << AES_EMR_ALGO_Pos)           /* (AES_EMR) The AES algorithm is used for encryption. Position  */
#define AES_EMR_ALGO_ARIA                     (AES_EMR_ALGO_ARIA_Val << AES_EMR_ALGO_Pos)          /* (AES_EMR) The ARIA algorithm is used for encryption. Position  */
#define AES_EMR_BPE_Pos                       _UINT32_(31)                                         /* (AES_EMR) Block Processing End Position */
#define AES_EMR_BPE_Msk                       (_UINT32_(0x1) << AES_EMR_BPE_Pos)                   /* (AES_EMR) Block Processing End Mask */
#define AES_EMR_BPE(value)                    (AES_EMR_BPE_Msk & (_UINT32_(value) << AES_EMR_BPE_Pos)) /* Assigment of value for BPE in the AES_EMR register */
#define AES_EMR_Msk                           _UINT32_(0x81FFFFF7)                                 /* (AES_EMR) Register Mask  */


/* -------- AES_BCNT : (AES Offset: 0xB4) (R/W 32) Byte Counter Register -------- */
#define AES_BCNT_BCNT_Pos                     _UINT32_(0)                                          /* (AES_BCNT) Auto Padding Byte Counter Position */
#define AES_BCNT_BCNT_Msk                     (_UINT32_(0xFFFFFFFF) << AES_BCNT_BCNT_Pos)          /* (AES_BCNT) Auto Padding Byte Counter Mask */
#define AES_BCNT_BCNT(value)                  (AES_BCNT_BCNT_Msk & (_UINT32_(value) << AES_BCNT_BCNT_Pos)) /* Assigment of value for BCNT in the AES_BCNT register */
#define AES_BCNT_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (AES_BCNT) Register Mask  */


/* -------- AES_WPMR : (AES Offset: 0xE4) (R/W 32) Write Protection Mode Register -------- */
#define AES_WPMR_WPEN_Pos                     _UINT32_(0)                                          /* (AES_WPMR) Write Protection Configuration Enable Position */
#define AES_WPMR_WPEN_Msk                     (_UINT32_(0x1) << AES_WPMR_WPEN_Pos)                 /* (AES_WPMR) Write Protection Configuration Enable Mask */
#define AES_WPMR_WPEN(value)                  (AES_WPMR_WPEN_Msk & (_UINT32_(value) << AES_WPMR_WPEN_Pos)) /* Assigment of value for WPEN in the AES_WPMR register */
#define AES_WPMR_WPITEN_Pos                   _UINT32_(1)                                          /* (AES_WPMR) Write Protection Interruption Enable Position */
#define AES_WPMR_WPITEN_Msk                   (_UINT32_(0x1) << AES_WPMR_WPITEN_Pos)               /* (AES_WPMR) Write Protection Interruption Enable Mask */
#define AES_WPMR_WPITEN(value)                (AES_WPMR_WPITEN_Msk & (_UINT32_(value) << AES_WPMR_WPITEN_Pos)) /* Assigment of value for WPITEN in the AES_WPMR register */
#define AES_WPMR_WPCREN_Pos                   _UINT32_(2)                                          /* (AES_WPMR) Write Protection Control Enable Position */
#define AES_WPMR_WPCREN_Msk                   (_UINT32_(0x1) << AES_WPMR_WPCREN_Pos)               /* (AES_WPMR) Write Protection Control Enable Mask */
#define AES_WPMR_WPCREN(value)                (AES_WPMR_WPCREN_Msk & (_UINT32_(value) << AES_WPMR_WPCREN_Pos)) /* Assigment of value for WPCREN in the AES_WPMR register */
#define AES_WPMR_FIRSTE_Pos                   _UINT32_(4)                                          /* (AES_WPMR) First Error Report Enable Position */
#define AES_WPMR_FIRSTE_Msk                   (_UINT32_(0x1) << AES_WPMR_FIRSTE_Pos)               /* (AES_WPMR) First Error Report Enable Mask */
#define AES_WPMR_FIRSTE(value)                (AES_WPMR_FIRSTE_Msk & (_UINT32_(value) << AES_WPMR_FIRSTE_Pos)) /* Assigment of value for FIRSTE in the AES_WPMR register */
#define AES_WPMR_ACTION_Pos                   _UINT32_(5)                                          /* (AES_WPMR) Action on Abnormal Event Detection Position */
#define AES_WPMR_ACTION_Msk                   (_UINT32_(0x7) << AES_WPMR_ACTION_Pos)               /* (AES_WPMR) Action on Abnormal Event Detection Mask */
#define AES_WPMR_ACTION(value)                (AES_WPMR_ACTION_Msk & (_UINT32_(value) << AES_WPMR_ACTION_Pos)) /* Assigment of value for ACTION in the AES_WPMR register */
#define   AES_WPMR_ACTION_REPORT_ONLY_Val     _UINT32_(0x0)                                        /* (AES_WPMR) No action (stop or clear key) is performed when one of PKRPVS, WPVS, CGD, SEQE, or SWE flags is set.  */
#define   AES_WPMR_ACTION_LOCK_PKRPVS_WPVS_SWE_Val _UINT32_(0x1)                                        /* (AES_WPMR) If a processing is in progress when the AES_WPSR.PKRPVS/WPVS/SWE event detection occurs, the current processing is ended normally but no other processing is started while a AES_CR.UNLOCK command is issued.  */
#define   AES_WPMR_ACTION_LOCK_CGD_SEQE_Val   _UINT32_(0x2)                                        /* (AES_WPMR) If a processing is in progress when the AES_WPSR.CGD/SEQE event detection occurs, the current processing is ended normally but no other processing is started while a AES_CR.UNLOCK command is issued.  */
#define   AES_WPMR_ACTION_LOCK_ANY_EV_Val     _UINT32_(0x3)                                        /* (AES_WPMR) If a processing is in progress when the AES_WPSR.PKRPVS/WPVS/CGD/SEQE/SWE events detection occurs, the current processing is ended normally but no other processing is started while a AES_CR.UNLOCK command is issued.  */
#define   AES_WPMR_ACTION_CLEAR_PKRPVS_WPVS_SWE_Val _UINT32_(0x4)                                        /* (AES_WPMR) If a processing is in progress when the AES_WPSR.PKRPVS/WPVS/SWE events detection occurs, the current processing is ended normally but no other processing is started while a AES_CR.UNLOCK command is issued. Moreover, the AES_KEYWRx key is immediately cleared.  */
#define   AES_WPMR_ACTION_CLEAR_CGD_SEQE_Val  _UINT32_(0x5)                                        /* (AES_WPMR) If a processing is in progress when the AES_WPSR.CGD/SEQE events detection occurs, the current processing is ended normally but no other processing is started while a AES_CR.UNLOCK command is issued. Moreover, the AES_KEYWRx key is immediately cleared.  */
#define   AES_WPMR_ACTION_CLEAR_ANY_EV_Val    _UINT32_(0x6)                                        /* (AES_WPMR) If a processing is in progress when the AES_WPSR.PKRPVS/WPVS/CGD/SEQE/SWE events detection occurs, the current processing is ended normally but no other processing is started while a AES_CR.UNLOCK command is issued. Moreover, the AES_KEYWRx key is immediately cleared.  */
#define AES_WPMR_ACTION_REPORT_ONLY           (AES_WPMR_ACTION_REPORT_ONLY_Val << AES_WPMR_ACTION_Pos) /* (AES_WPMR) No action (stop or clear key) is performed when one of PKRPVS, WPVS, CGD, SEQE, or SWE flags is set. Position  */
#define AES_WPMR_ACTION_LOCK_PKRPVS_WPVS_SWE  (AES_WPMR_ACTION_LOCK_PKRPVS_WPVS_SWE_Val << AES_WPMR_ACTION_Pos) /* (AES_WPMR) If a processing is in progress when the AES_WPSR.PKRPVS/WPVS/SWE event detection occurs, the current processing is ended normally but no other processing is started while a AES_CR.UNLOCK command is issued. Position  */
#define AES_WPMR_ACTION_LOCK_CGD_SEQE         (AES_WPMR_ACTION_LOCK_CGD_SEQE_Val << AES_WPMR_ACTION_Pos) /* (AES_WPMR) If a processing is in progress when the AES_WPSR.CGD/SEQE event detection occurs, the current processing is ended normally but no other processing is started while a AES_CR.UNLOCK command is issued. Position  */
#define AES_WPMR_ACTION_LOCK_ANY_EV           (AES_WPMR_ACTION_LOCK_ANY_EV_Val << AES_WPMR_ACTION_Pos) /* (AES_WPMR) If a processing is in progress when the AES_WPSR.PKRPVS/WPVS/CGD/SEQE/SWE events detection occurs, the current processing is ended normally but no other processing is started while a AES_CR.UNLOCK command is issued. Position  */
#define AES_WPMR_ACTION_CLEAR_PKRPVS_WPVS_SWE (AES_WPMR_ACTION_CLEAR_PKRPVS_WPVS_SWE_Val << AES_WPMR_ACTION_Pos) /* (AES_WPMR) If a processing is in progress when the AES_WPSR.PKRPVS/WPVS/SWE events detection occurs, the current processing is ended normally but no other processing is started while a AES_CR.UNLOCK command is issued. Moreover, the AES_KEYWRx key is immediately cleared. Position  */
#define AES_WPMR_ACTION_CLEAR_CGD_SEQE        (AES_WPMR_ACTION_CLEAR_CGD_SEQE_Val << AES_WPMR_ACTION_Pos) /* (AES_WPMR) If a processing is in progress when the AES_WPSR.CGD/SEQE events detection occurs, the current processing is ended normally but no other processing is started while a AES_CR.UNLOCK command is issued. Moreover, the AES_KEYWRx key is immediately cleared. Position  */
#define AES_WPMR_ACTION_CLEAR_ANY_EV          (AES_WPMR_ACTION_CLEAR_ANY_EV_Val << AES_WPMR_ACTION_Pos) /* (AES_WPMR) If a processing is in progress when the AES_WPSR.PKRPVS/WPVS/CGD/SEQE/SWE events detection occurs, the current processing is ended normally but no other processing is started while a AES_CR.UNLOCK command is issued. Moreover, the AES_KEYWRx key is immediately cleared. Position  */
#define AES_WPMR_WPKEY_Pos                    _UINT32_(8)                                          /* (AES_WPMR) Write Protection Key Position */
#define AES_WPMR_WPKEY_Msk                    (_UINT32_(0xFFFFFF) << AES_WPMR_WPKEY_Pos)           /* (AES_WPMR) Write Protection Key Mask */
#define AES_WPMR_WPKEY(value)                 (AES_WPMR_WPKEY_Msk & (_UINT32_(value) << AES_WPMR_WPKEY_Pos)) /* Assigment of value for WPKEY in the AES_WPMR register */
#define   AES_WPMR_WPKEY_PASSWD_Val           _UINT32_(0x414553)                                   /* (AES_WPMR) Writing any other value in this field aborts the write operation of the WPEN,WPITEN,WPCREN bits. Always reads as 0.  */
#define AES_WPMR_WPKEY_PASSWD                 (AES_WPMR_WPKEY_PASSWD_Val << AES_WPMR_WPKEY_Pos)    /* (AES_WPMR) Writing any other value in this field aborts the write operation of the WPEN,WPITEN,WPCREN bits. Always reads as 0. Position  */
#define AES_WPMR_Msk                          _UINT32_(0xFFFFFFF7)                                 /* (AES_WPMR) Register Mask  */


/* -------- AES_WPSR : (AES Offset: 0xE8) ( R/ 32) Write Protection Status Register -------- */
#define AES_WPSR_WPVS_Pos                     _UINT32_(0)                                          /* (AES_WPSR) Write Protection Violation Status (cleared on read) Position */
#define AES_WPSR_WPVS_Msk                     (_UINT32_(0x1) << AES_WPSR_WPVS_Pos)                 /* (AES_WPSR) Write Protection Violation Status (cleared on read) Mask */
#define AES_WPSR_WPVS(value)                  (AES_WPSR_WPVS_Msk & (_UINT32_(value) << AES_WPSR_WPVS_Pos)) /* Assigment of value for WPVS in the AES_WPSR register */
#define AES_WPSR_CGD_Pos                      _UINT32_(1)                                          /* (AES_WPSR) Clock Glitch Detected (cleared on read) Position */
#define AES_WPSR_CGD_Msk                      (_UINT32_(0x1) << AES_WPSR_CGD_Pos)                  /* (AES_WPSR) Clock Glitch Detected (cleared on read) Mask */
#define AES_WPSR_CGD(value)                   (AES_WPSR_CGD_Msk & (_UINT32_(value) << AES_WPSR_CGD_Pos)) /* Assigment of value for CGD in the AES_WPSR register */
#define AES_WPSR_SEQE_Pos                     _UINT32_(2)                                          /* (AES_WPSR) Internal Sequencer Error (cleared on read) Position */
#define AES_WPSR_SEQE_Msk                     (_UINT32_(0x1) << AES_WPSR_SEQE_Pos)                 /* (AES_WPSR) Internal Sequencer Error (cleared on read) Mask */
#define AES_WPSR_SEQE(value)                  (AES_WPSR_SEQE_Msk & (_UINT32_(value) << AES_WPSR_SEQE_Pos)) /* Assigment of value for SEQE in the AES_WPSR register */
#define AES_WPSR_SWE_Pos                      _UINT32_(3)                                          /* (AES_WPSR) Software Control Error (cleared on read) Position */
#define AES_WPSR_SWE_Msk                      (_UINT32_(0x1) << AES_WPSR_SWE_Pos)                  /* (AES_WPSR) Software Control Error (cleared on read) Mask */
#define AES_WPSR_SWE(value)                   (AES_WPSR_SWE_Msk & (_UINT32_(value) << AES_WPSR_SWE_Pos)) /* Assigment of value for SWE in the AES_WPSR register */
#define AES_WPSR_PKRPVS_Pos                   _UINT32_(4)                                          /* (AES_WPSR) Private Key Internal Register Protection Violation Status (cleared on read) Position */
#define AES_WPSR_PKRPVS_Msk                   (_UINT32_(0x1) << AES_WPSR_PKRPVS_Pos)               /* (AES_WPSR) Private Key Internal Register Protection Violation Status (cleared on read) Mask */
#define AES_WPSR_PKRPVS(value)                (AES_WPSR_PKRPVS_Msk & (_UINT32_(value) << AES_WPSR_PKRPVS_Pos)) /* Assigment of value for PKRPVS in the AES_WPSR register */
#define AES_WPSR_WPVSRC_Pos                   _UINT32_(8)                                          /* (AES_WPSR) Write Protection Violation Source Position */
#define AES_WPSR_WPVSRC_Msk                   (_UINT32_(0xFF) << AES_WPSR_WPVSRC_Pos)              /* (AES_WPSR) Write Protection Violation Source Mask */
#define AES_WPSR_WPVSRC(value)                (AES_WPSR_WPVSRC_Msk & (_UINT32_(value) << AES_WPSR_WPVSRC_Pos)) /* Assigment of value for WPVSRC in the AES_WPSR register */
#define AES_WPSR_SWETYP_Pos                   _UINT32_(24)                                         /* (AES_WPSR) Software Error Type (cleared on read) Position */
#define AES_WPSR_SWETYP_Msk                   (_UINT32_(0xF) << AES_WPSR_SWETYP_Pos)               /* (AES_WPSR) Software Error Type (cleared on read) Mask */
#define AES_WPSR_SWETYP(value)                (AES_WPSR_SWETYP_Msk & (_UINT32_(value) << AES_WPSR_SWETYP_Pos)) /* Assigment of value for SWETYP in the AES_WPSR register */
#define   AES_WPSR_SWETYP_READ_WO_Val         _UINT32_(0x0)                                        /* (AES_WPSR) A write-only register has been read (Warning).  */
#define   AES_WPSR_SWETYP_WRITE_RO_Val        _UINT32_(0x1)                                        /* (AES_WPSR) AES is enabled and a write access has been performed on a read-only register (Warning).  */
#define   AES_WPSR_SWETYP_UNDEF_RW_Val        _UINT32_(0x2)                                        /* (AES_WPSR) Access to an undefined address (Warning).  */
#define   AES_WPSR_SWETYP_CTRL_START_Val      _UINT32_(0x3)                                        /* (AES_WPSR) Abnormal use of AES_CR.START command when DMA access is configured.  */
#define   AES_WPSR_SWETYP_WEIRD_ACTION_Val    _UINT32_(0x4)                                        /* (AES_WPSR) A key write, init value write, output data read, AES_MR and AES_EMR write, GCM configuration registers write, AES_BCNT write, Private Key bus access has been performed while a current processing is in progress (abnormal).  */
#define   AES_WPSR_SWETYP_INCOMPLETE_KEY_Val  _UINT32_(0x5)                                        /* (AES_WPSR) A tentative of start is required while the key is not fully loaded into the AES_KEYWRx registers.  */
#define AES_WPSR_SWETYP_READ_WO               (AES_WPSR_SWETYP_READ_WO_Val << AES_WPSR_SWETYP_Pos) /* (AES_WPSR) A write-only register has been read (Warning). Position  */
#define AES_WPSR_SWETYP_WRITE_RO              (AES_WPSR_SWETYP_WRITE_RO_Val << AES_WPSR_SWETYP_Pos) /* (AES_WPSR) AES is enabled and a write access has been performed on a read-only register (Warning). Position  */
#define AES_WPSR_SWETYP_UNDEF_RW              (AES_WPSR_SWETYP_UNDEF_RW_Val << AES_WPSR_SWETYP_Pos) /* (AES_WPSR) Access to an undefined address (Warning). Position  */
#define AES_WPSR_SWETYP_CTRL_START            (AES_WPSR_SWETYP_CTRL_START_Val << AES_WPSR_SWETYP_Pos) /* (AES_WPSR) Abnormal use of AES_CR.START command when DMA access is configured. Position  */
#define AES_WPSR_SWETYP_WEIRD_ACTION          (AES_WPSR_SWETYP_WEIRD_ACTION_Val << AES_WPSR_SWETYP_Pos) /* (AES_WPSR) A key write, init value write, output data read, AES_MR and AES_EMR write, GCM configuration registers write, AES_BCNT write, Private Key bus access has been performed while a current processing is in progress (abnormal). Position  */
#define AES_WPSR_SWETYP_INCOMPLETE_KEY        (AES_WPSR_SWETYP_INCOMPLETE_KEY_Val << AES_WPSR_SWETYP_Pos) /* (AES_WPSR) A tentative of start is required while the key is not fully loaded into the AES_KEYWRx registers. Position  */
#define AES_WPSR_ECLASS_Pos                   _UINT32_(31)                                         /* (AES_WPSR) Software Error Class (cleared on read) Position */
#define AES_WPSR_ECLASS_Msk                   (_UINT32_(0x1) << AES_WPSR_ECLASS_Pos)               /* (AES_WPSR) Software Error Class (cleared on read) Mask */
#define AES_WPSR_ECLASS(value)                (AES_WPSR_ECLASS_Msk & (_UINT32_(value) << AES_WPSR_ECLASS_Pos)) /* Assigment of value for ECLASS in the AES_WPSR register */
#define   AES_WPSR_ECLASS_WARNING_Val         _UINT32_(0x0)                                        /* (AES_WPSR) An abnormal access that does not affect system functionality  */
#define   AES_WPSR_ECLASS_ERROR_Val           _UINT32_(0x1)                                        /* (AES_WPSR) An access is performed into key, input data, control registers while the AES is performing an encryption/decryption or a start is request by software or DMA while the key is not fully configured.  */
#define AES_WPSR_ECLASS_WARNING               (AES_WPSR_ECLASS_WARNING_Val << AES_WPSR_ECLASS_Pos) /* (AES_WPSR) An abnormal access that does not affect system functionality Position  */
#define AES_WPSR_ECLASS_ERROR                 (AES_WPSR_ECLASS_ERROR_Val << AES_WPSR_ECLASS_Pos)   /* (AES_WPSR) An access is performed into key, input data, control registers while the AES is performing an encryption/decryption or a start is request by software or DMA while the key is not fully configured. Position  */
#define AES_WPSR_Msk                          _UINT32_(0x8F00FF1F)                                 /* (AES_WPSR) Register Mask  */


/* -------- AES_RPR : (AES Offset: 0x100) (R/W 32) Receive Pointer Register -------- */
#define AES_RPR_RXPTR_Pos                     _UINT32_(0)                                          /* (AES_RPR) Receive Pointer Register Position */
#define AES_RPR_RXPTR_Msk                     (_UINT32_(0xFFFFFFFF) << AES_RPR_RXPTR_Pos)          /* (AES_RPR) Receive Pointer Register Mask */
#define AES_RPR_RXPTR(value)                  (AES_RPR_RXPTR_Msk & (_UINT32_(value) << AES_RPR_RXPTR_Pos)) /* Assigment of value for RXPTR in the AES_RPR register */
#define AES_RPR_Msk                           _UINT32_(0xFFFFFFFF)                                 /* (AES_RPR) Register Mask  */


/* -------- AES_RCR : (AES Offset: 0x104) (R/W 32) Receive Counter Register -------- */
#define AES_RCR_RXCTR_Pos                     _UINT32_(0)                                          /* (AES_RCR) Receive Counter Register Position */
#define AES_RCR_RXCTR_Msk                     (_UINT32_(0xFFFF) << AES_RCR_RXCTR_Pos)              /* (AES_RCR) Receive Counter Register Mask */
#define AES_RCR_RXCTR(value)                  (AES_RCR_RXCTR_Msk & (_UINT32_(value) << AES_RCR_RXCTR_Pos)) /* Assigment of value for RXCTR in the AES_RCR register */
#define AES_RCR_Msk                           _UINT32_(0x0000FFFF)                                 /* (AES_RCR) Register Mask  */


/* -------- AES_TPR : (AES Offset: 0x108) (R/W 32) Transmit Pointer Register -------- */
#define AES_TPR_TXPTR_Pos                     _UINT32_(0)                                          /* (AES_TPR) Transmit Counter Register Position */
#define AES_TPR_TXPTR_Msk                     (_UINT32_(0xFFFFFFFF) << AES_TPR_TXPTR_Pos)          /* (AES_TPR) Transmit Counter Register Mask */
#define AES_TPR_TXPTR(value)                  (AES_TPR_TXPTR_Msk & (_UINT32_(value) << AES_TPR_TXPTR_Pos)) /* Assigment of value for TXPTR in the AES_TPR register */
#define AES_TPR_Msk                           _UINT32_(0xFFFFFFFF)                                 /* (AES_TPR) Register Mask  */


/* -------- AES_TCR : (AES Offset: 0x10C) (R/W 32) Transmit Counter Register -------- */
#define AES_TCR_TXCTR_Pos                     _UINT32_(0)                                          /* (AES_TCR) Transmit Counter Register Position */
#define AES_TCR_TXCTR_Msk                     (_UINT32_(0xFFFF) << AES_TCR_TXCTR_Pos)              /* (AES_TCR) Transmit Counter Register Mask */
#define AES_TCR_TXCTR(value)                  (AES_TCR_TXCTR_Msk & (_UINT32_(value) << AES_TCR_TXCTR_Pos)) /* Assigment of value for TXCTR in the AES_TCR register */
#define AES_TCR_Msk                           _UINT32_(0x0000FFFF)                                 /* (AES_TCR) Register Mask  */


/* -------- AES_RNPR : (AES Offset: 0x110) (R/W 32) Receive Next Pointer Register -------- */
#define AES_RNPR_RXNPTR_Pos                   _UINT32_(0)                                          /* (AES_RNPR) Receive Next Pointer Position */
#define AES_RNPR_RXNPTR_Msk                   (_UINT32_(0xFFFFFFFF) << AES_RNPR_RXNPTR_Pos)        /* (AES_RNPR) Receive Next Pointer Mask */
#define AES_RNPR_RXNPTR(value)                (AES_RNPR_RXNPTR_Msk & (_UINT32_(value) << AES_RNPR_RXNPTR_Pos)) /* Assigment of value for RXNPTR in the AES_RNPR register */
#define AES_RNPR_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (AES_RNPR) Register Mask  */


/* -------- AES_RNCR : (AES Offset: 0x114) (R/W 32) Receive Next Counter Register -------- */
#define AES_RNCR_RXNCTR_Pos                   _UINT32_(0)                                          /* (AES_RNCR) Receive Next Counter Position */
#define AES_RNCR_RXNCTR_Msk                   (_UINT32_(0xFFFF) << AES_RNCR_RXNCTR_Pos)            /* (AES_RNCR) Receive Next Counter Mask */
#define AES_RNCR_RXNCTR(value)                (AES_RNCR_RXNCTR_Msk & (_UINT32_(value) << AES_RNCR_RXNCTR_Pos)) /* Assigment of value for RXNCTR in the AES_RNCR register */
#define AES_RNCR_Msk                          _UINT32_(0x0000FFFF)                                 /* (AES_RNCR) Register Mask  */


/* -------- AES_TNPR : (AES Offset: 0x118) (R/W 32) Transmit Next Pointer Register -------- */
#define AES_TNPR_TXNPTR_Pos                   _UINT32_(0)                                          /* (AES_TNPR) Transmit Next Pointer Position */
#define AES_TNPR_TXNPTR_Msk                   (_UINT32_(0xFFFFFFFF) << AES_TNPR_TXNPTR_Pos)        /* (AES_TNPR) Transmit Next Pointer Mask */
#define AES_TNPR_TXNPTR(value)                (AES_TNPR_TXNPTR_Msk & (_UINT32_(value) << AES_TNPR_TXNPTR_Pos)) /* Assigment of value for TXNPTR in the AES_TNPR register */
#define AES_TNPR_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (AES_TNPR) Register Mask  */


/* -------- AES_TNCR : (AES Offset: 0x11C) (R/W 32) Transmit Next Counter Register -------- */
#define AES_TNCR_TXNCTR_Pos                   _UINT32_(0)                                          /* (AES_TNCR) Transmit Counter Next Position */
#define AES_TNCR_TXNCTR_Msk                   (_UINT32_(0xFFFF) << AES_TNCR_TXNCTR_Pos)            /* (AES_TNCR) Transmit Counter Next Mask */
#define AES_TNCR_TXNCTR(value)                (AES_TNCR_TXNCTR_Msk & (_UINT32_(value) << AES_TNCR_TXNCTR_Pos)) /* Assigment of value for TXNCTR in the AES_TNCR register */
#define AES_TNCR_Msk                          _UINT32_(0x0000FFFF)                                 /* (AES_TNCR) Register Mask  */


/* -------- AES_PTCR : (AES Offset: 0x120) ( /W 32) Transfer Control Register -------- */
#define AES_PTCR_RXTEN_Pos                    _UINT32_(0)                                          /* (AES_PTCR) Receiver Transfer Enable Position */
#define AES_PTCR_RXTEN_Msk                    (_UINT32_(0x1) << AES_PTCR_RXTEN_Pos)                /* (AES_PTCR) Receiver Transfer Enable Mask */
#define AES_PTCR_RXTEN(value)                 (AES_PTCR_RXTEN_Msk & (_UINT32_(value) << AES_PTCR_RXTEN_Pos)) /* Assigment of value for RXTEN in the AES_PTCR register */
#define AES_PTCR_RXTDIS_Pos                   _UINT32_(1)                                          /* (AES_PTCR) Receiver Transfer Disable Position */
#define AES_PTCR_RXTDIS_Msk                   (_UINT32_(0x1) << AES_PTCR_RXTDIS_Pos)               /* (AES_PTCR) Receiver Transfer Disable Mask */
#define AES_PTCR_RXTDIS(value)                (AES_PTCR_RXTDIS_Msk & (_UINT32_(value) << AES_PTCR_RXTDIS_Pos)) /* Assigment of value for RXTDIS in the AES_PTCR register */
#define AES_PTCR_TXTEN_Pos                    _UINT32_(8)                                          /* (AES_PTCR) Transmitter Transfer Enable Position */
#define AES_PTCR_TXTEN_Msk                    (_UINT32_(0x1) << AES_PTCR_TXTEN_Pos)                /* (AES_PTCR) Transmitter Transfer Enable Mask */
#define AES_PTCR_TXTEN(value)                 (AES_PTCR_TXTEN_Msk & (_UINT32_(value) << AES_PTCR_TXTEN_Pos)) /* Assigment of value for TXTEN in the AES_PTCR register */
#define AES_PTCR_TXTDIS_Pos                   _UINT32_(9)                                          /* (AES_PTCR) Transmitter Transfer Disable Position */
#define AES_PTCR_TXTDIS_Msk                   (_UINT32_(0x1) << AES_PTCR_TXTDIS_Pos)               /* (AES_PTCR) Transmitter Transfer Disable Mask */
#define AES_PTCR_TXTDIS(value)                (AES_PTCR_TXTDIS_Msk & (_UINT32_(value) << AES_PTCR_TXTDIS_Pos)) /* Assigment of value for TXTDIS in the AES_PTCR register */
#define AES_PTCR_RXCBEN_Pos                   _UINT32_(16)                                         /* (AES_PTCR) Receiver Circular Buffer Enable Position */
#define AES_PTCR_RXCBEN_Msk                   (_UINT32_(0x1) << AES_PTCR_RXCBEN_Pos)               /* (AES_PTCR) Receiver Circular Buffer Enable Mask */
#define AES_PTCR_RXCBEN(value)                (AES_PTCR_RXCBEN_Msk & (_UINT32_(value) << AES_PTCR_RXCBEN_Pos)) /* Assigment of value for RXCBEN in the AES_PTCR register */
#define AES_PTCR_RXCBDIS_Pos                  _UINT32_(17)                                         /* (AES_PTCR) Receiver Circular Buffer Disable Position */
#define AES_PTCR_RXCBDIS_Msk                  (_UINT32_(0x1) << AES_PTCR_RXCBDIS_Pos)              /* (AES_PTCR) Receiver Circular Buffer Disable Mask */
#define AES_PTCR_RXCBDIS(value)               (AES_PTCR_RXCBDIS_Msk & (_UINT32_(value) << AES_PTCR_RXCBDIS_Pos)) /* Assigment of value for RXCBDIS in the AES_PTCR register */
#define AES_PTCR_TXCBEN_Pos                   _UINT32_(18)                                         /* (AES_PTCR) Transmitter Circular Buffer Enable Position */
#define AES_PTCR_TXCBEN_Msk                   (_UINT32_(0x1) << AES_PTCR_TXCBEN_Pos)               /* (AES_PTCR) Transmitter Circular Buffer Enable Mask */
#define AES_PTCR_TXCBEN(value)                (AES_PTCR_TXCBEN_Msk & (_UINT32_(value) << AES_PTCR_TXCBEN_Pos)) /* Assigment of value for TXCBEN in the AES_PTCR register */
#define AES_PTCR_TXCBDIS_Pos                  _UINT32_(19)                                         /* (AES_PTCR) Transmitter Circular Buffer Disable Position */
#define AES_PTCR_TXCBDIS_Msk                  (_UINT32_(0x1) << AES_PTCR_TXCBDIS_Pos)              /* (AES_PTCR) Transmitter Circular Buffer Disable Mask */
#define AES_PTCR_TXCBDIS(value)               (AES_PTCR_TXCBDIS_Msk & (_UINT32_(value) << AES_PTCR_TXCBDIS_Pos)) /* Assigment of value for TXCBDIS in the AES_PTCR register */
#define AES_PTCR_ERRCLR_Pos                   _UINT32_(24)                                         /* (AES_PTCR) Transfer Bus Error Clear Position */
#define AES_PTCR_ERRCLR_Msk                   (_UINT32_(0x1) << AES_PTCR_ERRCLR_Pos)               /* (AES_PTCR) Transfer Bus Error Clear Mask */
#define AES_PTCR_ERRCLR(value)                (AES_PTCR_ERRCLR_Msk & (_UINT32_(value) << AES_PTCR_ERRCLR_Pos)) /* Assigment of value for ERRCLR in the AES_PTCR register */
#define AES_PTCR_Msk                          _UINT32_(0x010F0303)                                 /* (AES_PTCR) Register Mask  */


/* -------- AES_PTSR : (AES Offset: 0x124) ( R/ 32) Transfer Status Register -------- */
#define AES_PTSR_RXTEN_Pos                    _UINT32_(0)                                          /* (AES_PTSR) Receiver Transfer Enable Position */
#define AES_PTSR_RXTEN_Msk                    (_UINT32_(0x1) << AES_PTSR_RXTEN_Pos)                /* (AES_PTSR) Receiver Transfer Enable Mask */
#define AES_PTSR_RXTEN(value)                 (AES_PTSR_RXTEN_Msk & (_UINT32_(value) << AES_PTSR_RXTEN_Pos)) /* Assigment of value for RXTEN in the AES_PTSR register */
#define AES_PTSR_TXTEN_Pos                    _UINT32_(8)                                          /* (AES_PTSR) Transmitter Transfer Enable Position */
#define AES_PTSR_TXTEN_Msk                    (_UINT32_(0x1) << AES_PTSR_TXTEN_Pos)                /* (AES_PTSR) Transmitter Transfer Enable Mask */
#define AES_PTSR_TXTEN(value)                 (AES_PTSR_TXTEN_Msk & (_UINT32_(value) << AES_PTSR_TXTEN_Pos)) /* Assigment of value for TXTEN in the AES_PTSR register */
#define AES_PTSR_RXCBEN_Pos                   _UINT32_(16)                                         /* (AES_PTSR) Receiver Circular Buffer Enable Position */
#define AES_PTSR_RXCBEN_Msk                   (_UINT32_(0x1) << AES_PTSR_RXCBEN_Pos)               /* (AES_PTSR) Receiver Circular Buffer Enable Mask */
#define AES_PTSR_RXCBEN(value)                (AES_PTSR_RXCBEN_Msk & (_UINT32_(value) << AES_PTSR_RXCBEN_Pos)) /* Assigment of value for RXCBEN in the AES_PTSR register */
#define AES_PTSR_TXCBEN_Pos                   _UINT32_(18)                                         /* (AES_PTSR) Transmitter Circular Buffer Enable Position */
#define AES_PTSR_TXCBEN_Msk                   (_UINT32_(0x1) << AES_PTSR_TXCBEN_Pos)               /* (AES_PTSR) Transmitter Circular Buffer Enable Mask */
#define AES_PTSR_TXCBEN(value)                (AES_PTSR_TXCBEN_Msk & (_UINT32_(value) << AES_PTSR_TXCBEN_Pos)) /* Assigment of value for TXCBEN in the AES_PTSR register */
#define AES_PTSR_ERR_Pos                      _UINT32_(24)                                         /* (AES_PTSR) Transfer Bus Error Position */
#define AES_PTSR_ERR_Msk                      (_UINT32_(0x1) << AES_PTSR_ERR_Pos)                  /* (AES_PTSR) Transfer Bus Error Mask */
#define AES_PTSR_ERR(value)                   (AES_PTSR_ERR_Msk & (_UINT32_(value) << AES_PTSR_ERR_Pos)) /* Assigment of value for ERR in the AES_PTSR register */
#define AES_PTSR_Msk                          _UINT32_(0x01050101)                                 /* (AES_PTSR) Register Mask  */


/* -------- AES_PWPMR : (AES Offset: 0x128) (R/W 32) Write Protection Mode Register -------- */
#define AES_PWPMR_WPPTREN_Pos                 _UINT32_(0)                                          /* (AES_PWPMR) Write Protection Pointer Registers Enable Position */
#define AES_PWPMR_WPPTREN_Msk                 (_UINT32_(0x1) << AES_PWPMR_WPPTREN_Pos)             /* (AES_PWPMR) Write Protection Pointer Registers Enable Mask */
#define AES_PWPMR_WPPTREN(value)              (AES_PWPMR_WPPTREN_Msk & (_UINT32_(value) << AES_PWPMR_WPPTREN_Pos)) /* Assigment of value for WPPTREN in the AES_PWPMR register */
#define AES_PWPMR_WPCTREN_Pos                 _UINT32_(1)                                          /* (AES_PWPMR) Write Protection Counter Registers Enable Position */
#define AES_PWPMR_WPCTREN_Msk                 (_UINT32_(0x1) << AES_PWPMR_WPCTREN_Pos)             /* (AES_PWPMR) Write Protection Counter Registers Enable Mask */
#define AES_PWPMR_WPCTREN(value)              (AES_PWPMR_WPCTREN_Msk & (_UINT32_(value) << AES_PWPMR_WPCTREN_Pos)) /* Assigment of value for WPCTREN in the AES_PWPMR register */
#define AES_PWPMR_WPCREN_Pos                  _UINT32_(2)                                          /* (AES_PWPMR) Write Protection Control Register Enable Position */
#define AES_PWPMR_WPCREN_Msk                  (_UINT32_(0x1) << AES_PWPMR_WPCREN_Pos)              /* (AES_PWPMR) Write Protection Control Register Enable Mask */
#define AES_PWPMR_WPCREN(value)               (AES_PWPMR_WPCREN_Msk & (_UINT32_(value) << AES_PWPMR_WPCREN_Pos)) /* Assigment of value for WPCREN in the AES_PWPMR register */
#define AES_PWPMR_WPKEY_Pos                   _UINT32_(8)                                          /* (AES_PWPMR) Write Protection Key Position */
#define AES_PWPMR_WPKEY_Msk                   (_UINT32_(0xFFFFFF) << AES_PWPMR_WPKEY_Pos)          /* (AES_PWPMR) Write Protection Key Mask */
#define AES_PWPMR_WPKEY(value)                (AES_PWPMR_WPKEY_Msk & (_UINT32_(value) << AES_PWPMR_WPKEY_Pos)) /* Assigment of value for WPKEY in the AES_PWPMR register */
#define   AES_PWPMR_WPKEY_PASSWD_Val          _UINT32_(0x504443)                                   /* (AES_PWPMR) Writing any other value in this field aborts the write operation. Always reads as 0.  */
#define AES_PWPMR_WPKEY_PASSWD                (AES_PWPMR_WPKEY_PASSWD_Val << AES_PWPMR_WPKEY_Pos)  /* (AES_PWPMR) Writing any other value in this field aborts the write operation. Always reads as 0. Position  */
#define AES_PWPMR_Msk                         _UINT32_(0xFFFFFF07)                                 /* (AES_PWPMR) Register Mask  */


/** \brief AES register offsets definitions */
#define AES_CR_REG_OFST                _UINT32_(0x00)      /* (AES_CR) Control Register Offset */
#define AES_MR_REG_OFST                _UINT32_(0x04)      /* (AES_MR) Mode Register Offset */
#define AES_IER_REG_OFST               _UINT32_(0x10)      /* (AES_IER) Interrupt Enable Register Offset */
#define AES_IDR_REG_OFST               _UINT32_(0x14)      /* (AES_IDR) Interrupt Disable Register Offset */
#define AES_IMR_REG_OFST               _UINT32_(0x18)      /* (AES_IMR) Interrupt Mask Register Offset */
#define AES_ISR_REG_OFST               _UINT32_(0x1C)      /* (AES_ISR) Interrupt Status Register Offset */
#define AES_KEYWR_REG_OFST             _UINT32_(0x20)      /* (AES_KEYWR) Key Word Register Offset */
#define AES_KEYWR0_REG_OFST            _UINT32_(0x20)      /* (AES_KEYWR0) Key Word Register Offset */
#define AES_KEYWR1_REG_OFST            _UINT32_(0x24)      /* (AES_KEYWR1) Key Word Register Offset */
#define AES_KEYWR2_REG_OFST            _UINT32_(0x28)      /* (AES_KEYWR2) Key Word Register Offset */
#define AES_KEYWR3_REG_OFST            _UINT32_(0x2C)      /* (AES_KEYWR3) Key Word Register Offset */
#define AES_KEYWR4_REG_OFST            _UINT32_(0x30)      /* (AES_KEYWR4) Key Word Register Offset */
#define AES_KEYWR5_REG_OFST            _UINT32_(0x34)      /* (AES_KEYWR5) Key Word Register Offset */
#define AES_KEYWR6_REG_OFST            _UINT32_(0x38)      /* (AES_KEYWR6) Key Word Register Offset */
#define AES_KEYWR7_REG_OFST            _UINT32_(0x3C)      /* (AES_KEYWR7) Key Word Register Offset */
#define AES_IDATAR_REG_OFST            _UINT32_(0x40)      /* (AES_IDATAR) Input Data Register Offset */
#define AES_IDATAR0_REG_OFST           _UINT32_(0x40)      /* (AES_IDATAR0) Input Data Register Offset */
#define AES_IDATAR1_REG_OFST           _UINT32_(0x44)      /* (AES_IDATAR1) Input Data Register Offset */
#define AES_IDATAR2_REG_OFST           _UINT32_(0x48)      /* (AES_IDATAR2) Input Data Register Offset */
#define AES_IDATAR3_REG_OFST           _UINT32_(0x4C)      /* (AES_IDATAR3) Input Data Register Offset */
#define AES_ODATAR_REG_OFST            _UINT32_(0x50)      /* (AES_ODATAR) Output Data Register Offset */
#define AES_ODATAR0_REG_OFST           _UINT32_(0x50)      /* (AES_ODATAR0) Output Data Register Offset */
#define AES_ODATAR1_REG_OFST           _UINT32_(0x54)      /* (AES_ODATAR1) Output Data Register Offset */
#define AES_ODATAR2_REG_OFST           _UINT32_(0x58)      /* (AES_ODATAR2) Output Data Register Offset */
#define AES_ODATAR3_REG_OFST           _UINT32_(0x5C)      /* (AES_ODATAR3) Output Data Register Offset */
#define AES_IVR_REG_OFST               _UINT32_(0x60)      /* (AES_IVR) Initialization Vector Register Offset */
#define AES_IVR0_REG_OFST              _UINT32_(0x60)      /* (AES_IVR0) Initialization Vector Register Offset */
#define AES_IVR1_REG_OFST              _UINT32_(0x64)      /* (AES_IVR1) Initialization Vector Register Offset */
#define AES_IVR2_REG_OFST              _UINT32_(0x68)      /* (AES_IVR2) Initialization Vector Register Offset */
#define AES_IVR3_REG_OFST              _UINT32_(0x6C)      /* (AES_IVR3) Initialization Vector Register Offset */
#define AES_AADLENR_REG_OFST           _UINT32_(0x70)      /* (AES_AADLENR) Additional Authenticated Data Length Register Offset */
#define AES_CLENR_REG_OFST             _UINT32_(0x74)      /* (AES_CLENR) Plaintext/Ciphertext Length Register Offset */
#define AES_GHASHR_REG_OFST            _UINT32_(0x78)      /* (AES_GHASHR) GCM Intermediate Hash Word Register Offset */
#define AES_GHASHR0_REG_OFST           _UINT32_(0x78)      /* (AES_GHASHR0) GCM Intermediate Hash Word Register Offset */
#define AES_GHASHR1_REG_OFST           _UINT32_(0x7C)      /* (AES_GHASHR1) GCM Intermediate Hash Word Register Offset */
#define AES_GHASHR2_REG_OFST           _UINT32_(0x80)      /* (AES_GHASHR2) GCM Intermediate Hash Word Register Offset */
#define AES_GHASHR3_REG_OFST           _UINT32_(0x84)      /* (AES_GHASHR3) GCM Intermediate Hash Word Register Offset */
#define AES_TAGR_REG_OFST              _UINT32_(0x88)      /* (AES_TAGR) GCM Authentication Tag Word Register Offset */
#define AES_TAGR0_REG_OFST             _UINT32_(0x88)      /* (AES_TAGR0) GCM Authentication Tag Word Register Offset */
#define AES_TAGR1_REG_OFST             _UINT32_(0x8C)      /* (AES_TAGR1) GCM Authentication Tag Word Register Offset */
#define AES_TAGR2_REG_OFST             _UINT32_(0x90)      /* (AES_TAGR2) GCM Authentication Tag Word Register Offset */
#define AES_TAGR3_REG_OFST             _UINT32_(0x94)      /* (AES_TAGR3) GCM Authentication Tag Word Register Offset */
#define AES_CTRR_REG_OFST              _UINT32_(0x98)      /* (AES_CTRR) GCM Encryption Counter Value Register Offset */
#define AES_GCMHR_REG_OFST             _UINT32_(0x9C)      /* (AES_GCMHR) GCM H Word Register Offset */
#define AES_GCMHR0_REG_OFST            _UINT32_(0x9C)      /* (AES_GCMHR0) GCM H Word Register Offset */
#define AES_GCMHR1_REG_OFST            _UINT32_(0xA0)      /* (AES_GCMHR1) GCM H Word Register Offset */
#define AES_GCMHR2_REG_OFST            _UINT32_(0xA4)      /* (AES_GCMHR2) GCM H Word Register Offset */
#define AES_GCMHR3_REG_OFST            _UINT32_(0xA8)      /* (AES_GCMHR3) GCM H Word Register Offset */
#define AES_EMR_REG_OFST               _UINT32_(0xB0)      /* (AES_EMR) Extended Mode Register Offset */
#define AES_BCNT_REG_OFST              _UINT32_(0xB4)      /* (AES_BCNT) Byte Counter Register Offset */
#define AES_WPMR_REG_OFST              _UINT32_(0xE4)      /* (AES_WPMR) Write Protection Mode Register Offset */
#define AES_WPSR_REG_OFST              _UINT32_(0xE8)      /* (AES_WPSR) Write Protection Status Register Offset */
#define AES_RPR_REG_OFST               _UINT32_(0x100)     /* (AES_RPR) Receive Pointer Register Offset */
#define AES_RCR_REG_OFST               _UINT32_(0x104)     /* (AES_RCR) Receive Counter Register Offset */
#define AES_TPR_REG_OFST               _UINT32_(0x108)     /* (AES_TPR) Transmit Pointer Register Offset */
#define AES_TCR_REG_OFST               _UINT32_(0x10C)     /* (AES_TCR) Transmit Counter Register Offset */
#define AES_RNPR_REG_OFST              _UINT32_(0x110)     /* (AES_RNPR) Receive Next Pointer Register Offset */
#define AES_RNCR_REG_OFST              _UINT32_(0x114)     /* (AES_RNCR) Receive Next Counter Register Offset */
#define AES_TNPR_REG_OFST              _UINT32_(0x118)     /* (AES_TNPR) Transmit Next Pointer Register Offset */
#define AES_TNCR_REG_OFST              _UINT32_(0x11C)     /* (AES_TNCR) Transmit Next Counter Register Offset */
#define AES_PTCR_REG_OFST              _UINT32_(0x120)     /* (AES_PTCR) Transfer Control Register Offset */
#define AES_PTSR_REG_OFST              _UINT32_(0x124)     /* (AES_PTSR) Transfer Status Register Offset */
#define AES_PWPMR_REG_OFST             _UINT32_(0x128)     /* (AES_PWPMR) Write Protection Mode Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief AES register API structure */
typedef struct
{
  __O   uint32_t                       AES_CR;             /**< Offset: 0x00 ( /W  32) Control Register */
  __IO  uint32_t                       AES_MR;             /**< Offset: 0x04 (R/W  32) Mode Register */
  __I   uint8_t                        Reserved1[0x08];
  __O   uint32_t                       AES_IER;            /**< Offset: 0x10 ( /W  32) Interrupt Enable Register */
  __O   uint32_t                       AES_IDR;            /**< Offset: 0x14 ( /W  32) Interrupt Disable Register */
  __I   uint32_t                       AES_IMR;            /**< Offset: 0x18 (R/   32) Interrupt Mask Register */
  __I   uint32_t                       AES_ISR;            /**< Offset: 0x1C (R/   32) Interrupt Status Register */
  __O   uint32_t                       AES_KEYWR[8];       /**< Offset: 0x20 ( /W  32) Key Word Register */
  __O   uint32_t                       AES_IDATAR[4];      /**< Offset: 0x40 ( /W  32) Input Data Register */
  __I   uint32_t                       AES_ODATAR[4];      /**< Offset: 0x50 (R/   32) Output Data Register */
  __O   uint32_t                       AES_IVR[4];         /**< Offset: 0x60 ( /W  32) Initialization Vector Register */
  __IO  uint32_t                       AES_AADLENR;        /**< Offset: 0x70 (R/W  32) Additional Authenticated Data Length Register */
  __IO  uint32_t                       AES_CLENR;          /**< Offset: 0x74 (R/W  32) Plaintext/Ciphertext Length Register */
  __IO  uint32_t                       AES_GHASHR[4];      /**< Offset: 0x78 (R/W  32) GCM Intermediate Hash Word Register */
  __I   uint32_t                       AES_TAGR[4];        /**< Offset: 0x88 (R/   32) GCM Authentication Tag Word Register */
  __I   uint32_t                       AES_CTRR;           /**< Offset: 0x98 (R/   32) GCM Encryption Counter Value Register */
  __IO  uint32_t                       AES_GCMHR[4];       /**< Offset: 0x9C (R/W  32) GCM H Word Register */
  __I   uint8_t                        Reserved2[0x04];
  __IO  uint32_t                       AES_EMR;            /**< Offset: 0xB0 (R/W  32) Extended Mode Register */
  __IO  uint32_t                       AES_BCNT;           /**< Offset: 0xB4 (R/W  32) Byte Counter Register */
  __I   uint8_t                        Reserved3[0x2C];
  __IO  uint32_t                       AES_WPMR;           /**< Offset: 0xE4 (R/W  32) Write Protection Mode Register */
  __I   uint32_t                       AES_WPSR;           /**< Offset: 0xE8 (R/   32) Write Protection Status Register */
  __I   uint8_t                        Reserved4[0x14];
  __IO  uint32_t                       AES_RPR;            /**< Offset: 0x100 (R/W  32) Receive Pointer Register */
  __IO  uint32_t                       AES_RCR;            /**< Offset: 0x104 (R/W  32) Receive Counter Register */
  __IO  uint32_t                       AES_TPR;            /**< Offset: 0x108 (R/W  32) Transmit Pointer Register */
  __IO  uint32_t                       AES_TCR;            /**< Offset: 0x10C (R/W  32) Transmit Counter Register */
  __IO  uint32_t                       AES_RNPR;           /**< Offset: 0x110 (R/W  32) Receive Next Pointer Register */
  __IO  uint32_t                       AES_RNCR;           /**< Offset: 0x114 (R/W  32) Receive Next Counter Register */
  __IO  uint32_t                       AES_TNPR;           /**< Offset: 0x118 (R/W  32) Transmit Next Pointer Register */
  __IO  uint32_t                       AES_TNCR;           /**< Offset: 0x11C (R/W  32) Transmit Next Counter Register */
  __O   uint32_t                       AES_PTCR;           /**< Offset: 0x120 ( /W  32) Transfer Control Register */
  __I   uint32_t                       AES_PTSR;           /**< Offset: 0x124 (R/   32) Transfer Status Register */
  __IO  uint32_t                       AES_PWPMR;          /**< Offset: 0x128 (R/W  32) Write Protection Mode Register */
} aes_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CXMTG_AES_COMPONENT_H_ */
