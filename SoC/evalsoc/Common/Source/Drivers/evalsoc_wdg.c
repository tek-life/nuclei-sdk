/**
  ******************************************************************************
  * @file    evalsoc_wdg.c
  * @author  Driver Team
  * @brief   This file provides firmware functions to manage the following  
  *          functionalities of the watchdog(WDG) control peripheral:
  *           + Prescaler and Counter Configuration
  *           + WDG Control 
  *           + WDG Interrupt 
  ******************************************************************************           
  */
/* Includes ------------------------------------------------------------------*/
#include "nuclei_sdk_soc.h"

/** @addtogroup
  * @{
  */

/** @defgroup WDG 
  * @brief watchdog driver modules
  * @{
  */ 
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* RSR register bit mask */
#define RSR_KEY_RELOAD    ((uint32_t)0x00005AB9)

/* Private macro -------------------------------------------------------------*/
/* Exported variables --------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/

/** @defgroup WDG_Exported_Functions
  * @{
  */ 
/** @defgroup WDG_Group0 Prescaler and Counter Configuration
  * @{
  */ 
/**
  * @brief  Set WDG prescaler value.
  * @param  WDGx: where x can be 0 or 1 to select the WDG peripheral.
  * @param  WDG_Prescaler: specifies the WDG Prescaler value.
  *          This parameter can be one of the following values:
  *            @arg WDG_Prescaler_1: IWDG prescaler set to 1
  *            @arg WDG_Prescaler_2: IWDG prescaler set to 2
  *            @arg WDG_Prescaler_4: IWDG prescaler set to 4
  *            @arg WDG_Prescaler_8: IWDG prescaler set to 8
  *            @arg WDG_Prescaler_16: IWDG prescaler set to 16
  *            @arg WDG_Prescaler_32: IWDG prescaler set to 32
  *            @arg WDG_Prescaler_64: IWDG prescaler set to 64
  *            @arg WDG_Prescaler_128: IWDG prescaler set to 128
  *            @arg WDG_Prescaler_256: IWDG prescaler set to 256
  *            @arg WDG_Prescaler_512: IWDG prescaler set to 512
  *            @arg WDG_Prescaler_1024: IWDG prescaler set to 1024
  *            @arg WDG_Prescaler_2048: IWDG prescaler set to 2048
  *            @arg WDG_Prescaler_4096: IWDG prescaler set to 4096
  *            @arg WDG_Prescaler_8192: IWDG prescaler set to 8192
  *            @arg WDG_Prescaler_16384: IWDG prescaler set to 16384
  *            @arg WDG_Prescaler_32768: IWDG prescaler set to 32768
  * @retval None
  */
void WDG_SetPrescaler(WDG_TypeDef* WDGx, uint32_t Prescaler)
{
    
  /* Check the parameters */
  assert_param(IS_WDG_ALL_PERIPH(WDGx));
  assert_param(IS_WDG_PRESCALER(Prescaler));
  WDGx->PRES = Prescaler;
}


/**
  * @brief  Sets WDG Reload value.
  * @param  WDGx: where x can be 0 or 1 to select the WDG peripheral.
  * @param  Load: specifies the WDG Reload value.
  *          This parameter must be a number between 0 and 0xFFFFFFFF.
  * @note   If the Load be set as 0 or 1, the Reload value shuold be change 
  *         to 0x3EF1480 by hardware. 
  * @retval None
  */
void WDG_SetReload(WDG_TypeDef* WDGx, uint32_t Reload)
{
  /* Check the parameters */
  assert_param(IS_WDG_ALL_PERIPH(WDGx));
  assert_param(IS_WDG_RELOAD(Reload));
  WDGx->LOAD = Reload;
}

/**
  * @brief  Sets WDG Early Interrupt Counter value.
  * @param  WDGx: where x can be 0 or 1 to select the WDG peripheral.
  * @param  EarlyCnt: specifies the WDG Early Interrupt counter value.
  *          This parameter must be a number between 0 and 0xFFFFFFFF.
  * @note   The Earlycnt value shuold be Lower than Reload Value. 
  * @retval None
  */
