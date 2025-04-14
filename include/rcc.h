#ifndef RCC_H
#define RCC_H

#include <stdint.h>
#include "stm32wl55.h"

typedef struct {
    volatile uint32_t CR;             // 0x000 - Clock Control Register
    volatile uint32_t ICSCR;          // 0x004 - Internal Clock Sources Calibration Register
    volatile uint32_t CFGR;           // 0x008 - Clock Configuration Register
    volatile uint32_t PLLCFGR;        // 0x00C - PLL Configuration Register
    uint32_t RESERVED0[1];            // 0x010 - Reserved
    volatile uint32_t CIER;           // 0x018 - Clock Interrupt Enable Register
    volatile uint32_t CIFR;           // 0x01C - Clock Interrupt Flag Register
    volatile uint32_t CICR;           // 0x020 - Clock Interrupt Clear Register
    uint32_t RESERVED1;               // 0x024 - Reserved
    volatile uint32_t AHB1RSTR;       // 0x028
    volatile uint32_t AHB2RSTR;       // 0x02C
    volatile uint32_t AHB3RSTR;       // 0x030
    uint32_t RESERVED2;               // 0x034
    volatile uint32_t APB1RSTR1;      // 0x038
    volatile uint32_t APB1RSTR2;      // 0x03C
    volatile uint32_t APB2RSTR;       // 0x040
    volatile uint32_t APB3RSTR;       // 0x044
    volatile uint32_t AHB1ENR;        // 0x048
    volatile uint32_t AHB2ENR;        // 0x04C
    volatile uint32_t AHB3ENR;        // 0x050
    uint32_t RESERVED3;               // 0x054
    volatile uint32_t APB1ENR1;       // 0x058
    volatile uint32_t APB1ENR2;       // 0x05C
    volatile uint32_t APB2ENR;        // 0x060
    volatile uint32_t APB3ENR;        // 0x064
    volatile uint32_t AHB1SMENR;      // 0x068
    volatile uint32_t AHB2SMENR;      // 0x06C
    volatile uint32_t AHB3SMENR;      // 0x070
    uint32_t RESERVED4;               // 0x074
    volatile uint32_t APB1SMENR1;     // 0x078
    volatile uint32_t APB1SMENR2;     // 0x07C
    volatile uint32_t APB2SMENR;      // 0x080
    volatile uint32_t APB3SMENR;      // 0x084
    volatile uint32_t CCIPR;          // 0x088
    uint32_t RESERVED5;               // 0x08C
    volatile uint32_t BDCR;           // 0x090
    volatile uint32_t CSR;            // 0x094
    uint32_t RESERVED6[5];            // 0x098 - 0x0A4
    volatile uint32_t EXTCFGR;        // 0x108
    uint32_t RESERVED7[15];           // 0x10C - 0x144
    volatile uint32_t C2AHB1ENR;      // 0x148
    volatile uint32_t C2AHB2ENR;      // 0x14C
    volatile uint32_t C2AHB3ENR;      // 0x150
    uint32_t RESERVED8;               // 0x154
    volatile uint32_t C2APB1ENR1;     // 0x158
    volatile uint32_t C2APB1ENR2;     // 0x15C
    volatile uint32_t C2APB2ENR;      // 0x160
    volatile uint32_t C2APB3ENR;      // 0x164
    volatile uint32_t C2AHB1SMENR;    // 0x168
    volatile uint32_t C2AHB2SMENR;    // 0x16C
    volatile uint32_t C2AHB3SMENR;    // 0x170
    uint32_t RESERVED9;               // 0x174
    volatile uint32_t C2APB1SMENR1;   // 0x178
    volatile uint32_t C2APB1SMENR2;   // 0x17C
    volatile uint32_t C2APB2SMENR;    // 0x180
    volatile uint32_t C2APB3SMENR;    // 0x184
} RCC_TypeDef;

/* RCC Base Address */
#define RCC             ((RCC_TypeDef *) RCC_BASE)

#endif // STM32WL_RCC_H

