/**
  ******************************************************************************
  * @file    evalsoc_tim.c
  * @author  Driver Team
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of the TIM peripheral:
  *            + TimeBase management
  *            + PWM Output management
  *            + Input Capture management
  *            + Interrupts and flags management
  @verbatim
 ===============================================================================
                   #####  How to use this driver #####
 ===============================================================================
    [..]
    This driver provides functions to configure and program the TIM.
    These functions are split in following groups: 
      (#) TIM TimeBase management: this group includes all needed functions 
          to configure the Timebase unit:
        (++) Set/Get Prescaler
        (++) Set/Get Autoreload value
        (++) Counter modes configuration
        (++) Update Request Configuration
        (++) Enable/Disable the counter
      (#) TIM PWM Output management: this group configure the Compare
          unit used in PWM Output mode:
        (++) the complementary channel output invert configuration
        (++) Set the Compare register values
        (++) dead zone Configuration
      (#) TIM Input Capture management: this group configure the Capture 
          unit used in Input Capture mode:
        (++) Configure the input capture mode
        (++) Get the Capture values
      (#) TIM interrupts and flags management
        (++) Enable/Disable interrupt sources
        (++) Get flags status
        (++) Clear flags/ Pending bits
  @endverbatim
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "nuclei_sdk_soc.h"

/** @addtogroup
  * @{
  */

/** @defgroup TIM
  * @brief TIM driver modules
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

#define CR_CAPTURE_MODE_MASK                 ((uint32_t)0xFFFFFE7B)
#define CR_DEAD_LEN_MASK                     ((uint32_t)0x00FFFFFF)


/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup TIM_Private_Functions
  * @{
  */

/** @defgroup TimeBase management functions
  * @brief    TimeBase management functions
  *
@verbatim
 ===============================================================================
                     ##### TimeBase management functions #####
 ===============================================================================
               ##### TIM Driver: how to use it in Time Mode #####
 ===============================================================================
    [..]
    To use the Timer in Time base mode, the following steps are mandatory:
      (#) Enable TIM clock using 
          RCC_GRP0PeriphClockCmd(RCC_GRP0Periph_WDGTIM0, ENABLE);
          RCC_GRP0PeriphClockCmd(RCC_GRP0Periph_WDGTIM1, ENABLE);
      (#) Fill the TIM_InitStruct with the desired parameters.
      (#) Call TIM_TimeBaseInit(TIMx, &TIM_InitStruct) to configure the Time 
          Base unit with the corresponding configuration
      (#) Enable the corresponding interrupt using the function 
          TIM_ITConfig(TIMx, TIM_IT_Update)
      (#) Call the TIM_Cmd(ENABLE) function to enable the TIM counter.
       -@- All other functions can be used separately to modify, if needed,
           a specific feature of the Timer.
@endverbatim
  * @{
  */

/**
  * @brief  Deinitializes the TIMx peripheral registers to their default 
  *         reset values.
  * @param  TIMx: where x can be 0 to 15 to select the TIM peripheral.
  * @retval None
  */
void TIM_DeInit(TIM_TypeDef *TIMx)
{
    /* Check the parameters */
    assert_param(IS_TIM_PERIPH(TIMx));
    TIMx->ISR = 0x3f;
    TIMx->PRES = 0;
    TIMx->CR = 0;
    TIMx->CNTB = TIM_PERIOD_MAX;
    TIMx->CMPB = TIM_PERIOD_MAX;
}

/**
  * @brief  Initializes the TIMx Time Unit peripheral according to 
  *         the specified parameters in the TIM_InitStruct.
  * @param  TIMx: where x can be  0 to 15 to select the TIM peripheral.
  * @param  TIM_InitStruct: pointer to a TIM_InitTypeDef structure
  *         that contains the configuration information for the specified 
  *         TIM peripheral.
  * @retval None
  */
