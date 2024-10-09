/**
 * @file fxls8974cf.h
 * @brief FXLS8974CF 6-axis accelerometer
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

#ifndef _FXLS8974CF_H
#define _FXLS8974CF_H

//Dependencies
#include "os_port.h"
#include "error.h"

//FXLS8974CF registers
#define FXLS8974CF_INT_STATUS                    0x00
#define FXLS8974CF_TEMP_OUT                      0x01
#define FXLS8974CF_VECM_LSB                      0x02
#define FXLS8974CF_VECM_MSB                      0x03
#define FXLS8974CF_OUT_X_LSB                     0x04
#define FXLS8974CF_OUT_X_MSB                     0x05
#define FXLS8974CF_OUT_Y_LSB                     0x06
#define FXLS8974CF_OUT_Y_MSB                     0x07
#define FXLS8974CF_OUT_Z_LSB                     0x08
#define FXLS8974CF_OUT_Z_MSB                     0x09
#define FXLS8974CF_BUF_STATUS                    0x0B
#define FXLS8974CF_BUF_X_LSB                     0x0C
#define FXLS8974CF_BUF_X_MSB                     0x0D
#define FXLS8974CF_BUF_Y_LSB                     0x0E
#define FXLS8974CF_BUF_Y_MSB                     0x0F
#define FXLS8974CF_BUF_Z_LSB                     0x10
#define FXLS8974CF_BUF_Z_MSB                     0x11
#define FXLS8974CF_PROD_REV                      0x12
#define FXLS8974CF_WHO_AM_I                      0x13
#define FXLS8974CF_SYS_MODE                      0x14
#define FXLS8974CF_SENS_CONFIG1                  0x15
#define FXLS8974CF_SENS_CONFIG2                  0x16
#define FXLS8974CF_SENS_CONFIG3                  0x17
#define FXLS8974CF_SENS_CONFIG4                  0x18
#define FXLS8974CF_SENS_CONFIG5                  0x19
#define FXLS8974CF_WAKE_IDLE                     0x1A
#define FXLS8974CF_WAKE_IDLE_MSB                 0x1B
#define FXLS8974CF_SLEEP_IDLE_LSB                0x1C
#define FXLS8974CF_SLEEP_IDLE_MSB                0x1D
#define FXLS8974CF_ASLP_COUNT_LSB                0x1E
#define FXLS8974CF_ASLP_COUNT_MSB                0x1F
#define FXLS8974CF_INT_EN                        0x20
#define FXLS8974CF_INT_PIN_SEL                   0x21
#define FXLS8974CF_OFF_X                         0x22
#define FXLS8974CF_OFF_Y                         0x23
#define FXLS8974CF_OFF_Z                         0x24
#define FXLS8974CF_BUF_CONFIG1                   0x26
#define FXLS8974CF_BUF_CONFIG2                   0x27
#define FXLS8974CF_ORIENT_STATUS                 0x28
#define FXLS8974CF_ORIENT_CONFIG                 0x29
#define FXLS8974CF_ORIENT_DBCOUNT                0x2A
#define FXLS8974CF_ORIENT_BF_ZCOMP               0x2B
#define FXLS8974CF_ORIENT_THS_REG                0x2C
#define FXLS8974CF_SDCD_INT_SRC1                 0x2D
#define FXLS8974CF_SDCD_INT_SRC2                 0x2E
#define FXLS8974CF_SDCD_CONFIG1                  0x2F
#define FXLS8974CF_SDCD_CONFIG2                  0x30
#define FXLS8974CF_SDCD_OT_DBCNT                 0x31
#define FXLS8974CF_SDCD_WT_DBCNT                 0x32
#define FXLS8974CF_SDCD_LTHS_LSB                 0x33
#define FXLS8974CF_SDCD_LTHS_MSB                 0x34
#define FXLS8974CF_SDCD_UTHS_LSB                 0x35
#define FXLS8974CF_SDCD_UTHS_MSB                 0x36
#define FXLS8974CF_SELF_TEST_CONFIG1             0x37
#define FXLS8974CF_SELF_TEST_CONFIG2             0x38

//WHO_AM_I register
#define FXLS8974CF_WHO_AM_I_DEFAULT              0x86

//SENS_CONFIG1 register
#define FXLS8974CF_SENS_CONFIG1_RST              0x80
#define FXLS8974CF_SENS_CONFIG1_ST_AXIS_SEL      0x60
#define FXLS8974CF_SENS_CONFIG1_ST_POL           0x10
#define FXLS8974CF_SENS_CONFIG1_SPI_M            0x08
#define FXLS8974CF_SENS_CONFIG1_FSR              0x06
#define FXLS8974CF_SENS_CONFIG1_FSR_2G           0x00
#define FXLS8974CF_SENS_CONFIG1_FSR_4G           0x02
#define FXLS8974CF_SENS_CONFIG1_FSR_8G           0x04
#define FXLS8974CF_SENS_CONFIG1_FSR_16G          0x06
#define FXLS8974CF_SENS_CONFIG1_ACTIVE           0x01

//SENS_CONFIG2 register
#define FXLS8974CF_SENS_CONFIG2_WAKE_PM          0xC0
#define FXLS8974CF_SENS_CONFIG2_SLEEP_PM         0x30
#define FXLS8974CF_SENS_CONFIG2_LE_BE            0x08
#define FXLS8974CF_SENS_CONFIG2_AINC_TEMP        0x02
#define FXLS8974CF_SENS_CONFIG2_F_READ           0x01

//SENS_CONFIG3 register
#define FXLS8974CF_SENS_CONFIG3_WAKE_ODR         0xF0
#define FXLS8974CF_SENS_CONFIG3_WAKE_ODR_3200HZ  0x00
#define FXLS8974CF_SENS_CONFIG3_WAKE_ODR_50HZ    0x60
#define FXLS8974CF_SENS_CONFIG3_SLEEP_ODR        0x0F
#define FXLS8974CF_SENS_CONFIG3_SLEEP_ODR_3200HZ 0x00
#define FXLS8974CF_SENS_CONFIG3_SLEEP_ODR_50HZ   0x06

//FXLS8974CF related functions
error_t fxls8974cfInit(void);
error_t fxls8974cfGetAcc(int8_t *ax, int8_t *ay, int8_t *az);
error_t fxls8974cfWriteReg(uint8_t address, uint8_t data);
error_t fxls8974cfReadReg(uint8_t address, uint8_t *data);

//I2C related functions
void i2cInit(void);
void i2cDelay(void);
void i2cStart(void);
void i2cStop(void);
void i2cRepeatedStart(void);
error_t i2cWrite(uint8_t data);
uint8_t i2cRead(bool_t ack);

#endif
