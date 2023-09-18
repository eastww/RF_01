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

#if BSP_TEST_ENABLE
/* include external peripheral */
#include "./../../delay.h"
#include "./../../gpio.h"

/* external function */
void bspTest(void);
#endif

#endif