void TIM_Init(TIM_TypeDef *TIMx, TIM_InitTypeDef *TIM_InitStruct)
{
    uint32_t tmpcr = 0;

    /* Check the parameters */
    assert_param(IS_TIM_PERIPH(TIMx));
    assert_param(IS_TIM_PRESCALER_VALUE(TIM_InitStruct->TIM_Prescaler));
    assert_param(IS_TIM_MODE(TIM_InitStruct->TIM_Mode));
    assert_param(IS_TIM_COUNTMODE(TIM_InitStruct->TIM_CountMode));
    assert_param(IS_TIM_PERIOD_VALUE(TIM_InitStruct->TIM_Period));
    assert_param(IS_TIM_COMPARE_VALUE(TIM_InitStruct->TIM_Compare));
    assert_param(IS_TIM_OUT_N_INVERT_STATE(TIM_InitStruct->TIM_OutputNState));
    assert_param(IS_TIM_DEADZONE(TIM_InitStruct->TIM_DeadTime));

    /* Set the Prescaler value */
    TIMx->PRES = TIM_InitStruct->TIM_Prescaler;
    /* Set the Autoreload value */
    TIMx->CNTB = TIM_InitStruct->TIM_Period;
    /* Set the Compare Register value */
    TIMx->CMPB = TIM_InitStruct->TIM_Compare;

    /* TIM CR Configuration */
    tmpcr = TIMx->CR;

    /* Select the Tim Mode */
    tmpcr &= ~TIM_CR_MOD;
    tmpcr |= TIM_InitStruct->TIM_Mode;

    /* Select the Tim Count Mode */
    tmpcr &= ~TIM_CR_AUTO_RELOAD;
    tmpcr |= TIM_InitStruct->TIM_CountMode;

    tmpcr &= ~TIM_OUT_N_INVERT_VALID;
    tmpcr |= TIM_InitStruct->TIM_OutputNState;

    tmpcr &= CR_DEAD_LEN_MASK;
    tmpcr |= (TIM_InitStruct->TIM_DeadTime << 24);

    TIMx->CR = tmpcr;
}

/**
  * @brief  Fills each TIM_InitStruct member with its default value.
  * @param  TIM_InitStruct : pointer to a TIM_InitTypeDef
  *         structure which will be initialized.
  * @retval None
  */
void TIM_StructInit(TIM_InitTypeDef *TIM_InitStruct)
{
    TIM_InitStruct->TIM_Prescaler = TIM_PRESCALER_DIV1;
    TIM_InitStruct->TIM_Mode = TIM_BASIC_MODE;
    TIM_InitStruct->TIM_CountMode = TIM_COUNT_AUTORELOAD;
    TIM_InitStruct->TIM_Period = TIM_PERIOD_MASK;
    TIM_InitStruct->TIM_Compare = TIM_PERIOD_MASK;
    TIM_InitStruct->TIM_OutputNState = TIM_OUT_N_INVERT_INVALID;
    TIM_InitStruct->TIM_DeadTime = TIM_DEADZONE_INVALID;
}

/**
  * @brief  Configures the TIMx Prescaler.
  * @param  TIMx: where x can be 0 to 15 to select the TIM peripheral.
  * @param  Prescaler: specifies the Prescaler Register value
  * @retval None
  */
void TIM_PrescalerConfig(TIM_TypeDef *TIMx, uint16_t Prescaler)
{
    /* Check the parameters */
    assert_param(IS_TIM_PERIPH(TIMx));
    assert_param(IS_TIM_PRESCALER_VALUE(Prescaler));

    /* Set the Prescaler value */
    TIMx->PRES = Prescaler;
}

/**
  * @brief  Gets the TIMx Prescaler value.
  * @param  TIMx: where x can be 0 to 15 to select the TIM peripheral.
  * @retval Prescaler Register value.
  */
uint16_t TIM_GetPrescaler(TIM_TypeDef *TIMx)
{
    /* Check the parameters */
    assert_param(IS_TIM_PERIPH(TIMx));

    /* Get the Prescaler Register value */
    return TIMx->PRES;
}

/**
  * @brief  Specifies the TIMx Mode to be used.
  * @param  TIMx: where x can be 0 to 15 to select the TIM peripheral.
  * @param  Mode: specifies the Timer Mode to be used
  *          This parameter can be one of the following values:
  *            @arg TIM_BASIC_MODE: TIM Basic mode, Count down
  *            @arg TIM_CAPTURE_MODE: TIM input capture Mode
  *            @arg TIM_PWM_MODE: TIM PWM output Mode
  * @retval None
  */
