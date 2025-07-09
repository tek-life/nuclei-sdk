/**
  ******************************************************************************
  * @file    Baremetal\Drivers\T690_StdPeriph_Driver\Src\t690_uart.c
  * @author  TIH Driver Team
  * @brief   This file contains all the functions prototypes for the UART
  *          firmware library.
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "t690_uart.h"

/** @addtogroup TIHT690_StdPeriph_Driver
  * @{
  */

/** @defgroup UART
  * @brief UART driver modules
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

#define UART_MDR_MODE_SEL_UART      ((uint32_t)0x00000000)
#define UART_MDR_MODE_SEL_IR        ((uint32_t)0x00000001)


/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

static uint32_t FifoControl = UART_FCR_FIFO_ENABLE;
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup UART_Private_Functions
  * @{
  */

/** @defgroup UART_Group1 Initialization and Configuration functions
  *  @brief   Initialization and Configuration functions
  *
@verbatim
===============================================================================
          ##### Initialization and Configuration functions #####
===============================================================================
    [..]
    This subsection provides a set of functions allowing to initialize the UART.
   +-------------------------------------------------------------+
   | LCR_WL1 bit | LCR_WL0 bit |        Character Length         |
   |-------------|-------------|---------------------------------|
   |       0     |       1     |                 6               |
   |-------------|-------------|---------------------------------|
   |       1     |       0     |                 7               |
   |-------------|-------------|---------------------------------|
   |       1     |       1     |                 8               |
   +-------------------------------------------------------------+

@endverbatim
  * @{
  */

/**
  * @brief  Deinitializes the UARTx peripheral registers to their default reset values.
  * @param  UARTx: where x can be 0, 1, 2, 3, 4, 5, 6, or 7.
  * @retval None
  */
void UART_DeInit(UART_TypeDef* UARTx)
{
//     /* Check the parameters */
//     assert_param(IS_UART_ALL_PERIPH(UARTx));

//     if (UARTx == UART0)
//     {
//     	/* Enable UART0 reset state */
//     	LPRCCL_PeriphResetCmd(LPRCCL_Periph_UART0,ENABLE);
//     	/* Release UART1 from reset state */
//     	LPRCCL_PeriphResetCmd(LPRCCL_Periph_UART0,DISABLE);
//     }
// #ifndef FW_LPCORE
//     else if (UARTx == UART1)
//     {
//         /* Enable UART1 reset state */
//         RCC_GRP1PeriphResetCmd(RCC_GRP1Periph_UART1, ENABLE);
//         /* Release UART1 from reset state */
//         RCC_GRP1PeriphResetCmd(RCC_GRP1Periph_UART1, DISABLE);
//     }
//     else if (UARTx == UART2)
//     {
//         /* Enable UART2 reset state */
//         RCC_GRP1PeriphResetCmd(RCC_GRP1Periph_UART2, ENABLE);
//         /* Release UART2 from reset state */
//         RCC_GRP1PeriphResetCmd(RCC_GRP1Periph_UART2, DISABLE);
//     }
//     else if (UARTx == UART3)
//     {
//         /* Enable UART3 reset state */
//         RCC_GRP1PeriphResetCmd(RCC_GRP1Periph_UART3, ENABLE);
//         /* Release UART3 from reset state */
//         RCC_GRP1PeriphResetCmd(RCC_GRP1Periph_UART3, DISABLE);
//     }
//     else if (UARTx == UART4)
//     {
//         /* Enable UART4 reset state */
//         RCC_GRP1PeriphResetCmd(RCC_GRP1Periph_UART4, ENABLE);
//         /* Release UART4 from reset state */
//         RCC_GRP1PeriphResetCmd(RCC_GRP1Periph_UART4, DISABLE);
//     }
//     else if (UARTx == UART5)
//     {
//         /* Enable UART5 reset state */
//         RCC_GRP1PeriphResetCmd(RCC_GRP1Periph_UART5, ENABLE);
//         /* Release UART5 from reset state */
//         RCC_GRP1PeriphResetCmd(RCC_GRP1Periph_UART5, DISABLE);
//     }
//     else if (UARTx == UART6)
//     {
//         /* Enable UART6 reset state */
//         RCC_GRP1PeriphResetCmd(RCC_GRP1Periph_UART6, ENABLE);
//         /* Release UART6 from reset state */
//         RCC_GRP1PeriphResetCmd(RCC_GRP1Periph_UART6, DISABLE);
//     }
//     else if (UARTx == UART7)
//     {
//         /* Enable UART7 reset state */
//         RCC_GRP1PeriphResetCmd(RCC_GRP1Periph_UART7, ENABLE);
//         /* Release UART7 from reset state */
//         RCC_GRP1PeriphResetCmd(RCC_GRP1Periph_UART7, DISABLE);
//     }
// #endif
}

