#include "stm32f0xx.h"
#include "gpio.h"

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

/* ************************************************************************
*  The following need to be modified by user
*  ************************************************************************ */

/* ************************************************************************ */
void spi_gpio_init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

//CSB
    GPIO_InitStructure.GPIO_Pin = cmt_spi_csb_pin;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_Init(cmt_spi_csb_port, &GPIO_InitStructure);
//SCL
    GPIO_InitStructure.GPIO_Pin = cmt_spi_scl_pin;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_Init(cmt_spi_scl_port, &GPIO_InitStructure);
//DIO3
    GPIO_InitStructure.GPIO_Pin = cmt_spi_sda_pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(cmt_spi_gpio3_port, &GPIO_InitStructure);
//FCSB
    GPIO_InitStructure.GPIO_Pin = cmt_spi_fcsb_pin;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_Init(cmt_spi_fcsb_port, &GPIO_InitStructure);
//SDA
    GPIO_InitStructure.GPIO_Pin = cmt_spi_sda_pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(cmt_spi_sda_port, &GPIO_InitStructure);
    
  
    
}

void cmt_spi3_sda_out(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    GPIO_InitStructure.GPIO_Pin = cmt_spi_sda_pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(cmt_spi_sda_port, &GPIO_InitStructure);
}
void cmt_spi3_sda_in(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    GPIO_InitStructure.GPIO_Pin = cmt_spi_sda_pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(cmt_spi_sda_port, &GPIO_InitStructure);
}
void cmt_spi3_gpio3_out(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    GPIO_InitStructure.GPIO_Pin = cmt_spi_gpio3_pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(cmt_spi_gpio3_port, &GPIO_InitStructure);
}
void cmt_spi3_gpio3_in(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    GPIO_InitStructure.GPIO_Pin = cmt_spi_gpio3_pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(cmt_spi_gpio3_port, &GPIO_InitStructure);

    cmt_spi3_gpio3_1();
}


void NVIC_Config(void)
{
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
}
