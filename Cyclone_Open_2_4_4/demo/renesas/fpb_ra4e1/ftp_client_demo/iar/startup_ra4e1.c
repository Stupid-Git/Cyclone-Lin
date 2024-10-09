//Dependencies
#include "bsp_api.h"

//Forward function declaration
void SystemInit(void);
void __iar_program_start(void);
int __low_level_init(void);

//Default handler
void Default_Handler(void);

//Cortex-M4 core handlers
void Reset_Handler(void);
void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void SVC_Handler(void);
void DebugMon_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);

#pragma weak NMI_Handler = Default_Handler
#pragma weak HardFault_Handler = Default_Handler
#pragma weak MemManage_Handler = Default_Handler
#pragma weak BusFault_Handler = Default_Handler
#pragma weak UsageFault_Handler = Default_Handler
#pragma weak SVC_Handler = Default_Handler
#pragma weak DebugMon_Handler = Default_Handler
#pragma weak PendSV_Handler = Default_Handler
#pragma weak SysTick_Handler = Default_Handler

//Peripherals handlers
void ICU_IRQ0_IRQHandler(void);
void ICU_IRQ1_IRQHandler(void);
void ICU_IRQ2_IRQHandler(void);
void ICU_IRQ3_IRQHandler(void);
void ICU_IRQ4_IRQHandler(void);
void ICU_IRQ5_IRQHandler(void);
void ICU_IRQ6_IRQHandler(void);
void ICU_IRQ7_IRQHandler(void);
void ICU_IRQ8_IRQHandler(void);
void ICU_IRQ9_IRQHandler(void);
void ICU_IRQ13_IRQHandler(void);
void DMAC0_INT_IRQHandler(void);
void DMAC1_INT_IRQHandler(void);
void DMAC2_INT_IRQHandler(void);
void DMAC3_INT_IRQHandler(void);
void DMAC4_INT_IRQHandler(void);
void DMAC5_INT_IRQHandler(void);
void DMAC6_INT_IRQHandler(void);
void DMAC7_INT_IRQHandler(void);
void DTC_COMPLETE_IRQHandler(void);
void DTC_END_IRQHandler(void);
void DMA_TRANSERR_IRQHandler(void);
void ICU_SNOOZE_CANCEL_IRQHandler(void);
void FCU_FIFERR_IRQHandler(void);
void FCU_FRDYI_IRQHandler(void);
void LVD_LVD1_IRQHandler(void);
void LVD_LVD2_IRQHandler(void);
void CGC_MOSC_STOP_IRQHandler(void);
void LPM_SNOOZE_REQUEST_IRQHandler(void);
void AGT0_INT_IRQHandler(void);
void AGT0_COMPARE_A_IRQHandler(void);
void AGT0_COMPARE_B_IRQHandler(void);
void AGT1_INT_IRQHandler(void);
void AGT1_COMPARE_A_IRQHandler(void);
void AGT1_COMPARE_B_IRQHandler(void);
void AGT2_INT_IRQHandler(void);
void AGT2_COMPARE_A_IRQHandler(void);
void AGT2_COMPARE_B_IRQHandler(void);
void AGT3_INT_IRQHandler(void);
void AGT3_COMPARE_A_IRQHandler(void);
void AGT3_COMPARE_B_IRQHandler(void);
void AGT5_INT_IRQHandler(void);
void AGT5_COMPARE_A_IRQHandler(void);
void AGT5_COMPARE_B_IRQHandler(void);
void IWDT_UNDERFLOW_IRQHandler(void);
void WDT_UNDERFLOW_IRQHandler(void);
void RTC_ALARM_IRQHandler(void);
void RTC_PERIOD_IRQHandler(void);
void RTC_CARRY_IRQHandler(void);
void USBFS_FIFO_0_IRQHandler(void);
void USBFS_FIFO_1_IRQHandler(void);
void USBFS_INT_IRQHandler(void);
void USBFS_RESUME_IRQHandler(void);
void IIC0_RXI_IRQHandler(void);
void IIC0_TXI_IRQHandler(void);
void IIC0_TEI_IRQHandler(void);
void IIC0_ERI_IRQHandler(void);
void IIC0_WUI_IRQHandler(void);
void CAC_FREQUENCY_ERROR_IRQHandler(void);
void CAC_MEASUREMENT_END_IRQHandler(void);
void CAC_OVERFLOW_IRQHandler(void);
void CAN0_ERROR_IRQHandler(void);
void CAN0_FIFO_RX_IRQHandler(void);
void CAN0_FIFO_TX_IRQHandler(void);
void CAN0_MAILBOX_RX_IRQHandler(void);
void CAN0_MAILBOX_TX_IRQHandler(void);
void IOPORT_EVENT_1_IRQHandler(void);
void IOPORT_EVENT_2_IRQHandler(void);
void IOPORT_EVENT_3_IRQHandler(void);
void IOPORT_EVENT_4_IRQHandler(void);
void ELC_SOFTWARE_EVENT_0_IRQHandler(void);
void ELC_SOFTWARE_EVENT_1_IRQHandler(void);
void POEG0_EVENT_IRQHandler(void);
void POEG1_EVENT_IRQHandler(void);
void POEG2_EVENT_IRQHandler(void);
void POEG3_EVENT_IRQHandler(void);
void GPT1_CAPTURE_COMPARE_A_IRQHandler(void);
void GPT1_CAPTURE_COMPARE_B_IRQHandler(void);
void GPT1_COMPARE_C_IRQHandler(void);
void GPT1_COMPARE_D_IRQHandler(void);
void GPT1_COMPARE_E_IRQHandler(void);
void GPT1_COMPARE_F_IRQHandler(void);
void GPT1_COUNTER_OVERFLOW_IRQHandler(void);
void GPT1_COUNTER_UNDERFLOW_IRQHandler(void);
void GPT1_PC_IRQHandler(void);
void GPT2_CAPTURE_COMPARE_A_IRQHandler(void);
void GPT2_CAPTURE_COMPARE_B_IRQHandler(void);
void GPT2_COMPARE_C_IRQHandler(void);
void GPT2_COMPARE_D_IRQHandler(void);
void GPT2_COMPARE_E_IRQHandler(void);
void GPT2_COMPARE_F_IRQHandler(void);
void GPT2_COUNTER_OVERFLOW_IRQHandler(void);
void GPT2_COUNTER_UNDERFLOW_IRQHandler(void);
void GPT4_CAPTURE_COMPARE_A_IRQHandler(void);
void GPT4_CAPTURE_COMPARE_B_IRQHandler(void);
void GPT4_COMPARE_C_IRQHandler(void);
void GPT4_COMPARE_D_IRQHandler(void);
void GPT4_COMPARE_E_IRQHandler(void);
void GPT4_COMPARE_F_IRQHandler(void);
void GPT4_COUNTER_OVERFLOW_IRQHandler(void);
void GPT4_COUNTER_UNDERFLOW_IRQHandler(void);
void GPT4_PC_IRQHandler(void);
void GPT5_CAPTURE_COMPARE_A_IRQHandler(void);
void GPT5_CAPTURE_COMPARE_B_IRQHandler(void);
void GPT5_COMPARE_C_IRQHandler(void);
void GPT5_COMPARE_D_IRQHandler(void);
void GPT5_COMPARE_E_IRQHandler(void);
void GPT5_COMPARE_F_IRQHandler(void);
void GPT5_COUNTER_OVERFLOW_IRQHandler(void);
void GPT5_COUNTER_UNDERFLOW_IRQHandler(void);
void GPT5_PC_IRQHandler(void);
void ADC0_SCAN_END_IRQHandler(void);
void ADC0_SCAN_END_B_IRQHandler(void);
void ADC0_WINDOW_A_IRQHandler(void);
void ADC0_WINDOW_B_IRQHandler(void);
void ADC0_COMPARE_MATCH_IRQHandler(void);
void ADC0_COMPARE_MISMATCH_IRQHandler(void);
void SCI0_RXI_IRQHandler(void);
void SCI0_TXI_IRQHandler(void);
void SCI0_TEI_IRQHandler(void);
void SCI0_ERI_IRQHandler(void);
void SCI0_AM_IRQHandler(void);
void SCI0_RXI_OR_ERI_IRQHandler(void);
void SCI3_RXI_IRQHandler(void);
void SCI3_TXI_IRQHandler(void);
void SCI3_TEI_IRQHandler(void);
void SCI3_ERI_IRQHandler(void);
void SCI3_AM_IRQHandler(void);
void SCI4_RXI_IRQHandler(void);
void SCI4_TXI_IRQHandler(void);
void SCI4_TEI_IRQHandler(void);
void SCI4_ERI_IRQHandler(void);
void SCI4_AM_IRQHandler(void);
void SCI9_RXI_IRQHandler(void);
void SCI9_TXI_IRQHandler(void);
void SCI9_TEI_IRQHandler(void);
void SCI9_ERI_IRQHandler(void);
void SCI9_AM_IRQHandler(void);
void SPI0_RXI_IRQHandler(void);
void SPI0_TXI_IRQHandler(void);
void SPI0_IDLE_IRQHandler(void);
void SPI0_ERI_IRQHandler(void);
void SPI0_TEI_IRQHandler(void);
void QSPI_INT_IRQHandler(void);
void DOC_INT_IRQHandler(void);

