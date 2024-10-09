//Dependencies
#include "bsp_irq_cfg.h"
#include "s7g2.h"

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
void Reset_Handler                        (void);
void NMI_Handler                          (void) __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler                    (void) __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler                    (void) __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler                     (void) __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler                   (void) __attribute__((weak, alias("Default_Handler")));
void SVC_Handler                          (void) __attribute__((weak, alias("Default_Handler")));
void DebugMon_Handler                     (void) __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler                       (void) __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler                      (void) __attribute__((weak, alias("Default_Handler")));

//Peripheral handlers
void ICU_IRQ0_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void ICU_IRQ1_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void ICU_IRQ2_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void ICU_IRQ3_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void ICU_IRQ4_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void ICU_IRQ5_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void ICU_IRQ6_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void ICU_IRQ7_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void ICU_IRQ8_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void ICU_IRQ9_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void ICU_IRQ10_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler")));
void ICU_IRQ11_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler")));
void ICU_IRQ12_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler")));
void ICU_IRQ13_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler")));
void ICU_IRQ14_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler")));
void ICU_IRQ15_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler")));
void DMAC0_INT_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler")));
void DMAC1_INT_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler")));
void DMAC2_INT_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler")));
void DMAC3_INT_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler")));
void DMAC4_INT_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler")));
void DMAC5_INT_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler")));
void DMAC6_INT_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler")));
void DMAC7_INT_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler")));
void DTC_COMPLETE_IRQHandler              (void) __attribute__((weak, alias("Default_Handler")));
void DTC_END_IRQHandler                   (void) __attribute__((weak, alias("Default_Handler")));
void ICU_SNOOZE_CANCEL_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void FCU_FIFERR_IRQHandler                (void) __attribute__((weak, alias("Default_Handler")));
void FCU_FRDYI_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler")));
void LVD_LVD1_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void LVD_LVD2_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void CGC_MOSC_STOP_IRQHandler             (void) __attribute__((weak, alias("Default_Handler")));
void LPM_SNOOZE_REQUEST_IRQHandler        (void) __attribute__((weak, alias("Default_Handler")));
void AGT0_INT_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void AGT0_COMPARE_A_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void AGT0_COMPARE_B_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void AGT1_INT_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void AGT1_COMPARE_A_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void AGT1_COMPARE_B_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void IWDT_UNDERFLOW_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void WDT_UNDERFLOW_IRQHandler             (void) __attribute__((weak, alias("Default_Handler")));
void RTC_ALARM_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler")));
void RTC_PERIOD_IRQHandler                (void) __attribute__((weak, alias("Default_Handler")));
void RTC_CARRY_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler")));
void ADC0_SCAN_END_IRQHandler             (void) __attribute__((weak, alias("Default_Handler")));
void ADC0_SCAN_END_B_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void ADC0_WINDOW_A_IRQHandler             (void) __attribute__((weak, alias("Default_Handler")));
void ADC0_WINDOW_B_IRQHandler             (void) __attribute__((weak, alias("Default_Handler")));
void ADC0_COMPARE_MATCH_IRQHandler        (void) __attribute__((weak, alias("Default_Handler")));
void ADC0_COMPARE_MISMATCH_IRQHandler     (void) __attribute__((weak, alias("Default_Handler")));
void ADC1_SCAN_END_IRQHandler             (void) __attribute__((weak, alias("Default_Handler")));
void ADC1_SCAN_END_B_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void ADC1_WINDOW_A_IRQHandler             (void) __attribute__((weak, alias("Default_Handler")));
void ADC1_WINDOW_B_IRQHandler             (void) __attribute__((weak, alias("Default_Handler")));
void ADC1_COMPARE_MATCH_IRQHandler        (void) __attribute__((weak, alias("Default_Handler")));
void ADC1_COMPARE_MISMATCH_IRQHandler     (void) __attribute__((weak, alias("Default_Handler")));
void COMP_HS_0_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler")));
void COMP_HS0_INT_IRQHandler              (void) __attribute__((weak, alias("Default_Handler")));
void COMP_HS_1_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler")));
void COMP_HS1_INT_IRQHandler              (void) __attribute__((weak, alias("Default_Handler")));
void COMP_HS_2_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler")));
void COMP_HS2_INT_IRQHandler              (void) __attribute__((weak, alias("Default_Handler")));
void COMP_HS_3_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler")));
void COMP_HS3_INT_IRQHandler              (void) __attribute__((weak, alias("Default_Handler")));
void COMP_HS_4_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler")));
void COMP_HS4_INT_IRQHandler              (void) __attribute__((weak, alias("Default_Handler")));
void COMP_HS_5_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler")));
void COMP_HS5_INT_IRQHandler              (void) __attribute__((weak, alias("Default_Handler")));
void USBFS_FIFO_0_IRQHandler              (void) __attribute__((weak, alias("Default_Handler")));
void USBFS_FIFO_1_IRQHandler              (void) __attribute__((weak, alias("Default_Handler")));
void USBFS_INT_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler")));
void USBFS_RESUME_IRQHandler              (void) __attribute__((weak, alias("Default_Handler")));
void IIC0_RXI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void IIC0_TXI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void IIC0_TEI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void IIC0_ERI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void IIC0_WUI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void IIC1_RXI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void IIC1_TXI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void IIC1_TEI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void IIC1_ERI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void IIC2_RXI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void IIC2_TXI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void IIC2_TEI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void IIC2_ERI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SSI0_TXI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SSI0_RXI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SSI0_INT_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SSI1_TXI_RXI_IRQHandler              (void) __attribute__((weak, alias("Default_Handler")));
void SSI1_INT_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SRC_INPUT_FIFO_EMPTY_IRQHandler      (void) __attribute__((weak, alias("Default_Handler")));
void SRC_OUTPUT_FIFO_FULL_IRQHandler      (void) __attribute__((weak, alias("Default_Handler")));
void SRC_OUTPUT_FIFO_OVERFLOW_IRQHandler  (void) __attribute__((weak, alias("Default_Handler")));
void SRC_OUTPUT_FIFO_UNDERFLOW_IRQHandler (void) __attribute__((weak, alias("Default_Handler")));
void SRC_CONVERSION_END_IRQHandler        (void) __attribute__((weak, alias("Default_Handler")));
void PDC_RECEIVE_DATA_READY_IRQHandler    (void) __attribute__((weak, alias("Default_Handler")));
void PDC_FRAME_END_IRQHandler             (void) __attribute__((weak, alias("Default_Handler")));
void PDC_INT_IRQHandler                   (void) __attribute__((weak, alias("Default_Handler")));
void CTSU_WRITE_IRQHandler                (void) __attribute__((weak, alias("Default_Handler")));
void CTSU_READ_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler")));
void CTSU_END_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void KEY_INT_IRQHandler                   (void) __attribute__((weak, alias("Default_Handler")));
void DOC_INT_IRQHandler                   (void) __attribute__((weak, alias("Default_Handler")));
void CAC_FREQUENCY_ERROR_IRQHandler       (void) __attribute__((weak, alias("Default_Handler")));
void CAC_MEASUREMENT_END_IRQHandler       (void) __attribute__((weak, alias("Default_Handler")));
void CAC_OVERFLOW_IRQHandler              (void) __attribute__((weak, alias("Default_Handler")));
void CAN0_ERROR_IRQHandler                (void) __attribute__((weak, alias("Default_Handler")));
void CAN0_FIFO_RX_IRQHandler              (void) __attribute__((weak, alias("Default_Handler")));
void CAN0_FIFO_TX_IRQHandler              (void) __attribute__((weak, alias("Default_Handler")));
void CAN0_MAILBOX_RX_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void CAN0_MAILBOX_TX_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void CAN1_ERROR_IRQHandler                (void) __attribute__((weak, alias("Default_Handler")));
void CAN1_FIFO_RX_IRQHandler              (void) __attribute__((weak, alias("Default_Handler")));
void CAN1_FIFO_TX_IRQHandler              (void) __attribute__((weak, alias("Default_Handler")));
void CAN1_MAILBOX_RX_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void CAN1_MAILBOX_TX_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void IOPORT_EVENT_1_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void IOPORT_EVENT_2_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void IOPORT_EVENT_3_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void IOPORT_EVENT_4_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void ELC_SOFTWARE_EVENT_0_IRQHandler      (void) __attribute__((weak, alias("Default_Handler")));
void ELC_SOFTWARE_EVENT_1_IRQHandler      (void) __attribute__((weak, alias("Default_Handler")));
void POEG0_EVENT_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void POEG1_EVENT_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void POEG2_EVENT_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void POEG3_EVENT_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void GPT0_CAPTURE_COMPARE_A_IRQHandler    (void) __attribute__((weak, alias("Default_Handler")));
void GPT0_CAPTURE_COMPARE_B_IRQHandler    (void) __attribute__((weak, alias("Default_Handler")));
void GPT0_COMPARE_C_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT0_COMPARE_D_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT0_COMPARE_E_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT0_COMPARE_F_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT0_COUNTER_OVERFLOW_IRQHandler     (void) __attribute__((weak, alias("Default_Handler")));
void GPT0_COUNTER_UNDERFLOW_IRQHandler    (void) __attribute__((weak, alias("Default_Handler")));
void GPT0_AD_TRIG_A_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT0_AD_TRIG_B_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT1_CAPTURE_COMPARE_A_IRQHandler    (void) __attribute__((weak, alias("Default_Handler")));
void GPT1_CAPTURE_COMPARE_B_IRQHandler    (void) __attribute__((weak, alias("Default_Handler")));
void GPT1_COMPARE_C_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT1_COMPARE_D_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT1_COMPARE_E_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT1_COMPARE_F_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT1_COUNTER_OVERFLOW_IRQHandler     (void) __attribute__((weak, alias("Default_Handler")));
void GPT1_COUNTER_UNDERFLOW_IRQHandler    (void) __attribute__((weak, alias("Default_Handler")));
void GPT1_AD_TRIG_A_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT1_AD_TRIG_B_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT2_CAPTURE_COMPARE_A_IRQHandler    (void) __attribute__((weak, alias("Default_Handler")));
void GPT2_CAPTURE_COMPARE_B_IRQHandler    (void) __attribute__((weak, alias("Default_Handler")));
void GPT2_COMPARE_C_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT2_COMPARE_D_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT2_COMPARE_E_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT2_COMPARE_F_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT2_COUNTER_OVERFLOW_IRQHandler     (void) __attribute__((weak, alias("Default_Handler")));
void GPT2_COUNTER_UNDERFLOW_IRQHandler    (void) __attribute__((weak, alias("Default_Handler")));
void GPT2_AD_TRIG_A_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT2_AD_TRIG_B_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT3_CAPTURE_COMPARE_A_IRQHandler    (void) __attribute__((weak, alias("Default_Handler")));
void GPT3_CAPTURE_COMPARE_B_IRQHandler    (void) __attribute__((weak, alias("Default_Handler")));
void GPT3_COMPARE_C_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT3_COMPARE_D_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT3_COMPARE_E_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT3_COMPARE_F_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT3_COUNTER_OVERFLOW_IRQHandler     (void) __attribute__((weak, alias("Default_Handler")));
void GPT3_COUNTER_UNDERFLOW_IRQHandler    (void) __attribute__((weak, alias("Default_Handler")));
void GPT3_AD_TRIG_A_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT3_AD_TRIG_B_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT4_CAPTURE_COMPARE_A_IRQHandler    (void) __attribute__((weak, alias("Default_Handler")));
void GPT4_CAPTURE_COMPARE_B_IRQHandler    (void) __attribute__((weak, alias("Default_Handler")));
void GPT4_COMPARE_C_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT4_COMPARE_D_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT4_COMPARE_E_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT4_COMPARE_F_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT4_COUNTER_OVERFLOW_IRQHandler     (void) __attribute__((weak, alias("Default_Handler")));
void GPT4_COUNTER_UNDERFLOW_IRQHandler    (void) __attribute__((weak, alias("Default_Handler")));
void GPT4_AD_TRIG_A_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT4_AD_TRIG_B_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT5_CAPTURE_COMPARE_A_IRQHandler    (void) __attribute__((weak, alias("Default_Handler")));
void GPT5_CAPTURE_COMPARE_B_IRQHandler    (void) __attribute__((weak, alias("Default_Handler")));
void GPT5_COMPARE_C_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT5_COMPARE_D_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT5_COMPARE_E_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT5_COMPARE_F_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT5_COUNTER_OVERFLOW_IRQHandler     (void) __attribute__((weak, alias("Default_Handler")));
void GPT5_COUNTER_UNDERFLOW_IRQHandler    (void) __attribute__((weak, alias("Default_Handler")));
void GPT5_AD_TRIG_A_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT5_AD_TRIG_B_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT6_CAPTURE_COMPARE_A_IRQHandler    (void) __attribute__((weak, alias("Default_Handler")));
void GPT6_CAPTURE_COMPARE_B_IRQHandler    (void) __attribute__((weak, alias("Default_Handler")));
void GPT6_COMPARE_C_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT6_COMPARE_D_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT6_COMPARE_E_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT6_COMPARE_F_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT6_COUNTER_OVERFLOW_IRQHandler     (void) __attribute__((weak, alias("Default_Handler")));
void GPT6_COUNTER_UNDERFLOW_IRQHandler    (void) __attribute__((weak, alias("Default_Handler")));
void GPT6_AD_TRIG_A_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT6_AD_TRIG_B_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT7_CAPTURE_COMPARE_A_IRQHandler    (void) __attribute__((weak, alias("Default_Handler")));
void GPT7_CAPTURE_COMPARE_B_IRQHandler    (void) __attribute__((weak, alias("Default_Handler")));
void GPT7_COMPARE_C_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT7_COMPARE_D_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT7_COMPARE_E_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT7_COMPARE_F_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT7_COUNTER_OVERFLOW_IRQHandler     (void) __attribute__((weak, alias("Default_Handler")));
void GPT7_COUNTER_UNDERFLOW_IRQHandler    (void) __attribute__((weak, alias("Default_Handler")));
void GPT7_AD_TRIG_A_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT7_AD_TRIG_B_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT8_CAPTURE_COMPARE_A_IRQHandler    (void) __attribute__((weak, alias("Default_Handler")));
void GPT8_CAPTURE_COMPARE_B_IRQHandler    (void) __attribute__((weak, alias("Default_Handler")));
void GPT8_COMPARE_C_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT8_COMPARE_D_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT8_COMPARE_E_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT8_COMPARE_F_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT8_COUNTER_OVERFLOW_IRQHandler     (void) __attribute__((weak, alias("Default_Handler")));
void GPT8_COUNTER_UNDERFLOW_IRQHandler    (void) __attribute__((weak, alias("Default_Handler")));
void GPT9_CAPTURE_COMPARE_A_IRQHandler    (void) __attribute__((weak, alias("Default_Handler")));
void GPT9_CAPTURE_COMPARE_B_IRQHandler    (void) __attribute__((weak, alias("Default_Handler")));
void GPT9_COMPARE_C_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT9_COMPARE_D_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT9_COMPARE_E_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT9_COMPARE_F_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void GPT9_COUNTER_OVERFLOW_IRQHandler     (void) __attribute__((weak, alias("Default_Handler")));
void GPT9_COUNTER_UNDERFLOW_IRQHandler    (void) __attribute__((weak, alias("Default_Handler")));
void GPT10_CAPTURE_COMPARE_A_IRQHandler   (void) __attribute__((weak, alias("Default_Handler")));
void GPT10_CAPTURE_COMPARE_B_IRQHandler   (void) __attribute__((weak, alias("Default_Handler")));
void GPT10_COMPARE_C_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void GPT10_COMPARE_D_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void GPT10_COMPARE_E_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void GPT10_COMPARE_F_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void GPT10_COUNTER_OVERFLOW_IRQHandler    (void) __attribute__((weak, alias("Default_Handler")));
void GPT10_COUNTER_UNDERFLOW_IRQHandler   (void) __attribute__((weak, alias("Default_Handler")));
void GPT11_CAPTURE_COMPARE_A_IRQHandler   (void) __attribute__((weak, alias("Default_Handler")));
void GPT11_CAPTURE_COMPARE_B_IRQHandler   (void) __attribute__((weak, alias("Default_Handler")));
void GPT11_COMPARE_C_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void GPT11_COMPARE_D_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void GPT11_COMPARE_E_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void GPT11_COMPARE_F_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void GPT11_COUNTER_OVERFLOW_IRQHandler    (void) __attribute__((weak, alias("Default_Handler")));
void GPT11_COUNTER_UNDERFLOW_IRQHandler   (void) __attribute__((weak, alias("Default_Handler")));
void GPT12_CAPTURE_COMPARE_A_IRQHandler   (void) __attribute__((weak, alias("Default_Handler")));
void GPT12_CAPTURE_COMPARE_B_IRQHandler   (void) __attribute__((weak, alias("Default_Handler")));
void GPT12_COMPARE_C_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void GPT12_COMPARE_D_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void GPT12_COMPARE_E_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void GPT12_COMPARE_F_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void GPT12_COUNTER_OVERFLOW_IRQHandler    (void) __attribute__((weak, alias("Default_Handler")));
void GPT12_COUNTER_UNDERFLOW_IRQHandler   (void) __attribute__((weak, alias("Default_Handler")));
void GPT13_CAPTURE_COMPARE_A_IRQHandler   (void) __attribute__((weak, alias("Default_Handler")));
void GPT13_CAPTURE_COMPARE_B_IRQHandler   (void) __attribute__((weak, alias("Default_Handler")));
void GPT13_COMPARE_C_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void GPT13_COMPARE_D_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void GPT13_COMPARE_E_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void GPT13_COMPARE_F_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void GPT13_COUNTER_OVERFLOW_IRQHandler    (void) __attribute__((weak, alias("Default_Handler")));
void GPT13_COUNTER_UNDERFLOW_IRQHandler   (void) __attribute__((weak, alias("Default_Handler")));
void OPS_UVW_EDGE_IRQHandler              (void) __attribute__((weak, alias("Default_Handler")));
void EPTPC_IPLS_IRQHandler                (void) __attribute__((weak, alias("Default_Handler")));
void EPTPC_MINT_IRQHandler                (void) __attribute__((weak, alias("Default_Handler")));
void EPTPC_PINT_IRQHandler                (void) __attribute__((weak, alias("Default_Handler")));
void EDMAC0_EINT_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void EDMAC1_EINT_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void EPTPC_TIMER0_RISE_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void EPTPC_TIMER1_RISE_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void EPTPC_TIMER2_RISE_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void EPTPC_TIMER3_RISE_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void EPTPC_TIMER4_RISE_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void EPTPC_TIMER5_RISE_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void EPTPC_TIMER0_FALL_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void EPTPC_TIMER1_FALL_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void EPTPC_TIMER2_FALL_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void EPTPC_TIMER3_FALL_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void EPTPC_TIMER4_FALL_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void EPTPC_TIMER5_FALL_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void USBHS_FIFO_0_IRQHandler              (void) __attribute__((weak, alias("Default_Handler")));
void USBHS_FIFO_1_IRQHandler              (void) __attribute__((weak, alias("Default_Handler")));
void USBHS_USB_INT_RESUME_IRQHandler      (void) __attribute__((weak, alias("Default_Handler")));
void SCI0_RXI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SCI0_TXI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SCI0_TEI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SCI0_ERI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SCI0_AM_IRQHandler                   (void) __attribute__((weak, alias("Default_Handler")));
void SCI0_RXI_OR_ERI_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void SCI1_RXI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SCI1_TXI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SCI1_TEI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SCI1_ERI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SCI1_AM_IRQHandler                   (void) __attribute__((weak, alias("Default_Handler")));
void SCI2_RXI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SCI2_TXI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SCI2_TEI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SCI2_ERI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SCI2_AM_IRQHandler                   (void) __attribute__((weak, alias("Default_Handler")));
void SCI3_RXI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SCI3_TXI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SCI3_TEI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SCI3_ERI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SCI3_AM_IRQHandler                   (void) __attribute__((weak, alias("Default_Handler")));
void SCI4_RXI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SCI4_TXI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SCI4_TEI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SCI4_ERI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SCI4_AM_IRQHandler                   (void) __attribute__((weak, alias("Default_Handler")));
void SCI5_RXI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SCI5_TXI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SCI5_TEI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SCI5_ERI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SCI5_AM_IRQHandler                   (void) __attribute__((weak, alias("Default_Handler")));
void SCI6_RXI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SCI6_TXI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SCI6_TEI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SCI6_ERI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SCI6_AM_IRQHandler                   (void) __attribute__((weak, alias("Default_Handler")));
void SCI7_RXI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SCI7_TXI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SCI7_TEI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SCI7_ERI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SCI7_AM_IRQHandler                   (void) __attribute__((weak, alias("Default_Handler")));
void SCI8_RXI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SCI8_TXI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SCI8_TEI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SCI8_ERI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SCI8_AM_IRQHandler                   (void) __attribute__((weak, alias("Default_Handler")));
void SCI9_RXI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SCI9_TXI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SCI9_TEI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SCI9_ERI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SCI9_AM_IRQHandler                   (void) __attribute__((weak, alias("Default_Handler")));
void SPI0_RXI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SPI0_TXI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SPI0_IDLE_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler")));
void SPI0_ERI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SPI0_TEI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SPI1_RXI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SPI1_TXI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SPI1_IDLE_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler")));
void SPI1_ERI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SPI1_TEI_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void QSPI_INT_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SDHIMMC0_ACCS_IRQHandler             (void) __attribute__((weak, alias("Default_Handler")));
void SDHIMMC0_SDIO_IRQHandler             (void) __attribute__((weak, alias("Default_Handler")));
void SDHIMMC0_CARD_IRQHandler             (void) __attribute__((weak, alias("Default_Handler")));
void SDHIMMC0_DMA_REQ_IRQHandler          (void) __attribute__((weak, alias("Default_Handler")));
void SDHIMMC1_ACCS_IRQHandler             (void) __attribute__((weak, alias("Default_Handler")));
void SDHIMMC1_SDIO_IRQHandler             (void) __attribute__((weak, alias("Default_Handler")));
void SDHIMMC1_CARD_IRQHandler             (void) __attribute__((weak, alias("Default_Handler")));
void SDHIMMC1_DMA_REQ_IRQHandler          (void) __attribute__((weak, alias("Default_Handler")));
void SCE_PROC_BUSY_IRQHandler             (void) __attribute__((weak, alias("Default_Handler")));
void SCE_ROMOK_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler")));
void SCE_LONG_PLG_IRQHandler              (void) __attribute__((weak, alias("Default_Handler")));
void SCE_TEST_BUSY_IRQHandler             (void) __attribute__((weak, alias("Default_Handler")));
void SCE_WRRDY_0_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void SCE_WRRDY_1_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void SCE_WRRDY_4_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void SCE_RDRDY_0_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void SCE_RDRDY_1_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void SCE_INTEGRATE_WRRDY_IRQHandler       (void) __attribute__((weak, alias("Default_Handler")));
void SCE_INTEGRATE_RDRDY_IRQHandler       (void) __attribute__((weak, alias("Default_Handler")));
void GLCDC_LINE_DETECT_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void GLCDC_UNDERFLOW_1_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void GLCDC_UNDERFLOW_2_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void DRW_INT_IRQHandler                   (void) __attribute__((weak, alias("Default_Handler")));
void JPEG_JEDI_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler")));
void JPEG_JDTI_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler")));

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
#if (BSP_IRQ_CFG_ICU_IRQ10 != BSP_IRQ_DISABLED)
   (uint32_t) ICU_IRQ10_IRQHandler,
