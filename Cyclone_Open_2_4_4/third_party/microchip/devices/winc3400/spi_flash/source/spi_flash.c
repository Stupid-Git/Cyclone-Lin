/**
 *
 * \file
 *
 * \brief SPI Flash.
 *
 * Copyright (c) 2016-2018 Microchip Technology Inc. and its subsidiaries.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Subject to your compliance with these terms, you may use Microchip
 * software and any derivatives exclusively with Microchip products.
 * It is your responsibility to comply with third party license terms applicable
 * to your use of third party software (including open source software) that
 * may accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE,
 * INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE
 * LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE
 * SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE
 * POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY
 * RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * \asf_license_stop
 *
 */

#ifdef PROFILING
#include "windows.h"
#endif
#include "spi_flash/include/spi_flash.h"
#define DUMMY_REGISTER  (0x1084)

#define TIMEOUT (-1) /*MS*/

#define FLASH_MULTI_WRITE

//#define DISABLE_UNSED_FLASH_FUNCTIONS
#ifdef FLASH_MULTI_WRITE
#define MAX_PROG_CNT 2
#else
#define MAX_PROG_CNT 1
#endif
#define MAX_RETRY 4
#define MAX_ATTEMPT_STATUS_READ     50000

#define HOST_SHARE_MEM_BASE     (0xd0000UL)
#define CORTUS_SHARE_MEM_BASE   (0x60000000UL)
#define NMI_SPI_FLASH_ADDR      (0x111c)
/***********************************************************
SPI Flash DMA
***********************************************************/
#define GET_UINT32(X,Y)         (X[0+Y] + ((uint32)X[1+Y]<<8) + ((uint32)X[2+Y]<<16) +((uint32)X[3+Y]<<24))
#define SPI_FLASH_BASE          (0x10200)
#define SPI_FLASH_MODE          (SPI_FLASH_BASE + 0x00)
#define SPI_FLASH_CMD_CNT       (SPI_FLASH_BASE + 0x04)
#define SPI_FLASH_DATA_CNT      (SPI_FLASH_BASE + 0x08)
#define SPI_FLASH_BUF1          (SPI_FLASH_BASE + 0x0c)
#define SPI_FLASH_BUF2          (SPI_FLASH_BASE + 0x10)
#define SPI_FLASH_BUF_DIR       (SPI_FLASH_BASE + 0x14)
#define SPI_FLASH_TR_DONE       (SPI_FLASH_BASE + 0x18)
#define SPI_FLASH_DMA_ADDR      (SPI_FLASH_BASE + 0x1c)
#define SPI_FLASH_MSB_CTL       (SPI_FLASH_BASE + 0x20)
#define SPI_FLASH_TX_CTL        (SPI_FLASH_BASE + 0x24)

/*********************************************/
/* STATIC FUNCTIONS                          */
/*********************************************/

/**
*   @fn         spi_flash_read_status_reg
*   @brief      Read status register
*   @param[OUT] val
                    value of status reg
*   @return     Status of execution
*   @note       Compatible with MX25L6465E
*/
static sint8 spi_flash_read_status_reg(uint8 *val)
{
    sint8 ret = M2M_SUCCESS;
    uint8 cmd[1];
    uint32 reg;

    cmd[0] = 0x05;

    ret += nm_write_reg(SPI_FLASH_DATA_CNT, 4);
    ret += nm_write_reg(SPI_FLASH_BUF1, cmd[0]);
    ret += nm_write_reg(SPI_FLASH_BUF_DIR, 0x01);
    ret += nm_write_reg(SPI_FLASH_DMA_ADDR, DUMMY_REGISTER);
    ret += nm_write_reg(SPI_FLASH_CMD_CNT, 1 | (1<<7));
    do
    {
        ret += nm_read_reg_with_ret(SPI_FLASH_TR_DONE, (uint32 *)&reg);
        if(M2M_SUCCESS != ret) break;
    }
    while(reg != 1);

    reg = (M2M_SUCCESS == ret)?(nm_read_reg(DUMMY_REGISTER)):(0);
    *val = reg & 0xff;
    return ret;
}