#pragma weak ICU_IRQ0_IRQHandler = Default_Handler
#pragma weak ICU_IRQ1_IRQHandler = Default_Handler
#pragma weak ICU_IRQ2_IRQHandler = Default_Handler
#pragma weak ICU_IRQ3_IRQHandler = Default_Handler
#pragma weak ICU_IRQ4_IRQHandler = Default_Handler
#pragma weak ICU_IRQ5_IRQHandler = Default_Handler
#pragma weak ICU_IRQ6_IRQHandler = Default_Handler
#pragma weak ICU_IRQ7_IRQHandler = Default_Handler
#pragma weak ICU_IRQ8_IRQHandler = Default_Handler
#pragma weak ICU_IRQ9_IRQHandler = Default_Handler
#pragma weak ICU_IRQ13_IRQHandler = Default_Handler
#pragma weak DMAC0_INT_IRQHandler = Default_Handler
#pragma weak DMAC1_INT_IRQHandler = Default_Handler
#pragma weak DMAC2_INT_IRQHandler = Default_Handler
#pragma weak DMAC3_INT_IRQHandler = Default_Handler
#pragma weak DMAC4_INT_IRQHandler = Default_Handler
#pragma weak DMAC5_INT_IRQHandler = Default_Handler
#pragma weak DMAC6_INT_IRQHandler = Default_Handler
#pragma weak DMAC7_INT_IRQHandler = Default_Handler
#pragma weak DTC_COMPLETE_IRQHandler = Default_Handler
#pragma weak DTC_END_IRQHandler = Default_Handler
#pragma weak DMA_TRANSERR_IRQHandler = Default_Handler
#pragma weak ICU_SNOOZE_CANCEL_IRQHandler = Default_Handler
#pragma weak FCU_FIFERR_IRQHandler = Default_Handler
#pragma weak FCU_FRDYI_IRQHandler = Default_Handler
#pragma weak LVD_LVD1_IRQHandler = Default_Handler
#pragma weak LVD_LVD2_IRQHandler = Default_Handler
#pragma weak CGC_MOSC_STOP_IRQHandler = Default_Handler
#pragma weak LPM_SNOOZE_REQUEST_IRQHandler = Default_Handler
#pragma weak AGT0_INT_IRQHandler = Default_Handler
#pragma weak AGT0_COMPARE_A_IRQHandler = Default_Handler
#pragma weak AGT0_COMPARE_B_IRQHandler = Default_Handler
#pragma weak AGT1_INT_IRQHandler = Default_Handler
#pragma weak AGT1_COMPARE_A_IRQHandler = Default_Handler
#pragma weak AGT1_COMPARE_B_IRQHandler = Default_Handler
#pragma weak AGT2_INT_IRQHandler = Default_Handler
#pragma weak AGT2_COMPARE_A_IRQHandler = Default_Handler
#pragma weak AGT2_COMPARE_B_IRQHandler = Default_Handler
#pragma weak AGT3_INT_IRQHandler = Default_Handler
#pragma weak AGT3_COMPARE_A_IRQHandler = Default_Handler
#pragma weak AGT3_COMPARE_B_IRQHandler = Default_Handler
#pragma weak AGT5_INT_IRQHandler = Default_Handler
#pragma weak AGT5_COMPARE_A_IRQHandler = Default_Handler
#pragma weak AGT5_COMPARE_B_IRQHandler = Default_Handler
#pragma weak IWDT_UNDERFLOW_IRQHandler = Default_Handler
#pragma weak WDT_UNDERFLOW_IRQHandler = Default_Handler
#pragma weak RTC_ALARM_IRQHandler = Default_Handler
#pragma weak RTC_PERIOD_IRQHandler = Default_Handler
#pragma weak RTC_CARRY_IRQHandler = Default_Handler
#pragma weak USBFS_FIFO_0_IRQHandler = Default_Handler
#pragma weak USBFS_FIFO_1_IRQHandler = Default_Handler
#pragma weak USBFS_INT_IRQHandler = Default_Handler
#pragma weak USBFS_RESUME_IRQHandler = Default_Handler
#pragma weak IIC0_RXI_IRQHandler = Default_Handler
#pragma weak IIC0_TXI_IRQHandler = Default_Handler
#pragma weak IIC0_TEI_IRQHandler = Default_Handler
#pragma weak IIC0_ERI_IRQHandler = Default_Handler
#pragma weak IIC0_WUI_IRQHandler = Default_Handler
#pragma weak CAC_FREQUENCY_ERROR_IRQHandler = Default_Handler
#pragma weak CAC_MEASUREMENT_END_IRQHandler = Default_Handler
#pragma weak CAC_OVERFLOW_IRQHandler = Default_Handler
#pragma weak CAN0_ERROR_IRQHandler = Default_Handler
#pragma weak CAN0_FIFO_RX_IRQHandler = Default_Handler
#pragma weak CAN0_FIFO_TX_IRQHandler = Default_Handler
#pragma weak CAN0_MAILBOX_RX_IRQHandler = Default_Handler
#pragma weak CAN0_MAILBOX_TX_IRQHandler = Default_Handler
#pragma weak IOPORT_EVENT_1_IRQHandler = Default_Handler
#pragma weak IOPORT_EVENT_2_IRQHandler = Default_Handler
#pragma weak IOPORT_EVENT_3_IRQHandler = Default_Handler
#pragma weak IOPORT_EVENT_4_IRQHandler = Default_Handler
#pragma weak ELC_SOFTWARE_EVENT_0_IRQHandler = Default_Handler
#pragma weak ELC_SOFTWARE_EVENT_1_IRQHandler = Default_Handler
#pragma weak POEG0_EVENT_IRQHandler = Default_Handler
#pragma weak POEG1_EVENT_IRQHandler = Default_Handler
#pragma weak POEG2_EVENT_IRQHandler = Default_Handler
#pragma weak POEG3_EVENT_IRQHandler = Default_Handler
#pragma weak GPT1_CAPTURE_COMPARE_A_IRQHandler = Default_Handler
#pragma weak GPT1_CAPTURE_COMPARE_B_IRQHandler = Default_Handler
#pragma weak GPT1_COMPARE_C_IRQHandler = Default_Handler
#pragma weak GPT1_COMPARE_D_IRQHandler = Default_Handler
#pragma weak GPT1_COMPARE_E_IRQHandler = Default_Handler
#pragma weak GPT1_COMPARE_F_IRQHandler = Default_Handler
#pragma weak GPT1_COUNTER_OVERFLOW_IRQHandler = Default_Handler
#pragma weak GPT1_COUNTER_UNDERFLOW_IRQHandler = Default_Handler
#pragma weak GPT1_PC_IRQHandler = Default_Handler
#pragma weak GPT2_CAPTURE_COMPARE_A_IRQHandler = Default_Handler
#pragma weak GPT2_CAPTURE_COMPARE_B_IRQHandler = Default_Handler
#pragma weak GPT2_COMPARE_C_IRQHandler = Default_Handler
#pragma weak GPT2_COMPARE_D_IRQHandler = Default_Handler
#pragma weak GPT2_COMPARE_E_IRQHandler = Default_Handler
#pragma weak GPT2_COMPARE_F_IRQHandler = Default_Handler
#pragma weak GPT2_COUNTER_OVERFLOW_IRQHandler = Default_Handler
#pragma weak GPT2_COUNTER_UNDERFLOW_IRQHandler = Default_Handler
#pragma weak GPT4_CAPTURE_COMPARE_A_IRQHandler = Default_Handler
#pragma weak GPT4_CAPTURE_COMPARE_B_IRQHandler = Default_Handler
#pragma weak GPT4_COMPARE_C_IRQHandler = Default_Handler
#pragma weak GPT4_COMPARE_D_IRQHandler = Default_Handler
#pragma weak GPT4_COMPARE_E_IRQHandler = Default_Handler
#pragma weak GPT4_COMPARE_F_IRQHandler = Default_Handler
#pragma weak GPT4_COUNTER_OVERFLOW_IRQHandler = Default_Handler
#pragma weak GPT4_COUNTER_UNDERFLOW_IRQHandler = Default_Handler
#pragma weak GPT4_PC_IRQHandler = Default_Handler
#pragma weak GPT5_CAPTURE_COMPARE_A_IRQHandler = Default_Handler
#pragma weak GPT5_CAPTURE_COMPARE_B_IRQHandler = Default_Handler
#pragma weak GPT5_COMPARE_C_IRQHandler = Default_Handler
#pragma weak GPT5_COMPARE_D_IRQHandler = Default_Handler
#pragma weak GPT5_COMPARE_E_IRQHandler = Default_Handler
#pragma weak GPT5_COMPARE_F_IRQHandler = Default_Handler
#pragma weak GPT5_COUNTER_OVERFLOW_IRQHandler = Default_Handler
#pragma weak GPT5_COUNTER_UNDERFLOW_IRQHandler = Default_Handler
#pragma weak GPT5_PC_IRQHandler = Default_Handler
#pragma weak ADC0_SCAN_END_IRQHandler = Default_Handler
#pragma weak ADC0_SCAN_END_B_IRQHandler = Default_Handler
#pragma weak ADC0_WINDOW_A_IRQHandler = Default_Handler
#pragma weak ADC0_WINDOW_B_IRQHandler = Default_Handler
#pragma weak ADC0_COMPARE_MATCH_IRQHandler = Default_Handler
#pragma weak ADC0_COMPARE_MISMATCH_IRQHandler = Default_Handler
#pragma weak SCI0_RXI_IRQHandler = Default_Handler
#pragma weak SCI0_TXI_IRQHandler = Default_Handler
#pragma weak SCI0_TEI_IRQHandler = Default_Handler
#pragma weak SCI0_ERI_IRQHandler = Default_Handler
#pragma weak SCI0_AM_IRQHandler = Default_Handler
#pragma weak SCI0_RXI_OR_ERI_IRQHandler = Default_Handler
#pragma weak SCI3_RXI_IRQHandler = Default_Handler
#pragma weak SCI3_TXI_IRQHandler = Default_Handler
#pragma weak SCI3_TEI_IRQHandler = Default_Handler
#pragma weak SCI3_ERI_IRQHandler = Default_Handler
#pragma weak SCI3_AM_IRQHandler = Default_Handler
#pragma weak SCI4_RXI_IRQHandler = Default_Handler
#pragma weak SCI4_TXI_IRQHandler = Default_Handler
#pragma weak SCI4_TEI_IRQHandler = Default_Handler
#pragma weak SCI4_ERI_IRQHandler = Default_Handler
#pragma weak SCI4_AM_IRQHandler = Default_Handler
#pragma weak SCI9_RXI_IRQHandler = Default_Handler
#pragma weak SCI9_TXI_IRQHandler = Default_Handler
#pragma weak SCI9_TEI_IRQHandler = Default_Handler
#pragma weak SCI9_ERI_IRQHandler = Default_Handler
#pragma weak SCI9_AM_IRQHandler = Default_Handler
#pragma weak SPI0_RXI_IRQHandler = Default_Handler
#pragma weak SPI0_TXI_IRQHandler = Default_Handler
#pragma weak SPI0_IDLE_IRQHandler = Default_Handler
#pragma weak SPI0_ERI_IRQHandler = Default_Handler
#pragma weak SPI0_TEI_IRQHandler = Default_Handler
#pragma weak QSPI_INT_IRQHandler = Default_Handler
#pragma weak DOC_INT_IRQHandler = Default_Handler

