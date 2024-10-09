#include "bsp_irq_cfg.h"

; Amount of memory (in bytes) allocated for Stack
; Tailor this value to your application needs
; <h> Stack Configuration
;   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Stack_Size      EQU     0x400;

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp


; <h> Heap Configuration
;   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

;Heap_Size      EQU     0x200;

;                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
;__heap_base
;Heap_Mem        SPACE   Heap_Size
;__heap_limit

                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset
                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors
                EXPORT  __Vectors_End
                EXPORT  __Vectors_Size
                EXPORT  __Options
                EXPORT  __Options_End
                EXPORT  __Options_Size

__Vectors       DCD     __initial_sp               ; Top of Stack
                DCD     Reset_Handler              ; Reset Handler
                DCD     NMI_Handler                ; NMI Handler
                DCD     HardFault_Handler          ; Hard Fault Handler
                DCD     MemManage_Handler          ; MPU Fault Handler
                DCD     BusFault_Handler           ; Bus Fault Handler
                DCD     UsageFault_Handler         ; Usage Fault Handler
                DCD     0                          ; Reserved
                DCD     0                          ; Reserved
                DCD     0                          ; Reserved
                DCD     0                          ; Reserved
                DCD     SVC_Handler                ; SVCall Handler
                DCD     DebugMon_Handler           ; Debug Monitor Handler
                DCD     0                          ; Reserved
                DCD     PendSV_Handler             ; PendSV Handler
                DCD     SysTick_Handler            ; SysTick Handler

                ; External Interrupts
                IF      BSP_IRQ_CFG_ICU_IRQ0 != BSP_IRQ_DISABLED
                DCD     ICU_IRQ0_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_ICU_IRQ1 != BSP_IRQ_DISABLED
                DCD     ICU_IRQ1_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_ICU_IRQ2 != BSP_IRQ_DISABLED
                DCD     ICU_IRQ2_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_ICU_IRQ3 != BSP_IRQ_DISABLED
                DCD     ICU_IRQ3_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_ICU_IRQ4 != BSP_IRQ_DISABLED
                DCD     ICU_IRQ4_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_ICU_IRQ5 != BSP_IRQ_DISABLED
                DCD     ICU_IRQ5_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_ICU_IRQ6 != BSP_IRQ_DISABLED
                DCD     ICU_IRQ6_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_ICU_IRQ7 != BSP_IRQ_DISABLED
                DCD     ICU_IRQ7_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_ICU_IRQ8 != BSP_IRQ_DISABLED
                DCD     ICU_IRQ8_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_ICU_IRQ9 != BSP_IRQ_DISABLED
                DCD     ICU_IRQ9_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_ICU_IRQ10 != BSP_IRQ_DISABLED
                DCD     ICU_IRQ10_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_ICU_IRQ11 != BSP_IRQ_DISABLED
                DCD     ICU_IRQ11_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_ICU_IRQ12 != BSP_IRQ_DISABLED
                DCD     ICU_IRQ12_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_ICU_IRQ13 != BSP_IRQ_DISABLED
                DCD     ICU_IRQ13_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_ICU_IRQ14 != BSP_IRQ_DISABLED
                DCD     ICU_IRQ14_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_ICU_IRQ15 != BSP_IRQ_DISABLED
                DCD     ICU_IRQ15_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_DMAC0_INT != BSP_IRQ_DISABLED
                DCD     DMAC0_INT_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_DMAC1_INT != BSP_IRQ_DISABLED
                DCD     DMAC1_INT_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_DMAC2_INT != BSP_IRQ_DISABLED
                DCD     DMAC2_INT_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_DMAC3_INT != BSP_IRQ_DISABLED
                DCD     DMAC3_INT_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_DMAC4_INT != BSP_IRQ_DISABLED
                DCD     DMAC4_INT_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_DMAC5_INT != BSP_IRQ_DISABLED
                DCD     DMAC5_INT_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_DMAC6_INT != BSP_IRQ_DISABLED
                DCD     DMAC6_INT_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_DMAC7_INT != BSP_IRQ_DISABLED
                DCD     DMAC7_INT_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_DTC_COMPLETE != BSP_IRQ_DISABLED
                DCD     DTC_COMPLETE_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_DTC_END != BSP_IRQ_DISABLED
                DCD     DTC_END_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_ICU_SNOOZE_CANCEL != BSP_IRQ_DISABLED
                DCD     ICU_SNOOZE_CANCEL_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_FCU_FIFERR != BSP_IRQ_DISABLED
                DCD     FCU_FIFERR_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_FCU_FRDYI != BSP_IRQ_DISABLED
                DCD     FCU_FRDYI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_LVD_LVD1 != BSP_IRQ_DISABLED
                DCD     LVD_LVD1_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_LVD_LVD2 != BSP_IRQ_DISABLED
                DCD     LVD_LVD2_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_CGC_MOSC_STOP != BSP_IRQ_DISABLED
                DCD     CGC_MOSC_STOP_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_LPM_SNOOZE_REQUEST != BSP_IRQ_DISABLED
                DCD     LPM_SNOOZE_REQUEST_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_AGT0_INT != BSP_IRQ_DISABLED
                DCD     AGT0_INT_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_AGT0_COMPARE_A != BSP_IRQ_DISABLED
                DCD     AGT0_COMPARE_A_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_AGT0_COMPARE_B != BSP_IRQ_DISABLED
                DCD     AGT0_COMPARE_B_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_AGT1_INT != BSP_IRQ_DISABLED
                DCD     AGT1_INT_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_AGT1_COMPARE_A != BSP_IRQ_DISABLED
                DCD     AGT1_COMPARE_A_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_AGT1_COMPARE_B != BSP_IRQ_DISABLED
                DCD     AGT1_COMPARE_B_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_IWDT_UNDERFLOW != BSP_IRQ_DISABLED
                DCD     IWDT_UNDERFLOW_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_WDT_UNDERFLOW != BSP_IRQ_DISABLED
                DCD     WDT_UNDERFLOW_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_RTC_ALARM != BSP_IRQ_DISABLED
                DCD     RTC_ALARM_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_RTC_PERIOD != BSP_IRQ_DISABLED
                DCD     RTC_PERIOD_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_RTC_CARRY != BSP_IRQ_DISABLED
                DCD     RTC_CARRY_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_ADC0_SCAN_END != BSP_IRQ_DISABLED
                DCD     ADC0_SCAN_END_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_ADC0_SCAN_END_B != BSP_IRQ_DISABLED
                DCD     ADC0_SCAN_END_B_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_ADC0_WINDOW_A != BSP_IRQ_DISABLED
                DCD     ADC0_WINDOW_A_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_ADC0_WINDOW_B != BSP_IRQ_DISABLED
                DCD     ADC0_WINDOW_B_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_ADC0_COMPARE_MATCH != BSP_IRQ_DISABLED
                DCD     ADC0_COMPARE_MATCH_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_ADC0_COMPARE_MISMATCH != BSP_IRQ_DISABLED
                DCD     ADC0_COMPARE_MISMATCH_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_ADC1_SCAN_END != BSP_IRQ_DISABLED
                DCD     ADC1_SCAN_END_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_ADC1_SCAN_END_B != BSP_IRQ_DISABLED
                DCD     ADC1_SCAN_END_B_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_ADC1_WINDOW_A != BSP_IRQ_DISABLED
                DCD     ADC1_WINDOW_A_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_ADC1_WINDOW_B != BSP_IRQ_DISABLED
                DCD     ADC1_WINDOW_B_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_ADC1_COMPARE_MATCH != BSP_IRQ_DISABLED
                DCD     ADC1_COMPARE_MATCH_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_ADC1_COMPARE_MISMATCH != BSP_IRQ_DISABLED
                DCD     ADC1_COMPARE_MISMATCH_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_ACMPHS0_INT != BSP_IRQ_DISABLED
                DCD     ACMPHS0_INT_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_ACMPHS1_INT != BSP_IRQ_DISABLED
                DCD     ACMPHS1_INT_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_ACMPHS2_INT != BSP_IRQ_DISABLED
                DCD     ACMPHS2_INT_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_ACMPHS3_INT != BSP_IRQ_DISABLED
                DCD     ACMPHS3_INT_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_ACMPHS4_INT != BSP_IRQ_DISABLED
                DCD     ACMPHS4_INT_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_ACMPHS5_INT != BSP_IRQ_DISABLED
                DCD     ACMPHS5_INT_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_USBFS_FIFO_0 != BSP_IRQ_DISABLED
                DCD     USBFS_FIFO_0_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_USBFS_FIFO_1 != BSP_IRQ_DISABLED
                DCD     USBFS_FIFO_1_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_USBFS_INT != BSP_IRQ_DISABLED
                DCD     USBFS_INT_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_USBFS_RESUME != BSP_IRQ_DISABLED
                DCD     USBFS_RESUME_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_IIC0_RXI != BSP_IRQ_DISABLED
                DCD     IIC0_RXI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_IIC0_TXI != BSP_IRQ_DISABLED
                DCD     IIC0_TXI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_IIC0_TEI != BSP_IRQ_DISABLED
                DCD     IIC0_TEI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_IIC0_ERI != BSP_IRQ_DISABLED
                DCD     IIC0_ERI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_IIC0_WUI != BSP_IRQ_DISABLED
                DCD     IIC0_WUI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_IIC1_RXI != BSP_IRQ_DISABLED
                DCD     IIC1_RXI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_IIC1_TXI != BSP_IRQ_DISABLED
                DCD     IIC1_TXI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_IIC1_TEI != BSP_IRQ_DISABLED
                DCD     IIC1_TEI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_IIC1_ERI != BSP_IRQ_DISABLED
                DCD     IIC1_ERI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_IIC2_RXI != BSP_IRQ_DISABLED
                DCD     IIC2_RXI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_IIC2_TXI != BSP_IRQ_DISABLED
                DCD     IIC2_TXI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_IIC2_TEI != BSP_IRQ_DISABLED
                DCD     IIC2_TEI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_IIC2_ERI != BSP_IRQ_DISABLED
                DCD     IIC2_ERI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SSI0_TXI != BSP_IRQ_DISABLED
                DCD     SSI0_TXI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SSI0_RXI != BSP_IRQ_DISABLED
                DCD     SSI0_RXI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SSI0_INT != BSP_IRQ_DISABLED
                DCD     SSI0_INT_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SRC_INPUT_FIFO_EMPTY != BSP_IRQ_DISABLED
                DCD     SRC_INPUT_FIFO_EMPTY_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SRC_OUTPUT_FIFO_FULL != BSP_IRQ_DISABLED
                DCD     SRC_OUTPUT_FIFO_FULL_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SRC_OUTPUT_FIFO_OVERFLOW != BSP_IRQ_DISABLED
                DCD     SRC_OUTPUT_FIFO_OVERFLOW_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SRC_OUTPUT_FIFO_UNDERFLOW != BSP_IRQ_DISABLED
                DCD     SRC_OUTPUT_FIFO_UNDERFLOW_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SRC_CONVERSION_END != BSP_IRQ_DISABLED
                DCD     SRC_CONVERSION_END_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_PDC_RECEIVE_DATA_READY != BSP_IRQ_DISABLED
                DCD     PDC_RECEIVE_DATA_READY_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_PDC_FRAME_END != BSP_IRQ_DISABLED
                DCD     PDC_FRAME_END_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_PDC_INT != BSP_IRQ_DISABLED
                DCD     PDC_INT_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_CTSU_WRITE != BSP_IRQ_DISABLED
                DCD     CTSU_WRITE_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_CTSU_READ != BSP_IRQ_DISABLED
                DCD     CTSU_READ_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_CTSU_END != BSP_IRQ_DISABLED
                DCD     CTSU_END_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_KEY_INT != BSP_IRQ_DISABLED
                DCD     KEY_INT_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_DOC_INT != BSP_IRQ_DISABLED
                DCD     DOC_INT_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_CAC_FREQUENCY_ERROR != BSP_IRQ_DISABLED
                DCD     CAC_FREQUENCY_ERROR_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_CAC_MEASUREMENT_END != BSP_IRQ_DISABLED
                DCD     CAC_MEASUREMENT_END_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_CAC_OVERFLOW != BSP_IRQ_DISABLED
                DCD     CAC_OVERFLOW_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_CAN0_ERROR != BSP_IRQ_DISABLED
                DCD     CAN0_ERROR_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_CAN0_FIFO_RX != BSP_IRQ_DISABLED
                DCD     CAN0_FIFO_RX_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_CAN0_FIFO_TX != BSP_IRQ_DISABLED
                DCD     CAN0_FIFO_TX_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_CAN0_MAILBOX_RX != BSP_IRQ_DISABLED
                DCD     CAN0_MAILBOX_RX_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_CAN0_MAILBOX_TX != BSP_IRQ_DISABLED
                DCD     CAN0_MAILBOX_TX_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_CAN1_ERROR != BSP_IRQ_DISABLED
                DCD     CAN1_ERROR_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_CAN1_FIFO_RX != BSP_IRQ_DISABLED
                DCD     CAN1_FIFO_RX_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_CAN1_FIFO_TX != BSP_IRQ_DISABLED
                DCD     CAN1_FIFO_TX_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_CAN1_MAILBOX_RX != BSP_IRQ_DISABLED
                DCD     CAN1_MAILBOX_RX_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_CAN1_MAILBOX_TX != BSP_IRQ_DISABLED
                DCD     CAN1_MAILBOX_TX_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_IOPORT_EVENT_1 != BSP_IRQ_DISABLED
                DCD     IOPORT_EVENT_1_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_IOPORT_EVENT_2 != BSP_IRQ_DISABLED
                DCD     IOPORT_EVENT_2_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_IOPORT_EVENT_3 != BSP_IRQ_DISABLED
                DCD     IOPORT_EVENT_3_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_IOPORT_EVENT_4 != BSP_IRQ_DISABLED
                DCD     IOPORT_EVENT_4_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_ELC_SOFTWARE_EVENT_0 != BSP_IRQ_DISABLED
                DCD     ELC_SOFTWARE_EVENT_0_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_ELC_SOFTWARE_EVENT_1 != BSP_IRQ_DISABLED
                DCD     ELC_SOFTWARE_EVENT_1_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_POEG0_EVENT != BSP_IRQ_DISABLED
                DCD     POEG0_EVENT_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_POEG1_EVENT != BSP_IRQ_DISABLED
                DCD     POEG1_EVENT_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_POEG2_EVENT != BSP_IRQ_DISABLED
                DCD     POEG2_EVENT_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_POEG3_EVENT != BSP_IRQ_DISABLED
                DCD     POEG3_EVENT_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT0_CAPTURE_COMPARE_A != BSP_IRQ_DISABLED
                DCD     GPT0_CAPTURE_COMPARE_A_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT0_CAPTURE_COMPARE_B != BSP_IRQ_DISABLED
                DCD     GPT0_CAPTURE_COMPARE_B_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT0_COMPARE_C != BSP_IRQ_DISABLED
                DCD     GPT0_COMPARE_C_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT0_COMPARE_D != BSP_IRQ_DISABLED
                DCD     GPT0_COMPARE_D_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT0_COMPARE_E != BSP_IRQ_DISABLED
                DCD     GPT0_COMPARE_E_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT0_COMPARE_F != BSP_IRQ_DISABLED
                DCD     GPT0_COMPARE_F_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT0_COUNTER_OVERFLOW != BSP_IRQ_DISABLED
                DCD     GPT0_COUNTER_OVERFLOW_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT0_COUNTER_UNDERFLOW != BSP_IRQ_DISABLED
                DCD     GPT0_COUNTER_UNDERFLOW_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT0_AD_TRIG_A != BSP_IRQ_DISABLED
                DCD     GPT0_AD_TRIG_A_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT0_AD_TRIG_B != BSP_IRQ_DISABLED
                DCD     GPT0_AD_TRIG_B_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT1_CAPTURE_COMPARE_A != BSP_IRQ_DISABLED
                DCD     GPT1_CAPTURE_COMPARE_A_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT1_CAPTURE_COMPARE_B != BSP_IRQ_DISABLED
                DCD     GPT1_CAPTURE_COMPARE_B_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT1_COMPARE_C != BSP_IRQ_DISABLED
                DCD     GPT1_COMPARE_C_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT1_COMPARE_D != BSP_IRQ_DISABLED
                DCD     GPT1_COMPARE_D_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT1_COMPARE_E != BSP_IRQ_DISABLED
                DCD     GPT1_COMPARE_E_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT1_COMPARE_F != BSP_IRQ_DISABLED
                DCD     GPT1_COMPARE_F_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT1_COUNTER_OVERFLOW != BSP_IRQ_DISABLED
                DCD     GPT1_COUNTER_OVERFLOW_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT1_COUNTER_UNDERFLOW != BSP_IRQ_DISABLED
                DCD     GPT1_COUNTER_UNDERFLOW_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT1_AD_TRIG_A != BSP_IRQ_DISABLED
                DCD     GPT1_AD_TRIG_A_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT1_AD_TRIG_B != BSP_IRQ_DISABLED
                DCD     GPT1_AD_TRIG_B_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT2_CAPTURE_COMPARE_A != BSP_IRQ_DISABLED
                DCD     GPT2_CAPTURE_COMPARE_A_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT2_CAPTURE_COMPARE_B != BSP_IRQ_DISABLED
                DCD     GPT2_CAPTURE_COMPARE_B_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT2_COMPARE_C != BSP_IRQ_DISABLED
                DCD     GPT2_COMPARE_C_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT2_COMPARE_D != BSP_IRQ_DISABLED
                DCD     GPT2_COMPARE_D_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT2_COMPARE_E != BSP_IRQ_DISABLED
                DCD     GPT2_COMPARE_E_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT2_COMPARE_F != BSP_IRQ_DISABLED
                DCD     GPT2_COMPARE_F_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT2_COUNTER_OVERFLOW != BSP_IRQ_DISABLED
                DCD     GPT2_COUNTER_OVERFLOW_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT2_COUNTER_UNDERFLOW != BSP_IRQ_DISABLED
                DCD     GPT2_COUNTER_UNDERFLOW_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT2_AD_TRIG_A != BSP_IRQ_DISABLED
                DCD     GPT2_AD_TRIG_A_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT2_AD_TRIG_B != BSP_IRQ_DISABLED
                DCD     GPT2_AD_TRIG_B_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT3_CAPTURE_COMPARE_A != BSP_IRQ_DISABLED
                DCD     GPT3_CAPTURE_COMPARE_A_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT3_CAPTURE_COMPARE_B != BSP_IRQ_DISABLED
                DCD     GPT3_CAPTURE_COMPARE_B_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT3_COMPARE_C != BSP_IRQ_DISABLED
                DCD     GPT3_COMPARE_C_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT3_COMPARE_D != BSP_IRQ_DISABLED
                DCD     GPT3_COMPARE_D_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT3_COMPARE_E != BSP_IRQ_DISABLED
                DCD     GPT3_COMPARE_E_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT3_COMPARE_F != BSP_IRQ_DISABLED
                DCD     GPT3_COMPARE_F_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT3_COUNTER_OVERFLOW != BSP_IRQ_DISABLED
                DCD     GPT3_COUNTER_OVERFLOW_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT3_COUNTER_UNDERFLOW != BSP_IRQ_DISABLED
                DCD     GPT3_COUNTER_UNDERFLOW_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT3_AD_TRIG_A != BSP_IRQ_DISABLED
                DCD     GPT3_AD_TRIG_A_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT3_AD_TRIG_B != BSP_IRQ_DISABLED
                DCD     GPT3_AD_TRIG_B_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT4_CAPTURE_COMPARE_A != BSP_IRQ_DISABLED
                DCD     GPT4_CAPTURE_COMPARE_A_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT4_CAPTURE_COMPARE_B != BSP_IRQ_DISABLED
                DCD     GPT4_CAPTURE_COMPARE_B_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT4_COMPARE_C != BSP_IRQ_DISABLED
                DCD     GPT4_COMPARE_C_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT4_COMPARE_D != BSP_IRQ_DISABLED
                DCD     GPT4_COMPARE_D_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT4_COMPARE_E != BSP_IRQ_DISABLED
                DCD     GPT4_COMPARE_E_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT4_COMPARE_F != BSP_IRQ_DISABLED
                DCD     GPT4_COMPARE_F_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT4_COUNTER_OVERFLOW != BSP_IRQ_DISABLED
                DCD     GPT4_COUNTER_OVERFLOW_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT4_COUNTER_UNDERFLOW != BSP_IRQ_DISABLED
                DCD     GPT4_COUNTER_UNDERFLOW_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT4_AD_TRIG_A != BSP_IRQ_DISABLED
                DCD     GPT4_AD_TRIG_A_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT4_AD_TRIG_B != BSP_IRQ_DISABLED
                DCD     GPT4_AD_TRIG_B_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT5_CAPTURE_COMPARE_A != BSP_IRQ_DISABLED
                DCD     GPT5_CAPTURE_COMPARE_A_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT5_CAPTURE_COMPARE_B != BSP_IRQ_DISABLED
                DCD     GPT5_CAPTURE_COMPARE_B_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT5_COMPARE_C != BSP_IRQ_DISABLED
                DCD     GPT5_COMPARE_C_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT5_COMPARE_D != BSP_IRQ_DISABLED
                DCD     GPT5_COMPARE_D_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT5_COMPARE_E != BSP_IRQ_DISABLED
                DCD     GPT5_COMPARE_E_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT5_COMPARE_F != BSP_IRQ_DISABLED
                DCD     GPT5_COMPARE_F_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT5_COUNTER_OVERFLOW != BSP_IRQ_DISABLED
                DCD     GPT5_COUNTER_OVERFLOW_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT5_COUNTER_UNDERFLOW != BSP_IRQ_DISABLED
                DCD     GPT5_COUNTER_UNDERFLOW_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT5_AD_TRIG_A != BSP_IRQ_DISABLED
                DCD     GPT5_AD_TRIG_A_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT5_AD_TRIG_B != BSP_IRQ_DISABLED
                DCD     GPT5_AD_TRIG_B_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT6_CAPTURE_COMPARE_A != BSP_IRQ_DISABLED
                DCD     GPT6_CAPTURE_COMPARE_A_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT6_CAPTURE_COMPARE_B != BSP_IRQ_DISABLED
                DCD     GPT6_CAPTURE_COMPARE_B_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT6_COMPARE_C != BSP_IRQ_DISABLED
                DCD     GPT6_COMPARE_C_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT6_COMPARE_D != BSP_IRQ_DISABLED
                DCD     GPT6_COMPARE_D_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT6_COMPARE_E != BSP_IRQ_DISABLED
                DCD     GPT6_COMPARE_E_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT6_COMPARE_F != BSP_IRQ_DISABLED
                DCD     GPT6_COMPARE_F_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT6_COUNTER_OVERFLOW != BSP_IRQ_DISABLED
                DCD     GPT6_COUNTER_OVERFLOW_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT6_COUNTER_UNDERFLOW != BSP_IRQ_DISABLED
                DCD     GPT6_COUNTER_UNDERFLOW_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT6_AD_TRIG_A != BSP_IRQ_DISABLED
                DCD     GPT6_AD_TRIG_A_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT6_AD_TRIG_B != BSP_IRQ_DISABLED
                DCD     GPT6_AD_TRIG_B_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT7_CAPTURE_COMPARE_A != BSP_IRQ_DISABLED
                DCD     GPT7_CAPTURE_COMPARE_A_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT7_CAPTURE_COMPARE_B != BSP_IRQ_DISABLED
                DCD     GPT7_CAPTURE_COMPARE_B_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT7_COMPARE_C != BSP_IRQ_DISABLED
                DCD     GPT7_COMPARE_C_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT7_COMPARE_D != BSP_IRQ_DISABLED
                DCD     GPT7_COMPARE_D_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT7_COMPARE_E != BSP_IRQ_DISABLED
                DCD     GPT7_COMPARE_E_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT7_COMPARE_F != BSP_IRQ_DISABLED
                DCD     GPT7_COMPARE_F_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT7_COUNTER_OVERFLOW != BSP_IRQ_DISABLED
                DCD     GPT7_COUNTER_OVERFLOW_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT7_COUNTER_UNDERFLOW != BSP_IRQ_DISABLED
                DCD     GPT7_COUNTER_UNDERFLOW_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT7_AD_TRIG_A != BSP_IRQ_DISABLED
                DCD     GPT7_AD_TRIG_A_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT7_AD_TRIG_B != BSP_IRQ_DISABLED
                DCD     GPT7_AD_TRIG_B_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT8_CAPTURE_COMPARE_A != BSP_IRQ_DISABLED
                DCD     GPT8_CAPTURE_COMPARE_A_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT8_CAPTURE_COMPARE_B != BSP_IRQ_DISABLED
                DCD     GPT8_CAPTURE_COMPARE_B_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT8_COMPARE_C != BSP_IRQ_DISABLED
                DCD     GPT8_COMPARE_C_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT8_COMPARE_D != BSP_IRQ_DISABLED
                DCD     GPT8_COMPARE_D_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT8_COMPARE_E != BSP_IRQ_DISABLED
                DCD     GPT8_COMPARE_E_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT8_COMPARE_F != BSP_IRQ_DISABLED
                DCD     GPT8_COMPARE_F_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT8_COUNTER_OVERFLOW != BSP_IRQ_DISABLED
                DCD     GPT8_COUNTER_OVERFLOW_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT8_COUNTER_UNDERFLOW != BSP_IRQ_DISABLED
                DCD     GPT8_COUNTER_UNDERFLOW_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT9_CAPTURE_COMPARE_A != BSP_IRQ_DISABLED
                DCD     GPT9_CAPTURE_COMPARE_A_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT9_CAPTURE_COMPARE_B != BSP_IRQ_DISABLED
                DCD     GPT9_CAPTURE_COMPARE_B_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT9_COMPARE_C != BSP_IRQ_DISABLED
                DCD     GPT9_COMPARE_C_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT9_COMPARE_D != BSP_IRQ_DISABLED
                DCD     GPT9_COMPARE_D_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT9_COMPARE_E != BSP_IRQ_DISABLED
                DCD     GPT9_COMPARE_E_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT9_COMPARE_F != BSP_IRQ_DISABLED
                DCD     GPT9_COMPARE_F_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT9_COUNTER_OVERFLOW != BSP_IRQ_DISABLED
                DCD     GPT9_COUNTER_OVERFLOW_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT9_COUNTER_UNDERFLOW != BSP_IRQ_DISABLED
                DCD     GPT9_COUNTER_UNDERFLOW_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT10_CAPTURE_COMPARE_A != BSP_IRQ_DISABLED
                DCD     GPT10_CAPTURE_COMPARE_A_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT10_CAPTURE_COMPARE_B != BSP_IRQ_DISABLED
                DCD     GPT10_CAPTURE_COMPARE_B_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT10_COMPARE_C != BSP_IRQ_DISABLED
                DCD     GPT10_COMPARE_C_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT10_COMPARE_D != BSP_IRQ_DISABLED
                DCD     GPT10_COMPARE_D_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT10_COMPARE_E != BSP_IRQ_DISABLED
                DCD     GPT10_COMPARE_E_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT10_COMPARE_F != BSP_IRQ_DISABLED
                DCD     GPT10_COMPARE_F_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT10_COUNTER_OVERFLOW != BSP_IRQ_DISABLED
                DCD     GPT10_COUNTER_OVERFLOW_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT10_COUNTER_UNDERFLOW != BSP_IRQ_DISABLED
                DCD     GPT10_COUNTER_UNDERFLOW_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT11_CAPTURE_COMPARE_A != BSP_IRQ_DISABLED
                DCD     GPT11_CAPTURE_COMPARE_A_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT11_CAPTURE_COMPARE_B != BSP_IRQ_DISABLED
                DCD     GPT11_CAPTURE_COMPARE_B_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT11_COMPARE_C != BSP_IRQ_DISABLED
                DCD     GPT11_COMPARE_C_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT11_COMPARE_D != BSP_IRQ_DISABLED
                DCD     GPT11_COMPARE_D_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT11_COMPARE_E != BSP_IRQ_DISABLED
                DCD     GPT11_COMPARE_E_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT11_COMPARE_F != BSP_IRQ_DISABLED
                DCD     GPT11_COMPARE_F_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT11_COUNTER_OVERFLOW != BSP_IRQ_DISABLED
                DCD     GPT11_COUNTER_OVERFLOW_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT11_COUNTER_UNDERFLOW != BSP_IRQ_DISABLED
                DCD     GPT11_COUNTER_UNDERFLOW_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT12_CAPTURE_COMPARE_A != BSP_IRQ_DISABLED
                DCD     GPT12_CAPTURE_COMPARE_A_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT12_CAPTURE_COMPARE_B != BSP_IRQ_DISABLED
                DCD     GPT12_CAPTURE_COMPARE_B_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT12_COMPARE_C != BSP_IRQ_DISABLED
                DCD     GPT12_COMPARE_C_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT12_COMPARE_D != BSP_IRQ_DISABLED
                DCD     GPT12_COMPARE_D_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT12_COMPARE_E != BSP_IRQ_DISABLED
                DCD     GPT12_COMPARE_E_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT12_COMPARE_F != BSP_IRQ_DISABLED
                DCD     GPT12_COMPARE_F_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT12_COUNTER_OVERFLOW != BSP_IRQ_DISABLED
                DCD     GPT12_COUNTER_OVERFLOW_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT12_COUNTER_UNDERFLOW != BSP_IRQ_DISABLED
                DCD     GPT12_COUNTER_UNDERFLOW_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT13_CAPTURE_COMPARE_A != BSP_IRQ_DISABLED
                DCD     GPT13_CAPTURE_COMPARE_A_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT13_CAPTURE_COMPARE_B != BSP_IRQ_DISABLED
                DCD     GPT13_CAPTURE_COMPARE_B_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT13_COMPARE_C != BSP_IRQ_DISABLED
                DCD     GPT13_COMPARE_C_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT13_COMPARE_D != BSP_IRQ_DISABLED
                DCD     GPT13_COMPARE_D_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT13_COMPARE_E != BSP_IRQ_DISABLED
                DCD     GPT13_COMPARE_E_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT13_COMPARE_F != BSP_IRQ_DISABLED
                DCD     GPT13_COMPARE_F_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT13_COUNTER_OVERFLOW != BSP_IRQ_DISABLED
                DCD     GPT13_COUNTER_OVERFLOW_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_GPT13_COUNTER_UNDERFLOW != BSP_IRQ_DISABLED
                DCD     GPT13_COUNTER_UNDERFLOW_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_OPS_UVW_EDGE != BSP_IRQ_DISABLED
                DCD     OPS_UVW_EDGE_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_EDMAC0_EINT != BSP_IRQ_DISABLED
                DCD     EDMAC0_EINT_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI0_RXI != BSP_IRQ_DISABLED
                DCD     SCI0_RXI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI0_TXI != BSP_IRQ_DISABLED
                DCD     SCI0_TXI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI0_TEI != BSP_IRQ_DISABLED
                DCD     SCI0_TEI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI0_ERI != BSP_IRQ_DISABLED
                DCD     SCI0_ERI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI0_AM != BSP_IRQ_DISABLED
                DCD     SCI0_AM_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI0_RXI_OR_ERI != BSP_IRQ_DISABLED
                DCD     SCI0_RXI_OR_ERI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI1_RXI != BSP_IRQ_DISABLED
                DCD     SCI1_RXI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI1_TXI != BSP_IRQ_DISABLED
                DCD     SCI1_TXI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI1_TEI != BSP_IRQ_DISABLED
                DCD     SCI1_TEI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI1_ERI != BSP_IRQ_DISABLED
                DCD     SCI1_ERI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI1_AM != BSP_IRQ_DISABLED
                DCD     SCI1_AM_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI2_RXI != BSP_IRQ_DISABLED
                DCD     SCI2_RXI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI2_TXI != BSP_IRQ_DISABLED
                DCD     SCI2_TXI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI2_TEI != BSP_IRQ_DISABLED
                DCD     SCI2_TEI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI2_ERI != BSP_IRQ_DISABLED
                DCD     SCI2_ERI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI2_AM != BSP_IRQ_DISABLED
                DCD     SCI2_AM_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI3_RXI != BSP_IRQ_DISABLED
                DCD     SCI3_RXI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI3_TXI != BSP_IRQ_DISABLED
                DCD     SCI3_TXI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI3_TEI != BSP_IRQ_DISABLED
                DCD     SCI3_TEI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI3_ERI != BSP_IRQ_DISABLED
                DCD     SCI3_ERI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI3_AM != BSP_IRQ_DISABLED
                DCD     SCI3_AM_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI4_RXI != BSP_IRQ_DISABLED
                DCD     SCI4_RXI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI4_TXI != BSP_IRQ_DISABLED
                DCD     SCI4_TXI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI4_TEI != BSP_IRQ_DISABLED
                DCD     SCI4_TEI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI4_ERI != BSP_IRQ_DISABLED
                DCD     SCI4_ERI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI4_AM != BSP_IRQ_DISABLED
                DCD     SCI4_AM_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI5_RXI != BSP_IRQ_DISABLED
                DCD     SCI5_RXI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI5_TXI != BSP_IRQ_DISABLED
                DCD     SCI5_TXI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI5_TEI != BSP_IRQ_DISABLED
                DCD     SCI5_TEI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI5_ERI != BSP_IRQ_DISABLED
                DCD     SCI5_ERI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI5_AM != BSP_IRQ_DISABLED
                DCD     SCI5_AM_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI6_RXI != BSP_IRQ_DISABLED
                DCD     SCI6_RXI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI6_TXI != BSP_IRQ_DISABLED
                DCD     SCI6_TXI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI6_TEI != BSP_IRQ_DISABLED
                DCD     SCI6_TEI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI6_ERI != BSP_IRQ_DISABLED
                DCD     SCI6_ERI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI6_AM != BSP_IRQ_DISABLED
                DCD     SCI6_AM_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI7_RXI != BSP_IRQ_DISABLED
                DCD     SCI7_RXI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI7_TXI != BSP_IRQ_DISABLED
                DCD     SCI7_TXI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI7_TEI != BSP_IRQ_DISABLED
                DCD     SCI7_TEI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI7_ERI != BSP_IRQ_DISABLED
                DCD     SCI7_ERI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI7_AM != BSP_IRQ_DISABLED
                DCD     SCI7_AM_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI8_RXI != BSP_IRQ_DISABLED
                DCD     SCI8_RXI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI8_TXI != BSP_IRQ_DISABLED
                DCD     SCI8_TXI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI8_TEI != BSP_IRQ_DISABLED
                DCD     SCI8_TEI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI8_ERI != BSP_IRQ_DISABLED
                DCD     SCI8_ERI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI8_AM != BSP_IRQ_DISABLED
                DCD     SCI8_AM_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI9_RXI != BSP_IRQ_DISABLED
                DCD     SCI9_RXI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI9_TXI != BSP_IRQ_DISABLED
                DCD     SCI9_TXI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI9_TEI != BSP_IRQ_DISABLED
                DCD     SCI9_TEI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI9_ERI != BSP_IRQ_DISABLED
                DCD     SCI9_ERI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCI9_AM != BSP_IRQ_DISABLED
                DCD     SCI9_AM_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SPI0_RXI != BSP_IRQ_DISABLED
                DCD     SPI0_RXI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SPI0_TXI != BSP_IRQ_DISABLED
                DCD     SPI0_TXI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SPI0_IDLE != BSP_IRQ_DISABLED
                DCD     SPI0_IDLE_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SPI0_ERI != BSP_IRQ_DISABLED
                DCD     SPI0_ERI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SPI0_TEI != BSP_IRQ_DISABLED
                DCD     SPI0_TEI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SPI1_RXI != BSP_IRQ_DISABLED
                DCD     SPI1_RXI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SPI1_TXI != BSP_IRQ_DISABLED
                DCD     SPI1_TXI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SPI1_IDLE != BSP_IRQ_DISABLED
                DCD     SPI1_IDLE_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SPI1_ERI != BSP_IRQ_DISABLED
                DCD     SPI1_ERI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SPI1_TEI != BSP_IRQ_DISABLED
                DCD     SPI1_TEI_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_QSPI_INT != BSP_IRQ_DISABLED
                DCD     QSPI_INT_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SDHIMMC0_ACCS != BSP_IRQ_DISABLED
                DCD     SDHIMMC0_ACCS_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SDHIMMC0_SDIO != BSP_IRQ_DISABLED
                DCD     SDHIMMC0_SDIO_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SDHIMMC0_CARD != BSP_IRQ_DISABLED
                DCD     SDHIMMC0_CARD_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SDHIMMC0_DMA_REQ != BSP_IRQ_DISABLED
                DCD     SDHIMMC0_DMA_REQ_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SDHIMMC1_ACCS != BSP_IRQ_DISABLED
                DCD     SDHIMMC1_ACCS_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SDHIMMC1_SDIO != BSP_IRQ_DISABLED
                DCD     SDHIMMC1_SDIO_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SDHIMMC1_CARD != BSP_IRQ_DISABLED
                DCD     SDHIMMC1_CARD_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SDHIMMC1_DMA_REQ != BSP_IRQ_DISABLED
                DCD     SDHIMMC1_DMA_REQ_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCE_PROC_BUSY != BSP_IRQ_DISABLED
                DCD     SCE_PROC_BUSY_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCE_ROMOK != BSP_IRQ_DISABLED
                DCD     SCE_ROMOK_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCE_LONG_PLG != BSP_IRQ_DISABLED
                DCD     SCE_LONG_PLG_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCE_TEST_BUSY != BSP_IRQ_DISABLED
                DCD     SCE_TEST_BUSY_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCE_WRRDY_0 != BSP_IRQ_DISABLED
                DCD     SCE_WRRDY_0_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCE_WRRDY_1 != BSP_IRQ_DISABLED
                DCD     SCE_WRRDY_1_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCE_WRRDY_4 != BSP_IRQ_DISABLED
                DCD     SCE_WRRDY_4_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCE_RDRDY_0 != BSP_IRQ_DISABLED
                DCD     SCE_RDRDY_0_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCE_RDRDY_1 != BSP_IRQ_DISABLED
                DCD     SCE_RDRDY_1_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCE_INTEGRATE_WRRDY != BSP_IRQ_DISABLED
                DCD     SCE_INTEGRATE_WRRDY_IRQHandler
                ENDIF
                IF      BSP_IRQ_CFG_SCE_INTEGRATE_RDRDY != BSP_IRQ_DISABLED
                DCD     SCE_INTEGRATE_RDRDY_IRQHandler
                ENDIF
