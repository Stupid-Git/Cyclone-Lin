/**************************************************************************//**
 * @file     hbi.c
 * @version  V3.00
 * @brief    HyperBus Interface (HBI) driver source file
 *
 * @copyright SPDX-License-Identifier: Apache-2.0
 * @copyright Copyright (C) 2020 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/
#include "NuMicro.h"


/** @addtogroup Standard_Driver Standard Driver
  @{
*/

/** @addtogroup HBI_Driver HBI Driver
  @{
*/

#define WAIT_WHILE_RETURN(x, timeout, ret)   while(x){if((timeout)-- <= 0) return (ret);}
#define WAIT_WHILE_BREAK(x, timeout, err)   while(x){if((timeout)-- <= 0){g_HBI_i32ErrCode = (err); break;}}

int32_t g_HBI_i32ErrCode = 0;       /*!< HBI global error code */

/** @addtogroup HBI_EXPORTED_FUNCTIONS HBI Exported Functions
  @{
*/


/**
  * @brief      Reset HBI Device
  * @return     None
  * @note       This function sets g_HBI_i32ErrCode to HBI_ERR_TIMEOUT if waiting Hyper RAM time-out.
  */
void HBI_Reset(void)
{
    int32_t i32TimeOutCnt = HBI_TIMEOUT;

    HBI->CMD = HBI_CMD_RESET_HRAM;
    WAIT_WHILE_BREAK(HBI->CMD != HBI_CMD_HRAM_IDLE, i32TimeOutCnt, HBI_ERR_TIMEOUT);
}

/**
  * @brief      Exit from Hybrid sleep and deep Power down function
  * @return     None
  * @note       This function sets g_HBI_i32ErrCode to HBI_ERR_TIMEOUT if waiting Hyper RAM time-out.
  */
void HBI_ExitHSAndDPD(void)
{
    int32_t i32TimeOutCnt = HBI_TIMEOUT;

    HBI->CMD = HBI_CMD_EXIT_HS_PD;
    WAIT_WHILE_BREAK(HBI->CMD != HBI_CMD_HRAM_IDLE, i32TimeOutCnt, HBI_ERR_TIMEOUT);
}

/**
  * @brief      Read HyperRAM register space
  * @param[in]  u32Addr  Address of HyperRAM register space
  *                 - \ref HYPERRAM_ID_REG0       : 0x0000_0000 = Identification Register 0
  *                 - \ref HYPERRAM_ID_REG1       : 0x0000_0002 = Identification Register 1
  *                 - \ref HYPERRAM_CONFIG_REG0   : 0x0000_1000 = Configuration Register 0
  *                 - \ref HYPERRAM_CONFIG_REG1   : 0x0000_1002 = Configuration Register 1
  * @return   The data of HyperRAM register.
  * @return   -1  An illeagal register space
  * @return   -2  Wait Hyper RAM time-out
  */
int32_t HBI_ReadHyperRAMReg(uint32_t u32Addr)
{
    int32_t i32TimeOutCnt = HBI_TIMEOUT;

    if( (u32Addr == HYPERRAM_ID_REG0) || (u32Addr == HYPERRAM_ID_REG1) || (u32Addr == HYPERRAM_CONFIG_REG0) || (u32Addr == HYPERRAM_CONFIG_REG1) )
    {
        HBI->ADR = u32Addr;
        HBI->CMD = HBI_CMD_READ_HRAM_REGISTER;
        WAIT_WHILE_RETURN(HBI->CMD != HBI_CMD_HRAM_IDLE, i32TimeOutCnt, HBI_ERR_TIMEOUT);
        return *((uint16_t *)&HBI->RDATA);
    }
    else
    {
        return -1;
    }
}

/**
  * @brief      Write HyperRAM register space
  * @param[in]  u32Addr  Address of HyperRAM register space
  *                 - \ref HYPERRAM_ID_REG0       : 0x0000_0000 = Identification Register 0
  *                 - \ref HYPERRAM_ID_REG1       : 0x0000_0002 = Identification Register 1
  *                 - \ref HYPERRAM_CONFIG_REG0   : 0x0000_1000 = Configuration Register 0
  *                 - \ref HYPERRAM_CONFIG_REG1   : 0x0000_1002 = Configuration Register 1
  * @param[in]
  * @return   0   success.
  * @return   -1  An illeagal register space
  * @return   -2  Wait Hyper RAM time-out
  */
int32_t HBI_WriteHyperRAMReg(uint32_t u32Addr, uint32_t u32Value)
{
    int32_t i32TimeOutCnt = HBI_TIMEOUT;

    if( (u32Addr == HYPERRAM_ID_REG0) || (u32Addr == HYPERRAM_ID_REG1) || (u32Addr == HYPERRAM_CONFIG_REG0) || (u32Addr == HYPERRAM_CONFIG_REG1) )
    {
        HBI->ADR = u32Addr;
        HBI->WDATA = u32Value;
        HBI->CMD = HBI_CMD_WRITE_HRAM_REGISTER;
        WAIT_WHILE_RETURN(HBI->CMD != HBI_CMD_HRAM_IDLE, i32TimeOutCnt, HBI_ERR_TIMEOUT);
        return 0;
    }
    else
    {
        return -1;
    }
}

/**
  * @brief      Read 2 Bytes from HyperRAM space
  * @param[in]  u32Addr  Address of HyperRAM space
  * @return     The 16 bit data of HyperRAM space.
  * @note       This function sets g_HBI_i32ErrCode to HBI_ERR_TIMEOUT if waiting Hyper RAM time-out.
  */