#endif
#if (BSP_IRQ_CFG_ICU_IRQ11 != BSP_IRQ_DISABLED)
   (uint32_t) ICU_IRQ11_IRQHandler,
#endif
#if (BSP_IRQ_CFG_ICU_IRQ12 != BSP_IRQ_DISABLED)
   (uint32_t) ICU_IRQ12_IRQHandler,
#endif
#if (BSP_IRQ_CFG_ICU_IRQ13 != BSP_IRQ_DISABLED)
   (uint32_t) ICU_IRQ13_IRQHandler,
#endif
#if (BSP_IRQ_CFG_ICU_IRQ14 != BSP_IRQ_DISABLED)
   (uint32_t) ICU_IRQ14_IRQHandler,
#endif
#if (BSP_IRQ_CFG_ICU_IRQ15 != BSP_IRQ_DISABLED)
   (uint32_t) ICU_IRQ15_IRQHandler,
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
#if (BSP_IRQ_CFG_ADC1_SCAN_END != BSP_IRQ_DISABLED)
   (uint32_t) ADC1_SCAN_END_IRQHandler,
#endif
#if (BSP_IRQ_CFG_ADC1_SCAN_END_B != BSP_IRQ_DISABLED)
   (uint32_t) ADC1_SCAN_END_B_IRQHandler,
