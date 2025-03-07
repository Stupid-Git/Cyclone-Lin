/**
 *
 * \file
 *
 * \brief This module contains WINC3400 UART protocol bus APIs implementation.
 *
 * Copyright (c) 2017-2018 Microchip Technology Inc. and its subsidiaries.
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

#include "common/include/nm_common.h"

#ifdef CONF_WINC_USE_UART

#include "driver/source/nmuart.h"
#include "bus_wrapper/include/nm_bus_wrapper.h"

#define HDR_SZ  12

static uint8 get_cs(uint8* b, uint8 sz){
    int i;
    uint8 cs = 0;
    for(i = 0; i < sz; i++)
        cs ^= b[i];
    return cs;
}

/**
 *  @fn         nm_uart_sync_cmd
 *  @brief      Check COM Port
 *  @return     @ref M2M_SUCCESS in case of success and @ref M2M_ERR_BUS_FAIL in case of failure
 */
sint8 nm_uart_sync_cmd(void)
{
    tstrNmUartDefault strUart;
    sint8 s8Ret = M2M_ERR_BUS_FAIL;
    uint8 b [HDR_SZ+1];
    uint8 onchip = 0;
    int escape = 3;

    // send query char up to 3 times
    while(escape-- && (s8Ret != M2M_SUCCESS))
    {
        b[0] = 0x12;
        strUart.pu8Buf = b;
        strUart.u16Sz = 1;

        // then read back all chars in the buffer if any, is last char what we are looking for
        s8Ret = nm_bus_ioctl(NM_BUS_IOCTL_W, &strUart);
        if(M2M_SUCCESS == s8Ret)
        {
            uint8 lastchar;

            // drain buffer
            while(M2M_SUCCESS == s8Ret)
            {
                lastchar = b[0];
                s8Ret = nm_bus_ioctl(NM_BUS_IOCTL_R, &strUart);
            }

            switch(lastchar)
            {
                case 0x5a:
                    onchip = 1;
                    M2M_INFO("Built-in WINCxx00 UART Found\r\n");
                    s8Ret = M2M_SUCCESS;
                    break;
                case  0x5b:
                    onchip = 0;
                    M2M_INFO("WINCxx00 Serial Bridge Found\r\n");
                    s8Ret = M2M_SUCCESS;
                    break;
                case 0x5c:
                    onchip = 2;
                    M2M_INFO("WINCxx00 Serial Bridge + AT CMD app Found\r\n");
                    s8Ret = M2M_SUCCESS;
                    break;
                case 0x12:
                    M2M_INFO("failed to read Serial Bridge ID response\r\n");
                    s8Ret = M2M_ERR_BUS_FAIL;
                    break;
                default:
                    M2M_INFO("Non Serial Bridge Found\r\n");
                    s8Ret = M2M_ERR_BUS_FAIL;
                    break;
            }
        }
        else
        {
            M2M_ERR("failed to send Serial Bridge ID Query\r\n");
        }
    }

    if(s8Ret == M2M_SUCCESS)
        s8Ret = (sint8)onchip;

    return s8Ret;
}

/**
 *  @fn         nm_uart_reboot_cmd
 *  @brief      Sends a command to the MCU to force reboot
 *  @return     @ref M2M_SUCCESS in case of success and @ref M2M_ERR_BUS_FAIL in case of failure
 */
