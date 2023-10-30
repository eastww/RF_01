/**
 * @file dial_switch.h
 * @author Marshall (eastww@domain.com)
 * @brief dial switch bsp
 * @version 0.1
 * @date 2023-10-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef __DIAL_SWITCH_H
#define __DIAL_SWITCH_H

/*----------------------------------------------------------------
 *  INCLUDE
 *--------------------------------------------------------------*/
#include "main.h"

/*----------------------------------------------------------------
 *  DEFINITION
 *--------------------------------------------------------------*/
typedef enum {
    BSP_DS_FUNC0 = 0u,
    BSP_DS_FUNC1,
    BSP_DS_FUNC2,
    BSP_DS_FUNC3,
} dsRet_t;

/*----------------------------------------------------------------
 *  FUNCTION INTERFACE
 *--------------------------------------------------------------*/
dsRet_t getDsValue(void);

#endif // !__DIAL_SWITCH_H
