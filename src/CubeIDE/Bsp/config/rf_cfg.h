/**
 * @file rf_cfg.h
 * @author Marshall (eastww@domain.com)
 * @brief rf config file
 * @version 0.1
 * @date 2023-09-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef __RF_CONFIG_H
#define __RF_CONFIG_H

/*----------------------------------------------------------------
 *  INCLUDE
 *--------------------------------------------------------------*/
#include "stateActuator.h"
#include <stdint.h>

/*----------------------------------------------------------------
 *  FUNCTION INTERFACE
 *--------------------------------------------------------------*/
extern void rfRecvDoneCallback(void);
extern void rfSendDoneCallback(void);
extern void rfRecvTimeoutCallback(void);
extern void rfRecvErrorCallback(void);
extern void HAL_Timer16Callback(void);

#endif