__Vectors_End

__Vectors_Size  EQU  __Vectors_End - __Vectors

                FILL    (0x400 - __Vectors_Size), 0xFFFFFFFF, 4

__Options       DCD     0xFFFFFFFF                 ; Option Function Select Register 0 (OFS0)
                DCD     0xFFFFFDFF                 ; Option Function Select Register 1 (OFS1)
                DCD     0xFFFFFFFC                 ; Security MPU Program Counter Start Address Register 0 (SECMPUPCS0)
                DCD     0xFFFFFFFF                 ; Security MPU Program Counter End Address Register 0 (SECMPUPCE0)
                DCD     0xFFFFFFFC                 ; Security MPU Program Counter Start Address Register 1 (SECMPUPCS1)
                DCD     0xFFFFFFFF                 ; Security MPU Program Counter End Address Register 1 (SECMPUPCE1)
                DCD     0x00FFFFFC                 ; Security MPU Region 0 Start Address Register (SECMPUS0)
                DCD     0x00FFFFFF                 ; Security MPU Region 0 End Address Register (SECMPUE0)
                DCD     0x200FFFFC                 ; Security MPU Region 1 Start Address Register (SECMPUS1)
                DCD     0x200FFFFF                 ; Security MPU Region 1 End Address Register (SECMPUE1)
                DCD     0x407FFFFC                 ; Security MPU Region 2 Start Address Register (SECMPUS2)
                DCD     0x407FFFFF                 ; Security MPU Region 2 End Address Register (SECMPUE2)
                DCD     0x400DFFFC                 ; Security MPU Region 3 Start Address Register (SECMPUS3)
                DCD     0x400DFFFF                 ; Security MPU Region 3 End Address Register (SECMPUE3)
                DCD     0xFFFFFFFF                 ; Security MPU Access Control Register (SECMPUAC)
