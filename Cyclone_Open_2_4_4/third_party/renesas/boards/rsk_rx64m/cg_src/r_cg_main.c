/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only 
* intended for use with Renesas products. No other uses are authorized. This 
* software is owned by Renesas Electronics Corporation and is protected under 
* all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING 
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT 
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE 
* AND NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS 
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE 
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR 
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE 
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software 
* and to discontinue the availability of this software.  By using this software, 
* you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2013, 2014 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_cg_main.c
* Version      : Code Generator for RX64M V1.00.01.01 [09 May 2014]
* Device(s)    : R5F564MLCxFC
* Tool-Chain   : CCRX
* Description  : This file implements main function.
* Creation Date: 30/06/2014
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
#include "r_cg_cgc.h"
#include "r_cg_lpc.h"
#include "r_cg_icu.h"
#include "r_cg_port.h"
#include "r_cg_cmt.h"
#include "r_cg_sci.h"
/* Start user code for include. Do not edit comment generated here */
#include "r_okaya_lcd.h"
#include "r_rsk_async.h"
#include "rskrx64mdef.h"
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */


void R_MAIN_UserInit(void);
/***********************************************************************************************************************
* Function Name: main
* Description  : This function implements main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void main(void)
{
    R_MAIN_UserInit();
    /* Start user code. Do not edit comment generated here */

    /* Initialise the debug LCD */
    R_LCD_Init();
    
    /* Displays the application name on the debug LCD */
    R_LCD_Display(0, (uint8_t *)" Asynchronous ");
    R_LCD_Display(1, (uint8_t *)" Serial ");
    R_LCD_Display(2, (uint8_t *)" Comms ");

    /* enable uart reception and transmission */
    R_ASYNC_Init();

    /* start CMT1 timer to schedule RS232 transmissions via interrupt */
    R_CMT1_Start();

    /* Turn on LED0 and turn off LED1 to indicate serial transmission
        active */
    LED0 = LED_ON;
    LED1 = LED_OFF;

    while (1U)
    {
        /* Declare and initialise a variable used for counting from 0-9 */
        static uint8_t count = 0;
    
        /* Declare serial data output buffer */
        static uint8_t serial_data_out[] = "0123456789\r\n";

        /* Check the received character */
        if (TRUE == g_tx_flag)
        {
            g_tx_flag = FALSE;

            /* Transmit the data */
            R_SCI7_AsyncTransmit(&serial_data_out[count++], 1);

            /* Reset the count after transmitting all data in the buffer */
            if ((sizeof(serial_data_out)) == count)
            {
                /* Reset the count to 0 */
                count = 0;
            }
        }
    }
    /* End user code. Do not edit comment generated here */
}
/***********************************************************************************************************************
* Function Name: R_MAIN_UserInit
* Description  : This function adds user code before implementing main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_MAIN_UserInit(void)
{
    /* Start user code. Do not edit comment generated here */
    EI();
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
