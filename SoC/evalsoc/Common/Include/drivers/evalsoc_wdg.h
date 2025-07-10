/**
  ******************************************************************************
  * @file    evalsoc_wdg.h
  * @author  Driver Team
  * @brief   This file contains all the functions prototypes for the WDG
  *          firmware library.
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __EVALSOC_WDG_H
#define __EVALSOC_WDG_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "t153.h"

/** @addtogroup 
  * @{
  */

/** @addtogroup WDG
  * @{
  */ 

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
#define IS_WDG_ALL_PERIPH(PERIPH)    ((PERIPH) == WDG)

/** @defgroup WDG_prescaler 
  * @{
  */
#define WDG_Prescaler_1              ((uint32_t)0x00)
#define WDG_Prescaler_2              ((uint32_t)0x01)
#define WDG_Prescaler_4              ((uint32_t)0x02)
#define WDG_Prescaler_8              ((uint32_t)0x03)
#define WDG_Prescaler_16             ((uint32_t)0x04)
#define WDG_Prescaler_32             ((uint32_t)0x05)
#define WDG_Prescaler_64             ((uint32_t)0x06)
#define WDG_Prescaler_128            ((uint32_t)0x07)
#define WDG_Prescaler_256            ((uint32_t)0x08)
#define WDG_Prescaler_512            ((uint32_t)0x09)
#define WDG_Prescaler_1024           ((uint32_t)0x0A)
#define WDG_Prescaler_2048           ((uint32_t)0x0B)
#define WDG_Prescaler_4096           ((uint32_t)0x0C)
#define WDG_Prescaler_8192           ((uint32_t)0x0D)
#define WDG_Prescaler_16384          ((uint32_t)0x0E)
#define WDG_Prescaler_32768          ((uint32_t)0x0F)
#define IS_WDG_PRESCALER(PRESCALER)  (((PRESCALER) == WDG_Prescaler_1)  || \
                                      ((PRESCALER) == WDG_Prescaler_2)  || \
                                      ((PRESCALER) == WDG_Prescaler_4)  || \
                                      ((PRESCALER) == WDG_Prescaler_8)  || \
                                      ((PRESCALER) == WDG_Prescaler_16) || \
                                      ((PRESCALER) == WDG_Prescaler_32) || \
                                      ((PRESCALER) == WDG_Prescaler_64) || \
                                      ((PRESCALER) == WDG_Prescaler_128) || \
                                      ((PRESCALER) == WDG_Prescaler_128) || \
                                      ((PRESCALER) == WDG_Prescaler_256) || \
                                      ((PRESCALER) == WDG_Prescaler_512) || \
                                      ((PRESCALER) == WDG_Prescaler_1024) || \
                                      ((PRESCALER) == WDG_Prescaler_2048) || \
                                      ((PRESCALER) == WDG_Prescaler_4096) || \
                                      ((PRESCALER) == WDG_Prescaler_8192) || \
                                      ((PRESCALER) == WDG_Prescaler_16384) || \
                                      ((PRESCALER) == WDG_Prescaler_32768))
/**
  * @}
  */
#define IS_WDG_RELOAD(RELOAD)         (((RELOAD) <= 0xFFFFFFFF) && ((RELOAD) > 0x1))
#define IS_WDG_EARLYCNT(EARLYCNT)     ((EARLYCNT) <= 0xFFFFFFFF)

/** @defgroup WDG_interrupts_definition 
  * @{
  */

#define WDG_IT_NORMAL                 ((uint32_t)0x1)
#define WDG_IT_EARLY                  ((uint32_t)0x2)
#define IS_WDG_CONFIG_IT(IT)          (((IT) == 0x1) || ((IT) == 0x02) || ((IT) == 0x3))
#define IS_WDG_IT(IT)                 (((IT) == 0x1) || ((IT) == 0x02))
/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/ 
/* WDG prescaler and counter configuration ************************************/
void WDG_SetPrescaler(WDG_TypeDef* WDGx, uint32_t Prescaler);
void WDG_SetReload(WDG_TypeDef* WDGx, uint32_t Reload);
void WDG_SetEarlyCnt(WDG_TypeDef* WDGx, uint32_t EarlyCnt);

/* WDG control function functions *********************************************/
void WDG_DebugCMD(WDG_TypeDef* WDGx, FunctionalState NewState);
void WDG_ResetCMD(WDG_TypeDef* WDGx, FunctionalState NewState);

/* WDG activation functions ***************************************************/
void WDG_CMD(WDG_TypeDef* WDGx, FunctionalState NewState);
void WDG_ReloadCounter(WDG_TypeDef* WDGx);

/* WDG interrupt functions ****************************************************/
void WDG_ITConfig(WDG_TypeDef* WDGx, uint32_t WDG_IT, FunctionalState NewState);
ITStatus WDG_GetITStatus(WDG_TypeDef* WDGx, uint32_t WDG_IT);
void WDG_ClearITPendingBit(WDG_TypeDef* WDGx, uint32_t WDG_IT);

void WDG_Start(WDG_TypeDef* WDGx);
void WDG_Stop(WDG_TypeDef* WDGx);
void WDG_Feed(WDG_TypeDef* WDGx);

#ifdef __cplusplus
}
#endif

#endif /* __EVALSOC_WDG_H */
