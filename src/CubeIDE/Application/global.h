/**
 * @file global.h
 * @author Marshall (eastww@hotmail.com)
 * @brief common variable definiton, shared by all files 
 * @version 0.1
 * @date 2023-09-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/*----------------------------------------------------------------
 *  INCLUDE
 *--------------------------------------------------------------*/
#include <stdint.h>
#include "bsp.h"

/*----------------------------------------------------------------
 *  MACRO DEFINITION
 *--------------------------------------------------------------*/
#define RF_PACKET_SIZE                                      256

/*----------------------------------------------------------------
 *  PARAMETER DEFINITION
 *--------------------------------------------------------------*/
extern uint8_t g_rxBuffer[RF_PACKET_SIZE];
extern uint8_t txBuffer[RF_PACKET_SIZE];
extern uint32_t bufferSize;

/*----------------------------------------------------------------
 *  FUNCTION INTERFACE
 *--------------------------------------------------------------*/
void rfEntryRx(void);
void rfExitRx(void);
void rfEntryTx(void);
void rfExitTx(void);