//Vector table
#pragma language = extended
#pragma segment = "CSTACK"
#pragma section = ".intvec"
#pragma location = ".intvec"
const uint32_t __vector_table[320] =
{
   (uint32_t) __sfe("CSTACK"),

   (uint32_t) Reset_Handler,
   (uint32_t) NMI_Handler,
   (uint32_t) HardFault_Handler,
   (uint32_t) MemManage_Handler,
   (uint32_t) BusFault_Handler,
   (uint32_t) UsageFault_Handler,
   (uint32_t) 0,
   (uint32_t) 0,
   (uint32_t) 0,
   (uint32_t) 0,
   (uint32_t) SVC_Handler,
   (uint32_t) DebugMon_Handler,
   (uint32_t) 0,
   (uint32_t) PendSV_Handler,
   (uint32_t) SysTick_Handler,

#if (BSP_IRQ_CFG_ICU_IRQ0 != BSP_IRQ_DISABLED)
   (uint32_t) ICU_IRQ0_IRQHandler,
#endif
#if (BSP_IRQ_CFG_ICU_IRQ1 != BSP_IRQ_DISABLED)
   (uint32_t) ICU_IRQ1_IRQHandler,
#endif
#if (BSP_IRQ_CFG_ICU_IRQ2 != BSP_IRQ_DISABLED)
   (uint32_t) ICU_IRQ2_IRQHandler,
#endif
#if (BSP_IRQ_CFG_ICU_IRQ3 != BSP_IRQ_DISABLED)
   (uint32_t) ICU_IRQ3_IRQHandler,
#endif
#if (BSP_IRQ_CFG_ICU_IRQ4 != BSP_IRQ_DISABLED)
   (uint32_t) ICU_IRQ4_IRQHandler,
#endif
#if (BSP_IRQ_CFG_ICU_IRQ5 != BSP_IRQ_DISABLED)
   (uint32_t) ICU_IRQ5_IRQHandler,
#endif
#if (BSP_IRQ_CFG_ICU_IRQ6 != BSP_IRQ_DISABLED)
   (uint32_t) ICU_IRQ6_IRQHandler,
#endif
#if (BSP_IRQ_CFG_ICU_IRQ7 != BSP_IRQ_DISABLED)
   (uint32_t) ICU_IRQ7_IRQHandler,
#endif
#if (BSP_IRQ_CFG_ICU_IRQ8 != BSP_IRQ_DISABLED)
   (uint32_t) ICU_IRQ8_IRQHandler,
#endif
#if (BSP_IRQ_CFG_ICU_IRQ9 != BSP_IRQ_DISABLED)
   (uint32_t) ICU_IRQ9_IRQHandler,
#endif
#if (BSP_IRQ_CFG_ICU_IRQ13 != BSP_IRQ_DISABLED)
   (uint32_t) ICU_IRQ13_IRQHandler,
#endif
#if (BSP_IRQ_CFG_DMAC0_INT != BSP_IRQ_DISABLED)
   (uint32_t) DMAC0_INT_IRQHandler,
#endif
#if (BSP_IRQ_CFG_DMAC1_INT != BSP_IRQ_DISABLED)
   (uint32_t) DMAC1_INT_IRQHandler,
#endif
#if (BSP_IRQ_CFG_DMAC2_INT != BSP_IRQ_DISABLED)
   (uint32_t) DMAC2_INT_IRQHandler,
#endif
#if (BSP_IRQ_CFG_DMAC3_INT != BSP_IRQ_DISABLED)
   (uint32_t) DMAC3_INT_IRQHandler,
#endif
#if (BSP_IRQ_CFG_DMAC4_INT != BSP_IRQ_DISABLED)
   (uint32_t) DMAC4_INT_IRQHandler,
#endif
#if (BSP_IRQ_CFG_DMAC5_INT != BSP_IRQ_DISABLED)
   (uint32_t) DMAC5_INT_IRQHandler,
#endif
#if (BSP_IRQ_CFG_DMAC6_INT != BSP_IRQ_DISABLED)
   (uint32_t) DMAC6_INT_IRQHandler,
#endif
#if (BSP_IRQ_CFG_DMAC7_INT != BSP_IRQ_DISABLED)
   (uint32_t) DMAC7_INT_IRQHandler,
#endif
#if (BSP_IRQ_CFG_DTC_COMPLETE != BSP_IRQ_DISABLED)
   (uint32_t) DTC_COMPLETE_IRQHandler,
#endif
#if (BSP_IRQ_CFG_DTC_END != BSP_IRQ_DISABLED)
   (uint32_t) DTC_END_IRQHandler,
#endif
#if (BSP_IRQ_CFG_DMA_TRANSERR != BSP_IRQ_DISABLED)
   (uint32_t) DMA_TRANSERR_IRQHandler,
#endif
#if (BSP_IRQ_CFG_ICU_SNOOZE_CANCEL != BSP_IRQ_DISABLED)
   (uint32_t) ICU_SNOOZE_CANCEL_IRQHandler,
#endif
#if (BSP_IRQ_CFG_FCU_FIFERR != BSP_IRQ_DISABLED)
   (uint32_t) FCU_FIFERR_IRQHandler,
#endif
#if (BSP_IRQ_CFG_FCU_FRDYI != BSP_IRQ_DISABLED)
   (uint32_t) FCU_FRDYI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_LVD_LVD1 != BSP_IRQ_DISABLED)
   (uint32_t) LVD_LVD1_IRQHandler,
