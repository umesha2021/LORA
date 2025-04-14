#include "gpio.h"
#include "stm32wl55.h"

// Helper macros
#define __GPIO_PIN_MASK(pin)      (1U << (pin))
#define __GPIO_PIN_SHIFT(pin)     ((pin) * 2)

// Enable Gpio Clock Control
void GPIO_ClockControl(GPIO_RegDef_t *GPIOx, uint8_t EnOrDi)
{
    if (EnOrDi)
    {
        if (GPIOx == GPIOA)
            GPIOA_CLK_EN();
        else if (GPIOx == GPIOB)
            GPIOB_CLK_EN();
        else if (GPIOx == GPIOC)
            GPIOC_CLK_EN();
        else if (GPIOx == GPIOH)
            GPIOH_CLK_EN();
    }
    else
    {
        if (GPIOx == GPIOA)
            GPIOA_CLK_DI();
        else if (GPIOx == GPIOB)
            GPIOB_CLK_DI();
        else if (GPIOx == GPIOC)
            GPIOC_CLK_DI();
        else if (GPIOx == GPIOH)
            GPIOH_CLK_DI();
    }
}


// Gpio Init Function
void GPIO_Init(GPIO_RegDef_t *GPIOx, uint32_t pinNumber, uint32_t mode) {
    // Clear existing mode bits
    GPIOx->MODER &= ~(0x3U << __GPIO_PIN_SHIFT(pinNumber));
    GPIOx->MODER |= ((mode & 0x3U) << __GPIO_PIN_SHIFT(pinNumber));
}

void GPIO_SetOutputType(GPIO_RegDef_t *GPIOx, uint32_t pinNumber, uint32_t type) {
    if (type == GPIO_OTYPE_OPEN_DRAIN)
        GPIOx->OTYPER |= __GPIO_PIN_MASK(pinNumber);
    else
        GPIOx->OTYPER &= ~__GPIO_PIN_MASK(pinNumber);
}

void GPIO_SetSpeed(GPIO_RegDef_t *GPIOx, uint32_t pinNumber, uint32_t speed) {
    GPIOx->OSPEEDR &= ~(0x3U << __GPIO_PIN_SHIFT(pinNumber));
    GPIOx->OSPEEDR |= ((speed & 0x3U) << __GPIO_PIN_SHIFT(pinNumber));
}

void GPIO_SetPull(GPIO_RegDef_t *GPIOx, uint32_t pinNumber, uint32_t pull) {
    GPIOx->PUPDR &= ~(0x3U << __GPIO_PIN_SHIFT(pinNumber));
    GPIOx->PUPDR |= ((pull & 0x3U) << __GPIO_PIN_SHIFT(pinNumber));
}

void GPIO_WritePin(GPIO_RegDef_t *GPIOx, uint32_t pinNumber, uint8_t value) {
    if (value)
        GPIOx->BSRR = __GPIO_PIN_MASK(pinNumber);
    else
        GPIOx->BRR = __GPIO_PIN_MASK(pinNumber);
}

void GPIO_TogglePin(GPIO_RegDef_t *GPIOx, uint32_t pinNumber) {
    GPIOx->ODR ^= __GPIO_PIN_MASK(pinNumber);
}

uint8_t GPIO_ReadPin(GPIO_RegDef_t *GPIOx, uint32_t pinNumber) {
    return (GPIOx->IDR & __GPIO_PIN_MASK(pinNumber)) ? GPIO_PIN_SET : GPIO_PIN_RESET;
}

void GPIO_LockPin(GPIO_RegDef_t *GPIOx, uint32_t pinNumber) {
    uint32_t temp = (1U << 16) | __GPIO_PIN_MASK(pinNumber);
    GPIOx->LCKR = temp;
    GPIOx->LCKR = __GPIO_PIN_MASK(pinNumber);
    GPIOx->LCKR = temp;
    (void)GPIOx->LCKR;
}

void GPIO_SetAltFunction(GPIO_RegDef_t *GPIOx, uint32_t pinNumber, uint8_t altFunc) {
    if (pinNumber < 8) {
        GPIOx->AFRL &= ~(0xFU << (pinNumber * 4));
        GPIOx->AFRL |= ((altFunc & 0xFU) << (pinNumber * 4));
    } else {
        pinNumber -= 8;
        GPIOx->AFRH &= ~(0xFU << (pinNumber * 4));
        GPIOx->AFRH |= ((altFunc & 0xFU) << (pinNumber * 4));
    }
}

// ------------------ Interrupt Functions ------------------

void GPIO_EXTI_Init(uint32_t pinNumber, uint8_t triggerType) {
    // Configure EXTI interrupt edge (not implemented here)
    // Use EXTI, SYSCFG to route GPIO pin to EXTI line
    // Configure trigger type in EXTI
    // Set NVIC enable (done in GPIO_IRQInterruptConfig)
}

void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnOrDi) {
    if (EnOrDi)
        NVIC_ISER0 |= (1 << IRQNumber);  // For IRQNumber < 32
    else
        NVIC_ICER0 |= (1 << IRQNumber);
}

void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority) {
    // This depends on NVIC_IPR register. Not implemented here.
}

void GPIO_IRQHandling(uint32_t pinNumber) {
    // Clear EXTI pending register
    // Example:
    // if (EXTI->PR & __GPIO_PIN_MASK(pinNumber))
    //     EXTI->PR |= __GPIO_PIN_MASK(pinNumber);
}

