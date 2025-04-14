/*
 * File: stm32wl55_base_addresses.h
 * Description: Base addresses of STM32WL55 peripheral registers
 * Generated for low-level MCU development
 */

#ifndef STM32WL55_H
#define STM32WL55_H

// ----------------- AHB1 Bus Peripherals -----------------
#define DMA1_BASE           0x40020000UL
#define DMA2_BASE           0x40020400UL
#define DMAMUX1_BASE        0x40020800UL
#define CRC_BASE            0x40023000UL

// ----------------- AHB2 Bus Peripherals -----------------
#define GPIOA_BASE          0x48000000UL
#define GPIOB_BASE          0x48000400UL
#define GPIOC_BASE          0x48000800UL
#define GPIOH_BASE          0x48001C00UL

// ----------------- AHB3 Bus Peripherals -----------------
#define RCC_BASE            0x58000000UL
#define PWR_BASE            0x58000400UL
#define EXTI_BASE           0x58000800UL
#define IPCC_BASE           0x58000C00UL
#define RNG_BASE            0x58001000UL
#define HSEM_BASE           0x58001400UL
#define AES_BASE            0x58001800UL
#define PKA_BASE            0x58002000UL
#define FLASH_BASE          0x58004000UL
#define GTZC_TZSC_BASE      0x58004400UL
#define GTZC_TZIC_BASE      0x58004800UL
#define SUBGHZSPI_BASE      0x58010000UL

// ----------------- APB1 Bus Peripherals -----------------
#define TIM2_BASE           0x40000000UL
#define RTC_BASE            0x40002800UL
#define WWDG_BASE           0x40002C00UL
#define IWDG_BASE           0x40003000UL
#define SPI2S2_BASE         0x40003800UL
#define USART2_BASE         0x40004400UL
#define I2C1_BASE           0x40005400UL
#define I2C2_BASE           0x40005800UL
#define I2C3_BASE           0x40005C00UL
#define DAC_BASE            0x40007400UL
#define LPUART1_BASE        0x40008000UL
#define LPTIM1_BASE         0x40007C00UL
#define LPTIM2_BASE         0x40009400UL
#define LPTIM3_BASE         0x40009800UL
#define TAMP_BASE           0x4000B000UL

// ----------------- APB2 Bus Peripherals -----------------
#define SYSCFG_BASE         0x40010000UL
#define VREFBUF_BASE        0x40010030UL
#define COMP_BASE           0x40010200UL
#define ADC_BASE            0x40012400UL
#define TIM1_BASE           0x40012C00UL
#define SPI1_BASE           0x40013000UL
#define USART1_BASE         0x40013800UL
#define TIM16_BASE          0x40014400UL
#define TIM17_BASE          0x40014800UL

// ----------------- APB3 Bus Peripherals -----------------
#define SUBGHZSPI_APB3_BASE 0x58010000UL

#endif // STM32WL55_BASE_ADDRESSES_H