#endif
#if (BSP_IRQ_CFG_LVD_LVD2 != BSP_IRQ_DISABLED)
   (uint32_t) LVD_LVD2_IRQHandler,
#endif
#if (BSP_IRQ_CFG_CGC_MOSC_STOP != BSP_IRQ_DISABLED)
   (uint32_t) CGC_MOSC_STOP_IRQHandler,
#endif
#if (BSP_IRQ_CFG_LPM_SNOOZE_REQUEST != BSP_IRQ_DISABLED)
   (uint32_t) LPM_SNOOZE_REQUEST_IRQHandler,
#endif
#if (BSP_IRQ_CFG_AGT0_INT != BSP_IRQ_DISABLED)
   (uint32_t) AGT0_INT_IRQHandler,
#endif
#if (BSP_IRQ_CFG_AGT0_COMPARE_A != BSP_IRQ_DISABLED)
   (uint32_t) AGT0_COMPARE_A_IRQHandler,
#endif
#if (BSP_IRQ_CFG_AGT0_COMPARE_B != BSP_IRQ_DISABLED)
   (uint32_t) AGT0_COMPARE_B_IRQHandler,
#endif
#if (BSP_IRQ_CFG_AGT1_INT != BSP_IRQ_DISABLED)
   (uint32_t) AGT1_INT_IRQHandler,
