/**
  ******************************************************************************
  * @file    evalsoc_tim.h
  * @author  Driver Team
  * @brief   This file contains all the functions prototypes for the timer firmware 
  *          library.
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __EVALSOC_TIM_H
#define __EVALSOC_TIM_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "t153.h"

/** @addtogroup
  * @{
  */

/** @addtogroup TIM
  * @{
  */

/* Exported types ------------------------------------------------------------*/

/** 
  * @brief TIM Time Base Init structure definition
  * @note  This structure is used with all TIMx.
  */

typedef struct
{
    uint32_t TIM_Prescaler;                  /* Specifies the prescaler value used to divide the TIM clock.
                                                  This parameter can be a number between 0x00 and 0x0F */

    uint32_t TIM_Mode;                       /* Specifies the timer mode, basic or capture input or pwm mode.
                                                  This parameter can be a value of @ref TIM_Mode */

    uint32_t TIM_CountMode;                  /* Specifies the counter mode, one-shot or auto load mode.
                                                  This parameter can be a value of @ref TIM_Counter_Mode */

    uint32_t TIM_Period;                     /* Specifies the period value to the Counter Register.
                                                  This parameter must be a number between 0x0000 and 0xFFFF */

    uint32_t TIM_Compare;                    /* Specifies the compare value to the Compare Register.
                                                  This parameter must be a number between 0x0000 and 0xFFFF */

    uint32_t TIM_OutputNState;               /* Specifies the TIM complementary Output Compare state.
                                                  This parameter can be a value of @ref TIM_Output_Compare_N_State */

    uint32_t TIM_DeadTime;                   /* Specifies the delay time between the switching-off and the switching-on of the outputs.
                                                  This parameter can be a number between 0x00 and 0xFF */
} TIM_InitTypeDef; 

/* Exported constants --------------------------------------------------------*/

/** @defgroup TIM_Exported_constants 
  * @{
  */

#define IS_TIM_PERIPH(PERIPH)                ((PERIPH) == TIM)
/**
  * @}
  */

/** @defgroup TIM_Mode 
  * @{
  */

/* Basic timer, count down mode */
#define TIM_BASIC_MODE                       ((uint32_t)0x00000000)
/* Caputre Input, detect Pulse, Frequecy, Duty cycle */
#define TIM_CAPTURE_MODE                     ((uint32_t)0x00000001)
/* PWM output, Complement Output signal can be valid or invalid */
#define TIM_PWM_MODE                         ((uint32_t)0x00000002)

#define IS_TIM_MODE(MODE)                    (((MODE) == TIM_BASIC_MODE) || \
                                              ((MODE) == TIM_CAPTURE_MODE) || \
                                              ((MODE) == TIM_PWM_MODE))

/**
  * @}
  */

/** @defgroup TIM_Counter_Mode 
  * @{
  */
#define TIM_COUNT_ONESHOT                    ((uint32_t)0x00000000)
#define TIM_COUNT_AUTORELOAD                 ((uint32_t)0x00000020)

#define IS_TIM_COUNTMODE(MODE)               (((MODE) == TIM_COUNT_ONESHOT) || \
                                              ((MODE) == TIM_COUNT_AUTORELOAD))

/**
  * @}
  */

/** @defgroup TIM_Period_Value
  * @{
  */
#define TIM_PERIOD_MIN                       ((uint32_t)0x00000003)
#define TIM_PERIOD_MAX                       ((uint32_t)0xFFFFFFFF)

#define IS_TIM_PERIOD_VALUE(VALUE)           ((VALUE) <= TIM_PERIOD_MAX && \
                                              (VALUE) >= TIM_PERIOD_MIN)

/**
  * @}
  */

/** @defgroup TIM_Compare_Value
  * @{
  */
#define IS_TIM_COMPARE_VALUE(VALUE)          ((VALUE) <= (uint32_t)0xFFFFFFFF)

/**
  * @}
  */

/** @defgroup TIM_Complement_Output_State
  * @{
  */
#define TIM_OUT_N_INVERT_INVALID             ((uint32_t)0x00000000)
#define TIM_OUT_N_INVERT_VALID               ((uint32_t)0x00000010)

#define IS_TIM_OUT_N_INVERT_STATE(STATE)     (((STATE) == TIM_OUT_N_INVERT_INVALID) || \
                                              ((STATE) == TIM_OUT_N_INVERT_VALID))

/**
  * @}
  */

