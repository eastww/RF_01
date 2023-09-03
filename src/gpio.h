#ifndef _GPIO_H_
#define _GPIO_H_


#define cmt_spi_gpio3_port  GPIOB
#define cmt_spi_gpio3_pin   GPIO_Pin_10

#define cmt_spi_csb_port    GPIOB
#define cmt_spi_csb_pin     GPIO_Pin_12

#define cmt_spi_fcsb_port   GPIOA
#define cmt_spi_fcsb_pin    GPIO_Pin_12

#define cmt_spi_scl_port    GPIOB
#define cmt_spi_scl_pin     GPIO_Pin_13

#define cmt_spi_sda_port    GPIOB
#define cmt_spi_sda_pin     GPIO_Pin_15


#define cmt_spi3_gpio3_1()      GPIO_SetBits(cmt_spi_gpio3_port, cmt_spi_gpio3_pin)
#define cmt_spi3_gpio3_0()      GPIO_ResetBits(cmt_spi_gpio3_port, cmt_spi_gpio3_pin)
#define cmt_spi3_gpio3_read()   GPIO_ReadInputDataBit(cmt_spi_gpio3_port, cmt_spi_gpio3_pin)

#define cmt_spi3_csb_1()        GPIO_SetBits(cmt_spi_csb_port, cmt_spi_csb_pin)
#define cmt_spi3_csb_0()        GPIO_ResetBits(cmt_spi_csb_port, cmt_spi_csb_pin)

#define cmt_spi3_fcsb_1()       GPIO_SetBits(cmt_spi_fcsb_port, cmt_spi_fcsb_pin)
#define cmt_spi3_fcsb_0()       GPIO_ResetBits(cmt_spi_fcsb_port, cmt_spi_fcsb_pin)
    
#define cmt_spi3_scl_1()        GPIO_SetBits(cmt_spi_scl_port, cmt_spi_scl_pin)
#define cmt_spi3_scl_0()        GPIO_ResetBits(cmt_spi_scl_port, cmt_spi_scl_pin)

#define cmt_spi3_sda_1()        GPIO_SetBits(cmt_spi_sda_port, cmt_spi_sda_pin)
#define cmt_spi3_sda_0()        GPIO_ResetBits(cmt_spi_sda_port, cmt_spi_sda_pin)
#define cmt_spi3_sda_read()     GPIO_ReadInputDataBit(cmt_spi_sda_port, cmt_spi_sda_pin)


#define LED1_PORT          GPIOA
#define LED1_PIN           GPIO_Pin_15


void GPIO_Pin_Setting(GPIO_TypeDef *gpio, uint16_t nPin, GPIOSpeed_TypeDef speed, GPIOMode_TypeDef mode);
void cmt_spi3_init(void);
void cmt_spi3_gpio3_out(void);
void cmt_spi3_gpio3_in(void);
void spi_gpio_init(void);
void cmt_spi3_sda_out(void);
void cmt_spi3_sda_in(void);
void NVIC_Config(void);
#endif

