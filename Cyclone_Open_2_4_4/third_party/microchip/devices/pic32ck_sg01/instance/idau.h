/*
 * Instance header file for PIC32CK2051SG01144
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

/* file generated from device description version 2023-02-20T18:48:58Z */
#ifndef _PIC32CKSG01_IDAU_INSTANCE_
#define _PIC32CKSG01_IDAU_INSTANCE_


/* ========== Instance Parameter definitions for IDAU peripheral ========== */
#define IDAU_GRANULARITY_ANS                     (0x1000)   /* Application Non-Secure region granularity */
#define IDAU_GRANULARITY_ANSC                    (0x1000)   /* Application Non-Secure Callable region granularity */
#define IDAU_GRANULARITY_AS                      (0x1000)   /* Application Secure region granularity */
#define IDAU_GRANULARITY_BNSC                    (0x1000)   /* Boot Flash Non-Secure Callable region granularity */
#define IDAU_GRANULARITY_BOOTPROT                (0x1000)   /* BOOTPROT region granularity */
#define IDAU_GRANULARITY_BS                      (0x1000)   /* Boot Flash Secure region granularity */
#define IDAU_GRANULARITY_RNS                     (0x1000)   /* RAM Non-Secure region granularity */
#define IDAU_GRANULARITY_RS                      (0x1000)   /* RAM Secure region granularity */
#define IDAU_INSTANCE_ID                         (38)       /* Instance index for IDAU */
#define IDAU_MCLK_ID_APB                         (69)       /* Index for IDAU APB clock */
#define IDAU_PAC_ID                              (38)       /* Index for IDAU registers write protection */
#define IDAU_REGION_ANS                          (0x0A)     /* Application Non-Secure region ID */
#define IDAU_REGION_ANSC                         (0x09)     /* Application Non-Secure Callable region ID */
#define IDAU_REGION_AS                           (0x08)     /* Application Secure region ID */
#define IDAU_REGION_BNSC                         (0x06)     /* Boot Flash Non-Secure Callable region ID */
#define IDAU_REGION_BOOTROM                      (0x04)     /* Boot ROM region ID */
#define IDAU_REGION_BS                           (0x05)     /* Boot Flash Secure region ID */
#define IDAU_REGION_CFMS                         (0x07)     /* CONFIGURATION Flash Secure region ID */
#define IDAU_REGION_CMCCDS                       (0x01)     /* CMCC DATA RAM Secure region ID */
#define IDAU_REGION_CMCCTS                       (0x02)     /* CMCC TAG RAM Secure region ID */
#define IDAU_REGION_CMCCVS                       (0x03)     /* CMCC VALID RAM Secure region ID */
#define IDAU_REGION_HPB0                         (0x0F)     /* Peripheral Bus A region ID */
#define IDAU_REGION_HPB1                         (0x10)     /* Peripheral Bus B region ID */
#define IDAU_REGION_HPB2                         (0x11)     /* Peripheral Bus C region ID */
#define IDAU_REGION_HSM                          (0x13)     /* HSM region ID */
#define IDAU_REGION_OTHER                        (0x00)     /* Other region ID */
#define IDAU_REGION_RNS                          (0x0E)     /* RAM Non-Secure region ID */
#define IDAU_REGION_RS                           (0x0D)     /* RAM Secure region ID */
#define IDAU_REGION_USBHS                        (0x12)     /* USB SFR region ID */

#endif /* _PIC32CKSG01_IDAU_INSTANCE_ */
