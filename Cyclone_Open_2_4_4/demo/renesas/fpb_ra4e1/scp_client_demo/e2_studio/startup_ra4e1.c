//Dependencies
#include "bsp_api.h"

//Linker file constants
extern uint32_t _sidata;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;
extern uint32_t _estack;

//Function declaration
void SystemInit(void);
void __libc_init_array(void);
int main(void);

//Default empty handler
void Default_Handler(void);

//Cortex-M4 core handlers
void Reset_Handler                     (void);
void NMI_Handler                       (void) __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler                 (void) __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler                 (void) __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler                  (void) __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler                (void) __attribute__((weak, alias("Default_Handler")));
void SVC_Handler                       (void) __attribute__((weak, alias("Default_Handler")));
void DebugMon_Handler                  (void) __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler                    (void) __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler                   (void) __attribute__((weak, alias("Default_Handler")));

//Peripheral handlers
void ICU_IRQ0_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void ICU_IRQ1_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void ICU_IRQ2_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void ICU_IRQ3_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void ICU_IRQ4_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void ICU_IRQ5_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void ICU_IRQ6_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void ICU_IRQ7_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void ICU_IRQ8_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void ICU_IRQ9_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void ICU_IRQ13_IRQHandler              (void) __attribute__((weak, alias("Default_Handler")));
void DMAC0_INT_IRQHandler              (void) __attribute__((weak, alias("Default_Handler")));
void DMAC1_INT_IRQHandler              (void) __attribute__((weak, alias("Default_Handler")));
void DMAC2_INT_IRQHandler              (void) __attribute__((weak, alias("Default_Handler")));
void DMAC3_INT_IRQHandler              (void) __attribute__((weak, alias("Default_Handler")));
void DMAC4_INT_IRQHandler              (void) __attribute__((weak, alias("Default_Handler")));
void DMAC5_INT_IRQHandler              (void) __attribute__((weak, alias("Default_Handler")));
void DMAC6_INT_IRQHandler              (void) __attribute__((weak, alias("Default_Handler")));
void DMAC7_INT_IRQHandler              (void) __attribute__((weak, alias("Default_Handler")));
void DTC_COMPLETE_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void DTC_END_IRQHandler                (void) __attribute__((weak, alias("Default_Handler")));
void DMA_TRANSERR_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void ICU_SNOOZE_CANCEL_IRQHandler      (void) __attribute__((weak, alias("Default_Handler")));
void FCU_FIFERR_IRQHandler             (void) __attribute__((weak, alias("Default_Handler")));
void FCU_FRDYI_IRQHandler              (void) __attribute__((weak, alias("Default_Handler")));
void LVD_LVD1_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void LVD_LVD2_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void CGC_MOSC_STOP_IRQHandler          (void) __attribute__((weak, alias("Default_Handler")));
void LPM_SNOOZE_REQUEST_IRQHandler     (void) __attribute__((weak, alias("Default_Handler")));
void AGT0_INT_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void AGT0_COMPARE_A_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void AGT0_COMPARE_B_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void AGT1_INT_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void AGT1_COMPARE_A_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void AGT1_COMPARE_B_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void AGT2_INT_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void AGT2_COMPARE_A_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void AGT2_COMPARE_B_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void AGT3_INT_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void AGT3_COMPARE_A_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void AGT3_COMPARE_B_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void AGT5_INT_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void AGT5_COMPARE_A_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void AGT5_COMPARE_B_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void IWDT_UNDERFLOW_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void WDT_UNDERFLOW_IRQHandler          (void) __attribute__((weak, alias("Default_Handler")));
void RTC_ALARM_IRQHandler              (void) __attribute__((weak, alias("Default_Handler")));
void RTC_PERIOD_IRQHandler             (void) __attribute__((weak, alias("Default_Handler")));
void RTC_CARRY_IRQHandler              (void) __attribute__((weak, alias("Default_Handler")));
void USBFS_FIFO_0_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void USBFS_FIFO_1_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void USBFS_INT_IRQHandler              (void) __attribute__((weak, alias("Default_Handler")));
void USBFS_RESUME_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void IIC0_RXI_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void IIC0_TXI_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void IIC0_TEI_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void IIC0_ERI_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void IIC0_WUI_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void CAC_FREQUENCY_ERROR_IRQHandler    (void) __attribute__((weak, alias("Default_Handler")));
void CAC_MEASUREMENT_END_IRQHandler    (void) __attribute__((weak, alias("Default_Handler")));
void CAC_OVERFLOW_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void CAN0_ERROR_IRQHandler             (void) __attribute__((weak, alias("Default_Handler")));
void CAN0_FIFO_RX_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void CAN0_FIFO_TX_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void CAN0_MAILBOX_RX_IRQHandler        (void) __attribute__((weak, alias("Default_Handler")));
void CAN0_MAILBOX_TX_IRQHandler        (void) __attribute__((weak, alias("Default_Handler")));
void IOPORT_EVENT_1_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void IOPORT_EVENT_2_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void IOPORT_EVENT_3_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void IOPORT_EVENT_4_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void ELC_SOFTWARE_EVENT_0_IRQHandler   (void) __attribute__((weak, alias("Default_Handler")));
void ELC_SOFTWARE_EVENT_1_IRQHandler   (void) __attribute__((weak, alias("Default_Handler")));
void POEG0_EVENT_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void POEG1_EVENT_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void POEG2_EVENT_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void POEG3_EVENT_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT1_CAPTURE_COMPARE_A_IRQHandler (void) __attribute__((weak, alias("Default_Handler")));
void GPT1_CAPTURE_COMPARE_B_IRQHandler (void) __attribute__((weak, alias("Default_Handler")));
void GPT1_COMPARE_C_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void GPT1_COMPARE_D_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void GPT1_COMPARE_E_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void GPT1_COMPARE_F_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void GPT1_COUNTER_OVERFLOW_IRQHandler  (void) __attribute__((weak, alias("Default_Handler")));
void GPT1_COUNTER_UNDERFLOW_IRQHandler (void) __attribute__((weak, alias("Default_Handler")));
void GPT1_PC_IRQHandler                (void) __attribute__((weak, alias("Default_Handler")));
void GPT2_CAPTURE_COMPARE_A_IRQHandler (void) __attribute__((weak, alias("Default_Handler")));
void GPT2_CAPTURE_COMPARE_B_IRQHandler (void) __attribute__((weak, alias("Default_Handler")));
void GPT2_COMPARE_C_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void GPT2_COMPARE_D_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void GPT2_COMPARE_E_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void GPT2_COMPARE_F_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void GPT2_COUNTER_OVERFLOW_IRQHandler  (void) __attribute__((weak, alias("Default_Handler")));
void GPT2_COUNTER_UNDERFLOW_IRQHandler (void) __attribute__((weak, alias("Default_Handler")));
void GPT4_CAPTURE_COMPARE_A_IRQHandler (void) __attribute__((weak, alias("Default_Handler")));
void GPT4_CAPTURE_COMPARE_B_IRQHandler (void) __attribute__((weak, alias("Default_Handler")));
void GPT4_COMPARE_C_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void GPT4_COMPARE_D_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void GPT4_COMPARE_E_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void GPT4_COMPARE_F_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void GPT4_COUNTER_OVERFLOW_IRQHandler  (void) __attribute__((weak, alias("Default_Handler")));
void GPT4_COUNTER_UNDERFLOW_IRQHandler (void) __attribute__((weak, alias("Default_Handler")));
void GPT4_PC_IRQHandler                (void) __attribute__((weak, alias("Default_Handler")));
void GPT5_CAPTURE_COMPARE_A_IRQHandler (void) __attribute__((weak, alias("Default_Handler")));
void GPT5_CAPTURE_COMPARE_B_IRQHandler (void) __attribute__((weak, alias("Default_Handler")));
void GPT5_COMPARE_C_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void GPT5_COMPARE_D_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void GPT5_COMPARE_E_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void GPT5_COMPARE_F_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void GPT5_COUNTER_OVERFLOW_IRQHandler  (void) __attribute__((weak, alias("Default_Handler")));
void GPT5_COUNTER_UNDERFLOW_IRQHandler (void) __attribute__((weak, alias("Default_Handler")));
void GPT5_PC_IRQHandler                (void) __attribute__((weak, alias("Default_Handler")));
void ADC0_SCAN_END_IRQHandler          (void) __attribute__((weak, alias("Default_Handler")));
void ADC0_SCAN_END_B_IRQHandler        (void) __attribute__((weak, alias("Default_Handler")));
void ADC0_WINDOW_A_IRQHandler          (void) __attribute__((weak, alias("Default_Handler")));
void ADC0_WINDOW_B_IRQHandler          (void) __attribute__((weak, alias("Default_Handler")));
void ADC0_COMPARE_MATCH_IRQHandler     (void) __attribute__((weak, alias("Default_Handler")));
void ADC0_COMPARE_MISMATCH_IRQHandler  (void) __attribute__((weak, alias("Default_Handler")));
void SCI0_RXI_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void SCI0_TXI_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void SCI0_TEI_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void SCI0_ERI_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void SCI0_AM_IRQHandler                (void) __attribute__((weak, alias("Default_Handler")));
void SCI0_RXI_OR_ERI_IRQHandler        (void) __attribute__((weak, alias("Default_Handler")));
void SCI3_RXI_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void SCI3_TXI_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void SCI3_TEI_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void SCI3_ERI_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void SCI3_AM_IRQHandler                (void) __attribute__((weak, alias("Default_Handler")));
void SCI4_RXI_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void SCI4_TXI_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void SCI4_TEI_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void SCI4_ERI_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void SCI4_AM_IRQHandler                (void) __attribute__((weak, alias("Default_Handler")));
void SCI9_RXI_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void SCI9_TXI_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void SCI9_TEI_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void SCI9_ERI_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void SCI9_AM_IRQHandler                (void) __attribute__((weak, alias("Default_Handler")));
void SPI0_RXI_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void SPI0_TXI_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void SPI0_IDLE_IRQHandler              (void) __attribute__((weak, alias("Default_Handler")));
void SPI0_ERI_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void SPI0_TEI_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void QSPI_INT_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void DOC_INT_IRQHandler                (void) __attribute__((weak, alias("Default_Handler")));

//Vector table
__attribute__((section(".isr_vector")))
const uint32_t vectorTable[320] =
{
   //Initial stack pointer
   (uint32_t) (&_estack),

   //Core handlers
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

   //Peripheral handlers
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


/**
 * @brief Reset handler
 **/

void Reset_Handler(void)
{
   uint32_t *src;
   uint32_t *dest;

   //Set vector table offset
   SCB->VTOR = (uint32_t) vectorTable & SCB_VTOR_TBLOFF_Msk;

   //System initialization
   SystemInit();

   //Initialize the relocate segment
   src = &_sidata;
   dest = &_sdata;

   if(src != dest)
   {
      while(dest < &_edata)
      {
         *dest++ = *src++;
      }
   }

   //Clear the zero segment
   for(dest = &_sbss; dest < &_ebss;)
   {
      *dest++ = 0;
   }

   //C library initialization
   __libc_init_array();

   //Branch to main function
   main();

   //Endless loop
   while(1);
}


/**
 * @brief Default interrupt handler
 **/

void Default_Handler(void)
{
   while(1)
   {
   }
}