__Options_End

__Options_Size  EQU  __Options_End - __Options

                FILL    (0x100 - __Options_Size), 0xFFFFFFFF, 4

                AREA    |.text|, CODE, READONLY

; Reset handler
Reset_Handler    PROC
                 EXPORT  Reset_Handler             [WEAK]
        IMPORT  SystemInit
        IMPORT  __main

                 LDR     R0, =SystemInit
                 BLX     R0
                 LDR     R0, =__main
                 BX      R0
                 ENDP

; Dummy Exception Handlers (infinite loops which can be modified)

NMI_Handler     PROC
                EXPORT  NMI_Handler                [WEAK]
                B       .
                ENDP
HardFault_Handler\
                PROC
                EXPORT  HardFault_Handler          [WEAK]
                B       .
                ENDP
MemManage_Handler\
                PROC
                EXPORT  MemManage_Handler          [WEAK]
                B       .
                ENDP
BusFault_Handler\
                PROC
                EXPORT  BusFault_Handler           [WEAK]
                B       .
                ENDP
UsageFault_Handler\
                PROC
                EXPORT  UsageFault_Handler         [WEAK]
                B       .
                ENDP
SVC_Handler     PROC
                EXPORT  SVC_Handler                [WEAK]
                B       .
                ENDP
DebugMon_Handler\
                PROC
                EXPORT  DebugMon_Handler           [WEAK]
                B       .
                ENDP