/**
  * @brief  Initializes the UARTx peripheral according to the specified
  *         parameters in the UART_InitStruct .
  * @param  UARTx: where x can be 0, 1, 2, 3, 4, 5, 6, or 7.
  * @param  UART_InitStruct: pointer to a UART_InitTypeDef structure that contains
  *         the configuration information for the specified UART peripheral.
  * @retval None
  */
void UART_Init(UART_TypeDef* UARTx, UART_InitTypeDef* UART_InitStruct)
{
    volatile uint32_t uartclk;
    uint32_t tmpreg = 0x00;
    uint32_t integerdivider = 0x00;
// #ifndef FW_LPCORE
//     RCC_ClocksTypeDef rcc_clocks;
// #endif
//     LPRCCL_ClocksTypeDef lprccl_clocks;

    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_UART_BAUDRATE(UART_InitStruct->UART_BaudRate));
    assert_param(IS_UART_WORD_LENGTH(UART_InitStruct->UART_WordLength));
    assert_param(IS_UART_STOPBITS(UART_InitStruct->UART_StopBits));
    assert_param(IS_UART_PARITY(UART_InitStruct->UART_Parity));
    assert_param(IS_UART_HARDWARE_FLOW_CONTROL(UART_InitStruct->UART_HardwareFlowControl));

    UARTx->DR_OR_DLL;
    UARTx->LSR;
    /*---------------------- config parity, stop bits, wordlength --------------*/
    tmpreg = UARTx->LCR;
    tmpreg &= ~(UART_LCR_STICK_PARITY | UART_LCR_EVEN_PARITY | UART_LCR_PARITY_ENABLE |
                UART_LCR_STOP_BITS | UART_LCR_WL1 | UART_LCR_WL0);
    tmpreg |= UART_InitStruct->UART_Parity | UART_InitStruct->UART_StopBits |
                    UART_InitStruct->UART_WordLength;
    UARTx->LCR = tmpreg;

    /*------------------------------ config flow_ctl ----------------------------*/
    tmpreg = UARTx->IER_OR_DLM;
    tmpreg &= ~(UART_IER_CTSEN | UART_IER_RTSEN);
    tmpreg |= UART_InitStruct->UART_HardwareFlowControl;
    UARTx->IER_OR_DLM = tmpreg;

    /*--------------------- default is uart mode, not ir mode ------------------*/
    tmpreg = UARTx->MDR;
    tmpreg &= ~UART_MDR_MODE_SEL;
    UARTx->MDR = tmpreg;

    /*--------------------- default fifo is enable -----------------------------*/
    tmpreg = 0;
    tmpreg |= UART_FCR_FIFO_ENABLE;
    UARTx->ISR_OR_FCR = tmpreg;

    /*--------------------- reset tx/rx fifo -----------------------------------*/
    tmpreg = UARTx->ISR_OR_FCR;
    tmpreg |= UART_FCR_TXFIFO_RST;
    tmpreg |= UART_FCR_RXFIFO_RST;
    UARTx->ISR_OR_FCR = tmpreg;

    /*---------------------------- UART BaudRate Configuration -----------------------*/
    /* Configure the UART Baud Rate */