#ifdef DISABLE_UNSED_FLASH_FUNCTIONS
/**
*   @fn         spi_flash_read_security_reg
*   @brief      Read security register
*   @return     Security register value
*   @note       Compatible with MX25L6465E
*/
static uint8 spi_flash_read_security_reg(void)
{
    uint8   cmd[1];
    uint32  reg;
    sint8   ret = M2M_SUCCESS;

    cmd[0] = 0x2b;

    ret += nm_write_reg(SPI_FLASH_DATA_CNT, 1);
    ret += nm_write_reg(SPI_FLASH_BUF1, cmd[0]);
    ret += nm_write_reg(SPI_FLASH_BUF_DIR, 0x01);
    ret += nm_write_reg(SPI_FLASH_DMA_ADDR, DUMMY_REGISTER);
    ret += nm_write_reg(SPI_FLASH_CMD_CNT, 1 | (1<<7));
    do
    {
        ret += nm_read_reg_with_ret(SPI_FLASH_TR_DONE, (uint32 *)&reg);
        if(M2M_SUCCESS != ret) break;
    }
    while(reg != 1);
    reg = (M2M_SUCCESS == ret)?(nm_read_reg(DUMMY_REGISTER)):(0);

    return (sint8)reg & 0xff;
}

/**
*   @fn         spi_flash_gang_unblock
*   @brief      Unblock all flash area
*   @note       Compatible with MX25L6465E
*/
static sint8 spi_flash_gang_unblock(void)
{
    uint8   cmd[1];
    uint32  val = 0;
    sint8   ret = M2M_SUCCESS;

    cmd[0] = 0x98;

    ret += nm_write_reg(SPI_FLASH_DATA_CNT, 0);
    ret += nm_write_reg(SPI_FLASH_BUF1, cmd[0]);
    ret += nm_write_reg(SPI_FLASH_BUF_DIR, 0x01);
    ret += nm_write_reg(SPI_FLASH_DMA_ADDR, 0);
    ret += nm_write_reg(SPI_FLASH_CMD_CNT, 1 | (1<<7));
    do
    {
        ret += nm_read_reg_with_ret(SPI_FLASH_TR_DONE, (uint32 *)&val);
        if(M2M_SUCCESS != ret) break;
    }
    while(val != 1);

    return ret;
}

/**
*   @fn         spi_flash_clear_security_flags
*   @brief      Clear all security flags
*   @note       Compatible with MX25L6465E
*/
static sint8 spi_flash_clear_security_flags(void)
{
    uint8 cmd[1];
    uint32  val = 0;
    sint8   ret = M2M_SUCCESS;

    cmd[0] = 0x30;

    ret += nm_write_reg(SPI_FLASH_DATA_CNT, 0);
    ret += nm_write_reg(SPI_FLASH_BUF1, cmd[0]);
    ret += nm_write_reg(SPI_FLASH_BUF_DIR, 0x01);
    ret += nm_write_reg(SPI_FLASH_DMA_ADDR, 0);
    ret += nm_write_reg(SPI_FLASH_CMD_CNT, 1 | (1<<7));
    do
    {
        ret += nm_read_reg_with_ret(SPI_FLASH_TR_DONE, (uint32 *)&val);
        if(M2M_SUCCESS != ret) break;
    }
    while(val != 1);

    return ret;
}
#endif

/**
*   @fn         spi_flash_load_to_cortus_mem
*   @brief      Load data from SPI flash into cortus memory
*   @param[IN]  u32MemAdr
*                   Cortus load address. It must be set to its AHB access address
*   @param[IN]  u32FlashAdr
*                   Address to read from at the SPI flash
*   @param[IN]  u32Sz
*                   Data size
*   @return     Status of execution
*   @note       Compatible with MX25L6465E and should be working with other types
*/
static sint8 spi_flash_load_to_cortus_mem(uint32 u32MemAdr, uint32 u32FlashAdr, uint32 u32Sz)
{
    uint8 cmd[5];
    uint32  val = 0;
    sint8   ret = M2M_SUCCESS;

    cmd[0] = 0x0b;
    cmd[1] = (uint8)(u32FlashAdr >> 16);
    cmd[2] = (uint8)(u32FlashAdr >> 8);
    cmd[3] = (uint8)(u32FlashAdr);
    cmd[4] = 0xA5;

    ret += nm_write_reg(SPI_FLASH_DATA_CNT, u32Sz);
    ret += nm_write_reg(SPI_FLASH_BUF1, cmd[0]|(cmd[1]<<8)|(cmd[2]<<16)|(cmd[3]<<24));
    ret += nm_write_reg(SPI_FLASH_BUF2, cmd[4]);
    ret += nm_write_reg(SPI_FLASH_BUF_DIR, 0x1f);
    ret += nm_write_reg(SPI_FLASH_DMA_ADDR, u32MemAdr);
    ret += nm_write_reg(SPI_FLASH_CMD_CNT, 5 | (1<<7));
    do
    {
        ret += nm_read_reg_with_ret(SPI_FLASH_TR_DONE, (uint32 *)&val);
        if(M2M_SUCCESS != ret) break;
    }
    while(val != 1);

    return ret;
}

