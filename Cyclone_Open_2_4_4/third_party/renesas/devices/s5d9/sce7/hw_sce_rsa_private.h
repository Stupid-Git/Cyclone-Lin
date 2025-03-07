/***********************************************************************************************************************
 * Copyright [2020-2021] Renesas Electronics Corporation and/or its affiliates.  All Rights Reserved.
 *
 * This software and documentation are supplied by Renesas Electronics America Inc. and may only be used with products
 * of Renesas Electronics Corp. and its affiliates ("Renesas").  No other uses are authorized.  Renesas products are
 * sold pursuant to Renesas terms and conditions of sale.  Purchasers are solely responsible for the selection and use
 * of Renesas products and Renesas assumes no liability.  No license, express or implied, to any intellectual property
 * right is granted by Renesas. This software is protected under all applicable laws, including copyright laws. Renesas
 * reserves the right to change or discontinue this software and/or this documentation. THE SOFTWARE AND DOCUMENTATION
 * IS DELIVERED TO YOU "AS IS," AND RENESAS MAKES NO REPRESENTATIONS OR WARRANTIES, AND TO THE FULLEST EXTENT
 * PERMISSIBLE UNDER APPLICABLE LAW, DISCLAIMS ALL WARRANTIES, WHETHER EXPLICITLY OR IMPLICITLY, INCLUDING WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NONINFRINGEMENT, WITH RESPECT TO THE SOFTWARE OR
 * DOCUMENTATION.  RENESAS SHALL HAVE NO LIABILITY ARISING OUT OF ANY SECURITY VULNERABILITY OR BREACH.  TO THE MAXIMUM
 * EXTENT PERMITTED BY LAW, IN NO EVENT WILL RENESAS BE LIABLE TO YOU IN CONNECTION WITH THE SOFTWARE OR DOCUMENTATION
 * (OR ANY PERSON OR ENTITY CLAIMING RIGHTS DERIVED FROM YOU) FOR ANY LOSS, DAMAGES, OR CLAIMS WHATSOEVER, INCLUDING,
 * WITHOUT LIMITATION, ANY DIRECT, CONSEQUENTIAL, SPECIAL, INDIRECT, PUNITIVE, OR INCIDENTAL DAMAGES; ANY LOST PROFITS,
 * OTHER ECONOMIC DAMAGE, PROPERTY DAMAGE, OR PERSONAL INJURY; AND EVEN IF RENESAS HAS BEEN ADVISED OF THE POSSIBILITY
 * OF SUCH LOSS, DAMAGES, CLAIMS OR COSTS.
 **********************************************************************************************************************/

#ifndef HW_SCE_RSA_PRIVATE_H
#define HW_SCE_RSA_PRIVATE_H

/**********************************************************************************************************************
 * Includes
 ***********************************************************************************************************************/
#include "hw_sce_common.h"

ssp_err_t HW_SCE_RSA_1024PublicEncrypt(uint32_t         reserved,
                                       const uint32_t * InData_Text,
                                       const uint32_t * InData_PublicKey,
                                       const uint32_t * InData_N,
                                       uint32_t       * OutData_Text);

ssp_err_t HW_SCE_RSA_1024PrivateKeyDecrypt(uint32_t         reserved,
                                           const uint32_t * InData_Text,
                                           const uint32_t * InData_PrivateKey,
                                           const uint32_t * InData_N,
                                           uint32_t       * OutData_Text);

ssp_err_t HW_SCE_RSA_1024KeyGenerate(uint32_t   num_tries,
                                     uint32_t * OutData_PrivateKey,
                                     uint32_t * OutData_N,
                                     uint32_t * OutData_DomainParam);

ssp_err_t HW_SCE_RSA_2048PublicEncrypt(uint32_t         reserved,
                                       const uint32_t * InData_Text,
                                       const uint32_t * InData_PublicKey,
                                       const uint32_t * InData_N,
                                       uint32_t       * OutData_Text);

ssp_err_t HW_SCE_RSA_2048PrivateKeyDecrypt(uint32_t         reserved,
                                           const uint32_t * InData_Text,
                                           const uint32_t * InData_PrivateKey,
                                           const uint32_t * InData_N,
                                           uint32_t       * OutData_Text);

ssp_err_t HW_SCE_RSA_2048KeyGenerate(uint32_t   num_tries,
                                     uint32_t * OutData_PrivateKey,
                                     uint32_t * OutData_N,
                                     uint32_t * OutData_DomainParam);

ssp_err_t HW_SCE_HRK_RSA_2048KeyGenerate(uint32_t   num_tries,
                                         uint32_t * OutData_KeyIndex,
                                         uint32_t * OutData_N,
                                         uint32_t * OutData_DomainParam);

ssp_err_t HW_SCE_HRK_RSA_2048PrivateKeyDecrypt(const uint32_t * InData_Text,
                                               const uint32_t * InData_KeyIndex,
                                               const uint32_t * InData_N,
                                               uint32_t       * OutData_Text);

#endif                                 /* HW_SCE_RSA_PRIVATE_H */