#endif
#if (BSP_IRQ_CFG_ADC1_WINDOW_A != BSP_IRQ_DISABLED)
   (uint32_t) ADC1_WINDOW_A_IRQHandler,
#endif
#if (BSP_IRQ_CFG_ADC1_WINDOW_B != BSP_IRQ_DISABLED)
   (uint32_t) ADC1_WINDOW_B_IRQHandler,
#endif
#if (BSP_IRQ_CFG_ADC1_COMPARE_MATCH != BSP_IRQ_DISABLED)
   (uint32_t) ADC1_COMPARE_MATCH_IRQHandler,
#endif
#if (BSP_IRQ_CFG_ADC1_COMPARE_MISMATCH != BSP_IRQ_DISABLED)
   (uint32_t) ADC1_COMPARE_MISMATCH_IRQHandler,
#endif
#if (BSP_IRQ_CFG_COMP_HS_0 != BSP_IRQ_DISABLED)
   (uint32_t) COMP_HS_0_IRQHandler,
#endif
#if (BSP_IRQ_CFG_COMP_HS0_INT != BSP_IRQ_DISABLED)
   (uint32_t) COMP_HS0_INT_IRQHandler,
#endif
#if (BSP_IRQ_CFG_COMP_HS_1 != BSP_IRQ_DISABLED)
   (uint32_t) COMP_HS_1_IRQHandler,
