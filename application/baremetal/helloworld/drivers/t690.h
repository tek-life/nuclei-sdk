/**
  ******************************************************************************
  * @file    Baremetal\Drivers\Device\T690\Include\t690.h
  * @author  TIH Driver Team
  * @brief   Core Peripheral Access Layer Header File for T690
  ******************************************************************************
  */

#ifndef __T690_H
#define __T690_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup TIH
  * @{
  */

/** @addtogroup T690
  * @{
  */

/** @addtogroup Configuration_of_NMSIS
  * @{
  */
/** \brief SoC Download mode definition */
typedef enum 
{
    DOWNLOAD_MODE_FLASHXIP = 0,                   /*!< Flashxip download mode */
    DOWNLOAD_MODE_FLASH    = 1,                   /*!< Flash download mode */
    DOWNLOAD_MODE_RAM      = 2,                   /*!< RAM download mode */
    DOWNLOAD_MODE_DDR      = 3,                   /*!< DDR download mode */
    DOWNLOAD_MODE_MAX,
} DownloadMode_Type;

typedef enum 
{
    MCORE = 0,                                    /*!< Main-Core */
	CCORE = 1,                                    /*!< Co-Core */
    LCORE = 2,                                    /*!< LP-Core */
    CORE_MAX,
} Core_Type;

/* =========================================================================================================================== */
/* ================                                Interrupt Number Definition                                ================ */
/* =========================================================================================================================== */

typedef enum IRQn 
{
/* ========================================  Nuclei N/NX Specific Interrupt Numbers  ========================================= */
    Reserved0_IRQn            =  0,               /*!< Internal reserved */
    Reserved1_IRQn            =  1,               /*!< Internal reserved */
    Reserved2_IRQn            =  2,               /*!< Internal reserved */
    SysSoft_IRQn              =  3,               /*!< System Software Interrupt */
    Reserved3_IRQn            =  4,               /*!< Internal reserved */
    Reserved4_IRQn            =  5,               /*!< Internal reserved */
    Reserved5_IRQn            =  6,               /*!< Internal reserved */
    SysTimer_IRQn             =  7,               /*!< System Timer Interrupt */
    Reserved6_IRQn            =  8,               /*!< Internal reserved */
    Reserved7_IRQn            =  9,               /*!< Internal reserved */
    Reserved8_IRQn            = 10,               /*!< Internal reserved */
    Reserved9_IRQn            = 11,               /*!< Internal reserved */
    Reserved10_IRQn           = 12,               /*!< Internal reserved */
    Reserved11_IRQn           = 13,               /*!< Internal reserved */
    Reserved12_IRQn           = 14,               /*!< Internal reserved */
    Reserved13_IRQn           = 15,               /*!< Internal reserved */
    Reserved14_IRQn           = 16,               /*!< Internal reserved */
    Reserved15_IRQn           = 17,               /*!< Internal reserved */
    Reserved16_IRQn           = 18,               /*!< Internal reserved */

/* ===========================================  T690 Specific Interrupt Numbers  ============================================= */
    SYMINT_Q0_IRQn            = 19,               /*!< HSM SYM Queue 0 Interrupt */
    SYMINT_Q1_IRQn            = 20,               /*!< HSM SYM Queue 1 Interrupt */
    SYMINT_Q2_IRQn            = 21,               /*!< HSM SYM Queue 2 Interrupt */
    MB_CTRL0_IRQn             = 22,               /*!< HSM Mailbox Ctrl 0 Interrupt */
    MB_CTRL1_IRQn             = 23,               /*!< HSM Mailbox Ctrl 1 Interrupt */
    MB_CTRL2_IRQn             = 24,               /*!< HSM Mailbox Ctrl 2 Interrupt */
    MB_PK0_IRQn               = 25,               /*!< HSM Mailbox PK 0 Interrupt */
    MB_PK1_IRQn               = 26,               /*!< HSM Mailbox PK 1 Interrupt */
    MB_PK2_IRQn               = 27,               /*!< HSM Mailbox PK 2 Interrupt */
    SECMON_IRQn               = 28,               /*!< HSM Security Monitor Interrupt */
    USB3_IRQn                 = 34,               /*!< USB 3.0 global Interrupt */
    GMAC0_IRQn                = 35,               /*!< GMAC0 global Interrupt */
    GMAC0_Q0_RX_IRQn          = 36,               /*!< GMAC0 Queue 0 RX Interrupt */
    GMAC0_Q0_TX_IRQn          = 37,               /*!< GMAC0 Queue 0 TX Interrupt */
    GMAC0_Q1_RX_IRQn          = 38,               /*!< GMAC0 Queue 1 RX Interrupt */
    GMAC0_Q1_TX_IRQn          = 39,               /*!< GMAC0 Queue 1 TX Interrupt */
    GMAC0_Q2_RX_IRQn          = 40,               /*!< GMAC0 Queue 2 RX Interrupt */
    GMAC0_Q2_TX_IRQn          = 41,               /*!< GMAC0 Queue 2 TX Interrupt */
    GMAC0_Q3_RX_IRQn          = 42,               /*!< GMAC0 Queue 3 RX Interrupt */
    GMAC0_Q3_TX_IRQn          = 43,               /*!< GMAC0 Queue 3 TX Interrupt */
    GMAC1_IRQn                = 44,               /*!< GMAC1 global Interrupt */
    GMAC1_Q0_RX_IRQn          = 45,               /*!< GMAC1 Queue 0 RX Interrupt */
    GMAC1_Q0_TX_IRQn          = 46,               /*!< GMAC1 Queue 0 TX Interrupt */
    GMAC1_Q1_RX_IRQn          = 47,               /*!< GMAC1 Queue 1 RX Interrupt */
    GMAC1_Q1_TX_IRQn          = 48,               /*!< GMAC1 Queue 1 TX Interrupt */
    GMAC1_Q2_RX_IRQn          = 49,               /*!< GMAC1 Queue 2 RX Interrupt */
    GMAC1_Q2_TX_IRQn          = 50,               /*!< GMAC1 Queue 2 TX Interrupt */
    GMAC1_Q3_RX_IRQn          = 51,               /*!< GMAC1 Queue 3 RX Interrupt */
    GMAC1_Q3_TX_IRQn          = 52,               /*!< GMAC1 Queue 3 TX Interrupt */
    PCIE_DMA0_END_IRQn        = 71,               /*!< PCIE DMA0 End Interrupt */
    PCIE_DMA1_END_IRQn        = 72,               /*!< PCIE DMA1 End Interrupt */
    PCIE_DMA2_END_IRQn        = 73,               /*!< PCIE DMA2 End Interrupt */
    PCIE_DMA3_END_IRQn        = 74,               /*!< PCIE DMA3 End Interrupt */
    PCIE_DMA0_ERR_IRQn        = 79,               /*!< PCIE DMA0 Error Interrupt */
    PCIE_DMA1_ERR_IRQn        = 80,               /*!< PCIE DMA1 Error Interrupt */
    PCIE_DMA2_ERR_IRQn        = 81,               /*!< PCIE DMA2 Error Interrupt */
    PCIE_DMA3_ERR_IRQn        = 82,               /*!< PCIE DMA3 Error Interrupt */
    PCIE_AXI_POST_ERR_IRQn    = 87,               /*!< PCIE Address Translation: AXI Post Error Interrupt */
    PCIE_AXI_FETCH_ERR_IRQn   = 88,               /*!< PCIE Address Translation: AXI Fetch Error Interrupt */
    PCIE_AXI_DISC_ERR_IRQn    = 89,               /*!< PCIE Address Translation: AXI Discard Error Interrupt */
    PCIE_AXI_DOORBELL_IRQn    = 90,               /*!< PCIE Address Translation: AXI Doorbell Error Interrupt */
    PCIE_PCIE_POST_ERR_IRQn   = 91,               /*!< PCIE Address Translation: PCIe Post Error Interrupt */
    PCIE_PCIE_FETCH_ERR_IRQn  = 92,               /*!< PCIE Address Translation: PCIe Fetch Error Interrupt */
    PCIE_PCIE_DISC_ERR_IRQn   = 93,               /*!< PCIE Address Translation: PCIe Discard Error Interrupt */
    PCIE_PCIE_DOORBEL_IRQn    = 94,               /*!< PCIE Address Translation: PCIe Doorbell Error Interrupt */
    PCIE_INTA_IRQn            = 95,               /*!< PCIE Interrupt Line A Interrupt */
    PCIE_INTB_IRQn            = 96,               /*!< PCIE Interrupt Line B Interrupt */
    PCIE_INTC_IRQn            = 97,               /*!< PCIE Interrupt Line C Interrupt */
    PCIE_INTD_IRQn            = 98,               /*!< PCIE Interrupt Line D Interrupt */
    PCIE_MSI_RCV_IRQn         = 99,               /*!< PCIE MSI Receive Interrupt */
    PCIE_AER_EVT_IRQn         = 100,              /*!< PCIE Advance Error Report Event Interrupt */
    PCIE_PM_EVT_IRQn          = 101,              /*!< PCIE Power Management Event Interrupt */
    PCIE_SYS_ERR_IRQn         = 102,              /*!< PCIE System Error Interrupt */
    PCIE_FLR_IRQn             = 103,              /*!< PCIE Function Level Reset Interrupt */
    PCIE_ERR_IRQn             = 104,              /*!< PCIE Error Interrupt */
    PCIE_AT_IRQn              = 105,              /*!< PCIE Address Translation Interrupt */
    PCIE_VPD_IRQn             = 106,              /*!< PCIE Vital Product Data Interrupt */    
    MINTC_IRQn                = 107,              /*!< MINTC global Interrupt */
    DDR_ECC_IRQn              = 108,              /*!< DDR ECC Interrupt */
    DDR_IRQn                  = 109,              /*!< ddr global interrupt */
    DMA0_IRQn                 = 119,              /*!< DMA0 global Interrupt */
    DMA1_IRQn                 = 120,              /*!< DMA1 global Interrupt */
    FMC0_IRQn                 = 121,              /*!< FMC0 global Interrupt */
    FMC1_IRQn                 = 122,              /*!< FMC1 global Interrupt */
    SDHC0_IRQn                = 123,              /*!< SDHC0 global Interrupt */
    SDHC1_IRQn                = 124,              /*!< SDHC1 global Interrupt */
    SDHC2_IRQn                = 125,              /*!< SDHC2 global Interrupt */
    SDDC_IRQn                 = 126,              /*!< SDDC global Interrupt */
    USB2_IRQn                 = 127,              /*!< USB2 global Interrupt */
    MAC0_IRQn                 = 131,              /*!< MAC0 global Interrupt */
    MAC1_IRQn                 = 132,              /*!< MAC1 global Interrupt */
    LTDC_IRQn                 = 135,              /*!< LTDC global Interrupt */
    TIM0_IRQn                 = 147,              /*!< TIM0 global Interrupt */
    TIM1_IRQn                 = 148,              /*!< TIM1 global Interrupt */
    TIM2_IRQn                 = 149,              /*!< TIM2 global Interrupt */
    TIM3_IRQn                 = 150,              /*!< TIM3 global Interrupt */
    TIM4_IRQn                 = 151,              /*!< TIM4 global Interrupt */
    TIM5_IRQn                 = 152,              /*!< TIM5 global Interrupt */
    TIM6_IRQn                 = 153,              /*!< TIM6 global Interrupt */
    TIM7_IRQn                 = 154,              /*!< TIM7 global Interrupt */
    TIM8_IRQn                 = 155,              /*!< TIM8 global Interrupt */
    TIM9_IRQn                 = 156,              /*!< TIM9 global Interrupt */
    TIM10_IRQn                = 157,              /*!< TIM10 global Interrupt */
    TIM11_IRQn                = 158,              /*!< TIM11 global Interrupt */
    TIM12_IRQn                = 159,              /*!< TIM12 global Interrupt */
    TIM13_IRQn                = 160,              /*!< TIM13 global Interrupt */
    TIM14_IRQn                = 161,              /*!< TIM14 global Interrupt */
    TIM15_IRQn                = 162,              /*!< TIM15 global Interrupt */
    WDG0_EARLY_IRQn           = 163,              /*!< WatchDog0 Early Interrupt */
    WDG0_IRQn                 = 164,              /*!< WatchDog0 Interrupt */
    WDG1_EARLY_IRQn           = 165,              /*!< WatchDog1 Early Interrupt */
    WDG1_IRQn                 = 166,              /*!< WatchDog1 Interrupt */
    GPIOA_IRQn                = 167,              /*!< GPIOA global Interrupt */
    GPIOB_IRQn                = 168,              /*!< GPIOB global Interrupt */
    GPIOC_IRQn                = 169,              /*!< GPIOC global Interrupt */
    GPIOD_IRQn                = 170,              /*!< GPIOD global Interrupt */
    IIC0_IRQn                 = 171,              /*!< IIC0 global Interrupt */
    IIC1_IRQn                 = 172,              /*!< IIC1 global Interrupt */
    IIC2_IRQn                 = 173,              /*!< IIC2 global Interrupt */
    SPI0_IRQn                 = 175,              /*!< SPI0 global Interrupt */
    SPI1_IRQn                 = 176,              /*!< SPI1 global Interrupt */
    SSP0_IRQn                 = 177,              /*!< SSP0 global Interrupt */
    SSP1_IRQn                 = 178,              /*!< SSP1 global Interrupt */
    CANA0_IRQn                = 179,              /*!< CANA0 global Interrupt */
    CANA1_IRQn                = 180,              /*!< CANA1 global Interrupt */
    CANA2_IRQn                = 181,              /*!< CANA2 global Interrupt */
    CANA3_IRQn                = 182,              /*!< CANA3 global Interrupt */
    CANB0_IRQn                = 183,              /*!< CANB0 global Interrupt */
    CANB1_IRQn                = 184,              /*!< CANB1 global Interrupt */
    CANB2_IRQn                = 185,              /*!< CANB2 global Interrupt */
    CANB3_IRQn                = 186,              /*!< CANB3 global Interrupt */
    UART0_IRQn                = 187,              /*!< UART0 global Interrupt */
    UART1_IRQn                = 188,              /*!< UART1 global Interrupt */
    UART2_IRQn                = 189,              /*!< UART2 global Interrupt */
    UART3_IRQn                = 190,              /*!< UART3 global Interrupt */
    UART4_IRQn                = 191,              /*!< UART4 global Interrupt */
    UART5_IRQn                = 192,              /*!< UART5 global Interrupt */
    UART6_IRQn                = 193,              /*!< UART6 global Interrupt */
    UART7_IRQn                = 194,              /*!< UART7 global Interrupt */
    SCI0_IRQn                 = 195,              /*!< SCI0 global Interrupt */
    SCI1_IRQn                 = 196,              /*!< SCI1 global Interrupt */
    ADC0_IRQn                 = 197,              /*!< ADC0 global Interrupt */
    ADC1_IRQn                 = 198,              /*!< ADC1 global Interrupt */
    DAC_IRQn                  = 199,              /*!< DAC global Interrupt */
    RTC_IRQn                  = 200,              /*!< RTC global Interrupt */
    RCC_GPHY_LED_IRQn         = 213,              /*!< RCC GPHY LED global Interrupt */
    RCC_GMACX_WOL_IRQn        = 214,              /*!< RCC GMACX WOL global Interrupt */
    RCC_ECCERR_RD_IRQn        = 215,              /*!< RCC ECCERR RD global Interrupt */
    RCC_ECCERR_RMW_IRQn       = 216,              /*!< RCC ECCERR RMW global Interrupt */
    RCC_CRCERR_AHB_IRQn       = 217,              /*!< RCC CRCERR AHB global Interrupt */
    RCC_CRCERR_AXI_IRQn       = 218,              /*!< RCC CRCERR AXI global Interrupt */
    TEE_OVERLAP_IRQn          = 219,              /*!< TEE OVERLAP global Interrupt */
    TEE_ILLEGAL_IRQn          = 220,              /*!< TEE ILLEGAL global Interrupt */
    AXIC_X0_IRQn              = 221,              /*!< AXIC X0 global Interrupt */
    AXIC_X1_IRQn              = 222,              /*!< AXIC X1 global Interrupt */
    AHBC0_IRQn                = 223,              /*!< AHBC0 global Interrupt */
    H2XL_IRQn                 = 224,              /*!< H2XL global Interrupt */
    H2XH_IRQn                 = 225,              /*!< H2XH global Interrupt */
    REE_DECERR_IRQn           = 226,              /*!< REE DECERR global Interrupt */
    CFG_DECERR_IRQn           = 227,              /*!< CFG DECERR global Interrupt */
    LPC_DECERR_IRQn           = 228,              /*!< LPC DECERR global Interrupt */
    RCC_PCIE_TRACK_IRQn       = 229,              /*!< RCC PCIE TRACK global Interrupt */
    RCC_USB3_LTSSM_IRQn       = 230,              /*!< RCC USB3 LTSSM global Interrupt */
    IPC0_IRQn                 = 267,              /*!< IPC0 global Interrupt */
    IPC1_IRQn                 = 268,              /*!< IPC1 global Interrupt */
    IPC2_IRQn                 = 269,              /*!< IPC2 global Interrupt */
    IPC3_IRQn                 = 270,              /*!< IPC3 global Interrupt */
    IPC4_IRQn                 = 271,              /*!< IPC4 global Interrupt */
    IPC5_IRQn                 = 272,              /*!< IPC5 global Interrupt */
    IPC6_IRQn                 = 273,              /*!< IPC6 global Interrupt */
    IPC7_IRQn                 = 274,              /*!< IPC7 global Interrupt */
    SOC_INT_MAX ,                                 /*!< Max SoC interrupt Number */
} IRQn_Type;

/* =========================================================================================================================== */
/* ================                                  Exception Code Definition                                ================ */
/* =========================================================================================================================== */

typedef enum EXCn 
{
/* =======================================  Nuclei N/NX Specific Exception Code  ======================================== */
    InsUnalign_EXCn           = 0,                /*!< Instruction address misaligned */
    InsAccFault_EXCn          = 1,                /*!< Instruction access fault */
    IlleIns_EXCn              = 2,                /*!< Illegal instruction */
    Break_EXCn                = 3,                /*!< Beakpoint */
    LdAddrUnalign_EXCn        = 4,                /*!< Load address misaligned */
    LdFault_EXCn              = 5,                /*!< Load access fault */
    StAddrUnalign_EXCn        = 6,                /*!< Store or AMO address misaligned */
    StAccessFault_EXCn        = 7,                /*!< Store or AMO access fault */
    UmodeEcall_EXCn           = 8,                /*!< Environment call from User mode */
    MmodeEcall_EXCn           = 11,               /*!< Environment call from Machine mode */
    NMI_EXCn                  = 0xfff,            /*!< NMI interrupt*/
} EXCn_Type;

/* =========================================================================================================================== */
/* ================                           Processor and Core Peripheral Section                           ================ */
/* =========================================================================================================================== */

/* ===========================  Configuration of the Nuclei N/NX Processor and Core Peripherals  =========================== */
#define __NUCLEI_NX_REV           0x0100          /*!< Core Revision rXpY, version X.Y */
#define __ECLIC_PRESENT           1               /*!< ECLIC is present */
#define __ECLIC_BASEADDR          0x14000000UL    /*!< ECLIC baseaddr */
#define __ECLIC_INTCTLBITS        3               /*!< The number of hardware bits actually implemented in the clicintctl registers. */
#define __ECLIC_INTNUM            256             /*!< The total interrupt number of ECLIC Unit */
#define __SYSTIMER_PRESENT        1               /*!< System Timer is present */
#define __SYSTIMER_BASEADDR       0x15000000UL    /*!< SysTimer baseaddr */
#define __FPU_PRESENT             2               /*!< Double floating point unit present */
#define __DSP_PRESENT             0               /*!< DSP is not present */
#define __PMP_PRESENT             1               /*!< PMP is present */
#define __PMP_ENTRY_NUM           16              /*!< The number of PMP entries */
#define __CCM_PRESENT             1               /*!< Cache is present */
#define __ICACHE_PRESENT          1               /*!< I-Cache is present */
#define __DCACHE_PRESENT          1               /*!< D-Cache is present only for Main CPU */
#define __MCORE_DCACHE_PRESENT    1               /*!< D-Cache is present for Main CPU */
#define __CCORE_DCACHE_PRESENT    0               /*!< D-Cache is NOT present for Main CPU */
#define __Vendor_SysTickConfig    0               /*!< Set to 1 if different SysTick Config is used */ 

/** @} */ /* End of group Configuration_of_NMSIS */
// #include <nmsis_core.h>
// #include "system_t690.h"                          /*!< T690 System */
#if !defined  (USE_STDPERIPH_DRIVER)
/**
 * @brief Comment the line below if you will not use the peripherals drivers.
   In this case, these drivers will not be included and the application code will
   be based on direct access to peripherals registers
   */
   #define USE_STDPERIPH_DRIVER
#endif /* USE_STDPERIPH_DRIVER */



/* ========================================  Start of section using anonymous unions  ======================================== */
#if   defined (__GNUC__)
  /* anonymous unions are enabled by default */
#else
  #warning Not supported compiler type
#endif

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */
/* Macros for memory access operations */
#define _REG8P(p, i)                        ((volatile uint8_t *) ((uintptr_t)((p) + (i))))
#define _REG16P(p, i)                       ((volatile uint16_t *) ((uintptr_t)((p) + (i))))
#define _REG32P(p, i)                       ((volatile uint32_t *) ((uintptr_t)((p) + (i))))
#define _REG64P(p, i)                       ((volatile uint64_t *) ((uintptr_t)((p) + (i))))
#define _REG8(p, i)                         (*(_REG8P(p, i)))
#define _REG16(p, i)                        (*(_REG16P(p, i)))
#define _REG32(p, i)                        (*(_REG32P(p, i)))
#define _REG64(p, i)                        (*(_REG64P(p, i)))
#define REG8(addr)                          _REG8((addr), 0)
#define REG16(addr)                         _REG16((addr), 0)
#define REG32(addr)                         _REG32((addr), 0)
#define REG64(addr)                         _REG64((addr), 0)

/* Macros for address type convert and access operations */
#define ADDR16(addr)                        ((uint16_t)(uintptr_t)(addr))
#define ADDR32(addr)                        ((uint32_t)(uintptr_t)(addr))
#define ADDR64(addr)                        ((uint64_t)(uintptr_t)(addr))
#define ADDR8P(addr)                        ((uint8_t *)(uintptr_t)(addr))
#define ADDR16P(addr)                       ((uint16_t *)(uintptr_t)(addr))
#define ADDR32P(addr)                       ((uint32_t *)(uintptr_t)(addr))
#define ADDR64P(addr)                       ((uint64_t *)(uintptr_t)(addr))

/* Macros for Bit Operations */
#define BITMASK_MAX                         0xFFFFFFFFUL
#define BITOFS_MAX                          31
//#define BITMASK_MAX                         0xFFFFFFFFFFFFFFFFULL
//#define BITOFS_MAX                          63

// BIT/BITS only support bit mask for __riscv_xlen
// For RISC-V 32 bit, it support mask 32 bit wide
// For RISC-V 64 bit, it support mask 64 bit wide
#define BIT(ofs)                            (0x1UL << (ofs))
#define BITS(start, end)                    ((BITMASK_MAX) << (start) & (BITMASK_MAX) >> (BITOFS_MAX - (end)))
#define GET_BIT(regval, bitofs)             (((regval) >> (bitofs)) & 0x1)
#define SET_BIT(regval, bitofs)             ((regval) |= BIT(bitofs))
#define CLR_BIT(regval, bitofs)             ((regval) &= (~BIT(bitofs)))
#define FLIP_BIT(regval, bitofs)            ((regval) ^= BIT(bitofs))
#define WRITE_BIT(regval, bitofs, val)      CLR_BIT(regval, bitofs); ((regval) |= ((val) << bitofs) & BIT(bitofs))
#define CHECK_BIT(regval, bitofs)           (!!((regval) & (0x1UL<<(bitofs))))
#define GET_BITS(regval, start, end)        (((regval) & BITS((start), (end))) >> (start))
#define SET_BITS(regval, start, end)        ((regval) |= BITS((start), (end)))
#define CLR_BITS(regval, start, end)        ((regval) &= (~BITS((start), (end))))
#define FLIP_BITS(regval, start, end)       ((regval) ^= BITS((start), (end)))
#define WRITE_BITS(regval, start, end, val) CLR_BITS(regval, start, end); ((regval) |= ((val) << start) & BITS((start), (end)))
#define CHECK_BITS_ALL(regval, start, end)  (!((~(regval)) & BITS((start), (end))))
#define CHECK_BITS_ANY(regval, start, end)  ((regval) & BITS((start), (end)))

#define BITMASK_SET(regval, mask)           ((regval) |= (mask))
#define BITMASK_CLR(regval, mask)           ((regval) &= (~(mask)))
#define BITMASK_FLIP(regval, mask)          ((regval) ^= (mask))
#define BITMASK_CHECK_ALL(regval, mask)     (!((~(regval)) & (mask)))
#define BITMASK_CHECK_ANY(regval, mask)     ((regval) & (mask))

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

/** @addtogroup Device_Peripheral_peripherals
  * @{
  */

/* TODO: add here your device specific peripheral access structure typedefs
         following is an example for UART */

/* =========================================================================================================================== */
/* ================                                  ADC                                                      ================ */
/* =========================================================================================================================== */
/**
  * @brief Analog to Digital Converter
  */

typedef struct
{
    __IO uint32_t SR;                                  /*!< ADC status register,             Address offset: 0x00 */
    __IO uint32_t CR;                                  /*!< ADC control register,            Address offset: 0x04 */
    __IO uint32_t CONV;                                /*!< ADC sample time register,        Address offset: 0x08 */
    __IO uint32_t WDG;                                 /*!< ADC analog watchdog register,    Address offset: 0x0C */
    __IO uint32_t GSQ0;                                /*!< ADC regular sequence register 0, Address offset: 0x10 */
    __IO uint32_t GSQ1;                                /*!< ADC regular sequence register 1, Address offset: 0x14 */
    __IO uint32_t PSQ;                                 /*!< ADC injected sequence register,  Address offset: 0x18 */
    __IO uint32_t GFIFO;                               /*!< ADC regular data register,       Address offset: 0x1C */
    __IO uint32_t PFIFO;                               /*!< ADC injected data register,      Address offset: 0x20 */
    __IO uint32_t CALIB;                               /*!< ADC calibration register,        Address offset: 0x24 */
    __IO uint32_t OFR[10];                             /*!< ADC regular and injected data offset register buffer, Address offset: 0x28 - 0x4C */
} ADC_TypeDef;

/* =========================================================================================================================== */
/* ================                                  CAN                                                       ================ */
/* =========================================================================================================================== */
/**
  * @brief Controller Area Network  (CAN)
  */
typedef struct
{
    __IO uint32_t TBID;                                /*!< CANA TX Buffer ID register */
    __IO uint32_t TBDLC;	                           /*!< CANA TX Buffer DLC register */
    __IO uint32_t TBDW[16];                            /*!< CANA TX Buffer Data Word register */
} CANA_TxMailBox_TypeDef;

typedef struct
{
    __IO uint32_t AFMR;                                /*!< CANA Acception Filter Mask register */
    __IO uint32_t AFIR;	                               /*!< CANA Acception Filter ID register */
} CANA_FilterRegister_TypeDef;

typedef struct
{
    __I uint32_t RBID;                                 /*!< CANA TX Buffer ID register */
    __I uint32_t RBDLC;	                               /*!< CANA TX Buffer DLC register */
    __I uint32_t RBDW[16];                             /*!< CANA TX Buffer Data Word register */
} CANA_RxFIFO_TypeDef;

typedef struct
{
	__IO uint32_t SRR;                 		           /*!< CANA software reset register,               Address offset: 0x00 */
	__IO uint32_t MSR;                 		           /*!< CANA mode select register,                  Address offset: 0x04 */
	__IO uint32_t APBRPR;              		           /*!< CANA arbitration phase baud rate register,  Address offset: 0x08 */
	__IO uint32_t APBTR;               		           /*!< CANA arbitration phase bit timing register, Address offset: 0x0C */
	__IO uint32_t ECR;                 		           /*!< CANA error count register,                  Address offset: 0x10 */
	__IO uint32_t ESR;                 		           /*!< CANA error status register,                 Address offset: 0x14 */
	__I  uint32_t SR;                  		           /*!< CANA status register,                       Address offset: 0x18 */
	__I  uint32_t ISR;                 		           /*!< CANA interrupt status register,             Address offset: 0x1C */
	__IO uint32_t IER;                 		           /*!< CANA interrupt enable register,             Address offset: 0x20 */
	__O  uint32_t ICR;                 		           /*!< CANA interrupt clear register,              Address offset: 0x24 */
	__IO uint32_t TSR;                 		           /*!< CANA timestamp register,                    Address offset: 0x28 */
	uint32_t RESERVED0[23];                            /*!< Reserved, 0x2C - 0x87 */
	__IO uint32_t DPBRPR;              		           /*!< CANA date phase baud rate register,         Address offset: 0x88 */
	__IO uint32_t DPBTR;               		           /*!< CANA date phase bit timing register,        Address offset: 0x8C */
	__IO uint32_t TBRR;   		           		       /*!< CANA TX buffer ready request register,      Address offset: 0x90 */
	uint32_t RESERVED1;                                /*!< Reserved, 0x94 */
	__IO uint32_t TBCR;     	            		   /*!< CANA TX buffer cancel request register,     Address offset: 0x98 */
	uint32_t RESERVED2[17];                            /*!< Reserved, 0x9C - 0xDF */
	__IO uint32_t AFCR;		                  		   /*!< CANA acceptance filter control register,    Address offset: 0xE0 */
	uint32_t RESERVED3;                                /*!< Reserved, 0xE4 */
	__IO uint32_t RFSR;                				   /*!< CANA RX FIFO status register,               Address offset: 0xE8 */
	__IO uint32_t RFWR;                		           /*!< CANA RX FIFO watermark register,            Address offset: 0xEC */
	uint32_t RESERVED4[4];                             /*!< Reserved, 0xF0 - 0xFF */
	CANA_TxMailBox_TypeDef sTxMailBox[8];    		   /*!< CANA Tx MailBox register,                   Address offset: 0x100 - 0x33C */
	uint32_t RESERVED5[432];                           /*!< Reserved, 0x340 - 0x9FF */
	CANA_FilterRegister_TypeDef sFilterRegister[32];   /*!< CANA filter register,                       Address offset: 0xA00 - 0xAFC */
	uint32_t RESERVED6[1408];                          /*!< Reserved, 0xB00 - 0x20FF */
	CANA_RxFIFO_TypeDef sRxFIFO[32];		           /*!< CANA RX FIFO register,                      Address offset: 0x2100 - 0x29FC */
} CANA_TypeDef;

typedef struct
{
    __IO uint32_t CR;                                  /*!< CANB control register,                         Address offset: 0x00 */
    __IO uint32_t SR;                                  /*!< CANB status register,                          Address offset: 0x04 */
    __IO uint32_t TB0R0;                               /*!< CANB TX buffer0 register0,                     Address offset: 0x08 */
    __IO uint32_t TB0R1;                               /*!< CANB TX buffer0 register1,                     Address offset: 0x0C */
    __IO uint32_t TB1R0;                               /*!< CANB TX buffer1 register0,                     Address offset: 0x10 */
    __IO uint32_t TB1R1;                               /*!< CANB TX buffer1 register1,                     Address offset: 0x14 */
    __IO uint32_t TB2R0;                               /*!< CANB TX buffer2 register0,                     Address offset: 0x18 */
	__IO uint32_t TB2R1;                               /*!< CANB TX buffer2 register1,                     Address offset: 0x1C */
	__IO uint32_t AFIR[6];                             /*!< CANB acception filter ID registers,            Address offset: 0x20 - 0x34 */
	__IO uint32_t AFDBR;                               /*!< CANB acception filter data byte register,      Address offset: 0x38 */
	__IO uint32_t AFCR;                                /*!< CANB acception filter control register,        Address offset: 0x3C */
	__IO uint32_t AFMIR0;                              /*!< CANB acception filter mask ID register0,       Address offset: 0x40 */
	__IO uint32_t AFMIR1;                              /*!< CANB acception filter mask ID register1,       Address offset: 0x44 */
	__IO uint32_t AFMDBR;                              /*!< CANB acception filter mask data byte register, Address offset: 0x48 */
	__IO uint32_t AFMCR;                               /*!< CANB acception filter mask control register,   Address offset: 0x4C */
	__I uint32_t RB0PR0;                               /*!< CANB RX buffer0 parameter register0,           Address offset: 0x50 */
	__I uint32_t RB0PR1;                               /*!< CANB RX buffer0 parameter register1,           Address offset: 0x54 */
	__I uint32_t RB1PR0;                               /*!< CANB RX buffer1 parameter register0,           Address offset: 0x58 */
	__I uint32_t RB1PR1;                               /*!< CANB RX buffer1 parameter register1,           Address offset: 0x5C */
	__IO uint32_t APBTR0;                              /*!< CANB arbitrary phase bit timing register0,     Address offset: 0x60 */
	__IO uint32_t APBTR1;                              /*!< CANB arbitrary phase bit timing register1,     Address offset: 0x64 */
	__IO uint32_t DPBTR;                               /*!< CANB data phase bit timing register,           Address offset: 0x68 */
	__I uint32_t ECR;                                  /*!< CANB error counter register,                   Address offset: 0x6C */
	__I uint32_t ESR;                                  /*!< CANB error status register,                    Address offset: 0x70 */
	uint32_t RESERVED0;
	__IO uint32_t IRR;                                 /*!< CANB interrupt request register,               Address offset: 0x78 */
	__IO uint32_t TB0DR[16];                           /*!< CANB TX buffer0 data registers,                Address offset: 0x7C - 0xB8 */
	__IO uint32_t TB1DR[16];                           /*!< CANB TX buffer1 data registers,                Address offset: 0xBC - 0xF8 */
	__IO uint32_t TB2DR[16];                           /*!< CANB TX buffer2 data registers,                Address offset: 0xFC - 0x138 */
	__I uint32_t RB0DR[16];                            /*!< CANB RX buffer0 data registers,                Address offset: 0x13C - 0x178 */
	__I uint32_t RB1DR[16];                            /*!< CANB RX buffer0 data registers,                Address offset: 0x17C - 0x1B8 */
} CANB_TypeDef;

/* =========================================================================================================================== */
/* ================                                  CPUAT                                                    ================ */
/* =========================================================================================================================== */
/**
  * @brief CPU Address Transfer (CPUAT)
  */
typedef struct
{
  __IO uint32_t CTRL;                                  /*!< CPU Address Transfer Ctrl register,                  Address offset: 0x00 */
  __IO uint32_t R0BASE;                                /*!< CPU Address Transfer Region 0 Base Address register, Address offset: 0x04 */
  __IO uint32_t R0SIZE;                                /*!< CPU Address Transfer Region 0 Size register,         Address offset: 0x08 */
  __IO uint32_t R1BASE;                                /*!< CPU Address Transfer Region 1 Base Address register, Address offset: 0x0C */
  __IO uint32_t R1SIZE;                                /*!< CPU Address Transfer Region 1 Size register,         Address offset: 0x10 */
  __IO uint32_t R2BASE;                                /*!< CPU Address Transfer Region 2 Base Address register, Address offset: 0x14 */
  __IO uint32_t R2SIZE;                                /*!< CPU Address Transfer Region 2 Size register,         Address offset: 0x18 */
  __IO uint32_t R3BASE;                                /*!< CPU Address Transfer Region 3 Base Address register, Address offset: 0x1C */
  __IO uint32_t R3SIZE;                                /*!< CPU Address Transfer Region 3 Size register,         Address offset: 0x20 */
} CPUAT_TypeDef;

/* =========================================================================================================================== */
/* ================                                  CPUIMC                                                   ================ */
/* =========================================================================================================================== */
/**
  * @brief CPU Interrupt MUX Controller (CPUIMC)
  */
typedef struct
{
    __IO uint32_t IMCR[8];                             /*!< Interrupt mux control register, Address offset: 0x0 - 0x1C */
} CPUIMC_TypeDef;

/* =========================================================================================================================== */
/* ================                                  CPUIPC                                                   ================ */
/* =========================================================================================================================== */
/**
  * @brief CPU Inter Process Controller (CPUIPC)
  */
typedef struct
{
    __IO uint32_t IPCR[8];                              /*!< IPC register, Address offset: 0x00 - 0x1C */
} CPUIPC_TypeDef;

/* =========================================================================================================================== */
/* ================                                  DAC                                                      ================ */
/* =========================================================================================================================== */
/**
  * @brief Digital to Analog Converter
  */
typedef struct
{
    __IO uint32_t CR;                                   /*!< DAC control register,               Address offset: 0x00 */
    __IO uint32_t SWTRGR;                               /*!< DAC software trigger register,      Address offset: 0x04 */
    __IO uint32_t DHR0;                                 /*!< DAC channel0 data holding register, Address offset: 0x08 */
    __IO uint32_t DHR1;                                 /*!< DAC channel1 data holding register, Address offset: 0x0C */
    __IO uint32_t DHRD;                                 /*!< Dual DAC data holding register,     Address offset: 0x10 */
    __IO uint32_t DOR0;                                 /*!< DAC channel0 data output register,  Address offset: 0x14 */
    __IO uint32_t DOR1;                                 /*!< DAC channel1 data output register,  Address offset: 0x18 */
    uint32_t      RESERVED0;                            /*!< Reserved, 0x1C */
    __IO uint32_t DIV;                                  /*!< DAC clock divison rate register,    Address offset: 0x20 */
    uint32_t RESERVED1[3];                              /*!< Reserved, 0x24 - 0x2C  */
    __IO uint32_t ISR;                                  /*!< DAC status register,                Address offset: 0x30 */
    __IO uint32_t IER;                                  /*!< DAC interrupt register,             Address offset: 0x34 */
} DAC_TypeDef;

/* =========================================================================================================================== */
/* ================                                  DMA                                                      ================ */
/* =========================================================================================================================== */
typedef struct
{
    __IO uint32_t CnCR;                                 /*!< DMA stream x control register */
    __IO uint32_t CnCFGR;                               /*!< DMA stream x configuration register */
    __IO uint32_t CnSAR;                                /*!< DMA stream x memory source address register */
    __IO uint32_t CnDAR;                                /*!< DMA stream x memory destion address register */
    __IO uint32_t CnLLPR;                               /*!< DMA stream x link list pointer register */
    __IO uint32_t CnSIZER;                              /*!< DMA stream x number of data register */
    __IO uint32_t CnSDSR;                               /*!< DMA stream x source/destination stride register */
    uint32_t RESERVED[57];                              /*!< 0x11C ~ 1FC */
    __IO uint32_t CnSDAER;                              /*!< DMA stream x source address and destination address expand register */
    __IO uint32_t CnLLPER;                              /*!< DMA stream x link list pointer and user-defined signal expand register */

} DMA_Stream_TypeDef;

typedef struct
{
    __I uint32_t ISR;                                   /*!< DMA interrupt of each DMA channel register,             Address offset: 0x00 */
    __I uint32_t TCISR;                                 /*!< DMA terminal count interrupt register,                  Address offset: 0x04 */
    __IO uint32_t TCICR;                                /*!< DMA terminal count interrupt flag clear register,       Address offset: 0x08 */
    __I uint32_t EAISR;                                 /*!< DMA error/abort interrupt status register,              Address offset: 0x0C */
    __IO uint32_t EAICR;                                /*!< DMA error/abort flag clear interrupt status register,   Address offset: 0x10 */
    __I uint32_t TCSR;                                  /*!< DMA terminal count status register,regardless mask bit, Address offset: 0x14 */
    __I uint32_t EASR;                                  /*!< DMA error/abort status register, regardless mask bit,   Address offset: 0x18 */
    __IO uint32_t CER;                                  /*!< DMA channel enable  register,                           Address offset: 0x1C */
    __IO uint32_t SPIR;                                 /*!< DMA synchronization of peripheral interface register,   Address offset: 0x20 */
    uint32_t RESERVED0;                                 /*!< DMA local descriptor memorys register,(Not used),       Address offset: 0x24 */
    __IO uint32_t TOR;                                  /*!< DMA timeout register,                                   Address offset: 0x28 */
    __IO uint32_t GER;                                  /*!< DMA global events register,                             Address offset: 0x2C */
    __IO uint32_t PSER;                                 /*!< DMA APB slave error Enable  register,                   Address offset: 0x30 */
    __I uint32_t REVISION;                              /*!< DMA revision number register,                           Address offset: 0x34 */
    __I uint32_t HFR1;                                  /*!< DMA hardware feature register,                          Address offset: 0x38 */
    uint32_t RESERVED1[4];                              /*!< DMA reserved                                            Address offset: 0x3C ~ 0x48 */
    __IO uint32_t ECR;                                  /*!< DMA endian conversion register,                         Address offset: 0x4C */
    __IO uint32_t WOMCVR;                               /*!< DMA write-only mode constant value register,            Address offset: 0x50 */
    __I uint32_t HFR2;                                  /*!< DMA hardware feature register2,                         Address offset: 0x38 */
} DMA_TypeDef;

/* =========================================================================================================================== */
/* ================                                  DDRC                                                      ================ */
/* =========================================================================================================================== */
/**
  * @brief Double Data Rate SDRAM Controller (DDRC)
  */
typedef struct {
    __IO uint32_t MCCR;                                 /*!< Memory controller configuration,                        Address offset: 0x0 */
    __IO uint32_t MCSR;                                 /*!< Memory controller state control,                        Address offset: 0x4 */
    __IO uint32_t MRSVR0;                               /*!< Mode register set values for the Mode Register(MR) and Extended Mode Register(EMR), Address offset: 0x8 */
    __IO uint32_t MRSVR1;                               /*!< Mode register set values for EMR2 and EMR3,             Address offset: 0xC */
    __IO uint32_t EXRANKR;                              /*!< External rank0/rand1 register,                          Address offset: 0x10 */
    __IO uint32_t TMPR0;                                /*!< Timing parameter 0,                                     Address offset: 0x14 */
    __IO uint32_t TMPR1;                                /*!< Timing parameter 1,                                     Address offset: 0x18 */
    __IO uint32_t TMPR2;                                /*!< Timing parameter 2,                                     Address offset: 0x1C */
    __IO uint32_t PHYCR0;                               /*!< Data block control,                                     Address offset: 0x20 */
    __IO uint32_t PHYRDTR;                              /*!< DLL delay tuning of the DDR PHY read path,              Address offset: 0x24 */
    __IO uint32_t COMPBLKCR;                            /*!< COMPBLK control,                                        Address offset: 0x28 */
    __IO uint32_t APDCR;                                /*!< Automatic power-down/self-refresh control,              Address offset: 0x2C */
    __IO uint32_t CHARBRA;                              /*!< Channel arbitration setup register A,                   Address offset: 0x30 */
    __IO uint32_t CHGNTRA;                              /*!< Channel arbiter grant count register A,                 Address offset: 0x34 */
    __IO uint32_t CHGNTRB;                              /*!< Channel arbiter grant count register B,                 Address offset: 0x38 */
    __IO uint32_t PHYWRTMR;                             /*!< DDRx PHY write/read data access timing control,         Address offset: 0x3C */
    __IO uint32_t FLUSHCR;                              /*!< Command flush control,                                  Address offset: 0x40 */
    __IO uint32_t FLUSHSR;                              /*!< Command flush status,                                   Address offset: 0x44 */
    __IO uint32_t SPLITCR;                              /*!< AHB split control,                                      Address offset: 0x48 */
    __IO uint32_t UPDCR;                                /*!< DDRx PHY and DDR3 updata control,                       Address offset: 0x4C */
    __I  uint32_t REVR;                                 /*!< Revisiong register,                                     Address offset: 0x50 */
    __I  uint32_t FEATR1;                               /*!< Feature register,                                       Address offset: 0x54 */
    __I  uint32_t FEATR2;                               /*!< Feature register 2,                                     Address offset: 0x58 */
    __IO uint32_t UDEFR;                                /*!< User-defined register,                                  Address offset: 0x5C */
    __IO uint32_t WLEVELCR;                             /*!< Write-leveling control register,                        Address offset: 0x60 */
    __IO uint32_t WLEVELBHR;                            /*!< Byte 7 ~ byte 4 of the write-leveling control register, Address offset: 0x64 */
    __IO uint32_t WLEVELBLR;                            /*!< Byte 3 ~ byte 0 of the write-leveling control register, Address offset: 0x68 */
    __IO uint32_t PHYMISCR1;                            /*!< DDR3 MISC register,                                     Address offset: 0x6C */
    __IO uint32_t RLEVELCR;                             /*!< Read-leveling control register,                         Address offset: 0x70 */
    __IO uint32_t MSDLYCR;                              /*!< msdly byte control register,                            Address offset: 0x74 */
    __IO uint32_t WRDLLCR;                              /*!< wdllsel control register,                               Address offset: 0x78 */
    __IO uint32_t TRAFMR;                               /*!< Traffic monitor clock cycle register,                   Address offset: 0x7C */
    __I  uint32_t CMDCNTR0;                             /*!< Command count for channel 0,                            Address offset: 0x80 */
    __I  uint32_t CMDCNTR1;                             /*!< Command count for channel 1,                            Address offset: 0x84 */
    __I  uint32_t CMDCNTR2;                             /*!< Command count for channel 2,                            Address offset: 0x88 */
    __I  uint32_t CMDCNTR3;                             /*!< Command count for channel 3,                            Address offset: 0x8C */
    __I  uint32_t CMDCNTR4;                             /*!< Command count for channel 4,                            Address offset: 0x90 */
    __I  uint32_t CMDCNTR5;                             /*!< Command count for channel 5,                            Address offset: 0x94 */
    __I  uint32_t CMDCNTR6;                             /*!< Command count for channel 6,                            Address offset: 0x98 */
    __I  uint32_t CMDCNTR7;                             /*!< Command count for channel 7,                            Address offset: 0x9C */
    __IO uint32_t AHBRPRER1;                            /*!< AHB INCR read prefetch length 1,                        Address offset: 0xA0 */
    __IO uint32_t AHBRPRER2;                            /*!< AHB INCR read prefetch length 2,                        Address offset: 0xA4 */
    __IO uint32_t INITWCR1;                             /*!< Initialization waiting cycle count 1,                   Address offset: 0xA8 */
    __IO uint32_t INITWCR2;                             /*!< Initialization waiting cycle count 2,                   Address offset: 0xAC */
    __IO uint32_t QOSCR;                                /*!< QoS control register,                                   Address offset: 0xB0 */
    __IO uint32_t QOSCNTRA;                             /*!< QoS command count register A,                           Address offset: 0xB4 */
    __IO uint32_t QOSCNTRB;                             /*!< QoS command count register B,                           Address offset: 0xB8 */
    __IO uint32_t QOSCNTRC;                             /*!< QoS command count register C,                           Address offset: 0xBC */
    __IO uint32_t QOSCNTRD;                             /*!< QoS command count register D,                           Address offset: 0xC0 */
    __IO uint32_t CHARBRB;                              /*!< Channel arbitration setup register B,                   Address offset: 0xC4 */
    __IO uint32_t CHGNTRC;                              /*!< Channel arbiter grant count register C,                 Address offset: 0xC8 */
    __IO uint32_t CHGNTRD;                              /*!< Channel arbiter grant count register D,                 Address offset: 0xCC */
    uint32_t RESERVED0[12];                             /*!< Reserved, 0xD0-0xFC */
    __IO uint32_t LP2MRA;                               /*!< LPDDR2 Mode Register MR1/MR2/MR3,                       Address offset: 0x100 */
    __IO uint32_t LP2MRB;                               /*!< LPDDR2 Mode Registe MR9/MR10,                           Address offset: 0x104 */
    __IO uint32_t LP2MRC;                               /*!< LPDDR2 Mode Register MR16/MR17,                         Address offset: 0x108 */
    __IO uint32_t LP2MRD;                               /*!< LPDDR2 Mode Register MR41/MR42/MR48,                    Address offset: 0x10C */
    __IO uint32_t LP2MRE;                               /*!< LPDDR2 Mode Register MR63,                              Address offset: 0x110 */
    __IO uint32_t LP2MRCR;                              /*!< LPDDR2 MRW and MRR Commands,                            Address offset: 0x114 */
    __I  uint32_t LP2MRVR;                              /*!< LPDDR2 MRR Read Value,                                  Address offset: 0x118 */
    __IO uint32_t LP2ADLR;                              /*!< LPDDR2 Added Latency,                                   Address offset: 0x11C */
    __IO uint32_t LP2WCR1;                              /*!< LPDDR2 1us waiting cycle,                               Address offset: 0x120 */
    __IO uint32_t LP2WCR2;                              /*!< LPDDR2 10us waiting cycle,                              Address offset: 0x124 */
    uint32_t RESERVED1;                                 /*!< Reserved, 0x128 */
    __IO uint32_t REARBDISR;                            /*!< Re-arbitration disable count register,                  Address offset: 0x12C */
    __IO uint32_t PHYRDTFR;                             /*!< DLL delay tuning of the DDR PHY read path (Falling),    Address offset: 0x130 */
    __IO uint32_t PHYMISCR2;                            /*!< DDR PHY MISC2 register,                                 Address offset: 0x134 */
    __IO uint32_t EFIFOCR;                              /*!< EFIFO control register,                                 Address offset: 0x138 */
    uint32_t RESERVED2[28];                             /*!< Reserved, 0x13C-0x1A8 */
    __IO uint32_t B8PHYCR;                              /*!< Byte 8 PHY control register,                            Address offset: 0x1AC */
    uint32_t RESERVED3[12];                             /*!< Reserved, 0x1B0-0x1DC */
    __IO uint32_t ECCCTRLR;                             /*!< ECC control register,                                   Address offset: 0x1E0 */
    __IO uint32_t ECCINTCR;                             /*!< ECC interrupt control register,                         Address offset: 0x1E4 */
    __I  uint32_t ECCCHR;                               /*!< ECC error channel register,                             Address offset: 0x1E8 */
    __I  uint32_t ECCEAR;                               /*!< ECC error address,                                      Address offset: 0x1EC */
    __I  uint32_t ECCEBPLR;                             /*!< ECC error bit position low bytes,                       Address offset: 0x1F0 */
    __I  uint32_t ECCEBPHR;                             /*!< ECC error bit position high bytes,                      Address offset: 0x1F4 */
    __I  uint32_t ECCERR1CNT;                           /*!< ECC one-bit error counts register,                      Address offset: 0x1F8 */
    __I  uint32_t ECCERR2CNT;                           /*!< ECC two-bit error counts register,                      Address offset: 0x1FC */
    __IO uint32_t WL2ND_CTRL1;                          /*!< Second Write Leveling Pattern Select Register,          Address offset: 0x200 */
    __IO uint32_t WL2ND_START_BANK;                     /*!< Second Write Leveling Start Bank Address Register,      Address offset: 0x204 */
    __IO uint32_t WL2ND_START_ROW;                      /*!< Second Write Leveling Start Row Address Register,       Address offset: 0x208 */
    __IO uint32_t WL2ND_START_COLUMN;                   /*!< Second Write Leveling Start Column Address Register,    Address offset: 0x20C */
    __IO uint32_t WL2ND_CTRL2;                          /*!< Second Write Leveling Control Register2,                Address offset: 0x210 */
    __IO uint32_t WL2ND_ADJUST;                         /*!< Second Write Leveling Adjust Register,                  Address offset: 0x214 */
    __IO uint32_t FEATR3;                               /*!< Feature Register 3,                                     Address offset: 0x218 */
    uint32_t RESERVED4;                                 /*!< Reserved, 0x21C */
    __IO uint32_t ODTMD_DQ;                             /*!< ODTMD_DQ Register,                                      Address offset: 0x220 */
    __IO uint32_t ODTMD_DQS;                            /*!< ODTMD_DQS Register,                                     Address offset: 0x224 */
    __IO uint32_t RONMD_DQ;                             /*!< RONMD_DQ Register,                                      Address offset: 0x228 */
    __IO uint32_t RONMD_DQS;                            /*!< RONMD_DQS Register,                                     Address offset: 0x22C */
} DDRC_TypeDef;

typedef struct
{
    __IO uint32_t CFG0;                                 /*!< DDR PHY configuration 0 register, Address offset: 0x0 */
    __IO uint32_t CFG1;                                 /*!< DDR PHY configuration 1 register, Address offset: 0x4 */
    __IO uint32_t CFG2;                                 /*!< DDR PHY configuration 2 register, Address offset: 0x8 */
    __IO uint32_t CFG3;                                 /*!< DDR PHY configuration 3 register, Address offset: 0xC */
} DDRC_Config_TypeDef;

/* =========================================================================================================================== */
/* ================                                  FMC                                                      ================ */
/* =========================================================================================================================== */
/**
  * @brief Flexible Memory Controller (FMC)
  */

typedef struct
{
    __IO uint32_t CMDW0;                                /*!< FMC Address register,                   Address offset: 0x00 */
    __IO uint32_t CMDW1;                                /*!< FMC CMD1 register,                      Address offset: 0x04 */
    __IO uint32_t CMDW2;                                /*!< FMC Data Length register,               Address offset: 0x08 */
    __IO uint32_t CMDW3;                                /*!< FMC CMD3 register,                      Address offset: 0x0C */
    __IO uint32_t CR;                                   /*!< FMC Device Configuration register,      Address offset: 0x10 */
    __IO uint32_t ACTR;                                 /*!< FMC Device ACTR Configuration register, Address offset: 0x14 */
    __I uint32_t SR;                                    /*!< FMC  Status register,                   Address offset: 0x18 */
    uint32_t RESERVED;
    __IO uint32_t ICR;                                  /*!< FMC Interrupt register,                 Address offset: 0x20 */
    __IO uint32_t ISR;                                  /*!< FMC Interrupt Status register,          Address offset: 0x24 */
    __I uint32_t SPISR;                                 /*!< FMC Flash Status register,              Address offset: 0x28 */
    __IO uint32_t SPIFSR;                               /*!< FMC Flash Size register,                Address offset: 0x20 */
    __IO uint32_t XIPCR0;                               /*!< FMC XIP Configuration register,         Address offset: 0x20 */
    __IO uint32_t XIPCR1;                               /*!< FMC XIP PFO register,                   Address offset: 0x20 */
    __IO uint32_t XIPCR2;                               /*!< FMC XIP WCMD register,                  Address offset: 0x38 */
    uint32_t RESERVED0[6];                              /*!< Reserved, 0x3C-0x50 */
    __I uint32_t FEATURE;                               /*!< FMC Feature register,                   Address offset: 0x54 */
    uint32_t RESERVED1[42];                             /*!< Reserved, 0x58-0xFC */
    __IO uint32_t DR;                                   /*!< FMC Data register,                      Address offset: 0x100 */
} FMC_TypeDef;

typedef struct
{
    __IO uint32_t IC;                                   /*!< FMC0 IO control register, Address offset: 0x0 */
} FMC0_IOControl_TypeDef;

typedef struct
{
    __IO uint32_t DC;                                   /*!< FMC1 DLL control register, Address offset: 0x0 */
} FMC1_DllControl_TypeDef;

/* =========================================================================================================================== */
/* ================                                  GMAC                                                     ================ */
/* =========================================================================================================================== */
/**
  * @brief GMAC
  */

typedef struct
{
    __IO uint32_t GMAC_MACFLTL;                         /*!< MAC address filter least significant control register, Address offset: 0x1B8 */
    __IO uint32_t GMAC_MACFLTH;                         /*!< MAC address filter most significant control register,  Address offset: 0x1BC */
} GMAC_MacFilterRegister_TypeDef;

typedef struct
{
    __IO uint32_t GMAC_QPAIRCR;                          /*!< Queue control register,                                      Address offset: 0x400 */
    __IO uint32_t GMAC_QUEUEISR;                         /*!< Queue interrupt status register,                             Address offset: 0x404 */
    __IO uint32_t GMAC_QUEUEIER;                         /*!< Queue interrupt enable register,                             Address offset: 0x408 */
    __IO uint32_t GMAC_TXINTCR;                          /*!< Queue transmit interrupt control register,                   Address offset: 0x40C */
    __IO uint32_t GMAC_RXINTCR;                          /*!< Queue receive interrupt control register,                    Address offset: 0x410 */
    __IO uint32_t GMAC_RXDESCCR;                         /*!< Queue receive descriptor control register,                   Address offset: 0x414 */
    __IO uint32_t GMAC_RXRINGBADDRL;                     /*!< Queue receive ring base least significant address register,  Address offset: 0x418 */
    __IO uint32_t GMAC_RXRINGBADDRH;                     /*!< Queue receive ring base most significant address register,   Address offset: 0x41C */
    __IO uint32_t GMAC_RXRINGHDINDEX;                    /*!< Queue receive ring header index register,                    Address offset: 0x420 */
    __IO uint32_t GMAC_RXRINGTLINDEX;                    /*!< Queue receive ring tail index register,                      Address offset: 0x424 */
    __IO uint32_t RESERVED[6];                           /*!< Reserved, Address offset: 0x428 ~ 0x43C */
    __IO uint32_t GMAC_TXDESCCR;                         /*!< Queue transmit descriptor control register,                  Address offset: 0x440 */
    __IO uint32_t GMAC_TXRINGBADDRL;                     /*!< Queue transmit ring base least significant address register, Address offset: 0x444 */
    __IO uint32_t GMAC_TXRINGBADDRH;                     /*!< Queue transmit ring base most significant address register,  Address offset: 0x448 */
    __IO uint32_t GMAC_TXRINGHDINDEX;                    /*!< Queue transmit ring header index register,                   Address offset: 0x44C */
    __IO uint32_t GMAC_TXRINGTLINDEX;                    /*!< Queue transmit ring tail index register,                     Address offset: 0x450 */
    __IO uint32_t RESERVED0[4];                          /*!< Reserved, Address offset: 0x454 ~ 0X460 */
    __IO uint32_t GMAC_TPHCR;                            /*!< Queue TPH control register,                                  Address offset: 0x464 */
    __IO uint32_t GMAC_FUNCID;                           /*!< Queue function id register,                                  Address offset: 0x468 */
    __IO uint32_t GMAC_TQBUFCR;                          /*!< Queue transmit buffer control register,                      Address offset: 0x46C */
    __IO uint32_t GMAC_RQBUFCR;                          /*!< Queue receive buffer control register,                       Address offset: 0x470 */
    __IO uint32_t GMAC_RQBUFSR;                          /*!< Queue reveice buffer size register,                          Address offset: 0x474 */
    __IO uint32_t RESERVED1[34];                         /*!< Reserved, Address offset: 0x478 ~ 0x4FC */
} GMAC_QueueRegister_TypeDef;

typedef struct
{
    __IO uint32_t GMAC_MACCR;                            /*!< GMAC control register,                                                   Address offset: 0x000 */
    __IO uint32_t GMAC_FDPFLOWCR;                        /*!< Full-duplex Flow control register,                                       Address offset: 0x004 */
    __IO uint32_t RESERVED;                              /*!< Reserved, Address offset: 0x008 */
    __IO uint32_t GMAC_DMABLCR;                          /*!< DMA burst length control register,                                       Address offset: 0x00C */
    __IO uint32_t GMAC_DMAFIFOSTS;                       /*!< DMA/FIFO state register,                                                 Address offset: 0x010 */
    __IO uint32_t RESERVED0;                             /*!< Reserved, Address offset: 0x014 */
    __IO uint32_t GMAC_WOLCR;                            /*!< Wake-On-LAN control register,                                            Address offset: 0x018 */
    __IO uint32_t GMAC_WOLSTS;                           /*!< Wake-On-LAN status register,                                             Address offset: 0x01C */
    __IO uint32_t RESERVED1[5];                          /*!< Reserved, Address offset: 0x020 ~ 0x030*/
    __IO uint32_t GMAC_PTPRXUCSTDA;                      /*!< PTP RX Unicast IP destination address register,                          Address offset: 0x034 */
    __IO uint32_t GMAC_PTPTXUCSTDA;                      /*!< PTP TX Unicast IP destination address register,                          Address offset: 0x038 */
    __IO uint32_t GMAC_PTPTXPSEC;                        /*!< PTP TX event frame register(PTP TX frame timestamp for seconds),         Address offset: 0x03C */
    __IO uint32_t GMAC_PTPTXPNSEC;                       /*!< PTP TX event frame register(PTP TX frame timestamp for nanoseconds),     Address offset: 0x040 */
    __IO uint32_t GMAC_PTPRXPSEC;                        /*!< PTP RX event frame register(PTP RX frame timestamp for seconds),         Address offset: 0x044 */
    __IO uint32_t GMAC_PTPRXPNSEC;                       /*!< PTP RX event frame register(PTP RX frame timestamp for nanoseconds),     Address offset: 0x048 */
    __IO uint32_t GMAC_PTPTXPPSEC;                       /*!< PTP TX peer frame register(PTP TX peer frame timestamp for seconds),     Address offset: 0x04C */
    __IO uint32_t GMAC_PTPTXPPNSEC;                      /*!< PTP TX peer frame register(PTP TX peer frame timestamp for nanoseconds), Address offset: 0x050 */
    __IO uint32_t GMAC_PTPRXPPSEC;                       /*!< PTP RX peer frame register(PTP RX peer frame timestamp for seconds),     Address offset: 0x054 */
    __IO uint32_t GMAC_PTPRXPPNSEC;                      /*!< PTP RX peer frame register(PTP RX peer frame timestamp for seconds),     Address offset: 0x058 */
    __IO uint32_t GMAC_PTPTMR0;                          /*!< PTP timer register(nano-nanosecond timer),                               Address offset: 0x05C */
    __IO uint32_t GMAC_PTPTMR1;                          /*!< PTP timer register(nanosecond timer),                                    Address offset: 0x060 */
    __IO uint32_t GMAC_PTPTMR2;                          /*!< PTP timer register(Second timer),                                        Address offset: 0x064 */
    __IO uint32_t GMAC_PTPPER0;                          /*!< PTP clock period register(The unit is nanosecond),                       Address offset: 0x068 */
    __IO uint32_t GMAC_PTPPER1;                          /*!< PTP clock period register(The unit is nano-nanosecond),                  Address offset: 0x06C */
    __IO uint32_t GMAC_PTPOFF;                           /*!< PTP clock period offset register,                                        Address offset: 0x070 */
    __IO uint32_t GMAC_PTPADJ;                           /*!< PTP Timer Adjustment Register,                                           Address offset: 0x074 */
    __IO uint32_t GMAC_AXICR;                            /*!< AXI interface control register,                                          Address offset: 0x078 */
    __IO uint32_t GMAC_PHYIF;                            /*!< GMAC PHY interface control register,                                     Address offset: 0x07C */
    __IO uint32_t GMAC_SWRSTCYCCNT;                      /*!< GMAC software reset cyclic control register,                             Address offset: 0x080 */
    __IO uint32_t GMAC_EEECR;                            /*!< GMAC EEE control register,                                               Address offset: 0x084 */
    __IO uint32_t GMAC_REV;                              /*!< GMAC revision register,                                                  Address offset: 0x088 */
    __IO uint32_t GMAC_HWFEC;                            /*!< GMAC hardware feature register,                                          Address offset: 0x08C */
    __IO uint32_t RESERVED2[2];                          /*!< Reserved, Address offset: 0x090 ~ 0x094*/
    __IO uint32_t GMAC_BMCSTTHRCR;                       /*!< GMAC broadcast/multicast control register,                               Address offset: 0x098 */
    __IO uint32_t GMAC_PHYCR;                            /*!< PHY control register,                                                    Address offset: 0x09C */
    __IO uint32_t GMAC_PHYDATA;                          /*!< PHY data register,                                                       Address offset: 0x0A0 */
    __IO uint32_t RESERVED3[62];                         /*!< Reserved, Address offset: 0xA4 ~ 0x198 */
    __IO uint32_t GMAC_SYSISR;                           /*!< System interrupt status register,                                        Address offset: 0x19C */
    __IO uint32_t GMAC_SYSIER;                           /*!< System interrupt enable register,                                        Address offset: 0x1A0 */
    __IO uint32_t RESERVED4;                             /*!< Reserved , Address offset: 0x1A4 */
    __IO uint32_t GMAC_MACADDRL;                         /*!< MAC least significant address register,                                  Address offset: 0x1A8 */
    __IO uint32_t GMAC_MACADDRH;                         /*!< MAC most significant address register,                                   Address offset: 0x1AC */
    __IO uint32_t GMAC_MCSTHASHTB0;                      /*!< multicast address hash table 0 register,                                 Address offset: 0x1B0 */
    __IO uint32_t GMAC_MCSTHASHTB1;                      /*!< multicast address hash table 1 register,                                 Address offset: 0x1B4 */
    GMAC_MacFilterRegister_TypeDef MAC_FILTER[8];
    __IO uint32_t RESERVED5[42];                         /*!< Reserved, Address offset: 0x1F8 ~ 0x29C */
    __IO uint32_t GMAC_RSSCR;                            /*!< GMAC RSS control register,                                               Address offset: 0x2A0 */
    __IO uint32_t RSSRK[10];                             /*!< GMAC RSS key register n(n=0~9),                                          Address offset: 0x2A4 ~ 0x2C8*/
    __IO uint32_t RESERVED6[18];                         /*!< Reserved, Address offset: 0x2CC ~ 0x310 */
    __IO uint32_t GMAC_TQWBCR;                           /*!< Transmit descriptor write back control register,                         Address offset: 0x314 */
    __IO uint32_t GMAC_RQWBCR;                           /*!< Receive descriptor write back control register,                          Address offset: 0x318 */
    __IO uint32_t RESERVED7[57];                         /*!< Reserved, Address offset: 0x31C ~ 0x3FC*/

    GMAC_QueueRegister_TypeDef QUEUE_REG[8];

    __IO uint32_t RESERVED8[16];                         /*!< Reserved, Address offset: 0xC00 ~ 0XC3C */
} GMAC_TypeDef;

typedef struct
{
    __IO uint32_t SYSSCU;                                /*!< GMAC config register */
} GMAC_SYSCFG_TypeDef;

typedef struct
{
    __IO uint32_t CR;                                    /*!< GMAC0 PHY control register, Address offset: 0x1110 */
    __IO uint32_t GLCR;                                  /*!< GMAC0 LED control register, Address offset: 0x1114 */
    __IO uint32_t PHYSR;                                 /*!< GMAC0 PHY type register,    Address offset: 0x1118 */
} GPHY_TypeDef;         

/* =========================================================================================================================== */
/* ================                                  GPIO                                                     ================ */
/* =========================================================================================================================== */
/**
  * @brief General Purpose I/O (GPIO)
  */
typedef struct
{
	__IO uint32_t GPIOA_AFR[4];                          /*!< GPIO A alternate function registers,   Address offset: 0x1120 - 0x112C */
	__IO uint32_t GPIOB_AFR[4];                          /*!< GPIO B alternate function registers,   Address offset: 0x1130 - 0x113C */
	__IO uint32_t GPIOC_AFR[4];                          /*!< GPIO C alternate function registers,   Address offset: 0x1140 - 0x114C */
	__IO uint32_t GPIOA_PUR;                             /*!< GPIO A port pull-up register,          Address offset: 0x1150 */
	__IO uint32_t GPIOA_PDR;                             /*!< GPIO A port pull-down register,        Address offset: 0x1154 */
	__IO uint32_t GPIOB_PUR;                             /*!< GPIO B port pull-up register,          Address offset: 0x1158 */
	__IO uint32_t GPIOB_PDR;                             /*!< GPIO B port pull-down register,        Address offset: 0x115C */
	__IO uint32_t GPIOC_PUR;                             /*!< GPIO C port pull-up register,          Address offset: 0x1160 */
	__IO uint32_t GPIOC_PDR;                             /*!< GPIO C port pull-down register,        Address offset: 0x1164 */
	__IO uint32_t GPIOA_DR[2];                           /*!< GPIO A port driver strength registers, Address offset: 0x1168 - 0x116C */
	__IO uint32_t GPIOB_DR[2];                           /*!< GPIO B port driver strength registers, Address offset: 0x1170 - 0x1174 */
	__IO uint32_t GPIOC_DR[2];                           /*!< GPIO C port driver strength registers, Address offset: 0x1178 - 0x117C */
	__IO uint32_t GPIOA_SR;                              /*!< GPIO A port schmitt trigger register,  Address offset: 0x1180 */
	__IO uint32_t GPIOB_SR;                              /*!< GPIO B port schmitt trigger register,  Address offset: 0x1184 */
	__IO uint32_t GPIOC_SR;                              /*!< GPIO C port schmitt trigger register,  Address offset: 0x1188 */
	__IO uint32_t GPIOC_LS3V;                            /*!< GPIO C port level select register,     Address offset: 0x118C */
} GPIO_Attribute_TypeDef;

typedef struct
{
	__IO uint32_t GPIOA50_AFR;                           /*!< GPIO A 5~0 alternate function registers,   Address offset: 0x70 */
	__IO uint32_t GPIOA50_PUR;                           /*!< GPIO A 5~0 port pull-up register,          Address offset: 0x74 */
	__IO uint32_t GPIOA50_PDR;                           /*!< GPIO A 5~0 port pull-down register,        Address offset: 0x78 */
	__IO uint32_t GPIOA50_DR[2];                         /*!< GPIO A 5~0 port driver strength registers, Address offset: 0x7C - 0x80 */
	__IO uint32_t GPIOA50_SR;                            /*!< GPIO A 5~0 port schmitt trigger register,  Address offset: 0x84 */
} GPIOA50_Attribute_TypeDef;

typedef struct
{
	__IO uint32_t DOR;                                   /*!< GPIO data output register,                     Address offset: 0x0 */
	__I  uint32_t DIR;                                   /*!< GPIO data input register,                      Address offset: 0x4 */
	__IO uint32_t PDR;                                   /*!< GPIO pin direction register,                   Address offset: 0x8 */
	uint32_t RESERVED0;                                  /*!< Reserved, 0xC */
	__IO uint32_t DSR;                                   /*!< GPIO data set register,                        Address offset: 0x10 */
	__IO uint32_t DCLR;                                  /*!< GPIO data clear register,                      Address offset: 0x14 */
	uint32_t RESERVED1[2];                               /*!< Reserved, 0x18 - 0x19 */
	__IO uint32_t IER;                                   /*!< GPIO interrupt enable register,                Address offset: 0x20 */
	__I  uint32_t ISR;                                   /*!< GPIO interrupt state register,                 Address offset: 0x24 */
	__I  uint32_t IMSR;                                  /*!< GPIO interrupt masked state register,          Address offset: 0x28 */
	__IO uint32_t IMR;                                   /*!< GPIO interrupt mask register,                  Address offset: 0x2C */
	__IO uint32_t ICLR;                                  /*!< GPIO interrupt clear register,                 Address offset: 0x30 */
	__IO uint32_t ITR;                                   /*!< GPIO interrupt trigger register,               Address offset: 0x34 */
	__IO uint32_t IBR;                                   /*!< GPIO interrupt bothedge register,              Address offset: 0x38 */
	__IO uint32_t IELSR;                                 /*!< GPIO interrupt edge and level select register, Address offset: 0x3C */
	__IO uint32_t DBR;                                   /*!< GPIO debounce register,                        Address offset: 0x40 */
	__IO uint32_t DCR;                                   /*!< GPIO debounce count register,                  Address offset: 0x44 */
} GPIO_TypeDef;

/* =========================================================================================================================== */
/* ================                                   HSM                                                     ================ */
/* =========================================================================================================================== */
/**
  * @brief Hardware Security Module (HSM)
  */
typedef struct
{
    __IO uint32_t QC;                                    /*!< HSM Queue Ctrl register,             Address offset: 0x00 */
    __IO uint32_t QIER;                                  /*!< HSM Queue Interrupt Enable register, Address offset: 0x04 */
    __IO uint32_t QISR;                                  /*!< HSM Queue Interrupt Status register, Address offset: 0x08 */
    __IO uint32_t QLSR;                                  /*!< HSM Queue LSR register,              Address offset: 0x0C */
    uint32_t RESERVED0;                                  /*!< Reserved, 0x10 */
    __IO uint32_t DC;                                    /*!< HSM Descriptor Ctrl register,        Address offset: 0x14 */
    uint32_t RESERVED1[2];                               /*!< Reserved, 0x18-0x1C */
    __IO uint32_t RINGBL;                                /*!< HSM Ring Low Base Address register,  Address offset: 0x20 */
    __IO uint32_t RINGBH;                                /*!< HSM Ring High Base Address register, Address offset: 0x24 */
    __IO uint32_t RINGHD;                                /*!< HSM Ring Header Index register,      Address offset: 0x28 */
    __IO uint32_t RINGTL;                                /*!< HSM Ring Tail Index register,        Address offset: 0x2C */
    uint32_t RESERVED2;                                  /*!< Reserved, 0x30 */
    uint32_t RESERVED3;                                  /*!< Reserved, 0x34 */
    __IO uint32_t FUNCID;                                /*!< HSM Sym Function ID register,        Address offset: 0x38 */
} HSM_TypeDef;

/* =========================================================================================================================== */
/* ================                                  I2C                                                      ================ */
/* =========================================================================================================================== */
/**
  * @brief Inter-integrated Circuit Interface (I2C)
  */
typedef struct
{
    __IO uint32_t CR;                                    /*!< I2C control register,                              Address offset: 0x00 */
    __IO uint32_t SR;                                    /*!< I2C status register,                               Address offset: 0x04 */
    __IO uint32_t CDR;                                   /*!< I2C clock division register,                       Address offset: 0x08 */
    __IO uint32_t DR;                                    /*!< I2C data register,                                 Address offset: 0x0C */
    __IO uint32_t AR;                                    /*!< I2C address register,                              Address offset: 0x10 */
    __IO uint32_t TGSR;                                  /*!< I2C set/hold time and glitch suppression register, Address offset: 0x14 */
    __IO uint32_t BMR;                                   /*!< I2C bus monitor register,                          Address offset: 0x18 */
    __IO uint32_t BSTMR;                                 /*!< I2C burst mode register,                           Address offset: 0x1C */
} I2C_TypeDef;

/* =========================================================================================================================== */
/* ================                                  LP                                                       ================ */
/* =========================================================================================================================== */
/**
  * @brief Low Power sub-system(LP)
  */
typedef struct
{
    uint32_t RESERVED0[4];                               /*!< Reserved, 0x00-0x0C */
    __IO uint32_t RCR;                                   /*!< LPRCCL reset control register, Address offset: 0x10 */
    uint32_t RESERVED1[3];                               /*!< Reserved, 0x14-0x1C */
    __IO uint32_t CCR;                                   /*!< LPRCCL clock control register, Address offset: 0x20 */
    uint32_t RESERVED2[3];                               /*!< Reserved, 0x24-0x2C */
    __IO uint32_t APBDIVR;                               /*!< LPRCCL APB divider register,   Address offset: 0x30 */
    __IO uint32_t UART0DIVR;                             /*!< LPRCCL UART0 divider register, Address offset: 0x34 */
    __IO uint32_t CANA0DIVR;                             /*!< LPRCCL CANA0 divider register, Address offset: 0x38 */
} LPRCCL_TypeDef;

typedef struct
{
    __IO uint32_t SCR;                                   /*!< LPSYSCFGL system control register,                  Address offset: 0x00 */
    __IO uint32_t RAR;                                   /*!< LPSYSCFGL N101 reset address register,              Address offset: 0x04 */
    uint32_t RESERVED0[14];                              /*!< Reserved, 0x08-0x3C */
    __IO uint32_t RRECR;                                 /*!< LPSYSCFGL retention ram ECC control register,       Address offset: 0x40 */
    __IO uint32_t RREEAR;                                /*!< LPSYSCFGL retention ram ECC error address register, Address offset: 0x44 */
    __IO uint32_t RREECR;                                /*!< LPSYSCFGL retention ram ECC error count register,   Address offset: 0x48 */
    uint32_t RESERVED1[9];                               /*!< Reserved, 0x4C-0x6C */
    __IO uint32_t GPIOAAFR;                              /*!< LPSYSCFGL GPIOA[0:4] alternate function register,   Address offset: 0x70 */
    __IO uint32_t GPIOAPUR;                              /*!< LPSYSCFGL GPIOA[0:4] pull up register,              Address offset: 0x74 */
    __IO uint32_t GPIOAPDR;                              /*!< LPSYSCFGL GPIOA[0:4] pull down register,            Address offset: 0x78 */
    __IO uint32_t GPIOADR0;                              /*!< LPSYSCFGL GPIOA[0:4] driver register 0,             Address offset: 0x7C */
    __IO uint32_t GPIOADR1;                              /*!< LPSYSCFGL GPIOA[0:4] driver register 1,             Address offset: 0x80 */
    __IO uint32_t GPIOADSR;                              /*!< LPSYSCFGL GPIOA[0:4] schmidt register,              Address offset: 0x84 */
} LPSYSCFGL_TypeDef;

/* =========================================================================================================================== */
/* ================                                  LTDC                                                     ================ */
/* =========================================================================================================================== */
/**
  * @brief LCD-TFT Display Controller (LTDC)
  */
typedef struct
{
    __IO uint32_t FER;                                   /*!< LTDC function enable register,                           Address offset: 0x00 */
    __IO uint32_t PPCR;                                  /*!< LTDC panel pixel control register,                       Address offset: 0x04 */
    __IO uint32_t IER;                                   /*!< LTDC interrupt enable register,                          Address offset: 0x08 */
    __IO uint32_t ISCR;                                  /*!< LTDC interrupt status clear register,                    Address offset: 0x0C */
    __IO uint32_t ISR;                                   /*!< LTDC interrupt status register,                          Address offset: 0x10 */
    __IO uint32_t ISDR;                                  /*!< LTDC image scaling down register,                        Address offset: 0x14 */
    __IO uint32_t PIFBAR0;                               /*!< LTDC panel image frame base address register0,           Address offset: 0x18 */
    uint32_t      RESERVED0[2];                          /*!< Reserved, 0x1C-0x20 */
    __IO uint32_t PIFBAR1;                               /*!< LTDC panel image frame base address register1,           Address offset: 0x24 */
    uint32_t      RESERVED1[2];                          /*!< Reserved, 0x28-0x2C */
    __IO uint32_t PIFBAR2;                               /*!< LTDC panel image frame base address register2,           Address offset: 0x30 */
    uint32_t      RESERVED2[2];                          /*!< Reserved, 0x34-0x38 */
    __IO uint32_t PIFBAR3;                               /*!< LTDC panel image frame base address register3,           Address offset: 0x3C */
    uint32_t      RESERVED3[2];                          /*!< Reserved, 0x40-0x44 */
    __IO uint32_t PBGR;                                  /*!< LTDC pattern bar generator register,                     Address offset: 0x48 */
    __IO uint32_t FTCR;                                  /*!< LTDC fifo threshold control register,                    Address offset: 0x4C */
    uint32_t      RESERVED4[44];                         /*!< Reserved, 0x50-0xFC */
    __IO uint32_t HTCPR;                                 /*!< LTDC panel horizontal timing control parameter register, Address offset: 0x100 */
    __IO uint32_t VTCPR;                                 /*!< LTDC panel vertical timing control parameter register,   Address offset: 0x104 */
    __IO uint32_t VBPPR;                                 /*!< LTDC panel vertical back porch parameter register,       Address offset: 0x108 */
    __IO uint32_t PCPR;                                  /*!< LTDC panel polarity control parameter register,          Address offset: 0x10C */
    uint32_t      RESERVED5[60];                         /*!< Reserved, 0x110-0x1FC */
    uint32_t      RESERVED6[64];                         /*!< Reserved, 0x200-0x2FC */
    __IO uint32_t PIPBR;                                 /*!< LTDC pip blending register,                              Address offset: 0x300 */
    __IO uint32_t SP1PR;                                 /*!< LTDC sub-picture1 position register,                     Address offset: 0x304 */
    __IO uint32_t SP1DR;                                 /*!< LTDC sub-picture1 dimension register,                    Address offset: 0x308 */
    __IO uint32_t SP2PR;                                 /*!< LTDC sub-picture2 position register,                     Address offset: 0x30C */
    __IO uint32_t SP2DR;                                 /*!< LTDC sub-picture2 dimension register,                    Address offset: 0x310 */
    __IO uint32_t PIPPCR;                                /*!< LTDC pip priority control register,                      Address offset: 0x314 */
    __IO uint32_t IFR1;                                  /*!< LTDC image format register1,                             Address offset: 0x318 */
    __IO uint32_t IFR2;                                  /*!< LTDC image format register2,                             Address offset: 0x31C */
    __IO uint32_t PIPCKR1;                               /*!< LTDC pip color key register1,                            Address offset: 0x320 */
    __IO uint32_t PIPCKR2;                               /*!< LTDC pip color key register2,                            Address offset: 0x324 */
    __IO uint32_t PIPCKR3;                               /*!< LTDC pip color key register3,                            Address offset: 0x328 */
    __IO uint32_t SP3PR;                                 /*!< LTDC sub-picture3 position register,                     Address offset: 0x32C */
    __IO uint32_t SP3DR;                                 /*!< LTDC sub-picture3 dimension register,                    Address offset: 0x330 */
    uint32_t      RESERVED7[179];                        /*!< Reserved, 0x334-0x5FC */
    __IO uint32_t GRTR[64];                              /*!< LTDC gamma red table register,                           Address offset: 0x600 */
    __IO uint32_t GGTR[64];                              /*!< LTDC gamma green table register,                         Address offset: 0x700 */
    __IO uint32_t GBTR[64];                              /*!< LTDC gamma blue table register,                          Address offset: 0x800 */
    uint32_t      RESERVED8[64];                         /*!< Reserved, 0x804-0x9FC */
    __IO uint32_t PRR[128];                              /*!< LTDC palette ram register,                               Address offset: 0xA00~0xBFC */
    uint32_t      RESERVED9[320];                        /*!< Reserved, 0xC00-0x10FC */
    __IO uint32_t SIHRR;                                 /*!< LTDC scaler input horizontal resolution register,        Address offset: 0x1100 */
    __IO uint32_t SIVRR;                                 /*!< LTDC scaler input vertical resolution register,          Address offset: 0x1104 */
    __IO uint32_t SOHRR;                                 /*!< LTDC scaler ouput horizontal resolution register,        Address offset: 0x1108 */
    __IO uint32_t SOVRR;                                 /*!< LTDC scaler output vertical resolution register,         Address offset: 0x110C */
    __IO uint32_t SCR;                                   /*!< LTDC scaler control register,                            Address offset: 0x1110 */
    __IO uint32_t HHTR;                                  /*!< LTDC horizontal high threshold register,                 Address offset: 0x1114 */
    __IO uint32_t HLTR;                                  /*!< LTDC horizontal low threshold register,                  Address offset: 0x1118 */
    __IO uint32_t VHTR;                                  /*!< LTDC vertical high threshold register,                   Address offset: 0x111C */
    __IO uint32_t VLTR;                                  /*!< LTDC vertical low threshold register,                    Address offset: 0x1120 */
    uint32_t      RESERVED10[2];                         /*!< Reserved, 0x1124-0x1128 */
    __IO uint32_t SRR;                                   /*!< LTDC scaler resolution register,                         Address offset: 0x112C */
} LTDC_TypeDef;

/* =========================================================================================================================== */
/* ================                                   MAC                                                     ================ */
/* =========================================================================================================================== */
/**
  * @brief MAC
  */
typedef struct
{
    __IO uint32_t MAC_ISR;                               /*!< Interrupt Status Register                         Address offset: 0x00 */
    __IO uint32_t MAC_IER;                               /*!< Interrupt Enable Register                         Address offset: 0x04 */
    __IO uint32_t MAC_MADR;                              /*!< MAC Most Significant Address Register             Address offset: 0x08 */
    __IO uint32_t MAC_LADR;                              /*!< MAC Least Significant Address Register            Address offset: 0x0C */
    __IO uint32_t MAC_MAHT0;                             /*!< Multicast Address Hash Table 0 Register           Address offset: 0x10 */
    __IO uint32_t MAC_MAHT1;                             /*!< Multicast Address Hash Table 1 Register           Address offset: 0x14 */
    __IO uint32_t MAC_NPTXPD;                            /*!< Normal Priority Transmit Poll Demand Register     Address offset: 0x18 */
    __IO uint32_t MAC_RXPD;                              /*!< Receive Poll Demand Register                      Address offset: 0x1C */
    __IO uint32_t MAC_NPTRBAR;                           /*!< Normal Priority Transmit Ring Base Address Register Address offset: 0x20 */
    __IO uint32_t MAC_RRBAR;                             /*!< Receive Ring Base Address Register                Address offset: 0x24 */
    __IO uint32_t MAC_HPTPDR;                            /*!< High Priority Transmit Poll Demand Register       Address offset: 0x28 */
    __IO uint32_t MAC_HPTXRBADR;                         /*!< High Priority Transmit Ring Base Address Register Address offset: 0x2C */
    __IO uint32_t MAC_TXITC;                             /*!< TX Interrupt Timer Control Register               Address offset: 0x30 */
    __IO uint32_t MAC_RXITC;                             /*!< RX Interrupt Timer Control Register               Address offset: 0x34 */
    __IO uint32_t MAC_APTC;                              /*!< Automatic Polling Timer Control Register          Address offset: 0x38 */
    __IO uint32_t MAC_DBLAC;                             /*!< DMA Burst Length and Arbitration Control Register Address offset: 0x3C */
    __IO uint32_t MAC_DMAFIFOS;                          /*!< DMA/FIFO State Register                           Address offset: 0x40 */
    __IO uint32_t RESERVED0;                             /*!< Address offset: 0x44 */
    __IO uint32_t MAC_TPAFCR;                            /*!< Transmit Priority Arbitration and FIFO Control Register   Address offset: 0x48 */
    __IO uint32_t MAC_RBSR;                              /*!< Receive Buffer Size Register                      Address offset: 0x4C */
    __IO uint32_t MAC_CR;                                /*!< MAC Control Register                              Address offset: 0x50 */
    __IO uint32_t MAC_SR;                                /*!< MAC Status Register                               Address offset: 0x54 */
    __IO uint32_t RESERVED1;                             /*!< Address offset: 0x58 */
    __IO uint32_t RESERVED2;                             /*!< Address offset: 0x5C */
    __IO uint32_t MAC_PHYCR;                             /*!< PHY Control Register                              Address offset: 0x60 */
    __IO uint32_t MAC_PHYDATA;                           /*!< PHY Data Register                                 Address offset: 0x64 */
    __IO uint32_t MAC_FCR;                               /*!< Flow Control Register                             Address offset: 0x68 */
    __IO uint32_t MAC_BPR;                               /*!< Back Pressure Register                            Address offset: 0x6C */
    __IO uint32_t MAC_WOLCR;                             /*!< Wake-On-LAN Control Register                      Address offset: 0x70 */
    __IO uint32_t MAC_WOLSR;                             /*!< Wake-On-LAN Status Register                       Address offset: 0x74 */
    __IO uint32_t MAC_WFCRC;                             /*!< Wake-up Frame CRC Register                        Address offset: 0x78 */
    __IO uint32_t RESERVED3;                             /*!< Address offset: 0x7C */
    __IO uint32_t MAC_WFBM1;                             /*!< Wake-up Frame Byte Mask 1st Double-word Register  Address offset: 0x80 */
    __IO uint32_t MAC_WFBM2;                             /*!< Wake-up Frame Byte Mask 2st Double-word Register  Address offset: 0x84 */
    __IO uint32_t MAC_WFBM3;                             /*!< Wake-up Frame Byte Mask 3st Double-word Register  Address offset: 0x88 */
    __IO uint32_t MAC_WFBM4;                             /*!< Wake-up Frame Byte Mask 4st Double-word Register  Address offset: 0x8C */
    __IO uint32_t MAC_NPTXRPTR;                          /*!< Normal Priority Transmit Ring Pointer Register    Address offset: 0x90 */
    __IO uint32_t MAC_HPTXRPTR;                          /*!< High Priority Transmit Ring Pointer Register      Address offset: 0x94 */
    __IO uint32_t MAC_RXRPTR;                            /*!< Receive Ring Pointer Register                     Address offset: 0x98 */
    __IO uint32_t RESERVED4;                             /*!< Address offset: 0x9C */
    __IO uint32_t MAC_TXCNT1;                            /*!< TPKT_CNT Counter Register                         Address offset: 0xA0 */
    __IO uint32_t MAC_TXCNT2;                            /*!< TXMCOL_CNT and TXSCOL_CNT Counter Register        Address offset: 0xA4 */
    __IO uint32_t MAC_TXCNT3;                            /*!< TXECOL_CNT and TXFAIL_CNT Counter Register        Address offset: 0xA8 */
    __IO uint32_t MAC_TXCNT4;                            /*!< TXLCOL_CNT and TXUNDERUN_CNT Counter Register     Address offset: 0xAC */
    __IO uint32_t MAC_RXCNT1;                            /*!< RPKT_CNT Counter Register                         Address offset: 0xB0 */
    __IO uint32_t MAC_RXCNT2;                            /*!< BROPKT_CNT Counter Register                       Address offset: 0xB4 */
    __IO uint32_t MAC_RXCNT3;                            /*!< MULPKT_CNT Counter Register                       Address offset: 0xB8 */
    __IO uint32_t MAC_RXCNT4;                            /*!< RPF_CNT and AEP_CNT Counter Register              Address offset: 0xBC */
    __IO uint32_t MAC_RXCNT5;                            /*!< RUNT_CNT Counter Register                         Address offset: 0xC0 */
    __IO uint32_t MAC_RXCNT6;                            /*!< CRCER_CNT and FTL_CNT Counter Register            Address offset: 0xC4 */
    __IO uint32_t MAC_RXCNT7;                            /*!< RCOL_CNT and RLOST_CNT Counter Register           Address offset: 0xC8 */
    __IO uint32_t RESERVED5;                             /*!< Address offset: 0xCC */
    __IO uint32_t MAC_BMTHRCTRL;                         /*!< Broadcast and Multicast Receiving Control Register Address offset: 0xD0 */
    __IO uint32_t RESERVED6[3];                          /*!< Address offset: 0xD4 ~ Address offset: 0xDC */
    __IO uint32_t MAC_ERCR;                              /*!< Error Response Control Register                   Address offset: 0xE0 */
    __IO uint32_t RESERVED7[2];                          /*!<  */
    __IO uint32_t MAC_SCCR;                              /*!< SW Reset Cycle Count Register                     Address offset: 0xEC */
    __IO uint32_t MAC_ECT;                               /*!< EEE Control Register                              Address offset: 0xF0 */
} MAC_TypeDef;

/* =========================================================================================================================== */
/* ================                                  PWR                                                      ================ */
/* =========================================================================================================================== */
/**
  * @brief Power (PWR)
  */
typedef struct
{
    __IO uint32_t PCR;                                   /*!< PWRPCR power control register, Address offset: 0x00 */
} PWRPCR_TypeDef;

typedef struct
{
    __IO uint32_t CR;                                    /*!< PWRPMU control register,           Address offset: 0x00 */
    __IO uint32_t PWONCR;                                /*!< PWRPMU power on control register,  Address offset: 0x04 */
    __IO uint32_t PWOFFCR;                               /*!< PWRPMU power off control register, Address offset: 0x08 */
    __IO uint32_t SR;                                    /*!< PWRPMU status register,            Address offset: 0x0C */
} PWRPMU_TypeDef;


/* =========================================================================================================================== */
/* ================                                  RCC                                                     ================ */
/* =========================================================================================================================== */
/**
  * @brief Reset and Clock Control (RCC)
  */
typedef struct
{
    __IO uint32_t CR;                                    /*!< RCC control register,                  Address offset: 0x00 */
    __IO uint32_t CNTR;                                  /*!< RCC count register,                    Address offset: 0x04 */
    __IO uint32_t RCR0;                                  /*!< RCC record register 0,                 Address offset: 0x08 */
    __IO uint32_t RCR1;                                  /*!< RCC record register 1,                 Address offset: 0x0C */
    uint32_t      RESERVED0[2];                          /*!< Reserved, 0x10 - 0x14 */
    __IO uint32_t UX608RAR;                              /*!< RCC UX608 reset address register,      Address offset: 0x18 */
    __IO uint32_t UX608LRAR;                             /*!< RCC UX608_Lite reset address register, Address offset: 0x1C */
    uint32_t      RESERVED1[12];                         /*!< Reserved, 0x20 - 0x4C */
    __IO uint32_t PLLSCFGR;                              /*!< RCC PLLSYS config register,            Address offset: 0x50 */
    __IO uint32_t PLLGMAC;                               /*!< RCC PLLGMAC config register,           Address offset: 0x54 */
    __IO uint32_t PLLDCFGR;                              /*!< RCC PLLDDR config register,            Address offset: 0x58 */
    __IO uint32_t PLLHP0R;                               /*!< RCC PLLHP0R config register,           Address offset: 0x5C */
    __IO uint32_t PLLHP0DIVR;                            /*!< RCC PLLHP0DIVR config register,        Address offset: 0x60 */
    uint32_t      RESERVED3[7];                          /*!< Reserved, 0x64-0x7C */
    __IO uint32_t CLKCR0;                                /*!< RCC clock control register 0,          Address offset: 0x80 */
    __IO uint32_t CLKCR1;                                /*!< RCC clock control register 1,          Address offset: 0x84 */
    __IO uint32_t CLKCR2;                                /*!< RCC clock control register 2,          Address offset: 0x88 */
    __IO uint32_t AXIDIVR;                               /*!< RCC AXI divider register,              Address offset: 0x8C */
    __IO uint32_t AHB0DIVR;                              /*!< RCC AHB0 divider register,             Address offset: 0x90 */
    __IO uint32_t APB0DIVR;                              /*!< RCC APB0 divider register,             Address offset: 0x94 */
    __IO uint32_t UX608DIVR;                             /*!< RCC CPU divider register,              Address offset: 0x98 */
    __IO uint32_t HSMDIVR;                               /*!< RCC HSM divider register,              Address offset: 0x9C */
    __IO uint32_t LPDIVR;                                /*!< RCC LP divider register,               Address offset: 0xA0 */
    __IO uint32_t FMC0DIVR;                              /*!< RCC FMC0 divider register,             Address offset: 0xA4 */
    __IO uint32_t FMC1DIVR;                              /*!< RCC FMC1 divider register,             Address offset: 0xA8 */
    __IO uint32_t UART1DIVR;                             /*!< RCC UART1 divider register,            Address offset: 0xAC */
    __IO uint32_t UART2DIVR;                             /*!< RCC UART2 divider register,            Address offset: 0xB0 */
    __IO uint32_t UART3DIVR;                             /*!< RCC UART3 divider register,            Address offset: 0xB4 */
    __IO uint32_t UART4DIVR;                             /*!< RCC UART4 divider register,            Address offset: 0xB8 */
    __IO uint32_t UART5DIVR;                             /*!< RCC UART5 divider register,            Address offset: 0xBC */
    __IO uint32_t UART6DIVR;                             /*!< RCC UART6 divider register,            Address offset: 0xC0 */
    __IO uint32_t UART7DIVR;                             /*!< RCC UART7 divider register,            Address offset: 0xC4 */
    __IO uint32_t SCI0DIVR;                              /*!< RCC SCI0 divider register,             Address offset: 0xC8 */
    __IO uint32_t SCI1DIVR;                              /*!< RCC SCI1 divider register,             Address offset: 0xCC */
    __IO uint32_t SPI0DIVR;                              /*!< RCC SPI0 divider register,             Address offset: 0xD0 */
    __IO uint32_t SPI1DIVR;                              /*!< RCC SPI1 divider register,             Address offset: 0xD4 */
    __IO uint32_t SSP0DIVR;                              /*!< RCC clock divider register,            Address offset: 0xD8 */
    __IO uint32_t SSP1DIVR;                              /*!< RCC clock divider register,            Address offset: 0xDC */
    __IO uint32_t CANA1DIVR;                             /*!< RCC CANA1 divider register,            Address offset: 0xE0 */
    __IO uint32_t CANA2DIVR;                             /*!< RCC CANA2 divider register,            Address offset: 0xE4 */
    __IO uint32_t CANA3DIVR;                             /*!< RCC CANA3 divider register,            Address offset: 0xE8 */
    __IO uint32_t CANB0DIVR;                             /*!< RCC CANB0 divider register,            Address offset: 0xEC */
    __IO uint32_t CANB1DIVR;                             /*!< RCC CANB1 divider register,            Address offset: 0xF0 */
    __IO uint32_t CANB2DIVR;                             /*!< RCC CANB2 divider register,            Address offset: 0xF4 */
    __IO uint32_t CANB3DIVR;                             /*!< RCC CANB3 divider register,            Address offset: 0xF8 */
    uint32_t      RESERVED4[10];                         /*!< Reserved, 0xFC - 0x120 */
    __IO uint32_t SDHC1DIVR;                             /*!< RCC SDHC1 divider register,            Address offset: 0x124 */
    __IO uint32_t SDHC2DIVR;                             /*!< RCC SDHC2 divider register,            Address offset: 0x128 */
    __IO uint32_t SDHC0DIVR;                             /*!< RCC SDHC0 divider register,            Address offset: 0x12C */
    uint32_t      RESERVED5;                             /*!< Reserved, 0x130 */
    __IO uint32_t LTDCLCDIVR;                            /*!< RCC LTDCLC divider register,           Address offset: 0x134 */
    __IO uint32_t LTDCTVDIVR;                            /*!< RCC LTDCTV divider register,           Address offset: 0x138 */
    __IO uint32_t LTDCSCALDIVR;                          /*!< RCC LTDCSCAL divider register,         Address offset: 0x13C */
    uint32_t      RESERVED6[4];                          /*!< Reserved, 0x140 - 0x14C */
    __IO uint32_t PCIETLDIVR;                            /*!< RCC PCIETL divider register,           Address offset: 0x150 */
    uint32_t      RESERVED7[7];                          /*!< Reserved, 0x154 - 0x16C */
    __IO uint32_t RSTCR0;                                /*!< RCC reset control register 0,          Address offset: 0x170 */
    __IO uint32_t RSTCR1;                                /*!< RCC reset control register 1,          Address offset: 0x174 */
    __IO uint32_t RSTCR2;                                /*!< RCC reset control register 2,          Address offset: 0x178 */
} RCC_TypeDef;


/* =========================================================================================================================== */
/* ================                                  RTC                                                      ================ */
/* =========================================================================================================================== */
/**
  * @brief Real-Time Clock (RTC)
  */
typedef struct
{
    __IO uint32_t SECOND;                                /*!< RTC Second Register,            Address offset: 0x00 */
    __IO uint32_t MINUTE;                                /*!< RTC Minute Register,            Address offset: 0x04 */
    __IO uint32_t HOUR;                                  /*!< RTC Hour Register,              Address offset: 0x08 */
    __IO uint32_t DAY;                                   /*!< RTC Day Register,               Address offset: 0x0C */
    __IO uint32_t ALMSEC;                                /*!< RTC Alarm Second Register,      Address offset: 0x10 */
    __IO uint32_t ALMMIN;                                /*!< RTC Alarm Minute Register,      Address offset: 0x14 */
    __IO uint32_t ALMHOUR;                               /*!< RTC Alarm Hour Register,        Address offset: 0x18 */
    uint32_t RESERVED0;                                  /*!< Reserved, 0x1C */
    __IO uint32_t CR;                                    /*!< RTC Control Register,           Address offset: 0x20 */
    __IO uint32_t WSECOND;                               /*!< RTC Write Second Register,      Address offset: 0x24 */
    __IO uint32_t WMINUTE;                               /*!< RTC Write Minute Register,      Address offset: 0x28 */
    __IO uint32_t WHOUR;                                 /*!< RTC Write Hour Register,        Address offset: 0x2C */
    __IO uint32_t WDAY;                                  /*!< RTC Write DAY Register,         Address offset: 0x30 */
    __IO uint32_t ISR;                                   /*!< RTC Interrupt Status Register,  Address offset: 0x34 */
    uint32_t RESERVED1[2];                               /*!< Reserved, 0x38-0x3C */
    __IO uint32_t RWS;                                   /*!< RTC Read Write Status Register, Address offset: 0x40 */
    __IO uint32_t CUR;                                   /*!< RTC Current Register,           Address offset: 0x44 */
    __IO uint32_t SLEPTIM;                               /*!< RTC Sleep Time Register,        Address offset: 0x48 */
    __IO uint32_t CURDATE;                               /*!< RTC Current Date Register,      Address offset: 0x4C */
    __IO uint32_t SLEPDATE;                              /*!< RTC Sleep Date Register,        Address offset: 0x50 */
} RTC_TypeDef;

/* =========================================================================================================================== */
/* ================                                  SCI                                                      ================ */
/* =========================================================================================================================== */
/**
  * @brief Smart Card Interface
  */
typedef struct
{
    __IO uint32_t DR;                                    /*!< SCI data register,                            Address offset: 0x00 */
    __IO uint32_t CR0;                                   /*!< SCI control register 0,                       Address offset: 0x04 */
    __IO uint32_t CR1;                                   /*!< SCI control register 0,                       Address offset: 0x08 */
    __IO uint32_t CR2;                                   /*!< SCI control register 0,                       Address offset: 0x0C */
    __IO uint32_t IER;                                   /*!< SCI interrupt enable register,                Address offset: 0x10 */
    __IO uint32_t RETRY;                                 /*!< SCI retry limit register,                     Address offset: 0x14 */
    __IO uint32_t FTHR;                                  /*!< SCI FIFO Threshold mark register,             Address offset: 0x18 */
    __IO uint32_t TFCNTR;                                /*!< SCI transmit FIFO count/clear register,       Address offset: 0x1C */
    __IO uint32_t RFCNTR;                                /*!< SCI receive FIFO count/clear register,        Address offset: 0x20 */
    __IO uint32_t FSR;                                   /*!< SCI FIFO flag register,                       Address offset: 0x24 */
    __IO uint32_t RXTOUTR;                               /*!< SCI receive read timeout register,            Address offset: 0x28 */
    __IO uint32_t ICCSR;                                 /*!< SCI ICC status register,                      Address offset: 0x2C */
    uint32_t      RESERVED0;
    __IO uint32_t ATIME;                                 /*!< SCI activation event time register,           Address offset: 0x34 */
    __IO uint32_t DTIME;                                 /*!< SCI deactivation event time register,         Address offset: 0x38 */
    __IO uint32_t ATRSTIME;                              /*!< the time to start of ATR reception register,  Address offset: 0x3C */
    __IO uint32_t ATRDTIME;                              /*!< maximum duration of ATR character register,   Address offset: 0x40 */
    __IO uint32_t BLKTIME;                               /*!< SCI receive timeout between blocks register,  Address offset: 0x44 */
    __IO uint32_t CHTIME;                                /*!< character to character timeout register,      Address offset: 0x48 */
    __IO uint32_t CLKICC;                                /*!< external smart card clcok frequency register, Address offset: 0x4C */
    __IO uint32_t BAUD;                                  /*!< SCI baud rate clock register,                 Address offset: 0x50 */
    __IO uint32_t VALUE;                                 /*!< SCI baud cycles register,                     Address offset: 0x54 */
    __IO uint32_t CHGUARD;                               /*!< character to character extra guard time reg,  Address offset: 0x58 */
    __IO uint32_t BLKGUARD;                              /*!< SCI block guard time register,                Address offset: 0x5C */
    __IO uint32_t IOCR;                                  /*!< asynchronous/synchronous multiplexing reg,    Address offset: 0x60 */
    __IO uint32_t IOSYNC;                                /*!< synchronous smart card data register,         Address offset: 0x64 */
    __IO uint32_t IOSR;                                  /*!< raw input/output and clock status register,   Address offset: 0x68 */
    __IO uint32_t ISR;                                   /*!< SCI interruot identification/clear register,  Address offset: 0x6C */
}SCI_TypeDef;

/* =========================================================================================================================== */
/* ================                                  SDDC                                                     ================ */
/* =========================================================================================================================== */
/**
  * @brief Secure Digital memory card Device Controller (SDDC)
  */
// TODO : serial number from 1
typedef struct
{
    __IO uint32_t CR;                                    /*!< SDDC Control register,             Address offset: 0x00 */
    __I uint32_t CMD;                                    /*!< SDDC received command register,    Address offset: 0x04 */
    __I uint32_t ARG;                                    /*!< SDDC received argument register,   Address offset: 0x08 */
    __I uint32_t BCOUNT;                                 /*!< SDDC Block count register,         Address offset: 0x0C */
    __IO uint32_t DMA1AR;                                /*!< SDDC DMA1 Address register,        Address offset: 0x10 */
    __IO uint32_t DMA1CR;                                /*!< SDDC DMA1 Contrl register,         Address offset: 0x14 */
    __IO uint32_t DMA2AR;                                /*!< SDDC DMA2Address register,         Address offset: 0x14 */
    __IO uint32_t DMA2CR;                                /*!< SDDC DMA2Address register,         Address offset: 0x1C */
    __I uint32_t EWSAR;                                  /*!< Erase Write Block Start Register,  Address offset: 0x20 */
    __I uint32_t EWEAR;                                  /*!< Erase Write Block End Register,    Address offset: 0x24 */
    __IO uint32_t PLR;                                   /*!< Password Length Register,          Address offset: 0x28 */
    __IO uint32_t SBCOUNT;                               /*!< Secure Block Count Register,       Address offset: 0x2C */
    uint32_t RESERVED0[3];
    __IO uint32_t ISR;                                   /*!< Interrupt Status Register,         Address offset: 0x3C */
    __IO uint32_t ISCR;                                  /*!< Interrupt Status Enable Register,  Address offset: 0x40 */
    __IO uint32_t ISGCR;                                 /*!< Interrupt Signal Enable Register,  Address offset: 0x44 */
    __IO uint32_t CAR;                                   /*!< CardAddress Register,              Address offset: 0x48 */
    __IO uint32_t CDR;                                   /*!< Card Data Register,                Address offset: 0x4C */
    __IO uint32_t IORR;                                  /*!< IOREADY Register,                  Address offset: 0x50 */
    __IO uint32_t FUN1;                                  /*!< Function1 Control Register,        Address offset: 0x54 */
    __IO uint32_t FUN2;                                  /*!< Function2 Control Register,        Address offset: 0x58 */
    __IO uint32_t CCCR;                                  /*!< SDIO CCCR Control Register,        Address offset: 0x5C */
    __IO uint32_t FBR0;                                  /*!< SDIO FBR0 Control Register,        Address offset: 0x60 */
    __IO uint32_t FBR1;                                  /*!< SDIO FBR1 Control Register,        Address offset: 0x64 */
    __IO uint32_t FBR2;                                  /*!< SDIO FBR2 Control Register,        Address offset: 0x68 */
    __IO uint32_t FBR3;                                  /*!< SDIO FBR3 Control Register,        Address offset: 0x6C */
    __IO uint32_t FBR4;                                  /*!< SDIO FBR4 Control Register,        Address offset: 0x70 */
    __IO uint32_t FBR5;                                  /*!< SDIO FBR5 Control Register,        Address offset: 0x74 */
    __IO uint32_t FBR6;                                  /*!< SDIO FBR6 Control Register,        Address offset: 0x78 */
    __IO uint32_t FBR7;                                  /*!< SDIO FBR7 Control Register,        Address offset: 0x7C */
    __IO uint32_t CSIZE;                                 /*!< Card Size Register,                Address offset: 0x80 */
    __IO uint32_t OCR;                                   /*!< Secure Block Count Register,       Address offset: 0x84 */
    __IO uint32_t CR2;                                   /*!< Card OCR Register,                 Address offset: 0x88 */
    uint32_t RESERVED2;
    __IO uint32_t FUN3;                                  /*!< Function3 Control Register,        Address offset: 0x90 */
    __IO uint32_t FUN4;                                  /*!< Function4 Control Register,        Address offset: 0x94 */
    __IO uint32_t FUN5;                                  /*!< Function5 Control Register,        Address offset: 0x98 */
    __IO uint32_t ISR2;                                  /*!< Interrupt Status2 Register,        Address offset: 0x9C */
    __IO uint32_t ISCR2;                                 /*!< Interrupt Status Enable2 Register, Address offset: 0xA0 */
    __IO uint32_t ISGCR2;                                /*!< Interrupt Signal Enable2 Register, Address offset: 0xA4 */
    __IO uint32_t PSWD4;                                 /*!< Password Register_127_96,          Address offset: 0xA8 */
    __IO uint32_t PSWD3;                                 /*!< Password_95_64 Register,           Address offset: 0xAC */
    __IO uint32_t PSWD2;                                 /*!< Password_64_32 Register,           Address offset: 0xB0 */
    __IO uint32_t PSWD1;                                 /*!< Password_31_0 Register,            Address offset: 0xB4 */
    __IO uint32_t ADMAESR;                               /*!< ADMA Error Status Register,        Address offset: 0xB8 */
    __IO uint32_t RCA;                                   /*!< RCA Register,                      Address offset: 0xBC */
    uint32_t RESERVED3[7];
    __IO uint32_t BURST;                                 /*!< AHB Master Burst size register,    Address offset: 0xDC */
    __IO uint32_t ARG2;                                  /*!< Argument2 Register,                Address offset: 0xE0 */
} SDDC_TypeDef;

/* =========================================================================================================================== */
/* ================                                  SDC SYSTEM CONFIG                                        ================ */
/* =========================================================================================================================== */
/**
  * @brief Secure Digital HOST/DEVICE Controller (SDC)
  */
typedef struct
{
    __IO uint32_t SR;                                    /*!< SDC Host or Device Mode Switch register, Address offset: 0x00 */
    __IO uint32_t SYSCR;                                 /*!< SDC System Control register,             Address offset: 0x04 */
    uint32_t RESERVED0;                                  /*!< Reserved, 0x8 */
    __IO uint32_t SMID;                                  /*!< SDC SMID,                                Address offset: 0x0C */
    __IO uint32_t OCR;                                   /*!< SDC SDIO Operation condition register,   Address offset: 0x10 */
    uint32_t RESERVED1;                                  /*!< Reserved, 0x14 */
    __IO uint32_t DLLCR;                                 /*!< SDC DLL Control register,                Address offset: 0x18 */
    uint32_t RESERVED2[28];                              /*!< Reserved, 0x1C - 0x88 */
    __IO uint32_t IOCR;                                  /*!< SDC IO Control register,                 Address offset: 0x8C */
} SDC_Config_TypeDef;

/* =========================================================================================================================== */
/* ================                                  SDHC                                                     ================ */
/* =========================================================================================================================== */
/**
  * @brief Secure Digital Host Controller (SDHC)
  */
typedef struct
{
    __IO uint32_t SDMASAR;                               /*!< SDMA System Address register,                Address offset: 0x00 */
    __IO uint16_t BSR;                                   /*!< Block Size register,                         Address offset: 0x04 */
    __IO uint16_t BCR;                                   /*!< Block Count register,                        Address offset: 0x06 */
    __IO uint32_t ARG;                                   /*!< Argument register,                           Address offset: 0x08 */
    __IO uint16_t TMR;                                   /*!< Transfer mode register,                      Address offset: 0x0C */
    __IO uint16_t CMDR;                                  /*!< Command register,                            Address offset: 0x0E */
    __IO uint32_t RESPO;                                 /*!< Response register 0,                         Address offset: 0x10 */
    __IO uint32_t RESP1;                                 /*!< Response register 1,                         Address offset: 0x14 */
    __IO uint32_t RESP2;                                 /*!< Response register 2,                         Address offset: 0x18 */
    __IO uint32_t RESP3;                                 /*!< Response register 3,                         Address offset: 0x1C */
    __IO uint32_t BDP;                                   /*!< Buffer Data Port register,                   Address offset: 0x20 */
    __IO uint32_t SR;                                    /*!< Present state register,                      Address offset: 0x24 */
    __IO uint8_t HC0;                                    /*!< Host Control register 0,                     Address offset: 0x28 */
    __IO uint8_t PCR;                                    /*!< Power Control register,                      Address offset: 0x29 */
    __IO uint8_t BGCR;                                   /*!< Block Gap Control register,                  Address offset: 0x2A */
    uint8_t      RESERVED0;                              /*!< Reserved, 0x2B */
    __IO uint16_t CCR;                                   /*!< Clock Control register,                      Address offset: 0x2C */
    __IO uint8_t TCR;                                    /*!< Timeout Control register,                    Address offset: 0x2E */
    __IO uint8_t SRR;                                    /*!< Software Reset register,                     Address offset: 0x2F */
    __IO uint16_t NISR;                                  /*!< Normal Interrupt Status register,            Address offset: 0x30 */
    __IO uint16_t EISR;                                  /*!< Error Interrupt Status register,             Address offset: 0x32 */
    __IO uint16_t NISER;                                 /*!< Normal Interrupt Status Enable register,     Address offset: 0x34 */
    __IO uint16_t EISER;                                 /*!< Error Interrupt Status Enable register,      Address offset: 0x36 */
    __IO uint16_t NIER;                                  /*!< Normal Interrupt Signal Enable register,     Address offset: 0x38 */
    __IO uint16_t EIER;                                  /*!< Error Interrupt Signal Enable register,      Address offset: 0x3A */
    __IO uint16_t AC12ESR;                               /*!< Auto CMD12 Error Status register,            Address offset: 0x3C */
    __IO uint16_t HC1;                                   /*!< Host Control register 1,                     Address offset: 0x3E */
    __IO uint32_t CAP0;                                  /*!< Capabilities 0 register,                     Address offset: 0x40 */
    __IO uint32_t CAP1;                                  /*!< Capabilities 1 register,                     Address offset: 0x44 */
    uint32_t      RESERVED1[2];                          /*!< Reserved, 0x48 - 0x4c */
    __IO uint16_t ACEFER;                                /*!< Force Event for the Auto CMD12 Error Status, Address offset: 0x50 */
    __IO uint16_t EISFER;                                /*!< Force Event for the Error Interrupt Status,  Address offset: 0x52 */
    __IO uint8_t ADMAESR;                                /*!< ADMA Eoor Status register,                   Address offset: 0x54 */
    uint8_t      RESERVED2;                              /*!< Reserved, 0x55 */
    uint16_t     RESERVED3;                              /*!< Reserved, 0x56 */
    __IO uint32_t ADMASALR;                              /*!< ADMA Low System Address register,            Address offset: 0x58 */
    uint32_t      RESERVED4;                             /*!< Reserved, 0x5C */
    __IO uint32_t PV0;                                   /*!< Preset Value 0,                              Address offset: 0x60 */
    __IO uint32_t PV1;                                   /*!< Preset Value 1,                              Address offset: 0x64 */
    __IO uint32_t PV2;                                   /*!< Preset Value 0,                              Address offset: 0x68 */
    __IO uint32_t PV3;                                   /*!< Preset Value 0,                              Address offset: 0x6C */
    uint32_t      RESERVED5[35];                         /*!< Reserved, 0x70 - 0xF8 */
    uint16_t      RESERVED6;                             /*!< Reserved, 0xFC */
    __IO uint8_t HCVR;                                   /*!< Host Controller Version register,            Address offset: 0xFE */
    uint8_t      RESERVED7;                              /*!< Reserved, 0xFF */
    __IO uint32_t VR0;                                   /*!< Vendor-defined Register 0,                   Address offset: 0x100 */
    __IO uint32_t VR1;                                   /*!< Vendor-defined Register 1,                   Address offset: 0x104 */
    __IO uint32_t VR2;                                   /*!< Vendor-defined Register 2,                   Address offset: 0x108 */
    __IO uint32_t VR3;                                   /*!< Vendor-defined Register 3,                   Address offset: 0x10C */
    __IO uint32_t VR4;                                   /*!< Vendor-defined Register 4,                   Address offset: 0x110 */
    __IO uint32_t VR5;                                   /*!< Vendor-defined Register 5,                   Address offset: 0x114 */
    __IO uint32_t VR6;                                   /*!< Vendor-defined Register 6,                   Address offset: 0x118 */
    __IO uint32_t VR7;                                   /*!< Vendor-defined Register 7,                   Address offset: 0x11C */
    __IO uint32_t VR8;                                   /*!< Vendor-defined Register 8,                   Address offset: 0x120 */
    __IO uint32_t VR9;                                   /*!< Vendor-defined Register 9,                   Address offset: 0x124 */
    uint32_t      RESERVED8[20];                         /*!< Reserved, 0x128 - 0x174 */
    __IO uint32_t HAR;                                   /*!< Hardware Attributes Register,                Address offset: 0x178 */
    uint32_t      RESERVED9[33];                         /*!< Reserved, 0x17C- 0x1FC */
    __IO uint32_t CQVR;                                  /*!< Command Queuing Version,                     Address offset: 0x200 */
    __IO uint32_t CQCAP;                                 /*!< Command Queuing Capabilities,                Address offset: 0x204 */
    __IO uint32_t CQCFGR;                                /*!< Command Queuing Configurarion,               Address offset: 0x208 */
    __IO uint32_t CQCR;                                  /*!< Command Queuing Control,                     Address offset: 0x20C */
    __IO uint32_t CQISR;                                 /*!< Command Queuing Interruot Status,            Address offset: 0x210 */
    __IO uint32_t CQISTER;                               /*!< Command Queuing Interrupt Status Enable,     Address offset: 0x214 */
    __IO uint32_t CQIER;                                 /*!< Command Queuing Interrupt Signal Enable,     Address offset: 0x218 */
    __IO uint32_t CQICOLR;                               /*!< Interrupt Coalescing,                        Address offset: 0x21C */
    __IO uint32_t CQTDLBAR;                              /*!< Command Queuing Task Descriptor List Base Address, Address offset: 0x220 */
    uint32_t      RESERVED10;                            /*!< Reserved, 0x224 */
    __IO uint32_t CQTDBR;                                /*!< Command Queuing Task Doorbell,               Address offset: 0x228 */
    __IO uint32_t CQTCNR;                                /*!< Task Completion Notification,                Address offset: 0x22C */
    __IO uint32_t CQDQSR;                                /*!< Device Queue Status,                         Address offset: 0x230 */
    __IO uint32_t CQDPTR;                                /*!< Device Pending Status,                       Address offset: 0x234 */
    __IO uint32_t CQTCR;                                 /*!< Task Clear,                                  Address offset: 0x238 */
    uint32_t      RESERVED11;                            /*!< Reserved, 0x23C */
    __IO uint32_t CQSSCFGR0;                             /*!< Send Status Configuration 1,                 Address offset: 0x240 */
    __IO uint32_t CQSSCFGR1;                             /*!< Send Status Configuration 2,                 Address offset: 0x244 */
    __IO uint32_t CQDCMDTRR;                             /*!< Command Response for Direct-Command Task,    Address offset: 0x248 */
    uint32_t      RESERVED12;                            /*!< Reserved, 0x24C */
    __IO uint32_t CQMERMR;                               /*!< Response Mode Error Mask,                    Address offset: 0x250 */
    __IO uint32_t CQTEIR;                                /*!< Task Error Information,                      Address offset: 0x254 */
    __IO uint32_t CQRIR;                                 /*!< Command Response Index,                      Address offset: 0x258 */
    __IO uint32_t CQRAR;                                 /*!< Command Response Argument,                   Address offset: 0x25C */
    __IO uint32_t CQRTASR;                               /*!< Command Queue Ready Task Arbiration Select,  Address offset: 0x260 */
} SDHC_TypeDef;

/* =========================================================================================================================== */
/* ================                                  SGMII                                                   ================ */
/* =========================================================================================================================== */
/**
  * @brief Serial Gigabit Media Independent Interface (SGMII)
  */
typedef struct {
    __IO uint32_t CR0;                                   /*!< SGMII control register 0, Address offset: 0x00 */
    __IO uint32_t CR1;                                   /*!< SGMII control register 1, Address offset: 0x04 */
    __IO uint32_t CR2;                                   /*!< SGMII control register 2, Address offset: 0x08 */
    __IO uint32_t CR3;                                   /*!< SGMII control register 3, Address offset: 0x0C */
    __IO uint32_t CR4;                                   /*!< SGMII control register 4, Address offset: 0x10 */
    __IO uint32_t SR0;                                   /*!< SGMII status register 0,  Address offset: 0x14 */
    __IO uint32_t SR1;                                   /*!< SGMII status register 1,  Address offset: 0x18 */
} SGMII_TypeDef;

/* =========================================================================================================================== */
/* ================                                  SSP                                                   ================ */
/* =========================================================================================================================== */
/**
  * @brief Synchronous Serial Peripheral (SSP)
  */
typedef struct {
    __IO uint32_t CR0;                                   /*!< SSP control register 0,             Address offset: 0x00 */
    __IO uint32_t CR1;                                   /*!< SSP control register 1,             Address offset: 0x04 */
    __IO uint32_t CR2;                                   /*!< SSP control register 2,             Address offset: 0x08 */
    __IO uint32_t SR;                                    /*!< SSP status register,                Address offset: 0x0C */
    __IO uint32_t ICR;                                   /*!< SSP interrupt control register,     Address offset: 0x10 */
    __IO uint32_t ISR;                                   /*!< SSP interrupt status register,      Address offset: 0x14 */
    __IO uint32_t DR;                                    /*!< SSP transmit/receive data register, Address offset: 0x18 */
    __IO uint32_t CR3;                                   /*!< SSP control register 3,             Address offset: 0x1C */
} SSP_TypeDef;

/* =========================================================================================================================== */
/* ================                                  SPI                                                      ================ */
/* =========================================================================================================================== */
/**
  * @brief Synchronous Serial Interface (SPI)
  */
typedef struct
{
    __IO uint32_t   CR0;                                 /*!< SPI Control Register 0,                        Address offset: 0x00 */
    __IO uint32_t   CR1;                                 /*!< SPI Control Register 1,                        Address offset: 0x04 */
    __IO uint32_t   ENR;                                 /*!< SPI Enable Register,                           Address offset: 0x08 */
    __IO uint32_t   MWCR;                                /*!< SPI Microwire Control Register,                Address offset: 0x0C */
    __IO uint32_t   SER;                                 /*!< SPI Slave Enable Register,                     Address offset: 0x10 */
    __IO uint32_t   CDR;                                 /*!< SPI Clock Divisor Register,                    Address offset: 0x14 */
    __IO uint32_t   TFTR;                                /*!< SPI TXFIFO Threshold Register,                 Address offset: 0x18 */
    __IO uint32_t   RFTR;                                /*!< SPI RXFIFO Threshold Register,                 Address offset: 0x1C */
    __IO uint32_t   TFDCR;                               /*!< SPI TXFIFO Data Count Register,                Address offset: 0x20 */
    __IO uint32_t   RFDCR;                               /*!< SPI RXFIFO Data Count Register,                Address offset: 0x24 */
    __IO uint32_t   SR;                                  /*!< SPI Status Register,                           Address offset: 0x28 */
    __IO uint32_t   IMR;                                 /*!< SPI Interrupt Mask Register,                   Address offset: 0x2C */
    __IO uint32_t   ISR;                                 /*!< SPI Interrupt Status Register,                 Address offset: 0x30 */
    __IO uint32_t   RISR;                                /*!< SPI Raw Interrupt Status Register,             Address offset: 0x34 */
    __IO uint32_t   TFOICR;                              /*!< SPI TXFIFO Overflow Interrupt Clear Register,  Address offset: 0x38 */
    __IO uint32_t   RFOICR;                              /*!< SPI RXFIFO Overflow Interrupt Clear Register,  Address offset: 0x3C */
    __IO uint32_t   RFUICR;                              /*!< SPI RXFIFO Underflow Interrupt Clear Register, Address offset: 0x40 */
    __IO uint32_t   MSTICR;                              /*!< SPI Multi-Master Interrupt Clear Register,     Address offset: 0x44 */
    __IO uint32_t   ICR;                                 /*!< SPI Interrupt Clear Register,                  Address offset: 0x48 */
    __IO uint32_t   DMACR;                               /*!< SPI DMA Control Register,                      Address offset: 0x4C */
    __IO uint32_t   DMATDTR;                             /*!< SPI DMA Transmit Data Threshold Register,      Address offset: 0x50 */
    __IO uint32_t   DMARDTR;                             /*!< SPI DMA Receive Data Threshold Register,       Address offset: 0x54 */
    uint32_t RESERVED0[2];                               /*!< Reserved, 0x58-0x5C */
    __IO uint32_t   DR;                                  /*!< SPI Data Register,                             Address offset: 0x60 */
    uint32_t RESERVED1[36];                              /*!< Reserved, 0x64-0xF0 */
    __IO uint32_t   MLCR;                                /*!< SPI Multi Line Control Register,               Address offset: 0xF4 */
} SPI_TypeDef;

typedef struct
{
    __IO uint32_t SSCR;   /*!< SPI ss control register, Address offset: 0x0 */
} SPI_Config_TypeDef;

/* =========================================================================================================================== */
/* ================                                  SYSCFG                                                   ================ */
/* =========================================================================================================================== */
/**
  * @brief System Configure (SYSCFG)
  */
typedef struct {
    __IO uint32_t ECR;                                   /*!< SYSCFG SRAM ECC Control Register,              Address offset: 0x10 */
    __I  uint32_t WEEAR;                                 /*!< SYSCFG Write ECC Error Address Register,       Address offset: 0x14 */
    __I  uint32_t WEEACNTR;                              /*!< SYSCFG Write ECC Error Address Count Register, Address offset: 0x18 */
    __I  uint32_t REEAR;                                 /*!< SYSCFG Read ECC Error Address Register,        Address offset: 0x1C */
    __I  uint32_t REEACNTR;                              /*!< SYSCFG Read ECC Error Address Count Register,  Address offset: 0x20 */
    uint32_t      RESERVED0[3];                          /*!< Reserved, 0x24-0x2C */
    __I  uint32_t AXICER0;                               /*!< SYSCFG AXI CRC Error Register 0,               Address offset: 0x30 */
    __I  uint32_t AXICER1;                               /*!< SYSCFG AXI CRC Error Register 1,               Address offset: 0x34 */
    __I  uint32_t AXICECNTR;                             /*!< SYSCFG AXI CRC Error Count Register,           Address offset: 0x38 */
    uint32_t      RESERVED1;                             /*!< Reserved, 0x3C */
    __I  uint32_t AHB0CER;                               /*!< SYSCFG AHB0 CRC Error Register,                Address offset: 0x40 */
    __I  uint32_t AHB0CECNTR;                            /*!< SYSCFG AHB0 CRC Error Count Register,          Address offset: 0x44 */
} SYSCFG_TypeDef;

/* =========================================================================================================================== */
/* ================                                  TIM                                                      ================ */
/* =========================================================================================================================== */
/**
  * @brief TIMER
  */
typedef struct
{
    __IO uint32_t ISR;                                   /*!< TIM status register,                                               Address offset: 0x00 */
    __IO uint32_t PRES;                                  /*!< TIM prescaler,                                                     Address offset: 0x04 */
    __IO uint32_t CR;                                    /*!< TIM control register,                                              Address offset: 0x08 */
    __IO uint32_t CNTB;                                  /*!< TIM auto-reload register or End value of pulse detection register, Address offset: 0x0C */
    __IO uint32_t CMPB;                                  /*!< TIM compare register,                                              Address offset: 0x10 */
    __IO uint32_t CNTO;                                  /*!< TIM counter register(only read reg),                               Address offset: 0x14 */
    __IO uint32_t FD;                                    /*!< TIM frequency detection count reg,                                 Address offset: 0x18 */
    __IO uint32_t DCD;                                   /*!< TIM duty cycle detection count reg,                                Address offset: 0x1C */
} TIM_TypeDef;

/* =========================================================================================================================== */
/* ================                                  UART                                                     ================ */
/* =========================================================================================================================== */
/**
  * @brief Universal Asynchronous Receiver Transmitter (UART)
  */
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

/* =========================================================================================================================== */
/* ================                                  WDG                                                     ================ */
/* =========================================================================================================================== */
/**
  * @brief Watch DOG (WDG)
  */
typedef struct
{
	__I  uint32_t CNT;                                   /*!< Watch Dog Count Register,                   Address offset: 0x00 */
	__IO  uint32_t RSR;                                  /*!< Watch Dog Reset Register,                   Address offset: 0x04 */
	__IO  uint32_t ISR;                                  /*!< Watch Dog Interrupt Status Register,        Address offset: 0x08 */
    __IO uint32_t LOAD;                                  /*!< Watch Dog Load Register,                    Address offset: 0x0C */
    __IO uint32_t CR;                                    /*!< Watch Dog Control Register,                 Address offset: 0x10 */
    __IO uint32_t ICLR;                                  /*!< Watch Dog Interrupt Clear Register,         Address offset: 0x14 */
    uint32_t RESERVED;                                   /*!< Reserved, Address offset: 0x18 */
    __IO uint32_t EICR;                                  /*!< Watch Dog Early Interrupt Control Register, Address offset: 0x1C */
    __IO uint32_t EICLR;                                 /*!< Watch Dog Early Interrupt Clear Register,   Address offset: 0x20 */
    __IO uint32_t PRES;                                  /*!< Watch Dog Pre-Scaler Resiter,               Address offset: 0x24 */
    __IO uint32_t EIVR;                                  /*!< Watch Dog Early Interrupt Value Register,   Address Offset: 0x28 */
} WDG_TypeDef;
/*@}*/ /* end of group T690_Peripherals */

/* =========================================  End of section using anonymous unions  ========================================= */
#if defined (__GNUC__)
  /* anonymous unions are enabled by default */
#else
  #warning Not supported compiler type
#endif

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */
/** @addtogroup Device_Peripheral_peripheralAddr
  * @{
  */
/*!< Peripheral base address */
#define AXI0_BASE                             ((uint32_t)0x00000000)
#define AHB_BASE                              ((uint32_t)0x04000000)
#define APB0_BASE                             ((uint32_t)0x06000000)
#define APB1_BASE                             ((uint32_t)0x08000000)
#define APB2_BASE                             ((uint32_t)0x09000000)
#define APBLP_BASE                            ((uint32_t)0x00000000)

/* Memory base address */
#define ROM_BASE                              (AXI0_BASE + 0x00000000)
#define SRAM_BASE                             (AXI0_BASE + 0x00800000)
#ifdef FW_LPCORE
#define RETRAM_BASE                           (APBLP_BASE + 0x00000000)
#else
#define RETRAM_BASE                           (APB1_BASE + 0x00000000)
#endif
#define UX608LDLM_BASE                        (AXI0_BASE + 0x01000000)
#define FMC0XIP_BASE                          (AXI0_BASE + 0x20000000)
#define FMC1XIP_BASE                          (AXI0_BASE + 0x30000000)
#define DDR_BASE                              ((uint32_t)0x80000000)

/*!< AXI0 peripherals */
#define HSMSYM0_BASE                          (AXI0_BASE + 0x02100000)
#define HSMSYM1_BASE                          (AXI0_BASE + 0x02101000)
#define HSMSYM2_BASE                          (AXI0_BASE + 0x02102000)
#define HSMPK0_BASE                           (AXI0_BASE + 0x02300000)
#define HSMPK1_BASE                           (AXI0_BASE + 0x02301000)
#define HSMPK2_BASE                           (AXI0_BASE + 0x02302000)
#define HSMCTRL0_BASE                         (AXI0_BASE + 0x02200000)
#define HSMCTRL1_BASE                         (AXI0_BASE + 0x02201000)
#define HSMCTRL2_BASE                         (AXI0_BASE + 0x02202000)
#define GMAC0_BASE                            (AXI0_BASE + 0x02400000)
#define GMAC1_BASE                            (AXI0_BASE + 0x02500000)
#define PCIE_BASE                             (AXI0_BASE + 0x02800000)
#define USB3_BASE                             (AXI0_BASE + 0x02900000)
#define CPUIMC_BASE                           (AXI0_BASE + 0x02A00400)
#define CPUIPC_BASE                           (AXI0_BASE + 0x02A00460)

/*!< AHB peripherals */
#define FMC0CMD_BASE                          (AHB_BASE + 0x00100000)
#define FMC1CMD_BASE                          (AHB_BASE + 0x00200000)
#define USB2_BASE                             (AHB_BASE + 0x00400000)
#define SDHC0_BASE                            (AHB_BASE + 0x00800000)
#define SDHC1_BASE                            (AHB_BASE + 0x00900000)
#define SDHC2_BASE                            (AHB_BASE + 0x00A00000)
#define SDDC_BASE                             (AHB_BASE + 0x00B00000)
#define MAC0_BASE                             (AHB_BASE + 0x01000000)
#define MAC1_BASE                             (AHB_BASE + 0x01100000)

/*!< APB0 peripherals */
#define RCC_BASE                              (APB0_BASE + 0x00000000)
#define PWRPCR_BASE                           (APB0_BASE + 0x00000190)
#define SYSCFG_BASE                           (APB0_BASE + 0x000001A0)
#define CPUAT_BASE                            (APB0_BASE + 0x00001010)
#define USB2CFG_BASE                          (APB0_BASE + 0x00001040)
#define USB3CFG_BASE                          (APB0_BASE + 0x00001050)
#define SDCCFG_BASE                           (APB0_BASE + 0x00001068)
#define FMC1DC_BASE                           (APB0_BASE + 0x00001094)
#define DDRCCFG_BASE                          (APB0_BASE + 0x000010A0)
#define FMC0IC_BASE                           (APB0_BASE + 0x000010F0)
#define GMAC1DL_BASE                          (APB0_BASE + 0x000010F8)
#define SPICFG_BASE                           (APB0_BASE + 0x00001100)
#define GPHY_BASE                             (APB0_BASE + 0x00001110)
#define GMAC0PHY_BASE                         (APB0_BASE + 0x00001118)
#define MACWOL_BASE                           (APB0_BASE + 0x0000111C)
#define GPIOATTR_BASE                         (APB0_BASE + 0x00001120)
#define PCIEPHY_BASE                          (APB0_BASE + 0x00001200)
#define SGMII_BASE                            (APB0_BASE + 0x00001270)
#define DMA0_BASE                             (APB0_BASE + 0x00100000)
#define DMA0_Stream0_BASE                     (APB0_BASE + 0x00100100)
#define DMA0_Stream1_BASE                     (APB0_BASE + 0x00100120)
#define DMA0_Stream2_BASE                     (APB0_BASE + 0x00100140)
#define DMA0_Stream3_BASE                     (APB0_BASE + 0x00100160)
#define DMA0_Stream4_BASE                     (APB0_BASE + 0x00100180)
#define DMA0_Stream5_BASE                     (APB0_BASE + 0x001001A0)
#define DMA0_Stream6_BASE                     (APB0_BASE + 0x001001C0)
#define DMA0_Stream7_BASE                     (APB0_BASE + 0x001001E0)
#define DMA1_BASE                             (APB0_BASE + 0x00200000)
#define DMA1_Stream0_BASE                     (APB0_BASE + 0x00200100)
#define DMA1_Stream1_BASE                     (APB0_BASE + 0x00200120)
#define DMA1_Stream2_BASE                     (APB0_BASE + 0x00200140)
#define DMA1_Stream3_BASE                     (APB0_BASE + 0x00200160)
#define DMA1_Stream4_BASE                     (APB0_BASE + 0x00200180)
#define DMA1_Stream5_BASE                     (APB0_BASE + 0x002001A0)
#define DMA1_Stream6_BASE                     (APB0_BASE + 0x002001C0)
#define DMA1_Stream7_BASE                     (APB0_BASE + 0x002001E0)
#define WDG0_BASE                             (APB0_BASE + 0x00300000)
#define WDG1_BASE                             (APB0_BASE + 0x00400000)
#define TIM0_BASE                             (APB0_BASE + 0x00300600)
#define TIM1_BASE                             (APB0_BASE + 0x00300620)
#define TIM2_BASE                             (APB0_BASE + 0x00300640)
#define TIM3_BASE                             (APB0_BASE + 0x00300660)
#define TIM4_BASE                             (APB0_BASE + 0x00300680)
#define TIM5_BASE                             (APB0_BASE + 0x003006A0)
#define TIM6_BASE                             (APB0_BASE + 0x003006C0)
#define TIM7_BASE                             (APB0_BASE + 0x003006E0)
#define TIM8_BASE                             (APB0_BASE + 0x00400600)
#define TIM9_BASE                             (APB0_BASE + 0x00400620)
#define TIM10_BASE                            (APB0_BASE + 0x00400640)
#define TIM11_BASE                            (APB0_BASE + 0x00400660)
#define TIM12_BASE                            (APB0_BASE + 0x00400680)
#define TIM13_BASE                            (APB0_BASE + 0x004006A0)
#define TIM14_BASE                            (APB0_BASE + 0x004006C0)
#define TIM15_BASE                            (APB0_BASE + 0x004006E0)
#define GPIOA_BASE                            (APB0_BASE + 0x00500000)
#define GPIOB_BASE                            (APB0_BASE + 0x00520000)
#define GPIOC_BASE                            (APB0_BASE + 0x00540000)
#define USB3PHY_BASE                          (APB0_BASE + 0x00600000)
#define I2C1_BASE                             (APB0_BASE + 0x00700000)
#define I2C2_BASE                             (APB0_BASE + 0x00800000)
#define LTDC_BASE                             (APB0_BASE + 0x00900000)
#define SPI0_BASE                             (APB0_BASE + 0x00A00000)
#define SPI1_BASE                             (APB0_BASE + 0x00B00000)
#define SSP0_BASE                             (APB0_BASE + 0x00C00000)
#define SSP1_BASE                             (APB0_BASE + 0x00D00000)
#define CANA1_BASE                            (APB0_BASE + 0x00E00000)
#define CANA2_BASE                            (APB0_BASE + 0x00F00000)
#define CANA3_BASE                            (APB0_BASE + 0x01000000)
#define CANB0_BASE                            (APB0_BASE + 0x01100000)
#define CANB1_BASE                            (APB0_BASE + 0x01200000)
#define CANB2_BASE                            (APB0_BASE + 0x01300000)
#define CANB3_BASE                            (APB0_BASE + 0x01400000)
#define UART1_BASE                            (APB0_BASE + 0x01500000)
#define UART2_BASE                            (APB0_BASE + 0x01600000)
#define UART3_BASE                            (APB0_BASE + 0x01700000)
#define UART4_BASE                            (APB0_BASE + 0x01800000)
#define UART5_BASE                            (APB0_BASE + 0x01900000)
#define UART6_BASE                            (APB0_BASE + 0x01A00000)
#define UART7_BASE                            (APB0_BASE + 0x01B00000)
#define SCI0_BASE                             (APB0_BASE + 0x01C00000)
#define SCI1_BASE                             (APB0_BASE + 0x01D00000)
#define ADC0_BASE                             (APB0_BASE + 0x01E00000)
#define ADC1_BASE                             (APB0_BASE + 0x01E00060)
#define DAC_BASE                              (APB0_BASE + 0x01F00000)

/*!< LP peripherals */
#ifdef FW_LPCORE
#define LPRCCL_BASE                           (APBLP_BASE + 0x00002000)
#define LPSYSCFGL_BASE                        (APBLP_BASE + 0x00002000)
#define GPIOA50ATTR_BASE                      (APBLP_BASE + 0x00002070)
#define PWRPMU_BASE                           (APBLP_BASE + 0x00002400)
#define RTC_BASE                              (APBLP_BASE + 0x00002800)
#define GPIOD_BASE                            (APBLP_BASE + 0x00002C00)
#define I2C0_BASE                             (APBLP_BASE + 0x00003000)
#define CANA0_BASE                            (APBLP_BASE + 0x00008000)
#define UART0_BASE                            (APBLP_BASE + 0x00010000)
#else
#define LPRCCL_BASE                           (APB1_BASE + 0x00100000)
#define LPSYSCFGL_BASE                        (APB1_BASE + 0x00100000)
#define GPIOA50ATTR_BASE                      (APB1_BASE + 0x00100070)
#define PWRPMU_BASE                           (APB1_BASE + 0x00200000)
#define RTC_BASE                              (APB1_BASE + 0x00300000)
#define GPIOD_BASE                            (APB1_BASE + 0x00400000)
#define I2C0_BASE                             (APB1_BASE + 0x00500000)
#define CANA0_BASE                            (APB1_BASE + 0x00600000)
#define UART0_BASE                            (APB1_BASE + 0x00700000)
#endif

/*!< APB2 peripherals */
#define DDRC_BASE                             (APB2_BASE + 0x00400000)
#define H2XL_BASE                             (APB2_BASE + 0x00A00000)
#define H2XH_BASE                             (APB2_BASE + 0x00B00000)
/** @} */ /* End of group Device_Peripheral_peripheralAddr */

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

/* TODO: add here your device peripherals pointer definitions
         following is an example for uart0 */
/** @addtogroup Device_Peripheral_declaration
  * @{
  */
#define ADC0                                ((ADC_TypeDef *) ADC0_BASE)
#define ADC1                                ((ADC_TypeDef *) ADC1_BASE)
#define CANA0                               ((CANA_TypeDef *) CANA0_BASE)
#define CANA1                               ((CANA_TypeDef *) CANA1_BASE)
#define CANA2                               ((CANA_TypeDef *) CANA2_BASE)
#define CANA3                               ((CANA_TypeDef *) CANA3_BASE)
#define CANB0                               ((CANB_TypeDef *) CANB0_BASE)
#define CANB1                               ((CANB_TypeDef *) CANB1_BASE)
#define CANB2                               ((CANB_TypeDef *) CANB2_BASE)
#define CANB3                               ((CANB_TypeDef *) CANB3_BASE)
#define CPUAT                               ((CPUAT_TypeDef *) CPUAT_BASE)
#define CPUIMC                              ((CPUIMC_TypeDef *) CPUIMC_BASE)
#define CPUIPC                              ((CPUIPC_TypeDef *) CPUIPC_BASE)
#define DAC                                 ((DAC_TypeDef *) DAC_BASE)
#define DDRC                                ((DDRC_TypeDef *) DDRC_BASE)
#define DDRC_CFG                            ((DDRC_Config_TypeDef *) DDRCCFG_BASE)
#define DMA0                                ((DMA_TypeDef *) DMA0_BASE)
#define DMA0_Stream0                        ((DMA_Stream_TypeDef *) DMA0_Stream0_BASE)
#define DMA0_Stream1                        ((DMA_Stream_TypeDef *) DMA0_Stream1_BASE)
#define DMA0_Stream2                        ((DMA_Stream_TypeDef *) DMA0_Stream2_BASE)
#define DMA0_Stream3                        ((DMA_Stream_TypeDef *) DMA0_Stream3_BASE)
#define DMA0_Stream4                        ((DMA_Stream_TypeDef *) DMA0_Stream4_BASE)
#define DMA0_Stream5                        ((DMA_Stream_TypeDef *) DMA0_Stream5_BASE)
#define DMA0_Stream6                        ((DMA_Stream_TypeDef *) DMA0_Stream6_BASE)
#define DMA0_Stream7                        ((DMA_Stream_TypeDef *) DMA0_Stream7_BASE)
#define DMA1                                ((DMA_TypeDef *) DMA1_BASE)
#define DMA1_Stream0                        ((DMA_Stream_TypeDef *) DMA1_Stream0_BASE)
#define DMA1_Stream1                        ((DMA_Stream_TypeDef *) DMA1_Stream1_BASE)
#define DMA1_Stream2                        ((DMA_Stream_TypeDef *) DMA1_Stream2_BASE)
#define DMA1_Stream3                        ((DMA_Stream_TypeDef *) DMA1_Stream3_BASE)
#define DMA1_Stream4                        ((DMA_Stream_TypeDef *) DMA1_Stream4_BASE)
#define DMA1_Stream5                        ((DMA_Stream_TypeDef *) DMA1_Stream5_BASE)
#define DMA1_Stream6                        ((DMA_Stream_TypeDef *) DMA1_Stream6_BASE)
#define DMA1_Stream7                        ((DMA_Stream_TypeDef *) DMA1_Stream7_BASE)
#define FMC0                                ((FMC_TypeDef *) FMC0CMD_BASE)
#define FMC0_IC                             ((FMC0_IOControl_TypeDef *) FMC0IC_BASE)
#define FMC1                                ((FMC_TypeDef *) FMC1CMD_BASE)
#define FMC1_DC                             ((FMC1_DllControl_TypeDef *) FMC1DC_BASE)
#define GPHY                                ((GPHY_TypeDef *) GPHY_BASE)
#define GMAC0                               ((GMAC_TypeDef *) GMAC0_BASE)
#define GMAC1                               ((GMAC_TypeDef *) GMAC1_BASE)
#define GPIOA                               ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB                               ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC                               ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD                               ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIO_ATTRIBUTE                      ((GPIO_Attribute_TypeDef *) GPIOATTR_BASE)
#define GPIOA50_ATTRIBUTE                   ((GPIOA50_Attribute_TypeDef *) GPIOA50ATTR_BASE)
#define HSMSYM0                             ((HSM_TypeDef *) HSMSYM0_BASE)
#define HSMSYM1                             ((HSM_TypeDef *) HSMSYM1_BASE)
#define HSMSYM2                             ((HSM_TypeDef *) HSMSYM2_BASE)
#define HSMPK0                              ((HSM_TypeDef *) HSMPK0_BASE)
#define HSMPK1                              ((HSM_TypeDef *) HSMPK1_BASE)
#define HSMPK2                              ((HSM_TypeDef *) HSMPK2_BASE)
#define HSMCTRL0                            ((HSM_TypeDef *) HSMCTRL0_BASE)
#define HSMCTRL1                            ((HSM_TypeDef *) HSMCTRL1_BASE)
#define HSMCTRL2                            ((HSM_TypeDef *) HSMCTRL2_BASE)
#define I2C0                                ((I2C_TypeDef *) I2C0_BASE)
#define I2C1                                ((I2C_TypeDef *) I2C1_BASE)
#define I2C2                                ((I2C_TypeDef *) I2C2_BASE)
#define LTDC                                ((LTDC_TypeDef *) LTDC_BASE)
#define MAC0                                ((MAC_TypeDef *) MAC0_BASE)
#define MAC1                                ((MAC_TypeDef *) MAC1_BASE)
#define PWRPCR                              ((PWRPCR_TypeDef *) PWRPCR_BASE)
#define PWRPMU                              ((PWRPMU_TypeDef *) PWRPMU_BASE)
#define RCC                                 ((RCC_TypeDef *) RCC_BASE)
#define SCI0                                ((SCI_TypeDef *) SCI0_BASE)
#define SCI1                                ((SCI_TypeDef *) SCI1_BASE)
#define SDDC                                ((SDDC_TypeDef *) SDDC_BASE)
#define SDHC0                               ((SDHC_TypeDef *) SDHC0_BASE)
#define SDHC1                               ((SDHC_TypeDef *) SDHC1_BASE)
#define SDHC2                               ((SDHC_TypeDef *) SDHC2_BASE)
#define SDCCFG                              ((SDC_Config_TypeDef *) SDCCFG_BASE)
#define SSP0                                ((SSP_TypeDef *) SSP0_BASE)
#define SSP1                                ((SSP_TypeDef *) SSP1_BASE)
#define SPI0                                ((SPI_TypeDef *) SPI0_BASE)
#define SPI1                                ((SPI_TypeDef *) SPI1_BASE)
#define SPICFG                              ((SPI_Config_TypeDef *) SPICFG_BASE)
#define SYSCFG                              ((SYSCFG_TypeDef *) SYSCFG_BASE)
#define TIM0                                ((TIM_TypeDef *) TIM0_BASE)
#define TIM1                                ((TIM_TypeDef *) TIM1_BASE)
#define TIM2                                ((TIM_TypeDef *) TIM2_BASE)
#define TIM3                                ((TIM_TypeDef *) TIM3_BASE)
#define TIM4                                ((TIM_TypeDef *) TIM4_BASE)
#define TIM5                                ((TIM_TypeDef *) TIM5_BASE)
#define TIM6                                ((TIM_TypeDef *) TIM6_BASE)
#define TIM7                                ((TIM_TypeDef *) TIM7_BASE)
#define TIM8                                ((TIM_TypeDef *) TIM8_BASE)
#define TIM9                                ((TIM_TypeDef *) TIM9_BASE)
#define TIM10                               ((TIM_TypeDef *) TIM10_BASE)
#define TIM11                               ((TIM_TypeDef *) TIM11_BASE)
#define TIM12                               ((TIM_TypeDef *) TIM12_BASE)
#define TIM13                               ((TIM_TypeDef *) TIM13_BASE)
#define TIM14                               ((TIM_TypeDef *) TIM14_BASE)
#define TIM15                               ((TIM_TypeDef *) TIM15_BASE)
#define UART0                               ((UART_TypeDef *) UART0_BASE)
#define UART1                               ((UART_TypeDef *) UART1_BASE)
#define UART2                               ((UART_TypeDef *) UART2_BASE)
#define UART3                               ((UART_TypeDef *) UART3_BASE)
#define UART4                               ((UART_TypeDef *) UART4_BASE)
#define UART5                               ((UART_TypeDef *) UART5_BASE)
#define UART6                               ((UART_TypeDef *) UART6_BASE)
#define UART7                               ((UART_TypeDef *) UART7_BASE)
#define LPRCCL                              ((LPRCCL_TypeDef *) LPRCCL_BASE)
#define LPSYSCFGL                           ((LPSYSCFGL_TypeDef *) LPSYSCFGL_BASE)
#define RTC                                 ((RTC_TypeDef *) RTC_BASE)
#define SGMII                               ((SGMII_TypeDef *) SGMII_BASE)
#define WDG0                                ((WDG_TypeDef *) WDG0_BASE)
#define WDG1                                ((WDG_TypeDef *) WDG1_BASE)
#define MAC0                                ((MAC_TypeDef *) MAC0_BASE)
#define MAC1                                ((MAC_TypeDef *) MAC1_BASE)
/** @} */ /* End of group Device_Peripheral_declaration */

/** @addtogroup Peripheral_Registers_Bits_Definition
 * @{
 */
/* =========================================================================================================================== */
/* ================                            Peripheral Registers Bits Definition                          ================= */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                            Analog to Digital Converter                                   ================= */
/* =========================================================================================================================== */

/* ====================  Bit definition for ADC_SR register  ====================== */
#define ADC_SR_GEOC                         ((uint16_t)0x0001)            /*!< Geneal channel end of conversion */
#define ADC_SR_PEOC                         ((uint16_t)0x0002)            /*!< Prior channel end of conversion */
#define ADC_SR_WDLT                         ((uint16_t)0x0004)            /*!< Analog watchdog low threshold alarm flag  */
#define ADC_SR_WDHT                         ((uint16_t)0x0008)            /*!< Analog watchdog high threshold alarm flag */
#define ADC_SR_GFOF                         ((uint16_t)0x0010)            /*!< general channel Fifo Overrun flag */
#define ADC_SR_GFEMP                        ((uint16_t)0x0020)            /*!< general channel Fifo Empty flag */
#define ADC_SR_GFCNT                        ((uint16_t)0x03C0)            /*!< general channel Fifo data count */
#define ADC_SR_GFCNT_0                      ((uint16_t)0x0040)            /*!< Bit 0 */
#define ADC_SR_GFCNT_1                      ((uint16_t)0x0080)            /*!< Bit 1 */
#define ADC_SR_GFCNT_2                      ((uint16_t)0x0100)            /*!< Bit 2 */
#define ADC_SR_GFCNT_3                      ((uint16_t)0x0200)            /*!< Bit 3 */
#define ADC_SR_PFOF                         ((uint16_t)0x0400)            /*!< Prior channel Fifo verrun flag */
#define ADC_SR_PFEMP                        ((uint16_t)0x0800)            /*!< Prior channel Fifo Empty flag */
#define ADC_SR_PFCNT                        ((uint16_t)0x7000)            /*!< Prior channel Fifo data count */
#define ADC_SR_PFCNT_0                      ((uint16_t)0x1000)            /*!< Bit 0 */
#define ADC_SR_PFCNT_1                      ((uint16_t)0x2000)            /*!< Bit 1 */
#define ADC_SR_PFCNT_2                      ((uint16_t)0x4000)            /*!< Bit 2 */

/* ====================  Bit definition for ADC_CR1 register  ====================== */
#define ADC_CR_ADPD                         ((uint32_t)0x00000001)        /*!< A/D Converter ON / OFF */
#define ADC_CR_CONT                         ((uint32_t)0x00000002)        /*!< Continuous Conversion */
#define ADC_CR_DMAEN                        ((uint32_t)0x00000004)        /*!< Direct Memory access mode */
#define ADC_CR_DALIGN                       ((uint32_t)0x00000008)        /*!< Data Alignment */
#define ADC_CR_PEXTSEL                      ((uint32_t)0x000000F0)        /*!< JEXTSEL[3:0] bits (External event select for injected group) */
#define ADC_CR_PEXTSEL_0                    ((uint32_t)0x00000010)        /*!< Bit 0 */
#define ADC_CR_PEXTSEL_1                    ((uint32_t)0x00000020)        /*!< Bit 1 */
#define ADC_CR_PEXTSEL_2                    ((uint32_t)0x00000040)        /*!< Bit 2 */
#define ADC_CR_PEXTSEL_3                    ((uint32_t)0x00000080)        /*!< Bit 3 */
#define ADC_CR_PEXTEN                       ((uint32_t)0x00000300)        /*!< JEXTEN[1:0] bits (External Trigger Conversion mode for injected channelsp) */
#define ADC_CR_PEXTEN_0                     ((uint32_t)0x00000100)        /*!< Bit 0 */
#define ADC_CR_PEXTEN_1                     ((uint32_t)0x00000200)        /*!< Bit 1 */
#define ADC_CR_PSWSTART                     ((uint32_t)0x00000400)        /*!< Start Conversion of injected channels */
#define ADC_CR_GEXTSEL                      ((uint32_t)0x0000F000)        /*!< EXTSEL[3:0] bits (External Event Select for regular group) */
#define ADC_CR_GEXTSEL_0                    ((uint32_t)0x00001000)        /*!< Bit 0 */
#define ADC_CR_GEXTSEL_1                    ((uint32_t)0x00002000)        /*!< Bit 1 */
#define ADC_CR_GEXTSEL_2                    ((uint32_t)0x00004000)        /*!< Bit 2 */
#define ADC_CR_GEXTSEL_3                    ((uint32_t)0x00008000)        /*!< Bit 3 */
#define ADC_CR_GEXTEN                       ((uint32_t)0x00030000)        /*!< EXTEN[1:0] bits (External Trigger Conversion mode for regular channelsp) */
#define ADC_CR_GEXTEN_0                     ((uint32_t)0x00010000)        /*!< Bit 0 */
#define ADC_CR_GEXTEN_1                     ((uint32_t)0x00020000)        /*!< Bit 1 */
#define ADC_CR_GSWSTART                     ((uint32_t)0x00040000)        /*!< Start Conversion of regular channels */
#define ADC_CR_GEOCIE                       ((uint32_t)0x01000000)        /*!< Interrupt enable for EOC */
#define ADC_CR_WDGIE                        ((uint32_t)0x02000000)        /*!< AAnalog Watchdog interrupt enable */
#define ADC_CR_PEOCIE                       ((uint32_t)0x04000000)        /*!< Interrupt enable for injected channels */
#define ADC_CR_FOFIE                        ((uint32_t)0x08000000)        /*!< overrun interrupt enable */
#define ADC_CR_SCAN                         ((uint32_t)0x10000000)        /*!< Scan mode */
#define ADC_CR_SW                           ((uint32_t)0x20000000)        /*!< Software reset */

/* ====================  Bit definition for ADC_AWD register  ====================== */
#define ADC_WDG_WDGLT                       ((uint32_t)0x00000FFF)        /*!<Analog watchdog low threshold */
#define ADC_WDG_WDGHT                       ((uint32_t)0x00FFF000)        /*!<Analog watchdog high threshold */
#define ADC_WDG_WDGCH                       ((uint32_t)0x0F000000)        /*!< AWDCH[4:0] bits (Analog watchdog channel select bits) */
#define ADC_WDG_WDGCH_0                     ((uint32_t)0x01000000)        /*!< Bit 0 */
#define ADC_WDG_WDGCH_1                     ((uint32_t)0x02000000)        /*!< Bit 1 */
#define ADC_WDG_WDGCH_2                     ((uint32_t)0x04000000)        /*!< Bit 2 */
#define ADC_WDG_WDGCH_3                     ((uint32_t)0x08000000)        /*!< Bit 3 */
#define ADC_WDG_WDGGEN                      ((uint32_t)0x10000000)        /*!< Analog watchdog enable on regular channels */
#define ADC_WDG_WDGPEN                      ((uint32_t)0x20000000)        /*!< Analog watchdog enable on injected channels */
#define ADC_WDG_WDGALL                      ((uint32_t)0x40000000)        /*!< Enable the watchdog on a single channel or group channels in scan mode */

/* ====================  Bit definition for ADC_Calibration register  ====================== */
#define ADC_CALIB_EN                        ((uint16_t)0x0001)            /*!< Calibration enable */
#define ADC_CALIB_OUT                       ((uint16_t)0x0002)            /*!< Calibration signal output */
#define ADC_CALIB_XBVOS                     ((uint16_t)0x01FC)            /*!< XBVOS config */

/* =========================================================================================================================== */
/* ================                            Controller Area Network  A                                    ================= */
/* =========================================================================================================================== */
/* ====================  Bit definition for CANA_SRR register  ====================== */
#define CANA_SRR_SRST                       ((uint32_t)0x00000001)        /*!< Reset Value */
#define CANA_SRR_CEN                        ((uint32_t)0x00000002)        /*!< CAN ENABLE */

/* ====================  Bit definition for CANA_SR register  ====================== */
#define CANA_SR_CONFIG                      ((uint32_t)0x00000001)        /*!< Configuration mode */
#define CANA_SR_SLEEP                       ((uint32_t)0x00000004)        /*!< Sleep mode */

/* ====================  Bit definition for CANA_ESR register  ====================== */
#define CANA_ESR_REC                        ((uint32_t)0x0000FF00)        /*!< Receive Error Count */
#define CANA_ESR_TEC                        ((uint32_t)0x000000FF)        /*!< Transmit Error Count */

/* ====================  Bit definition for CANA_RB-ID register  ====================== */
#define CANA_IDR_ID1                        ((uint32_t)0xFFE00000)        /*!< Standard msg identifier */
#define CANA_IDR_SRR                        ((uint32_t)0x00100000)        /*!< Substitute remote TXreq */
#define CANA_IDR_IDE                        ((uint32_t)0x00080000)        /*!< Identifier extension */
#define CANA_IDR_ID2                        ((uint32_t)0x0007FFFE)        /*!< Extended message ident */
#define CANA_IDR_RTR                        ((uint32_t)0x00000001)        /*!< Remote TX request */

/* ====================  Bit definition for CANA_DLC register  ====================== */
#define CANA_DLCR_DLC                       ((uint32_t)0xF0000000)        /*!< Data length code */
#define CANA_DLCR_EDL                       ((uint32_t)0x08000000)        /*!< EDL Mask in DLC */
#define CANA_DLCR_BRS                       ((uint32_t)0x04000000)        /*!< BRS Mask in DLC */

/* ====================  Bit definition for CANA_RFSR register  ====================== */
#define CANA_RFSR_FL                        ((uint32_t)0x00003F00)        /*!< RX Fill Level */
#define CANA_RFSR_IRI                       ((uint32_t)0x00000080)        /*!< RX Increment Read Index */
#define CANA_RFSR_RI                        ((uint32_t)0x0000001F)        /*!< RX Read Index */

/* ====================  Bit definition for CANA_IER register  ====================== */
#define CANA_IER_EARBLOST                   ((uint32_t)0x00000001)        /*!< Arbitration lost interruption */
#define CANA_IER_ETXOK                      ((uint32_t)0x00000002)        /*!< Transmission successful */
#define CANA_IER_ERXOK                      ((uint32_t)0x00000010)        /*!< New Message Received */
#define CANA_IER_ERFXOFLW                   ((uint32_t)0x00000040)        /*!< RX FIFO-0 Overflow */
#define CANA_IER_EERROR                     ((uint32_t)0x00000100)        /*!< Error Interrupt Enable */
#define CANA_IER_EBSOFF                     ((uint32_t)0x00000200)        /*!< Bus-Off Interrupt Enable */
#define CANA_IER_ESLP                       ((uint32_t)0x00000400)        /*!< Sleep Interrupt Enable */
#define CANA_IER_EWKUP                      ((uint32_t)0x00000800)        /*!< Wake-Up Interrupt Enable */
#define CANA_IER_ERXFWMFLL                  ((uint32_t)0x00001000)        /*!< RX FIFO-0 Watermark Full Interrupt Enable */
#define CANA_IER_ETXRRS                     ((uint32_t)0x00002000)        /*!< TX Buffer Ready Request Served */

/* ====================  Bit definition for CANA_ISR register  ====================== */
#define CANA_ISR_ARBLOST                    ((uint32_t)0x00000001)        /*!< Arbitration Lost Interrupt */
#define CANA_ISR_TXOK                       ((uint32_t)0x00000002)        /*!< Transmission Successful Interrupt */
#define CANA_ISR_RXOK                       ((uint32_t)0x00000010)        /*!< New Message Received Interrupt */
#define CANA_ISR_RFXOFLW                    ((uint32_t)0x00000040)        /*!< RX FIFO-0 Overflow Interrupt */
#define CANA_ISR_ERROR                      ((uint32_t)0x00000100)        /*!< Error Interrupt */
#define CANA_ISR_BSOFF                      ((uint32_t)0x00000200)        /*!< Bus-Off Interrupt */
#define CANA_ISR_SLP                        ((uint32_t)0x00000400)        /*!< Sleep Interrupt */
#define CANA_ISR_WKUP                       ((uint32_t)0x00000800)        /*!< Wake-Up Interrupt */
#define CANA_ISR_RXFWMFLL                   ((uint32_t)0x00001000)        /*!< RX FIFO-0 Watermark Full Interrupt */
#define CANA_ISR_ETXRRS                     ((uint32_t)0x00002000)        /*!< TX Buffer Ready Request Served */

/* ====================  Bit definition for CANA_MSR register  ====================== */
#define CANA_MSR_DAR                        ((uint32_t)0x00000010)        /*!< Disable Auto-Retransmission */

/* ====================  Bit definition for CANA_AFMR register  ====================== */
#define CANA_AFMR_AMSRR                     ((uint32_t)0x00100000)        /*!< Substitute Remote Transmission Request Mask */
#define CANA_AFMR_AMIDE                     ((uint32_t)0x00080000)        /*!< Identif ier Extension  Mask */
#define CANA_AFMR_AMRTR                     ((uint32_t)0x00000001)        /*!< Remote Transmission Request  Mask */

/* ====================  Bit definition for CANA_AFIR register  ====================== */
#define CANA_AFIR_AISRR                     ((uint32_t)0x00100000)        /*!< Substitute Remote Transmission Request */
#define CANA_AFIR_AIIDE                     ((uint32_t)0x00080000)        /*!< Identif ier Extension */
#define CANA_AFIR_AIRTR                     ((uint32_t)0x00000001)        /*!< Remote Transmission Request */

/* =========================================================================================================================== */
/* ================                            Controller Area Network  B                                    ================= */
/* =========================================================================================================================== */
/* ====================  Bit definition for CANB_CR register  ====================== */
#define CANB_CR_RR                          ((uint32_t)0x40000000)        /*!< Soft Reset the CAN core */
#define CANB_CR_OMR                         ((uint32_t)0x07000000)        /*!< Operation Mode Request */
#define CANB_CR_RT                          ((uint32_t)0x18000000)        /*!< Retransmission Times */
#define CANB_CR_WIE                         ((uint32_t)0x00008000)        /*!< Wake-up Interrupt Enable */
#define CANB_CR_OIE                         ((uint32_t)0x00004000)        /*!< Overrun Interrupt Enable */
#define CANB_CR_EIE                         ((uint32_t)0x00002000)        /*!< Error Interrupt Enable */
#define CANB_CR_TIE                         ((uint32_t)0x00001000)        /*!< Transmit Interrupt Enable */
#define CANB_CR_RIE                         ((uint32_t)0x00000800)        /*!< Receive Interrupt Enable */
#define CANB_CR_RRB0                        ((uint32_t)0x00000080)        /*!< Release Receive Buffer 0 */
#define CANB_CR_RRB1                        ((uint32_t)0x00000040)        /*!< Release Receive Buffer 1 */
#define CANB_CR_BTR0                        ((uint32_t)0x00000020)        /*!< Transmit Buffer 0 Request */
#define CANB_CR_BTR1                        ((uint32_t)0x00000010)        /*!< Transmit Buffer 1 Request */
#define CANB_CR_BTR2                        ((uint32_t)0x00000008)        /*!< Transmit Buffer 2 Request */
#define CANB_CR_BTRn                        ((uint32_t)0x00000038)        /*!< Transmit Buffer 0, 1, 2 Request */
#define CANB_CR_SLEEP                       ((uint32_t)0x02000000)        /*!< Sleep Mode */

/* ====================  Bit definition for CANB_BS register  ====================== */
#define CANB_SR_BRS0                        ((uint32_t)0x00001800)        /*!< Receive Buffer (FIFO) 0 Status */
#define CANB_SR_BRS1                        ((uint32_t)0x00000600)        /*!< Receive Buffer (FIFO) 1 Status */
#define CANB_SR_BO                          ((uint32_t)0x00000080)        /*!< Bus-off */
#define CANB_SR_EW                          ((uint32_t)0x00000040)        /*!< Error Warning */
#define CANB_SR_TS                          ((uint32_t)0x00000020)        /*!< Transmit Status */
#define CANB_SR_RS                          ((uint32_t)0x00000010)        /*!< Receive Status */
#define CANB_SR_DO                          ((uint32_t)0x0000000C)        /*!< Data Overrun Field */
#define CANB_SR_BTA0                        ((uint32_t)0x08000000)        /*!< Buffer0 Transmission Abort */
#define CANB_SR_BTA1                        ((uint32_t)0x04000000)        /*!< Buffer1 Transmission Abort */
#define CANB_SR_BTA2                        ((uint32_t)0x02000000)        /*!< Buffer2 Transmission Abort */
#define CANB_SR_BTS0                        ((uint32_t)0x00010000)        /*!< TX Buffer0 Transmission status */
#define CANB_SR_BTS1                        ((uint32_t)0x00020000)        /*!< TX Buffer1 Transmission status */
#define CANB_SR_BTS2                        ((uint32_t)0x00030000)        /*!< TX Buffer2 Transmission status */

/* ====================  Bit definition for CANB_TFDn register  ====================== */
#define CANB_TFDn_RTR                       ((uint16_t)0x8000)            /*!< (Tx Buffer) Remote Transmission Request */
#define CANB_TFDn_EIR                       ((uint16_t)0x4000)            /*!< (Tx Buffer) Extended Identifier Enable */
#define CANB_TFDn_EDL                       ((uint16_t)0x0080)            /*!< (Tx Buffer) Extended Data Length (FD Enable) */
#define CANB_TFDn_BRS                       ((uint16_t)0x0040)            /*!< (Tx Buffer) Baud Rate Switch */

/* ====================  Bit definition for CANB_AFC0 register  ====================== */
#define CANB_AFC0_RBAFG0E                   ((uint8_t)0x80)               /*!< Receive Buffer Acceptance Filter Group 0 Enable */
#define CANB_AFC0_RBAFG1E                   ((uint8_t)0x40)               /*!< Receive Buffer Acceptance Filter Group 1 Enable */
#define CANB_AFC0_RB0DFB0E                  ((uint8_t)0x20)               /*!< Receive Buffer0 Data Filter Byte 0 Enable */
#define CANB_AFC0_RB0DFB1E                  ((uint8_t)0x10)               /*!< Receive Buffer0 Data Filter Byte 1 Enable */
#define CANB_AFC0_RB1DFB0E                  ((uint8_t)0x08)               /*!< Receive Buffer1 Data Filter Byte 0 Enable */
#define CANB_AFC0_RB1DFB1E                  ((uint8_t)0x04)               /*!< Receive Buffer1 Data Filter Byte 1 Enable */

/* ====================  Bit definition for CANB_FMC register  ====================== */
#define CANB_FMC_FMA                        ((uint8_t)0x80)               /*!< Filter Mask All */
#define CANB_FMC_RBAFM0E                    ((uint8_t)0x40)               /*!< Receive Buffer Acceptance Filter Mask Group 0 Enable */
#define CANB_FMC_RBAFM1E                    ((uint8_t)0x20)               /*!< Receive Buffer Acceptance Filter Mask Group 1 Enable */
#define CANB_FMC_RB0DFMB0E                  ((uint8_t)0x10)               /*!< Receive Buffer0 Data Filter Mask Byte 0 Enable */
#define CANB_FMC_RB0DFMB1E                  ((uint8_t)0x08)               /*!< Receive Buffer0 Data Filter Mask Byte 1 Enable */
#define CANB_FMC_RB1DFMB0E                  ((uint8_t)0x04)               /*!< Receive Buffer1 Data Filter Mask Byte 0 Enable */
#define CANB_FMC_RB1DFMB1E                  ((uint8_t)0x02)               /*!< Receive Buffer1 Data Filter Mask Byte 1 Enable */

/* ====================  Bit definition for CANB_RFDn register  ====================== */
#define CANB_RFDn_RTR                       ((uint16_t)0x8000)            /*!< (Rx Buffer) Remote Transmission Request */
#define CANB_RFDn_EIE                       ((uint16_t)0x4000)            /*!< (Rx Buffer) Extended Identifier Enable */
#define CANB_RFDn_EDL                       ((uint16_t)0x0080)            /*!< (Rx Buffer) Extended Data Length (FD Enable) */
#define CANB_RFDn_BRS                       ((uint16_t)0x0040)            /*!< (Rx Buffer) Baud Rate Switch */
#define CANB_RFDn_ESI                       ((uint16_t)0x0020)            /*!< (Rx Buffer) Error State Indicator */

/* ====================  Bit definition for CANB_REIHn register  ====================== */
#define CANB_REIHn_DL                       ((uint16_t)0x0F00)            /*!< (Rx Buffer) Data Lentgh Code */

/* ====================  Bit definition for CANB_EC register  ====================== */
#define CANB_EC_TEC                         ((uint16_t)0xFF00)            /*!< Transmitter Error Counter (TEC) */
#define CANB_EC_REC                         ((uint16_t)0x00FF)            /*!< Receiver Error Counter (REC) */

/* ====================  Bit definition for CANB_ET register  ====================== */
#define CANB_ET_BE                          ((uint8_t)0x80)               /*!< Bit Error */
#define CANB_ET_SE                          ((uint8_t)0x40)               /*!< Stuff Error */
#define CANB_ET_CE                          ((uint8_t)0x20)               /*!< CRC Error */
#define CANB_ET_FE                          ((uint8_t)0x10)               /*!< Form Error */
#define CANB_ET_AE                          ((uint8_t)0x08)               /*!< ACK Error */
#define CANB_ET_OE                          ((uint8_t)0x04)               /*!< Overrun Error */

/* ====================  Bit definition for CANB_IR register  ====================== */
#define CANB_IRR_WIR                        ((uint32_t)0x00000080)        /*!< Wake-up Interrupt Request */
#define CANB_IRR_OIR                        ((uint32_t)0x00000040)        /*!< Overrun Interrupt Request */
#define CANB_IRR_EIR                        ((uint32_t)0x00000020)        /*!< Error Interrupt Request */
#define CANB_IRR_TBI0                       ((uint32_t)0x00000010)        /*!< Transmit Buffer Interrupt 0 */
#define CANB_IRR_TBI1                       ((uint32_t)0x00000008)        /*!< Transmit Buffer Interrupt 1 */
#define CANB_IRR_TBI2                       ((uint32_t)0x00000004)        /*!< Transmit Buffer Interrupt 2 */
#define CANB_IRR_TBIn                       ((uint32_t)0x0000001C)        /*!< TBIn (n=0,1,2) field */
#define CANB_IRR_RBI0                       ((uint32_t)0x00000002)        /*!< Receive Buffer Interrupt 0 */
#define CANB_IRR_RBI1                       ((uint32_t)0x00000001)        /*!< Receive Buffer Interrupt 1 */
#define CANB_IRR_RBIn                       ((uint32_t)0x00000003)        /*!< RBIn (n=0,1) field */

/* =========================================================================================================================== */
/* ================                            CPU Address Transfer                                          ================= */
/* =========================================================================================================================== */
/* ====================  Bit definition for CPUAT_CTRL register  ====================== */
#define CPUAT_CTRL_EN                       ((uint32_t)0x00000001)        /*!< CPU Address Transfer Enable */

/* ====================  Bit definition for CPUAT_R0BASE register  ====================== */
#define CPUAT_R0BASE_VAL                    ((uint32_t)0xFFF00000)        /*!< Region 0 Transfer Base Address */

/* ====================  Bit definition for CPUAT_R0SIZE register  ====================== */
#define CPUAT_R0SIZE_VAL                    ((uint32_t)0xFFF00000)        /*!< Region 0 Transfer Size */

/* ====================  Bit definition for CPUAT_R1BASE register  ====================== */
#define CPUAT_R1BASE_VAL                    ((uint32_t)0xFFF00000)        /*!< Region 1 Transfer Base Address */

/* ====================  Bit definition for CPUAT_R1SIZE register  ====================== */
#define CPUAT_R1SIZE_VAL                    ((uint32_t)0xFFF00000)        /*!< Region 1 Transfer Size */

/* ====================  Bit definition for CPUAT_R2BASE register  ====================== */
#define CPUAT_R2BASE_VAL                    ((uint32_t)0xFFF00000)        /*!< Region 2 Transfer Base Address */

/* ====================  Bit definition for CPUAT_R2SIZE register  ====================== */
#define CPUAT_R2SIZE_VAL                    ((uint32_t)0xFFF00000)        /*!< Region 2 Transfer Size */

/* ====================  Bit definition for CPUAT_R3BASE register  ====================== */
#define CPUAT_R3BASE_VAL                    ((uint32_t)0xFFF00000)        /*!< Region 3 Transfer Base Address */

/* ====================  Bit definition for CPUAT_R3SIZE register  ====================== */
#define CPUAT_R3SIZE_VAL                    ((uint32_t)0xFFF00000)        /*!< Region 3 Transfer Size */

/* =========================================================================================================================== */
/* ================                         CPU Interrupt Mux Controller                               ================= */
/* =========================================================================================================================== */
/* ============================== Bit definition for IMCR register =================================== */
#define CPUIMC_IMCR_VAL                     ((uint32_t)0xFFFFFFFF)        /*!< Interrupt mux control */

/* =========================================================================================================================== */
/* ================                         CPU Inter Process Controller                               ================= */
/* =========================================================================================================================== */
/* ============================== Bit definition for IPCR register =================================== */
#define CPUIPC_IPCR_INTR2UX608L             ((uint32_t)0x00000001)        /*!< IPC UX608 to Ux608Lite interrupt control bit */
#define CPUIPC_IPCR_INTR2UX608              ((uint32_t)0x00000002)        /*!< IPC Ux608Lite to UX608 interrupt control bit */

/* =========================================================================================================================== */
/* ================                            Double Data Rate SDRAM                                        ================= */
/* =========================================================================================================================== */
/* ====================  Bit definition for DAC_CR register  ====================== */
#define DAC_CR_EN0                          ((uint32_t)0x00000001)        /*!< DAC channel0 enable */
#define DAC_CR_TEN0                         ((uint32_t)0x00000002)        /*!< DAC channel0 Trigger enable */
#define DAC_CR_TSEL0                        ((uint32_t)0x0000001C)        /*!< TSEL1[2:0] (DAC channel0 Trigger selection) */
#define DAC_CR_TSEL1_0                      ((uint32_t)0x00000004)        /*!< Bit 0 */
#define DAC_CR_TSEL1_1                      ((uint32_t)0x00000008)        /*!< Bit 1 */
#define DAC_CR_TSEL1_2                      ((uint32_t)0x00000010)        /*!< Bit 2 */
#define DAC_CR_WAVE0                        ((uint32_t)0x00000020)        /*!< WAVE1 (DAC channel0 triangle wave generation enable) */
#define DAC_CR_MAMP0                        ((uint32_t)0x000003C0)        /*!< MAMP1[3:0] (DAC channel0 Amplitude selector) */
#define DAC_CR_MAMP0_0                      ((uint32_t)0x00000040)        /*!< Bit 0 */
#define DAC_CR_MAMP0_1                      ((uint32_t)0x00000080)        /*!< Bit 1 */
#define DAC_CR_MAMP0_2                      ((uint32_t)0x00000100)        /*!< Bit 2 */
#define DAC_CR_MAMP0_3                      ((uint32_t)0x00000200)        /*!< Bit 3 */
#define DAC_CR_ALIGN0                       ((uint32_t)0x00000400)        /*!< DAC channel0 data align */
#define DAC_CR_DSIZE0                       ((uint32_t)0x00000800)        /*!< DAC channel0 data width */
#define DAC_CR_DMA_EN0                      ((uint32_t)0x00001000)        /*!< DAC channel0 DMA enable */
#define DAC_CR_SYNC_RTG_EN                  ((uint32_t)0x20000000)        /*!< DAC channel0 and channel2 synchronous trigger enabled */

/* ====================  Bit definition for DAC_SWTRIGR register  ====================== */
#define DAC_SWTRGR_SW_TRG0                  ((uint8_t)0x01)               /*!< DAC channel0 software trigger */
#define DAC_SWTRGR_SW_TRG1                  ((uint8_t)0x02)               /*!< DAC channel1 software trigger */

/* ====================  Bit definition for DAC_ISR register  ====================== */
#define DAC_ISR_DMA_UDR0                    ((uint8_t)0x01)               /*!< DAC channel0 dma underrun state */
#define DAC_ISR_DMA_UDR1                    ((uint8_t)0x02)               /*!< DAC channel1 dma underrun state */

/* ====================  Bit definition for DAC_IER register  ====================== */
#define DAC_IER_DMA_IER0                    ((uint8_t)0x01)               /*!< DAC channel0 dma interrupt enable */
#define DAC_IER_DMA_IER1                    ((uint8_t)0x02)               /*!< DAC channel1 dma interrupt enable */

/* =========================================================================================================================== */
/* ================                            Double Data Rate SDRAM Controller                             ================= */
/* =========================================================================================================================== */
/* ====================  Bit definition for MCCR register  ====================== */
#define DDRC_MCCR_GDS                       ((uint32_t)0x00000007)        /*!< Generate DQS sampling window */
#define DDRC_MCCR_DC                        ((uint32_t)0x00000008)        /*!< Data coherence check disable */
#define DDRC_MCCR_AMTSEL                    ((uint32_t)0x00000030)        /*!< DDR memory address mapping table select */
#define DDRC_MCCR_MW                        ((uint32_t)0x00000300)        /*!< Memory Width */
#define DDRC_MCCR_ARCI                      ((uint32_t)0x00001C00)        /*!< Auto-refresh commands in the initial SDRAM sequency */
#define DDRC_MCCR_PRCCNT                    ((uint32_t)0x0000E000)        /*!< Post-refresh command counts threshold */
#define DDRC_MCCR_DM                        ((uint32_t)0x00030000)        /*!< DDR Mode */
#define DDRC_MCCR_BYONE                     ((uint32_t)0x00040000)        /*!< MClk versus DRAM clock frequency ratio */
#define DDRC_MCCR_LPM                       ((uint32_t)0x00080000)        /*!< LPDDR mode */
#define DDRC_MCCR_CMDR                      ((uint32_t)0x00100000)        /*!< DDR command reorder */
#define DDRC_MCCR_CCL                       ((uint32_t)0x00600000)        /*!< Continuous command limitation in the scheduler */
#define DDRC_MCCR_WC                        ((uint32_t)0x07800000)        /*!< Wait cycles max value for command popped out to the scheduler */
#define DDRC_MCCR_AER                       ((uint32_t)0x08000000)        /*!< APB error response disable */
#define DDRC_MCCR_MR                        ((uint32_t)0x10000000)        /*!< manual refresh enable */

/* ====================  Bit definition for MCSR register  ====================== */
#define DDRC_MCSR_INIT                      ((uint32_t)0x00000001)        /*!< Initial command */
#define DDRC_MCSR_MRS                       ((uint32_t)0x00000002)        /*!< Initial command */
#define DDRC_MCSR_SRF                       ((uint32_t)0x00000004)        /*!< Self-refresh command */
#define DDRC_MCSR_SRFE                      ((uint32_t)0x00000008)        /*!< Exit self-refresh command */
#define DDRC_MCSR_RM                        ((uint32_t)0x00000030)        /*!< Register mode */
#define DDRC_MCSR_ZQCS                      ((uint32_t)0x00000040)        /*!< ZQCS Operation */
#define DDRC_MCSR_ZQCL                      ((uint32_t)0x00000080)        /*!< ZQCL Operation */
#define DDRC_MCSR_INITCMPL                  ((uint32_t)0x00000100)        /*!< Initial OK */
#define DDRC_MCSR_INITSTS                   ((uint32_t)0x00000200)        /*!< Initial state */
#define DDRC_MCSR_SRFSTS                    ((uint32_t)0x00000400)        /*!< Self-refresh state */
#define DDRC_MCSR_APDSTS                    ((uint32_t)0x00000800)        /*!< Automatic power-down state */
#define DDRC_MCSR_ZQCSSTS                   ((uint32_t)0x00001000)        /*!< ZQCS state */
#define DDRC_MCSR_ZQCLSTS                   ((uint32_t)0x00002000)        /*!< ZQCL state */
#define DDRC_MCSR_MCCQE                     ((uint32_t)0x00004000)        /*!< Memory controller command queue empty */
#define DDRC_MCSR_ACQE                      ((uint32_t)0x00008000)        /*!< AHB/AXI command queue empty */
#define DDRC_MCSR_RLFAIL                    ((uint32_t)0x00010000)        /*!< Read-leveling fail or hardware disable */
#define DDRC_MCSR_WLFAIL                    ((uint32_t)0x00020000)        /*!< Write-leveling fail or hardware disable */
#define DDRC_MCSR_DADC                      ((uint32_t)0x00040000)        /*!< DDR access disable complete */
#define DDRC_MCSR_WS                        ((uint32_t)0x01000000)        /*!< Warm Start */
#define DDRC_MCSR_DAD                       ((uint32_t)0x02000000)        /*!< DDR access disable */
#define DDRC_MCSR_MRRS                      ((uint32_t)0x04000000)        /*!< MR rank select */

/* ====================  Bit definition for MRSVR0 register  ====================== */
#define DDRC_MRSVR0_MR                      ((uint32_t)0x00003FFF)        /*!< Mode register (MR0 in the DDR3 mode) */
#define DDRC_MRSVR0_EMR                     ((uint32_t)0x3FFF0000)        /*!< Extended mode register (MR1 in the DDR3 mode) */

/* ====================  Bit definition for MRSVR1 register  ====================== */
#define DDRC_MRSVR1_EMR2                    ((uint32_t)0x00003FFF)        /*!< Extended mode register 2 (MR2 in the DDR3 mode) */
#define DDRC_MRSVR1_EMR3                    ((uint32_t)0x3FFF0000)        /*!< Extended mode register 3 (MR3 in the DDR3 mode) */

/* ====================  Bit definition for EXRANKR register  ====================== */
#define DDRC_EXRANKR_R0S                    ((uint32_t)0x00000007)        /*!< Rank0 size */
#define DDRC_EXRANKR_R0T                    ((uint32_t)0x00000070)        /*!< Rank0 type */
#define DDRC_EXRANKR_R1S                    ((uint32_t)0x00000700)        /*!< Rank1 size */
#define DDRC_EXRANKR_R1T                    ((uint32_t)0x00007000)        /*!< Rank1 type */
#define DDRC_EXRANKR_R1EN                   ((uint32_t)0x00010000)        /*!< Rank1 enable */
#define DDRC_EXRANKR_R0B                    ((uint32_t)0xFF000000)        /*!< Rank0 base address */

/* ====================  Bit definition for TMPR0 register  ====================== */
#define DDRC_TMPR0_TRAS                     ((uint32_t)0x0000001F)        /*!< Active to Precharge period */
#define DDRC_TMPR0_TRC                      ((uint32_t)0x00003F00)        /*!< Active to Active command period for the same bank */
#define DDRC_TMPR0_TFAW                     ((uint32_t)0x001F0000)        /*!< 4 bank activate windows */
#define DDRC_TMPR0_TRFC                     ((uint32_t)0xFF000000)        /*!< Refresh-to-Active/Refresh command period */

/* ====================  Bit definition for TMPR1 register  ====================== */
#define DDRC_TMPR1_TRCD                     ((uint32_t)0x0000000F)        /*!< The minimum delay between the active and read/write commands */
#define DDRC_TMPR1_TRRD                     ((uint32_t)0x000000F0)        /*!< Active-to-Active command period for different banks */
#define DDRC_TMPR1_TRP                      ((uint32_t)0x00000F00)        /*!< Precharge period */
#define DDRC_TMPR1_TMRD                     ((uint32_t)0x0000F000)        /*!< Cycle time of the load mode register command */
#define DDRC_TMPR1_TMOD                     ((uint32_t)0x000F0000)        /*!< The mode register sets the command update delay */
#define DDRC_TMPR1_TWR                      ((uint32_t)0x00F00000)        /*!< Write recovery time */
#define DDRC_TMPR1_TRTP                     ((uint32_t)0x07000000)        /*!< Internal read-to-precharge delay */
#define DDRC_TMPR1_TWTR                     ((uint32_t)0x70000000)        /*!< Internal write-to-read delay */

/* ====================  Bit definition for TMPR2 register  ====================== */
#define DDRC_TMPR2_TREFI                    ((uint32_t)0x000000FF)        /*!< Average periodic refresh interval */
#define DDRC_TMPR2_TXSR                     ((uint32_t)0x0000FF00)        /*!< Exit from the self-refresh mode to a command period */
#define DDRC_TMPR2_TRTOW                    ((uint32_t)0x03000000)        /*!< Additional delay cycles from the read command to the write command */
#define DDRC_TMPR2_TRTOR                    ((uint32_t)0x0C000000)        /*!< Additional delay cycles from the read command to the read command */
#define DDRC_TMPR2_TWTOW                    ((uint32_t)0x30000000)        /*!< Additional delay cycles from the write command to the write command */
#define DDRC_TMPR2_TWTOR                    ((uint32_t)0xC0000000)        /*!< Additional delay cycles from the write command to the read command for accessing different ranks */

/* ====================  Bit definition for PHYCR0 register  ====================== */
#define DDRC_PHYCR0_ODTMDDQ                 ((uint32_t)0x00000007)        /*!< ODT value of DQ */
#define DDRC_PHYCR0_PRSRFX                  ((uint32_t)0x00000008)        /*!< Enable automatically reset D-PHY after exiting the self-refresh mode */
#define DDRC_PHYCR0_ODTMDDQS                ((uint32_t)0x00000070)        /*!< ODT value of DQS */
#define DDRC_PHYCR0_AICPDN                  ((uint32_t)0x00000080)        /*!< Automatic control of the I/O Input buffer at power-down state */
#define DDRC_PHYCR0_ODTOEN                  ((uint32_t)0x00000100)        /*!< Enable input drivers of ODT */
#define DDRC_PHYCR0_CMDADDROEN              ((uint32_t)0x00000200)        /*!< The input controls of the DDR PHY ADDR, BA, RAS, CAS, WE, and CS drivers */
#define DDRC_PHYCR0_CLKOEN                  ((uint32_t)0x00000400)        /*!< The input controls DDR PHY CK and CKB */
#define DDRC_PHYCR0_DQIE                    ((uint32_t)0x00000800)        /*!< DQ and DQS receivers enable */
#define DDRC_PHYCR0_CPS                     ((uint32_t)0x00001000)        /*!< DDR PHY input clock for the DDR SDRAM phase */
#define DDRC_PHYCR0_CUP                     ((uint32_t)0x00002000)        /*!< DDR PHY DLL update enable control */
#define DDRC_PHYCR0_SB                      ((uint32_t)0x00004000)        /*!< VREF selection */
#define DDRC_PHYCR0_AIDPDN                  ((uint32_t)0x00008000)        /*!< Automatic control of the I/O input buffer at the power-down state */
#define DDRC_PHYCR0_CFLDO                   ((uint32_t)0x00010000)        /*!< Command block DLL lock state. */
#define DDRC_PHYCR0_PHYODD                  ((uint32_t)0x00020000)        /*!< RE_ODD and WR_ODD signal usages for DDRx PHY */
#define DDRC_PHYCR0_B0FLDO                  ((uint32_t)0x01000000)        /*!< Byte 0 DLL lock flag indicates that DLL is at the lock state */
#define DDRC_PHYCR0_B1FLDO                  ((uint32_t)0x02000000)        /*!< Byte 1 DLL lock flag indicates that DLL is at the lock state */
#define DDRC_PHYCR0_B2FLDO                  ((uint32_t)0x04000000)        /*!< Byte 2 DLL lock flag indicates that DLL is at the lock state */
#define DDRC_PHYCR0_B3FLDO                  ((uint32_t)0x08000000)        /*!< Byte 3 DLL lock flag indicates that DLL is at the lock state */

/* ====================  Bit definition for PHYRDTR register  ====================== */
#define DDRC_PHYRDTR_B0DLSELRD              ((uint32_t)0x0000000F)        /*!< Byte 0 delay value control to add a delay into the read DQS or read DQ */
#define DDRC_PHYRDTR_B1DLSELRD              ((uint32_t)0x000000F0)        /*!< Byte 1 delay value control to add a delay into the read DQS or read DQ */
#define DDRC_PHYRDTR_B2DLSELRD              ((uint32_t)0x00000F00)        /*!< Byte 2 delay value control to add a delay into the read DQS or read DQ */
#define DDRC_PHYRDTR_B3DLSELRD              ((uint32_t)0x0000F000)        /*!< Byte 3 delay value control to add a delay into the read DQS or read DQ */

/* ====================  Bit definition for COMPBLKCR register  ====================== */
#define DDRC_COMPBLKCR_COMPSEL              ((uint32_t)0x00000001)        /*!< Compensation method selection */
#define DDRC_COMPBLKCR_DIP                  ((uint32_t)0x0000007E)        /*!< Preset value for the COMPBLK pull-up PMOS impedance */
#define DDRC_COMPBLKCR_DIN                  ((uint32_t)0x00001F80)        /*!< Preset value for the COMPBLK pull-down NMOS impedance */
#define DDRC_COMPBLKCR_DOP                  ((uint32_t)0x0007E000)        /*!< Value of the COMPBLK pull-up PMOS impedance setting from the input */
#define DDRC_COMPBLKCR_DON                  ((uint32_t)0x01F80000)        /*!< Value of the COMPBLK pull-down NMOS impedance setting from the input */

/* ====================  Bit definition for APDCR register  ====================== */
#define DDRC_APDCR_APDNT                    ((uint32_t)0x00000FFF)        /*!< Automatic power-down timer */
#define DDRC_APDCR_APDN                     ((uint32_t)0x00001000)        /*!< Automatic power-down mode control */
#define DDRC_APDCR_ASRFT                    ((uint32_t)0x0FFF0000)        /*!< Automatic self-refresh timer */
#define DDRC_APDCR_ASRF                     ((uint32_t)0x10000000)        /*!< Automatic self-refresh mode control */

/* ====================  Bit definition for CHARBRA register  ====================== */
#define DDRC_CHARBRA_CHP                    ((uint32_t)0x000000FF)        /*!< Channel high-priority */
#define DDRC_CHARBRA_BOA                    ((uint32_t)0x0000FF00)        /*!< Burst oriented arbitration enable */
#define DDRC_CHARBRA_GGCL                   ((uint32_t)0x1F000000)        /*!< Group grant count low */
#define DDRC_CHARBRA_IRW                    ((uint32_t)0x40000000)        /*!< Independent R/W control */
#define DDRC_CHARBRA_RWG                    ((uint32_t)0x80000000)        /*!< Enable the Read-Write group arbitration */

/* ====================  Bit definition for CHGNTRA register  ====================== */
#define DDRC_CHGNTRA_ARBCNT0                ((uint32_t)0x000000FF)        /*!< The maximum allowed commands will be issued once channel 0 is granted. */
#define DDRC_CHGNTRA_ARBCNT1                ((uint32_t)0x0000FF00)        /*!< The maximum allowed commands will be issued once channel 1 is granted. */
#define DDRC_CHGNTRA_ARBCNT2                ((uint32_t)0x00FF0000)        /*!< The maximum allowed commands will be issued once channel 2 is granted. */
#define DDRC_CHGNTRA_ARBCNT3                ((uint32_t)0xFF000000)        /*!< The maximum allowed commands will be issued once channel 3 is granted. */

/* ====================  Bit definition for PHYWRTMR register  ====================== */
#define DDRC_PHYWRTMR_WRLAT                 ((uint32_t)0x0000000F)        /*!< The number of MClk clock cycles between when a write command is sent
                                                                              on the DFI control interface and when the dfi_wrdata_en signal is asserted. */
#define DDRC_PHYWRTMR_WRD                   ((uint32_t)0x00000030)        /*!< The number of MClk clock cycles between when the dfi_wrdata_en signal is
                                                                              asserted and when the associated write data are driven on the dfi_wrdata signal. */
#define DDRC_PHYWRTMR_TRDEN                 ((uint32_t)0x000F0000)        /*!< The cycles must be asserted after the assertion of a read command on the PHY
                                                                              control interface and remains valid for the duration of contiguous read data
                                                                              expected on the dfi_rddata bus. */
#define DDRC_PHYWRTMR_RDLAT                 ((uint32_t)0x00F00000)        /*!< The MClk cycles that dfi_rddata expected to receive after rdcmd is asserted. */

/* ====================  Bit definition for FLUSHCR register  ====================== */
#define DDRC_FLUSHCR_CFEN                   ((uint32_t)0x000000FF)        /*!< Enable of command flushing. */
#define DDRC_FLUSHCR_FIEN                   ((uint32_t)0x0000FF00)        /*!< Interrupt enable for the command flushing. */
#define DDRC_FLUSHCR_DIEN                   ((uint32_t)0x00010000)        /*!< Interrupt enable for the debug function. */

/* ====================  Bit definition for FLUSHSR register  ====================== */
#define DDRC_FLUSHSR_FD                     ((uint32_t)0x000000FF)        /*!< Status of the command flushing. */
#define DDRC_FLUSHSR_DH                     ((uint32_t)0x00000100)        /*!< Status of the debug function. */

/* ====================  Bit definition for SPLITCR register  ====================== */
#define DDRC_SPLITCR_CH2SDEN                ((uint32_t)0x00000004)        /*!< Disable SPLIT response of channel 2. */
#define DDRC_SPLITCR_CH3SDEN                ((uint32_t)0x00000008)        /*!< Disable SPLIT response of channel 3. */
#define DDRC_SPLITCR_CH2HPROT               ((uint32_t)0x00003000)        /*!< Channel 2 bufferable select. */
#define DDRC_SPLITCR_CH3HPROT               ((uint32_t)0x0000C000)        /*!< Channel 3 bufferable select. */

/* ====================  Bit definition for UPDCR register  ======================== */
#define DDRC_UPDCR_TDLLUP                   ((uint32_t)0x000000FF)        /*!< Digital DLL update delay control code timing interval. */
#define DDRC_UPDCR_TWLUP                    ((uint32_t)0x0000FF00)        /*!< Write-leveling calibration timing interval. */
#define DDRC_UPDCR_ZQCUP                    ((uint32_t)0x00030000)        /*!< ZQCS or ZQCL enable after exiting from the self-refresh state. */

/* ====================  Bit definition for REVR register  =======---=============== */
#define DDRC_REVR_REL                       ((uint32_t)0x000000FF)        /*!< The release number of the current revision. */
#define DDRC_REVR_MIN                       ((uint32_t)0x0000FF00)        /*!< The minor version number of the DDRx memory controller. */
#define DDRC_REVR_MAJ                       ((uint32_t)0x00000000)        /*!< The major version number of the DDRx memory controller. */

/* ====================  Bit definition for FEATR1 register  ======================= */
#define DDRC_FEATR1_CHNCNT                  ((uint32_t)0x00000007)        /*!< The channel counts */
#define DDRC_FEATR1_AMECN                   ((uint32_t)0x00000038)        /*!< The atomic monitor entries counts */
#define DDRC_FEATR1_MAXMW                   ((uint32_t)0x000000C0)        /*!< The maximum memory width of controller */
#define DDRC_FEATR1_CH0TYP                  ((uint32_t)0x00000100)        /*!< The channel 0 interface type */
#define DDRC_FEATR1_CH1TYP                  ((uint32_t)0x00000200)        /*!< The channel 1 interface type */
#define DDRC_FEATR1_CH2TYP                  ((uint32_t)0x00000300)        /*!< The channel 2 interface type */
#define DDRC_FEATR1_CH3TYP                  ((uint32_t)0x00000400)        /*!< The channel 3 interface type */
#define DDRC_FEATR1_CH0DW                   ((uint32_t)0x00010000)        /*!< The channel 0 data width */
#define DDRC_FEATR1_CH1DW                   ((uint32_t)0x00020000)        /*!< The channel 1 data width */
#define DDRC_FEATR1_CH2DW                   ((uint32_t)0x00040000)        /*!< The channel 2 data width */
#define DDRC_FEATR1_CH3DW                   ((uint32_t)0x00080000)        /*!< The channel 3 data width */
#define DDRC_FEATR1_BN                      ((uint32_t)0x01000000)        /*!< The bank number per rank */
#define DDRC_FEATR1_BS                      ((uint32_t)0x02000000)        /*!< The bank swizzle configuration */

/* ====================  Bit definition for FEATR2 register  ====================== */
#define DDRC_FEATR2_CH0CM                   ((uint32_t)0x00000003)        /*!< The channel 0 clock mode. */
#define DDRC_FEATR2_CH0STYP                 ((uint32_t)0x00000004)        /*!< The channel 0 split type. */
#define DDRC_FEATR2_CH0BCTYP                ((uint32_t)0x00000008)        /*!< The channel 0 bus connect type. */
#define DDRC_FEATR2_CH1CM                   ((uint32_t)0x00000030)        /*!< The channel 1 clock mode. */
#define DDRC_FEATR2_CH1STYP                 ((uint32_t)0x00000040)        /*!< The channel 1 split type. */
#define DDRC_FEATR2_CH1BCTYP                ((uint32_t)0x00000080)        /*!< The channel 1 bus connect type. */
#define DDRC_FEATR2_CH2CM                   ((uint32_t)0x00000300)        /*!< The channel 2 clock mode. */
#define DDRC_FEATR2_CH2STYP                 ((uint32_t)0x00000400)        /*!< The channel 2 split type. */
#define DDRC_FEATR2_CH2BCTYP                ((uint32_t)0x00000800)        /*!< The channel 2 bus connect type. */
#define DDRC_FEATR2_CH3CM                   ((uint32_t)0x00003000)        /*!< The channel 3 clock mode. */
#define DDRC_FEATR2_CH3STYP                 ((uint32_t)0x00004000)        /*!< The channel 3 split type. */
#define DDRC_FEATR2_CH3BCTYP                ((uint32_t)0x00008000)        /*!< The channel 3 bus connect type. */

/* ====================  Bit definition for UDEFR register  ====================== */
#define DDRC_UDEFR_UDR                      ((uint32_t)0xFFFFFFFF)        /*!< User-defined register for specific usage. */

/* ====================  Bit definition for WLEVELCR register  ====================== */
#define DDRC_WLEVELCR_TWLO                  ((uint32_t)0x000000FF)        /*!< Write-leveling DQS enable to latch the DQ data delay time. */
#define DDRC_WLEVELCR_BYTE0DEN              ((uint32_t)0x00010000)        /*!< Byte 0 write-leveling hardware disable. */
#define DDRC_WLEVELCR_BYTE1DEN              ((uint32_t)0x00020000)        /*!< Byte 1 write-leveling hardware disable. */
#define DDRC_WLEVELCR_BYTE2DEN              ((uint32_t)0x00040000)        /*!< Byte 2 write-leveling hardware disable. */
#define DDRC_WLEVELCR_BYTE3DEN              ((uint32_t)0x00080000)        /*!< Byte 3 write-leveling hardware disable. */
#define DDRC_WLEVELCR_BYTE0PASS             ((uint32_t)0x01000000)        /*!< Byte 0 write-leveling status. */
#define DDRC_WLEVELCR_BYTE1PASS             ((uint32_t)0x02000000)        /*!< Byte 1 write-leveling status. */
#define DDRC_WLEVELCR_BYTE2PASS             ((uint32_t)0x04000000)        /*!< Byte 2 write-leveling status. */
#define DDRC_WLEVELCR_BYTE3PASS             ((uint32_t)0x08000000)        /*!< Byte 3 write-leveling status. */

/* ====================  Bit definition for WLEVELBLR register  ====================== */
#define DDRC_WLEVELBLR_BYTE0PDL             ((uint32_t)0x0000007F)        /*!< Byte 0 programable DLL delay */
#define DDRC_WLEVELBLR_BYTE1PDL             ((uint32_t)0x00007F00)        /*!< Byte 1 programable DLL delay */
#define DDRC_WLEVELBLR_BYTE2PDL             ((uint32_t)0x007F0000)        /*!< Byte 2 programable DLL delay */
#define DDRC_WLEVELBLR_BYTE3PDL             ((uint32_t)0x7F000000)        /*!< Byte 3 programable DLL delay */

/* ====================  Bit definition for PHYMISCR1 register  ====================== */
#define DDRC_PHYMISCR1_BYTE0DQSRD           ((uint32_t)0x00000001)        /*!< Byte 0 read added delay in DQ or DQS configuration */
#define DDRC_PHYMISCR1_BYTE0DQSWR           ((uint32_t)0x00000002)        /*!< Byte 0 write added delay in DQ or DQS configuration */
#define DDRC_PHYMISCR1_BYTE1DQSRD           ((uint32_t)0x00000010)        /*!< Byte 1 read added delay in DQ or DQS configuration */
#define DDRC_PHYMISCR1_BYTE1DQSWR           ((uint32_t)0x00000020)        /*!< Byte 1 write added delay in DQ or DQS configuration */
#define DDRC_PHYMISCR1_BYTE2DQSRD           ((uint32_t)0x00000100)        /*!< Byte 2 read added delay in DQ or DQS configuration */
#define DDRC_PHYMISCR1_BYTE2DQSWR           ((uint32_t)0x00000200)        /*!< Byte 2 write added delay in DQ or DQS configuration */
#define DDRC_PHYMISCR1_BYTE3DQSRD           ((uint32_t)0x00001000)        /*!< Byte 3 read added delay in DQ or DQS configuration */
#define DDRC_PHYMISCR1_BYTE3DQSWR           ((uint32_t)0x00002000)        /*!< Byte 3 write added delay in DQ or DQS configuration */

/* ====================  Bit definition for RLEVELCR register  ====================== */
#define DDRC_RLEVELCR_BYTE0DEN              ((uint32_t)0x00000001)        /*!< Byte 0 read-leveling hardware disable */
#define DDRC_RLEVELCR_BYTE1DEN              ((uint32_t)0x00000002)        /*!< Byte 1 read-leveling hardware disable */
#define DDRC_RLEVELCR_BYTE2DEN              ((uint32_t)0x00000004)        /*!< Byte 2 read-leveling hardware disable */
#define DDRC_RLEVELCR_BYTE3DEN              ((uint32_t)0x00000008)        /*!< Byte 3 read-leveling hardware disable */
#define DDRC_RLEVELCR_TRAINPERIOD           ((uint32_t)0x0000FF00)        /*!< Periodic read-leveling training timing interval */
#define DDRC_RLEVELCR_PERIOTRAINEN          ((uint32_t)0x00010000)        /*!< Periodic read leveling enable (Only for LPDDR2 mode) */
#define DDRC_RLEVELCR_BYTE0PASS             ((uint32_t)0x01000000)        /*!< Byte 0 read-leveling status */
#define DDRC_RLEVELCR_BYTE1PASS             ((uint32_t)0x02000000)        /*!< Byte 1 read-leveling status */
#define DDRC_RLEVELCR_BYTE2PASS             ((uint32_t)0x04000000)        /*!< Byte 2 read-leveling status */
#define DDRC_RLEVELCR_BYTE3PASS             ((uint32_t)0x08000000)        /*!< Byte 3 read-leveling status */

/* ====================  Bit definition for MSDLYCR register  ====================== */
#define DDRC_MSDLYCR_BYTE0MSDLY             ((uint32_t)0x0000000F)        /*!< Byte 0 programmable read DQS filtering window */
#define DDRC_MSDLYCR_BYTE1MSDLY             ((uint32_t)0x000000F0)        /*!< Byte 1 programmable read DQS filtering window */
#define DDRC_MSDLYCR_BYTE2MSDLY             ((uint32_t)0x00000F00)        /*!< Byte 2 programmable read DQS filtering window */
#define DDRC_MSDLYCR_BYTE3MSDLY             ((uint32_t)0x0000F000)        /*!< Byte 3 programmable read DQS filtering window */

/* ====================  Bit definition for WRDLLCR register  ====================== */
#define DDRC_WRDLLCR_BYTE0DLSEL             ((uint32_t)0x0000000F)        /*!< Byte 0 delay control, to add a delay in DQS or DQ */
#define DDRC_WRDLLCR_BYTE1DLSEL             ((uint32_t)0x000000F0)        /*!< Byte 1 delay control, to add a delay in DQS or DQ */
#define DDRC_WRDLLCR_BYTE2DLSEL             ((uint32_t)0x00000F00)        /*!< Byte 2 delay control, to add a delay in DQS or DQ */
#define DDRC_WRDLLCR_BYTE3DLSEL             ((uint32_t)0x0000F000)        /*!< Byte 3 delay control, to add a delay in DQS or DQ */

/* ====================  Bit definition for TRAFMR register  ====================== */
#define DDRC_TRAFMR_CYCLE                   ((uint32_t)0xFFFFFFFF)        /*!< Traffic monitor clock cycle */

/* ====================  Bit definition for CMDCNTR0 register  ====================== */
#define DDRC_CMDCNTR0_CNT                   ((uint32_t)0xFFFFFFFF)        /*!< The records of issued commands from channel 0 */

/* ====================  Bit definition for CMDCNTR1 register  ====================== */
#define DDRC_CMDCNTR1_CNT                   ((uint32_t)0xFFFFFFFF)        /*!< The records of issued commands from channel 1 */

/* ====================  Bit definition for CMDCNTR2 register  ====================== */
#define DDRC_CMDCNTR2_CNT                   ((uint32_t)0xFFFFFFFF)        /*!< The records of issued commands from channel 2 */

/* ====================  Bit definition for CMDCNTR3 register  ====================== */
#define DDRC_CMDCNTR3_CNT                   ((uint32_t)0xFFFFFFFF)        /*!< The records of issued commands from channel 3 */

/* ====================  Bit definition for AHBRPRER1 register  ====================== */
#define DDRC_AHBRPRER1_CH0PREFAVL           ((uint32_t)0x0000001F)        /*!< The channel 0 INCR read prefetching value */
#define DDRC_AHBRPRER1_CH0PREFLMIT          ((uint32_t)0x00000080)        /*!< The channel 0 Prefetch mechanism */
#define DDRC_AHBRPRER1_CH1PREFVAL           ((uint32_t)0x00001F00)        /*!< The channel 1 INCR read prefetching value */
#define DDRC_AHBRPRER1_CH1PRELMIT           ((uint32_t)0x00080000)        /*!< The channel 1 Prefetch mechanism  */
#define DDRC_AHBRPRER1_CH2PREFVAL           ((uint32_t)0x001F0000)        /*!< The channel 2 INCR read prefetching value */
#define DDRC_AHBRPRER1_CH2PREFLMIT          ((uint32_t)0x00800000)        /*!< The channel 2 Prefetch mechanism  */
#define DDRC_AHBRPRER1_CH3PREFVAL           ((uint32_t)0x1F000000)        /*!< The channel 3 INCR read prefetching value */
#define DDRC_AHBRPRER1_CH3PREFLMIT          ((uint32_t)0x80000000)        /*!< The channel 3 Prefetch mechanism  */

/* ====================  Bit definition for INITWCR1 register  ====================== */
#define DDRC_INITWCR1_WAITCYCLE             ((uint32_t)0x000FFFFF)        /*!< The cycles for initial 200us waiting time */

/* ====================  Bit definition for INITWCR2 register  ====================== */
#define DDRC_INITWCR2_WAITCYCLE             ((uint32_t)0x000FFFFF)        /*!< The cycles for initial 500us waiting time    */

/* ====================  Bit definition for QOSCR register  ====================== */
#define DDRC_QOSCR_EN                       ((uint32_t)0x00000001)        /*!< QoS enable */
#define DDRC_QOSCR_PERIOD                   ((uint32_t)0x00000006)        /*!< QoS period mode */
#define DDRC_QOSCR_INDEPRWEN                ((uint32_t)0x00000008)        /*!< QoS independent R/W enable */

/* ====================  Bit definition for QOSCNTRA register  ====================== */
#define DDRC_QOSCNTRA_CH0CMDCNT             ((uint32_t)0x000000FF)        /*!< Command count limitation for channel 0 */
#define DDRC_QOSCNTRA_CH1CMDCNT             ((uint32_t)0x0000FF00)        /*!< Command count limitation for channel 1 */
#define DDRC_QOSCNTRA_CH2CMDCNT             ((uint32_t)0x00FF0000)        /*!< Command count limitation for channel 2 */
#define DDRC_QOSCNTRA_CH3CMDCNT             ((uint32_t)0xFF000000)        /*!< Command count limitation for channel 3 */

/* ====================  Bit definition for QOSCNTRC register  ====================== */
#define DDRC_QOSCNTRC_CH0CMDCNTW            ((uint32_t)0x000000FF)        /*!< Write command count limitation for channel 0 */
#define DDRC_QOSCNTRC_CH1CMDCNTW            ((uint32_t)0x0000FF00)        /*!< Write command count limitation for channel 1 */
#define DDRC_QOSCNTRC_CH2CMDCNTW            ((uint32_t)0x00FF0000)        /*!< Write command count limitation for channel 2 */
#define DDRC_QOSCNTRC_CH3CMDCNTW            ((uint32_t)0xFF000000)        /*!< Write command count limitation for channel 3 */

/* ====================  Bit definition for CHARBRB register  ====================== */
#define DDRC_CHARBRB_HIPRIORW               ((uint32_t)0x000000FF)        /*!< Channel write command priority group select */
#define DDRC_CHARBRB_BSTORIARBW             ((uint32_t)0x0000FF00)        /*!< Channel write command burst oriented arbition enable bit */
#define DDRC_CHARBRB_GRPGRANTCNTH           ((uint32_t)0x00070000)        /*!< Group grant count high */
#define DDRC_CHARBRB_GRPGRANTCNTW           ((uint32_t)0xFF000000)        /*!< The maxinum of write commands issued when the write group is granted */

/* ====================  Bit definition for CHGNTRC register  ====================== */
#define DDRC_CHGNTRC_CH0ARBCNTW             ((uint32_t)0x000000FF)        /*!< The maxinum of write commands issued when once channel 0 is granted */
#define DDRC_CHGNTRC_CH1ARBCNTW             ((uint32_t)0x0000FF00)        /*!< The maxinum of write commands issued when once channel 1 is granted */
#define DDRC_CHGNTRC_CH2ARBCNTW             ((uint32_t)0x00FF0000)        /*!< The maxinum of write commands issued when once channel 2 is granted */
#define DDRC_CHGNTRC_CH3ARBCNTW             ((uint32_t)0xFF000000)        /*!< The maxinum of write commands issued when once channel 3 is granted */

/* ====================  Bit definition for LP2MRA register  ====================== */
#define DDRC_LP2MRA_MR1                     ((uint32_t)0x000000FF)        /*!< Device feature 1, LPDDR2 Mode Register MR1 */
#define DDRC_LP2MRA_MR2                     ((uint32_t)0x0000FF00)        /*!< Device feature 2, LPDDR2 Mode Register MR2 */
#define DDRC_LP2MRA_MR3                     ((uint32_t)0x00FF0000)        /*!< I/O configure 1, LPDDR2 Mode Register MR3 */

/* ====================  Bit definition for LP2MRB register  ====================== */
#define DDRC_LP2MRB_MR9                     ((uint32_t)0x000000FF)        /*!< Test mode, LPDDR2 Mode Register MR9 */
#define DDRC_LP2MRB_MR10                    ((uint32_t)0x0000FF00)        /*!< I/O calibration, LPDDR2 Mode Register MR10  */

/* ====================  Bit definition for LP2MRC register  ====================== */
#define DDRC_LP2MRC_MR16                    ((uint32_t)0x000000FF)        /*!< PASR_Bank, LPDDR2 Mode Register MR16 */
#define DDRC_LP2MRC_MR17                    ((uint32_t)0x0000FF00)        /*!< PASR_Seg, LPDDR2 Mode Register MR17 */

/* ====================  Bit definition for LP2MRD register  ====================== */
#define DDRC_LP2MRD_MR41                    ((uint32_t)0x000000FF)        /*!< Reserved */
#define DDRC_LP2MRD_MR42                    ((uint32_t)0x0000FF00)        /*!< Reserved */
#define DDRC_LP2MRD_MR48                    ((uint32_t)0x00FF0000)        /*!< Reserved */

/* ====================  Bit definition for LP2MRE register  ====================== */
#define DDRC_LP2MRE_MR63                    ((uint32_t)0x000000FF)        /*!< Reset, LPDDR2 Mode Register MR63 */

/* ====================  Bit definition for LP2MRCR register  ====================== */
#define DDRC_LP2MRCR_MRCMD                  ((uint32_t)0x00000003)        /*!< LP Mode Register command */
#define DDRC_LP2MRCR_MRSEL                  ((uint32_t)0x0000FF00)        /*!< Target Mode Register for MRW/MRR */
#define DDRC_LP2MRCR_RANKSEL                ((uint32_t)0x00010000)        /*!< Target rank for MRW/MRR */
#define DDRC_LP2MRCR_MRRBYTESEL             ((uint32_t)0x03000000)        /*!< MRR command latch byte select */

/* ====================  Bit definition for LP2MRVR register  ====================== */
#define DDRC_LP2MRVR_MRRVAL                 ((uint32_t)0x000000FF)        /*!< Mode register read value */
#define DDRC_LP2MRVR_MRRVALID               ((uint32_t)0x80000000)        /*!< MRR value valid */

/* ====================  Bit definition for LP2ADLR register  ====================== */
#define DDRC_LP2ADLR_WLSEL                  ((uint32_t)0x00000001)        /*!< LPDDR2 write latency select */
#define DDRC_LP2ADLR_RLSEL                  ((uint32_t)0x00000002)        /*!< LPDDR2 read latency select */

/* ====================  Bit definition for LP2WCR1 register  ====================== */
#define DDRC_LP2WCR1_WAITVAL                ((uint32_t)0x000FFFFF)        /*!< LPDDR2 1us wait cycle in the initial sequence */

/* ====================  Bit definition for LP2WCR2 register  ====================== */
#define DDRC_LP2WCR2_WAITVAL                ((uint32_t)0x000FFFFF)        /*!< LPDDR2 10us wait cycle in the initial sequence */

/* ====================  Bit definition for REARBDISR register  ====================== */
#define DDRC_REARBDISR_CH0ARBDISCNT         ((uint32_t)0x00000007)        /*!< Re-arbitration disable counter of channel 0 */
#define DDRC_REARBDISR_CH1ARBDISCNT         ((uint32_t)0x00000070)        /*!< Re-arbitration disable counter of channel 1 */
#define DDRC_REARBDISR_CH2ARBDISCNT         ((uint32_t)0x00000700)        /*!< Re-arbitration disable counter of channel 2 */
#define DDRC_REARBDISR_CH3ARBDISCNT         ((uint32_t)0x00007000)        /*!< Re-arbitration disable counter of channel 3 */

/* ====================  Bit definition for PHYRDTFR register  ====================== */
#define DDRC_PHYRDTFR_BYTE0DLRDFALL         ((uint32_t)0x0000000F)        /*!< Delay setting of byte 0 to adjust the falling-edge delay of DQS or DQ for read */
#define DDRC_PHYRDTFR_BYTE1DLRDFALL         ((uint32_t)0x000000F0)        /*!< Delay setting of byte 1 to adjust the falling-edge delay of DQS or DQ for read */
#define DDRC_PHYRDTFR_BYTE2DLRDFALL         ((uint32_t)0x00000F00)        /*!< Delay setting of byte 2 to adjust the falling-edge delay of DQS or DQ for read */
#define DDRC_PHYRDTFR_BYTE3DLRDFALL         ((uint32_t)0x0000F000)        /*!< Delay setting of byte 3 to adjust the falling-edge delay of DQS or DQ for read */

/* ====================  Bit definition for PHYMISCR2 register  ====================== */
#define DDRC_PHYMISCR2_RONMDCMD             ((uint32_t)0x00000007)        /*!< The driving impedance setting of DDR I/O CMD */
#define DDRC_PHYMISCR2_RONMDCK              ((uint32_t)0x00000070)        /*!< The driving impedance setting of DDR I/O CK */
#define DDRC_PHYMISCR2_RONMDDQ              ((uint32_t)0x00000700)        /*!< The driving impedance setting of DDR I/O DQ */
#define DDRC_PHYMISCR2_RONMDDQS             ((uint32_t)0x00007000)        /*!< The driving impedance setting of DDR I/O DQS */
#define DDRC_PHYMISCR2_EYERDLVL             ((uint32_t)0x00010000)        /*!< Eye margin check of DQ for DQS latch */
#define DDRC_PHYMISCR2_RDLVLGATE            ((uint32_t)0x00020000)        /*!< MSDLY margin check */
#define DDRC_PHYMISCR2_CMDDLSEL             ((uint32_t)0x00700000)        /*!< DRAM command/address versus CK position adjustment */
#define DDRC_PHYMISCR2_ODTMODEWR            ((uint32_t)0x0F000000)        /*!< Write command ODT output option */
#define DDRC_PHYMISCR2_ODTMODERD            ((uint32_t)0xF0000000)        /*!< Read command ODT output option */

/* ====================  Bit definition for EFIFOCR register  ====================== */
#define DDRC_EFIFOCR_CMDSYNCPOS             ((uint32_t)0x00000003)        /*!< Command elastic FIFO synchronization position for MClk to POSTCTLCLK */
#define DDRC_EFIFOCR_RDSYNCPOS              ((uint32_t)0x0000000C)        /*!< Read data elastic FIFO synchronization position for POSTCTLCLK to MClk */
#define DDRC_EFIFOCR_AUTORSTSRF             ((uint32_t)0x00000010)        /*!< Automatically reset elastic FIFO when self-refresh state is entered */
#define DDRC_EFIFOCR_EFIFORST               ((uint32_t)0x00000100)        /*!< Writing to this bit will trigger elastic FIFO reset, this bit will be self-cleared */

/* ====================  Bit definition for B8PHYCR register  ====================== */
#define DDRC_B8PHYCR_MSDLY                  ((uint32_t)0x0000000F)        /*!< Programmable read DQS filtering window for byte 8 */
#define DDRC_B8PHYCR_RLHWDIS                ((uint32_t)0x00000010)        /*!< Read-leveling hardware disable for byte 8 */
#define DDRC_B8PHYCR_WLHWDIS                ((uint32_t)0x00000020)        /*!< Write-leveling hardware disable for byte 8 */
#define DDRC_B8PHYCR_DQSSEL                 ((uint32_t)0x00000040)        /*!< Add a delay in DQ or DQS, the delay value is controlled by BYTE8_DLSEL_RD */
#define DDRC_B8PHYCR_DQSSELWR               ((uint32_t)0x00000080)        /*!< Add a delay in DQ or DQS, the delay value is controlled by BYTE8_DLSEL_WR */
#define DDRC_B8PHYCR_PDLSET                 ((uint32_t)0x00007F00)        /*!< Programmable DLL delay for byte 8 */
#define DDRC_B8PHYCR_WLPASS                 ((uint32_t)0x00008000)        /*!< Byte 8 of the write-leveling status */
#define DDRC_B8PHYCR_DLSELRD                ((uint32_t)0x000F0000)        /*!< Delay value control to add a delay into read DQS or read DQ */
#define DDRC_B8PHYCR_DLSELRDFALL            ((uint32_t)0x00F00000)        /*!< Delay setting of byte 8 to adjust the falling-edge delay of DQS or DQ for read */
#define DDRC_B8PHYCR_BLSELWR                ((uint32_t)0x0F000000)        /*!< Delay control for byte 8 to add a delay in DQS or DQ  */
#define DDRC_B8PHYCR_RLPASS                 ((uint32_t)0x80000000)        /*!< Read-leveling status for byte 8 */

/* ====================  Bit definition for ECCCTRLR register  ====================== */
#define DDRC_ECCCTRLR_ECCEN                 ((uint32_t)0x00000001)        /*!< ECC enable */
#define DDRC_ECCCTRLR_FORCEERR              ((uint32_t)0x00000006)        /*!< Insert error at the ECC encoder output */
#define DDRC_ECCCTRLR_ECCINTDIS             ((uint32_t)0x00000008)        /*!< ECC interrupt disenable */
#define DDRC_ECCCTRLR_RMWRDECCDIS           ((uint32_t)0x00000010)        /*!< Read data ECC correction during RMW operation disable */
#define DDRC_ECCCTRLR_CH0RMWLOCKEN          ((uint32_t)0x00000100)        /*!< Channel 0 Lock read to write commands during RMW operation enable */
#define DDRC_ECCCTRLR_CH1RMWLOCKEN          ((uint32_t)0x00000200)        /*!< Channel 1 Lock read to write commands during RMW operation enable */
#define DDRC_ECCCTRLR_CH2RMWLOCKEN          ((uint32_t)0x00000400)        /*!< Channel 2 Lock read to write commands during RMW operation enable */
#define DDRC_ECCCTRLR_CH3RMWLOCKEN          ((uint32_t)0x00000800)        /*!< Channel 3 Lock read to write commands during RMW operation enable */

/* ====================  Bit definition for ECCINTCR register  ====================== */
#define DDRC_ECCINTCR_STAT                  ((uint32_t)0x00000001)        /*!< ECC interrupt status */

/* ====================  Bit definition for ECCCHR register  ====================== */
#define DDRC_ECCCHR_ERRCHN                  ((uint32_t)0x00000007)        /*!< The first occurred ECC error channel */

/* ====================  Bit definition for ECCEAR register  ====================== */
#define DDRC_ECCEAR_ERRADDR                 ((uint32_t)0xFFFFFFFF)        /*!< The first occurred ECC error address */

/* ====================  Bit definition for ECCEBPLR register  ====================== */
#define DDRC_ECCEBPLR_POSLOW                ((uint32_t)0xFFFFFFFF)        /*!< 32 bit error bit position in low bytes */

/* ====================  Bit definition for ECCEBPHR register  ====================== */
#define DDRC_ECCEBPHR_POSHIGH               ((uint32_t)0xFFFFFFFF)        /*!< 32 bit error bit position in high bytes */

/* ====================  Bit definition for ECCERR1CNTR register  ====================== */
#define DDRC_ECCERR1CNTR_ERRCNT             ((uint32_t)0xFFFFFFFF)        /*!< ECC one bit error counts */

/* ====================  Bit definition for ECCERR2CNTR register  ====================== */
#define DDRC_ECCERR2CNTR_ERRCNT             ((uint32_t)0x00000000)        /*!< ECC two bit error counts */

/* ====================  Bit definition for PHYCFG0 register  ====================== */
#define DDRC_PHYCFG0_HWSRFREQ               ((uint32_t)0x00000001)        /*!< Hardware self-refresh request */
#define DDRC_PHYCFG0_CH0HIP                 ((uint32_t)0x00000002)        /*!< Channel 0 External high priority signal */
#define DDRC_PHYCFG0_CH1HIP                 ((uint32_t)0x00000004)        /*!< Channel 1 External high priority signal */
#define DDRC_PHYCFG0_CH2HIP                 ((uint32_t)0x00000008)        /*!< Channel 2 External high priority signal */
#define DDRC_PHYCFG0_CH3HIP                 ((uint32_t)0x00000010)        /*!< Channel 3 External high priority signal */
#define DDRC_PHYCFG0_CTDEL                  ((uint32_t)0x000007C0)        /*!< The programmable delay controll bits */
#define DDRC_PHYCFG0_CTSKEW                 ((uint32_t)0x00003800)        /*!< The skew control bits used to adjust */
#define DDRC_PHYCFG0_DUTYSEL                ((uint32_t)0x0003C000)        /*!< The CK/CKB adjusting bits */
#define DDRC_PHYCFG0_SIO                    ((uint32_t)0x00040000)        /*!< DQS in the single-ended mode or differential mode selection */
#define DDRC_PHYCFG0_DLLPDN                 ((uint32_t)0x00080000)        /*!< DLL power-down control */
#define DDRC_PHYCFG0_DLLFRANGE              ((uint32_t)0x00700000)        /*!< DLL reference frequency selection */
#define DDRC_PHYCFG0_CONUPDATE              ((uint32_t)0x00800000)        /*!< Continuous enable update code of DLL */
#define DDRC_PHYCFG0_LEAKAGE0               ((uint32_t)0x01000000)        /*!< I/O leakage mode */
#define DDRC_PHYCFG0_LEAKAGE1               ((uint32_t)0x02000000)        /*!< I/O leakage mode */
#define DDRC_PHYCFG0_LEAKAGE2               ((uint32_t)0x04000000)        /*!< I/O leakage mode */
#define DDRC_PHYCFG0_LEAKAGE3               ((uint32_t)0x08000000)        /*!< I/O leakage mode */
#define DDRC_PHYCFG0_LEAKAGE4               ((uint32_t)0x10000000)        /*!< I/O leakage mode */

/* ====================  Bit definition for PHYCFG1 register  ====================== */
#define DDRC_PHYCFG1_BYONE                  ((uint32_t)0x00000001)        /*!< Byone mode */
#define DDRC_PHYCFG1_DDR3EN                 ((uint32_t)0x00000002)        /*!< DDR3 mode enable */
#define DDRC_PHYCFG1_MDDREN                 ((uint32_t)0x00000004)        /*!< MDDR(LPDDR) mode enable */
#define DDRC_PHYCFG1_PHYCLKEN               ((uint32_t)0x00000008)        /*!< DDR PHY internal clock enable */
#define DDRC_PHYCFG1_VREF_SEL               ((uint32_t)0x00000070)        /*!< Bias voltage generated by PHY for VREF */
#define DDRC_PHYCFG1_IO15V                  ((uint32_t)0x00000080)        /*!< I/O voltage selection */
#define DDRC_PHYCFG1_DSRONB                 ((uint32_t)0x00000100)        /*!< Power control signal for keeping CKE[1:0] */
#define DDRC_PHYCFG1_LPDDR2EN               ((uint32_t)0x00000200)        /*!< LPDDR2 mode enable */
#define DDRC_PHYCFG1_SELFBIASEN             ((uint32_t)0x00000000)        /*!< Self-bias generation enalbe */

/* ====================  Bit definition for PHYCFG2 register  ====================== */
#define DDRC_PHYCFG3_CTDEL4                 ((uint32_t)0x0000001F)        /*!< The programmable delay control bits */
#define DDRC_PHYCFG3_CTSKEW4                ((uint32_t)0x000000E0)        /*!< The control bits used to adjust the skew */
#define DDRC_PHYCFG3_CLKEN0                 ((uint32_t)0x00000100)        /*!< DDR PHY internal clock Enable */
#define DDRC_PHYCFG3_CLKEN1                 ((uint32_t)0x00000200)        /*!< DDR PHY internal clock ENABLE */
#define DDRC_PHYCFG3_CLKEN2                 ((uint32_t)0x00000400)        /*!< DDR PHY internal clock ENABLE */
#define DDRC_PHYCFG3_CLKEN3                 ((uint32_t)0x00000800)        /*!< DDR PHY internal clock ENABLE */
#define DDRC_PHYCFG3_CLKEN4                 ((uint32_t)0x00001000)        /*!< DDR PHY internal clock ENABLE */
#define DDRC_PHYCFG3_PLLPDN                 ((uint32_t)0x00002000)        /*!< PLL power-down control */
#define DDRC_PHYCFG3_PLLRST                 ((uint32_t)0x00004000)        /*!< DDR pll sw reset */
#define DDRC_PHYCFG3_PHYRST                 ((uint32_t)0x00008000)        /*!< DDR phy reset */
#define DDRC_PHYCFG3_MRST                   ((uint32_t)0x00010000)        /*!< DDR Mreset */
#define DDRC_PHYCFG3_DPHYRST                ((uint32_t)0x00020000)        /*!< DDR dphy reset */

/* =========================================================================================================================== */
/* ================                            Flexible Memory Controller                                    ================= */
/* =========================================================================================================================== */
/* ====================  Bits definition for DMA_SxCNDTR register  ====================== */
#define DMA_SxCTR_EN                        ((uint32_t)0x00010000)

/* =========================================================================================================================== */
/* ================                           Flex Memory Cotroller                                          ================= */
/* =========================================================================================================================== */
/* ====================== Bit definition for SMC_AR register =================== */
#define FMC_AR_ADDRESS                      ((uint32_t)0xFFFFFFFF)        /*!< ADDRESS[31:0]: Address */

/* ====================== Bit definition for FMC_CCR register =================== */
#define FMC_CCR_CONTI_READ_EN               ((uint32_t)0x10000000)        /*!< Continuous Mode Enable */
#define FMC_CCR_INSTR_LEN                   ((uint32_t)0x03000000)        /*!< Instruction Length */
#define FMC_CCR_INSTR_LEN_1                 ((uint32_t)0x01000000)        /*!< Instruction Length: 1 Byte */
#define FMC_CCR_INSTR_LEN_2                 ((uint32_t)0x02000000)        /*!< Instruction Length: 2 Byte */
#define FMC_DCY                             ((uint32_t)0x00FF0000)        /*!< Dummy[2:0]: Address Size */
#define FMC_CCR_ADSIZE                      ((uint32_t)0x00000007)        /*!< ADSIZE[2:0]: Address Size */
#define FMC_CCR_ADSIZE_1                    ((uint32_t)0x00000001)        /*!< Bit 0 */
#define FMC_CCR_ADSIZE_2                    ((uint32_t)0x00000002)        /*!< Bit 1 */
#define FMC_CCR_ADSIZE_3                    ((uint32_t)0x00000003)        /*!< Bit 2 */
#define FMC_CCR_ADSIZE_4                    ((uint32_t)0x00000004)        /*!< Bit 2 */

/* ====================== Bit definition for FMC_DLR register =================== */
#define   FMC_DLR                           ((uint32_t)0xFFFFFFFF)        /*!< DL[31:0]: Data Length */
/* ====================== Bit definition for FMC_CCR2 register =================== */
#define FMC_CCR2_INSTRUCTION                ((uint32_t)0xFF000000)        /*!< INSTRUCTION[7:0]: Instruction */
#define FMC_CCR2_CRM_INSTRUCTION            ((uint32_t)0xFF000000)        /*!< Continuous Read Mode Instruction[7:0]: Instruction */
#define FMC_CCR2_IO_MODE_EN                 ((uint32_t)0x00000400)        /*!< IO Mode Enable */
#define FMC_CCR2_CS                         ((uint32_t)0x00000300)        /*!< Chip Select[1:0]: CS */
#define FMC_CCR2_OP_MODE                    ((uint32_t)0x000000E0)        /*!< SPI Operate Mode Mode[3:0]: Mode */
#define FMC_CCR2_OP_MODE_111                ((uint32_t)0x00000000)        /*!< Mode: 1-1-1 */
#define FMC_CCR2_OP_MODE_114                ((uint32_t)0x00000040)        /*!< Mode: 1-1-4 */
#define FMC_CCR2_OP_MODE_144                ((uint32_t)0x00000080)        /*!< Mode: 1-4-4 */
#define FMC_CCR2_OP_MODE_444                ((uint32_t)0x00000060)        /*!< Mode: 4-4-4 */
#define FMC_CCR2_OP_MODE_118                ((uint32_t)0x000000A0)        /*!< Mode: 1-1-8 */
#define FMC_CCR2_OP_MODE_188                ((uint32_t)0x000000C0)        /*!< Mode: 1-8-8 */
#define FMC_CCR2_OP_MODE_888                ((uint32_t)0x000000E0)        /*!< Mode: 8-8-8 */
#define FMC_CCR2_DDRM_EN                    ((uint32_t)0x00000010)        /*!< DTR Enable */
#define FMC_CCR2_READ_STATUS_BY_SW          ((uint32_t)0x00000008)        /*!< Read Status By SW */
#define FMC_CCR2_READ_STATUS_EN             ((uint32_t)0x00000004)        /*!< Read Status Enable */
#define FMC_CCR2_WRITE_EN                   ((uint32_t)0x00000002)        /*!< Write Enable */

/* ====================== Bit definition for FMC_CR register =================== */
#define FMC_CR_PORT_SELECT                  ((uint32_t)0x00100000)        /*!< Port selection */
#define FMC_CR_BUSY_BIT_STS                 ((uint32_t)0x000E0000)        /*!< BUSY_BIT_STS[2:0]: BusyBitStatus*/
#define FMC_CR_DTR_MODE_SELECT              ((uint32_t)0x00000200)        /*!< Psram DTR mode OB/OC interface select */
#define FMC_CR_ABORT                        ((uint32_t)0x00000100)        /*!< Abort request */
#define FMC_CR_XPORT_STS                    ((uint32_t)0x00000080)        /*!< XIP port idle status */
#define FMC_CR_DQSM_EN                      ((uint32_t)0x00000040)        /*!< DQS/DM enable */
#define FMC_CR_CLK_EDGE                     ((uint32_t)0x00000020)        /*!< Clock edge latch */
#define FMC_CR_DEV_TYPE                     ((uint32_t)0x0000000C)        /*!< DEV_TYPE[1:0]: Device type */

/* ====================== Bit definition for FMC_ACTR register =================== */
#define FMC_ACTR_DLL_POWER_DOWN             ((uint32_t)0x00000800)        /*!< DLL power down */
#define FMC_ACTR_DLL_SELECT                 ((uint32_t)0x00000700)        /*!< DLL_SELECT[2:0]: DLL Select */
#define FMC_ACTR_CS_DELAY                   ((uint32_t)0x0000000F)        /*!< CS_DELAY[3:0]: CS delay */

/* ====================== Bit definition for FMC_SR register =================== */
#define FMC_SR_TXFIFO_RDY                   ((uint32_t)0x00000001)        /*!< Transfer Tx FIFO Ready     */
#define FMC_SR_RXFIFO_RDY                   ((uint32_t)0x00000002)        /*!< Transfer Rx FIFO Ready     */

/* ====================== Bit definition for FMC_ICR register =================== */
#define FMC_ICR_RX_FIFO_TRIGGER             ((uint32_t)0x00003000)        /*!< RX_FIFO_TRIGGER [1:0]: RxFIFO threshold*/
#define FMC_ICR_TX_FIFO_TRIGGER             ((uint32_t)0x00000300)        /*!< TX_FIFO_TRIGGER [1:0]: TxFIFO threshold*/
#define FMC_ICR_XIP_WERR_INTR_EN            ((uint32_t)0x00000004)        /*!< XIP write data error interrupt enable */
#define FMC_ICR_CMD_CMPLT_INTR_EN           ((uint32_t)0x00000002)        /*!< Command complete interrupt enable */
#define FMC_ICR_DMAEN                       ((uint32_t)0x00000001)        /*!< DMA handshake enable */

/* ====================== Bit definition for FMC_ISR register =================== */
#define FMC_ISR_XIPW_EF                     ((uint32_t)0x00000002)        /*!< XIP Write Transfer Error Flag     */
#define FMC_ISR_TCF                         ((uint32_t)0x00000001)        /*!< Transfer Complete Flag  */

/* ====================== Bit definition for FMC_SPISR register =================== */
#define FMC_SPISR                           ((uint32_t)0x000000FF)        /*!< Status of norflash  */

/* ====================== Bit definition for FMC_SIZE register =================== */
#define FMC_SIZE                            ((uint32_t)0xFFFFFFFF)        /*!< flash/psram size */

/* ====================== Bit definition for FMC_XIPCR0 register =================== */
#define FMC_XIP_RDTR                        ((uint32_t)0x80000000)        /*!< XIP read data DTR mode */
#define FMC_XIP_CS                          ((uint32_t)0x60000000)        /*!< XIPCR0_CS[1:0] */
#define FMC_XIP_IO_MODE_EN                  ((uint32_t)0x10000000)        /*!< XIP IO mode enable */
#define FMC_XIP_IO_MODE_INSTRUCTION         ((uint32_t)0x0FF00000)        /*!< IO_MODE_INSTRUCTION[7:0]: XIP IO mode code */
#define FMC_XIP_RD_INSTRUCTION              ((uint32_t)0x000FF000)        /*!< RD_INSTRUCTION[7:0]: XIP read data Instruction code */
#define FMC_XIP_ADDR_LEN_4BYTE              ((uint32_t)0x00000800)        /*!< SPI address length for XIP port */
#define FMC_XIP_RD_MODE                     ((uint32_t)0x00000700)        /*!< XIPCR0_RD_MODE[2:0]: XIP SPI read data operate mode */
#define FMC_XIP_DUMMY_CYCLE                 ((uint32_t)0x000000FF)        /*!< XIPCR0_DUMMY_CYCLE[7:0]: Second dummy state cycle for XIP port */

/* ====================== Bit definition for FMC_XIPCR1 register =================== */
#define FMC_XIPCR1_RSTS_DUMMY               ((uint32_t)0x0FF00000)        /*!< XIPCR1_RSTS_DUMMY[7:0]: XIP channel read status dummy cycle */
#define FMC_XIPCR1_WEN_INSTRUCTION          ((uint32_t)0x000FF000)        /*!< XIPCR1_WEN_INSTRUCTION[7:0]: XIP channel write enable instruction code */
#define FMC_XIPCR1_RSTS_INSTRUCTION         ((uint32_t)0x00000FF0)        /*!< XIPCR1_RSTS_INTRUCTION[7:0]: XIP channel read status instruction code */
#define FMC_XIPCR1_WE                       ((uint32_t)0x00000008)        /*!< XIP channel write data allow */
#define FMC_XIPCR1_BYPASS_CACHE             ((uint32_t)0x00000001)        /*!< Bypass cache function */

/* ====================== Bit definition for FMC_XIPCR2 register =================== */
#define FMC_XIPCR2_DTR_EN                   ((uint32_t)0x00080000)        /*!< XIP write data DTR mode */
#define FMC_XIPCR2_WD_MODE                  ((uint32_t)0x00070000)        /*!< XIPCR2_WD_MODE[2:0] XIP SPI write data operate mode */
#define FMC_XIPCR2_WD_DUMMY                 ((uint32_t)0x0000FF00)        /*!< XIPCR2_WD_DUMMY[7:0] XIP channel write data dummy cycle */
#define FMC_XIPCR2_WD_INSTRUCTION           ((uint32_t)0x000000FF)        /*!< XIPCR2_WD_INSTRUCTION[7:0] XIP channel write data instruction code */

/* ====================== Bit definition for FMC_FEATURE register =================== */
#define FMC_FEATURE_RXFIFO_DEPTH            ((uint32_t)0x0003FE00)        /*!< FEATURE_RXFIFO_DEPTH[8:0]: RXFIFO depth */
#define FMC_FEATURE_TXFIFO_DEPTH            ((uint32_t)0x000001FF)        /*!< FEATURE_TXFIFO_DEPTH[8:0]: TXFIFO depth */

/* ====================== Bit definition for FMC_DR register =================== */
#define FMC_DR_DATA                         ((uint32_t)0xFFFFFFFF)        /*!< DATA[31:0]: Data */

/* ====================== Bit definition for PSRAM init register =================== */
#define FMC_PSRAM_INIT_ACTR                 ((uint32_t)0x00000104)        /* !< ACTR value for PSRAM */
#define FMC_PSRAM_INIT_ICR                  ((uint32_t)0x00000000)        /* !< ICR value for PSRAM */
#define FMC_PSRAM_INIT_SPIFSR               ((uint32_t)0x02000000)        /* !< Memory size register value for PSRAM */
#define FMC_PSRAM_INIT_XIPCR0               ((uint32_t)0x800A0F11)        /* !< Config XIP0 for PSRAM */
#define FMC_PSRAM_INIT_XIPCR1               ((uint32_t)0x00000009)        /* !< Config XIP1 for PSRAM */
#define FMC_PSRAM_INIT_XIPCR2               ((uint32_t)0x000F0F20)        /* !< Config XIP2 for PSRAM */
#define FMC_PSRAM_INIT_CR0                  ((uint32_t)0x000002D4)        /* !< Config CR for PSRAM */

#define FMC_PSRAM_INIT0_CMD0                ((uint32_t)0x00040000)        /* !< Command 0 config PSRAM mode register */
#define FMC_PSRAM_INIT0_CMD1                ((uint32_t)0x01000004)        /* !< Command 1 config PSRAM mode register */
#define FMC_PSRAM_INIT0_CMD2                ((uint32_t)0x00000002)        /* !< Command 2 config PSRAM mode register */
#define FMC_PSRAM_INIT0_CMD3                ((uint32_t)0x400000FA)        /* !< Command 3 config PSRAM mode register */
#define FMC_PSRAM_INIT0_DATA0               ((uint8_t)0xF0)               /* !< Data 0 config PSRAM mode */
#define FMC_PSRAM_INIT0_DATA1               ((uint8_t)0x5A)               /* !< Date 1 config PSRAM mode */

#define FMC_PSRAM_INIT_RCMD0                ((uint32_t)0x00040000)        /* !< Command 0 read psram mode */
#define FMC_PSRAM_INIT_RCMD1                ((uint32_t)0x01100004)        /* !< Command 1 read psram mode */
#define FMC_PSRAM_INIT_RCMD2                ((uint32_t)0x00000002)        /* !< Command 2 read PSRAM mode */
#define FMC_PSRAM_INIT_RCMD3                ((uint32_t)0xC00000F8)        /* !< Command 3 read psram mode */

#define FMC_PSRAM_INIT_CR1                  ((uint32_t)0x001002D4)        /* !< Control 1 for PSRAM */

#define FMC_PSRAM_INIT_AFR2_MASK            ((uint32_t)0x00000007)        /* !< AFR 2 mask for PSRAM */
#define FMC_PSRAM_INIT_AFR2                 ((uint32_t)0x1B6DB6D8)        /* !< AFR 2 for PSRAM */
#define FMC_PSRAM_INIT_AFR3                 ((uint32_t)0x0000001B)        /* !< AFR 2 for PSRAM */
#define FMC_PSRAM_INIT_DC                   ((uint32_t)0x000001F7)        /* !< DC for PSRAM */

/* ====================== Bit definition for norflash init register =================== */
#define FMC_NOR_INIT_ACTR                   ((uint32_t)0x00001034)        /* !< ACTR value for Norflash initial */
#define FMC_NOR_INIT_ICR                    ((uint32_t)0x00000000)        /* !< ICR value for Norflash initial */
#define FMC_NOR_INIT_SPIFSR                 ((uint32_t)0x00400000)        /* !< Memory size register value for Norflash initial */
#define FMC_NOR_INIT_XIPCR0                 ((uint32_t)0x000EB406)        /* !< XIP 0 for Norflash initial */
#define FMC_NOR_INIT_XIPCR1                 ((uint32_t)0x00000001)        /* !< XIP 1 for Norflash initial */
#define FMC_NOR_INIT_XIPCR2                 ((uint32_t)0x00000000)        /* !< XIP 2 for Norflash initial */
#define FMC_NOR_INIT_CR0                    ((uint32_t)0x00100090)        /* !< Contorl 0 for Norflash initial */
#define FMC_NOR_INIT_CMD0                   ((uint32_t)0x00000000)        /* !< Command 0 Norflash enable quad */
#define FMC_NOR_INIT_CMD1                   ((uint32_t)0x01000000)        /* !< Command 1 Norflash enable quad */
#define FMC_NOR_INIT_CMD2                   ((uint32_t)0x00000001)        /* !< Command 2 Norflash enable quad */
#define FMC_NOR_INIT_CMD3                   ((uint32_t)0x3100000A)        /* !< Command 3 Norflash enable quad */
#define FMC_NOR_INIT_ECMD0                  ((uint32_t)0x00000000)        /* !< Command 0 Norflash write enable */
#define FMC_NOR_INIT_ECMD1                  ((uint32_t)0x01000000)        /* !< Command 1 Norflash write enable */
#define FMC_NOR_INIT_ECMD2                  ((uint32_t)0x00000000)        /* !< Command 2 Norflash write enable */
#define FMC_NOR_INIT_ECMD3                  ((uint32_t)0x0600000A)        /* !< Command 3 Norflash write enable */
#define FMC_NOR_INIT_RSCMD0                 ((uint32_t)0x00000000)        /* !< Command 0 Norflash read status */
#define FMC_NOR_INIT_RSCMD1                 ((uint32_t)0x01000000)        /* !< Command 1 Norflash read status */
#define FMC_NOR_INIT_RSCMD2                 ((uint32_t)0x00000000)        /* !< Command 2 Norflash read status */
#define FMC_NOR_INIT_RSCMD3                 ((uint32_t)0x05000004)        /* !< Command 3 Norflash read status */
#define FMC_NOR_INIT_DP                     ((uint8_t) 0x02)              /* !< Data Norflash enable quad */

/* =========================================================================================================================== */
/* ================                                           GMAC                                           ================= */
/* =========================================================================================================================== */
/* ====================== Bit definition for CTRL register ====================== */
#define GMAC_CTRL_SW_RST                    ((uint32_t)0x80000000)        /*!< Software reset */
#define GMAC_CTRL_FULLDUP                   ((uint32_t)0x04000000)        /*!< Full duplex */
#define GMAC_CTRL_SPEED                     ((uint32_t)0x03000000)        /*!< Speed bit mask */
#define GMAC_CTRL_IFG                       ((uint32_t)0x00800000)        /*!< Frame gap incress bit */
#define GMAC_CTRL_IFG_CNT                   ((uint32_t)0x00700000)        /*!< Frame gap incress or decress count */
#define GMAC_CTRL_LOOPBACK                  ((uint32_t)0x00080000)        /*!< Loopback mode */
#define GMAC_CTRL_PTP_EN                    ((uint32_t)0x00040000)        /*!< PTP function enable */
#define GMAC_CTRL_TX_PAD                    ((uint32_t)0x00020000)        /*!< Pad frame that size lower than 64 bytes to 64 bytes */
#define GMAC_CTRL_APPEND_CRC                ((uint32_t)0x00008000)        /*!< Append CRC to frame */
#define GMAC_CTRL_JUMBO_LONG                ((uint32_t)0x00002000)        /*!< Enable send and receiving frame with length more than 1514 bytes */
#define GMAC_CTRL_RX_RUNT                   ((uint32_t)0x00001000)        /*!< Enable receiving frame with length less than 64 bytes */
#define GMAC_CTRL_RX_ALL_BCST_EN            ((uint32_t)0x00000800)        /*!< Enable receiving broadcast frame */
#define GMAC_CTRL_RX_ALL_MCST_EN            ((uint32_t)0x00000400)        /*!< Enable receiving multicast frame */
#define GMAC_CTRL_RX_HASH_MCAST_EN          ((uint32_t)0x00000200)        /*!< Enable receiving multicast frame that pass the HASH filters */
#define GMAC_CTRL_L4_FLT_EN                 ((uint32_t)0x00000080)        /*!< Enable port filter */
#define GMAC_CTRL_L3_FLT_EN                 ((uint32_t)0x00000040)        /*!< Enable IP address filter */
#define GMAC_CTRL_L2_FLT_EN                 ((uint32_t)0x00000010)        /*!< Enable MAC address filter */
#define GMAC_CTRL_RXMAC_EN                  ((uint32_t)0x00000008)        /*!< Enable GMAC rx */
#define GMAC_CTRL_TXMAC_EN                  ((uint32_t)0x00000004)        /*!< Enable GMAC tx */
#define GMAC_CTRL_RXDMA_EN                  ((uint32_t)0x00000002)        /*!< Enable GMAC rx DMA */
#define GMAC_CTRL_TXDMA_EN                  ((uint32_t)0x00000001)        /*!< Enable GMAC Tx DMA */

/* ====================== Bit definition for FDPX register ====================== */
#define GMAC_FDPX_PAUSE_TIME                ((uint32_t)0xffff0000)        /*!< Pause time in the pause frame */
#define GMAC_FDPX_LOW_THR                   ((uint32_t)0x0000FE00)        /*!< RX fifo low threshold */
#define GMAC_FDPX_HIGH_THR                  ((uint32_t)0x000001FC)        /*!< RX fifi high threashold  */
#define GMAC_FDPX_TX_PAUSE_FRAME            ((uint32_t)0x00000002)        /*!< Transmit pause frame */
#define GMAC_FDPX_EN                        ((uint32_t)0x00000001)        /*!< Enable flow control for full duplex mode */

/* ====================== Bit definition for HDPX register ====================== */
#define GMAC_HDPX_LOW_THR                   ((uint32_t)0x00007F00)        /*!< RX fifo low threshold */
#define GMAC_HDPX_JAM_LEN                   ((uint32_t)0x000000f0)        /*!< Jam length */
#define GMAC_HDPX_PATTERN_ALL               ((uint32_t)0x00000002)        /*!< Jam pattern */
#define GMAC_HDPX_EN                        ((uint32_t)0x00000001)        /*!< Enable flow control for half duplex mode */

/* ====================== Bit definition for GMAC_DMAFIFOSTS register ====================== */
#define GMAC_DMA_FIFO_STS_TX_FIFO_EMPTY     ((uint32_t)0x08000000)        /*!< TX fifo is empty flag */
#define GMAC_DMA_FIFO_STS_RX_FIFO_EMPTY     ((uint32_t)0x04000000)        /*!< RX fifo is empty flag */

/* ====================== Bit definition for GMAC_WOLCR register ====================== */
#define GMAC_WOLCR_OUTPUT_SIGNAL            ((uint32_t)0x3000000)         /*!< WOL signal type bit mask */

/* ====================== Bit definition for PTPTMR1 register ====================== */
// #define GMAC_PTP_TMR1(x) ((x & 0x3fffffff) << 0)

/* ====================== Bit definition for GMAC_PTPOFF register ====================== */
#define GMAC_PTP_OFF_INC_CYC                ((uint32_t)0xffff0000)        /*!< PTP period cycle offset */
#define GMAC_PTP_OFF_NS_OFF                 ((uint32_t)0x0000ffff)        /*!< PTP time offset  */

/* ====================== Bit definition for GMAC_PTPADJ register ====================== */
#define GMAC_PTP_ADJ_ADD                    ((uint32_t)0x80000000)        /*!< adjust ptp time by add time offset  */

/* ====================== Bit definition for GMAC_PHYIF register ====================== */
#define GMAC_PHY_IF_GMII                    ((uint32_t)0x00000000)        /*!< GMII interface */
#define GMAC_PHY_IF_RGMII                   ((uint32_t)0x00000002)        /*!< RGMII interface */

/* ====================== Bit definition for GMAC_PHYCR register ====================== */
#define GMAC_MDIO_SOF                       ((uint32_t)0x00000001)        /*!< start of the MDIO frame */
#define GMAC_MDIO_EXT_SOF                   ((uint32_t)0x00000000)        /*!< start of the externed MDIO frame */
#define GMAC_MDIO_OP_RD                     ((uint32_t)0x00000002)        /*!< MDIO read */
#define GMAC_MDIO_OP_WR                     ((uint32_t)0x00000001)        /*!< MDIO write */
#define GMAC_MDIO_OP_ADR                    ((uint32_t)0x00000000)        /*!< MDIO device address */
#define GMAC_PHYCR_PHYWR                    ((uint32_t)0x08000000)        /*!< PHY write sequence */
#define GMAC_PHYCR_PHYRD                    ((uint32_t)0x04000000)        /*!< PHY read sequence */
#define GMAC_PHYCR_REGAD                    ((uint32_t)0x03e00000)        /*!< PHY register address */
#define GMAC_PHYCR_PHYAD                    ((uint32_t)0x001f0000)        /*!< PHY device address */
#define GMAC_PHYCR_OP                       ((uint32_t)0x0000c000)        /*!< Operation code bit mask */
#define GMAC_PHYCR_SOF                      ((uint32_t)0x00003000)        /*!< Bit mask of SOF */
#define GMAC_PHYCR_CYCTHR                   ((uint32_t)0x000000ff)        /*!< MDIO clock cycle */

/* ====================== Bit definition for GMAC_PHYDATA register ====================== */
#define GMAC_PHYDATA_RDATA                  ((uint32_t)0xffff0000)        /*!< Result of MIDO read */
#define GMAC_PHYDATA_WDATA                  ((uint32_t)0x0000ffff)        /*!< Value to be writen for MDIO write */

/* ====================== Bit definition for MFCR register ====================== */
#define GMAC_L2_REDR_EN                     ((uint32_t)0x00400000)        /*!< Frame redirection */
#define GMAC_L2_FLT_INV                     ((uint32_t)0x00020000)        /*!< Drop or Receive frames that pass the filter */
#define GMAC_L2_FLT_DA                      ((uint32_t)0x00010000)        /*!< Destination mac address filter */

/* ====================== Bit definition for RSSCR register ====================== */
#define GMAC_RSS_EN                         ((uint32_t)0x00000001)        /*!< Enable RSS */

/* ====================== Bit definition for GMAC_TQWBCR register ====================== */
#define GMAC_TQ_WB_THR                      ((uint32_t)0x000f0000)        /*!< Collected frame number before TX descriptors writen back */
#define GMAC_TQ_WB_TIMEOUT                  ((uint32_t)0x0000ffff)        /*!< Waited time before TX descriptors writen back */

/* ====================== Bit definition for GMAC_RQWBCR register ====================== */
#define GMAC_RQ_WB_THR                      ((uint32_t)0x000f0000)        /*!< Collected frame number before RX descriptors writen back */
#define GMAC_RQ_WB_TIMEOUT                  ((uint32_t)0x0000ffff)        /*!< Waited time before RX descriptors writen back */

/* ====================== Bit definition for GMAC_QPAIRCR register ====================== */
#define GMAC_QPAIR_CTRL_RX_EN               ((uint32_t)0x00000010)        /*!< Enable RX queue */
#define GMAC_QPAIR_CTRL_TX_EN               ((uint32_t)0x00000008)        /*!< Enable TX queue */

/* ====================== Bit definition for TXITC register ====================== */
#define GMAC_INT_UNIT_1                     ((uint32_t)0x00000000)        /*!< Uint is 1 frame */
#define GMAC_INT_UNIT_4                     ((uint32_t)0x00000001)        /*!< Uint is 4 frames */
#define GMAC_INT_UNIT_16                    ((uint32_t)0x00000002)        /*!< Uint is 16 frames */
#define GMAC_INT_UNIT_64                    ((uint32_t)0x00000003)        /*!< Uint is 64 frames */
#define GMAC_TXINT_THR                      ((uint32_t)0x00000070)        /*!< Max frame number before TX interrupt is triggered */
#define GMAC_TXINT_UNIT                     ((uint32_t)0x00000003)        /*!< Unit selected */

/* ====================== Bit definition for RXITC register ====================== */
#define GMAC_RXINT_THR                      ((uint32_t)0x00000070)        /*!< Max frame number before RX interrupt is triggered */
#define GMAC_RXINT_UNIT                     ((uint32_t)0x00000003)        /*!< Unit selected */

/* ====================== Bit definition for RDSR register ====================== */
#define GMAC_RX_DESC_SZ                     ((uint32_t)0x0000f000)        /*!< Word number of each RX descriptor */
#define GMAC_RX_DESC_CNT                    ((uint32_t)0x00000fff)        /*!< Number of RX descriptor */

/* ====================== Bit definition for RXR_BADR_L register ====================== */
#define GMAC_RX_RING_BASE_L                 ((uint32_t)0xffffffff)        /*!< Lower word of RX ring base address */

/* ====================== Bit definition for RXR_BADR_H register ====================== */
#define GMAC_RX_RING_BASE_H                 ((uint32_t)0x0000ffff)        /*!< High word of RX ring base address */

/* ====================== Bit definition for TDSR register ====================== */
#define GMAC_TX_DESC_SZ                     ((uint32_t)0x0000f000)        /*!< Word number of each TX descriptor */
#define GMAC_TX_DESC_CNT                    ((uint32_t)0x00000fff)        /*!< Number of TX descriptor */

/* ====================== Bit definition for TXR_BADR_L register ====================== */
#define GMAC_TX_RING_BASE_L                 ((uint32_t)0xffffffff)        /*!< Lower word of TX ring base address */

/* ====================== Bit definition for TXR_BADR_H register ====================== */
#define GMAC_TX_RING_BASE_H                 ((uint32_t)0x0000ffff)        /*!< High word of TX ring base address */

/* ====================== Bit definition for EEECTRL register ====================== */
#define GMAC_EEE_CTRL_TX_LPI                ((uint32_t)0x00010000)        /*!< Send LPI */
#define GMAC_EEE_CTRL_WU_CNT                ((uint32_t)(0x0000ffff))      /*!< EEE wakeup counter */

/* ====================== Bit definition for TQBCR register ====================== */
#define GMAC_TQ_BUF_CTRL_TIMEOUT            ((uint32_t)0xffff0000)        /*!< Timeout vaule for TX descriptor perfetch */
#define GMAC_TQ_BUF_CTRL_DES_THR            ((uint32_t)0x0000f000)        /*!< Descriptor threshold for TX descriptor prefetch */
#define GMAC_TQ_BUF_CTRL_BUF_THR            ((uint32_t)0x00000f00)        /*!< Buffer size threshold for TX descriptor prefetch */
#define GMAC_TQ_BUF_CTRL_BUF_SZ             ((uint32_t)0x000000ff)        /*!< Word number of each TX descriptor */

/* ====================== Bit definition for RQBCR register ====================== */
#define GMAC_RQ_BUF_CTRL_TIMEOUT            ((uint32_t)0xffff0000)        /*!< Timeout vaule for RX descriptor perfetch */
#define GMAC_RQ_BUF_CTRL_DES_THR            ((uint32_t)0x0000f000)        /*!< Descriptor threshold for RX descriptor prefetch */
#define GMAC_RQ_BUF_CTRL_BUF_THR            ((uint32_t)0x00000f00)        /*!< Buffer size threshold for RX descriptor prefetch */
#define GMAC_RQ_BUF_CTRL_BUF_SZ             ((uint32_t)0x000000ff)        /*!< Word number of each RX descriptor */

/* TXDES3 */
#define GMAC_TXDES3_TXBUF_BADRH             ((uint32_t)0x0000ffff)        /*!< TX buffer address high bits mask */

/* TXDES4 */
#define GMAC_TXDES4_TXBUF_BADRL             ((uint32_t)0xffffffff)        /*!< TX buffer address low bits mask */

/* RXDES2 */
#define GMAC_RXDES2_RXBUF_BADRH             ((uint32_t)0x0000ffff)        /*!< RX buffer address high bits mask */

/* RXDES3 */
#define GMAC_RXDES3_RXBUF_BADRL             ((uint32_t)0xffffffff)        /*!< RX buffer address low bits mask */

/* =========================================================================================================================== */
/* ================                            General Purpose I/O                                           ================= */
/* =========================================================================================================================== */
/* ============================== Bit definition for GPIO_OUT register =================================== */
/*!< GPIO Output value */
#define GPIO_OUT                            ((uint32_t)0xFFFFFFFF)        /*!< GPIO output value */

/* ============================== Bit definition for GPIO_IN register =================================== */
/*!< GPIO Input Value */
#define GPIO_IN                             ((uint32_t)0xFFFFFFFF)        /*!< GPIO input value */

/* ============================== Bit definition for GPIO_DIR register =================================== */
/*!< GPIO Direction set */
#define GPIO_DIR                            ((uint32_t)0xFFFFFFFF)        /*!< GPIO Direction set */

/* ============================== Bit definition for GPIO_SET register =================================== */
/*!< GPIO Data Set */
#define GPIO_SET                            ((uint32_t)0xFFFFFFFF)        /*!< GPIO Data Set */

/* ============================== Bit definition for GPIO_CLR register =================================== */
/*!< GPIO Data Clear */
#define GPIO_CLR                            ((uint32_t)0xFFFFFFFF)        /*!< GPIO Data clear */

/* ============================== Bit definition for GPIO_IER register =================================== */
/*!< GPIO Interrput enable */
#define GPIO_IER                            ((uint32_t)0xFFFFFFFF)        /*!< GPIO Interrput enable */

/* ============================== Bit definition for GPIO_IRS register =================================== */
/*!< GPIO Interrput raw state */
#define GPIO_IRS                            ((uint32_t)0xFFFFFFFF)        /*!< GPIO Interrput raw state */

/* ============================== Bit definition for GPIO_IMS register =================================== */
/*!< GPIO Interrput masked state */
#define GPIO_IMS                            ((uint32_t)0xFFFFFFFF)        /*!< GPIO Interrput masked state */

/* ============================== Bit definition for GPIO_IM register =================================== */
/*!< GPIO Interrput masked */
#define GPIO_IM                             ((uint32_t)0xFFFFFFFF)        /*!< GPIO Interrput masked */

/* ============================== Bit definition for GPIO_ICLR register =================================== */
/*!< GPIO Interrput clear */
#define GPIO_ICL                            ((uint32_t)0xFFFFFFFF)        /*!< GPIO Interrput clear */

/* ============================== Bit definition for GPIO_TMR register =================================== */
/*!< GPIO Trigger mode configuration */
#define GPIO_TMR                            ((uint32_t)0xFFFFFFFF)        /*!< GPIO Trigger mode configuration */

/* ============================== Bit definition for GPIO_TER register =================================== */
/*!< GPIO Trigger edge configuration */
#define GPIO_TER                            ((uint32_t)0xFFFFFFFF)        /*!< GPIO Trigger edge configuration */

/* ============================== Bit definition for GPIO_TRFR register =================================== */
/*!< GPIO Trigger rise or fail configuration */
#define GPIO_TRFR                           ((uint32_t)0xFFFFFFFF)        /*!< GPIO Trigger rise or fail configuration */

/* ============================== Bit definition for GPIO_DBCR register =================================== */
/*!< GPIO Debounce configuration */
#define GPIO_DBCR                           ((uint32_t)0xFFFFFFFF)        /*!< GPIO Debounce configuration */

/* ============================== Bit definition for GPIO_DBCCNT register =================================== */
/*!< GPIO Debounce Count */
#define GPIO_DBCCNT                         ((uint32_t)0xFFFFFFFF)        /*!< GPIO Debounce Count*/


/* ============================== Bit definition for GPIOA_AF0 register =================================== */
/*!< GPIOA Alternate Function group0 Configuration  */
#define GPIOA_AF0R                          ((uint32_t)0xFFFFFFFF)        /*!< GPIOA Alternate Function group0 Configuration */

#define GPIOA_AF0R_0                        ((uint32_t)0x00000007)
#define GPIOA_AF0R_1                        ((uint32_t)0x00000038)
#define GPIOA_AF0R_2                        ((uint32_t)0x000001C0)
#define GPIOA_AF0R_3                        ((uint32_t)0x00000E00)
#define GPIOA_AF0R_4                        ((uint32_t)0x00007000)
#define GPIOA_AF0R_5                        ((uint32_t)0x00038000)
#define GPIOA_AF0R_6                        ((uint32_t)0x001C0000)
#define GPIOA_AF0R_7                        ((uint32_t)0x00E00000)
#define GPIOA_AF0R_8                        ((uint32_t)0x07000000)
#define GPIOA_AF0R_9                        ((uint32_t)0x38000000)

/* ============================== Bit definition for GPIOA_AF1 register =================================== */
/*!< GPIOA Alternate Function group1 Configuration  */
#define GPIOA_AF1R                          ((uint32_t)0xFFFFFFFF)        /*!< GPIOA Alternate Function group1 Configuration */

#define GPIOA_AF1R_10                       ((uint32_t)0x00000007)
#define GPIOA_AF1R_11                       ((uint32_t)0x00000038)
#define GPIOA_AF1R_12                       ((uint32_t)0x000001C0)
#define GPIOA_AF1R_13                       ((uint32_t)0x00000E00)
#define GPIOA_AF1R_14                       ((uint32_t)0x00007000)
#define GPIOA_AF1R_15                       ((uint32_t)0x00038000)
#define GPIOA_AF1R_16                       ((uint32_t)0x001C0000)
#define GPIOA_AF1R_17                       ((uint32_t)0x00E00000)
#define GPIOA_AF1R_18                       ((uint32_t)0x07000000)
#define GPIOA_AF1R_19                       ((uint32_t)0x38000000)

/* ============================== Bit definition for GPIOA_AF2 register =================================== */
/*!< GPIOA Alternate Function group2 Configuration  */
#define GPIOA_AF2R                          ((uint32_t)0xFFFFFFFF)        /*!< GPIOA Alternate Function group2 Configuration */

#define GPIOA_AF2R_20                       ((uint32_t)0x00000007)
#define GPIOA_AF2R_21                       ((uint32_t)0x00000038)
#define GPIOA_AF2R_22                       ((uint32_t)0x000001C0)
#define GPIOA_AF2R_23                       ((uint32_t)0x00000E00)
#define GPIOA_AF2R_24                       ((uint32_t)0x00007000)
#define GPIOA_AF2R_25                       ((uint32_t)0x00038000)
#define GPIOA_AF2R_26                       ((uint32_t)0x001C0000)
#define GPIOA_AF2R_27                       ((uint32_t)0x00E00000)
#define GPIOA_AF2R_28                       ((uint32_t)0x07000000)
#define GPIOA_AF2R_29                       ((uint32_t)0x38000000)

/* ============================== Bit definition for GPIOA_AF3 register =================================== */
/*!< GPIOA Alternate Function group3 Configuration  */
#define GPIOA_AF3R                          ((uint32_t)0xFFFFFFFF)        /*!< GPIOA Alternate Function group2 Configuration */

#define GPIOA_AF3R_30                       ((uint32_t)0x00000007)
#define GPIOA_AF3R_31                       ((uint32_t)0x00000038)

/* ============================== Bit definition for GPIOB_AF0 register =================================== */
/*!< GPIOB Alternate Function group0 Configuration  */
#define GPIOB_AF0R                          ((uint32_t)0xFFFFFFFF)        /*!< GPIOB Alternate Function group0 Configuration */

#define GPIOB_AF0R_0                        ((uint32_t)0x00000007)
#define GPIOB_AF0R_1                        ((uint32_t)0x00000038)
#define GPIOB_AF0R_2                        ((uint32_t)0x000001C0)
#define GPIOB_AF0R_3                        ((uint32_t)0x00000E00)
#define GPIOB_AF0R_4                        ((uint32_t)0x00007000)
#define GPIOB_AF0R_5                        ((uint32_t)0x00038000)
#define GPIOB_AF0R_6                        ((uint32_t)0x001C0000)
#define GPIOB_AF0R_7                        ((uint32_t)0x00E00000)
#define GPIOB_AF0R_8                        ((uint32_t)0x07000000)
#define GPIOB_AF0R_9                        ((uint32_t)0x38000000)

/* ============================== Bit definition for GPIOB_AF1 register =================================== */
/*!< GPIOB Alternate Function group1 Configuration  */
#define GPIOB_AF1R                          ((uint32_t)0xFFFFFFFF)        /*!< GPIOA Alternate Function group1 Configuration */

#define GPIOB_AF1R_10                       ((uint32_t)0x00000007)
#define GPIOB_AF1R_11                       ((uint32_t)0x00000038)
#define GPIOB_AF1R_12                       ((uint32_t)0x000001C0)
#define GPIOB_AF1R_13                       ((uint32_t)0x00000E00)
#define GPIOB_AF1R_14                       ((uint32_t)0x00007000)
#define GPIOB_AF1R_15                       ((uint32_t)0x00038000)
#define GPIOB_AF1R_16                       ((uint32_t)0x001C0000)
#define GPIOB_AF1R_17                       ((uint32_t)0x00E00000)
#define GPIOB_AF1R_18                       ((uint32_t)0x07000000)
#define GPIOB_AF1R_19                       ((uint32_t)0x38000000)

/* ============================== Bit definition for GPIOB_AF2 register =================================== */
/*!< GPIOB Alternate Function group2 Configuration  */
#define GPIOB_AF2R                          ((uint32_t)0xFFFFFFFF)        /*!< GPIOB Alternate Function group2 Configuration */

#define GPIOB_AF2R_20                       ((uint32_t)0x00000007)
#define GPIOB_AF2R_21                       ((uint32_t)0x00000038)
#define GPIOB_AF2R_22                       ((uint32_t)0x000001C0)
#define GPIOB_AF2R_23                       ((uint32_t)0x00000E00)
#define GPIOB_AF2R_24                       ((uint32_t)0x00007000)
#define GPIOB_AF2R_25                       ((uint32_t)0x00038000)
#define GPIOB_AF2R_26                       ((uint32_t)0x001C0000)
#define GPIOB_AF2R_27                       ((uint32_t)0x00E00000)
#define GPIOB_AF2R_28                       ((uint32_t)0x07000000)
#define GPIOB_AF2R_29                       ((uint32_t)0x38000000)

/* ============================== Bit definition for GPIOB_AF3 register =================================== */
/*!< GPIOB Alternate Function group3 Configuration  */
#define GPIOB_AF3R                          ((uint32_t)0xFFFFFFFF)        /*!< GPIOB Alternate Function group2 Configuration */

#define GPIOB_AF3R_30                       ((uint32_t)0x00000007)
#define GPIOB_AF3R_31                       ((uint32_t)0x00000038)


/* ============================== Bit definition for GPIOC_AF0 register =================================== */
/*!< GPIOC Alternate Function group0 Configuration  */
#define GPIOC_AF0R                          ((uint32_t)0xFFFFFFFF)        /*!< GPIOC Alternate Function group0 Configuration */

#define GPIOC_AF0R_0                        ((uint32_t)0x00000007)
#define GPIOC_AF0R_1                        ((uint32_t)0x00000038)
#define GPIOC_AF0R_2                        ((uint32_t)0x000001C0)
#define GPIOC_AF0R_3                        ((uint32_t)0x00000E00)
#define GPIOC_AF0R_4                        ((uint32_t)0x00007000)
#define GPIOC_AF0R_5                        ((uint32_t)0x00038000)
#define GPIOC_AF0R_6                        ((uint32_t)0x001C0000)
#define GPIOC_AF0R_7                        ((uint32_t)0x00E00000)
#define GPIOC_AF0R_8                        ((uint32_t)0x07000000)
#define GPIOC_AF0R_9                        ((uint32_t)0x38000000)

/* ============================== Bit definition for GPIOC_AF1 register =================================== */
/*!< GPIOC Alternate Function group1 Configuration  */
#define GPIOC_AF1R                          ((uint32_t)0xFFFFFFFF)        /*!< GPIOA Alternate Function group1 Configuration */

#define GPIOC_AF1R_10                       ((uint32_t)0x00000007)
#define GPIOC_AF1R_11                       ((uint32_t)0x00000038)
#define GPIOC_AF1R_12                       ((uint32_t)0x000001C0)
#define GPIOC_AF1R_13                       ((uint32_t)0x00000E00)
#define GPIOC_AF1R_14                       ((uint32_t)0x00007000)
#define GPIOC_AF1R_15                       ((uint32_t)0x00038000)
#define GPIOC_AF1R_16                       ((uint32_t)0x001C0000)
#define GPIOC_AF1R_17                       ((uint32_t)0x00E00000)
#define GPIOC_AF1R_18                       ((uint32_t)0x07000000)
#define GPIOC_AF1R_19                       ((uint32_t)0x38000000)

/* ============================== Bit definition for GPIOC_AF2 register =================================== */
/*!< GPIOC Alternate Function group2 Configuration  */
#define GPIOC_AF2R                          ((uint32_t)0xFFFFFFFF)        /*!< GPIOC Alternate Function group2 Configuration */

#define GPIOC_AF2R_20                       ((uint32_t)0x00000007)
#define GPIOC_AF2R_21                       ((uint32_t)0x00000038)
#define GPIOC_AF2R_22                       ((uint32_t)0x000001C0)
#define GPIOC_AF2R_23                       ((uint32_t)0x00000E00)
#define GPIOC_AF2R_24                       ((uint32_t)0x00007000)
#define GPIOC_AF2R_25                       ((uint32_t)0x00038000)
#define GPIOC_AF2R_26                       ((uint32_t)0x001C0000)
#define GPIOC_AF2R_27                       ((uint32_t)0x00E00000)
#define GPIOC_AF2R_28                       ((uint32_t)0x07000000)
#define GPIOC_AF2R_29                       ((uint32_t)0x38000000)

/* ============================== Bit definition for GPIOC_AF3 register =================================== */
/*!< GPIOC Alternate Function group3 Configuration  */
#define GPIOC_AF3R                          ((uint32_t)0xFFFFFFFF)        /*!< GPIOC Alternate Function group2 Configuration */
#define GPIOC_AF3R_30                       ((uint32_t)0x00000007)
#define GPIOC_AF3R_31                       ((uint32_t)0x00000038)

/* ============================== Bit definition for GPIOA_PU register =================================== */
/*!< GPIOA Pull Up Configuration  */
#define GPIOA_PU                            ((uint32_t)0xFFFFFFFF)        /*!< GPIOA Pull Up Configuration */

/* ============================== Bit definition for GPIOA_PD register =================================== */
/*!< GPIOA Pull Down Configuration  */
#define GPIOA_PD                            ((uint32_t)0xFFFFFFFF)        /*!< GPIOA Pull Down Configuration */

/* ============================== Bit definition for GPIOB_PU register =================================== */
/*!< GPIOB Pull Up Configuration  */
#define GPIOB_PU                            ((uint32_t)0xFFFFFFFF)        /*!< GPIOB Pull Up Configuration */

/* ============================== Bit definition for GPIOB_PD register =================================== */
/*!< GPIOB Pull Down Configuration  */
#define GPIOB_PD                            ((uint32_t)0xFFFFFFFF)        /*!< GPIOB Pull Down Configuration */

/* ============================== Bit definition for GPIOC_PU register =================================== */
/*!< GPIOC Pull Up Configuration  */
#define GPIOC_PU                            ((uint32_t)0xFFFFFFFF)        /*!< GPIOC Pull Up Configuration */

/* ============================== Bit definition for GPIOC_PD register =================================== */
/*!< GPIOC Pull Down Configuration  */
#define GPIOC_PD                            ((uint32_t)0xFFFFFFFF)        /*!< GPIOC Pull Down Configuration */

/* ============================== Bit definition for GPIOA_DRV0 register =================================== */
/*!< GPIOA driver strength sel0 Configuration  */
#define GPIOA_DRV0R                         ((uint32_t)0xFFFFFFFF)        /*!< GPIOA Driver Strength sel0 Configuration */

/* ============================== Bit definition for GPIOA_DRV1 register =================================== */
/*!< GPIOA driver strength sel1 Configuration  */
#define GPIOA_DRV1R                         ((uint32_t)0xFFFFFFFF)        /*!< GPIOA Driver Strength sel1 Configuration */

/* ============================== Bit definition for GPIOB_DRV0 register =================================== */
/*!< GPIOB driver strength sel0 Configuration  */
#define GPIOB_DRV0R                         ((uint32_t)0xFFFFFFFF)        /*!< GPIOB Driver Strength sel0 Configuration */

/* ============================== Bit definition for GPIOB_DRV1 register =================================== */
/*!< GPIOB driver strength sel1 Configuration  */
#define GPIOB_DRV1R                         ((uint32_t)0xFFFFFFFF)        /*!< GPIOB Driver Strength sel1 Configuration */

/* ============================== Bit definition for GPIOC_DRV0 register =================================== */
/*!< GPIOC driver strength sel0 Configuration  */
#define GPIOC_DRV0R                         ((uint32_t)0xFFFFFFFF)        /*!< GPIOC Driver Strength sel0 Configuration */

/* ============================== Bit definition for GPIOC_DRV1 register =================================== */
/*!< GPIOC driver strength sel1 Configuration  */
#define GPIOC_DRV1R                         ((uint32_t)0xFFFFFFFF)        /*!< GPIOC Driver Strength sel1 Configuration */

/* ============================== Bit definition for GPIOA_SMT register =================================== */
/*!< GPIOA SMT Configuration  */
#define GPIOA_SMTR                          ((uint32_t)0xFFFFFFFF)        /*!< GPIOA SMT Configuration */

/* ============================== Bit definition for GPIOB_SMT register =================================== */
/*!< GPIOB SMT Configuration  */  
#define GPIOB_SMTR                          ((uint32_t)0xFFFFFFFF)        /*!< GPIOB SMT Configuration */

/* ============================== Bit definition for GPIOC_SMT register =================================== */
/*!< GPIOC SMT Configuration  */
#define GPIOC_SMTR                          ((uint32_t)0xFFFFFFFF)        /*!< GPIOC SMT Configuration */

/* ============================== Bit definition for GPIOC_LS3V register =================================== */
/*!< GPIOC LS3V Configuration  */
#define GPIOC_LS3VR                         ((uint32_t)0xFFFFFFFF)        /*!< GPIOC LS3V Configuration */


/* =========================================================================================================================== */
/* ================                          Hardware Security Module (HSM)                                  ================= */
/* =========================================================================================================================== */
/* ============================== Bit definition for HSM_QC register =================================== */
#define HSM_QC_QE                           ((uint32_t)0x00000001)        /*!< Queue enable */

/* ============================== Bit definition for HSM_QIER register =================================== */
#define HSM_QIER_QD                         ((uint32_t)0x00000001)        /*!< Queue done Interrupt Enable */

/* ============================== Bit definition for HSM_QISR register =================================== */
#define HSM_QISR_QD                         ((uint32_t)0x00000001)        /*!< Queue done Interrupt */

/* ============================== Bit definition for HSM_QLSR register =================================== */
#define HSM_QLSR_BUSY                       ((uint32_t)0x00000002)        /*!< Kernel Busy */


/* =========================================================================================================================== */
/* ================                            Inter-integrated Circuit Interface                            ================= */
/* =========================================================================================================================== */
/* ============================== Bit definition for CR register =================================== */
#define I2C_CR_BURST_CTRL_EN                ((uint32_t)0x03000000)        /*!< for burst mode */
#define I2C_CR_SBI_EN                       ((uint32_t)0x00200000)        /*!< start byte detects interrupt enable */
#define I2C_CR_HSI_EN                       ((uint32_t)0x00100000)        /*!< HS-mode detects interrupt enable */
#define I2C_CR_HS_MODE                      ((uint32_t)0x00080000)        /*!< HS-mode enable */
#define I2C_CR_ARB_OFF                      ((uint32_t)0x00040000)        /*!< ignore the arbitration lose detection */
#define I2C_CR_TEST_BIT                     ((uint32_t)0x00020000)        /*!< special test mode */
#define I2C_CR_STARTI_EN                    ((uint32_t)0x00004000)        /*!< start condition detects interrupt enable */
#define I2C_CR_ALI_EN                       ((uint32_t)0x00002000)        /*!< arbitration lose interrupt enable */
#define I2C_CR_SAMI_EN                      ((uint32_t)0x00001000)        /*!< slave address matches interrupt enable */
#define I2C_CR_STOPI_EN                     ((uint32_t)0x00000800)        /*!< stop condition detects interrupt enable */
#define I2C_CR_NACKI_EN                     ((uint32_t)0x00000400)        /*!< non-ACK responses detects interrupt enable */
#define I2C_CR_TDI_EN                       ((uint32_t)0x00000200)        /*!< transfer data complete interrupt enable */
#define I2C_CR_BSTTHODI_EN                  ((uint32_t)0x00000100)        /*!< read data reaches the threshold interrupt enable */
#define I2C_CR_TB_EN                        ((uint32_t)0x00000080)        /*!< transfer byte enable */
#define I2C_CR_NACK                         ((uint32_t)0x00000040)        /*!< acknowledge signal control */
#define I2C_CR_STOP                         ((uint32_t)0x00000020)        /*!< stop condition control */
#define I2C_CR_START                        ((uint32_t)0x00000010)        /*!< start condition control */
#define I2C_CR_GC_EN                        ((uint32_t)0x00000008)        /*!< general call enable */
#define I2C_CR_MST_EN                       ((uint32_t)0x00000004)        /*!< master mode enable */
#define I2C_CR_I2C_EN                       ((uint32_t)0x00000002)        /*!< i2c controller enable */
#define I2C_CR_I2C_RST                      ((uint32_t)0x00000001)        /*!< i2c controller reset */

/* ============================== Bit definition for SR register =================================== */
#define I2C_SR_SBS                          ((uint32_t)0x00800000)        /*!< start byte detected status */
#define I2C_SR_HSS                          ((uint32_t)0x00400000)        /*!< HS-mode detected status */
#define I2C_SR_START                        ((uint32_t)0x00000800)        /*!< start condition detected */
#define I2C_SR_AL                           ((uint32_t)0x00000400)        /*!< arbitration lose */
#define I2C_SR_GC                           ((uint32_t)0x00000200)        /*!< matches the general-call address */
#define I2C_SR_SAM                          ((uint32_t)0x00000100)        /*!< slave address matches */
#define I2C_SR_STOP                         ((uint32_t)0x00000080)        /*!< stop condition detected */
#define I2C_SR_NACK                         ((uint32_t)0x00000040)        /*!< non-ACK responses detected */
#define I2C_SR_TD                           ((uint32_t)0x00000020)        /*!< transfer completed */
#define I2C_SR_BSTTHOD_SR                   ((uint32_t)0x00000010)        /*!< read data reaches the threshold */
#define I2C_SR_BB                           ((uint32_t)0x00000008)        /*!< i2c bus is busy, but the i2c controller is not involved in the transaction */
#define I2C_SR_I2CB                         ((uint32_t)0x00000004)        /*!< i2c controller is busy */
#define I2C_SR_RW                           ((uint32_t)0x00000001)        /*!< indicate the i2c controller services in the RX or TX mode */

/* ============================== Bit definition for CDR register ================================== */
#define I2C_CDR_DUTY_OFFSET                 ((uint32_t)0xF0000000)        /*!< clock division register of duty value */
#define I2C_CDR_COUNTH                      ((uint32_t)0x0FF00000)        /*!< clock division register of counter value in HS-mode */
#define I2C_CDR_COUNT                       ((uint32_t)0x000FFFFF)        /*!< clock division register of counter value in F/S-mode */

/* ============================== Bit definition for AR register =================================== */
#define I2C_AR_MEM_IDX2                     ((uint32_t)0xFF000000)        /*!< second transmitted index for master RX/TX burst mode */
#define I2C_AR_MEM_IDX1                     ((uint32_t)0x00FF0000)        /*!< first transmitted index for master RX/TX burst mode */
#define I2C_AR_M2BIDX_EN                    ((uint32_t)0x00002000)        /*!< set to 1 to transfer second index bytes */
#define I2C_AR_ADDR10EN                     ((uint32_t)0x00001000)        /*!< set to 1 to transfer second index bytes */
#define I2C_AR_ADDR2                        ((uint32_t)0x00000380)        /*!< the most significant 3-bit address */
#define I2C_AR_ADDR                         ((uint32_t)0x0000007F)        /*!< the least significant 7-bit address */

/* ============================== Bit definition for TGSR register ================================= */
#define I2C_TGSR_GSR                        ((uint32_t)0x00003C00)        /*!< glitch suppression logic value */
#define I2C_TGSR_TSR                        ((uint32_t)0x000003FF)        /*!< delay values of the PCLK clock cycles between SCL and SDA */

/* ============================== Bit definition for BMR register ================================= */
#define I2C_BMR_SCLIN                       ((uint32_t)0x00000002)        /*!< this bit continuously reflects the value of the SCLin pin */
#define I2C_BMR_SDAIN                       ((uint32_t)0x00000001)        /*!< this bit continuously reflects the value of the SDAin pin */

/* ============================== Bit definition for BSTMR register =============================== */
#define I2C_BSTMR_BUFHW                     ((uint32_t)0x00070000)        /*!< buffer depth in burst mode */
#define I2C_BSTMR_BSTTDC                    ((uint32_t)0x0000FF00)        /*!< total burst data count */
#define I2C_BSTMR_BSTTHOD                   ((uint32_t)0x000000FF)        /*!< burst threshold, only valid in the master RX burst mode */

/* =========================================================================================================================== */
/* ================                           Low Power sub-system                                           ================= */
/* =========================================================================================================================== */
/* ====================== Bit definition for LP_RCCL_RCR register ================================== */
#define LPRCCL_RCR_UART0RST                 ((uint32_t)0x00000002)        /*!< UART0 Software Reset */
#define LPRCCL_RCR_GPIODRST                 ((uint32_t)0x00000004)        /*!< GPIOD Software Reset */
#define LPRCCL_RCR_I2C0RST                  ((uint32_t)0x00000008)        /*!< I2C0 Software Reset */
#define LPRCCL_RCR_CANA0RST                 ((uint32_t)0x00000010)        /*!< CANA0 Software Reset */
#define LPRCCL_RCR_RETRAMRST                ((uint32_t)0x00000020)        /*!< RETRAM Software Reset */
#define LPRCCL_RCR_AXI2APBRST               ((uint32_t)0x00000040)        /*!< AXI2APB Software Reset */

/* =================  Bit definition for LP_RCCL_CCR register  ====================== */
#define LPRCCL_CCR_UART0CLKEN               ((uint32_t)0x00000002)        /*!< UART0 Clock Enable */
#define LPRCCL_CCR_GPIODCLKEN               ((uint32_t)0x00000004)        /*!< GPIOD Clock Enable */
#define LPRCCL_CCR_I2C0CLKEN                ((uint32_t)0x00000008)        /*!< I2C0 Clock Enable */
#define LPRCCL_CCR_CANB0CLKEN               ((uint32_t)0x00000010)        /*!< CANB0 Clock Enable */
#define LPRCCL_CCR_RETRAMCLKEN              ((uint32_t)0x00000020)        /*!< RETRAM Clock Enable */
#define LPRCCL_CCR_AXI2APBCLKEN             ((uint32_t)0x00000040)        /*!< AXI2APB Clock Enable */

/* =================  Bit definition for LP_RCCL_ModuleDIV register  =================== */
#define LPRCCL_APBDIVR_APBDIV               ((uint32_t)0x000000FF)        /*!< LP APB Clock Divider Value */
#define LPRCCL_UART0DIVR_UART0DIV           ((uint32_t)0x000000FF)        /*!< UART0 Clock Divider Value */
#define LPRCCL_CANB0DIVR_CANA0DIV           ((uint32_t)0x000000FF)        /*!< CANA0 Clock Divider Value */

/* ================= Bit definition for LP_SYSCFGL_SCR register ======================= */
#define LPSYSCFGL_SCR_LPCCLKSEL             ((uint32_t)0x00000001)        /*!< LP system clock select */
#define LPSYSCFGL_SCR_APBCLKSEL             ((uint32_t)0x00000002)        /*!< LPC APB clock select */
#define LPSYSCFGL_SCR_UART0CLKSEL           ((uint32_t)0x00000004)        /*!< UART0 clock select */
#define LPSYSCFGL_SCR_CANA0CLKSEL           ((uint32_t)0x00000008)        /*!< CANA0 clock select */
#define LPSYSCFGL_SCR_MASTERSEL             ((uint32_t)0x00000010)        /*!< LP mater configuration */

/* ======================= Bit definition for LP_SYSCFGL_RAR register ================== */
#define LPSYSCFGL_RAR_VAL                   ((uint32_t)0xFFFFFFFF)        /*!< LP N101 reset address configuration */

/* ====================  Bit definition for LP_SYSCFGL_RRECR register  ====================== */
#define LPSYSCFGL_RRECR_ECCEN               ((uint32_t)0x00000001)        /*!< Retention RAM ECC Control */

/* ====================  Bit definition for LP_SYSCFGL_RREEAR register  ================== */
#define LPSYSCFGL_RREEAR_VAL                ((uint32_t)0x000FFFFF)        /*!< Retention RAM ECC Error Address */

/* ====================  Bit definition for LP_SYSCFGL_RREECR register  ================= */
#define LPSYSCFGL_RREECR_VAL                ((uint32_t)0x00000007)        /*!< Retention RAM ECC Error Count */

/* =========================================================================================================================== */
/* ================                           LCD-TFT Display Controller                                     ================= */
/* =========================================================================================================================== */
/* ============================== Bit definition for Function Enable register ===================== */
#define LTDC_FER_DOUBLE_EN                  ((uint32_t)0x00020000)        /*!< double word command enable */
#define LTDC_FER_ADDR_SYNC_EN               ((uint32_t)0x00010000)        /*!< address sync enable */
#define LTDC_FER_PAT_GEN                    ((uint32_t)0x00004000)        /*!< test pattern generator */
#define LTDC_FER_PIP_EN                     ((uint32_t)0x00000C00)        /*!< Picture-in-Picture(PiP) mode */
#define LTDC_FER_BLEND_EN                   ((uint32_t)0x00000300)        /*!< alpha blending enable */
#define LTDC_FER_POP_EN                     ((uint32_t)0x00000080)        /*!< Picture-out-Picture(PoP) mode */
#define LTDC_FER_SCALER_EN                  ((uint32_t)0x00000020)        /*!< scaler enable */
#define LTDC_FER_YCBCR_EN                   ((uint32_t)0x00000008)        /*!< YCbCr input mode control */
#define LTDC_FER_YCBCR420_EN                ((uint32_t)0x00000004)        /*!< YCbCr420 input mode control */
#define LTDC_FER_LCD_ON                     ((uint32_t)0x00000002)        /*!< lcd screen on/off control */
#define LTDC_FER_LCD_EN                     ((uint32_t)0x00000001)        /*!< lcd controller enable control */

/* ============================== Bit definition for Panel Pixel Control register ================= */
#define LTDC_PPCR_PRST                      ((uint32_t)0x00080000)        /*!< PCLK domain reset */
#define LTDC_PPCR_LRST                      ((uint32_t)0x00040000)        /*!< LC_CLK domain reset */
#define LTDC_PPCR_MRST                      ((uint32_t)0x00020000)        /*!< Master domain reset(AXI or AHB) */
#define LTDC_PPCR_ADDR_UPDATE               ((uint32_t)0x00010000)        /*!< address update */
#define LTDC_PPCR_UPDATE_SRC                ((uint32_t)0x0000C000)        /*!< update source selection */
#define LTDC_PPCR_PANEL_TYPE                ((uint32_t)0x00000800)        /*!< TFT panel color depth selection */
#define LTDC_PPCR_VCOMP                     ((uint32_t)0x00000600)        /*!< generate the vertical status interrupt */
#define LTDC_PPCR_ENDIAN                    ((uint32_t)0x00000060)        /*!< frame buffer data endianness control */
#define LTDC_PPCR_BGRSW                     ((uint32_t)0x00000010)        /*!< RGB or BGR output format selection */
#define LTDC_PPCR_BPPFIFO                   ((uint32_t)0x00000007)        /*!< pixel format in FIFO */

/* ============================== Bit definition for Interrupt Enable register ==================== */
#define LTDC_IER_INTR_BUSERR_EN             ((uint32_t)0x00000008)        /*!< AXI/AHB master error interrupt enable */
#define LTDC_IER_INTR_VSTATUS_EN            ((uint32_t)0x00000004)        /*!< vertical duration comparision interrupt enable */
#define LTDC_IER_INTR_NXTBASE_EN            ((uint32_t)0x00000002)        /*!< next frame base address updated interrupt enable */
#define LTDC_IER_INTR_FIFOUDN_EN            ((uint32_t)0x00000001)        /*!< FIFO under-run interrupt enable */

/* ============================== Bit definition for Interrupt Status Clear register ============== */
#define LTDC_ISCR_CLR_BUSERR                ((uint32_t)0x00000008)        /*!< clear the AXI/AHB master error interrupt status */
#define LTDC_ISCR_CLR_VSTATUS               ((uint32_t)0x00000004)        /*!< clear the interrupt of vertical duration comparision */
#define LTDC_ISCR_CLR_NXTBASE               ((uint32_t)0x00000002)        /*!< clear the frame buffer base address update interrupt status */
#define LTDC_ISCR_CLR_FIFOUDN               ((uint32_t)0x00000001)        /*!< clear the FIFO under-run interrupt status */

/* ============================== Bit definition for Interrupt Status register ==================== */
#define LTDC_ISR_INT_BUSERR                 ((uint32_t)0x00000008)        /*!< AXI/AHB master error status */
#define LTDC_ISR_INT_VSTATUS                ((uint32_t)0x00000004)        /*!< vertical duration comparision status */
#define LTDC_ISR_INT_NXTBASE                ((uint32_t)0x00000002)        /*!< frame base address update status */
#define LTDC_ISR_INT_FIFOUDN                ((uint32_t)0x00000001)        /*!< FIFO under-run status */

/* ============================== Bit definition for Pattern Bar Generator register =============== */
#define LTDC_PBGR_IMG3PAT_GEN               ((uint32_t)0x000000C0)        /*!< pattern generator of image 3 */
#define LTDC_PBGR_IMG2PAT_GEN               ((uint32_t)0x00000030)        /*!< pattern generator of image 2 */
#define LTDC_PBGR_IMG1PAT_GEN               ((uint32_t)0x0000000C)        /*!< pattern generator of image 1 */
#define LTDC_PBGR_IMG0PAT_GEN               ((uint32_t)0x00000003)        /*!< pattern generator of image 0 */

/* ============================== Bit definition for FIFO Threshold Control register ============== */
#define LTDC_FTCR_BUF3_THRESHOLD            ((uint32_t)0xFF000000)        /*!< DMA buffer 3 threshold */
#define LTDC_FTCR_BUF2_THRESHOLD            ((uint32_t)0x00FF0000)        /*!< DMA buffer 2 threshold */
#define LTDC_FTCR_BUF1_THRESHOLD            ((uint32_t)0x0000FF00)        /*!< DMA buffer 1 threshold */
#define LTDC_FTCR_BUF0_THRESHOLD            ((uint32_t)0x000000FF)        /*!< DMA buffer 0 threshold */

/* ============================== Bit definition for Horizontal Timing Control Parameter register = */
#define LTDC_HTCPR_HBP                      ((uint32_t)0xFF000000)        /*!< horizontal back porch */
#define LTDC_HTCPR_HFP                      ((uint32_t)0x00FF0000)        /*!< horizontal front porch */
#define LTDC_HTCPR_HW                       ((uint32_t)0x0000FF00)        /*!< horizontal synchronization pulses width */
#define LTDC_HTCPR_PL                       ((uint32_t)0x000000FF)        /*!< pixels-per-line */

/* ============================== Bit definition for Vertical Timing Control Parameter register === */
#define LTDC_VTCPR_VFP                      ((uint32_t)0xFF000000)        /*!< vertical front porch */
#define LTDC_VTCPR_VW                       ((uint32_t)0x003F0000)        /*!< vertical synchronization pulses width */
#define LTDC_VTCPR_LF                       ((uint32_t)0x00000FFF)        /*!< lines-per-line */

/* ============================== Bit definition for Vertical Back Porch Parameter register ======= */
#define LTDC_VBPPR_VBP                      ((uint32_t)0x000000FF)        /*!< vertical back porch */

/* ============================== Bit definition for Polarity Control register ==================== */
#define LTDC_PCPR_DIVNO                     ((uint32_t)0x00007F00)        /*!< LCD panel clock divisor control(LC_PCLK) */
#define LTDC_PCPR_IDE                       ((uint32_t)0x00000008)        /*!< LC_DE output pin active control */
#define LTDC_PCPR_ICK                       ((uint32_t)0x00000004)        /*!< LC_PCLK edge control */
#define LTDC_PCPR_IHS                       ((uint32_t)0x00000002)        /*!< LC_HS output pin active control */
#define LTDC_PCPR_IVS                       ((uint32_t)0x00000001)        /*!< LC_VS output pin active control */

/* ============================== Bit definition for PIP Blending register ======================== */
#define LTDC_PIPBR_PIPBLEND_D               ((uint32_t)0x00FF0000)        /*!< alpha blending level of an image with the down priority */
#define LTDC_PIPBR_PIPBLEND_H               ((uint32_t)0x0000FF00)        /*!< alpha blending level of an image with the higher priority */
#define LTDC_PIPBR_PIPBLEND_L               ((uint32_t)0x000000FF)        /*!< alpha blending level of an image with the lower priority */

/* ============================== Bit definition for Sub-Picture1 Position register =============== */
#define LTDC_SP1PR_PIP_UPDATE               ((uint32_t)0x10000000)        /*!< update PiP dimensions and positions registers */
#define LTDC_SP1PR_PIP1_HPOS                ((uint32_t)0x07FF0000)        /*!< specify the horizontal position of the sub-picture1 of PiP window */
#define LTDC_SP1PR_PIP1_VPOS                ((uint32_t)0x000007FF)        /*!< specify the vertical position of the sub-picture1 of PiP window */

/* ============================== Bit definition for Sub-Picture1 Dimension register ============== */
#define LTDC_SP1DR_PIP1_HDIM                ((uint32_t)0x07FF0000)        /*!< specify the horizontal dimension of the sub-picture1 of PiP window */
#define LTDC_SP1DR_PIP1_VDIM                ((uint32_t)0x000007FF)        /*!< specify the vertical dimension of the sub-picture1 of PiP window */

/* ============================== Bit definition for Sub-Picture2 Position register =============== */
#define LTDC_SP2PR_PIP2_HPOS                ((uint32_t)0x07FF0000)        /*!< specify the horizontal position of the sub-picture2 of PiP window */
#define LTDC_SP2PR_PIP2_VPOS                ((uint32_t)0x000007FF)        /*!< specify the vertical position of the sub-picture2 of PiP window */

/* ============================== Bit definition for Sub-Picture2 Dimension register ============== */
#define LTDC_SP2DR_PIP2_HDIM                ((uint32_t)0x07FF0000)        /*!< specify the horizontal dimension of the sub-picture2 of PiP window */
#define LTDC_SP2DR_PIP2_VDIM                ((uint32_t)0x000007FF)        /*!< specify the vertical dimension of the sub-picture2 of PiP window */

/* ============================== Bit definition for PIP Priority Control register ================ */
#define LTDC_PIPPCR_IMG3_PRIORITY           ((uint32_t)0x000000C0)        /*!< image3 priority */
#define LTDC_PIPPCR_IMG2_PRIORITY           ((uint32_t)0x00000030)        /*!< image2 priority */
#define LTDC_PIPPCR_IMG1_PRIORITY           ((uint32_t)0x0000000C)        /*!< image1 priority */ 
#define LTDC_PIPPCR_IMG0_PRIORITY           ((uint32_t)0x00000003)        /*!< image0 priority */

/* ============================== Bit definition for PIP Color Key register1 ====================== */
#define LTDC_PIPCKR1_COLORKEY1_EN           ((uint32_t)0x01000000)        /*!< color key for the PiP image1 function control */
#define LTDC_PIPCKR1_COLORKEY1              ((uint32_t)0x00FFFFFF)        /*!< color key for the PiP image1 value */

/* ============================== Bit definition for PIP Color Key register2 ====================== */
#define LTDC_PIPCKR2_COLORKEY2_EN           ((uint32_t)0x01000000)        /*!< color key for the PiP image2 function control */
#define LTDC_PIPCKR2_COLORKEY2              ((uint32_t)0x00FFFFFF)        /*!< color key for the PiP image2 value */

/* ============================== Bit definition for PIP Color Key register3 ====================== */
#define LTDC_PIPCKR3_COLORKEY3_EN           ((uint32_t)0x01000000)        /*!< color key for the PiP image3 function control */
#define LTDC_PIPCKR3_COLORKEY3              ((uint32_t)0x00FFFFFF)        /*!< color key for the PiP image3 value */

/* ============================== Bit definition for Sub-Picture3 Position register =============== */
#define LTDC_SP3PR_PIP3_HPOS                ((uint32_t)0x07FF0000)        /*!< specify the horizontal position of the sub-picture3 of PiP window */
#define LTDC_SP3PR_PIP3_VPOS                ((uint32_t)0x000007FF)        /*!< specify the vertical position of the sub-picture3 of PiP window */

/* ============================== Bit definition for Sub-Picture3 Dimension register ============== */
#define LTDC_SP3DR_PIP3_HDIM                ((uint32_t)0x07FF0000)        /*!< specify the horizontal dimension of the sub-picture3 of PiP window */
#define LTDC_SP3DR_PIP3_VDIM                ((uint32_t)0x000007FF)        /*!< specify the vertical dimension of the sub-picture3 of PiP window */

/* ============================== Bit definition for Scaler Control register ====================== */
#define LTDC_SCR_FIR_SEL                    ((uint32_t)0x000001C0)        /*!< the scaling ratio selection of the first stage scaler */
#define LTDC_SCR_HORINTR_MODE               ((uint32_t)0x00000018)        /*!< the horizontal interpolation mode */
#define LTDC_SCR_VERINTR_MODE               ((uint32_t)0x00000006)        /*!< the vertical interpolation mode */
#define LTDC_SCR_BYPASS_MODE                ((uint32_t)0x00000001)        /*!< identifies the second stage scaler */

/* =========================================================================================================================== */
/* ================                                            MAC                                           ================= */
/* =========================================================================================================================== */
/* ====================== Bit definition for MADR register ====================== */
#define MAC_MADR_MASK                       ((uint32_t)0x0000ffff)        /*!< The most significant two bytes of the MAC address bit mask*/

/* ====================== Bit definition for LADR register ====================== */
#define MAC_LADR_MASK                       ((uint32_t)0xffffffff)        /*!< The least significant four bytes of the MAC address bit mask */

/* ====================== Bit definition for TXITC register ====================== */
#define MAC_TXITC_TIME_SEL                  ((uint32_t)0x00010000)        /*!< the period of TX cycle time */
#define MAC_TXITC_CYL                       ((uint32_t)0x0000ff00)        /*!< the maximum wait time interrupts */
#define MAC_TXITC_THR                       ((uint32_t)0x00000070)        /*!< the maximum number of transmit interrupts */
#define MAC_TXITC_THR_UNIT                  ((uint32_t)0x00000003)        /*!< the unit of TXINT_THR */

/* ====================== Bit definition for RXITC register ====================== */
#define MAC_RXITC_RST                       ((uint32_t)0x0ff00000)        /*!< the refresh time */
#define MAC_RXITC_TIME_SEL                  ((uint32_t)0x00010000)        /*!< the period of RX cycle time */
#define MAC_RXITC_CYL                       ((uint32_t)0x0000ff00)        /*!< the maximum wait time to issue a receive interrupt */
#define MAC_RXITC_THR                       ((uint32_t)0x00000070)        /*!< the maximum number of receive interrupts */
#define MAC_RXITC_THR_UNIT                  ((uint32_t)0x00000003)        /*!< the unit of RXINT_THR */

/* ====================== Bit definition for APTC register ====================== */
#define MAC_APTC_TX_TIME                    ((uint32_t)0x00001000)        /*!< the period of TX poll time */
#define MAC_APTC_TX_CNT                     ((uint32_t)0x00000f00)        /*!< the period of transmit automatic poll time */
#define MAC_APTC_RX_TIME                    ((uint32_t)0x00000010)        /*!< the period of RX poll time */
#define MAC_APTC_RX_CNT                     ((uint32_t)0x0000000f)        /*!< the period of receive automatic poll time */

/* ====================== Bit definition for DBLAC register ====================== */
#define MAC_DBLAC_IFG_INC                   ((uint32_t)0x00800000)        /*!< IFG (Inter-Frame Gap) increase */
#define MAC_DBLAC_IFG_CNT                   ((uint32_t)0x00700000)        /*!< IFG (Inter-Frame Gap) count */
#define MAC_DBLAC_TXBST_SIZE                ((uint32_t)0x00000c00)        /*!< TXDMA maximum burst size per TXDMA burst */
#define MAC_DBLAC_RXBST_SIZE                ((uint32_t)0x00000300)        /*!< RXDMA maximum burst size per RXDMA burst */
#define MAC_DBLAC_RX_THR_EN                 ((uint32_t)0x00000040)        /*!< Enable the RX FIFO threshold arbitration */
#define MAC_DBLAC_RXFIFO_HTHR               ((uint32_t)0x00000038)        /*!< RX FIFO high threshold value for arbitration */
#define MAC_DBLAC_RXFIFO_LTHR               ((uint32_t)0x00000007)        /*!< RX FIFO low threshold value for arbitration */

/* ====================== Bit definition for DMAFIFOS register ====================== */

#define MAC_DMAFIFOS_TXFIFO_EMPTY           ((uint32_t)0x08000000)        /*!< TX FIFO is empty */
#define MAC_DMAFIFOS_RXFIFO_EMPTY           ((uint32_t)0x04000000)        /*!< RX FIFO is empty */

/* ====================== Bit definition for TPAFCR register ====================== */
#define MAC_TPAFCR_TFIFO_SIZE               ((uint32_t)0x38000000)        /*!< TX FIFO size */
#define MAC_TPAFCR_RFIFO_SIZE               ((uint32_t)0x07000000)        /*!< RX FIFO size */
#define MAC_TPAFCR_HPKT_THR                 ((uint32_t)0x000000f0)        /*!< High Priority Transmit Packet Threshold */
#define MAC_TPAFCR_NPKT_THR                 ((uint32_t)0x0000000f)        /*!< Normal Priority Transmit Packet Threshold */

/* ====================== Bit definition for RBSR register ====================== */
#define MAC_RBSR_RXBUF_SIZE                 ((uint32_t)0x00003fff)        /*!< Receive buffer size */

/* ====================== Bit definition for MACCR register ====================== */
#define MAC_MACCR_SW_RST                    ((uint32_t)0x80000000)        /*!< Software reset */
#define MAC_MACCR_FULLDUP                   ((uint32_t)0x04000000)        /*!< Full duplex */
#define MAC_MACCR_SPEED                     ((uint32_t)0x03000000)        /*!< MAC operation mode */
#define MAC_MACCR_HPTXR_EN                  ((uint32_t)0x00400000)        /*!< High priority transmit ring enable */
#define MAC_MACCR_LOOP_EN                   ((uint32_t)0x00200000)        /*!< Internal loopback enable */
#define MAC_MACCR_PTP_EN                    ((uint32_t)0x00100000)        /*!< IEEE 1588 PTP TX/RX frame detection enable */
#define MAC_MACCR_REMOVE_VLAN               ((uint32_t)0x00040000)        /*!< Remove the VLAN tag from the packets received with the VLAN tag */
#define MAC_MACCR_CRC_APD                   ((uint32_t)0x00020000)        /*!< Append CRC to transmitted packets  */
#define MAC_MACCR_DROP_CRC_ERR              ((uint32_t)0x00010000)        /*!< Discard the CRC error packet if there is CRC error status in the transmit packet */
#define MAC_MACCR_ENRX_IN_HALFTX            ((uint32_t)0x00004000)        /*!< Enable packet reception when transmitting packets in the half-duplex mode */
#define MAC_MACCR_JUMBO_LF                  ((uint32_t)0x00002000)        /*!< Jumbo Long Frame */
#define MAC_MACCR_RX_RUNT                   ((uint32_t)0x00001000)        /*!< Receive the incoming packet even if its length is less than 64 bytes  */
#define MAC_MACCR_RX_BROADPKT_EN            ((uint32_t)0x00000800)        /*!< Receives broadcast packets */
#define MAC_MACCR_RX_MULTIPKT_EN            ((uint32_t)0x00000400)        /*!< Receives all multicast packets */
#define MAC_MACCR_RX_HT_EN                  ((uint32_t)0x00000200)        /*!< Enables storing incoming packet if the packet passes hash table */
#define MAC_MACCR_RX_ALLADR                 ((uint32_t)0x00000100)        /*!< Destination address of the incoming packet is not checked */
#define MAC_MACCR_RXMAC_EN                  ((uint32_t)0x00000008)        /*!< RXMAC enable */
#define MAC_MACCR_TXMAC_EN                  ((uint32_t)0x00000004)        /*!< TXMAC enable */
#define MAC_MACCR_RXDMA_EN                  ((uint32_t)0x00000002)        /*!< Enable receive DMA channel  */
#define MAC_MACCR_TXDMA_EN                  ((uint32_t)0x00000001)        /*!< Enable transmit DMA channel */

/* ====================== Bit definition for TM register ====================== */
#define MAC_TM_PTIMER_TEST                  ((uint32_t)0x00100000)        /*!< Automatic polling timer test mode */
#define MAC_TM_ITIMER_TEST                  ((uint32_t)0x00080000)        /*!< Interrupt timer test mode */
#define MAC_TM_TEST_COL                     ((uint32_t)0x00008000)        /*!< Transmit collision test mode */
#define MAC_TM_TEST_BKOFF                   ((uint32_t)0x00007FE0)        /*!< Back-off value in the transmission collision test mode */
#define MAC_TM_TEST_EXSTHR                  ((uint32_t)0x0000001f)        /*!< Retry upper limit in the transmit collision test mode */

/* ====================== Bit definition for PHYCR register ====================== */
#define MAC_PHYCR_PHYWR                     ((uint32_t)0x08000000)        /*!< Setting this bit to 1 initializes a write sequence to PHY */
#define MAC_PHYCR_PHYRD                     ((uint32_t)0x04000000)        /*!< Setting this bit to 1 initializes a read sequence to PHY */
#define MAC_PHYCR_REGAD                     ((uint32_t)0x03e00000)        /*!< Register address for 802.3 Clause 22 */
#define MAC_PHYCR_PHYAD                     ((uint32_t)0x001f0000)        /*!< PHY address for 802.3 Clause 22 */
#define MAC_PHYCR_OP                        ((uint32_t)0x0000c000)        /*!< Operation code */
#define MAC_PHYCR_SOF                       ((uint32_t)0x00003000)        /*!< Start of frame */
#define MAC_PHYCR_CYCTHR                    ((uint32_t)0x000000ff)        /*!< MDC cycle threshold */

/* ====================== Bit definition for PHYDATA register ====================== */
#define MAC_PHYDATA_MIIRDATA                ((uint32_t)0xffff0000)        /*!< Read data from PHY */
#define MAC_PHYDATA_MIIWDATA                ((uint32_t)0x0000ffff)        /*!< Write data to PHY  */

/* ====================== Bit definition for FCR register ====================== */
#define MAC_FCR_PAUSE_TIME                  ((uint32_t)0xffff0000)        /*!< Pause time in the pause frame */
#define MAC_FCR_FC_H_L                      ((uint32_t)0x0000fe00)        /*!< RX FIFO free space high threshold */
#define MAC_FCR_HTHR                        ((uint32_t)0x00000100)        /*!< RX FIFO free space high threshold select */
#define MAC_FCR_RX_PAUSE                    ((uint32_t)0x00000010)        /*!< Receive pause frame */
#define MAC_FCR_TXPAUSED                    ((uint32_t)0x00000008)        /*!< Packet transmission paused due to the receive pause frame */
#define MAC_FCR_FCTHR_EN                    ((uint32_t)0x00000004)        /*!< Enable flow control threshold mode */
#define MAC_FCR_TX_PAUSE                    ((uint32_t)0x00000002)        /*!< Transmit pause frame */
#define MAC_FCR_FC_EN                       ((uint32_t)0x00000001)        /*!< Flow control mode enable */

/* ====================== Bit definition for BPR register ====================== */
#define MAC_BPR_BK_LOW                      ((uint32_t)0x00007f00)        /*!< RX FIFO free space low threshold  */
#define MAC_BPR_BKJAM_LEN                   ((uint32_t)0x000000f0)        /*!< Back pressure jam length */
#define MAC_BPR_BKADR_MODE                  ((uint32_t)0x00000002)        /*!< Back pressure address mode */
#define MAC_BPR_BKEN                        ((uint32_t)0x00000001)        /*!< Back pressure mode enable */

/* ====================== Bit definition for WOLCR register ====================== */
#define MAC_WOLCR_WOL_TYPE                  ((uint32_t)0x03000000)        /*!< WOL output signal type */
#define MAC_WOLCR_SW_PDNPHY                 ((uint32_t)0x00040000)        /*!< Software power down PHY */
#define MAC_WOLCR_WAKEUP_SEL                ((uint32_t)0x00030000)        /*!< Wake-up frame select */

/* ====================== Bit definition for WOLSR register ====================== */
#define MAC_WOLSR_WAKEUP4                   ((uint32_t)0x00000040)        /*!< Wake-up frame 4 event status */
#define MAC_WOLSR_WAKEUP3                   ((uint32_t)0x00000020)        /*!< Wake-up frame 3 event status */
#define MAC_WOLSR_WAKEUP2                   ((uint32_t)0x00000010)        /*!< Wake-up frame 2 event status */
#define MAC_WOLSR_WAKEUP1                   ((uint32_t)0x00000008)        /*!< Wake-up frame 1 event status */
#define MAC_WOLSR_MAGICPKT                  ((uint32_t)0x00000004)        /*!< Magic packet event status */
#define MAC_WOLSR_LINKCHG1                  ((uint32_t)0x00000002)        /*!< Link change to 1 event status */
#define MAC_WOLSR_LINKCHG0                  ((uint32_t)0x00000001)        /*!< Link change to 0 event status  */

/* ====================== Bit definition for BMRCR register ====================== */
#define MAC_BMRCR_TIME_STEP                 ((uint32_t)0x01000000)        /*!< Timer step setting */
#define MAC_BMRCR_TIME_THR_NUM              ((uint32_t)0x00ff0000)        /*!< Timer threshold number */
#define MAC_BMRCR_PKT_THR_VAL               ((uint32_t)0x0000001f)        /*!< Multicast and broadcast packets threshold value */

/* ====================== Bit definition for ERCR register ====================== */
#define MAC_ERCR_RONLY_ERR_EN               ((uint32_t)0x00000002)        /*!< Read-only Error enable */
#define MAC_ERCR_DEC_ERR_EN                 ((uint32_t)0x00000001)        /*!< Decode Error enable */

/* =========================================================================================================================== */
/* ================                            Power Control                                                 ================= */
/* =========================================================================================================================== */
/* ====================== Bit definition for PWRPCR_PCR register  ====================== */
#define PWRPCR_PCR_DDRPS                    ((uint32_t)0x00000020)        /*!< DDR Power Switch */
#define PWRPCR_PCR_USB3PS                   ((uint32_t)0x00000040)        /*!< USB3 Power Switch */
#define PWRPCR_PCR_DDRISO                   ((uint32_t)0x00002000)        /*!< DDR Isolation */
#define PWRPCR_PCR_USB3ISO                  ((uint32_t)0x00004000)        /*!< USB3 Isolation */

/* ====================== Bit definition for PWRPMU_CR register  ======================= */
#define PWRPMU_CR_DATASYNC                  ((uint32_t)0x00000001)        /*!< PMU domain control data synchrobization */
#define PWRPMU_CR_POWERDOWN                 ((uint32_t)0x00000002)        /*!< PMU Power Down */
#define PWRPMU_CR_POWERON                   ((uint32_t)0x00000004)        /*!< PMU Power ON */
#define PWRPMU_CR_RTCALARM                  ((uint32_t)0x00000008)        /*!< RTC Alarm control */
#define PWRPMU_CR_PWRENOUPUTVAL             ((uint32_t)0x000000F0)        /*!< Power Enable output value */
#define PWRPMU_CR_WAKEUPENABLE              ((uint32_t)0x00000700)        /*!< PMU wakeup source enable */
#define PWRPMU_CR_WAKEUPSRC0MODE            ((uint32_t)0x00003000)        /*!< PMU wakeup source 0 active mode */
#define PWRPMU_CR_WAKEUPSRC1MODE            ((uint32_t)0x0000C000)        /*!< PMU wakeup source 1 active mode */
#define PWRPMU_CR_WAKEUPSRC2MODE            ((uint32_t)0x00030000)        /*!< PMU wakeup source 2 active mode */
#define PWRPMU_CR_RSTENABLE                 ((uint32_t)0x00040000)        /*!< PMU Reset Enable */
#define PWRPMU_CR_PWRENMASK                 ((uint32_t)0x00780000)        /*!< PMU PWREN signal Mask */

/* ====================== Bit definition for PWRPMU_PWONCR register  ======================= */
#define PWRPMU_PWONCR_PWREN0ON              ((uint32_t)0x000000FF)        /*!< PMU PWREN0 power on timing parameter */
#define PWRPMU_PWONCR_PWREN1ON              ((uint32_t)0x0000FF00)        /*!< PMU PWREN1 power on timing parameter */
#define PWRPMU_PWONCR_PWREN2ON              ((uint32_t)0x00FF0000)        /*!< PMU PWREN2 power on timing parameter */
#define PWRPMU_PWONCR_PWREN3ON              ((uint32_t)0xFF000000)        /*!< PMU PWREN3 power on timing parameter */

/* ====================== Bit definition for PWRPMU_PWOFFCR register  ======================= */
#define PWRPMU_PWOFFCR_PWREN0OFF            ((uint32_t)0x000000FF)        /*!< PMU PWREN0 power off timing parameter */
#define PWRPMU_PWOFFCR_PWREN1OFF            ((uint32_t)0x0000FF00)        /*!< PMU PWREN1 power off timing parameter */
#define PWRPMU_PWOFFCR_PWREN2OFF            ((uint32_t)0x00FF0000)        /*!< PMU PWREN2 power off timing parameter */
#define PWRPMU_PWOFFCR_PWREN3OFF            ((uint32_t)0xFF000000)        /*!< PMU PWREN3 power off timing parameter */

/* ====================== Bit definition for PWRPMU_PWOFFCR register  ======================= */
#define PWRPMU_SR_WAKEUPINPUT               ((uint32_t)0x00000007)        /*!< PMU wakeup intput status */
#define PWRPMU_SR_BUTTONINPUT               ((uint32_t)0x00000008)        /*!< PMU button intput status */
#define PWRPMU_SR_SATEMACHINE               ((uint32_t)0x00000030)        /*!< PMU state machine status */

/* =========================================================================================================================== */
/* ================                            Reset and Clock Control of Systerm                            ================= */
/* =========================================================================================================================== */
/* ============================== Bit definition for RCC control register =================================== */
#define RCC_CR_SYSCLKSEL                    ((uint32_t)0x00000001)        /*!< System Clock Select*/
#define RCC_CR_UX608CLKDIVSEL               ((uint32_t)0x00000002)        /*!< MCORE Clock Divider Select */
#define RCC_CR_UX608LITECLKSRCSEL           ((uint32_t)0x00000004)        /*!< CCORE Clock Select */
#define RCC_CR_PKGTYPE                      ((uint32_t)0x000000C0)        /*!< Chip Package Type */
#define RCC_CR_SSP0CLKSEL                   ((uint32_t)0x00000100)        /*!< SSP0 clock select */
#define RCC_CR_SSP1CLKSEL                   ((uint32_t)0x00000200)        /*!< SSP1 clock select */
#define RCC_CR_MCORESLEEP                   ((uint32_t)0x00000400)        /*!< MCORE Sleep State */
#define RCC_CR_CCORESLEEP                   ((uint32_t)0x00000800)        /*!< CCORE Sleep State */
#define RCC_CR_HSMSLEEP                     ((uint32_t)0x00001000)        /*!< HSM Sleep State */

/* ============================== Bit definition for RCC count register =================================== */
#define RCC_CNTR_START                      ((uint32_t)0x00000001)        /*!< RCC Counter Start */
#define RCC_CCNT_VAL                        ((uint32_t)0xFFFFFFFF)        /*!< RCC Counter Value */

/* ============================== Bit definition for RCC record register 0 ================================ */
#define RCC_RCR0_VAL                        ((uint32_t)0xFFFFFFFF)        /*!< RCC Record 0 Value */

/* ============================== Bit definition for RCC record register 1 ================================ */
#define RCC_RCR1_VAL                        ((uint32_t)0xFFFFFFFF)        /*!< RCC Record 1 Value */

/* ============================== Bit definition for RCC UX608 reset address register ===================== */
#define RCC_UX608RAR_VAL                    ((uint32_t)0xFFFFFFFF)        /*!< RCC UX608 Reset Address Value */

/* ============================== Bit definition for RCC UX608_Lite reset address register ================ */
#define RCC_UX608LRAR_VAL                   ((uint32_t)0xFFFFFFFF)        /*!< RCC UX608_Lite Reset Address Value */

/* ============================== Bit definition for RCC PLLSYS config register =========================== */
#define RCC_PLLSCFGR_PLLNS                  ((uint32_t)0x0000003F)        /*!< RCC PLL NS Value */
#define RCC_PLLSCFGR_PLLEN                  ((uint32_t)0x00000040)        /*!< RCC PLL Enable */

/* ============================== Bit definition for RCC PLLDDR config register =========================== */
#define RCC_PLLDCFGR_PLLNS                  ((uint32_t)0x0000003F)        /*!< RCC PLLDDR NS Value */
#define RCC_PLLDCFGR_PLLEN                  ((uint32_t)0x00000040)        /*!< RCC PLLDDR Enable */

/* ================= Bit definition for RCC clock control register 0 ===================== */
#define RCC_CLKCR0_UX608CLKEN               ((uint32_t)0x00000002)        /*!< UX608 Clock Enable */
#define RCC_CLKCR0_UX608LITECLKEN           ((uint32_t)0x00000004)        /*!< UX608_Lite Clock Enable */
#define RCC_CLKCR0_PCIECLKEN                ((uint32_t)0x00000008)        /*!< PCIe Clock Enable */
#define RCC_CLKCR0_GMAC0CLKEN               ((uint32_t)0x00000010)        /*!< GMAC0 Clock Enable */
#define RCC_CLKCR0_GMAC1CLKEN               ((uint32_t)0x00000020)        /*!< GMAC1 Clock Enable */
#define RCC_CLKCR0_USB3CLKEN                ((uint32_t)0x00000080)        /*!< USB3 Clock Enable */
#define RCC_CLKCR0_FMC0CLKEN                ((uint32_t)0x00000100)        /*!< FMC0 Clock Enable */
#define RCC_CLKCR0_FMC1CLKEN                ((uint32_t)0x00000200)        /*!< FMC1 Clock Enable */
#define RCC_CLKCR0_DDRCCLKEN                ((uint32_t)0x00000400)        /*!< DDRC Clock Enable */
#define RCC_CLKCR0_DMA0CLKEN                ((uint32_t)0x00020000)        /*!< DMA0 Clock Enable */
#define RCC_CLKCR0_DMA1CLKEN                ((uint32_t)0x00040000)        /*!< DMA1 Clock Enable */
#define RCC_CLKCR0_WDGTIM0CLKEN             ((uint32_t)0x00080000)        /*!< WDGTIM0 Clock Enable */
#define RCC_CLKCR0_WDGTIM1CLKEN             ((uint32_t)0x00100000)        /*!< WDGTIM1 Clock Enable */
#define RCC_CLKCR0_IIC2CLKEN                ((uint32_t)0x00400000)        /*!< IIC2 Clock Enable */
#define RCC_CLKCR0_IIC1CLKEN                ((uint32_t)0x00800000)        /*!< IIC1 Clock Enable */
#define RCC_CLKCR0_GPIOCLKEN                ((uint32_t)0x01000000)        /*!< GPIO Clock Enable */
#define RCC_CLKCR0_AXI1CLKEN                ((uint32_t)0x04000000)        /*!< AXI1 Clock Enable */
#define RCC_CLKCR0_AHB0CLKEN                ((uint32_t)0x10000000)        /*!< AHB0 Clock Enable */

/* ================= Bit definition for RCC clock control register 1 ====================== */
#define RCC_CLKCR1_UART1CLKEN               ((uint32_t)0x00000001)        /*!< UART1 Clock Enable */
#define RCC_CLKCR1_UART2CLKEN               ((uint32_t)0x00000002)        /*!< UART2 Clock Enable */
#define RCC_CLKCR1_UART3CLKEN               ((uint32_t)0x00000004)        /*!< UART3 Clock Enable */
#define RCC_CLKCR1_UART4CLKEN               ((uint32_t)0x00000008)        /*!< UART4 Clock Enable */
#define RCC_CLKCR1_UART5CLKEN               ((uint32_t)0x00000010)        /*!< UART5 Clock Enable */
#define RCC_CLKCR1_UART6CLKEN               ((uint32_t)0x00000020)        /*!< UART6 Clock Enable */
#define RCC_CLKCR1_UART7CLKEN               ((uint32_t)0x00000040)        /*!< UART7 Clock Enable */
#define RCC_CLKCR1_SCI0CLKEN                ((uint32_t)0x00000080)        /*!< SCI0 Clock Enable */
#define RCC_CLKCR1_SCI1CLKEN                ((uint32_t)0x00000100)        /*!< SCI1 Clock Enable */
#define RCC_CLKCR1_SPI0CLKEN                ((uint32_t)0x00000200)        /*!< SPI0 Clock Enable */
#define RCC_CLKCR1_SPI1CLKEN                ((uint32_t)0x00000400)        /*!< SPI1 Clock Enable */
#define RCC_CLKCR1_DACCLKEN                 ((uint32_t)0x00000800)        /*!< DAC Clock Enable */
#define RCC_CLKCR1_SSP0CLKEN                ((uint32_t)0x00001000)        /*!< SSP0 Clock Enable */
#define RCC_CLKCR1_SSP1CLKEN                ((uint32_t)0x00002000)        /*!< SSP1 Clock Enable */
#define RCC_CLKCR1_CANB1CLKEN               ((uint32_t)0x00004000)        /*!< CANB1 Clock Enable */
#define RCC_CLKCR1_CANB2CLKEN               ((uint32_t)0x00008000)        /*!< CANB2 Clock Enable */
#define RCC_CLKCR1_CANB3CLKEN               ((uint32_t)0x00010000)        /*!< CANB3 Clock Enable */
#define RCC_CLKCR1_CANA0CLKEN               ((uint32_t)0x00020000)        /*!< CANA0 Clock Enable */
#define RCC_CLKCR1_CANA1CLKEN               ((uint32_t)0x00040000)        /*!< CANA1 Clock Enable */
#define RCC_CLKCR1_CANA2CLKEN               ((uint32_t)0x00080000)        /*!< CANA2 Clock Enable */
#define RCC_CLKCR1_CANA3CLKEN               ((uint32_t)0x00100000)        /*!< CANA3 Clock Enable */
#define RCC_CLKCR1_USB2CLKEN                ((uint32_t)0x00200000)        /*!< USB2 Clock Enable */
#define RCC_CLKCR1_LTDCCLKEN                ((uint32_t)0x00400000)        /*!< LTDC Clock Enable */
#define RCC_CLKCR1_SDHC1CLKEN               ((uint32_t)0x00800000)        /*!< SDHC1 Clock Enable */
#define RCC_CLKCR1_SDHC2CLKEN               ((uint32_t)0x01000000)        /*!< SDHC2 Clock Enable */
#define RCC_CLKCR1_SDHC0CLKEN               ((uint32_t)0x02000000)        /*!< SDHC0 Clock Enable */
#define RCC_CLKCR1_MAC0CLKEN                ((uint32_t)0x04000000)        /*!< MAC0 Clock Enable */
#define RCC_CLKCR1_MAC1CLKEN                ((uint32_t)0x08000000)        /*!< MAC1 Clock Enable */
#define RCC_CLKCR1_TEECFGCLKEN              ((uint32_t)0x10000000)        /*!< TEE Config Clock Enable */

/* =================  Bit definition forRCC clock control register 2  ====================== */
#define RCC_CLKCR2_HSMCLKEN                 ((uint32_t)0x00000001)        /*!< HSM Clock Enable */
#define RCC_CLKCR2_LPCLKEN                  ((uint32_t)0x00000002)        /*!< LP Clock Enable */
#define RCC_CLKCR2_SRAMECCCLKEN             ((uint32_t)0x00000004)        /*!< SRAM ECC Clock Enable */
#define RCC_CLKCR2_ROMCLKEN                 ((uint32_t)0x00000008)        /*!< ROM Clock Enable */

/* =================  Bit definition for RCC AXI divider register  =================== */
#define RCC_AXIDIVR_VAL                     ((uint32_t)0x000000FF)        /*!< AXI Clock Divier Value */

/* =================  Bit definition for RCC AHB0 divider register  =================== */
#define RCC_AHB0DIVR_VAL                    ((uint32_t)0x000000FF)        /*!< AHB0 Clock Divider Value */

/* =================  Bit definition for RCC APB0 divider register  =================== */
#define RCC_APB0DIVR_VAL                    ((uint32_t)0x000000FF)        /*!< APB0 Clock Divider Value */

/* =================  Bit definition for RCC CPU divider register  =================== */
#define RCC_UX608DIVR_VAL                   ((uint32_t)0x000000FF)        /*!< CPU Clock Divider Value */

/* =================  Bit definition for RCC HSM divider register  =================== */
#define RCC_HSMDIVR_VAL                     ((uint32_t)0x000000FF)        /*!< HSM Clock Divider Value */

/* =================  Bit definition for RCC LP divider register  =================== */
#define RCC_LPDIVR_VAL                      ((uint32_t)0x000000FF)        /*!< LP Clock Divider Value */

/* =================  Bit definition for RCC FMC0 divider register  =================== */
#define RCC_FMC0DIVR_VAL                    ((uint32_t)0x000000FF)        /*!< FMC0 Clock Divider Value */

/* =================  Bit definition for RCC FMC1 divider register  =================== */
#define RCC_FMC1DIVR_VAL                    ((uint32_t)0x000000FF)        /*!< FMC1 Clock Divider Value */

/* =================  Bit definition for RCC UART1 divider register  =================== */
#define RCC_UART1DIVR_VAL                   ((uint32_t)0x000000FF)        /*!< UART1 Clock Divider Value */

/* =================  Bit definition for RCC UART2 divider register  =================== */
#define RCC_UART2DIVR_VAL                   ((uint32_t)0x000000FF)        /*!< UART2 Clock Divider Value */

/* =================  Bit definition for RCC UART3 divider register  =================== */
#define RCC_UART3DIVR_VAL                   ((uint32_t)0x000000FF)        /*!< UART3 Clock Divider Value */

/* =================  Bit definition for RCC UART4 divider register  =================== */
#define RCC_UART4DIVR_VAL                   ((uint32_t)0x000000FF)        /*!< UART4 Clock Divider Value */

/* =================  Bit definition for RCC UART5 divider register  =================== */
#define RCC_UART5DIVR_VAL                   ((uint32_t)0x000000FF)        /*!< UART5 Clock Divider Value */

/* =================  Bit definition for RCC UART6 divider register  =================== */
#define RCC_UART6DIVR_VAL                   ((uint32_t)0x000000FF)        /*!< UART6 Clock Divider Value */

/* =================  Bit definition for RCC UART7 divider register  =================== */
#define RCC_UART7DIVR_VAL                   ((uint32_t)0x000000FF)        /*!< UART7 Clock Divider Value */

/* =================  Bit definition for RCC SCI0 divider register  =================== */
#define RCC_SCI0DIVR_VAL                    ((uint32_t)0x000000FF)        /*!< SCI0 Clock Divider Value */

/* =================  Bit definition for RCC SCI1 divider register  =================== */
#define RCC_SCI1DIVR_VAL                    ((uint32_t)0x000000FF)        /*!< SCI1 Clock Divider Value */

/* =================  Bit definition for RCC SPI0 divider register  =================== */
#define RCC_SPI0DIVR_VAL                    ((uint32_t)0x000000FF)        /*!< SPI0 Clock Divider Value */

/* =================  Bit definition for RCC SPI1 divider register  =================== */
#define RCC_SPI1DIVR_VAL                    ((uint32_t)0x000000FF)        /*!< SPI1 Clock Divider Value */

/* =================  Bit definition for RCC SSP0 divider register  =================== */
#define RCC_SSP0DIVR_VAL                    ((uint32_t)0x000000FF)        /*!< SSP0 Clock Divider Value */

/* =================  Bit definition for RCC SSP1 divider register  =================== */
#define RCC_SSP1DIVR_VAL                    ((uint32_t)0x000000FF)        /*!< SSP1 Clock Divider Value */

/* =================  Bit definition for RCC CANB1 divider register  =================== */
#define RCC_CANB1DIVR_VAL                   ((uint32_t)0x000000FF)        /*!< CANA1 Clock Divider Value */

/* =================  Bit definition for RCC CANB2 divider register  =================== */
#define RCC_CANB2DIVR_VAL                   ((uint32_t)0x000000FF)        /*!< CANA2 Clock Divider Value */

/* =================  Bit definition for RCC CANB3 divider register  =================== */
#define RCC_CANB3DIVR_VAL                   ((uint32_t)0x000000FF)        /*!< CANA3 Clock Divider Value */

/* =================  Bit definition for RCC CANA0 divider register  =================== */
#define RCC_CANA0DIVR_VAL                   ((uint32_t)0x000000FF)        /*!< CANB0 Clock Divider Value */

/* =================  Bit definition for RCC CANA1 divider register  =================== */
#define RCC_CANA1DIVR_VAL                   ((uint32_t)0x000000FF)        /*!< CANB1 Clock Divider Value */

/* =================  Bit definition for RCC CANA2 divider register  =================== */
#define RCC_CANA2DIVR_VAL                   ((uint32_t)0x000000FF)        /*!< CANB2 Clock Divider Value */

/* =================  Bit definition for RCC CANA3 divider register  =================== */
#define RCC_CANA3DIVR_VAL                   ((uint32_t)0x000000FF)        /*!< CANB3 Clock Divider Value */

/* =================  Bit definition for RCC SDHC2 divider register  =================== */
#define RCC_SDHC2DIVR_VAL                   ((uint32_t)0x000000FF)        /*!< SDHC2 Clock Divider Value */

/* =================  Bit definition for RCC SDHC1 divider register  =================== */
#define RCC_SDHC1DIVR_VAL                   ((uint32_t)0x000000FF)        /*!< SDHC1 Clock Divider Value */

/* =================  Bit definition for RCC SDHC0 divider register  =================== */
#define RCC_SDHC0DIVR_VAL                   ((uint32_t)0x000000FF)        /*!< SDHC0 Clock Divider Value */
 
/* =================  Bit definition for RCC APB2 divider register  =================== */
#define RCC_APB2CDIVR_VAL                   ((uint32_t)0x000000FF)        /*!< APB2 Clock Divider Value */

/* =================  Bit definition for RCC LTDCLC divider register  =================== */
#define RCC_LTDCLCDIVR_VAL                  ((uint32_t)0x000000FF)        /*!< LTDCLC Clock Divider Value */

/* =================  Bit definition for RCC LTDCTV divider register  =================== */
#define RCC_LTDCTVDIVR_VAL                  ((uint32_t)0x000000FF)        /*!< LTDCTV Clock Divider Value */

/* =================  Bit definition for RCC LTDCSCAL divider register  =================== */
#define RCC_LTDCSCALDIVR_VAL                ((uint32_t)0x000000FF)        /*!< LTDCSCAL Clock Divider Value */

/* =================  Bit definition for RCC PCIETL divider register  =================== */
#define RCC_PCIETLDIVR_VAL                  ((uint32_t)0x000000FF)        /*!< PCIETL Clock Divider Value */

/* ====================  Bit definition for RCC reset control register 0 ==================== */
#define RCC_RSTCR0_UX608SWRST               ((uint32_t)0x00000002)        /*!< UX608 Software Reset */
#define RCC_RSTCR0_UX608LITESWRST           ((uint32_t)0x00000004)        /*!< Ux608_LITE Software Reset */
#define RCC_RSTCR0_PCIESWRST                ((uint32_t)0x00000008)        /*!< PCIe Software Reset */
#define RCC_RSTCR0_GMAC0SWRST               ((uint32_t)0x00000010)        /*!< GMAC0 Software Reset */
#define RCC_RSTCR0_GMAC1SWRST               ((uint32_t)0x00000020)        /*!< GMAC1 Software Reset */
#define RCC_RSTCR0_USB3SWRST                ((uint32_t)0x00000080)        /*!< USB3 Software Reset */
#define RCC_RSTCR0_FMC0SWRST                ((uint32_t)0x00000100)        /*!< FMC0 Software Reset */
#define RCC_RSTCR0_FMC1SWRST                ((uint32_t)0x00000200)        /*!< FMC1 Software Reset */
#define RCC_RSTCR0_DDRCSWRST                ((uint32_t)0x00000400)        /*!< DDRC Software Reset */
#define RCC_RSTCR0_DMA0SWRST                ((uint32_t)0x00002000)        /*!< DMA0 Software Reset */
#define RCC_RSTCR0_DMA1SWRST                ((uint32_t)0x00004000)        /*!< DMA1 Software Reset */
#define RCC_RSTCR0_WDGTIM0SWRST             ((uint32_t)0x00008000)        /*!< WDGTIM0 Software Reset */
#define RCC_RSTCR0_WDGTIM1SWRST             ((uint32_t)0x00010000)        /*!< WDGTIM1 Software Reset */
#define RCC_RSTCR0_IIC2SWRST                ((uint32_t)0x00400000)        /*!< IIC2 Software Reset */
#define RCC_RSTCR0_IIC1SWRST                ((uint32_t)0x00800000)        /*!< IIC1 Software Reset */
#define RCC_RSTCR0_GPIOSWRST                ((uint32_t)0x01000000)        /*!< GPIO Software Reset */
#define RCC_RSTCR0_AXI1SWRST                ((uint32_t)0x04000000)        /*!< AXI1 Software Reset */
#define RCC_RSTCR0_AHB0SWRST                ((uint32_t)0x10000000)        /*!< AHB0 Software Reset */
#define RCC_RSTCR0_USB3PHYSWRST             ((uint32_t)0x20000000)        /*!< USB3PHY Software Reset */

/* ====================  Bit definition for RCC reset control register 1  =================== */
#define RCC_RSTCR1_UART1SWRST               ((uint32_t)0x00000001)        /*!< UART1 Software Reset */
#define RCC_RSTCR1_UART2SWRST               ((uint32_t)0x00000002)        /*!< UART2 Software Reset */
#define RCC_RSTCR1_UART3SWRST               ((uint32_t)0x00000004)        /*!< UART3 Software Reset */
#define RCC_RSTCR1_UART4SWRST               ((uint32_t)0x00000008)        /*!< UART4 Software Reset */
#define RCC_RSTCR1_UART5SWRST               ((uint32_t)0x00000010)        /*!< UART5 Software Reset */
#define RCC_RSTCR1_UART6SWRST               ((uint32_t)0x00000020)        /*!< UART6 Software Reset */
#define RCC_RSTCR1_UART7SWRST               ((uint32_t)0x00000040)        /*!< UART7 Software Reset */
#define RCC_RSTCR1_SCI0SWRST                ((uint32_t)0x00000080)        /*!< SCI0 Software Reset */
#define RCC_RSTCR1_SCI1SWRST                ((uint32_t)0x00000100)        /*!< SCI1 Software Reset */
#define RCC_RSTCR1_SPI0SWRST                ((uint32_t)0x00000200)        /*!< SPI0 Software Reset */
#define RCC_RSTCR1_SPI1SWRST                ((uint32_t)0x00000400)        /*!< SPI1 Software Reset */
#define RCC_RSTCR1_DACSWRST                 ((uint32_t)0x00000800)        /*!< DAC Software Reset */
#define RCC_RSTCR1_SSP0SWRST                ((uint32_t)0x00001000)        /*!< SSP0 Software Reset */
#define RCC_RSTCR1_SSP1SWRST                ((uint32_t)0x00002000)        /*!< SSP1 Software Reset */
#define RCC_RSTCR1_CANB1SWRST               ((uint32_t)0x00004000)        /*!< CANB1 Software Reset */
#define RCC_RSTCR1_CANB2SWRST               ((uint32_t)0x00008000)        /*!< CANB2 Software Reset */
#define RCC_RSTCR1_CANB3SWRST               ((uint32_t)0x00010000)        /*!< CANB3 Software Reset */
#define RCC_RSTCR1_CANA0SWRST               ((uint32_t)0x00020000)        /*!< CANA0 Software Reset */
#define RCC_RSTCR1_CANA1SWRST               ((uint32_t)0x00040000)        /*!< CANA1 Software Reset */
#define RCC_RSTCR1_CANA2SWRST               ((uint32_t)0x00080000)        /*!< CANA2 Software Reset */
#define RCC_RSTCR1_CANA3SWRST               ((uint32_t)0x00100000)        /*!< CANA3 Software Reset */
#define RCC_RSTCR1_USB2SWRST                ((uint32_t)0x00200000)        /*!< USB2 Software Reset */
#define RCC_RSTCR1_LTDCSWRST                ((uint32_t)0x00400000)        /*!< LTDC Software Reset */
#define RCC_RSTCR1_SDHC1SWRST               ((uint32_t)0x00800000)        /*!< SDHC1 Software Reset */
#define RCC_RSTCR1_SDHC2SWRST               ((uint32_t)0x01000000)        /*!< SDHC2 Software Reset */
#define RCC_RSTCR1_SDHC0SWRST               ((uint32_t)0x02000000)        /*!< SDHC0 Software Reset */
#define RCC_RSTCR1_MAC0SWRST                ((uint32_t)0x04000000)        /*!< MAC0 Software Reset */
#define RCC_RSTCR1_MAC1SWRST                ((uint32_t)0x08000000)        /*!< MAC1 Software Reset */
#define RCC_RSTCR1_TEECFGSWRST              ((uint32_t)0x10000000)        /*!< TEECFG Software Reset */
#define RCC_RSTCR1_USB2PHYSWRST             ((uint32_t)0x20000000)        /*!< USB2PHY Software Reset */

/* ====================== Bit definition for reset control register 2  =================== */
#define RCC_RSTCR2_LPSWRST                  ((uint32_t)0x00000002)        /*!< TEECFG Software Reset */
#define RCC_RSTCR2_SRAMECCSWRST             ((uint32_t)0x00000004)        /*!< TEECFG Software Reset */
#define RCC_RSTCR2_ROMSWRST                 ((uint32_t)0x00000008)        /*!< TEECFG Software Reset */

/* =========================================================================================================================== */
/* ================                        Real-Time Clock                                                   ================= */
/* =========================================================================================================================== */

/* ====================== Bit definition for DAY register  =============================== */
#define RTC_DAY_YEAR                        ((uint32_t)0x7F000000)        /*!< year of calendar */
#define RTC_DAY_MONTH                       ((uint32_t)0x000F0000)        /*!< month of calendar */
#define RTC_DAY_DAY                         ((uint32_t)0x00001F00)        /*!< day of calendar */
#define RTC_DAY_WEEK                        ((uint32_t)0x00000007)        /*!< week of calendar */

/* ====================== Bit definition for CR register  ================================ */
#define RTC_CR_CRR                          ((uint32_t)0x00000080)        /*!< counter register refresh per second */
#define RTC_CR_CNTLOAD                      ((uint32_t)0x00000040)        /*!< counter load */
#define RTC_CR_ALARM                        ((uint32_t)0x00000020)        /*!< alarm interrupt */
#define RTC_CR_ALM_DAY                      ((uint32_t)0x00000010)        /*!< alarm interrupt per day */
#define RTC_CR_ALM_HOUR                     ((uint32_t)0x00000008)        /*!< alarm interrupt per hour */
#define RTC_CR_ALM_MIN                      ((uint32_t)0x00000004)        /*!< alarm interrupt per minute */
#define RTC_CR_ALM_SEC                      ((uint32_t)0x00000002)        /*!< alarm interrupt per second */
#define RTC_CR_EN                           ((uint32_t)0x00000001)        /*!< rtc enable */

/* ====================== Bit definition for WDAY register  ========================= */
#define RTC_WDAY_YEAR                       ((uint32_t)0x007F0000)        /*!< write year of calendar */
#define RTC_WDAY_MONTH                      ((uint32_t)0x00000F00)        /*!< write month of calendar */
#define RTC_WDAY_DAY                        ((uint32_t)0x0000001F)        /*!< write day of calendar */

/* ====================== Bit definition for ISR register  =============================== */
#define RTC_ISR_YEAR                        ((uint32_t)0x00000080)        /*!< this bit indicates the occurrence of the rtc_year interrupt */
#define RTC_ISR_MONTH                       ((uint32_t)0x00000040)        /*!< this bit indicates the occurrence of the rtc_month interrupt */
#define RTC_ISR_LOAD                        ((uint32_t)0x00000020)        /*!< this bit indicates the occurrence of the rtc_load interrupt */
#define RTC_ISR_ALARM                       ((uint32_t)0x00000010)        /*!< this bit indicates the occurrence of the rtc_alarm interrupt */
#define RTC_ISR_DAY                         ((uint32_t)0x00000008)        /*!< this bit indicates the occurrence of the rtc_day interrupt */
#define RTC_ISR_HOUR                        ((uint32_t)0x00000004)        /*!< this bit indicates the occurrence of the rtc_hour interrupt */
#define RTC_ISR_MIN                         ((uint32_t)0x00000002)        /*!< this bit indicates the occurrence of the rtc_min interrupt */
#define RTC_ISR_SEC                         ((uint32_t)0x00000001)        /*!< this bit indicates the occurrence of the rtc_sec interrupt */

/* ====================== Bit definition for RW STATUS register  ========================= */
#define RTC_RWS_WEEK_ST                     ((uint32_t)0x00000200)        /*!< RtcWeek calculate status */
#define RTC_RWS_REF_ST                      ((uint32_t)0x00000100)        /*!< Restore or refresh status */
#define RTC_RWS_WR_DAY_ST                   ((uint32_t)0x00000080)        /*!< WRtcDay transfer status */
#define RTC_RWS_WR_HOUR_ST                  ((uint32_t)0x00000040)        /*!< WRtcHour transfer status */
#define RTC_RWS_WR_MINUTE_ST                ((uint32_t)0x00000020)        /*!< WRtcMinute transfer status */
#define RTC_RWS_WR_SECOND_ST                ((uint32_t)0x00000010)        /*!< WRtcSecond transfer status */
#define RTC_RWS_CR_ST                       ((uint32_t)0x00000008)        /*!< RtcCR transfer status */
#define RTC_RWS_ALM_HOUR_ST                 ((uint32_t)0x00000004)        /*!< AlarmHour transfer status */
#define RTC_RWS_ALM_MIN_ST                  ((uint32_t)0x00000002)        /*!< AlarmMinute transfer status */
#define RTC_RWS_ALM_SEC_ST                  ((uint32_t)0x00000001)        /*!< AlarmSecond transfer status */

/* ====================== Bit definition for CURRENT TIME register  ====================== */
#define RTC_CUR_HOUR                        ((uint32_t)0x001F0000)        /*!< current hour */
#define RTC_CUR_MINUTE                      ((uint32_t)0x00003F00)        /*!< current minute */
#define RTC_CUR_SECOND                      ((uint32_t)0x0000003F)        /*!< current second */

/* ====================== Bit definition for SLEEP TIME register  ======================== */
#define RTC_SLEPTIM_HOUR                    ((uint32_t)0x001F0000)        /*!< hour of sleep time */
#define RTC_SLEPTIM_MINUTE                  ((uint32_t)0x00003F00)        /*!< minute of sleep time */
#define RTC_SLEPTIM_SECOND                  ((uint32_t)0x0000003F)        /*!< second of sleep time */

/* ====================== Bit definition for CURRENT DATE register  ====================== */
#define RTC_CUR_DATE_YEAR                   ((uint32_t)0x7F000000)        /*!< current year */
#define RTC_CUR_DATE_MONTH                  ((uint32_t)0x000F0000)        /*!< current month */
#define RTC_CUR_DATE_DAY                    ((uint32_t)0x00001F00)        /*!< current day */
#define RTC_CUR_DATE_WEEK                   ((uint32_t)0x00000007)        /*!< current week */

/* ====================== Bit definition for SLEEP DATE register  ======================== */
#define RTC_SLEPDATE_YEAR                   ((uint32_t)0x7F000000)        /*!< sleep year */
#define RTC_SLEPDATE_MONTH                  ((uint32_t)0x000F0000)        /*!< sleep month */
#define RTC_SLEPDATE_DAY                    ((uint32_t)0x00001F00)        /*!< sleep day */
#define RTC_SLEPDATE_WEEK                   ((uint32_t)0x00000007)        /*!< sleep week */

/* =========================================================================================================================== */
/* ================               Smart Card Interfac                                                        ================= */
/* =========================================================================================================================== */
/* ====================== Bit definition for SCI_DATA register  ===================== */
#define SCI_DR_PARITY                       ((uint16_t)0x0100)            /*!< Parity Error */
#define SCI_DR_DATA                         ((uint16_t)0x00FF)            /*!< Eight data bits */

/* ====================== Bit definition for SCI_CR0 register  ====================== */
#define SCI_CR0_RX_RETRY_EN                 ((uint8_t)0x20)               /*!< Character receipt handshaking  */
#define SCI_CR0_RXPARITY                    ((uint8_t)0x10)               /*!< Receive Parity setting */
#define SCI_CR0_TX_RETRY_EN                 ((uint8_t)0x08)               /*!< Character transmission handshaking */
#define SCI_CR0_TXPARITY                    ((uint8_t)0x04)               /*!< Transmit Parity setting */
#define SCI_CR0_ORDER                       ((uint8_t)0x02)               /*!< Ordering of the data bits */
#define SCI_CR0_SENSE                       ((uint8_t)0x01)               /*!< Inverts sense of in/out line for data and Parity bits */

/* ====================== Bit definition for SCI_CR1 register  ====================== */
#define SCI_CR1_BGTEN                       ((uint8_t)0x10)               /*!< Block guard timer enable */
#define SCI_CR1_CLKZ1                       ((uint8_t)0x08)               /*!< SCICLK output configuration */
#define SCI_CR1_MODE                        ((uint8_t)0x04)               /*!< Interface direction of communication control */
#define SCI_CR1_BLKEN                       ((uint8_t)0x02)               /*!< Block timeout enable */
#define SCI_CR1_ATRDEN                      ((uint8_t)0x01)               /*!< ATR duration timeout enable */

/* ====================== Bit definition for SCI_CR2 register  ====================== */
#define SCI_CR2_WRESET                      ((uint8_t)0x04)               /*!< Warm reset */
#define SCI_CR2_FINISH                      ((uint8_t)0x02)               /*!< Deactivates the card */
#define SCI_CR2_STARTUP                     ((uint8_t)0x01)               /*!< Starts the activates of the card */

/* ====================== Bit definition for SCI_IER register  ====================== */
#define SCI_IER_TF_THOD_IE                  ((uint16_t)0x0800)            /*!< Transmit FIFO Threshold Interrupt Enable */
#define SCI_IER_RF_THOD_IE                  ((uint16_t)0x0400)            /*!< Receive FIFO Threshold mark */
#define SCI_IER_RF_TOUT_IE                  ((uint16_t)0x0200)            /*!< Receive FIFO read timeout */
#define SCI_IER_CH_TOUT_IE                  ((uint16_t)0x0100)            /*!< Between character timeout */
#define SCI_IER_BLK_TOUT_IE                 ((uint16_t)0x0080)            /*!< Between block timeout */
#define SCI_IER_ATR_DTOUT_IE                ((uint16_t)0x0040)            /*!< ATR reception duration timeout */
#define SCI_IER_ATR_STOUT_IE                ((uint16_t)0x0020)            /*!< ATR reception start timeout */
#define SCI_IER_TX_ERR_IE                   ((uint16_t)0x0010)            /*!< Character transmission error */

/* ====================== Bit definition for SCI_FR register  ====================== */
#define SCI_FSR_RFE                         ((uint8_t)0x08)               /*!< RXFIFO empty status */
#define SCI_FSR_RFF                         ((uint8_t)0x04)               /*!< RXFIFO full status */
#define SCI_FSR_TFE                         ((uint8_t)0x02)               /*!< TXFIFO empty status */
#define SCI_FSR_TFF                         ((uint8_t)0x01)               /*!< TXFIFO full status */

/* ====================== Bit definition for SCI_ISTAT register  ====================== */
#define SCI_ICCSR_CARDPRESENT               ((uint16_t)0x0200)            /*!< Smart card present */
#define SCI_ICCSR_NDATAEN                   ((uint16_t)0x0100)            /*!< Tristate control for external off-chip buffer for data */
#define SCI_ICCSR_NDATAOUTEN                ((uint16_t)0x0080)            /*!< Tristate output buffer control for data */
#define SCI_ICCSR_CLKOUT                    ((uint16_t)0x0040)            /*!< Smart card clock output */
#define SCI_ICCSR_NCLKEN                    ((uint16_t)0x0020)            /*!< Tristate control for external off-chip buffer for clock */
#define SCI_ICCSR_NCLKOUTEN                 ((uint16_t)0x0010)            /*!< Tristate output buffer control for clock */
#define SCI_ICCSR_DATAEN                    ((uint16_t)0x0008)            /*!< Enable smart card data */
#define SCI_ICCSR_CLKEN                     ((uint16_t)0x0004)            /*!< Enable smart card clock */
#define SCI_ICCSR_CRESETEN                  ((uint16_t)0x0002)            /*!< Controls smart card reset signal */

/* ====================== Bit definition for SCI_IOCR register  ====================== */
#define SCI_IOCR_SELCLK                     ((uint8_t)0x02)               /*!< Selects the source of the smart card clock */
#define SCI_IOCR_SELDATA                    ((uint8_t)0x01)               /*!< Selects the signal used to drive the in/out lline */

/* ====================== Bit definition for SCI_SYNCDATA register  ====================== */
#define SCI_IOSYNC_WCLKEN                   ((uint8_t)0x08)               /*!< Control the SCICLKEN line */
#define SCI_IOSYNC_WDATAEN                  ((uint8_t)0x04)               /*!< Control the SCIDATAEN line */
#define SCI_IOSYNC_WCLK                     ((uint8_t)0x02)               /*!< drive the smart card clock */
#define SCI_IOSYNC_WDATA                    ((uint8_t)0x01)               /*!< drive the in/out line */

/* ====================== Bit definition for SCI_RAWSTAT register  ====================== */
#define SCI_IOSR_RCLK                       ((uint8_t)0x02)               /*!< Raw value of the clock */
#define SCI_IOSR_RLDATA                     ((uint8_t)0x01)               /*!< Raw value of the in/out lline */

/* ====================== Bit definition for SCI_IIR register  ====================== */
#define SCI_ISR_TF_THOD_INTR                ((uint16_t)0x0800)            /*!< Transmit FIFO tide mark */
#define SCI_ISR_RF_THOD_INTR                ((uint16_t)0x0400)            /*!< Receive FIFO tide mark */
#define SCI_ISR_RF_TOUT_INTR                ((uint16_t)0x0200)            /*!< Receive FIFO read timeout */
#define SCI_ISR_CH_TOUT_INTR                ((uint16_t)0x0100)            /*!< Between character timeout */
#define SCI_IIR_BLK_TOUT_INTR               ((uint16_t)0x0080)            /*!< Between block timeout */
#define SCI_IIR_ATR_DTOUT_INTR              ((uint16_t)0x0040)            /*!< ATR reception duration timeout */
#define SCI_IIR_ATR_STOUT_INTR              ((uint16_t)0x0020)            /*!< ATR reception start timeout */
#define SCI_IIR_TX_ERR_INTR                 ((uint16_t)0x0010)            /*!< Character transmission error */

/* =========================================================================================================================== */
/* ================              Secure Digital memory card Device Controller                                ================= */
/* =========================================================================================================================== */

/* ====================== Bit definition for DMA1CR register  ====================== */
#define  SDDC_DMA1CR_DMA_EN                 ((uint32_t)0x00000001)

/* =========================================================================================================================== */
/* ================              SDHC Interface                                                           ================= */
/* =========================================================================================================================== */
/* ====================== Bit definition for SDHC Transfer Mode register  ====================== */
#define SDHC_TMR_MULTI_BLK_SEL              ((uint16_t)0x0020)            /*!< Single/Multi-block selection */
#define SDHC_TMR_TRAN_DIR_SEL               ((uint16_t)0x0010)            /*!< Data transfer direction selection */
#define SDHC_TMR_AUTO_CMD_EN                ((uint16_t)0x000C)            /*!< Auto CMD enable */
#define SDHC_TMR_AUTO_CMD_EN_0              ((uint16_t)0x0004)            /*!< Bit 0 */
#define SDHC_TMR_AUTO_CMD_EN_1              ((uint16_t)0x0008)            /*!< Bit 1 */
#define SDHC_TMR_BLK_CNT_EN                 ((uint16_t)0x0002)            /*!< Block count enable */
#define SDHC_TMR_DMA_EN                     ((uint16_t)0x0001)            /*!< DMA enable */

/* ====================== Bit definition for SDHC Present state register  ====================== */
#define SDHC_SR_CMD_LINE_LV                 ((uint32_t)0x01000000)        /*!< Command Line Signal Level  */
#define SDHC_SR_DATA_LINE_LV                ((uint32_t)0x00F00000)        /*!< DATA[3:0] Line Signal Level */
#define SDHC_SR_DATA_LINE_LV_0              ((uint32_t)0x00100000)        /*!< Bit 0 */
#define SDHC_SR_DATA_LINE_LV_1              ((uint32_t)0x00200000)        /*!< Bit 1 */
#define SDHC_SR_DATA_LINE_LV_2              ((uint32_t)0x00400000)        /*!< Bit 2 */
#define SDHC_SR_DATA_LINE_LV_3              ((uint32_t)0x00800000)        /*!< Bit 3 */
#define SDHC_SR_WR_PROT_LV                  ((uint32_t)0x00080000)        /*!< Write Protect Pin Level */
#define SDHC_SR_CD_PIN_LV                   ((uint32_t)0x00040000)        /*!< Card Detect Pin Level */
#define SDHC_SR_SYS_CARD_STABLE             ((uint32_t)0x00020000)        /*!< Card State Stable */
#define SDHC_SR_SYS_CARD_INSERT             ((uint32_t)0x00010000)        /*!< Card State Stable */
#define SDHC_SR_BUF_REN                     ((uint32_t)0x00000800)        /*!< Buffer Read Enable */
#define SDHC_SR_BUF_WEN                     ((uint32_t)0x00000400)        /*!< Buffer Write Enable */
#define SDHC_SR_RD_TRAN_ACT                 ((uint32_t)0x00000200)        /*!< Read Transfer Active */
#define SDHC_SR_WR_TRAN_ACT                 ((uint32_t)0x00000100)        /*!< Write Transfer Active */
#define SDHC_SR_DATA_LIN_ACT                ((uint32_t)0x00000004)        /*!< Data Line Active */
#define SDHC_SR_CMD_INHIBIT_D               ((uint32_t)0x00000002)        /*!< Command Inhibit(DAT) */
#define SDHC_SR_CMD_INHIBIT_C               ((uint32_t)0x00000001)        /*!< Command Inhibit(CMD) */

/* ====================== Bit definition for SDHC Block Gap Control register  ================== */
#define SDHC_BGCR_INT_AT_BLK_GAP            ((uint8_t)0x08)               /*!< Interrupt at Block Gap */
#define SDHC_BGCR_READ_WAIT                 ((uint8_t)0x04)               /*!< Read Wait Control */
#define SDHC_BGCR_CONT_REQ                  ((uint8_t)0x02)               /*!< Continue Request */
#define SDHC_BGCR_SP_BLK_GAP_REQ            ((uint8_t)0x01)               /*!< Stop at Block Gap */

/* ====================== Bit definition for SDHC Clock Control register  ====================== */
#define SDHC_CCR_LOW_BIT_SD_CLK_DIV         ((uint16_t)0xFF00)            /*!< SD Clock Frequency Value[7:0] */
#define SDHC_CCR_LOW_BIT_SD_CLK_DIV_0       ((uint16_t)0x0100)            /*!< Bit 0 */
#define SDHC_CCR_LOW_BIT_SD_CLK_DIV_1       ((uint16_t)0x0200)            /*!< Bit 1 */
#define SDHC_CCR_LOW_BIT_SD_CLK_DIV_2       ((uint16_t)0x0400)            /*!< Bit 2 */
#define SDHC_CCR_LOW_BIT_SD_CLK_DIV_3       ((uint16_t)0x0800)            /*!< Bit 3 */
#define SDHC_CCR_LOW_BIT_SD_CLK_DIV_4       ((uint16_t)0x1000)            /*!< Bit 4 */
#define SDHC_CCR_LOW_BIT_SD_CLK_DIV_5       ((uint16_t)0x2000)            /*!< Bit 5 */
#define SDHC_CCR_LOW_BIT_SD_CLK_DIV_6       ((uint16_t)0x4000)            /*!< Bit 6 */
#define SDHC_CCR_LOW_BIT_SD_CLK_DIV_7       ((uint16_t)0x8000)            /*!< Bit 7 */
#define SDHC_CCR_UPPER_BIT_SD_CLK_DIV       ((uint16_t)0x00C0)            /*!< SD Clock Frequency Value[9:8] */
#define SDHC_CCR_UPPER_BIT_SD_CLK_DIV_0     ((uint16_t)0x0040)            /*!< Bit 0 */
#define SDHC_CCR_UPPER_BIT_SD_CLK_DIV_1     ((uint16_t)0x0080)            /*!< Bit 1 */
#define SDHC_CCR_SDCLK_GEN_SEL              ((uint16_t)0x0020)            /*!< This bit is always set to zero */
#define SDHC_CCR_SD_CLK_EN                  ((uint16_t)0x0004)            /*!< SD Clock Enable */
#define SDHC_CCR_CLK_STABLE                 ((uint16_t)0x0002)            /*!< Internal Clock Stable */
#define SDHC_CCR_INTER_CLK_EN               ((uint16_t)0x0001)            /*!< Internal Clock Enable */

/* ====================== Bit definition for SDHC Software Reset register  ===================== */
#define SDHC_SRR_SOFT_RST_DAT               ((uint8_t)0x04)               /*!< Software Reset for Data Line */
#define SDHC_SRR_SOFT_RST_CMD               ((uint8_t)0x02)               /*!< Software Reset for Command Line */
#define SDHC_SRR_SOFT_RST_ALL               ((uint8_t)0x01)               /*!< Software Reset for All */

/* ====================== Bit definition for SDHC Normal Interrupt Status register  ============ */
#define SDHC_NISR_ERR_INTR                  ((uint16_t)0x8000)            /*!< Error Interrupt */
#define SDHC_NISR_CQ_INTR                   ((uint16_t)0x4000)            /*!< Command Queuing Interrupt */
#define SDHC_NISR_CARD_INTR                 ((uint16_t)0x0100)            /*!< Card Interrupt */
#define SDHC_NISR_CARD_REMOVE               ((uint16_t)0x0080)            /*!< Card Remove */
#define SDHC_NISR_CARD_INSERT               ((uint16_t)0x0040)            /*!< Card Insert */
#define SDHC_NISR_BUF_R_RDY                 ((uint16_t)0x0020)            /*!< Buffer Read Ready */
#define SDHC_NISR_BUF_W_RDY                 ((uint16_t)0x0010)            /*!< Buffer Write Ready */
#define SDHC_NISR_DMA_INTR                  ((uint16_t)0x0008)            /*!< DMA Interrupt */
#define SDHC_NISR_BLK_GAP_EVT               ((uint16_t)0x0004)            /*!< Block Gap Event */
#define SDHC_NISR_TRAN_COMPLETE             ((uint16_t)0x0002)            /*!< Transfer Complete */
#define SDHC_NISR_CMD_COMPLETE              ((uint16_t)0x0001)            /*!< Command Complete */

/* ====================== Bit definition for SDHC Error Interrupt Status register  ============= */
#define SDHC_EISR_TUNING_ERR                ((uint16_t)0x0400)            /*!< Tuning Error */
#define SDHC_EISR_ADMA_ERR                  ((uint16_t)0x0200)            /*!< ADMA Error */
#define SDHC_EISR_AUTO_CMD12_ERR            ((uint16_t)0x0100)            /*!< Auto CMD 12 Error */
#define SDHC_EISR_DATA_END_BIT_ERR          ((uint16_t)0x0040)            /*!< Data End Bit Error */
#define SDHC_EISR_DATA_CRC_ERR              ((uint16_t)0x0020)            /*!< Data CRC Error */
#define SDHC_EISR_DATA_TIMEOUT_ERR          ((uint16_t)0x0010)            /*!< Data Timeout Error */
#define SDHC_EISR_CMD_IDX_ERR               ((uint16_t)0x0008)            /*!< Command Index Error */
#define SDHC_EISR_CMD_END_BIT_ERR           ((uint16_t)0x0004)            /*!< Command End Bit Error */
#define SDHC_EISR_CMD_CRC_ERR               ((uint16_t)0x0002)            /*!< Command CRC Error */
#define SDHC_EISR_CMD_TIMEOUT_ERR           ((uint16_t)0x0001)            /*!< Command Timeout Error */

/* ====================== Bit definition for SDC Host or Device Mode Switch register  ========== */
#define SDC_SR_HOST_SEL                     ((uint32_t)0x00000001)        /*!< Mode Switch */

/* ====================== Bit definition for SDC System Control register  ====================== */
#define SDC_SYSCR_SD_POWER_3V3_EN           ((uint32_t)0x00000100)        /*!< Power Selector */
#define SDC_SYSCR_SD_POWER_EN               ((uint32_t)0x00000080)        /*!< Power Enable */
#define SDC_SYSCR_LIMIT_INDICATE            ((uint32_t)0x00000002)        /*!< Current Limit Indicat */
#define SDC_SYSCR_IO_VOLT_SW_FAIL           ((uint32_t)0x00000001)        /*!< IO Voltage Switch Fail Indicat */

/* ====================== Bit definition for SDC DLL Control register  ========================= */
#define SDC_DLLCR_FLDO                      ((uint32_t)0x00000100)        /*!< Frequency Lock Indicate */
#define SDC_DLLCR_POWER_ON                  ((uint32_t)0x00000001)        /*!< DLL Power Enable */

/* ====================== Bit definition for SDC IO Control register  ========================== */
#define SDC_IOCR_LEVEL_SHIFT                ((uint32_t)0x00000400)        /*!< Level Shift Control */
#define SDC_IOCR_DATA_PULL_DOWN             ((uint32_t)0x00000200)        /*!< Data Pull Down */
#define SDC_IOCR_DATA_PULL_UP               ((uint32_t)0x00000100)        /*!< Data Pull Up */
#define SDC_IOCR_CMD_PULL_DOWN              ((uint32_t)0x00000080)        /*!< Command Pull Down */
#define SDC_IOCR_CMD_PULL_UP                ((uint32_t)0x00000040)        /*!< Command Pull Up */

/* =========================================================================================================================== */
/* ================              Synchronous Serial Peripheral                                               ================= */
/* =========================================================================================================================== */
/* ====================== Bit definition for SSP_I2S_CR0 register  ====================== */
#define SSP_I2S_CR0_SPICONTX                ((uint32_t)0x00080000)        /*!< SPI Continuous Transfer control */
#define SSP_I2S_CR0_FLASHTX                 ((uint32_t)0x00040000)        /*!< FLASH Transmit control */
#define SSP_I2S_CR0_SPI_SSPO                ((uint32_t)0x00008000)        /*!< Frame/Sync. polarity for the SPI mode */
#define SSP_I2S_CR0_FFMT                    ((uint32_t)0x00007000)        /*!< FFMT[14:12] bits Frame format */
#define SSP_I2S_CR0_FFMT_SSP                ((uint32_t)0x00000000)        /*!< Frame format ssp */
#define SSP_I2S_CR0_FFMT_SPI                ((uint32_t)0x00001000)        /*!< Frame format spi */
#define SSP_I2S_CR0_FFMT_MWR                ((uint32_t)0x00002000)        /*!< Frame format microwire */
#define SSP_I2S_CR0_FFMT_I2S                ((uint32_t)0x00003000)        /*!< Frame format i2s */
#define SSP_I2S_CR0_FLASH                   ((uint32_t)0x00000800)        /*!< This bit indicates that the current application is SPI Flash */
#define SSP_I2S_CR0_SSDIST_MASK             ((uint32_t)0x00000300)        /*!< Frame/Sync. and data distance mask */
#define SSP_I2S_CR0_SSDIST_I2S              ((uint32_t)0x00000100)        /*!< Frame/Sync. and data distance */
#define SSP_I2S_CR0_LBM                     ((uint32_t)0x00000080)        /*!< Loopback mode */
#define SSP_I2S_CR0_LSB                     ((uint32_t)0x00000040)        /*!< Bit sequence indicator */
#define SSP_I2S_CR0_SSPO                    ((uint32_t)0x00000020)        /*!< Frame/Sync. polarity */
#define SSP_I2S_CR0_DATA_JUSTIFY            ((uint32_t)0x00000010)        /*!< Data justify */
#define SSP_I2S_CR0_OPM                     ((uint32_t)0x0000000C)        /*!< OPM[3:2] bits operation mode */
#define SSP_I2S_CR0_SCKPO                   ((uint32_t)0x00000002)        /*!< SCK polarity */
#define SSP_I2S_CR0_SCKPH                   ((uint32_t)0x00000001)        /*!< SCK phase */

/* ====================== Bit definition for SSP_I2S_CR1 register  ====================== */
#define SSP_I2S_CR1_PDL                     ((uint32_t)0xFF000000)        /*!< PDL[31:24] Padding data length */
#define SSP_I2S_CR1_SDL                     ((uint32_t)0x007F0000)        /*!< SDL[22:16] Serial data length */
#define SSP_I2S_CR1_SCKDIV                  ((uint32_t)0x0000FFFF)        /*!< SCKDIV[15:0] SCLK divider */

/* ====================== Bit definition for SSP_I2S_CR2 register  ====================== */
#define SSP_I2S_CR2_SS                      ((uint16_t)0x0200)            /*!< Frame Sync. output */
#define SSP_I2S_CR2_TXEN                    ((uint16_t)0x0100)            /*!< Transmit Function Enable */
#define SSP_I2S_CR2_RXEN                    ((uint16_t)0x0080)            /*!< Receive Function Enable */
#define SSP_I2S_CR2_SSPRST                  ((uint16_t)0x0040)            /*!< SSP Reset */
#define SSP_I2S_CR2_TXFCLR                  ((uint16_t)0x0008)            /*!< Transmit FIFO Clear */
#define SSP_I2S_CR2_RXFCLR                  ((uint16_t)0x0004)            /*!< Receive FIFO Clear */
#define SSP_I2S_CR2_TXOE                    ((uint16_t)0x0002)            /*!< Transmit Data Output Enable */
#define SSP_I2S_CR2_SSPEN                   ((uint16_t)0x0001)            /*!< SSP Enable */

/* ====================== Bit definition for SSP_I2S_SR register  ====================== */
#define SSP_I2S_SR_TFVE                     ((uint32_t)0x0003F000)        /*!< TFVE[17:12] Transmit FIFO Valid Entry */
#define SSP_I2S_SR_RFVE                     ((uint32_t)0x000003F0)        /*!< RFVE[9:4] Receive FIFO Valid Entry */
#define SSP_I2S_SR_BUSY                     ((uint32_t)0x00000004)        /*!< Busy Indicator */
#define SSP_I2S_SR_TFNF                     ((uint32_t)0x00000002)        /*!< Transmit FIFO Not Full */
#define SSP_I2S_SR_RFF                      ((uint32_t)0x00000001)        /*!< Receive FIFO Full */

/* ====================== Bit definition for SSP_I2S_ICR register  ====================== */
#define SSP_I2S_ICR_TXCIEN                  ((uint32_t)0x00040000)        /*!< Transmit Data Complete Interrupt Enable */
#define SSP_I2S_ICR_RFTHOD_UINT             ((uint32_t)0x00020000)        /*!< Receive FIFO Threshold Unit */
#define SSP_I2S_ICR_TFTHOD                  ((uint32_t)0x0001F000)        /*!< TFTHOD[16:12] Transmit FIFO Threshold */
#define SSP_I2S_ICR_RFTHOD                  ((uint32_t)0x00000F80)        /*!< RFTHOD[11:7] Receive FIFO Threshold */
#define SSP_I2S_ICR_TFDMAEN                 ((uint32_t)0x00000020)        /*!< Transmit DMA Request Enable */
#define SSP_I2S_ICR_RFDMAEN                 ((uint32_t)0x00000010)        /*!< Receive DMA Request Enable */
#define SSP_I2S_ICR_TFTHIEN                 ((uint32_t)0x00000008)        /*!< Transmit FIFO Threshold Interrupt Enable */
#define SSP_I2S_ICR_RFTHIEN                 ((uint32_t)0x00000004)        /*!< Receive FIFO Threshold Interrupt Enable */
#define SSP_I2S_ICR_TFURIEN                 ((uint32_t)0x00000002)        /*!< Transmit FIFO Underrun Interrupt Enable */
#define SSP_I2S_ICR_RFORIEN                 ((uint32_t)0x00000001)        /*!< Receive FIFO Overrun Interrupt Enable */

/* ====================== Bit definition for SSP_I2S_ISR register  ====================== */
#define SSP_I2S_ISR_TXCI                    ((uint8_t)0x20)               /*!< Transmit Data Complete Interrupt */
#define SSP_I2S_ISR_TFTHI                   ((uint8_t)0x08)               /*!< Transmit FIFO Threshold Interrupt */
#define SSP_I2S_ISR_RFTHI                   ((uint8_t)0x04)               /*!< Receive FIFO Threshold Interrupt */
#define SSP_I2S_ISR_TFURI                   ((uint8_t)0x02)               /*!< Transmit FIFO Underrun Interrupt */
#define SSP_I2S_ISR_RFORI                   ((uint8_t)0x01)               /*!< Receive FIFO Overrun Interrupt */

/* ====================== Bit definition for SSP_I2S_CR3 register  ====================== */
#define SSP_I2S_CR3_DPDL                    ((uint32_t)0x00FF0000)        /*!< DPDL[23:16] Different Padding Data Length */
#define SSP_I2S_CR3_DPDLEN                  ((uint32_t)0x00001000)        /*!< Different Padding Data Length Enable */
#define SSP_I2S_CR3_PCL                     ((uint32_t)0x000003FF)        /*!< PCL[9:0] Padding Cycle Length(SPI only) */

/* =========================================================================================================================== */
/* ================              Synchronous Serial Interface                                                ================= */
/* =========================================================================================================================== */
/* ====================== Bit definition for CR0 register  ====================== */
#define SPI_CR0_SSTE                        ((uint32_t)0x01000000)        /*!< Slave Select Toggle Enable */
#define SPI_CR0_SPI_FRF                     ((uint32_t)0x00600000)        /*!< SPI Frame Format */
#define SPI_CR0_DFS                         ((uint32_t)0x001F0000)        /*!< Data Frame Size */
#define SPI_CR0_CFS                         ((uint32_t)0x0000F000)        /*!< Control Frame Size */
#define SPI_CR0_SRL                         ((uint32_t)0x00008000)        /*!< Shift Register Loop */
#define SPI_CR0_TMOD                        ((uint32_t)0x00000300)        /*!< Transfer Mode */
#define SPI_CR0_SCPOL                       ((uint32_t)0x00000080)        /*!< Serial Clock Polarity */
#define SPI_CR0_SCPH                        ((uint32_t)0x00000040)        /*!< Serial Clock Phase */
#define SPI_CR0_FRF                         ((uint32_t)0x00000030)        /*!< Frame Format */

/* ====================== Bit definition for CR1 register  ====================================== */
#define SPI_CR1_NDF                         ((uint32_t)0x0000FFFF)        /*!< Number of Data Frames */

/* ====================== Bit definition for ENR register  ====================================== */
#define SPI_ENR_SPI_EN                      ((uint32_t)0x00000001)        /*!< SPI Enable */

/* ====================== Bit definition for MWCR register  ===================================== */
#define SPI_MWCR_MHS                        ((uint32_t)0x00000004)        /*!< HANDSHAKE */
#define SPI_MWCR_MDD                        ((uint32_t)0x00000002)        /*!< data direction */
#define SPI_MWCR_MWMOD                      ((uint32_t)0x00000001)        /*!< sequential or no sequential */

/* ====================== Bit definition for SER register  ===================================== */
#define SPI_SER_CSER                        ((uint32_t)0x00000001)        /*!< Slave Select Enable */

/* ====================== Bit definition for CDR register  ====================================== */
#define SPI_CDR_SCKDV                       ((uint32_t)0x0000FFFF)        /*!< SPI Clock Divider */

/* ====================== Bit definition for TFTR register  ===================================== */
#define SPI_TFTR_TFT                        ((uint32_t)0x0000003F)        /*!< Transmit FIFO Threshold */

/* ====================== Bit definition for RFTR register  ===================================== */
#define SPI_RFTR_RFT                        ((uint32_t)0x0000003F)        /*!< Receive FIFO Threshold */

/* ====================== Bit definition for TFDCR register  ==================================== */
#define SPI_TFDCR_TFDC                      ((uint32_t)0x0000003F)        /*!< Transmit FIFO Level */

/* ====================== Bit definition for RFDCR register  ==================================== */
#define SPI_RFDCR_RXDC                      ((uint32_t)0x0000003F)        /*!< Receive FIFO Level */

/* ====================== Bit definition for SR register  ======================================= */
#define SPI_SR_TXE                          ((uint32_t)0x00000020)        /*!< Transmission Error */
#define SPI_SR_RFF                          ((uint32_t)0x00000010)        /*!< Receive FIFO Full */
#define SPI_SR_RFNE                         ((uint32_t)0x00000008)        /*!< Receive FIFO Not Empty */
#define SPI_SR_TFE                          ((uint32_t)0x00000004)        /*!< Transmit FIFO Empty */
#define SPI_SR_TFNF                         ((uint32_t)0x00000002)        /*!< Transmit FIFO Not Full */
#define SPI_SR_BUSY                         ((uint32_t)0x00000001)        /*!< SPI Busy Flag. */

/* ====================== Bit definition for IMR register  ====================================== */
#define SPI_IMR_MSTIM                       ((uint32_t)0x00000020)        /*!< Multi-Master Contention Interrupt Mask */
#define SPI_IMR_RFIM                        ((uint32_t)0x00000010)        /*!< Receive FIFO Full Interrupt Mask */
#define SPI_IMR_RXOIM                       ((uint32_t)0x00000008)        /*!< Receive FIFO Overflow Interrupt Mask */
#define SPI_IMR_RFUIM                       ((uint32_t)0x00000004)        /*!< Receive FIFO Underflow Interrupt Mask */
#define SPI_IMR_TFOIM                       ((uint32_t)0x00000002)        /*!< Transmit FIFO Overflow Interrupt Mask */
#define SPI_IMR_TFEIM                       ((uint32_t)0x00000001)        /*!< Transmit FIFO Empty Interrupt Mask */

/* ====================== Bit definition for ISR register  ====================================== */
#define SPI_ISR_MSTIS                       ((uint32_t)0x00000020)        /*!< Multi-Master Contention Interrupt Status. */
#define SPI_ISR_RFFIS                       ((uint32_t)0x00000010)        /*!< Receive FIFO Full Interrupt Status. */
#define SPI_ISR_RFOIS                       ((uint32_t)0x00000008)        /*!< Receive FIFO Overflow Interrupt Status. */
#define SPI_ISR_RFUIS                       ((uint32_t)0x00000004)        /*!< Receive FIFO Underflow Interrupt Status. */
#define SPI_ISR_TFOIS                       ((uint32_t)0x00000002)        /*!< Transmit FIFO Overflow Interrupt Status. */
#define SPI_ISR_TFEIS                       ((uint32_t)0x00000001)        /*!< Transmit FIFO Empty Interrupt Status. */

/* ====================== Bit definition for RISR register  ===================================== */
#define SPI_RISR_MSTIS                      ((uint32_t)0x00000020)        /*!< Multi-Master Contention Raw Interrupt Status. */
#define SPI_RISR_RFFIS                      ((uint32_t)0x00000010)        /*!< Receive FIFO Full Raw Interrupt Status. */
#define SPI_RISR_RFOIS                      ((uint32_t)0x00000008)        /*!< Receive FIFO Overflow Raw Interrupt Status. */
#define SPI_RISR_RFUIS                      ((uint32_t)0x00000004)        /*!< Receive FIFO Underflow Raw Interrupt Status. */
#define SPI_RISR_TFOIS                      ((uint32_t)0x00000002)        /*!< Transmit FIFO Overflow Raw Interrupt Status. */
#define SPI_RISR_TFEIS                      ((uint32_t)0x00000001)        /*!< Transmit FIFO Empty Raw Interrupt Status. */

/* ====================== Bit definition for TFOICR register  =================================== */
#define SPI_TFOICR_TFOICR                   ((uint32_t)0x00000001)        /*!< Clear Transmit FIFO Overflow Interrupt */

/* ====================== Bit definition for RFOICR register  =================================== */
#define SPI_RFOICR_RFOICR                   ((uint32_t)0x00000001)        /*!< Clear Receive FIFO Overflow Interrupt */

/* ====================== Bit definition for RFUICR register  =================================== */
#define SPI_RFUICR_RFUICR                   ((uint32_t)0x00000001)        /*!< Clear Receive FIFO Underflow Interrupt */

/* ====================== Bit definition for MSTICR register  =================================== */
#define SPI_MSTICR_MSTICR                   ((uint32_t)0x00000001)        /*!< Clear Multi-Master Contention Interrupt */

/* ====================== Bit definition for ICR register  ====================================== */
#define SPI_ICR_ICR                         ((uint32_t)0x00000001)        /*!< Clear Interrupts */

/* ====================== Bit definition for DMACR register  ==================================== */
#define SPI_DMACR_TDMAE                     ((uint32_t)0x00000002)        /*!< Transmit DMA Enable */
#define SPI_DMACR_RDMAE                     ((uint32_t)0x00000001)        /*!< Receive DMA Enable */

/* ====================== Bit definition for DMATDTR register  ================================== */
#define SPI_DMATDTR_DMATDH                  ((uint32_t)0x0000003F)        /*!< Transmit Data Level */

/* ====================== Bit definition for DMARDTR register  ================================== */
#define SPI_DMARDTR_DMARDH                  ((uint32_t)0x0000003F)        /*!< Receive Data Level */

/* ====================== Bit definition for MLCR register  ===================================== */
#define SPI_MLCR_WAIT_CYCLES                ((uint32_t)0x0000F800)        /*!< Wait cycles */
#define SPI_MLCR_INST_L                     ((uint32_t)0x00000300)        /*!< Instruction Length */
#define SPI_MLCR_ADDR_L                     ((uint32_t)0x0000003C)        /*!< Address Length */
#define SPI_MLCR_TRANS_TYPE                 ((uint32_t)0x00000003)        /*!< Address and instruction transfer format */


/* =========================================================================================================================== */
/* ================                           Systerm Configure                                              ================= */
/* =========================================================================================================================== */


/* ====================  Bit definition for SYSCFG_ECR register  ====================== */
#define SYSCFG_ECR_ECCEN                    ((uint32_t)0x00000001)        /*!< SRAM ECC Control */

/* ====================  Bit definition for SYSCFG_WEEAR register  ================== */
#define SYSCFG_WEEAR_VAL                    ((uint32_t)0x0000FFFF)        /*!< SRAM Write ECC Error Address */

/* ====================  Bit definition for SYSCFG_WEEACNTR register  ================= */
#define SYSCFG_WEEACNTR_VAL                 ((uint32_t)0x00000007)        /*!< SRAM Write ECC Error Address Count */

/* ====================  Bit definition for SYSCFG_REEAR register  =================== */
#define SYSCFG_REEAR_VAL                    ((uint32_t)0x0000FFFF)        /*!< SRAM Read ECC Error Address */

/* ====================  Bit definition for SYSCFG_REEACNTR register =================== */
#define SYSCFG_REEACNTR_VAL                 ((uint32_t)0x00000007)        /*!< SRAM Read ECC Error Address Count */

/* ====================  Bit definition for SYSCFG_AXICER0 register  ====================== */
#define SYSCFG_AXICER0_PCIES0               ((uint32_t)0x00000001)        /*!< CRC Error Status of PCIE Data Slave0 */
#define SYSCFG_AXICER0_DDRS1                ((uint32_t)0x00000002)        /*!< CRC Error Status of DDR Data Slave1 */
#define SYSCFG_AXICER0_FMC1XIPS             ((uint32_t)0x00000004)        /*!< CRC Error Status of FMC1 XIP Data Slave */
#define SYSCFG_AXICER0_FMC0XIPS             ((uint32_t)0x00000008)        /*!< CRC Error Status of FMC0 XIP Data Slave */
#define SYSCFG_AXICER0_APB2S                ((uint32_t)0x00000010)        /*!< CRC Error Status of CFG X2P bridge Data Slave */
#define SYSCFG_AXICER0_APB1S                ((uint32_t)0x00000020)        /*!< CRC Error Status of LPC X2P bridge Data Slave */
#define SYSCFG_AXICER0_APB0S                ((uint32_t)0x00000040)        /*!< CRC Error Status of REE X2P bridge Data Slave */
#define SYSCFG_AXICER0_USB3S                ((uint32_t)0x00000800)        /*!< CRC Error Status of USB3 Register Slave */
#define SYSCFG_AXICER0_PCIERS               ((uint32_t)0x00001000)        /*!< CRC Error Status of PCIE Register Slave */
#define SYSCFG_AXICER0_GMAC1S               ((uint32_t)0x00002000)        /*!< CRC Error Status of GMAC1 Register Slave */
#define SYSCFG_AXICER0_GMAC0S               ((uint32_t)0x00004000)        /*!< CRC Error Status of GMAC0 Register Slave */
#define SYSCFG_AXICER0_HSMS_0               ((uint32_t)0x00008000)        /*!< CRC Error 1 Status of HSM Data Slave */
#define SYSCFG_AXICER0_HSMS_1               ((uint32_t)0x00010000)        /*!< CRC Error 0 Status of HSM Data slave */
#define SYSCFG_AXICER0_UX608LS              ((uint32_t)0x00020000)        /*!< CRC Error Status of Co-CPU Data slave */
#define SYSCFG_AXICER0_SRAMS                ((uint32_t)0x00040000)        /*!< CRC Error Status of SRAM */
#define SYSCFG_AXICER0_ROMS                 ((uint32_t)0x00080000)        /*!< CRC Error Status of ROM */
#define SYSCFG_AXICER0_PCIES                ((uint32_t)0x00100000)        /*!< CRC Error Status of PCIE Data Slave1 */
#define SYSCFG_AXICER0_DDRDS                ((uint32_t)0x00200000)        /*!< CRC Error Status of DDR Data Slave2 */
#define SYSCFG_AXICER0_PCIEM                ((uint32_t)0x01000000)        /*!< CRC Error Status of PCIE Master */
#define SYSCFG_AXICER0_DMA1M                ((uint32_t)0x02000000)        /*!< CRC Error Status of DMA1 Master */
#define SYSCFG_AXICER0_DMA0M                ((uint32_t)0x04000000)        /*!< CRC Error Status of DMA0 Master */
#define SYSCFG_AXICER0_HSMM_1               ((uint32_t)0x20000000)        /*!< CRC Error 1 Status of HSM SYM Master */
#define SYSCFG_AXICER0_HSMM_0               ((uint32_t)0x40000000)        /*!< CRC Error 0 Status of HSM SYM Master */

/* ====================  Bit definition for SYSCFG_AXICER1 register  ====================== */
#define SYSCFG_AXICER1_UX608LM              ((uint32_t)0x00000001)        /*!< CRC Error Status of UX608Lite Master */
#define SYSCFG_AXICER1_UX608M               ((uint32_t)0x00000002)        /*!< CRC Error Status of UX608 Master */
#define SYSCFG_AXICER1_USB3M                ((uint32_t)0x00000008)        /*!< CRC Error Status of USB3 Master */
#define SYSCFG_AXICER1_GMAC1M               ((uint32_t)0x00000010)        /*!< CRC Error Status of GMAC1 Master */
#define SYSCFG_AXICER1_GMAC0M               ((uint32_t)0x00000020)        /*!< CRC Error Status of GMAC0 Master */


/* ====================  Bit definition for SYSCFG_AXICECNTR register  ====================== */
#define SYSCFG_AXICECNTR_VAL                ((uint32_t)0x00000007)        /*!< AXI CRC Error Count */

/* ====================  Bit definition for SYSCFG_AHB0CER register  ====================== */
#define SYSCFG_AHB0CER_DDRDS                ((uint32_t)0x00000001)        /*!< CRC Error Status of DDR Data Slave3 */
#define SYSCFG_AHB0CER_SDHC1S               ((uint32_t)0x00000008)        /*!< CRC Error Status of SDHC1 Register Slave */
#define SYSCFG_AHB0CER_SDHC0S               ((uint32_t)0x00000010)        /*!< CRC Error Status of SDHC0 Register Slave */
#define SYSCFG_AHB0CER_MAC1S                ((uint32_t)0x00000020)        /*!< CRC Error Status of MAC1 Register Slave */
#define SYSCFG_AHB0CER_MAC0S                ((uint32_t)0x00000040)        /*!< CRC Error Status of MAC0 Register Slave */
#define SYSCFG_AHB0CER_SDHC2S               ((uint32_t)0x00000100)        /*!< CRC Error Status of SDHC2 Register Slave */
#define SYSCFG_AHB0CER_USB2S                ((uint32_t)0x00000200)        /*!< CRC Error Status of USB2 Register Slave */
#define SYSCFG_AHB0CER_FMS1CMDS             ((uint32_t)0x00000400)        /*!< CRC Error Status of FMS1 CMD Data Slave */
#define SYSCFG_AHB0CER_FMS0CMDS             ((uint32_t)0x00001000)        /*!< CRC Error Status of FMS0 CMD Data Slave */
#define SYSCFG_AHB0CER_LTDCM                ((uint32_t)0x00002000)        /*!< CRC Error Status of LTDC Master */
#define SYSCFG_AHB0CER_MAC1M                ((uint32_t)0x00004000)        /*!< CRC Error Status of MAC1 Master */
#define SYSCFG_AHB0CER_MAC0M                ((uint32_t)0x00008000)        /*!< CRC Error Status of MAC0 Master */
#define SYSCFG_AHB0CER_SDHC2M               ((uint32_t)0x00010000)        /*!< CRC Error Status of SDHC2 Master */
#define SYSCFG_AHB0CER_SDHC1M               ((uint32_t)0x00020000)        /*!< CRC Error Status of SDHC1 Master */
#define SYSCFG_AHB0CER_SDHC0M               ((uint32_t)0x00040000)        /*!< CRC Error Status of SDHC0 Master */
#define SYSCFG_AHB0CER_USB2M                ((uint32_t)0x00080000)        /*!< CRC Error Status of USB2 Master */

/* ====================  Bit definition for SYSCFG_AHB0CECNTR register  ====================== */
#define SYSCFG_AHB0CECNTR_VAL               ((uint32_t)0x00000007)        /*!< AHB CRC Error Count */

/* =========================================================================================================================== */
/* ================                   TIM                                                                    ================= */
/* =========================================================================================================================== */
/* ====================== Bit definition for TIM_CR register  ====================== */
#define TIM_CR_MOD                          ((uint32_t)0x00000003)        /*!< Counter MODE */
#define TIM_CR_MOD_0                        ((uint32_t)0x00000001)        /*!< Bit 0 */
#define TIM_CR_MOD_1                        ((uint32_t)0x00000001)        /*!< Bit 0 */
#define TIM_CR_START                        ((uint32_t)0x00000004)        /*!< Counter enable */
#define TIM_CR_IMM_LOAD                     ((uint32_t)0x00000008)        /*!< Immediate load */
#define TIM_CR_INV                          ((uint32_t)0x00000010)        /*!< Complement invert output */
#define TIM_CR_AUTO_RELOAD                  ((uint32_t)0x00000020)        /*!< Auto reload or One pulse mode */
#define TIM_CR_DEBUG_MODE                   ((uint32_t)0x00000040)        /*!< Debug mode enable */

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

/* =========================================================================================================================== */
/* ================                   WDG                                                                    ================= */
/* =========================================================================================================================== */
/* ====================== Bit definition for WDG_CNT register  ====================== */
#define WDG_CNT_VAL                         ((uint32_t)0xFFFFFFFF)        /*!< WDG Counter Value */

/* ====================== Bit definition for WDG_RSR register  ====================== */
#define WDG_RSR_VAL                         ((uint32_t)0xFFFFFFFF)        /*!< WDG Reset Value */

/* ====================== Bit definition for WDG_ISR register  ====================== */
#define WDG_ISR_ISR                         ((uint32_t)0x00000001)        /*!< WDG Interrupt Status */
#define WDG_ISR_EISR                        ((uint32_t)0x00000002)        /*!< WDG Eraly Interrupt Status */

/* ====================== Bit definition for WDG_Load register  ====================== */
#define WDG_LOAD_VAL                        ((uint32_t)0xFFFFFFFF)        /*!< WDG Load Value */

/* ====================== Bit definition for WDG_CR register  ====================== */
#define WDG_CR_EN                           ((uint32_t)0x00000001)        /*!< WDG Work Enable */
#define WDG_CR_RSTEN                        ((uint32_t)0x00000002)        /*!< WDG Reset Enable */
#define WDG_CR_INTREN                       ((uint32_t)0x00000004)        /*!< WDG Interrupt Status */
#define WDG_CR_DBGMODEEN                    ((uint32_t)0x00000020)        /*!< WDG Debug Mode Enable */

/* ====================== Bit definition for WDG_ICLR register  ====================== */
#define WDG_ICLR_INTRCLR                    ((uint32_t)0x00000001)        /*!< WDG Interrupt Clear */

/* ====================== Bit definition for WDG_EICR register  ====================== */
#define WDG_EICR_EINTREN                    ((uint32_t)0x00000001)        /*!< WDG Early Interrupt Enable */

/* ====================== Bit definition for WDG_EICLR register  ====================== */
#define WDG_EICLR_EINTRCLR                  ((uint32_t)0x00000001)        /*!< WDG Early Interrupt Clear */

/* ====================== Bit definition for WDG_PRES register  ====================== */
#define WDG_PRES_PRESCAL                    ((uint32_t)0x0000000F)        /*!< WDG pre-scal value */

/* ====================== Bit definition for WDG_EIVR register  ====================== */
#define WDG_EIVR_VAL                        ((uint32_t)0xFFFFFFFF)        /*!< WDG Early Interrupt Threshold value */


#ifdef __cplusplus
}
#endif

#endif  /* __T690_H */

/********* (C) COPYRIGHT TIHMicroelectronics *****END OF FILE******************/