#endif
#if (BSP_IRQ_CFG_AGT1_COMPARE_A != BSP_IRQ_DISABLED)
   (uint32_t) AGT1_COMPARE_A_IRQHandler,
#endif
#if (BSP_IRQ_CFG_AGT1_COMPARE_B != BSP_IRQ_DISABLED)
   (uint32_t) AGT1_COMPARE_B_IRQHandler,
#endif
#if (BSP_IRQ_CFG_AGT2_INT != BSP_IRQ_DISABLED)
   (uint32_t) AGT2_INT_IRQHandler,
#endif
#if (BSP_IRQ_CFG_AGT2_COMPARE_A != BSP_IRQ_DISABLED)
   (uint32_t) AGT2_COMPARE_A_IRQHandler,
#endif
#if (BSP_IRQ_CFG_AGT2_COMPARE_B != BSP_IRQ_DISABLED)
   (uint32_t) AGT2_COMPARE_B_IRQHandler,
#endif
#if (BSP_IRQ_CFG_AGT3_INT != BSP_IRQ_DISABLED)
   (uint32_t) AGT3_INT_IRQHandler,
#endif
#if (BSP_IRQ_CFG_AGT3_COMPARE_A != BSP_IRQ_DISABLED)
   (uint32_t) AGT3_COMPARE_A_IRQHandler,
#endif
#if (BSP_IRQ_CFG_AGT3_COMPARE_B != BSP_IRQ_DISABLED)
   (uint32_t) AGT3_COMPARE_B_IRQHandler,
#endif
#if (BSP_IRQ_CFG_AGT5_INT != BSP_IRQ_DISABLED)
   (uint32_t) AGT5_INT_IRQHandler,
#endif
#if (BSP_IRQ_CFG_AGT5_COMPARE_A != BSP_IRQ_DISABLED)
   (uint32_t) AGT5_COMPARE_A_IRQHandler,
#endif
#if (BSP_IRQ_CFG_AGT5_COMPARE_B != BSP_IRQ_DISABLED)
   (uint32_t) AGT5_COMPARE_B_IRQHandler,
#endif
#if (BSP_IRQ_CFG_IWDT_UNDERFLOW != BSP_IRQ_DISABLED)
   (uint32_t) IWDT_UNDERFLOW_IRQHandler,