PendSV_Handler  PROC
                EXPORT  PendSV_Handler             [WEAK]
                B       .
                ENDP
SysTick_Handler PROC
                EXPORT  SysTick_Handler            [WEAK]
                B       .
                ENDP

Default_Handler PROC
                EXPORT  ICU_IRQ0_IRQHandler                  [WEAK]
                EXPORT  ICU_IRQ1_IRQHandler                  [WEAK]
                EXPORT  ICU_IRQ2_IRQHandler                  [WEAK]
                EXPORT  ICU_IRQ3_IRQHandler                  [WEAK]
                EXPORT  ICU_IRQ4_IRQHandler                  [WEAK]
                EXPORT  ICU_IRQ5_IRQHandler                  [WEAK]
                EXPORT  ICU_IRQ6_IRQHandler                  [WEAK]
                EXPORT  ICU_IRQ7_IRQHandler                  [WEAK]
                EXPORT  ICU_IRQ8_IRQHandler                  [WEAK]
                EXPORT  ICU_IRQ9_IRQHandler                  [WEAK]
                EXPORT  ICU_IRQ10_IRQHandler                 [WEAK]
                EXPORT  ICU_IRQ11_IRQHandler                 [WEAK]
                EXPORT  ICU_IRQ12_IRQHandler                 [WEAK]
                EXPORT  ICU_IRQ13_IRQHandler                 [WEAK]
                EXPORT  ICU_IRQ14_IRQHandler                 [WEAK]
                EXPORT  ICU_IRQ15_IRQHandler                 [WEAK]
                EXPORT  DMAC0_INT_IRQHandler                 [WEAK]
                EXPORT  DMAC1_INT_IRQHandler                 [WEAK]
                EXPORT  DMAC2_INT_IRQHandler                 [WEAK]
                EXPORT  DMAC3_INT_IRQHandler                 [WEAK]
                EXPORT  DMAC4_INT_IRQHandler                 [WEAK]
                EXPORT  DMAC5_INT_IRQHandler                 [WEAK]
                EXPORT  DMAC6_INT_IRQHandler                 [WEAK]
                EXPORT  DMAC7_INT_IRQHandler                 [WEAK]
                EXPORT  DTC_COMPLETE_IRQHandler              [WEAK]
                EXPORT  DTC_END_IRQHandler                   [WEAK]
                EXPORT  ICU_SNOOZE_CANCEL_IRQHandler         [WEAK]
                EXPORT  FCU_FIFERR_IRQHandler                [WEAK]
                EXPORT  FCU_FRDYI_IRQHandler                 [WEAK]
                EXPORT  LVD_LVD1_IRQHandler                  [WEAK]
                EXPORT  LVD_LVD2_IRQHandler                  [WEAK]
                EXPORT  CGC_MOSC_STOP_IRQHandler             [WEAK]
                EXPORT  LPM_SNOOZE_REQUEST_IRQHandler        [WEAK]
                EXPORT  AGT0_INT_IRQHandler                  [WEAK]
                EXPORT  AGT0_COMPARE_A_IRQHandler            [WEAK]
                EXPORT  AGT0_COMPARE_B_IRQHandler            [WEAK]
                EXPORT  AGT1_INT_IRQHandler                  [WEAK]
                EXPORT  AGT1_COMPARE_A_IRQHandler            [WEAK]
                EXPORT  AGT1_COMPARE_B_IRQHandler            [WEAK]
                EXPORT  IWDT_UNDERFLOW_IRQHandler            [WEAK]
                EXPORT  WDT_UNDERFLOW_IRQHandler             [WEAK]
                EXPORT  RTC_ALARM_IRQHandler                 [WEAK]
                EXPORT  RTC_PERIOD_IRQHandler                [WEAK]
                EXPORT  RTC_CARRY_IRQHandler                 [WEAK]
                EXPORT  ADC0_SCAN_END_IRQHandler             [WEAK]
                EXPORT  ADC0_SCAN_END_B_IRQHandler           [WEAK]
                EXPORT  ADC0_WINDOW_A_IRQHandler             [WEAK]
                EXPORT  ADC0_WINDOW_B_IRQHandler             [WEAK]
                EXPORT  ADC0_COMPARE_MATCH_IRQHandler        [WEAK]
                EXPORT  ADC0_COMPARE_MISMATCH_IRQHandler     [WEAK]
                EXPORT  ADC1_SCAN_END_IRQHandler             [WEAK]
                EXPORT  ADC1_SCAN_END_B_IRQHandler           [WEAK]
                EXPORT  ADC1_WINDOW_A_IRQHandler             [WEAK]
                EXPORT  ADC1_WINDOW_B_IRQHandler             [WEAK]
                EXPORT  ADC1_COMPARE_MATCH_IRQHandler        [WEAK]
                EXPORT  ADC1_COMPARE_MISMATCH_IRQHandler     [WEAK]
                EXPORT  ACMPHS0_INT_IRQHandler               [WEAK]
                EXPORT  ACMPHS1_INT_IRQHandler               [WEAK]
                EXPORT  ACMPHS2_INT_IRQHandler               [WEAK]
                EXPORT  ACMPHS3_INT_IRQHandler               [WEAK]
                EXPORT  ACMPHS4_INT_IRQHandler               [WEAK]
                EXPORT  ACMPHS5_INT_IRQHandler               [WEAK]
                EXPORT  USBFS_FIFO_0_IRQHandler              [WEAK]
                EXPORT  USBFS_FIFO_1_IRQHandler              [WEAK]
                EXPORT  USBFS_INT_IRQHandler                 [WEAK]
                EXPORT  USBFS_RESUME_IRQHandler              [WEAK]
                EXPORT  IIC0_RXI_IRQHandler                  [WEAK]
                EXPORT  IIC0_TXI_IRQHandler                  [WEAK]
                EXPORT  IIC0_TEI_IRQHandler                  [WEAK]
                EXPORT  IIC0_ERI_IRQHandler                  [WEAK]
                EXPORT  IIC0_WUI_IRQHandler                  [WEAK]
                EXPORT  IIC1_RXI_IRQHandler                  [WEAK]
                EXPORT  IIC1_TXI_IRQHandler                  [WEAK]
                EXPORT  IIC1_TEI_IRQHandler                  [WEAK]
                EXPORT  IIC1_ERI_IRQHandler                  [WEAK]
                EXPORT  IIC2_RXI_IRQHandler                  [WEAK]
                EXPORT  IIC2_TXI_IRQHandler                  [WEAK]
                EXPORT  IIC2_TEI_IRQHandler                  [WEAK]
                EXPORT  IIC2_ERI_IRQHandler                  [WEAK]
                EXPORT  SSI0_TXI_IRQHandler                  [WEAK]
                EXPORT  SSI0_RXI_IRQHandler                  [WEAK]
                EXPORT  SSI0_INT_IRQHandler                  [WEAK]
                EXPORT  SRC_INPUT_FIFO_EMPTY_IRQHandler      [WEAK]
                EXPORT  SRC_OUTPUT_FIFO_FULL_IRQHandler      [WEAK]
                EXPORT  SRC_OUTPUT_FIFO_OVERFLOW_IRQHandler  [WEAK]
                EXPORT  SRC_OUTPUT_FIFO_UNDERFLOW_IRQHandler [WEAK]
                EXPORT  SRC_CONVERSION_END_IRQHandler        [WEAK]
                EXPORT  PDC_RECEIVE_DATA_READY_IRQHandler    [WEAK]
                EXPORT  PDC_FRAME_END_IRQHandler             [WEAK]
                EXPORT  PDC_INT_IRQHandler                   [WEAK]
                EXPORT  CTSU_WRITE_IRQHandler                [WEAK]
                EXPORT  CTSU_READ_IRQHandler                 [WEAK]
                EXPORT  CTSU_END_IRQHandler                  [WEAK]
                EXPORT  KEY_INT_IRQHandler                   [WEAK]
                EXPORT  DOC_INT_IRQHandler                   [WEAK]
                EXPORT  CAC_FREQUENCY_ERROR_IRQHandler       [WEAK]
                EXPORT  CAC_MEASUREMENT_END_IRQHandler       [WEAK]
                EXPORT  CAC_OVERFLOW_IRQHandler              [WEAK]
                EXPORT  CAN0_ERROR_IRQHandler                [WEAK]
                EXPORT  CAN0_FIFO_RX_IRQHandler              [WEAK]
                EXPORT  CAN0_FIFO_TX_IRQHandler              [WEAK]
                EXPORT  CAN0_MAILBOX_RX_IRQHandler           [WEAK]
                EXPORT  CAN0_MAILBOX_TX_IRQHandler           [WEAK]
                EXPORT  CAN1_ERROR_IRQHandler                [WEAK]
                EXPORT  CAN1_FIFO_RX_IRQHandler              [WEAK]
                EXPORT  CAN1_FIFO_TX_IRQHandler              [WEAK]
                EXPORT  CAN1_MAILBOX_RX_IRQHandler           [WEAK]
                EXPORT  CAN1_MAILBOX_TX_IRQHandler           [WEAK]
                EXPORT  IOPORT_EVENT_1_IRQHandler            [WEAK]
                EXPORT  IOPORT_EVENT_2_IRQHandler            [WEAK]
                EXPORT  IOPORT_EVENT_3_IRQHandler            [WEAK]
                EXPORT  IOPORT_EVENT_4_IRQHandler            [WEAK]
                EXPORT  ELC_SOFTWARE_EVENT_0_IRQHandler      [WEAK]
                EXPORT  ELC_SOFTWARE_EVENT_1_IRQHandler      [WEAK]
                EXPORT  POEG0_EVENT_IRQHandler               [WEAK]
                EXPORT  POEG1_EVENT_IRQHandler               [WEAK]
                EXPORT  POEG2_EVENT_IRQHandler               [WEAK]
                EXPORT  POEG3_EVENT_IRQHandler               [WEAK]
                EXPORT  GPT0_CAPTURE_COMPARE_A_IRQHandler    [WEAK]
                EXPORT  GPT0_CAPTURE_COMPARE_B_IRQHandler    [WEAK]
                EXPORT  GPT0_COMPARE_C_IRQHandler            [WEAK]
                EXPORT  GPT0_COMPARE_D_IRQHandler            [WEAK]
                EXPORT  GPT0_COMPARE_E_IRQHandler            [WEAK]
                EXPORT  GPT0_COMPARE_F_IRQHandler            [WEAK]
                EXPORT  GPT0_COUNTER_OVERFLOW_IRQHandler     [WEAK]
                EXPORT  GPT0_COUNTER_UNDERFLOW_IRQHandler    [WEAK]
                EXPORT  GPT0_AD_TRIG_A_IRQHandler            [WEAK]
                EXPORT  GPT0_AD_TRIG_B_IRQHandler            [WEAK]
                EXPORT  GPT1_CAPTURE_COMPARE_A_IRQHandler    [WEAK]
                EXPORT  GPT1_CAPTURE_COMPARE_B_IRQHandler    [WEAK]
                EXPORT  GPT1_COMPARE_C_IRQHandler            [WEAK]
                EXPORT  GPT1_COMPARE_D_IRQHandler            [WEAK]
                EXPORT  GPT1_COMPARE_E_IRQHandler            [WEAK]
                EXPORT  GPT1_COMPARE_F_IRQHandler            [WEAK]
                EXPORT  GPT1_COUNTER_OVERFLOW_IRQHandler     [WEAK]
                EXPORT  GPT1_COUNTER_UNDERFLOW_IRQHandler    [WEAK]
                EXPORT  GPT1_AD_TRIG_A_IRQHandler            [WEAK]
                EXPORT  GPT1_AD_TRIG_B_IRQHandler            [WEAK]
                EXPORT  GPT2_CAPTURE_COMPARE_A_IRQHandler    [WEAK]
                EXPORT  GPT2_CAPTURE_COMPARE_B_IRQHandler    [WEAK]
                EXPORT  GPT2_COMPARE_C_IRQHandler            [WEAK]
                EXPORT  GPT2_COMPARE_D_IRQHandler            [WEAK]
                EXPORT  GPT2_COMPARE_E_IRQHandler            [WEAK]
                EXPORT  GPT2_COMPARE_F_IRQHandler            [WEAK]
                EXPORT  GPT2_COUNTER_OVERFLOW_IRQHandler     [WEAK]
                EXPORT  GPT2_COUNTER_UNDERFLOW_IRQHandler    [WEAK]
                EXPORT  GPT2_AD_TRIG_A_IRQHandler            [WEAK]
                EXPORT  GPT2_AD_TRIG_B_IRQHandler            [WEAK]
                EXPORT  GPT3_CAPTURE_COMPARE_A_IRQHandler    [WEAK]
                EXPORT  GPT3_CAPTURE_COMPARE_B_IRQHandler    [WEAK]
                EXPORT  GPT3_COMPARE_C_IRQHandler            [WEAK]
                EXPORT  GPT3_COMPARE_D_IRQHandler            [WEAK]
                EXPORT  GPT3_COMPARE_E_IRQHandler            [WEAK]
                EXPORT  GPT3_COMPARE_F_IRQHandler            [WEAK]
                EXPORT  GPT3_COUNTER_OVERFLOW_IRQHandler     [WEAK]
                EXPORT  GPT3_COUNTER_UNDERFLOW_IRQHandler    [WEAK]
                EXPORT  GPT3_AD_TRIG_A_IRQHandler            [WEAK]
                EXPORT  GPT3_AD_TRIG_B_IRQHandler            [WEAK]
                EXPORT  GPT4_CAPTURE_COMPARE_A_IRQHandler    [WEAK]
                EXPORT  GPT4_CAPTURE_COMPARE_B_IRQHandler    [WEAK]
                EXPORT  GPT4_COMPARE_C_IRQHandler            [WEAK]
                EXPORT  GPT4_COMPARE_D_IRQHandler            [WEAK]
                EXPORT  GPT4_COMPARE_E_IRQHandler            [WEAK]
                EXPORT  GPT4_COMPARE_F_IRQHandler            [WEAK]
                EXPORT  GPT4_COUNTER_OVERFLOW_IRQHandler     [WEAK]
                EXPORT  GPT4_COUNTER_UNDERFLOW_IRQHandler    [WEAK]
                EXPORT  GPT4_AD_TRIG_A_IRQHandler            [WEAK]
                EXPORT  GPT4_AD_TRIG_B_IRQHandler            [WEAK]
                EXPORT  GPT5_CAPTURE_COMPARE_A_IRQHandler    [WEAK]
                EXPORT  GPT5_CAPTURE_COMPARE_B_IRQHandler    [WEAK]
                EXPORT  GPT5_COMPARE_C_IRQHandler            [WEAK]
                EXPORT  GPT5_COMPARE_D_IRQHandler            [WEAK]
                EXPORT  GPT5_COMPARE_E_IRQHandler            [WEAK]
                EXPORT  GPT5_COMPARE_F_IRQHandler            [WEAK]
                EXPORT  GPT5_COUNTER_OVERFLOW_IRQHandler     [WEAK]
                EXPORT  GPT5_COUNTER_UNDERFLOW_IRQHandler    [WEAK]
                EXPORT  GPT5_AD_TRIG_A_IRQHandler            [WEAK]
                EXPORT  GPT5_AD_TRIG_B_IRQHandler            [WEAK]
                EXPORT  GPT6_CAPTURE_COMPARE_A_IRQHandler    [WEAK]
                EXPORT  GPT6_CAPTURE_COMPARE_B_IRQHandler    [WEAK]
                EXPORT  GPT6_COMPARE_C_IRQHandler            [WEAK]
                EXPORT  GPT6_COMPARE_D_IRQHandler            [WEAK]
                EXPORT  GPT6_COMPARE_E_IRQHandler            [WEAK]
                EXPORT  GPT6_COMPARE_F_IRQHandler            [WEAK]
                EXPORT  GPT6_COUNTER_OVERFLOW_IRQHandler     [WEAK]
                EXPORT  GPT6_COUNTER_UNDERFLOW_IRQHandler    [WEAK]
                EXPORT  GPT6_AD_TRIG_A_IRQHandler            [WEAK]
                EXPORT  GPT6_AD_TRIG_B_IRQHandler            [WEAK]
                EXPORT  GPT7_CAPTURE_COMPARE_A_IRQHandler    [WEAK]
                EXPORT  GPT7_CAPTURE_COMPARE_B_IRQHandler    [WEAK]
                EXPORT  GPT7_COMPARE_C_IRQHandler            [WEAK]
                EXPORT  GPT7_COMPARE_D_IRQHandler            [WEAK]
                EXPORT  GPT7_COMPARE_E_IRQHandler            [WEAK]
                EXPORT  GPT7_COMPARE_F_IRQHandler            [WEAK]
                EXPORT  GPT7_COUNTER_OVERFLOW_IRQHandler     [WEAK]
                EXPORT  GPT7_COUNTER_UNDERFLOW_IRQHandler    [WEAK]
                EXPORT  GPT7_AD_TRIG_A_IRQHandler            [WEAK]
                EXPORT  GPT7_AD_TRIG_B_IRQHandler            [WEAK]
                EXPORT  GPT8_CAPTURE_COMPARE_A_IRQHandler    [WEAK]
                EXPORT  GPT8_CAPTURE_COMPARE_B_IRQHandler    [WEAK]
                EXPORT  GPT8_COMPARE_C_IRQHandler            [WEAK]
                EXPORT  GPT8_COMPARE_D_IRQHandler            [WEAK]
                EXPORT  GPT8_COMPARE_E_IRQHandler            [WEAK]
                EXPORT  GPT8_COMPARE_F_IRQHandler            [WEAK]
                EXPORT  GPT8_COUNTER_OVERFLOW_IRQHandler     [WEAK]
                EXPORT  GPT8_COUNTER_UNDERFLOW_IRQHandler    [WEAK]
                EXPORT  GPT9_CAPTURE_COMPARE_A_IRQHandler    [WEAK]
                EXPORT  GPT9_CAPTURE_COMPARE_B_IRQHandler    [WEAK]
                EXPORT  GPT9_COMPARE_C_IRQHandler            [WEAK]
                EXPORT  GPT9_COMPARE_D_IRQHandler            [WEAK]
                EXPORT  GPT9_COMPARE_E_IRQHandler            [WEAK]
                EXPORT  GPT9_COMPARE_F_IRQHandler            [WEAK]
                EXPORT  GPT9_COUNTER_OVERFLOW_IRQHandler     [WEAK]
                EXPORT  GPT9_COUNTER_UNDERFLOW_IRQHandler    [WEAK]
                EXPORT  GPT10_CAPTURE_COMPARE_A_IRQHandler   [WEAK]
                EXPORT  GPT10_CAPTURE_COMPARE_B_IRQHandler   [WEAK]
                EXPORT  GPT10_COMPARE_C_IRQHandler           [WEAK]
                EXPORT  GPT10_COMPARE_D_IRQHandler           [WEAK]
                EXPORT  GPT10_COMPARE_E_IRQHandler           [WEAK]
                EXPORT  GPT10_COMPARE_F_IRQHandler           [WEAK]
                EXPORT  GPT10_COUNTER_OVERFLOW_IRQHandler    [WEAK]
                EXPORT  GPT10_COUNTER_UNDERFLOW_IRQHandler   [WEAK]
                EXPORT  GPT11_CAPTURE_COMPARE_A_IRQHandler   [WEAK]
                EXPORT  GPT11_CAPTURE_COMPARE_B_IRQHandler   [WEAK]
                EXPORT  GPT11_COMPARE_C_IRQHandler           [WEAK]
                EXPORT  GPT11_COMPARE_D_IRQHandler           [WEAK]
                EXPORT  GPT11_COMPARE_E_IRQHandler           [WEAK]
                EXPORT  GPT11_COMPARE_F_IRQHandler           [WEAK]
                EXPORT  GPT11_COUNTER_OVERFLOW_IRQHandler    [WEAK]
                EXPORT  GPT11_COUNTER_UNDERFLOW_IRQHandler   [WEAK]
                EXPORT  GPT12_CAPTURE_COMPARE_A_IRQHandler   [WEAK]
                EXPORT  GPT12_CAPTURE_COMPARE_B_IRQHandler   [WEAK]
                EXPORT  GPT12_COMPARE_C_IRQHandler           [WEAK]
                EXPORT  GPT12_COMPARE_D_IRQHandler           [WEAK]
                EXPORT  GPT12_COMPARE_E_IRQHandler           [WEAK]
                EXPORT  GPT12_COMPARE_F_IRQHandler           [WEAK]
                EXPORT  GPT12_COUNTER_OVERFLOW_IRQHandler    [WEAK]
                EXPORT  GPT12_COUNTER_UNDERFLOW_IRQHandler   [WEAK]
                EXPORT  GPT13_CAPTURE_COMPARE_A_IRQHandler   [WEAK]
                EXPORT  GPT13_CAPTURE_COMPARE_B_IRQHandler   [WEAK]
                EXPORT  GPT13_COMPARE_C_IRQHandler           [WEAK]
                EXPORT  GPT13_COMPARE_D_IRQHandler           [WEAK]
                EXPORT  GPT13_COMPARE_E_IRQHandler           [WEAK]
                EXPORT  GPT13_COMPARE_F_IRQHandler           [WEAK]
                EXPORT  GPT13_COUNTER_OVERFLOW_IRQHandler    [WEAK]
                EXPORT  GPT13_COUNTER_UNDERFLOW_IRQHandler   [WEAK]
                EXPORT  OPS_UVW_EDGE_IRQHandler              [WEAK]
                EXPORT  EDMAC0_EINT_IRQHandler               [WEAK]
                EXPORT  SCI0_RXI_IRQHandler                  [WEAK]
                EXPORT  SCI0_TXI_IRQHandler                  [WEAK]
                EXPORT  SCI0_TEI_IRQHandler                  [WEAK]
                EXPORT  SCI0_ERI_IRQHandler                  [WEAK]
                EXPORT  SCI0_AM_IRQHandler                   [WEAK]
                EXPORT  SCI0_RXI_OR_ERI_IRQHandler           [WEAK]
                EXPORT  SCI1_RXI_IRQHandler                  [WEAK]
                EXPORT  SCI1_TXI_IRQHandler                  [WEAK]
                EXPORT  SCI1_TEI_IRQHandler                  [WEAK]
                EXPORT  SCI1_ERI_IRQHandler                  [WEAK]
                EXPORT  SCI1_AM_IRQHandler                   [WEAK]
                EXPORT  SCI2_RXI_IRQHandler                  [WEAK]
                EXPORT  SCI2_TXI_IRQHandler                  [WEAK]
                EXPORT  SCI2_TEI_IRQHandler                  [WEAK]
                EXPORT  SCI2_ERI_IRQHandler                  [WEAK]
                EXPORT  SCI2_AM_IRQHandler                   [WEAK]
                EXPORT  SCI3_RXI_IRQHandler                  [WEAK]
                EXPORT  SCI3_TXI_IRQHandler                  [WEAK]
                EXPORT  SCI3_TEI_IRQHandler                  [WEAK]
                EXPORT  SCI3_ERI_IRQHandler                  [WEAK]
                EXPORT  SCI3_AM_IRQHandler                   [WEAK]
                EXPORT  SCI4_RXI_IRQHandler                  [WEAK]
                EXPORT  SCI4_TXI_IRQHandler                  [WEAK]
                EXPORT  SCI4_TEI_IRQHandler                  [WEAK]
                EXPORT  SCI4_ERI_IRQHandler                  [WEAK]
                EXPORT  SCI4_AM_IRQHandler                   [WEAK]
                EXPORT  SCI5_RXI_IRQHandler                  [WEAK]
                EXPORT  SCI5_TXI_IRQHandler                  [WEAK]
                EXPORT  SCI5_TEI_IRQHandler                  [WEAK]
                EXPORT  SCI5_ERI_IRQHandler                  [WEAK]
                EXPORT  SCI5_AM_IRQHandler                   [WEAK]
                EXPORT  SCI6_RXI_IRQHandler                  [WEAK]
                EXPORT  SCI6_TXI_IRQHandler                  [WEAK]
                EXPORT  SCI6_TEI_IRQHandler                  [WEAK]
                EXPORT  SCI6_ERI_IRQHandler                  [WEAK]
                EXPORT  SCI6_AM_IRQHandler                   [WEAK]
                EXPORT  SCI7_RXI_IRQHandler                  [WEAK]
                EXPORT  SCI7_TXI_IRQHandler                  [WEAK]
                EXPORT  SCI7_TEI_IRQHandler                  [WEAK]
                EXPORT  SCI7_ERI_IRQHandler                  [WEAK]
                EXPORT  SCI7_AM_IRQHandler                   [WEAK]
                EXPORT  SCI8_RXI_IRQHandler                  [WEAK]
                EXPORT  SCI8_TXI_IRQHandler                  [WEAK]
                EXPORT  SCI8_TEI_IRQHandler                  [WEAK]
                EXPORT  SCI8_ERI_IRQHandler                  [WEAK]
                EXPORT  SCI8_AM_IRQHandler                   [WEAK]
                EXPORT  SCI9_RXI_IRQHandler                  [WEAK]
                EXPORT  SCI9_TXI_IRQHandler                  [WEAK]
                EXPORT  SCI9_TEI_IRQHandler                  [WEAK]
                EXPORT  SCI9_ERI_IRQHandler                  [WEAK]
                EXPORT  SCI9_AM_IRQHandler                   [WEAK]
                EXPORT  SPI0_RXI_IRQHandler                  [WEAK]
                EXPORT  SPI0_TXI_IRQHandler                  [WEAK]
                EXPORT  SPI0_IDLE_IRQHandler                 [WEAK]
                EXPORT  SPI0_ERI_IRQHandler                  [WEAK]
                EXPORT  SPI0_TEI_IRQHandler                  [WEAK]
                EXPORT  SPI1_RXI_IRQHandler                  [WEAK]
                EXPORT  SPI1_TXI_IRQHandler                  [WEAK]
                EXPORT  SPI1_IDLE_IRQHandler                 [WEAK]
                EXPORT  SPI1_ERI_IRQHandler                  [WEAK]
                EXPORT  SPI1_TEI_IRQHandler                  [WEAK]
                EXPORT  QSPI_INT_IRQHandler                  [WEAK]
                EXPORT  SDHIMMC0_ACCS_IRQHandler             [WEAK]
                EXPORT  SDHIMMC0_SDIO_IRQHandler             [WEAK]
                EXPORT  SDHIMMC0_CARD_IRQHandler             [WEAK]
                EXPORT  SDHIMMC0_DMA_REQ_IRQHandler          [WEAK]
                EXPORT  SDHIMMC1_ACCS_IRQHandler             [WEAK]
                EXPORT  SDHIMMC1_SDIO_IRQHandler             [WEAK]
                EXPORT  SDHIMMC1_CARD_IRQHandler             [WEAK]
                EXPORT  SDHIMMC1_DMA_REQ_IRQHandler          [WEAK]
                EXPORT  SCE_PROC_BUSY_IRQHandler             [WEAK]
                EXPORT  SCE_ROMOK_IRQHandler                 [WEAK]
                EXPORT  SCE_LONG_PLG_IRQHandler              [WEAK]
                EXPORT  SCE_TEST_BUSY_IRQHandler             [WEAK]
                EXPORT  SCE_WRRDY_0_IRQHandler               [WEAK]
                EXPORT  SCE_WRRDY_1_IRQHandler               [WEAK]
                EXPORT  SCE_WRRDY_4_IRQHandler               [WEAK]
                EXPORT  SCE_RDRDY_0_IRQHandler               [WEAK]
                EXPORT  SCE_RDRDY_1_IRQHandler               [WEAK]
                EXPORT  SCE_INTEGRATE_WRRDY_IRQHandler       [WEAK]
                EXPORT  SCE_INTEGRATE_RDRDY_IRQHandler       [WEAK]

