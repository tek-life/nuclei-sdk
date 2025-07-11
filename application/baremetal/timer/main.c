#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "nuclei_sdk_soc.h"

/* APB bus clock frequency */
#define APB_BUS_CLK                          100000000
/* TIMx frequency 1HZ */
#define TIMx_FRQUENCY                        1

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
    TIM_InitTypeDef TIM_InitStructure;

    /* TIM Init */
    TIM_DeInit(TIM);
    TIM_InitStructure.TIM_Prescaler = TIM_PRESCALER_DIV1024;
    TIM_InitStructure.TIM_Mode = TIM_BASIC_MODE;
    TIM_InitStructure.TIM_CountMode = TIM_COUNT_AUTORELOAD;
    TIM_InitStructure.TIM_Period = TIM_PERIOD_MASK;
    TIM_InitStructure.TIM_Compare = TIM_PERIOD_MASK;
    TIM_InitStructure.TIM_OutputNState = TIM_OUT_N_INVERT_INVALID;
    TIM_InitStructure.TIM_DeadTime = TIM_DEADZONE_INVALID;

    TIM_Init(TIM, &TIM_InitStructure);
    TIM_Cmd(TIM, ENABLE);
    while (1) {
        printf("Timer counter:%u\n", TIM_GetCounter(TIM));
        soft_delay_us(30000);
    }

    return 0;
}

