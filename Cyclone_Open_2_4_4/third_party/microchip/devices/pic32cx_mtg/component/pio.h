/*
 * Component description for PIO
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
#ifndef _PIC32CXMTG_PIO_COMPONENT_H_
#define _PIC32CXMTG_PIO_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR PIO                                          */
/* ************************************************************************** */

/* -------- PIO_MSKR : (PIO Offset: 0x00) (R/W 32) PIO Mask Register -------- */
#define PIO_MSKR_MSK0_Pos                     _UINT32_(0)                                          /* (PIO_MSKR) PIO Line 0 Mask Position */
#define PIO_MSKR_MSK0_Msk                     (_UINT32_(0x1) << PIO_MSKR_MSK0_Pos)                 /* (PIO_MSKR) PIO Line 0 Mask Mask */
#define PIO_MSKR_MSK0(value)                  (PIO_MSKR_MSK0_Msk & (_UINT32_(value) << PIO_MSKR_MSK0_Pos)) /* Assigment of value for MSK0 in the PIO_MSKR register */
#define   PIO_MSKR_MSK0_DISABLED_Val          _UINT32_(0x0)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_MSKR_MSK0_ENABLED_Val           _UINT32_(0x1)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration.  */
#define PIO_MSKR_MSK0_DISABLED                (PIO_MSKR_MSK0_DISABLED_Val << PIO_MSKR_MSK0_Pos)    /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK0_ENABLED                 (PIO_MSKR_MSK0_ENABLED_Val << PIO_MSKR_MSK0_Pos)     /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK1_Pos                     _UINT32_(1)                                          /* (PIO_MSKR) PIO Line 1 Mask Position */
#define PIO_MSKR_MSK1_Msk                     (_UINT32_(0x1) << PIO_MSKR_MSK1_Pos)                 /* (PIO_MSKR) PIO Line 1 Mask Mask */
#define PIO_MSKR_MSK1(value)                  (PIO_MSKR_MSK1_Msk & (_UINT32_(value) << PIO_MSKR_MSK1_Pos)) /* Assigment of value for MSK1 in the PIO_MSKR register */
#define   PIO_MSKR_MSK1_DISABLED_Val          _UINT32_(0x0)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_MSKR_MSK1_ENABLED_Val           _UINT32_(0x1)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration.  */
#define PIO_MSKR_MSK1_DISABLED                (PIO_MSKR_MSK1_DISABLED_Val << PIO_MSKR_MSK1_Pos)    /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK1_ENABLED                 (PIO_MSKR_MSK1_ENABLED_Val << PIO_MSKR_MSK1_Pos)     /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK2_Pos                     _UINT32_(2)                                          /* (PIO_MSKR) PIO Line 2 Mask Position */
#define PIO_MSKR_MSK2_Msk                     (_UINT32_(0x1) << PIO_MSKR_MSK2_Pos)                 /* (PIO_MSKR) PIO Line 2 Mask Mask */
#define PIO_MSKR_MSK2(value)                  (PIO_MSKR_MSK2_Msk & (_UINT32_(value) << PIO_MSKR_MSK2_Pos)) /* Assigment of value for MSK2 in the PIO_MSKR register */
#define   PIO_MSKR_MSK2_DISABLED_Val          _UINT32_(0x0)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_MSKR_MSK2_ENABLED_Val           _UINT32_(0x1)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration.  */
#define PIO_MSKR_MSK2_DISABLED                (PIO_MSKR_MSK2_DISABLED_Val << PIO_MSKR_MSK2_Pos)    /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK2_ENABLED                 (PIO_MSKR_MSK2_ENABLED_Val << PIO_MSKR_MSK2_Pos)     /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK3_Pos                     _UINT32_(3)                                          /* (PIO_MSKR) PIO Line 3 Mask Position */
#define PIO_MSKR_MSK3_Msk                     (_UINT32_(0x1) << PIO_MSKR_MSK3_Pos)                 /* (PIO_MSKR) PIO Line 3 Mask Mask */
#define PIO_MSKR_MSK3(value)                  (PIO_MSKR_MSK3_Msk & (_UINT32_(value) << PIO_MSKR_MSK3_Pos)) /* Assigment of value for MSK3 in the PIO_MSKR register */
#define   PIO_MSKR_MSK3_DISABLED_Val          _UINT32_(0x0)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_MSKR_MSK3_ENABLED_Val           _UINT32_(0x1)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration.  */
#define PIO_MSKR_MSK3_DISABLED                (PIO_MSKR_MSK3_DISABLED_Val << PIO_MSKR_MSK3_Pos)    /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK3_ENABLED                 (PIO_MSKR_MSK3_ENABLED_Val << PIO_MSKR_MSK3_Pos)     /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK4_Pos                     _UINT32_(4)                                          /* (PIO_MSKR) PIO Line 4 Mask Position */
#define PIO_MSKR_MSK4_Msk                     (_UINT32_(0x1) << PIO_MSKR_MSK4_Pos)                 /* (PIO_MSKR) PIO Line 4 Mask Mask */
#define PIO_MSKR_MSK4(value)                  (PIO_MSKR_MSK4_Msk & (_UINT32_(value) << PIO_MSKR_MSK4_Pos)) /* Assigment of value for MSK4 in the PIO_MSKR register */
#define   PIO_MSKR_MSK4_DISABLED_Val          _UINT32_(0x0)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_MSKR_MSK4_ENABLED_Val           _UINT32_(0x1)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration.  */
#define PIO_MSKR_MSK4_DISABLED                (PIO_MSKR_MSK4_DISABLED_Val << PIO_MSKR_MSK4_Pos)    /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK4_ENABLED                 (PIO_MSKR_MSK4_ENABLED_Val << PIO_MSKR_MSK4_Pos)     /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK5_Pos                     _UINT32_(5)                                          /* (PIO_MSKR) PIO Line 5 Mask Position */
#define PIO_MSKR_MSK5_Msk                     (_UINT32_(0x1) << PIO_MSKR_MSK5_Pos)                 /* (PIO_MSKR) PIO Line 5 Mask Mask */
#define PIO_MSKR_MSK5(value)                  (PIO_MSKR_MSK5_Msk & (_UINT32_(value) << PIO_MSKR_MSK5_Pos)) /* Assigment of value for MSK5 in the PIO_MSKR register */
#define   PIO_MSKR_MSK5_DISABLED_Val          _UINT32_(0x0)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_MSKR_MSK5_ENABLED_Val           _UINT32_(0x1)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration.  */
#define PIO_MSKR_MSK5_DISABLED                (PIO_MSKR_MSK5_DISABLED_Val << PIO_MSKR_MSK5_Pos)    /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK5_ENABLED                 (PIO_MSKR_MSK5_ENABLED_Val << PIO_MSKR_MSK5_Pos)     /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK6_Pos                     _UINT32_(6)                                          /* (PIO_MSKR) PIO Line 6 Mask Position */
#define PIO_MSKR_MSK6_Msk                     (_UINT32_(0x1) << PIO_MSKR_MSK6_Pos)                 /* (PIO_MSKR) PIO Line 6 Mask Mask */
#define PIO_MSKR_MSK6(value)                  (PIO_MSKR_MSK6_Msk & (_UINT32_(value) << PIO_MSKR_MSK6_Pos)) /* Assigment of value for MSK6 in the PIO_MSKR register */
#define   PIO_MSKR_MSK6_DISABLED_Val          _UINT32_(0x0)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_MSKR_MSK6_ENABLED_Val           _UINT32_(0x1)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration.  */
#define PIO_MSKR_MSK6_DISABLED                (PIO_MSKR_MSK6_DISABLED_Val << PIO_MSKR_MSK6_Pos)    /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK6_ENABLED                 (PIO_MSKR_MSK6_ENABLED_Val << PIO_MSKR_MSK6_Pos)     /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK7_Pos                     _UINT32_(7)                                          /* (PIO_MSKR) PIO Line 7 Mask Position */
#define PIO_MSKR_MSK7_Msk                     (_UINT32_(0x1) << PIO_MSKR_MSK7_Pos)                 /* (PIO_MSKR) PIO Line 7 Mask Mask */
#define PIO_MSKR_MSK7(value)                  (PIO_MSKR_MSK7_Msk & (_UINT32_(value) << PIO_MSKR_MSK7_Pos)) /* Assigment of value for MSK7 in the PIO_MSKR register */
#define   PIO_MSKR_MSK7_DISABLED_Val          _UINT32_(0x0)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_MSKR_MSK7_ENABLED_Val           _UINT32_(0x1)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration.  */
#define PIO_MSKR_MSK7_DISABLED                (PIO_MSKR_MSK7_DISABLED_Val << PIO_MSKR_MSK7_Pos)    /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK7_ENABLED                 (PIO_MSKR_MSK7_ENABLED_Val << PIO_MSKR_MSK7_Pos)     /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK8_Pos                     _UINT32_(8)                                          /* (PIO_MSKR) PIO Line 8 Mask Position */
#define PIO_MSKR_MSK8_Msk                     (_UINT32_(0x1) << PIO_MSKR_MSK8_Pos)                 /* (PIO_MSKR) PIO Line 8 Mask Mask */
#define PIO_MSKR_MSK8(value)                  (PIO_MSKR_MSK8_Msk & (_UINT32_(value) << PIO_MSKR_MSK8_Pos)) /* Assigment of value for MSK8 in the PIO_MSKR register */
#define   PIO_MSKR_MSK8_DISABLED_Val          _UINT32_(0x0)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_MSKR_MSK8_ENABLED_Val           _UINT32_(0x1)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration.  */
#define PIO_MSKR_MSK8_DISABLED                (PIO_MSKR_MSK8_DISABLED_Val << PIO_MSKR_MSK8_Pos)    /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK8_ENABLED                 (PIO_MSKR_MSK8_ENABLED_Val << PIO_MSKR_MSK8_Pos)     /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK9_Pos                     _UINT32_(9)                                          /* (PIO_MSKR) PIO Line 9 Mask Position */
#define PIO_MSKR_MSK9_Msk                     (_UINT32_(0x1) << PIO_MSKR_MSK9_Pos)                 /* (PIO_MSKR) PIO Line 9 Mask Mask */
#define PIO_MSKR_MSK9(value)                  (PIO_MSKR_MSK9_Msk & (_UINT32_(value) << PIO_MSKR_MSK9_Pos)) /* Assigment of value for MSK9 in the PIO_MSKR register */
#define   PIO_MSKR_MSK9_DISABLED_Val          _UINT32_(0x0)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_MSKR_MSK9_ENABLED_Val           _UINT32_(0x1)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration.  */
#define PIO_MSKR_MSK9_DISABLED                (PIO_MSKR_MSK9_DISABLED_Val << PIO_MSKR_MSK9_Pos)    /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK9_ENABLED                 (PIO_MSKR_MSK9_ENABLED_Val << PIO_MSKR_MSK9_Pos)     /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK10_Pos                    _UINT32_(10)                                         /* (PIO_MSKR) PIO Line 10 Mask Position */
#define PIO_MSKR_MSK10_Msk                    (_UINT32_(0x1) << PIO_MSKR_MSK10_Pos)                /* (PIO_MSKR) PIO Line 10 Mask Mask */
#define PIO_MSKR_MSK10(value)                 (PIO_MSKR_MSK10_Msk & (_UINT32_(value) << PIO_MSKR_MSK10_Pos)) /* Assigment of value for MSK10 in the PIO_MSKR register */
#define   PIO_MSKR_MSK10_DISABLED_Val         _UINT32_(0x0)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_MSKR_MSK10_ENABLED_Val          _UINT32_(0x1)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration.  */
#define PIO_MSKR_MSK10_DISABLED               (PIO_MSKR_MSK10_DISABLED_Val << PIO_MSKR_MSK10_Pos)  /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK10_ENABLED                (PIO_MSKR_MSK10_ENABLED_Val << PIO_MSKR_MSK10_Pos)   /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK11_Pos                    _UINT32_(11)                                         /* (PIO_MSKR) PIO Line 11 Mask Position */
#define PIO_MSKR_MSK11_Msk                    (_UINT32_(0x1) << PIO_MSKR_MSK11_Pos)                /* (PIO_MSKR) PIO Line 11 Mask Mask */
#define PIO_MSKR_MSK11(value)                 (PIO_MSKR_MSK11_Msk & (_UINT32_(value) << PIO_MSKR_MSK11_Pos)) /* Assigment of value for MSK11 in the PIO_MSKR register */
#define   PIO_MSKR_MSK11_DISABLED_Val         _UINT32_(0x0)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_MSKR_MSK11_ENABLED_Val          _UINT32_(0x1)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration.  */
#define PIO_MSKR_MSK11_DISABLED               (PIO_MSKR_MSK11_DISABLED_Val << PIO_MSKR_MSK11_Pos)  /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK11_ENABLED                (PIO_MSKR_MSK11_ENABLED_Val << PIO_MSKR_MSK11_Pos)   /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK12_Pos                    _UINT32_(12)                                         /* (PIO_MSKR) PIO Line 12 Mask Position */
#define PIO_MSKR_MSK12_Msk                    (_UINT32_(0x1) << PIO_MSKR_MSK12_Pos)                /* (PIO_MSKR) PIO Line 12 Mask Mask */
#define PIO_MSKR_MSK12(value)                 (PIO_MSKR_MSK12_Msk & (_UINT32_(value) << PIO_MSKR_MSK12_Pos)) /* Assigment of value for MSK12 in the PIO_MSKR register */
#define   PIO_MSKR_MSK12_DISABLED_Val         _UINT32_(0x0)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_MSKR_MSK12_ENABLED_Val          _UINT32_(0x1)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration.  */
#define PIO_MSKR_MSK12_DISABLED               (PIO_MSKR_MSK12_DISABLED_Val << PIO_MSKR_MSK12_Pos)  /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK12_ENABLED                (PIO_MSKR_MSK12_ENABLED_Val << PIO_MSKR_MSK12_Pos)   /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK13_Pos                    _UINT32_(13)                                         /* (PIO_MSKR) PIO Line 13 Mask Position */
#define PIO_MSKR_MSK13_Msk                    (_UINT32_(0x1) << PIO_MSKR_MSK13_Pos)                /* (PIO_MSKR) PIO Line 13 Mask Mask */
#define PIO_MSKR_MSK13(value)                 (PIO_MSKR_MSK13_Msk & (_UINT32_(value) << PIO_MSKR_MSK13_Pos)) /* Assigment of value for MSK13 in the PIO_MSKR register */
#define   PIO_MSKR_MSK13_DISABLED_Val         _UINT32_(0x0)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_MSKR_MSK13_ENABLED_Val          _UINT32_(0x1)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration.  */
#define PIO_MSKR_MSK13_DISABLED               (PIO_MSKR_MSK13_DISABLED_Val << PIO_MSKR_MSK13_Pos)  /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK13_ENABLED                (PIO_MSKR_MSK13_ENABLED_Val << PIO_MSKR_MSK13_Pos)   /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK14_Pos                    _UINT32_(14)                                         /* (PIO_MSKR) PIO Line 14 Mask Position */
#define PIO_MSKR_MSK14_Msk                    (_UINT32_(0x1) << PIO_MSKR_MSK14_Pos)                /* (PIO_MSKR) PIO Line 14 Mask Mask */
#define PIO_MSKR_MSK14(value)                 (PIO_MSKR_MSK14_Msk & (_UINT32_(value) << PIO_MSKR_MSK14_Pos)) /* Assigment of value for MSK14 in the PIO_MSKR register */
#define   PIO_MSKR_MSK14_DISABLED_Val         _UINT32_(0x0)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_MSKR_MSK14_ENABLED_Val          _UINT32_(0x1)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration.  */
#define PIO_MSKR_MSK14_DISABLED               (PIO_MSKR_MSK14_DISABLED_Val << PIO_MSKR_MSK14_Pos)  /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK14_ENABLED                (PIO_MSKR_MSK14_ENABLED_Val << PIO_MSKR_MSK14_Pos)   /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK15_Pos                    _UINT32_(15)                                         /* (PIO_MSKR) PIO Line 15 Mask Position */
#define PIO_MSKR_MSK15_Msk                    (_UINT32_(0x1) << PIO_MSKR_MSK15_Pos)                /* (PIO_MSKR) PIO Line 15 Mask Mask */
#define PIO_MSKR_MSK15(value)                 (PIO_MSKR_MSK15_Msk & (_UINT32_(value) << PIO_MSKR_MSK15_Pos)) /* Assigment of value for MSK15 in the PIO_MSKR register */
#define   PIO_MSKR_MSK15_DISABLED_Val         _UINT32_(0x0)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_MSKR_MSK15_ENABLED_Val          _UINT32_(0x1)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration.  */
#define PIO_MSKR_MSK15_DISABLED               (PIO_MSKR_MSK15_DISABLED_Val << PIO_MSKR_MSK15_Pos)  /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK15_ENABLED                (PIO_MSKR_MSK15_ENABLED_Val << PIO_MSKR_MSK15_Pos)   /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK16_Pos                    _UINT32_(16)                                         /* (PIO_MSKR) PIO Line 16 Mask Position */
#define PIO_MSKR_MSK16_Msk                    (_UINT32_(0x1) << PIO_MSKR_MSK16_Pos)                /* (PIO_MSKR) PIO Line 16 Mask Mask */
#define PIO_MSKR_MSK16(value)                 (PIO_MSKR_MSK16_Msk & (_UINT32_(value) << PIO_MSKR_MSK16_Pos)) /* Assigment of value for MSK16 in the PIO_MSKR register */
#define   PIO_MSKR_MSK16_DISABLED_Val         _UINT32_(0x0)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_MSKR_MSK16_ENABLED_Val          _UINT32_(0x1)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration.  */
#define PIO_MSKR_MSK16_DISABLED               (PIO_MSKR_MSK16_DISABLED_Val << PIO_MSKR_MSK16_Pos)  /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK16_ENABLED                (PIO_MSKR_MSK16_ENABLED_Val << PIO_MSKR_MSK16_Pos)   /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK17_Pos                    _UINT32_(17)                                         /* (PIO_MSKR) PIO Line 17 Mask Position */
#define PIO_MSKR_MSK17_Msk                    (_UINT32_(0x1) << PIO_MSKR_MSK17_Pos)                /* (PIO_MSKR) PIO Line 17 Mask Mask */
#define PIO_MSKR_MSK17(value)                 (PIO_MSKR_MSK17_Msk & (_UINT32_(value) << PIO_MSKR_MSK17_Pos)) /* Assigment of value for MSK17 in the PIO_MSKR register */
#define   PIO_MSKR_MSK17_DISABLED_Val         _UINT32_(0x0)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_MSKR_MSK17_ENABLED_Val          _UINT32_(0x1)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration.  */
#define PIO_MSKR_MSK17_DISABLED               (PIO_MSKR_MSK17_DISABLED_Val << PIO_MSKR_MSK17_Pos)  /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK17_ENABLED                (PIO_MSKR_MSK17_ENABLED_Val << PIO_MSKR_MSK17_Pos)   /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK18_Pos                    _UINT32_(18)                                         /* (PIO_MSKR) PIO Line 18 Mask Position */
#define PIO_MSKR_MSK18_Msk                    (_UINT32_(0x1) << PIO_MSKR_MSK18_Pos)                /* (PIO_MSKR) PIO Line 18 Mask Mask */
#define PIO_MSKR_MSK18(value)                 (PIO_MSKR_MSK18_Msk & (_UINT32_(value) << PIO_MSKR_MSK18_Pos)) /* Assigment of value for MSK18 in the PIO_MSKR register */
#define   PIO_MSKR_MSK18_DISABLED_Val         _UINT32_(0x0)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_MSKR_MSK18_ENABLED_Val          _UINT32_(0x1)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration.  */
#define PIO_MSKR_MSK18_DISABLED               (PIO_MSKR_MSK18_DISABLED_Val << PIO_MSKR_MSK18_Pos)  /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK18_ENABLED                (PIO_MSKR_MSK18_ENABLED_Val << PIO_MSKR_MSK18_Pos)   /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK19_Pos                    _UINT32_(19)                                         /* (PIO_MSKR) PIO Line 19 Mask Position */
#define PIO_MSKR_MSK19_Msk                    (_UINT32_(0x1) << PIO_MSKR_MSK19_Pos)                /* (PIO_MSKR) PIO Line 19 Mask Mask */
#define PIO_MSKR_MSK19(value)                 (PIO_MSKR_MSK19_Msk & (_UINT32_(value) << PIO_MSKR_MSK19_Pos)) /* Assigment of value for MSK19 in the PIO_MSKR register */
#define   PIO_MSKR_MSK19_DISABLED_Val         _UINT32_(0x0)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_MSKR_MSK19_ENABLED_Val          _UINT32_(0x1)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration.  */
#define PIO_MSKR_MSK19_DISABLED               (PIO_MSKR_MSK19_DISABLED_Val << PIO_MSKR_MSK19_Pos)  /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK19_ENABLED                (PIO_MSKR_MSK19_ENABLED_Val << PIO_MSKR_MSK19_Pos)   /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK20_Pos                    _UINT32_(20)                                         /* (PIO_MSKR) PIO Line 20 Mask Position */
#define PIO_MSKR_MSK20_Msk                    (_UINT32_(0x1) << PIO_MSKR_MSK20_Pos)                /* (PIO_MSKR) PIO Line 20 Mask Mask */
#define PIO_MSKR_MSK20(value)                 (PIO_MSKR_MSK20_Msk & (_UINT32_(value) << PIO_MSKR_MSK20_Pos)) /* Assigment of value for MSK20 in the PIO_MSKR register */
#define   PIO_MSKR_MSK20_DISABLED_Val         _UINT32_(0x0)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_MSKR_MSK20_ENABLED_Val          _UINT32_(0x1)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration.  */
#define PIO_MSKR_MSK20_DISABLED               (PIO_MSKR_MSK20_DISABLED_Val << PIO_MSKR_MSK20_Pos)  /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK20_ENABLED                (PIO_MSKR_MSK20_ENABLED_Val << PIO_MSKR_MSK20_Pos)   /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK21_Pos                    _UINT32_(21)                                         /* (PIO_MSKR) PIO Line 21 Mask Position */
#define PIO_MSKR_MSK21_Msk                    (_UINT32_(0x1) << PIO_MSKR_MSK21_Pos)                /* (PIO_MSKR) PIO Line 21 Mask Mask */
#define PIO_MSKR_MSK21(value)                 (PIO_MSKR_MSK21_Msk & (_UINT32_(value) << PIO_MSKR_MSK21_Pos)) /* Assigment of value for MSK21 in the PIO_MSKR register */
#define   PIO_MSKR_MSK21_DISABLED_Val         _UINT32_(0x0)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_MSKR_MSK21_ENABLED_Val          _UINT32_(0x1)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration.  */
#define PIO_MSKR_MSK21_DISABLED               (PIO_MSKR_MSK21_DISABLED_Val << PIO_MSKR_MSK21_Pos)  /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK21_ENABLED                (PIO_MSKR_MSK21_ENABLED_Val << PIO_MSKR_MSK21_Pos)   /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK22_Pos                    _UINT32_(22)                                         /* (PIO_MSKR) PIO Line 22 Mask Position */
#define PIO_MSKR_MSK22_Msk                    (_UINT32_(0x1) << PIO_MSKR_MSK22_Pos)                /* (PIO_MSKR) PIO Line 22 Mask Mask */
#define PIO_MSKR_MSK22(value)                 (PIO_MSKR_MSK22_Msk & (_UINT32_(value) << PIO_MSKR_MSK22_Pos)) /* Assigment of value for MSK22 in the PIO_MSKR register */
#define   PIO_MSKR_MSK22_DISABLED_Val         _UINT32_(0x0)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_MSKR_MSK22_ENABLED_Val          _UINT32_(0x1)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration.  */
#define PIO_MSKR_MSK22_DISABLED               (PIO_MSKR_MSK22_DISABLED_Val << PIO_MSKR_MSK22_Pos)  /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK22_ENABLED                (PIO_MSKR_MSK22_ENABLED_Val << PIO_MSKR_MSK22_Pos)   /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK23_Pos                    _UINT32_(23)                                         /* (PIO_MSKR) PIO Line 23 Mask Position */
#define PIO_MSKR_MSK23_Msk                    (_UINT32_(0x1) << PIO_MSKR_MSK23_Pos)                /* (PIO_MSKR) PIO Line 23 Mask Mask */
#define PIO_MSKR_MSK23(value)                 (PIO_MSKR_MSK23_Msk & (_UINT32_(value) << PIO_MSKR_MSK23_Pos)) /* Assigment of value for MSK23 in the PIO_MSKR register */
#define   PIO_MSKR_MSK23_DISABLED_Val         _UINT32_(0x0)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_MSKR_MSK23_ENABLED_Val          _UINT32_(0x1)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration.  */
#define PIO_MSKR_MSK23_DISABLED               (PIO_MSKR_MSK23_DISABLED_Val << PIO_MSKR_MSK23_Pos)  /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK23_ENABLED                (PIO_MSKR_MSK23_ENABLED_Val << PIO_MSKR_MSK23_Pos)   /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK24_Pos                    _UINT32_(24)                                         /* (PIO_MSKR) PIO Line 24 Mask Position */
#define PIO_MSKR_MSK24_Msk                    (_UINT32_(0x1) << PIO_MSKR_MSK24_Pos)                /* (PIO_MSKR) PIO Line 24 Mask Mask */
#define PIO_MSKR_MSK24(value)                 (PIO_MSKR_MSK24_Msk & (_UINT32_(value) << PIO_MSKR_MSK24_Pos)) /* Assigment of value for MSK24 in the PIO_MSKR register */
#define   PIO_MSKR_MSK24_DISABLED_Val         _UINT32_(0x0)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_MSKR_MSK24_ENABLED_Val          _UINT32_(0x1)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration.  */
#define PIO_MSKR_MSK24_DISABLED               (PIO_MSKR_MSK24_DISABLED_Val << PIO_MSKR_MSK24_Pos)  /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK24_ENABLED                (PIO_MSKR_MSK24_ENABLED_Val << PIO_MSKR_MSK24_Pos)   /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK25_Pos                    _UINT32_(25)                                         /* (PIO_MSKR) PIO Line 25 Mask Position */
#define PIO_MSKR_MSK25_Msk                    (_UINT32_(0x1) << PIO_MSKR_MSK25_Pos)                /* (PIO_MSKR) PIO Line 25 Mask Mask */
#define PIO_MSKR_MSK25(value)                 (PIO_MSKR_MSK25_Msk & (_UINT32_(value) << PIO_MSKR_MSK25_Pos)) /* Assigment of value for MSK25 in the PIO_MSKR register */
#define   PIO_MSKR_MSK25_DISABLED_Val         _UINT32_(0x0)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_MSKR_MSK25_ENABLED_Val          _UINT32_(0x1)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration.  */
#define PIO_MSKR_MSK25_DISABLED               (PIO_MSKR_MSK25_DISABLED_Val << PIO_MSKR_MSK25_Pos)  /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK25_ENABLED                (PIO_MSKR_MSK25_ENABLED_Val << PIO_MSKR_MSK25_Pos)   /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK26_Pos                    _UINT32_(26)                                         /* (PIO_MSKR) PIO Line 26 Mask Position */
#define PIO_MSKR_MSK26_Msk                    (_UINT32_(0x1) << PIO_MSKR_MSK26_Pos)                /* (PIO_MSKR) PIO Line 26 Mask Mask */
#define PIO_MSKR_MSK26(value)                 (PIO_MSKR_MSK26_Msk & (_UINT32_(value) << PIO_MSKR_MSK26_Pos)) /* Assigment of value for MSK26 in the PIO_MSKR register */
#define   PIO_MSKR_MSK26_DISABLED_Val         _UINT32_(0x0)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_MSKR_MSK26_ENABLED_Val          _UINT32_(0x1)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration.  */
#define PIO_MSKR_MSK26_DISABLED               (PIO_MSKR_MSK26_DISABLED_Val << PIO_MSKR_MSK26_Pos)  /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK26_ENABLED                (PIO_MSKR_MSK26_ENABLED_Val << PIO_MSKR_MSK26_Pos)   /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK27_Pos                    _UINT32_(27)                                         /* (PIO_MSKR) PIO Line 27 Mask Position */
#define PIO_MSKR_MSK27_Msk                    (_UINT32_(0x1) << PIO_MSKR_MSK27_Pos)                /* (PIO_MSKR) PIO Line 27 Mask Mask */
#define PIO_MSKR_MSK27(value)                 (PIO_MSKR_MSK27_Msk & (_UINT32_(value) << PIO_MSKR_MSK27_Pos)) /* Assigment of value for MSK27 in the PIO_MSKR register */
#define   PIO_MSKR_MSK27_DISABLED_Val         _UINT32_(0x0)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_MSKR_MSK27_ENABLED_Val          _UINT32_(0x1)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration.  */
#define PIO_MSKR_MSK27_DISABLED               (PIO_MSKR_MSK27_DISABLED_Val << PIO_MSKR_MSK27_Pos)  /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK27_ENABLED                (PIO_MSKR_MSK27_ENABLED_Val << PIO_MSKR_MSK27_Pos)   /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK28_Pos                    _UINT32_(28)                                         /* (PIO_MSKR) PIO Line 28 Mask Position */
#define PIO_MSKR_MSK28_Msk                    (_UINT32_(0x1) << PIO_MSKR_MSK28_Pos)                /* (PIO_MSKR) PIO Line 28 Mask Mask */
#define PIO_MSKR_MSK28(value)                 (PIO_MSKR_MSK28_Msk & (_UINT32_(value) << PIO_MSKR_MSK28_Pos)) /* Assigment of value for MSK28 in the PIO_MSKR register */
#define   PIO_MSKR_MSK28_DISABLED_Val         _UINT32_(0x0)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_MSKR_MSK28_ENABLED_Val          _UINT32_(0x1)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration.  */
#define PIO_MSKR_MSK28_DISABLED               (PIO_MSKR_MSK28_DISABLED_Val << PIO_MSKR_MSK28_Pos)  /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK28_ENABLED                (PIO_MSKR_MSK28_ENABLED_Val << PIO_MSKR_MSK28_Pos)   /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK29_Pos                    _UINT32_(29)                                         /* (PIO_MSKR) PIO Line 29 Mask Position */
#define PIO_MSKR_MSK29_Msk                    (_UINT32_(0x1) << PIO_MSKR_MSK29_Pos)                /* (PIO_MSKR) PIO Line 29 Mask Mask */
#define PIO_MSKR_MSK29(value)                 (PIO_MSKR_MSK29_Msk & (_UINT32_(value) << PIO_MSKR_MSK29_Pos)) /* Assigment of value for MSK29 in the PIO_MSKR register */
#define   PIO_MSKR_MSK29_DISABLED_Val         _UINT32_(0x0)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_MSKR_MSK29_ENABLED_Val          _UINT32_(0x1)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration.  */
#define PIO_MSKR_MSK29_DISABLED               (PIO_MSKR_MSK29_DISABLED_Val << PIO_MSKR_MSK29_Pos)  /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK29_ENABLED                (PIO_MSKR_MSK29_ENABLED_Val << PIO_MSKR_MSK29_Pos)   /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK30_Pos                    _UINT32_(30)                                         /* (PIO_MSKR) PIO Line 30 Mask Position */
#define PIO_MSKR_MSK30_Msk                    (_UINT32_(0x1) << PIO_MSKR_MSK30_Pos)                /* (PIO_MSKR) PIO Line 30 Mask Mask */
#define PIO_MSKR_MSK30(value)                 (PIO_MSKR_MSK30_Msk & (_UINT32_(value) << PIO_MSKR_MSK30_Pos)) /* Assigment of value for MSK30 in the PIO_MSKR register */
#define   PIO_MSKR_MSK30_DISABLED_Val         _UINT32_(0x0)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_MSKR_MSK30_ENABLED_Val          _UINT32_(0x1)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration.  */
#define PIO_MSKR_MSK30_DISABLED               (PIO_MSKR_MSK30_DISABLED_Val << PIO_MSKR_MSK30_Pos)  /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK30_ENABLED                (PIO_MSKR_MSK30_ENABLED_Val << PIO_MSKR_MSK30_Pos)   /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK31_Pos                    _UINT32_(31)                                         /* (PIO_MSKR) PIO Line 31 Mask Position */
#define PIO_MSKR_MSK31_Msk                    (_UINT32_(0x1) << PIO_MSKR_MSK31_Pos)                /* (PIO_MSKR) PIO Line 31 Mask Mask */
#define PIO_MSKR_MSK31(value)                 (PIO_MSKR_MSK31_Msk & (_UINT32_(value) << PIO_MSKR_MSK31_Pos)) /* Assigment of value for MSK31 in the PIO_MSKR register */
#define   PIO_MSKR_MSK31_DISABLED_Val         _UINT32_(0x0)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_MSKR_MSK31_ENABLED_Val          _UINT32_(0x1)                                        /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration.  */
#define PIO_MSKR_MSK31_DISABLED               (PIO_MSKR_MSK31_DISABLED_Val << PIO_MSKR_MSK31_Pos)  /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_MSKR_MSK31_ENABLED                (PIO_MSKR_MSK31_ENABLED_Val << PIO_MSKR_MSK31_Pos)   /* (PIO_MSKR) Writing the PIO_CFGRx, PIO_ODSRx or PIO_IOFRx updates the corresponding I/O line configuration. Position  */
#define PIO_MSKR_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (PIO_MSKR) Register Mask  */

#define PIO_MSKR_MSK_Pos                      _UINT32_(0)                                          /* (PIO_MSKR Position) PIO Line 3x Mask */
#define PIO_MSKR_MSK_Msk                      (_UINT32_(0xFFFFFFFF) << PIO_MSKR_MSK_Pos)           /* (PIO_MSKR Mask) MSK */
#define PIO_MSKR_MSK(value)                   (PIO_MSKR_MSK_Msk & (_UINT32_(value) << PIO_MSKR_MSK_Pos)) 

/* -------- PIO_CFGR : (PIO Offset: 0x04) (R/W 32) PIO Configuration Register -------- */
#define PIO_CFGR_FUNC_Pos                     _UINT32_(0)                                          /* (PIO_CFGR) I/O Line Function Position */
#define PIO_CFGR_FUNC_Msk                     (_UINT32_(0x7) << PIO_CFGR_FUNC_Pos)                 /* (PIO_CFGR) I/O Line Function Mask */
#define PIO_CFGR_FUNC(value)                  (PIO_CFGR_FUNC_Msk & (_UINT32_(value) << PIO_CFGR_FUNC_Pos)) /* Assigment of value for FUNC in the PIO_CFGR register */
#define   PIO_CFGR_FUNC_GPIO_Val              _UINT32_(0x0)                                        /* (PIO_CFGR) Select the PIO mode for the selected I/O lines.  */
#define   PIO_CFGR_FUNC_PERIPH_A_Val          _UINT32_(0x1)                                        /* (PIO_CFGR) Select the peripheral A for the selected I/O lines.  */
#define   PIO_CFGR_FUNC_PERIPH_B_Val          _UINT32_(0x2)                                        /* (PIO_CFGR) Select the peripheral B for the selected I/O lines.  */
#define   PIO_CFGR_FUNC_PERIPH_C_Val          _UINT32_(0x3)                                        /* (PIO_CFGR) Select the peripheral C for the selected I/O lines.  */
#define   PIO_CFGR_FUNC_PERIPH_D_Val          _UINT32_(0x4)                                        /* (PIO_CFGR) Select the peripheral D for the selected I/O lines.  */
#define PIO_CFGR_FUNC_GPIO                    (PIO_CFGR_FUNC_GPIO_Val << PIO_CFGR_FUNC_Pos)        /* (PIO_CFGR) Select the PIO mode for the selected I/O lines. Position  */
#define PIO_CFGR_FUNC_PERIPH_A                (PIO_CFGR_FUNC_PERIPH_A_Val << PIO_CFGR_FUNC_Pos)    /* (PIO_CFGR) Select the peripheral A for the selected I/O lines. Position  */
#define PIO_CFGR_FUNC_PERIPH_B                (PIO_CFGR_FUNC_PERIPH_B_Val << PIO_CFGR_FUNC_Pos)    /* (PIO_CFGR) Select the peripheral B for the selected I/O lines. Position  */
#define PIO_CFGR_FUNC_PERIPH_C                (PIO_CFGR_FUNC_PERIPH_C_Val << PIO_CFGR_FUNC_Pos)    /* (PIO_CFGR) Select the peripheral C for the selected I/O lines. Position  */
#define PIO_CFGR_FUNC_PERIPH_D                (PIO_CFGR_FUNC_PERIPH_D_Val << PIO_CFGR_FUNC_Pos)    /* (PIO_CFGR) Select the peripheral D for the selected I/O lines. Position  */
#define PIO_CFGR_DIR_Pos                      _UINT32_(8)                                          /* (PIO_CFGR) Direction Position */
#define PIO_CFGR_DIR_Msk                      (_UINT32_(0x1) << PIO_CFGR_DIR_Pos)                  /* (PIO_CFGR) Direction Mask */
#define PIO_CFGR_DIR(value)                   (PIO_CFGR_DIR_Msk & (_UINT32_(value) << PIO_CFGR_DIR_Pos)) /* Assigment of value for DIR in the PIO_CFGR register */
#define   PIO_CFGR_DIR_INPUT_Val              _UINT32_(0x0)                                        /* (PIO_CFGR) The selected I/O lines are pure inputs.  */
#define   PIO_CFGR_DIR_OUTPUT_Val             _UINT32_(0x1)                                        /* (PIO_CFGR) The selected I/O lines are enabled in output.  */
#define PIO_CFGR_DIR_INPUT                    (PIO_CFGR_DIR_INPUT_Val << PIO_CFGR_DIR_Pos)         /* (PIO_CFGR) The selected I/O lines are pure inputs. Position  */
#define PIO_CFGR_DIR_OUTPUT                   (PIO_CFGR_DIR_OUTPUT_Val << PIO_CFGR_DIR_Pos)        /* (PIO_CFGR) The selected I/O lines are enabled in output. Position  */
#define PIO_CFGR_PUEN_Pos                     _UINT32_(9)                                          /* (PIO_CFGR) Pull-Up Enable Position */
#define PIO_CFGR_PUEN_Msk                     (_UINT32_(0x1) << PIO_CFGR_PUEN_Pos)                 /* (PIO_CFGR) Pull-Up Enable Mask */
#define PIO_CFGR_PUEN(value)                  (PIO_CFGR_PUEN_Msk & (_UINT32_(value) << PIO_CFGR_PUEN_Pos)) /* Assigment of value for PUEN in the PIO_CFGR register */
#define   PIO_CFGR_PUEN_DISABLED_Val          _UINT32_(0x0)                                        /* (PIO_CFGR) Pull-Up is disabled for the selected I/O lines.  */
#define   PIO_CFGR_PUEN_ENABLED_Val           _UINT32_(0x1)                                        /* (PIO_CFGR) Pull-Up is enabled for the selected I/O lines.  */
#define PIO_CFGR_PUEN_DISABLED                (PIO_CFGR_PUEN_DISABLED_Val << PIO_CFGR_PUEN_Pos)    /* (PIO_CFGR) Pull-Up is disabled for the selected I/O lines. Position  */
#define PIO_CFGR_PUEN_ENABLED                 (PIO_CFGR_PUEN_ENABLED_Val << PIO_CFGR_PUEN_Pos)     /* (PIO_CFGR) Pull-Up is enabled for the selected I/O lines. Position  */
#define PIO_CFGR_PDEN_Pos                     _UINT32_(10)                                         /* (PIO_CFGR) Pull-Down Enable Position */
#define PIO_CFGR_PDEN_Msk                     (_UINT32_(0x1) << PIO_CFGR_PDEN_Pos)                 /* (PIO_CFGR) Pull-Down Enable Mask */
#define PIO_CFGR_PDEN(value)                  (PIO_CFGR_PDEN_Msk & (_UINT32_(value) << PIO_CFGR_PDEN_Pos)) /* Assigment of value for PDEN in the PIO_CFGR register */
#define   PIO_CFGR_PDEN_DISABLED_Val          _UINT32_(0x0)                                        /* (PIO_CFGR) Pull-Down is disabled for the selected I/O lines.  */
#define   PIO_CFGR_PDEN_ENABLED_Val           _UINT32_(0x1)                                        /* (PIO_CFGR) Pull-Down is enabled for the selected I/O lines only if PUEN is 0.  */
#define PIO_CFGR_PDEN_DISABLED                (PIO_CFGR_PDEN_DISABLED_Val << PIO_CFGR_PDEN_Pos)    /* (PIO_CFGR) Pull-Down is disabled for the selected I/O lines. Position  */
#define PIO_CFGR_PDEN_ENABLED                 (PIO_CFGR_PDEN_ENABLED_Val << PIO_CFGR_PDEN_Pos)     /* (PIO_CFGR) Pull-Down is enabled for the selected I/O lines only if PUEN is 0. Position  */
#define PIO_CFGR_IFEN_Pos                     _UINT32_(12)                                         /* (PIO_CFGR) Input Filter Enable Position */
#define PIO_CFGR_IFEN_Msk                     (_UINT32_(0x1) << PIO_CFGR_IFEN_Pos)                 /* (PIO_CFGR) Input Filter Enable Mask */
#define PIO_CFGR_IFEN(value)                  (PIO_CFGR_IFEN_Msk & (_UINT32_(value) << PIO_CFGR_IFEN_Pos)) /* Assigment of value for IFEN in the PIO_CFGR register */
#define   PIO_CFGR_IFEN_DISABLED_Val          _UINT32_(0x0)                                        /* (PIO_CFGR) The input filter is disabled for the selected I/O lines.  */
#define   PIO_CFGR_IFEN_ENABLED_Val           _UINT32_(0x1)                                        /* (PIO_CFGR) The input filter is enabled for the selected I/O lines.  */
#define PIO_CFGR_IFEN_DISABLED                (PIO_CFGR_IFEN_DISABLED_Val << PIO_CFGR_IFEN_Pos)    /* (PIO_CFGR) The input filter is disabled for the selected I/O lines. Position  */
#define PIO_CFGR_IFEN_ENABLED                 (PIO_CFGR_IFEN_ENABLED_Val << PIO_CFGR_IFEN_Pos)     /* (PIO_CFGR) The input filter is enabled for the selected I/O lines. Position  */
#define PIO_CFGR_IFSCEN_Pos                   _UINT32_(13)                                         /* (PIO_CFGR) Input Filter Slow Clock Enable Position */
#define PIO_CFGR_IFSCEN_Msk                   (_UINT32_(0x1) << PIO_CFGR_IFSCEN_Pos)               /* (PIO_CFGR) Input Filter Slow Clock Enable Mask */
#define PIO_CFGR_IFSCEN(value)                (PIO_CFGR_IFSCEN_Msk & (_UINT32_(value) << PIO_CFGR_IFSCEN_Pos)) /* Assigment of value for IFSCEN in the PIO_CFGR register */
#define   PIO_CFGR_IFSCEN_DISABLED_Val        _UINT32_(0x0)                                        /* (PIO_CFGR) The glitch filter is able to filter glitches with a duration < tmck/2 for the selected I/O lines.  */
#define   PIO_CFGR_IFSCEN_ENABLED_Val         _UINT32_(0x1)                                        /* (PIO_CFGR) The debouncing filter is able to filter pulses with a duration < tdiv_slck/2 for the selected I/O lines.  */
#define PIO_CFGR_IFSCEN_DISABLED              (PIO_CFGR_IFSCEN_DISABLED_Val << PIO_CFGR_IFSCEN_Pos) /* (PIO_CFGR) The glitch filter is able to filter glitches with a duration < tmck/2 for the selected I/O lines. Position  */
#define PIO_CFGR_IFSCEN_ENABLED               (PIO_CFGR_IFSCEN_ENABLED_Val << PIO_CFGR_IFSCEN_Pos) /* (PIO_CFGR) The debouncing filter is able to filter pulses with a duration < tdiv_slck/2 for the selected I/O lines. Position  */
#define PIO_CFGR_OPD_Pos                      _UINT32_(14)                                         /* (PIO_CFGR) Open-Drain Position */
#define PIO_CFGR_OPD_Msk                      (_UINT32_(0x1) << PIO_CFGR_OPD_Pos)                  /* (PIO_CFGR) Open-Drain Mask */
#define PIO_CFGR_OPD(value)                   (PIO_CFGR_OPD_Msk & (_UINT32_(value) << PIO_CFGR_OPD_Pos)) /* Assigment of value for OPD in the PIO_CFGR register */
#define   PIO_CFGR_OPD_DISABLED_Val           _UINT32_(0x0)                                        /* (PIO_CFGR) The open-drain is disabled for the selected I/O lines. I/O lines are driven at high- and low-level.  */
#define   PIO_CFGR_OPD_ENABLED_Val            _UINT32_(0x1)                                        /* (PIO_CFGR) The open-drain is enabled for the selected I/O lines. I/O lines are driven at low-level only.  */
#define PIO_CFGR_OPD_DISABLED                 (PIO_CFGR_OPD_DISABLED_Val << PIO_CFGR_OPD_Pos)      /* (PIO_CFGR) The open-drain is disabled for the selected I/O lines. I/O lines are driven at high- and low-level. Position  */
#define PIO_CFGR_OPD_ENABLED                  (PIO_CFGR_OPD_ENABLED_Val << PIO_CFGR_OPD_Pos)       /* (PIO_CFGR) The open-drain is enabled for the selected I/O lines. I/O lines are driven at low-level only. Position  */
#define PIO_CFGR_SCHMITT_Pos                  _UINT32_(15)                                         /* (PIO_CFGR) Schmitt Trigger Position */
#define PIO_CFGR_SCHMITT_Msk                  (_UINT32_(0x1) << PIO_CFGR_SCHMITT_Pos)              /* (PIO_CFGR) Schmitt Trigger Mask */
#define PIO_CFGR_SCHMITT(value)               (PIO_CFGR_SCHMITT_Msk & (_UINT32_(value) << PIO_CFGR_SCHMITT_Pos)) /* Assigment of value for SCHMITT in the PIO_CFGR register */
#define   PIO_CFGR_SCHMITT_ENABLED_Val        _UINT32_(0x0)                                        /* (PIO_CFGR) Schmitt trigger is enabled for the selected I/O lines.  */
#define   PIO_CFGR_SCHMITT_DISABLED_Val       _UINT32_(0x1)                                        /* (PIO_CFGR) Schmitt trigger is disabled for the selected I/O lines.  */
#define PIO_CFGR_SCHMITT_ENABLED              (PIO_CFGR_SCHMITT_ENABLED_Val << PIO_CFGR_SCHMITT_Pos) /* (PIO_CFGR) Schmitt trigger is enabled for the selected I/O lines. Position  */
#define PIO_CFGR_SCHMITT_DISABLED             (PIO_CFGR_SCHMITT_DISABLED_Val << PIO_CFGR_SCHMITT_Pos) /* (PIO_CFGR) Schmitt trigger is disabled for the selected I/O lines. Position  */
#define PIO_CFGR_SLEWRATE_Pos                 _UINT32_(16)                                         /* (PIO_CFGR) Slew Rate Position */
#define PIO_CFGR_SLEWRATE_Msk                 (_UINT32_(0x3) << PIO_CFGR_SLEWRATE_Pos)             /* (PIO_CFGR) Slew Rate Mask */
#define PIO_CFGR_SLEWRATE(value)              (PIO_CFGR_SLEWRATE_Msk & (_UINT32_(value) << PIO_CFGR_SLEWRATE_Pos)) /* Assigment of value for SLEWRATE in the PIO_CFGR register */
#define   PIO_CFGR_SLEWRATE_FAST_Val          _UINT32_(0x0)                                        /* (PIO_CFGR) Fast slew rate  */
#define   PIO_CFGR_SLEWRATE_MEDIUMFAST_Val    _UINT32_(0x1)                                        /* (PIO_CFGR) Medium-fast slew rate  */
#define   PIO_CFGR_SLEWRATE_MEDIUM_Val        _UINT32_(0x2)                                        /* (PIO_CFGR) Medium slew rate  */
#define   PIO_CFGR_SLEWRATE_SLOW_Val          _UINT32_(0x3)                                        /* (PIO_CFGR) Slow slew rate  */
#define PIO_CFGR_SLEWRATE_FAST                (PIO_CFGR_SLEWRATE_FAST_Val << PIO_CFGR_SLEWRATE_Pos) /* (PIO_CFGR) Fast slew rate Position  */
#define PIO_CFGR_SLEWRATE_MEDIUMFAST          (PIO_CFGR_SLEWRATE_MEDIUMFAST_Val << PIO_CFGR_SLEWRATE_Pos) /* (PIO_CFGR) Medium-fast slew rate Position  */
#define PIO_CFGR_SLEWRATE_MEDIUM              (PIO_CFGR_SLEWRATE_MEDIUM_Val << PIO_CFGR_SLEWRATE_Pos) /* (PIO_CFGR) Medium slew rate Position  */
#define PIO_CFGR_SLEWRATE_SLOW                (PIO_CFGR_SLEWRATE_SLOW_Val << PIO_CFGR_SLEWRATE_Pos) /* (PIO_CFGR) Slow slew rate Position  */
#define PIO_CFGR_EVTSEL_Pos                   _UINT32_(24)                                         /* (PIO_CFGR) Event Selection Position */
#define PIO_CFGR_EVTSEL_Msk                   (_UINT32_(0x7) << PIO_CFGR_EVTSEL_Pos)               /* (PIO_CFGR) Event Selection Mask */
#define PIO_CFGR_EVTSEL(value)                (PIO_CFGR_EVTSEL_Msk & (_UINT32_(value) << PIO_CFGR_EVTSEL_Pos)) /* Assigment of value for EVTSEL in the PIO_CFGR register */
#define   PIO_CFGR_EVTSEL_FALLING_Val         _UINT32_(0x0)                                        /* (PIO_CFGR) Event detection on input falling edge  */
#define   PIO_CFGR_EVTSEL_RISING_Val          _UINT32_(0x1)                                        /* (PIO_CFGR) Event detection on input rising edge  */
#define   PIO_CFGR_EVTSEL_BOTH_Val            _UINT32_(0x2)                                        /* (PIO_CFGR) Event detection on input both edge  */
#define   PIO_CFGR_EVTSEL_LOW_Val             _UINT32_(0x3)                                        /* (PIO_CFGR) Event detection on low level input  */
#define   PIO_CFGR_EVTSEL_HIGH_Val            _UINT32_(0x4)                                        /* (PIO_CFGR) Event detection on high level input  */
#define PIO_CFGR_EVTSEL_FALLING               (PIO_CFGR_EVTSEL_FALLING_Val << PIO_CFGR_EVTSEL_Pos) /* (PIO_CFGR) Event detection on input falling edge Position  */
#define PIO_CFGR_EVTSEL_RISING                (PIO_CFGR_EVTSEL_RISING_Val << PIO_CFGR_EVTSEL_Pos)  /* (PIO_CFGR) Event detection on input rising edge Position  */
#define PIO_CFGR_EVTSEL_BOTH                  (PIO_CFGR_EVTSEL_BOTH_Val << PIO_CFGR_EVTSEL_Pos)    /* (PIO_CFGR) Event detection on input both edge Position  */
#define PIO_CFGR_EVTSEL_LOW                   (PIO_CFGR_EVTSEL_LOW_Val << PIO_CFGR_EVTSEL_Pos)     /* (PIO_CFGR) Event detection on low level input Position  */
#define PIO_CFGR_EVTSEL_HIGH                  (PIO_CFGR_EVTSEL_HIGH_Val << PIO_CFGR_EVTSEL_Pos)    /* (PIO_CFGR) Event detection on high level input Position  */
#define PIO_CFGR_PCFS_Pos                     _UINT32_(29)                                         /* (PIO_CFGR) Physical Configuration Freeze Status (read-only) Position */
#define PIO_CFGR_PCFS_Msk                     (_UINT32_(0x1) << PIO_CFGR_PCFS_Pos)                 /* (PIO_CFGR) Physical Configuration Freeze Status (read-only) Mask */
#define PIO_CFGR_PCFS(value)                  (PIO_CFGR_PCFS_Msk & (_UINT32_(value) << PIO_CFGR_PCFS_Pos)) /* Assigment of value for PCFS in the PIO_CFGR register */
#define   PIO_CFGR_PCFS_NOT_FROZEN_Val        _UINT32_(0x0)                                        /* (PIO_CFGR) The fields are not frozen and can be written for this I/O line.  */
#define   PIO_CFGR_PCFS_FROZEN_Val            _UINT32_(0x1)                                        /* (PIO_CFGR) The fields are frozen and cannot be written for this I/O line. Only a hardware reset can release these fields.  */
#define PIO_CFGR_PCFS_NOT_FROZEN              (PIO_CFGR_PCFS_NOT_FROZEN_Val << PIO_CFGR_PCFS_Pos)  /* (PIO_CFGR) The fields are not frozen and can be written for this I/O line. Position  */
#define PIO_CFGR_PCFS_FROZEN                  (PIO_CFGR_PCFS_FROZEN_Val << PIO_CFGR_PCFS_Pos)      /* (PIO_CFGR) The fields are frozen and cannot be written for this I/O line. Only a hardware reset can release these fields. Position  */
#define PIO_CFGR_ICFS_Pos                     _UINT32_(30)                                         /* (PIO_CFGR) Interrupt Configuration Freeze Status (read-only) Position */
#define PIO_CFGR_ICFS_Msk                     (_UINT32_(0x1) << PIO_CFGR_ICFS_Pos)                 /* (PIO_CFGR) Interrupt Configuration Freeze Status (read-only) Mask */
#define PIO_CFGR_ICFS(value)                  (PIO_CFGR_ICFS_Msk & (_UINT32_(value) << PIO_CFGR_ICFS_Pos)) /* Assigment of value for ICFS in the PIO_CFGR register */
#define   PIO_CFGR_ICFS_NOT_FROZEN_Val        _UINT32_(0x0)                                        /* (PIO_CFGR) The fields are not frozen and can be written for this I/O line.  */
#define   PIO_CFGR_ICFS_FROZEN_Val            _UINT32_(0x1)                                        /* (PIO_CFGR) The fields are frozen and cannot be written for this I/O line. Only a hardware reset can release these fields.  */
#define PIO_CFGR_ICFS_NOT_FROZEN              (PIO_CFGR_ICFS_NOT_FROZEN_Val << PIO_CFGR_ICFS_Pos)  /* (PIO_CFGR) The fields are not frozen and can be written for this I/O line. Position  */
#define PIO_CFGR_ICFS_FROZEN                  (PIO_CFGR_ICFS_FROZEN_Val << PIO_CFGR_ICFS_Pos)      /* (PIO_CFGR) The fields are frozen and cannot be written for this I/O line. Only a hardware reset can release these fields. Position  */
#define PIO_CFGR_Msk                          _UINT32_(0x6703F707)                                 /* (PIO_CFGR) Register Mask  */


/* -------- PIO_PDSR : (PIO Offset: 0x08) ( R/ 32) PIO Pin Data Status Register -------- */
#define PIO_PDSR_P0_Pos                       _UINT32_(0)                                          /* (PIO_PDSR) Input Data Status Position */
#define PIO_PDSR_P0_Msk                       (_UINT32_(0x1) << PIO_PDSR_P0_Pos)                   /* (PIO_PDSR) Input Data Status Mask */
#define PIO_PDSR_P0(value)                    (PIO_PDSR_P0_Msk & (_UINT32_(value) << PIO_PDSR_P0_Pos)) /* Assigment of value for P0 in the PIO_PDSR register */
#define PIO_PDSR_P1_Pos                       _UINT32_(1)                                          /* (PIO_PDSR) Input Data Status Position */
#define PIO_PDSR_P1_Msk                       (_UINT32_(0x1) << PIO_PDSR_P1_Pos)                   /* (PIO_PDSR) Input Data Status Mask */
#define PIO_PDSR_P1(value)                    (PIO_PDSR_P1_Msk & (_UINT32_(value) << PIO_PDSR_P1_Pos)) /* Assigment of value for P1 in the PIO_PDSR register */
#define PIO_PDSR_P2_Pos                       _UINT32_(2)                                          /* (PIO_PDSR) Input Data Status Position */
#define PIO_PDSR_P2_Msk                       (_UINT32_(0x1) << PIO_PDSR_P2_Pos)                   /* (PIO_PDSR) Input Data Status Mask */
#define PIO_PDSR_P2(value)                    (PIO_PDSR_P2_Msk & (_UINT32_(value) << PIO_PDSR_P2_Pos)) /* Assigment of value for P2 in the PIO_PDSR register */
#define PIO_PDSR_P3_Pos                       _UINT32_(3)                                          /* (PIO_PDSR) Input Data Status Position */
#define PIO_PDSR_P3_Msk                       (_UINT32_(0x1) << PIO_PDSR_P3_Pos)                   /* (PIO_PDSR) Input Data Status Mask */
#define PIO_PDSR_P3(value)                    (PIO_PDSR_P3_Msk & (_UINT32_(value) << PIO_PDSR_P3_Pos)) /* Assigment of value for P3 in the PIO_PDSR register */
#define PIO_PDSR_P4_Pos                       _UINT32_(4)                                          /* (PIO_PDSR) Input Data Status Position */
#define PIO_PDSR_P4_Msk                       (_UINT32_(0x1) << PIO_PDSR_P4_Pos)                   /* (PIO_PDSR) Input Data Status Mask */
#define PIO_PDSR_P4(value)                    (PIO_PDSR_P4_Msk & (_UINT32_(value) << PIO_PDSR_P4_Pos)) /* Assigment of value for P4 in the PIO_PDSR register */
#define PIO_PDSR_P5_Pos                       _UINT32_(5)                                          /* (PIO_PDSR) Input Data Status Position */
#define PIO_PDSR_P5_Msk                       (_UINT32_(0x1) << PIO_PDSR_P5_Pos)                   /* (PIO_PDSR) Input Data Status Mask */
#define PIO_PDSR_P5(value)                    (PIO_PDSR_P5_Msk & (_UINT32_(value) << PIO_PDSR_P5_Pos)) /* Assigment of value for P5 in the PIO_PDSR register */
#define PIO_PDSR_P6_Pos                       _UINT32_(6)                                          /* (PIO_PDSR) Input Data Status Position */
#define PIO_PDSR_P6_Msk                       (_UINT32_(0x1) << PIO_PDSR_P6_Pos)                   /* (PIO_PDSR) Input Data Status Mask */
#define PIO_PDSR_P6(value)                    (PIO_PDSR_P6_Msk & (_UINT32_(value) << PIO_PDSR_P6_Pos)) /* Assigment of value for P6 in the PIO_PDSR register */
#define PIO_PDSR_P7_Pos                       _UINT32_(7)                                          /* (PIO_PDSR) Input Data Status Position */
#define PIO_PDSR_P7_Msk                       (_UINT32_(0x1) << PIO_PDSR_P7_Pos)                   /* (PIO_PDSR) Input Data Status Mask */
#define PIO_PDSR_P7(value)                    (PIO_PDSR_P7_Msk & (_UINT32_(value) << PIO_PDSR_P7_Pos)) /* Assigment of value for P7 in the PIO_PDSR register */
#define PIO_PDSR_P8_Pos                       _UINT32_(8)                                          /* (PIO_PDSR) Input Data Status Position */
#define PIO_PDSR_P8_Msk                       (_UINT32_(0x1) << PIO_PDSR_P8_Pos)                   /* (PIO_PDSR) Input Data Status Mask */
#define PIO_PDSR_P8(value)                    (PIO_PDSR_P8_Msk & (_UINT32_(value) << PIO_PDSR_P8_Pos)) /* Assigment of value for P8 in the PIO_PDSR register */
#define PIO_PDSR_P9_Pos                       _UINT32_(9)                                          /* (PIO_PDSR) Input Data Status Position */
#define PIO_PDSR_P9_Msk                       (_UINT32_(0x1) << PIO_PDSR_P9_Pos)                   /* (PIO_PDSR) Input Data Status Mask */
#define PIO_PDSR_P9(value)                    (PIO_PDSR_P9_Msk & (_UINT32_(value) << PIO_PDSR_P9_Pos)) /* Assigment of value for P9 in the PIO_PDSR register */
#define PIO_PDSR_P10_Pos                      _UINT32_(10)                                         /* (PIO_PDSR) Input Data Status Position */
#define PIO_PDSR_P10_Msk                      (_UINT32_(0x1) << PIO_PDSR_P10_Pos)                  /* (PIO_PDSR) Input Data Status Mask */
#define PIO_PDSR_P10(value)                   (PIO_PDSR_P10_Msk & (_UINT32_(value) << PIO_PDSR_P10_Pos)) /* Assigment of value for P10 in the PIO_PDSR register */
#define PIO_PDSR_P11_Pos                      _UINT32_(11)                                         /* (PIO_PDSR) Input Data Status Position */
#define PIO_PDSR_P11_Msk                      (_UINT32_(0x1) << PIO_PDSR_P11_Pos)                  /* (PIO_PDSR) Input Data Status Mask */
#define PIO_PDSR_P11(value)                   (PIO_PDSR_P11_Msk & (_UINT32_(value) << PIO_PDSR_P11_Pos)) /* Assigment of value for P11 in the PIO_PDSR register */
#define PIO_PDSR_P12_Pos                      _UINT32_(12)                                         /* (PIO_PDSR) Input Data Status Position */
#define PIO_PDSR_P12_Msk                      (_UINT32_(0x1) << PIO_PDSR_P12_Pos)                  /* (PIO_PDSR) Input Data Status Mask */
#define PIO_PDSR_P12(value)                   (PIO_PDSR_P12_Msk & (_UINT32_(value) << PIO_PDSR_P12_Pos)) /* Assigment of value for P12 in the PIO_PDSR register */
#define PIO_PDSR_P13_Pos                      _UINT32_(13)                                         /* (PIO_PDSR) Input Data Status Position */
#define PIO_PDSR_P13_Msk                      (_UINT32_(0x1) << PIO_PDSR_P13_Pos)                  /* (PIO_PDSR) Input Data Status Mask */
#define PIO_PDSR_P13(value)                   (PIO_PDSR_P13_Msk & (_UINT32_(value) << PIO_PDSR_P13_Pos)) /* Assigment of value for P13 in the PIO_PDSR register */
#define PIO_PDSR_P14_Pos                      _UINT32_(14)                                         /* (PIO_PDSR) Input Data Status Position */
#define PIO_PDSR_P14_Msk                      (_UINT32_(0x1) << PIO_PDSR_P14_Pos)                  /* (PIO_PDSR) Input Data Status Mask */
#define PIO_PDSR_P14(value)                   (PIO_PDSR_P14_Msk & (_UINT32_(value) << PIO_PDSR_P14_Pos)) /* Assigment of value for P14 in the PIO_PDSR register */
#define PIO_PDSR_P15_Pos                      _UINT32_(15)                                         /* (PIO_PDSR) Input Data Status Position */
#define PIO_PDSR_P15_Msk                      (_UINT32_(0x1) << PIO_PDSR_P15_Pos)                  /* (PIO_PDSR) Input Data Status Mask */
#define PIO_PDSR_P15(value)                   (PIO_PDSR_P15_Msk & (_UINT32_(value) << PIO_PDSR_P15_Pos)) /* Assigment of value for P15 in the PIO_PDSR register */
#define PIO_PDSR_P16_Pos                      _UINT32_(16)                                         /* (PIO_PDSR) Input Data Status Position */
#define PIO_PDSR_P16_Msk                      (_UINT32_(0x1) << PIO_PDSR_P16_Pos)                  /* (PIO_PDSR) Input Data Status Mask */
#define PIO_PDSR_P16(value)                   (PIO_PDSR_P16_Msk & (_UINT32_(value) << PIO_PDSR_P16_Pos)) /* Assigment of value for P16 in the PIO_PDSR register */
#define PIO_PDSR_P17_Pos                      _UINT32_(17)                                         /* (PIO_PDSR) Input Data Status Position */
#define PIO_PDSR_P17_Msk                      (_UINT32_(0x1) << PIO_PDSR_P17_Pos)                  /* (PIO_PDSR) Input Data Status Mask */
#define PIO_PDSR_P17(value)                   (PIO_PDSR_P17_Msk & (_UINT32_(value) << PIO_PDSR_P17_Pos)) /* Assigment of value for P17 in the PIO_PDSR register */
#define PIO_PDSR_P18_Pos                      _UINT32_(18)                                         /* (PIO_PDSR) Input Data Status Position */
#define PIO_PDSR_P18_Msk                      (_UINT32_(0x1) << PIO_PDSR_P18_Pos)                  /* (PIO_PDSR) Input Data Status Mask */
#define PIO_PDSR_P18(value)                   (PIO_PDSR_P18_Msk & (_UINT32_(value) << PIO_PDSR_P18_Pos)) /* Assigment of value for P18 in the PIO_PDSR register */
#define PIO_PDSR_P19_Pos                      _UINT32_(19)                                         /* (PIO_PDSR) Input Data Status Position */
#define PIO_PDSR_P19_Msk                      (_UINT32_(0x1) << PIO_PDSR_P19_Pos)                  /* (PIO_PDSR) Input Data Status Mask */
#define PIO_PDSR_P19(value)                   (PIO_PDSR_P19_Msk & (_UINT32_(value) << PIO_PDSR_P19_Pos)) /* Assigment of value for P19 in the PIO_PDSR register */
#define PIO_PDSR_P20_Pos                      _UINT32_(20)                                         /* (PIO_PDSR) Input Data Status Position */
#define PIO_PDSR_P20_Msk                      (_UINT32_(0x1) << PIO_PDSR_P20_Pos)                  /* (PIO_PDSR) Input Data Status Mask */
#define PIO_PDSR_P20(value)                   (PIO_PDSR_P20_Msk & (_UINT32_(value) << PIO_PDSR_P20_Pos)) /* Assigment of value for P20 in the PIO_PDSR register */
#define PIO_PDSR_P21_Pos                      _UINT32_(21)                                         /* (PIO_PDSR) Input Data Status Position */
#define PIO_PDSR_P21_Msk                      (_UINT32_(0x1) << PIO_PDSR_P21_Pos)                  /* (PIO_PDSR) Input Data Status Mask */
#define PIO_PDSR_P21(value)                   (PIO_PDSR_P21_Msk & (_UINT32_(value) << PIO_PDSR_P21_Pos)) /* Assigment of value for P21 in the PIO_PDSR register */
#define PIO_PDSR_P22_Pos                      _UINT32_(22)                                         /* (PIO_PDSR) Input Data Status Position */
#define PIO_PDSR_P22_Msk                      (_UINT32_(0x1) << PIO_PDSR_P22_Pos)                  /* (PIO_PDSR) Input Data Status Mask */
#define PIO_PDSR_P22(value)                   (PIO_PDSR_P22_Msk & (_UINT32_(value) << PIO_PDSR_P22_Pos)) /* Assigment of value for P22 in the PIO_PDSR register */
#define PIO_PDSR_P23_Pos                      _UINT32_(23)                                         /* (PIO_PDSR) Input Data Status Position */
#define PIO_PDSR_P23_Msk                      (_UINT32_(0x1) << PIO_PDSR_P23_Pos)                  /* (PIO_PDSR) Input Data Status Mask */
#define PIO_PDSR_P23(value)                   (PIO_PDSR_P23_Msk & (_UINT32_(value) << PIO_PDSR_P23_Pos)) /* Assigment of value for P23 in the PIO_PDSR register */
#define PIO_PDSR_P24_Pos                      _UINT32_(24)                                         /* (PIO_PDSR) Input Data Status Position */
#define PIO_PDSR_P24_Msk                      (_UINT32_(0x1) << PIO_PDSR_P24_Pos)                  /* (PIO_PDSR) Input Data Status Mask */
#define PIO_PDSR_P24(value)                   (PIO_PDSR_P24_Msk & (_UINT32_(value) << PIO_PDSR_P24_Pos)) /* Assigment of value for P24 in the PIO_PDSR register */
#define PIO_PDSR_P25_Pos                      _UINT32_(25)                                         /* (PIO_PDSR) Input Data Status Position */
#define PIO_PDSR_P25_Msk                      (_UINT32_(0x1) << PIO_PDSR_P25_Pos)                  /* (PIO_PDSR) Input Data Status Mask */
#define PIO_PDSR_P25(value)                   (PIO_PDSR_P25_Msk & (_UINT32_(value) << PIO_PDSR_P25_Pos)) /* Assigment of value for P25 in the PIO_PDSR register */
#define PIO_PDSR_P26_Pos                      _UINT32_(26)                                         /* (PIO_PDSR) Input Data Status Position */
#define PIO_PDSR_P26_Msk                      (_UINT32_(0x1) << PIO_PDSR_P26_Pos)                  /* (PIO_PDSR) Input Data Status Mask */
#define PIO_PDSR_P26(value)                   (PIO_PDSR_P26_Msk & (_UINT32_(value) << PIO_PDSR_P26_Pos)) /* Assigment of value for P26 in the PIO_PDSR register */
#define PIO_PDSR_P27_Pos                      _UINT32_(27)                                         /* (PIO_PDSR) Input Data Status Position */
#define PIO_PDSR_P27_Msk                      (_UINT32_(0x1) << PIO_PDSR_P27_Pos)                  /* (PIO_PDSR) Input Data Status Mask */
#define PIO_PDSR_P27(value)                   (PIO_PDSR_P27_Msk & (_UINT32_(value) << PIO_PDSR_P27_Pos)) /* Assigment of value for P27 in the PIO_PDSR register */
#define PIO_PDSR_P28_Pos                      _UINT32_(28)                                         /* (PIO_PDSR) Input Data Status Position */
#define PIO_PDSR_P28_Msk                      (_UINT32_(0x1) << PIO_PDSR_P28_Pos)                  /* (PIO_PDSR) Input Data Status Mask */
#define PIO_PDSR_P28(value)                   (PIO_PDSR_P28_Msk & (_UINT32_(value) << PIO_PDSR_P28_Pos)) /* Assigment of value for P28 in the PIO_PDSR register */
#define PIO_PDSR_P29_Pos                      _UINT32_(29)                                         /* (PIO_PDSR) Input Data Status Position */
#define PIO_PDSR_P29_Msk                      (_UINT32_(0x1) << PIO_PDSR_P29_Pos)                  /* (PIO_PDSR) Input Data Status Mask */
#define PIO_PDSR_P29(value)                   (PIO_PDSR_P29_Msk & (_UINT32_(value) << PIO_PDSR_P29_Pos)) /* Assigment of value for P29 in the PIO_PDSR register */
#define PIO_PDSR_P30_Pos                      _UINT32_(30)                                         /* (PIO_PDSR) Input Data Status Position */
#define PIO_PDSR_P30_Msk                      (_UINT32_(0x1) << PIO_PDSR_P30_Pos)                  /* (PIO_PDSR) Input Data Status Mask */
#define PIO_PDSR_P30(value)                   (PIO_PDSR_P30_Msk & (_UINT32_(value) << PIO_PDSR_P30_Pos)) /* Assigment of value for P30 in the PIO_PDSR register */
#define PIO_PDSR_P31_Pos                      _UINT32_(31)                                         /* (PIO_PDSR) Input Data Status Position */
#define PIO_PDSR_P31_Msk                      (_UINT32_(0x1) << PIO_PDSR_P31_Pos)                  /* (PIO_PDSR) Input Data Status Mask */
#define PIO_PDSR_P31(value)                   (PIO_PDSR_P31_Msk & (_UINT32_(value) << PIO_PDSR_P31_Pos)) /* Assigment of value for P31 in the PIO_PDSR register */
#define PIO_PDSR_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (PIO_PDSR) Register Mask  */

#define PIO_PDSR_P_Pos                        _UINT32_(0)                                          /* (PIO_PDSR Position) Input Data Status */
#define PIO_PDSR_P_Msk                        (_UINT32_(0xFFFFFFFF) << PIO_PDSR_P_Pos)             /* (PIO_PDSR Mask) P */
#define PIO_PDSR_P(value)                     (PIO_PDSR_P_Msk & (_UINT32_(value) << PIO_PDSR_P_Pos)) 

/* -------- PIO_LOCKSR : (PIO Offset: 0x0C) ( R/ 32) PIO Lock Status Register -------- */
#define PIO_LOCKSR_P0_Pos                     _UINT32_(0)                                          /* (PIO_LOCKSR) Lock Status Position */
#define PIO_LOCKSR_P0_Msk                     (_UINT32_(0x1) << PIO_LOCKSR_P0_Pos)                 /* (PIO_LOCKSR) Lock Status Mask */
#define PIO_LOCKSR_P0(value)                  (PIO_LOCKSR_P0_Msk & (_UINT32_(value) << PIO_LOCKSR_P0_Pos)) /* Assigment of value for P0 in the PIO_LOCKSR register */
#define PIO_LOCKSR_P1_Pos                     _UINT32_(1)                                          /* (PIO_LOCKSR) Lock Status Position */
#define PIO_LOCKSR_P1_Msk                     (_UINT32_(0x1) << PIO_LOCKSR_P1_Pos)                 /* (PIO_LOCKSR) Lock Status Mask */
#define PIO_LOCKSR_P1(value)                  (PIO_LOCKSR_P1_Msk & (_UINT32_(value) << PIO_LOCKSR_P1_Pos)) /* Assigment of value for P1 in the PIO_LOCKSR register */
#define PIO_LOCKSR_P2_Pos                     _UINT32_(2)                                          /* (PIO_LOCKSR) Lock Status Position */
#define PIO_LOCKSR_P2_Msk                     (_UINT32_(0x1) << PIO_LOCKSR_P2_Pos)                 /* (PIO_LOCKSR) Lock Status Mask */
#define PIO_LOCKSR_P2(value)                  (PIO_LOCKSR_P2_Msk & (_UINT32_(value) << PIO_LOCKSR_P2_Pos)) /* Assigment of value for P2 in the PIO_LOCKSR register */
#define PIO_LOCKSR_P3_Pos                     _UINT32_(3)                                          /* (PIO_LOCKSR) Lock Status Position */
#define PIO_LOCKSR_P3_Msk                     (_UINT32_(0x1) << PIO_LOCKSR_P3_Pos)                 /* (PIO_LOCKSR) Lock Status Mask */
#define PIO_LOCKSR_P3(value)                  (PIO_LOCKSR_P3_Msk & (_UINT32_(value) << PIO_LOCKSR_P3_Pos)) /* Assigment of value for P3 in the PIO_LOCKSR register */
#define PIO_LOCKSR_P4_Pos                     _UINT32_(4)                                          /* (PIO_LOCKSR) Lock Status Position */
#define PIO_LOCKSR_P4_Msk                     (_UINT32_(0x1) << PIO_LOCKSR_P4_Pos)                 /* (PIO_LOCKSR) Lock Status Mask */
#define PIO_LOCKSR_P4(value)                  (PIO_LOCKSR_P4_Msk & (_UINT32_(value) << PIO_LOCKSR_P4_Pos)) /* Assigment of value for P4 in the PIO_LOCKSR register */
#define PIO_LOCKSR_P5_Pos                     _UINT32_(5)                                          /* (PIO_LOCKSR) Lock Status Position */
#define PIO_LOCKSR_P5_Msk                     (_UINT32_(0x1) << PIO_LOCKSR_P5_Pos)                 /* (PIO_LOCKSR) Lock Status Mask */
#define PIO_LOCKSR_P5(value)                  (PIO_LOCKSR_P5_Msk & (_UINT32_(value) << PIO_LOCKSR_P5_Pos)) /* Assigment of value for P5 in the PIO_LOCKSR register */
#define PIO_LOCKSR_P6_Pos                     _UINT32_(6)                                          /* (PIO_LOCKSR) Lock Status Position */
#define PIO_LOCKSR_P6_Msk                     (_UINT32_(0x1) << PIO_LOCKSR_P6_Pos)                 /* (PIO_LOCKSR) Lock Status Mask */
#define PIO_LOCKSR_P6(value)                  (PIO_LOCKSR_P6_Msk & (_UINT32_(value) << PIO_LOCKSR_P6_Pos)) /* Assigment of value for P6 in the PIO_LOCKSR register */
#define PIO_LOCKSR_P7_Pos                     _UINT32_(7)                                          /* (PIO_LOCKSR) Lock Status Position */
#define PIO_LOCKSR_P7_Msk                     (_UINT32_(0x1) << PIO_LOCKSR_P7_Pos)                 /* (PIO_LOCKSR) Lock Status Mask */
#define PIO_LOCKSR_P7(value)                  (PIO_LOCKSR_P7_Msk & (_UINT32_(value) << PIO_LOCKSR_P7_Pos)) /* Assigment of value for P7 in the PIO_LOCKSR register */
#define PIO_LOCKSR_P8_Pos                     _UINT32_(8)                                          /* (PIO_LOCKSR) Lock Status Position */
#define PIO_LOCKSR_P8_Msk                     (_UINT32_(0x1) << PIO_LOCKSR_P8_Pos)                 /* (PIO_LOCKSR) Lock Status Mask */
#define PIO_LOCKSR_P8(value)                  (PIO_LOCKSR_P8_Msk & (_UINT32_(value) << PIO_LOCKSR_P8_Pos)) /* Assigment of value for P8 in the PIO_LOCKSR register */
#define PIO_LOCKSR_P9_Pos                     _UINT32_(9)                                          /* (PIO_LOCKSR) Lock Status Position */
#define PIO_LOCKSR_P9_Msk                     (_UINT32_(0x1) << PIO_LOCKSR_P9_Pos)                 /* (PIO_LOCKSR) Lock Status Mask */
#define PIO_LOCKSR_P9(value)                  (PIO_LOCKSR_P9_Msk & (_UINT32_(value) << PIO_LOCKSR_P9_Pos)) /* Assigment of value for P9 in the PIO_LOCKSR register */
#define PIO_LOCKSR_P10_Pos                    _UINT32_(10)                                         /* (PIO_LOCKSR) Lock Status Position */
#define PIO_LOCKSR_P10_Msk                    (_UINT32_(0x1) << PIO_LOCKSR_P10_Pos)                /* (PIO_LOCKSR) Lock Status Mask */
#define PIO_LOCKSR_P10(value)                 (PIO_LOCKSR_P10_Msk & (_UINT32_(value) << PIO_LOCKSR_P10_Pos)) /* Assigment of value for P10 in the PIO_LOCKSR register */
#define PIO_LOCKSR_P11_Pos                    _UINT32_(11)                                         /* (PIO_LOCKSR) Lock Status Position */
#define PIO_LOCKSR_P11_Msk                    (_UINT32_(0x1) << PIO_LOCKSR_P11_Pos)                /* (PIO_LOCKSR) Lock Status Mask */
#define PIO_LOCKSR_P11(value)                 (PIO_LOCKSR_P11_Msk & (_UINT32_(value) << PIO_LOCKSR_P11_Pos)) /* Assigment of value for P11 in the PIO_LOCKSR register */
#define PIO_LOCKSR_P12_Pos                    _UINT32_(12)                                         /* (PIO_LOCKSR) Lock Status Position */
#define PIO_LOCKSR_P12_Msk                    (_UINT32_(0x1) << PIO_LOCKSR_P12_Pos)                /* (PIO_LOCKSR) Lock Status Mask */
#define PIO_LOCKSR_P12(value)                 (PIO_LOCKSR_P12_Msk & (_UINT32_(value) << PIO_LOCKSR_P12_Pos)) /* Assigment of value for P12 in the PIO_LOCKSR register */
#define PIO_LOCKSR_P13_Pos                    _UINT32_(13)                                         /* (PIO_LOCKSR) Lock Status Position */
#define PIO_LOCKSR_P13_Msk                    (_UINT32_(0x1) << PIO_LOCKSR_P13_Pos)                /* (PIO_LOCKSR) Lock Status Mask */
#define PIO_LOCKSR_P13(value)                 (PIO_LOCKSR_P13_Msk & (_UINT32_(value) << PIO_LOCKSR_P13_Pos)) /* Assigment of value for P13 in the PIO_LOCKSR register */
#define PIO_LOCKSR_P14_Pos                    _UINT32_(14)                                         /* (PIO_LOCKSR) Lock Status Position */
#define PIO_LOCKSR_P14_Msk                    (_UINT32_(0x1) << PIO_LOCKSR_P14_Pos)                /* (PIO_LOCKSR) Lock Status Mask */
#define PIO_LOCKSR_P14(value)                 (PIO_LOCKSR_P14_Msk & (_UINT32_(value) << PIO_LOCKSR_P14_Pos)) /* Assigment of value for P14 in the PIO_LOCKSR register */
#define PIO_LOCKSR_P15_Pos                    _UINT32_(15)                                         /* (PIO_LOCKSR) Lock Status Position */
#define PIO_LOCKSR_P15_Msk                    (_UINT32_(0x1) << PIO_LOCKSR_P15_Pos)                /* (PIO_LOCKSR) Lock Status Mask */
#define PIO_LOCKSR_P15(value)                 (PIO_LOCKSR_P15_Msk & (_UINT32_(value) << PIO_LOCKSR_P15_Pos)) /* Assigment of value for P15 in the PIO_LOCKSR register */
#define PIO_LOCKSR_P16_Pos                    _UINT32_(16)                                         /* (PIO_LOCKSR) Lock Status Position */
#define PIO_LOCKSR_P16_Msk                    (_UINT32_(0x1) << PIO_LOCKSR_P16_Pos)                /* (PIO_LOCKSR) Lock Status Mask */
#define PIO_LOCKSR_P16(value)                 (PIO_LOCKSR_P16_Msk & (_UINT32_(value) << PIO_LOCKSR_P16_Pos)) /* Assigment of value for P16 in the PIO_LOCKSR register */
#define PIO_LOCKSR_P17_Pos                    _UINT32_(17)                                         /* (PIO_LOCKSR) Lock Status Position */
#define PIO_LOCKSR_P17_Msk                    (_UINT32_(0x1) << PIO_LOCKSR_P17_Pos)                /* (PIO_LOCKSR) Lock Status Mask */
#define PIO_LOCKSR_P17(value)                 (PIO_LOCKSR_P17_Msk & (_UINT32_(value) << PIO_LOCKSR_P17_Pos)) /* Assigment of value for P17 in the PIO_LOCKSR register */
#define PIO_LOCKSR_P18_Pos                    _UINT32_(18)                                         /* (PIO_LOCKSR) Lock Status Position */
#define PIO_LOCKSR_P18_Msk                    (_UINT32_(0x1) << PIO_LOCKSR_P18_Pos)                /* (PIO_LOCKSR) Lock Status Mask */
#define PIO_LOCKSR_P18(value)                 (PIO_LOCKSR_P18_Msk & (_UINT32_(value) << PIO_LOCKSR_P18_Pos)) /* Assigment of value for P18 in the PIO_LOCKSR register */
#define PIO_LOCKSR_P19_Pos                    _UINT32_(19)                                         /* (PIO_LOCKSR) Lock Status Position */
#define PIO_LOCKSR_P19_Msk                    (_UINT32_(0x1) << PIO_LOCKSR_P19_Pos)                /* (PIO_LOCKSR) Lock Status Mask */
#define PIO_LOCKSR_P19(value)                 (PIO_LOCKSR_P19_Msk & (_UINT32_(value) << PIO_LOCKSR_P19_Pos)) /* Assigment of value for P19 in the PIO_LOCKSR register */
#define PIO_LOCKSR_P20_Pos                    _UINT32_(20)                                         /* (PIO_LOCKSR) Lock Status Position */
#define PIO_LOCKSR_P20_Msk                    (_UINT32_(0x1) << PIO_LOCKSR_P20_Pos)                /* (PIO_LOCKSR) Lock Status Mask */
#define PIO_LOCKSR_P20(value)                 (PIO_LOCKSR_P20_Msk & (_UINT32_(value) << PIO_LOCKSR_P20_Pos)) /* Assigment of value for P20 in the PIO_LOCKSR register */
#define PIO_LOCKSR_P21_Pos                    _UINT32_(21)                                         /* (PIO_LOCKSR) Lock Status Position */
#define PIO_LOCKSR_P21_Msk                    (_UINT32_(0x1) << PIO_LOCKSR_P21_Pos)                /* (PIO_LOCKSR) Lock Status Mask */
#define PIO_LOCKSR_P21(value)                 (PIO_LOCKSR_P21_Msk & (_UINT32_(value) << PIO_LOCKSR_P21_Pos)) /* Assigment of value for P21 in the PIO_LOCKSR register */
#define PIO_LOCKSR_P22_Pos                    _UINT32_(22)                                         /* (PIO_LOCKSR) Lock Status Position */
#define PIO_LOCKSR_P22_Msk                    (_UINT32_(0x1) << PIO_LOCKSR_P22_Pos)                /* (PIO_LOCKSR) Lock Status Mask */
#define PIO_LOCKSR_P22(value)                 (PIO_LOCKSR_P22_Msk & (_UINT32_(value) << PIO_LOCKSR_P22_Pos)) /* Assigment of value for P22 in the PIO_LOCKSR register */
#define PIO_LOCKSR_P23_Pos                    _UINT32_(23)                                         /* (PIO_LOCKSR) Lock Status Position */
#define PIO_LOCKSR_P23_Msk                    (_UINT32_(0x1) << PIO_LOCKSR_P23_Pos)                /* (PIO_LOCKSR) Lock Status Mask */
#define PIO_LOCKSR_P23(value)                 (PIO_LOCKSR_P23_Msk & (_UINT32_(value) << PIO_LOCKSR_P23_Pos)) /* Assigment of value for P23 in the PIO_LOCKSR register */
#define PIO_LOCKSR_P24_Pos                    _UINT32_(24)                                         /* (PIO_LOCKSR) Lock Status Position */
#define PIO_LOCKSR_P24_Msk                    (_UINT32_(0x1) << PIO_LOCKSR_P24_Pos)                /* (PIO_LOCKSR) Lock Status Mask */
#define PIO_LOCKSR_P24(value)                 (PIO_LOCKSR_P24_Msk & (_UINT32_(value) << PIO_LOCKSR_P24_Pos)) /* Assigment of value for P24 in the PIO_LOCKSR register */
#define PIO_LOCKSR_P25_Pos                    _UINT32_(25)                                         /* (PIO_LOCKSR) Lock Status Position */
#define PIO_LOCKSR_P25_Msk                    (_UINT32_(0x1) << PIO_LOCKSR_P25_Pos)                /* (PIO_LOCKSR) Lock Status Mask */
#define PIO_LOCKSR_P25(value)                 (PIO_LOCKSR_P25_Msk & (_UINT32_(value) << PIO_LOCKSR_P25_Pos)) /* Assigment of value for P25 in the PIO_LOCKSR register */
#define PIO_LOCKSR_P26_Pos                    _UINT32_(26)                                         /* (PIO_LOCKSR) Lock Status Position */
#define PIO_LOCKSR_P26_Msk                    (_UINT32_(0x1) << PIO_LOCKSR_P26_Pos)                /* (PIO_LOCKSR) Lock Status Mask */
#define PIO_LOCKSR_P26(value)                 (PIO_LOCKSR_P26_Msk & (_UINT32_(value) << PIO_LOCKSR_P26_Pos)) /* Assigment of value for P26 in the PIO_LOCKSR register */
#define PIO_LOCKSR_P27_Pos                    _UINT32_(27)                                         /* (PIO_LOCKSR) Lock Status Position */
#define PIO_LOCKSR_P27_Msk                    (_UINT32_(0x1) << PIO_LOCKSR_P27_Pos)                /* (PIO_LOCKSR) Lock Status Mask */
#define PIO_LOCKSR_P27(value)                 (PIO_LOCKSR_P27_Msk & (_UINT32_(value) << PIO_LOCKSR_P27_Pos)) /* Assigment of value for P27 in the PIO_LOCKSR register */
#define PIO_LOCKSR_P28_Pos                    _UINT32_(28)                                         /* (PIO_LOCKSR) Lock Status Position */
#define PIO_LOCKSR_P28_Msk                    (_UINT32_(0x1) << PIO_LOCKSR_P28_Pos)                /* (PIO_LOCKSR) Lock Status Mask */
#define PIO_LOCKSR_P28(value)                 (PIO_LOCKSR_P28_Msk & (_UINT32_(value) << PIO_LOCKSR_P28_Pos)) /* Assigment of value for P28 in the PIO_LOCKSR register */
#define PIO_LOCKSR_P29_Pos                    _UINT32_(29)                                         /* (PIO_LOCKSR) Lock Status Position */
#define PIO_LOCKSR_P29_Msk                    (_UINT32_(0x1) << PIO_LOCKSR_P29_Pos)                /* (PIO_LOCKSR) Lock Status Mask */
#define PIO_LOCKSR_P29(value)                 (PIO_LOCKSR_P29_Msk & (_UINT32_(value) << PIO_LOCKSR_P29_Pos)) /* Assigment of value for P29 in the PIO_LOCKSR register */
#define PIO_LOCKSR_P30_Pos                    _UINT32_(30)                                         /* (PIO_LOCKSR) Lock Status Position */
#define PIO_LOCKSR_P30_Msk                    (_UINT32_(0x1) << PIO_LOCKSR_P30_Pos)                /* (PIO_LOCKSR) Lock Status Mask */
#define PIO_LOCKSR_P30(value)                 (PIO_LOCKSR_P30_Msk & (_UINT32_(value) << PIO_LOCKSR_P30_Pos)) /* Assigment of value for P30 in the PIO_LOCKSR register */
#define PIO_LOCKSR_P31_Pos                    _UINT32_(31)                                         /* (PIO_LOCKSR) Lock Status Position */
#define PIO_LOCKSR_P31_Msk                    (_UINT32_(0x1) << PIO_LOCKSR_P31_Pos)                /* (PIO_LOCKSR) Lock Status Mask */
#define PIO_LOCKSR_P31(value)                 (PIO_LOCKSR_P31_Msk & (_UINT32_(value) << PIO_LOCKSR_P31_Pos)) /* Assigment of value for P31 in the PIO_LOCKSR register */
#define PIO_LOCKSR_Msk                        _UINT32_(0xFFFFFFFF)                                 /* (PIO_LOCKSR) Register Mask  */

#define PIO_LOCKSR_P_Pos                      _UINT32_(0)                                          /* (PIO_LOCKSR Position) Lock Status */
#define PIO_LOCKSR_P_Msk                      (_UINT32_(0xFFFFFFFF) << PIO_LOCKSR_P_Pos)           /* (PIO_LOCKSR Mask) P */
#define PIO_LOCKSR_P(value)                   (PIO_LOCKSR_P_Msk & (_UINT32_(value) << PIO_LOCKSR_P_Pos)) 

/* -------- PIO_SODR : (PIO Offset: 0x10) ( /W 32) PIO Set Output Data Register -------- */
#define PIO_SODR_P0_Pos                       _UINT32_(0)                                          /* (PIO_SODR) Set Output Data Position */
#define PIO_SODR_P0_Msk                       (_UINT32_(0x1) << PIO_SODR_P0_Pos)                   /* (PIO_SODR) Set Output Data Mask */
#define PIO_SODR_P0(value)                    (PIO_SODR_P0_Msk & (_UINT32_(value) << PIO_SODR_P0_Pos)) /* Assigment of value for P0 in the PIO_SODR register */
#define PIO_SODR_P1_Pos                       _UINT32_(1)                                          /* (PIO_SODR) Set Output Data Position */
#define PIO_SODR_P1_Msk                       (_UINT32_(0x1) << PIO_SODR_P1_Pos)                   /* (PIO_SODR) Set Output Data Mask */
#define PIO_SODR_P1(value)                    (PIO_SODR_P1_Msk & (_UINT32_(value) << PIO_SODR_P1_Pos)) /* Assigment of value for P1 in the PIO_SODR register */
#define PIO_SODR_P2_Pos                       _UINT32_(2)                                          /* (PIO_SODR) Set Output Data Position */
#define PIO_SODR_P2_Msk                       (_UINT32_(0x1) << PIO_SODR_P2_Pos)                   /* (PIO_SODR) Set Output Data Mask */
#define PIO_SODR_P2(value)                    (PIO_SODR_P2_Msk & (_UINT32_(value) << PIO_SODR_P2_Pos)) /* Assigment of value for P2 in the PIO_SODR register */
#define PIO_SODR_P3_Pos                       _UINT32_(3)                                          /* (PIO_SODR) Set Output Data Position */
#define PIO_SODR_P3_Msk                       (_UINT32_(0x1) << PIO_SODR_P3_Pos)                   /* (PIO_SODR) Set Output Data Mask */
#define PIO_SODR_P3(value)                    (PIO_SODR_P3_Msk & (_UINT32_(value) << PIO_SODR_P3_Pos)) /* Assigment of value for P3 in the PIO_SODR register */
#define PIO_SODR_P4_Pos                       _UINT32_(4)                                          /* (PIO_SODR) Set Output Data Position */
#define PIO_SODR_P4_Msk                       (_UINT32_(0x1) << PIO_SODR_P4_Pos)                   /* (PIO_SODR) Set Output Data Mask */
#define PIO_SODR_P4(value)                    (PIO_SODR_P4_Msk & (_UINT32_(value) << PIO_SODR_P4_Pos)) /* Assigment of value for P4 in the PIO_SODR register */
#define PIO_SODR_P5_Pos                       _UINT32_(5)                                          /* (PIO_SODR) Set Output Data Position */
#define PIO_SODR_P5_Msk                       (_UINT32_(0x1) << PIO_SODR_P5_Pos)                   /* (PIO_SODR) Set Output Data Mask */
#define PIO_SODR_P5(value)                    (PIO_SODR_P5_Msk & (_UINT32_(value) << PIO_SODR_P5_Pos)) /* Assigment of value for P5 in the PIO_SODR register */
#define PIO_SODR_P6_Pos                       _UINT32_(6)                                          /* (PIO_SODR) Set Output Data Position */
#define PIO_SODR_P6_Msk                       (_UINT32_(0x1) << PIO_SODR_P6_Pos)                   /* (PIO_SODR) Set Output Data Mask */
#define PIO_SODR_P6(value)                    (PIO_SODR_P6_Msk & (_UINT32_(value) << PIO_SODR_P6_Pos)) /* Assigment of value for P6 in the PIO_SODR register */
#define PIO_SODR_P7_Pos                       _UINT32_(7)                                          /* (PIO_SODR) Set Output Data Position */
#define PIO_SODR_P7_Msk                       (_UINT32_(0x1) << PIO_SODR_P7_Pos)                   /* (PIO_SODR) Set Output Data Mask */
#define PIO_SODR_P7(value)                    (PIO_SODR_P7_Msk & (_UINT32_(value) << PIO_SODR_P7_Pos)) /* Assigment of value for P7 in the PIO_SODR register */
#define PIO_SODR_P8_Pos                       _UINT32_(8)                                          /* (PIO_SODR) Set Output Data Position */
#define PIO_SODR_P8_Msk                       (_UINT32_(0x1) << PIO_SODR_P8_Pos)                   /* (PIO_SODR) Set Output Data Mask */
#define PIO_SODR_P8(value)                    (PIO_SODR_P8_Msk & (_UINT32_(value) << PIO_SODR_P8_Pos)) /* Assigment of value for P8 in the PIO_SODR register */
#define PIO_SODR_P9_Pos                       _UINT32_(9)                                          /* (PIO_SODR) Set Output Data Position */
#define PIO_SODR_P9_Msk                       (_UINT32_(0x1) << PIO_SODR_P9_Pos)                   /* (PIO_SODR) Set Output Data Mask */
#define PIO_SODR_P9(value)                    (PIO_SODR_P9_Msk & (_UINT32_(value) << PIO_SODR_P9_Pos)) /* Assigment of value for P9 in the PIO_SODR register */
#define PIO_SODR_P10_Pos                      _UINT32_(10)                                         /* (PIO_SODR) Set Output Data Position */
#define PIO_SODR_P10_Msk                      (_UINT32_(0x1) << PIO_SODR_P10_Pos)                  /* (PIO_SODR) Set Output Data Mask */
#define PIO_SODR_P10(value)                   (PIO_SODR_P10_Msk & (_UINT32_(value) << PIO_SODR_P10_Pos)) /* Assigment of value for P10 in the PIO_SODR register */
#define PIO_SODR_P11_Pos                      _UINT32_(11)                                         /* (PIO_SODR) Set Output Data Position */
#define PIO_SODR_P11_Msk                      (_UINT32_(0x1) << PIO_SODR_P11_Pos)                  /* (PIO_SODR) Set Output Data Mask */
#define PIO_SODR_P11(value)                   (PIO_SODR_P11_Msk & (_UINT32_(value) << PIO_SODR_P11_Pos)) /* Assigment of value for P11 in the PIO_SODR register */
#define PIO_SODR_P12_Pos                      _UINT32_(12)                                         /* (PIO_SODR) Set Output Data Position */
#define PIO_SODR_P12_Msk                      (_UINT32_(0x1) << PIO_SODR_P12_Pos)                  /* (PIO_SODR) Set Output Data Mask */
#define PIO_SODR_P12(value)                   (PIO_SODR_P12_Msk & (_UINT32_(value) << PIO_SODR_P12_Pos)) /* Assigment of value for P12 in the PIO_SODR register */
#define PIO_SODR_P13_Pos                      _UINT32_(13)                                         /* (PIO_SODR) Set Output Data Position */
#define PIO_SODR_P13_Msk                      (_UINT32_(0x1) << PIO_SODR_P13_Pos)                  /* (PIO_SODR) Set Output Data Mask */
#define PIO_SODR_P13(value)                   (PIO_SODR_P13_Msk & (_UINT32_(value) << PIO_SODR_P13_Pos)) /* Assigment of value for P13 in the PIO_SODR register */
#define PIO_SODR_P14_Pos                      _UINT32_(14)                                         /* (PIO_SODR) Set Output Data Position */
#define PIO_SODR_P14_Msk                      (_UINT32_(0x1) << PIO_SODR_P14_Pos)                  /* (PIO_SODR) Set Output Data Mask */
#define PIO_SODR_P14(value)                   (PIO_SODR_P14_Msk & (_UINT32_(value) << PIO_SODR_P14_Pos)) /* Assigment of value for P14 in the PIO_SODR register */
#define PIO_SODR_P15_Pos                      _UINT32_(15)                                         /* (PIO_SODR) Set Output Data Position */
#define PIO_SODR_P15_Msk                      (_UINT32_(0x1) << PIO_SODR_P15_Pos)                  /* (PIO_SODR) Set Output Data Mask */
#define PIO_SODR_P15(value)                   (PIO_SODR_P15_Msk & (_UINT32_(value) << PIO_SODR_P15_Pos)) /* Assigment of value for P15 in the PIO_SODR register */
#define PIO_SODR_P16_Pos                      _UINT32_(16)                                         /* (PIO_SODR) Set Output Data Position */
#define PIO_SODR_P16_Msk                      (_UINT32_(0x1) << PIO_SODR_P16_Pos)                  /* (PIO_SODR) Set Output Data Mask */
#define PIO_SODR_P16(value)                   (PIO_SODR_P16_Msk & (_UINT32_(value) << PIO_SODR_P16_Pos)) /* Assigment of value for P16 in the PIO_SODR register */
#define PIO_SODR_P17_Pos                      _UINT32_(17)                                         /* (PIO_SODR) Set Output Data Position */
#define PIO_SODR_P17_Msk                      (_UINT32_(0x1) << PIO_SODR_P17_Pos)                  /* (PIO_SODR) Set Output Data Mask */
#define PIO_SODR_P17(value)                   (PIO_SODR_P17_Msk & (_UINT32_(value) << PIO_SODR_P17_Pos)) /* Assigment of value for P17 in the PIO_SODR register */
#define PIO_SODR_P18_Pos                      _UINT32_(18)                                         /* (PIO_SODR) Set Output Data Position */
#define PIO_SODR_P18_Msk                      (_UINT32_(0x1) << PIO_SODR_P18_Pos)                  /* (PIO_SODR) Set Output Data Mask */
#define PIO_SODR_P18(value)                   (PIO_SODR_P18_Msk & (_UINT32_(value) << PIO_SODR_P18_Pos)) /* Assigment of value for P18 in the PIO_SODR register */
#define PIO_SODR_P19_Pos                      _UINT32_(19)                                         /* (PIO_SODR) Set Output Data Position */
#define PIO_SODR_P19_Msk                      (_UINT32_(0x1) << PIO_SODR_P19_Pos)                  /* (PIO_SODR) Set Output Data Mask */
#define PIO_SODR_P19(value)                   (PIO_SODR_P19_Msk & (_UINT32_(value) << PIO_SODR_P19_Pos)) /* Assigment of value for P19 in the PIO_SODR register */
#define PIO_SODR_P20_Pos                      _UINT32_(20)                                         /* (PIO_SODR) Set Output Data Position */
#define PIO_SODR_P20_Msk                      (_UINT32_(0x1) << PIO_SODR_P20_Pos)                  /* (PIO_SODR) Set Output Data Mask */
#define PIO_SODR_P20(value)                   (PIO_SODR_P20_Msk & (_UINT32_(value) << PIO_SODR_P20_Pos)) /* Assigment of value for P20 in the PIO_SODR register */
#define PIO_SODR_P21_Pos                      _UINT32_(21)                                         /* (PIO_SODR) Set Output Data Position */
#define PIO_SODR_P21_Msk                      (_UINT32_(0x1) << PIO_SODR_P21_Pos)                  /* (PIO_SODR) Set Output Data Mask */
#define PIO_SODR_P21(value)                   (PIO_SODR_P21_Msk & (_UINT32_(value) << PIO_SODR_P21_Pos)) /* Assigment of value for P21 in the PIO_SODR register */
#define PIO_SODR_P22_Pos                      _UINT32_(22)                                         /* (PIO_SODR) Set Output Data Position */
#define PIO_SODR_P22_Msk                      (_UINT32_(0x1) << PIO_SODR_P22_Pos)                  /* (PIO_SODR) Set Output Data Mask */
#define PIO_SODR_P22(value)                   (PIO_SODR_P22_Msk & (_UINT32_(value) << PIO_SODR_P22_Pos)) /* Assigment of value for P22 in the PIO_SODR register */
#define PIO_SODR_P23_Pos                      _UINT32_(23)                                         /* (PIO_SODR) Set Output Data Position */
#define PIO_SODR_P23_Msk                      (_UINT32_(0x1) << PIO_SODR_P23_Pos)                  /* (PIO_SODR) Set Output Data Mask */
#define PIO_SODR_P23(value)                   (PIO_SODR_P23_Msk & (_UINT32_(value) << PIO_SODR_P23_Pos)) /* Assigment of value for P23 in the PIO_SODR register */
#define PIO_SODR_P24_Pos                      _UINT32_(24)                                         /* (PIO_SODR) Set Output Data Position */
#define PIO_SODR_P24_Msk                      (_UINT32_(0x1) << PIO_SODR_P24_Pos)                  /* (PIO_SODR) Set Output Data Mask */
#define PIO_SODR_P24(value)                   (PIO_SODR_P24_Msk & (_UINT32_(value) << PIO_SODR_P24_Pos)) /* Assigment of value for P24 in the PIO_SODR register */
#define PIO_SODR_P25_Pos                      _UINT32_(25)                                         /* (PIO_SODR) Set Output Data Position */
#define PIO_SODR_P25_Msk                      (_UINT32_(0x1) << PIO_SODR_P25_Pos)                  /* (PIO_SODR) Set Output Data Mask */
#define PIO_SODR_P25(value)                   (PIO_SODR_P25_Msk & (_UINT32_(value) << PIO_SODR_P25_Pos)) /* Assigment of value for P25 in the PIO_SODR register */
#define PIO_SODR_P26_Pos                      _UINT32_(26)                                         /* (PIO_SODR) Set Output Data Position */
#define PIO_SODR_P26_Msk                      (_UINT32_(0x1) << PIO_SODR_P26_Pos)                  /* (PIO_SODR) Set Output Data Mask */
#define PIO_SODR_P26(value)                   (PIO_SODR_P26_Msk & (_UINT32_(value) << PIO_SODR_P26_Pos)) /* Assigment of value for P26 in the PIO_SODR register */
#define PIO_SODR_P27_Pos                      _UINT32_(27)                                         /* (PIO_SODR) Set Output Data Position */
#define PIO_SODR_P27_Msk                      (_UINT32_(0x1) << PIO_SODR_P27_Pos)                  /* (PIO_SODR) Set Output Data Mask */
#define PIO_SODR_P27(value)                   (PIO_SODR_P27_Msk & (_UINT32_(value) << PIO_SODR_P27_Pos)) /* Assigment of value for P27 in the PIO_SODR register */
#define PIO_SODR_P28_Pos                      _UINT32_(28)                                         /* (PIO_SODR) Set Output Data Position */
#define PIO_SODR_P28_Msk                      (_UINT32_(0x1) << PIO_SODR_P28_Pos)                  /* (PIO_SODR) Set Output Data Mask */
#define PIO_SODR_P28(value)                   (PIO_SODR_P28_Msk & (_UINT32_(value) << PIO_SODR_P28_Pos)) /* Assigment of value for P28 in the PIO_SODR register */
#define PIO_SODR_P29_Pos                      _UINT32_(29)                                         /* (PIO_SODR) Set Output Data Position */
#define PIO_SODR_P29_Msk                      (_UINT32_(0x1) << PIO_SODR_P29_Pos)                  /* (PIO_SODR) Set Output Data Mask */
#define PIO_SODR_P29(value)                   (PIO_SODR_P29_Msk & (_UINT32_(value) << PIO_SODR_P29_Pos)) /* Assigment of value for P29 in the PIO_SODR register */
#define PIO_SODR_P30_Pos                      _UINT32_(30)                                         /* (PIO_SODR) Set Output Data Position */
#define PIO_SODR_P30_Msk                      (_UINT32_(0x1) << PIO_SODR_P30_Pos)                  /* (PIO_SODR) Set Output Data Mask */
#define PIO_SODR_P30(value)                   (PIO_SODR_P30_Msk & (_UINT32_(value) << PIO_SODR_P30_Pos)) /* Assigment of value for P30 in the PIO_SODR register */
#define PIO_SODR_P31_Pos                      _UINT32_(31)                                         /* (PIO_SODR) Set Output Data Position */
#define PIO_SODR_P31_Msk                      (_UINT32_(0x1) << PIO_SODR_P31_Pos)                  /* (PIO_SODR) Set Output Data Mask */
#define PIO_SODR_P31(value)                   (PIO_SODR_P31_Msk & (_UINT32_(value) << PIO_SODR_P31_Pos)) /* Assigment of value for P31 in the PIO_SODR register */
#define PIO_SODR_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (PIO_SODR) Register Mask  */

#define PIO_SODR_P_Pos                        _UINT32_(0)                                          /* (PIO_SODR Position) Set Output Data */
#define PIO_SODR_P_Msk                        (_UINT32_(0xFFFFFFFF) << PIO_SODR_P_Pos)             /* (PIO_SODR Mask) P */
#define PIO_SODR_P(value)                     (PIO_SODR_P_Msk & (_UINT32_(value) << PIO_SODR_P_Pos)) 

/* -------- PIO_CODR : (PIO Offset: 0x14) ( /W 32) PIO Clear Output Data Register -------- */
#define PIO_CODR_P0_Pos                       _UINT32_(0)                                          /* (PIO_CODR) Clear Output Data Position */
#define PIO_CODR_P0_Msk                       (_UINT32_(0x1) << PIO_CODR_P0_Pos)                   /* (PIO_CODR) Clear Output Data Mask */
#define PIO_CODR_P0(value)                    (PIO_CODR_P0_Msk & (_UINT32_(value) << PIO_CODR_P0_Pos)) /* Assigment of value for P0 in the PIO_CODR register */
#define PIO_CODR_P1_Pos                       _UINT32_(1)                                          /* (PIO_CODR) Clear Output Data Position */
#define PIO_CODR_P1_Msk                       (_UINT32_(0x1) << PIO_CODR_P1_Pos)                   /* (PIO_CODR) Clear Output Data Mask */
#define PIO_CODR_P1(value)                    (PIO_CODR_P1_Msk & (_UINT32_(value) << PIO_CODR_P1_Pos)) /* Assigment of value for P1 in the PIO_CODR register */
#define PIO_CODR_P2_Pos                       _UINT32_(2)                                          /* (PIO_CODR) Clear Output Data Position */
#define PIO_CODR_P2_Msk                       (_UINT32_(0x1) << PIO_CODR_P2_Pos)                   /* (PIO_CODR) Clear Output Data Mask */
#define PIO_CODR_P2(value)                    (PIO_CODR_P2_Msk & (_UINT32_(value) << PIO_CODR_P2_Pos)) /* Assigment of value for P2 in the PIO_CODR register */
#define PIO_CODR_P3_Pos                       _UINT32_(3)                                          /* (PIO_CODR) Clear Output Data Position */
#define PIO_CODR_P3_Msk                       (_UINT32_(0x1) << PIO_CODR_P3_Pos)                   /* (PIO_CODR) Clear Output Data Mask */
#define PIO_CODR_P3(value)                    (PIO_CODR_P3_Msk & (_UINT32_(value) << PIO_CODR_P3_Pos)) /* Assigment of value for P3 in the PIO_CODR register */
#define PIO_CODR_P4_Pos                       _UINT32_(4)                                          /* (PIO_CODR) Clear Output Data Position */
#define PIO_CODR_P4_Msk                       (_UINT32_(0x1) << PIO_CODR_P4_Pos)                   /* (PIO_CODR) Clear Output Data Mask */
#define PIO_CODR_P4(value)                    (PIO_CODR_P4_Msk & (_UINT32_(value) << PIO_CODR_P4_Pos)) /* Assigment of value for P4 in the PIO_CODR register */
#define PIO_CODR_P5_Pos                       _UINT32_(5)                                          /* (PIO_CODR) Clear Output Data Position */
#define PIO_CODR_P5_Msk                       (_UINT32_(0x1) << PIO_CODR_P5_Pos)                   /* (PIO_CODR) Clear Output Data Mask */
#define PIO_CODR_P5(value)                    (PIO_CODR_P5_Msk & (_UINT32_(value) << PIO_CODR_P5_Pos)) /* Assigment of value for P5 in the PIO_CODR register */
#define PIO_CODR_P6_Pos                       _UINT32_(6)                                          /* (PIO_CODR) Clear Output Data Position */
#define PIO_CODR_P6_Msk                       (_UINT32_(0x1) << PIO_CODR_P6_Pos)                   /* (PIO_CODR) Clear Output Data Mask */
#define PIO_CODR_P6(value)                    (PIO_CODR_P6_Msk & (_UINT32_(value) << PIO_CODR_P6_Pos)) /* Assigment of value for P6 in the PIO_CODR register */
#define PIO_CODR_P7_Pos                       _UINT32_(7)                                          /* (PIO_CODR) Clear Output Data Position */
#define PIO_CODR_P7_Msk                       (_UINT32_(0x1) << PIO_CODR_P7_Pos)                   /* (PIO_CODR) Clear Output Data Mask */
#define PIO_CODR_P7(value)                    (PIO_CODR_P7_Msk & (_UINT32_(value) << PIO_CODR_P7_Pos)) /* Assigment of value for P7 in the PIO_CODR register */
#define PIO_CODR_P8_Pos                       _UINT32_(8)                                          /* (PIO_CODR) Clear Output Data Position */
#define PIO_CODR_P8_Msk                       (_UINT32_(0x1) << PIO_CODR_P8_Pos)                   /* (PIO_CODR) Clear Output Data Mask */
#define PIO_CODR_P8(value)                    (PIO_CODR_P8_Msk & (_UINT32_(value) << PIO_CODR_P8_Pos)) /* Assigment of value for P8 in the PIO_CODR register */
#define PIO_CODR_P9_Pos                       _UINT32_(9)                                          /* (PIO_CODR) Clear Output Data Position */
#define PIO_CODR_P9_Msk                       (_UINT32_(0x1) << PIO_CODR_P9_Pos)                   /* (PIO_CODR) Clear Output Data Mask */
#define PIO_CODR_P9(value)                    (PIO_CODR_P9_Msk & (_UINT32_(value) << PIO_CODR_P9_Pos)) /* Assigment of value for P9 in the PIO_CODR register */
#define PIO_CODR_P10_Pos                      _UINT32_(10)                                         /* (PIO_CODR) Clear Output Data Position */
#define PIO_CODR_P10_Msk                      (_UINT32_(0x1) << PIO_CODR_P10_Pos)                  /* (PIO_CODR) Clear Output Data Mask */
#define PIO_CODR_P10(value)                   (PIO_CODR_P10_Msk & (_UINT32_(value) << PIO_CODR_P10_Pos)) /* Assigment of value for P10 in the PIO_CODR register */
#define PIO_CODR_P11_Pos                      _UINT32_(11)                                         /* (PIO_CODR) Clear Output Data Position */
#define PIO_CODR_P11_Msk                      (_UINT32_(0x1) << PIO_CODR_P11_Pos)                  /* (PIO_CODR) Clear Output Data Mask */
#define PIO_CODR_P11(value)                   (PIO_CODR_P11_Msk & (_UINT32_(value) << PIO_CODR_P11_Pos)) /* Assigment of value for P11 in the PIO_CODR register */
#define PIO_CODR_P12_Pos                      _UINT32_(12)                                         /* (PIO_CODR) Clear Output Data Position */
#define PIO_CODR_P12_Msk                      (_UINT32_(0x1) << PIO_CODR_P12_Pos)                  /* (PIO_CODR) Clear Output Data Mask */
#define PIO_CODR_P12(value)                   (PIO_CODR_P12_Msk & (_UINT32_(value) << PIO_CODR_P12_Pos)) /* Assigment of value for P12 in the PIO_CODR register */
#define PIO_CODR_P13_Pos                      _UINT32_(13)                                         /* (PIO_CODR) Clear Output Data Position */
#define PIO_CODR_P13_Msk                      (_UINT32_(0x1) << PIO_CODR_P13_Pos)                  /* (PIO_CODR) Clear Output Data Mask */
#define PIO_CODR_P13(value)                   (PIO_CODR_P13_Msk & (_UINT32_(value) << PIO_CODR_P13_Pos)) /* Assigment of value for P13 in the PIO_CODR register */
#define PIO_CODR_P14_Pos                      _UINT32_(14)                                         /* (PIO_CODR) Clear Output Data Position */
#define PIO_CODR_P14_Msk                      (_UINT32_(0x1) << PIO_CODR_P14_Pos)                  /* (PIO_CODR) Clear Output Data Mask */
#define PIO_CODR_P14(value)                   (PIO_CODR_P14_Msk & (_UINT32_(value) << PIO_CODR_P14_Pos)) /* Assigment of value for P14 in the PIO_CODR register */
#define PIO_CODR_P15_Pos                      _UINT32_(15)                                         /* (PIO_CODR) Clear Output Data Position */
#define PIO_CODR_P15_Msk                      (_UINT32_(0x1) << PIO_CODR_P15_Pos)                  /* (PIO_CODR) Clear Output Data Mask */
#define PIO_CODR_P15(value)                   (PIO_CODR_P15_Msk & (_UINT32_(value) << PIO_CODR_P15_Pos)) /* Assigment of value for P15 in the PIO_CODR register */
#define PIO_CODR_P16_Pos                      _UINT32_(16)                                         /* (PIO_CODR) Clear Output Data Position */
#define PIO_CODR_P16_Msk                      (_UINT32_(0x1) << PIO_CODR_P16_Pos)                  /* (PIO_CODR) Clear Output Data Mask */
#define PIO_CODR_P16(value)                   (PIO_CODR_P16_Msk & (_UINT32_(value) << PIO_CODR_P16_Pos)) /* Assigment of value for P16 in the PIO_CODR register */
#define PIO_CODR_P17_Pos                      _UINT32_(17)                                         /* (PIO_CODR) Clear Output Data Position */
#define PIO_CODR_P17_Msk                      (_UINT32_(0x1) << PIO_CODR_P17_Pos)                  /* (PIO_CODR) Clear Output Data Mask */
#define PIO_CODR_P17(value)                   (PIO_CODR_P17_Msk & (_UINT32_(value) << PIO_CODR_P17_Pos)) /* Assigment of value for P17 in the PIO_CODR register */
#define PIO_CODR_P18_Pos                      _UINT32_(18)                                         /* (PIO_CODR) Clear Output Data Position */
#define PIO_CODR_P18_Msk                      (_UINT32_(0x1) << PIO_CODR_P18_Pos)                  /* (PIO_CODR) Clear Output Data Mask */
#define PIO_CODR_P18(value)                   (PIO_CODR_P18_Msk & (_UINT32_(value) << PIO_CODR_P18_Pos)) /* Assigment of value for P18 in the PIO_CODR register */
#define PIO_CODR_P19_Pos                      _UINT32_(19)                                         /* (PIO_CODR) Clear Output Data Position */
#define PIO_CODR_P19_Msk                      (_UINT32_(0x1) << PIO_CODR_P19_Pos)                  /* (PIO_CODR) Clear Output Data Mask */
#define PIO_CODR_P19(value)                   (PIO_CODR_P19_Msk & (_UINT32_(value) << PIO_CODR_P19_Pos)) /* Assigment of value for P19 in the PIO_CODR register */
#define PIO_CODR_P20_Pos                      _UINT32_(20)                                         /* (PIO_CODR) Clear Output Data Position */
#define PIO_CODR_P20_Msk                      (_UINT32_(0x1) << PIO_CODR_P20_Pos)                  /* (PIO_CODR) Clear Output Data Mask */
#define PIO_CODR_P20(value)                   (PIO_CODR_P20_Msk & (_UINT32_(value) << PIO_CODR_P20_Pos)) /* Assigment of value for P20 in the PIO_CODR register */
#define PIO_CODR_P21_Pos                      _UINT32_(21)                                         /* (PIO_CODR) Clear Output Data Position */
#define PIO_CODR_P21_Msk                      (_UINT32_(0x1) << PIO_CODR_P21_Pos)                  /* (PIO_CODR) Clear Output Data Mask */
#define PIO_CODR_P21(value)                   (PIO_CODR_P21_Msk & (_UINT32_(value) << PIO_CODR_P21_Pos)) /* Assigment of value for P21 in the PIO_CODR register */
#define PIO_CODR_P22_Pos                      _UINT32_(22)                                         /* (PIO_CODR) Clear Output Data Position */
#define PIO_CODR_P22_Msk                      (_UINT32_(0x1) << PIO_CODR_P22_Pos)                  /* (PIO_CODR) Clear Output Data Mask */
#define PIO_CODR_P22(value)                   (PIO_CODR_P22_Msk & (_UINT32_(value) << PIO_CODR_P22_Pos)) /* Assigment of value for P22 in the PIO_CODR register */
#define PIO_CODR_P23_Pos                      _UINT32_(23)                                         /* (PIO_CODR) Clear Output Data Position */
#define PIO_CODR_P23_Msk                      (_UINT32_(0x1) << PIO_CODR_P23_Pos)                  /* (PIO_CODR) Clear Output Data Mask */
#define PIO_CODR_P23(value)                   (PIO_CODR_P23_Msk & (_UINT32_(value) << PIO_CODR_P23_Pos)) /* Assigment of value for P23 in the PIO_CODR register */
#define PIO_CODR_P24_Pos                      _UINT32_(24)                                         /* (PIO_CODR) Clear Output Data Position */
#define PIO_CODR_P24_Msk                      (_UINT32_(0x1) << PIO_CODR_P24_Pos)                  /* (PIO_CODR) Clear Output Data Mask */
#define PIO_CODR_P24(value)                   (PIO_CODR_P24_Msk & (_UINT32_(value) << PIO_CODR_P24_Pos)) /* Assigment of value for P24 in the PIO_CODR register */
#define PIO_CODR_P25_Pos                      _UINT32_(25)                                         /* (PIO_CODR) Clear Output Data Position */
#define PIO_CODR_P25_Msk                      (_UINT32_(0x1) << PIO_CODR_P25_Pos)                  /* (PIO_CODR) Clear Output Data Mask */
#define PIO_CODR_P25(value)                   (PIO_CODR_P25_Msk & (_UINT32_(value) << PIO_CODR_P25_Pos)) /* Assigment of value for P25 in the PIO_CODR register */
#define PIO_CODR_P26_Pos                      _UINT32_(26)                                         /* (PIO_CODR) Clear Output Data Position */
#define PIO_CODR_P26_Msk                      (_UINT32_(0x1) << PIO_CODR_P26_Pos)                  /* (PIO_CODR) Clear Output Data Mask */
#define PIO_CODR_P26(value)                   (PIO_CODR_P26_Msk & (_UINT32_(value) << PIO_CODR_P26_Pos)) /* Assigment of value for P26 in the PIO_CODR register */
#define PIO_CODR_P27_Pos                      _UINT32_(27)                                         /* (PIO_CODR) Clear Output Data Position */
#define PIO_CODR_P27_Msk                      (_UINT32_(0x1) << PIO_CODR_P27_Pos)                  /* (PIO_CODR) Clear Output Data Mask */
#define PIO_CODR_P27(value)                   (PIO_CODR_P27_Msk & (_UINT32_(value) << PIO_CODR_P27_Pos)) /* Assigment of value for P27 in the PIO_CODR register */
#define PIO_CODR_P28_Pos                      _UINT32_(28)                                         /* (PIO_CODR) Clear Output Data Position */
#define PIO_CODR_P28_Msk                      (_UINT32_(0x1) << PIO_CODR_P28_Pos)                  /* (PIO_CODR) Clear Output Data Mask */
#define PIO_CODR_P28(value)                   (PIO_CODR_P28_Msk & (_UINT32_(value) << PIO_CODR_P28_Pos)) /* Assigment of value for P28 in the PIO_CODR register */
#define PIO_CODR_P29_Pos                      _UINT32_(29)                                         /* (PIO_CODR) Clear Output Data Position */
#define PIO_CODR_P29_Msk                      (_UINT32_(0x1) << PIO_CODR_P29_Pos)                  /* (PIO_CODR) Clear Output Data Mask */
#define PIO_CODR_P29(value)                   (PIO_CODR_P29_Msk & (_UINT32_(value) << PIO_CODR_P29_Pos)) /* Assigment of value for P29 in the PIO_CODR register */
#define PIO_CODR_P30_Pos                      _UINT32_(30)                                         /* (PIO_CODR) Clear Output Data Position */
#define PIO_CODR_P30_Msk                      (_UINT32_(0x1) << PIO_CODR_P30_Pos)                  /* (PIO_CODR) Clear Output Data Mask */
#define PIO_CODR_P30(value)                   (PIO_CODR_P30_Msk & (_UINT32_(value) << PIO_CODR_P30_Pos)) /* Assigment of value for P30 in the PIO_CODR register */
#define PIO_CODR_P31_Pos                      _UINT32_(31)                                         /* (PIO_CODR) Clear Output Data Position */
#define PIO_CODR_P31_Msk                      (_UINT32_(0x1) << PIO_CODR_P31_Pos)                  /* (PIO_CODR) Clear Output Data Mask */
#define PIO_CODR_P31(value)                   (PIO_CODR_P31_Msk & (_UINT32_(value) << PIO_CODR_P31_Pos)) /* Assigment of value for P31 in the PIO_CODR register */
#define PIO_CODR_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (PIO_CODR) Register Mask  */

#define PIO_CODR_P_Pos                        _UINT32_(0)                                          /* (PIO_CODR Position) Clear Output Data */
#define PIO_CODR_P_Msk                        (_UINT32_(0xFFFFFFFF) << PIO_CODR_P_Pos)             /* (PIO_CODR Mask) P */
#define PIO_CODR_P(value)                     (PIO_CODR_P_Msk & (_UINT32_(value) << PIO_CODR_P_Pos)) 

/* -------- PIO_ODSR : (PIO Offset: 0x18) (R/W 32) PIO Output Data Status Register -------- */
#define PIO_ODSR_P0_Pos                       _UINT32_(0)                                          /* (PIO_ODSR) Output Data Status Position */
#define PIO_ODSR_P0_Msk                       (_UINT32_(0x1) << PIO_ODSR_P0_Pos)                   /* (PIO_ODSR) Output Data Status Mask */
#define PIO_ODSR_P0(value)                    (PIO_ODSR_P0_Msk & (_UINT32_(value) << PIO_ODSR_P0_Pos)) /* Assigment of value for P0 in the PIO_ODSR register */
#define PIO_ODSR_P1_Pos                       _UINT32_(1)                                          /* (PIO_ODSR) Output Data Status Position */
#define PIO_ODSR_P1_Msk                       (_UINT32_(0x1) << PIO_ODSR_P1_Pos)                   /* (PIO_ODSR) Output Data Status Mask */
#define PIO_ODSR_P1(value)                    (PIO_ODSR_P1_Msk & (_UINT32_(value) << PIO_ODSR_P1_Pos)) /* Assigment of value for P1 in the PIO_ODSR register */
#define PIO_ODSR_P2_Pos                       _UINT32_(2)                                          /* (PIO_ODSR) Output Data Status Position */
#define PIO_ODSR_P2_Msk                       (_UINT32_(0x1) << PIO_ODSR_P2_Pos)                   /* (PIO_ODSR) Output Data Status Mask */
#define PIO_ODSR_P2(value)                    (PIO_ODSR_P2_Msk & (_UINT32_(value) << PIO_ODSR_P2_Pos)) /* Assigment of value for P2 in the PIO_ODSR register */
#define PIO_ODSR_P3_Pos                       _UINT32_(3)                                          /* (PIO_ODSR) Output Data Status Position */
#define PIO_ODSR_P3_Msk                       (_UINT32_(0x1) << PIO_ODSR_P3_Pos)                   /* (PIO_ODSR) Output Data Status Mask */
#define PIO_ODSR_P3(value)                    (PIO_ODSR_P3_Msk & (_UINT32_(value) << PIO_ODSR_P3_Pos)) /* Assigment of value for P3 in the PIO_ODSR register */
#define PIO_ODSR_P4_Pos                       _UINT32_(4)                                          /* (PIO_ODSR) Output Data Status Position */
#define PIO_ODSR_P4_Msk                       (_UINT32_(0x1) << PIO_ODSR_P4_Pos)                   /* (PIO_ODSR) Output Data Status Mask */
#define PIO_ODSR_P4(value)                    (PIO_ODSR_P4_Msk & (_UINT32_(value) << PIO_ODSR_P4_Pos)) /* Assigment of value for P4 in the PIO_ODSR register */
#define PIO_ODSR_P5_Pos                       _UINT32_(5)                                          /* (PIO_ODSR) Output Data Status Position */
#define PIO_ODSR_P5_Msk                       (_UINT32_(0x1) << PIO_ODSR_P5_Pos)                   /* (PIO_ODSR) Output Data Status Mask */
#define PIO_ODSR_P5(value)                    (PIO_ODSR_P5_Msk & (_UINT32_(value) << PIO_ODSR_P5_Pos)) /* Assigment of value for P5 in the PIO_ODSR register */
#define PIO_ODSR_P6_Pos                       _UINT32_(6)                                          /* (PIO_ODSR) Output Data Status Position */
#define PIO_ODSR_P6_Msk                       (_UINT32_(0x1) << PIO_ODSR_P6_Pos)                   /* (PIO_ODSR) Output Data Status Mask */
#define PIO_ODSR_P6(value)                    (PIO_ODSR_P6_Msk & (_UINT32_(value) << PIO_ODSR_P6_Pos)) /* Assigment of value for P6 in the PIO_ODSR register */
#define PIO_ODSR_P7_Pos                       _UINT32_(7)                                          /* (PIO_ODSR) Output Data Status Position */
#define PIO_ODSR_P7_Msk                       (_UINT32_(0x1) << PIO_ODSR_P7_Pos)                   /* (PIO_ODSR) Output Data Status Mask */
#define PIO_ODSR_P7(value)                    (PIO_ODSR_P7_Msk & (_UINT32_(value) << PIO_ODSR_P7_Pos)) /* Assigment of value for P7 in the PIO_ODSR register */
#define PIO_ODSR_P8_Pos                       _UINT32_(8)                                          /* (PIO_ODSR) Output Data Status Position */
#define PIO_ODSR_P8_Msk                       (_UINT32_(0x1) << PIO_ODSR_P8_Pos)                   /* (PIO_ODSR) Output Data Status Mask */
#define PIO_ODSR_P8(value)                    (PIO_ODSR_P8_Msk & (_UINT32_(value) << PIO_ODSR_P8_Pos)) /* Assigment of value for P8 in the PIO_ODSR register */
#define PIO_ODSR_P9_Pos                       _UINT32_(9)                                          /* (PIO_ODSR) Output Data Status Position */
#define PIO_ODSR_P9_Msk                       (_UINT32_(0x1) << PIO_ODSR_P9_Pos)                   /* (PIO_ODSR) Output Data Status Mask */
#define PIO_ODSR_P9(value)                    (PIO_ODSR_P9_Msk & (_UINT32_(value) << PIO_ODSR_P9_Pos)) /* Assigment of value for P9 in the PIO_ODSR register */
#define PIO_ODSR_P10_Pos                      _UINT32_(10)                                         /* (PIO_ODSR) Output Data Status Position */
#define PIO_ODSR_P10_Msk                      (_UINT32_(0x1) << PIO_ODSR_P10_Pos)                  /* (PIO_ODSR) Output Data Status Mask */
#define PIO_ODSR_P10(value)                   (PIO_ODSR_P10_Msk & (_UINT32_(value) << PIO_ODSR_P10_Pos)) /* Assigment of value for P10 in the PIO_ODSR register */
#define PIO_ODSR_P11_Pos                      _UINT32_(11)                                         /* (PIO_ODSR) Output Data Status Position */
#define PIO_ODSR_P11_Msk                      (_UINT32_(0x1) << PIO_ODSR_P11_Pos)                  /* (PIO_ODSR) Output Data Status Mask */
#define PIO_ODSR_P11(value)                   (PIO_ODSR_P11_Msk & (_UINT32_(value) << PIO_ODSR_P11_Pos)) /* Assigment of value for P11 in the PIO_ODSR register */
#define PIO_ODSR_P12_Pos                      _UINT32_(12)                                         /* (PIO_ODSR) Output Data Status Position */
#define PIO_ODSR_P12_Msk                      (_UINT32_(0x1) << PIO_ODSR_P12_Pos)                  /* (PIO_ODSR) Output Data Status Mask */
#define PIO_ODSR_P12(value)                   (PIO_ODSR_P12_Msk & (_UINT32_(value) << PIO_ODSR_P12_Pos)) /* Assigment of value for P12 in the PIO_ODSR register */
#define PIO_ODSR_P13_Pos                      _UINT32_(13)                                         /* (PIO_ODSR) Output Data Status Position */
#define PIO_ODSR_P13_Msk                      (_UINT32_(0x1) << PIO_ODSR_P13_Pos)                  /* (PIO_ODSR) Output Data Status Mask */
#define PIO_ODSR_P13(value)                   (PIO_ODSR_P13_Msk & (_UINT32_(value) << PIO_ODSR_P13_Pos)) /* Assigment of value for P13 in the PIO_ODSR register */
#define PIO_ODSR_P14_Pos                      _UINT32_(14)                                         /* (PIO_ODSR) Output Data Status Position */
#define PIO_ODSR_P14_Msk                      (_UINT32_(0x1) << PIO_ODSR_P14_Pos)                  /* (PIO_ODSR) Output Data Status Mask */
#define PIO_ODSR_P14(value)                   (PIO_ODSR_P14_Msk & (_UINT32_(value) << PIO_ODSR_P14_Pos)) /* Assigment of value for P14 in the PIO_ODSR register */
#define PIO_ODSR_P15_Pos                      _UINT32_(15)                                         /* (PIO_ODSR) Output Data Status Position */
#define PIO_ODSR_P15_Msk                      (_UINT32_(0x1) << PIO_ODSR_P15_Pos)                  /* (PIO_ODSR) Output Data Status Mask */
#define PIO_ODSR_P15(value)                   (PIO_ODSR_P15_Msk & (_UINT32_(value) << PIO_ODSR_P15_Pos)) /* Assigment of value for P15 in the PIO_ODSR register */
#define PIO_ODSR_P16_Pos                      _UINT32_(16)                                         /* (PIO_ODSR) Output Data Status Position */
#define PIO_ODSR_P16_Msk                      (_UINT32_(0x1) << PIO_ODSR_P16_Pos)                  /* (PIO_ODSR) Output Data Status Mask */
#define PIO_ODSR_P16(value)                   (PIO_ODSR_P16_Msk & (_UINT32_(value) << PIO_ODSR_P16_Pos)) /* Assigment of value for P16 in the PIO_ODSR register */
#define PIO_ODSR_P17_Pos                      _UINT32_(17)                                         /* (PIO_ODSR) Output Data Status Position */
#define PIO_ODSR_P17_Msk                      (_UINT32_(0x1) << PIO_ODSR_P17_Pos)                  /* (PIO_ODSR) Output Data Status Mask */
#define PIO_ODSR_P17(value)                   (PIO_ODSR_P17_Msk & (_UINT32_(value) << PIO_ODSR_P17_Pos)) /* Assigment of value for P17 in the PIO_ODSR register */
#define PIO_ODSR_P18_Pos                      _UINT32_(18)                                         /* (PIO_ODSR) Output Data Status Position */
#define PIO_ODSR_P18_Msk                      (_UINT32_(0x1) << PIO_ODSR_P18_Pos)                  /* (PIO_ODSR) Output Data Status Mask */
#define PIO_ODSR_P18(value)                   (PIO_ODSR_P18_Msk & (_UINT32_(value) << PIO_ODSR_P18_Pos)) /* Assigment of value for P18 in the PIO_ODSR register */
#define PIO_ODSR_P19_Pos                      _UINT32_(19)                                         /* (PIO_ODSR) Output Data Status Position */
#define PIO_ODSR_P19_Msk                      (_UINT32_(0x1) << PIO_ODSR_P19_Pos)                  /* (PIO_ODSR) Output Data Status Mask */
#define PIO_ODSR_P19(value)                   (PIO_ODSR_P19_Msk & (_UINT32_(value) << PIO_ODSR_P19_Pos)) /* Assigment of value for P19 in the PIO_ODSR register */
#define PIO_ODSR_P20_Pos                      _UINT32_(20)                                         /* (PIO_ODSR) Output Data Status Position */
#define PIO_ODSR_P20_Msk                      (_UINT32_(0x1) << PIO_ODSR_P20_Pos)                  /* (PIO_ODSR) Output Data Status Mask */
#define PIO_ODSR_P20(value)                   (PIO_ODSR_P20_Msk & (_UINT32_(value) << PIO_ODSR_P20_Pos)) /* Assigment of value for P20 in the PIO_ODSR register */
#define PIO_ODSR_P21_Pos                      _UINT32_(21)                                         /* (PIO_ODSR) Output Data Status Position */
#define PIO_ODSR_P21_Msk                      (_UINT32_(0x1) << PIO_ODSR_P21_Pos)                  /* (PIO_ODSR) Output Data Status Mask */
#define PIO_ODSR_P21(value)                   (PIO_ODSR_P21_Msk & (_UINT32_(value) << PIO_ODSR_P21_Pos)) /* Assigment of value for P21 in the PIO_ODSR register */
#define PIO_ODSR_P22_Pos                      _UINT32_(22)                                         /* (PIO_ODSR) Output Data Status Position */
#define PIO_ODSR_P22_Msk                      (_UINT32_(0x1) << PIO_ODSR_P22_Pos)                  /* (PIO_ODSR) Output Data Status Mask */
#define PIO_ODSR_P22(value)                   (PIO_ODSR_P22_Msk & (_UINT32_(value) << PIO_ODSR_P22_Pos)) /* Assigment of value for P22 in the PIO_ODSR register */
#define PIO_ODSR_P23_Pos                      _UINT32_(23)                                         /* (PIO_ODSR) Output Data Status Position */
#define PIO_ODSR_P23_Msk                      (_UINT32_(0x1) << PIO_ODSR_P23_Pos)                  /* (PIO_ODSR) Output Data Status Mask */
#define PIO_ODSR_P23(value)                   (PIO_ODSR_P23_Msk & (_UINT32_(value) << PIO_ODSR_P23_Pos)) /* Assigment of value for P23 in the PIO_ODSR register */
#define PIO_ODSR_P24_Pos                      _UINT32_(24)                                         /* (PIO_ODSR) Output Data Status Position */
#define PIO_ODSR_P24_Msk                      (_UINT32_(0x1) << PIO_ODSR_P24_Pos)                  /* (PIO_ODSR) Output Data Status Mask */
#define PIO_ODSR_P24(value)                   (PIO_ODSR_P24_Msk & (_UINT32_(value) << PIO_ODSR_P24_Pos)) /* Assigment of value for P24 in the PIO_ODSR register */
#define PIO_ODSR_P25_Pos                      _UINT32_(25)                                         /* (PIO_ODSR) Output Data Status Position */
#define PIO_ODSR_P25_Msk                      (_UINT32_(0x1) << PIO_ODSR_P25_Pos)                  /* (PIO_ODSR) Output Data Status Mask */
#define PIO_ODSR_P25(value)                   (PIO_ODSR_P25_Msk & (_UINT32_(value) << PIO_ODSR_P25_Pos)) /* Assigment of value for P25 in the PIO_ODSR register */
#define PIO_ODSR_P26_Pos                      _UINT32_(26)                                         /* (PIO_ODSR) Output Data Status Position */
#define PIO_ODSR_P26_Msk                      (_UINT32_(0x1) << PIO_ODSR_P26_Pos)                  /* (PIO_ODSR) Output Data Status Mask */
#define PIO_ODSR_P26(value)                   (PIO_ODSR_P26_Msk & (_UINT32_(value) << PIO_ODSR_P26_Pos)) /* Assigment of value for P26 in the PIO_ODSR register */
#define PIO_ODSR_P27_Pos                      _UINT32_(27)                                         /* (PIO_ODSR) Output Data Status Position */
#define PIO_ODSR_P27_Msk                      (_UINT32_(0x1) << PIO_ODSR_P27_Pos)                  /* (PIO_ODSR) Output Data Status Mask */
#define PIO_ODSR_P27(value)                   (PIO_ODSR_P27_Msk & (_UINT32_(value) << PIO_ODSR_P27_Pos)) /* Assigment of value for P27 in the PIO_ODSR register */
#define PIO_ODSR_P28_Pos                      _UINT32_(28)                                         /* (PIO_ODSR) Output Data Status Position */
#define PIO_ODSR_P28_Msk                      (_UINT32_(0x1) << PIO_ODSR_P28_Pos)                  /* (PIO_ODSR) Output Data Status Mask */
#define PIO_ODSR_P28(value)                   (PIO_ODSR_P28_Msk & (_UINT32_(value) << PIO_ODSR_P28_Pos)) /* Assigment of value for P28 in the PIO_ODSR register */
#define PIO_ODSR_P29_Pos                      _UINT32_(29)                                         /* (PIO_ODSR) Output Data Status Position */
#define PIO_ODSR_P29_Msk                      (_UINT32_(0x1) << PIO_ODSR_P29_Pos)                  /* (PIO_ODSR) Output Data Status Mask */
#define PIO_ODSR_P29(value)                   (PIO_ODSR_P29_Msk & (_UINT32_(value) << PIO_ODSR_P29_Pos)) /* Assigment of value for P29 in the PIO_ODSR register */
#define PIO_ODSR_P30_Pos                      _UINT32_(30)                                         /* (PIO_ODSR) Output Data Status Position */
#define PIO_ODSR_P30_Msk                      (_UINT32_(0x1) << PIO_ODSR_P30_Pos)                  /* (PIO_ODSR) Output Data Status Mask */
#define PIO_ODSR_P30(value)                   (PIO_ODSR_P30_Msk & (_UINT32_(value) << PIO_ODSR_P30_Pos)) /* Assigment of value for P30 in the PIO_ODSR register */
#define PIO_ODSR_P31_Pos                      _UINT32_(31)                                         /* (PIO_ODSR) Output Data Status Position */
#define PIO_ODSR_P31_Msk                      (_UINT32_(0x1) << PIO_ODSR_P31_Pos)                  /* (PIO_ODSR) Output Data Status Mask */
#define PIO_ODSR_P31(value)                   (PIO_ODSR_P31_Msk & (_UINT32_(value) << PIO_ODSR_P31_Pos)) /* Assigment of value for P31 in the PIO_ODSR register */
#define PIO_ODSR_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (PIO_ODSR) Register Mask  */

#define PIO_ODSR_P_Pos                        _UINT32_(0)                                          /* (PIO_ODSR Position) Output Data Status */
#define PIO_ODSR_P_Msk                        (_UINT32_(0xFFFFFFFF) << PIO_ODSR_P_Pos)             /* (PIO_ODSR Mask) P */
#define PIO_ODSR_P(value)                     (PIO_ODSR_P_Msk & (_UINT32_(value) << PIO_ODSR_P_Pos)) 

/* -------- PIO_IER : (PIO Offset: 0x20) ( /W 32) PIO Interrupt Enable Register -------- */
#define PIO_IER_P0_Pos                        _UINT32_(0)                                          /* (PIO_IER) Input Change Interrupt Enable Position */
#define PIO_IER_P0_Msk                        (_UINT32_(0x1) << PIO_IER_P0_Pos)                    /* (PIO_IER) Input Change Interrupt Enable Mask */
#define PIO_IER_P0(value)                     (PIO_IER_P0_Msk & (_UINT32_(value) << PIO_IER_P0_Pos)) /* Assigment of value for P0 in the PIO_IER register */
#define PIO_IER_P1_Pos                        _UINT32_(1)                                          /* (PIO_IER) Input Change Interrupt Enable Position */
#define PIO_IER_P1_Msk                        (_UINT32_(0x1) << PIO_IER_P1_Pos)                    /* (PIO_IER) Input Change Interrupt Enable Mask */
#define PIO_IER_P1(value)                     (PIO_IER_P1_Msk & (_UINT32_(value) << PIO_IER_P1_Pos)) /* Assigment of value for P1 in the PIO_IER register */
#define PIO_IER_P2_Pos                        _UINT32_(2)                                          /* (PIO_IER) Input Change Interrupt Enable Position */
#define PIO_IER_P2_Msk                        (_UINT32_(0x1) << PIO_IER_P2_Pos)                    /* (PIO_IER) Input Change Interrupt Enable Mask */
#define PIO_IER_P2(value)                     (PIO_IER_P2_Msk & (_UINT32_(value) << PIO_IER_P2_Pos)) /* Assigment of value for P2 in the PIO_IER register */
#define PIO_IER_P3_Pos                        _UINT32_(3)                                          /* (PIO_IER) Input Change Interrupt Enable Position */
#define PIO_IER_P3_Msk                        (_UINT32_(0x1) << PIO_IER_P3_Pos)                    /* (PIO_IER) Input Change Interrupt Enable Mask */
#define PIO_IER_P3(value)                     (PIO_IER_P3_Msk & (_UINT32_(value) << PIO_IER_P3_Pos)) /* Assigment of value for P3 in the PIO_IER register */
#define PIO_IER_P4_Pos                        _UINT32_(4)                                          /* (PIO_IER) Input Change Interrupt Enable Position */
#define PIO_IER_P4_Msk                        (_UINT32_(0x1) << PIO_IER_P4_Pos)                    /* (PIO_IER) Input Change Interrupt Enable Mask */
#define PIO_IER_P4(value)                     (PIO_IER_P4_Msk & (_UINT32_(value) << PIO_IER_P4_Pos)) /* Assigment of value for P4 in the PIO_IER register */
#define PIO_IER_P5_Pos                        _UINT32_(5)                                          /* (PIO_IER) Input Change Interrupt Enable Position */
#define PIO_IER_P5_Msk                        (_UINT32_(0x1) << PIO_IER_P5_Pos)                    /* (PIO_IER) Input Change Interrupt Enable Mask */
#define PIO_IER_P5(value)                     (PIO_IER_P5_Msk & (_UINT32_(value) << PIO_IER_P5_Pos)) /* Assigment of value for P5 in the PIO_IER register */
#define PIO_IER_P6_Pos                        _UINT32_(6)                                          /* (PIO_IER) Input Change Interrupt Enable Position */
#define PIO_IER_P6_Msk                        (_UINT32_(0x1) << PIO_IER_P6_Pos)                    /* (PIO_IER) Input Change Interrupt Enable Mask */
#define PIO_IER_P6(value)                     (PIO_IER_P6_Msk & (_UINT32_(value) << PIO_IER_P6_Pos)) /* Assigment of value for P6 in the PIO_IER register */
#define PIO_IER_P7_Pos                        _UINT32_(7)                                          /* (PIO_IER) Input Change Interrupt Enable Position */
#define PIO_IER_P7_Msk                        (_UINT32_(0x1) << PIO_IER_P7_Pos)                    /* (PIO_IER) Input Change Interrupt Enable Mask */
#define PIO_IER_P7(value)                     (PIO_IER_P7_Msk & (_UINT32_(value) << PIO_IER_P7_Pos)) /* Assigment of value for P7 in the PIO_IER register */
#define PIO_IER_P8_Pos                        _UINT32_(8)                                          /* (PIO_IER) Input Change Interrupt Enable Position */
#define PIO_IER_P8_Msk                        (_UINT32_(0x1) << PIO_IER_P8_Pos)                    /* (PIO_IER) Input Change Interrupt Enable Mask */
#define PIO_IER_P8(value)                     (PIO_IER_P8_Msk & (_UINT32_(value) << PIO_IER_P8_Pos)) /* Assigment of value for P8 in the PIO_IER register */
#define PIO_IER_P9_Pos                        _UINT32_(9)                                          /* (PIO_IER) Input Change Interrupt Enable Position */
#define PIO_IER_P9_Msk                        (_UINT32_(0x1) << PIO_IER_P9_Pos)                    /* (PIO_IER) Input Change Interrupt Enable Mask */
#define PIO_IER_P9(value)                     (PIO_IER_P9_Msk & (_UINT32_(value) << PIO_IER_P9_Pos)) /* Assigment of value for P9 in the PIO_IER register */
#define PIO_IER_P10_Pos                       _UINT32_(10)                                         /* (PIO_IER) Input Change Interrupt Enable Position */
#define PIO_IER_P10_Msk                       (_UINT32_(0x1) << PIO_IER_P10_Pos)                   /* (PIO_IER) Input Change Interrupt Enable Mask */
#define PIO_IER_P10(value)                    (PIO_IER_P10_Msk & (_UINT32_(value) << PIO_IER_P10_Pos)) /* Assigment of value for P10 in the PIO_IER register */
#define PIO_IER_P11_Pos                       _UINT32_(11)                                         /* (PIO_IER) Input Change Interrupt Enable Position */
#define PIO_IER_P11_Msk                       (_UINT32_(0x1) << PIO_IER_P11_Pos)                   /* (PIO_IER) Input Change Interrupt Enable Mask */
#define PIO_IER_P11(value)                    (PIO_IER_P11_Msk & (_UINT32_(value) << PIO_IER_P11_Pos)) /* Assigment of value for P11 in the PIO_IER register */
#define PIO_IER_P12_Pos                       _UINT32_(12)                                         /* (PIO_IER) Input Change Interrupt Enable Position */
#define PIO_IER_P12_Msk                       (_UINT32_(0x1) << PIO_IER_P12_Pos)                   /* (PIO_IER) Input Change Interrupt Enable Mask */
#define PIO_IER_P12(value)                    (PIO_IER_P12_Msk & (_UINT32_(value) << PIO_IER_P12_Pos)) /* Assigment of value for P12 in the PIO_IER register */
#define PIO_IER_P13_Pos                       _UINT32_(13)                                         /* (PIO_IER) Input Change Interrupt Enable Position */
#define PIO_IER_P13_Msk                       (_UINT32_(0x1) << PIO_IER_P13_Pos)                   /* (PIO_IER) Input Change Interrupt Enable Mask */
#define PIO_IER_P13(value)                    (PIO_IER_P13_Msk & (_UINT32_(value) << PIO_IER_P13_Pos)) /* Assigment of value for P13 in the PIO_IER register */
#define PIO_IER_P14_Pos                       _UINT32_(14)                                         /* (PIO_IER) Input Change Interrupt Enable Position */
#define PIO_IER_P14_Msk                       (_UINT32_(0x1) << PIO_IER_P14_Pos)                   /* (PIO_IER) Input Change Interrupt Enable Mask */
#define PIO_IER_P14(value)                    (PIO_IER_P14_Msk & (_UINT32_(value) << PIO_IER_P14_Pos)) /* Assigment of value for P14 in the PIO_IER register */
#define PIO_IER_P15_Pos                       _UINT32_(15)                                         /* (PIO_IER) Input Change Interrupt Enable Position */
#define PIO_IER_P15_Msk                       (_UINT32_(0x1) << PIO_IER_P15_Pos)                   /* (PIO_IER) Input Change Interrupt Enable Mask */
#define PIO_IER_P15(value)                    (PIO_IER_P15_Msk & (_UINT32_(value) << PIO_IER_P15_Pos)) /* Assigment of value for P15 in the PIO_IER register */
#define PIO_IER_P16_Pos                       _UINT32_(16)                                         /* (PIO_IER) Input Change Interrupt Enable Position */
#define PIO_IER_P16_Msk                       (_UINT32_(0x1) << PIO_IER_P16_Pos)                   /* (PIO_IER) Input Change Interrupt Enable Mask */
#define PIO_IER_P16(value)                    (PIO_IER_P16_Msk & (_UINT32_(value) << PIO_IER_P16_Pos)) /* Assigment of value for P16 in the PIO_IER register */
#define PIO_IER_P17_Pos                       _UINT32_(17)                                         /* (PIO_IER) Input Change Interrupt Enable Position */
#define PIO_IER_P17_Msk                       (_UINT32_(0x1) << PIO_IER_P17_Pos)                   /* (PIO_IER) Input Change Interrupt Enable Mask */
#define PIO_IER_P17(value)                    (PIO_IER_P17_Msk & (_UINT32_(value) << PIO_IER_P17_Pos)) /* Assigment of value for P17 in the PIO_IER register */
#define PIO_IER_P18_Pos                       _UINT32_(18)                                         /* (PIO_IER) Input Change Interrupt Enable Position */
#define PIO_IER_P18_Msk                       (_UINT32_(0x1) << PIO_IER_P18_Pos)                   /* (PIO_IER) Input Change Interrupt Enable Mask */
#define PIO_IER_P18(value)                    (PIO_IER_P18_Msk & (_UINT32_(value) << PIO_IER_P18_Pos)) /* Assigment of value for P18 in the PIO_IER register */
#define PIO_IER_P19_Pos                       _UINT32_(19)                                         /* (PIO_IER) Input Change Interrupt Enable Position */
#define PIO_IER_P19_Msk                       (_UINT32_(0x1) << PIO_IER_P19_Pos)                   /* (PIO_IER) Input Change Interrupt Enable Mask */
#define PIO_IER_P19(value)                    (PIO_IER_P19_Msk & (_UINT32_(value) << PIO_IER_P19_Pos)) /* Assigment of value for P19 in the PIO_IER register */
#define PIO_IER_P20_Pos                       _UINT32_(20)                                         /* (PIO_IER) Input Change Interrupt Enable Position */
#define PIO_IER_P20_Msk                       (_UINT32_(0x1) << PIO_IER_P20_Pos)                   /* (PIO_IER) Input Change Interrupt Enable Mask */
#define PIO_IER_P20(value)                    (PIO_IER_P20_Msk & (_UINT32_(value) << PIO_IER_P20_Pos)) /* Assigment of value for P20 in the PIO_IER register */
#define PIO_IER_P21_Pos                       _UINT32_(21)                                         /* (PIO_IER) Input Change Interrupt Enable Position */
#define PIO_IER_P21_Msk                       (_UINT32_(0x1) << PIO_IER_P21_Pos)                   /* (PIO_IER) Input Change Interrupt Enable Mask */
#define PIO_IER_P21(value)                    (PIO_IER_P21_Msk & (_UINT32_(value) << PIO_IER_P21_Pos)) /* Assigment of value for P21 in the PIO_IER register */
#define PIO_IER_P22_Pos                       _UINT32_(22)                                         /* (PIO_IER) Input Change Interrupt Enable Position */
#define PIO_IER_P22_Msk                       (_UINT32_(0x1) << PIO_IER_P22_Pos)                   /* (PIO_IER) Input Change Interrupt Enable Mask */
#define PIO_IER_P22(value)                    (PIO_IER_P22_Msk & (_UINT32_(value) << PIO_IER_P22_Pos)) /* Assigment of value for P22 in the PIO_IER register */
#define PIO_IER_P23_Pos                       _UINT32_(23)                                         /* (PIO_IER) Input Change Interrupt Enable Position */
#define PIO_IER_P23_Msk                       (_UINT32_(0x1) << PIO_IER_P23_Pos)                   /* (PIO_IER) Input Change Interrupt Enable Mask */
#define PIO_IER_P23(value)                    (PIO_IER_P23_Msk & (_UINT32_(value) << PIO_IER_P23_Pos)) /* Assigment of value for P23 in the PIO_IER register */
#define PIO_IER_P24_Pos                       _UINT32_(24)                                         /* (PIO_IER) Input Change Interrupt Enable Position */
#define PIO_IER_P24_Msk                       (_UINT32_(0x1) << PIO_IER_P24_Pos)                   /* (PIO_IER) Input Change Interrupt Enable Mask */
#define PIO_IER_P24(value)                    (PIO_IER_P24_Msk & (_UINT32_(value) << PIO_IER_P24_Pos)) /* Assigment of value for P24 in the PIO_IER register */
#define PIO_IER_P25_Pos                       _UINT32_(25)                                         /* (PIO_IER) Input Change Interrupt Enable Position */
#define PIO_IER_P25_Msk                       (_UINT32_(0x1) << PIO_IER_P25_Pos)                   /* (PIO_IER) Input Change Interrupt Enable Mask */
#define PIO_IER_P25(value)                    (PIO_IER_P25_Msk & (_UINT32_(value) << PIO_IER_P25_Pos)) /* Assigment of value for P25 in the PIO_IER register */
#define PIO_IER_P26_Pos                       _UINT32_(26)                                         /* (PIO_IER) Input Change Interrupt Enable Position */
#define PIO_IER_P26_Msk                       (_UINT32_(0x1) << PIO_IER_P26_Pos)                   /* (PIO_IER) Input Change Interrupt Enable Mask */
#define PIO_IER_P26(value)                    (PIO_IER_P26_Msk & (_UINT32_(value) << PIO_IER_P26_Pos)) /* Assigment of value for P26 in the PIO_IER register */
#define PIO_IER_P27_Pos                       _UINT32_(27)                                         /* (PIO_IER) Input Change Interrupt Enable Position */
#define PIO_IER_P27_Msk                       (_UINT32_(0x1) << PIO_IER_P27_Pos)                   /* (PIO_IER) Input Change Interrupt Enable Mask */
#define PIO_IER_P27(value)                    (PIO_IER_P27_Msk & (_UINT32_(value) << PIO_IER_P27_Pos)) /* Assigment of value for P27 in the PIO_IER register */
#define PIO_IER_P28_Pos                       _UINT32_(28)                                         /* (PIO_IER) Input Change Interrupt Enable Position */
#define PIO_IER_P28_Msk                       (_UINT32_(0x1) << PIO_IER_P28_Pos)                   /* (PIO_IER) Input Change Interrupt Enable Mask */
#define PIO_IER_P28(value)                    (PIO_IER_P28_Msk & (_UINT32_(value) << PIO_IER_P28_Pos)) /* Assigment of value for P28 in the PIO_IER register */
#define PIO_IER_P29_Pos                       _UINT32_(29)                                         /* (PIO_IER) Input Change Interrupt Enable Position */
#define PIO_IER_P29_Msk                       (_UINT32_(0x1) << PIO_IER_P29_Pos)                   /* (PIO_IER) Input Change Interrupt Enable Mask */
#define PIO_IER_P29(value)                    (PIO_IER_P29_Msk & (_UINT32_(value) << PIO_IER_P29_Pos)) /* Assigment of value for P29 in the PIO_IER register */
#define PIO_IER_P30_Pos                       _UINT32_(30)                                         /* (PIO_IER) Input Change Interrupt Enable Position */
#define PIO_IER_P30_Msk                       (_UINT32_(0x1) << PIO_IER_P30_Pos)                   /* (PIO_IER) Input Change Interrupt Enable Mask */
#define PIO_IER_P30(value)                    (PIO_IER_P30_Msk & (_UINT32_(value) << PIO_IER_P30_Pos)) /* Assigment of value for P30 in the PIO_IER register */
#define PIO_IER_P31_Pos                       _UINT32_(31)                                         /* (PIO_IER) Input Change Interrupt Enable Position */
#define PIO_IER_P31_Msk                       (_UINT32_(0x1) << PIO_IER_P31_Pos)                   /* (PIO_IER) Input Change Interrupt Enable Mask */
#define PIO_IER_P31(value)                    (PIO_IER_P31_Msk & (_UINT32_(value) << PIO_IER_P31_Pos)) /* Assigment of value for P31 in the PIO_IER register */
#define PIO_IER_Msk                           _UINT32_(0xFFFFFFFF)                                 /* (PIO_IER) Register Mask  */

#define PIO_IER_P_Pos                         _UINT32_(0)                                          /* (PIO_IER Position) Input Change Interrupt Enable */
#define PIO_IER_P_Msk                         (_UINT32_(0xFFFFFFFF) << PIO_IER_P_Pos)              /* (PIO_IER Mask) P */
#define PIO_IER_P(value)                      (PIO_IER_P_Msk & (_UINT32_(value) << PIO_IER_P_Pos)) 

/* -------- PIO_IDR : (PIO Offset: 0x24) ( /W 32) PIO Interrupt Disable Register -------- */
#define PIO_IDR_P0_Pos                        _UINT32_(0)                                          /* (PIO_IDR) Input Change Interrupt Disable Position */
#define PIO_IDR_P0_Msk                        (_UINT32_(0x1) << PIO_IDR_P0_Pos)                    /* (PIO_IDR) Input Change Interrupt Disable Mask */
#define PIO_IDR_P0(value)                     (PIO_IDR_P0_Msk & (_UINT32_(value) << PIO_IDR_P0_Pos)) /* Assigment of value for P0 in the PIO_IDR register */
#define PIO_IDR_P1_Pos                        _UINT32_(1)                                          /* (PIO_IDR) Input Change Interrupt Disable Position */
#define PIO_IDR_P1_Msk                        (_UINT32_(0x1) << PIO_IDR_P1_Pos)                    /* (PIO_IDR) Input Change Interrupt Disable Mask */
#define PIO_IDR_P1(value)                     (PIO_IDR_P1_Msk & (_UINT32_(value) << PIO_IDR_P1_Pos)) /* Assigment of value for P1 in the PIO_IDR register */
#define PIO_IDR_P2_Pos                        _UINT32_(2)                                          /* (PIO_IDR) Input Change Interrupt Disable Position */
#define PIO_IDR_P2_Msk                        (_UINT32_(0x1) << PIO_IDR_P2_Pos)                    /* (PIO_IDR) Input Change Interrupt Disable Mask */
#define PIO_IDR_P2(value)                     (PIO_IDR_P2_Msk & (_UINT32_(value) << PIO_IDR_P2_Pos)) /* Assigment of value for P2 in the PIO_IDR register */
#define PIO_IDR_P3_Pos                        _UINT32_(3)                                          /* (PIO_IDR) Input Change Interrupt Disable Position */
#define PIO_IDR_P3_Msk                        (_UINT32_(0x1) << PIO_IDR_P3_Pos)                    /* (PIO_IDR) Input Change Interrupt Disable Mask */
#define PIO_IDR_P3(value)                     (PIO_IDR_P3_Msk & (_UINT32_(value) << PIO_IDR_P3_Pos)) /* Assigment of value for P3 in the PIO_IDR register */
#define PIO_IDR_P4_Pos                        _UINT32_(4)                                          /* (PIO_IDR) Input Change Interrupt Disable Position */
#define PIO_IDR_P4_Msk                        (_UINT32_(0x1) << PIO_IDR_P4_Pos)                    /* (PIO_IDR) Input Change Interrupt Disable Mask */
#define PIO_IDR_P4(value)                     (PIO_IDR_P4_Msk & (_UINT32_(value) << PIO_IDR_P4_Pos)) /* Assigment of value for P4 in the PIO_IDR register */
#define PIO_IDR_P5_Pos                        _UINT32_(5)                                          /* (PIO_IDR) Input Change Interrupt Disable Position */
#define PIO_IDR_P5_Msk                        (_UINT32_(0x1) << PIO_IDR_P5_Pos)                    /* (PIO_IDR) Input Change Interrupt Disable Mask */
#define PIO_IDR_P5(value)                     (PIO_IDR_P5_Msk & (_UINT32_(value) << PIO_IDR_P5_Pos)) /* Assigment of value for P5 in the PIO_IDR register */
#define PIO_IDR_P6_Pos                        _UINT32_(6)                                          /* (PIO_IDR) Input Change Interrupt Disable Position */
#define PIO_IDR_P6_Msk                        (_UINT32_(0x1) << PIO_IDR_P6_Pos)                    /* (PIO_IDR) Input Change Interrupt Disable Mask */
#define PIO_IDR_P6(value)                     (PIO_IDR_P6_Msk & (_UINT32_(value) << PIO_IDR_P6_Pos)) /* Assigment of value for P6 in the PIO_IDR register */
#define PIO_IDR_P7_Pos                        _UINT32_(7)                                          /* (PIO_IDR) Input Change Interrupt Disable Position */
#define PIO_IDR_P7_Msk                        (_UINT32_(0x1) << PIO_IDR_P7_Pos)                    /* (PIO_IDR) Input Change Interrupt Disable Mask */
#define PIO_IDR_P7(value)                     (PIO_IDR_P7_Msk & (_UINT32_(value) << PIO_IDR_P7_Pos)) /* Assigment of value for P7 in the PIO_IDR register */
#define PIO_IDR_P8_Pos                        _UINT32_(8)                                          /* (PIO_IDR) Input Change Interrupt Disable Position */
#define PIO_IDR_P8_Msk                        (_UINT32_(0x1) << PIO_IDR_P8_Pos)                    /* (PIO_IDR) Input Change Interrupt Disable Mask */
#define PIO_IDR_P8(value)                     (PIO_IDR_P8_Msk & (_UINT32_(value) << PIO_IDR_P8_Pos)) /* Assigment of value for P8 in the PIO_IDR register */
#define PIO_IDR_P9_Pos                        _UINT32_(9)                                          /* (PIO_IDR) Input Change Interrupt Disable Position */
#define PIO_IDR_P9_Msk                        (_UINT32_(0x1) << PIO_IDR_P9_Pos)                    /* (PIO_IDR) Input Change Interrupt Disable Mask */
#define PIO_IDR_P9(value)                     (PIO_IDR_P9_Msk & (_UINT32_(value) << PIO_IDR_P9_Pos)) /* Assigment of value for P9 in the PIO_IDR register */
#define PIO_IDR_P10_Pos                       _UINT32_(10)                                         /* (PIO_IDR) Input Change Interrupt Disable Position */
#define PIO_IDR_P10_Msk                       (_UINT32_(0x1) << PIO_IDR_P10_Pos)                   /* (PIO_IDR) Input Change Interrupt Disable Mask */
#define PIO_IDR_P10(value)                    (PIO_IDR_P10_Msk & (_UINT32_(value) << PIO_IDR_P10_Pos)) /* Assigment of value for P10 in the PIO_IDR register */
#define PIO_IDR_P11_Pos                       _UINT32_(11)                                         /* (PIO_IDR) Input Change Interrupt Disable Position */
#define PIO_IDR_P11_Msk                       (_UINT32_(0x1) << PIO_IDR_P11_Pos)                   /* (PIO_IDR) Input Change Interrupt Disable Mask */
#define PIO_IDR_P11(value)                    (PIO_IDR_P11_Msk & (_UINT32_(value) << PIO_IDR_P11_Pos)) /* Assigment of value for P11 in the PIO_IDR register */
#define PIO_IDR_P12_Pos                       _UINT32_(12)                                         /* (PIO_IDR) Input Change Interrupt Disable Position */
#define PIO_IDR_P12_Msk                       (_UINT32_(0x1) << PIO_IDR_P12_Pos)                   /* (PIO_IDR) Input Change Interrupt Disable Mask */
#define PIO_IDR_P12(value)                    (PIO_IDR_P12_Msk & (_UINT32_(value) << PIO_IDR_P12_Pos)) /* Assigment of value for P12 in the PIO_IDR register */
#define PIO_IDR_P13_Pos                       _UINT32_(13)                                         /* (PIO_IDR) Input Change Interrupt Disable Position */
#define PIO_IDR_P13_Msk                       (_UINT32_(0x1) << PIO_IDR_P13_Pos)                   /* (PIO_IDR) Input Change Interrupt Disable Mask */
#define PIO_IDR_P13(value)                    (PIO_IDR_P13_Msk & (_UINT32_(value) << PIO_IDR_P13_Pos)) /* Assigment of value for P13 in the PIO_IDR register */
#define PIO_IDR_P14_Pos                       _UINT32_(14)                                         /* (PIO_IDR) Input Change Interrupt Disable Position */
#define PIO_IDR_P14_Msk                       (_UINT32_(0x1) << PIO_IDR_P14_Pos)                   /* (PIO_IDR) Input Change Interrupt Disable Mask */
#define PIO_IDR_P14(value)                    (PIO_IDR_P14_Msk & (_UINT32_(value) << PIO_IDR_P14_Pos)) /* Assigment of value for P14 in the PIO_IDR register */
#define PIO_IDR_P15_Pos                       _UINT32_(15)                                         /* (PIO_IDR) Input Change Interrupt Disable Position */
#define PIO_IDR_P15_Msk                       (_UINT32_(0x1) << PIO_IDR_P15_Pos)                   /* (PIO_IDR) Input Change Interrupt Disable Mask */
#define PIO_IDR_P15(value)                    (PIO_IDR_P15_Msk & (_UINT32_(value) << PIO_IDR_P15_Pos)) /* Assigment of value for P15 in the PIO_IDR register */
#define PIO_IDR_P16_Pos                       _UINT32_(16)                                         /* (PIO_IDR) Input Change Interrupt Disable Position */
#define PIO_IDR_P16_Msk                       (_UINT32_(0x1) << PIO_IDR_P16_Pos)                   /* (PIO_IDR) Input Change Interrupt Disable Mask */
#define PIO_IDR_P16(value)                    (PIO_IDR_P16_Msk & (_UINT32_(value) << PIO_IDR_P16_Pos)) /* Assigment of value for P16 in the PIO_IDR register */
#define PIO_IDR_P17_Pos                       _UINT32_(17)                                         /* (PIO_IDR) Input Change Interrupt Disable Position */
#define PIO_IDR_P17_Msk                       (_UINT32_(0x1) << PIO_IDR_P17_Pos)                   /* (PIO_IDR) Input Change Interrupt Disable Mask */
#define PIO_IDR_P17(value)                    (PIO_IDR_P17_Msk & (_UINT32_(value) << PIO_IDR_P17_Pos)) /* Assigment of value for P17 in the PIO_IDR register */
#define PIO_IDR_P18_Pos                       _UINT32_(18)                                         /* (PIO_IDR) Input Change Interrupt Disable Position */
#define PIO_IDR_P18_Msk                       (_UINT32_(0x1) << PIO_IDR_P18_Pos)                   /* (PIO_IDR) Input Change Interrupt Disable Mask */
#define PIO_IDR_P18(value)                    (PIO_IDR_P18_Msk & (_UINT32_(value) << PIO_IDR_P18_Pos)) /* Assigment of value for P18 in the PIO_IDR register */
#define PIO_IDR_P19_Pos                       _UINT32_(19)                                         /* (PIO_IDR) Input Change Interrupt Disable Position */
#define PIO_IDR_P19_Msk                       (_UINT32_(0x1) << PIO_IDR_P19_Pos)                   /* (PIO_IDR) Input Change Interrupt Disable Mask */
#define PIO_IDR_P19(value)                    (PIO_IDR_P19_Msk & (_UINT32_(value) << PIO_IDR_P19_Pos)) /* Assigment of value for P19 in the PIO_IDR register */
#define PIO_IDR_P20_Pos                       _UINT32_(20)                                         /* (PIO_IDR) Input Change Interrupt Disable Position */
#define PIO_IDR_P20_Msk                       (_UINT32_(0x1) << PIO_IDR_P20_Pos)                   /* (PIO_IDR) Input Change Interrupt Disable Mask */
#define PIO_IDR_P20(value)                    (PIO_IDR_P20_Msk & (_UINT32_(value) << PIO_IDR_P20_Pos)) /* Assigment of value for P20 in the PIO_IDR register */
#define PIO_IDR_P21_Pos                       _UINT32_(21)                                         /* (PIO_IDR) Input Change Interrupt Disable Position */
#define PIO_IDR_P21_Msk                       (_UINT32_(0x1) << PIO_IDR_P21_Pos)                   /* (PIO_IDR) Input Change Interrupt Disable Mask */
#define PIO_IDR_P21(value)                    (PIO_IDR_P21_Msk & (_UINT32_(value) << PIO_IDR_P21_Pos)) /* Assigment of value for P21 in the PIO_IDR register */
#define PIO_IDR_P22_Pos                       _UINT32_(22)                                         /* (PIO_IDR) Input Change Interrupt Disable Position */
#define PIO_IDR_P22_Msk                       (_UINT32_(0x1) << PIO_IDR_P22_Pos)                   /* (PIO_IDR) Input Change Interrupt Disable Mask */
#define PIO_IDR_P22(value)                    (PIO_IDR_P22_Msk & (_UINT32_(value) << PIO_IDR_P22_Pos)) /* Assigment of value for P22 in the PIO_IDR register */
#define PIO_IDR_P23_Pos                       _UINT32_(23)                                         /* (PIO_IDR) Input Change Interrupt Disable Position */
#define PIO_IDR_P23_Msk                       (_UINT32_(0x1) << PIO_IDR_P23_Pos)                   /* (PIO_IDR) Input Change Interrupt Disable Mask */
#define PIO_IDR_P23(value)                    (PIO_IDR_P23_Msk & (_UINT32_(value) << PIO_IDR_P23_Pos)) /* Assigment of value for P23 in the PIO_IDR register */
#define PIO_IDR_P24_Pos                       _UINT32_(24)                                         /* (PIO_IDR) Input Change Interrupt Disable Position */
#define PIO_IDR_P24_Msk                       (_UINT32_(0x1) << PIO_IDR_P24_Pos)                   /* (PIO_IDR) Input Change Interrupt Disable Mask */
#define PIO_IDR_P24(value)                    (PIO_IDR_P24_Msk & (_UINT32_(value) << PIO_IDR_P24_Pos)) /* Assigment of value for P24 in the PIO_IDR register */
#define PIO_IDR_P25_Pos                       _UINT32_(25)                                         /* (PIO_IDR) Input Change Interrupt Disable Position */
#define PIO_IDR_P25_Msk                       (_UINT32_(0x1) << PIO_IDR_P25_Pos)                   /* (PIO_IDR) Input Change Interrupt Disable Mask */
#define PIO_IDR_P25(value)                    (PIO_IDR_P25_Msk & (_UINT32_(value) << PIO_IDR_P25_Pos)) /* Assigment of value for P25 in the PIO_IDR register */
#define PIO_IDR_P26_Pos                       _UINT32_(26)                                         /* (PIO_IDR) Input Change Interrupt Disable Position */
#define PIO_IDR_P26_Msk                       (_UINT32_(0x1) << PIO_IDR_P26_Pos)                   /* (PIO_IDR) Input Change Interrupt Disable Mask */
#define PIO_IDR_P26(value)                    (PIO_IDR_P26_Msk & (_UINT32_(value) << PIO_IDR_P26_Pos)) /* Assigment of value for P26 in the PIO_IDR register */
#define PIO_IDR_P27_Pos                       _UINT32_(27)                                         /* (PIO_IDR) Input Change Interrupt Disable Position */
#define PIO_IDR_P27_Msk                       (_UINT32_(0x1) << PIO_IDR_P27_Pos)                   /* (PIO_IDR) Input Change Interrupt Disable Mask */
#define PIO_IDR_P27(value)                    (PIO_IDR_P27_Msk & (_UINT32_(value) << PIO_IDR_P27_Pos)) /* Assigment of value for P27 in the PIO_IDR register */
#define PIO_IDR_P28_Pos                       _UINT32_(28)                                         /* (PIO_IDR) Input Change Interrupt Disable Position */
#define PIO_IDR_P28_Msk                       (_UINT32_(0x1) << PIO_IDR_P28_Pos)                   /* (PIO_IDR) Input Change Interrupt Disable Mask */
#define PIO_IDR_P28(value)                    (PIO_IDR_P28_Msk & (_UINT32_(value) << PIO_IDR_P28_Pos)) /* Assigment of value for P28 in the PIO_IDR register */
#define PIO_IDR_P29_Pos                       _UINT32_(29)                                         /* (PIO_IDR) Input Change Interrupt Disable Position */
#define PIO_IDR_P29_Msk                       (_UINT32_(0x1) << PIO_IDR_P29_Pos)                   /* (PIO_IDR) Input Change Interrupt Disable Mask */
#define PIO_IDR_P29(value)                    (PIO_IDR_P29_Msk & (_UINT32_(value) << PIO_IDR_P29_Pos)) /* Assigment of value for P29 in the PIO_IDR register */
#define PIO_IDR_P30_Pos                       _UINT32_(30)                                         /* (PIO_IDR) Input Change Interrupt Disable Position */
#define PIO_IDR_P30_Msk                       (_UINT32_(0x1) << PIO_IDR_P30_Pos)                   /* (PIO_IDR) Input Change Interrupt Disable Mask */
#define PIO_IDR_P30(value)                    (PIO_IDR_P30_Msk & (_UINT32_(value) << PIO_IDR_P30_Pos)) /* Assigment of value for P30 in the PIO_IDR register */
#define PIO_IDR_P31_Pos                       _UINT32_(31)                                         /* (PIO_IDR) Input Change Interrupt Disable Position */
#define PIO_IDR_P31_Msk                       (_UINT32_(0x1) << PIO_IDR_P31_Pos)                   /* (PIO_IDR) Input Change Interrupt Disable Mask */
#define PIO_IDR_P31(value)                    (PIO_IDR_P31_Msk & (_UINT32_(value) << PIO_IDR_P31_Pos)) /* Assigment of value for P31 in the PIO_IDR register */
#define PIO_IDR_Msk                           _UINT32_(0xFFFFFFFF)                                 /* (PIO_IDR) Register Mask  */

#define PIO_IDR_P_Pos                         _UINT32_(0)                                          /* (PIO_IDR Position) Input Change Interrupt Disable */
#define PIO_IDR_P_Msk                         (_UINT32_(0xFFFFFFFF) << PIO_IDR_P_Pos)              /* (PIO_IDR Mask) P */
#define PIO_IDR_P(value)                      (PIO_IDR_P_Msk & (_UINT32_(value) << PIO_IDR_P_Pos)) 

/* -------- PIO_IMR : (PIO Offset: 0x28) ( R/ 32) PIO Interrupt Mask Register -------- */
#define PIO_IMR_P0_Pos                        _UINT32_(0)                                          /* (PIO_IMR) Input Change Interrupt Mask Position */
#define PIO_IMR_P0_Msk                        (_UINT32_(0x1) << PIO_IMR_P0_Pos)                    /* (PIO_IMR) Input Change Interrupt Mask Mask */
#define PIO_IMR_P0(value)                     (PIO_IMR_P0_Msk & (_UINT32_(value) << PIO_IMR_P0_Pos)) /* Assigment of value for P0 in the PIO_IMR register */
#define PIO_IMR_P1_Pos                        _UINT32_(1)                                          /* (PIO_IMR) Input Change Interrupt Mask Position */
#define PIO_IMR_P1_Msk                        (_UINT32_(0x1) << PIO_IMR_P1_Pos)                    /* (PIO_IMR) Input Change Interrupt Mask Mask */
#define PIO_IMR_P1(value)                     (PIO_IMR_P1_Msk & (_UINT32_(value) << PIO_IMR_P1_Pos)) /* Assigment of value for P1 in the PIO_IMR register */
#define PIO_IMR_P2_Pos                        _UINT32_(2)                                          /* (PIO_IMR) Input Change Interrupt Mask Position */
#define PIO_IMR_P2_Msk                        (_UINT32_(0x1) << PIO_IMR_P2_Pos)                    /* (PIO_IMR) Input Change Interrupt Mask Mask */
#define PIO_IMR_P2(value)                     (PIO_IMR_P2_Msk & (_UINT32_(value) << PIO_IMR_P2_Pos)) /* Assigment of value for P2 in the PIO_IMR register */
#define PIO_IMR_P3_Pos                        _UINT32_(3)                                          /* (PIO_IMR) Input Change Interrupt Mask Position */
#define PIO_IMR_P3_Msk                        (_UINT32_(0x1) << PIO_IMR_P3_Pos)                    /* (PIO_IMR) Input Change Interrupt Mask Mask */
#define PIO_IMR_P3(value)                     (PIO_IMR_P3_Msk & (_UINT32_(value) << PIO_IMR_P3_Pos)) /* Assigment of value for P3 in the PIO_IMR register */
#define PIO_IMR_P4_Pos                        _UINT32_(4)                                          /* (PIO_IMR) Input Change Interrupt Mask Position */
#define PIO_IMR_P4_Msk                        (_UINT32_(0x1) << PIO_IMR_P4_Pos)                    /* (PIO_IMR) Input Change Interrupt Mask Mask */
#define PIO_IMR_P4(value)                     (PIO_IMR_P4_Msk & (_UINT32_(value) << PIO_IMR_P4_Pos)) /* Assigment of value for P4 in the PIO_IMR register */
#define PIO_IMR_P5_Pos                        _UINT32_(5)                                          /* (PIO_IMR) Input Change Interrupt Mask Position */
#define PIO_IMR_P5_Msk                        (_UINT32_(0x1) << PIO_IMR_P5_Pos)                    /* (PIO_IMR) Input Change Interrupt Mask Mask */
#define PIO_IMR_P5(value)                     (PIO_IMR_P5_Msk & (_UINT32_(value) << PIO_IMR_P5_Pos)) /* Assigment of value for P5 in the PIO_IMR register */
#define PIO_IMR_P6_Pos                        _UINT32_(6)                                          /* (PIO_IMR) Input Change Interrupt Mask Position */
#define PIO_IMR_P6_Msk                        (_UINT32_(0x1) << PIO_IMR_P6_Pos)                    /* (PIO_IMR) Input Change Interrupt Mask Mask */
#define PIO_IMR_P6(value)                     (PIO_IMR_P6_Msk & (_UINT32_(value) << PIO_IMR_P6_Pos)) /* Assigment of value for P6 in the PIO_IMR register */
#define PIO_IMR_P7_Pos                        _UINT32_(7)                                          /* (PIO_IMR) Input Change Interrupt Mask Position */
#define PIO_IMR_P7_Msk                        (_UINT32_(0x1) << PIO_IMR_P7_Pos)                    /* (PIO_IMR) Input Change Interrupt Mask Mask */
#define PIO_IMR_P7(value)                     (PIO_IMR_P7_Msk & (_UINT32_(value) << PIO_IMR_P7_Pos)) /* Assigment of value for P7 in the PIO_IMR register */
#define PIO_IMR_P8_Pos                        _UINT32_(8)                                          /* (PIO_IMR) Input Change Interrupt Mask Position */
#define PIO_IMR_P8_Msk                        (_UINT32_(0x1) << PIO_IMR_P8_Pos)                    /* (PIO_IMR) Input Change Interrupt Mask Mask */
#define PIO_IMR_P8(value)                     (PIO_IMR_P8_Msk & (_UINT32_(value) << PIO_IMR_P8_Pos)) /* Assigment of value for P8 in the PIO_IMR register */
#define PIO_IMR_P9_Pos                        _UINT32_(9)                                          /* (PIO_IMR) Input Change Interrupt Mask Position */
#define PIO_IMR_P9_Msk                        (_UINT32_(0x1) << PIO_IMR_P9_Pos)                    /* (PIO_IMR) Input Change Interrupt Mask Mask */
#define PIO_IMR_P9(value)                     (PIO_IMR_P9_Msk & (_UINT32_(value) << PIO_IMR_P9_Pos)) /* Assigment of value for P9 in the PIO_IMR register */
#define PIO_IMR_P10_Pos                       _UINT32_(10)                                         /* (PIO_IMR) Input Change Interrupt Mask Position */
#define PIO_IMR_P10_Msk                       (_UINT32_(0x1) << PIO_IMR_P10_Pos)                   /* (PIO_IMR) Input Change Interrupt Mask Mask */
#define PIO_IMR_P10(value)                    (PIO_IMR_P10_Msk & (_UINT32_(value) << PIO_IMR_P10_Pos)) /* Assigment of value for P10 in the PIO_IMR register */
#define PIO_IMR_P11_Pos                       _UINT32_(11)                                         /* (PIO_IMR) Input Change Interrupt Mask Position */
#define PIO_IMR_P11_Msk                       (_UINT32_(0x1) << PIO_IMR_P11_Pos)                   /* (PIO_IMR) Input Change Interrupt Mask Mask */
#define PIO_IMR_P11(value)                    (PIO_IMR_P11_Msk & (_UINT32_(value) << PIO_IMR_P11_Pos)) /* Assigment of value for P11 in the PIO_IMR register */
#define PIO_IMR_P12_Pos                       _UINT32_(12)                                         /* (PIO_IMR) Input Change Interrupt Mask Position */
#define PIO_IMR_P12_Msk                       (_UINT32_(0x1) << PIO_IMR_P12_Pos)                   /* (PIO_IMR) Input Change Interrupt Mask Mask */
#define PIO_IMR_P12(value)                    (PIO_IMR_P12_Msk & (_UINT32_(value) << PIO_IMR_P12_Pos)) /* Assigment of value for P12 in the PIO_IMR register */
#define PIO_IMR_P13_Pos                       _UINT32_(13)                                         /* (PIO_IMR) Input Change Interrupt Mask Position */
#define PIO_IMR_P13_Msk                       (_UINT32_(0x1) << PIO_IMR_P13_Pos)                   /* (PIO_IMR) Input Change Interrupt Mask Mask */
#define PIO_IMR_P13(value)                    (PIO_IMR_P13_Msk & (_UINT32_(value) << PIO_IMR_P13_Pos)) /* Assigment of value for P13 in the PIO_IMR register */
#define PIO_IMR_P14_Pos                       _UINT32_(14)                                         /* (PIO_IMR) Input Change Interrupt Mask Position */
#define PIO_IMR_P14_Msk                       (_UINT32_(0x1) << PIO_IMR_P14_Pos)                   /* (PIO_IMR) Input Change Interrupt Mask Mask */
#define PIO_IMR_P14(value)                    (PIO_IMR_P14_Msk & (_UINT32_(value) << PIO_IMR_P14_Pos)) /* Assigment of value for P14 in the PIO_IMR register */
#define PIO_IMR_P15_Pos                       _UINT32_(15)                                         /* (PIO_IMR) Input Change Interrupt Mask Position */
#define PIO_IMR_P15_Msk                       (_UINT32_(0x1) << PIO_IMR_P15_Pos)                   /* (PIO_IMR) Input Change Interrupt Mask Mask */
#define PIO_IMR_P15(value)                    (PIO_IMR_P15_Msk & (_UINT32_(value) << PIO_IMR_P15_Pos)) /* Assigment of value for P15 in the PIO_IMR register */
#define PIO_IMR_P16_Pos                       _UINT32_(16)                                         /* (PIO_IMR) Input Change Interrupt Mask Position */
#define PIO_IMR_P16_Msk                       (_UINT32_(0x1) << PIO_IMR_P16_Pos)                   /* (PIO_IMR) Input Change Interrupt Mask Mask */
#define PIO_IMR_P16(value)                    (PIO_IMR_P16_Msk & (_UINT32_(value) << PIO_IMR_P16_Pos)) /* Assigment of value for P16 in the PIO_IMR register */
#define PIO_IMR_P17_Pos                       _UINT32_(17)                                         /* (PIO_IMR) Input Change Interrupt Mask Position */
#define PIO_IMR_P17_Msk                       (_UINT32_(0x1) << PIO_IMR_P17_Pos)                   /* (PIO_IMR) Input Change Interrupt Mask Mask */
#define PIO_IMR_P17(value)                    (PIO_IMR_P17_Msk & (_UINT32_(value) << PIO_IMR_P17_Pos)) /* Assigment of value for P17 in the PIO_IMR register */
#define PIO_IMR_P18_Pos                       _UINT32_(18)                                         /* (PIO_IMR) Input Change Interrupt Mask Position */
#define PIO_IMR_P18_Msk                       (_UINT32_(0x1) << PIO_IMR_P18_Pos)                   /* (PIO_IMR) Input Change Interrupt Mask Mask */
#define PIO_IMR_P18(value)                    (PIO_IMR_P18_Msk & (_UINT32_(value) << PIO_IMR_P18_Pos)) /* Assigment of value for P18 in the PIO_IMR register */
#define PIO_IMR_P19_Pos                       _UINT32_(19)                                         /* (PIO_IMR) Input Change Interrupt Mask Position */
#define PIO_IMR_P19_Msk                       (_UINT32_(0x1) << PIO_IMR_P19_Pos)                   /* (PIO_IMR) Input Change Interrupt Mask Mask */
#define PIO_IMR_P19(value)                    (PIO_IMR_P19_Msk & (_UINT32_(value) << PIO_IMR_P19_Pos)) /* Assigment of value for P19 in the PIO_IMR register */
#define PIO_IMR_P20_Pos                       _UINT32_(20)                                         /* (PIO_IMR) Input Change Interrupt Mask Position */
#define PIO_IMR_P20_Msk                       (_UINT32_(0x1) << PIO_IMR_P20_Pos)                   /* (PIO_IMR) Input Change Interrupt Mask Mask */
#define PIO_IMR_P20(value)                    (PIO_IMR_P20_Msk & (_UINT32_(value) << PIO_IMR_P20_Pos)) /* Assigment of value for P20 in the PIO_IMR register */
#define PIO_IMR_P21_Pos                       _UINT32_(21)                                         /* (PIO_IMR) Input Change Interrupt Mask Position */
#define PIO_IMR_P21_Msk                       (_UINT32_(0x1) << PIO_IMR_P21_Pos)                   /* (PIO_IMR) Input Change Interrupt Mask Mask */
#define PIO_IMR_P21(value)                    (PIO_IMR_P21_Msk & (_UINT32_(value) << PIO_IMR_P21_Pos)) /* Assigment of value for P21 in the PIO_IMR register */
#define PIO_IMR_P22_Pos                       _UINT32_(22)                                         /* (PIO_IMR) Input Change Interrupt Mask Position */
#define PIO_IMR_P22_Msk                       (_UINT32_(0x1) << PIO_IMR_P22_Pos)                   /* (PIO_IMR) Input Change Interrupt Mask Mask */
#define PIO_IMR_P22(value)                    (PIO_IMR_P22_Msk & (_UINT32_(value) << PIO_IMR_P22_Pos)) /* Assigment of value for P22 in the PIO_IMR register */
#define PIO_IMR_P23_Pos                       _UINT32_(23)                                         /* (PIO_IMR) Input Change Interrupt Mask Position */
#define PIO_IMR_P23_Msk                       (_UINT32_(0x1) << PIO_IMR_P23_Pos)                   /* (PIO_IMR) Input Change Interrupt Mask Mask */
#define PIO_IMR_P23(value)                    (PIO_IMR_P23_Msk & (_UINT32_(value) << PIO_IMR_P23_Pos)) /* Assigment of value for P23 in the PIO_IMR register */
#define PIO_IMR_P24_Pos                       _UINT32_(24)                                         /* (PIO_IMR) Input Change Interrupt Mask Position */
#define PIO_IMR_P24_Msk                       (_UINT32_(0x1) << PIO_IMR_P24_Pos)                   /* (PIO_IMR) Input Change Interrupt Mask Mask */
#define PIO_IMR_P24(value)                    (PIO_IMR_P24_Msk & (_UINT32_(value) << PIO_IMR_P24_Pos)) /* Assigment of value for P24 in the PIO_IMR register */
#define PIO_IMR_P25_Pos                       _UINT32_(25)                                         /* (PIO_IMR) Input Change Interrupt Mask Position */
#define PIO_IMR_P25_Msk                       (_UINT32_(0x1) << PIO_IMR_P25_Pos)                   /* (PIO_IMR) Input Change Interrupt Mask Mask */
#define PIO_IMR_P25(value)                    (PIO_IMR_P25_Msk & (_UINT32_(value) << PIO_IMR_P25_Pos)) /* Assigment of value for P25 in the PIO_IMR register */
#define PIO_IMR_P26_Pos                       _UINT32_(26)                                         /* (PIO_IMR) Input Change Interrupt Mask Position */
#define PIO_IMR_P26_Msk                       (_UINT32_(0x1) << PIO_IMR_P26_Pos)                   /* (PIO_IMR) Input Change Interrupt Mask Mask */
#define PIO_IMR_P26(value)                    (PIO_IMR_P26_Msk & (_UINT32_(value) << PIO_IMR_P26_Pos)) /* Assigment of value for P26 in the PIO_IMR register */
#define PIO_IMR_P27_Pos                       _UINT32_(27)                                         /* (PIO_IMR) Input Change Interrupt Mask Position */
#define PIO_IMR_P27_Msk                       (_UINT32_(0x1) << PIO_IMR_P27_Pos)                   /* (PIO_IMR) Input Change Interrupt Mask Mask */
#define PIO_IMR_P27(value)                    (PIO_IMR_P27_Msk & (_UINT32_(value) << PIO_IMR_P27_Pos)) /* Assigment of value for P27 in the PIO_IMR register */
#define PIO_IMR_P28_Pos                       _UINT32_(28)                                         /* (PIO_IMR) Input Change Interrupt Mask Position */
#define PIO_IMR_P28_Msk                       (_UINT32_(0x1) << PIO_IMR_P28_Pos)                   /* (PIO_IMR) Input Change Interrupt Mask Mask */
#define PIO_IMR_P28(value)                    (PIO_IMR_P28_Msk & (_UINT32_(value) << PIO_IMR_P28_Pos)) /* Assigment of value for P28 in the PIO_IMR register */
#define PIO_IMR_P29_Pos                       _UINT32_(29)                                         /* (PIO_IMR) Input Change Interrupt Mask Position */
#define PIO_IMR_P29_Msk                       (_UINT32_(0x1) << PIO_IMR_P29_Pos)                   /* (PIO_IMR) Input Change Interrupt Mask Mask */
#define PIO_IMR_P29(value)                    (PIO_IMR_P29_Msk & (_UINT32_(value) << PIO_IMR_P29_Pos)) /* Assigment of value for P29 in the PIO_IMR register */
#define PIO_IMR_P30_Pos                       _UINT32_(30)                                         /* (PIO_IMR) Input Change Interrupt Mask Position */
#define PIO_IMR_P30_Msk                       (_UINT32_(0x1) << PIO_IMR_P30_Pos)                   /* (PIO_IMR) Input Change Interrupt Mask Mask */
#define PIO_IMR_P30(value)                    (PIO_IMR_P30_Msk & (_UINT32_(value) << PIO_IMR_P30_Pos)) /* Assigment of value for P30 in the PIO_IMR register */
#define PIO_IMR_P31_Pos                       _UINT32_(31)                                         /* (PIO_IMR) Input Change Interrupt Mask Position */
#define PIO_IMR_P31_Msk                       (_UINT32_(0x1) << PIO_IMR_P31_Pos)                   /* (PIO_IMR) Input Change Interrupt Mask Mask */
#define PIO_IMR_P31(value)                    (PIO_IMR_P31_Msk & (_UINT32_(value) << PIO_IMR_P31_Pos)) /* Assigment of value for P31 in the PIO_IMR register */
#define PIO_IMR_Msk                           _UINT32_(0xFFFFFFFF)                                 /* (PIO_IMR) Register Mask  */

#define PIO_IMR_P_Pos                         _UINT32_(0)                                          /* (PIO_IMR Position) Input Change Interrupt Mask */
#define PIO_IMR_P_Msk                         (_UINT32_(0xFFFFFFFF) << PIO_IMR_P_Pos)              /* (PIO_IMR Mask) P */
#define PIO_IMR_P(value)                      (PIO_IMR_P_Msk & (_UINT32_(value) << PIO_IMR_P_Pos)) 

/* -------- PIO_ISR : (PIO Offset: 0x2C) ( R/ 32) PIO Interrupt Status Register -------- */
#define PIO_ISR_P0_Pos                        _UINT32_(0)                                          /* (PIO_ISR) Input Change Interrupt Status Position */
#define PIO_ISR_P0_Msk                        (_UINT32_(0x1) << PIO_ISR_P0_Pos)                    /* (PIO_ISR) Input Change Interrupt Status Mask */
#define PIO_ISR_P0(value)                     (PIO_ISR_P0_Msk & (_UINT32_(value) << PIO_ISR_P0_Pos)) /* Assigment of value for P0 in the PIO_ISR register */
#define PIO_ISR_P1_Pos                        _UINT32_(1)                                          /* (PIO_ISR) Input Change Interrupt Status Position */
#define PIO_ISR_P1_Msk                        (_UINT32_(0x1) << PIO_ISR_P1_Pos)                    /* (PIO_ISR) Input Change Interrupt Status Mask */
#define PIO_ISR_P1(value)                     (PIO_ISR_P1_Msk & (_UINT32_(value) << PIO_ISR_P1_Pos)) /* Assigment of value for P1 in the PIO_ISR register */
#define PIO_ISR_P2_Pos                        _UINT32_(2)                                          /* (PIO_ISR) Input Change Interrupt Status Position */
#define PIO_ISR_P2_Msk                        (_UINT32_(0x1) << PIO_ISR_P2_Pos)                    /* (PIO_ISR) Input Change Interrupt Status Mask */
#define PIO_ISR_P2(value)                     (PIO_ISR_P2_Msk & (_UINT32_(value) << PIO_ISR_P2_Pos)) /* Assigment of value for P2 in the PIO_ISR register */
#define PIO_ISR_P3_Pos                        _UINT32_(3)                                          /* (PIO_ISR) Input Change Interrupt Status Position */
#define PIO_ISR_P3_Msk                        (_UINT32_(0x1) << PIO_ISR_P3_Pos)                    /* (PIO_ISR) Input Change Interrupt Status Mask */
#define PIO_ISR_P3(value)                     (PIO_ISR_P3_Msk & (_UINT32_(value) << PIO_ISR_P3_Pos)) /* Assigment of value for P3 in the PIO_ISR register */
#define PIO_ISR_P4_Pos                        _UINT32_(4)                                          /* (PIO_ISR) Input Change Interrupt Status Position */
#define PIO_ISR_P4_Msk                        (_UINT32_(0x1) << PIO_ISR_P4_Pos)                    /* (PIO_ISR) Input Change Interrupt Status Mask */
#define PIO_ISR_P4(value)                     (PIO_ISR_P4_Msk & (_UINT32_(value) << PIO_ISR_P4_Pos)) /* Assigment of value for P4 in the PIO_ISR register */
#define PIO_ISR_P5_Pos                        _UINT32_(5)                                          /* (PIO_ISR) Input Change Interrupt Status Position */
#define PIO_ISR_P5_Msk                        (_UINT32_(0x1) << PIO_ISR_P5_Pos)                    /* (PIO_ISR) Input Change Interrupt Status Mask */
#define PIO_ISR_P5(value)                     (PIO_ISR_P5_Msk & (_UINT32_(value) << PIO_ISR_P5_Pos)) /* Assigment of value for P5 in the PIO_ISR register */
#define PIO_ISR_P6_Pos                        _UINT32_(6)                                          /* (PIO_ISR) Input Change Interrupt Status Position */
#define PIO_ISR_P6_Msk                        (_UINT32_(0x1) << PIO_ISR_P6_Pos)                    /* (PIO_ISR) Input Change Interrupt Status Mask */
#define PIO_ISR_P6(value)                     (PIO_ISR_P6_Msk & (_UINT32_(value) << PIO_ISR_P6_Pos)) /* Assigment of value for P6 in the PIO_ISR register */
#define PIO_ISR_P7_Pos                        _UINT32_(7)                                          /* (PIO_ISR) Input Change Interrupt Status Position */
#define PIO_ISR_P7_Msk                        (_UINT32_(0x1) << PIO_ISR_P7_Pos)                    /* (PIO_ISR) Input Change Interrupt Status Mask */
#define PIO_ISR_P7(value)                     (PIO_ISR_P7_Msk & (_UINT32_(value) << PIO_ISR_P7_Pos)) /* Assigment of value for P7 in the PIO_ISR register */
#define PIO_ISR_P8_Pos                        _UINT32_(8)                                          /* (PIO_ISR) Input Change Interrupt Status Position */
#define PIO_ISR_P8_Msk                        (_UINT32_(0x1) << PIO_ISR_P8_Pos)                    /* (PIO_ISR) Input Change Interrupt Status Mask */
#define PIO_ISR_P8(value)                     (PIO_ISR_P8_Msk & (_UINT32_(value) << PIO_ISR_P8_Pos)) /* Assigment of value for P8 in the PIO_ISR register */
#define PIO_ISR_P9_Pos                        _UINT32_(9)                                          /* (PIO_ISR) Input Change Interrupt Status Position */
#define PIO_ISR_P9_Msk                        (_UINT32_(0x1) << PIO_ISR_P9_Pos)                    /* (PIO_ISR) Input Change Interrupt Status Mask */
#define PIO_ISR_P9(value)                     (PIO_ISR_P9_Msk & (_UINT32_(value) << PIO_ISR_P9_Pos)) /* Assigment of value for P9 in the PIO_ISR register */
#define PIO_ISR_P10_Pos                       _UINT32_(10)                                         /* (PIO_ISR) Input Change Interrupt Status Position */
#define PIO_ISR_P10_Msk                       (_UINT32_(0x1) << PIO_ISR_P10_Pos)                   /* (PIO_ISR) Input Change Interrupt Status Mask */
#define PIO_ISR_P10(value)                    (PIO_ISR_P10_Msk & (_UINT32_(value) << PIO_ISR_P10_Pos)) /* Assigment of value for P10 in the PIO_ISR register */
#define PIO_ISR_P11_Pos                       _UINT32_(11)                                         /* (PIO_ISR) Input Change Interrupt Status Position */
#define PIO_ISR_P11_Msk                       (_UINT32_(0x1) << PIO_ISR_P11_Pos)                   /* (PIO_ISR) Input Change Interrupt Status Mask */
#define PIO_ISR_P11(value)                    (PIO_ISR_P11_Msk & (_UINT32_(value) << PIO_ISR_P11_Pos)) /* Assigment of value for P11 in the PIO_ISR register */
#define PIO_ISR_P12_Pos                       _UINT32_(12)                                         /* (PIO_ISR) Input Change Interrupt Status Position */
#define PIO_ISR_P12_Msk                       (_UINT32_(0x1) << PIO_ISR_P12_Pos)                   /* (PIO_ISR) Input Change Interrupt Status Mask */
#define PIO_ISR_P12(value)                    (PIO_ISR_P12_Msk & (_UINT32_(value) << PIO_ISR_P12_Pos)) /* Assigment of value for P12 in the PIO_ISR register */
#define PIO_ISR_P13_Pos                       _UINT32_(13)                                         /* (PIO_ISR) Input Change Interrupt Status Position */
#define PIO_ISR_P13_Msk                       (_UINT32_(0x1) << PIO_ISR_P13_Pos)                   /* (PIO_ISR) Input Change Interrupt Status Mask */
#define PIO_ISR_P13(value)                    (PIO_ISR_P13_Msk & (_UINT32_(value) << PIO_ISR_P13_Pos)) /* Assigment of value for P13 in the PIO_ISR register */
#define PIO_ISR_P14_Pos                       _UINT32_(14)                                         /* (PIO_ISR) Input Change Interrupt Status Position */
#define PIO_ISR_P14_Msk                       (_UINT32_(0x1) << PIO_ISR_P14_Pos)                   /* (PIO_ISR) Input Change Interrupt Status Mask */
#define PIO_ISR_P14(value)                    (PIO_ISR_P14_Msk & (_UINT32_(value) << PIO_ISR_P14_Pos)) /* Assigment of value for P14 in the PIO_ISR register */
#define PIO_ISR_P15_Pos                       _UINT32_(15)                                         /* (PIO_ISR) Input Change Interrupt Status Position */
#define PIO_ISR_P15_Msk                       (_UINT32_(0x1) << PIO_ISR_P15_Pos)                   /* (PIO_ISR) Input Change Interrupt Status Mask */
#define PIO_ISR_P15(value)                    (PIO_ISR_P15_Msk & (_UINT32_(value) << PIO_ISR_P15_Pos)) /* Assigment of value for P15 in the PIO_ISR register */
#define PIO_ISR_P16_Pos                       _UINT32_(16)                                         /* (PIO_ISR) Input Change Interrupt Status Position */
#define PIO_ISR_P16_Msk                       (_UINT32_(0x1) << PIO_ISR_P16_Pos)                   /* (PIO_ISR) Input Change Interrupt Status Mask */
#define PIO_ISR_P16(value)                    (PIO_ISR_P16_Msk & (_UINT32_(value) << PIO_ISR_P16_Pos)) /* Assigment of value for P16 in the PIO_ISR register */
#define PIO_ISR_P17_Pos                       _UINT32_(17)                                         /* (PIO_ISR) Input Change Interrupt Status Position */
#define PIO_ISR_P17_Msk                       (_UINT32_(0x1) << PIO_ISR_P17_Pos)                   /* (PIO_ISR) Input Change Interrupt Status Mask */
#define PIO_ISR_P17(value)                    (PIO_ISR_P17_Msk & (_UINT32_(value) << PIO_ISR_P17_Pos)) /* Assigment of value for P17 in the PIO_ISR register */
#define PIO_ISR_P18_Pos                       _UINT32_(18)                                         /* (PIO_ISR) Input Change Interrupt Status Position */
#define PIO_ISR_P18_Msk                       (_UINT32_(0x1) << PIO_ISR_P18_Pos)                   /* (PIO_ISR) Input Change Interrupt Status Mask */
#define PIO_ISR_P18(value)                    (PIO_ISR_P18_Msk & (_UINT32_(value) << PIO_ISR_P18_Pos)) /* Assigment of value for P18 in the PIO_ISR register */
#define PIO_ISR_P19_Pos                       _UINT32_(19)                                         /* (PIO_ISR) Input Change Interrupt Status Position */
#define PIO_ISR_P19_Msk                       (_UINT32_(0x1) << PIO_ISR_P19_Pos)                   /* (PIO_ISR) Input Change Interrupt Status Mask */
#define PIO_ISR_P19(value)                    (PIO_ISR_P19_Msk & (_UINT32_(value) << PIO_ISR_P19_Pos)) /* Assigment of value for P19 in the PIO_ISR register */
#define PIO_ISR_P20_Pos                       _UINT32_(20)                                         /* (PIO_ISR) Input Change Interrupt Status Position */
#define PIO_ISR_P20_Msk                       (_UINT32_(0x1) << PIO_ISR_P20_Pos)                   /* (PIO_ISR) Input Change Interrupt Status Mask */
#define PIO_ISR_P20(value)                    (PIO_ISR_P20_Msk & (_UINT32_(value) << PIO_ISR_P20_Pos)) /* Assigment of value for P20 in the PIO_ISR register */
#define PIO_ISR_P21_Pos                       _UINT32_(21)                                         /* (PIO_ISR) Input Change Interrupt Status Position */
#define PIO_ISR_P21_Msk                       (_UINT32_(0x1) << PIO_ISR_P21_Pos)                   /* (PIO_ISR) Input Change Interrupt Status Mask */
#define PIO_ISR_P21(value)                    (PIO_ISR_P21_Msk & (_UINT32_(value) << PIO_ISR_P21_Pos)) /* Assigment of value for P21 in the PIO_ISR register */
#define PIO_ISR_P22_Pos                       _UINT32_(22)                                         /* (PIO_ISR) Input Change Interrupt Status Position */
#define PIO_ISR_P22_Msk                       (_UINT32_(0x1) << PIO_ISR_P22_Pos)                   /* (PIO_ISR) Input Change Interrupt Status Mask */
#define PIO_ISR_P22(value)                    (PIO_ISR_P22_Msk & (_UINT32_(value) << PIO_ISR_P22_Pos)) /* Assigment of value for P22 in the PIO_ISR register */
#define PIO_ISR_P23_Pos                       _UINT32_(23)                                         /* (PIO_ISR) Input Change Interrupt Status Position */
#define PIO_ISR_P23_Msk                       (_UINT32_(0x1) << PIO_ISR_P23_Pos)                   /* (PIO_ISR) Input Change Interrupt Status Mask */
#define PIO_ISR_P23(value)                    (PIO_ISR_P23_Msk & (_UINT32_(value) << PIO_ISR_P23_Pos)) /* Assigment of value for P23 in the PIO_ISR register */
#define PIO_ISR_P24_Pos                       _UINT32_(24)                                         /* (PIO_ISR) Input Change Interrupt Status Position */
#define PIO_ISR_P24_Msk                       (_UINT32_(0x1) << PIO_ISR_P24_Pos)                   /* (PIO_ISR) Input Change Interrupt Status Mask */
#define PIO_ISR_P24(value)                    (PIO_ISR_P24_Msk & (_UINT32_(value) << PIO_ISR_P24_Pos)) /* Assigment of value for P24 in the PIO_ISR register */
#define PIO_ISR_P25_Pos                       _UINT32_(25)                                         /* (PIO_ISR) Input Change Interrupt Status Position */
#define PIO_ISR_P25_Msk                       (_UINT32_(0x1) << PIO_ISR_P25_Pos)                   /* (PIO_ISR) Input Change Interrupt Status Mask */
#define PIO_ISR_P25(value)                    (PIO_ISR_P25_Msk & (_UINT32_(value) << PIO_ISR_P25_Pos)) /* Assigment of value for P25 in the PIO_ISR register */
#define PIO_ISR_P26_Pos                       _UINT32_(26)                                         /* (PIO_ISR) Input Change Interrupt Status Position */
#define PIO_ISR_P26_Msk                       (_UINT32_(0x1) << PIO_ISR_P26_Pos)                   /* (PIO_ISR) Input Change Interrupt Status Mask */
#define PIO_ISR_P26(value)                    (PIO_ISR_P26_Msk & (_UINT32_(value) << PIO_ISR_P26_Pos)) /* Assigment of value for P26 in the PIO_ISR register */
#define PIO_ISR_P27_Pos                       _UINT32_(27)                                         /* (PIO_ISR) Input Change Interrupt Status Position */
#define PIO_ISR_P27_Msk                       (_UINT32_(0x1) << PIO_ISR_P27_Pos)                   /* (PIO_ISR) Input Change Interrupt Status Mask */
#define PIO_ISR_P27(value)                    (PIO_ISR_P27_Msk & (_UINT32_(value) << PIO_ISR_P27_Pos)) /* Assigment of value for P27 in the PIO_ISR register */
#define PIO_ISR_P28_Pos                       _UINT32_(28)                                         /* (PIO_ISR) Input Change Interrupt Status Position */
#define PIO_ISR_P28_Msk                       (_UINT32_(0x1) << PIO_ISR_P28_Pos)                   /* (PIO_ISR) Input Change Interrupt Status Mask */
#define PIO_ISR_P28(value)                    (PIO_ISR_P28_Msk & (_UINT32_(value) << PIO_ISR_P28_Pos)) /* Assigment of value for P28 in the PIO_ISR register */
#define PIO_ISR_P29_Pos                       _UINT32_(29)                                         /* (PIO_ISR) Input Change Interrupt Status Position */
#define PIO_ISR_P29_Msk                       (_UINT32_(0x1) << PIO_ISR_P29_Pos)                   /* (PIO_ISR) Input Change Interrupt Status Mask */
#define PIO_ISR_P29(value)                    (PIO_ISR_P29_Msk & (_UINT32_(value) << PIO_ISR_P29_Pos)) /* Assigment of value for P29 in the PIO_ISR register */
#define PIO_ISR_P30_Pos                       _UINT32_(30)                                         /* (PIO_ISR) Input Change Interrupt Status Position */
#define PIO_ISR_P30_Msk                       (_UINT32_(0x1) << PIO_ISR_P30_Pos)                   /* (PIO_ISR) Input Change Interrupt Status Mask */
#define PIO_ISR_P30(value)                    (PIO_ISR_P30_Msk & (_UINT32_(value) << PIO_ISR_P30_Pos)) /* Assigment of value for P30 in the PIO_ISR register */
#define PIO_ISR_P31_Pos                       _UINT32_(31)                                         /* (PIO_ISR) Input Change Interrupt Status Position */
#define PIO_ISR_P31_Msk                       (_UINT32_(0x1) << PIO_ISR_P31_Pos)                   /* (PIO_ISR) Input Change Interrupt Status Mask */
#define PIO_ISR_P31(value)                    (PIO_ISR_P31_Msk & (_UINT32_(value) << PIO_ISR_P31_Pos)) /* Assigment of value for P31 in the PIO_ISR register */
#define PIO_ISR_Msk                           _UINT32_(0xFFFFFFFF)                                 /* (PIO_ISR) Register Mask  */

#define PIO_ISR_P_Pos                         _UINT32_(0)                                          /* (PIO_ISR Position) Input Change Interrupt Status */
#define PIO_ISR_P_Msk                         (_UINT32_(0xFFFFFFFF) << PIO_ISR_P_Pos)              /* (PIO_ISR Mask) P */
#define PIO_ISR_P(value)                      (PIO_ISR_P_Msk & (_UINT32_(value) << PIO_ISR_P_Pos)) 

/* -------- PIO_IOFR : (PIO Offset: 0x3C) ( /W 32) PIO I/O Freeze Configuration Register -------- */
#define PIO_IOFR_FPHY_Pos                     _UINT32_(0)                                          /* (PIO_IOFR) Freeze Physical Configuration Position */
#define PIO_IOFR_FPHY_Msk                     (_UINT32_(0x1) << PIO_IOFR_FPHY_Pos)                 /* (PIO_IOFR) Freeze Physical Configuration Mask */
#define PIO_IOFR_FPHY(value)                  (PIO_IOFR_FPHY_Msk & (_UINT32_(value) << PIO_IOFR_FPHY_Pos)) /* Assigment of value for FPHY in the PIO_IOFR register */
#define PIO_IOFR_FINT_Pos                     _UINT32_(1)                                          /* (PIO_IOFR) Freeze Interrupt Configuration Position */
#define PIO_IOFR_FINT_Msk                     (_UINT32_(0x1) << PIO_IOFR_FINT_Pos)                 /* (PIO_IOFR) Freeze Interrupt Configuration Mask */
#define PIO_IOFR_FINT(value)                  (PIO_IOFR_FINT_Msk & (_UINT32_(value) << PIO_IOFR_FINT_Pos)) /* Assigment of value for FINT in the PIO_IOFR register */
#define PIO_IOFR_FRZKEY_Pos                   _UINT32_(8)                                          /* (PIO_IOFR) Freeze Key Position */
#define PIO_IOFR_FRZKEY_Msk                   (_UINT32_(0xFFFFFF) << PIO_IOFR_FRZKEY_Pos)          /* (PIO_IOFR) Freeze Key Mask */
#define PIO_IOFR_FRZKEY(value)                (PIO_IOFR_FRZKEY_Msk & (_UINT32_(value) << PIO_IOFR_FRZKEY_Pos)) /* Assigment of value for FRZKEY in the PIO_IOFR register */
#define   PIO_IOFR_FRZKEY_PASSWD_Val          _UINT32_(0x494F46)                                   /* (PIO_IOFR) Writing any other value in this field aborts the write operation of the WPEN bit.  */
#define PIO_IOFR_FRZKEY_PASSWD                (PIO_IOFR_FRZKEY_PASSWD_Val << PIO_IOFR_FRZKEY_Pos)  /* (PIO_IOFR) Writing any other value in this field aborts the write operation of the WPEN bit. Position  */
#define PIO_IOFR_Msk                          _UINT32_(0xFFFFFF03)                                 /* (PIO_IOFR) Register Mask  */


/* -------- PIO_P_MSKR : (PIO Offset: 0x00) (R/W 32) PIO Privilege Mask Register (p_iogroup = 0) -------- */
#define PIO_P_MSKR_MSK0_Pos                   _UINT32_(0)                                          /* (PIO_P_MSKR) PIO Line 0 Mask Position */
#define PIO_P_MSKR_MSK0_Msk                   (_UINT32_(0x1) << PIO_P_MSKR_MSK0_Pos)               /* (PIO_P_MSKR) PIO Line 0 Mask Mask */
#define PIO_P_MSKR_MSK0(value)                (PIO_P_MSKR_MSK0_Msk & (_UINT32_(value) << PIO_P_MSKR_MSK0_Pos)) /* Assigment of value for MSK0 in the PIO_P_MSKR register */
#define   PIO_P_MSKR_MSK0_DISABLED_Val        _UINT32_(0x0)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_P_MSKR_MSK0_ENABLED_Val         _UINT32_(0x1)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration.  */
#define PIO_P_MSKR_MSK0_DISABLED              (PIO_P_MSKR_MSK0_DISABLED_Val << PIO_P_MSKR_MSK0_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK0_ENABLED               (PIO_P_MSKR_MSK0_ENABLED_Val << PIO_P_MSKR_MSK0_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK1_Pos                   _UINT32_(1)                                          /* (PIO_P_MSKR) PIO Line 1 Mask Position */
#define PIO_P_MSKR_MSK1_Msk                   (_UINT32_(0x1) << PIO_P_MSKR_MSK1_Pos)               /* (PIO_P_MSKR) PIO Line 1 Mask Mask */
#define PIO_P_MSKR_MSK1(value)                (PIO_P_MSKR_MSK1_Msk & (_UINT32_(value) << PIO_P_MSKR_MSK1_Pos)) /* Assigment of value for MSK1 in the PIO_P_MSKR register */
#define   PIO_P_MSKR_MSK1_DISABLED_Val        _UINT32_(0x0)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_P_MSKR_MSK1_ENABLED_Val         _UINT32_(0x1)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration.  */
#define PIO_P_MSKR_MSK1_DISABLED              (PIO_P_MSKR_MSK1_DISABLED_Val << PIO_P_MSKR_MSK1_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK1_ENABLED               (PIO_P_MSKR_MSK1_ENABLED_Val << PIO_P_MSKR_MSK1_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK2_Pos                   _UINT32_(2)                                          /* (PIO_P_MSKR) PIO Line 2 Mask Position */
#define PIO_P_MSKR_MSK2_Msk                   (_UINT32_(0x1) << PIO_P_MSKR_MSK2_Pos)               /* (PIO_P_MSKR) PIO Line 2 Mask Mask */
#define PIO_P_MSKR_MSK2(value)                (PIO_P_MSKR_MSK2_Msk & (_UINT32_(value) << PIO_P_MSKR_MSK2_Pos)) /* Assigment of value for MSK2 in the PIO_P_MSKR register */
#define   PIO_P_MSKR_MSK2_DISABLED_Val        _UINT32_(0x0)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_P_MSKR_MSK2_ENABLED_Val         _UINT32_(0x1)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration.  */
#define PIO_P_MSKR_MSK2_DISABLED              (PIO_P_MSKR_MSK2_DISABLED_Val << PIO_P_MSKR_MSK2_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK2_ENABLED               (PIO_P_MSKR_MSK2_ENABLED_Val << PIO_P_MSKR_MSK2_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK3_Pos                   _UINT32_(3)                                          /* (PIO_P_MSKR) PIO Line 3 Mask Position */
#define PIO_P_MSKR_MSK3_Msk                   (_UINT32_(0x1) << PIO_P_MSKR_MSK3_Pos)               /* (PIO_P_MSKR) PIO Line 3 Mask Mask */
#define PIO_P_MSKR_MSK3(value)                (PIO_P_MSKR_MSK3_Msk & (_UINT32_(value) << PIO_P_MSKR_MSK3_Pos)) /* Assigment of value for MSK3 in the PIO_P_MSKR register */
#define   PIO_P_MSKR_MSK3_DISABLED_Val        _UINT32_(0x0)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_P_MSKR_MSK3_ENABLED_Val         _UINT32_(0x1)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration.  */
#define PIO_P_MSKR_MSK3_DISABLED              (PIO_P_MSKR_MSK3_DISABLED_Val << PIO_P_MSKR_MSK3_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK3_ENABLED               (PIO_P_MSKR_MSK3_ENABLED_Val << PIO_P_MSKR_MSK3_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK4_Pos                   _UINT32_(4)                                          /* (PIO_P_MSKR) PIO Line 4 Mask Position */
#define PIO_P_MSKR_MSK4_Msk                   (_UINT32_(0x1) << PIO_P_MSKR_MSK4_Pos)               /* (PIO_P_MSKR) PIO Line 4 Mask Mask */
#define PIO_P_MSKR_MSK4(value)                (PIO_P_MSKR_MSK4_Msk & (_UINT32_(value) << PIO_P_MSKR_MSK4_Pos)) /* Assigment of value for MSK4 in the PIO_P_MSKR register */
#define   PIO_P_MSKR_MSK4_DISABLED_Val        _UINT32_(0x0)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_P_MSKR_MSK4_ENABLED_Val         _UINT32_(0x1)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration.  */
#define PIO_P_MSKR_MSK4_DISABLED              (PIO_P_MSKR_MSK4_DISABLED_Val << PIO_P_MSKR_MSK4_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK4_ENABLED               (PIO_P_MSKR_MSK4_ENABLED_Val << PIO_P_MSKR_MSK4_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK5_Pos                   _UINT32_(5)                                          /* (PIO_P_MSKR) PIO Line 5 Mask Position */
#define PIO_P_MSKR_MSK5_Msk                   (_UINT32_(0x1) << PIO_P_MSKR_MSK5_Pos)               /* (PIO_P_MSKR) PIO Line 5 Mask Mask */
#define PIO_P_MSKR_MSK5(value)                (PIO_P_MSKR_MSK5_Msk & (_UINT32_(value) << PIO_P_MSKR_MSK5_Pos)) /* Assigment of value for MSK5 in the PIO_P_MSKR register */
#define   PIO_P_MSKR_MSK5_DISABLED_Val        _UINT32_(0x0)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_P_MSKR_MSK5_ENABLED_Val         _UINT32_(0x1)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration.  */
#define PIO_P_MSKR_MSK5_DISABLED              (PIO_P_MSKR_MSK5_DISABLED_Val << PIO_P_MSKR_MSK5_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK5_ENABLED               (PIO_P_MSKR_MSK5_ENABLED_Val << PIO_P_MSKR_MSK5_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK6_Pos                   _UINT32_(6)                                          /* (PIO_P_MSKR) PIO Line 6 Mask Position */
#define PIO_P_MSKR_MSK6_Msk                   (_UINT32_(0x1) << PIO_P_MSKR_MSK6_Pos)               /* (PIO_P_MSKR) PIO Line 6 Mask Mask */
#define PIO_P_MSKR_MSK6(value)                (PIO_P_MSKR_MSK6_Msk & (_UINT32_(value) << PIO_P_MSKR_MSK6_Pos)) /* Assigment of value for MSK6 in the PIO_P_MSKR register */
#define   PIO_P_MSKR_MSK6_DISABLED_Val        _UINT32_(0x0)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_P_MSKR_MSK6_ENABLED_Val         _UINT32_(0x1)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration.  */
#define PIO_P_MSKR_MSK6_DISABLED              (PIO_P_MSKR_MSK6_DISABLED_Val << PIO_P_MSKR_MSK6_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK6_ENABLED               (PIO_P_MSKR_MSK6_ENABLED_Val << PIO_P_MSKR_MSK6_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK7_Pos                   _UINT32_(7)                                          /* (PIO_P_MSKR) PIO Line 7 Mask Position */
#define PIO_P_MSKR_MSK7_Msk                   (_UINT32_(0x1) << PIO_P_MSKR_MSK7_Pos)               /* (PIO_P_MSKR) PIO Line 7 Mask Mask */
#define PIO_P_MSKR_MSK7(value)                (PIO_P_MSKR_MSK7_Msk & (_UINT32_(value) << PIO_P_MSKR_MSK7_Pos)) /* Assigment of value for MSK7 in the PIO_P_MSKR register */
#define   PIO_P_MSKR_MSK7_DISABLED_Val        _UINT32_(0x0)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_P_MSKR_MSK7_ENABLED_Val         _UINT32_(0x1)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration.  */
#define PIO_P_MSKR_MSK7_DISABLED              (PIO_P_MSKR_MSK7_DISABLED_Val << PIO_P_MSKR_MSK7_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK7_ENABLED               (PIO_P_MSKR_MSK7_ENABLED_Val << PIO_P_MSKR_MSK7_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK8_Pos                   _UINT32_(8)                                          /* (PIO_P_MSKR) PIO Line 8 Mask Position */
#define PIO_P_MSKR_MSK8_Msk                   (_UINT32_(0x1) << PIO_P_MSKR_MSK8_Pos)               /* (PIO_P_MSKR) PIO Line 8 Mask Mask */
#define PIO_P_MSKR_MSK8(value)                (PIO_P_MSKR_MSK8_Msk & (_UINT32_(value) << PIO_P_MSKR_MSK8_Pos)) /* Assigment of value for MSK8 in the PIO_P_MSKR register */
#define   PIO_P_MSKR_MSK8_DISABLED_Val        _UINT32_(0x0)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_P_MSKR_MSK8_ENABLED_Val         _UINT32_(0x1)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration.  */
#define PIO_P_MSKR_MSK8_DISABLED              (PIO_P_MSKR_MSK8_DISABLED_Val << PIO_P_MSKR_MSK8_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK8_ENABLED               (PIO_P_MSKR_MSK8_ENABLED_Val << PIO_P_MSKR_MSK8_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK9_Pos                   _UINT32_(9)                                          /* (PIO_P_MSKR) PIO Line 9 Mask Position */
#define PIO_P_MSKR_MSK9_Msk                   (_UINT32_(0x1) << PIO_P_MSKR_MSK9_Pos)               /* (PIO_P_MSKR) PIO Line 9 Mask Mask */
#define PIO_P_MSKR_MSK9(value)                (PIO_P_MSKR_MSK9_Msk & (_UINT32_(value) << PIO_P_MSKR_MSK9_Pos)) /* Assigment of value for MSK9 in the PIO_P_MSKR register */
#define   PIO_P_MSKR_MSK9_DISABLED_Val        _UINT32_(0x0)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_P_MSKR_MSK9_ENABLED_Val         _UINT32_(0x1)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration.  */
#define PIO_P_MSKR_MSK9_DISABLED              (PIO_P_MSKR_MSK9_DISABLED_Val << PIO_P_MSKR_MSK9_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK9_ENABLED               (PIO_P_MSKR_MSK9_ENABLED_Val << PIO_P_MSKR_MSK9_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK10_Pos                  _UINT32_(10)                                         /* (PIO_P_MSKR) PIO Line 10 Mask Position */
#define PIO_P_MSKR_MSK10_Msk                  (_UINT32_(0x1) << PIO_P_MSKR_MSK10_Pos)              /* (PIO_P_MSKR) PIO Line 10 Mask Mask */
#define PIO_P_MSKR_MSK10(value)               (PIO_P_MSKR_MSK10_Msk & (_UINT32_(value) << PIO_P_MSKR_MSK10_Pos)) /* Assigment of value for MSK10 in the PIO_P_MSKR register */
#define   PIO_P_MSKR_MSK10_DISABLED_Val       _UINT32_(0x0)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_P_MSKR_MSK10_ENABLED_Val        _UINT32_(0x1)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration.  */
#define PIO_P_MSKR_MSK10_DISABLED             (PIO_P_MSKR_MSK10_DISABLED_Val << PIO_P_MSKR_MSK10_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK10_ENABLED              (PIO_P_MSKR_MSK10_ENABLED_Val << PIO_P_MSKR_MSK10_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK11_Pos                  _UINT32_(11)                                         /* (PIO_P_MSKR) PIO Line 11 Mask Position */
#define PIO_P_MSKR_MSK11_Msk                  (_UINT32_(0x1) << PIO_P_MSKR_MSK11_Pos)              /* (PIO_P_MSKR) PIO Line 11 Mask Mask */
#define PIO_P_MSKR_MSK11(value)               (PIO_P_MSKR_MSK11_Msk & (_UINT32_(value) << PIO_P_MSKR_MSK11_Pos)) /* Assigment of value for MSK11 in the PIO_P_MSKR register */
#define   PIO_P_MSKR_MSK11_DISABLED_Val       _UINT32_(0x0)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_P_MSKR_MSK11_ENABLED_Val        _UINT32_(0x1)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration.  */
#define PIO_P_MSKR_MSK11_DISABLED             (PIO_P_MSKR_MSK11_DISABLED_Val << PIO_P_MSKR_MSK11_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK11_ENABLED              (PIO_P_MSKR_MSK11_ENABLED_Val << PIO_P_MSKR_MSK11_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK12_Pos                  _UINT32_(12)                                         /* (PIO_P_MSKR) PIO Line 12 Mask Position */
#define PIO_P_MSKR_MSK12_Msk                  (_UINT32_(0x1) << PIO_P_MSKR_MSK12_Pos)              /* (PIO_P_MSKR) PIO Line 12 Mask Mask */
#define PIO_P_MSKR_MSK12(value)               (PIO_P_MSKR_MSK12_Msk & (_UINT32_(value) << PIO_P_MSKR_MSK12_Pos)) /* Assigment of value for MSK12 in the PIO_P_MSKR register */
#define   PIO_P_MSKR_MSK12_DISABLED_Val       _UINT32_(0x0)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_P_MSKR_MSK12_ENABLED_Val        _UINT32_(0x1)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration.  */
#define PIO_P_MSKR_MSK12_DISABLED             (PIO_P_MSKR_MSK12_DISABLED_Val << PIO_P_MSKR_MSK12_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK12_ENABLED              (PIO_P_MSKR_MSK12_ENABLED_Val << PIO_P_MSKR_MSK12_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK13_Pos                  _UINT32_(13)                                         /* (PIO_P_MSKR) PIO Line 13 Mask Position */
#define PIO_P_MSKR_MSK13_Msk                  (_UINT32_(0x1) << PIO_P_MSKR_MSK13_Pos)              /* (PIO_P_MSKR) PIO Line 13 Mask Mask */
#define PIO_P_MSKR_MSK13(value)               (PIO_P_MSKR_MSK13_Msk & (_UINT32_(value) << PIO_P_MSKR_MSK13_Pos)) /* Assigment of value for MSK13 in the PIO_P_MSKR register */
#define   PIO_P_MSKR_MSK13_DISABLED_Val       _UINT32_(0x0)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_P_MSKR_MSK13_ENABLED_Val        _UINT32_(0x1)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration.  */
#define PIO_P_MSKR_MSK13_DISABLED             (PIO_P_MSKR_MSK13_DISABLED_Val << PIO_P_MSKR_MSK13_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK13_ENABLED              (PIO_P_MSKR_MSK13_ENABLED_Val << PIO_P_MSKR_MSK13_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK14_Pos                  _UINT32_(14)                                         /* (PIO_P_MSKR) PIO Line 14 Mask Position */
#define PIO_P_MSKR_MSK14_Msk                  (_UINT32_(0x1) << PIO_P_MSKR_MSK14_Pos)              /* (PIO_P_MSKR) PIO Line 14 Mask Mask */
#define PIO_P_MSKR_MSK14(value)               (PIO_P_MSKR_MSK14_Msk & (_UINT32_(value) << PIO_P_MSKR_MSK14_Pos)) /* Assigment of value for MSK14 in the PIO_P_MSKR register */
#define   PIO_P_MSKR_MSK14_DISABLED_Val       _UINT32_(0x0)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_P_MSKR_MSK14_ENABLED_Val        _UINT32_(0x1)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration.  */
#define PIO_P_MSKR_MSK14_DISABLED             (PIO_P_MSKR_MSK14_DISABLED_Val << PIO_P_MSKR_MSK14_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK14_ENABLED              (PIO_P_MSKR_MSK14_ENABLED_Val << PIO_P_MSKR_MSK14_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK15_Pos                  _UINT32_(15)                                         /* (PIO_P_MSKR) PIO Line 15 Mask Position */
#define PIO_P_MSKR_MSK15_Msk                  (_UINT32_(0x1) << PIO_P_MSKR_MSK15_Pos)              /* (PIO_P_MSKR) PIO Line 15 Mask Mask */
#define PIO_P_MSKR_MSK15(value)               (PIO_P_MSKR_MSK15_Msk & (_UINT32_(value) << PIO_P_MSKR_MSK15_Pos)) /* Assigment of value for MSK15 in the PIO_P_MSKR register */
#define   PIO_P_MSKR_MSK15_DISABLED_Val       _UINT32_(0x0)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_P_MSKR_MSK15_ENABLED_Val        _UINT32_(0x1)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration.  */
#define PIO_P_MSKR_MSK15_DISABLED             (PIO_P_MSKR_MSK15_DISABLED_Val << PIO_P_MSKR_MSK15_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK15_ENABLED              (PIO_P_MSKR_MSK15_ENABLED_Val << PIO_P_MSKR_MSK15_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK16_Pos                  _UINT32_(16)                                         /* (PIO_P_MSKR) PIO Line 16 Mask Position */
#define PIO_P_MSKR_MSK16_Msk                  (_UINT32_(0x1) << PIO_P_MSKR_MSK16_Pos)              /* (PIO_P_MSKR) PIO Line 16 Mask Mask */
#define PIO_P_MSKR_MSK16(value)               (PIO_P_MSKR_MSK16_Msk & (_UINT32_(value) << PIO_P_MSKR_MSK16_Pos)) /* Assigment of value for MSK16 in the PIO_P_MSKR register */
#define   PIO_P_MSKR_MSK16_DISABLED_Val       _UINT32_(0x0)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_P_MSKR_MSK16_ENABLED_Val        _UINT32_(0x1)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration.  */
#define PIO_P_MSKR_MSK16_DISABLED             (PIO_P_MSKR_MSK16_DISABLED_Val << PIO_P_MSKR_MSK16_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK16_ENABLED              (PIO_P_MSKR_MSK16_ENABLED_Val << PIO_P_MSKR_MSK16_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK17_Pos                  _UINT32_(17)                                         /* (PIO_P_MSKR) PIO Line 17 Mask Position */
#define PIO_P_MSKR_MSK17_Msk                  (_UINT32_(0x1) << PIO_P_MSKR_MSK17_Pos)              /* (PIO_P_MSKR) PIO Line 17 Mask Mask */
#define PIO_P_MSKR_MSK17(value)               (PIO_P_MSKR_MSK17_Msk & (_UINT32_(value) << PIO_P_MSKR_MSK17_Pos)) /* Assigment of value for MSK17 in the PIO_P_MSKR register */
#define   PIO_P_MSKR_MSK17_DISABLED_Val       _UINT32_(0x0)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_P_MSKR_MSK17_ENABLED_Val        _UINT32_(0x1)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration.  */
#define PIO_P_MSKR_MSK17_DISABLED             (PIO_P_MSKR_MSK17_DISABLED_Val << PIO_P_MSKR_MSK17_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK17_ENABLED              (PIO_P_MSKR_MSK17_ENABLED_Val << PIO_P_MSKR_MSK17_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK18_Pos                  _UINT32_(18)                                         /* (PIO_P_MSKR) PIO Line 18 Mask Position */
#define PIO_P_MSKR_MSK18_Msk                  (_UINT32_(0x1) << PIO_P_MSKR_MSK18_Pos)              /* (PIO_P_MSKR) PIO Line 18 Mask Mask */
#define PIO_P_MSKR_MSK18(value)               (PIO_P_MSKR_MSK18_Msk & (_UINT32_(value) << PIO_P_MSKR_MSK18_Pos)) /* Assigment of value for MSK18 in the PIO_P_MSKR register */
#define   PIO_P_MSKR_MSK18_DISABLED_Val       _UINT32_(0x0)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_P_MSKR_MSK18_ENABLED_Val        _UINT32_(0x1)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration.  */
#define PIO_P_MSKR_MSK18_DISABLED             (PIO_P_MSKR_MSK18_DISABLED_Val << PIO_P_MSKR_MSK18_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK18_ENABLED              (PIO_P_MSKR_MSK18_ENABLED_Val << PIO_P_MSKR_MSK18_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK19_Pos                  _UINT32_(19)                                         /* (PIO_P_MSKR) PIO Line 19 Mask Position */
#define PIO_P_MSKR_MSK19_Msk                  (_UINT32_(0x1) << PIO_P_MSKR_MSK19_Pos)              /* (PIO_P_MSKR) PIO Line 19 Mask Mask */
#define PIO_P_MSKR_MSK19(value)               (PIO_P_MSKR_MSK19_Msk & (_UINT32_(value) << PIO_P_MSKR_MSK19_Pos)) /* Assigment of value for MSK19 in the PIO_P_MSKR register */
#define   PIO_P_MSKR_MSK19_DISABLED_Val       _UINT32_(0x0)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_P_MSKR_MSK19_ENABLED_Val        _UINT32_(0x1)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration.  */
#define PIO_P_MSKR_MSK19_DISABLED             (PIO_P_MSKR_MSK19_DISABLED_Val << PIO_P_MSKR_MSK19_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK19_ENABLED              (PIO_P_MSKR_MSK19_ENABLED_Val << PIO_P_MSKR_MSK19_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK20_Pos                  _UINT32_(20)                                         /* (PIO_P_MSKR) PIO Line 20 Mask Position */
#define PIO_P_MSKR_MSK20_Msk                  (_UINT32_(0x1) << PIO_P_MSKR_MSK20_Pos)              /* (PIO_P_MSKR) PIO Line 20 Mask Mask */
#define PIO_P_MSKR_MSK20(value)               (PIO_P_MSKR_MSK20_Msk & (_UINT32_(value) << PIO_P_MSKR_MSK20_Pos)) /* Assigment of value for MSK20 in the PIO_P_MSKR register */
#define   PIO_P_MSKR_MSK20_DISABLED_Val       _UINT32_(0x0)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_P_MSKR_MSK20_ENABLED_Val        _UINT32_(0x1)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration.  */
#define PIO_P_MSKR_MSK20_DISABLED             (PIO_P_MSKR_MSK20_DISABLED_Val << PIO_P_MSKR_MSK20_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK20_ENABLED              (PIO_P_MSKR_MSK20_ENABLED_Val << PIO_P_MSKR_MSK20_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK21_Pos                  _UINT32_(21)                                         /* (PIO_P_MSKR) PIO Line 21 Mask Position */
#define PIO_P_MSKR_MSK21_Msk                  (_UINT32_(0x1) << PIO_P_MSKR_MSK21_Pos)              /* (PIO_P_MSKR) PIO Line 21 Mask Mask */
#define PIO_P_MSKR_MSK21(value)               (PIO_P_MSKR_MSK21_Msk & (_UINT32_(value) << PIO_P_MSKR_MSK21_Pos)) /* Assigment of value for MSK21 in the PIO_P_MSKR register */
#define   PIO_P_MSKR_MSK21_DISABLED_Val       _UINT32_(0x0)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_P_MSKR_MSK21_ENABLED_Val        _UINT32_(0x1)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration.  */
#define PIO_P_MSKR_MSK21_DISABLED             (PIO_P_MSKR_MSK21_DISABLED_Val << PIO_P_MSKR_MSK21_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK21_ENABLED              (PIO_P_MSKR_MSK21_ENABLED_Val << PIO_P_MSKR_MSK21_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK22_Pos                  _UINT32_(22)                                         /* (PIO_P_MSKR) PIO Line 22 Mask Position */
#define PIO_P_MSKR_MSK22_Msk                  (_UINT32_(0x1) << PIO_P_MSKR_MSK22_Pos)              /* (PIO_P_MSKR) PIO Line 22 Mask Mask */
#define PIO_P_MSKR_MSK22(value)               (PIO_P_MSKR_MSK22_Msk & (_UINT32_(value) << PIO_P_MSKR_MSK22_Pos)) /* Assigment of value for MSK22 in the PIO_P_MSKR register */
#define   PIO_P_MSKR_MSK22_DISABLED_Val       _UINT32_(0x0)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_P_MSKR_MSK22_ENABLED_Val        _UINT32_(0x1)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration.  */
#define PIO_P_MSKR_MSK22_DISABLED             (PIO_P_MSKR_MSK22_DISABLED_Val << PIO_P_MSKR_MSK22_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK22_ENABLED              (PIO_P_MSKR_MSK22_ENABLED_Val << PIO_P_MSKR_MSK22_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK23_Pos                  _UINT32_(23)                                         /* (PIO_P_MSKR) PIO Line 23 Mask Position */
#define PIO_P_MSKR_MSK23_Msk                  (_UINT32_(0x1) << PIO_P_MSKR_MSK23_Pos)              /* (PIO_P_MSKR) PIO Line 23 Mask Mask */
#define PIO_P_MSKR_MSK23(value)               (PIO_P_MSKR_MSK23_Msk & (_UINT32_(value) << PIO_P_MSKR_MSK23_Pos)) /* Assigment of value for MSK23 in the PIO_P_MSKR register */
#define   PIO_P_MSKR_MSK23_DISABLED_Val       _UINT32_(0x0)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_P_MSKR_MSK23_ENABLED_Val        _UINT32_(0x1)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration.  */
#define PIO_P_MSKR_MSK23_DISABLED             (PIO_P_MSKR_MSK23_DISABLED_Val << PIO_P_MSKR_MSK23_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK23_ENABLED              (PIO_P_MSKR_MSK23_ENABLED_Val << PIO_P_MSKR_MSK23_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK24_Pos                  _UINT32_(24)                                         /* (PIO_P_MSKR) PIO Line 24 Mask Position */
#define PIO_P_MSKR_MSK24_Msk                  (_UINT32_(0x1) << PIO_P_MSKR_MSK24_Pos)              /* (PIO_P_MSKR) PIO Line 24 Mask Mask */
#define PIO_P_MSKR_MSK24(value)               (PIO_P_MSKR_MSK24_Msk & (_UINT32_(value) << PIO_P_MSKR_MSK24_Pos)) /* Assigment of value for MSK24 in the PIO_P_MSKR register */
#define   PIO_P_MSKR_MSK24_DISABLED_Val       _UINT32_(0x0)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_P_MSKR_MSK24_ENABLED_Val        _UINT32_(0x1)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration.  */
#define PIO_P_MSKR_MSK24_DISABLED             (PIO_P_MSKR_MSK24_DISABLED_Val << PIO_P_MSKR_MSK24_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK24_ENABLED              (PIO_P_MSKR_MSK24_ENABLED_Val << PIO_P_MSKR_MSK24_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK25_Pos                  _UINT32_(25)                                         /* (PIO_P_MSKR) PIO Line 25 Mask Position */
#define PIO_P_MSKR_MSK25_Msk                  (_UINT32_(0x1) << PIO_P_MSKR_MSK25_Pos)              /* (PIO_P_MSKR) PIO Line 25 Mask Mask */
#define PIO_P_MSKR_MSK25(value)               (PIO_P_MSKR_MSK25_Msk & (_UINT32_(value) << PIO_P_MSKR_MSK25_Pos)) /* Assigment of value for MSK25 in the PIO_P_MSKR register */
#define   PIO_P_MSKR_MSK25_DISABLED_Val       _UINT32_(0x0)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_P_MSKR_MSK25_ENABLED_Val        _UINT32_(0x1)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration.  */
#define PIO_P_MSKR_MSK25_DISABLED             (PIO_P_MSKR_MSK25_DISABLED_Val << PIO_P_MSKR_MSK25_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK25_ENABLED              (PIO_P_MSKR_MSK25_ENABLED_Val << PIO_P_MSKR_MSK25_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK26_Pos                  _UINT32_(26)                                         /* (PIO_P_MSKR) PIO Line 26 Mask Position */
#define PIO_P_MSKR_MSK26_Msk                  (_UINT32_(0x1) << PIO_P_MSKR_MSK26_Pos)              /* (PIO_P_MSKR) PIO Line 26 Mask Mask */
#define PIO_P_MSKR_MSK26(value)               (PIO_P_MSKR_MSK26_Msk & (_UINT32_(value) << PIO_P_MSKR_MSK26_Pos)) /* Assigment of value for MSK26 in the PIO_P_MSKR register */
#define   PIO_P_MSKR_MSK26_DISABLED_Val       _UINT32_(0x0)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_P_MSKR_MSK26_ENABLED_Val        _UINT32_(0x1)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration.  */
#define PIO_P_MSKR_MSK26_DISABLED             (PIO_P_MSKR_MSK26_DISABLED_Val << PIO_P_MSKR_MSK26_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK26_ENABLED              (PIO_P_MSKR_MSK26_ENABLED_Val << PIO_P_MSKR_MSK26_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK27_Pos                  _UINT32_(27)                                         /* (PIO_P_MSKR) PIO Line 27 Mask Position */
#define PIO_P_MSKR_MSK27_Msk                  (_UINT32_(0x1) << PIO_P_MSKR_MSK27_Pos)              /* (PIO_P_MSKR) PIO Line 27 Mask Mask */
#define PIO_P_MSKR_MSK27(value)               (PIO_P_MSKR_MSK27_Msk & (_UINT32_(value) << PIO_P_MSKR_MSK27_Pos)) /* Assigment of value for MSK27 in the PIO_P_MSKR register */
#define   PIO_P_MSKR_MSK27_DISABLED_Val       _UINT32_(0x0)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_P_MSKR_MSK27_ENABLED_Val        _UINT32_(0x1)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration.  */
#define PIO_P_MSKR_MSK27_DISABLED             (PIO_P_MSKR_MSK27_DISABLED_Val << PIO_P_MSKR_MSK27_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK27_ENABLED              (PIO_P_MSKR_MSK27_ENABLED_Val << PIO_P_MSKR_MSK27_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK28_Pos                  _UINT32_(28)                                         /* (PIO_P_MSKR) PIO Line 28 Mask Position */
#define PIO_P_MSKR_MSK28_Msk                  (_UINT32_(0x1) << PIO_P_MSKR_MSK28_Pos)              /* (PIO_P_MSKR) PIO Line 28 Mask Mask */
#define PIO_P_MSKR_MSK28(value)               (PIO_P_MSKR_MSK28_Msk & (_UINT32_(value) << PIO_P_MSKR_MSK28_Pos)) /* Assigment of value for MSK28 in the PIO_P_MSKR register */
#define   PIO_P_MSKR_MSK28_DISABLED_Val       _UINT32_(0x0)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_P_MSKR_MSK28_ENABLED_Val        _UINT32_(0x1)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration.  */
#define PIO_P_MSKR_MSK28_DISABLED             (PIO_P_MSKR_MSK28_DISABLED_Val << PIO_P_MSKR_MSK28_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK28_ENABLED              (PIO_P_MSKR_MSK28_ENABLED_Val << PIO_P_MSKR_MSK28_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK29_Pos                  _UINT32_(29)                                         /* (PIO_P_MSKR) PIO Line 29 Mask Position */
#define PIO_P_MSKR_MSK29_Msk                  (_UINT32_(0x1) << PIO_P_MSKR_MSK29_Pos)              /* (PIO_P_MSKR) PIO Line 29 Mask Mask */
#define PIO_P_MSKR_MSK29(value)               (PIO_P_MSKR_MSK29_Msk & (_UINT32_(value) << PIO_P_MSKR_MSK29_Pos)) /* Assigment of value for MSK29 in the PIO_P_MSKR register */
#define   PIO_P_MSKR_MSK29_DISABLED_Val       _UINT32_(0x0)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_P_MSKR_MSK29_ENABLED_Val        _UINT32_(0x1)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration.  */
#define PIO_P_MSKR_MSK29_DISABLED             (PIO_P_MSKR_MSK29_DISABLED_Val << PIO_P_MSKR_MSK29_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK29_ENABLED              (PIO_P_MSKR_MSK29_ENABLED_Val << PIO_P_MSKR_MSK29_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK30_Pos                  _UINT32_(30)                                         /* (PIO_P_MSKR) PIO Line 30 Mask Position */
#define PIO_P_MSKR_MSK30_Msk                  (_UINT32_(0x1) << PIO_P_MSKR_MSK30_Pos)              /* (PIO_P_MSKR) PIO Line 30 Mask Mask */
#define PIO_P_MSKR_MSK30(value)               (PIO_P_MSKR_MSK30_Msk & (_UINT32_(value) << PIO_P_MSKR_MSK30_Pos)) /* Assigment of value for MSK30 in the PIO_P_MSKR register */
#define   PIO_P_MSKR_MSK30_DISABLED_Val       _UINT32_(0x0)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_P_MSKR_MSK30_ENABLED_Val        _UINT32_(0x1)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration.  */
#define PIO_P_MSKR_MSK30_DISABLED             (PIO_P_MSKR_MSK30_DISABLED_Val << PIO_P_MSKR_MSK30_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK30_ENABLED              (PIO_P_MSKR_MSK30_ENABLED_Val << PIO_P_MSKR_MSK30_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK31_Pos                  _UINT32_(31)                                         /* (PIO_P_MSKR) PIO Line 31 Mask Position */
#define PIO_P_MSKR_MSK31_Msk                  (_UINT32_(0x1) << PIO_P_MSKR_MSK31_Pos)              /* (PIO_P_MSKR) PIO Line 31 Mask Mask */
#define PIO_P_MSKR_MSK31(value)               (PIO_P_MSKR_MSK31_Msk & (_UINT32_(value) << PIO_P_MSKR_MSK31_Pos)) /* Assigment of value for MSK31 in the PIO_P_MSKR register */
#define   PIO_P_MSKR_MSK31_DISABLED_Val       _UINT32_(0x0)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration.  */
#define   PIO_P_MSKR_MSK31_ENABLED_Val        _UINT32_(0x1)                                        /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration.  */
#define PIO_P_MSKR_MSK31_DISABLED             (PIO_P_MSKR_MSK31_DISABLED_Val << PIO_P_MSKR_MSK31_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRx does not affect the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_MSK31_ENABLED              (PIO_P_MSKR_MSK31_ENABLED_Val << PIO_P_MSKR_MSK31_Pos) /* (PIO_P_MSKR) Writing the PIO_P_CFGRx, PIO_P_ODSRx or PIO_P_IOFRX updates the corresponding I/O line configuration. Position  */
#define PIO_P_MSKR_Msk                        _UINT32_(0xFFFFFFFF)                                 /* (PIO_P_MSKR) Register Mask  */

#define PIO_P_MSKR_MSK_Pos                    _UINT32_(0)                                          /* (PIO_P_MSKR Position) PIO Line 3x Mask */
#define PIO_P_MSKR_MSK_Msk                    (_UINT32_(0xFFFFFFFF) << PIO_P_MSKR_MSK_Pos)         /* (PIO_P_MSKR Mask) MSK */
#define PIO_P_MSKR_MSK(value)                 (PIO_P_MSKR_MSK_Msk & (_UINT32_(value) << PIO_P_MSKR_MSK_Pos)) 

/* -------- PIO_P_CFGR : (PIO Offset: 0x04) (R/W 32) PIO Privilege Configuration Register (p_iogroup = 0) -------- */
#define PIO_P_CFGR_FUNC_Pos                   _UINT32_(0)                                          /* (PIO_P_CFGR) I/O Line Function Position */
#define PIO_P_CFGR_FUNC_Msk                   (_UINT32_(0x7) << PIO_P_CFGR_FUNC_Pos)               /* (PIO_P_CFGR) I/O Line Function Mask */
#define PIO_P_CFGR_FUNC(value)                (PIO_P_CFGR_FUNC_Msk & (_UINT32_(value) << PIO_P_CFGR_FUNC_Pos)) /* Assigment of value for FUNC in the PIO_P_CFGR register */
#define   PIO_P_CFGR_FUNC_GPIO_Val            _UINT32_(0x0)                                        /* (PIO_P_CFGR) Select the PIO mode for the selected I/O lines.  */
#define   PIO_P_CFGR_FUNC_PERIPH_A_Val        _UINT32_(0x1)                                        /* (PIO_P_CFGR) Select the peripheral A for the selected I/O lines.  */
#define   PIO_P_CFGR_FUNC_PERIPH_B_Val        _UINT32_(0x2)                                        /* (PIO_P_CFGR) Select the peripheral B for the selected I/O lines.  */
#define   PIO_P_CFGR_FUNC_PERIPH_C_Val        _UINT32_(0x3)                                        /* (PIO_P_CFGR) Select the peripheral C for the selected I/O lines.  */
#define   PIO_P_CFGR_FUNC_PERIPH_D_Val        _UINT32_(0x4)                                        /* (PIO_P_CFGR) Select the peripheral D for the selected I/O lines.  */
#define PIO_P_CFGR_FUNC_GPIO                  (PIO_P_CFGR_FUNC_GPIO_Val << PIO_P_CFGR_FUNC_Pos)    /* (PIO_P_CFGR) Select the PIO mode for the selected I/O lines. Position  */
#define PIO_P_CFGR_FUNC_PERIPH_A              (PIO_P_CFGR_FUNC_PERIPH_A_Val << PIO_P_CFGR_FUNC_Pos) /* (PIO_P_CFGR) Select the peripheral A for the selected I/O lines. Position  */
#define PIO_P_CFGR_FUNC_PERIPH_B              (PIO_P_CFGR_FUNC_PERIPH_B_Val << PIO_P_CFGR_FUNC_Pos) /* (PIO_P_CFGR) Select the peripheral B for the selected I/O lines. Position  */
#define PIO_P_CFGR_FUNC_PERIPH_C              (PIO_P_CFGR_FUNC_PERIPH_C_Val << PIO_P_CFGR_FUNC_Pos) /* (PIO_P_CFGR) Select the peripheral C for the selected I/O lines. Position  */
#define PIO_P_CFGR_FUNC_PERIPH_D              (PIO_P_CFGR_FUNC_PERIPH_D_Val << PIO_P_CFGR_FUNC_Pos) /* (PIO_P_CFGR) Select the peripheral D for the selected I/O lines. Position  */
#define PIO_P_CFGR_DIR_Pos                    _UINT32_(8)                                          /* (PIO_P_CFGR) Direction Position */
#define PIO_P_CFGR_DIR_Msk                    (_UINT32_(0x1) << PIO_P_CFGR_DIR_Pos)                /* (PIO_P_CFGR) Direction Mask */
#define PIO_P_CFGR_DIR(value)                 (PIO_P_CFGR_DIR_Msk & (_UINT32_(value) << PIO_P_CFGR_DIR_Pos)) /* Assigment of value for DIR in the PIO_P_CFGR register */
#define   PIO_P_CFGR_DIR_INPUT_Val            _UINT32_(0x0)                                        /* (PIO_P_CFGR) The selected I/O lines are pure inputs.  */
#define   PIO_P_CFGR_DIR_OUTPUT_Val           _UINT32_(0x1)                                        /* (PIO_P_CFGR) The selected I/O lines are enabled in output.  */
#define PIO_P_CFGR_DIR_INPUT                  (PIO_P_CFGR_DIR_INPUT_Val << PIO_P_CFGR_DIR_Pos)     /* (PIO_P_CFGR) The selected I/O lines are pure inputs. Position  */
#define PIO_P_CFGR_DIR_OUTPUT                 (PIO_P_CFGR_DIR_OUTPUT_Val << PIO_P_CFGR_DIR_Pos)    /* (PIO_P_CFGR) The selected I/O lines are enabled in output. Position  */
#define PIO_P_CFGR_PUEN_Pos                   _UINT32_(9)                                          /* (PIO_P_CFGR) Pull-Up Enable Position */
#define PIO_P_CFGR_PUEN_Msk                   (_UINT32_(0x1) << PIO_P_CFGR_PUEN_Pos)               /* (PIO_P_CFGR) Pull-Up Enable Mask */
#define PIO_P_CFGR_PUEN(value)                (PIO_P_CFGR_PUEN_Msk & (_UINT32_(value) << PIO_P_CFGR_PUEN_Pos)) /* Assigment of value for PUEN in the PIO_P_CFGR register */
#define   PIO_P_CFGR_PUEN_DISABLED_Val        _UINT32_(0x0)                                        /* (PIO_P_CFGR) Pull-Up is disabled for the selected I/O lines.  */
#define   PIO_P_CFGR_PUEN_ENABLED_Val         _UINT32_(0x1)                                        /* (PIO_P_CFGR) Pull-Up is enabled for the selected I/O lines.  */
#define PIO_P_CFGR_PUEN_DISABLED              (PIO_P_CFGR_PUEN_DISABLED_Val << PIO_P_CFGR_PUEN_Pos) /* (PIO_P_CFGR) Pull-Up is disabled for the selected I/O lines. Position  */
#define PIO_P_CFGR_PUEN_ENABLED               (PIO_P_CFGR_PUEN_ENABLED_Val << PIO_P_CFGR_PUEN_Pos) /* (PIO_P_CFGR) Pull-Up is enabled for the selected I/O lines. Position  */
#define PIO_P_CFGR_PDEN_Pos                   _UINT32_(10)                                         /* (PIO_P_CFGR) Pull-Down Enable Position */
#define PIO_P_CFGR_PDEN_Msk                   (_UINT32_(0x1) << PIO_P_CFGR_PDEN_Pos)               /* (PIO_P_CFGR) Pull-Down Enable Mask */
#define PIO_P_CFGR_PDEN(value)                (PIO_P_CFGR_PDEN_Msk & (_UINT32_(value) << PIO_P_CFGR_PDEN_Pos)) /* Assigment of value for PDEN in the PIO_P_CFGR register */
#define   PIO_P_CFGR_PDEN_DISABLED_Val        _UINT32_(0x0)                                        /* (PIO_P_CFGR) Pull-Down is disabled for the selected I/O lines.  */
#define   PIO_P_CFGR_PDEN_ENABLED_Val         _UINT32_(0x1)                                        /* (PIO_P_CFGR) Pull-Down is enabled for the selected I/O lines only if PUEN is 0.  */
#define PIO_P_CFGR_PDEN_DISABLED              (PIO_P_CFGR_PDEN_DISABLED_Val << PIO_P_CFGR_PDEN_Pos) /* (PIO_P_CFGR) Pull-Down is disabled for the selected I/O lines. Position  */
#define PIO_P_CFGR_PDEN_ENABLED               (PIO_P_CFGR_PDEN_ENABLED_Val << PIO_P_CFGR_PDEN_Pos) /* (PIO_P_CFGR) Pull-Down is enabled for the selected I/O lines only if PUEN is 0. Position  */
#define PIO_P_CFGR_IFEN_Pos                   _UINT32_(12)                                         /* (PIO_P_CFGR) Input Filter Enable Position */
#define PIO_P_CFGR_IFEN_Msk                   (_UINT32_(0x1) << PIO_P_CFGR_IFEN_Pos)               /* (PIO_P_CFGR) Input Filter Enable Mask */
#define PIO_P_CFGR_IFEN(value)                (PIO_P_CFGR_IFEN_Msk & (_UINT32_(value) << PIO_P_CFGR_IFEN_Pos)) /* Assigment of value for IFEN in the PIO_P_CFGR register */
#define   PIO_P_CFGR_IFEN_DISABLED_Val        _UINT32_(0x0)                                        /* (PIO_P_CFGR) The input filter is disabled for the selected I/O lines.  */
#define   PIO_P_CFGR_IFEN_ENABLED_Val         _UINT32_(0x1)                                        /* (PIO_P_CFGR) The input filter is enabled for the selected I/O lines.  */
#define PIO_P_CFGR_IFEN_DISABLED              (PIO_P_CFGR_IFEN_DISABLED_Val << PIO_P_CFGR_IFEN_Pos) /* (PIO_P_CFGR) The input filter is disabled for the selected I/O lines. Position  */
#define PIO_P_CFGR_IFEN_ENABLED               (PIO_P_CFGR_IFEN_ENABLED_Val << PIO_P_CFGR_IFEN_Pos) /* (PIO_P_CFGR) The input filter is enabled for the selected I/O lines. Position  */
#define PIO_P_CFGR_IFSCEN_Pos                 _UINT32_(13)                                         /* (PIO_P_CFGR) Input Filter Slow Clock Enable Position */
#define PIO_P_CFGR_IFSCEN_Msk                 (_UINT32_(0x1) << PIO_P_CFGR_IFSCEN_Pos)             /* (PIO_P_CFGR) Input Filter Slow Clock Enable Mask */
#define PIO_P_CFGR_IFSCEN(value)              (PIO_P_CFGR_IFSCEN_Msk & (_UINT32_(value) << PIO_P_CFGR_IFSCEN_Pos)) /* Assigment of value for IFSCEN in the PIO_P_CFGR register */
#define PIO_P_CFGR_OPD_Pos                    _UINT32_(14)                                         /* (PIO_P_CFGR) Open-Drain Position */
#define PIO_P_CFGR_OPD_Msk                    (_UINT32_(0x1) << PIO_P_CFGR_OPD_Pos)                /* (PIO_P_CFGR) Open-Drain Mask */
#define PIO_P_CFGR_OPD(value)                 (PIO_P_CFGR_OPD_Msk & (_UINT32_(value) << PIO_P_CFGR_OPD_Pos)) /* Assigment of value for OPD in the PIO_P_CFGR register */
#define   PIO_P_CFGR_OPD_DISABLED_Val         _UINT32_(0x0)                                        /* (PIO_P_CFGR) The open-drain is disabled for the selected I/O lines. I/O lines are driven at high- and low-level.  */
#define   PIO_P_CFGR_OPD_ENABLED_Val          _UINT32_(0x1)                                        /* (PIO_P_CFGR) The open-drain is enabled for the selected I/O lines. I/O lines are driven at low-level only.  */
#define PIO_P_CFGR_OPD_DISABLED               (PIO_P_CFGR_OPD_DISABLED_Val << PIO_P_CFGR_OPD_Pos)  /* (PIO_P_CFGR) The open-drain is disabled for the selected I/O lines. I/O lines are driven at high- and low-level. Position  */
#define PIO_P_CFGR_OPD_ENABLED                (PIO_P_CFGR_OPD_ENABLED_Val << PIO_P_CFGR_OPD_Pos)   /* (PIO_P_CFGR) The open-drain is enabled for the selected I/O lines. I/O lines are driven at low-level only. Position  */
#define PIO_P_CFGR_SCHMITT_Pos                _UINT32_(15)                                         /* (PIO_P_CFGR) Schmitt Trigger Position */
#define PIO_P_CFGR_SCHMITT_Msk                (_UINT32_(0x1) << PIO_P_CFGR_SCHMITT_Pos)            /* (PIO_P_CFGR) Schmitt Trigger Mask */
#define PIO_P_CFGR_SCHMITT(value)             (PIO_P_CFGR_SCHMITT_Msk & (_UINT32_(value) << PIO_P_CFGR_SCHMITT_Pos)) /* Assigment of value for SCHMITT in the PIO_P_CFGR register */
#define   PIO_P_CFGR_SCHMITT_ENABLED_Val      _UINT32_(0x0)                                        /* (PIO_P_CFGR) Schmitt trigger is enabled for the selected I/O lines.  */
#define   PIO_P_CFGR_SCHMITT_DISABLED_Val     _UINT32_(0x1)                                        /* (PIO_P_CFGR) Schmitt trigger is disabled for the selected I/O lines.  */
#define PIO_P_CFGR_SCHMITT_ENABLED            (PIO_P_CFGR_SCHMITT_ENABLED_Val << PIO_P_CFGR_SCHMITT_Pos) /* (PIO_P_CFGR) Schmitt trigger is enabled for the selected I/O lines. Position  */
#define PIO_P_CFGR_SCHMITT_DISABLED           (PIO_P_CFGR_SCHMITT_DISABLED_Val << PIO_P_CFGR_SCHMITT_Pos) /* (PIO_P_CFGR) Schmitt trigger is disabled for the selected I/O lines. Position  */
#define PIO_P_CFGR_SLEWRATE_Pos               _UINT32_(16)                                         /* (PIO_P_CFGR) Slew Rate Position */
#define PIO_P_CFGR_SLEWRATE_Msk               (_UINT32_(0x3) << PIO_P_CFGR_SLEWRATE_Pos)           /* (PIO_P_CFGR) Slew Rate Mask */
#define PIO_P_CFGR_SLEWRATE(value)            (PIO_P_CFGR_SLEWRATE_Msk & (_UINT32_(value) << PIO_P_CFGR_SLEWRATE_Pos)) /* Assigment of value for SLEWRATE in the PIO_P_CFGR register */
#define   PIO_P_CFGR_SLEWRATE_FAST_Val        _UINT32_(0x0)                                        /* (PIO_P_CFGR) Slow slew rate  */
#define   PIO_P_CFGR_SLEWRATE_MEDIUMFAST_Val  _UINT32_(0x1)                                        /* (PIO_P_CFGR) Medium-fast slew rate  */
#define   PIO_P_CFGR_SLEWRATE_MEDIUM_Val      _UINT32_(0x2)                                        /* (PIO_P_CFGR) Medium slew rate  */
#define   PIO_P_CFGR_SLEWRATE_SLOW_Val        _UINT32_(0x3)                                        /* (PIO_P_CFGR) Slow slew rate  */
#define PIO_P_CFGR_SLEWRATE_FAST              (PIO_P_CFGR_SLEWRATE_FAST_Val << PIO_P_CFGR_SLEWRATE_Pos) /* (PIO_P_CFGR) Slow slew rate Position  */
#define PIO_P_CFGR_SLEWRATE_MEDIUMFAST        (PIO_P_CFGR_SLEWRATE_MEDIUMFAST_Val << PIO_P_CFGR_SLEWRATE_Pos) /* (PIO_P_CFGR) Medium-fast slew rate Position  */
#define PIO_P_CFGR_SLEWRATE_MEDIUM            (PIO_P_CFGR_SLEWRATE_MEDIUM_Val << PIO_P_CFGR_SLEWRATE_Pos) /* (PIO_P_CFGR) Medium slew rate Position  */
#define PIO_P_CFGR_SLEWRATE_SLOW              (PIO_P_CFGR_SLEWRATE_SLOW_Val << PIO_P_CFGR_SLEWRATE_Pos) /* (PIO_P_CFGR) Slow slew rate Position  */
#define PIO_P_CFGR_EVTSEL_Pos                 _UINT32_(24)                                         /* (PIO_P_CFGR) Event Selection Position */
#define PIO_P_CFGR_EVTSEL_Msk                 (_UINT32_(0x7) << PIO_P_CFGR_EVTSEL_Pos)             /* (PIO_P_CFGR) Event Selection Mask */
#define PIO_P_CFGR_EVTSEL(value)              (PIO_P_CFGR_EVTSEL_Msk & (_UINT32_(value) << PIO_P_CFGR_EVTSEL_Pos)) /* Assigment of value for EVTSEL in the PIO_P_CFGR register */
#define   PIO_P_CFGR_EVTSEL_FALLING_Val       _UINT32_(0x0)                                        /* (PIO_P_CFGR) Event detection on input falling edge  */
#define   PIO_P_CFGR_EVTSEL_RISING_Val        _UINT32_(0x1)                                        /* (PIO_P_CFGR) Event detection on input rising edge  */
#define   PIO_P_CFGR_EVTSEL_BOTH_Val          _UINT32_(0x2)                                        /* (PIO_P_CFGR) Event detection on input both edge  */
#define   PIO_P_CFGR_EVTSEL_LOW_Val           _UINT32_(0x3)                                        /* (PIO_P_CFGR) Event detection on low level input  */
#define   PIO_P_CFGR_EVTSEL_HIGH_Val          _UINT32_(0x4)                                        /* (PIO_P_CFGR) Event detection on high level input  */
#define PIO_P_CFGR_EVTSEL_FALLING             (PIO_P_CFGR_EVTSEL_FALLING_Val << PIO_P_CFGR_EVTSEL_Pos) /* (PIO_P_CFGR) Event detection on input falling edge Position  */
#define PIO_P_CFGR_EVTSEL_RISING              (PIO_P_CFGR_EVTSEL_RISING_Val << PIO_P_CFGR_EVTSEL_Pos) /* (PIO_P_CFGR) Event detection on input rising edge Position  */
#define PIO_P_CFGR_EVTSEL_BOTH                (PIO_P_CFGR_EVTSEL_BOTH_Val << PIO_P_CFGR_EVTSEL_Pos) /* (PIO_P_CFGR) Event detection on input both edge Position  */
#define PIO_P_CFGR_EVTSEL_LOW                 (PIO_P_CFGR_EVTSEL_LOW_Val << PIO_P_CFGR_EVTSEL_Pos) /* (PIO_P_CFGR) Event detection on low level input Position  */
#define PIO_P_CFGR_EVTSEL_HIGH                (PIO_P_CFGR_EVTSEL_HIGH_Val << PIO_P_CFGR_EVTSEL_Pos) /* (PIO_P_CFGR) Event detection on high level input Position  */
#define PIO_P_CFGR_PCFS_Pos                   _UINT32_(29)                                         /* (PIO_P_CFGR) Physical Configuration Freeze Status (read-only) Position */
#define PIO_P_CFGR_PCFS_Msk                   (_UINT32_(0x1) << PIO_P_CFGR_PCFS_Pos)               /* (PIO_P_CFGR) Physical Configuration Freeze Status (read-only) Mask */
#define PIO_P_CFGR_PCFS(value)                (PIO_P_CFGR_PCFS_Msk & (_UINT32_(value) << PIO_P_CFGR_PCFS_Pos)) /* Assigment of value for PCFS in the PIO_P_CFGR register */
#define   PIO_P_CFGR_PCFS_NOT_FROZEN_Val      _UINT32_(0x0)                                        /* (PIO_P_CFGR) The fields are not frozen and can be written for this I/O line.  */
#define   PIO_P_CFGR_PCFS_FROZEN_Val          _UINT32_(0x1)                                        /* (PIO_P_CFGR) The fields are frozen and cannot be written for this I/O line. Only a hardware reset can release these fields.  */
#define PIO_P_CFGR_PCFS_NOT_FROZEN            (PIO_P_CFGR_PCFS_NOT_FROZEN_Val << PIO_P_CFGR_PCFS_Pos) /* (PIO_P_CFGR) The fields are not frozen and can be written for this I/O line. Position  */
#define PIO_P_CFGR_PCFS_FROZEN                (PIO_P_CFGR_PCFS_FROZEN_Val << PIO_P_CFGR_PCFS_Pos)  /* (PIO_P_CFGR) The fields are frozen and cannot be written for this I/O line. Only a hardware reset can release these fields. Position  */
#define PIO_P_CFGR_ICFS_Pos                   _UINT32_(30)                                         /* (PIO_P_CFGR) Interrupt Configuration Freeze Status (read-only) Position */
#define PIO_P_CFGR_ICFS_Msk                   (_UINT32_(0x1) << PIO_P_CFGR_ICFS_Pos)               /* (PIO_P_CFGR) Interrupt Configuration Freeze Status (read-only) Mask */
#define PIO_P_CFGR_ICFS(value)                (PIO_P_CFGR_ICFS_Msk & (_UINT32_(value) << PIO_P_CFGR_ICFS_Pos)) /* Assigment of value for ICFS in the PIO_P_CFGR register */
#define   PIO_P_CFGR_ICFS_NOT_FROZEN_Val      _UINT32_(0x0)                                        /* (PIO_P_CFGR) The fields are not frozen and can be written for this I/O line.  */
#define   PIO_P_CFGR_ICFS_FROZEN_Val          _UINT32_(0x1)                                        /* (PIO_P_CFGR) The fields are frozen and cannot be written for this I/O line. Only a hardware reset can release these fields.  */
#define PIO_P_CFGR_ICFS_NOT_FROZEN            (PIO_P_CFGR_ICFS_NOT_FROZEN_Val << PIO_P_CFGR_ICFS_Pos) /* (PIO_P_CFGR) The fields are not frozen and can be written for this I/O line. Position  */
#define PIO_P_CFGR_ICFS_FROZEN                (PIO_P_CFGR_ICFS_FROZEN_Val << PIO_P_CFGR_ICFS_Pos)  /* (PIO_P_CFGR) The fields are frozen and cannot be written for this I/O line. Only a hardware reset can release these fields. Position  */
#define PIO_P_CFGR_Msk                        _UINT32_(0x6703F707)                                 /* (PIO_P_CFGR) Register Mask  */


/* -------- PIO_P_PDSR : (PIO Offset: 0x08) ( R/ 32) PIO Privilege Pin Data Status Register (p_iogroup = 0) -------- */
#define PIO_P_PDSR_P0_Pos                     _UINT32_(0)                                          /* (PIO_P_PDSR) Input Data Status Position */
#define PIO_P_PDSR_P0_Msk                     (_UINT32_(0x1) << PIO_P_PDSR_P0_Pos)                 /* (PIO_P_PDSR) Input Data Status Mask */
#define PIO_P_PDSR_P0(value)                  (PIO_P_PDSR_P0_Msk & (_UINT32_(value) << PIO_P_PDSR_P0_Pos)) /* Assigment of value for P0 in the PIO_P_PDSR register */
#define PIO_P_PDSR_P1_Pos                     _UINT32_(1)                                          /* (PIO_P_PDSR) Input Data Status Position */
#define PIO_P_PDSR_P1_Msk                     (_UINT32_(0x1) << PIO_P_PDSR_P1_Pos)                 /* (PIO_P_PDSR) Input Data Status Mask */
#define PIO_P_PDSR_P1(value)                  (PIO_P_PDSR_P1_Msk & (_UINT32_(value) << PIO_P_PDSR_P1_Pos)) /* Assigment of value for P1 in the PIO_P_PDSR register */
#define PIO_P_PDSR_P2_Pos                     _UINT32_(2)                                          /* (PIO_P_PDSR) Input Data Status Position */
#define PIO_P_PDSR_P2_Msk                     (_UINT32_(0x1) << PIO_P_PDSR_P2_Pos)                 /* (PIO_P_PDSR) Input Data Status Mask */
#define PIO_P_PDSR_P2(value)                  (PIO_P_PDSR_P2_Msk & (_UINT32_(value) << PIO_P_PDSR_P2_Pos)) /* Assigment of value for P2 in the PIO_P_PDSR register */
#define PIO_P_PDSR_P3_Pos                     _UINT32_(3)                                          /* (PIO_P_PDSR) Input Data Status Position */
#define PIO_P_PDSR_P3_Msk                     (_UINT32_(0x1) << PIO_P_PDSR_P3_Pos)                 /* (PIO_P_PDSR) Input Data Status Mask */
#define PIO_P_PDSR_P3(value)                  (PIO_P_PDSR_P3_Msk & (_UINT32_(value) << PIO_P_PDSR_P3_Pos)) /* Assigment of value for P3 in the PIO_P_PDSR register */
#define PIO_P_PDSR_P4_Pos                     _UINT32_(4)                                          /* (PIO_P_PDSR) Input Data Status Position */
#define PIO_P_PDSR_P4_Msk                     (_UINT32_(0x1) << PIO_P_PDSR_P4_Pos)                 /* (PIO_P_PDSR) Input Data Status Mask */
#define PIO_P_PDSR_P4(value)                  (PIO_P_PDSR_P4_Msk & (_UINT32_(value) << PIO_P_PDSR_P4_Pos)) /* Assigment of value for P4 in the PIO_P_PDSR register */
#define PIO_P_PDSR_P5_Pos                     _UINT32_(5)                                          /* (PIO_P_PDSR) Input Data Status Position */
#define PIO_P_PDSR_P5_Msk                     (_UINT32_(0x1) << PIO_P_PDSR_P5_Pos)                 /* (PIO_P_PDSR) Input Data Status Mask */
#define PIO_P_PDSR_P5(value)                  (PIO_P_PDSR_P5_Msk & (_UINT32_(value) << PIO_P_PDSR_P5_Pos)) /* Assigment of value for P5 in the PIO_P_PDSR register */
#define PIO_P_PDSR_P6_Pos                     _UINT32_(6)                                          /* (PIO_P_PDSR) Input Data Status Position */
#define PIO_P_PDSR_P6_Msk                     (_UINT32_(0x1) << PIO_P_PDSR_P6_Pos)                 /* (PIO_P_PDSR) Input Data Status Mask */
#define PIO_P_PDSR_P6(value)                  (PIO_P_PDSR_P6_Msk & (_UINT32_(value) << PIO_P_PDSR_P6_Pos)) /* Assigment of value for P6 in the PIO_P_PDSR register */
#define PIO_P_PDSR_P7_Pos                     _UINT32_(7)                                          /* (PIO_P_PDSR) Input Data Status Position */
#define PIO_P_PDSR_P7_Msk                     (_UINT32_(0x1) << PIO_P_PDSR_P7_Pos)                 /* (PIO_P_PDSR) Input Data Status Mask */
#define PIO_P_PDSR_P7(value)                  (PIO_P_PDSR_P7_Msk & (_UINT32_(value) << PIO_P_PDSR_P7_Pos)) /* Assigment of value for P7 in the PIO_P_PDSR register */
#define PIO_P_PDSR_P8_Pos                     _UINT32_(8)                                          /* (PIO_P_PDSR) Input Data Status Position */
#define PIO_P_PDSR_P8_Msk                     (_UINT32_(0x1) << PIO_P_PDSR_P8_Pos)                 /* (PIO_P_PDSR) Input Data Status Mask */
#define PIO_P_PDSR_P8(value)                  (PIO_P_PDSR_P8_Msk & (_UINT32_(value) << PIO_P_PDSR_P8_Pos)) /* Assigment of value for P8 in the PIO_P_PDSR register */
#define PIO_P_PDSR_P9_Pos                     _UINT32_(9)                                          /* (PIO_P_PDSR) Input Data Status Position */
#define PIO_P_PDSR_P9_Msk                     (_UINT32_(0x1) << PIO_P_PDSR_P9_Pos)                 /* (PIO_P_PDSR) Input Data Status Mask */
#define PIO_P_PDSR_P9(value)                  (PIO_P_PDSR_P9_Msk & (_UINT32_(value) << PIO_P_PDSR_P9_Pos)) /* Assigment of value for P9 in the PIO_P_PDSR register */
#define PIO_P_PDSR_P10_Pos                    _UINT32_(10)                                         /* (PIO_P_PDSR) Input Data Status Position */
#define PIO_P_PDSR_P10_Msk                    (_UINT32_(0x1) << PIO_P_PDSR_P10_Pos)                /* (PIO_P_PDSR) Input Data Status Mask */
#define PIO_P_PDSR_P10(value)                 (PIO_P_PDSR_P10_Msk & (_UINT32_(value) << PIO_P_PDSR_P10_Pos)) /* Assigment of value for P10 in the PIO_P_PDSR register */
#define PIO_P_PDSR_P11_Pos                    _UINT32_(11)                                         /* (PIO_P_PDSR) Input Data Status Position */
#define PIO_P_PDSR_P11_Msk                    (_UINT32_(0x1) << PIO_P_PDSR_P11_Pos)                /* (PIO_P_PDSR) Input Data Status Mask */
#define PIO_P_PDSR_P11(value)                 (PIO_P_PDSR_P11_Msk & (_UINT32_(value) << PIO_P_PDSR_P11_Pos)) /* Assigment of value for P11 in the PIO_P_PDSR register */
#define PIO_P_PDSR_P12_Pos                    _UINT32_(12)                                         /* (PIO_P_PDSR) Input Data Status Position */
#define PIO_P_PDSR_P12_Msk                    (_UINT32_(0x1) << PIO_P_PDSR_P12_Pos)                /* (PIO_P_PDSR) Input Data Status Mask */
#define PIO_P_PDSR_P12(value)                 (PIO_P_PDSR_P12_Msk & (_UINT32_(value) << PIO_P_PDSR_P12_Pos)) /* Assigment of value for P12 in the PIO_P_PDSR register */
#define PIO_P_PDSR_P13_Pos                    _UINT32_(13)                                         /* (PIO_P_PDSR) Input Data Status Position */
#define PIO_P_PDSR_P13_Msk                    (_UINT32_(0x1) << PIO_P_PDSR_P13_Pos)                /* (PIO_P_PDSR) Input Data Status Mask */
#define PIO_P_PDSR_P13(value)                 (PIO_P_PDSR_P13_Msk & (_UINT32_(value) << PIO_P_PDSR_P13_Pos)) /* Assigment of value for P13 in the PIO_P_PDSR register */
#define PIO_P_PDSR_P14_Pos                    _UINT32_(14)                                         /* (PIO_P_PDSR) Input Data Status Position */
#define PIO_P_PDSR_P14_Msk                    (_UINT32_(0x1) << PIO_P_PDSR_P14_Pos)                /* (PIO_P_PDSR) Input Data Status Mask */
#define PIO_P_PDSR_P14(value)                 (PIO_P_PDSR_P14_Msk & (_UINT32_(value) << PIO_P_PDSR_P14_Pos)) /* Assigment of value for P14 in the PIO_P_PDSR register */
#define PIO_P_PDSR_P15_Pos                    _UINT32_(15)                                         /* (PIO_P_PDSR) Input Data Status Position */
#define PIO_P_PDSR_P15_Msk                    (_UINT32_(0x1) << PIO_P_PDSR_P15_Pos)                /* (PIO_P_PDSR) Input Data Status Mask */
#define PIO_P_PDSR_P15(value)                 (PIO_P_PDSR_P15_Msk & (_UINT32_(value) << PIO_P_PDSR_P15_Pos)) /* Assigment of value for P15 in the PIO_P_PDSR register */
#define PIO_P_PDSR_P16_Pos                    _UINT32_(16)                                         /* (PIO_P_PDSR) Input Data Status Position */
#define PIO_P_PDSR_P16_Msk                    (_UINT32_(0x1) << PIO_P_PDSR_P16_Pos)                /* (PIO_P_PDSR) Input Data Status Mask */
#define PIO_P_PDSR_P16(value)                 (PIO_P_PDSR_P16_Msk & (_UINT32_(value) << PIO_P_PDSR_P16_Pos)) /* Assigment of value for P16 in the PIO_P_PDSR register */
#define PIO_P_PDSR_P17_Pos                    _UINT32_(17)                                         /* (PIO_P_PDSR) Input Data Status Position */
#define PIO_P_PDSR_P17_Msk                    (_UINT32_(0x1) << PIO_P_PDSR_P17_Pos)                /* (PIO_P_PDSR) Input Data Status Mask */
#define PIO_P_PDSR_P17(value)                 (PIO_P_PDSR_P17_Msk & (_UINT32_(value) << PIO_P_PDSR_P17_Pos)) /* Assigment of value for P17 in the PIO_P_PDSR register */
#define PIO_P_PDSR_P18_Pos                    _UINT32_(18)                                         /* (PIO_P_PDSR) Input Data Status Position */
#define PIO_P_PDSR_P18_Msk                    (_UINT32_(0x1) << PIO_P_PDSR_P18_Pos)                /* (PIO_P_PDSR) Input Data Status Mask */
#define PIO_P_PDSR_P18(value)                 (PIO_P_PDSR_P18_Msk & (_UINT32_(value) << PIO_P_PDSR_P18_Pos)) /* Assigment of value for P18 in the PIO_P_PDSR register */
#define PIO_P_PDSR_P19_Pos                    _UINT32_(19)                                         /* (PIO_P_PDSR) Input Data Status Position */
#define PIO_P_PDSR_P19_Msk                    (_UINT32_(0x1) << PIO_P_PDSR_P19_Pos)                /* (PIO_P_PDSR) Input Data Status Mask */
#define PIO_P_PDSR_P19(value)                 (PIO_P_PDSR_P19_Msk & (_UINT32_(value) << PIO_P_PDSR_P19_Pos)) /* Assigment of value for P19 in the PIO_P_PDSR register */
#define PIO_P_PDSR_P20_Pos                    _UINT32_(20)                                         /* (PIO_P_PDSR) Input Data Status Position */
#define PIO_P_PDSR_P20_Msk                    (_UINT32_(0x1) << PIO_P_PDSR_P20_Pos)                /* (PIO_P_PDSR) Input Data Status Mask */
#define PIO_P_PDSR_P20(value)                 (PIO_P_PDSR_P20_Msk & (_UINT32_(value) << PIO_P_PDSR_P20_Pos)) /* Assigment of value for P20 in the PIO_P_PDSR register */
#define PIO_P_PDSR_P21_Pos                    _UINT32_(21)                                         /* (PIO_P_PDSR) Input Data Status Position */
#define PIO_P_PDSR_P21_Msk                    (_UINT32_(0x1) << PIO_P_PDSR_P21_Pos)                /* (PIO_P_PDSR) Input Data Status Mask */
#define PIO_P_PDSR_P21(value)                 (PIO_P_PDSR_P21_Msk & (_UINT32_(value) << PIO_P_PDSR_P21_Pos)) /* Assigment of value for P21 in the PIO_P_PDSR register */
#define PIO_P_PDSR_P22_Pos                    _UINT32_(22)                                         /* (PIO_P_PDSR) Input Data Status Position */
#define PIO_P_PDSR_P22_Msk                    (_UINT32_(0x1) << PIO_P_PDSR_P22_Pos)                /* (PIO_P_PDSR) Input Data Status Mask */
#define PIO_P_PDSR_P22(value)                 (PIO_P_PDSR_P22_Msk & (_UINT32_(value) << PIO_P_PDSR_P22_Pos)) /* Assigment of value for P22 in the PIO_P_PDSR register */
#define PIO_P_PDSR_P23_Pos                    _UINT32_(23)                                         /* (PIO_P_PDSR) Input Data Status Position */
#define PIO_P_PDSR_P23_Msk                    (_UINT32_(0x1) << PIO_P_PDSR_P23_Pos)                /* (PIO_P_PDSR) Input Data Status Mask */
#define PIO_P_PDSR_P23(value)                 (PIO_P_PDSR_P23_Msk & (_UINT32_(value) << PIO_P_PDSR_P23_Pos)) /* Assigment of value for P23 in the PIO_P_PDSR register */
#define PIO_P_PDSR_P24_Pos                    _UINT32_(24)                                         /* (PIO_P_PDSR) Input Data Status Position */
#define PIO_P_PDSR_P24_Msk                    (_UINT32_(0x1) << PIO_P_PDSR_P24_Pos)                /* (PIO_P_PDSR) Input Data Status Mask */
#define PIO_P_PDSR_P24(value)                 (PIO_P_PDSR_P24_Msk & (_UINT32_(value) << PIO_P_PDSR_P24_Pos)) /* Assigment of value for P24 in the PIO_P_PDSR register */
#define PIO_P_PDSR_P25_Pos                    _UINT32_(25)                                         /* (PIO_P_PDSR) Input Data Status Position */
#define PIO_P_PDSR_P25_Msk                    (_UINT32_(0x1) << PIO_P_PDSR_P25_Pos)                /* (PIO_P_PDSR) Input Data Status Mask */
#define PIO_P_PDSR_P25(value)                 (PIO_P_PDSR_P25_Msk & (_UINT32_(value) << PIO_P_PDSR_P25_Pos)) /* Assigment of value for P25 in the PIO_P_PDSR register */
#define PIO_P_PDSR_P26_Pos                    _UINT32_(26)                                         /* (PIO_P_PDSR) Input Data Status Position */
#define PIO_P_PDSR_P26_Msk                    (_UINT32_(0x1) << PIO_P_PDSR_P26_Pos)                /* (PIO_P_PDSR) Input Data Status Mask */
#define PIO_P_PDSR_P26(value)                 (PIO_P_PDSR_P26_Msk & (_UINT32_(value) << PIO_P_PDSR_P26_Pos)) /* Assigment of value for P26 in the PIO_P_PDSR register */
#define PIO_P_PDSR_P27_Pos                    _UINT32_(27)                                         /* (PIO_P_PDSR) Input Data Status Position */
#define PIO_P_PDSR_P27_Msk                    (_UINT32_(0x1) << PIO_P_PDSR_P27_Pos)                /* (PIO_P_PDSR) Input Data Status Mask */
#define PIO_P_PDSR_P27(value)                 (PIO_P_PDSR_P27_Msk & (_UINT32_(value) << PIO_P_PDSR_P27_Pos)) /* Assigment of value for P27 in the PIO_P_PDSR register */
#define PIO_P_PDSR_P28_Pos                    _UINT32_(28)                                         /* (PIO_P_PDSR) Input Data Status Position */
#define PIO_P_PDSR_P28_Msk                    (_UINT32_(0x1) << PIO_P_PDSR_P28_Pos)                /* (PIO_P_PDSR) Input Data Status Mask */
#define PIO_P_PDSR_P28(value)                 (PIO_P_PDSR_P28_Msk & (_UINT32_(value) << PIO_P_PDSR_P28_Pos)) /* Assigment of value for P28 in the PIO_P_PDSR register */
#define PIO_P_PDSR_P29_Pos                    _UINT32_(29)                                         /* (PIO_P_PDSR) Input Data Status Position */
#define PIO_P_PDSR_P29_Msk                    (_UINT32_(0x1) << PIO_P_PDSR_P29_Pos)                /* (PIO_P_PDSR) Input Data Status Mask */
#define PIO_P_PDSR_P29(value)                 (PIO_P_PDSR_P29_Msk & (_UINT32_(value) << PIO_P_PDSR_P29_Pos)) /* Assigment of value for P29 in the PIO_P_PDSR register */
#define PIO_P_PDSR_P30_Pos                    _UINT32_(30)                                         /* (PIO_P_PDSR) Input Data Status Position */
#define PIO_P_PDSR_P30_Msk                    (_UINT32_(0x1) << PIO_P_PDSR_P30_Pos)                /* (PIO_P_PDSR) Input Data Status Mask */
#define PIO_P_PDSR_P30(value)                 (PIO_P_PDSR_P30_Msk & (_UINT32_(value) << PIO_P_PDSR_P30_Pos)) /* Assigment of value for P30 in the PIO_P_PDSR register */
#define PIO_P_PDSR_P31_Pos                    _UINT32_(31)                                         /* (PIO_P_PDSR) Input Data Status Position */
#define PIO_P_PDSR_P31_Msk                    (_UINT32_(0x1) << PIO_P_PDSR_P31_Pos)                /* (PIO_P_PDSR) Input Data Status Mask */
#define PIO_P_PDSR_P31(value)                 (PIO_P_PDSR_P31_Msk & (_UINT32_(value) << PIO_P_PDSR_P31_Pos)) /* Assigment of value for P31 in the PIO_P_PDSR register */
#define PIO_P_PDSR_Msk                        _UINT32_(0xFFFFFFFF)                                 /* (PIO_P_PDSR) Register Mask  */

#define PIO_P_PDSR_P_Pos                      _UINT32_(0)                                          /* (PIO_P_PDSR Position) Input Data Status */
#define PIO_P_PDSR_P_Msk                      (_UINT32_(0xFFFFFFFF) << PIO_P_PDSR_P_Pos)           /* (PIO_P_PDSR Mask) P */
#define PIO_P_PDSR_P(value)                   (PIO_P_PDSR_P_Msk & (_UINT32_(value) << PIO_P_PDSR_P_Pos)) 

/* -------- PIO_P_LOCKSR : (PIO Offset: 0x0C) ( R/ 32) PIO Privilege Lock Status Register (p_iogroup = 0) -------- */
#define PIO_P_LOCKSR_P0_Pos                   _UINT32_(0)                                          /* (PIO_P_LOCKSR) Lock Status Position */
#define PIO_P_LOCKSR_P0_Msk                   (_UINT32_(0x1) << PIO_P_LOCKSR_P0_Pos)               /* (PIO_P_LOCKSR) Lock Status Mask */
#define PIO_P_LOCKSR_P0(value)                (PIO_P_LOCKSR_P0_Msk & (_UINT32_(value) << PIO_P_LOCKSR_P0_Pos)) /* Assigment of value for P0 in the PIO_P_LOCKSR register */
#define PIO_P_LOCKSR_P1_Pos                   _UINT32_(1)                                          /* (PIO_P_LOCKSR) Lock Status Position */
#define PIO_P_LOCKSR_P1_Msk                   (_UINT32_(0x1) << PIO_P_LOCKSR_P1_Pos)               /* (PIO_P_LOCKSR) Lock Status Mask */
#define PIO_P_LOCKSR_P1(value)                (PIO_P_LOCKSR_P1_Msk & (_UINT32_(value) << PIO_P_LOCKSR_P1_Pos)) /* Assigment of value for P1 in the PIO_P_LOCKSR register */
#define PIO_P_LOCKSR_P2_Pos                   _UINT32_(2)                                          /* (PIO_P_LOCKSR) Lock Status Position */
#define PIO_P_LOCKSR_P2_Msk                   (_UINT32_(0x1) << PIO_P_LOCKSR_P2_Pos)               /* (PIO_P_LOCKSR) Lock Status Mask */
#define PIO_P_LOCKSR_P2(value)                (PIO_P_LOCKSR_P2_Msk & (_UINT32_(value) << PIO_P_LOCKSR_P2_Pos)) /* Assigment of value for P2 in the PIO_P_LOCKSR register */
#define PIO_P_LOCKSR_P3_Pos                   _UINT32_(3)                                          /* (PIO_P_LOCKSR) Lock Status Position */
#define PIO_P_LOCKSR_P3_Msk                   (_UINT32_(0x1) << PIO_P_LOCKSR_P3_Pos)               /* (PIO_P_LOCKSR) Lock Status Mask */
#define PIO_P_LOCKSR_P3(value)                (PIO_P_LOCKSR_P3_Msk & (_UINT32_(value) << PIO_P_LOCKSR_P3_Pos)) /* Assigment of value for P3 in the PIO_P_LOCKSR register */
#define PIO_P_LOCKSR_P4_Pos                   _UINT32_(4)                                          /* (PIO_P_LOCKSR) Lock Status Position */
#define PIO_P_LOCKSR_P4_Msk                   (_UINT32_(0x1) << PIO_P_LOCKSR_P4_Pos)               /* (PIO_P_LOCKSR) Lock Status Mask */
#define PIO_P_LOCKSR_P4(value)                (PIO_P_LOCKSR_P4_Msk & (_UINT32_(value) << PIO_P_LOCKSR_P4_Pos)) /* Assigment of value for P4 in the PIO_P_LOCKSR register */
#define PIO_P_LOCKSR_P5_Pos                   _UINT32_(5)                                          /* (PIO_P_LOCKSR) Lock Status Position */
#define PIO_P_LOCKSR_P5_Msk                   (_UINT32_(0x1) << PIO_P_LOCKSR_P5_Pos)               /* (PIO_P_LOCKSR) Lock Status Mask */
#define PIO_P_LOCKSR_P5(value)                (PIO_P_LOCKSR_P5_Msk & (_UINT32_(value) << PIO_P_LOCKSR_P5_Pos)) /* Assigment of value for P5 in the PIO_P_LOCKSR register */
#define PIO_P_LOCKSR_P6_Pos                   _UINT32_(6)                                          /* (PIO_P_LOCKSR) Lock Status Position */
#define PIO_P_LOCKSR_P6_Msk                   (_UINT32_(0x1) << PIO_P_LOCKSR_P6_Pos)               /* (PIO_P_LOCKSR) Lock Status Mask */
#define PIO_P_LOCKSR_P6(value)                (PIO_P_LOCKSR_P6_Msk & (_UINT32_(value) << PIO_P_LOCKSR_P6_Pos)) /* Assigment of value for P6 in the PIO_P_LOCKSR register */
#define PIO_P_LOCKSR_P7_Pos                   _UINT32_(7)                                          /* (PIO_P_LOCKSR) Lock Status Position */
#define PIO_P_LOCKSR_P7_Msk                   (_UINT32_(0x1) << PIO_P_LOCKSR_P7_Pos)               /* (PIO_P_LOCKSR) Lock Status Mask */
#define PIO_P_LOCKSR_P7(value)                (PIO_P_LOCKSR_P7_Msk & (_UINT32_(value) << PIO_P_LOCKSR_P7_Pos)) /* Assigment of value for P7 in the PIO_P_LOCKSR register */
#define PIO_P_LOCKSR_P8_Pos                   _UINT32_(8)                                          /* (PIO_P_LOCKSR) Lock Status Position */
#define PIO_P_LOCKSR_P8_Msk                   (_UINT32_(0x1) << PIO_P_LOCKSR_P8_Pos)               /* (PIO_P_LOCKSR) Lock Status Mask */
#define PIO_P_LOCKSR_P8(value)                (PIO_P_LOCKSR_P8_Msk & (_UINT32_(value) << PIO_P_LOCKSR_P8_Pos)) /* Assigment of value for P8 in the PIO_P_LOCKSR register */
#define PIO_P_LOCKSR_P9_Pos                   _UINT32_(9)                                          /* (PIO_P_LOCKSR) Lock Status Position */
#define PIO_P_LOCKSR_P9_Msk                   (_UINT32_(0x1) << PIO_P_LOCKSR_P9_Pos)               /* (PIO_P_LOCKSR) Lock Status Mask */
#define PIO_P_LOCKSR_P9(value)                (PIO_P_LOCKSR_P9_Msk & (_UINT32_(value) << PIO_P_LOCKSR_P9_Pos)) /* Assigment of value for P9 in the PIO_P_LOCKSR register */
#define PIO_P_LOCKSR_P10_Pos                  _UINT32_(10)                                         /* (PIO_P_LOCKSR) Lock Status Position */
#define PIO_P_LOCKSR_P10_Msk                  (_UINT32_(0x1) << PIO_P_LOCKSR_P10_Pos)              /* (PIO_P_LOCKSR) Lock Status Mask */
#define PIO_P_LOCKSR_P10(value)               (PIO_P_LOCKSR_P10_Msk & (_UINT32_(value) << PIO_P_LOCKSR_P10_Pos)) /* Assigment of value for P10 in the PIO_P_LOCKSR register */
#define PIO_P_LOCKSR_P11_Pos                  _UINT32_(11)                                         /* (PIO_P_LOCKSR) Lock Status Position */
#define PIO_P_LOCKSR_P11_Msk                  (_UINT32_(0x1) << PIO_P_LOCKSR_P11_Pos)              /* (PIO_P_LOCKSR) Lock Status Mask */
#define PIO_P_LOCKSR_P11(value)               (PIO_P_LOCKSR_P11_Msk & (_UINT32_(value) << PIO_P_LOCKSR_P11_Pos)) /* Assigment of value for P11 in the PIO_P_LOCKSR register */
#define PIO_P_LOCKSR_P12_Pos                  _UINT32_(12)                                         /* (PIO_P_LOCKSR) Lock Status Position */
#define PIO_P_LOCKSR_P12_Msk                  (_UINT32_(0x1) << PIO_P_LOCKSR_P12_Pos)              /* (PIO_P_LOCKSR) Lock Status Mask */
#define PIO_P_LOCKSR_P12(value)               (PIO_P_LOCKSR_P12_Msk & (_UINT32_(value) << PIO_P_LOCKSR_P12_Pos)) /* Assigment of value for P12 in the PIO_P_LOCKSR register */
#define PIO_P_LOCKSR_P13_Pos                  _UINT32_(13)                                         /* (PIO_P_LOCKSR) Lock Status Position */
#define PIO_P_LOCKSR_P13_Msk                  (_UINT32_(0x1) << PIO_P_LOCKSR_P13_Pos)              /* (PIO_P_LOCKSR) Lock Status Mask */
#define PIO_P_LOCKSR_P13(value)               (PIO_P_LOCKSR_P13_Msk & (_UINT32_(value) << PIO_P_LOCKSR_P13_Pos)) /* Assigment of value for P13 in the PIO_P_LOCKSR register */
#define PIO_P_LOCKSR_P14_Pos                  _UINT32_(14)                                         /* (PIO_P_LOCKSR) Lock Status Position */
#define PIO_P_LOCKSR_P14_Msk                  (_UINT32_(0x1) << PIO_P_LOCKSR_P14_Pos)              /* (PIO_P_LOCKSR) Lock Status Mask */
#define PIO_P_LOCKSR_P14(value)               (PIO_P_LOCKSR_P14_Msk & (_UINT32_(value) << PIO_P_LOCKSR_P14_Pos)) /* Assigment of value for P14 in the PIO_P_LOCKSR register */
#define PIO_P_LOCKSR_P15_Pos                  _UINT32_(15)                                         /* (PIO_P_LOCKSR) Lock Status Position */
#define PIO_P_LOCKSR_P15_Msk                  (_UINT32_(0x1) << PIO_P_LOCKSR_P15_Pos)              /* (PIO_P_LOCKSR) Lock Status Mask */
#define PIO_P_LOCKSR_P15(value)               (PIO_P_LOCKSR_P15_Msk & (_UINT32_(value) << PIO_P_LOCKSR_P15_Pos)) /* Assigment of value for P15 in the PIO_P_LOCKSR register */
#define PIO_P_LOCKSR_P16_Pos                  _UINT32_(16)                                         /* (PIO_P_LOCKSR) Lock Status Position */
#define PIO_P_LOCKSR_P16_Msk                  (_UINT32_(0x1) << PIO_P_LOCKSR_P16_Pos)              /* (PIO_P_LOCKSR) Lock Status Mask */
#define PIO_P_LOCKSR_P16(value)               (PIO_P_LOCKSR_P16_Msk & (_UINT32_(value) << PIO_P_LOCKSR_P16_Pos)) /* Assigment of value for P16 in the PIO_P_LOCKSR register */
#define PIO_P_LOCKSR_P17_Pos                  _UINT32_(17)                                         /* (PIO_P_LOCKSR) Lock Status Position */
#define PIO_P_LOCKSR_P17_Msk                  (_UINT32_(0x1) << PIO_P_LOCKSR_P17_Pos)              /* (PIO_P_LOCKSR) Lock Status Mask */
#define PIO_P_LOCKSR_P17(value)               (PIO_P_LOCKSR_P17_Msk & (_UINT32_(value) << PIO_P_LOCKSR_P17_Pos)) /* Assigment of value for P17 in the PIO_P_LOCKSR register */
#define PIO_P_LOCKSR_P18_Pos                  _UINT32_(18)                                         /* (PIO_P_LOCKSR) Lock Status Position */
#define PIO_P_LOCKSR_P18_Msk                  (_UINT32_(0x1) << PIO_P_LOCKSR_P18_Pos)              /* (PIO_P_LOCKSR) Lock Status Mask */
#define PIO_P_LOCKSR_P18(value)               (PIO_P_LOCKSR_P18_Msk & (_UINT32_(value) << PIO_P_LOCKSR_P18_Pos)) /* Assigment of value for P18 in the PIO_P_LOCKSR register */
#define PIO_P_LOCKSR_P19_Pos                  _UINT32_(19)                                         /* (PIO_P_LOCKSR) Lock Status Position */
#define PIO_P_LOCKSR_P19_Msk                  (_UINT32_(0x1) << PIO_P_LOCKSR_P19_Pos)              /* (PIO_P_LOCKSR) Lock Status Mask */
#define PIO_P_LOCKSR_P19(value)               (PIO_P_LOCKSR_P19_Msk & (_UINT32_(value) << PIO_P_LOCKSR_P19_Pos)) /* Assigment of value for P19 in the PIO_P_LOCKSR register */
#define PIO_P_LOCKSR_P20_Pos                  _UINT32_(20)                                         /* (PIO_P_LOCKSR) Lock Status Position */
#define PIO_P_LOCKSR_P20_Msk                  (_UINT32_(0x1) << PIO_P_LOCKSR_P20_Pos)              /* (PIO_P_LOCKSR) Lock Status Mask */
#define PIO_P_LOCKSR_P20(value)               (PIO_P_LOCKSR_P20_Msk & (_UINT32_(value) << PIO_P_LOCKSR_P20_Pos)) /* Assigment of value for P20 in the PIO_P_LOCKSR register */
#define PIO_P_LOCKSR_P21_Pos                  _UINT32_(21)                                         /* (PIO_P_LOCKSR) Lock Status Position */
#define PIO_P_LOCKSR_P21_Msk                  (_UINT32_(0x1) << PIO_P_LOCKSR_P21_Pos)              /* (PIO_P_LOCKSR) Lock Status Mask */
#define PIO_P_LOCKSR_P21(value)               (PIO_P_LOCKSR_P21_Msk & (_UINT32_(value) << PIO_P_LOCKSR_P21_Pos)) /* Assigment of value for P21 in the PIO_P_LOCKSR register */
#define PIO_P_LOCKSR_P22_Pos                  _UINT32_(22)                                         /* (PIO_P_LOCKSR) Lock Status Position */
#define PIO_P_LOCKSR_P22_Msk                  (_UINT32_(0x1) << PIO_P_LOCKSR_P22_Pos)              /* (PIO_P_LOCKSR) Lock Status Mask */
#define PIO_P_LOCKSR_P22(value)               (PIO_P_LOCKSR_P22_Msk & (_UINT32_(value) << PIO_P_LOCKSR_P22_Pos)) /* Assigment of value for P22 in the PIO_P_LOCKSR register */
#define PIO_P_LOCKSR_P23_Pos                  _UINT32_(23)                                         /* (PIO_P_LOCKSR) Lock Status Position */
#define PIO_P_LOCKSR_P23_Msk                  (_UINT32_(0x1) << PIO_P_LOCKSR_P23_Pos)              /* (PIO_P_LOCKSR) Lock Status Mask */
#define PIO_P_LOCKSR_P23(value)               (PIO_P_LOCKSR_P23_Msk & (_UINT32_(value) << PIO_P_LOCKSR_P23_Pos)) /* Assigment of value for P23 in the PIO_P_LOCKSR register */
#define PIO_P_LOCKSR_P24_Pos                  _UINT32_(24)                                         /* (PIO_P_LOCKSR) Lock Status Position */
#define PIO_P_LOCKSR_P24_Msk                  (_UINT32_(0x1) << PIO_P_LOCKSR_P24_Pos)              /* (PIO_P_LOCKSR) Lock Status Mask */
#define PIO_P_LOCKSR_P24(value)               (PIO_P_LOCKSR_P24_Msk & (_UINT32_(value) << PIO_P_LOCKSR_P24_Pos)) /* Assigment of value for P24 in the PIO_P_LOCKSR register */
#define PIO_P_LOCKSR_P25_Pos                  _UINT32_(25)                                         /* (PIO_P_LOCKSR) Lock Status Position */
#define PIO_P_LOCKSR_P25_Msk                  (_UINT32_(0x1) << PIO_P_LOCKSR_P25_Pos)              /* (PIO_P_LOCKSR) Lock Status Mask */
#define PIO_P_LOCKSR_P25(value)               (PIO_P_LOCKSR_P25_Msk & (_UINT32_(value) << PIO_P_LOCKSR_P25_Pos)) /* Assigment of value for P25 in the PIO_P_LOCKSR register */
#define PIO_P_LOCKSR_P26_Pos                  _UINT32_(26)                                         /* (PIO_P_LOCKSR) Lock Status Position */
#define PIO_P_LOCKSR_P26_Msk                  (_UINT32_(0x1) << PIO_P_LOCKSR_P26_Pos)              /* (PIO_P_LOCKSR) Lock Status Mask */
#define PIO_P_LOCKSR_P26(value)               (PIO_P_LOCKSR_P26_Msk & (_UINT32_(value) << PIO_P_LOCKSR_P26_Pos)) /* Assigment of value for P26 in the PIO_P_LOCKSR register */
#define PIO_P_LOCKSR_P27_Pos                  _UINT32_(27)                                         /* (PIO_P_LOCKSR) Lock Status Position */
#define PIO_P_LOCKSR_P27_Msk                  (_UINT32_(0x1) << PIO_P_LOCKSR_P27_Pos)              /* (PIO_P_LOCKSR) Lock Status Mask */
#define PIO_P_LOCKSR_P27(value)               (PIO_P_LOCKSR_P27_Msk & (_UINT32_(value) << PIO_P_LOCKSR_P27_Pos)) /* Assigment of value for P27 in the PIO_P_LOCKSR register */
#define PIO_P_LOCKSR_P28_Pos                  _UINT32_(28)                                         /* (PIO_P_LOCKSR) Lock Status Position */
#define PIO_P_LOCKSR_P28_Msk                  (_UINT32_(0x1) << PIO_P_LOCKSR_P28_Pos)              /* (PIO_P_LOCKSR) Lock Status Mask */
#define PIO_P_LOCKSR_P28(value)               (PIO_P_LOCKSR_P28_Msk & (_UINT32_(value) << PIO_P_LOCKSR_P28_Pos)) /* Assigment of value for P28 in the PIO_P_LOCKSR register */
#define PIO_P_LOCKSR_P29_Pos                  _UINT32_(29)                                         /* (PIO_P_LOCKSR) Lock Status Position */
#define PIO_P_LOCKSR_P29_Msk                  (_UINT32_(0x1) << PIO_P_LOCKSR_P29_Pos)              /* (PIO_P_LOCKSR) Lock Status Mask */
#define PIO_P_LOCKSR_P29(value)               (PIO_P_LOCKSR_P29_Msk & (_UINT32_(value) << PIO_P_LOCKSR_P29_Pos)) /* Assigment of value for P29 in the PIO_P_LOCKSR register */
#define PIO_P_LOCKSR_P30_Pos                  _UINT32_(30)                                         /* (PIO_P_LOCKSR) Lock Status Position */
#define PIO_P_LOCKSR_P30_Msk                  (_UINT32_(0x1) << PIO_P_LOCKSR_P30_Pos)              /* (PIO_P_LOCKSR) Lock Status Mask */
#define PIO_P_LOCKSR_P30(value)               (PIO_P_LOCKSR_P30_Msk & (_UINT32_(value) << PIO_P_LOCKSR_P30_Pos)) /* Assigment of value for P30 in the PIO_P_LOCKSR register */
#define PIO_P_LOCKSR_P31_Pos                  _UINT32_(31)                                         /* (PIO_P_LOCKSR) Lock Status Position */
#define PIO_P_LOCKSR_P31_Msk                  (_UINT32_(0x1) << PIO_P_LOCKSR_P31_Pos)              /* (PIO_P_LOCKSR) Lock Status Mask */
#define PIO_P_LOCKSR_P31(value)               (PIO_P_LOCKSR_P31_Msk & (_UINT32_(value) << PIO_P_LOCKSR_P31_Pos)) /* Assigment of value for P31 in the PIO_P_LOCKSR register */
#define PIO_P_LOCKSR_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (PIO_P_LOCKSR) Register Mask  */

#define PIO_P_LOCKSR_P_Pos                    _UINT32_(0)                                          /* (PIO_P_LOCKSR Position) Lock Status */
#define PIO_P_LOCKSR_P_Msk                    (_UINT32_(0xFFFFFFFF) << PIO_P_LOCKSR_P_Pos)         /* (PIO_P_LOCKSR Mask) P */
#define PIO_P_LOCKSR_P(value)                 (PIO_P_LOCKSR_P_Msk & (_UINT32_(value) << PIO_P_LOCKSR_P_Pos)) 

/* -------- PIO_P_SODR : (PIO Offset: 0x10) ( /W 32) PIO Privilege Set Output Data Register (p_iogroup = 0) -------- */
#define PIO_P_SODR_P0_Pos                     _UINT32_(0)                                          /* (PIO_P_SODR) Set Output Data Position */
#define PIO_P_SODR_P0_Msk                     (_UINT32_(0x1) << PIO_P_SODR_P0_Pos)                 /* (PIO_P_SODR) Set Output Data Mask */
#define PIO_P_SODR_P0(value)                  (PIO_P_SODR_P0_Msk & (_UINT32_(value) << PIO_P_SODR_P0_Pos)) /* Assigment of value for P0 in the PIO_P_SODR register */
#define PIO_P_SODR_P1_Pos                     _UINT32_(1)                                          /* (PIO_P_SODR) Set Output Data Position */
#define PIO_P_SODR_P1_Msk                     (_UINT32_(0x1) << PIO_P_SODR_P1_Pos)                 /* (PIO_P_SODR) Set Output Data Mask */
#define PIO_P_SODR_P1(value)                  (PIO_P_SODR_P1_Msk & (_UINT32_(value) << PIO_P_SODR_P1_Pos)) /* Assigment of value for P1 in the PIO_P_SODR register */
#define PIO_P_SODR_P2_Pos                     _UINT32_(2)                                          /* (PIO_P_SODR) Set Output Data Position */
#define PIO_P_SODR_P2_Msk                     (_UINT32_(0x1) << PIO_P_SODR_P2_Pos)                 /* (PIO_P_SODR) Set Output Data Mask */
#define PIO_P_SODR_P2(value)                  (PIO_P_SODR_P2_Msk & (_UINT32_(value) << PIO_P_SODR_P2_Pos)) /* Assigment of value for P2 in the PIO_P_SODR register */
#define PIO_P_SODR_P3_Pos                     _UINT32_(3)                                          /* (PIO_P_SODR) Set Output Data Position */
#define PIO_P_SODR_P3_Msk                     (_UINT32_(0x1) << PIO_P_SODR_P3_Pos)                 /* (PIO_P_SODR) Set Output Data Mask */
#define PIO_P_SODR_P3(value)                  (PIO_P_SODR_P3_Msk & (_UINT32_(value) << PIO_P_SODR_P3_Pos)) /* Assigment of value for P3 in the PIO_P_SODR register */
#define PIO_P_SODR_P4_Pos                     _UINT32_(4)                                          /* (PIO_P_SODR) Set Output Data Position */
#define PIO_P_SODR_P4_Msk                     (_UINT32_(0x1) << PIO_P_SODR_P4_Pos)                 /* (PIO_P_SODR) Set Output Data Mask */
#define PIO_P_SODR_P4(value)                  (PIO_P_SODR_P4_Msk & (_UINT32_(value) << PIO_P_SODR_P4_Pos)) /* Assigment of value for P4 in the PIO_P_SODR register */
#define PIO_P_SODR_P5_Pos                     _UINT32_(5)                                          /* (PIO_P_SODR) Set Output Data Position */
#define PIO_P_SODR_P5_Msk                     (_UINT32_(0x1) << PIO_P_SODR_P5_Pos)                 /* (PIO_P_SODR) Set Output Data Mask */
#define PIO_P_SODR_P5(value)                  (PIO_P_SODR_P5_Msk & (_UINT32_(value) << PIO_P_SODR_P5_Pos)) /* Assigment of value for P5 in the PIO_P_SODR register */
#define PIO_P_SODR_P6_Pos                     _UINT32_(6)                                          /* (PIO_P_SODR) Set Output Data Position */
#define PIO_P_SODR_P6_Msk                     (_UINT32_(0x1) << PIO_P_SODR_P6_Pos)                 /* (PIO_P_SODR) Set Output Data Mask */
#define PIO_P_SODR_P6(value)                  (PIO_P_SODR_P6_Msk & (_UINT32_(value) << PIO_P_SODR_P6_Pos)) /* Assigment of value for P6 in the PIO_P_SODR register */
#define PIO_P_SODR_P7_Pos                     _UINT32_(7)                                          /* (PIO_P_SODR) Set Output Data Position */
#define PIO_P_SODR_P7_Msk                     (_UINT32_(0x1) << PIO_P_SODR_P7_Pos)                 /* (PIO_P_SODR) Set Output Data Mask */
#define PIO_P_SODR_P7(value)                  (PIO_P_SODR_P7_Msk & (_UINT32_(value) << PIO_P_SODR_P7_Pos)) /* Assigment of value for P7 in the PIO_P_SODR register */
#define PIO_P_SODR_P8_Pos                     _UINT32_(8)                                          /* (PIO_P_SODR) Set Output Data Position */
#define PIO_P_SODR_P8_Msk                     (_UINT32_(0x1) << PIO_P_SODR_P8_Pos)                 /* (PIO_P_SODR) Set Output Data Mask */
#define PIO_P_SODR_P8(value)                  (PIO_P_SODR_P8_Msk & (_UINT32_(value) << PIO_P_SODR_P8_Pos)) /* Assigment of value for P8 in the PIO_P_SODR register */
#define PIO_P_SODR_P9_Pos                     _UINT32_(9)                                          /* (PIO_P_SODR) Set Output Data Position */
#define PIO_P_SODR_P9_Msk                     (_UINT32_(0x1) << PIO_P_SODR_P9_Pos)                 /* (PIO_P_SODR) Set Output Data Mask */
#define PIO_P_SODR_P9(value)                  (PIO_P_SODR_P9_Msk & (_UINT32_(value) << PIO_P_SODR_P9_Pos)) /* Assigment of value for P9 in the PIO_P_SODR register */
#define PIO_P_SODR_P10_Pos                    _UINT32_(10)                                         /* (PIO_P_SODR) Set Output Data Position */
#define PIO_P_SODR_P10_Msk                    (_UINT32_(0x1) << PIO_P_SODR_P10_Pos)                /* (PIO_P_SODR) Set Output Data Mask */
#define PIO_P_SODR_P10(value)                 (PIO_P_SODR_P10_Msk & (_UINT32_(value) << PIO_P_SODR_P10_Pos)) /* Assigment of value for P10 in the PIO_P_SODR register */
#define PIO_P_SODR_P11_Pos                    _UINT32_(11)                                         /* (PIO_P_SODR) Set Output Data Position */
#define PIO_P_SODR_P11_Msk                    (_UINT32_(0x1) << PIO_P_SODR_P11_Pos)                /* (PIO_P_SODR) Set Output Data Mask */
#define PIO_P_SODR_P11(value)                 (PIO_P_SODR_P11_Msk & (_UINT32_(value) << PIO_P_SODR_P11_Pos)) /* Assigment of value for P11 in the PIO_P_SODR register */
#define PIO_P_SODR_P12_Pos                    _UINT32_(12)                                         /* (PIO_P_SODR) Set Output Data Position */
#define PIO_P_SODR_P12_Msk                    (_UINT32_(0x1) << PIO_P_SODR_P12_Pos)                /* (PIO_P_SODR) Set Output Data Mask */
#define PIO_P_SODR_P12(value)                 (PIO_P_SODR_P12_Msk & (_UINT32_(value) << PIO_P_SODR_P12_Pos)) /* Assigment of value for P12 in the PIO_P_SODR register */
#define PIO_P_SODR_P13_Pos                    _UINT32_(13)                                         /* (PIO_P_SODR) Set Output Data Position */
#define PIO_P_SODR_P13_Msk                    (_UINT32_(0x1) << PIO_P_SODR_P13_Pos)                /* (PIO_P_SODR) Set Output Data Mask */
#define PIO_P_SODR_P13(value)                 (PIO_P_SODR_P13_Msk & (_UINT32_(value) << PIO_P_SODR_P13_Pos)) /* Assigment of value for P13 in the PIO_P_SODR register */
#define PIO_P_SODR_P14_Pos                    _UINT32_(14)                                         /* (PIO_P_SODR) Set Output Data Position */
#define PIO_P_SODR_P14_Msk                    (_UINT32_(0x1) << PIO_P_SODR_P14_Pos)                /* (PIO_P_SODR) Set Output Data Mask */
#define PIO_P_SODR_P14(value)                 (PIO_P_SODR_P14_Msk & (_UINT32_(value) << PIO_P_SODR_P14_Pos)) /* Assigment of value for P14 in the PIO_P_SODR register */
#define PIO_P_SODR_P15_Pos                    _UINT32_(15)                                         /* (PIO_P_SODR) Set Output Data Position */
#define PIO_P_SODR_P15_Msk                    (_UINT32_(0x1) << PIO_P_SODR_P15_Pos)                /* (PIO_P_SODR) Set Output Data Mask */
#define PIO_P_SODR_P15(value)                 (PIO_P_SODR_P15_Msk & (_UINT32_(value) << PIO_P_SODR_P15_Pos)) /* Assigment of value for P15 in the PIO_P_SODR register */
#define PIO_P_SODR_P16_Pos                    _UINT32_(16)                                         /* (PIO_P_SODR) Set Output Data Position */
#define PIO_P_SODR_P16_Msk                    (_UINT32_(0x1) << PIO_P_SODR_P16_Pos)                /* (PIO_P_SODR) Set Output Data Mask */
#define PIO_P_SODR_P16(value)                 (PIO_P_SODR_P16_Msk & (_UINT32_(value) << PIO_P_SODR_P16_Pos)) /* Assigment of value for P16 in the PIO_P_SODR register */
#define PIO_P_SODR_P17_Pos                    _UINT32_(17)                                         /* (PIO_P_SODR) Set Output Data Position */
#define PIO_P_SODR_P17_Msk                    (_UINT32_(0x1) << PIO_P_SODR_P17_Pos)                /* (PIO_P_SODR) Set Output Data Mask */
#define PIO_P_SODR_P17(value)                 (PIO_P_SODR_P17_Msk & (_UINT32_(value) << PIO_P_SODR_P17_Pos)) /* Assigment of value for P17 in the PIO_P_SODR register */
#define PIO_P_SODR_P18_Pos                    _UINT32_(18)                                         /* (PIO_P_SODR) Set Output Data Position */
#define PIO_P_SODR_P18_Msk                    (_UINT32_(0x1) << PIO_P_SODR_P18_Pos)                /* (PIO_P_SODR) Set Output Data Mask */
#define PIO_P_SODR_P18(value)                 (PIO_P_SODR_P18_Msk & (_UINT32_(value) << PIO_P_SODR_P18_Pos)) /* Assigment of value for P18 in the PIO_P_SODR register */
#define PIO_P_SODR_P19_Pos                    _UINT32_(19)                                         /* (PIO_P_SODR) Set Output Data Position */
#define PIO_P_SODR_P19_Msk                    (_UINT32_(0x1) << PIO_P_SODR_P19_Pos)                /* (PIO_P_SODR) Set Output Data Mask */
#define PIO_P_SODR_P19(value)                 (PIO_P_SODR_P19_Msk & (_UINT32_(value) << PIO_P_SODR_P19_Pos)) /* Assigment of value for P19 in the PIO_P_SODR register */
#define PIO_P_SODR_P20_Pos                    _UINT32_(20)                                         /* (PIO_P_SODR) Set Output Data Position */
#define PIO_P_SODR_P20_Msk                    (_UINT32_(0x1) << PIO_P_SODR_P20_Pos)                /* (PIO_P_SODR) Set Output Data Mask */
#define PIO_P_SODR_P20(value)                 (PIO_P_SODR_P20_Msk & (_UINT32_(value) << PIO_P_SODR_P20_Pos)) /* Assigment of value for P20 in the PIO_P_SODR register */
#define PIO_P_SODR_P21_Pos                    _UINT32_(21)                                         /* (PIO_P_SODR) Set Output Data Position */
#define PIO_P_SODR_P21_Msk                    (_UINT32_(0x1) << PIO_P_SODR_P21_Pos)                /* (PIO_P_SODR) Set Output Data Mask */
#define PIO_P_SODR_P21(value)                 (PIO_P_SODR_P21_Msk & (_UINT32_(value) << PIO_P_SODR_P21_Pos)) /* Assigment of value for P21 in the PIO_P_SODR register */
#define PIO_P_SODR_P22_Pos                    _UINT32_(22)                                         /* (PIO_P_SODR) Set Output Data Position */
#define PIO_P_SODR_P22_Msk                    (_UINT32_(0x1) << PIO_P_SODR_P22_Pos)                /* (PIO_P_SODR) Set Output Data Mask */
#define PIO_P_SODR_P22(value)                 (PIO_P_SODR_P22_Msk & (_UINT32_(value) << PIO_P_SODR_P22_Pos)) /* Assigment of value for P22 in the PIO_P_SODR register */
#define PIO_P_SODR_P23_Pos                    _UINT32_(23)                                         /* (PIO_P_SODR) Set Output Data Position */
#define PIO_P_SODR_P23_Msk                    (_UINT32_(0x1) << PIO_P_SODR_P23_Pos)                /* (PIO_P_SODR) Set Output Data Mask */
#define PIO_P_SODR_P23(value)                 (PIO_P_SODR_P23_Msk & (_UINT32_(value) << PIO_P_SODR_P23_Pos)) /* Assigment of value for P23 in the PIO_P_SODR register */
#define PIO_P_SODR_P24_Pos                    _UINT32_(24)                                         /* (PIO_P_SODR) Set Output Data Position */
#define PIO_P_SODR_P24_Msk                    (_UINT32_(0x1) << PIO_P_SODR_P24_Pos)                /* (PIO_P_SODR) Set Output Data Mask */
#define PIO_P_SODR_P24(value)                 (PIO_P_SODR_P24_Msk & (_UINT32_(value) << PIO_P_SODR_P24_Pos)) /* Assigment of value for P24 in the PIO_P_SODR register */
#define PIO_P_SODR_P25_Pos                    _UINT32_(25)                                         /* (PIO_P_SODR) Set Output Data Position */
#define PIO_P_SODR_P25_Msk                    (_UINT32_(0x1) << PIO_P_SODR_P25_Pos)                /* (PIO_P_SODR) Set Output Data Mask */
#define PIO_P_SODR_P25(value)                 (PIO_P_SODR_P25_Msk & (_UINT32_(value) << PIO_P_SODR_P25_Pos)) /* Assigment of value for P25 in the PIO_P_SODR register */
#define PIO_P_SODR_P26_Pos                    _UINT32_(26)                                         /* (PIO_P_SODR) Set Output Data Position */
#define PIO_P_SODR_P26_Msk                    (_UINT32_(0x1) << PIO_P_SODR_P26_Pos)                /* (PIO_P_SODR) Set Output Data Mask */
#define PIO_P_SODR_P26(value)                 (PIO_P_SODR_P26_Msk & (_UINT32_(value) << PIO_P_SODR_P26_Pos)) /* Assigment of value for P26 in the PIO_P_SODR register */
#define PIO_P_SODR_P27_Pos                    _UINT32_(27)                                         /* (PIO_P_SODR) Set Output Data Position */
#define PIO_P_SODR_P27_Msk                    (_UINT32_(0x1) << PIO_P_SODR_P27_Pos)                /* (PIO_P_SODR) Set Output Data Mask */
#define PIO_P_SODR_P27(value)                 (PIO_P_SODR_P27_Msk & (_UINT32_(value) << PIO_P_SODR_P27_Pos)) /* Assigment of value for P27 in the PIO_P_SODR register */
#define PIO_P_SODR_P28_Pos                    _UINT32_(28)                                         /* (PIO_P_SODR) Set Output Data Position */
#define PIO_P_SODR_P28_Msk                    (_UINT32_(0x1) << PIO_P_SODR_P28_Pos)                /* (PIO_P_SODR) Set Output Data Mask */
#define PIO_P_SODR_P28(value)                 (PIO_P_SODR_P28_Msk & (_UINT32_(value) << PIO_P_SODR_P28_Pos)) /* Assigment of value for P28 in the PIO_P_SODR register */
#define PIO_P_SODR_P29_Pos                    _UINT32_(29)                                         /* (PIO_P_SODR) Set Output Data Position */
#define PIO_P_SODR_P29_Msk                    (_UINT32_(0x1) << PIO_P_SODR_P29_Pos)                /* (PIO_P_SODR) Set Output Data Mask */
#define PIO_P_SODR_P29(value)                 (PIO_P_SODR_P29_Msk & (_UINT32_(value) << PIO_P_SODR_P29_Pos)) /* Assigment of value for P29 in the PIO_P_SODR register */
#define PIO_P_SODR_P30_Pos                    _UINT32_(30)                                         /* (PIO_P_SODR) Set Output Data Position */
#define PIO_P_SODR_P30_Msk                    (_UINT32_(0x1) << PIO_P_SODR_P30_Pos)                /* (PIO_P_SODR) Set Output Data Mask */
#define PIO_P_SODR_P30(value)                 (PIO_P_SODR_P30_Msk & (_UINT32_(value) << PIO_P_SODR_P30_Pos)) /* Assigment of value for P30 in the PIO_P_SODR register */
#define PIO_P_SODR_P31_Pos                    _UINT32_(31)                                         /* (PIO_P_SODR) Set Output Data Position */
#define PIO_P_SODR_P31_Msk                    (_UINT32_(0x1) << PIO_P_SODR_P31_Pos)                /* (PIO_P_SODR) Set Output Data Mask */
#define PIO_P_SODR_P31(value)                 (PIO_P_SODR_P31_Msk & (_UINT32_(value) << PIO_P_SODR_P31_Pos)) /* Assigment of value for P31 in the PIO_P_SODR register */
#define PIO_P_SODR_Msk                        _UINT32_(0xFFFFFFFF)                                 /* (PIO_P_SODR) Register Mask  */

#define PIO_P_SODR_P_Pos                      _UINT32_(0)                                          /* (PIO_P_SODR Position) Set Output Data */
#define PIO_P_SODR_P_Msk                      (_UINT32_(0xFFFFFFFF) << PIO_P_SODR_P_Pos)           /* (PIO_P_SODR Mask) P */
#define PIO_P_SODR_P(value)                   (PIO_P_SODR_P_Msk & (_UINT32_(value) << PIO_P_SODR_P_Pos)) 

/* -------- PIO_P_CODR : (PIO Offset: 0x14) ( /W 32) PIO Privilege Clear Output Data Register (p_iogroup = 0) -------- */
#define PIO_P_CODR_P0_Pos                     _UINT32_(0)                                          /* (PIO_P_CODR) Clear Output Data Position */
#define PIO_P_CODR_P0_Msk                     (_UINT32_(0x1) << PIO_P_CODR_P0_Pos)                 /* (PIO_P_CODR) Clear Output Data Mask */
#define PIO_P_CODR_P0(value)                  (PIO_P_CODR_P0_Msk & (_UINT32_(value) << PIO_P_CODR_P0_Pos)) /* Assigment of value for P0 in the PIO_P_CODR register */
#define PIO_P_CODR_P1_Pos                     _UINT32_(1)                                          /* (PIO_P_CODR) Clear Output Data Position */
#define PIO_P_CODR_P1_Msk                     (_UINT32_(0x1) << PIO_P_CODR_P1_Pos)                 /* (PIO_P_CODR) Clear Output Data Mask */
#define PIO_P_CODR_P1(value)                  (PIO_P_CODR_P1_Msk & (_UINT32_(value) << PIO_P_CODR_P1_Pos)) /* Assigment of value for P1 in the PIO_P_CODR register */
#define PIO_P_CODR_P2_Pos                     _UINT32_(2)                                          /* (PIO_P_CODR) Clear Output Data Position */
#define PIO_P_CODR_P2_Msk                     (_UINT32_(0x1) << PIO_P_CODR_P2_Pos)                 /* (PIO_P_CODR) Clear Output Data Mask */
#define PIO_P_CODR_P2(value)                  (PIO_P_CODR_P2_Msk & (_UINT32_(value) << PIO_P_CODR_P2_Pos)) /* Assigment of value for P2 in the PIO_P_CODR register */
#define PIO_P_CODR_P3_Pos                     _UINT32_(3)                                          /* (PIO_P_CODR) Clear Output Data Position */
#define PIO_P_CODR_P3_Msk                     (_UINT32_(0x1) << PIO_P_CODR_P3_Pos)                 /* (PIO_P_CODR) Clear Output Data Mask */
#define PIO_P_CODR_P3(value)                  (PIO_P_CODR_P3_Msk & (_UINT32_(value) << PIO_P_CODR_P3_Pos)) /* Assigment of value for P3 in the PIO_P_CODR register */
#define PIO_P_CODR_P4_Pos                     _UINT32_(4)                                          /* (PIO_P_CODR) Clear Output Data Position */
#define PIO_P_CODR_P4_Msk                     (_UINT32_(0x1) << PIO_P_CODR_P4_Pos)                 /* (PIO_P_CODR) Clear Output Data Mask */
#define PIO_P_CODR_P4(value)                  (PIO_P_CODR_P4_Msk & (_UINT32_(value) << PIO_P_CODR_P4_Pos)) /* Assigment of value for P4 in the PIO_P_CODR register */
#define PIO_P_CODR_P5_Pos                     _UINT32_(5)                                          /* (PIO_P_CODR) Clear Output Data Position */
#define PIO_P_CODR_P5_Msk                     (_UINT32_(0x1) << PIO_P_CODR_P5_Pos)                 /* (PIO_P_CODR) Clear Output Data Mask */
#define PIO_P_CODR_P5(value)                  (PIO_P_CODR_P5_Msk & (_UINT32_(value) << PIO_P_CODR_P5_Pos)) /* Assigment of value for P5 in the PIO_P_CODR register */
#define PIO_P_CODR_P6_Pos                     _UINT32_(6)                                          /* (PIO_P_CODR) Clear Output Data Position */
#define PIO_P_CODR_P6_Msk                     (_UINT32_(0x1) << PIO_P_CODR_P6_Pos)                 /* (PIO_P_CODR) Clear Output Data Mask */
#define PIO_P_CODR_P6(value)                  (PIO_P_CODR_P6_Msk & (_UINT32_(value) << PIO_P_CODR_P6_Pos)) /* Assigment of value for P6 in the PIO_P_CODR register */
#define PIO_P_CODR_P7_Pos                     _UINT32_(7)                                          /* (PIO_P_CODR) Clear Output Data Position */
#define PIO_P_CODR_P7_Msk                     (_UINT32_(0x1) << PIO_P_CODR_P7_Pos)                 /* (PIO_P_CODR) Clear Output Data Mask */
#define PIO_P_CODR_P7(value)                  (PIO_P_CODR_P7_Msk & (_UINT32_(value) << PIO_P_CODR_P7_Pos)) /* Assigment of value for P7 in the PIO_P_CODR register */
#define PIO_P_CODR_P8_Pos                     _UINT32_(8)                                          /* (PIO_P_CODR) Clear Output Data Position */
#define PIO_P_CODR_P8_Msk                     (_UINT32_(0x1) << PIO_P_CODR_P8_Pos)                 /* (PIO_P_CODR) Clear Output Data Mask */
#define PIO_P_CODR_P8(value)                  (PIO_P_CODR_P8_Msk & (_UINT32_(value) << PIO_P_CODR_P8_Pos)) /* Assigment of value for P8 in the PIO_P_CODR register */
#define PIO_P_CODR_P9_Pos                     _UINT32_(9)                                          /* (PIO_P_CODR) Clear Output Data Position */
#define PIO_P_CODR_P9_Msk                     (_UINT32_(0x1) << PIO_P_CODR_P9_Pos)                 /* (PIO_P_CODR) Clear Output Data Mask */
#define PIO_P_CODR_P9(value)                  (PIO_P_CODR_P9_Msk & (_UINT32_(value) << PIO_P_CODR_P9_Pos)) /* Assigment of value for P9 in the PIO_P_CODR register */
#define PIO_P_CODR_P10_Pos                    _UINT32_(10)                                         /* (PIO_P_CODR) Clear Output Data Position */
#define PIO_P_CODR_P10_Msk                    (_UINT32_(0x1) << PIO_P_CODR_P10_Pos)                /* (PIO_P_CODR) Clear Output Data Mask */
#define PIO_P_CODR_P10(value)                 (PIO_P_CODR_P10_Msk & (_UINT32_(value) << PIO_P_CODR_P10_Pos)) /* Assigment of value for P10 in the PIO_P_CODR register */
#define PIO_P_CODR_P11_Pos                    _UINT32_(11)                                         /* (PIO_P_CODR) Clear Output Data Position */
#define PIO_P_CODR_P11_Msk                    (_UINT32_(0x1) << PIO_P_CODR_P11_Pos)                /* (PIO_P_CODR) Clear Output Data Mask */
#define PIO_P_CODR_P11(value)                 (PIO_P_CODR_P11_Msk & (_UINT32_(value) << PIO_P_CODR_P11_Pos)) /* Assigment of value for P11 in the PIO_P_CODR register */
#define PIO_P_CODR_P12_Pos                    _UINT32_(12)                                         /* (PIO_P_CODR) Clear Output Data Position */
#define PIO_P_CODR_P12_Msk                    (_UINT32_(0x1) << PIO_P_CODR_P12_Pos)                /* (PIO_P_CODR) Clear Output Data Mask */
#define PIO_P_CODR_P12(value)                 (PIO_P_CODR_P12_Msk & (_UINT32_(value) << PIO_P_CODR_P12_Pos)) /* Assigment of value for P12 in the PIO_P_CODR register */
#define PIO_P_CODR_P13_Pos                    _UINT32_(13)                                         /* (PIO_P_CODR) Clear Output Data Position */
#define PIO_P_CODR_P13_Msk                    (_UINT32_(0x1) << PIO_P_CODR_P13_Pos)                /* (PIO_P_CODR) Clear Output Data Mask */
#define PIO_P_CODR_P13(value)                 (PIO_P_CODR_P13_Msk & (_UINT32_(value) << PIO_P_CODR_P13_Pos)) /* Assigment of value for P13 in the PIO_P_CODR register */
#define PIO_P_CODR_P14_Pos                    _UINT32_(14)                                         /* (PIO_P_CODR) Clear Output Data Position */
#define PIO_P_CODR_P14_Msk                    (_UINT32_(0x1) << PIO_P_CODR_P14_Pos)                /* (PIO_P_CODR) Clear Output Data Mask */
#define PIO_P_CODR_P14(value)                 (PIO_P_CODR_P14_Msk & (_UINT32_(value) << PIO_P_CODR_P14_Pos)) /* Assigment of value for P14 in the PIO_P_CODR register */
#define PIO_P_CODR_P15_Pos                    _UINT32_(15)                                         /* (PIO_P_CODR) Clear Output Data Position */
#define PIO_P_CODR_P15_Msk                    (_UINT32_(0x1) << PIO_P_CODR_P15_Pos)                /* (PIO_P_CODR) Clear Output Data Mask */
#define PIO_P_CODR_P15(value)                 (PIO_P_CODR_P15_Msk & (_UINT32_(value) << PIO_P_CODR_P15_Pos)) /* Assigment of value for P15 in the PIO_P_CODR register */
#define PIO_P_CODR_P16_Pos                    _UINT32_(16)                                         /* (PIO_P_CODR) Clear Output Data Position */
#define PIO_P_CODR_P16_Msk                    (_UINT32_(0x1) << PIO_P_CODR_P16_Pos)                /* (PIO_P_CODR) Clear Output Data Mask */
#define PIO_P_CODR_P16(value)                 (PIO_P_CODR_P16_Msk & (_UINT32_(value) << PIO_P_CODR_P16_Pos)) /* Assigment of value for P16 in the PIO_P_CODR register */
#define PIO_P_CODR_P17_Pos                    _UINT32_(17)                                         /* (PIO_P_CODR) Clear Output Data Position */
#define PIO_P_CODR_P17_Msk                    (_UINT32_(0x1) << PIO_P_CODR_P17_Pos)                /* (PIO_P_CODR) Clear Output Data Mask */
#define PIO_P_CODR_P17(value)                 (PIO_P_CODR_P17_Msk & (_UINT32_(value) << PIO_P_CODR_P17_Pos)) /* Assigment of value for P17 in the PIO_P_CODR register */
#define PIO_P_CODR_P18_Pos                    _UINT32_(18)                                         /* (PIO_P_CODR) Clear Output Data Position */
#define PIO_P_CODR_P18_Msk                    (_UINT32_(0x1) << PIO_P_CODR_P18_Pos)                /* (PIO_P_CODR) Clear Output Data Mask */
#define PIO_P_CODR_P18(value)                 (PIO_P_CODR_P18_Msk & (_UINT32_(value) << PIO_P_CODR_P18_Pos)) /* Assigment of value for P18 in the PIO_P_CODR register */
#define PIO_P_CODR_P19_Pos                    _UINT32_(19)                                         /* (PIO_P_CODR) Clear Output Data Position */
#define PIO_P_CODR_P19_Msk                    (_UINT32_(0x1) << PIO_P_CODR_P19_Pos)                /* (PIO_P_CODR) Clear Output Data Mask */
#define PIO_P_CODR_P19(value)                 (PIO_P_CODR_P19_Msk & (_UINT32_(value) << PIO_P_CODR_P19_Pos)) /* Assigment of value for P19 in the PIO_P_CODR register */
#define PIO_P_CODR_P20_Pos                    _UINT32_(20)                                         /* (PIO_P_CODR) Clear Output Data Position */
#define PIO_P_CODR_P20_Msk                    (_UINT32_(0x1) << PIO_P_CODR_P20_Pos)                /* (PIO_P_CODR) Clear Output Data Mask */
#define PIO_P_CODR_P20(value)                 (PIO_P_CODR_P20_Msk & (_UINT32_(value) << PIO_P_CODR_P20_Pos)) /* Assigment of value for P20 in the PIO_P_CODR register */
#define PIO_P_CODR_P21_Pos                    _UINT32_(21)                                         /* (PIO_P_CODR) Clear Output Data Position */
#define PIO_P_CODR_P21_Msk                    (_UINT32_(0x1) << PIO_P_CODR_P21_Pos)                /* (PIO_P_CODR) Clear Output Data Mask */
#define PIO_P_CODR_P21(value)                 (PIO_P_CODR_P21_Msk & (_UINT32_(value) << PIO_P_CODR_P21_Pos)) /* Assigment of value for P21 in the PIO_P_CODR register */
#define PIO_P_CODR_P22_Pos                    _UINT32_(22)                                         /* (PIO_P_CODR) Clear Output Data Position */
#define PIO_P_CODR_P22_Msk                    (_UINT32_(0x1) << PIO_P_CODR_P22_Pos)                /* (PIO_P_CODR) Clear Output Data Mask */
#define PIO_P_CODR_P22(value)                 (PIO_P_CODR_P22_Msk & (_UINT32_(value) << PIO_P_CODR_P22_Pos)) /* Assigment of value for P22 in the PIO_P_CODR register */
#define PIO_P_CODR_P23_Pos                    _UINT32_(23)                                         /* (PIO_P_CODR) Clear Output Data Position */
#define PIO_P_CODR_P23_Msk                    (_UINT32_(0x1) << PIO_P_CODR_P23_Pos)                /* (PIO_P_CODR) Clear Output Data Mask */
#define PIO_P_CODR_P23(value)                 (PIO_P_CODR_P23_Msk & (_UINT32_(value) << PIO_P_CODR_P23_Pos)) /* Assigment of value for P23 in the PIO_P_CODR register */
#define PIO_P_CODR_P24_Pos                    _UINT32_(24)                                         /* (PIO_P_CODR) Clear Output Data Position */
#define PIO_P_CODR_P24_Msk                    (_UINT32_(0x1) << PIO_P_CODR_P24_Pos)                /* (PIO_P_CODR) Clear Output Data Mask */
#define PIO_P_CODR_P24(value)                 (PIO_P_CODR_P24_Msk & (_UINT32_(value) << PIO_P_CODR_P24_Pos)) /* Assigment of value for P24 in the PIO_P_CODR register */
#define PIO_P_CODR_P25_Pos                    _UINT32_(25)                                         /* (PIO_P_CODR) Clear Output Data Position */
#define PIO_P_CODR_P25_Msk                    (_UINT32_(0x1) << PIO_P_CODR_P25_Pos)                /* (PIO_P_CODR) Clear Output Data Mask */
#define PIO_P_CODR_P25(value)                 (PIO_P_CODR_P25_Msk & (_UINT32_(value) << PIO_P_CODR_P25_Pos)) /* Assigment of value for P25 in the PIO_P_CODR register */
#define PIO_P_CODR_P26_Pos                    _UINT32_(26)                                         /* (PIO_P_CODR) Clear Output Data Position */
#define PIO_P_CODR_P26_Msk                    (_UINT32_(0x1) << PIO_P_CODR_P26_Pos)                /* (PIO_P_CODR) Clear Output Data Mask */
#define PIO_P_CODR_P26(value)                 (PIO_P_CODR_P26_Msk & (_UINT32_(value) << PIO_P_CODR_P26_Pos)) /* Assigment of value for P26 in the PIO_P_CODR register */
#define PIO_P_CODR_P27_Pos                    _UINT32_(27)                                         /* (PIO_P_CODR) Clear Output Data Position */
#define PIO_P_CODR_P27_Msk                    (_UINT32_(0x1) << PIO_P_CODR_P27_Pos)                /* (PIO_P_CODR) Clear Output Data Mask */
#define PIO_P_CODR_P27(value)                 (PIO_P_CODR_P27_Msk & (_UINT32_(value) << PIO_P_CODR_P27_Pos)) /* Assigment of value for P27 in the PIO_P_CODR register */
#define PIO_P_CODR_P28_Pos                    _UINT32_(28)                                         /* (PIO_P_CODR) Clear Output Data Position */
#define PIO_P_CODR_P28_Msk                    (_UINT32_(0x1) << PIO_P_CODR_P28_Pos)                /* (PIO_P_CODR) Clear Output Data Mask */
#define PIO_P_CODR_P28(value)                 (PIO_P_CODR_P28_Msk & (_UINT32_(value) << PIO_P_CODR_P28_Pos)) /* Assigment of value for P28 in the PIO_P_CODR register */
#define PIO_P_CODR_P29_Pos                    _UINT32_(29)                                         /* (PIO_P_CODR) Clear Output Data Position */
#define PIO_P_CODR_P29_Msk                    (_UINT32_(0x1) << PIO_P_CODR_P29_Pos)                /* (PIO_P_CODR) Clear Output Data Mask */
#define PIO_P_CODR_P29(value)                 (PIO_P_CODR_P29_Msk & (_UINT32_(value) << PIO_P_CODR_P29_Pos)) /* Assigment of value for P29 in the PIO_P_CODR register */
#define PIO_P_CODR_P30_Pos                    _UINT32_(30)                                         /* (PIO_P_CODR) Clear Output Data Position */
#define PIO_P_CODR_P30_Msk                    (_UINT32_(0x1) << PIO_P_CODR_P30_Pos)                /* (PIO_P_CODR) Clear Output Data Mask */
#define PIO_P_CODR_P30(value)                 (PIO_P_CODR_P30_Msk & (_UINT32_(value) << PIO_P_CODR_P30_Pos)) /* Assigment of value for P30 in the PIO_P_CODR register */
#define PIO_P_CODR_P31_Pos                    _UINT32_(31)                                         /* (PIO_P_CODR) Clear Output Data Position */
#define PIO_P_CODR_P31_Msk                    (_UINT32_(0x1) << PIO_P_CODR_P31_Pos)                /* (PIO_P_CODR) Clear Output Data Mask */
#define PIO_P_CODR_P31(value)                 (PIO_P_CODR_P31_Msk & (_UINT32_(value) << PIO_P_CODR_P31_Pos)) /* Assigment of value for P31 in the PIO_P_CODR register */
#define PIO_P_CODR_Msk                        _UINT32_(0xFFFFFFFF)                                 /* (PIO_P_CODR) Register Mask  */

#define PIO_P_CODR_P_Pos                      _UINT32_(0)                                          /* (PIO_P_CODR Position) Clear Output Data */
#define PIO_P_CODR_P_Msk                      (_UINT32_(0xFFFFFFFF) << PIO_P_CODR_P_Pos)           /* (PIO_P_CODR Mask) P */
#define PIO_P_CODR_P(value)                   (PIO_P_CODR_P_Msk & (_UINT32_(value) << PIO_P_CODR_P_Pos)) 

/* -------- PIO_P_ODSR : (PIO Offset: 0x18) (R/W 32) PIO Privilege Output Data Status Register (p_iogroup = 0) -------- */
#define PIO_P_ODSR_P0_Pos                     _UINT32_(0)                                          /* (PIO_P_ODSR) Output Data Status Position */
#define PIO_P_ODSR_P0_Msk                     (_UINT32_(0x1) << PIO_P_ODSR_P0_Pos)                 /* (PIO_P_ODSR) Output Data Status Mask */
#define PIO_P_ODSR_P0(value)                  (PIO_P_ODSR_P0_Msk & (_UINT32_(value) << PIO_P_ODSR_P0_Pos)) /* Assigment of value for P0 in the PIO_P_ODSR register */
#define PIO_P_ODSR_P1_Pos                     _UINT32_(1)                                          /* (PIO_P_ODSR) Output Data Status Position */
#define PIO_P_ODSR_P1_Msk                     (_UINT32_(0x1) << PIO_P_ODSR_P1_Pos)                 /* (PIO_P_ODSR) Output Data Status Mask */
#define PIO_P_ODSR_P1(value)                  (PIO_P_ODSR_P1_Msk & (_UINT32_(value) << PIO_P_ODSR_P1_Pos)) /* Assigment of value for P1 in the PIO_P_ODSR register */
#define PIO_P_ODSR_P2_Pos                     _UINT32_(2)                                          /* (PIO_P_ODSR) Output Data Status Position */
#define PIO_P_ODSR_P2_Msk                     (_UINT32_(0x1) << PIO_P_ODSR_P2_Pos)                 /* (PIO_P_ODSR) Output Data Status Mask */
#define PIO_P_ODSR_P2(value)                  (PIO_P_ODSR_P2_Msk & (_UINT32_(value) << PIO_P_ODSR_P2_Pos)) /* Assigment of value for P2 in the PIO_P_ODSR register */
#define PIO_P_ODSR_P3_Pos                     _UINT32_(3)                                          /* (PIO_P_ODSR) Output Data Status Position */
#define PIO_P_ODSR_P3_Msk                     (_UINT32_(0x1) << PIO_P_ODSR_P3_Pos)                 /* (PIO_P_ODSR) Output Data Status Mask */
#define PIO_P_ODSR_P3(value)                  (PIO_P_ODSR_P3_Msk & (_UINT32_(value) << PIO_P_ODSR_P3_Pos)) /* Assigment of value for P3 in the PIO_P_ODSR register */
#define PIO_P_ODSR_P4_Pos                     _UINT32_(4)                                          /* (PIO_P_ODSR) Output Data Status Position */
#define PIO_P_ODSR_P4_Msk                     (_UINT32_(0x1) << PIO_P_ODSR_P4_Pos)                 /* (PIO_P_ODSR) Output Data Status Mask */
#define PIO_P_ODSR_P4(value)                  (PIO_P_ODSR_P4_Msk & (_UINT32_(value) << PIO_P_ODSR_P4_Pos)) /* Assigment of value for P4 in the PIO_P_ODSR register */
#define PIO_P_ODSR_P5_Pos                     _UINT32_(5)                                          /* (PIO_P_ODSR) Output Data Status Position */
#define PIO_P_ODSR_P5_Msk                     (_UINT32_(0x1) << PIO_P_ODSR_P5_Pos)                 /* (PIO_P_ODSR) Output Data Status Mask */
#define PIO_P_ODSR_P5(value)                  (PIO_P_ODSR_P5_Msk & (_UINT32_(value) << PIO_P_ODSR_P5_Pos)) /* Assigment of value for P5 in the PIO_P_ODSR register */
#define PIO_P_ODSR_P6_Pos                     _UINT32_(6)                                          /* (PIO_P_ODSR) Output Data Status Position */
#define PIO_P_ODSR_P6_Msk                     (_UINT32_(0x1) << PIO_P_ODSR_P6_Pos)                 /* (PIO_P_ODSR) Output Data Status Mask */
#define PIO_P_ODSR_P6(value)                  (PIO_P_ODSR_P6_Msk & (_UINT32_(value) << PIO_P_ODSR_P6_Pos)) /* Assigment of value for P6 in the PIO_P_ODSR register */
#define PIO_P_ODSR_P7_Pos                     _UINT32_(7)                                          /* (PIO_P_ODSR) Output Data Status Position */
#define PIO_P_ODSR_P7_Msk                     (_UINT32_(0x1) << PIO_P_ODSR_P7_Pos)                 /* (PIO_P_ODSR) Output Data Status Mask */
#define PIO_P_ODSR_P7(value)                  (PIO_P_ODSR_P7_Msk & (_UINT32_(value) << PIO_P_ODSR_P7_Pos)) /* Assigment of value for P7 in the PIO_P_ODSR register */
#define PIO_P_ODSR_P8_Pos                     _UINT32_(8)                                          /* (PIO_P_ODSR) Output Data Status Position */
#define PIO_P_ODSR_P8_Msk                     (_UINT32_(0x1) << PIO_P_ODSR_P8_Pos)                 /* (PIO_P_ODSR) Output Data Status Mask */
#define PIO_P_ODSR_P8(value)                  (PIO_P_ODSR_P8_Msk & (_UINT32_(value) << PIO_P_ODSR_P8_Pos)) /* Assigment of value for P8 in the PIO_P_ODSR register */
#define PIO_P_ODSR_P9_Pos                     _UINT32_(9)                                          /* (PIO_P_ODSR) Output Data Status Position */
#define PIO_P_ODSR_P9_Msk                     (_UINT32_(0x1) << PIO_P_ODSR_P9_Pos)                 /* (PIO_P_ODSR) Output Data Status Mask */
#define PIO_P_ODSR_P9(value)                  (PIO_P_ODSR_P9_Msk & (_UINT32_(value) << PIO_P_ODSR_P9_Pos)) /* Assigment of value for P9 in the PIO_P_ODSR register */
#define PIO_P_ODSR_P10_Pos                    _UINT32_(10)                                         /* (PIO_P_ODSR) Output Data Status Position */
#define PIO_P_ODSR_P10_Msk                    (_UINT32_(0x1) << PIO_P_ODSR_P10_Pos)                /* (PIO_P_ODSR) Output Data Status Mask */
#define PIO_P_ODSR_P10(value)                 (PIO_P_ODSR_P10_Msk & (_UINT32_(value) << PIO_P_ODSR_P10_Pos)) /* Assigment of value for P10 in the PIO_P_ODSR register */
#define PIO_P_ODSR_P11_Pos                    _UINT32_(11)                                         /* (PIO_P_ODSR) Output Data Status Position */
#define PIO_P_ODSR_P11_Msk                    (_UINT32_(0x1) << PIO_P_ODSR_P11_Pos)                /* (PIO_P_ODSR) Output Data Status Mask */
#define PIO_P_ODSR_P11(value)                 (PIO_P_ODSR_P11_Msk & (_UINT32_(value) << PIO_P_ODSR_P11_Pos)) /* Assigment of value for P11 in the PIO_P_ODSR register */
#define PIO_P_ODSR_P12_Pos                    _UINT32_(12)                                         /* (PIO_P_ODSR) Output Data Status Position */
#define PIO_P_ODSR_P12_Msk                    (_UINT32_(0x1) << PIO_P_ODSR_P12_Pos)                /* (PIO_P_ODSR) Output Data Status Mask */
#define PIO_P_ODSR_P12(value)                 (PIO_P_ODSR_P12_Msk & (_UINT32_(value) << PIO_P_ODSR_P12_Pos)) /* Assigment of value for P12 in the PIO_P_ODSR register */
#define PIO_P_ODSR_P13_Pos                    _UINT32_(13)                                         /* (PIO_P_ODSR) Output Data Status Position */
#define PIO_P_ODSR_P13_Msk                    (_UINT32_(0x1) << PIO_P_ODSR_P13_Pos)                /* (PIO_P_ODSR) Output Data Status Mask */
#define PIO_P_ODSR_P13(value)                 (PIO_P_ODSR_P13_Msk & (_UINT32_(value) << PIO_P_ODSR_P13_Pos)) /* Assigment of value for P13 in the PIO_P_ODSR register */
#define PIO_P_ODSR_P14_Pos                    _UINT32_(14)                                         /* (PIO_P_ODSR) Output Data Status Position */
#define PIO_P_ODSR_P14_Msk                    (_UINT32_(0x1) << PIO_P_ODSR_P14_Pos)                /* (PIO_P_ODSR) Output Data Status Mask */
#define PIO_P_ODSR_P14(value)                 (PIO_P_ODSR_P14_Msk & (_UINT32_(value) << PIO_P_ODSR_P14_Pos)) /* Assigment of value for P14 in the PIO_P_ODSR register */
#define PIO_P_ODSR_P15_Pos                    _UINT32_(15)                                         /* (PIO_P_ODSR) Output Data Status Position */
#define PIO_P_ODSR_P15_Msk                    (_UINT32_(0x1) << PIO_P_ODSR_P15_Pos)                /* (PIO_P_ODSR) Output Data Status Mask */
#define PIO_P_ODSR_P15(value)                 (PIO_P_ODSR_P15_Msk & (_UINT32_(value) << PIO_P_ODSR_P15_Pos)) /* Assigment of value for P15 in the PIO_P_ODSR register */
#define PIO_P_ODSR_P16_Pos                    _UINT32_(16)                                         /* (PIO_P_ODSR) Output Data Status Position */
#define PIO_P_ODSR_P16_Msk                    (_UINT32_(0x1) << PIO_P_ODSR_P16_Pos)                /* (PIO_P_ODSR) Output Data Status Mask */
#define PIO_P_ODSR_P16(value)                 (PIO_P_ODSR_P16_Msk & (_UINT32_(value) << PIO_P_ODSR_P16_Pos)) /* Assigment of value for P16 in the PIO_P_ODSR register */
#define PIO_P_ODSR_P17_Pos                    _UINT32_(17)                                         /* (PIO_P_ODSR) Output Data Status Position */
#define PIO_P_ODSR_P17_Msk                    (_UINT32_(0x1) << PIO_P_ODSR_P17_Pos)                /* (PIO_P_ODSR) Output Data Status Mask */
#define PIO_P_ODSR_P17(value)                 (PIO_P_ODSR_P17_Msk & (_UINT32_(value) << PIO_P_ODSR_P17_Pos)) /* Assigment of value for P17 in the PIO_P_ODSR register */
#define PIO_P_ODSR_P18_Pos                    _UINT32_(18)                                         /* (PIO_P_ODSR) Output Data Status Position */
#define PIO_P_ODSR_P18_Msk                    (_UINT32_(0x1) << PIO_P_ODSR_P18_Pos)                /* (PIO_P_ODSR) Output Data Status Mask */
#define PIO_P_ODSR_P18(value)                 (PIO_P_ODSR_P18_Msk & (_UINT32_(value) << PIO_P_ODSR_P18_Pos)) /* Assigment of value for P18 in the PIO_P_ODSR register */
#define PIO_P_ODSR_P19_Pos                    _UINT32_(19)                                         /* (PIO_P_ODSR) Output Data Status Position */
#define PIO_P_ODSR_P19_Msk                    (_UINT32_(0x1) << PIO_P_ODSR_P19_Pos)                /* (PIO_P_ODSR) Output Data Status Mask */
#define PIO_P_ODSR_P19(value)                 (PIO_P_ODSR_P19_Msk & (_UINT32_(value) << PIO_P_ODSR_P19_Pos)) /* Assigment of value for P19 in the PIO_P_ODSR register */
#define PIO_P_ODSR_P20_Pos                    _UINT32_(20)                                         /* (PIO_P_ODSR) Output Data Status Position */
#define PIO_P_ODSR_P20_Msk                    (_UINT32_(0x1) << PIO_P_ODSR_P20_Pos)                /* (PIO_P_ODSR) Output Data Status Mask */
#define PIO_P_ODSR_P20(value)                 (PIO_P_ODSR_P20_Msk & (_UINT32_(value) << PIO_P_ODSR_P20_Pos)) /* Assigment of value for P20 in the PIO_P_ODSR register */
#define PIO_P_ODSR_P21_Pos                    _UINT32_(21)                                         /* (PIO_P_ODSR) Output Data Status Position */
#define PIO_P_ODSR_P21_Msk                    (_UINT32_(0x1) << PIO_P_ODSR_P21_Pos)                /* (PIO_P_ODSR) Output Data Status Mask */
#define PIO_P_ODSR_P21(value)                 (PIO_P_ODSR_P21_Msk & (_UINT32_(value) << PIO_P_ODSR_P21_Pos)) /* Assigment of value for P21 in the PIO_P_ODSR register */
#define PIO_P_ODSR_P22_Pos                    _UINT32_(22)                                         /* (PIO_P_ODSR) Output Data Status Position */
#define PIO_P_ODSR_P22_Msk                    (_UINT32_(0x1) << PIO_P_ODSR_P22_Pos)                /* (PIO_P_ODSR) Output Data Status Mask */
#define PIO_P_ODSR_P22(value)                 (PIO_P_ODSR_P22_Msk & (_UINT32_(value) << PIO_P_ODSR_P22_Pos)) /* Assigment of value for P22 in the PIO_P_ODSR register */
#define PIO_P_ODSR_P23_Pos                    _UINT32_(23)                                         /* (PIO_P_ODSR) Output Data Status Position */
#define PIO_P_ODSR_P23_Msk                    (_UINT32_(0x1) << PIO_P_ODSR_P23_Pos)                /* (PIO_P_ODSR) Output Data Status Mask */
#define PIO_P_ODSR_P23(value)                 (PIO_P_ODSR_P23_Msk & (_UINT32_(value) << PIO_P_ODSR_P23_Pos)) /* Assigment of value for P23 in the PIO_P_ODSR register */
#define PIO_P_ODSR_P24_Pos                    _UINT32_(24)                                         /* (PIO_P_ODSR) Output Data Status Position */
#define PIO_P_ODSR_P24_Msk                    (_UINT32_(0x1) << PIO_P_ODSR_P24_Pos)                /* (PIO_P_ODSR) Output Data Status Mask */
#define PIO_P_ODSR_P24(value)                 (PIO_P_ODSR_P24_Msk & (_UINT32_(value) << PIO_P_ODSR_P24_Pos)) /* Assigment of value for P24 in the PIO_P_ODSR register */
#define PIO_P_ODSR_P25_Pos                    _UINT32_(25)                                         /* (PIO_P_ODSR) Output Data Status Position */
#define PIO_P_ODSR_P25_Msk                    (_UINT32_(0x1) << PIO_P_ODSR_P25_Pos)                /* (PIO_P_ODSR) Output Data Status Mask */
#define PIO_P_ODSR_P25(value)                 (PIO_P_ODSR_P25_Msk & (_UINT32_(value) << PIO_P_ODSR_P25_Pos)) /* Assigment of value for P25 in the PIO_P_ODSR register */
#define PIO_P_ODSR_P26_Pos                    _UINT32_(26)                                         /* (PIO_P_ODSR) Output Data Status Position */
#define PIO_P_ODSR_P26_Msk                    (_UINT32_(0x1) << PIO_P_ODSR_P26_Pos)                /* (PIO_P_ODSR) Output Data Status Mask */
#define PIO_P_ODSR_P26(value)                 (PIO_P_ODSR_P26_Msk & (_UINT32_(value) << PIO_P_ODSR_P26_Pos)) /* Assigment of value for P26 in the PIO_P_ODSR register */
#define PIO_P_ODSR_P27_Pos                    _UINT32_(27)                                         /* (PIO_P_ODSR) Output Data Status Position */
#define PIO_P_ODSR_P27_Msk                    (_UINT32_(0x1) << PIO_P_ODSR_P27_Pos)                /* (PIO_P_ODSR) Output Data Status Mask */
#define PIO_P_ODSR_P27(value)                 (PIO_P_ODSR_P27_Msk & (_UINT32_(value) << PIO_P_ODSR_P27_Pos)) /* Assigment of value for P27 in the PIO_P_ODSR register */
#define PIO_P_ODSR_P28_Pos                    _UINT32_(28)                                         /* (PIO_P_ODSR) Output Data Status Position */
#define PIO_P_ODSR_P28_Msk                    (_UINT32_(0x1) << PIO_P_ODSR_P28_Pos)                /* (PIO_P_ODSR) Output Data Status Mask */
#define PIO_P_ODSR_P28(value)                 (PIO_P_ODSR_P28_Msk & (_UINT32_(value) << PIO_P_ODSR_P28_Pos)) /* Assigment of value for P28 in the PIO_P_ODSR register */
#define PIO_P_ODSR_P29_Pos                    _UINT32_(29)                                         /* (PIO_P_ODSR) Output Data Status Position */
#define PIO_P_ODSR_P29_Msk                    (_UINT32_(0x1) << PIO_P_ODSR_P29_Pos)                /* (PIO_P_ODSR) Output Data Status Mask */
#define PIO_P_ODSR_P29(value)                 (PIO_P_ODSR_P29_Msk & (_UINT32_(value) << PIO_P_ODSR_P29_Pos)) /* Assigment of value for P29 in the PIO_P_ODSR register */
#define PIO_P_ODSR_P30_Pos                    _UINT32_(30)                                         /* (PIO_P_ODSR) Output Data Status Position */
#define PIO_P_ODSR_P30_Msk                    (_UINT32_(0x1) << PIO_P_ODSR_P30_Pos)                /* (PIO_P_ODSR) Output Data Status Mask */
#define PIO_P_ODSR_P30(value)                 (PIO_P_ODSR_P30_Msk & (_UINT32_(value) << PIO_P_ODSR_P30_Pos)) /* Assigment of value for P30 in the PIO_P_ODSR register */
#define PIO_P_ODSR_P31_Pos                    _UINT32_(31)                                         /* (PIO_P_ODSR) Output Data Status Position */
#define PIO_P_ODSR_P31_Msk                    (_UINT32_(0x1) << PIO_P_ODSR_P31_Pos)                /* (PIO_P_ODSR) Output Data Status Mask */
#define PIO_P_ODSR_P31(value)                 (PIO_P_ODSR_P31_Msk & (_UINT32_(value) << PIO_P_ODSR_P31_Pos)) /* Assigment of value for P31 in the PIO_P_ODSR register */
#define PIO_P_ODSR_Msk                        _UINT32_(0xFFFFFFFF)                                 /* (PIO_P_ODSR) Register Mask  */

#define PIO_P_ODSR_P_Pos                      _UINT32_(0)                                          /* (PIO_P_ODSR Position) Output Data Status */
#define PIO_P_ODSR_P_Msk                      (_UINT32_(0xFFFFFFFF) << PIO_P_ODSR_P_Pos)           /* (PIO_P_ODSR Mask) P */
#define PIO_P_ODSR_P(value)                   (PIO_P_ODSR_P_Msk & (_UINT32_(value) << PIO_P_ODSR_P_Pos)) 

/* -------- PIO_P_IER : (PIO Offset: 0x20) ( /W 32) PIO Privilege Interrupt Enable Register (p_iogroup = 0) -------- */
#define PIO_P_IER_P0_Pos                      _UINT32_(0)                                          /* (PIO_P_IER) Input Change Interrupt Enable Position */
#define PIO_P_IER_P0_Msk                      (_UINT32_(0x1) << PIO_P_IER_P0_Pos)                  /* (PIO_P_IER) Input Change Interrupt Enable Mask */
#define PIO_P_IER_P0(value)                   (PIO_P_IER_P0_Msk & (_UINT32_(value) << PIO_P_IER_P0_Pos)) /* Assigment of value for P0 in the PIO_P_IER register */
#define PIO_P_IER_P1_Pos                      _UINT32_(1)                                          /* (PIO_P_IER) Input Change Interrupt Enable Position */
#define PIO_P_IER_P1_Msk                      (_UINT32_(0x1) << PIO_P_IER_P1_Pos)                  /* (PIO_P_IER) Input Change Interrupt Enable Mask */
#define PIO_P_IER_P1(value)                   (PIO_P_IER_P1_Msk & (_UINT32_(value) << PIO_P_IER_P1_Pos)) /* Assigment of value for P1 in the PIO_P_IER register */
#define PIO_P_IER_P2_Pos                      _UINT32_(2)                                          /* (PIO_P_IER) Input Change Interrupt Enable Position */
#define PIO_P_IER_P2_Msk                      (_UINT32_(0x1) << PIO_P_IER_P2_Pos)                  /* (PIO_P_IER) Input Change Interrupt Enable Mask */
#define PIO_P_IER_P2(value)                   (PIO_P_IER_P2_Msk & (_UINT32_(value) << PIO_P_IER_P2_Pos)) /* Assigment of value for P2 in the PIO_P_IER register */
#define PIO_P_IER_P3_Pos                      _UINT32_(3)                                          /* (PIO_P_IER) Input Change Interrupt Enable Position */
#define PIO_P_IER_P3_Msk                      (_UINT32_(0x1) << PIO_P_IER_P3_Pos)                  /* (PIO_P_IER) Input Change Interrupt Enable Mask */
#define PIO_P_IER_P3(value)                   (PIO_P_IER_P3_Msk & (_UINT32_(value) << PIO_P_IER_P3_Pos)) /* Assigment of value for P3 in the PIO_P_IER register */
#define PIO_P_IER_P4_Pos                      _UINT32_(4)                                          /* (PIO_P_IER) Input Change Interrupt Enable Position */
#define PIO_P_IER_P4_Msk                      (_UINT32_(0x1) << PIO_P_IER_P4_Pos)                  /* (PIO_P_IER) Input Change Interrupt Enable Mask */
#define PIO_P_IER_P4(value)                   (PIO_P_IER_P4_Msk & (_UINT32_(value) << PIO_P_IER_P4_Pos)) /* Assigment of value for P4 in the PIO_P_IER register */
#define PIO_P_IER_P5_Pos                      _UINT32_(5)                                          /* (PIO_P_IER) Input Change Interrupt Enable Position */
#define PIO_P_IER_P5_Msk                      (_UINT32_(0x1) << PIO_P_IER_P5_Pos)                  /* (PIO_P_IER) Input Change Interrupt Enable Mask */
#define PIO_P_IER_P5(value)                   (PIO_P_IER_P5_Msk & (_UINT32_(value) << PIO_P_IER_P5_Pos)) /* Assigment of value for P5 in the PIO_P_IER register */
#define PIO_P_IER_P6_Pos                      _UINT32_(6)                                          /* (PIO_P_IER) Input Change Interrupt Enable Position */
#define PIO_P_IER_P6_Msk                      (_UINT32_(0x1) << PIO_P_IER_P6_Pos)                  /* (PIO_P_IER) Input Change Interrupt Enable Mask */
#define PIO_P_IER_P6(value)                   (PIO_P_IER_P6_Msk & (_UINT32_(value) << PIO_P_IER_P6_Pos)) /* Assigment of value for P6 in the PIO_P_IER register */
#define PIO_P_IER_P7_Pos                      _UINT32_(7)                                          /* (PIO_P_IER) Input Change Interrupt Enable Position */
#define PIO_P_IER_P7_Msk                      (_UINT32_(0x1) << PIO_P_IER_P7_Pos)                  /* (PIO_P_IER) Input Change Interrupt Enable Mask */
#define PIO_P_IER_P7(value)                   (PIO_P_IER_P7_Msk & (_UINT32_(value) << PIO_P_IER_P7_Pos)) /* Assigment of value for P7 in the PIO_P_IER register */
#define PIO_P_IER_P8_Pos                      _UINT32_(8)                                          /* (PIO_P_IER) Input Change Interrupt Enable Position */
#define PIO_P_IER_P8_Msk                      (_UINT32_(0x1) << PIO_P_IER_P8_Pos)                  /* (PIO_P_IER) Input Change Interrupt Enable Mask */
#define PIO_P_IER_P8(value)                   (PIO_P_IER_P8_Msk & (_UINT32_(value) << PIO_P_IER_P8_Pos)) /* Assigment of value for P8 in the PIO_P_IER register */
#define PIO_P_IER_P9_Pos                      _UINT32_(9)                                          /* (PIO_P_IER) Input Change Interrupt Enable Position */
#define PIO_P_IER_P9_Msk                      (_UINT32_(0x1) << PIO_P_IER_P9_Pos)                  /* (PIO_P_IER) Input Change Interrupt Enable Mask */
#define PIO_P_IER_P9(value)                   (PIO_P_IER_P9_Msk & (_UINT32_(value) << PIO_P_IER_P9_Pos)) /* Assigment of value for P9 in the PIO_P_IER register */
#define PIO_P_IER_P10_Pos                     _UINT32_(10)                                         /* (PIO_P_IER) Input Change Interrupt Enable Position */
#define PIO_P_IER_P10_Msk                     (_UINT32_(0x1) << PIO_P_IER_P10_Pos)                 /* (PIO_P_IER) Input Change Interrupt Enable Mask */
#define PIO_P_IER_P10(value)                  (PIO_P_IER_P10_Msk & (_UINT32_(value) << PIO_P_IER_P10_Pos)) /* Assigment of value for P10 in the PIO_P_IER register */
#define PIO_P_IER_P11_Pos                     _UINT32_(11)                                         /* (PIO_P_IER) Input Change Interrupt Enable Position */
#define PIO_P_IER_P11_Msk                     (_UINT32_(0x1) << PIO_P_IER_P11_Pos)                 /* (PIO_P_IER) Input Change Interrupt Enable Mask */
#define PIO_P_IER_P11(value)                  (PIO_P_IER_P11_Msk & (_UINT32_(value) << PIO_P_IER_P11_Pos)) /* Assigment of value for P11 in the PIO_P_IER register */
#define PIO_P_IER_P12_Pos                     _UINT32_(12)                                         /* (PIO_P_IER) Input Change Interrupt Enable Position */
#define PIO_P_IER_P12_Msk                     (_UINT32_(0x1) << PIO_P_IER_P12_Pos)                 /* (PIO_P_IER) Input Change Interrupt Enable Mask */
#define PIO_P_IER_P12(value)                  (PIO_P_IER_P12_Msk & (_UINT32_(value) << PIO_P_IER_P12_Pos)) /* Assigment of value for P12 in the PIO_P_IER register */
#define PIO_P_IER_P13_Pos                     _UINT32_(13)                                         /* (PIO_P_IER) Input Change Interrupt Enable Position */
#define PIO_P_IER_P13_Msk                     (_UINT32_(0x1) << PIO_P_IER_P13_Pos)                 /* (PIO_P_IER) Input Change Interrupt Enable Mask */
#define PIO_P_IER_P13(value)                  (PIO_P_IER_P13_Msk & (_UINT32_(value) << PIO_P_IER_P13_Pos)) /* Assigment of value for P13 in the PIO_P_IER register */
#define PIO_P_IER_P14_Pos                     _UINT32_(14)                                         /* (PIO_P_IER) Input Change Interrupt Enable Position */
#define PIO_P_IER_P14_Msk                     (_UINT32_(0x1) << PIO_P_IER_P14_Pos)                 /* (PIO_P_IER) Input Change Interrupt Enable Mask */
#define PIO_P_IER_P14(value)                  (PIO_P_IER_P14_Msk & (_UINT32_(value) << PIO_P_IER_P14_Pos)) /* Assigment of value for P14 in the PIO_P_IER register */
#define PIO_P_IER_P15_Pos                     _UINT32_(15)                                         /* (PIO_P_IER) Input Change Interrupt Enable Position */
#define PIO_P_IER_P15_Msk                     (_UINT32_(0x1) << PIO_P_IER_P15_Pos)                 /* (PIO_P_IER) Input Change Interrupt Enable Mask */
#define PIO_P_IER_P15(value)                  (PIO_P_IER_P15_Msk & (_UINT32_(value) << PIO_P_IER_P15_Pos)) /* Assigment of value for P15 in the PIO_P_IER register */
#define PIO_P_IER_P16_Pos                     _UINT32_(16)                                         /* (PIO_P_IER) Input Change Interrupt Enable Position */
#define PIO_P_IER_P16_Msk                     (_UINT32_(0x1) << PIO_P_IER_P16_Pos)                 /* (PIO_P_IER) Input Change Interrupt Enable Mask */
#define PIO_P_IER_P16(value)                  (PIO_P_IER_P16_Msk & (_UINT32_(value) << PIO_P_IER_P16_Pos)) /* Assigment of value for P16 in the PIO_P_IER register */
#define PIO_P_IER_P17_Pos                     _UINT32_(17)                                         /* (PIO_P_IER) Input Change Interrupt Enable Position */
#define PIO_P_IER_P17_Msk                     (_UINT32_(0x1) << PIO_P_IER_P17_Pos)                 /* (PIO_P_IER) Input Change Interrupt Enable Mask */
#define PIO_P_IER_P17(value)                  (PIO_P_IER_P17_Msk & (_UINT32_(value) << PIO_P_IER_P17_Pos)) /* Assigment of value for P17 in the PIO_P_IER register */
#define PIO_P_IER_P18_Pos                     _UINT32_(18)                                         /* (PIO_P_IER) Input Change Interrupt Enable Position */
#define PIO_P_IER_P18_Msk                     (_UINT32_(0x1) << PIO_P_IER_P18_Pos)                 /* (PIO_P_IER) Input Change Interrupt Enable Mask */
#define PIO_P_IER_P18(value)                  (PIO_P_IER_P18_Msk & (_UINT32_(value) << PIO_P_IER_P18_Pos)) /* Assigment of value for P18 in the PIO_P_IER register */
#define PIO_P_IER_P19_Pos                     _UINT32_(19)                                         /* (PIO_P_IER) Input Change Interrupt Enable Position */
#define PIO_P_IER_P19_Msk                     (_UINT32_(0x1) << PIO_P_IER_P19_Pos)                 /* (PIO_P_IER) Input Change Interrupt Enable Mask */
#define PIO_P_IER_P19(value)                  (PIO_P_IER_P19_Msk & (_UINT32_(value) << PIO_P_IER_P19_Pos)) /* Assigment of value for P19 in the PIO_P_IER register */
#define PIO_P_IER_P20_Pos                     _UINT32_(20)                                         /* (PIO_P_IER) Input Change Interrupt Enable Position */
#define PIO_P_IER_P20_Msk                     (_UINT32_(0x1) << PIO_P_IER_P20_Pos)                 /* (PIO_P_IER) Input Change Interrupt Enable Mask */
#define PIO_P_IER_P20(value)                  (PIO_P_IER_P20_Msk & (_UINT32_(value) << PIO_P_IER_P20_Pos)) /* Assigment of value for P20 in the PIO_P_IER register */
#define PIO_P_IER_P21_Pos                     _UINT32_(21)                                         /* (PIO_P_IER) Input Change Interrupt Enable Position */
#define PIO_P_IER_P21_Msk                     (_UINT32_(0x1) << PIO_P_IER_P21_Pos)                 /* (PIO_P_IER) Input Change Interrupt Enable Mask */
#define PIO_P_IER_P21(value)                  (PIO_P_IER_P21_Msk & (_UINT32_(value) << PIO_P_IER_P21_Pos)) /* Assigment of value for P21 in the PIO_P_IER register */
#define PIO_P_IER_P22_Pos                     _UINT32_(22)                                         /* (PIO_P_IER) Input Change Interrupt Enable Position */
#define PIO_P_IER_P22_Msk                     (_UINT32_(0x1) << PIO_P_IER_P22_Pos)                 /* (PIO_P_IER) Input Change Interrupt Enable Mask */
#define PIO_P_IER_P22(value)                  (PIO_P_IER_P22_Msk & (_UINT32_(value) << PIO_P_IER_P22_Pos)) /* Assigment of value for P22 in the PIO_P_IER register */
#define PIO_P_IER_P23_Pos                     _UINT32_(23)                                         /* (PIO_P_IER) Input Change Interrupt Enable Position */
#define PIO_P_IER_P23_Msk                     (_UINT32_(0x1) << PIO_P_IER_P23_Pos)                 /* (PIO_P_IER) Input Change Interrupt Enable Mask */
#define PIO_P_IER_P23(value)                  (PIO_P_IER_P23_Msk & (_UINT32_(value) << PIO_P_IER_P23_Pos)) /* Assigment of value for P23 in the PIO_P_IER register */
#define PIO_P_IER_P24_Pos                     _UINT32_(24)                                         /* (PIO_P_IER) Input Change Interrupt Enable Position */
#define PIO_P_IER_P24_Msk                     (_UINT32_(0x1) << PIO_P_IER_P24_Pos)                 /* (PIO_P_IER) Input Change Interrupt Enable Mask */
#define PIO_P_IER_P24(value)                  (PIO_P_IER_P24_Msk & (_UINT32_(value) << PIO_P_IER_P24_Pos)) /* Assigment of value for P24 in the PIO_P_IER register */
#define PIO_P_IER_P25_Pos                     _UINT32_(25)                                         /* (PIO_P_IER) Input Change Interrupt Enable Position */
#define PIO_P_IER_P25_Msk                     (_UINT32_(0x1) << PIO_P_IER_P25_Pos)                 /* (PIO_P_IER) Input Change Interrupt Enable Mask */
#define PIO_P_IER_P25(value)                  (PIO_P_IER_P25_Msk & (_UINT32_(value) << PIO_P_IER_P25_Pos)) /* Assigment of value for P25 in the PIO_P_IER register */
#define PIO_P_IER_P26_Pos                     _UINT32_(26)                                         /* (PIO_P_IER) Input Change Interrupt Enable Position */
#define PIO_P_IER_P26_Msk                     (_UINT32_(0x1) << PIO_P_IER_P26_Pos)                 /* (PIO_P_IER) Input Change Interrupt Enable Mask */
#define PIO_P_IER_P26(value)                  (PIO_P_IER_P26_Msk & (_UINT32_(value) << PIO_P_IER_P26_Pos)) /* Assigment of value for P26 in the PIO_P_IER register */
#define PIO_P_IER_P27_Pos                     _UINT32_(27)                                         /* (PIO_P_IER) Input Change Interrupt Enable Position */
#define PIO_P_IER_P27_Msk                     (_UINT32_(0x1) << PIO_P_IER_P27_Pos)                 /* (PIO_P_IER) Input Change Interrupt Enable Mask */
#define PIO_P_IER_P27(value)                  (PIO_P_IER_P27_Msk & (_UINT32_(value) << PIO_P_IER_P27_Pos)) /* Assigment of value for P27 in the PIO_P_IER register */
#define PIO_P_IER_P28_Pos                     _UINT32_(28)                                         /* (PIO_P_IER) Input Change Interrupt Enable Position */
#define PIO_P_IER_P28_Msk                     (_UINT32_(0x1) << PIO_P_IER_P28_Pos)                 /* (PIO_P_IER) Input Change Interrupt Enable Mask */
#define PIO_P_IER_P28(value)                  (PIO_P_IER_P28_Msk & (_UINT32_(value) << PIO_P_IER_P28_Pos)) /* Assigment of value for P28 in the PIO_P_IER register */
#define PIO_P_IER_P29_Pos                     _UINT32_(29)                                         /* (PIO_P_IER) Input Change Interrupt Enable Position */
#define PIO_P_IER_P29_Msk                     (_UINT32_(0x1) << PIO_P_IER_P29_Pos)                 /* (PIO_P_IER) Input Change Interrupt Enable Mask */
#define PIO_P_IER_P29(value)                  (PIO_P_IER_P29_Msk & (_UINT32_(value) << PIO_P_IER_P29_Pos)) /* Assigment of value for P29 in the PIO_P_IER register */
#define PIO_P_IER_P30_Pos                     _UINT32_(30)                                         /* (PIO_P_IER) Input Change Interrupt Enable Position */
#define PIO_P_IER_P30_Msk                     (_UINT32_(0x1) << PIO_P_IER_P30_Pos)                 /* (PIO_P_IER) Input Change Interrupt Enable Mask */
#define PIO_P_IER_P30(value)                  (PIO_P_IER_P30_Msk & (_UINT32_(value) << PIO_P_IER_P30_Pos)) /* Assigment of value for P30 in the PIO_P_IER register */
#define PIO_P_IER_P31_Pos                     _UINT32_(31)                                         /* (PIO_P_IER) Input Change Interrupt Enable Position */
#define PIO_P_IER_P31_Msk                     (_UINT32_(0x1) << PIO_P_IER_P31_Pos)                 /* (PIO_P_IER) Input Change Interrupt Enable Mask */
#define PIO_P_IER_P31(value)                  (PIO_P_IER_P31_Msk & (_UINT32_(value) << PIO_P_IER_P31_Pos)) /* Assigment of value for P31 in the PIO_P_IER register */
#define PIO_P_IER_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (PIO_P_IER) Register Mask  */

#define PIO_P_IER_P_Pos                       _UINT32_(0)                                          /* (PIO_P_IER Position) Input Change Interrupt Enable */
#define PIO_P_IER_P_Msk                       (_UINT32_(0xFFFFFFFF) << PIO_P_IER_P_Pos)            /* (PIO_P_IER Mask) P */
#define PIO_P_IER_P(value)                    (PIO_P_IER_P_Msk & (_UINT32_(value) << PIO_P_IER_P_Pos)) 

/* -------- PIO_P_IDR : (PIO Offset: 0x24) ( /W 32) PIO Privilege Interrupt Disable Register (p_iogroup = 0) -------- */
#define PIO_P_IDR_P0_Pos                      _UINT32_(0)                                          /* (PIO_P_IDR) Input Change Interrupt Disable Position */
#define PIO_P_IDR_P0_Msk                      (_UINT32_(0x1) << PIO_P_IDR_P0_Pos)                  /* (PIO_P_IDR) Input Change Interrupt Disable Mask */
#define PIO_P_IDR_P0(value)                   (PIO_P_IDR_P0_Msk & (_UINT32_(value) << PIO_P_IDR_P0_Pos)) /* Assigment of value for P0 in the PIO_P_IDR register */
#define PIO_P_IDR_P1_Pos                      _UINT32_(1)                                          /* (PIO_P_IDR) Input Change Interrupt Disable Position */
#define PIO_P_IDR_P1_Msk                      (_UINT32_(0x1) << PIO_P_IDR_P1_Pos)                  /* (PIO_P_IDR) Input Change Interrupt Disable Mask */
#define PIO_P_IDR_P1(value)                   (PIO_P_IDR_P1_Msk & (_UINT32_(value) << PIO_P_IDR_P1_Pos)) /* Assigment of value for P1 in the PIO_P_IDR register */
#define PIO_P_IDR_P2_Pos                      _UINT32_(2)                                          /* (PIO_P_IDR) Input Change Interrupt Disable Position */
#define PIO_P_IDR_P2_Msk                      (_UINT32_(0x1) << PIO_P_IDR_P2_Pos)                  /* (PIO_P_IDR) Input Change Interrupt Disable Mask */
#define PIO_P_IDR_P2(value)                   (PIO_P_IDR_P2_Msk & (_UINT32_(value) << PIO_P_IDR_P2_Pos)) /* Assigment of value for P2 in the PIO_P_IDR register */
#define PIO_P_IDR_P3_Pos                      _UINT32_(3)                                          /* (PIO_P_IDR) Input Change Interrupt Disable Position */
#define PIO_P_IDR_P3_Msk                      (_UINT32_(0x1) << PIO_P_IDR_P3_Pos)                  /* (PIO_P_IDR) Input Change Interrupt Disable Mask */
#define PIO_P_IDR_P3(value)                   (PIO_P_IDR_P3_Msk & (_UINT32_(value) << PIO_P_IDR_P3_Pos)) /* Assigment of value for P3 in the PIO_P_IDR register */
#define PIO_P_IDR_P4_Pos                      _UINT32_(4)                                          /* (PIO_P_IDR) Input Change Interrupt Disable Position */
#define PIO_P_IDR_P4_Msk                      (_UINT32_(0x1) << PIO_P_IDR_P4_Pos)                  /* (PIO_P_IDR) Input Change Interrupt Disable Mask */
#define PIO_P_IDR_P4(value)                   (PIO_P_IDR_P4_Msk & (_UINT32_(value) << PIO_P_IDR_P4_Pos)) /* Assigment of value for P4 in the PIO_P_IDR register */
#define PIO_P_IDR_P5_Pos                      _UINT32_(5)                                          /* (PIO_P_IDR) Input Change Interrupt Disable Position */
#define PIO_P_IDR_P5_Msk                      (_UINT32_(0x1) << PIO_P_IDR_P5_Pos)                  /* (PIO_P_IDR) Input Change Interrupt Disable Mask */
#define PIO_P_IDR_P5(value)                   (PIO_P_IDR_P5_Msk & (_UINT32_(value) << PIO_P_IDR_P5_Pos)) /* Assigment of value for P5 in the PIO_P_IDR register */
#define PIO_P_IDR_P6_Pos                      _UINT32_(6)                                          /* (PIO_P_IDR) Input Change Interrupt Disable Position */
#define PIO_P_IDR_P6_Msk                      (_UINT32_(0x1) << PIO_P_IDR_P6_Pos)                  /* (PIO_P_IDR) Input Change Interrupt Disable Mask */
#define PIO_P_IDR_P6(value)                   (PIO_P_IDR_P6_Msk & (_UINT32_(value) << PIO_P_IDR_P6_Pos)) /* Assigment of value for P6 in the PIO_P_IDR register */
#define PIO_P_IDR_P7_Pos                      _UINT32_(7)                                          /* (PIO_P_IDR) Input Change Interrupt Disable Position */
#define PIO_P_IDR_P7_Msk                      (_UINT32_(0x1) << PIO_P_IDR_P7_Pos)                  /* (PIO_P_IDR) Input Change Interrupt Disable Mask */
#define PIO_P_IDR_P7(value)                   (PIO_P_IDR_P7_Msk & (_UINT32_(value) << PIO_P_IDR_P7_Pos)) /* Assigment of value for P7 in the PIO_P_IDR register */
#define PIO_P_IDR_P8_Pos                      _UINT32_(8)                                          /* (PIO_P_IDR) Input Change Interrupt Disable Position */
#define PIO_P_IDR_P8_Msk                      (_UINT32_(0x1) << PIO_P_IDR_P8_Pos)                  /* (PIO_P_IDR) Input Change Interrupt Disable Mask */
#define PIO_P_IDR_P8(value)                   (PIO_P_IDR_P8_Msk & (_UINT32_(value) << PIO_P_IDR_P8_Pos)) /* Assigment of value for P8 in the PIO_P_IDR register */
#define PIO_P_IDR_P9_Pos                      _UINT32_(9)                                          /* (PIO_P_IDR) Input Change Interrupt Disable Position */
#define PIO_P_IDR_P9_Msk                      (_UINT32_(0x1) << PIO_P_IDR_P9_Pos)                  /* (PIO_P_IDR) Input Change Interrupt Disable Mask */
#define PIO_P_IDR_P9(value)                   (PIO_P_IDR_P9_Msk & (_UINT32_(value) << PIO_P_IDR_P9_Pos)) /* Assigment of value for P9 in the PIO_P_IDR register */
#define PIO_P_IDR_P10_Pos                     _UINT32_(10)                                         /* (PIO_P_IDR) Input Change Interrupt Disable Position */
#define PIO_P_IDR_P10_Msk                     (_UINT32_(0x1) << PIO_P_IDR_P10_Pos)                 /* (PIO_P_IDR) Input Change Interrupt Disable Mask */
#define PIO_P_IDR_P10(value)                  (PIO_P_IDR_P10_Msk & (_UINT32_(value) << PIO_P_IDR_P10_Pos)) /* Assigment of value for P10 in the PIO_P_IDR register */
#define PIO_P_IDR_P11_Pos                     _UINT32_(11)                                         /* (PIO_P_IDR) Input Change Interrupt Disable Position */
#define PIO_P_IDR_P11_Msk                     (_UINT32_(0x1) << PIO_P_IDR_P11_Pos)                 /* (PIO_P_IDR) Input Change Interrupt Disable Mask */
#define PIO_P_IDR_P11(value)                  (PIO_P_IDR_P11_Msk & (_UINT32_(value) << PIO_P_IDR_P11_Pos)) /* Assigment of value for P11 in the PIO_P_IDR register */
#define PIO_P_IDR_P12_Pos                     _UINT32_(12)                                         /* (PIO_P_IDR) Input Change Interrupt Disable Position */
#define PIO_P_IDR_P12_Msk                     (_UINT32_(0x1) << PIO_P_IDR_P12_Pos)                 /* (PIO_P_IDR) Input Change Interrupt Disable Mask */
#define PIO_P_IDR_P12(value)                  (PIO_P_IDR_P12_Msk & (_UINT32_(value) << PIO_P_IDR_P12_Pos)) /* Assigment of value for P12 in the PIO_P_IDR register */
#define PIO_P_IDR_P13_Pos                     _UINT32_(13)                                         /* (PIO_P_IDR) Input Change Interrupt Disable Position */
#define PIO_P_IDR_P13_Msk                     (_UINT32_(0x1) << PIO_P_IDR_P13_Pos)                 /* (PIO_P_IDR) Input Change Interrupt Disable Mask */
#define PIO_P_IDR_P13(value)                  (PIO_P_IDR_P13_Msk & (_UINT32_(value) << PIO_P_IDR_P13_Pos)) /* Assigment of value for P13 in the PIO_P_IDR register */
#define PIO_P_IDR_P14_Pos                     _UINT32_(14)                                         /* (PIO_P_IDR) Input Change Interrupt Disable Position */
#define PIO_P_IDR_P14_Msk                     (_UINT32_(0x1) << PIO_P_IDR_P14_Pos)                 /* (PIO_P_IDR) Input Change Interrupt Disable Mask */
#define PIO_P_IDR_P14(value)                  (PIO_P_IDR_P14_Msk & (_UINT32_(value) << PIO_P_IDR_P14_Pos)) /* Assigment of value for P14 in the PIO_P_IDR register */
#define PIO_P_IDR_P15_Pos                     _UINT32_(15)                                         /* (PIO_P_IDR) Input Change Interrupt Disable Position */
#define PIO_P_IDR_P15_Msk                     (_UINT32_(0x1) << PIO_P_IDR_P15_Pos)                 /* (PIO_P_IDR) Input Change Interrupt Disable Mask */
#define PIO_P_IDR_P15(value)                  (PIO_P_IDR_P15_Msk & (_UINT32_(value) << PIO_P_IDR_P15_Pos)) /* Assigment of value for P15 in the PIO_P_IDR register */
#define PIO_P_IDR_P16_Pos                     _UINT32_(16)                                         /* (PIO_P_IDR) Input Change Interrupt Disable Position */
#define PIO_P_IDR_P16_Msk                     (_UINT32_(0x1) << PIO_P_IDR_P16_Pos)                 /* (PIO_P_IDR) Input Change Interrupt Disable Mask */
#define PIO_P_IDR_P16(value)                  (PIO_P_IDR_P16_Msk & (_UINT32_(value) << PIO_P_IDR_P16_Pos)) /* Assigment of value for P16 in the PIO_P_IDR register */
#define PIO_P_IDR_P17_Pos                     _UINT32_(17)                                         /* (PIO_P_IDR) Input Change Interrupt Disable Position */
#define PIO_P_IDR_P17_Msk                     (_UINT32_(0x1) << PIO_P_IDR_P17_Pos)                 /* (PIO_P_IDR) Input Change Interrupt Disable Mask */
#define PIO_P_IDR_P17(value)                  (PIO_P_IDR_P17_Msk & (_UINT32_(value) << PIO_P_IDR_P17_Pos)) /* Assigment of value for P17 in the PIO_P_IDR register */
#define PIO_P_IDR_P18_Pos                     _UINT32_(18)                                         /* (PIO_P_IDR) Input Change Interrupt Disable Position */
#define PIO_P_IDR_P18_Msk                     (_UINT32_(0x1) << PIO_P_IDR_P18_Pos)                 /* (PIO_P_IDR) Input Change Interrupt Disable Mask */
#define PIO_P_IDR_P18(value)                  (PIO_P_IDR_P18_Msk & (_UINT32_(value) << PIO_P_IDR_P18_Pos)) /* Assigment of value for P18 in the PIO_P_IDR register */
#define PIO_P_IDR_P19_Pos                     _UINT32_(19)                                         /* (PIO_P_IDR) Input Change Interrupt Disable Position */
#define PIO_P_IDR_P19_Msk                     (_UINT32_(0x1) << PIO_P_IDR_P19_Pos)                 /* (PIO_P_IDR) Input Change Interrupt Disable Mask */
#define PIO_P_IDR_P19(value)                  (PIO_P_IDR_P19_Msk & (_UINT32_(value) << PIO_P_IDR_P19_Pos)) /* Assigment of value for P19 in the PIO_P_IDR register */
#define PIO_P_IDR_P20_Pos                     _UINT32_(20)                                         /* (PIO_P_IDR) Input Change Interrupt Disable Position */
#define PIO_P_IDR_P20_Msk                     (_UINT32_(0x1) << PIO_P_IDR_P20_Pos)                 /* (PIO_P_IDR) Input Change Interrupt Disable Mask */
#define PIO_P_IDR_P20(value)                  (PIO_P_IDR_P20_Msk & (_UINT32_(value) << PIO_P_IDR_P20_Pos)) /* Assigment of value for P20 in the PIO_P_IDR register */
#define PIO_P_IDR_P21_Pos                     _UINT32_(21)                                         /* (PIO_P_IDR) Input Change Interrupt Disable Position */
#define PIO_P_IDR_P21_Msk                     (_UINT32_(0x1) << PIO_P_IDR_P21_Pos)                 /* (PIO_P_IDR) Input Change Interrupt Disable Mask */
#define PIO_P_IDR_P21(value)                  (PIO_P_IDR_P21_Msk & (_UINT32_(value) << PIO_P_IDR_P21_Pos)) /* Assigment of value for P21 in the PIO_P_IDR register */
#define PIO_P_IDR_P22_Pos                     _UINT32_(22)                                         /* (PIO_P_IDR) Input Change Interrupt Disable Position */
#define PIO_P_IDR_P22_Msk                     (_UINT32_(0x1) << PIO_P_IDR_P22_Pos)                 /* (PIO_P_IDR) Input Change Interrupt Disable Mask */
#define PIO_P_IDR_P22(value)                  (PIO_P_IDR_P22_Msk & (_UINT32_(value) << PIO_P_IDR_P22_Pos)) /* Assigment of value for P22 in the PIO_P_IDR register */
#define PIO_P_IDR_P23_Pos                     _UINT32_(23)                                         /* (PIO_P_IDR) Input Change Interrupt Disable Position */
#define PIO_P_IDR_P23_Msk                     (_UINT32_(0x1) << PIO_P_IDR_P23_Pos)                 /* (PIO_P_IDR) Input Change Interrupt Disable Mask */
#define PIO_P_IDR_P23(value)                  (PIO_P_IDR_P23_Msk & (_UINT32_(value) << PIO_P_IDR_P23_Pos)) /* Assigment of value for P23 in the PIO_P_IDR register */
#define PIO_P_IDR_P24_Pos                     _UINT32_(24)                                         /* (PIO_P_IDR) Input Change Interrupt Disable Position */
#define PIO_P_IDR_P24_Msk                     (_UINT32_(0x1) << PIO_P_IDR_P24_Pos)                 /* (PIO_P_IDR) Input Change Interrupt Disable Mask */
#define PIO_P_IDR_P24(value)                  (PIO_P_IDR_P24_Msk & (_UINT32_(value) << PIO_P_IDR_P24_Pos)) /* Assigment of value for P24 in the PIO_P_IDR register */
#define PIO_P_IDR_P25_Pos                     _UINT32_(25)                                         /* (PIO_P_IDR) Input Change Interrupt Disable Position */
#define PIO_P_IDR_P25_Msk                     (_UINT32_(0x1) << PIO_P_IDR_P25_Pos)                 /* (PIO_P_IDR) Input Change Interrupt Disable Mask */
#define PIO_P_IDR_P25(value)                  (PIO_P_IDR_P25_Msk & (_UINT32_(value) << PIO_P_IDR_P25_Pos)) /* Assigment of value for P25 in the PIO_P_IDR register */
#define PIO_P_IDR_P26_Pos                     _UINT32_(26)                                         /* (PIO_P_IDR) Input Change Interrupt Disable Position */
#define PIO_P_IDR_P26_Msk                     (_UINT32_(0x1) << PIO_P_IDR_P26_Pos)                 /* (PIO_P_IDR) Input Change Interrupt Disable Mask */
#define PIO_P_IDR_P26(value)                  (PIO_P_IDR_P26_Msk & (_UINT32_(value) << PIO_P_IDR_P26_Pos)) /* Assigment of value for P26 in the PIO_P_IDR register */
#define PIO_P_IDR_P27_Pos                     _UINT32_(27)                                         /* (PIO_P_IDR) Input Change Interrupt Disable Position */
#define PIO_P_IDR_P27_Msk                     (_UINT32_(0x1) << PIO_P_IDR_P27_Pos)                 /* (PIO_P_IDR) Input Change Interrupt Disable Mask */
#define PIO_P_IDR_P27(value)                  (PIO_P_IDR_P27_Msk & (_UINT32_(value) << PIO_P_IDR_P27_Pos)) /* Assigment of value for P27 in the PIO_P_IDR register */
#define PIO_P_IDR_P28_Pos                     _UINT32_(28)                                         /* (PIO_P_IDR) Input Change Interrupt Disable Position */
#define PIO_P_IDR_P28_Msk                     (_UINT32_(0x1) << PIO_P_IDR_P28_Pos)                 /* (PIO_P_IDR) Input Change Interrupt Disable Mask */
#define PIO_P_IDR_P28(value)                  (PIO_P_IDR_P28_Msk & (_UINT32_(value) << PIO_P_IDR_P28_Pos)) /* Assigment of value for P28 in the PIO_P_IDR register */
#define PIO_P_IDR_P29_Pos                     _UINT32_(29)                                         /* (PIO_P_IDR) Input Change Interrupt Disable Position */
#define PIO_P_IDR_P29_Msk                     (_UINT32_(0x1) << PIO_P_IDR_P29_Pos)                 /* (PIO_P_IDR) Input Change Interrupt Disable Mask */
#define PIO_P_IDR_P29(value)                  (PIO_P_IDR_P29_Msk & (_UINT32_(value) << PIO_P_IDR_P29_Pos)) /* Assigment of value for P29 in the PIO_P_IDR register */
#define PIO_P_IDR_P30_Pos                     _UINT32_(30)                                         /* (PIO_P_IDR) Input Change Interrupt Disable Position */
#define PIO_P_IDR_P30_Msk                     (_UINT32_(0x1) << PIO_P_IDR_P30_Pos)                 /* (PIO_P_IDR) Input Change Interrupt Disable Mask */
#define PIO_P_IDR_P30(value)                  (PIO_P_IDR_P30_Msk & (_UINT32_(value) << PIO_P_IDR_P30_Pos)) /* Assigment of value for P30 in the PIO_P_IDR register */
#define PIO_P_IDR_P31_Pos                     _UINT32_(31)                                         /* (PIO_P_IDR) Input Change Interrupt Disable Position */
#define PIO_P_IDR_P31_Msk                     (_UINT32_(0x1) << PIO_P_IDR_P31_Pos)                 /* (PIO_P_IDR) Input Change Interrupt Disable Mask */
#define PIO_P_IDR_P31(value)                  (PIO_P_IDR_P31_Msk & (_UINT32_(value) << PIO_P_IDR_P31_Pos)) /* Assigment of value for P31 in the PIO_P_IDR register */
#define PIO_P_IDR_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (PIO_P_IDR) Register Mask  */

#define PIO_P_IDR_P_Pos                       _UINT32_(0)                                          /* (PIO_P_IDR Position) Input Change Interrupt Disable */
#define PIO_P_IDR_P_Msk                       (_UINT32_(0xFFFFFFFF) << PIO_P_IDR_P_Pos)            /* (PIO_P_IDR Mask) P */
#define PIO_P_IDR_P(value)                    (PIO_P_IDR_P_Msk & (_UINT32_(value) << PIO_P_IDR_P_Pos)) 

/* -------- PIO_P_IMR : (PIO Offset: 0x28) ( R/ 32) PIO Privilege Interrupt Mask Register (p_iogroup = 0) -------- */
#define PIO_P_IMR_P0_Pos                      _UINT32_(0)                                          /* (PIO_P_IMR) Input Change Interrupt Mask Position */
#define PIO_P_IMR_P0_Msk                      (_UINT32_(0x1) << PIO_P_IMR_P0_Pos)                  /* (PIO_P_IMR) Input Change Interrupt Mask Mask */
#define PIO_P_IMR_P0(value)                   (PIO_P_IMR_P0_Msk & (_UINT32_(value) << PIO_P_IMR_P0_Pos)) /* Assigment of value for P0 in the PIO_P_IMR register */
#define PIO_P_IMR_P1_Pos                      _UINT32_(1)                                          /* (PIO_P_IMR) Input Change Interrupt Mask Position */
#define PIO_P_IMR_P1_Msk                      (_UINT32_(0x1) << PIO_P_IMR_P1_Pos)                  /* (PIO_P_IMR) Input Change Interrupt Mask Mask */
#define PIO_P_IMR_P1(value)                   (PIO_P_IMR_P1_Msk & (_UINT32_(value) << PIO_P_IMR_P1_Pos)) /* Assigment of value for P1 in the PIO_P_IMR register */
#define PIO_P_IMR_P2_Pos                      _UINT32_(2)                                          /* (PIO_P_IMR) Input Change Interrupt Mask Position */
#define PIO_P_IMR_P2_Msk                      (_UINT32_(0x1) << PIO_P_IMR_P2_Pos)                  /* (PIO_P_IMR) Input Change Interrupt Mask Mask */
#define PIO_P_IMR_P2(value)                   (PIO_P_IMR_P2_Msk & (_UINT32_(value) << PIO_P_IMR_P2_Pos)) /* Assigment of value for P2 in the PIO_P_IMR register */
#define PIO_P_IMR_P3_Pos                      _UINT32_(3)                                          /* (PIO_P_IMR) Input Change Interrupt Mask Position */
#define PIO_P_IMR_P3_Msk                      (_UINT32_(0x1) << PIO_P_IMR_P3_Pos)                  /* (PIO_P_IMR) Input Change Interrupt Mask Mask */
#define PIO_P_IMR_P3(value)                   (PIO_P_IMR_P3_Msk & (_UINT32_(value) << PIO_P_IMR_P3_Pos)) /* Assigment of value for P3 in the PIO_P_IMR register */
#define PIO_P_IMR_P4_Pos                      _UINT32_(4)                                          /* (PIO_P_IMR) Input Change Interrupt Mask Position */
#define PIO_P_IMR_P4_Msk                      (_UINT32_(0x1) << PIO_P_IMR_P4_Pos)                  /* (PIO_P_IMR) Input Change Interrupt Mask Mask */
#define PIO_P_IMR_P4(value)                   (PIO_P_IMR_P4_Msk & (_UINT32_(value) << PIO_P_IMR_P4_Pos)) /* Assigment of value for P4 in the PIO_P_IMR register */
#define PIO_P_IMR_P5_Pos                      _UINT32_(5)                                          /* (PIO_P_IMR) Input Change Interrupt Mask Position */
#define PIO_P_IMR_P5_Msk                      (_UINT32_(0x1) << PIO_P_IMR_P5_Pos)                  /* (PIO_P_IMR) Input Change Interrupt Mask Mask */
#define PIO_P_IMR_P5(value)                   (PIO_P_IMR_P5_Msk & (_UINT32_(value) << PIO_P_IMR_P5_Pos)) /* Assigment of value for P5 in the PIO_P_IMR register */
#define PIO_P_IMR_P6_Pos                      _UINT32_(6)                                          /* (PIO_P_IMR) Input Change Interrupt Mask Position */
#define PIO_P_IMR_P6_Msk                      (_UINT32_(0x1) << PIO_P_IMR_P6_Pos)                  /* (PIO_P_IMR) Input Change Interrupt Mask Mask */
#define PIO_P_IMR_P6(value)                   (PIO_P_IMR_P6_Msk & (_UINT32_(value) << PIO_P_IMR_P6_Pos)) /* Assigment of value for P6 in the PIO_P_IMR register */
#define PIO_P_IMR_P7_Pos                      _UINT32_(7)                                          /* (PIO_P_IMR) Input Change Interrupt Mask Position */
#define PIO_P_IMR_P7_Msk                      (_UINT32_(0x1) << PIO_P_IMR_P7_Pos)                  /* (PIO_P_IMR) Input Change Interrupt Mask Mask */
#define PIO_P_IMR_P7(value)                   (PIO_P_IMR_P7_Msk & (_UINT32_(value) << PIO_P_IMR_P7_Pos)) /* Assigment of value for P7 in the PIO_P_IMR register */
#define PIO_P_IMR_P8_Pos                      _UINT32_(8)                                          /* (PIO_P_IMR) Input Change Interrupt Mask Position */
#define PIO_P_IMR_P8_Msk                      (_UINT32_(0x1) << PIO_P_IMR_P8_Pos)                  /* (PIO_P_IMR) Input Change Interrupt Mask Mask */
#define PIO_P_IMR_P8(value)                   (PIO_P_IMR_P8_Msk & (_UINT32_(value) << PIO_P_IMR_P8_Pos)) /* Assigment of value for P8 in the PIO_P_IMR register */
#define PIO_P_IMR_P9_Pos                      _UINT32_(9)                                          /* (PIO_P_IMR) Input Change Interrupt Mask Position */
#define PIO_P_IMR_P9_Msk                      (_UINT32_(0x1) << PIO_P_IMR_P9_Pos)                  /* (PIO_P_IMR) Input Change Interrupt Mask Mask */
#define PIO_P_IMR_P9(value)                   (PIO_P_IMR_P9_Msk & (_UINT32_(value) << PIO_P_IMR_P9_Pos)) /* Assigment of value for P9 in the PIO_P_IMR register */
#define PIO_P_IMR_P10_Pos                     _UINT32_(10)                                         /* (PIO_P_IMR) Input Change Interrupt Mask Position */
#define PIO_P_IMR_P10_Msk                     (_UINT32_(0x1) << PIO_P_IMR_P10_Pos)                 /* (PIO_P_IMR) Input Change Interrupt Mask Mask */
#define PIO_P_IMR_P10(value)                  (PIO_P_IMR_P10_Msk & (_UINT32_(value) << PIO_P_IMR_P10_Pos)) /* Assigment of value for P10 in the PIO_P_IMR register */
#define PIO_P_IMR_P11_Pos                     _UINT32_(11)                                         /* (PIO_P_IMR) Input Change Interrupt Mask Position */
#define PIO_P_IMR_P11_Msk                     (_UINT32_(0x1) << PIO_P_IMR_P11_Pos)                 /* (PIO_P_IMR) Input Change Interrupt Mask Mask */
#define PIO_P_IMR_P11(value)                  (PIO_P_IMR_P11_Msk & (_UINT32_(value) << PIO_P_IMR_P11_Pos)) /* Assigment of value for P11 in the PIO_P_IMR register */
#define PIO_P_IMR_P12_Pos                     _UINT32_(12)                                         /* (PIO_P_IMR) Input Change Interrupt Mask Position */
#define PIO_P_IMR_P12_Msk                     (_UINT32_(0x1) << PIO_P_IMR_P12_Pos)                 /* (PIO_P_IMR) Input Change Interrupt Mask Mask */
#define PIO_P_IMR_P12(value)                  (PIO_P_IMR_P12_Msk & (_UINT32_(value) << PIO_P_IMR_P12_Pos)) /* Assigment of value for P12 in the PIO_P_IMR register */
#define PIO_P_IMR_P13_Pos                     _UINT32_(13)                                         /* (PIO_P_IMR) Input Change Interrupt Mask Position */
#define PIO_P_IMR_P13_Msk                     (_UINT32_(0x1) << PIO_P_IMR_P13_Pos)                 /* (PIO_P_IMR) Input Change Interrupt Mask Mask */
#define PIO_P_IMR_P13(value)                  (PIO_P_IMR_P13_Msk & (_UINT32_(value) << PIO_P_IMR_P13_Pos)) /* Assigment of value for P13 in the PIO_P_IMR register */
#define PIO_P_IMR_P14_Pos                     _UINT32_(14)                                         /* (PIO_P_IMR) Input Change Interrupt Mask Position */
#define PIO_P_IMR_P14_Msk                     (_UINT32_(0x1) << PIO_P_IMR_P14_Pos)                 /* (PIO_P_IMR) Input Change Interrupt Mask Mask */
#define PIO_P_IMR_P14(value)                  (PIO_P_IMR_P14_Msk & (_UINT32_(value) << PIO_P_IMR_P14_Pos)) /* Assigment of value for P14 in the PIO_P_IMR register */
#define PIO_P_IMR_P15_Pos                     _UINT32_(15)                                         /* (PIO_P_IMR) Input Change Interrupt Mask Position */
#define PIO_P_IMR_P15_Msk                     (_UINT32_(0x1) << PIO_P_IMR_P15_Pos)                 /* (PIO_P_IMR) Input Change Interrupt Mask Mask */
#define PIO_P_IMR_P15(value)                  (PIO_P_IMR_P15_Msk & (_UINT32_(value) << PIO_P_IMR_P15_Pos)) /* Assigment of value for P15 in the PIO_P_IMR register */
#define PIO_P_IMR_P16_Pos                     _UINT32_(16)                                         /* (PIO_P_IMR) Input Change Interrupt Mask Position */
#define PIO_P_IMR_P16_Msk                     (_UINT32_(0x1) << PIO_P_IMR_P16_Pos)                 /* (PIO_P_IMR) Input Change Interrupt Mask Mask */
#define PIO_P_IMR_P16(value)                  (PIO_P_IMR_P16_Msk & (_UINT32_(value) << PIO_P_IMR_P16_Pos)) /* Assigment of value for P16 in the PIO_P_IMR register */
#define PIO_P_IMR_P17_Pos                     _UINT32_(17)                                         /* (PIO_P_IMR) Input Change Interrupt Mask Position */
#define PIO_P_IMR_P17_Msk                     (_UINT32_(0x1) << PIO_P_IMR_P17_Pos)                 /* (PIO_P_IMR) Input Change Interrupt Mask Mask */
#define PIO_P_IMR_P17(value)                  (PIO_P_IMR_P17_Msk & (_UINT32_(value) << PIO_P_IMR_P17_Pos)) /* Assigment of value for P17 in the PIO_P_IMR register */
#define PIO_P_IMR_P18_Pos                     _UINT32_(18)                                         /* (PIO_P_IMR) Input Change Interrupt Mask Position */
#define PIO_P_IMR_P18_Msk                     (_UINT32_(0x1) << PIO_P_IMR_P18_Pos)                 /* (PIO_P_IMR) Input Change Interrupt Mask Mask */
#define PIO_P_IMR_P18(value)                  (PIO_P_IMR_P18_Msk & (_UINT32_(value) << PIO_P_IMR_P18_Pos)) /* Assigment of value for P18 in the PIO_P_IMR register */
#define PIO_P_IMR_P19_Pos                     _UINT32_(19)                                         /* (PIO_P_IMR) Input Change Interrupt Mask Position */
#define PIO_P_IMR_P19_Msk                     (_UINT32_(0x1) << PIO_P_IMR_P19_Pos)                 /* (PIO_P_IMR) Input Change Interrupt Mask Mask */
#define PIO_P_IMR_P19(value)                  (PIO_P_IMR_P19_Msk & (_UINT32_(value) << PIO_P_IMR_P19_Pos)) /* Assigment of value for P19 in the PIO_P_IMR register */
#define PIO_P_IMR_P20_Pos                     _UINT32_(20)                                         /* (PIO_P_IMR) Input Change Interrupt Mask Position */
#define PIO_P_IMR_P20_Msk                     (_UINT32_(0x1) << PIO_P_IMR_P20_Pos)                 /* (PIO_P_IMR) Input Change Interrupt Mask Mask */
#define PIO_P_IMR_P20(value)                  (PIO_P_IMR_P20_Msk & (_UINT32_(value) << PIO_P_IMR_P20_Pos)) /* Assigment of value for P20 in the PIO_P_IMR register */
#define PIO_P_IMR_P21_Pos                     _UINT32_(21)                                         /* (PIO_P_IMR) Input Change Interrupt Mask Position */
#define PIO_P_IMR_P21_Msk                     (_UINT32_(0x1) << PIO_P_IMR_P21_Pos)                 /* (PIO_P_IMR) Input Change Interrupt Mask Mask */
#define PIO_P_IMR_P21(value)                  (PIO_P_IMR_P21_Msk & (_UINT32_(value) << PIO_P_IMR_P21_Pos)) /* Assigment of value for P21 in the PIO_P_IMR register */
#define PIO_P_IMR_P22_Pos                     _UINT32_(22)                                         /* (PIO_P_IMR) Input Change Interrupt Mask Position */
#define PIO_P_IMR_P22_Msk                     (_UINT32_(0x1) << PIO_P_IMR_P22_Pos)                 /* (PIO_P_IMR) Input Change Interrupt Mask Mask */
#define PIO_P_IMR_P22(value)                  (PIO_P_IMR_P22_Msk & (_UINT32_(value) << PIO_P_IMR_P22_Pos)) /* Assigment of value for P22 in the PIO_P_IMR register */
#define PIO_P_IMR_P23_Pos                     _UINT32_(23)                                         /* (PIO_P_IMR) Input Change Interrupt Mask Position */
#define PIO_P_IMR_P23_Msk                     (_UINT32_(0x1) << PIO_P_IMR_P23_Pos)                 /* (PIO_P_IMR) Input Change Interrupt Mask Mask */
#define PIO_P_IMR_P23(value)                  (PIO_P_IMR_P23_Msk & (_UINT32_(value) << PIO_P_IMR_P23_Pos)) /* Assigment of value for P23 in the PIO_P_IMR register */
#define PIO_P_IMR_P24_Pos                     _UINT32_(24)                                         /* (PIO_P_IMR) Input Change Interrupt Mask Position */
#define PIO_P_IMR_P24_Msk                     (_UINT32_(0x1) << PIO_P_IMR_P24_Pos)                 /* (PIO_P_IMR) Input Change Interrupt Mask Mask */
#define PIO_P_IMR_P24(value)                  (PIO_P_IMR_P24_Msk & (_UINT32_(value) << PIO_P_IMR_P24_Pos)) /* Assigment of value for P24 in the PIO_P_IMR register */
#define PIO_P_IMR_P25_Pos                     _UINT32_(25)                                         /* (PIO_P_IMR) Input Change Interrupt Mask Position */
#define PIO_P_IMR_P25_Msk                     (_UINT32_(0x1) << PIO_P_IMR_P25_Pos)                 /* (PIO_P_IMR) Input Change Interrupt Mask Mask */
#define PIO_P_IMR_P25(value)                  (PIO_P_IMR_P25_Msk & (_UINT32_(value) << PIO_P_IMR_P25_Pos)) /* Assigment of value for P25 in the PIO_P_IMR register */
#define PIO_P_IMR_P26_Pos                     _UINT32_(26)                                         /* (PIO_P_IMR) Input Change Interrupt Mask Position */
#define PIO_P_IMR_P26_Msk                     (_UINT32_(0x1) << PIO_P_IMR_P26_Pos)                 /* (PIO_P_IMR) Input Change Interrupt Mask Mask */
#define PIO_P_IMR_P26(value)                  (PIO_P_IMR_P26_Msk & (_UINT32_(value) << PIO_P_IMR_P26_Pos)) /* Assigment of value for P26 in the PIO_P_IMR register */
#define PIO_P_IMR_P27_Pos                     _UINT32_(27)                                         /* (PIO_P_IMR) Input Change Interrupt Mask Position */
#define PIO_P_IMR_P27_Msk                     (_UINT32_(0x1) << PIO_P_IMR_P27_Pos)                 /* (PIO_P_IMR) Input Change Interrupt Mask Mask */
#define PIO_P_IMR_P27(value)                  (PIO_P_IMR_P27_Msk & (_UINT32_(value) << PIO_P_IMR_P27_Pos)) /* Assigment of value for P27 in the PIO_P_IMR register */
#define PIO_P_IMR_P28_Pos                     _UINT32_(28)                                         /* (PIO_P_IMR) Input Change Interrupt Mask Position */
#define PIO_P_IMR_P28_Msk                     (_UINT32_(0x1) << PIO_P_IMR_P28_Pos)                 /* (PIO_P_IMR) Input Change Interrupt Mask Mask */
#define PIO_P_IMR_P28(value)                  (PIO_P_IMR_P28_Msk & (_UINT32_(value) << PIO_P_IMR_P28_Pos)) /* Assigment of value for P28 in the PIO_P_IMR register */
#define PIO_P_IMR_P29_Pos                     _UINT32_(29)                                         /* (PIO_P_IMR) Input Change Interrupt Mask Position */
#define PIO_P_IMR_P29_Msk                     (_UINT32_(0x1) << PIO_P_IMR_P29_Pos)                 /* (PIO_P_IMR) Input Change Interrupt Mask Mask */
#define PIO_P_IMR_P29(value)                  (PIO_P_IMR_P29_Msk & (_UINT32_(value) << PIO_P_IMR_P29_Pos)) /* Assigment of value for P29 in the PIO_P_IMR register */
#define PIO_P_IMR_P30_Pos                     _UINT32_(30)                                         /* (PIO_P_IMR) Input Change Interrupt Mask Position */
#define PIO_P_IMR_P30_Msk                     (_UINT32_(0x1) << PIO_P_IMR_P30_Pos)                 /* (PIO_P_IMR) Input Change Interrupt Mask Mask */
#define PIO_P_IMR_P30(value)                  (PIO_P_IMR_P30_Msk & (_UINT32_(value) << PIO_P_IMR_P30_Pos)) /* Assigment of value for P30 in the PIO_P_IMR register */
#define PIO_P_IMR_P31_Pos                     _UINT32_(31)                                         /* (PIO_P_IMR) Input Change Interrupt Mask Position */
#define PIO_P_IMR_P31_Msk                     (_UINT32_(0x1) << PIO_P_IMR_P31_Pos)                 /* (PIO_P_IMR) Input Change Interrupt Mask Mask */
#define PIO_P_IMR_P31(value)                  (PIO_P_IMR_P31_Msk & (_UINT32_(value) << PIO_P_IMR_P31_Pos)) /* Assigment of value for P31 in the PIO_P_IMR register */
#define PIO_P_IMR_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (PIO_P_IMR) Register Mask  */

#define PIO_P_IMR_P_Pos                       _UINT32_(0)                                          /* (PIO_P_IMR Position) Input Change Interrupt Mask */
#define PIO_P_IMR_P_Msk                       (_UINT32_(0xFFFFFFFF) << PIO_P_IMR_P_Pos)            /* (PIO_P_IMR Mask) P */
#define PIO_P_IMR_P(value)                    (PIO_P_IMR_P_Msk & (_UINT32_(value) << PIO_P_IMR_P_Pos)) 

/* -------- PIO_P_ISR : (PIO Offset: 0x2C) ( R/ 32) PIO Privilege Interrupt Status Register (p_iogroup = 0) -------- */
#define PIO_P_ISR_P0_Pos                      _UINT32_(0)                                          /* (PIO_P_ISR) Input Change Interrupt Status Position */
#define PIO_P_ISR_P0_Msk                      (_UINT32_(0x1) << PIO_P_ISR_P0_Pos)                  /* (PIO_P_ISR) Input Change Interrupt Status Mask */
#define PIO_P_ISR_P0(value)                   (PIO_P_ISR_P0_Msk & (_UINT32_(value) << PIO_P_ISR_P0_Pos)) /* Assigment of value for P0 in the PIO_P_ISR register */
#define PIO_P_ISR_P1_Pos                      _UINT32_(1)                                          /* (PIO_P_ISR) Input Change Interrupt Status Position */
#define PIO_P_ISR_P1_Msk                      (_UINT32_(0x1) << PIO_P_ISR_P1_Pos)                  /* (PIO_P_ISR) Input Change Interrupt Status Mask */
#define PIO_P_ISR_P1(value)                   (PIO_P_ISR_P1_Msk & (_UINT32_(value) << PIO_P_ISR_P1_Pos)) /* Assigment of value for P1 in the PIO_P_ISR register */
#define PIO_P_ISR_P2_Pos                      _UINT32_(2)                                          /* (PIO_P_ISR) Input Change Interrupt Status Position */
#define PIO_P_ISR_P2_Msk                      (_UINT32_(0x1) << PIO_P_ISR_P2_Pos)                  /* (PIO_P_ISR) Input Change Interrupt Status Mask */
#define PIO_P_ISR_P2(value)                   (PIO_P_ISR_P2_Msk & (_UINT32_(value) << PIO_P_ISR_P2_Pos)) /* Assigment of value for P2 in the PIO_P_ISR register */
#define PIO_P_ISR_P3_Pos                      _UINT32_(3)                                          /* (PIO_P_ISR) Input Change Interrupt Status Position */
#define PIO_P_ISR_P3_Msk                      (_UINT32_(0x1) << PIO_P_ISR_P3_Pos)                  /* (PIO_P_ISR) Input Change Interrupt Status Mask */
#define PIO_P_ISR_P3(value)                   (PIO_P_ISR_P3_Msk & (_UINT32_(value) << PIO_P_ISR_P3_Pos)) /* Assigment of value for P3 in the PIO_P_ISR register */
#define PIO_P_ISR_P4_Pos                      _UINT32_(4)                                          /* (PIO_P_ISR) Input Change Interrupt Status Position */
#define PIO_P_ISR_P4_Msk                      (_UINT32_(0x1) << PIO_P_ISR_P4_Pos)                  /* (PIO_P_ISR) Input Change Interrupt Status Mask */
#define PIO_P_ISR_P4(value)                   (PIO_P_ISR_P4_Msk & (_UINT32_(value) << PIO_P_ISR_P4_Pos)) /* Assigment of value for P4 in the PIO_P_ISR register */
#define PIO_P_ISR_P5_Pos                      _UINT32_(5)                                          /* (PIO_P_ISR) Input Change Interrupt Status Position */
#define PIO_P_ISR_P5_Msk                      (_UINT32_(0x1) << PIO_P_ISR_P5_Pos)                  /* (PIO_P_ISR) Input Change Interrupt Status Mask */
#define PIO_P_ISR_P5(value)                   (PIO_P_ISR_P5_Msk & (_UINT32_(value) << PIO_P_ISR_P5_Pos)) /* Assigment of value for P5 in the PIO_P_ISR register */
#define PIO_P_ISR_P6_Pos                      _UINT32_(6)                                          /* (PIO_P_ISR) Input Change Interrupt Status Position */
#define PIO_P_ISR_P6_Msk                      (_UINT32_(0x1) << PIO_P_ISR_P6_Pos)                  /* (PIO_P_ISR) Input Change Interrupt Status Mask */
#define PIO_P_ISR_P6(value)                   (PIO_P_ISR_P6_Msk & (_UINT32_(value) << PIO_P_ISR_P6_Pos)) /* Assigment of value for P6 in the PIO_P_ISR register */
#define PIO_P_ISR_P7_Pos                      _UINT32_(7)                                          /* (PIO_P_ISR) Input Change Interrupt Status Position */
#define PIO_P_ISR_P7_Msk                      (_UINT32_(0x1) << PIO_P_ISR_P7_Pos)                  /* (PIO_P_ISR) Input Change Interrupt Status Mask */
#define PIO_P_ISR_P7(value)                   (PIO_P_ISR_P7_Msk & (_UINT32_(value) << PIO_P_ISR_P7_Pos)) /* Assigment of value for P7 in the PIO_P_ISR register */
#define PIO_P_ISR_P8_Pos                      _UINT32_(8)                                          /* (PIO_P_ISR) Input Change Interrupt Status Position */
#define PIO_P_ISR_P8_Msk                      (_UINT32_(0x1) << PIO_P_ISR_P8_Pos)                  /* (PIO_P_ISR) Input Change Interrupt Status Mask */
#define PIO_P_ISR_P8(value)                   (PIO_P_ISR_P8_Msk & (_UINT32_(value) << PIO_P_ISR_P8_Pos)) /* Assigment of value for P8 in the PIO_P_ISR register */
#define PIO_P_ISR_P9_Pos                      _UINT32_(9)                                          /* (PIO_P_ISR) Input Change Interrupt Status Position */
#define PIO_P_ISR_P9_Msk                      (_UINT32_(0x1) << PIO_P_ISR_P9_Pos)                  /* (PIO_P_ISR) Input Change Interrupt Status Mask */
#define PIO_P_ISR_P9(value)                   (PIO_P_ISR_P9_Msk & (_UINT32_(value) << PIO_P_ISR_P9_Pos)) /* Assigment of value for P9 in the PIO_P_ISR register */
#define PIO_P_ISR_P10_Pos                     _UINT32_(10)                                         /* (PIO_P_ISR) Input Change Interrupt Status Position */
#define PIO_P_ISR_P10_Msk                     (_UINT32_(0x1) << PIO_P_ISR_P10_Pos)                 /* (PIO_P_ISR) Input Change Interrupt Status Mask */
#define PIO_P_ISR_P10(value)                  (PIO_P_ISR_P10_Msk & (_UINT32_(value) << PIO_P_ISR_P10_Pos)) /* Assigment of value for P10 in the PIO_P_ISR register */
#define PIO_P_ISR_P11_Pos                     _UINT32_(11)                                         /* (PIO_P_ISR) Input Change Interrupt Status Position */
#define PIO_P_ISR_P11_Msk                     (_UINT32_(0x1) << PIO_P_ISR_P11_Pos)                 /* (PIO_P_ISR) Input Change Interrupt Status Mask */
#define PIO_P_ISR_P11(value)                  (PIO_P_ISR_P11_Msk & (_UINT32_(value) << PIO_P_ISR_P11_Pos)) /* Assigment of value for P11 in the PIO_P_ISR register */
#define PIO_P_ISR_P12_Pos                     _UINT32_(12)                                         /* (PIO_P_ISR) Input Change Interrupt Status Position */
#define PIO_P_ISR_P12_Msk                     (_UINT32_(0x1) << PIO_P_ISR_P12_Pos)                 /* (PIO_P_ISR) Input Change Interrupt Status Mask */
#define PIO_P_ISR_P12(value)                  (PIO_P_ISR_P12_Msk & (_UINT32_(value) << PIO_P_ISR_P12_Pos)) /* Assigment of value for P12 in the PIO_P_ISR register */
#define PIO_P_ISR_P13_Pos                     _UINT32_(13)                                         /* (PIO_P_ISR) Input Change Interrupt Status Position */
#define PIO_P_ISR_P13_Msk                     (_UINT32_(0x1) << PIO_P_ISR_P13_Pos)                 /* (PIO_P_ISR) Input Change Interrupt Status Mask */
#define PIO_P_ISR_P13(value)                  (PIO_P_ISR_P13_Msk & (_UINT32_(value) << PIO_P_ISR_P13_Pos)) /* Assigment of value for P13 in the PIO_P_ISR register */
#define PIO_P_ISR_P14_Pos                     _UINT32_(14)                                         /* (PIO_P_ISR) Input Change Interrupt Status Position */
#define PIO_P_ISR_P14_Msk                     (_UINT32_(0x1) << PIO_P_ISR_P14_Pos)                 /* (PIO_P_ISR) Input Change Interrupt Status Mask */
#define PIO_P_ISR_P14(value)                  (PIO_P_ISR_P14_Msk & (_UINT32_(value) << PIO_P_ISR_P14_Pos)) /* Assigment of value for P14 in the PIO_P_ISR register */
#define PIO_P_ISR_P15_Pos                     _UINT32_(15)                                         /* (PIO_P_ISR) Input Change Interrupt Status Position */
#define PIO_P_ISR_P15_Msk                     (_UINT32_(0x1) << PIO_P_ISR_P15_Pos)                 /* (PIO_P_ISR) Input Change Interrupt Status Mask */
#define PIO_P_ISR_P15(value)                  (PIO_P_ISR_P15_Msk & (_UINT32_(value) << PIO_P_ISR_P15_Pos)) /* Assigment of value for P15 in the PIO_P_ISR register */
#define PIO_P_ISR_P16_Pos                     _UINT32_(16)                                         /* (PIO_P_ISR) Input Change Interrupt Status Position */
#define PIO_P_ISR_P16_Msk                     (_UINT32_(0x1) << PIO_P_ISR_P16_Pos)                 /* (PIO_P_ISR) Input Change Interrupt Status Mask */
#define PIO_P_ISR_P16(value)                  (PIO_P_ISR_P16_Msk & (_UINT32_(value) << PIO_P_ISR_P16_Pos)) /* Assigment of value for P16 in the PIO_P_ISR register */
#define PIO_P_ISR_P17_Pos                     _UINT32_(17)                                         /* (PIO_P_ISR) Input Change Interrupt Status Position */
#define PIO_P_ISR_P17_Msk                     (_UINT32_(0x1) << PIO_P_ISR_P17_Pos)                 /* (PIO_P_ISR) Input Change Interrupt Status Mask */
#define PIO_P_ISR_P17(value)                  (PIO_P_ISR_P17_Msk & (_UINT32_(value) << PIO_P_ISR_P17_Pos)) /* Assigment of value for P17 in the PIO_P_ISR register */
#define PIO_P_ISR_P18_Pos                     _UINT32_(18)                                         /* (PIO_P_ISR) Input Change Interrupt Status Position */
#define PIO_P_ISR_P18_Msk                     (_UINT32_(0x1) << PIO_P_ISR_P18_Pos)                 /* (PIO_P_ISR) Input Change Interrupt Status Mask */
#define PIO_P_ISR_P18(value)                  (PIO_P_ISR_P18_Msk & (_UINT32_(value) << PIO_P_ISR_P18_Pos)) /* Assigment of value for P18 in the PIO_P_ISR register */
#define PIO_P_ISR_P19_Pos                     _UINT32_(19)                                         /* (PIO_P_ISR) Input Change Interrupt Status Position */
#define PIO_P_ISR_P19_Msk                     (_UINT32_(0x1) << PIO_P_ISR_P19_Pos)                 /* (PIO_P_ISR) Input Change Interrupt Status Mask */
#define PIO_P_ISR_P19(value)                  (PIO_P_ISR_P19_Msk & (_UINT32_(value) << PIO_P_ISR_P19_Pos)) /* Assigment of value for P19 in the PIO_P_ISR register */
#define PIO_P_ISR_P20_Pos                     _UINT32_(20)                                         /* (PIO_P_ISR) Input Change Interrupt Status Position */
#define PIO_P_ISR_P20_Msk                     (_UINT32_(0x1) << PIO_P_ISR_P20_Pos)                 /* (PIO_P_ISR) Input Change Interrupt Status Mask */
#define PIO_P_ISR_P20(value)                  (PIO_P_ISR_P20_Msk & (_UINT32_(value) << PIO_P_ISR_P20_Pos)) /* Assigment of value for P20 in the PIO_P_ISR register */
#define PIO_P_ISR_P21_Pos                     _UINT32_(21)                                         /* (PIO_P_ISR) Input Change Interrupt Status Position */
#define PIO_P_ISR_P21_Msk                     (_UINT32_(0x1) << PIO_P_ISR_P21_Pos)                 /* (PIO_P_ISR) Input Change Interrupt Status Mask */
#define PIO_P_ISR_P21(value)                  (PIO_P_ISR_P21_Msk & (_UINT32_(value) << PIO_P_ISR_P21_Pos)) /* Assigment of value for P21 in the PIO_P_ISR register */
#define PIO_P_ISR_P22_Pos                     _UINT32_(22)                                         /* (PIO_P_ISR) Input Change Interrupt Status Position */
#define PIO_P_ISR_P22_Msk                     (_UINT32_(0x1) << PIO_P_ISR_P22_Pos)                 /* (PIO_P_ISR) Input Change Interrupt Status Mask */
#define PIO_P_ISR_P22(value)                  (PIO_P_ISR_P22_Msk & (_UINT32_(value) << PIO_P_ISR_P22_Pos)) /* Assigment of value for P22 in the PIO_P_ISR register */
#define PIO_P_ISR_P23_Pos                     _UINT32_(23)                                         /* (PIO_P_ISR) Input Change Interrupt Status Position */
#define PIO_P_ISR_P23_Msk                     (_UINT32_(0x1) << PIO_P_ISR_P23_Pos)                 /* (PIO_P_ISR) Input Change Interrupt Status Mask */
#define PIO_P_ISR_P23(value)                  (PIO_P_ISR_P23_Msk & (_UINT32_(value) << PIO_P_ISR_P23_Pos)) /* Assigment of value for P23 in the PIO_P_ISR register */
#define PIO_P_ISR_P24_Pos                     _UINT32_(24)                                         /* (PIO_P_ISR) Input Change Interrupt Status Position */
#define PIO_P_ISR_P24_Msk                     (_UINT32_(0x1) << PIO_P_ISR_P24_Pos)                 /* (PIO_P_ISR) Input Change Interrupt Status Mask */
#define PIO_P_ISR_P24(value)                  (PIO_P_ISR_P24_Msk & (_UINT32_(value) << PIO_P_ISR_P24_Pos)) /* Assigment of value for P24 in the PIO_P_ISR register */
#define PIO_P_ISR_P25_Pos                     _UINT32_(25)                                         /* (PIO_P_ISR) Input Change Interrupt Status Position */
#define PIO_P_ISR_P25_Msk                     (_UINT32_(0x1) << PIO_P_ISR_P25_Pos)                 /* (PIO_P_ISR) Input Change Interrupt Status Mask */
#define PIO_P_ISR_P25(value)                  (PIO_P_ISR_P25_Msk & (_UINT32_(value) << PIO_P_ISR_P25_Pos)) /* Assigment of value for P25 in the PIO_P_ISR register */
#define PIO_P_ISR_P26_Pos                     _UINT32_(26)                                         /* (PIO_P_ISR) Input Change Interrupt Status Position */
#define PIO_P_ISR_P26_Msk                     (_UINT32_(0x1) << PIO_P_ISR_P26_Pos)                 /* (PIO_P_ISR) Input Change Interrupt Status Mask */
#define PIO_P_ISR_P26(value)                  (PIO_P_ISR_P26_Msk & (_UINT32_(value) << PIO_P_ISR_P26_Pos)) /* Assigment of value for P26 in the PIO_P_ISR register */
#define PIO_P_ISR_P27_Pos                     _UINT32_(27)                                         /* (PIO_P_ISR) Input Change Interrupt Status Position */
#define PIO_P_ISR_P27_Msk                     (_UINT32_(0x1) << PIO_P_ISR_P27_Pos)                 /* (PIO_P_ISR) Input Change Interrupt Status Mask */
#define PIO_P_ISR_P27(value)                  (PIO_P_ISR_P27_Msk & (_UINT32_(value) << PIO_P_ISR_P27_Pos)) /* Assigment of value for P27 in the PIO_P_ISR register */
#define PIO_P_ISR_P28_Pos                     _UINT32_(28)                                         /* (PIO_P_ISR) Input Change Interrupt Status Position */
#define PIO_P_ISR_P28_Msk                     (_UINT32_(0x1) << PIO_P_ISR_P28_Pos)                 /* (PIO_P_ISR) Input Change Interrupt Status Mask */
#define PIO_P_ISR_P28(value)                  (PIO_P_ISR_P28_Msk & (_UINT32_(value) << PIO_P_ISR_P28_Pos)) /* Assigment of value for P28 in the PIO_P_ISR register */
#define PIO_P_ISR_P29_Pos                     _UINT32_(29)                                         /* (PIO_P_ISR) Input Change Interrupt Status Position */
#define PIO_P_ISR_P29_Msk                     (_UINT32_(0x1) << PIO_P_ISR_P29_Pos)                 /* (PIO_P_ISR) Input Change Interrupt Status Mask */
#define PIO_P_ISR_P29(value)                  (PIO_P_ISR_P29_Msk & (_UINT32_(value) << PIO_P_ISR_P29_Pos)) /* Assigment of value for P29 in the PIO_P_ISR register */
#define PIO_P_ISR_P30_Pos                     _UINT32_(30)                                         /* (PIO_P_ISR) Input Change Interrupt Status Position */
#define PIO_P_ISR_P30_Msk                     (_UINT32_(0x1) << PIO_P_ISR_P30_Pos)                 /* (PIO_P_ISR) Input Change Interrupt Status Mask */
#define PIO_P_ISR_P30(value)                  (PIO_P_ISR_P30_Msk & (_UINT32_(value) << PIO_P_ISR_P30_Pos)) /* Assigment of value for P30 in the PIO_P_ISR register */
#define PIO_P_ISR_P31_Pos                     _UINT32_(31)                                         /* (PIO_P_ISR) Input Change Interrupt Status Position */
#define PIO_P_ISR_P31_Msk                     (_UINT32_(0x1) << PIO_P_ISR_P31_Pos)                 /* (PIO_P_ISR) Input Change Interrupt Status Mask */
#define PIO_P_ISR_P31(value)                  (PIO_P_ISR_P31_Msk & (_UINT32_(value) << PIO_P_ISR_P31_Pos)) /* Assigment of value for P31 in the PIO_P_ISR register */
#define PIO_P_ISR_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (PIO_P_ISR) Register Mask  */

#define PIO_P_ISR_P_Pos                       _UINT32_(0)                                          /* (PIO_P_ISR Position) Input Change Interrupt Status */
#define PIO_P_ISR_P_Msk                       (_UINT32_(0xFFFFFFFF) << PIO_P_ISR_P_Pos)            /* (PIO_P_ISR Mask) P */
#define PIO_P_ISR_P(value)                    (PIO_P_ISR_P_Msk & (_UINT32_(value) << PIO_P_ISR_P_Pos)) 

/* -------- PIO_P_SIO_UAR : (PIO Offset: 0x30) ( /W 32) PIO Privilege Set I/O User Register (p_iogroup = 0) -------- */
#define PIO_P_SIO_UAR_P0_Pos                  _UINT32_(0)                                          /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Position */
#define PIO_P_SIO_UAR_P0_Msk                  (_UINT32_(0x1) << PIO_P_SIO_UAR_P0_Pos)              /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Mask */
#define PIO_P_SIO_UAR_P0(value)               (PIO_P_SIO_UAR_P0_Msk & (_UINT32_(value) << PIO_P_SIO_UAR_P0_Pos)) /* Assigment of value for P0 in the PIO_P_SIO_UAR register */
#define PIO_P_SIO_UAR_P1_Pos                  _UINT32_(1)                                          /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Position */
#define PIO_P_SIO_UAR_P1_Msk                  (_UINT32_(0x1) << PIO_P_SIO_UAR_P1_Pos)              /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Mask */
#define PIO_P_SIO_UAR_P1(value)               (PIO_P_SIO_UAR_P1_Msk & (_UINT32_(value) << PIO_P_SIO_UAR_P1_Pos)) /* Assigment of value for P1 in the PIO_P_SIO_UAR register */
#define PIO_P_SIO_UAR_P2_Pos                  _UINT32_(2)                                          /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Position */
#define PIO_P_SIO_UAR_P2_Msk                  (_UINT32_(0x1) << PIO_P_SIO_UAR_P2_Pos)              /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Mask */
#define PIO_P_SIO_UAR_P2(value)               (PIO_P_SIO_UAR_P2_Msk & (_UINT32_(value) << PIO_P_SIO_UAR_P2_Pos)) /* Assigment of value for P2 in the PIO_P_SIO_UAR register */
#define PIO_P_SIO_UAR_P3_Pos                  _UINT32_(3)                                          /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Position */
#define PIO_P_SIO_UAR_P3_Msk                  (_UINT32_(0x1) << PIO_P_SIO_UAR_P3_Pos)              /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Mask */
#define PIO_P_SIO_UAR_P3(value)               (PIO_P_SIO_UAR_P3_Msk & (_UINT32_(value) << PIO_P_SIO_UAR_P3_Pos)) /* Assigment of value for P3 in the PIO_P_SIO_UAR register */
#define PIO_P_SIO_UAR_P4_Pos                  _UINT32_(4)                                          /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Position */
#define PIO_P_SIO_UAR_P4_Msk                  (_UINT32_(0x1) << PIO_P_SIO_UAR_P4_Pos)              /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Mask */
#define PIO_P_SIO_UAR_P4(value)               (PIO_P_SIO_UAR_P4_Msk & (_UINT32_(value) << PIO_P_SIO_UAR_P4_Pos)) /* Assigment of value for P4 in the PIO_P_SIO_UAR register */
#define PIO_P_SIO_UAR_P5_Pos                  _UINT32_(5)                                          /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Position */
#define PIO_P_SIO_UAR_P5_Msk                  (_UINT32_(0x1) << PIO_P_SIO_UAR_P5_Pos)              /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Mask */
#define PIO_P_SIO_UAR_P5(value)               (PIO_P_SIO_UAR_P5_Msk & (_UINT32_(value) << PIO_P_SIO_UAR_P5_Pos)) /* Assigment of value for P5 in the PIO_P_SIO_UAR register */
#define PIO_P_SIO_UAR_P6_Pos                  _UINT32_(6)                                          /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Position */
#define PIO_P_SIO_UAR_P6_Msk                  (_UINT32_(0x1) << PIO_P_SIO_UAR_P6_Pos)              /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Mask */
#define PIO_P_SIO_UAR_P6(value)               (PIO_P_SIO_UAR_P6_Msk & (_UINT32_(value) << PIO_P_SIO_UAR_P6_Pos)) /* Assigment of value for P6 in the PIO_P_SIO_UAR register */
#define PIO_P_SIO_UAR_P7_Pos                  _UINT32_(7)                                          /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Position */
#define PIO_P_SIO_UAR_P7_Msk                  (_UINT32_(0x1) << PIO_P_SIO_UAR_P7_Pos)              /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Mask */
#define PIO_P_SIO_UAR_P7(value)               (PIO_P_SIO_UAR_P7_Msk & (_UINT32_(value) << PIO_P_SIO_UAR_P7_Pos)) /* Assigment of value for P7 in the PIO_P_SIO_UAR register */
#define PIO_P_SIO_UAR_P8_Pos                  _UINT32_(8)                                          /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Position */
#define PIO_P_SIO_UAR_P8_Msk                  (_UINT32_(0x1) << PIO_P_SIO_UAR_P8_Pos)              /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Mask */
#define PIO_P_SIO_UAR_P8(value)               (PIO_P_SIO_UAR_P8_Msk & (_UINT32_(value) << PIO_P_SIO_UAR_P8_Pos)) /* Assigment of value for P8 in the PIO_P_SIO_UAR register */
#define PIO_P_SIO_UAR_P9_Pos                  _UINT32_(9)                                          /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Position */
#define PIO_P_SIO_UAR_P9_Msk                  (_UINT32_(0x1) << PIO_P_SIO_UAR_P9_Pos)              /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Mask */
#define PIO_P_SIO_UAR_P9(value)               (PIO_P_SIO_UAR_P9_Msk & (_UINT32_(value) << PIO_P_SIO_UAR_P9_Pos)) /* Assigment of value for P9 in the PIO_P_SIO_UAR register */
#define PIO_P_SIO_UAR_P10_Pos                 _UINT32_(10)                                         /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Position */
#define PIO_P_SIO_UAR_P10_Msk                 (_UINT32_(0x1) << PIO_P_SIO_UAR_P10_Pos)             /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Mask */
#define PIO_P_SIO_UAR_P10(value)              (PIO_P_SIO_UAR_P10_Msk & (_UINT32_(value) << PIO_P_SIO_UAR_P10_Pos)) /* Assigment of value for P10 in the PIO_P_SIO_UAR register */
#define PIO_P_SIO_UAR_P11_Pos                 _UINT32_(11)                                         /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Position */
#define PIO_P_SIO_UAR_P11_Msk                 (_UINT32_(0x1) << PIO_P_SIO_UAR_P11_Pos)             /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Mask */
#define PIO_P_SIO_UAR_P11(value)              (PIO_P_SIO_UAR_P11_Msk & (_UINT32_(value) << PIO_P_SIO_UAR_P11_Pos)) /* Assigment of value for P11 in the PIO_P_SIO_UAR register */
#define PIO_P_SIO_UAR_P12_Pos                 _UINT32_(12)                                         /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Position */
#define PIO_P_SIO_UAR_P12_Msk                 (_UINT32_(0x1) << PIO_P_SIO_UAR_P12_Pos)             /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Mask */
#define PIO_P_SIO_UAR_P12(value)              (PIO_P_SIO_UAR_P12_Msk & (_UINT32_(value) << PIO_P_SIO_UAR_P12_Pos)) /* Assigment of value for P12 in the PIO_P_SIO_UAR register */
#define PIO_P_SIO_UAR_P13_Pos                 _UINT32_(13)                                         /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Position */
#define PIO_P_SIO_UAR_P13_Msk                 (_UINT32_(0x1) << PIO_P_SIO_UAR_P13_Pos)             /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Mask */
#define PIO_P_SIO_UAR_P13(value)              (PIO_P_SIO_UAR_P13_Msk & (_UINT32_(value) << PIO_P_SIO_UAR_P13_Pos)) /* Assigment of value for P13 in the PIO_P_SIO_UAR register */
#define PIO_P_SIO_UAR_P14_Pos                 _UINT32_(14)                                         /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Position */
#define PIO_P_SIO_UAR_P14_Msk                 (_UINT32_(0x1) << PIO_P_SIO_UAR_P14_Pos)             /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Mask */
#define PIO_P_SIO_UAR_P14(value)              (PIO_P_SIO_UAR_P14_Msk & (_UINT32_(value) << PIO_P_SIO_UAR_P14_Pos)) /* Assigment of value for P14 in the PIO_P_SIO_UAR register */
#define PIO_P_SIO_UAR_P15_Pos                 _UINT32_(15)                                         /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Position */
#define PIO_P_SIO_UAR_P15_Msk                 (_UINT32_(0x1) << PIO_P_SIO_UAR_P15_Pos)             /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Mask */
#define PIO_P_SIO_UAR_P15(value)              (PIO_P_SIO_UAR_P15_Msk & (_UINT32_(value) << PIO_P_SIO_UAR_P15_Pos)) /* Assigment of value for P15 in the PIO_P_SIO_UAR register */
#define PIO_P_SIO_UAR_P16_Pos                 _UINT32_(16)                                         /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Position */
#define PIO_P_SIO_UAR_P16_Msk                 (_UINT32_(0x1) << PIO_P_SIO_UAR_P16_Pos)             /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Mask */
#define PIO_P_SIO_UAR_P16(value)              (PIO_P_SIO_UAR_P16_Msk & (_UINT32_(value) << PIO_P_SIO_UAR_P16_Pos)) /* Assigment of value for P16 in the PIO_P_SIO_UAR register */
#define PIO_P_SIO_UAR_P17_Pos                 _UINT32_(17)                                         /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Position */
#define PIO_P_SIO_UAR_P17_Msk                 (_UINT32_(0x1) << PIO_P_SIO_UAR_P17_Pos)             /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Mask */
#define PIO_P_SIO_UAR_P17(value)              (PIO_P_SIO_UAR_P17_Msk & (_UINT32_(value) << PIO_P_SIO_UAR_P17_Pos)) /* Assigment of value for P17 in the PIO_P_SIO_UAR register */
#define PIO_P_SIO_UAR_P18_Pos                 _UINT32_(18)                                         /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Position */
#define PIO_P_SIO_UAR_P18_Msk                 (_UINT32_(0x1) << PIO_P_SIO_UAR_P18_Pos)             /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Mask */
#define PIO_P_SIO_UAR_P18(value)              (PIO_P_SIO_UAR_P18_Msk & (_UINT32_(value) << PIO_P_SIO_UAR_P18_Pos)) /* Assigment of value for P18 in the PIO_P_SIO_UAR register */
#define PIO_P_SIO_UAR_P19_Pos                 _UINT32_(19)                                         /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Position */
#define PIO_P_SIO_UAR_P19_Msk                 (_UINT32_(0x1) << PIO_P_SIO_UAR_P19_Pos)             /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Mask */
#define PIO_P_SIO_UAR_P19(value)              (PIO_P_SIO_UAR_P19_Msk & (_UINT32_(value) << PIO_P_SIO_UAR_P19_Pos)) /* Assigment of value for P19 in the PIO_P_SIO_UAR register */
#define PIO_P_SIO_UAR_P20_Pos                 _UINT32_(20)                                         /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Position */
#define PIO_P_SIO_UAR_P20_Msk                 (_UINT32_(0x1) << PIO_P_SIO_UAR_P20_Pos)             /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Mask */
#define PIO_P_SIO_UAR_P20(value)              (PIO_P_SIO_UAR_P20_Msk & (_UINT32_(value) << PIO_P_SIO_UAR_P20_Pos)) /* Assigment of value for P20 in the PIO_P_SIO_UAR register */
#define PIO_P_SIO_UAR_P21_Pos                 _UINT32_(21)                                         /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Position */
#define PIO_P_SIO_UAR_P21_Msk                 (_UINT32_(0x1) << PIO_P_SIO_UAR_P21_Pos)             /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Mask */
#define PIO_P_SIO_UAR_P21(value)              (PIO_P_SIO_UAR_P21_Msk & (_UINT32_(value) << PIO_P_SIO_UAR_P21_Pos)) /* Assigment of value for P21 in the PIO_P_SIO_UAR register */
#define PIO_P_SIO_UAR_P22_Pos                 _UINT32_(22)                                         /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Position */
#define PIO_P_SIO_UAR_P22_Msk                 (_UINT32_(0x1) << PIO_P_SIO_UAR_P22_Pos)             /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Mask */
#define PIO_P_SIO_UAR_P22(value)              (PIO_P_SIO_UAR_P22_Msk & (_UINT32_(value) << PIO_P_SIO_UAR_P22_Pos)) /* Assigment of value for P22 in the PIO_P_SIO_UAR register */
#define PIO_P_SIO_UAR_P23_Pos                 _UINT32_(23)                                         /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Position */
#define PIO_P_SIO_UAR_P23_Msk                 (_UINT32_(0x1) << PIO_P_SIO_UAR_P23_Pos)             /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Mask */
#define PIO_P_SIO_UAR_P23(value)              (PIO_P_SIO_UAR_P23_Msk & (_UINT32_(value) << PIO_P_SIO_UAR_P23_Pos)) /* Assigment of value for P23 in the PIO_P_SIO_UAR register */
#define PIO_P_SIO_UAR_P24_Pos                 _UINT32_(24)                                         /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Position */
#define PIO_P_SIO_UAR_P24_Msk                 (_UINT32_(0x1) << PIO_P_SIO_UAR_P24_Pos)             /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Mask */
#define PIO_P_SIO_UAR_P24(value)              (PIO_P_SIO_UAR_P24_Msk & (_UINT32_(value) << PIO_P_SIO_UAR_P24_Pos)) /* Assigment of value for P24 in the PIO_P_SIO_UAR register */
#define PIO_P_SIO_UAR_P25_Pos                 _UINT32_(25)                                         /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Position */
#define PIO_P_SIO_UAR_P25_Msk                 (_UINT32_(0x1) << PIO_P_SIO_UAR_P25_Pos)             /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Mask */
#define PIO_P_SIO_UAR_P25(value)              (PIO_P_SIO_UAR_P25_Msk & (_UINT32_(value) << PIO_P_SIO_UAR_P25_Pos)) /* Assigment of value for P25 in the PIO_P_SIO_UAR register */
#define PIO_P_SIO_UAR_P26_Pos                 _UINT32_(26)                                         /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Position */
#define PIO_P_SIO_UAR_P26_Msk                 (_UINT32_(0x1) << PIO_P_SIO_UAR_P26_Pos)             /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Mask */
#define PIO_P_SIO_UAR_P26(value)              (PIO_P_SIO_UAR_P26_Msk & (_UINT32_(value) << PIO_P_SIO_UAR_P26_Pos)) /* Assigment of value for P26 in the PIO_P_SIO_UAR register */
#define PIO_P_SIO_UAR_P27_Pos                 _UINT32_(27)                                         /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Position */
#define PIO_P_SIO_UAR_P27_Msk                 (_UINT32_(0x1) << PIO_P_SIO_UAR_P27_Pos)             /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Mask */
#define PIO_P_SIO_UAR_P27(value)              (PIO_P_SIO_UAR_P27_Msk & (_UINT32_(value) << PIO_P_SIO_UAR_P27_Pos)) /* Assigment of value for P27 in the PIO_P_SIO_UAR register */
#define PIO_P_SIO_UAR_P28_Pos                 _UINT32_(28)                                         /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Position */
#define PIO_P_SIO_UAR_P28_Msk                 (_UINT32_(0x1) << PIO_P_SIO_UAR_P28_Pos)             /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Mask */
#define PIO_P_SIO_UAR_P28(value)              (PIO_P_SIO_UAR_P28_Msk & (_UINT32_(value) << PIO_P_SIO_UAR_P28_Pos)) /* Assigment of value for P28 in the PIO_P_SIO_UAR register */
#define PIO_P_SIO_UAR_P29_Pos                 _UINT32_(29)                                         /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Position */
#define PIO_P_SIO_UAR_P29_Msk                 (_UINT32_(0x1) << PIO_P_SIO_UAR_P29_Pos)             /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Mask */
#define PIO_P_SIO_UAR_P29(value)              (PIO_P_SIO_UAR_P29_Msk & (_UINT32_(value) << PIO_P_SIO_UAR_P29_Pos)) /* Assigment of value for P29 in the PIO_P_SIO_UAR register */
#define PIO_P_SIO_UAR_P30_Pos                 _UINT32_(30)                                         /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Position */
#define PIO_P_SIO_UAR_P30_Msk                 (_UINT32_(0x1) << PIO_P_SIO_UAR_P30_Pos)             /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Mask */
#define PIO_P_SIO_UAR_P30(value)              (PIO_P_SIO_UAR_P30_Msk & (_UINT32_(value) << PIO_P_SIO_UAR_P30_Pos)) /* Assigment of value for P30 in the PIO_P_SIO_UAR register */
#define PIO_P_SIO_UAR_P31_Pos                 _UINT32_(31)                                         /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Position */
#define PIO_P_SIO_UAR_P31_Msk                 (_UINT32_(0x1) << PIO_P_SIO_UAR_P31_Pos)             /* (PIO_P_SIO_UAR) Set I/O in User-Access mode Mask */
#define PIO_P_SIO_UAR_P31(value)              (PIO_P_SIO_UAR_P31_Msk & (_UINT32_(value) << PIO_P_SIO_UAR_P31_Pos)) /* Assigment of value for P31 in the PIO_P_SIO_UAR register */
#define PIO_P_SIO_UAR_Msk                     _UINT32_(0xFFFFFFFF)                                 /* (PIO_P_SIO_UAR) Register Mask  */

#define PIO_P_SIO_UAR_P_Pos                   _UINT32_(0)                                          /* (PIO_P_SIO_UAR Position) Set I/O in User-Access mode */
#define PIO_P_SIO_UAR_P_Msk                   (_UINT32_(0xFFFFFFFF) << PIO_P_SIO_UAR_P_Pos)        /* (PIO_P_SIO_UAR Mask) P */
#define PIO_P_SIO_UAR_P(value)                (PIO_P_SIO_UAR_P_Msk & (_UINT32_(value) << PIO_P_SIO_UAR_P_Pos)) 

/* -------- PIO_P_SIO_PAR : (PIO Offset: 0x34) ( /W 32) PIO Privilege Set I/O Privilege Register (p_iogroup = 0) -------- */
#define PIO_P_SIO_PAR_P0_Pos                  _UINT32_(0)                                          /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Position */
#define PIO_P_SIO_PAR_P0_Msk                  (_UINT32_(0x1) << PIO_P_SIO_PAR_P0_Pos)              /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Mask */
#define PIO_P_SIO_PAR_P0(value)               (PIO_P_SIO_PAR_P0_Msk & (_UINT32_(value) << PIO_P_SIO_PAR_P0_Pos)) /* Assigment of value for P0 in the PIO_P_SIO_PAR register */
#define PIO_P_SIO_PAR_P1_Pos                  _UINT32_(1)                                          /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Position */
#define PIO_P_SIO_PAR_P1_Msk                  (_UINT32_(0x1) << PIO_P_SIO_PAR_P1_Pos)              /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Mask */
#define PIO_P_SIO_PAR_P1(value)               (PIO_P_SIO_PAR_P1_Msk & (_UINT32_(value) << PIO_P_SIO_PAR_P1_Pos)) /* Assigment of value for P1 in the PIO_P_SIO_PAR register */
#define PIO_P_SIO_PAR_P2_Pos                  _UINT32_(2)                                          /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Position */
#define PIO_P_SIO_PAR_P2_Msk                  (_UINT32_(0x1) << PIO_P_SIO_PAR_P2_Pos)              /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Mask */
#define PIO_P_SIO_PAR_P2(value)               (PIO_P_SIO_PAR_P2_Msk & (_UINT32_(value) << PIO_P_SIO_PAR_P2_Pos)) /* Assigment of value for P2 in the PIO_P_SIO_PAR register */
#define PIO_P_SIO_PAR_P3_Pos                  _UINT32_(3)                                          /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Position */
#define PIO_P_SIO_PAR_P3_Msk                  (_UINT32_(0x1) << PIO_P_SIO_PAR_P3_Pos)              /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Mask */
#define PIO_P_SIO_PAR_P3(value)               (PIO_P_SIO_PAR_P3_Msk & (_UINT32_(value) << PIO_P_SIO_PAR_P3_Pos)) /* Assigment of value for P3 in the PIO_P_SIO_PAR register */
#define PIO_P_SIO_PAR_P4_Pos                  _UINT32_(4)                                          /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Position */
#define PIO_P_SIO_PAR_P4_Msk                  (_UINT32_(0x1) << PIO_P_SIO_PAR_P4_Pos)              /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Mask */
#define PIO_P_SIO_PAR_P4(value)               (PIO_P_SIO_PAR_P4_Msk & (_UINT32_(value) << PIO_P_SIO_PAR_P4_Pos)) /* Assigment of value for P4 in the PIO_P_SIO_PAR register */
#define PIO_P_SIO_PAR_P5_Pos                  _UINT32_(5)                                          /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Position */
#define PIO_P_SIO_PAR_P5_Msk                  (_UINT32_(0x1) << PIO_P_SIO_PAR_P5_Pos)              /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Mask */
#define PIO_P_SIO_PAR_P5(value)               (PIO_P_SIO_PAR_P5_Msk & (_UINT32_(value) << PIO_P_SIO_PAR_P5_Pos)) /* Assigment of value for P5 in the PIO_P_SIO_PAR register */
#define PIO_P_SIO_PAR_P6_Pos                  _UINT32_(6)                                          /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Position */
#define PIO_P_SIO_PAR_P6_Msk                  (_UINT32_(0x1) << PIO_P_SIO_PAR_P6_Pos)              /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Mask */
#define PIO_P_SIO_PAR_P6(value)               (PIO_P_SIO_PAR_P6_Msk & (_UINT32_(value) << PIO_P_SIO_PAR_P6_Pos)) /* Assigment of value for P6 in the PIO_P_SIO_PAR register */
#define PIO_P_SIO_PAR_P7_Pos                  _UINT32_(7)                                          /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Position */
#define PIO_P_SIO_PAR_P7_Msk                  (_UINT32_(0x1) << PIO_P_SIO_PAR_P7_Pos)              /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Mask */
#define PIO_P_SIO_PAR_P7(value)               (PIO_P_SIO_PAR_P7_Msk & (_UINT32_(value) << PIO_P_SIO_PAR_P7_Pos)) /* Assigment of value for P7 in the PIO_P_SIO_PAR register */
#define PIO_P_SIO_PAR_P8_Pos                  _UINT32_(8)                                          /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Position */
#define PIO_P_SIO_PAR_P8_Msk                  (_UINT32_(0x1) << PIO_P_SIO_PAR_P8_Pos)              /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Mask */
#define PIO_P_SIO_PAR_P8(value)               (PIO_P_SIO_PAR_P8_Msk & (_UINT32_(value) << PIO_P_SIO_PAR_P8_Pos)) /* Assigment of value for P8 in the PIO_P_SIO_PAR register */
#define PIO_P_SIO_PAR_P9_Pos                  _UINT32_(9)                                          /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Position */
#define PIO_P_SIO_PAR_P9_Msk                  (_UINT32_(0x1) << PIO_P_SIO_PAR_P9_Pos)              /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Mask */
#define PIO_P_SIO_PAR_P9(value)               (PIO_P_SIO_PAR_P9_Msk & (_UINT32_(value) << PIO_P_SIO_PAR_P9_Pos)) /* Assigment of value for P9 in the PIO_P_SIO_PAR register */
#define PIO_P_SIO_PAR_P10_Pos                 _UINT32_(10)                                         /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Position */
#define PIO_P_SIO_PAR_P10_Msk                 (_UINT32_(0x1) << PIO_P_SIO_PAR_P10_Pos)             /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Mask */
#define PIO_P_SIO_PAR_P10(value)              (PIO_P_SIO_PAR_P10_Msk & (_UINT32_(value) << PIO_P_SIO_PAR_P10_Pos)) /* Assigment of value for P10 in the PIO_P_SIO_PAR register */
#define PIO_P_SIO_PAR_P11_Pos                 _UINT32_(11)                                         /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Position */
#define PIO_P_SIO_PAR_P11_Msk                 (_UINT32_(0x1) << PIO_P_SIO_PAR_P11_Pos)             /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Mask */
#define PIO_P_SIO_PAR_P11(value)              (PIO_P_SIO_PAR_P11_Msk & (_UINT32_(value) << PIO_P_SIO_PAR_P11_Pos)) /* Assigment of value for P11 in the PIO_P_SIO_PAR register */
#define PIO_P_SIO_PAR_P12_Pos                 _UINT32_(12)                                         /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Position */
#define PIO_P_SIO_PAR_P12_Msk                 (_UINT32_(0x1) << PIO_P_SIO_PAR_P12_Pos)             /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Mask */
#define PIO_P_SIO_PAR_P12(value)              (PIO_P_SIO_PAR_P12_Msk & (_UINT32_(value) << PIO_P_SIO_PAR_P12_Pos)) /* Assigment of value for P12 in the PIO_P_SIO_PAR register */
#define PIO_P_SIO_PAR_P13_Pos                 _UINT32_(13)                                         /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Position */
#define PIO_P_SIO_PAR_P13_Msk                 (_UINT32_(0x1) << PIO_P_SIO_PAR_P13_Pos)             /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Mask */
#define PIO_P_SIO_PAR_P13(value)              (PIO_P_SIO_PAR_P13_Msk & (_UINT32_(value) << PIO_P_SIO_PAR_P13_Pos)) /* Assigment of value for P13 in the PIO_P_SIO_PAR register */
#define PIO_P_SIO_PAR_P14_Pos                 _UINT32_(14)                                         /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Position */
#define PIO_P_SIO_PAR_P14_Msk                 (_UINT32_(0x1) << PIO_P_SIO_PAR_P14_Pos)             /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Mask */
#define PIO_P_SIO_PAR_P14(value)              (PIO_P_SIO_PAR_P14_Msk & (_UINT32_(value) << PIO_P_SIO_PAR_P14_Pos)) /* Assigment of value for P14 in the PIO_P_SIO_PAR register */
#define PIO_P_SIO_PAR_P15_Pos                 _UINT32_(15)                                         /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Position */
#define PIO_P_SIO_PAR_P15_Msk                 (_UINT32_(0x1) << PIO_P_SIO_PAR_P15_Pos)             /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Mask */
#define PIO_P_SIO_PAR_P15(value)              (PIO_P_SIO_PAR_P15_Msk & (_UINT32_(value) << PIO_P_SIO_PAR_P15_Pos)) /* Assigment of value for P15 in the PIO_P_SIO_PAR register */
#define PIO_P_SIO_PAR_P16_Pos                 _UINT32_(16)                                         /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Position */
#define PIO_P_SIO_PAR_P16_Msk                 (_UINT32_(0x1) << PIO_P_SIO_PAR_P16_Pos)             /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Mask */
#define PIO_P_SIO_PAR_P16(value)              (PIO_P_SIO_PAR_P16_Msk & (_UINT32_(value) << PIO_P_SIO_PAR_P16_Pos)) /* Assigment of value for P16 in the PIO_P_SIO_PAR register */
#define PIO_P_SIO_PAR_P17_Pos                 _UINT32_(17)                                         /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Position */
#define PIO_P_SIO_PAR_P17_Msk                 (_UINT32_(0x1) << PIO_P_SIO_PAR_P17_Pos)             /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Mask */
#define PIO_P_SIO_PAR_P17(value)              (PIO_P_SIO_PAR_P17_Msk & (_UINT32_(value) << PIO_P_SIO_PAR_P17_Pos)) /* Assigment of value for P17 in the PIO_P_SIO_PAR register */
#define PIO_P_SIO_PAR_P18_Pos                 _UINT32_(18)                                         /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Position */
#define PIO_P_SIO_PAR_P18_Msk                 (_UINT32_(0x1) << PIO_P_SIO_PAR_P18_Pos)             /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Mask */
#define PIO_P_SIO_PAR_P18(value)              (PIO_P_SIO_PAR_P18_Msk & (_UINT32_(value) << PIO_P_SIO_PAR_P18_Pos)) /* Assigment of value for P18 in the PIO_P_SIO_PAR register */
#define PIO_P_SIO_PAR_P19_Pos                 _UINT32_(19)                                         /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Position */
#define PIO_P_SIO_PAR_P19_Msk                 (_UINT32_(0x1) << PIO_P_SIO_PAR_P19_Pos)             /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Mask */
#define PIO_P_SIO_PAR_P19(value)              (PIO_P_SIO_PAR_P19_Msk & (_UINT32_(value) << PIO_P_SIO_PAR_P19_Pos)) /* Assigment of value for P19 in the PIO_P_SIO_PAR register */
#define PIO_P_SIO_PAR_P20_Pos                 _UINT32_(20)                                         /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Position */
#define PIO_P_SIO_PAR_P20_Msk                 (_UINT32_(0x1) << PIO_P_SIO_PAR_P20_Pos)             /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Mask */
#define PIO_P_SIO_PAR_P20(value)              (PIO_P_SIO_PAR_P20_Msk & (_UINT32_(value) << PIO_P_SIO_PAR_P20_Pos)) /* Assigment of value for P20 in the PIO_P_SIO_PAR register */
#define PIO_P_SIO_PAR_P21_Pos                 _UINT32_(21)                                         /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Position */
#define PIO_P_SIO_PAR_P21_Msk                 (_UINT32_(0x1) << PIO_P_SIO_PAR_P21_Pos)             /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Mask */
#define PIO_P_SIO_PAR_P21(value)              (PIO_P_SIO_PAR_P21_Msk & (_UINT32_(value) << PIO_P_SIO_PAR_P21_Pos)) /* Assigment of value for P21 in the PIO_P_SIO_PAR register */
#define PIO_P_SIO_PAR_P22_Pos                 _UINT32_(22)                                         /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Position */
#define PIO_P_SIO_PAR_P22_Msk                 (_UINT32_(0x1) << PIO_P_SIO_PAR_P22_Pos)             /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Mask */
#define PIO_P_SIO_PAR_P22(value)              (PIO_P_SIO_PAR_P22_Msk & (_UINT32_(value) << PIO_P_SIO_PAR_P22_Pos)) /* Assigment of value for P22 in the PIO_P_SIO_PAR register */
#define PIO_P_SIO_PAR_P23_Pos                 _UINT32_(23)                                         /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Position */
#define PIO_P_SIO_PAR_P23_Msk                 (_UINT32_(0x1) << PIO_P_SIO_PAR_P23_Pos)             /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Mask */
#define PIO_P_SIO_PAR_P23(value)              (PIO_P_SIO_PAR_P23_Msk & (_UINT32_(value) << PIO_P_SIO_PAR_P23_Pos)) /* Assigment of value for P23 in the PIO_P_SIO_PAR register */
#define PIO_P_SIO_PAR_P24_Pos                 _UINT32_(24)                                         /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Position */
#define PIO_P_SIO_PAR_P24_Msk                 (_UINT32_(0x1) << PIO_P_SIO_PAR_P24_Pos)             /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Mask */
#define PIO_P_SIO_PAR_P24(value)              (PIO_P_SIO_PAR_P24_Msk & (_UINT32_(value) << PIO_P_SIO_PAR_P24_Pos)) /* Assigment of value for P24 in the PIO_P_SIO_PAR register */
#define PIO_P_SIO_PAR_P25_Pos                 _UINT32_(25)                                         /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Position */
#define PIO_P_SIO_PAR_P25_Msk                 (_UINT32_(0x1) << PIO_P_SIO_PAR_P25_Pos)             /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Mask */
#define PIO_P_SIO_PAR_P25(value)              (PIO_P_SIO_PAR_P25_Msk & (_UINT32_(value) << PIO_P_SIO_PAR_P25_Pos)) /* Assigment of value for P25 in the PIO_P_SIO_PAR register */
#define PIO_P_SIO_PAR_P26_Pos                 _UINT32_(26)                                         /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Position */
#define PIO_P_SIO_PAR_P26_Msk                 (_UINT32_(0x1) << PIO_P_SIO_PAR_P26_Pos)             /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Mask */
#define PIO_P_SIO_PAR_P26(value)              (PIO_P_SIO_PAR_P26_Msk & (_UINT32_(value) << PIO_P_SIO_PAR_P26_Pos)) /* Assigment of value for P26 in the PIO_P_SIO_PAR register */
#define PIO_P_SIO_PAR_P27_Pos                 _UINT32_(27)                                         /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Position */
#define PIO_P_SIO_PAR_P27_Msk                 (_UINT32_(0x1) << PIO_P_SIO_PAR_P27_Pos)             /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Mask */
#define PIO_P_SIO_PAR_P27(value)              (PIO_P_SIO_PAR_P27_Msk & (_UINT32_(value) << PIO_P_SIO_PAR_P27_Pos)) /* Assigment of value for P27 in the PIO_P_SIO_PAR register */
#define PIO_P_SIO_PAR_P28_Pos                 _UINT32_(28)                                         /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Position */
#define PIO_P_SIO_PAR_P28_Msk                 (_UINT32_(0x1) << PIO_P_SIO_PAR_P28_Pos)             /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Mask */
#define PIO_P_SIO_PAR_P28(value)              (PIO_P_SIO_PAR_P28_Msk & (_UINT32_(value) << PIO_P_SIO_PAR_P28_Pos)) /* Assigment of value for P28 in the PIO_P_SIO_PAR register */
#define PIO_P_SIO_PAR_P29_Pos                 _UINT32_(29)                                         /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Position */
#define PIO_P_SIO_PAR_P29_Msk                 (_UINT32_(0x1) << PIO_P_SIO_PAR_P29_Pos)             /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Mask */
#define PIO_P_SIO_PAR_P29(value)              (PIO_P_SIO_PAR_P29_Msk & (_UINT32_(value) << PIO_P_SIO_PAR_P29_Pos)) /* Assigment of value for P29 in the PIO_P_SIO_PAR register */
#define PIO_P_SIO_PAR_P30_Pos                 _UINT32_(30)                                         /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Position */
#define PIO_P_SIO_PAR_P30_Msk                 (_UINT32_(0x1) << PIO_P_SIO_PAR_P30_Pos)             /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Mask */
#define PIO_P_SIO_PAR_P30(value)              (PIO_P_SIO_PAR_P30_Msk & (_UINT32_(value) << PIO_P_SIO_PAR_P30_Pos)) /* Assigment of value for P30 in the PIO_P_SIO_PAR register */
#define PIO_P_SIO_PAR_P31_Pos                 _UINT32_(31)                                         /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Position */
#define PIO_P_SIO_PAR_P31_Msk                 (_UINT32_(0x1) << PIO_P_SIO_PAR_P31_Pos)             /* (PIO_P_SIO_PAR) Set I/O in Privileged-Access mode Mask */
#define PIO_P_SIO_PAR_P31(value)              (PIO_P_SIO_PAR_P31_Msk & (_UINT32_(value) << PIO_P_SIO_PAR_P31_Pos)) /* Assigment of value for P31 in the PIO_P_SIO_PAR register */
#define PIO_P_SIO_PAR_Msk                     _UINT32_(0xFFFFFFFF)                                 /* (PIO_P_SIO_PAR) Register Mask  */

#define PIO_P_SIO_PAR_P_Pos                   _UINT32_(0)                                          /* (PIO_P_SIO_PAR Position) Set I/O in Privileged-Access mode */
#define PIO_P_SIO_PAR_P_Msk                   (_UINT32_(0xFFFFFFFF) << PIO_P_SIO_PAR_P_Pos)        /* (PIO_P_SIO_PAR Mask) P */
#define PIO_P_SIO_PAR_P(value)                (PIO_P_SIO_PAR_P_Msk & (_UINT32_(value) << PIO_P_SIO_PAR_P_Pos)) 

/* -------- PIO_P_IOSSR : (PIO Offset: 0x38) ( R/ 32) PIO Privilege I/O Security Status Register (p_iogroup = 0) -------- */
#define PIO_P_IOSSR_P0_Pos                    _UINT32_(0)                                          /* (PIO_P_IOSSR) I/O Security Status Position */
#define PIO_P_IOSSR_P0_Msk                    (_UINT32_(0x1) << PIO_P_IOSSR_P0_Pos)                /* (PIO_P_IOSSR) I/O Security Status Mask */
#define PIO_P_IOSSR_P0(value)                 (PIO_P_IOSSR_P0_Msk & (_UINT32_(value) << PIO_P_IOSSR_P0_Pos)) /* Assigment of value for P0 in the PIO_P_IOSSR register */
#define   PIO_P_IOSSR_P0_PRIVILEGED_ACCESS_Val _UINT32_(0x0)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode.  */
#define   PIO_P_IOSSR_P0_USER_ACCESS_Val      _UINT32_(0x1)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode.  */
#define PIO_P_IOSSR_P0_PRIVILEGED_ACCESS      (PIO_P_IOSSR_P0_PRIVILEGED_ACCESS_Val << PIO_P_IOSSR_P0_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode. Position  */
#define PIO_P_IOSSR_P0_USER_ACCESS            (PIO_P_IOSSR_P0_USER_ACCESS_Val << PIO_P_IOSSR_P0_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode. Position  */
#define PIO_P_IOSSR_P1_Pos                    _UINT32_(1)                                          /* (PIO_P_IOSSR) I/O Security Status Position */
#define PIO_P_IOSSR_P1_Msk                    (_UINT32_(0x1) << PIO_P_IOSSR_P1_Pos)                /* (PIO_P_IOSSR) I/O Security Status Mask */
#define PIO_P_IOSSR_P1(value)                 (PIO_P_IOSSR_P1_Msk & (_UINT32_(value) << PIO_P_IOSSR_P1_Pos)) /* Assigment of value for P1 in the PIO_P_IOSSR register */
#define   PIO_P_IOSSR_P1_PRIVILEGED_ACCESS_Val _UINT32_(0x0)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode.  */
#define   PIO_P_IOSSR_P1_USER_ACCESS_Val      _UINT32_(0x1)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode.  */
#define PIO_P_IOSSR_P1_PRIVILEGED_ACCESS      (PIO_P_IOSSR_P1_PRIVILEGED_ACCESS_Val << PIO_P_IOSSR_P1_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode. Position  */
#define PIO_P_IOSSR_P1_USER_ACCESS            (PIO_P_IOSSR_P1_USER_ACCESS_Val << PIO_P_IOSSR_P1_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode. Position  */
#define PIO_P_IOSSR_P2_Pos                    _UINT32_(2)                                          /* (PIO_P_IOSSR) I/O Security Status Position */
#define PIO_P_IOSSR_P2_Msk                    (_UINT32_(0x1) << PIO_P_IOSSR_P2_Pos)                /* (PIO_P_IOSSR) I/O Security Status Mask */
#define PIO_P_IOSSR_P2(value)                 (PIO_P_IOSSR_P2_Msk & (_UINT32_(value) << PIO_P_IOSSR_P2_Pos)) /* Assigment of value for P2 in the PIO_P_IOSSR register */
#define   PIO_P_IOSSR_P2_PRIVILEGED_ACCESS_Val _UINT32_(0x0)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode.  */
#define   PIO_P_IOSSR_P2_USER_ACCESS_Val      _UINT32_(0x1)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode.  */
#define PIO_P_IOSSR_P2_PRIVILEGED_ACCESS      (PIO_P_IOSSR_P2_PRIVILEGED_ACCESS_Val << PIO_P_IOSSR_P2_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode. Position  */
#define PIO_P_IOSSR_P2_USER_ACCESS            (PIO_P_IOSSR_P2_USER_ACCESS_Val << PIO_P_IOSSR_P2_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode. Position  */
#define PIO_P_IOSSR_P3_Pos                    _UINT32_(3)                                          /* (PIO_P_IOSSR) I/O Security Status Position */
#define PIO_P_IOSSR_P3_Msk                    (_UINT32_(0x1) << PIO_P_IOSSR_P3_Pos)                /* (PIO_P_IOSSR) I/O Security Status Mask */
#define PIO_P_IOSSR_P3(value)                 (PIO_P_IOSSR_P3_Msk & (_UINT32_(value) << PIO_P_IOSSR_P3_Pos)) /* Assigment of value for P3 in the PIO_P_IOSSR register */
#define   PIO_P_IOSSR_P3_PRIVILEGED_ACCESS_Val _UINT32_(0x0)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode.  */
#define   PIO_P_IOSSR_P3_USER_ACCESS_Val      _UINT32_(0x1)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode.  */
#define PIO_P_IOSSR_P3_PRIVILEGED_ACCESS      (PIO_P_IOSSR_P3_PRIVILEGED_ACCESS_Val << PIO_P_IOSSR_P3_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode. Position  */
#define PIO_P_IOSSR_P3_USER_ACCESS            (PIO_P_IOSSR_P3_USER_ACCESS_Val << PIO_P_IOSSR_P3_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode. Position  */
#define PIO_P_IOSSR_P4_Pos                    _UINT32_(4)                                          /* (PIO_P_IOSSR) I/O Security Status Position */
#define PIO_P_IOSSR_P4_Msk                    (_UINT32_(0x1) << PIO_P_IOSSR_P4_Pos)                /* (PIO_P_IOSSR) I/O Security Status Mask */
#define PIO_P_IOSSR_P4(value)                 (PIO_P_IOSSR_P4_Msk & (_UINT32_(value) << PIO_P_IOSSR_P4_Pos)) /* Assigment of value for P4 in the PIO_P_IOSSR register */
#define   PIO_P_IOSSR_P4_PRIVILEGED_ACCESS_Val _UINT32_(0x0)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode.  */
#define   PIO_P_IOSSR_P4_USER_ACCESS_Val      _UINT32_(0x1)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode.  */
#define PIO_P_IOSSR_P4_PRIVILEGED_ACCESS      (PIO_P_IOSSR_P4_PRIVILEGED_ACCESS_Val << PIO_P_IOSSR_P4_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode. Position  */
#define PIO_P_IOSSR_P4_USER_ACCESS            (PIO_P_IOSSR_P4_USER_ACCESS_Val << PIO_P_IOSSR_P4_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode. Position  */
#define PIO_P_IOSSR_P5_Pos                    _UINT32_(5)                                          /* (PIO_P_IOSSR) I/O Security Status Position */
#define PIO_P_IOSSR_P5_Msk                    (_UINT32_(0x1) << PIO_P_IOSSR_P5_Pos)                /* (PIO_P_IOSSR) I/O Security Status Mask */
#define PIO_P_IOSSR_P5(value)                 (PIO_P_IOSSR_P5_Msk & (_UINT32_(value) << PIO_P_IOSSR_P5_Pos)) /* Assigment of value for P5 in the PIO_P_IOSSR register */
#define   PIO_P_IOSSR_P5_PRIVILEGED_ACCESS_Val _UINT32_(0x0)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode.  */
#define   PIO_P_IOSSR_P5_USER_ACCESS_Val      _UINT32_(0x1)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode.  */
#define PIO_P_IOSSR_P5_PRIVILEGED_ACCESS      (PIO_P_IOSSR_P5_PRIVILEGED_ACCESS_Val << PIO_P_IOSSR_P5_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode. Position  */
#define PIO_P_IOSSR_P5_USER_ACCESS            (PIO_P_IOSSR_P5_USER_ACCESS_Val << PIO_P_IOSSR_P5_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode. Position  */
#define PIO_P_IOSSR_P6_Pos                    _UINT32_(6)                                          /* (PIO_P_IOSSR) I/O Security Status Position */
#define PIO_P_IOSSR_P6_Msk                    (_UINT32_(0x1) << PIO_P_IOSSR_P6_Pos)                /* (PIO_P_IOSSR) I/O Security Status Mask */
#define PIO_P_IOSSR_P6(value)                 (PIO_P_IOSSR_P6_Msk & (_UINT32_(value) << PIO_P_IOSSR_P6_Pos)) /* Assigment of value for P6 in the PIO_P_IOSSR register */
#define   PIO_P_IOSSR_P6_PRIVILEGED_ACCESS_Val _UINT32_(0x0)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode.  */
#define   PIO_P_IOSSR_P6_USER_ACCESS_Val      _UINT32_(0x1)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode.  */
#define PIO_P_IOSSR_P6_PRIVILEGED_ACCESS      (PIO_P_IOSSR_P6_PRIVILEGED_ACCESS_Val << PIO_P_IOSSR_P6_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode. Position  */
#define PIO_P_IOSSR_P6_USER_ACCESS            (PIO_P_IOSSR_P6_USER_ACCESS_Val << PIO_P_IOSSR_P6_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode. Position  */
#define PIO_P_IOSSR_P7_Pos                    _UINT32_(7)                                          /* (PIO_P_IOSSR) I/O Security Status Position */
#define PIO_P_IOSSR_P7_Msk                    (_UINT32_(0x1) << PIO_P_IOSSR_P7_Pos)                /* (PIO_P_IOSSR) I/O Security Status Mask */
#define PIO_P_IOSSR_P7(value)                 (PIO_P_IOSSR_P7_Msk & (_UINT32_(value) << PIO_P_IOSSR_P7_Pos)) /* Assigment of value for P7 in the PIO_P_IOSSR register */
#define   PIO_P_IOSSR_P7_PRIVILEGED_ACCESS_Val _UINT32_(0x0)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode.  */
#define   PIO_P_IOSSR_P7_USER_ACCESS_Val      _UINT32_(0x1)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode.  */
#define PIO_P_IOSSR_P7_PRIVILEGED_ACCESS      (PIO_P_IOSSR_P7_PRIVILEGED_ACCESS_Val << PIO_P_IOSSR_P7_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode. Position  */
#define PIO_P_IOSSR_P7_USER_ACCESS            (PIO_P_IOSSR_P7_USER_ACCESS_Val << PIO_P_IOSSR_P7_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode. Position  */
#define PIO_P_IOSSR_P8_Pos                    _UINT32_(8)                                          /* (PIO_P_IOSSR) I/O Security Status Position */
#define PIO_P_IOSSR_P8_Msk                    (_UINT32_(0x1) << PIO_P_IOSSR_P8_Pos)                /* (PIO_P_IOSSR) I/O Security Status Mask */
#define PIO_P_IOSSR_P8(value)                 (PIO_P_IOSSR_P8_Msk & (_UINT32_(value) << PIO_P_IOSSR_P8_Pos)) /* Assigment of value for P8 in the PIO_P_IOSSR register */
#define   PIO_P_IOSSR_P8_PRIVILEGED_ACCESS_Val _UINT32_(0x0)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode.  */
#define   PIO_P_IOSSR_P8_USER_ACCESS_Val      _UINT32_(0x1)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode.  */
#define PIO_P_IOSSR_P8_PRIVILEGED_ACCESS      (PIO_P_IOSSR_P8_PRIVILEGED_ACCESS_Val << PIO_P_IOSSR_P8_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode. Position  */
#define PIO_P_IOSSR_P8_USER_ACCESS            (PIO_P_IOSSR_P8_USER_ACCESS_Val << PIO_P_IOSSR_P8_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode. Position  */
#define PIO_P_IOSSR_P9_Pos                    _UINT32_(9)                                          /* (PIO_P_IOSSR) I/O Security Status Position */
#define PIO_P_IOSSR_P9_Msk                    (_UINT32_(0x1) << PIO_P_IOSSR_P9_Pos)                /* (PIO_P_IOSSR) I/O Security Status Mask */
#define PIO_P_IOSSR_P9(value)                 (PIO_P_IOSSR_P9_Msk & (_UINT32_(value) << PIO_P_IOSSR_P9_Pos)) /* Assigment of value for P9 in the PIO_P_IOSSR register */
#define   PIO_P_IOSSR_P9_PRIVILEGED_ACCESS_Val _UINT32_(0x0)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode.  */
#define   PIO_P_IOSSR_P9_USER_ACCESS_Val      _UINT32_(0x1)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode.  */
#define PIO_P_IOSSR_P9_PRIVILEGED_ACCESS      (PIO_P_IOSSR_P9_PRIVILEGED_ACCESS_Val << PIO_P_IOSSR_P9_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode. Position  */
#define PIO_P_IOSSR_P9_USER_ACCESS            (PIO_P_IOSSR_P9_USER_ACCESS_Val << PIO_P_IOSSR_P9_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode. Position  */
#define PIO_P_IOSSR_P10_Pos                   _UINT32_(10)                                         /* (PIO_P_IOSSR) I/O Security Status Position */
#define PIO_P_IOSSR_P10_Msk                   (_UINT32_(0x1) << PIO_P_IOSSR_P10_Pos)               /* (PIO_P_IOSSR) I/O Security Status Mask */
#define PIO_P_IOSSR_P10(value)                (PIO_P_IOSSR_P10_Msk & (_UINT32_(value) << PIO_P_IOSSR_P10_Pos)) /* Assigment of value for P10 in the PIO_P_IOSSR register */
#define   PIO_P_IOSSR_P10_PRIVILEGED_ACCESS_Val _UINT32_(0x0)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode.  */
#define   PIO_P_IOSSR_P10_USER_ACCESS_Val     _UINT32_(0x1)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode.  */
#define PIO_P_IOSSR_P10_PRIVILEGED_ACCESS     (PIO_P_IOSSR_P10_PRIVILEGED_ACCESS_Val << PIO_P_IOSSR_P10_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode. Position  */
#define PIO_P_IOSSR_P10_USER_ACCESS           (PIO_P_IOSSR_P10_USER_ACCESS_Val << PIO_P_IOSSR_P10_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode. Position  */
#define PIO_P_IOSSR_P11_Pos                   _UINT32_(11)                                         /* (PIO_P_IOSSR) I/O Security Status Position */
#define PIO_P_IOSSR_P11_Msk                   (_UINT32_(0x1) << PIO_P_IOSSR_P11_Pos)               /* (PIO_P_IOSSR) I/O Security Status Mask */
#define PIO_P_IOSSR_P11(value)                (PIO_P_IOSSR_P11_Msk & (_UINT32_(value) << PIO_P_IOSSR_P11_Pos)) /* Assigment of value for P11 in the PIO_P_IOSSR register */
#define   PIO_P_IOSSR_P11_PRIVILEGED_ACCESS_Val _UINT32_(0x0)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode.  */
#define   PIO_P_IOSSR_P11_USER_ACCESS_Val     _UINT32_(0x1)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode.  */
#define PIO_P_IOSSR_P11_PRIVILEGED_ACCESS     (PIO_P_IOSSR_P11_PRIVILEGED_ACCESS_Val << PIO_P_IOSSR_P11_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode. Position  */
#define PIO_P_IOSSR_P11_USER_ACCESS           (PIO_P_IOSSR_P11_USER_ACCESS_Val << PIO_P_IOSSR_P11_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode. Position  */
#define PIO_P_IOSSR_P12_Pos                   _UINT32_(12)                                         /* (PIO_P_IOSSR) I/O Security Status Position */
#define PIO_P_IOSSR_P12_Msk                   (_UINT32_(0x1) << PIO_P_IOSSR_P12_Pos)               /* (PIO_P_IOSSR) I/O Security Status Mask */
#define PIO_P_IOSSR_P12(value)                (PIO_P_IOSSR_P12_Msk & (_UINT32_(value) << PIO_P_IOSSR_P12_Pos)) /* Assigment of value for P12 in the PIO_P_IOSSR register */
#define   PIO_P_IOSSR_P12_PRIVILEGED_ACCESS_Val _UINT32_(0x0)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode.  */
#define   PIO_P_IOSSR_P12_USER_ACCESS_Val     _UINT32_(0x1)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode.  */
#define PIO_P_IOSSR_P12_PRIVILEGED_ACCESS     (PIO_P_IOSSR_P12_PRIVILEGED_ACCESS_Val << PIO_P_IOSSR_P12_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode. Position  */
#define PIO_P_IOSSR_P12_USER_ACCESS           (PIO_P_IOSSR_P12_USER_ACCESS_Val << PIO_P_IOSSR_P12_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode. Position  */
#define PIO_P_IOSSR_P13_Pos                   _UINT32_(13)                                         /* (PIO_P_IOSSR) I/O Security Status Position */
#define PIO_P_IOSSR_P13_Msk                   (_UINT32_(0x1) << PIO_P_IOSSR_P13_Pos)               /* (PIO_P_IOSSR) I/O Security Status Mask */
#define PIO_P_IOSSR_P13(value)                (PIO_P_IOSSR_P13_Msk & (_UINT32_(value) << PIO_P_IOSSR_P13_Pos)) /* Assigment of value for P13 in the PIO_P_IOSSR register */
#define   PIO_P_IOSSR_P13_PRIVILEGED_ACCESS_Val _UINT32_(0x0)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode.  */
#define   PIO_P_IOSSR_P13_USER_ACCESS_Val     _UINT32_(0x1)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode.  */
#define PIO_P_IOSSR_P13_PRIVILEGED_ACCESS     (PIO_P_IOSSR_P13_PRIVILEGED_ACCESS_Val << PIO_P_IOSSR_P13_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode. Position  */
#define PIO_P_IOSSR_P13_USER_ACCESS           (PIO_P_IOSSR_P13_USER_ACCESS_Val << PIO_P_IOSSR_P13_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode. Position  */
#define PIO_P_IOSSR_P14_Pos                   _UINT32_(14)                                         /* (PIO_P_IOSSR) I/O Security Status Position */
#define PIO_P_IOSSR_P14_Msk                   (_UINT32_(0x1) << PIO_P_IOSSR_P14_Pos)               /* (PIO_P_IOSSR) I/O Security Status Mask */
#define PIO_P_IOSSR_P14(value)                (PIO_P_IOSSR_P14_Msk & (_UINT32_(value) << PIO_P_IOSSR_P14_Pos)) /* Assigment of value for P14 in the PIO_P_IOSSR register */
#define   PIO_P_IOSSR_P14_PRIVILEGED_ACCESS_Val _UINT32_(0x0)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode.  */
#define   PIO_P_IOSSR_P14_USER_ACCESS_Val     _UINT32_(0x1)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode.  */
#define PIO_P_IOSSR_P14_PRIVILEGED_ACCESS     (PIO_P_IOSSR_P14_PRIVILEGED_ACCESS_Val << PIO_P_IOSSR_P14_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode. Position  */
#define PIO_P_IOSSR_P14_USER_ACCESS           (PIO_P_IOSSR_P14_USER_ACCESS_Val << PIO_P_IOSSR_P14_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode. Position  */
#define PIO_P_IOSSR_P15_Pos                   _UINT32_(15)                                         /* (PIO_P_IOSSR) I/O Security Status Position */
#define PIO_P_IOSSR_P15_Msk                   (_UINT32_(0x1) << PIO_P_IOSSR_P15_Pos)               /* (PIO_P_IOSSR) I/O Security Status Mask */
#define PIO_P_IOSSR_P15(value)                (PIO_P_IOSSR_P15_Msk & (_UINT32_(value) << PIO_P_IOSSR_P15_Pos)) /* Assigment of value for P15 in the PIO_P_IOSSR register */
#define   PIO_P_IOSSR_P15_PRIVILEGED_ACCESS_Val _UINT32_(0x0)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode.  */
#define   PIO_P_IOSSR_P15_USER_ACCESS_Val     _UINT32_(0x1)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode.  */
#define PIO_P_IOSSR_P15_PRIVILEGED_ACCESS     (PIO_P_IOSSR_P15_PRIVILEGED_ACCESS_Val << PIO_P_IOSSR_P15_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode. Position  */
#define PIO_P_IOSSR_P15_USER_ACCESS           (PIO_P_IOSSR_P15_USER_ACCESS_Val << PIO_P_IOSSR_P15_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode. Position  */
#define PIO_P_IOSSR_P16_Pos                   _UINT32_(16)                                         /* (PIO_P_IOSSR) I/O Security Status Position */
#define PIO_P_IOSSR_P16_Msk                   (_UINT32_(0x1) << PIO_P_IOSSR_P16_Pos)               /* (PIO_P_IOSSR) I/O Security Status Mask */
#define PIO_P_IOSSR_P16(value)                (PIO_P_IOSSR_P16_Msk & (_UINT32_(value) << PIO_P_IOSSR_P16_Pos)) /* Assigment of value for P16 in the PIO_P_IOSSR register */
#define   PIO_P_IOSSR_P16_PRIVILEGED_ACCESS_Val _UINT32_(0x0)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode.  */
#define   PIO_P_IOSSR_P16_USER_ACCESS_Val     _UINT32_(0x1)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode.  */
#define PIO_P_IOSSR_P16_PRIVILEGED_ACCESS     (PIO_P_IOSSR_P16_PRIVILEGED_ACCESS_Val << PIO_P_IOSSR_P16_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode. Position  */
#define PIO_P_IOSSR_P16_USER_ACCESS           (PIO_P_IOSSR_P16_USER_ACCESS_Val << PIO_P_IOSSR_P16_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode. Position  */
#define PIO_P_IOSSR_P17_Pos                   _UINT32_(17)                                         /* (PIO_P_IOSSR) I/O Security Status Position */
#define PIO_P_IOSSR_P17_Msk                   (_UINT32_(0x1) << PIO_P_IOSSR_P17_Pos)               /* (PIO_P_IOSSR) I/O Security Status Mask */
#define PIO_P_IOSSR_P17(value)                (PIO_P_IOSSR_P17_Msk & (_UINT32_(value) << PIO_P_IOSSR_P17_Pos)) /* Assigment of value for P17 in the PIO_P_IOSSR register */
#define   PIO_P_IOSSR_P17_PRIVILEGED_ACCESS_Val _UINT32_(0x0)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode.  */
#define   PIO_P_IOSSR_P17_USER_ACCESS_Val     _UINT32_(0x1)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode.  */
#define PIO_P_IOSSR_P17_PRIVILEGED_ACCESS     (PIO_P_IOSSR_P17_PRIVILEGED_ACCESS_Val << PIO_P_IOSSR_P17_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode. Position  */
#define PIO_P_IOSSR_P17_USER_ACCESS           (PIO_P_IOSSR_P17_USER_ACCESS_Val << PIO_P_IOSSR_P17_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode. Position  */
#define PIO_P_IOSSR_P18_Pos                   _UINT32_(18)                                         /* (PIO_P_IOSSR) I/O Security Status Position */
#define PIO_P_IOSSR_P18_Msk                   (_UINT32_(0x1) << PIO_P_IOSSR_P18_Pos)               /* (PIO_P_IOSSR) I/O Security Status Mask */
#define PIO_P_IOSSR_P18(value)                (PIO_P_IOSSR_P18_Msk & (_UINT32_(value) << PIO_P_IOSSR_P18_Pos)) /* Assigment of value for P18 in the PIO_P_IOSSR register */
#define   PIO_P_IOSSR_P18_PRIVILEGED_ACCESS_Val _UINT32_(0x0)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode.  */
#define   PIO_P_IOSSR_P18_USER_ACCESS_Val     _UINT32_(0x1)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode.  */
#define PIO_P_IOSSR_P18_PRIVILEGED_ACCESS     (PIO_P_IOSSR_P18_PRIVILEGED_ACCESS_Val << PIO_P_IOSSR_P18_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode. Position  */
#define PIO_P_IOSSR_P18_USER_ACCESS           (PIO_P_IOSSR_P18_USER_ACCESS_Val << PIO_P_IOSSR_P18_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode. Position  */
#define PIO_P_IOSSR_P19_Pos                   _UINT32_(19)                                         /* (PIO_P_IOSSR) I/O Security Status Position */
#define PIO_P_IOSSR_P19_Msk                   (_UINT32_(0x1) << PIO_P_IOSSR_P19_Pos)               /* (PIO_P_IOSSR) I/O Security Status Mask */
#define PIO_P_IOSSR_P19(value)                (PIO_P_IOSSR_P19_Msk & (_UINT32_(value) << PIO_P_IOSSR_P19_Pos)) /* Assigment of value for P19 in the PIO_P_IOSSR register */
#define   PIO_P_IOSSR_P19_PRIVILEGED_ACCESS_Val _UINT32_(0x0)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode.  */
#define   PIO_P_IOSSR_P19_USER_ACCESS_Val     _UINT32_(0x1)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode.  */
#define PIO_P_IOSSR_P19_PRIVILEGED_ACCESS     (PIO_P_IOSSR_P19_PRIVILEGED_ACCESS_Val << PIO_P_IOSSR_P19_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode. Position  */
#define PIO_P_IOSSR_P19_USER_ACCESS           (PIO_P_IOSSR_P19_USER_ACCESS_Val << PIO_P_IOSSR_P19_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode. Position  */
#define PIO_P_IOSSR_P20_Pos                   _UINT32_(20)                                         /* (PIO_P_IOSSR) I/O Security Status Position */
#define PIO_P_IOSSR_P20_Msk                   (_UINT32_(0x1) << PIO_P_IOSSR_P20_Pos)               /* (PIO_P_IOSSR) I/O Security Status Mask */
#define PIO_P_IOSSR_P20(value)                (PIO_P_IOSSR_P20_Msk & (_UINT32_(value) << PIO_P_IOSSR_P20_Pos)) /* Assigment of value for P20 in the PIO_P_IOSSR register */
#define   PIO_P_IOSSR_P20_PRIVILEGED_ACCESS_Val _UINT32_(0x0)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode.  */
#define   PIO_P_IOSSR_P20_USER_ACCESS_Val     _UINT32_(0x1)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode.  */
#define PIO_P_IOSSR_P20_PRIVILEGED_ACCESS     (PIO_P_IOSSR_P20_PRIVILEGED_ACCESS_Val << PIO_P_IOSSR_P20_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode. Position  */
#define PIO_P_IOSSR_P20_USER_ACCESS           (PIO_P_IOSSR_P20_USER_ACCESS_Val << PIO_P_IOSSR_P20_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode. Position  */
#define PIO_P_IOSSR_P21_Pos                   _UINT32_(21)                                         /* (PIO_P_IOSSR) I/O Security Status Position */
#define PIO_P_IOSSR_P21_Msk                   (_UINT32_(0x1) << PIO_P_IOSSR_P21_Pos)               /* (PIO_P_IOSSR) I/O Security Status Mask */
#define PIO_P_IOSSR_P21(value)                (PIO_P_IOSSR_P21_Msk & (_UINT32_(value) << PIO_P_IOSSR_P21_Pos)) /* Assigment of value for P21 in the PIO_P_IOSSR register */
#define   PIO_P_IOSSR_P21_PRIVILEGED_ACCESS_Val _UINT32_(0x0)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode.  */
#define   PIO_P_IOSSR_P21_USER_ACCESS_Val     _UINT32_(0x1)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode.  */
#define PIO_P_IOSSR_P21_PRIVILEGED_ACCESS     (PIO_P_IOSSR_P21_PRIVILEGED_ACCESS_Val << PIO_P_IOSSR_P21_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode. Position  */
#define PIO_P_IOSSR_P21_USER_ACCESS           (PIO_P_IOSSR_P21_USER_ACCESS_Val << PIO_P_IOSSR_P21_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode. Position  */
#define PIO_P_IOSSR_P22_Pos                   _UINT32_(22)                                         /* (PIO_P_IOSSR) I/O Security Status Position */
#define PIO_P_IOSSR_P22_Msk                   (_UINT32_(0x1) << PIO_P_IOSSR_P22_Pos)               /* (PIO_P_IOSSR) I/O Security Status Mask */
#define PIO_P_IOSSR_P22(value)                (PIO_P_IOSSR_P22_Msk & (_UINT32_(value) << PIO_P_IOSSR_P22_Pos)) /* Assigment of value for P22 in the PIO_P_IOSSR register */
#define   PIO_P_IOSSR_P22_PRIVILEGED_ACCESS_Val _UINT32_(0x0)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode.  */
#define   PIO_P_IOSSR_P22_USER_ACCESS_Val     _UINT32_(0x1)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode.  */
#define PIO_P_IOSSR_P22_PRIVILEGED_ACCESS     (PIO_P_IOSSR_P22_PRIVILEGED_ACCESS_Val << PIO_P_IOSSR_P22_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode. Position  */
#define PIO_P_IOSSR_P22_USER_ACCESS           (PIO_P_IOSSR_P22_USER_ACCESS_Val << PIO_P_IOSSR_P22_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode. Position  */
#define PIO_P_IOSSR_P23_Pos                   _UINT32_(23)                                         /* (PIO_P_IOSSR) I/O Security Status Position */
#define PIO_P_IOSSR_P23_Msk                   (_UINT32_(0x1) << PIO_P_IOSSR_P23_Pos)               /* (PIO_P_IOSSR) I/O Security Status Mask */
#define PIO_P_IOSSR_P23(value)                (PIO_P_IOSSR_P23_Msk & (_UINT32_(value) << PIO_P_IOSSR_P23_Pos)) /* Assigment of value for P23 in the PIO_P_IOSSR register */
#define   PIO_P_IOSSR_P23_PRIVILEGED_ACCESS_Val _UINT32_(0x0)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode.  */
#define   PIO_P_IOSSR_P23_USER_ACCESS_Val     _UINT32_(0x1)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode.  */
#define PIO_P_IOSSR_P23_PRIVILEGED_ACCESS     (PIO_P_IOSSR_P23_PRIVILEGED_ACCESS_Val << PIO_P_IOSSR_P23_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode. Position  */
#define PIO_P_IOSSR_P23_USER_ACCESS           (PIO_P_IOSSR_P23_USER_ACCESS_Val << PIO_P_IOSSR_P23_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode. Position  */
#define PIO_P_IOSSR_P24_Pos                   _UINT32_(24)                                         /* (PIO_P_IOSSR) I/O Security Status Position */
#define PIO_P_IOSSR_P24_Msk                   (_UINT32_(0x1) << PIO_P_IOSSR_P24_Pos)               /* (PIO_P_IOSSR) I/O Security Status Mask */
#define PIO_P_IOSSR_P24(value)                (PIO_P_IOSSR_P24_Msk & (_UINT32_(value) << PIO_P_IOSSR_P24_Pos)) /* Assigment of value for P24 in the PIO_P_IOSSR register */
#define   PIO_P_IOSSR_P24_PRIVILEGED_ACCESS_Val _UINT32_(0x0)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode.  */
#define   PIO_P_IOSSR_P24_USER_ACCESS_Val     _UINT32_(0x1)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode.  */
#define PIO_P_IOSSR_P24_PRIVILEGED_ACCESS     (PIO_P_IOSSR_P24_PRIVILEGED_ACCESS_Val << PIO_P_IOSSR_P24_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode. Position  */
#define PIO_P_IOSSR_P24_USER_ACCESS           (PIO_P_IOSSR_P24_USER_ACCESS_Val << PIO_P_IOSSR_P24_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode. Position  */
#define PIO_P_IOSSR_P25_Pos                   _UINT32_(25)                                         /* (PIO_P_IOSSR) I/O Security Status Position */
#define PIO_P_IOSSR_P25_Msk                   (_UINT32_(0x1) << PIO_P_IOSSR_P25_Pos)               /* (PIO_P_IOSSR) I/O Security Status Mask */
#define PIO_P_IOSSR_P25(value)                (PIO_P_IOSSR_P25_Msk & (_UINT32_(value) << PIO_P_IOSSR_P25_Pos)) /* Assigment of value for P25 in the PIO_P_IOSSR register */
#define   PIO_P_IOSSR_P25_PRIVILEGED_ACCESS_Val _UINT32_(0x0)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode.  */
#define   PIO_P_IOSSR_P25_USER_ACCESS_Val     _UINT32_(0x1)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode.  */
#define PIO_P_IOSSR_P25_PRIVILEGED_ACCESS     (PIO_P_IOSSR_P25_PRIVILEGED_ACCESS_Val << PIO_P_IOSSR_P25_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode. Position  */
#define PIO_P_IOSSR_P25_USER_ACCESS           (PIO_P_IOSSR_P25_USER_ACCESS_Val << PIO_P_IOSSR_P25_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode. Position  */
#define PIO_P_IOSSR_P26_Pos                   _UINT32_(26)                                         /* (PIO_P_IOSSR) I/O Security Status Position */
#define PIO_P_IOSSR_P26_Msk                   (_UINT32_(0x1) << PIO_P_IOSSR_P26_Pos)               /* (PIO_P_IOSSR) I/O Security Status Mask */
#define PIO_P_IOSSR_P26(value)                (PIO_P_IOSSR_P26_Msk & (_UINT32_(value) << PIO_P_IOSSR_P26_Pos)) /* Assigment of value for P26 in the PIO_P_IOSSR register */
#define   PIO_P_IOSSR_P26_PRIVILEGED_ACCESS_Val _UINT32_(0x0)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode.  */
#define   PIO_P_IOSSR_P26_USER_ACCESS_Val     _UINT32_(0x1)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode.  */
#define PIO_P_IOSSR_P26_PRIVILEGED_ACCESS     (PIO_P_IOSSR_P26_PRIVILEGED_ACCESS_Val << PIO_P_IOSSR_P26_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode. Position  */
#define PIO_P_IOSSR_P26_USER_ACCESS           (PIO_P_IOSSR_P26_USER_ACCESS_Val << PIO_P_IOSSR_P26_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode. Position  */
#define PIO_P_IOSSR_P27_Pos                   _UINT32_(27)                                         /* (PIO_P_IOSSR) I/O Security Status Position */
#define PIO_P_IOSSR_P27_Msk                   (_UINT32_(0x1) << PIO_P_IOSSR_P27_Pos)               /* (PIO_P_IOSSR) I/O Security Status Mask */
#define PIO_P_IOSSR_P27(value)                (PIO_P_IOSSR_P27_Msk & (_UINT32_(value) << PIO_P_IOSSR_P27_Pos)) /* Assigment of value for P27 in the PIO_P_IOSSR register */
#define   PIO_P_IOSSR_P27_PRIVILEGED_ACCESS_Val _UINT32_(0x0)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode.  */
#define   PIO_P_IOSSR_P27_USER_ACCESS_Val     _UINT32_(0x1)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode.  */
#define PIO_P_IOSSR_P27_PRIVILEGED_ACCESS     (PIO_P_IOSSR_P27_PRIVILEGED_ACCESS_Val << PIO_P_IOSSR_P27_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode. Position  */
#define PIO_P_IOSSR_P27_USER_ACCESS           (PIO_P_IOSSR_P27_USER_ACCESS_Val << PIO_P_IOSSR_P27_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode. Position  */
#define PIO_P_IOSSR_P28_Pos                   _UINT32_(28)                                         /* (PIO_P_IOSSR) I/O Security Status Position */
#define PIO_P_IOSSR_P28_Msk                   (_UINT32_(0x1) << PIO_P_IOSSR_P28_Pos)               /* (PIO_P_IOSSR) I/O Security Status Mask */
#define PIO_P_IOSSR_P28(value)                (PIO_P_IOSSR_P28_Msk & (_UINT32_(value) << PIO_P_IOSSR_P28_Pos)) /* Assigment of value for P28 in the PIO_P_IOSSR register */
#define   PIO_P_IOSSR_P28_PRIVILEGED_ACCESS_Val _UINT32_(0x0)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode.  */
#define   PIO_P_IOSSR_P28_USER_ACCESS_Val     _UINT32_(0x1)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode.  */
#define PIO_P_IOSSR_P28_PRIVILEGED_ACCESS     (PIO_P_IOSSR_P28_PRIVILEGED_ACCESS_Val << PIO_P_IOSSR_P28_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode. Position  */
#define PIO_P_IOSSR_P28_USER_ACCESS           (PIO_P_IOSSR_P28_USER_ACCESS_Val << PIO_P_IOSSR_P28_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode. Position  */
#define PIO_P_IOSSR_P29_Pos                   _UINT32_(29)                                         /* (PIO_P_IOSSR) I/O Security Status Position */
#define PIO_P_IOSSR_P29_Msk                   (_UINT32_(0x1) << PIO_P_IOSSR_P29_Pos)               /* (PIO_P_IOSSR) I/O Security Status Mask */
#define PIO_P_IOSSR_P29(value)                (PIO_P_IOSSR_P29_Msk & (_UINT32_(value) << PIO_P_IOSSR_P29_Pos)) /* Assigment of value for P29 in the PIO_P_IOSSR register */
#define   PIO_P_IOSSR_P29_PRIVILEGED_ACCESS_Val _UINT32_(0x0)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode.  */
#define   PIO_P_IOSSR_P29_USER_ACCESS_Val     _UINT32_(0x1)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode.  */
#define PIO_P_IOSSR_P29_PRIVILEGED_ACCESS     (PIO_P_IOSSR_P29_PRIVILEGED_ACCESS_Val << PIO_P_IOSSR_P29_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode. Position  */
#define PIO_P_IOSSR_P29_USER_ACCESS           (PIO_P_IOSSR_P29_USER_ACCESS_Val << PIO_P_IOSSR_P29_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode. Position  */
#define PIO_P_IOSSR_P30_Pos                   _UINT32_(30)                                         /* (PIO_P_IOSSR) I/O Security Status Position */
#define PIO_P_IOSSR_P30_Msk                   (_UINT32_(0x1) << PIO_P_IOSSR_P30_Pos)               /* (PIO_P_IOSSR) I/O Security Status Mask */
#define PIO_P_IOSSR_P30(value)                (PIO_P_IOSSR_P30_Msk & (_UINT32_(value) << PIO_P_IOSSR_P30_Pos)) /* Assigment of value for P30 in the PIO_P_IOSSR register */
#define   PIO_P_IOSSR_P30_PRIVILEGED_ACCESS_Val _UINT32_(0x0)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode.  */
#define   PIO_P_IOSSR_P30_USER_ACCESS_Val     _UINT32_(0x1)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode.  */
#define PIO_P_IOSSR_P30_PRIVILEGED_ACCESS     (PIO_P_IOSSR_P30_PRIVILEGED_ACCESS_Val << PIO_P_IOSSR_P30_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode. Position  */
#define PIO_P_IOSSR_P30_USER_ACCESS           (PIO_P_IOSSR_P30_USER_ACCESS_Val << PIO_P_IOSSR_P30_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode. Position  */
#define PIO_P_IOSSR_P31_Pos                   _UINT32_(31)                                         /* (PIO_P_IOSSR) I/O Security Status Position */
#define PIO_P_IOSSR_P31_Msk                   (_UINT32_(0x1) << PIO_P_IOSSR_P31_Pos)               /* (PIO_P_IOSSR) I/O Security Status Mask */
#define PIO_P_IOSSR_P31(value)                (PIO_P_IOSSR_P31_Msk & (_UINT32_(value) << PIO_P_IOSSR_P31_Pos)) /* Assigment of value for P31 in the PIO_P_IOSSR register */
#define   PIO_P_IOSSR_P31_PRIVILEGED_ACCESS_Val _UINT32_(0x0)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode.  */
#define   PIO_P_IOSSR_P31_USER_ACCESS_Val     _UINT32_(0x1)                                        /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode.  */
#define PIO_P_IOSSR_P31_PRIVILEGED_ACCESS     (PIO_P_IOSSR_P31_PRIVILEGED_ACCESS_Val << PIO_P_IOSSR_P31_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in Privileged-Access mode. Position  */
#define PIO_P_IOSSR_P31_USER_ACCESS           (PIO_P_IOSSR_P31_USER_ACCESS_Val << PIO_P_IOSSR_P31_Pos) /* (PIO_P_IOSSR) The I/O line of the I/O group 0 is in User-Access mode. Position  */
#define PIO_P_IOSSR_Msk                       _UINT32_(0xFFFFFFFF)                                 /* (PIO_P_IOSSR) Register Mask  */

#define PIO_P_IOSSR_P_Pos                     _UINT32_(0)                                          /* (PIO_P_IOSSR Position) I/O Security Status */
#define PIO_P_IOSSR_P_Msk                     (_UINT32_(0xFFFFFFFF) << PIO_P_IOSSR_P_Pos)          /* (PIO_P_IOSSR Mask) P */
#define PIO_P_IOSSR_P(value)                  (PIO_P_IOSSR_P_Msk & (_UINT32_(value) << PIO_P_IOSSR_P_Pos)) 

/* -------- PIO_P_IOFR : (PIO Offset: 0x3C) ( /W 32) PIO Privilege I/O Freeze Configuration Register (p_iogroup = 0) -------- */
#define PIO_P_IOFR_FPHY_Pos                   _UINT32_(0)                                          /* (PIO_P_IOFR) Freeze Physical Configuration Position */
#define PIO_P_IOFR_FPHY_Msk                   (_UINT32_(0x1) << PIO_P_IOFR_FPHY_Pos)               /* (PIO_P_IOFR) Freeze Physical Configuration Mask */
#define PIO_P_IOFR_FPHY(value)                (PIO_P_IOFR_FPHY_Msk & (_UINT32_(value) << PIO_P_IOFR_FPHY_Pos)) /* Assigment of value for FPHY in the PIO_P_IOFR register */
#define PIO_P_IOFR_FINT_Pos                   _UINT32_(1)                                          /* (PIO_P_IOFR) Freeze Interrupt Configuration Position */
#define PIO_P_IOFR_FINT_Msk                   (_UINT32_(0x1) << PIO_P_IOFR_FINT_Pos)               /* (PIO_P_IOFR) Freeze Interrupt Configuration Mask */
#define PIO_P_IOFR_FINT(value)                (PIO_P_IOFR_FINT_Msk & (_UINT32_(value) << PIO_P_IOFR_FINT_Pos)) /* Assigment of value for FINT in the PIO_P_IOFR register */
#define PIO_P_IOFR_FRZKEY_Pos                 _UINT32_(8)                                          /* (PIO_P_IOFR) Freeze Key Position */
#define PIO_P_IOFR_FRZKEY_Msk                 (_UINT32_(0xFFFFFF) << PIO_P_IOFR_FRZKEY_Pos)        /* (PIO_P_IOFR) Freeze Key Mask */
#define PIO_P_IOFR_FRZKEY(value)              (PIO_P_IOFR_FRZKEY_Msk & (_UINT32_(value) << PIO_P_IOFR_FRZKEY_Pos)) /* Assigment of value for FRZKEY in the PIO_P_IOFR register */
#define   PIO_P_IOFR_FRZKEY_PASSWD_Val        _UINT32_(0x494F46)                                   /* (PIO_P_IOFR) Writing any other value in this field aborts the write operation of the WPEN bit.  */
#define PIO_P_IOFR_FRZKEY_PASSWD              (PIO_P_IOFR_FRZKEY_PASSWD_Val << PIO_P_IOFR_FRZKEY_Pos) /* (PIO_P_IOFR) Writing any other value in this field aborts the write operation of the WPEN bit. Position  */
#define PIO_P_IOFR_Msk                        _UINT32_(0xFFFFFF03)                                 /* (PIO_P_IOFR) Register Mask  */


/* -------- PIO_WPMR : (PIO Offset: 0x5E0) (R/W 32) PIO Write Protection Mode Register -------- */
#define PIO_WPMR_WPEN_Pos                     _UINT32_(0)                                          /* (PIO_WPMR) Write Protection Enable Position */
#define PIO_WPMR_WPEN_Msk                     (_UINT32_(0x1) << PIO_WPMR_WPEN_Pos)                 /* (PIO_WPMR) Write Protection Enable Mask */
#define PIO_WPMR_WPEN(value)                  (PIO_WPMR_WPEN_Msk & (_UINT32_(value) << PIO_WPMR_WPEN_Pos)) /* Assigment of value for WPEN in the PIO_WPMR register */
#define PIO_WPMR_WPITEN_Pos                   _UINT32_(1)                                          /* (PIO_WPMR) Write Protection Interrupt Enable Position */
#define PIO_WPMR_WPITEN_Msk                   (_UINT32_(0x1) << PIO_WPMR_WPITEN_Pos)               /* (PIO_WPMR) Write Protection Interrupt Enable Mask */
#define PIO_WPMR_WPITEN(value)                (PIO_WPMR_WPITEN_Msk & (_UINT32_(value) << PIO_WPMR_WPITEN_Pos)) /* Assigment of value for WPITEN in the PIO_WPMR register */
#define PIO_WPMR_WPKEY_Pos                    _UINT32_(8)                                          /* (PIO_WPMR) Write Protection Key Position */
#define PIO_WPMR_WPKEY_Msk                    (_UINT32_(0xFFFFFF) << PIO_WPMR_WPKEY_Pos)           /* (PIO_WPMR) Write Protection Key Mask */
#define PIO_WPMR_WPKEY(value)                 (PIO_WPMR_WPKEY_Msk & (_UINT32_(value) << PIO_WPMR_WPKEY_Pos)) /* Assigment of value for WPKEY in the PIO_WPMR register */
#define   PIO_WPMR_WPKEY_PASSWD_Val           _UINT32_(0x50494F)                                   /* (PIO_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit. Always reads as 0.  */
#define PIO_WPMR_WPKEY_PASSWD                 (PIO_WPMR_WPKEY_PASSWD_Val << PIO_WPMR_WPKEY_Pos)    /* (PIO_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit. Always reads as 0. Position  */
#define PIO_WPMR_Msk                          _UINT32_(0xFFFFFF03)                                 /* (PIO_WPMR) Register Mask  */


/* -------- PIO_WPSR : (PIO Offset: 0x5E4) ( R/ 32) PIO Write Protection Status Register -------- */
#define PIO_WPSR_WPVS_Pos                     _UINT32_(0)                                          /* (PIO_WPSR) Write Protection Violation Status Position */
#define PIO_WPSR_WPVS_Msk                     (_UINT32_(0x1) << PIO_WPSR_WPVS_Pos)                 /* (PIO_WPSR) Write Protection Violation Status Mask */
#define PIO_WPSR_WPVS(value)                  (PIO_WPSR_WPVS_Msk & (_UINT32_(value) << PIO_WPSR_WPVS_Pos)) /* Assigment of value for WPVS in the PIO_WPSR register */
#define PIO_WPSR_WPVSRC_Pos                   _UINT32_(8)                                          /* (PIO_WPSR) Write Protection Violation Source Position */
#define PIO_WPSR_WPVSRC_Msk                   (_UINT32_(0xFFFF) << PIO_WPSR_WPVSRC_Pos)            /* (PIO_WPSR) Write Protection Violation Source Mask */
#define PIO_WPSR_WPVSRC(value)                (PIO_WPSR_WPVSRC_Msk & (_UINT32_(value) << PIO_WPSR_WPVSRC_Pos)) /* Assigment of value for WPVSRC in the PIO_WPSR register */
#define PIO_WPSR_Msk                          _UINT32_(0x00FFFF01)                                 /* (PIO_WPSR) Register Mask  */


/* -------- PIO_P_SCDR : (PIO Offset: 0x1500) (R/W 32) PIO Privilege Slow Clock Divider Debouncing Register -------- */
#define PIO_P_SCDR_DIV_Pos                    _UINT32_(0)                                          /* (PIO_P_SCDR) Slow Clock Divider Selection for Debouncing Position */
#define PIO_P_SCDR_DIV_Msk                    (_UINT32_(0x3FFF) << PIO_P_SCDR_DIV_Pos)             /* (PIO_P_SCDR) Slow Clock Divider Selection for Debouncing Mask */
#define PIO_P_SCDR_DIV(value)                 (PIO_P_SCDR_DIV_Msk & (_UINT32_(value) << PIO_P_SCDR_DIV_Pos)) /* Assigment of value for DIV in the PIO_P_SCDR register */
#define PIO_P_SCDR_Msk                        _UINT32_(0x00003FFF)                                 /* (PIO_P_SCDR) Register Mask  */


/* -------- PIO_P_WPMR : (PIO Offset: 0x15E0) (R/W 32) PIO Privilege Write Protection Mode Register -------- */
#define PIO_P_WPMR_WPEN_Pos                   _UINT32_(0)                                          /* (PIO_P_WPMR) Write Protection Enable Position */
#define PIO_P_WPMR_WPEN_Msk                   (_UINT32_(0x1) << PIO_P_WPMR_WPEN_Pos)               /* (PIO_P_WPMR) Write Protection Enable Mask */
#define PIO_P_WPMR_WPEN(value)                (PIO_P_WPMR_WPEN_Msk & (_UINT32_(value) << PIO_P_WPMR_WPEN_Pos)) /* Assigment of value for WPEN in the PIO_P_WPMR register */
#define PIO_P_WPMR_WPITEN_Pos                 _UINT32_(1)                                          /* (PIO_P_WPMR) Write Protection Interrupt Enable Position */
#define PIO_P_WPMR_WPITEN_Msk                 (_UINT32_(0x1) << PIO_P_WPMR_WPITEN_Pos)             /* (PIO_P_WPMR) Write Protection Interrupt Enable Mask */
#define PIO_P_WPMR_WPITEN(value)              (PIO_P_WPMR_WPITEN_Msk & (_UINT32_(value) << PIO_P_WPMR_WPITEN_Pos)) /* Assigment of value for WPITEN in the PIO_P_WPMR register */
#define PIO_P_WPMR_WPKEY_Pos                  _UINT32_(8)                                          /* (PIO_P_WPMR) Write Protection Key Position */
#define PIO_P_WPMR_WPKEY_Msk                  (_UINT32_(0xFFFFFF) << PIO_P_WPMR_WPKEY_Pos)         /* (PIO_P_WPMR) Write Protection Key Mask */
#define PIO_P_WPMR_WPKEY(value)               (PIO_P_WPMR_WPKEY_Msk & (_UINT32_(value) << PIO_P_WPMR_WPKEY_Pos)) /* Assigment of value for WPKEY in the PIO_P_WPMR register */
#define   PIO_P_WPMR_WPKEY_PASSWD_Val         _UINT32_(0x50494F)                                   /* (PIO_P_WPMR) Writing any other value in this field aborts the write operation of WPEN. Always reads as 0.  */
#define PIO_P_WPMR_WPKEY_PASSWD               (PIO_P_WPMR_WPKEY_PASSWD_Val << PIO_P_WPMR_WPKEY_Pos) /* (PIO_P_WPMR) Writing any other value in this field aborts the write operation of WPEN. Always reads as 0. Position  */
#define PIO_P_WPMR_Msk                        _UINT32_(0xFFFFFF03)                                 /* (PIO_P_WPMR) Register Mask  */


/* -------- PIO_P_WPSR : (PIO Offset: 0x15E4) ( R/ 32) PIO Privilege Write Protection Status Register -------- */
#define PIO_P_WPSR_WPVS_Pos                   _UINT32_(0)                                          /* (PIO_P_WPSR) Write Protection Violation Status Position */
#define PIO_P_WPSR_WPVS_Msk                   (_UINT32_(0x1) << PIO_P_WPSR_WPVS_Pos)               /* (PIO_P_WPSR) Write Protection Violation Status Mask */
#define PIO_P_WPSR_WPVS(value)                (PIO_P_WPSR_WPVS_Msk & (_UINT32_(value) << PIO_P_WPSR_WPVS_Pos)) /* Assigment of value for WPVS in the PIO_P_WPSR register */
#define PIO_P_WPSR_WPVSRC_Pos                 _UINT32_(8)                                          /* (PIO_P_WPSR) Write Protection Violation Source Position */
#define PIO_P_WPSR_WPVSRC_Msk                 (_UINT32_(0xFFFF) << PIO_P_WPSR_WPVSRC_Pos)          /* (PIO_P_WPSR) Write Protection Violation Source Mask */
#define PIO_P_WPSR_WPVSRC(value)              (PIO_P_WPSR_WPVSRC_Msk & (_UINT32_(value) << PIO_P_WPSR_WPVSRC_Pos)) /* Assigment of value for WPVSRC in the PIO_P_WPSR register */
#define PIO_P_WPSR_Msk                        _UINT32_(0x00FFFF01)                                 /* (PIO_P_WPSR) Register Mask  */


/** \brief PIO register offsets definitions */
#define PIO_MSKR_REG_OFST              _UINT32_(0x00)      /* (PIO_MSKR) PIO Mask Register Offset */
#define PIO_CFGR_REG_OFST              _UINT32_(0x04)      /* (PIO_CFGR) PIO Configuration Register Offset */
#define PIO_PDSR_REG_OFST              _UINT32_(0x08)      /* (PIO_PDSR) PIO Pin Data Status Register Offset */
#define PIO_LOCKSR_REG_OFST            _UINT32_(0x0C)      /* (PIO_LOCKSR) PIO Lock Status Register Offset */
#define PIO_SODR_REG_OFST              _UINT32_(0x10)      /* (PIO_SODR) PIO Set Output Data Register Offset */
#define PIO_CODR_REG_OFST              _UINT32_(0x14)      /* (PIO_CODR) PIO Clear Output Data Register Offset */
#define PIO_ODSR_REG_OFST              _UINT32_(0x18)      /* (PIO_ODSR) PIO Output Data Status Register Offset */
#define PIO_IER_REG_OFST               _UINT32_(0x20)      /* (PIO_IER) PIO Interrupt Enable Register Offset */
#define PIO_IDR_REG_OFST               _UINT32_(0x24)      /* (PIO_IDR) PIO Interrupt Disable Register Offset */
#define PIO_IMR_REG_OFST               _UINT32_(0x28)      /* (PIO_IMR) PIO Interrupt Mask Register Offset */
#define PIO_ISR_REG_OFST               _UINT32_(0x2C)      /* (PIO_ISR) PIO Interrupt Status Register Offset */
#define PIO_IOFR_REG_OFST              _UINT32_(0x3C)      /* (PIO_IOFR) PIO I/O Freeze Configuration Register Offset */
#define PIO_P_MSKR_REG_OFST            _UINT32_(0x00)      /* (PIO_P_MSKR) PIO Privilege Mask Register (p_iogroup = 0) Offset */
#define PIO_P_CFGR_REG_OFST            _UINT32_(0x04)      /* (PIO_P_CFGR) PIO Privilege Configuration Register (p_iogroup = 0) Offset */
#define PIO_P_PDSR_REG_OFST            _UINT32_(0x08)      /* (PIO_P_PDSR) PIO Privilege Pin Data Status Register (p_iogroup = 0) Offset */
#define PIO_P_LOCKSR_REG_OFST          _UINT32_(0x0C)      /* (PIO_P_LOCKSR) PIO Privilege Lock Status Register (p_iogroup = 0) Offset */
#define PIO_P_SODR_REG_OFST            _UINT32_(0x10)      /* (PIO_P_SODR) PIO Privilege Set Output Data Register (p_iogroup = 0) Offset */
#define PIO_P_CODR_REG_OFST            _UINT32_(0x14)      /* (PIO_P_CODR) PIO Privilege Clear Output Data Register (p_iogroup = 0) Offset */
#define PIO_P_ODSR_REG_OFST            _UINT32_(0x18)      /* (PIO_P_ODSR) PIO Privilege Output Data Status Register (p_iogroup = 0) Offset */
#define PIO_P_IER_REG_OFST             _UINT32_(0x20)      /* (PIO_P_IER) PIO Privilege Interrupt Enable Register (p_iogroup = 0) Offset */
#define PIO_P_IDR_REG_OFST             _UINT32_(0x24)      /* (PIO_P_IDR) PIO Privilege Interrupt Disable Register (p_iogroup = 0) Offset */
#define PIO_P_IMR_REG_OFST             _UINT32_(0x28)      /* (PIO_P_IMR) PIO Privilege Interrupt Mask Register (p_iogroup = 0) Offset */
#define PIO_P_ISR_REG_OFST             _UINT32_(0x2C)      /* (PIO_P_ISR) PIO Privilege Interrupt Status Register (p_iogroup = 0) Offset */
#define PIO_P_SIO_UAR_REG_OFST         _UINT32_(0x30)      /* (PIO_P_SIO_UAR) PIO Privilege Set I/O User Register (p_iogroup = 0) Offset */
#define PIO_P_SIO_PAR_REG_OFST         _UINT32_(0x34)      /* (PIO_P_SIO_PAR) PIO Privilege Set I/O Privilege Register (p_iogroup = 0) Offset */
#define PIO_P_IOSSR_REG_OFST           _UINT32_(0x38)      /* (PIO_P_IOSSR) PIO Privilege I/O Security Status Register (p_iogroup = 0) Offset */
#define PIO_P_IOFR_REG_OFST            _UINT32_(0x3C)      /* (PIO_P_IOFR) PIO Privilege I/O Freeze Configuration Register (p_iogroup = 0) Offset */
#define PIO_WPMR_REG_OFST              _UINT32_(0x5E0)     /* (PIO_WPMR) PIO Write Protection Mode Register Offset */
#define PIO_WPSR_REG_OFST              _UINT32_(0x5E4)     /* (PIO_WPSR) PIO Write Protection Status Register Offset */
#define PIO_P_SCDR_REG_OFST            _UINT32_(0x1500)    /* (PIO_P_SCDR) PIO Privilege Slow Clock Divider Debouncing Register Offset */
#define PIO_P_WPMR_REG_OFST            _UINT32_(0x15E0)    /* (PIO_P_WPMR) PIO Privilege Write Protection Mode Register Offset */
#define PIO_P_WPSR_REG_OFST            _UINT32_(0x15E4)    /* (PIO_P_WPSR) PIO Privilege Write Protection Status Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief PIO_GROUP register API structure */
typedef struct
{
  __IO  uint32_t                       PIO_MSKR;           /**< Offset: 0x00 (R/W  32) PIO Mask Register */
  __IO  uint32_t                       PIO_CFGR;           /**< Offset: 0x04 (R/W  32) PIO Configuration Register */
  __I   uint32_t                       PIO_PDSR;           /**< Offset: 0x08 (R/   32) PIO Pin Data Status Register */
  __I   uint32_t                       PIO_LOCKSR;         /**< Offset: 0x0C (R/   32) PIO Lock Status Register */
  __O   uint32_t                       PIO_SODR;           /**< Offset: 0x10 ( /W  32) PIO Set Output Data Register */
  __O   uint32_t                       PIO_CODR;           /**< Offset: 0x14 ( /W  32) PIO Clear Output Data Register */
  __IO  uint32_t                       PIO_ODSR;           /**< Offset: 0x18 (R/W  32) PIO Output Data Status Register */
  __I   uint8_t                        Reserved1[0x04];
  __O   uint32_t                       PIO_IER;            /**< Offset: 0x20 ( /W  32) PIO Interrupt Enable Register */
  __O   uint32_t                       PIO_IDR;            /**< Offset: 0x24 ( /W  32) PIO Interrupt Disable Register */
  __I   uint32_t                       PIO_IMR;            /**< Offset: 0x28 (R/   32) PIO Interrupt Mask Register */
  __I   uint32_t                       PIO_ISR;            /**< Offset: 0x2C (R/   32) PIO Interrupt Status Register */
  __I   uint8_t                        Reserved2[0x0C];
  __O   uint32_t                       PIO_IOFR;           /**< Offset: 0x3C ( /W  32) PIO I/O Freeze Configuration Register */
} pio_group_registers_t;

/** \brief PIO_P register API structure */
typedef struct
{
  __IO  uint32_t                       PIO_P_MSKR;         /**< Offset: 0x00 (R/W  32) PIO Privilege Mask Register (p_iogroup = 0) */
  __IO  uint32_t                       PIO_P_CFGR;         /**< Offset: 0x04 (R/W  32) PIO Privilege Configuration Register (p_iogroup = 0) */
  __I   uint32_t                       PIO_P_PDSR;         /**< Offset: 0x08 (R/   32) PIO Privilege Pin Data Status Register (p_iogroup = 0) */
  __I   uint32_t                       PIO_P_LOCKSR;       /**< Offset: 0x0C (R/   32) PIO Privilege Lock Status Register (p_iogroup = 0) */
  __O   uint32_t                       PIO_P_SODR;         /**< Offset: 0x10 ( /W  32) PIO Privilege Set Output Data Register (p_iogroup = 0) */
  __O   uint32_t                       PIO_P_CODR;         /**< Offset: 0x14 ( /W  32) PIO Privilege Clear Output Data Register (p_iogroup = 0) */
  __IO  uint32_t                       PIO_P_ODSR;         /**< Offset: 0x18 (R/W  32) PIO Privilege Output Data Status Register (p_iogroup = 0) */
  __I   uint8_t                        Reserved1[0x04];
  __O   uint32_t                       PIO_P_IER;          /**< Offset: 0x20 ( /W  32) PIO Privilege Interrupt Enable Register (p_iogroup = 0) */
  __O   uint32_t                       PIO_P_IDR;          /**< Offset: 0x24 ( /W  32) PIO Privilege Interrupt Disable Register (p_iogroup = 0) */
  __I   uint32_t                       PIO_P_IMR;          /**< Offset: 0x28 (R/   32) PIO Privilege Interrupt Mask Register (p_iogroup = 0) */
  __I   uint32_t                       PIO_P_ISR;          /**< Offset: 0x2C (R/   32) PIO Privilege Interrupt Status Register (p_iogroup = 0) */
  __O   uint32_t                       PIO_P_SIO_UAR;      /**< Offset: 0x30 ( /W  32) PIO Privilege Set I/O User Register (p_iogroup = 0) */
  __O   uint32_t                       PIO_P_SIO_PAR;      /**< Offset: 0x34 ( /W  32) PIO Privilege Set I/O Privilege Register (p_iogroup = 0) */
  __I   uint32_t                       PIO_P_IOSSR;        /**< Offset: 0x38 (R/   32) PIO Privilege I/O Security Status Register (p_iogroup = 0) */
  __O   uint32_t                       PIO_P_IOFR;         /**< Offset: 0x3C ( /W  32) PIO Privilege I/O Freeze Configuration Register (p_iogroup = 0) */
} pio_p_registers_t;

#define PIO_GROUP_NUMBER 3

#define PIO_P_NUMBER 3

/** \brief PIO register API structure */
typedef struct
{
        pio_group_registers_t          PIO_GROUP[PIO_GROUP_NUMBER]; /**< Offset: 0x00  */
  __I   uint8_t                        Reserved1[0x520];
  __IO  uint32_t                       PIO_WPMR;           /**< Offset: 0x5E0 (R/W  32) PIO Write Protection Mode Register */
  __I   uint32_t                       PIO_WPSR;           /**< Offset: 0x5E4 (R/   32) PIO Write Protection Status Register */
  __I   uint8_t                        Reserved2[0xA18];
        pio_p_registers_t              PIO_P[PIO_P_NUMBER]; /**< Offset: 0x1000  */
  __I   uint8_t                        Reserved3[0x440];
  __IO  uint32_t                       PIO_P_SCDR;         /**< Offset: 0x1500 (R/W  32) PIO Privilege Slow Clock Divider Debouncing Register */
  __I   uint8_t                        Reserved4[0xDC];
  __IO  uint32_t                       PIO_P_WPMR;         /**< Offset: 0x15E0 (R/W  32) PIO Privilege Write Protection Mode Register */
  __I   uint32_t                       PIO_P_WPSR;         /**< Offset: 0x15E4 (R/   32) PIO Privilege Write Protection Status Register */
} pio_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CXMTG_PIO_COMPONENT_H_ */