uint32_t HBI_Read2Byte(uint32_t u32Addr)
{
    int32_t i32TimeOutCnt = HBI_TIMEOUT;

    if(u32Addr & 0x1)
    {
        g_HBI_i32ErrCode = HBI_ERR_ALIGN;
    }

    HBI->ADR = u32Addr;
    HBI->CMD = HBI_CMD_READ_HRAM_2_BYTE;
    WAIT_WHILE_BREAK(HBI->CMD != HBI_CMD_HRAM_IDLE, i32TimeOutCnt, HBI_ERR_TIMEOUT);
    return *((uint16_t *)&HBI->RDATA);
}

/**
  * @brief      Read 4 bytes from HyperRAM space
  * @param[in]  u32Addr  Address of HyperRAM space
  * @return     The 32bit data of HyperRAM space.
  */
uint32_t HBI_Read4Byte(uint32_t u32Addr)
{
    int32_t i32TimeOutCnt = HBI_TIMEOUT;

    if(u32Addr & 0x3)
    {
        g_HBI_i32ErrCode = HBI_ERR_ALIGN;
    }

    HBI->ADR = u32Addr;
    HBI->CMD = HBI_CMD_READ_HRAM_4_BYTE;
    WAIT_WHILE_BREAK(HBI->CMD != HBI_CMD_HRAM_IDLE, i32TimeOutCnt, HBI_ERR_TIMEOUT);
    return HBI->RDATA;
}

/**
  * @brief      Write 1 byte to HyperRAM space
  * @param[in]  u32Addr  Address of HyperRAM space
  * @param[in]  u8Data   8 bits data to be written to HyperRAM space
  * @return     None.
  * @note       This function sets g_HBI_i32ErrCode to HBI_ERR_TIMEOUT if waiting Hyper RAM time-out.
  */
void HBI_Write1Byte(uint32_t u32Addr, uint8_t u8Data)
{
    int32_t i32TimeOutCnt = HBI_TIMEOUT;

    HBI->ADR = u32Addr;
    HBI->WDATA = u8Data;
    HBI->CMD = HBI_CMD_WRITE_HRAM_1_BYTE;
    WAIT_WHILE_BREAK(HBI->CMD != HBI_CMD_HRAM_IDLE, i32TimeOutCnt, HBI_ERR_TIMEOUT);
}

/**
  * @brief      Write 2 bytes to HyperRAM space
  * @param[in]  u32Addr  Address of HyperRAM space
  * @param[in]  u16Data  16 bits data to be written to HyperRAM space
  * @return     None.
  * @note       This function sets g_HBI_i32ErrCode to HBI_ERR_TIMEOUT if waiting Hyper RAM time-out.
  */
void HBI_Write2Byte(uint32_t u32Addr, uint16_t u16Data)
{
    int32_t i32TimeOutCnt = HBI_TIMEOUT;

    if(u32Addr & 0x1)
    {
        g_HBI_i32ErrCode = HBI_ERR_ALIGN;
    }

    HBI->ADR = u32Addr;
    HBI->WDATA = u16Data;
    HBI->CMD = HBI_CMD_WRITE_HRAM_2_BYTE;
    WAIT_WHILE_BREAK(HBI->CMD != HBI_CMD_HRAM_IDLE, i32TimeOutCnt, HBI_ERR_TIMEOUT);
}

/**
  * @brief      Write 3 bytes to HyperRAM space
  * @param[in]  u32Addr  Address of HyperRAM space
  * @param[in]  u32Data  24 bits data to be written to HyperRAM space
  * @return     None.
  * @note       This function sets g_HBI_i32ErrCode to HBI_ERR_TIMEOUT if waiting Hyper RAM time-out.
  */
void HBI_Write3Byte(uint32_t u32Addr, uint32_t u32Data)
{
    int32_t i32TimeOutCnt = HBI_TIMEOUT;

    HBI->ADR = u32Addr;
    HBI->WDATA = u32Data;
    HBI->CMD = HBI_CMD_WRITE_HRAM_3_BYTE;
    WAIT_WHILE_BREAK(HBI->CMD != HBI_CMD_HRAM_IDLE, i32TimeOutCnt, HBI_ERR_TIMEOUT);
}

/**
  * @brief      Write 4 byte to HyperRAM space
  * @param[in]  u32Addr  Address of HyperRAM space
  * @param[in]  u32Data  32 bits data to be written to HyperRAM space
  * @return     None.
  * @note       This function sets g_HBI_i32ErrCode to HBI_ERR_TIMEOUT if waiting Hyper RAM time-out.
  */
void HBI_Write4Byte(uint32_t u32Addr, uint32_t u32Data)
{
    int32_t i32TimeOutCnt = HBI_TIMEOUT;
    if(u32Addr & 0x3)
    {
        g_HBI_i32ErrCode = HBI_ERR_ALIGN;
    }

    HBI->ADR = u32Addr;
    HBI->WDATA = u32Data;
    HBI->CMD = HBI_CMD_WRITE_HRAM_4_BYTE;
    WAIT_WHILE_BREAK(HBI->CMD != HBI_CMD_HRAM_IDLE, i32TimeOutCnt, HBI_ERR_TIMEOUT);
}


/*@}*/ /* end of group HBI_EXPORTED_FUNCTIONS */

/*@}*/ /* end of group HBI_Driver */

/*@}*/ /* end of group Standard_Driver */