sint8 nm_uart_reboot_cmd(void)
{
    tstrNmUartDefault strUart;
    sint8 s8Ret = M2M_SUCCESS;
    uint8 b[HDR_SZ + 1];
    uint8 rsz;
    uint8 onchip = 0;

    /*read reg*/
    b[0] = 0x13;

    rsz = 1;
    strUart.pu8Buf = b;
    strUart.u16Sz = 1;

    if(M2M_SUCCESS != nm_bus_ioctl(NM_BUS_IOCTL_W, &strUart))
    {
        M2M_ERR("failed to send reboot cmd\r\n");
        s8Ret = M2M_ERR_BUS_FAIL;
    }
    return s8Ret;
}


 sint8 nm_uart_read_reg_with_ret(uint32 u32Addr, uint32* pu32RetVal)
{
    tstrNmUartDefault strUart;
    sint8 s8Ret = M2M_SUCCESS;
    uint8 b [HDR_SZ+1];
    uint8 rsz;

    /*read reg*/
    b[0] = 0xa5;
    b[1] = 0;
    b[2] = 0;
    b[3] = 0;
    b[4] = 0;
    b[5] = (uint8)(u32Addr & 0x000000ff);
    b[6] = (uint8)((u32Addr & 0x0000ff00)>>8);
    b[7] = (uint8)((u32Addr & 0x00ff0000)>>16);
    b[8] = (uint8)((u32Addr & 0xff000000)>>24);
    b[9] = 0;
    b[10] = 0;
    b[11] = 0;
    b[12] = 0;

    b[2] = get_cs(&b[1], HDR_SZ);

    rsz = 4;
    strUart.pu8Buf = b;
    strUart.u16Sz = sizeof(b);

    if(M2M_SUCCESS == nm_bus_ioctl(NM_BUS_IOCTL_W, &strUart))
    {
        if(!nm_bus_get_chip_type())
        {
            strUart.u16Sz = 1;
            if(M2M_SUCCESS != nm_bus_ioctl(NM_BUS_IOCTL_R, &strUart))
            {
                s8Ret = M2M_ERR_BUS_FAIL;
            }
            if(b[0] == 0xAC)
            {
                M2M_DBG("Successfully sent the command\r\n");
                strUart.u16Sz = rsz;
                if(M2M_SUCCESS != nm_bus_ioctl(NM_BUS_IOCTL_R, &strUart))
                {
                    s8Ret = M2M_ERR_BUS_FAIL;
                }
            }
            else
            {
                s8Ret = M2M_ERR_BUS_FAIL;
            }
        }
        else
        {
            strUart.u16Sz = rsz;
            if(M2M_SUCCESS != nm_bus_ioctl(NM_BUS_IOCTL_R, &strUart))
            {
                s8Ret = M2M_ERR_BUS_FAIL;
            }
        }
    }
    else
    {
        M2M_ERR("failed to send cfg bytes\r\n");
        s8Ret = M2M_ERR_BUS_FAIL;
    }

    *pu32RetVal = ((uint32)b[0] << 24) | ((uint32)b[1] << 16) | ((uint32)b[2] << 8) | b[3];

    return s8Ret;
}

/**
 *  @fn         nm_uart_read_reg
 *  @brief      Read register
 *  @param[in]  u32Addr
 *                  Register address
 *  @return     Register value
 */
uint32 nm_uart_read_reg(uint32 u32Addr)
{
    uint32 val;
    nm_uart_read_reg_with_ret(u32Addr, &val);
    return val;
}

/**
 *  @fn         nm_uart_write_reg
 *  @brief      Write register
 *  @param[in]  u32Addr
 *                  Register address
 *  @param[in]  u32Val
 *                  Value to be written to the register
 *  @return     @ref M2M_SUCCESS in case of success and @ref M2M_ERR_BUS_FAIL in case of failure
 */
sint8 nm_uart_write_reg(uint32 u32Addr, uint32 u32Val)
{
    tstrNmUartDefault strUart;
    sint8 s8Ret = M2M_SUCCESS;
    uint8 b[HDR_SZ+1];

    /*write reg*/
    b[0] = 0xa5;
    b[1] = 1;
    b[2] = 0;
    b[3] = 0;
    b[4] = 0;
    b[5] = (uint8)(u32Addr & 0x000000ff);
    b[6] = (uint8)((u32Addr & 0x0000ff00)>>8);
    b[7] = (uint8)((u32Addr & 0x00ff0000)>>16);
    b[8] = (uint8)((u32Addr & 0xff000000)>>24);
    b[9] = (uint8)(u32Val & 0x000000ff);
    b[10] = (uint8)((u32Val & 0x0000ff00)>>8);
    b[11] = (uint8)((u32Val & 0x00ff0000)>>16);
    b[12] = (uint8)((u32Val & 0xff000000)>>24);

    b[2] = get_cs(&b[1], HDR_SZ);

    get_cs(&b[1], HDR_SZ);

    strUart.pu8Buf = b;
    strUart.u16Sz = sizeof(b);

    if(M2M_SUCCESS != nm_bus_ioctl(NM_BUS_IOCTL_W, &strUart))
    {
        M2M_ERR("write error\r\n");
        s8Ret = M2M_ERR_BUS_FAIL;
    }
    else
    {
        if(!nm_bus_get_chip_type())
        {
            //check for the ack from the SAMD21 for the packet reception.
            strUart.u16Sz = 1;
            if(M2M_SUCCESS != nm_bus_ioctl(NM_BUS_IOCTL_R, &strUart))
            {
                s8Ret = M2M_ERR_BUS_FAIL;
            }
            if(b[0] == 0xAC)
            {
                M2M_DBG("Successfully sent the reg write command\r\n");
            }
            else
            {
                M2M_ERR("write error\r\n");
                s8Ret = M2M_ERR_BUS_FAIL;
            }
        }
    }

    return s8Ret;
}


