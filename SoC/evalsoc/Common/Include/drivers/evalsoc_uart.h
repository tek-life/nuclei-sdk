/**
  ******************************************************************************
  * @file    evalsoc_uart.h
  * @author  Driver Team
  * @brief   This file contains all the functions prototypes for the UART
  *          firmware library.
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __EVALSOC_UART_H
#define __EVALSOC_UART_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "t153.h"

/** @addtogroup
  * @{
  */

/** @addtogroup UART
  * @{
  */

/* Exported types ------------------------------------------------------------*/

/**
  * @brief  UART Init Structure definition
  */

typedef struct
{
    uint32_t UART_BaudRate;                 /* This member configures the UART communication baud rate.
                                                The baud rate is computed using the following formula:
                                                 - UART_BaudRate = ((PCLKx) / (DL * 16)) */

    uint32_t UART_WordLength;               /* Specifies the number of data bits transmitted or received in a frame.
                                                This parameter can be a value of @ref UART_Word_Length */

    uint32_t UART_StopBits;                 /* Specifies the number of stop bits transmitted.
                                                This parameter can be a value of @ref UART_Stop_Bits */

    uint32_t UART_Parity;                   /* Specifies the parity mode.
                                                This parameter can be a value of @ref UART_Parity
                                                @note When parity is enabled, the computed parity is inserted
                                                      at the MSB position of the transmitted data (9th bit when
                                                      the word length is set to 9 data bits; 8th bit when the
                                                      word length is set to 8 data bits). */

    uint32_t UART_HardwareFlowControl;      /* Specifies wether the hardware flow control mode is enabled
                                                or disabled.
                                                This parameter can be a value of @ref UART_Hardware_Flow_Control */
} UART_InitTypeDef;

/* Exported constants --------------------------------------------------------*/

/** @defgroup UART_Exported_Constants
  * @{
  */

#define IS_UART_ALL_PERIPH(PERIPH)          ((PERIPH) == UART0)
#define IS_UART_IRDA_PERIPH(PERIPH)         ((PERIPH) == UART0)

/** @defgroup UART_Word_Length
  * @{
  */
#define UART_WordLength_6b                  ((uint32_t)0x00000001)
#define UART_WordLength_7b                  ((uint32_t)0x00000002)
#define UART_WordLength_8b                  ((uint32_t)0x00000003)
#define IS_UART_WORD_LENGTH(LENGTH)         (((LENGTH) == UART_WordLength_6b) || \
                                             ((LENGTH) == UART_WordLength_7b) || \
                                             ((LENGTH) == UART_WordLength_8b))
/**
  * @}
  */

/** @defgroup UART_Stop_Bits
  * @{
  */

#define UART_StopBits_1                     ((uint32_t)0x00000000)
#define UART_StopBits_2                     ((uint32_t)0x00000004)
#define IS_UART_STOPBITS(STOPBITS)          (((STOPBITS) == UART_StopBits_1) || \
                                             ((STOPBITS) == UART_StopBits_2))
/**
  * @}
  */

/** @defgroup UART_Parity
  * @{
  */

#define UART_Parity_No                      ((uint32_t)0x00000000)
#define UART_Parity_Even                    ((uint32_t)0x00000018)
#define UART_Parity_Odd                     ((uint32_t)0x00000008)
#define IS_UART_PARITY(PARITY)              (((PARITY) == UART_Parity_No) || \
                                             ((PARITY) == UART_Parity_Even) || \
                                             ((PARITY) == UART_Parity_Odd))
/**
  * @}
  */

/** @defgroup UART_Hardware_Flow_Control
  * @{
  */
#define UART_HardwareFlowControl_None       ((uint32_t)0x00000000)
#define UART_HardwareFlowControl_RTS        ((uint32_t)0x00000010)
#define UART_HardwareFlowControl_CTS        ((uint32_t)0x00000020)
#define UART_HardwareFlowControl_RTS_CTS    ((uint32_t)0x00000030)
#define IS_UART_HARDWARE_FLOW_CONTROL(CONTROL)\
                                            (((CONTROL) == UART_HardwareFlowControl_None) || \
                                             ((CONTROL) == UART_HardwareFlowControl_RTS) || \
                                             ((CONTROL) == UART_HardwareFlowControl_CTS) || \
                                             ((CONTROL) == UART_HardwareFlowControl_RTS_CTS))
/**
  * @}
  */

/** @defgroup UART_Interrupt_definition
  * @{
  */
#define UART_IT_DR                          ((uint32_t)0x00000001)
#define UART_IT_TE                          ((uint32_t)0x00000002)
#define UART_IT_RLS                         ((uint32_t)0x00000004)
#define UART_IT_RLS_STATUS                  ((uint32_t)0x00000006)
#define UART_IT_DR_STATUS                   ((uint32_t)0x00000004)
#define UART_IT_TIMEOUT_STATUS              ((uint32_t)0x0000000C)
#define UART_IT_TE_STATUS                   ((uint32_t)0x00000002)
#define UART_IT_MODEM_STATUS                ((uint32_t)0x00000000)
#define IS_UART_CONFIG_IT(IT)               (((IT) == UART_IT_DR) || ((IT) == UART_IT_TE) || \
                                             ((IT) == UART_IT_RLS))