void WDG_SetEarlyCnt(WDG_TypeDef* WDGx, uint32_t EarlyCnt)
{
  /* Check the parameters */
  assert_param(IS_WDG_ALL_PERIPH(WDGx));
  assert_param(IS_WDG_EARLYCNT(EarlyCnt));
  WDGx->EIVR = EarlyCnt;
}
/**
  * @}
  */ 


/** @defgroup WDG_Group1 control function
  * @{
  */ 
/**
  * @brief  Enable or Disable WDG Debug mode.
  * @param  WDGx: where x can be 0 or 1 to select the WDG peripheral.
  * @param  NewState: new state of the WDGx debug mode. 
  *          This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void WDG_DebugCMD(WDG_TypeDef* WDGx, FunctionalState NewState)
{
    
    uint32_t tmpreg = 0;
    
    /* Check the parameters */
    assert_param(IS_WDG_ALL_PERIPH(WDGx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));
  
    tmpreg = WDGx->CR;

    /*  Enable or Disable DDR or USB3 Module Power */
    if (NewState == ENABLE)
    {
    	tmpreg |= (WDG_CR_DBGMODEEN);
    }
    else
    {
    	tmpreg &= (~WDG_CR_DBGMODEEN);
    }

    WDGx->CR = tmpreg;
}

/**
  * @brief  Enable or Disable WDG system reset mode.
  * @param  WDGx: where x can be 0 or 1 to select the WDG peripheral.
  * @param  NewState: new state of the WDGx system reset mode. 
  *          This parameter can be: ENABLE or DISABLE.
  * @note   If enable WDG system reset mode, the chip will be reset 
  *         when WDG timeout.
  * @retval None
  */
void WDG_ResetCMD(WDG_TypeDef* WDGx, FunctionalState NewState)
{
    
    uint32_t tmpreg = 0;
    
    /* Check the parameters */
    assert_param(IS_WDG_ALL_PERIPH(WDGx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));
  
    tmpreg = WDGx->CR;

    /*  Enable or Disable DDR or USB3 Module Power */
    if (NewState == ENABLE)
    {
    	tmpreg |= (WDG_CR_RSTEN);
    }
    else
    {
    	tmpreg &= (~WDG_CR_RSTEN);
    }

    WDGx->CR = tmpreg;
}
/**
  * @}
  */ 

/** @defgroup WDG_Group2 Activation function 
  * @{
  */ 
/**
  * @brief  Enable or Disable WDG.
  * @param  WDGx: where x can be 0 or 1 to select the WDG peripheral.
  * @param  NewState: new state of the WDGx. 
  *          This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void WDG_CMD(WDG_TypeDef* WDGx, FunctionalState NewState)
{
    
    uint32_t tmpreg = 0;
    
    /* Check the parameters */
    assert_param(IS_WDG_ALL_PERIPH(WDGx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));
  
    tmpreg = WDGx->CR;

    /*  Enable or Disable DDR or USB3 Module Power */
    if (NewState == ENABLE)
    {
    	tmpreg |= (WDG_CR_EN);
    }
    else
    {
    	tmpreg &= (~WDG_CR_EN);
    }

    WDGx->CR = tmpreg;
}

/**
  * @brief  Reloads WDG counter with value defined in the reload register
  * @param  WDGx: where x can be 0 or 1 to select the WDG peripheral.
  * @retval None
  */
void WDG_ReloadCounter(WDG_TypeDef* WDGx)
{
    /* Check the parameters */
    assert_param(IS_WDG_ALL_PERIPH(WDGx));
    
    WDGx->RSR = RSR_KEY_RELOAD;
}
/**
  * @}
  */ 

/** @defgroup WDG_Group3 Interrupt function
  * @{
  */