#endif
#if (BSP_IRQ_CFG_WDT_UNDERFLOW != BSP_IRQ_DISABLED)
   (uint32_t) WDT_UNDERFLOW_IRQHandler,
#endif
#if (BSP_IRQ_CFG_RTC_ALARM != BSP_IRQ_DISABLED)
   (uint32_t) RTC_ALARM_IRQHandler,
#endif
#if (BSP_IRQ_CFG_RTC_PERIOD != BSP_IRQ_DISABLED)
   (uint32_t) RTC_PERIOD_IRQHandler,
#endif
#if (BSP_IRQ_CFG_RTC_CARRY != BSP_IRQ_DISABLED)
   (uint32_t) RTC_CARRY_IRQHandler,
#endif
#if (BSP_IRQ_CFG_USBFS_FIFO_0 != BSP_IRQ_DISABLED)
   (uint32_t) USBFS_FIFO_0_IRQHandler,
#endif
#if (BSP_IRQ_CFG_USBFS_FIFO_1 != BSP_IRQ_DISABLED)
   (uint32_t) USBFS_FIFO_1_IRQHandler,
#endif
#if (BSP_IRQ_CFG_USBFS_INT != BSP_IRQ_DISABLED)
   (uint32_t) USBFS_INT_IRQHandler,
#endif
#if (BSP_IRQ_CFG_USBFS_RESUME != BSP_IRQ_DISABLED)
   (uint32_t) USBFS_RESUME_IRQHandler,
#endif
#if (BSP_IRQ_CFG_IIC0_RXI != BSP_IRQ_DISABLED)
   (uint32_t) IIC0_RXI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_IIC0_TXI != BSP_IRQ_DISABLED)
   (uint32_t) IIC0_TXI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_IIC0_TEI != BSP_IRQ_DISABLED)
   (uint32_t) IIC0_TEI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_IIC0_ERI != BSP_IRQ_DISABLED)
   (uint32_t) IIC0_ERI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_IIC0_WUI != BSP_IRQ_DISABLED)
   (uint32_t) IIC0_WUI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_CAC_FREQUENCY_ERROR != BSP_IRQ_DISABLED)
   (uint32_t) CAC_FREQUENCY_ERROR_IRQHandler,
#endif
#if (BSP_IRQ_CFG_CAC_MEASUREMENT_END != BSP_IRQ_DISABLED)
   (uint32_t) CAC_MEASUREMENT_END_IRQHandler,
#endif
#if (BSP_IRQ_CFG_CAC_OVERFLOW != BSP_IRQ_DISABLED)
   (uint32_t) CAC_OVERFLOW_IRQHandler,
#endif
#if (BSP_IRQ_CFG_CAN0_ERROR != BSP_IRQ_DISABLED)
   (uint32_t) CAN0_ERROR_IRQHandler,
#endif
#if (BSP_IRQ_CFG_CAN0_FIFO_RX != BSP_IRQ_DISABLED)
   (uint32_t) CAN0_FIFO_RX_IRQHandler,
#endif
#if (BSP_IRQ_CFG_CAN0_FIFO_TX != BSP_IRQ_DISABLED)
   (uint32_t) CAN0_FIFO_TX_IRQHandler,
#endif
#if (BSP_IRQ_CFG_CAN0_MAILBOX_RX != BSP_IRQ_DISABLED)
   (uint32_t) CAN0_MAILBOX_RX_IRQHandler,
#endif
#if (BSP_IRQ_CFG_CAN0_MAILBOX_TX != BSP_IRQ_DISABLED)
   (uint32_t) CAN0_MAILBOX_TX_IRQHandler,
#endif
#if (BSP_IRQ_CFG_IOPORT_EVENT_1 != BSP_IRQ_DISABLED)
   (uint32_t) IOPORT_EVENT_1_IRQHandler,
#endif
#if (BSP_IRQ_CFG_IOPORT_EVENT_2 != BSP_IRQ_DISABLED)
   (uint32_t) IOPORT_EVENT_2_IRQHandler,
#endif
#if (BSP_IRQ_CFG_IOPORT_EVENT_3 != BSP_IRQ_DISABLED)
   (uint32_t) IOPORT_EVENT_3_IRQHandler,
#endif
#if (BSP_IRQ_CFG_IOPORT_EVENT_4 != BSP_IRQ_DISABLED)
   (uint32_t) IOPORT_EVENT_4_IRQHandler,
#endif
#if (BSP_IRQ_CFG_ELC_SOFTWARE_EVENT_0 != BSP_IRQ_DISABLED)
   (uint32_t) ELC_SOFTWARE_EVENT_0_IRQHandler,
#endif
#if (BSP_IRQ_CFG_ELC_SOFTWARE_EVENT_1 != BSP_IRQ_DISABLED)
   (uint32_t) ELC_SOFTWARE_EVENT_1_IRQHandler,
#endif
#if (BSP_IRQ_CFG_POEG0_EVENT != BSP_IRQ_DISABLED)
   (uint32_t) POEG0_EVENT_IRQHandler,
#endif
#if (BSP_IRQ_CFG_POEG1_EVENT != BSP_IRQ_DISABLED)
   (uint32_t) POEG1_EVENT_IRQHandler,
#endif
#if (BSP_IRQ_CFG_POEG2_EVENT != BSP_IRQ_DISABLED)
   (uint32_t) POEG2_EVENT_IRQHandler,