/**
*   @fn         spi_flash_sector_erase
*   @brief      Erase sector (4KB)
*   @param[IN]  u32FlashAdr
*                   Any memory address within the sector
*   @return     Status of execution
*   @note       Compatible with MX25L6465E and should be working with other types
*/
static sint8 spi_flash_sector_erase(uint32 u32FlashAdr)
{
    uint8 cmd[4];
    uint32  val = 0;
    sint8   ret = M2M_SUCCESS;

    cmd[0] = 0x20;
    cmd[1] = (uint8)(u32FlashAdr >> 16);
    cmd[2] = (uint8)(u32FlashAdr >> 8);
    cmd[3] = (uint8)(u32FlashAdr);

    ret += nm_write_reg(SPI_FLASH_DATA_CNT, 0);
    ret += nm_write_reg(SPI_FLASH_BUF1, cmd[0]|(cmd[1]<<8)|(cmd[2]<<16)|(cmd[3]<<24));
    ret += nm_write_reg(SPI_FLASH_BUF_DIR, 0x0f);
    ret += nm_write_reg(SPI_FLASH_DMA_ADDR, 0);
    ret += nm_write_reg(SPI_FLASH_CMD_CNT, 4 | (1<<7));
    do
    {
        ret += nm_read_reg_with_ret(SPI_FLASH_TR_DONE, (uint32 *)&val);
        if(M2M_SUCCESS != ret) break;
    }
    while(val != 1);

    return ret;
}

/**
*   @fn         spi_flash_write_enable
*   @brief      Send write enable command to SPI flash
*   @return     Status of execution
*   @note       Compatible with MX25L6465E and should be working with other types
*/
static sint8 spi_flash_write_enable(void)
{
    uint8 cmd[1];
    uint32  val = 0;
    sint8   ret = M2M_SUCCESS;

    cmd[0] = 0x06;

    ret += nm_write_reg(SPI_FLASH_DATA_CNT, 0);
    ret += nm_write_reg(SPI_FLASH_BUF1, cmd[0]);
    ret += nm_write_reg(SPI_FLASH_BUF_DIR, 0x01);
    ret += nm_write_reg(SPI_FLASH_DMA_ADDR, 0);
    ret += nm_write_reg(SPI_FLASH_CMD_CNT, 1 | (1<<7));
    do
    {
        ret += nm_read_reg_with_ret(SPI_FLASH_TR_DONE, (uint32 *)&val);
        if(M2M_SUCCESS != ret) break;
    }
    while(val != 1);

    return ret;
}

/**
*   @fn         spi_flash_write_disable
*   @brief      Send write disable command to SPI flash
*   @note       Compatible with MX25L6465E and should be working with other types
*/
static sint8 spi_flash_write_disable(void)
{
    uint8 cmd[1];
    uint32  val = 0;
    sint8   ret = M2M_SUCCESS;
    cmd[0] = 0x04;

    ret += nm_write_reg(SPI_FLASH_DATA_CNT, 0);
    ret += nm_write_reg(SPI_FLASH_BUF1, cmd[0]);
    ret += nm_write_reg(SPI_FLASH_BUF_DIR, 0x01);
    ret += nm_write_reg(SPI_FLASH_DMA_ADDR, 0);
    ret += nm_write_reg(SPI_FLASH_CMD_CNT, 1 | (1<<7));
    do
    {
        ret += nm_read_reg_with_ret(SPI_FLASH_TR_DONE, (uint32 *)&val);
        if(M2M_SUCCESS != ret) break;
    }
    while(val != 1);

    return ret;
}

