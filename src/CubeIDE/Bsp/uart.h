/**
 * @file uart.h
 * @author Marshall (eastww@hotmail.com)
 * @brief This is STM32F030 uart bsp driver
 * 		  defect:
 * 		  Uart use kfifo to cache data, but only cache one package, if two package come,
 * 		  the cached data are wrong.
 * @version 0.2
 * @date 2023-09-18
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef __BSP_UART_H
#define __BSP_UART_H
#include "Kfifo.h"
#include "main.h"
#include <stdbool.h>
#include <string.h>

/* UART channel size */
#define UART_ENABLED_CHANNEL 1

/* UART channel */
typedef enum {
    BSP_TTL_CHANNEL1 = 0x00U,
} uartChannel_t;

/* UART buffer size */
#define UART_BUFFER_SIZE 256

/* UART state define */
typedef enum {
    BSP_UART_IDLE = 0x00U,
    BSP_UART_TX_START,
    BSP_UART_TX_COMPLETED,
    BSP_UART_RX_START,
    BSP_UART_RX_COMPLETED,
} uartStatus_t;

/* UART param */
typedef struct
{
    USART_TypeDef *uart_instance;
    UART_HandleTypeDef *uart_handle_addr;
    TIM_TypeDef *tim_instance;
    TIM_HandleTypeDef *tim_handle_addr;
} uartParamDef;

/* External function api */
void uartInit(uartChannel_t channel);
void uartSendData(uartChannel_t channel, uint8_t data[], uint16_t length);
uint32_t uartGetData(uartChannel_t channel, uint8_t data[], uint16_t length);
void uartResetData(uartChannel_t channel);
// bool uartReadTxFinishedFlag(uartChannel_t channel);
uartStatus_t uartReadRxStatus(uartChannel_t channel);
uartStatus_t uartReadTxStatus(uartChannel_t channel);
void uartSetRxStatus(uartChannel_t channel, uartStatus_t status);

#endif
