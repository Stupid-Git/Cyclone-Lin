//###########################################################################
// FILE:   i2c.h
// TITLE:  Prototypes for the I2C Driver.
//###########################################################################
// $TI Release: F28M35x Support Library v206 $
// $Release Date: Thu Mar  5 10:10:30 CST 2015 $
// $Copyright:
// Copyright (C) 2011-2015 Texas Instruments Incorporated - http://www.ti.com/
//
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions 
// are met:
// 
//   Redistributions of source code must retain the above copyright 
//   notice, this list of conditions and the following disclaimer.
// 
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the 
//   documentation and/or other materials provided with the   
//   distribution.
// 
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// $
//###########################################################################

#ifndef __I2C_H__
#define __I2C_H__

//*****************************************************************************
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
// Defines for the API.
//*****************************************************************************

//*****************************************************************************
// Interrupt defines.
//*****************************************************************************
#define I2C_INT_MASTER                             0x00000001
#define I2C_INT_SLAVE                              0x00000002

//*****************************************************************************
// I2C Master commands.
//*****************************************************************************
#define I2C_MASTER_CMD_SINGLE_SEND                 0x00000007
#define I2C_MASTER_CMD_SINGLE_RECEIVE              0x00000007
#define I2C_MASTER_CMD_BURST_SEND_START            0x00000003
#define I2C_MASTER_CMD_BURST_SEND_CONT             0x00000001
#define I2C_MASTER_CMD_BURST_SEND_FINISH           0x00000005
#define I2C_MASTER_CMD_BURST_SEND_ERROR_STOP       0x00000004
#define I2C_MASTER_CMD_BURST_RECEIVE_START         0x0000000b
#define I2C_MASTER_CMD_BURST_RECEIVE_CONT          0x00000009
#define I2C_MASTER_CMD_BURST_RECEIVE_FINISH        0x00000005
#define I2C_MASTER_CMD_BURST_RECEIVE_ERROR_STOP    0x00000004

//*****************************************************************************
// I2C Master error status.
//*****************************************************************************
#define I2C_MASTER_ERR_NONE                        0
#define I2C_MASTER_ERR_ADDR_ACK                    0x00000004
#define I2C_MASTER_ERR_DATA_ACK                    0x00000008
#define I2C_MASTER_ERR_ARB_LOST                    0x00000010

//*****************************************************************************
// I2C Slave action requests
//*****************************************************************************
#define I2C_SLAVE_ACT_NONE                         0
#define I2C_SLAVE_ACT_RREQ                         0x00000001   // Master has
                                                                // sent data
#define I2C_SLAVE_ACT_TREQ                         0x00000002   // Master has
                                                                // requested
                                                                // data
#define I2C_SLAVE_ACT_RREQ_FBR                     0x00000005   // Master has
                                                                // sent first
                                                                // byte

//*****************************************************************************
// Miscellaneous I2C driver definitions.
//*****************************************************************************
#define I2C_MASTER_MAX_RETRIES                     1000         // Number of
                                                                // retries


//*****************************************************************************
// I2C Slave interrupts.
//*****************************************************************************
#define I2C_SLAVE_INT_STOP                         0x00000004   // Stop
                                                                // Condition
                                                                // Interrupt.
#define I2C_SLAVE_INT_START                        0x00000002   // Start
                                                                // Condition
                                                                // Interrupt.
#define I2C_SLAVE_INT_DATA                         0x00000001   // Data
                                                                // Interrupt.


//*****************************************************************************
// Prototypes for the APIs.
//*****************************************************************************
extern void I2CIntRegister(unsigned long ulBase, void(fnHandler) (void));
extern void I2CIntUnregister(unsigned long ulBase);
extern tBoolean I2CMasterBusBusy(unsigned long ulBase);
extern tBoolean I2CMasterBusy(unsigned long ulBase);
extern void I2CMasterControl(unsigned long ulBase, unsigned long ulCmd);
extern unsigned long I2CMasterDataGet(unsigned long ulBase);
extern void I2CMasterDataPut(unsigned long ulBase, unsigned char ucData);
extern void I2CMasterDisable(unsigned long ulBase);
extern void I2CMasterEnable(unsigned long ulBase);
extern unsigned long I2CMasterErr(unsigned long ulBase);
extern void I2CMasterInitExpClk(unsigned long ulBase, unsigned long ulI2CClk,
                                tBoolean bFast);
extern void I2CMasterIntClear(unsigned long ulBase);
extern void I2CMasterIntDisable(unsigned long ulBase);
extern void I2CMasterIntEnable(unsigned long ulBase);
extern tBoolean I2CMasterIntStatus(unsigned long ulBase, tBoolean bMasked);
extern void I2CMasterSlaveAddrSet(unsigned long ulBase,
                                  unsigned char ucSlaveAddr,
                                  tBoolean      bReceive);
extern unsigned long I2CSlaveDataGet(unsigned long ulBase);
extern void I2CSlaveDataPut(unsigned long ulBase, unsigned char ucData);
extern void I2CSlaveDisable(unsigned long ulBase);
extern void I2CSlaveEnable(unsigned long ulBase);
extern void I2CSlaveInit(unsigned long ulBase, unsigned char ucSlaveAddr);
extern void I2CSlaveIntClear(unsigned long ulBase);
extern void I2CSlaveIntDisable(unsigned long ulBase);
extern void I2CSlaveIntEnable(unsigned long ulBase);
extern void I2CSlaveIntClearEx(unsigned long ulBase, unsigned long ulIntFlags);
extern void I2CSlaveIntDisableEx(unsigned long ulBase,
                                 unsigned long ulIntFlags);
extern void I2CSlaveIntEnableEx(unsigned long ulBase, unsigned long ulIntFlags);
extern tBoolean I2CSlaveIntStatus(unsigned long ulBase, tBoolean bMasked);
extern unsigned long I2CSlaveIntStatusEx(unsigned long ulBase,
                                         tBoolean      bMasked);
extern unsigned long I2CSlaveStatus(unsigned long ulBase);

//*****************************************************************************
// Mark the end of the C bindings section for C++ compilers.
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // __I2C_H__



