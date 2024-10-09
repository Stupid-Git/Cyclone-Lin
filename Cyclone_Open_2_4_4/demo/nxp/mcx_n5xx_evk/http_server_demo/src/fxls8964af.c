/**
 * @file fxls8964af.c
 * @brief FXLS8964AF 3-axis accelerometer
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

//Dependencies
#include "fsl_device_registers.h"
#include "fsl_gpio.h"
#include "fsl_port.h"
#include "fxls8964af.h"
#include "error.h"
#include "debug.h"

//I2C slave address
#define FXLS8964AF_SLAVE_ADDR_W 0x32
#define FXLS8964AF_SLAVE_ADDR_R 0x33

//I2C pins
#define SCL_OUT(a) GPIO_PinWrite(GPIO4, 1, a)
#define SDA_OUT(a) GPIO4->PDDR |= (1U << 0), GPIO_PinWrite(GPIO4, 0, a)
#define SDA_IN() GPIO_PinRead(GPIO4, 0)


/**
 * @brief FXLS8964AF initialization
 * @return Error code (see #ErrorCode enumeration)
 **/

error_t fxls8964afInit(void)
{
   error_t error;
   uint8_t value;

   //Debug message
   TRACE_INFO("Initializing FXLS8964AF...\r\n");

   //I2C initialization
   i2cInit();

   //Read WHO_AM_I register
   error = fxls8964afReadReg(FXLS8964AF_WHO_AM_I, &value);
   //Any error to report?
   if(error)
      return error;

   //Verify chip identifier
   if(value != FXLS8964AF_WHO_AM_I_DEFAULT &&
      value != FXLS8974CF_WHO_AM_I_DEFAULT)
   {
      return ERROR_INVALID_VERSION;
   }

   //Enter standby mode
   error = fxls8964afWriteReg(FXLS8964AF_SENS_CONFIG1, 0);
   //Any error to report?
   if(error)
      return error;

   //Select big-endian output mode
   error = fxls8964afWriteReg(FXLS8964AF_SENS_CONFIG2,
      FXLS8964AF_SENS_CONFIG2_LE_BE);
   //Any error to report?
   if(error)
      return error;

   //Select 50Hz bandwidth
   error = fxls8964afWriteReg(FXLS8964AF_SENS_CONFIG3,
      FXLS8964AF_SENS_CONFIG3_WAKE_ODR_50HZ |
      FXLS8964AF_SENS_CONFIG3_SLEEP_ODR_50HZ);
   //Any error to report?
   if(error)
      return error;

   //Select +/-2g range
   error = fxls8964afWriteReg(FXLS8964AF_SENS_CONFIG1,
      FXLS8964AF_SENS_CONFIG1_FSR_2G |
      FXLS8964AF_SENS_CONFIG1_ACTIVE);
   //Any error to report?
   if(error)
      return error;

   //Successful initialization
   return NO_ERROR;
}


/**
 * @brief Get acceleration data
 * @param[out] ax Acceleration value (X axis)
 * @param[out] ay Acceleration value (Y axis)
 * @param[out] az Acceleration value (Z axis)
 * @param[in] data Register value
 * @return Error code (see #ErrorCode enumeration)
 **/

error_t fxls8964afGetAcc(int8_t *ax, int8_t *ay, int8_t *az)
{
   error_t error;

   //Issue a start condition
   i2cStart();

   //Send I2C slave address
   error = i2cWrite(FXLS8964AF_SLAVE_ADDR_W);

   //Check status code
   if(!error)
   {
      //Write register address
      error = i2cWrite(FXLS8964AF_OUT_X_LSB);
   }

   //Check status code
   if(!error)
   {
      //Issue a repeated start condition
      i2cRepeatedStart();

      //Send I2C slave address
      error = i2cWrite(FXLS8964AF_SLAVE_ADDR_R);

      if(!error)
      {
         //Read ax acceleration value (MSB)
         *ax = i2cRead(TRUE);
         //Read ax acceleration value (LSB)
         i2cRead(TRUE);

         //Read ay acceleration value (MSB)
         *ay = i2cRead(TRUE);
         //Read ay acceleration value (LSB)
         i2cRead(TRUE);

         //Read az acceleration value (MSB)
         *az = i2cRead(TRUE);
         //Read az acceleration value (LSB)
         i2cRead(FALSE);
      }
   }

   //Issue a stop condition
   i2cStop();

   //Return status code
   return error;
}


/**
 * @brief Write FXLS8964AF register
 * @param[in] address Register address
 * @param[in] data Register value
 * @return Error code (see #ErrorCode enumeration)
 **/

error_t fxls8964afWriteReg(uint8_t address, uint8_t data)
{
   error_t error;

   //Issue a start condition
   i2cStart();

   //Send I2C slave address
   error = i2cWrite(FXLS8964AF_SLAVE_ADDR_W);

   //Check status code
   if(!error)
   {
      //Write register address
      error = i2cWrite(address);
   }

   //Check status code
   if(!error)
   {
      //Write register value
      error = i2cWrite(data);
   }

   //Issue a stop condition
   i2cStop();

   //Return status code
   return error;
}


/**
 * @brief Read FXLS8964AF register
 * @param[in] address Register address
 * @param[out] data Register value
 * @return Error code (see #ErrorCode enumeration)
 **/

