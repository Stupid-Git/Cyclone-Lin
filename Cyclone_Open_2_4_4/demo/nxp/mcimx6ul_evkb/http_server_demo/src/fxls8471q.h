/**
 * @file fxls8471q.h
 * @brief FXLS8471Q triaxial acceleration sensor
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

#ifndef _FXLS8471Q_H
#define _FXLS8471Q_H

//Dependencies
#include "os_port.h"
#include "error.h"

//FXLS8471Q registers
#define FXLS8471Q_REG_STATUS           0x00
#define FXLS8471Q_REG_OUT_X_MSB        0x01
#define FXLS8471Q_REG_OUT_X_LSB        0x02
#define FXLS8471Q_REG_OUT_Y_MSB        0x03
#define FXLS8471Q_REG_OUT_Y_LSB        0x04
#define FXLS8471Q_REG_OUT_Z_MSB        0x05
#define FXLS8471Q_REG_OUT_Z_LSB        0x06
#define FXLS8471Q_REG_F_SETUP          0x09
#define FXLS8471Q_REG_TRIG_CFG         0x0A
#define FXLS8471Q_REG_SYSMOD           0x0B
#define FXLS8471Q_REG_INT_SOURCE       0x0C
#define FXLS8471Q_REG_WHO_AM_I         0x0D
#define FXLS8471Q_REG_XYZ_DATA_CFG     0x0E
#define FXLS8471Q_REG_HP_FILTER_CUTOFF 0x0F
#define FXLS8471Q_REG_PL_STATUS        0x10
#define FXLS8471Q_REG_PL_CFG           0x11
#define FXLS8471Q_REG_PL_COUNT         0x12
#define FXLS8471Q_REG_PL_BF_ZCOMP      0x13
#define FXLS8471Q_REG_PL_THS_REG       0x14
#define FXLS8471Q_REG_A_FFMT_CFG       0x15
#define FXLS8471Q_REG_A_FFMT_SRC       0x16
#define FXLS8471Q_REG_A_FFMT_THS       0x17
#define FXLS8471Q_REG_A_FFMT_COUNT     0x18
#define FXLS8471Q_REG_TRANSIENT_CFG    0x1D
#define FXLS8471Q_REG_TRANSIENT_SRC    0x1E
#define FXLS8471Q_REG_TRANSIENT_THS    0x1F
#define FXLS8471Q_REG_TRANSIENT_COUNT  0x20
#define FXLS8471Q_REG_PULSE_CFG        0x21
#define FXLS8471Q_REG_PULSE_SRC        0x22
#define FXLS8471Q_REG_PULSE_THSX       0x23
#define FXLS8471Q_REG_PULSE_THSY       0x24
#define FXLS8471Q_REG_PULSE_THSZ       0x25
#define FXLS8471Q_REG_PULSE_TMLT       0x26
#define FXLS8471Q_REG_PULSE_LTCY       0x27
#define FXLS8471Q_REG_PULSE_WIND       0x28
#define FXLS8471Q_REG_ASLP_COUNT       0x29
#define FXLS8471Q_REG_CTRL_REG1        0x2A
#define FXLS8471Q_REG_CTRL_REG2        0x2B
#define FXLS8471Q_REG_CTRL_REG3        0x2C
#define FXLS8471Q_REG_CTRL_REG4        0x2D
#define FXLS8471Q_REG_CTRL_REG5        0x2E
#define FXLS8471Q_REG_OFF_X            0x2F
#define FXLS8471Q_REG_OFF_Y            0x30
#define FXLS8471Q_REG_OFF_Z            0x31
#define FXLS8471Q_REG_TEMP_OUT         0x51
#define FXLS8471Q_REG_CTRL_REG6        0x5B
#define FXLS8471Q_REG_CTRL_REG7        0x5C
#define FXLS8471Q_REG_A_VECM_CFG       0x5F
#define FXLS8471Q_REG_A_VECM_THS_MSB   0x60
#define FXLS8471Q_REG_A_VECM_THS_LSB   0x61
#define FXLS8471Q_REG_A_VECM_CNT       0x62
#define FXLS8471Q_REG_A_VECM_INITX_MSB 0x63
#define FXLS8471Q_REG_A_VECM_INITX_LSB 0x64
#define FXLS8471Q_REG_A_VECM_INITY_MSB 0x65
#define FXLS8471Q_REG_A_VECM_INITY_LSB 0x66
#define FXLS8471Q_REG_A_VECM_INITZ_MSB 0x67
#define FXLS8471Q_REG_A_VECM_INITZ_LSB 0x68
#define FXLS8471Q_REG_A_FFMT_THS_X_MSB 0x73
#define FXLS8471Q_REG_A_FFMT_THS_X_LSB 0x74
#define FXLS8471Q_REG_A_FFMT_THS_Y_MSB 0x75
#define FXLS8471Q_REG_A_FFMT_THS_Y_LSB 0x76
#define FXLS8471Q_REG_A_FFMT_THS_Z_MSB 0x77
#define FXLS8471Q_REG_A_FFMT_THS_Z_LSB 0x78

//WHO_AM_I register
#define WHO_AM_I_FXLS8471Q             0x6A

//XYZ_DATA_CFG register
#define XYZ_DATA_CFG_HPF_OUT           0x10
#define XYZ_DATA_CFG_FS_MASK           0x03
#define XYZ_DATA_CFG_FS_2G             0x00
#define XYZ_DATA_CFG_FS_4G             0x01
#define XYZ_DATA_CFG_FS_8G             0x02

//CTRL_REG1 register
#define CTRL_REG1_ASLP_RATE_MASK       0xC0
#define CTRL_REG1_ASLP_RATE_50HZ       0x00
#define CTRL_REG1_ASLP_RATE_12_5HZ     0x40
#define CTRL_REG1_ASLP_RATE_6_25HZ     0x80
#define CTRL_REG1_ASLP_RATE_1_56HZ     0xC0
#define CTRL_REG1_DR_MASK              0x38
#define CTRL_REG1_DR_800HZ             0x00
#define CTRL_REG1_DR_400HZ             0x08
#define CTRL_REG1_DR_200HZ             0x10
#define CTRL_REG1_DR_100HZ             0x18
#define CTRL_REG1_DR_50HZ              0x20
#define CTRL_REG1_DR_12_5HZ            0x28
#define CTRL_REG1_DR_6_25HZ            0x30
#define CTRL_REG1_DR_1_56HZ            0x38
#define CTRL_REG1_LNOISE               0x04
#define CTRL_REG1_F_READ               0x02
#define CTRL_REG1_ACTIVE               0x01

//FXLS8471Q related functions
error_t fxls8471qInit(void);
error_t fxls8471qGetAcc(int8_t *ax, int8_t *ay, int8_t *az);
error_t fxls8471qWriteReg(uint8_t address, uint8_t data);
error_t fxls8471qReadReg(uint8_t address, uint8_t *data);

//I2C related functions
void i2cInit(void);
void i2cDelay(void);
void i2cStart(void);
void i2cStop(void);
void i2cRepeatedStart(void);
error_t i2cWrite(uint8_t data);
uint8_t i2cRead(bool_t ack);

#endif