void TIM_ModeConfig(TIM_TypeDef *TIMx, uint32_t Mode)
{
    uint32_t tmpcr = 0;

    /* Check the parameters */
    assert_param(IS_TIM_PERIPH(TIMx));
    assert_param(IS_TIM_MODE(Mode));

    tmpcr = TIMx->CR;
    /* Reset the mode Bits */
    tmpcr &= ~TIM_CR_MOD;
    /* Set the Timer Mode */
    tmpcr |= Mode;
    /* Write to TIMx CR register */
    TIMx->CR = tmpcr;
}

/**
  * @brief  Set the TIMx's Counter Mode.
  * @param  TIMx: where x can be 0 to 15 to select the TIM peripheral.
  * @param  CountMode: specifies the Tim count Load Mode to be used.
  *          This parameter can be one of the following values:
  *            @arg TIM_COUNT_ONESHOT
  *            @arg TIM_COUNT_AUTORELOAD
  * @retval None
  */
void TIM_CounterModeConfig(TIM_TypeDef *TIMx, uint32_t CountMode)
{
    /* Check the parameters */
    assert_param(IS_TIM_PERIPH(TIMx));
    assert_param(IS_TIM_COUNTMODE(CountMode));

    /* Reset timer auto-reload bit */
    TIMx->CR &= ~TIM_CR_AUTO_RELOAD;
    /* Configure the Timer Load Mode */
    TIMx->CR |= CountMode;
}

/**
  * @brief  Sets the TIMx Period Register value
  * @param  TIMx: where x can be 0 to 15 to select the TIM peripheral
  * @param  Counter: specifies the Period register new value
  * @retval None
  */
void TIM_SetPeriod(TIM_TypeDef *TIMx, uint32_t Period)
{
    /* Check the parameters */
    assert_param(IS_TIM_PERIPH(TIMx));
    assert_param(IS_TIM_PERIOD_VALUE(Period));

    /* Set the Counter Register value */
    TIMx->CNTB = Period;
    /* Manual update generation */
    TIMx->CR |= TIM_CR_IMM_LOAD;
}

/**
  * @brief  Gets the TIMx Period Register value
  * @param  TIMx: where x can be 0 to 15 to select the TIM peripheral
  * @retval the Period register value
  */
uint32_t TIM_GetPeriod(TIM_TypeDef *TIMx)
{
    /* Check the parameters */
    assert_param(IS_TIM_PERIPH(TIMx));

    /* Get the Period Register value */
    return TIMx->CNTB;
}

/**
  * @brief  Gets the TIMx Counter value.
  * @param  TIMx: where x can be 0 to 15 to select the TIM peripheral.
  * @retval Counter Register value
  */
uint32_t TIM_GetCounter(TIM_TypeDef *TIMx)
{
    /* Check the parameters */
    assert_param(IS_TIM_PERIPH(TIMx));

    /* Get the Counter Register value */
    return TIMx->CNTO;
}

/**
  * @brief  Enables or disables the TIM Debug function.
  * @param  TIMx: where x can be 0 to 15 to select the TIM peripheral.
  * @param  NewState: new state of the TIMx Debug Mode.
  *          This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void TIM_DebugCmd(TIM_TypeDef *TIMx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_TIM_PERIPH(TIMx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE)
    {
        /* Enable debug mode */
        TIMx->CR |= TIM_CR_DEBUG_MODE;
    }
    else
    {
        /* Disable debug mode */
        TIMx->CR &= ~TIM_CR_DEBUG_MODE;
    }
}

/**
  * @brief  Enables or disables the specified TIM peripheral.
  * @param  TIMx: where x can be 0 to 15 to select the TIMx peripheral.
  * @param  NewState: new state of the TIMx peripheral.
  *          This parameter can be: ENABLE or DISABLE.
  * @retval None
  * @note   Input Capture mode, please call TIM_CaptureCmd()
  */
void TIM_Cmd(TIM_TypeDef *TIMx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_TIM_PERIPH(TIMx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE)
    {
        /* Enable the TIM Counter and Load immediate update */
        TIMx->CR |= (TIM_CR_START | TIM_CR_IMM_LOAD);
    }
    else
    {
        /* Disable the TIM Counter */
        TIMx->CR &= ~TIM_CR_START;
    }
}

/**
  * @}
  */