// #ifndef FW_LPCORE
//     RCC_GetClockFreq(&rcc_clocks);
//     LPRCCL_GetClockFreq(&lprccl_clocks, rcc_clocks.LPCLK_Frequency);
// #else
//     LPRCCL_GetClockFreq(&lprccl_clocks, LPOSC);
// #endif
//     switch (ADDR32(UARTx))
//     {
//         case (ADDR32(UART0)):
//         	uartclk = lprccl_clocks.UART0CLK_Frequency;
//             break;
// #ifndef FW_LPCORE
//         case (ADDR32(UART1)):
//         	uartclk = rcc_clocks.UART1CLK_Frequency;
//         	break;
//         case (ADDR32(UART2)):
//         	uartclk = rcc_clocks.UART2CLK_Frequency;
//         	break;
//         case (ADDR32(UART3)):
//         	uartclk = rcc_clocks.UART3CLK_Frequency;
//         	break;
//         case (ADDR32(UART4)):
//         	uartclk = rcc_clocks.UART4CLK_Frequency;
//         	break;
//         case (ADDR32(UART5)):
//         	uartclk = rcc_clocks.UART5CLK_Frequency;
//         	break;
//         case (ADDR32(UART6)):
//         	uartclk = rcc_clocks.UART6CLK_Frequency;
//         	break;
//         case (ADDR32(UART7)):
//         	uartclk = rcc_clocks.UART7CLK_Frequency;
//         	break;
// #endif
//         default:
//         	break;
//     }

    /* calculate to the nearest */
    integerdivider = ((10 * uartclk) / (16 * (UART_InitStruct->UART_BaudRate)));
    integerdivider = (integerdivider + 5) / 10;

    tmpreg = UARTx->LCR;
    tmpreg |= UART_LCR_DLAB;
    UARTx->LCR = tmpreg;

    UARTx->IER_OR_DLM = (integerdivider & 0XFF00) >> 8;
    UARTx->DR_OR_DLL = integerdivider & 0XFF;

    tmpreg &= ~UART_LCR_DLAB;
    UARTx->LCR = tmpreg;
}

/**
  * @brief  Fills each UART_InitStruct member with its default value.
  * @param  UART_InitStruct: pointer to a UART_InitTypeDef structure which will
  *         be initialized.
  * @retval None
  */
void UART_StructInit(UART_InitTypeDef* UART_InitStruct)
{
    /* UART_InitStruct members default value */
    UART_InitStruct->UART_BaudRate = 115200;
    UART_InitStruct->UART_WordLength = UART_WordLength_8b;
    UART_InitStruct->UART_StopBits = UART_StopBits_1;
    UART_InitStruct->UART_Parity = UART_Parity_No;
    UART_InitStruct->UART_HardwareFlowControl = UART_HardwareFlowControl_None;
}

/**
  * @}
  */

/** @defgroup UART_Group2 Data transfers functions
  * @brief   Data transfers functions
  *
@verbatim
===============================================================================
                     ##### Data transfers functions #####
===============================================================================
    [..]
    This subsection provides a set of functions allowing to manage the UART data
    transfers.
@endverbatim
  * @{
  */

/**
  * @brief  Transmits single data through the UARTx peripheral.
  * @param  UARTx: where x can be 0, 1, 2, 3, 4, 5, 6, or 7.
  * @param  Data: the data to transmit.
  * @retval None
  */
void UART_SendData(UART_TypeDef* UARTx, uint8_t Data)
{
    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_UART_DATA(Data));

    /* Transmit Data */
    UARTx->DR_OR_DLL = Data;
}

/**
  * @brief  Returns the most recent received data by the UARTx peripheral.
  * @param  UARTx: where x can be 0, 1, 2, 3, 4, 5, 6, or 7.
  * @retval The received data.
  */
uint8_t UART_ReceiveData(UART_TypeDef* UARTx)
{
    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));

    /* Receive Data */
    return (uint8_t)UARTx->DR_OR_DLL;
}

/**
  * @brief  Transmits single data through the UARTx peripheral.
  * @param  UARTx: where x can be 0, 1, 2, 3, 4, 5, 6, or 7.
  * @param  Data: the data to transmit.
  * @retval None
  */