#endif
#if (BSP_IRQ_CFG_COMP_HS1_INT != BSP_IRQ_DISABLED)
   (uint32_t) COMP_HS1_INT_IRQHandler,
#endif
#if (BSP_IRQ_CFG_COMP_HS_2 != BSP_IRQ_DISABLED)
   (uint32_t) COMP_HS_2_IRQHandler,
#endif
#if (BSP_IRQ_CFG_COMP_HS2_INT != BSP_IRQ_DISABLED)
   (uint32_t) COMP_HS2_INT_IRQHandler,
#endif
#if (BSP_IRQ_CFG_COMP_HS_3 != BSP_IRQ_DISABLED)
   (uint32_t) COMP_HS_3_IRQHandler,
#endif
#if (BSP_IRQ_CFG_COMP_HS3_INT != BSP_IRQ_DISABLED)
   (uint32_t) COMP_HS3_INT_IRQHandler,
#endif
#if (BSP_IRQ_CFG_COMP_HS_4 != BSP_IRQ_DISABLED)
   (uint32_t) COMP_HS_4_IRQHandler,
#endif
#if (BSP_IRQ_CFG_COMP_HS4_INT != BSP_IRQ_DISABLED)
   (uint32_t) COMP_HS4_INT_IRQHandler,
#endif
#if (BSP_IRQ_CFG_COMP_HS_5 != BSP_IRQ_DISABLED)
   (uint32_t) COMP_HS_5_IRQHandler,