/** @defgroup TIM_PWM_MODE, PWM Output management functions
 *  @brief    TIM_PWM_MODE, PWM Output management functions
 *
@verbatim
 ===============================================================================
              ##### PWM Output management functions #####
 ===============================================================================
        ##### TIM Driver: how to use it in PWM Output Mode #####
 ===============================================================================
    [..]
    To use the Timer in PWM Output mode, the following steps are mandatory:
      (#) Enable TIM clock using 
          RCC_GRP0PeriphClockCmd(RCC_GRP0Periph_WDGTIM0, ENABLE);
          RCC_GRP0PeriphClockCmd(RCC_GRP0Periph_WDGTIM1, ENABLE);
      (#) Configure PWM pins by configure the corresponding GPIO pins
      (#) Configure the Time base unit as described in the first part of this 
          driver if needed, else the Timer will run with the default 
          configuration
        (++) Period value = 0xFFFFFFFF
        (++) Compare value = 0x7FFFFFFF
        (++) TIM mode = PWM Mode
        (++) Complement invert mode = Invalid
        (++) Dead time = DeadZone Invalid
        (++) Prescaler value = 0x00000000
      (#) Call the TIM_Cmd(ENABLE) function to enable the TIM counter.
      -@- If the corresponding interrupt are needed, the user should:
        (+@) Enable the NVIC to use the TIM interrupts.
        (+@) Enable the corresponding interrupt using the function 
             TIM_ITConfig(TIMx, TIM_IT_CCx)
@endverbatim
  * @{
  */

/**
  * @brief  Sets the TIMx Compare Register value
  * @param  TIMx: where x can be 0 to 15 to select the TIM peripheral.
  * @param  Compare: specifies the Compare register new value.
  * @retval None
  */
void TIM_SetCompare(TIM_TypeDef *TIMx, uint32_t Compare)
{
    /* Check the parameters */
    assert_param(IS_TIM_PERIPH(TIMx));
    assert_param(IS_TIM_COMPARE_VALUE(Compare));

    /* Set the Compare Register value */
    TIMx->CMPB = Compare;
}

/**
  * @brief  Sets the TIMx Capture Compare Register value
  * @param  TIMx: where x can be 0 to 15 to select the TIM peripheral.
  * @param  Compare: specifies the Capture Compare register new value.
  * @retval None
  */
void TIM_ComplementConfig(TIM_TypeDef *TIMx, uint32_t OutNState)
{
    /* Check the parameters */
    assert_param(IS_TIM_PERIPH(TIMx));
    assert_param(IS_TIM_OUT_N_INVERT_STATE(OutNState));

    /* Set the Complement invert state */
    TIMx->CR &= (uint32_t)(~TIM_CR_INV);
    TIMx->CR |= OutNState;
}

/**
  * @brief  use the Dead Zone feature.
  * @param  TIMx: where x can be  0 to 15 to select the TIM 
  * @param  DeadTime: the dead zone configuration information.
  * @retval None
  */
void TIM_DeadZoneConfig(TIM_TypeDef *TIMx, uint32_t DeadTime)
{
    /* Check the parameters */
    assert_param(IS_TIM_PERIPH(TIMx));
    assert_param(IS_TIM_DEADZONE(DeadTime));

    TIMx->CR &= CR_DEAD_LEN_MASK;
    TIMx->CR |= (DeadTime << 24);
}

/**
  * @}
  */

/** @defgroup Input Capture management functions
 *  @brief    Input Capture management functions
 *
@verbatim
 ===============================================================================
                  ##### Input Capture management functions #####
 ===============================================================================
            ##### TIM Driver: how to use it in Input Capture Mode #####
 ===============================================================================
    [..]
    To use the Timer in Input Capture mode, the following steps are mandatory:
      (#) Enable TIM clock using 
          RCC_GRP0PeriphClockCmd(RCC_GRP0Periph_WDGTIM0, ENABLE);
          RCC_GRP0PeriphClockCmd(RCC_GRP0Periph_WDGTIM1, ENABLE);
      (#) Configure Capture pins by configure the corresponding GPIO pins
      (#) Configure the Time base unit as described in the first part of this 
          driver if needed, else the Timer will run with the default 
          configuration
        (++) Pulse count value = 0xFFFFFFFF
        (++) Tim mode = Capture Mode
        (++) Prescaler value = 0x00000000
      (#) Configure Capture Mode, Enable the Capture.
      (#) Enable the corresponding interrupt to read the Captured value, using 
          the function TIM_ITConfig(TIMx, TIM_IT_CCx) 
      (#) Call the TIM_Cmd(ENABLE) function to enable the TIM counter.
      (#) Use TIM_GetCapture_Pulse(TIMx) to read the captured Pulse counter 
          value.
          Use TIM_GetCapture_Frequency(TIMx) to read the captured Frequency 
          value.
          Use TIM_GetCapture_DutyCycle(TIMx) to read the captured Duty Cycle 
          value.
@endverbatim
  * @{
  */