#define IS_UART_GET_IT(IT)                  (((IT) == UART_IT_RLS_STATUS) || ((IT) == UART_IT_DR_STATUS) || \
                                              ((IT) == UART_IT_TIMEOUT_STATUS) || ((IT) == UART_IT_TE_STATUS) || \
                                              ((IT) == UART_IT_MODEM_STATUS))
#define IS_UART_CLEAR_IT(IT)                (((IT) == UART_IT_RLS_STATUS) || ((IT) == UART_IT_TIMEOUT_STATUS) || \
                                              ((IT) == UART_IT_MODEM_STATUS))
/**
  * @}
  */

/** @defgroup UART_IrDA_Mode
  * @{
  */

#define UART_IrDAMode_Tx                    ((uint32_t)0x00000001)
#define UART_IrDAMode_Rx                    ((uint32_t)0x00000002)
#define UART_IrDAMode_TxRx                  ((uint32_t)0x00000003)
#define IS_UART_IRDA_MODE(MODE)             (((MODE) == UART_IrDAMode_Tx) || \
                                             ((MODE) == UART_IrDAMode_Tx) || \
                                             ((MODE) == UART_IrDAMode_TxRx))
/**
  * @}
  */

/** @defgroup UART_Flags
  * @{
  */
#define UART_FLAG_TX_FIFO_FULL              ((uint32_t)0x00000100)
#define UART_FLAG_FIFO_DATA_ERR             ((uint32_t)0x00000080)
#define UART_FLAG_TE                        ((uint32_t)0x00000040)
#define UART_FLAG_THRE                      ((uint32_t)0x00000020)
#define UART_FLAG_BI                        ((uint32_t)0x00000010)
#define UART_FLAG_FE                        ((uint32_t)0x00000008)
#define UART_FLAG_PE                        ((uint32_t)0x00000004)
#define UART_FLAG_ORE                       ((uint32_t)0x00000002)
#define UART_FLAG_DR                        ((uint32_t)0x00000001)
#define IS_UART_FLAG(FLAG)                  (((FLAG) == UART_FLAG_DR) || ((FLAG) == UART_FLAG_ORE) || \
                                              ((FLAG) == UART_FLAG_PE) || ((FLAG) == UART_FLAG_FE) || \
                                              ((FLAG) == UART_FLAG_BI) || ((FLAG) == UART_FLAG_THRE) || \
                                              ((FLAG) == UART_FLAG_TE) || ((FLAG) == UART_FLAG_FIFO_DATA_ERR) || \
                                              ((FLAG) == UART_FLAG_TX_FIFO_FULL))

#define IS_UART_CLEAR_FLAG(FLAG)            ((((FLAG) & (uint32_t)0x0000001E) == 0x00) && ((FLAG) != (uint32_t)0x00))
#define IS_UART_BAUDRATE(BAUDRATE)          (((BAUDRATE) > 0) && ((BAUDRATE) < 3125001))
#define IS_UART_DATA(DATA)                  ((DATA) <= 0xFF)

/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/

/* Function used to set the UART configuration to the default reset state *****/
void UART_DeInit(UART_TypeDef* UARTx);

/* Initialization and Configuration functions *********************************/
void UART_Init(UART_TypeDef* UARTx, UART_InitTypeDef* UART_InitStruct);
void UART_StructInit(UART_InitTypeDef* UART_InitStruct);

/* Data transfers functions ***************************************************/
void UART_SendData(UART_TypeDef* UARTx, uint8_t Data);
uint8_t UART_ReceiveData(UART_TypeDef* UARTx);
#ifdef FW_LPCORE
void UART_PutC(UART_TypeDef* UARTx, uint32_t Data);
#else
void UART_PutC(UART_TypeDef* UARTx, uint8_t Data);
#endif
uint8_t UART_GetC(UART_TypeDef* UARTx);

void UART_SendBreak(UART_TypeDef* UARTx);

/* IrDA mode functions ********************************************************/
void UART_IrDAConfig(UART_TypeDef* UARTx, uint32_t UART_IrDAMode);
void UART_IrDACmd(UART_TypeDef* UARTx, FunctionalState NewState);

/* DMA transfers management functions *****************************************/
void UART_DMACmd(UART_TypeDef* UARTx, FunctionalState NewState);

/* Interrupts and flags management functions **********************************/
void UART_ITConfig(UART_TypeDef* UARTx, uint32_t UART_IT, FunctionalState NewState);
FlagStatus UART_GetFlagStatus(UART_TypeDef* UARTx, uint32_t UART_FLAG);
void UART_ClearFlag(UART_TypeDef* UARTx, uint32_t UART_FLAG);
uint32_t UART_GetIIR(UART_TypeDef* UARTx);
ITStatus UART_GetITStatus(UART_TypeDef* UARTx, uint32_t UART_IT);
void UART_ClearITPendingBit(UART_TypeDef* UARTx, uint32_t UART_IT);

#ifdef __cplusplus
}
#endif

#endif /* __EVALSOC_UART_H */