#endif
#if (BSP_IRQ_CFG_POEG3_EVENT != BSP_IRQ_DISABLED)
   (uint32_t) POEG3_EVENT_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT1_CAPTURE_COMPARE_A != BSP_IRQ_DISABLED)
   (uint32_t) GPT1_CAPTURE_COMPARE_A_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT1_CAPTURE_COMPARE_B != BSP_IRQ_DISABLED)
   (uint32_t) GPT1_CAPTURE_COMPARE_B_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT1_COMPARE_C != BSP_IRQ_DISABLED)
   (uint32_t) GPT1_COMPARE_C_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT1_COMPARE_D != BSP_IRQ_DISABLED)
   (uint32_t) GPT1_COMPARE_D_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT1_COMPARE_E != BSP_IRQ_DISABLED)
   (uint32_t) GPT1_COMPARE_E_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT1_COMPARE_F != BSP_IRQ_DISABLED)
   (uint32_t) GPT1_COMPARE_F_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT1_COUNTER_OVERFLOW != BSP_IRQ_DISABLED)
   (uint32_t) GPT1_COUNTER_OVERFLOW_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT1_COUNTER_UNDERFLOW != BSP_IRQ_DISABLED)
   (uint32_t) GPT1_COUNTER_UNDERFLOW_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT1_PC != BSP_IRQ_DISABLED)
   (uint32_t) GPT1_PC_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT2_CAPTURE_COMPARE_A != BSP_IRQ_DISABLED)
   (uint32_t) GPT2_CAPTURE_COMPARE_A_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT2_CAPTURE_COMPARE_B != BSP_IRQ_DISABLED)
   (uint32_t) GPT2_CAPTURE_COMPARE_B_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT2_COMPARE_C != BSP_IRQ_DISABLED)
   (uint32_t) GPT2_COMPARE_C_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT2_COMPARE_D != BSP_IRQ_DISABLED)
   (uint32_t) GPT2_COMPARE_D_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT2_COMPARE_E != BSP_IRQ_DISABLED)
   (uint32_t) GPT2_COMPARE_E_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT2_COMPARE_F != BSP_IRQ_DISABLED)
   (uint32_t) GPT2_COMPARE_F_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT2_COUNTER_OVERFLOW != BSP_IRQ_DISABLED)
   (uint32_t) GPT2_COUNTER_OVERFLOW_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT2_COUNTER_UNDERFLOW != BSP_IRQ_DISABLED)
   (uint32_t) GPT2_COUNTER_UNDERFLOW_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT4_CAPTURE_COMPARE_A != BSP_IRQ_DISABLED)
   (uint32_t) GPT4_CAPTURE_COMPARE_A_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT4_CAPTURE_COMPARE_B != BSP_IRQ_DISABLED)
   (uint32_t) GPT4_CAPTURE_COMPARE_B_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT4_COMPARE_C != BSP_IRQ_DISABLED)
   (uint32_t) GPT4_COMPARE_C_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT4_COMPARE_D != BSP_IRQ_DISABLED)
   (uint32_t) GPT4_COMPARE_D_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT4_COMPARE_E != BSP_IRQ_DISABLED)
   (uint32_t) GPT4_COMPARE_E_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT4_COMPARE_F != BSP_IRQ_DISABLED)
   (uint32_t) GPT4_COMPARE_F_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT4_COUNTER_OVERFLOW != BSP_IRQ_DISABLED)
   (uint32_t) GPT4_COUNTER_OVERFLOW_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT4_COUNTER_UNDERFLOW != BSP_IRQ_DISABLED)
   (uint32_t) GPT4_COUNTER_UNDERFLOW_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT4_PC != BSP_IRQ_DISABLED)
   (uint32_t) GPT4_PC_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT5_CAPTURE_COMPARE_A != BSP_IRQ_DISABLED)
   (uint32_t) GPT5_CAPTURE_COMPARE_A_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT5_CAPTURE_COMPARE_B != BSP_IRQ_DISABLED)
   (uint32_t) GPT5_CAPTURE_COMPARE_B_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT5_COMPARE_C != BSP_IRQ_DISABLED)
   (uint32_t) GPT5_COMPARE_C_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT5_COMPARE_D != BSP_IRQ_DISABLED)
   (uint32_t) GPT5_COMPARE_D_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT5_COMPARE_E != BSP_IRQ_DISABLED)
   (uint32_t) GPT5_COMPARE_E_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT5_COMPARE_F != BSP_IRQ_DISABLED)
   (uint32_t) GPT5_COMPARE_F_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT5_COUNTER_OVERFLOW != BSP_IRQ_DISABLED)
   (uint32_t) GPT5_COUNTER_OVERFLOW_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT5_COUNTER_UNDERFLOW != BSP_IRQ_DISABLED)
   (uint32_t) GPT5_COUNTER_UNDERFLOW_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT5_PC != BSP_IRQ_DISABLED)
   (uint32_t) GPT5_PC_IRQHandler,
#endif
#if (BSP_IRQ_CFG_ADC0_SCAN_END != BSP_IRQ_DISABLED)
   (uint32_t) ADC0_SCAN_END_IRQHandler,
#endif
#if (BSP_IRQ_CFG_ADC0_SCAN_END_B != BSP_IRQ_DISABLED)
   (uint32_t) ADC0_SCAN_END_B_IRQHandler,
#endif
#if (BSP_IRQ_CFG_ADC0_WINDOW_A != BSP_IRQ_DISABLED)
   (uint32_t) ADC0_WINDOW_A_IRQHandler,
#endif
#if (BSP_IRQ_CFG_ADC0_WINDOW_B != BSP_IRQ_DISABLED)
   (uint32_t) ADC0_WINDOW_B_IRQHandler,
#endif
#if (BSP_IRQ_CFG_ADC0_COMPARE_MATCH != BSP_IRQ_DISABLED)
   (uint32_t) ADC0_COMPARE_MATCH_IRQHandler,
