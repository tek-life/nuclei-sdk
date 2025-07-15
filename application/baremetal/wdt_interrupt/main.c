/**
 * @file main.c
 * @brief This example demostrates how to use wdt early interrupt:
 *        In this example, the watch dog will reset after 10s if no feed. The watch dog early interrupt handle will enter every 5s, when enter the handle, will feed the watchdog, so the device will not reset.
 */

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
    /* Enable WDG early interrupt and set timeout as half of ms_timeout */
    WDG_SetEarlyCnt(WDG, WDG_PCLK / 1024 / 1000 * ms_timeout / 2);
    WDG_ITConfig(WDG, WDG_IT_EARLY, ENABLE);
    
    /* Enable WDG Systerm reset function when timeout */
    WDG_ResetCMD(WDG, ENABLE);
}

static __INTERRUPT void WDG0_EARLY_IRQHandler(void)
{
    if (WDG_GetITStatus(WDG, WDG_IT_EARLY) == SET)
	{
    	printf("WDG early isr\n");
    }
    //RCC_RecordConfig(RCC_RSTREC0, WDG0_RESET_RECORD);
    //printf("WDGRST flag set %x\n", RCC_GetRecord(RCC_RSTREC0));
    WDG_Feed(WDG);
    WDG_ClearITPendingBit(WDG, WDG_IT_EARLY);
}


int main(void)
{
    uint32_t cnt = 0;
    TIM_InitTypeDef TIM_InitStructure;

    /* WDT Init */
    WDG_Init(10000);
    WDG_Start(WDG);

    /* Interrupt initialization */
    Interrupt_Init();
    ECLIC_Register_IRQ(WDT_IRQn, ECLIC_VECTOR_INTERRUPT,
            ECLIC_LEVEL_TRIGGER, 1, 0, WDG0_EARLY_IRQHandler);
    // Enable IRQ
    __enable_irq();
    while (1) {
        ;
    }

    return 0;
}

