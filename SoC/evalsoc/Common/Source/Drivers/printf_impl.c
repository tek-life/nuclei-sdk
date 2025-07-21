#include <stdio.h>
#include <unistd.h>
#include "nuclei_sdk_soc.h"

#define UART_BASE_ADDRESS ((uint32_t)0x12100000)
UART_TypeDef *DEFAULT_UART = (UART_TypeDef *)UART_BASE_ADDRESS;

#define UART_LCR_DLBA_POS   7
#define UART_LCR_DLBA       (1UL << UART_LCR_DLBA_POS) // Data Latch Access Bit
#define UART_LSR_THRE_POS   5
#define UART_LSR_THRE       (1UL << UART_LSR_THRE_POS)
#define UART_LSR_TEMT_POS   6
#define UART_LSR_TEMT       (1UL << UART_LSR_TEMT_POS)

void UART_PutChar(UART_TypeDef *UART, char c)
{
    UART->LCR &= ~UART_LCR_DLBA;
    while (!(UART->LSR & UART_LSR_THRE));

    UART->DR_OR_DLL = (uint32_t)c;
}

void UART_PutString(UART_TypeDef *UART, const char *str)
{
    while (*str != '\0') {
        UART_PutChar(UART, *str);
        str++;
    }
}

int _write(int file, char *ptr, int len)
{
    int i;
    if (file == STDOUT_FILENO || file == STDERR_FILENO) {
        for (i = 0; i < len; i++) {
            UART_PutChar(DEFAULT_UART, *ptr++);
        }
        return len;
    }
    return -1;
}