#endif
#if (BSP_IRQ_CFG_COMP_HS5_INT != BSP_IRQ_DISABLED)
   (uint32_t) COMP_HS5_INT_IRQHandler,
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
#if (BSP_IRQ_CFG_IIC1_RXI != BSP_IRQ_DISABLED)
   (uint32_t) IIC1_RXI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_IIC1_TXI != BSP_IRQ_DISABLED)
   (uint32_t) IIC1_TXI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_IIC1_TEI != BSP_IRQ_DISABLED)
   (uint32_t) IIC1_TEI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_IIC1_ERI != BSP_IRQ_DISABLED)
   (uint32_t) IIC1_ERI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_IIC2_RXI != BSP_IRQ_DISABLED)
   (uint32_t) IIC2_RXI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_IIC2_TXI != BSP_IRQ_DISABLED)
   (uint32_t) IIC2_TXI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_IIC2_TEI != BSP_IRQ_DISABLED)
   (uint32_t) IIC2_TEI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_IIC2_ERI != BSP_IRQ_DISABLED)
   (uint32_t) IIC2_ERI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SSI0_TXI != BSP_IRQ_DISABLED)
   (uint32_t) SSI0_TXI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SSI0_RXI != BSP_IRQ_DISABLED)
   (uint32_t) SSI0_RXI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SSI0_INT != BSP_IRQ_DISABLED)
   (uint32_t) SSI0_INT_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SSI1_TXI_RXI != BSP_IRQ_DISABLED)
   (uint32_t) SSI1_TXI_RXI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SSI1_INT != BSP_IRQ_DISABLED)
   (uint32_t) SSI1_INT_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SRC_INPUT_FIFO_EMPTY != BSP_IRQ_DISABLED)
   (uint32_t) SRC_INPUT_FIFO_EMPTY_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SRC_OUTPUT_FIFO_FULL != BSP_IRQ_DISABLED)
   (uint32_t) SRC_OUTPUT_FIFO_FULL_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SRC_OUTPUT_FIFO_OVERFLOW != BSP_IRQ_DISABLED)
   (uint32_t) SRC_OUTPUT_FIFO_OVERFLOW_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SRC_OUTPUT_FIFO_UNDERFLOW != BSP_IRQ_DISABLED)
   (uint32_t) SRC_OUTPUT_FIFO_UNDERFLOW_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SRC_CONVERSION_END != BSP_IRQ_DISABLED)
   (uint32_t) SRC_CONVERSION_END_IRQHandler,
#endif
#if (BSP_IRQ_CFG_PDC_RECEIVE_DATA_READY != BSP_IRQ_DISABLED)
   (uint32_t) PDC_RECEIVE_DATA_READY_IRQHandler,
#endif
#if (BSP_IRQ_CFG_PDC_FRAME_END != BSP_IRQ_DISABLED)
   (uint32_t) PDC_FRAME_END_IRQHandler,
#endif
#if (BSP_IRQ_CFG_PDC_INT != BSP_IRQ_DISABLED)
   (uint32_t) PDC_INT_IRQHandler,
#endif
#if (BSP_IRQ_CFG_CTSU_WRITE != BSP_IRQ_DISABLED)
   (uint32_t) CTSU_WRITE_IRQHandler,
#endif
#if (BSP_IRQ_CFG_CTSU_READ != BSP_IRQ_DISABLED)
   (uint32_t) CTSU_READ_IRQHandler,
#endif
#if (BSP_IRQ_CFG_CTSU_END != BSP_IRQ_DISABLED)
   (uint32_t) CTSU_END_IRQHandler,
#endif
#if (BSP_IRQ_CFG_KEY_INT != BSP_IRQ_DISABLED)
   (uint32_t) KEY_INT_IRQHandler,
#endif
#if (BSP_IRQ_CFG_DOC_INT != BSP_IRQ_DISABLED)
   (uint32_t) DOC_INT_IRQHandler,
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
#if (BSP_IRQ_CFG_CAN1_ERROR != BSP_IRQ_DISABLED)
   (uint32_t) CAN1_ERROR_IRQHandler,
#endif
#if (BSP_IRQ_CFG_CAN1_FIFO_RX != BSP_IRQ_DISABLED)
   (uint32_t) CAN1_FIFO_RX_IRQHandler,
#endif
#if (BSP_IRQ_CFG_CAN1_FIFO_TX != BSP_IRQ_DISABLED)
   (uint32_t) CAN1_FIFO_TX_IRQHandler,
#endif
#if (BSP_IRQ_CFG_CAN1_MAILBOX_RX != BSP_IRQ_DISABLED)
   (uint32_t) CAN1_MAILBOX_RX_IRQHandler,