error_t fxls8964afReadReg(uint8_t address, uint8_t *data)
{
   error_t error;

   //Issue a start condition
   i2cStart();

   //Send I2C slave address
   error = i2cWrite(FXLS8964AF_SLAVE_ADDR_W);

   //Check status code
   if(!error)
   {
      //Write register address
      error = i2cWrite(address);
   }

   //Check status code
   if(!error)
   {
      //Issue a repeated start condition
      i2cRepeatedStart();

      //Send I2C slave address
      error = i2cWrite(FXLS8964AF_SLAVE_ADDR_R);

      //Check status code
      if(!error)
      {
         //Read register value
         *data = i2cRead(FALSE);
      }
   }

   //Issue a stop condition
   i2cStop();

   //Return status code
   return error;
}


/**
 * @brief I2C initialization
 **/

void i2cInit(void)
{
   port_pin_config_t portPinConfig;
   gpio_pin_config_t gpioPinConfig;

   //Enable PORT4 clock
   CLOCK_EnableClock(kCLOCK_Port4);
   //Enable GPIO4 clock
   CLOCK_EnableClock(kCLOCK_Gpio4);

   //Initialize port pin attributes
   portPinConfig.pullSelect = kPORT_PullUp;
   portPinConfig.pullValueSelect = kPORT_LowPullResistor;
   portPinConfig.slewRate = kPORT_SlowSlewRate;
   portPinConfig.passiveFilterEnable = kPORT_PassiveFilterDisable;
   portPinConfig.openDrainEnable = kPORT_OpenDrainEnable;
   portPinConfig.driveStrength = kPORT_LowDriveStrength;
   portPinConfig.mux = kPORT_MuxAlt0;
   portPinConfig.inputBuffer = kPORT_InputBufferEnable;
   portPinConfig.invertInput = kPORT_InputNormal;
   portPinConfig.lockRegister = kPORT_UnlockRegister;

   //Configure PORT4_0 pin as PIO4_0
   PORT_SetPinConfig(PORT4, 0, &portPinConfig);
   //Configure PORT4_1 pin as PIO4_1
   PORT_SetPinConfig(PORT4, 1, &portPinConfig);

   //Configure FC2_I2C_SCL
   gpioPinConfig.pinDirection = kGPIO_DigitalOutput;
   gpioPinConfig.outputLogic = 1;
   GPIO_PinInit(GPIO4, 1, &gpioPinConfig);

   //Configure FC2_I2C_SDA
   gpioPinConfig.pinDirection = kGPIO_DigitalOutput;
   gpioPinConfig.outputLogic = 1;
   GPIO_PinInit(GPIO4, 0, &gpioPinConfig);
}


/**
 * @brief I2C delay
 **/

void i2cDelay(void)
{
   volatile uint_t delay;

   //Delay loop
   for(delay = 0; delay < 500; delay++);
}


/**
 * @brief I2C start condition
 **/

void i2cStart(void)
{
   SDA_OUT(1);
   SCL_OUT(1);
   i2cDelay();

   //Pull SDA to low level
   SDA_OUT(0);
   i2cDelay();

   //Pull SCL to low level
   SCL_OUT(0);
   i2cDelay();
}


/**
 * @brief I2C stop condition
 **/

void i2cStop(void)
{
   SDA_OUT(0);
   i2cDelay();

   //Release SCL
   SCL_OUT(1);
   i2cDelay();

   //Release SDA
   SDA_OUT(1);
   i2cDelay();
}


/**
 * @brief I2C repeated start condition
 **/

void i2cRepeatedStart(void)
{
   //Release SDA
   SDA_OUT(1);
   i2cDelay();

   //Release SCL
   SCL_OUT(1);
   i2cDelay();

   //Pull SDA to low level
   SDA_OUT(0);
   i2cDelay();

   //Pull SCL to low level
   SCL_OUT(0);
   i2cDelay();
}


/**
 * @brief I2C write operation
 * @param[in] data Data byte to be written
 * @return Error code
 **/

error_t i2cWrite(uint8_t data)
{
   error_t error;
   uint_t i;

   //Iterate 8 times
   for(i = 0; i < 8; i++)
   {
      //Set SDA state
      if(data & 0x80)
         SDA_OUT(1);
      else
         SDA_OUT(0);

      //Pulse SCL
      i2cDelay();
      SCL_OUT(1);
      i2cDelay();
      SCL_OUT(0);
      i2cDelay();

      //Shift data byte
      data <<= 1;
   }

   //Release SDA in order to read ACK bit
   SDA_OUT(1);
   i2cDelay();

   //Set SCL to high level
   SCL_OUT(1);
   i2cDelay();

   GPIO4->PDDR &= ~(1U << 0);

   //Retrieve ACK value
   if(SDA_IN())
      error = ERROR_FAILURE;
   else
      error = NO_ERROR;

   //Pull SCL to low level
   SCL_OUT(0);
   i2cDelay();

   //Return status code
   return error;
}


/**
 * @brief I2C read operation
 * @param[out] ack ACK value
 * @return Data byte resulting from the read operation
 **/

uint8_t i2cRead(bool_t ack)
{
   uint_t i;
   uint8_t data;

   //Clear data
   data = 0;

   //Release SDA
   SDA_OUT(1);
   i2cDelay();

   GPIO4->PDDR &= ~(1U << 0);

   //Iterate 8 times
   for(i = 0; i < 8; i++)
   {
      //Shift data byte
      data <<= 1;

      //Set SCL to high level
      SCL_OUT(1);
      i2cDelay();

      //Retrieve bit value
      if(SDA_IN())
         data |= 1;

      //Pull SCL to low level
      SCL_OUT(0);
      i2cDelay();
   }

   //Write ACK bit
   if(ack)
      SDA_OUT(0);
   else
      SDA_OUT(1);

   //Pulse SCL
   i2cDelay();
   SCL_OUT(1);
   i2cDelay();
   SCL_OUT(0);
   i2cDelay();

   //Return data byte
   return data;
}