/** @defgroup TIM_Deadzone_State
  * @{
  */
#define TIM_DEADZONE_INVALID                 ((uint8_t)0x00)
#define TIM_DEADZONE_MAX                     ((uint8_t)0xff)
#define IS_TIM_DEADZONE(TIME)                ((TIME) <= TIM_DEADZONE_MAX)

/**
  * @}
  */

/** @defgroup TIM_Prescaler_Value
  * @{
  */
#define TIM_PRESCALER_DIV1                   ((uint8_t)0x00)
#define TIM_PRESCALER_DIV2                   ((uint8_t)0x01)
#define TIM_PRESCALER_DIV4                   ((uint8_t)0x02)
#define TIM_PRESCALER_DIV8                   ((uint8_t)0x03)
#define TIM_PRESCALER_DIV16                  ((uint8_t)0x04)
#define TIM_PRESCALER_DIV32                  ((uint8_t)0x05)
#define TIM_PRESCALER_DIV64                  ((uint8_t)0x06)
#define TIM_PRESCALER_DIV128                 ((uint8_t)0x07)
#define TIM_PRESCALER_DIV256                 ((uint8_t)0x08)
#define TIM_PRESCALER_DIV512                 ((uint8_t)0x09)
#define TIM_PRESCALER_DIV1024                ((uint8_t)0x0A)
#define TIM_PRESCALER_DIV2048                ((uint8_t)0x0B)
#define TIM_PRESCALER_DIV4096                ((uint8_t)0x0C)
#define TIM_PRESCALER_DIV8192                ((uint8_t)0x0D)
#define TIM_PRESCALER_DIV16384               ((uint8_t)0x0E)
#define TIM_PRESCALER_DIV32768               ((uint8_t)0x0F)

#define IS_TIM_PRESCALER_VALUE(VALUE)        ((VALUE) <= TIM_PRESCALER_DIV32768)

/**
  * @}
  */

/** @defgroup TIM_Input_Detection_Mode
  * @{
  */
#define TIM_CAPTURE_PULSE                    ((uint32_t)0x00000004)
#define TIM_CAPTURE_FREQUENCY                ((uint32_t)0x00000080)
#define TIM_CAPTURE_DUTYCYCLE                ((uint32_t)0x00000100)

#define IS_TIM_CAPTURE_MODE(MODE)            (((MODE) == TIM_CAPTURE_PULSE) || \
                                              ((MODE) == TIM_CAPTURE_FREQUENCY) || \
                                              ((MODE) == TIM_CAPTURE_DUTYCYCLE))

/**
  * @}
  */

/** @defgroup TIM_Capture_Detection_Start
  * @{
  */
#define TIM_CAPTURE_PULSE_START              ((uint32_t)0x00000200)
#define TIM_CAPTURE_FREQUENCY_START          ((uint32_t)0x00000400)
#define TIM_CAPTURE_DUTYCYCLE_START          ((uint32_t)0x00000800)

#define IS_TIM_CAPTURE_START(MODE)           (((MODE) == TIM_CAPTURE_PULSE_START) || \
                                              ((MODE) == TIM_CAPTURE_FREQUENCY_START) || \
                                              ((MODE) == TIM_CAPTURE_DUTYCYCLE_START))

/**
  * @}
  */

/** @defgroup TIM_interrupt_sources 
  * @{
  */
#define TIM_IT_UPDATE                        ((uint32_t)0x00001000)
#define TIM_IT_CAPTURE_FREQUENCY             ((uint32_t)0x00002000)
#define TIM_IT_CAPTURE_DUTY                  ((uint32_t)0x00004000)
#define TIM_IT_CAPTURE_RISING                ((uint32_t)0x00008000)
#define TIM_IT_CAPTURE_FALLING               ((uint32_t)0x00010000)
#define TIM_IT_DEADZONE                      ((uint32_t)0x00400000)

#define IS_TIM_IT(IT)                        ((((IT) & (uint32_t)0xFFBE0FFF) == 0) && ((IT) != 0))

#define IS_TIM_GET_IT(IT)                    (((IT) == TIM_IT_UPDATE) || \
                                              ((IT) == TIM_IT_CAPTURE_FREQUENCY) || \
                                              ((IT) == TIM_IT_CAPTURE_DUTY) || \
                                              ((IT) == TIM_IT_CAPTURE_RISING) || \
                                              ((IT) == TIM_IT_CAPTURE_FALLING) || \
                                              ((IT) == TIM_IT_DEADZONE))