#endif
#if (BSP_IRQ_CFG_CAN1_MAILBOX_TX != BSP_IRQ_DISABLED)
   (uint32_t) CAN1_MAILBOX_TX_IRQHandler,
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
#if (BSP_IRQ_CFG_GPT0_CAPTURE_COMPARE_A != BSP_IRQ_DISABLED)
   (uint32_t) GPT0_CAPTURE_COMPARE_A_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT0_CAPTURE_COMPARE_B != BSP_IRQ_DISABLED)
   (uint32_t) GPT0_CAPTURE_COMPARE_B_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT0_COMPARE_C != BSP_IRQ_DISABLED)
   (uint32_t) GPT0_COMPARE_C_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT0_COMPARE_D != BSP_IRQ_DISABLED)
   (uint32_t) GPT0_COMPARE_D_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT0_COMPARE_E != BSP_IRQ_DISABLED)
   (uint32_t) GPT0_COMPARE_E_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT0_COMPARE_F != BSP_IRQ_DISABLED)
   (uint32_t) GPT0_COMPARE_F_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT0_COUNTER_OVERFLOW != BSP_IRQ_DISABLED)
   (uint32_t) GPT0_COUNTER_OVERFLOW_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT0_COUNTER_UNDERFLOW != BSP_IRQ_DISABLED)
   (uint32_t) GPT0_COUNTER_UNDERFLOW_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT0_AD_TRIG_A != BSP_IRQ_DISABLED)
   (uint32_t) GPT0_AD_TRIG_A_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT0_AD_TRIG_B != BSP_IRQ_DISABLED)
   (uint32_t) GPT0_AD_TRIG_B_IRQHandler,
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
#if (BSP_IRQ_CFG_GPT1_AD_TRIG_A != BSP_IRQ_DISABLED)
   (uint32_t) GPT1_AD_TRIG_A_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT1_AD_TRIG_B != BSP_IRQ_DISABLED)
   (uint32_t) GPT1_AD_TRIG_B_IRQHandler,
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
#if (BSP_IRQ_CFG_GPT2_AD_TRIG_A != BSP_IRQ_DISABLED)
   (uint32_t) GPT2_AD_TRIG_A_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT2_AD_TRIG_B != BSP_IRQ_DISABLED)
   (uint32_t) GPT2_AD_TRIG_B_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT3_CAPTURE_COMPARE_A != BSP_IRQ_DISABLED)
   (uint32_t) GPT3_CAPTURE_COMPARE_A_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT3_CAPTURE_COMPARE_B != BSP_IRQ_DISABLED)
   (uint32_t) GPT3_CAPTURE_COMPARE_B_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT3_COMPARE_C != BSP_IRQ_DISABLED)
   (uint32_t) GPT3_COMPARE_C_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT3_COMPARE_D != BSP_IRQ_DISABLED)
   (uint32_t) GPT3_COMPARE_D_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT3_COMPARE_E != BSP_IRQ_DISABLED)
   (uint32_t) GPT3_COMPARE_E_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT3_COMPARE_F != BSP_IRQ_DISABLED)
   (uint32_t) GPT3_COMPARE_F_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT3_COUNTER_OVERFLOW != BSP_IRQ_DISABLED)
   (uint32_t) GPT3_COUNTER_OVERFLOW_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT3_COUNTER_UNDERFLOW != BSP_IRQ_DISABLED)
   (uint32_t) GPT3_COUNTER_UNDERFLOW_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT3_AD_TRIG_A != BSP_IRQ_DISABLED)
   (uint32_t) GPT3_AD_TRIG_A_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT3_AD_TRIG_B != BSP_IRQ_DISABLED)
   (uint32_t) GPT3_AD_TRIG_B_IRQHandler,
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
#if (BSP_IRQ_CFG_GPT4_AD_TRIG_A != BSP_IRQ_DISABLED)
   (uint32_t) GPT4_AD_TRIG_A_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT4_AD_TRIG_B != BSP_IRQ_DISABLED)
   (uint32_t) GPT4_AD_TRIG_B_IRQHandler,
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
#if (BSP_IRQ_CFG_GPT5_AD_TRIG_A != BSP_IRQ_DISABLED)
   (uint32_t) GPT5_AD_TRIG_A_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT5_AD_TRIG_B != BSP_IRQ_DISABLED)
   (uint32_t) GPT5_AD_TRIG_B_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT6_CAPTURE_COMPARE_A != BSP_IRQ_DISABLED)
   (uint32_t) GPT6_CAPTURE_COMPARE_A_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT6_CAPTURE_COMPARE_B != BSP_IRQ_DISABLED)
   (uint32_t) GPT6_CAPTURE_COMPARE_B_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT6_COMPARE_C != BSP_IRQ_DISABLED)
   (uint32_t) GPT6_COMPARE_C_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT6_COMPARE_D != BSP_IRQ_DISABLED)
   (uint32_t) GPT6_COMPARE_D_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT6_COMPARE_E != BSP_IRQ_DISABLED)
   (uint32_t) GPT6_COMPARE_E_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT6_COMPARE_F != BSP_IRQ_DISABLED)
   (uint32_t) GPT6_COMPARE_F_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT6_COUNTER_OVERFLOW != BSP_IRQ_DISABLED)
   (uint32_t) GPT6_COUNTER_OVERFLOW_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT6_COUNTER_UNDERFLOW != BSP_IRQ_DISABLED)
   (uint32_t) GPT6_COUNTER_UNDERFLOW_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT6_AD_TRIG_A != BSP_IRQ_DISABLED)
   (uint32_t) GPT6_AD_TRIG_A_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT6_AD_TRIG_B != BSP_IRQ_DISABLED)
   (uint32_t) GPT6_AD_TRIG_B_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT7_CAPTURE_COMPARE_A != BSP_IRQ_DISABLED)
   (uint32_t) GPT7_CAPTURE_COMPARE_A_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT7_CAPTURE_COMPARE_B != BSP_IRQ_DISABLED)
   (uint32_t) GPT7_CAPTURE_COMPARE_B_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT7_COMPARE_C != BSP_IRQ_DISABLED)
   (uint32_t) GPT7_COMPARE_C_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT7_COMPARE_D != BSP_IRQ_DISABLED)
   (uint32_t) GPT7_COMPARE_D_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT7_COMPARE_E != BSP_IRQ_DISABLED)
   (uint32_t) GPT7_COMPARE_E_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT7_COMPARE_F != BSP_IRQ_DISABLED)
   (uint32_t) GPT7_COMPARE_F_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT7_COUNTER_OVERFLOW != BSP_IRQ_DISABLED)
   (uint32_t) GPT7_COUNTER_OVERFLOW_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT7_COUNTER_UNDERFLOW != BSP_IRQ_DISABLED)
   (uint32_t) GPT7_COUNTER_UNDERFLOW_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT7_AD_TRIG_A != BSP_IRQ_DISABLED)
   (uint32_t) GPT7_AD_TRIG_A_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT7_AD_TRIG_B != BSP_IRQ_DISABLED)
   (uint32_t) GPT7_AD_TRIG_B_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT8_CAPTURE_COMPARE_A != BSP_IRQ_DISABLED)
   (uint32_t) GPT8_CAPTURE_COMPARE_A_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT8_CAPTURE_COMPARE_B != BSP_IRQ_DISABLED)
   (uint32_t) GPT8_CAPTURE_COMPARE_B_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT8_COMPARE_C != BSP_IRQ_DISABLED)
   (uint32_t) GPT8_COMPARE_C_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT8_COMPARE_D != BSP_IRQ_DISABLED)
   (uint32_t) GPT8_COMPARE_D_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT8_COMPARE_E != BSP_IRQ_DISABLED)
   (uint32_t) GPT8_COMPARE_E_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT8_COMPARE_F != BSP_IRQ_DISABLED)
   (uint32_t) GPT8_COMPARE_F_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT8_COUNTER_OVERFLOW != BSP_IRQ_DISABLED)
   (uint32_t) GPT8_COUNTER_OVERFLOW_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT8_COUNTER_UNDERFLOW != BSP_IRQ_DISABLED)
   (uint32_t) GPT8_COUNTER_UNDERFLOW_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT9_CAPTURE_COMPARE_A != BSP_IRQ_DISABLED)
   (uint32_t) GPT9_CAPTURE_COMPARE_A_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT9_CAPTURE_COMPARE_B != BSP_IRQ_DISABLED)
   (uint32_t) GPT9_CAPTURE_COMPARE_B_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT9_COMPARE_C != BSP_IRQ_DISABLED)
   (uint32_t) GPT9_COMPARE_C_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT9_COMPARE_D != BSP_IRQ_DISABLED)
   (uint32_t) GPT9_COMPARE_D_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT9_COMPARE_E != BSP_IRQ_DISABLED)
   (uint32_t) GPT9_COMPARE_E_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT9_COMPARE_F != BSP_IRQ_DISABLED)
   (uint32_t) GPT9_COMPARE_F_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT9_COUNTER_OVERFLOW != BSP_IRQ_DISABLED)
   (uint32_t) GPT9_COUNTER_OVERFLOW_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT9_COUNTER_UNDERFLOW != BSP_IRQ_DISABLED)
   (uint32_t) GPT9_COUNTER_UNDERFLOW_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT10_CAPTURE_COMPARE_A != BSP_IRQ_DISABLED)
   (uint32_t) GPT10_CAPTURE_COMPARE_A_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT10_CAPTURE_COMPARE_B != BSP_IRQ_DISABLED)
   (uint32_t) GPT10_CAPTURE_COMPARE_B_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT10_COMPARE_C != BSP_IRQ_DISABLED)
   (uint32_t) GPT10_COMPARE_C_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT10_COMPARE_D != BSP_IRQ_DISABLED)
   (uint32_t) GPT10_COMPARE_D_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT10_COMPARE_E != BSP_IRQ_DISABLED)
   (uint32_t) GPT10_COMPARE_E_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT10_COMPARE_F != BSP_IRQ_DISABLED)
   (uint32_t) GPT10_COMPARE_F_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT10_COUNTER_OVERFLOW != BSP_IRQ_DISABLED)
   (uint32_t) GPT10_COUNTER_OVERFLOW_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT10_COUNTER_UNDERFLOW != BSP_IRQ_DISABLED)
   (uint32_t) GPT10_COUNTER_UNDERFLOW_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT11_CAPTURE_COMPARE_A != BSP_IRQ_DISABLED)
   (uint32_t) GPT11_CAPTURE_COMPARE_A_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT11_CAPTURE_COMPARE_B != BSP_IRQ_DISABLED)
   (uint32_t) GPT11_CAPTURE_COMPARE_B_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT11_COMPARE_C != BSP_IRQ_DISABLED)
   (uint32_t) GPT11_COMPARE_C_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT11_COMPARE_D != BSP_IRQ_DISABLED)
   (uint32_t) GPT11_COMPARE_D_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT11_COMPARE_E != BSP_IRQ_DISABLED)
   (uint32_t) GPT11_COMPARE_E_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT11_COMPARE_F != BSP_IRQ_DISABLED)
   (uint32_t) GPT11_COMPARE_F_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT11_COUNTER_OVERFLOW != BSP_IRQ_DISABLED)
   (uint32_t) GPT11_COUNTER_OVERFLOW_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT11_COUNTER_UNDERFLOW != BSP_IRQ_DISABLED)
   (uint32_t) GPT11_COUNTER_UNDERFLOW_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT12_CAPTURE_COMPARE_A != BSP_IRQ_DISABLED)
   (uint32_t) GPT12_CAPTURE_COMPARE_A_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT12_CAPTURE_COMPARE_B != BSP_IRQ_DISABLED)
   (uint32_t) GPT12_CAPTURE_COMPARE_B_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT12_COMPARE_C != BSP_IRQ_DISABLED)
   (uint32_t) GPT12_COMPARE_C_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT12_COMPARE_D != BSP_IRQ_DISABLED)
   (uint32_t) GPT12_COMPARE_D_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT12_COMPARE_E != BSP_IRQ_DISABLED)
   (uint32_t) GPT12_COMPARE_E_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT12_COMPARE_F != BSP_IRQ_DISABLED)
   (uint32_t) GPT12_COMPARE_F_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT12_COUNTER_OVERFLOW != BSP_IRQ_DISABLED)
   (uint32_t) GPT12_COUNTER_OVERFLOW_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT12_COUNTER_UNDERFLOW != BSP_IRQ_DISABLED)
   (uint32_t) GPT12_COUNTER_UNDERFLOW_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT13_CAPTURE_COMPARE_A != BSP_IRQ_DISABLED)
   (uint32_t) GPT13_CAPTURE_COMPARE_A_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT13_CAPTURE_COMPARE_B != BSP_IRQ_DISABLED)
   (uint32_t) GPT13_CAPTURE_COMPARE_B_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT13_COMPARE_C != BSP_IRQ_DISABLED)
   (uint32_t) GPT13_COMPARE_C_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT13_COMPARE_D != BSP_IRQ_DISABLED)
   (uint32_t) GPT13_COMPARE_D_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT13_COMPARE_E != BSP_IRQ_DISABLED)
   (uint32_t) GPT13_COMPARE_E_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT13_COMPARE_F != BSP_IRQ_DISABLED)
   (uint32_t) GPT13_COMPARE_F_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT13_COUNTER_OVERFLOW != BSP_IRQ_DISABLED)
   (uint32_t) GPT13_COUNTER_OVERFLOW_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GPT13_COUNTER_UNDERFLOW != BSP_IRQ_DISABLED)
   (uint32_t) GPT13_COUNTER_UNDERFLOW_IRQHandler,