ICU_IRQ0_IRQHandler
ICU_IRQ1_IRQHandler
ICU_IRQ2_IRQHandler
ICU_IRQ3_IRQHandler
ICU_IRQ4_IRQHandler
ICU_IRQ5_IRQHandler
ICU_IRQ6_IRQHandler
ICU_IRQ7_IRQHandler
ICU_IRQ8_IRQHandler
ICU_IRQ9_IRQHandler
ICU_IRQ10_IRQHandler
ICU_IRQ11_IRQHandler
ICU_IRQ12_IRQHandler
ICU_IRQ13_IRQHandler
ICU_IRQ14_IRQHandler
ICU_IRQ15_IRQHandler
DMAC0_INT_IRQHandler
DMAC1_INT_IRQHandler
DMAC2_INT_IRQHandler
DMAC3_INT_IRQHandler
DMAC4_INT_IRQHandler
DMAC5_INT_IRQHandler
DMAC6_INT_IRQHandler
DMAC7_INT_IRQHandler
DTC_COMPLETE_IRQHandler
DTC_END_IRQHandler
ICU_SNOOZE_CANCEL_IRQHandler
FCU_FIFERR_IRQHandler
FCU_FRDYI_IRQHandler
LVD_LVD1_IRQHandler
LVD_LVD2_IRQHandler
CGC_MOSC_STOP_IRQHandler
LPM_SNOOZE_REQUEST_IRQHandler
AGT0_INT_IRQHandler
AGT0_COMPARE_A_IRQHandler
AGT0_COMPARE_B_IRQHandler
AGT1_INT_IRQHandler
AGT1_COMPARE_A_IRQHandler
AGT1_COMPARE_B_IRQHandler
IWDT_UNDERFLOW_IRQHandler
WDT_UNDERFLOW_IRQHandler
RTC_ALARM_IRQHandler
RTC_PERIOD_IRQHandler
RTC_CARRY_IRQHandler
ADC0_SCAN_END_IRQHandler
ADC0_SCAN_END_B_IRQHandler
ADC0_WINDOW_A_IRQHandler
ADC0_WINDOW_B_IRQHandler
ADC0_COMPARE_MATCH_IRQHandler
ADC0_COMPARE_MISMATCH_IRQHandler
ADC1_SCAN_END_IRQHandler
ADC1_SCAN_END_B_IRQHandler
ADC1_WINDOW_A_IRQHandler
ADC1_WINDOW_B_IRQHandler
ADC1_COMPARE_MATCH_IRQHandler
ADC1_COMPARE_MISMATCH_IRQHandler
ACMPHS0_INT_IRQHandler
ACMPHS1_INT_IRQHandler
ACMPHS2_INT_IRQHandler
ACMPHS3_INT_IRQHandler
ACMPHS4_INT_IRQHandler
ACMPHS5_INT_IRQHandler
USBFS_FIFO_0_IRQHandler
USBFS_FIFO_1_IRQHandler
USBFS_INT_IRQHandler
USBFS_RESUME_IRQHandler
IIC0_RXI_IRQHandler
IIC0_TXI_IRQHandler
IIC0_TEI_IRQHandler
IIC0_ERI_IRQHandler
IIC0_WUI_IRQHandler
IIC1_RXI_IRQHandler
IIC1_TXI_IRQHandler
IIC1_TEI_IRQHandler
IIC1_ERI_IRQHandler
IIC2_RXI_IRQHandler
IIC2_TXI_IRQHandler
IIC2_TEI_IRQHandler
IIC2_ERI_IRQHandler
SSI0_TXI_IRQHandler
SSI0_RXI_IRQHandler
SSI0_INT_IRQHandler
SRC_INPUT_FIFO_EMPTY_IRQHandler
SRC_OUTPUT_FIFO_FULL_IRQHandler
SRC_OUTPUT_FIFO_OVERFLOW_IRQHandler
SRC_OUTPUT_FIFO_UNDERFLOW_IRQHandler
SRC_CONVERSION_END_IRQHandler
PDC_RECEIVE_DATA_READY_IRQHandler
PDC_FRAME_END_IRQHandler
PDC_INT_IRQHandler
CTSU_WRITE_IRQHandler
CTSU_READ_IRQHandler
CTSU_END_IRQHandler
KEY_INT_IRQHandler
DOC_INT_IRQHandler
CAC_FREQUENCY_ERROR_IRQHandler
CAC_MEASUREMENT_END_IRQHandler
CAC_OVERFLOW_IRQHandler
CAN0_ERROR_IRQHandler
CAN0_FIFO_RX_IRQHandler
CAN0_FIFO_TX_IRQHandler
CAN0_MAILBOX_RX_IRQHandler
CAN0_MAILBOX_TX_IRQHandler
CAN1_ERROR_IRQHandler
CAN1_FIFO_RX_IRQHandler
CAN1_FIFO_TX_IRQHandler
CAN1_MAILBOX_RX_IRQHandler
CAN1_MAILBOX_TX_IRQHandler
IOPORT_EVENT_1_IRQHandler
IOPORT_EVENT_2_IRQHandler
IOPORT_EVENT_3_IRQHandler
IOPORT_EVENT_4_IRQHandler
ELC_SOFTWARE_EVENT_0_IRQHandler
ELC_SOFTWARE_EVENT_1_IRQHandler
POEG0_EVENT_IRQHandler
POEG1_EVENT_IRQHandler
POEG2_EVENT_IRQHandler
POEG3_EVENT_IRQHandler
GPT0_CAPTURE_COMPARE_A_IRQHandler
GPT0_CAPTURE_COMPARE_B_IRQHandler
GPT0_COMPARE_C_IRQHandler
GPT0_COMPARE_D_IRQHandler
GPT0_COMPARE_E_IRQHandler
GPT0_COMPARE_F_IRQHandler
GPT0_COUNTER_OVERFLOW_IRQHandler
GPT0_COUNTER_UNDERFLOW_IRQHandler
GPT0_AD_TRIG_A_IRQHandler
GPT0_AD_TRIG_B_IRQHandler
GPT1_CAPTURE_COMPARE_A_IRQHandler
GPT1_CAPTURE_COMPARE_B_IRQHandler
GPT1_COMPARE_C_IRQHandler
GPT1_COMPARE_D_IRQHandler
GPT1_COMPARE_E_IRQHandler
GPT1_COMPARE_F_IRQHandler
GPT1_COUNTER_OVERFLOW_IRQHandler
GPT1_COUNTER_UNDERFLOW_IRQHandler
GPT1_AD_TRIG_A_IRQHandler
GPT1_AD_TRIG_B_IRQHandler
GPT2_CAPTURE_COMPARE_A_IRQHandler
GPT2_CAPTURE_COMPARE_B_IRQHandler
GPT2_COMPARE_C_IRQHandler
GPT2_COMPARE_D_IRQHandler
GPT2_COMPARE_E_IRQHandler
GPT2_COMPARE_F_IRQHandler
GPT2_COUNTER_OVERFLOW_IRQHandler
GPT2_COUNTER_UNDERFLOW_IRQHandler
GPT2_AD_TRIG_A_IRQHandler
GPT2_AD_TRIG_B_IRQHandler
GPT3_CAPTURE_COMPARE_A_IRQHandler
GPT3_CAPTURE_COMPARE_B_IRQHandler
GPT3_COMPARE_C_IRQHandler
GPT3_COMPARE_D_IRQHandler
GPT3_COMPARE_E_IRQHandler
GPT3_COMPARE_F_IRQHandler
GPT3_COUNTER_OVERFLOW_IRQHandler
GPT3_COUNTER_UNDERFLOW_IRQHandler
GPT3_AD_TRIG_A_IRQHandler
GPT3_AD_TRIG_B_IRQHandler
GPT4_CAPTURE_COMPARE_A_IRQHandler
GPT4_CAPTURE_COMPARE_B_IRQHandler
GPT4_COMPARE_C_IRQHandler
GPT4_COMPARE_D_IRQHandler
GPT4_COMPARE_E_IRQHandler
GPT4_COMPARE_F_IRQHandler
GPT4_COUNTER_OVERFLOW_IRQHandler
GPT4_COUNTER_UNDERFLOW_IRQHandler
GPT4_AD_TRIG_A_IRQHandler
GPT4_AD_TRIG_B_IRQHandler
GPT5_CAPTURE_COMPARE_A_IRQHandler
GPT5_CAPTURE_COMPARE_B_IRQHandler
GPT5_COMPARE_C_IRQHandler
GPT5_COMPARE_D_IRQHandler
GPT5_COMPARE_E_IRQHandler
GPT5_COMPARE_F_IRQHandler
GPT5_COUNTER_OVERFLOW_IRQHandler
GPT5_COUNTER_UNDERFLOW_IRQHandler
GPT5_AD_TRIG_A_IRQHandler
GPT5_AD_TRIG_B_IRQHandler
GPT6_CAPTURE_COMPARE_A_IRQHandler
GPT6_CAPTURE_COMPARE_B_IRQHandler
GPT6_COMPARE_C_IRQHandler
GPT6_COMPARE_D_IRQHandler
GPT6_COMPARE_E_IRQHandler
GPT6_COMPARE_F_IRQHandler
GPT6_COUNTER_OVERFLOW_IRQHandler
GPT6_COUNTER_UNDERFLOW_IRQHandler
GPT6_AD_TRIG_A_IRQHandler
GPT6_AD_TRIG_B_IRQHandler
GPT7_CAPTURE_COMPARE_A_IRQHandler
GPT7_CAPTURE_COMPARE_B_IRQHandler
GPT7_COMPARE_C_IRQHandler
GPT7_COMPARE_D_IRQHandler
GPT7_COMPARE_E_IRQHandler
GPT7_COMPARE_F_IRQHandler
GPT7_COUNTER_OVERFLOW_IRQHandler
GPT7_COUNTER_UNDERFLOW_IRQHandler
GPT7_AD_TRIG_A_IRQHandler
GPT7_AD_TRIG_B_IRQHandler
GPT8_CAPTURE_COMPARE_A_IRQHandler
GPT8_CAPTURE_COMPARE_B_IRQHandler
GPT8_COMPARE_C_IRQHandler
GPT8_COMPARE_D_IRQHandler
GPT8_COMPARE_E_IRQHandler
GPT8_COMPARE_F_IRQHandler
GPT8_COUNTER_OVERFLOW_IRQHandler
GPT8_COUNTER_UNDERFLOW_IRQHandler
GPT9_CAPTURE_COMPARE_A_IRQHandler
GPT9_CAPTURE_COMPARE_B_IRQHandler
GPT9_COMPARE_C_IRQHandler
GPT9_COMPARE_D_IRQHandler
GPT9_COMPARE_E_IRQHandler
GPT9_COMPARE_F_IRQHandler
GPT9_COUNTER_OVERFLOW_IRQHandler
GPT9_COUNTER_UNDERFLOW_IRQHandler
GPT10_CAPTURE_COMPARE_A_IRQHandler
GPT10_CAPTURE_COMPARE_B_IRQHandler
GPT10_COMPARE_C_IRQHandler
GPT10_COMPARE_D_IRQHandler
GPT10_COMPARE_E_IRQHandler
GPT10_COMPARE_F_IRQHandler
GPT10_COUNTER_OVERFLOW_IRQHandler
GPT10_COUNTER_UNDERFLOW_IRQHandler
GPT11_CAPTURE_COMPARE_A_IRQHandler
GPT11_CAPTURE_COMPARE_B_IRQHandler
GPT11_COMPARE_C_IRQHandler
GPT11_COMPARE_D_IRQHandler
GPT11_COMPARE_E_IRQHandler
GPT11_COMPARE_F_IRQHandler
GPT11_COUNTER_OVERFLOW_IRQHandler
GPT11_COUNTER_UNDERFLOW_IRQHandler
GPT12_CAPTURE_COMPARE_A_IRQHandler
GPT12_CAPTURE_COMPARE_B_IRQHandler
GPT12_COMPARE_C_IRQHandler
GPT12_COMPARE_D_IRQHandler
GPT12_COMPARE_E_IRQHandler
GPT12_COMPARE_F_IRQHandler
GPT12_COUNTER_OVERFLOW_IRQHandler
GPT12_COUNTER_UNDERFLOW_IRQHandler
GPT13_CAPTURE_COMPARE_A_IRQHandler
GPT13_CAPTURE_COMPARE_B_IRQHandler
GPT13_COMPARE_C_IRQHandler
GPT13_COMPARE_D_IRQHandler
GPT13_COMPARE_E_IRQHandler
GPT13_COMPARE_F_IRQHandler
GPT13_COUNTER_OVERFLOW_IRQHandler
GPT13_COUNTER_UNDERFLOW_IRQHandler
OPS_UVW_EDGE_IRQHandler
EDMAC0_EINT_IRQHandler
SCI0_RXI_IRQHandler
SCI0_TXI_IRQHandler
SCI0_TEI_IRQHandler
SCI0_ERI_IRQHandler
SCI0_AM_IRQHandler
SCI0_RXI_OR_ERI_IRQHandler
SCI1_RXI_IRQHandler
SCI1_TXI_IRQHandler
SCI1_TEI_IRQHandler
SCI1_ERI_IRQHandler
SCI1_AM_IRQHandler
SCI2_RXI_IRQHandler
SCI2_TXI_IRQHandler
SCI2_TEI_IRQHandler
SCI2_ERI_IRQHandler
SCI2_AM_IRQHandler
SCI3_RXI_IRQHandler
SCI3_TXI_IRQHandler
SCI3_TEI_IRQHandler
SCI3_ERI_IRQHandler
SCI3_AM_IRQHandler
SCI4_RXI_IRQHandler
SCI4_TXI_IRQHandler
SCI4_TEI_IRQHandler
SCI4_ERI_IRQHandler
SCI4_AM_IRQHandler
SCI5_RXI_IRQHandler
SCI5_TXI_IRQHandler
SCI5_TEI_IRQHandler
SCI5_ERI_IRQHandler
SCI5_AM_IRQHandler
SCI6_RXI_IRQHandler
SCI6_TXI_IRQHandler
SCI6_TEI_IRQHandler
SCI6_ERI_IRQHandler
SCI6_AM_IRQHandler
SCI7_RXI_IRQHandler
SCI7_TXI_IRQHandler
SCI7_TEI_IRQHandler
SCI7_ERI_IRQHandler
SCI7_AM_IRQHandler
SCI8_RXI_IRQHandler
SCI8_TXI_IRQHandler
SCI8_TEI_IRQHandler
SCI8_ERI_IRQHandler
SCI8_AM_IRQHandler
SCI9_RXI_IRQHandler
SCI9_TXI_IRQHandler
SCI9_TEI_IRQHandler
SCI9_ERI_IRQHandler
SCI9_AM_IRQHandler
SPI0_RXI_IRQHandler
SPI0_TXI_IRQHandler
SPI0_IDLE_IRQHandler
SPI0_ERI_IRQHandler
SPI0_TEI_IRQHandler
SPI1_RXI_IRQHandler
SPI1_TXI_IRQHandler
SPI1_IDLE_IRQHandler
SPI1_ERI_IRQHandler
SPI1_TEI_IRQHandler
QSPI_INT_IRQHandler
SDHIMMC0_ACCS_IRQHandler
SDHIMMC0_SDIO_IRQHandler
SDHIMMC0_CARD_IRQHandler
SDHIMMC0_DMA_REQ_IRQHandler
SDHIMMC1_ACCS_IRQHandler
SDHIMMC1_SDIO_IRQHandler
SDHIMMC1_CARD_IRQHandler
SDHIMMC1_DMA_REQ_IRQHandler
SCE_PROC_BUSY_IRQHandler
SCE_ROMOK_IRQHandler
SCE_LONG_PLG_IRQHandler
SCE_TEST_BUSY_IRQHandler
SCE_WRRDY_0_IRQHandler
SCE_WRRDY_1_IRQHandler
SCE_WRRDY_4_IRQHandler
SCE_RDRDY_0_IRQHandler
SCE_RDRDY_1_IRQHandler
SCE_INTEGRATE_WRRDY_IRQHandler
SCE_INTEGRATE_RDRDY_IRQHandler
                B       .

                ENDP

                ALIGN

;*******************************************************************************
; User Stack and Heap initialization
;*******************************************************************************
;                 IF      :DEF:__MICROLIB

;                 EXPORT  __initial_sp
;                 EXPORT  __heap_base
;                 EXPORT  __heap_limit

;                 ELSE

;                 IMPORT  __use_two_region_memory
;                 EXPORT  __user_initial_stackheap

;__user_initial_stackheap

;                 LDR     R0, =  Heap_Mem
;                 LDR     R1, =(Stack_Mem + Stack_Size)
;                 LDR     R2, = (Heap_Mem +  Heap_Size)
;                 LDR     R3, = Stack_Mem
;                 BX      LR

;                 ALIGN

;                 ENDIF

                 END