/**
  * @brief  Sets the TIM Capture Mode.
  * @param  TIMx: where x can be 0 to 15 to select the TIM peripheral.
  * @param  IC_Mode: Configure the Capture mode.
  *          This parameter can be one of the following values:
  *            @arg TIM_CAPTURE_PULSE: Captuer some numbers of Pulse
  *            @arg TIM_CAPTURE_FREQUENCY: Captuer frequecy of Pulse
  *            @arg TIM_CAPTURE_DUTYCYCLE: Captuer duty cycle of Pulse
  * @retval None
  */
void TIM_ICConfig(TIM_TypeDef *TIMx, uint32_t IC_Mode)
{
    /* Check the parameters */
    assert_param(IS_TIM_PERIPH(TIMx));
    assert_param(IS_TIM_CAPTURE_MODE(IC_Mode));

    TIMx->CR &= CR_CAPTURE_MODE_MASK;
    TIMx->CR |= IC_Mode;
}

/**
  * @brief  Enables or disables the specified TIM peripheral.
  * @param  TIMx: where x can be 0 to 15 to select the TIMx peripheral.
  * @param  TIM_Capture_Start: specifies the TIM Capture mode to be enabled or 
  *         disabled.
  *          This parameter can be one of the following values:
  *            @arg TIM_CAPTURE_PULSE_START: the pluse counter detection start
  *            @arg TIM_CAPTURE_FREQUENCY_START: the frequency detection 
  *            function start
  *            @arg TIM_CAPTURE_DUTYCYCLE_START: the duty cycle function 
  *            detection start
  * @param  NewState: new state of the TIM interrupts.This parameter can be: 
  *         ENABLE or DISABLE.
  * @retval None
  */
void TIM_CaptureCmd(TIM_TypeDef *TIMx, uint32_t TIM_Capture_Start, \
                      FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_TIM_PERIPH(TIMx));
    assert_param(IS_TIM_CAPTURE_START(TIM_Capture_Start));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE)
    {
        /* Enable the capture detect start */
        TIMx->CR |= TIM_Capture_Start;
    }
    else
    {
        /* Disable the capture detect */
        TIMx->CR &= ~TIM_Capture_Start;
    }
}

/**
  * @brief  Set the end value of pulse count Register.
  * @param  TIMx: where x can be 0 to 15 to select the TIM peripheral.
  * @retval None.
  */
void TIM_PulseCaptureConfig(TIM_TypeDef *TIMx, uint32_t PulseCnt)
{
    /* Check the parameters */
    assert_param(IS_TIM_PERIPH(TIMx));
    assert_param(IS_TIM_PERIOD_VALUE(PulseCnt));

    /* Set the end value of pulse count Register value */
    TIMx->CNTB = PulseCnt;
}

/**
  * @brief  Gets the TIMx Input Capture value.
  * @param  TIMx: where x can be 0 to 15 to select the TIM peripheral.
  * @retval Pulse detection count Register value.
  */
uint32_t TIM_GetCapture_Pulse(TIM_TypeDef *TIMx)
{
    /* Check the parameters */
    assert_param(IS_TIM_PERIPH(TIMx));

    /* Get the Frequency detection count Register value */
    return TIMx->CNTO;
}

/**
  * @brief  Gets the TIMx Input Capture value.
  * @param  TIMx: where x can be 0 to 15 to select the TIM peripheral.
  * @retval Frequency detection count Register value.
  */
uint32_t TIM_GetCapture_Frequency(TIM_TypeDef *TIMx)
{
    /* Check the parameters */
    assert_param(IS_TIM_PERIPH(TIMx));

    /* Get the Frequency detection count Register value */
    return TIMx->FD;
}
/**
  * @brief  Gets the TIMx Input Capture value.
  * @param  TIMx: where x can be 0 to 15 to select the TIM peripheral.
  * @retval Duty Cycle detection count Register value.
  */