#ifdef FW_LPCORE
void UART_PutC(UART_TypeDef* UARTx, uint32_t Data)
{
    uint32_t status;

    do {
        status = UARTx->LSR;
        status &= UART_LSR_THR_EMPTY;
    } while (status != UART_LSR_THR_EMPTY);

    /* Transmit Data */
    UARTx->DR_OR_DLL = Data;
}
#else
void UART_PutC(UART_TypeDef* UARTx, uint8_t Data)
{
    uint32_t status;

    do {
        status = UARTx->LSR;
        status &= UART_LSR_THR_EMPTY;
    } while (status != UART_LSR_THR_EMPTY);

    /* Transmit Data */
    UARTx->DR_OR_DLL = Data;
}
#endif
/**
  * @brief  Returns the most recent received data by the UARTx peripheral.
  * @param  UARTx: where x can be 0, 1, 2, 3, 4, 5, 6, or 7.
  * @retval The received data.
  */
uint8_t UART_GetC(UART_TypeDef* UARTx)
{
    uint32_t status;
    do {
        status = UARTx->LSR;
        status &= UART_LSR_DATA_READY;
    } while (status != UART_LSR_DATA_READY);

    return (uint8_t)UARTx->DR_OR_DLL;
}

/**
  * @}
  */

/**
  * @brief  Transmits break characters.
  * @param  UARTx: where x can be 0, 1, 2, 3, 4, 5, 6, or 7.
  * @retval None
  */
void UART_SendBreak(UART_TypeDef* UARTx)
{
    uint32_t tmpreg = 0x00;

    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));

    /* wait until the transmitter is idle */
    while (!(UARTx->LSR & UART_LSR_TRANSMITTER_EMPTY));

    /* Send break characters */
    tmpreg = UARTx->LCR;
    tmpreg |= UART_LCR_SET_BREAK;
    UARTx->LCR = tmpreg;

    /* write any value to start transfer break */
    UART_SendData(UARTx, 0x00);

    /* wait until the transmitter is idle */
    while (UARTx->LSR & UART_LSR_TRANSMITTER_EMPTY);

    /* return normal mode */
    tmpreg &= ~UART_LCR_SET_BREAK;
    UARTx->LCR = tmpreg;
}

/**
  * @brief  Configures the UART's IrDA interface.
  * @param  UARTx: where x can be 1, 2, 3, 4.
  * @param  UART_IrDAMode: specifies the IrDA mode.
  *         This parameter can be one of the following values:
  *            @arg UART_IrDAMode_Tx
  *            @arg UART_IrDAMode_Rx
  *            @arg UART_IrDAMode_TxRx
  * @retval None
  */
void UART_IrDAConfig(UART_TypeDef* UARTx, uint32_t UART_IrDAMode)
{
    uint32_t tmpreg = 0x00;

    /* Check the parameters */
    assert_param(IS_UART_IRDA_PERIPH(UARTx));
    assert_param(IS_UART_IRDA_MODE(UART_IrDAMode));

    /*-------------- config sir mode, tx or rx or txrx ----------*/
    tmpreg = UARTx->ACR;
    tmpreg &= ~(UART_ACR_RX_ENABLE | UART_ACR_TX_ENABLE);
    tmpreg |= UART_IrDAMode;
    UARTx->ACR = tmpreg;
}

/**
  * @brief  Enables or disables the UART's IrDA interface.
  * @param  UARTx: where x can be 1, 2, 3, 4.
  * @param  NewState: new state of the IrDA mode.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void UART_IrDACmd(UART_TypeDef* UARTx, FunctionalState NewState)
{
    uint32_t tmpreg = 0x00;

    /* Check the parameters */
    assert_param(IS_UART_IRDA_PERIPH(UARTx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE)
    {
        /* Enable the IrDA mode by setting the MDR register, switch to sir mode */
        tmpreg = UARTx->MDR;
        tmpreg &= ~UART_MDR_MODE_SEL;
        tmpreg |= UART_MDR_MODE_SEL_IR;
        UARTx->MDR = tmpreg;
    }
    else
    {
        /* Disable the IrDA mode by setting the MDR register, switch to uart mode */
        tmpreg = UARTx->MDR;
        tmpreg &= ~UART_MDR_MODE_SEL;
        tmpreg |= UART_MDR_MODE_SEL_UART;
        UARTx->MDR = tmpreg;
    }
}

