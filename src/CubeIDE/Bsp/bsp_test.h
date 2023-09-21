/**
 * @file bsp_test.h
 * @author Marshall (eastww@hotmail.com)
 * @brief This is the bsp unit test code
 * @version 0.1
 * @date 2023-09-17
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef __BSP_TEST_H
#define __BSP_TEST_H

/* include external peripheral */
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

#if BSP_TEST_ENABLE
/* external function */
void bspTest(void);
#endif

#endif