#endif
#if (BSP_IRQ_CFG_ADC0_COMPARE_MISMATCH != BSP_IRQ_DISABLED)
   (uint32_t) ADC0_COMPARE_MISMATCH_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCI0_RXI != BSP_IRQ_DISABLED)
   (uint32_t) SCI0_RXI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCI0_TXI != BSP_IRQ_DISABLED)
   (uint32_t) SCI0_TXI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCI0_TEI != BSP_IRQ_DISABLED)
   (uint32_t) SCI0_TEI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCI0_ERI != BSP_IRQ_DISABLED)
   (uint32_t) SCI0_ERI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCI0_AM != BSP_IRQ_DISABLED)
   (uint32_t) SCI0_AM_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCI0_RXI_OR_ERI != BSP_IRQ_DISABLED)
   (uint32_t) SCI0_RXI_OR_ERI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCI3_RXI != BSP_IRQ_DISABLED)
   (uint32_t) SCI3_RXI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCI3_TXI != BSP_IRQ_DISABLED)
   (uint32_t) SCI3_TXI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCI3_TEI != BSP_IRQ_DISABLED)
   (uint32_t) SCI3_TEI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCI3_ERI != BSP_IRQ_DISABLED)
   (uint32_t) SCI3_ERI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCI3_AM != BSP_IRQ_DISABLED)
   (uint32_t) SCI3_AM_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCI4_RXI != BSP_IRQ_DISABLED)
   (uint32_t) SCI4_RXI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCI4_TXI != BSP_IRQ_DISABLED)
   (uint32_t) SCI4_TXI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCI4_TEI != BSP_IRQ_DISABLED)
   (uint32_t) SCI4_TEI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCI4_ERI != BSP_IRQ_DISABLED)
   (uint32_t) SCI4_ERI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCI4_AM != BSP_IRQ_DISABLED)
   (uint32_t) SCI4_AM_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCI9_RXI != BSP_IRQ_DISABLED)
   (uint32_t) SCI9_RXI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCI9_TXI != BSP_IRQ_DISABLED)
   (uint32_t) SCI9_TXI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCI9_TEI != BSP_IRQ_DISABLED)
   (uint32_t) SCI9_TEI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCI9_ERI != BSP_IRQ_DISABLED)
   (uint32_t) SCI9_ERI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCI9_AM != BSP_IRQ_DISABLED)
   (uint32_t) SCI9_AM_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SPI0_RXI != BSP_IRQ_DISABLED)
   (uint32_t) SPI0_RXI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SPI0_TXI != BSP_IRQ_DISABLED)
   (uint32_t) SPI0_TXI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SPI0_IDLE != BSP_IRQ_DISABLED)
   (uint32_t) SPI0_IDLE_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SPI0_ERI != BSP_IRQ_DISABLED)
   (uint32_t) SPI0_ERI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SPI0_TEI != BSP_IRQ_DISABLED)
   (uint32_t) SPI0_TEI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_QSPI_INT != BSP_IRQ_DISABLED)
   (uint32_t) QSPI_INT_IRQHandler,
#endif
#if (BSP_IRQ_CFG_DOC_INT != BSP_IRQ_DISABLED)
   (uint32_t) DOC_INT_IRQHandler,
#endif
   [256] = 0xFFFFFFFF,
   [257] = 0xFFFFFFFF,
   [258] = 0xFFFFFFFF,
   [259] = 0xFFFFFFFF,
   [260] = 0xFFFFFFFF,
   [261] = 0xFFFFFFFF,
   [262] = 0xFFFFFFFF,
   [263] = 0xFFFFFFFF,
   [264] = 0xFFFFFFFF,
   [265] = 0xFFFFFFFF,
   [266] = 0xFFFFFFFF,
   [267] = 0xFFFFFFFF,
   [268] = 0xFFFFFFFF,
   [269] = 0xFFFFFFFF,
   [270] = 0xFFFFFFFF,
   [271] = 0xFFFFFFFF,
   [272] = 0xFFFFFFFF,
   [273] = 0xFFFFFFFF,
   [274] = 0xFFFFFFFF,
   [275] = 0xFFFFFFFF,
   [276] = 0xFFFFFFFF,
   [277] = 0xFFFFFFFF,
   [278] = 0xFFFFFFFF,
   [279] = 0xFFFFFFFF,
   [280] = 0xFFFFFFFF,
   [281] = 0xFFFFFFFF,
   [282] = 0xFFFFFFFF,
   [283] = 0xFFFFFFFF,
   [284] = 0xFFFFFFFF,
   [285] = 0xFFFFFFFF,
   [286] = 0xFFFFFFFF,
   [287] = 0xFFFFFFFF,
   [288] = 0xFFFFFFFF,
   [289] = 0xFFFFFFFF,
   [290] = 0xFFFFFFFF,
   [291] = 0xFFFFFFFF,
   [292] = 0xFFFFFFFF,
   [293] = 0xFFFFFFFF,
   [294] = 0xFFFFFFFF,
   [295] = 0xFFFFFFFF,
   [296] = 0xFFFFFFFF,
   [297] = 0xFFFFFFFF,
   [298] = 0xFFFFFFFF,
   [299] = 0xFFFFFFFF,
   [300] = 0xFFFFFFFF,
   [301] = 0xFFFFFFFF,
   [302] = 0xFFFFFFFF,
   [303] = 0xFFFFFFFF,
   [304] = 0xFFFFFFFF,
   [305] = 0xFFFFFFFF,
   [306] = 0xFFFFFFFF,
   [307] = 0xFFFFFFFF,
   [308] = 0xFFFFFFFF,
   [309] = 0xFFFFFFFF,
   [310] = 0xFFFFFFFF,
   [311] = 0xFFFFFFFF,
   [312] = 0xFFFFFFFF,
   [313] = 0xFFFFFFFF,
   [314] = 0xFFFFFFFF,
   [315] = 0xFFFFFFFF,
   [316] = 0xFFFFFFFF,
   [317] = 0xFFFFFFFF,
   [318] = 0xFFFFFFFF,
   [319] = 0xFFFFFFFF
};

//Low-level initialization
int __low_level_init(void)
{
   //Point to the beginning of the vector table
   uint32_t *p = __section_begin(".intvec");
   //Set vector table offset
   SCB->VTOR = ((uint32_t) p & SCB_VTOR_TBLOFF_Msk);
   //If return 0, the data sections will not be initialized
   return 1;
}

//Reset handler
void Reset_Handler(void)
{
   //System initialization
   SystemInit();
   //Main entry point
   __iar_program_start();
}

//Default interrupt handler
void Default_Handler(void)
{
   while(1);
}
