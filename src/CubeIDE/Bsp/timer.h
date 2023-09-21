/**
 * @file timer.h
 * @author Marshall (eastww@hotmail.com)
 * @brief This is STM32F030 timer bsp driver
 * @version 0.2
 * @date 2023-09-18
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef __BSP_TIMER_H
#define __BSP_TIMER_H

#include "main.h"
#include <stdbool.h>

///*中断标志位*/
// extern volatile bool time10ms_flag;
// extern volatile bool time100ms_flag;
//
// void BSPTimerEnable(TIM_HandleTypeDef *htim);
// void BSPTimerDisable(TIM_HandleTypeDef *htim);
void HAL_SysTick_Handler(void);

#endif