/**
  * @}
  */

/** @defgroup TIM_Flags 
  * @{
  */
#define TIM_FLAG_UPDATE                      ((uint16_t)0x0001)
#define TIM_FLAG_DETECT_DUTY                 ((uint16_t)0x0002)
#define TIM_FLAG_DETECT_FREQUENCY            ((uint16_t)0x0004)
#define TIM_FLAG_DETECT_RISING               ((uint16_t)0x0008)
#define TIM_FLAG_DETECT_FALLING              ((uint16_t)0x0010)
#define TIM_FLAG_DEADZONE                    ((uint16_t)0x0020)

#define IS_TIM_CLEAR_FLAG(FLAG)              ((((FLAG) & (uint16_t)0x003F) != 0x00) && ((FLAG) != 0x0000))
#define IS_TIM_GET_FLAG(FLAG)                (((FLAG) == TIM_FLAG_UPDATE) || \
                                              ((FLAG) == TIM_FLAG_DETECT_DUTY) || \
                                              ((FLAG) == TIM_FLAG_DETECT_FREQUENCY) || \
                                              ((FLAG) == TIM_FLAG_DETECT_RISING) || \
                                              ((FLAG) == TIM_FLAG_DETECT_FALLING) || \
                                              ((FLAG) == TIM_FLAG_DEADZONE))


#define TIM_PERIOD_MASK                      ((uint32_t)0xFFFFFFFF)
                                              /**
  * @}
  */

/**
  * @}
  */
/* Exported macro ------------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/

/* TimeBase management ********************************************************/
void TIM_DeInit(TIM_TypeDef* TIMx);
void TIM_Init(TIM_TypeDef *TIMx, TIM_InitTypeDef *TIM_InitStruct);
void TIM_StructInit(TIM_InitTypeDef *TIM_InitStruct);
void TIM_PrescalerConfig(TIM_TypeDef* TIMx, uint16_t Prescaler);
uint16_t TIM_GetPrescaler(TIM_TypeDef* TIMx);
void TIM_ModeConfig(TIM_TypeDef *TIMx, uint32_t Mode);
void TIM_CounterModeConfig(TIM_TypeDef *TIMx, uint32_t CountMode);
void TIM_SetPeriod(TIM_TypeDef *TIMx, uint32_t Period);
uint32_t TIM_GetPeriod(TIM_TypeDef *TIMx);
uint32_t TIM_GetCounter(TIM_TypeDef *TIMx);
void TIM_DebugCmd(TIM_TypeDef *TIMx, FunctionalState NewState);
void TIM_Cmd(TIM_TypeDef* TIMx, FunctionalState NewState);

/* Output Compare management **************************************************/
void TIM_SetCompare(TIM_TypeDef* TIMx, uint32_t Compare);
void TIM_ComplementConfig(TIM_TypeDef *TIMx, uint32_t OutNState);
void TIM_DeadZoneConfig(TIM_TypeDef *TIMx, uint32_t DeadTime);

/* Input Capture management ***************************************************/
void TIM_ICConfig(TIM_TypeDef *TIMx, uint32_t IC_Mode);
void TIM_CaptureCmd(TIM_TypeDef *TIMx, uint32_t TIM_Capture_Start, FunctionalState NewState);
void TIM_PulseCaptureConfig(TIM_TypeDef *TIMx, uint32_t PulseCnt);
uint32_t TIM_GetCapture_Pulse(TIM_TypeDef* TIMx);
uint32_t TIM_GetCapture_Frequency(TIM_TypeDef* TIMx);
uint32_t TIM_GetCapture_DutyCycle(TIM_TypeDef* TIMx);

/* Interrupts and flags management ***************************************/
void TIM_ITConfig(TIM_TypeDef* TIMx, uint32_t TIM_IT, FunctionalState NewState);
uint32_t TIM_GetStatus(TIM_TypeDef *TIMx);
FlagStatus TIM_GetFlagStatus(TIM_TypeDef* TIMx, uint32_t TIM_FLAG);
void TIM_ClearFlag(TIM_TypeDef* TIMx, uint32_t TIM_FLAG);
ITStatus TIM_GetITStatus(TIM_TypeDef* TIMx, uint32_t TIM_IT);
void TIM_ClearITPendingBit(TIM_TypeDef* TIMx, uint32_t TIM_IT);

#ifdef __cplusplus
}
#endif

#endif /*__EVALSOC_TIM_H */