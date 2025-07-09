#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

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
    while (1) {
        printf("Hello World! ...%d\n", cnt++);
        soft_delay_us(3000);
    }

    return 0;
}