#endif
#if (BSP_IRQ_CFG_OPS_UVW_EDGE != BSP_IRQ_DISABLED)
   (uint32_t) OPS_UVW_EDGE_IRQHandler,
#endif
#if (BSP_IRQ_CFG_EPTPC_IPLS != BSP_IRQ_DISABLED)
   (uint32_t) EPTPC_IPLS_IRQHandler,
#endif
#if (BSP_IRQ_CFG_EPTPC_MINT != BSP_IRQ_DISABLED)
   (uint32_t) EPTPC_MINT_IRQHandler,
#endif
#if (BSP_IRQ_CFG_EPTPC_PINT != BSP_IRQ_DISABLED)
   (uint32_t) EPTPC_PINT_IRQHandler,
#endif
#if (BSP_IRQ_CFG_EDMAC0_EINT != BSP_IRQ_DISABLED)
   (uint32_t) EDMAC0_EINT_IRQHandler,
#endif
#if (BSP_IRQ_CFG_EDMAC1_EINT != BSP_IRQ_DISABLED)
   (uint32_t) EDMAC1_EINT_IRQHandler,
#endif
#if (BSP_IRQ_CFG_EPTPC_TIMER0_RISE != BSP_IRQ_DISABLED)
   (uint32_t) EPTPC_TIMER0_RISE_IRQHandler,
#endif
#if (BSP_IRQ_CFG_EPTPC_TIMER1_RISE != BSP_IRQ_DISABLED)
   (uint32_t) EPTPC_TIMER1_RISE_IRQHandler,
#endif
#if (BSP_IRQ_CFG_EPTPC_TIMER2_RISE != BSP_IRQ_DISABLED)
   (uint32_t) EPTPC_TIMER2_RISE_IRQHandler,
#endif
#if (BSP_IRQ_CFG_EPTPC_TIMER3_RISE != BSP_IRQ_DISABLED)
   (uint32_t) EPTPC_TIMER3_RISE_IRQHandler,
#endif
#if (BSP_IRQ_CFG_EPTPC_TIMER4_RISE != BSP_IRQ_DISABLED)
   (uint32_t) EPTPC_TIMER4_RISE_IRQHandler,
#endif
#if (BSP_IRQ_CFG_EPTPC_TIMER5_RISE != BSP_IRQ_DISABLED)
   (uint32_t) EPTPC_TIMER5_RISE_IRQHandler,
#endif
#if (BSP_IRQ_CFG_EPTPC_TIMER0_FALL != BSP_IRQ_DISABLED)
   (uint32_t) EPTPC_TIMER0_FALL_IRQHandler,
#endif
#if (BSP_IRQ_CFG_EPTPC_TIMER1_FALL != BSP_IRQ_DISABLED)
   (uint32_t) EPTPC_TIMER1_FALL_IRQHandler,
#endif
#if (BSP_IRQ_CFG_EPTPC_TIMER2_FALL != BSP_IRQ_DISABLED)
   (uint32_t) EPTPC_TIMER2_FALL_IRQHandler,
#endif
#if (BSP_IRQ_CFG_EPTPC_TIMER3_FALL != BSP_IRQ_DISABLED)
   (uint32_t) EPTPC_TIMER3_FALL_IRQHandler,
#endif
#if (BSP_IRQ_CFG_EPTPC_TIMER4_FALL != BSP_IRQ_DISABLED)
   (uint32_t) EPTPC_TIMER4_FALL_IRQHandler,
#endif
#if (BSP_IRQ_CFG_EPTPC_TIMER5_FALL != BSP_IRQ_DISABLED)
   (uint32_t) EPTPC_TIMER5_FALL_IRQHandler,
#endif
#if (BSP_IRQ_CFG_USBHS_FIFO_0 != BSP_IRQ_DISABLED)
   (uint32_t) USBHS_FIFO_0_IRQHandler,
#endif
#if (BSP_IRQ_CFG_USBHS_FIFO_1 != BSP_IRQ_DISABLED)
   (uint32_t) USBHS_FIFO_1_IRQHandler,
