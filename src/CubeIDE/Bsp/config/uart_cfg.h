/**
 * @file uart_cfg.h
 * @author Marshall (eastww@hotmail.com)
 * @brief uart cfg file
 * @version 0.1
 * @date 2023-09-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef __UART_CONFIG_H
#define __UART_CONFIG_H

/*----------------------------------------------------------------
 *  INCLUDE
 *--------------------------------------------------------------*/
#include "stateActuator.h"
#include <stdint.h>

/*----------------------------------------------------------------
 *  FUNCTION INTERFACE
 *--------------------------------------------------------------*/
extern void uartRecvDoneCallback(void);
extern void uartSendDoneCallback(void);

#endif