/**
 *  @fn         nm_uart_read_block
 *  @brief      Read block of data
 *  @param[in]  u32Addr
 *                  Start address
 *  @param[out] puBuf
 *                  Pointer to a buffer used to return the read data
 *  @param[in]  u16Sz
 *                  Number of bytes to read. The buffer size must be >= u16Sz
 *  @return     @ref M2M_SUCCESS in case of success and @ref M2M_ERR_BUS_FAIL in case of failure
 */
sint8 nm_uart_read_block(uint32 u32Addr, uint8 *pu8Buf, uint16 u16Sz)
{
    tstrNmUartDefault strUart;
    sint8 s8Ret = M2M_SUCCESS;
    uint8 au8Buf[HDR_SZ+1];

    au8Buf[0] = 0xa5;
    au8Buf[1] = 2;
    au8Buf[2] = 0;
    au8Buf[3] = (uint8)(u16Sz & 0x00ff);
    au8Buf[4] = (uint8)((u16Sz & 0xff00)>>8);
    au8Buf[5] = (uint8)(u32Addr & 0x000000ff);
    au8Buf[6] = (uint8)((u32Addr & 0x0000ff00)>>8);
    au8Buf[7] = (uint8)((u32Addr & 0x00ff0000)>>16);
    au8Buf[8] = (uint8)((u32Addr & 0xff000000)>>24);
    au8Buf[9] = 0;
    au8Buf[10] = 0;
    au8Buf[11] = 0;
    au8Buf[12] = 0;

    au8Buf[2] = get_cs(&au8Buf[1], HDR_SZ);

    strUart.pu8Buf = au8Buf;
    strUart.u16Sz = sizeof(au8Buf);

    if(M2M_SUCCESS != nm_bus_ioctl(NM_BUS_IOCTL_W, &strUart))
    {
        M2M_ERR("write error\r\n");
        s8Ret = M2M_ERR_BUS_FAIL;
    }
    else
    {
        if(!nm_bus_get_chip_type())
        {
            //check for the ack from the SAMD21 for the packet reception.
            strUart.u16Sz = 1;
            if(M2M_SUCCESS != nm_bus_ioctl(NM_BUS_IOCTL_R, &strUart))
            {
                s8Ret = M2M_ERR_BUS_FAIL;
            }
            if(au8Buf[0] == 0xAC)
            {
                M2M_DBG("Successfully sent the block read command\r\n");
                strUart.pu8Buf = pu8Buf;
                strUart.u16Sz = u16Sz;

                if(M2M_SUCCESS != nm_bus_ioctl(NM_BUS_IOCTL_R, &strUart))
                {
                    M2M_ERR("read error\r\n");
                    s8Ret = M2M_ERR_BUS_FAIL;
                }
            }
            else
            {
                M2M_ERR("write error (Error sending the block read command)\r\n");
                s8Ret = M2M_ERR_BUS_FAIL;
            }
        }
        else
        {
            strUart.pu8Buf = pu8Buf;
            strUart.u16Sz = u16Sz;

            if(M2M_SUCCESS != nm_bus_ioctl(NM_BUS_IOCTL_R, &strUart))
            {
                M2M_ERR("read error\r\n");
                s8Ret = M2M_ERR_BUS_FAIL;
            }
        }
    }

    return s8Ret;
}

/**
 *  @fn         nm_uart_write_block
 *  @brief      Write block of data
 *  @param[in]  u32Addr
 *                  Start address
 *  @param[in]  puBuf
 *                  Pointer to the buffer holding the data to be written
 *  @param[in]  u16Sz
 *                  Number of bytes to write. The buffer size must be >= u16Sz
 *  @return     @ref M2M_SUCCESS in case of success and @ref M2M_ERR_BUS_FAIL in case of failure
 */