#endif
#if (BSP_IRQ_CFG_USBHS_USB_INT_RESUME != BSP_IRQ_DISABLED)
   (uint32_t) USBHS_USB_INT_RESUME_IRQHandler,
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
#if (BSP_IRQ_CFG_SCI1_RXI != BSP_IRQ_DISABLED)
   (uint32_t) SCI1_RXI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCI1_TXI != BSP_IRQ_DISABLED)
   (uint32_t) SCI1_TXI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCI1_TEI != BSP_IRQ_DISABLED)
   (uint32_t) SCI1_TEI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCI1_ERI != BSP_IRQ_DISABLED)
   (uint32_t) SCI1_ERI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCI1_AM != BSP_IRQ_DISABLED)
   (uint32_t) SCI1_AM_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCI2_RXI != BSP_IRQ_DISABLED)
   (uint32_t) SCI2_RXI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCI2_TXI != BSP_IRQ_DISABLED)
   (uint32_t) SCI2_TXI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCI2_TEI != BSP_IRQ_DISABLED)
   (uint32_t) SCI2_TEI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCI2_ERI != BSP_IRQ_DISABLED)
   (uint32_t) SCI2_ERI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCI2_AM != BSP_IRQ_DISABLED)
   (uint32_t) SCI2_AM_IRQHandler,
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
#if (BSP_IRQ_CFG_SCI5_RXI != BSP_IRQ_DISABLED)
   (uint32_t) SCI5_RXI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCI5_TXI != BSP_IRQ_DISABLED)
   (uint32_t) SCI5_TXI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCI5_TEI != BSP_IRQ_DISABLED)
   (uint32_t) SCI5_TEI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCI5_ERI != BSP_IRQ_DISABLED)
   (uint32_t) SCI5_ERI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCI5_AM != BSP_IRQ_DISABLED)
   (uint32_t) SCI5_AM_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCI6_RXI != BSP_IRQ_DISABLED)
   (uint32_t) SCI6_RXI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCI6_TXI != BSP_IRQ_DISABLED)
   (uint32_t) SCI6_TXI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCI6_TEI != BSP_IRQ_DISABLED)
   (uint32_t) SCI6_TEI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCI6_ERI != BSP_IRQ_DISABLED)
   (uint32_t) SCI6_ERI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCI6_AM != BSP_IRQ_DISABLED)
   (uint32_t) SCI6_AM_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCI7_RXI != BSP_IRQ_DISABLED)
   (uint32_t) SCI7_RXI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCI7_TXI != BSP_IRQ_DISABLED)
   (uint32_t) SCI7_TXI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCI7_TEI != BSP_IRQ_DISABLED)
   (uint32_t) SCI7_TEI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCI7_ERI != BSP_IRQ_DISABLED)
   (uint32_t) SCI7_ERI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCI7_AM != BSP_IRQ_DISABLED)
   (uint32_t) SCI7_AM_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCI8_RXI != BSP_IRQ_DISABLED)
   (uint32_t) SCI8_RXI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCI8_TXI != BSP_IRQ_DISABLED)
   (uint32_t) SCI8_TXI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCI8_TEI != BSP_IRQ_DISABLED)
   (uint32_t) SCI8_TEI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCI8_ERI != BSP_IRQ_DISABLED)
   (uint32_t) SCI8_ERI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCI8_AM != BSP_IRQ_DISABLED)
   (uint32_t) SCI8_AM_IRQHandler,
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
#if (BSP_IRQ_CFG_SPI1_RXI != BSP_IRQ_DISABLED)
   (uint32_t) SPI1_RXI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SPI1_TXI != BSP_IRQ_DISABLED)
   (uint32_t) SPI1_TXI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SPI1_IDLE != BSP_IRQ_DISABLED)
   (uint32_t) SPI1_IDLE_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SPI1_ERI != BSP_IRQ_DISABLED)
   (uint32_t) SPI1_ERI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SPI1_TEI != BSP_IRQ_DISABLED)
   (uint32_t) SPI1_TEI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_QSPI_INT != BSP_IRQ_DISABLED)
   (uint32_t) QSPI_INT_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SDHIMMC0_ACCS != BSP_IRQ_DISABLED)
   (uint32_t) SDHIMMC0_ACCS_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SDHIMMC0_SDIO != BSP_IRQ_DISABLED)
   (uint32_t) SDHIMMC0_SDIO_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SDHIMMC0_CARD != BSP_IRQ_DISABLED)
   (uint32_t) SDHIMMC0_CARD_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SDHIMMC0_DMA_REQ != BSP_IRQ_DISABLED)
   (uint32_t) SDHIMMC0_DMA_REQ_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SDHIMMC1_ACCS != BSP_IRQ_DISABLED)
   (uint32_t) SDHIMMC1_ACCS_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SDHIMMC1_SDIO != BSP_IRQ_DISABLED)
   (uint32_t) SDHIMMC1_SDIO_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SDHIMMC1_CARD != BSP_IRQ_DISABLED)
   (uint32_t) SDHIMMC1_CARD_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SDHIMMC1_DMA_REQ != BSP_IRQ_DISABLED)
   (uint32_t) SDHIMMC1_DMA_REQ_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCE_PROC_BUSY != BSP_IRQ_DISABLED)
   (uint32_t) SCE_PROC_BUSY_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCE_ROMOK != BSP_IRQ_DISABLED)
   (uint32_t) SCE_ROMOK_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCE_LONG_PLG != BSP_IRQ_DISABLED)
   (uint32_t) SCE_LONG_PLG_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCE_TEST_BUSY != BSP_IRQ_DISABLED)
   (uint32_t) SCE_TEST_BUSY_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCE_WRRDY_0 != BSP_IRQ_DISABLED)
   (uint32_t) SCE_WRRDY_0_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCE_WRRDY_1 != BSP_IRQ_DISABLED)
   (uint32_t) SCE_WRRDY_1_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCE_WRRDY_4 != BSP_IRQ_DISABLED)
   (uint32_t) SCE_WRRDY_4_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCE_RDRDY_0 != BSP_IRQ_DISABLED)
   (uint32_t) SCE_RDRDY_0_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCE_RDRDY_1 != BSP_IRQ_DISABLED)
   (uint32_t) SCE_RDRDY_1_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCE_INTEGRATE_WRRDY != BSP_IRQ_DISABLED)
   (uint32_t) SCE_INTEGRATE_WRRDY_IRQHandler,
#endif
#if (BSP_IRQ_CFG_SCE_INTEGRATE_RDRDY != BSP_IRQ_DISABLED)
   (uint32_t) SCE_INTEGRATE_RDRDY_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GLCDC_LINE_DETECT != BSP_IRQ_DISABLED)
   (uint32_t) GLCDC_LINE_DETECT_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GLCDC_UNDERFLOW_1 != BSP_IRQ_DISABLED)
   (uint32_t) GLCDC_UNDERFLOW_1_IRQHandler,
#endif
#if (BSP_IRQ_CFG_GLCDC_UNDERFLOW_2 != BSP_IRQ_DISABLED)
   (uint32_t) GLCDC_UNDERFLOW_2_IRQHandler,
#endif
#if (BSP_IRQ_CFG_DRW_INT != BSP_IRQ_DISABLED)
   (uint32_t) DRW_INT_IRQHandler,
#endif
#if (BSP_IRQ_CFG_JPEG_JEDI != BSP_IRQ_DISABLED)
   (uint32_t) JPEG_JEDI_IRQHandler,
#endif
#if (BSP_IRQ_CFG_JPEG_JDTI != BSP_IRQ_DISABLED)
   (uint32_t) JPEG_JDTI_IRQHandler,
#endif
   [256] = 0xFFFFFFFF, //Option Function Select Register 0 (OFS0)
   [257] = 0xFFFFFDFF, //Option Function Select Register 1 (OFS1)
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