/**
  * @brief  Enable or Disable the specified WDG interrupts.
  * @param  WDGx: where x can be 0 or 1 to select the WDG peripheral.
  * @param  WDG_IT: specifies the I2C interrupts sources to be enabled or disabled. 
  *          This parameter can be any combination of the following values:
  *            @arg WDG_IT_NORMAL: Normal interrupt mask
  *            @arg WDG_IT_EARLY: Early interrupt mask
  * @param  NewState: new state of the WDGx interrupt. 
  *          This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void WDG_ITConfig(WDG_TypeDef* WDGx, uint32_t WDG_IT, FunctionalState NewState)
{
    
    uint32_t tmpreg = 0;
    
    /* Check the parameters */
    assert_param(IS_WDG_ALL_PERIPH(WDGx));
    assert_param(IS_WDG_CONFIG_IT(WDG_IT));
    assert_param(IS_FUNCTIONAL_STATE(NewState));
  
    /*  Enable or Disable WDG interrput */
    if (NewState == ENABLE)
    {
        switch (WDG_IT)
        {
            case 0x1:
                WDGx->CR |= WDG_CR_INTREN;
                break;
            case 0x2:
                WDGx->EICR |= WDG_EICR_EINTREN;
                break;
            case 0x3:
                WDGx->CR |= WDG_CR_INTREN;
                WDGx->EICR |= WDG_EICR_EINTREN;
                break;
            default:
                break;
        }
    }
    else
    {
        switch (WDG_IT)
        {
            case 0x1:
                WDGx->CR &= (~WDG_CR_INTREN);
                break;
            case 0x2:
                WDGx->EICR &= (~WDG_EICR_EINTREN);
                break;
            case 0x3:
                WDGx->CR &= (~WDG_CR_INTREN);
                WDGx->EICR &= (~WDG_EICR_EINTREN);
                break;
            default:
                break;
        }
    }
}

/**
  * @brief  Get WDG interrupt status.
  * @param  WDGx: where x can be 0 or 1 to select the WDG peripheral.
  * @param  WDG_IT: specifies the I2C interrupts sources to be enabled or disabled. 
  *          This parameter can be the following values:
  *            @arg WDG_IT_NORMAL: Normal interrupt flag
  *            @arg WDG_IT_EARLY: Early interrupt flag
  * @retval The value of interrupt status
  *           This parameter can be: SET or RESET
  */
ITStatus WDG_GetITStatus(WDG_TypeDef* WDGx, uint32_t WDG_IT)
{
    ITStatus bitstatus = RESET;    

    /* Check the parameters */
    assert_param(IS_WDG_ALL_PERIPH(WDGx));
    assert_param(IS_WDG_IT(WDG_IT));
   
    if (WDG_IT == WDG_IT_NORMAL)
    {
        bitstatus = ((WDGx->ISR & WDG_ISR_ISR) == 0x1) ? SET : RESET;
    }
    else
    {
        bitstatus = ((WDGx->ISR & WDG_ISR_EISR) == 0x2) ? SET : RESET;
    }
    return bitstatus;
}

/**
  * @brief  Clear WDG interrupt status.
  * @param  WDGx: where x can be 0 or 1 to select the WDG peripheral.
  * @param  WDG_IT: specifies the I2C interrupts sources to be enabled or disabled. 
  *          This parameter can be any combination of the following values:
  *            @arg WDG_IT_NORMAL: Normal interrupt mask
  *            @arg WDG_IT_EARLY: Early interrupt mask

  * @retval None
  */
void WDG_ClearITPendingBit(WDG_TypeDef* WDGx, uint32_t WDG_IT)
{
    
    uint32_t tmpreg = 0;
    
    /* Check the parameters */
    assert_param(IS_WDG_ALL_PERIPH(WDGx));
    assert_param(IS_WDG_CONFIG_IT(WDG_IT));
    
    /* Clear WDG interrput pending status */
    switch (WDG_IT)
    {
        case 0x1:
            WDGx->ICLR = WDG_ICLR_INTRCLR;
            break;
        case 0x2:
            WDGx->EICLR = WDG_EICLR_EINTRCLR;
            break;
        case 0x3:
            WDGx->ICLR = WDG_ICLR_INTRCLR;
            WDGx->EICLR = WDG_EICLR_EINTRCLR;
            break;
        default:
            break;
    }
}

void WDG_Start(WDG_TypeDef* WDGx)
{
    /* ENABLE WDG */ 
    WDG_CMD(WDGx, ENABLE);
}

void WDG_Stop(WDG_TypeDef* WDGx)
{
    /* ENABLE WDG */ 
    WDG_CMD(WDGx, DISABLE);
}

void WDG_Feed(WDG_TypeDef* WDGx)
{
    WDG_ReloadCounter(WDGx);
}