uint32_t TIM_GetCapture_DutyCycle(TIM_TypeDef *TIMx)
{
    /* Check the parameters */
    assert_param(IS_TIM_PERIPH(TIMx));

    /* Get the Duty Cycle detection count Register value */
    return TIMx->DCD;
}

/**
  * @}
  */

/** @defgroup TIM Interrupts and flags management functions
 *  @brief    Interrupts and flags management functions 
 *
@verbatim
 ===============================================================================
          ##### Interrupts and flags management functions #####
 ===============================================================================

@endverbatim
  * @{
  */

/**
  * @brief  Enables or disables the specified TIM interrupts.
  * @param  TIMx: where x can be 0 to 15 to select the TIMx peripheral.
  * @param  TIM_IT: specifies the TIM interrupts sources to be enabled or 
  *         disabled.
  *          This parameter can be any combination of the following values:
  *            @arg TIM_IT_UPDATE: TIM update Interrupt source
  *            @arg TIM_IT_DETECT_FREQUENCY: At the Input-Detection mode，
  *            frequency detection Interrupt source
  *            @arg TIM_IT_DETECT_DUTY: At the Input-Detection mode，duty 
  *            detection Interrupt source
  *            @arg TIM_IT_DETECT_RISING: At the Input-Detection mode，input 
  *            signal rising edge trigger Interrupt source
  *            @arg TIM_IT_DETECT_FALLING: At the Input-Detection mode，input 
  *            signal falling edge trigger Interrupt source
  *            @arg TIM_IT_DEADZONE: PWM dead zone Interrupt source
  * @param  NewState: new state of the TIM interrupts. This parameter can be: 
  *         ENABLE or DISABLE.
  * @retval None
  */
void TIM_ITConfig(TIM_TypeDef *TIMx, uint32_t TIM_IT, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_TIM_PERIPH(TIMx));
    assert_param(IS_TIM_IT(TIM_IT));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE)
    {
        /* Enable the Interrupt sources */
        TIMx->CR |= TIM_IT;
    }
    else
    {
        /* Disable the Interrupt sources */
        TIMx->CR &= ~TIM_IT;
    }
}

/**
  * @brief  Gets the TIMx Status.
  * @param  TIMx: where x can be 0 to 15 to select the TIM peripheral.
  * @retval TIMx Status.
  */
uint32_t TIM_GetStatus(TIM_TypeDef *TIMx)
{
    /* Check the parameters */
    assert_param(IS_TIM_PERIPH(TIMx));

    return TIMx->ISR;
}

/**
  * @brief  Checks whether the specified TIM flag is set or not.
  * @param  TIMx: where x can be 0 to 15 to select the TIM peripheral.
  * @param  TIM_FLAG: specifies the flag to check.
  *          This parameter can be one of the following values:
  *            @arg TIM_FLAG_UPDATE: TIM update Flag
  *            @arg TIM_FLAG_DETECT_DUTY: pulse duty cycle detecting Flag
  *            @arg TIM_FLAG_DETECT_FREQUENCY: freqency detection complete Flag
  *            @arg TIM_FLAG_DETECT_RISING: input signal rising edge trigger 
  *            Flag
  *            @arg TIM_FLAG_DETECT_FALLING: input signal falling edge trigger 
  *            Flag
  *            @arg TIM_FLAG_DEADZONE: Dead zone reach 0 before the last 
  *            tmr_out rising edge Flag
  * @retval The new state of TIM_FLAG (SET or RESET).
  */
