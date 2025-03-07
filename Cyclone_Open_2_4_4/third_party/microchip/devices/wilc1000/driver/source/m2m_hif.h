/**
 *
 * \file
 *
 * \brief This module contains WILC M2M host interface APIs implementation.
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
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */

#ifndef _M2M_HIF_
#define _M2M_HIF_

/*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
INCLUDES
*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*/

#include "common/include/nm_common.h"
/*!< Include depends on UNO Board is used or not*/
#ifdef ENABLE_UNO_BOARD
#include "m2m_uno_hif.h"
#endif

#if !(defined CONF_WILC_USE_1000_REV_B || defined CONF_WILC_USE_3000_REV_A)
#error "Please define either CONF_WILC_USE_1000_REV_B or CONF_WILC_USE_3000_REV_A before compiling the host driver"
#endif

/*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
MACROS
*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*/

#define M2M_HIF_MAX_PACKET_SIZE      (1600 - 4)
/*!< Maximum size of the buffer could be transferred between Host and Firmware.
*/

#define M2M_HIF_HDR_OFFSET (sizeof(tstrHifHdr) + 4)

/**
*	@struct		tstrHifHdr
*	@brief		Structure to hold HIF header
*/
typedef struct
{
    uint8   u8Gid;		/*!< Group ID */
    uint8   u8Opcode;	/*!< OP code */
    uint16  u16Length;	/*!< Payload length */
}tstrHifHdr;

/**
*	@struct		tstrHifinitParam
*	@brief		Structure to hold HIF Init Param
*/
typedef struct
{
    uint8   * pu8RcvBuff;	/*!< Receive Buffer */
    uint32   u32RcvBuffSize;/*!< Receive Buffer Size */
}tstrHifinitParam;

