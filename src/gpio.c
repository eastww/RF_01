#include "stm32f0xx.h"
#include "gpio.h"

/* request for irq */
volatile uint8_t  cmt2300_irq_request;

#ifndef USE_CUBEIDE
void GPIO_Pin_Setting(GPIO_TypeDef *gpio, uint16_t nPin, GPIOSpeed_TypeDef speed, GPIOMode_TypeDef mode)
{

    GPIO_InitTypeDef GPIO_InitStructure;

    GPIO_InitStructure.GPIO_Pin = nPin;
    GPIO_InitStructure.GPIO_Speed = speed;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Mode = mode;
    GPIO_Init(gpio, &GPIO_InitStructure);
}
#endif

/* ************************************************************************
*  The following need to be modified by user
*  ************************************************************************ */

/* ************************************************************************ */
void spi_gpio_init(void)
{
#ifdef USE_CUBEIDE
	/* gpio will be inited in main.c automatically */
#else
    GPIO_InitTypeDef GPIO_InitStructure;

    /* CSB */
    GPIO_InitStructure.GPIO_Pin = cmt_spi_csb_pin;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_Init(cmt_spi_csb_port, &GPIO_InitStructure);
    /* SCL */
    GPIO_InitStructure.GPIO_Pin = cmt_spi_scl_pin;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_Init(cmt_spi_scl_port, &GPIO_InitStructure);
    /* DIO3 */
    GPIO_InitStructure.GPIO_Pin = cmt_spi_sda_pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(cmt_spi_gpio3_port, &GPIO_InitStructure);
    /* FCSB */
    GPIO_InitStructure.GPIO_Pin = cmt_spi_fcsb_pin;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_Init(cmt_spi_fcsb_port, &GPIO_InitStructure);
    /* SDA */
    GPIO_InitStructure.GPIO_Pin = cmt_spi_sda_pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(cmt_spi_sda_port, &GPIO_InitStructure);
#endif
}

void cmt_spi3_sda_out(void)
{
#ifdef USE_CUBEIDE
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	__HAL_RCC_GPIOA_CLK_ENABLE();

	GPIO_InitStruct.Pin = GPIO_RF_SDIO_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIO_RF_SDIO_GPIO_Port, &GPIO_InitStruct);
#else
    GPIO_InitTypeDef GPIO_InitStructure;

    GPIO_InitStructure.GPIO_Pin = cmt_spi_sda_pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(cmt_spi_sda_port, &GPIO_InitStructure);
#endif
}
void cmt_spi3_sda_in(void)
{
#ifdef USE_CUBEIDE
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	__HAL_RCC_GPIOA_CLK_ENABLE();

	GPIO_InitStruct.Pin = GPIO_RF_SDIO_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIO_RF_SDIO_GPIO_Port, &GPIO_InitStruct);
#else
    GPIO_InitTypeDef GPIO_InitStructure;

    GPIO_InitStructure.GPIO_Pin = cmt_spi_sda_pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(cmt_spi_sda_port, &GPIO_InitStructure);
#endif
}
void cmt_spi3_gpio3_out(void)
{
#ifdef USE_CUBEIDE
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	__HAL_RCC_GPIOA_CLK_ENABLE();

	GPIO_InitStruct.Pin = GPIO_RF_GPIO3_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIO_RF_GPIO3_GPIO_Port, &GPIO_InitStruct);
#else
    GPIO_InitTypeDef GPIO_InitStructure;

    GPIO_InitStructure.GPIO_Pin = cmt_spi_gpio3_pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(cmt_spi_gpio3_port, &GPIO_InitStructure);
#endif
}
void cmt_spi3_gpio3_in(void)
{
#ifdef USE_CUBEIDE
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	__HAL_RCC_GPIOA_CLK_ENABLE();

	GPIO_InitStruct.Pin = GPIO_RF_GPIO3_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(GPIO_RF_GPIO3_GPIO_Port, &GPIO_InitStruct);
#else
    GPIO_InitTypeDef GPIO_InitStructure;

    GPIO_InitStructure.GPIO_Pin = cmt_spi_gpio3_pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(cmt_spi_gpio3_port, &GPIO_InitStructure);

    cmt_spi3_gpio3_1();
#endif
}


void NVIC_Config(void)
{
#ifdef USE_CUBEIDE
	/* gpio will be inited in main.c automatically */
#else
  NVIC_InitTypeDef  NVIC_InitStructure;
  EXTI_InitTypeDef  EXTI_InitStructure;
  
  EXTI_ClearITPendingBit(EXTI_Line10);
  EXTI_InitStructure.EXTI_Line = EXTI_Line10;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;//配置IRQ为上升沿中断
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);
  
  SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOB, EXTI_PinSource10);
  
  /* Enable and set EXTI0 Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = EXTI4_15_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPriority = 0x00;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
#endif
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin == GPIO_RF_GPIO3_Pin)
	{
		cmt2300_irq_request = 1;
	}
}
