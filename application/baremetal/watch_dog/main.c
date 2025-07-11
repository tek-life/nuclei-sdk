#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "nuclei_sdk_soc.h"

static void WDG_Init(uint32_t ms_timeout)
{
    /* WDG counter clock: APB0CLK_Frequency / 1024 */
    WDG_SetPrescaler(WDG, WDG_Prescaler_1024); 
    /** Set counter reload value to obtain 2s WDG TimeOut.
      *  WDG counter clock Frequency = APB0CLK_Frequency / 1024
      *  Counter Reload Value = 2s / WDG counter clock period
      *                       = 2s / (1024 / APB0CLK_Frequency)
      *                       = APB0CLK_Frequency / 512;
      */
    WDG_SetReload(WDG, WDG_PCLK / 1024 / 1000 * ms_timeout);
    WDG_ReloadCounter(WDG);
    /* Enable WDG Systerm reset function when timeout */
    WDG_ResetCMD(WDG, ENABLE);
}

#define FACTOR_US (32U)
void soft_delay_us(uint32_t us)
{
    volatile uint32_t i;
    uint32_t loops = us * FACTOR_US;

    for (i = 0; i < loops; i++) {
        __asm__ __volatile__ ("nop");
    }
}

int main(void)
{

    uint32_t cnt = 0;
    WDG_Init(10000);
    WDG_Start(WDG);
    while (1) {
        printf("Hello World! ...%d\n", cnt++);
        soft_delay_us(3000);
        //WDG_Feed(WDG);
    }

    return 0;
}

