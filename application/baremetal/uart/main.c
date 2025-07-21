#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "nuclei_sdk_soc.h"

/**
  * @brief  Configures the UART Peripheral.
  * @param  None
  * @retval None
  */
static void UART_Config(void)
{
    UART_InitTypeDef UART_InitStructure;
    UART_InitStructure.UART_BaudRate = 1000000;
    UART_InitStructure.UART_WordLength = UART_WordLength_8b;
    UART_InitStructure.UART_StopBits = UART_StopBits_1;
    UART_InitStructure.UART_Parity = UART_Parity_No;
    UART_InitStructure.UART_HardwareFlowControl = UART_HardwareFlowControl_None;

    UART_Init(UART0, &UART_InitStructure);
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
    UART_Config();
    while (1) {
        printf("Hello World! ...%d\n", cnt++);
        soft_delay_us(3000);
    }

    return 0;
}

