#include "fsl_device_registers.h"
#include "freertos.h"

void vApplicationIRQHandler(uint32_t ulICCIAR)
{
   //Dispatch IRQ to corresponding registered handler
   SystemIrqHandler(ulICCIAR);
}
