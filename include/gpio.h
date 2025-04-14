#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>
#include "stm32wl55.h"

// GPIO Register definition structure
typedef struct
{
    volatile uint32_t MODER;     // Mode register           Offset: 0x00
    volatile uint32_t OTYPER;    // Output type register     Offset: 0x04
    volatile uint32_t OSPEEDR;   // Output speed register    Offset: 0x08
    volatile uint32_t PUPDR;     // Pull-up/pull-down reg    Offset: 0x0C
    volatile uint32_t IDR;       // Input data register      Offset: 0x10
    volatile uint32_t ODR;       // Output data register     Offset: 0x14
    volatile uint32_t BSRR;      // Bit set/reset register   Offset: 0x18
    volatile uint32_t LCKR;      // Configuration lock reg   Offset: 0x1C
    volatile uint32_t AFRL;      // Alt function low reg     Offset: 0x20
    volatile uint32_t AFRH;      // Alt function high reg    Offset: 0x24
    volatile uint32_t BRR;       // Bit reset register       Offset: 0x28
} GPIO_RegDef_t;

// Enable Macros 
#define ENABLE     0
#define DISABLE    1

// GPIO Peripheral Clock Enable
#define GPIOA_CLK_EN()      (RCC->C2AHB2ENR |= ( 1 << 0))
#define GPIOB_CLK_EN()      (RCC->C2AHB2ENR |= ( 1 << 1))
#define GPIOC_CLK_EN()      (RCC->C2AHB2ENR |= ( 1 << 2))
#define GPIOH_CLK_EN()      (RCC->C2AHB2ENR |= ( 1 << 7))

// GPIO Peripheral Clock Disable
#define GPIOA_CLK_DI()      (RCC->C2AHB2ENR &= ~( 1 << 0))
#define GPIOB_CLK_DI()      (RCC->C2AHB2ENR &= ~( 1 << 1))
#define GPIOC_CLK_DI()      (RCC->C2AHB2ENR &= ~( 1 << 2))
#define GPIOH_CLK_DI()      (RCC->C2AHB2ENR &= ~( 1 << 7))


// GPIO Peripheral declarations
#define GPIOA   ((GPIO_RegDef_t *) GPIOA_BASE)
#define GPIOB   ((GPIO_RegDef_t *) GPIOB_BASE)
#define GPIOC   ((GPIO_RegDef_t *) GPIOC_BASE)
#define GPIOH   ((GPIO_RegDef_t *) GPIOH_BASE)


// GPIO Mode Macros
#define GPIO_MODE_INPUT        0x00U
#define GPIO_MODE_OUTPUT       0x01U
#define GPIO_MODE_ALTFN        0x02U
#define GPIO_MODE_ANALOG       0x03U
#define GPIO_MODE_IT_FT        0x04U  // Interrupt Falling Edge Trigger
#define GPIO_MODE_IT_RT        0x05U  // Interrupt Rising Edge Trigger
#define GPIO_MODE_IT_RFT       0x06U  // Interrupt Rising + Falling Edge

// Output Type
#define GPIO_OTYPE_PUSH_PULL   0x00U
#define GPIO_OTYPE_OPEN_DRAIN  0x01U

// Speed
#define GPIO_SPEED_LOW         0x00U
#define GPIO_SPEED_MEDIUM      0x01U
#define GPIO_SPEED_HIGH        0x02U
#define GPIO_SPEED_VERY_HIGH   0x03U

// Pull
#define GPIO_NO_PUPD           0x00U
#define GPIO_PULL_UP           0x01U
#define GPIO_PULL_DOWN         0x02U

// Pin state
#define GPIO_PIN_RESET         0
#define GPIO_PIN_SET           1

// ----------------------------
// GPIO Basic Functions
// ----------------------------
void GPIO_ClockControl(GPIO_RegDef_t *GPIOx, uint8_t EnOrDi)
void GPIO_Init(GPIO_RegDef_t *GPIOx, uint32_t pinNumber, uint32_t mode);
void GPIO_SetOutputType(GPIO_RegDef_t *GPIOx, uint32_t pinNumber, uint32_t type);
void GPIO_SetSpeed(GPIO_RegDef_t *GPIOx, uint32_t pinNumber, uint32_t speed);
void GPIO_SetPull(GPIO_RegDef_t *GPIOx, uint32_t pinNumber, uint32_t pull);
void GPIO_WritePin(GPIO_RegDef_t *GPIOx, uint32_t pinNumber, uint8_t value);
void GPIO_TogglePin(GPIO_RegDef_t *GPIOx, uint32_t pinNumber);
uint8_t GPIO_ReadPin(GPIO_RegDef_t *GPIOx, uint32_t pinNumber);
void GPIO_LockPin(GPIO_RegDef_t *GPIOx, uint32_t pinNumber);
void GPIO_SetAltFunction(GPIO_RegDef_t *GPIOx, uint32_t pinNumber, uint8_t altFunc);

// ----------------------------
// GPIO Interrupt Functions
// ----------------------------
void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnOrDi);
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);
void GPIO_IRQHandling(uint32_t pinNumber);
void GPIO_EXTI_Init(uint32_t pinNumber, uint8_t triggerType);

#endif // STM32WL_GPIO_H