/**
  * @brief  Enables or disables the UART's DMA interface.
  *         tx and rx all enable or disable.
  * @param  UARTx: where x can be 1, 2, 3, 4.
  * @param  NewState: new state of the DMA Request sources.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void UART_DMACmd(UART_TypeDef* UARTx, FunctionalState NewState)
{
    uint32_t tmpreg = 0x00;

    /* Check the parameters */
    assert_param(IS_UART_IRDA_PERIPH(UARTx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE)
    {
        tmpreg = UARTx->MCR;
        tmpreg |= UART_MCR_DMA_MODE2;
        UARTx->MCR = tmpreg;

        tmpreg = UARTx->MDR;
        tmpreg |= UART_MDR_DMA_EN;
        UARTx->MDR = tmpreg;
    }
    else
    {
        tmpreg = UARTx->MCR;
        tmpreg &= ~UART_MCR_DMA_MODE2;
        UARTx->MCR = tmpreg;

        tmpreg = UARTx->MDR;
        tmpreg &= ~UART_MDR_DMA_EN;
        UARTx->MDR = tmpreg;
    }
}

/** @defgroup UART_Group3 Interrupts and flags management functions
  *  @brief   Interrupts and flags management functions
  *
@verbatim
===============================================================================
           ##### Interrupts and flags management functions #####
===============================================================================
@endverbatim
  * @{
  */

/**
  * @brief  Enables or disables the specified UART interrupts.
  * @param  UARTx: where x can be 0, 1, 2, 3, 4, 5, 6, or 7.
  * @param  UART_IT: specifies the UART interrupt sources to be enabled or disabled.
  *         This parameter can be one of the following values:
  *            @arg UART_IT_DR:  Data Ready interrupt
  *            @arg UART_IT_TE:  Transmitter Holding empty interrupt
  *            @arg UART_IT_RLS:  Reciever Line Status interrupt
  * @param  NewState: new state of the specified UARTx interrupts.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void UART_ITConfig(UART_TypeDef* UARTx, uint32_t UART_IT, FunctionalState NewState)
{
    uint32_t tmpreg = 0x00;

    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_UART_CONFIG_IT(UART_IT));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE)
    {
        tmpreg = UARTx->IER_OR_DLM;
        tmpreg |= UART_IT;
        UARTx->IER_OR_DLM = tmpreg;
    }
    else
    {
        tmpreg = UARTx->IER_OR_DLM;
        tmpreg &= ~UART_IT;
        UARTx->IER_OR_DLM = tmpreg;
    }
}

/**
  * @brief  Checks whether the specified UART flag is set or not.
  * @param  UARTx: where x can be 1, 2, 3, 4, 5, 6, 7 or 8 to select the UART or
  *         UART peripheral.
  * @param  UART_FLAG: specifies the flag to check.
  *         This parameter can be one of the following values:
  *            @arg UART_FLAG_TX_FIFO_FULL  : txfifo is full flag
  *            @arg UART_FLAG_FIFO_DATA_ERR : fifo data err flag
  *            @arg UART_FLAG_TE            : transmitter empty flag
  *            @arg UART_FLAG_THRE          : transmitter holding register empty flag
  *            @arg UART_FLAG_BI            : break interrupt flag
  *            @arg UART_FLAG_FE            : framing error flag
  *            @arg UART_FLAG_PE            : parity error flag
  *            @arg UART_FLAG_ORE           : overRun error flag
  *            @arg UART_FLAG_DR            : data ready flag
  * @retval The new state of UART_FLAG (SET or RESET).
  */
FlagStatus UART_GetFlagStatus(UART_TypeDef* UARTx, uint32_t UART_FLAG)
{
    FlagStatus bitstatus = RESET;

    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_UART_FLAG(UART_FLAG));

    /* UART_FLAG_TX_FIFO_FULL at special register */
    if (UART_FLAG == UART_FLAG_TX_FIFO_FULL)
    {
        if ((UARTx->ISR_OR_FCR & 0x00000010) != (uint32_t)RESET)
        {
             bitstatus = SET;
        }
        else
        {
            bitstatus = RESET;
        }
        return bitstatus;
    }

    if ((UARTx->LSR & UART_FLAG) != (uint32_t)RESET)
    {
        bitstatus = SET;
    }
    else
    {
        bitstatus = RESET;
    }
    return bitstatus;
}