/**
*   @fn         spi_flash_page_program
*   @brief      Write data (less than page size) from cortus memory to SPI flash
*   @param[IN]  u32MemAdr
*                   Cortus data address. It must be set to its AHB access address
*   @param[IN]  u32FlashAdr
*                   Address to write to at the SPI flash
*   @param[IN]  u32Sz
*                   Data size
*   @note       Compatible with MX25L6465E and should be working with other types
*/
static sint8 spi_flash_page_program(uint32 u32MemAdr, uint32 u32FlashAdr, uint32 u32Sz)
{
    uint8 cmd[4];
    uint32  val = 0;
    sint8   ret = M2M_SUCCESS;

    cmd[0] = 0x02;
    cmd[1] = (uint8)(u32FlashAdr >> 16);
    cmd[2] = (uint8)(u32FlashAdr >> 8);
    cmd[3] = (uint8)(u32FlashAdr);

    ret += nm_write_reg(SPI_FLASH_DATA_CNT, 0);
    ret += nm_write_reg(SPI_FLASH_BUF1, cmd[0]|(cmd[1]<<8)|(cmd[2]<<16)|(cmd[3]<<24));
    ret += nm_write_reg(SPI_FLASH_BUF_DIR, 0x0f);
    ret += nm_write_reg(SPI_FLASH_DMA_ADDR, u32MemAdr);
    ret += nm_write_reg(SPI_FLASH_CMD_CNT, 4 | (1<<7) | ((u32Sz & 0xfffff) << 8));
    do
    {
        ret += nm_read_reg_with_ret(SPI_FLASH_TR_DONE, (uint32 *)&val);
        if(M2M_SUCCESS != ret) break;
    }
    while(val != 1);

    return ret;
}

/**
*   @fn         spi_flash_read_internal
*   @brief      Read from data from SPI flash
*   @param[OUT] pu8Buf
*                   Pointer to data buffer
*   @param[IN]  u32Addr
*                   Address to read from at the SPI flash
*   @param[IN]  u32Sz
*                   Data size
*   @note       Data size must be < 64KB (limitation imposed by the bus wrapper)
*/
static sint8 spi_flash_read_internal(uint8 *pu8Buf, uint32 u32Addr, uint32 u32Sz)
{
    sint8 ret = M2M_SUCCESS;
    /* read size must be < 64KB */
    ret = spi_flash_load_to_cortus_mem(HOST_SHARE_MEM_BASE, u32Addr, u32Sz);
    if(M2M_SUCCESS != ret) goto ERR;
    ret = nm_read_block(HOST_SHARE_MEM_BASE, pu8Buf, u32Sz);
ERR:
    return ret;
}

/**
*   @fn         spi_flash_pp
*   @brief      Program data of size less than a page (256 bytes) at the SPI flash
*   @param[IN]  u32Offset
*                   Address to write to at the SPI flash
*   @param[IN]  pu8Buf
*                   Pointer to data buffer
*   @param[IN]  u32Sz
*                   Data size
*   @return     Status of execution
*/
static sint8 spi_flash_pp(uint32 u32Offset, uint8 *pu8Buf, uint16 u16Sz)
{
    sint8 ret = M2M_SUCCESS;
    uint8 tmp;
    int i;
    int p;
    int x;

    /* use shared packet memory as temp mem */
    ret += nm_write_block(HOST_SHARE_MEM_BASE, pu8Buf, u16Sz);

    for(i = 0, p = 0; (i < MAX_RETRY) && (p < MAX_PROG_CNT); i++)
    {
        if((spi_flash_write_enable() == M2M_SUCCESS) &&
           (spi_flash_page_program(HOST_SHARE_MEM_BASE, u32Offset, u16Sz) == M2M_SUCCESS))
        {
            x = 0;
            while(++x < MAX_ATTEMPT_STATUS_READ)
            {
                if(spi_flash_read_status_reg(&tmp) != M2M_SUCCESS)
                {
                    break;
                }
                if(!(tmp & 0x01))
                {
                    p++;
                    break;
                }
            }
        }
    }
    ret = spi_flash_write_disable();

    if(p < MAX_PROG_CNT)
    {
        ret = M2M_ERR_FAIL;
    }

    return ret;
}

