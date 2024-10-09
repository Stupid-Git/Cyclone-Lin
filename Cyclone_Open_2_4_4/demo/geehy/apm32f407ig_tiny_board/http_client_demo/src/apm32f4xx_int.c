/*!
 * @file        apm32f4xx_int.c
 *
 * @brief       Main Interrupt Service Routines
 *
 * @version     V1.0.2
 *
 * @date        2022-06-23
 *
 */

/* Includes */
#include "apm32f4xx_int.h"

/** @addtogroup Examples
  @{
  */

/** @addtogroup ETH_Ping
  @{
  */ 

/** @defgroup ETH_Ping_INT_Functions INT_Functions
  @{
*/

/*!
 * @brief     This function handles NMI exception
 *
 * @param     None
 *
 * @retval    None
 *
 */
void NMI_Handler(void)
{
}

/*!
 * @brief     This function handles Hard Fault exception
 *
 * @param     None
 *
 * @retval    None
 *
 */
void HardFault_Handler(void)
{
    /* Go to infinite loop when Hard Fault exception occurs */
    while (1)
    {
    }
}

/*!
 * @brief     This function handles Memory Manage exception
 *
 * @param     None
 *
 * @retval    None
 *
 */
void MemManage_Handler(void)
{
    /* Go to infinite loop when Memory Manage exception occurs */
    while (1)
    {
    }
}

/*!
 * @brief     This function handles Bus Fault exception
 *
 * @param     None
 *
 * @retval    None
 *
 */
void BusFault_Handler(void)
{
    /* Go to infinite loop when Bus Fault exception occurs */
    while (1)
    {
    }
}

/*!
 * @brief     This function handles Usage Fault exception
 *
 * @param     None
 *
 * @retval    None
 *
 */
void UsageFault_Handler(void)
{
    /* Go to infinite loop when Usage Fault exception occurs */
    while (1)
    {
    }
}

/*!
 * @brief     This function handles SVCall exception
 *
 * @param     None
 *
 * @retval    None
 *
 */
#if 0
void SVC_Handler(void)
{
}
#endif

/*!
 * @brief     This function handles Debug Monitor exception
 *
 * @param     None
 *
 * @retval    None
 *
 */
void DebugMon_Handler(void)
{
}

/*!
 * @brief     This function handles PendSV_Handler exception
 *
 * @param     None
 *
 * @retval    None
 *
 */
#if 0
void PendSV_Handler(void)
{
}
#endif

/*!
 * @brief     This function handles SysTick Handler
 *
 * @param     None
 *
 * @retval    None
 *
 */
#if 0
void SysTick_Handler(void)
{
}
#endif

/**@} end of group ETH_Ping_INT_Functions */
/**@} end of group ETH_Ping */
/**@} end of group Examples */