/**
  * @brief  Clears the UARTx's pending flags.
  * @param  UARTx: where x can be 0, 1, 2, 3, 4, 5, 6, or 7.
  * @param  UART_FLAG: specifies the flag to clear.
  *         This parameter can be any combination of the following values:
  *            @arg UART_FLAG_BI            : break interrupt flag
  *            @arg UART_FLAG_FE            : framing error flag
  *            @arg UART_FLAG_PE            : parity error flag
  *            @arg UART_FLAG_ORE           : overRun error flag
  * @retval None
  */
void UART_ClearFlag(UART_TypeDef* UARTx, uint32_t UART_FLAG)
{
    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_UART_CLEAR_FLAG(UART_FLAG));

    /* do nothing, just read LSR, write to RR is not necessary */
    UARTx->RR = UARTx->LSR;
}

/**
  * @brief  Get interrupt identification register.
  * @param  UARTx: where x can be 0, 1, 2, 3, 4, 5, 6, or 7.
  * @param  UART_IT: specifies the UART interrupt source to check.
  * @retval The value of interrupt identification register.
  */
uint32_t UART_GetIIR(UART_TypeDef* UARTx)
{
    uint32_t tmpreg = 0x00;

    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));

    tmpreg = UARTx->ISR_OR_FCR;

    return tmpreg;
}

/**
  * @brief  Checks whether the specified UART interrupt has occurred or not.
  * @param  UARTx: where x can be 0, 1, 2, 3, 4, 5, 6, or 7.
  * @param  UART_IT: specifies the UART interrupt source to check.
  *         This parameter can be one of the following values:
  *            @arg UART_IT_RLS_STATUS     : Reciever Line Status interrupt
  *            @arg UART_IT_DR_STATUS      : Data Ready interrupt
  *            @arg UART_IT_TIMEOUT_STATUS : Character Reception Timeout interrupt
  *            @arg UART_IT_TE_STATUS      : Transmitter Holding empty interrupt
  *            @arg UART_IT_MODEM_STATUS   : Modem Status interrupt
  * @retval The new state of UART_IT (SET or RESET).
  */
ITStatus UART_GetITStatus(UART_TypeDef* UARTx, uint32_t UART_IT)
{
    uint32_t tmpreg = 0x00;
    ITStatus bitstatus = RESET;

    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_UART_GET_IT(UART_IT));

    tmpreg = UARTx->ISR_OR_FCR;
    tmpreg &= 0xf;

    if (tmpreg == UART_IT)
    {
        bitstatus = SET;
    }
    else
    {
        bitstatus = RESET;
    }

    return bitstatus;
}

/**
  * @brief  Clears the UARTx's interrupt pending bits.
  * @param  UARTx: where x can be 0, 1, 2, 3, 4, 5, 6, or 7.
  * @param  UART_IT: specifies the interrupt pending bit to clear.
  *         This parameter can be one of the following values:
  *            @arg UART_IT_RLS_STATUS     : Reciever Line Status interrupt
  *            @arg UART_IT_TIMEOUT_STATUS : Character Reception Timeout interrupt
  *            @arg UART_IT_MODEM_STATUS   : Modem Status interrupt
  * @retval None
  */
void UART_ClearITPendingBit(UART_TypeDef* UARTx, uint32_t UART_IT)
{
    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_UART_CLEAR_IT(UART_IT));

    if (UART_IT == UART_IT_RLS_STATUS)
    {
        /* do nothing, just read LSR, write to RR is not necessary */
        UARTx->RR = UARTx->DR_OR_DLL;
    }
    if (UART_IT == UART_IT_TIMEOUT_STATUS)
    {
        /* do nothing, just read LSR, write to RR is not necessary */
        UARTx->RR = UARTx->LSR;

        /* RX FIFO reset */
        UARTx->ISR_OR_FCR = FifoControl | UART_FCR_RXFIFO_RST;
    }

    if (UART_IT == UART_IT_MODEM_STATUS)
    {
        /* do nothing, just read MSR, write to RR is not necessary */
        UARTx->RR = UARTx->MSR;
    }
}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/********* (C) COPYRIGHT TIHMicroelectronics *****END OF FILE*****************/
