#ifndef _T153_H
#define _T153_H

#define assert_param(expr) ((void)0)

typedef struct
{
    __IO uint32_t DR_OR_DLL;                             /*!< when LCR_DLBA=0, this is Data Register(RBR/THR);
                                                              when LCR_DLBA=1, this is Divisor Register LSB(DLL),  Address offset: 0x00 */
    __IO uint32_t IER_OR_DLM;                            /*!< when LCR_DLBA=0, this is Interrupt Enable Register;
                                                              when LCR_DLBA=1, this is Divisor Register MSB(DLM),  Address offset: 0x04 */
    __IO uint32_t ISR_OR_FCR;                            /*!< when Read, this is Interrupt Status Register(Read);
                                                              when Write, this is FIFO Control Register(Write),    Address offset: 0x08 */
    __IO uint32_t LCR;                                   /*!< UART Line Control Register,                          Address offset: 0x0C */
    __IO uint32_t MCR;                                   /*!< UART Modem Control Register,                         Address offset: 0x10 */
    __IO uint32_t LSR;                                   /*!< UART Line status Register(Read),                     Address offset: 0x14 */
    __IO uint32_t MSR;                                   /*!< UART Modem Status Register (Read),                   Address offset: 0x18 */
    __IO uint32_t RR;                                    /*!< UART Reserved Register,                              Address offset: 0x1C */

    /* only UART0~3 have the following register */
    __IO uint32_t MDR;                                   /*!< UART Mode Definition Register,                       Address offset: 0x20 */
    __IO uint32_t ACR;                                   /*!< UART Auxiliary Control Register,                     Address offset: 0x24 */
} UART_TypeDef;


/* enum definitions */
#if 0
typedef enum {
    FALSE = 0,
    TRUE = !FALSE
} bool;
#endif

typedef enum {
    RESET = 0,
    SET = !RESET
} FlagStatus, ITStatus;

typedef enum {
    DISABLE = 0,
    ENABLE = !DISABLE
} FunctionalState;

typedef enum {
    ERROR = 0,
    SUCCESS = !ERROR
} ErrorStatus;

#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */
/** @addtogroup Device_Peripheral_peripheralAddr
  * @{
  */
#define UART0_BASE                              (0x12100000)
/** @} */ /* End of group Device_Peripheral_peripheralAddr */

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

/* TODO: add here your device peripherals pointer definitions
         following is an example for uart0 */
/** @addtogroup Device_Peripheral_declaration
  * @{
  */
#define UART0                                   ((UART_TypeDef *) UART0_BASE)

/** @} */ /* End of group Device_Peripheral_declaration */


/* =========================================================================================================================== */
/* ================                   Universal Asynchronous Receiver Transmitter                            ================= */
/* =========================================================================================================================== */
/* ====================== Bit definition for UART_IER register  ================= */
#define UART_IER_CTSEN                      ((uint32_t)0x00000020)        /*!< CTS flow control enable */
#define UART_IER_RTSEN                      ((uint32_t)0x00000010)        /*!< RTS flow control enable */
#define UART_IER_MODEM_STATUS               ((uint32_t)0x00000008)        /*!< modem status interrupt enable */
#define UART_IER_RX_LINE_STATUS             ((uint32_t)0x00000004)        /*!< receive line status interrupt enable */
#define UART_IER_THR_EMPTY                  ((uint32_t)0x00000002)        /*!< transmitter holding register empty interrupt enable */
#define UART_IER_RX_DATA_READY              ((uint32_t)0x00000001)        /*!< receive data available interrupt enable */

/* ====================== Bit definition for UART_ISR register  ================= */
#define UART_ISR_FIFO_MODE_EN               ((uint32_t)0x000000C0)        /*!< these two bits are set when FCR[0] is set to '1' */
#define UART_ISR_TXFIFO_FULL                ((uint32_t)0x00000010)        /*!< this bit is set to '1' when TX FIFO is full */
#define UART_ISR_FIFO_MODE_ONLY             ((uint32_t)0x00000008)        /*!< this bit is set along with bit 2 when a timeout interrupt is pending */

