/**
 * @file fxos8700cq.h
 * @brief FXOS8700CQ 6-axis sensor
 *
 * @section License
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * Copyright (C) 2010-2024 Oryx Embedded SARL. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * @author Oryx Embedded SARL (www.oryx-embedded.com)
 * @version 2.4.4
 **/

#ifndef _FXOS8700CQ_H
#define _FXOS8700CQ_H

//Dependencies
#include "os_port.h"
#include "error.h"

//FXOS8700CQ registers
#define FXOS8700CQ_REG_STATUS           0x00
#define FXOS8700CQ_REG_OUT_X_MSB        0x01
#define FXOS8700CQ_REG_OUT_X_LSB        0x02
#define FXOS8700CQ_REG_OUT_Y_MSB        0x03
#define FXOS8700CQ_REG_OUT_Y_LSB        0x04
#define FXOS8700CQ_REG_OUT_Z_MSB        0x05
#define FXOS8700CQ_REG_OUT_Z_LSB        0x06
#define FXOS8700CQ_REG_F_SETUP          0x09
#define FXOS8700CQ_REG_TRIG_CFG         0x0A
#define FXOS8700CQ_REG_SYSMOD           0x0B
#define FXOS8700CQ_REG_INT_SOURCE       0x0C
#define FXOS8700CQ_REG_WHO_AM_I         0x0D
#define FXOS8700CQ_REG_XYZ_DATA_CFG     0x0E
#define FXOS8700CQ_REG_HP_FILTER_CUTOFF 0x0F
#define FXOS8700CQ_REG_PL_STATUS        0x10
#define FXOS8700CQ_REG_PL_CFG           0x11
#define FXOS8700CQ_REG_PL_COUNT         0x12
#define FXOS8700CQ_REG_PL_BF_ZCOMP      0x13
#define FXOS8700CQ_REG_PL_THS_REG       0x14
#define FXOS8700CQ_REG_A_FFMT_CFG       0x15
#define FXOS8700CQ_REG_A_FFMT_SRC       0x16
#define FXOS8700CQ_REG_A_FFMT_THS       0x17
#define FXOS8700CQ_REG_A_FFMT_COUNT     0x18
#define FXOS8700CQ_REG_TRANSIENT_CFG    0x1D
#define FXOS8700CQ_REG_TRANSIENT_SRC    0x1E
#define FXOS8700CQ_REG_TRANSIENT_THS    0x1F
#define FXOS8700CQ_REG_TRANSIENT_COUNT  0x20
#define FXOS8700CQ_REG_PULSE_CFG        0x21
#define FXOS8700CQ_REG_PULSE_SRC        0x22
#define FXOS8700CQ_REG_PULSE_THSX       0x23
#define FXOS8700CQ_REG_PULSE_THSY       0x24
#define FXOS8700CQ_REG_PULSE_THSZ       0x25
#define FXOS8700CQ_REG_PULSE_TMLT       0x26
#define FXOS8700CQ_REG_PULSE_LTCY       0x27
#define FXOS8700CQ_REG_PULSE_WIND       0x28
#define FXOS8700CQ_REG_ASLP_COUNT       0x29
#define FXOS8700CQ_REG_CTRL_REG1        0x2A
#define FXOS8700CQ_REG_CTRL_REG2        0x2B
#define FXOS8700CQ_REG_CTRL_REG3        0x2C
#define FXOS8700CQ_REG_CTRL_REG4        0x2D
#define FXOS8700CQ_REG_CTRL_REG5        0x2E
#define FXOS8700CQ_REG_OFF_X            0x2F
#define FXOS8700CQ_REG_OFF_Y            0x30
#define FXOS8700CQ_REG_OFF_Z            0x31
#define FXOS8700CQ_REG_M_DR_STATUS      0x32
#define FXOS8700CQ_REG_M_OUT_X_MSB      0x33
#define FXOS8700CQ_REG_M_OUT_X_LSB      0x34
#define FXOS8700CQ_REG_M_OUT_Y_MSB      0x35
#define FXOS8700CQ_REG_M_OUT_Y_LSB      0x36
#define FXOS8700CQ_REG_M_OUT_Z_MSB      0x37
#define FXOS8700CQ_REG_M_OUT_Z_LSB      0x38
#define FXOS8700CQ_REG_CMP_X_MSB        0x39
#define FXOS8700CQ_REG_CMP_X_LSB        0x3A
#define FXOS8700CQ_REG_CMP_Y_MSB        0x3B
#define FXOS8700CQ_REG_CMP_Y_LSB        0x3C
#define FXOS8700CQ_REG_CMP_Z_MSB        0x3D
#define FXOS8700CQ_REG_CMP_Z_LSB        0x3E
#define FXOS8700CQ_REG_M_OFF_X_MSB      0x3F
#define FXOS8700CQ_REG_M_OFF_X_LSB      0x40
#define FXOS8700CQ_REG_M_OFF_Y_MSB      0x41
#define FXOS8700CQ_REG_M_OFF_Y_LSB      0x42
#define FXOS8700CQ_REG_M_OFF_Z_MSB      0x43
#define FXOS8700CQ_REG_M_OFF_Z_LSB      0x44
#define FXOS8700CQ_REG_MAX_X_MSB        0x45
#define FXOS8700CQ_REG_MAX_X_LSB        0x46
#define FXOS8700CQ_REG_MAX_Y_MSB        0x47
#define FXOS8700CQ_REG_MAX_Y_LSB        0x48
#define FXOS8700CQ_REG_MAX_Z_MSB        0x49
#define FXOS8700CQ_REG_MAX_Z_LSB        0x4A
#define FXOS8700CQ_REG_MIN_X_MSB        0x4B
#define FXOS8700CQ_REG_MIN_X_LSB        0x4C
#define FXOS8700CQ_REG_MIN_Y_MSB        0x4D
#define FXOS8700CQ_REG_MIN_Y_LSB        0x4E
#define FXOS8700CQ_REG_MIN_Z_MSB        0x4F
#define FXOS8700CQ_REG_MIN_Z_LSB        0x50
#define FXOS8700CQ_REG_TEMP             0x51
#define FXOS8700CQ_REG_M_THS_CFG        0x52
#define FXOS8700CQ_REG_M_THS_SRC        0x53
#define FXOS8700CQ_REG_M_THS_X_MSB      0x54
#define FXOS8700CQ_REG_M_THS_X_LSB      0x55
#define FXOS8700CQ_REG_M_THS_Y_MSB      0x56
#define FXOS8700CQ_REG_M_THS_Y_LSB      0x57
#define FXOS8700CQ_REG_M_THS_Z_MSB      0x58
#define FXOS8700CQ_REG_M_THS_Z_LSB      0x59
#define FXOS8700CQ_REG_M_THS_COUNT      0x5A
#define FXOS8700CQ_REG_M_CTRL_REG1      0x5B
#define FXOS8700CQ_REG_M_CTRL_REG2      0x5C
#define FXOS8700CQ_REG_M_CTRL_REG3      0x5D
#define FXOS8700CQ_REG_M_INT_SRC        0x5E
#define FXOS8700CQ_REG_A_VECM_CFG       0x5F
#define FXOS8700CQ_REG_A_VECM_THS_MSB   0x60
#define FXOS8700CQ_REG_A_VECM_THS_LSB   0x61
#define FXOS8700CQ_REG_A_VECM_CNT       0x62
#define FXOS8700CQ_REG_A_VECM_INITX_MSB 0x63
#define FXOS8700CQ_REG_A_VECM_INITX_LSB 0x64
#define FXOS8700CQ_REG_A_VECM_INITY_MSB 0x65
#define FXOS8700CQ_REG_A_VECM_INITY_LSB 0x66
#define FXOS8700CQ_REG_A_VECM_INITZ_MSB 0x67
#define FXOS8700CQ_REG_A_VECM_INITZ_LSB 0x68
#define FXOS8700CQ_REG_M_VECM_CFG       0x69
#define FXOS8700CQ_REG_M_VECM_THS_MSB   0x6A
#define FXOS8700CQ_REG_M_VECM_THS_LSB   0x6B
#define FXOS8700CQ_REG_M_VECM_CNT       0x6C
#define FXOS8700CQ_REG_M_VECM_INITX_MSB 0x6D
#define FXOS8700CQ_REG_M_VECM_INITX_LSB 0x6E
#define FXOS8700CQ_REG_M_VECM_INITY_MSB 0x6F
#define FXOS8700CQ_REG_M_VECM_INITY_LSB 0x70
#define FXOS8700CQ_REG_M_VECM_INITZ_MSB 0x71
#define FXOS8700CQ_REG_M_VECM_INITZ_LSB 0x72
#define FXOS8700CQ_REG_A_FFMT_THS_X_MSB 0x73
#define FXOS8700CQ_REG_A_FFMT_THS_X_LSB 0x74
#define FXOS8700CQ_REG_A_FFMT_THS_Y_MSB 0x75
#define FXOS8700CQ_REG_A_FFMT_THS_Y_LSB 0x76
#define FXOS8700CQ_REG_A_FFMT_THS_Z_MSB 0x77
#define FXOS8700CQ_REG_A_FFMT_THS_Z_LSB 0x78

