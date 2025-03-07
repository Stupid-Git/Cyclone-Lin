/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) . All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : Pin.c
* Version      : 1.0.2
* Device(s)    : R5F565NEDxFC
* Description  : This file implements SMC pin code generation.
* Creation Date: 2018-02-22
***********************************************************************************************************************/

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Pins_Create
* Description  : This function initializes Smart Configurator pins
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Pins_Create(void)
{
    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_MPC);

    /* Set RXD8 pin */
    MPC.PJ1PFS.BYTE = 0x0AU;
    PORTJ.PMR.BYTE |= 0x02U;

    /* Set SCK6 pin */
    MPC.P02PFS.BYTE = 0x0AU;
    PORT0.PMR.BYTE |= 0x04U;

    /* Set SMOSI6 pin */
    MPC.P00PFS.BYTE = 0x0AU;
    PORT0.PMR.BYTE |= 0x01U;

    /* Set TXD8 pin */
    PORTJ.PODR.BYTE |= 0x04U;
    MPC.PJ2PFS.BYTE = 0x0AU;
    PORTJ.PMR.BYTE |= 0x04U;
    PORTJ.PDR.BYTE |= 0x04U;

    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_MPC);
}

