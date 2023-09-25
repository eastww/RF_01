/**
 * @file bsp.h
 * @author Marshall (eastww@hotmail.com)
 * @brief bsp interface
 * @version 0.1
 * @date 2023-09-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef __BSP_H
#define __BSP_H

/*----------------------------------------------------------------
 *  INCLUDE
 *--------------------------------------------------------------*/
#include "./../../delay.h"
#include "./../../gpio.h"
// #include "./../../Radio/inc/cmt_spi3.h"
// #include "./../../Radio/inc/CMT230_params_RxTxTest.h"
// #include "./../../Radio/inc/cmt2300_defs.h"
// #include "./../../Radio/inc/CMT2300_FrqSetTab.h"
// #include "./../../Radio/inc/cmt2300_hal.h"
// #include "./../../Radio/inc/cmt2300_params.h"
// #include "./../../Radio/inc/cmt2300.h"
// #include "./../../Radio/inc/cmt2300a_params.h"
// #include "./../../Radio/inc/crc.h"
#include "./../../Radio/inc/radio.h"
#include "./../../Radio/inc/typedefs.h"
#include "uart.h"
#include "timer.h"

/*----------------------------------------------------------------
 *  FUNCTION INTERFACE
 *--------------------------------------------------------------*/
void bspInit(void);

#endif