FlagStatus TIM_GetFlagStatus(TIM_TypeDef *TIMx, uint32_t TIM_FLAG)
{
    ITStatus bitstatus = RESET;
    /* Check the parameters */
    assert_param(IS_TIM_PERIPH(TIMx));
    assert_param(IS_TIM_GET_FLAG(TIM_FLAG));

    if ((TIMx->ISR & TIM_FLAG) != (uint32_t)RESET)
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
  * @brief  Clears the TIMx's pending flags.
  * @param  TIMx: where x can be 0 to 15 to select the TIM peripheral.
  * @param  TIM_FLAG: specifies the flag bit to clear.
  *          This parameter can be any combination of the following values:
  *            @arg TIM_FLAG_UPDATE: TIM update Flag
  *            @arg TIM_FLAG_DETECT_DUTY: pulse duty cycle detecting Flag
  *            @arg TIM_FLAG_DETECT_FREQUENCY: freqency detection complete Flag
  *            @arg TIM_FLAG_DETECT_RISING: input signal rising edge trigger 
  *            Flag
  *            @arg TIM_FLAG_DETECT_FALLING: input signal falling edge trigger 
  *            Flag
  *            @arg TIM_FLAG_DEADZONE: Dead zone reach 0 before the last 
  *            tmr_out rising edge Flag
  * @retval None
  */
void TIM_ClearFlag(TIM_TypeDef *TIMx, uint32_t TIM_FLAG)
{
    /* Check the parameters */
    assert_param(IS_TIM_PERIPH(TIMx));
    assert_param(IS_TIM_CLEAR_FLAG(TIM_FLAG));

    /* Clear the flags, Type - w1c, write 1 to clear */
    TIMx->ISR = TIM_FLAG;
}

/**
  * @brief  Checks whether the TIM interrupt has occurred or not.
  * @param  TIMx: where x can be 0 to 15 to select the TIM peripheral.
  * @param  TIM_IT: specifies the TIM interrupt source to check.
  *          This parameter can be one of the following values:
  *            @arg TIM_IT_UPDATE: TIM update Interrupt source
  *            @arg TIM_IT_DETECT_FREQUENCY: At the Input-Detection mode，
  *            frequency detection Interrupt source
  *            @arg TIM_IT_DETECT_DUTY: At the Input-Detection mode，duty 
  *            detection Interrupt source
  *            @arg TIM_IT_DETECT_RISING: At the Input-Detection mode，input 
  *            signal rising edge trigger Interrupt source
  *            @arg TIM_IT_DETECT_FALLING: At the Input-Detection mode，input 
  *            signal falling edge trigger Interrupt source
  *            @arg TIM_IT_DEADZONE: PWM dead zone Interrupt source
  * @retval The new state of the TIM_IT(SET or RESET).
  */
ITStatus TIM_GetITStatus(TIM_TypeDef *TIMx, uint32_t TIM_IT)
{
    ITStatus bitstatus = RESET;
    uint32_t itstatus = 0x0;
    uint32_t itenable = 0x0;
    uint32_t TIM_FLAG;

    /* Check the parameters */
    assert_param(IS_TIM_PERIPH(TIMx));
    assert_param(IS_TIM_GET_IT(TIM_IT));

    if(TIM_IT == TIM_IT_DEADZONE)
    {
        TIM_FLAG = TIM_FLAG_DEADZONE;
    }
    else
    {
        TIM_FLAG = (TIM_IT >> 12);
    }
    itstatus = TIMx->ISR & TIM_FLAG;

    itenable = TIMx->CR & TIM_IT;
    if ((itstatus != (uint16_t)RESET) && (itenable != (uint32_t)RESET))
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
  * @brief  Clears the TIMx's interrupt pending bits.
  * @param  TIMx: where x can be 0 to 15 to select the TIM peripheral.
  * @param  TIM_IT: specifies the pending bit to clear.
  *          This parameter can be any combination of the following values:
  *            @arg TIM_IT_UPDATE: TIM update Interrupt source
  *            @arg TIM_IT_DETECT_FREQUENCY: At the Input-Detection mode，
  *            frequency detection Interrupt source
  *            @arg TIM_IT_DETECT_DUTY: At the Input-Detection mode，duty 
  *            detection Interrupt source
  *            @arg TIM_IT_DETECT_RISING: At the Input-Detection mode，input 
  *            signal rising edge trigger Interrupt source
  *            @arg TIM_IT_DETECT_FALLING: At the Input-Detection mode，input 
  *            signal falling edge trigger Interrupt source
  *            @arg TIM_IT_DEADZONE: PWM dead zone Interrupt source
  * @retval None
  */
void TIM_ClearITPendingBit(TIM_TypeDef *TIMx, uint32_t TIM_IT)
{
    __IO uint32_t TIM_FLAG;

    /* Check the parameters */
    assert_param(IS_TIM_PERIPH(TIMx));
    assert_param(IS_TIM_GET_IT(TIM_IT));

    if(TIM_IT == TIM_IT_DEADZONE)
    {
        TIM_FLAG = TIM_FLAG_DEADZONE;
    }
    else
    {
        TIM_FLAG = (TIM_IT >> 12);
    }

    /* Clear the IT pending Bit, Type - w1c, write 1 to clear */
    TIMx->ISR = TIM_FLAG;
}