/* ====================== Bit definition for UART_FCR register  ================= */
#define UART_FCR_RXFIFO_TRGL                ((uint32_t)0x000000C0)        /*!< set the trigger level of the RX FIFO interrupt */
#define UART_FCR_TXFIFO_TRGL                ((uint32_t)0x00000030)        /*!< set the trigger level of the TX FIFO interrupt */
#define UART_FCR_DMA_MODE                   ((uint32_t)0x00000008)        /*!< this bit selects the UART DMA mode */
#define UART_FCR_TXFIFO_RST                 ((uint32_t)0x00000004)        /*!< clear all bytes in TX FIFO and resets the counter logic to 0 */
#define UART_FCR_RXFIFO_RST                 ((uint32_t)0x00000002)        /*!< clear all bytes in RX FIFO and resets the counter logic to 0 */
#define UART_FCR_FIFO_ENABLE                ((uint32_t)0x00000001)        /*!< enable both the transmit and the receive FIFOs */

/* ====================== Bit definition for UART_LCR register  ================= */
#define UART_LCR_DLAB                       ((uint32_t)0x00000080)        /*!< divisor latch access bit */
#define UART_LCR_SET_BREAK                  ((uint32_t)0x00000040)        /*!< transmit a break condition */
#define UART_LCR_STICK_PARITY               ((uint32_t)0x00000020)        /*!< parity control */
#define UART_LCR_EVEN_PARITY                ((uint32_t)0x00000010)        /*!< the even parity select bit */
#define UART_LCR_PARITY_ENABLE              ((uint32_t)0x00000008)        /*!< the parity enable bit */
#define UART_LCR_STOP_BITS                  ((uint32_t)0x00000004)        /*!< this bit select the number of stop bits to be transmitted */
#define UART_LCR_WL1                        ((uint32_t)0x00000002)        /*!< this bit along with WL0 defines the word length of data */
#define UART_LCR_WL0                        ((uint32_t)0x00000001)        /*!< this bit along with WL1 defines the word length of data */

/* ====================== Bit definition for UART_MCR register  ================= */
#define UART_MCR_DMA_MODE2                  ((uint32_t)0x00000020)        /*!< this bit selects the UART/SIR DMA mode */
#define UART_MCR_LOOP                       ((uint32_t)0x00000010)        /*!< loopback mode control bit */
#define UART_MCR_RTS                        ((uint32_t)0x00000002)        /*!< this bit controls "request to send" */

/* ====================== Bit definition for UART_LSR register  ================= */
#define UART_LSR_FIFO_DATA_ERROR            ((uint32_t)0x00000080)        /*!< FIFO Data Error */
#define UART_LSR_TRANSMITTER_EMPTY          ((uint32_t)0x00000040)        /*!< Transmitter Empty */
#define UART_LSR_THR_EMPTY                  ((uint32_t)0x00000020)        /*!< THR Empty */
#define UART_LSR_BREAK_INTERRUPT            ((uint32_t)0x00000010)        /*!< Break Interrupt */
#define UART_LSR_FRAMING_ERROR              ((uint32_t)0x00000008)        /*!< Framing Error */
#define UART_LSR_PARITY_ERROR               ((uint32_t)0x00000004)        /*!< Parity Error */
#define UART_LSR_OVERRUN_ERROR              ((uint32_t)0x00000002)        /*!< Overrun Error */
#define UART_LSR_DATA_READY                 ((uint32_t)0x00000001)        /*!< Data Ready */

/* ====================== Bit definition for UART_MSR register  ================= */
#define UART_MSR_CTS                        ((uint32_t)0x00000010)        /*!< clear to send */
#define UART_MSR_DELTA_CTS                  ((uint32_t)0x00000001)        /*!< indicate the CTS pin has changed */

/* ====================== Bit definition for UART_MDR register  ================= */
#define UART_MDR_IR_INV_RX                  ((uint32_t)0x00000020)        /*!< invert SIR pulse during transmission */
#define UART_MDR_DMA_EN                     ((uint32_t)0x00000010)        /*!< when set to "1", the DMA mode of operation is enabled */
#define UART_MDR_MODE_SEL                   ((uint32_t)0x00000001)        /*!< mode select, e.g. UART mode or SIR mode */

/* ====================== Bit definition for UART_ACR register  ================= */
#define UART_ACR_SIR_PW                     ((uint32_t)0x00000080)        /*!< SIR pulse duration selection */
#define UART_ACR_RX_ENABLE                  ((uint32_t)0x00000002)        /*!< enable the data reception in SIR mode */
#define UART_ACR_TX_ENABLE                  ((uint32_t)0x00000001)        /*!< enable the data transmission in SIR mode */


#endif //_T153_H