/**
*   @fn         spi_flash_rdid
*   @brief      Read SPI Flash ID
*   @return     SPI FLash ID
*/
static uint32 spi_flash_rdid(void)
{
    unsigned char cmd[1];
    uint32 reg = 0;
    uint32 cnt = 0;
    sint8   ret = M2M_SUCCESS;

    cmd[0] = 0x9f;

    ret += nm_write_reg(SPI_FLASH_DATA_CNT, 4);
    ret += nm_write_reg(SPI_FLASH_BUF1, cmd[0]);
    ret += nm_write_reg(SPI_FLASH_BUF_DIR, 0x1);
    ret += nm_write_reg(SPI_FLASH_DMA_ADDR, DUMMY_REGISTER);
    ret += nm_write_reg(SPI_FLASH_CMD_CNT, 1 | (1<<7));
    do
    {
        ret += nm_read_reg_with_ret(SPI_FLASH_TR_DONE, (uint32 *)&reg);
        if(M2M_SUCCESS != ret) break;
        if(++cnt > 500)
        {
            ret = M2M_ERR_INIT;
            break;
        }
    }
    while(reg != 1);
    reg = (M2M_SUCCESS == ret)?(nm_read_reg(DUMMY_REGISTER)):(0);
    M2M_PRINT("Flash ID %x \r\n", (unsigned int)reg);
    return reg;
}

/**
*   @fn         spi_flash_unlock
*   @brief      Unlock SPI Flash
*/
#if 0
static void spi_flash_unlock(void)
{
    uint8 tmp;
    tmp = spi_flash_read_security_reg();
    spi_flash_clear_security_flags();
    if(tmp & 0x80)
    {
        spi_flash_write_enable();
        spi_flash_gang_unblock();
    }
}
#endif

/*********************************************/
/* GLOBAL FUNCTIONS                          */
/*********************************************/

/**
*   @fn         spi_flash_read
*   @brief      Read from data from SPI flash
*   @param[OUT] pu8Buf
*                   Pointer to data buffer
*   @param[IN]  u32offset
*                   Address to read from at the SPI flash
*   @param[IN]  u32Sz
*                   Data size
*   @return     Status of execution
*   @note       Data size is limited by the SPI flash size only
*/
sint8 spi_flash_read(uint8 *pu8Buf, uint32 u32offset, uint32 u32Sz)
{
    sint8 ret = M2M_SUCCESS;
    if(u32Sz > FLASH_BLOCK_SIZE)
    {
        do
        {
            ret = spi_flash_read_internal(pu8Buf, u32offset, FLASH_BLOCK_SIZE);
            if(M2M_SUCCESS != ret) goto ERR;
            u32Sz -= FLASH_BLOCK_SIZE;
            u32offset += FLASH_BLOCK_SIZE;
            pu8Buf += FLASH_BLOCK_SIZE;
        } while(u32Sz > FLASH_BLOCK_SIZE);
    }

    ret = spi_flash_read_internal(pu8Buf, u32offset, u32Sz);

ERR:
    return ret;
}

