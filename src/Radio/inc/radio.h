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
 * @file    radio.h
 * @brief   Generic radio handlers
 *
 * @version 1.1
 * @date    Feb 08 2017
 * @author  CMOSTEK R@D
 */

#ifndef __RADIO_H
#define __RADIO_H

#ifdef __cplusplus
extern "C"
{
#endif
#include "cmt2300.h"
#include "cmt2300_hal.h"
#include "cmt_spi3.h"


 //#define ENABLE_ANTENNA_SWITCH   
  
  
/* RF state machine */
typedef enum
{
    RF_STATE_IDLE = 0,
    RF_STATE_RX_START,
    RF_STATE_RX_WAIT,
    RF_STATE_RX_DONE,
    RF_STATE_RX_TIMEOUT,
    RF_STATE_TX_START,
    RF_STATE_TX_WAIT,
    RF_STATE_TX_DONE,
    RF_STATE_TX_TIMEOUT,
    RF_STATE_ERROR,
} EnumRFStatus;

/* RF process function results */
typedef enum
{
    RF_IDLE = 0,
    RF_BUSY,
    RF_RX_DONE,
    RF_RX_TIMEOUT,
    RF_TX_DONE,
    RF_TX_TIMEOUT,
    RF_ERROR,
} EnumRFResult;




void RF_Init(void);
void RF_Config(void);
int8_t RF_initWirelessCare(void);
int8_t RF_initRxSensitivityTest(void);

void RF_SetStatus(EnumRFStatus nStatus);
EnumRFStatus RF_GetStatus(void);
uint8_t RF_GetInterruptFlags(void);

void RF_StartRx(uint8_t buf[], uint16_t len, uint32_t timeout);
void RF_StartTx(uint8_t buf[], uint16_t len, uint32_t timeout);

EnumRFResult RF_Process(void);

#ifdef __cplusplus
}
#endif

#endif