//WHO_AM_I register
#define WHO_AM_I_FXOS8700CQ             0xC7

//XYZ_DATA_CFG register
#define XYZ_DATA_CFG_HPF_OUT            0x10
#define XYZ_DATA_CFG_FS_MASK            0x03
#define XYZ_DATA_CFG_FS_2G              0x00
#define XYZ_DATA_CFG_FS_4G              0x01
#define XYZ_DATA_CFG_FS_8G              0x02

//CTRL_REG1 register
#define CTRL_REG1_ASLP_RATE_MASK        0xC0
#define CTRL_REG1_ASLP_RATE_50HZ        0x00
#define CTRL_REG1_ASLP_RATE_12_5HZ      0x40
#define CTRL_REG1_ASLP_RATE_6_25HZ      0x80
#define CTRL_REG1_ASLP_RATE_1_56HZ      0xC0
#define CTRL_REG1_DR_MASK               0x38
#define CTRL_REG1_DR_800HZ              0x00
#define CTRL_REG1_DR_400HZ              0x08
#define CTRL_REG1_DR_200HZ              0x10
#define CTRL_REG1_DR_100HZ              0x18
#define CTRL_REG1_DR_50HZ               0x20
#define CTRL_REG1_DR_12_5HZ             0x28
#define CTRL_REG1_DR_6_25HZ             0x30
#define CTRL_REG1_DR_1_56HZ             0x38
#define CTRL_REG1_LNOISE                0x04
#define CTRL_REG1_F_READ                0x02
#define CTRL_REG1_ACTIVE                0x01

//FXOS8700CQ related functions
error_t fxos8700cqInit(void);
error_t fxos8700cqGetAcc(int8_t *ax, int8_t *ay, int8_t *az);
error_t fxos8700cqWriteReg(uint8_t address, uint8_t data);
error_t fxos8700cqReadReg(uint8_t address, uint8_t *data);

//I2C related functions
void i2cInit(void);
void i2cDelay(void);
void i2cStart(void);
void i2cStop(void);
void i2cRepeatedStart(void);
error_t i2cWrite(uint8_t data);
uint8_t i2cRead(bool_t ack);

#endif