#ifdef __cplusplus
     extern "C" {
#endif

/*!
@typedef typedef void (*tpfHifCallBack)(uint8 u8OpCode, uint16 u16DataSize, uint32 u32Addr);
@brief	used to point to Wi-Fi call back function depend on Arduino project or other projects.
@param [in]	u8OpCode
				HIF Opcode type.
@param [in]	u16DataSize
				HIF data length.
@param [in]	pu8Buff
				HIF Data Buffer.
@param [in]	grp
				HIF group type.
*/
typedef void (*tpfHifCallBack)(uint8 u8OpCode, uint16 u16DataSize, uint8* pu8Buff);
/**
*   @fn			NMI_API sint8 hif_init(void * arg);
*   @brief
				To initialize HIF layer.
*   @param [in]	pstrInitParam
*				Pointer to the init parameters.
*   @return
				The function shall return ZERO for successful operation and a negative value otherwise.
*/
NMI_API sint8 hif_init(tstrHifinitParam * pstrInitParam);
/**
*	@fn			NMI_API sint8 hif_deinit(void * arg);
*	@brief
				To Deinitialize HIF layer.
*   @param [in]	arg
*				Pointer to the arguments.
*    @return
				The function shall return ZERO for successful operation and a negative value otherwise.
*/
NMI_API sint8 hif_deinit(void * arg);
/**
*	@fn		NMI_API sint8 hif_send(uint8 u8Gid,uint8 u8Opcode,uint8 *pu8CtrlBuf,uint16 u16CtrlBufSize,
					   uint8 *pu8DataBuf,uint16 u16DataSize, uint16 u16DataOffset)
*	@brief	Send packet using host interface.

*	@param [in]	u8Gid
*				Group ID.
*	@param [in]	u8Opcode
*				Operation ID.
*	@param [in]	pu8CtrlBuf
*				Pointer to the Control buffer.
*	@param [in]	u16CtrlBufSize
				Control buffer size.
*	@param [in]	u16DataOffset
				Packet Data offset.
*	@param [in]	pu8DataBuf
*				Packet buffer Allocated by the caller.
*	@param [in]	u16DataSize
				Packet buffer size (including the HIF header).
*    @return	The function shall return ZERO for successful operation and a negative value otherwise.
*/
NMI_API sint8 hif_send(uint8 u8Gid,uint8 u8Opcode,uint8 *pu8CtrlBuf,uint16 u16CtrlBufSize,
					   uint8 *pu8DataBuf,uint16 u16DataSize, uint16 u16DataOffset);

 /**
 *	@fn sint8 hif_send_optimized(uint8 u8Gid,uint8 u8Opcode,uint8 *buffer,uint16 u16CtrlBufSize,
 *  uint16 u16DataSize, uint16 u16DataOffset)
 *	@brief	Send packet using host interface using one SDIO transaction.
 *	This API expects a big enough buffer with offsetted data and control fields so that
 *	the buffer is sent in one SDIO operation without copying.
 *
 *	@param [in]	u8Gid
 *				Group ID.
 *	@param [in]	u8Opcode
 *				Operation ID.
 *	@param [in]	buffer
 *				Pointer to the buffer.
 *	@param [in]	u16CtrlBufSize
 *              Control field size.
 *	@param [in]	u16DataOffset
 *              Data field offset.
 *	@param [in]	u16DataSize
 *              Data field length.
 *  @return		The function shall return ZERO for successful operation and a negative value otherwise.
 */

sint8 hif_send_optimized(uint8 u8Gid, uint8 u8Opcode, uint8* buffer, uint16 u16DataSize);

/*
*	@fn		hif_receive
*	@brief	Host interface interrupt serviece routine
*	@param [in]	u32Addr
*				Receive start address
*	@param [out] pu8Buf
*				Pointer to receive buffer. Allocated by the caller
*	@param [in]	 u16Sz
*				Receive buffer size
*	@param [in]	isDone
*				If you don't need any more packets send True otherwise send false
*   @return
				The function shall return ZERO for successful operation and a negative value otherwise.
*/

NMI_API sint8 hif_receive(uint32 u32Addr, uint8 *pu8Buf, uint16 u16Sz, uint8 isDone);
/**
*	@fn			hif_register_cb
*	@brief
				To set Callback function for every  Component.

*	@param [in]	u8Grp
*				Group to which the Callback function should be set.

*	@param [in]	fn
*				function to be set to the specified group.
*   @return
				The function shall return ZERO for successful operation and a negative value otherwise.
*/
NMI_API sint8 hif_register_cb(uint8 u8Grp,tpfHifCallBack fn);
/**
*	@fn		NMI_API sint8 hif_chip_sleep(void);
*	@brief
				To make the chip sleep.
*   @return
				The function shall return ZERO for successful operation and a negative value otherwise.
*/
NMI_API sint8 hif_chip_sleep(void);
/**
*	@fn		NMI_API sint8 hif_chip_sleep_sc(void);
*	@brief
				To clear the chip count only but keep the chip awake
*   @return
				The function shall return ZERO for successful operation and a negative value otherwise.
*/
NMI_API sint8 hif_chip_sleep_sc(void);
/**
*	@fn		NMI_API sint8 hif_chip_wake(void);
*	@brief
			To Wakeup the chip.
*   @return
			The function shall return ZERO for successful operation and a negative value otherwise.
*/

NMI_API sint8 hif_chip_wake(void);
/*!
@fn
			NMI_API void hif_set_sleep_mode(uint8 u8Pstype);

@brief
			Set the sleep mode of the HIF layer.

@param [in]	u8Pstype
				Sleep mode.

@return
			The function SHALL return 0 for success and a negative value otherwise.
*/

NMI_API void hif_set_sleep_mode(uint8 u8Pstype);
/*!
@fn
	NMI_API uint8 hif_get_sleep_mode(void);

@brief
	Get the sleep mode of the HIF layer.

@return
	The function SHALL return the sleep mode of the HIF layer.
*/

NMI_API uint8 hif_get_sleep_mode(void);

#ifdef CORTUS_APP
/**
*	@fn		hif_Resp_handler(uint8 *pu8Buffer, uint16 u16BufferSize)
*	@brief
				Response handler for HIF layer.

*	@param [in]	pu8Buffer
				Pointer to the buffer.

*	@param [in]	u16BufferSize
				Buffer size.

*   @return
			    The function SHALL return 0 for success and a negative value otherwise.
*/
NMI_API sint8 hif_Resp_handler(uint8 *pu8Buffer, uint16 u16BufferSize);
#endif

/**
*	@fn		hif_handle_isr(void)
*	@brief
			Handle interrupt received from NMC1500 firmware.
*   @return
			The function SHALL return 0 for success and a negative value otherwise.
*/
NMI_API sint8 hif_handle_isr(void);

/**
*	@fn		hif_set_receive_buffer(void* pvBuffer,uint16 u16BufferLen)
*	@brief
			Handle interrupt received from NMC1500 firmware.
*	@param [in]	pvBuffer
				Pointer to the buffer.
*	@param [in]	u16BufferLen
				Size of the buffer.
*   @return
			The function SHALL return 0 for success and a negative value otherwise.
*/
NMI_API sint8 hif_set_receive_buffer(void* pvBuffer,uint16 u16BufferLen);

#ifdef __cplusplus
}
#endif
#endif