sint8 nm_uart_write_block(uint32 u32Addr, uint8 *puBuf, uint16 u16Sz)
{
    tstrNmUartDefault strUart;
    sint8 s8Ret = M2M_SUCCESS;
    static uint8 au8Buf[HDR_SZ+1];

    au8Buf[0] = 0xa5;
    au8Buf[1] = 3;
    au8Buf[2] = 0;
    au8Buf[3] = (uint8)(u16Sz & 0x00ff);
    au8Buf[4] = (uint8)((u16Sz & 0xff00)>>8);
    au8Buf[5] = (uint8)(u32Addr & 0x000000ff);
    au8Buf[6] = (uint8)((u32Addr & 0x0000ff00)>>8);
    au8Buf[7] = (uint8)((u32Addr & 0x00ff0000)>>16);
    au8Buf[8] = (uint8)((u32Addr & 0xff000000)>>24);
    au8Buf[9] = 0;
    au8Buf[10] = 0;
    au8Buf[11] = 0;
    au8Buf[12] = 0;

    au8Buf[2] = get_cs(&au8Buf[1], HDR_SZ);

    strUart.pu8Buf = au8Buf;
    strUart.u16Sz = sizeof(au8Buf);

    if(M2M_SUCCESS != nm_bus_ioctl(NM_BUS_IOCTL_W, &strUart))
    {
        M2M_ERR("write error\r\n");
        s8Ret = M2M_ERR_BUS_FAIL;
    }
    else
    {
        if(!nm_bus_get_chip_type())
        {
            //check for the ack from the SAMD21 for the packet reception.
            strUart.u16Sz = 1;
            if(M2M_SUCCESS != nm_bus_ioctl(NM_BUS_IOCTL_R, &strUart))
            {
                s8Ret = M2M_ERR_BUS_FAIL;
            }
            if(au8Buf[0] == 0xAC)
            {
                M2M_DBG("Successfully sent the block Write command\r\n");
                strUart.pu8Buf = puBuf;
                strUart.u16Sz = u16Sz;

                if(M2M_SUCCESS != nm_bus_ioctl(NM_BUS_IOCTL_W, &strUart))
                {
                    M2M_ERR("write error\r\n");
                    s8Ret = M2M_ERR_BUS_FAIL;
                }
                else
                {
                    //check for the ack from the SAMD21 for the payload reception.
                    strUart.pu8Buf = au8Buf;
                    strUart.u16Sz = 1;
                    if(M2M_SUCCESS != nm_bus_ioctl(NM_BUS_IOCTL_R, &strUart))
                    {
                        s8Ret = M2M_ERR_BUS_FAIL;
                    }
                    if(au8Buf[0] == 0xAC)
                    {
                        M2M_DBG("Successfully sent the data payload\r\n");
                    }
                    else
                    {
                        M2M_ERR("write error\r\n");
                        s8Ret = M2M_ERR_BUS_FAIL;
                    }
                }
            }
            else
            {
                M2M_ERR("write error (Error sending the block write command)\r\n");
                s8Ret = M2M_ERR_BUS_FAIL;
            }
        }
        else
        {
            strUart.pu8Buf = puBuf;
            strUart.u16Sz = u16Sz;

            if(M2M_SUCCESS != nm_bus_ioctl(NM_BUS_IOCTL_W, &strUart))
            {
                M2M_ERR("write error\r\n");
                s8Ret = M2M_ERR_BUS_FAIL;
            }
        }
    }
    return s8Ret;
}

/**
 *  @fn         nm_uart_reconfigure
 *  @brief      Reconfigures the UART interface
 *  @param[in]  ptr
 *                  Pointer to a DWORD containing baudrate at this moment.
 *  @return     @ref M2M_SUCCESS in case of success and @ref M2M_ERR_BUS_FAIL in case of failure
 */
sint8 nm_uart_reconfigure(void *ptr)
{
    tstrNmUartDefault strUart;
    sint8 s8Ret = M2M_SUCCESS;
    uint8 b[HDR_SZ+1];

    if(ptr == NULL)
    {
        M2M_ERR("port not open\r\n");
        return M2M_ERR_BUS_FAIL;
    }

    /*write reg*/
    b[0] = 0xa5;
    b[1] = 5;
    b[2] = 0;
    b[3] = 0;
    b[4] = 0;
    b[5] = 0;
    b[6] = 0;
    b[7] = 0;
    b[8] = 0;
    b[9] = (uint8)((*(unsigned long *)ptr) & 0x000000ff);
    b[10] = (uint8)(((*(unsigned long *)ptr) & 0x0000ff00)>>8);
    b[11] = (uint8)(((*(unsigned long *)ptr) & 0x00ff0000)>>16);
    b[12] = (uint8)(((*(unsigned long *)ptr) & 0xff000000)>>24);

    b[2] = get_cs(&b[1], HDR_SZ);

    get_cs(&b[1], HDR_SZ);

    strUart.pu8Buf = b;
    strUart.u16Sz = sizeof(b);

    if(M2M_SUCCESS != nm_bus_ioctl(NM_BUS_IOCTL_W, &strUart))
    {
        M2M_ERR("write error\r\n");
        s8Ret = M2M_ERR_BUS_FAIL;
    }
    else
    {
        if(!nm_bus_get_chip_type())
        {
            //check for the ack from the SAMD21 for the packet reception.
            strUart.u16Sz = 1;
            if(M2M_SUCCESS != nm_bus_ioctl(NM_BUS_IOCTL_R, &strUart))
            {
                s8Ret = M2M_ERR_BUS_FAIL;
            }
            if(b[0] == 0xAC)
            {
                M2M_DBG("Successfully sent the UART reconfigure command\r\n");
            }
            else
            {
                M2M_ERR("write error\r\n");
                s8Ret = M2M_ERR_BUS_FAIL;
            }
        }
    }

    return s8Ret;
}
#endif
/* EOF */
