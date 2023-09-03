/*
 * THE FOLLOWING FIRMWARE IS PROVIDED: (1) "AS IS" WITH NO WARRANTY; AND
 * (2)TO ENABLE ACCESS TO CODING INFORMATION TO GUIDE AND FACILITATE CUSTOMER.
 * CONSEQUENTLY, CMOSTEK SHALL NOT BE HELD LIABLE FOR ANY DIRECT, INDIRECT OR
 * CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE CONTENT
 * OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING INFORMATION
 * CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 *
 * Copyright (C) CMOSTEK SZ.
 */

/*!
 * @file    cmt2300_hal.h
 * @brief   CMT2300 hardware abstraction layer
 *
 * @version 1.1
 * @date    Feb 08 2017
 * @author  CMOSTEK R@D
 */

#ifndef __CMT2300_HAL_H
#define __CMT2300_HAL_H
#include "stm32f0xx.h"
#include <stdint.h>
#include <stdio.h>
#ifdef __cplusplus
extern "C"
{
#endif
    extern uint32_t g_tickTimeCnt;
/* ************************************************************************
*  The following need to be modified by user
*  ************************************************************************ */
#define Cmt2300_SetGpio1In() SET_GPIO_IN(CMT_GPIO1_GPIO)
#define Cmt2300_SetGpio2In() SET_GPIO_IN(CMT_GPIO2_GPIO)
#define Cmt2300_SetGpio3In() SET_GPIO_IN(CMT_GPIO3_GPIO)
#define Cmt2300_ReadGpio1() READ_GPIO_PIN(CMT_GPIO1_GPIO)
#define Cmt2300_ReadGpio2() READ_GPIO_PIN(CMT_GPIO2_GPIO)
#define Cmt2300_ReadGpio3() READ_GPIO_PIN(CMT_GPIO3_GPIO)
#define Cmt2300_GetTickCount() g_nSysTickCount
    /* ************************************************************************ */

    void Cmt2300_InitGpio(void);

    uint8_t Cmt2300_ReadReg(uint8_t addr);
    void Cmt2300_WriteReg(uint8_t addr, uint8_t dat);

    void Cmt2300_ReadFifo(uint8_t buf[], uint16_t len);
    void Cmt2300_WriteFifo(const uint8_t buf[], uint16_t len);

#ifdef __cplusplus
}
#endif

#endif
