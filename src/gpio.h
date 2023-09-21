#ifndef _GPIO_H_
#define _GPIO_H_

#ifdef USE_CUBEIDE

#include <main.h>
#include "delay.h"

/* define spi */
#define cmt_spi_gpio3_port      GPIO_RF_GPIO3_GPIO_Port
#define cmt_spi_gpio3_pin       GPIO_RF_GPIO3_Pin

#define cmt_spi_csb_port        GPIO_RF_CSB_GPIO_Port
#define cmt_spi_csb_pin         GPIO_RF_CSB_Pin

#define cmt_spi_fcsb_port       GPIO_RF_FCSB_GPIO_Port
#define cmt_spi_fcsb_pin        GPIO_RF_FCSB_Pin

#define cmt_spi_scl_port        GPIO_RF_SCK_GPIO_Port
#define cmt_spi_scl_pin         GPIO_RF_SCK_Pin

#define cmt_spi_sda_port        GPIO_RF_SDIO_GPIO_Port
#define cmt_spi_sda_pin         GPIO_RF_SDIO_Pin

#define cmt_spi3_gpio3_1()      HAL_GPIO_WritePin(cmt_spi_gpio3_port, cmt_spi_gpio3_pin, GPIO_PIN_SET)
#define cmt_spi3_gpio3_0()      HAL_GPIO_WritePin(cmt_spi_gpio3_port, cmt_spi_gpio3_pin, GPIO_PIN_RESET)
#define cmt_spi3_gpio3_read()   HAL_GPIO_ReadPin(cmt_spi_gpio3_port, cmt_spi_gpio3_pin)

#define cmt_spi3_csb_1()        HAL_GPIO_WritePin(cmt_spi_csb_port, cmt_spi_csb_pin, GPIO_PIN_SET)
#define cmt_spi3_csb_0()        HAL_GPIO_WritePin(cmt_spi_csb_port, cmt_spi_csb_pin, GPIO_PIN_RESET)

#define cmt_spi3_fcsb_1()       HAL_GPIO_WritePin(cmt_spi_fcsb_port, cmt_spi_fcsb_pin, GPIO_PIN_SET)
#define cmt_spi3_fcsb_0()       HAL_GPIO_WritePin(cmt_spi_fcsb_port, cmt_spi_fcsb_pin, GPIO_PIN_RESET)

#define cmt_spi3_scl_1()        HAL_GPIO_WritePin(cmt_spi_scl_port, cmt_spi_scl_pin, GPIO_PIN_SET)
#define cmt_spi3_scl_0()        HAL_GPIO_WritePin(cmt_spi_scl_port, cmt_spi_scl_pin, GPIO_PIN_RESET)

#define cmt_spi3_sda_1()        HAL_GPIO_WritePin(cmt_spi_sda_port, cmt_spi_sda_pin, GPIO_PIN_SET)
#define cmt_spi3_sda_0()        HAL_GPIO_WritePin(cmt_spi_sda_port, cmt_spi_sda_pin, GPIO_PIN_RESET)
#define cmt_spi3_sda_read()     HAL_GPIO_ReadPin(cmt_spi_sda_port, cmt_spi_sda_pin)

/* define led */
#define LED1_PORT               GPIO_LED1_GPIO_Port
#define LED1_PIN                GPIO_LED1_Pin
#define LED2_PORT               GPIO_LED2_GPIO_Port
#define LED2_PIN                GPIO_LED2_Pin

/* define led function */
#define led1_on()               HAL_GPIO_WritePin(LED1_PORT, LED1_PIN, GPIO_PIN_SET)
#define led1_off()              HAL_GPIO_WritePin(LED1_PORT, LED1_PIN, GPIO_PIN_RESET)
#define led2_on()               HAL_GPIO_WritePin(LED2_PORT, LED2_PIN, GPIO_PIN_SET)
#define led2_off()              HAL_GPIO_WritePin(LED2_PORT, LED2_PIN, GPIO_PIN_RESET)
#define led1_toggle()           do {led1_off(); Delay_Ms(2); led1_on();} while (0)
#define led2_toggle()           do {led2_off(); Delay_Ms(2); led2_on();} while (0)

/* define RS485 enable */
#define RS485_ON HAL_GPIO_WritePin(GPIO_RS485_EN_GPIO_Port, GPIO_RS485_EN_Pin, GPIO_PIN_SET)
#define RS485_OFF HAL_GPIO_WritePin(GPIO_RS485_EN_GPIO_Port, GPIO_RS485_EN_Pin, GPIO_PIN_RESET)

#else

#define cmt_spi_gpio3_port GPIOB
#define cmt_spi_gpio3_pin GPIO_Pin_10

#define cmt_spi_csb_port GPIOB
#define cmt_spi_csb_pin GPIO_Pin_12

#define cmt_spi_fcsb_port GPIOA
#define cmt_spi_fcsb_pin GPIO_Pin_12

#define cmt_spi_scl_port GPIOB
#define cmt_spi_scl_pin GPIO_Pin_13

#define cmt_spi_sda_port GPIOB
#define cmt_spi_sda_pin GPIO_Pin_15

#define cmt_spi3_gpio3_1() GPIO_SetBits(cmt_spi_gpio3_port, cmt_spi_gpio3_pin)
#define cmt_spi3_gpio3_0() GPIO_ResetBits(cmt_spi_gpio3_port, cmt_spi_gpio3_pin)
#define cmt_spi3_gpio3_read() GPIO_ReadInputDataBit(cmt_spi_gpio3_port, cmt_spi_gpio3_pin)

#define cmt_spi3_csb_1() GPIO_SetBits(cmt_spi_csb_port, cmt_spi_csb_pin)
#define cmt_spi3_csb_0() GPIO_ResetBits(cmt_spi_csb_port, cmt_spi_csb_pin)

#define cmt_spi3_fcsb_1() GPIO_SetBits(cmt_spi_fcsb_port, cmt_spi_fcsb_pin)
#define cmt_spi3_fcsb_0() GPIO_ResetBits(cmt_spi_fcsb_port, cmt_spi_fcsb_pin)

#define cmt_spi3_scl_1() GPIO_SetBits(cmt_spi_scl_port, cmt_spi_scl_pin)
#define cmt_spi3_scl_0() GPIO_ResetBits(cmt_spi_scl_port, cmt_spi_scl_pin)

#define cmt_spi3_sda_1() GPIO_SetBits(cmt_spi_sda_port, cmt_spi_sda_pin)
#define cmt_spi3_sda_0() GPIO_ResetBits(cmt_spi_sda_port, cmt_spi_sda_pin)
#define cmt_spi3_sda_read() GPIO_ReadInputDataBit(cmt_spi_sda_port, cmt_spi_sda_pin)

#define LED1_PORT GPIOA
#define LED1_PIN GPIO_Pin_15
#define LED2_PORT GPIO_Pin_

#endif

/* extern function define */
#ifndef USE_CUBEIDE
void GPIO_Pin_Setting(GPIO_TypeDef *gpio, uint16_t nPin, GPIOSpeed_TypeDef speed, GPIOMode_TypeDef mode);
#endif
void cmt_spi3_init(void);
void cmt_spi3_gpio3_out(void);
void cmt_spi3_gpio3_in(void);
void spi_gpio_init(void);
void cmt_spi3_sda_out(void);
void cmt_spi3_sda_in(void);
void NVIC_Config(void);

#endif