/**
*   @fn         spi_flash_write
*   @brief      Program SPI flash
*   @param[IN]  pu8Buf
*                   Pointer to data buffer
*   @param[IN]  u32Offset
*                   Address to write to at the SPI flash
*   @param[IN]  u32Sz
*                   Data size
*   @return     Status of execution
*/
sint8 spi_flash_write(uint8 *pu8Buf, uint32 u32Offset, uint32 u32Sz)
{
#ifdef PROFILING
    uint32 t1 = 0;
    uint32 percent =0;
    uint32 tpercent =0;
#endif
    sint8 ret = M2M_SUCCESS;
    uint32 u32wsz;
    uint32 u32off;
    uint32 u32Blksz;
    u32Blksz = FLASH_PAGE_SZ;
    u32off = u32Offset % u32Blksz;
#ifdef PROFILING
    tpercent = (u32Sz/u32Blksz)+((u32Sz%u32Blksz)>0);
    t1 = nm_bsp_get_tick();
    M2M_PRINT(">Start programming...\r\n");
#endif
    if(u32Sz<=0)
    {
        M2M_ERR("Data size = %d", (int)u32Sz);
        ret = M2M_ERR_FAIL;
        goto ERR;
    }

    if(u32off) /*first part of data in the address page*/
    {
        u32wsz = u32Blksz - u32off;
        if(spi_flash_pp(u32Offset, pu8Buf, (uint16)BSP_MIN(u32Sz, u32wsz))!=M2M_SUCCESS)
        {
            ret = M2M_ERR_FAIL;
            goto ERR;
        }
        if(u32Sz < u32wsz) goto EXIT;
        pu8Buf += u32wsz;
        u32Offset += u32wsz;
        u32Sz -= u32wsz;
    }
    while(u32Sz > 0)
    {
        u32wsz = BSP_MIN(u32Sz, u32Blksz);

        /*write complete page or the remaining data*/
        if(spi_flash_pp(u32Offset, pu8Buf, (uint16)u32wsz)!=M2M_SUCCESS)
        {
            ret = M2M_ERR_FAIL;
            goto ERR;
        }
        pu8Buf += u32wsz;
        u32Offset += u32wsz;
        u32Sz -= u32wsz;
#ifdef PROFILING
        percent++;
        printf("\r>Complete Percentage = %d%%.\r", ((percent*100)/tpercent));
#endif
    }
EXIT:
#ifdef PROFILING
    M2M_PRINT("\rDone\t\t\t\t\t\t");
    M2M_PRINT("\n#Programming time = %f sec\n\r", (nm_bsp_get_tick() - t1)/1000.0);
#endif
ERR:
    return ret;
}

/**
*   @fn         spi_flash_erase
*   @brief      Erase from data from SPI flash
*   @param[IN]  u32Offset
*                   Address to write to at the SPI flash
*   @param[IN]  u32Sz
*                   Data size
*   @return     Status of execution
*   @note       Data size is limited by the SPI flash size only
*/
sint8 spi_flash_erase(uint32 u32Offset, uint32 u32Sz)
{
    uint32 i = 0;
    uint8  tmp = 0;
    int p;
    int j;
    int x;

#ifdef PROFILING
    uint32 t;
    t = nm_bsp_get_tick();
#endif
    M2M_DBG("\r\n>Start erasing...\r\n");
    for(i = u32Offset; i < (u32Sz +u32Offset); i += (16*FLASH_PAGE_SZ))
    {
        for(j = 0, p = 0; (j < MAX_RETRY) && (p < MAX_PROG_CNT); j++)
        {
            if((spi_flash_write_enable() == M2M_SUCCESS) &&
               (spi_flash_read_status_reg(&tmp) == M2M_SUCCESS) &&
               (spi_flash_sector_erase(i) == M2M_SUCCESS) &&
               (spi_flash_read_status_reg(&tmp) == M2M_SUCCESS))
            {
                x = 0;
                while(++x < MAX_ATTEMPT_STATUS_READ)
                {
                    if(spi_flash_read_status_reg(&tmp) != M2M_SUCCESS)
                    {
                        break;
                    }
                    if(!(tmp & 0x01))
                    {
                        p++;
                        break;
                    }
                }
            }
        }
        if(p != MAX_PROG_CNT)
        {
            return M2M_ERR_FAIL;
        }
    }
    M2M_DBG("Done\r\n");
#ifdef PROFILING
    M2M_PRINT("#Erase time = %f sec\r\n", (nm_bsp_get_tick()-t)/1000.0);
#endif
    return M2M_SUCCESS;
}

/**
*   @fn         spi_flash_get_size
*   @brief      Get size of SPI Flash
*   @return     Size of Flash
*/
uint32 spi_flash_get_size(void)
{
    uint32 u32FlashId = 0, u32FlashPwr = 0;
    static uint32 gu32InternalFlashSize= 0;

    if(!gu32InternalFlashSize)
    {
        u32FlashId = spi_flash_rdid();//spi_flash_probe();
        if(u32FlashId != 0xffffffff)
        {
            /*flash size is the third byte from the FLASH RDID*/
            u32FlashPwr = ((u32FlashId>>16)&0xff) - 0x11; /*2MBIT is the min*/
            /*That number power 2 to get the flash size*/
            gu32InternalFlashSize = 1<<u32FlashPwr;
            M2M_INFO("Flash Size %lu Mb\r\n", gu32InternalFlashSize);
        }
        else
        {
            M2M_ERR("Can't detect Flash size\r\n");
        }
    }

    return gu32InternalFlashSize;
}
