/**
 * @file rfRecvState.c
 * @author Marshall (eastww@hotmail.com)
 * @brief rf recv state
 * @version 0.1
 * @date 2023-09-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/*----------------------------------------------------------------
 *  INCLUDE
 *--------------------------------------------------------------*/
#include "stateActuator.h"
#include <stddef.h>

/*----------------------------------------------------------------
 *  PARAMETER DEFINITION
 *--------------------------------------------------------------*/

/*----------------------------------------------------------------
 *  FUNCTION DEFINITION
 *--------------------------------------------------------------*/
/**
 * @brief rf recv action
 * 
 * @param oldStateData 
 * @param event 
 * @param newStateData 
 */
void rfRecvStateAction( void *oldStateData, struct event *event,
      void *newStateData )
{   
    rfExitRx();
    uint8_t user_rxBuffer[RF_PACKET_SIZE] = { 0 };
    memcpy(user_rxBuffer, g_rxBuffer, g_rxBuffer[0]);
    uartSendData(BSP_TTL_CHANNEL1, user_rxBuffer, user_rxBuffer[0]);
//    led2Toggle();
    
    rfEntryRx();
}

/**
 * @brief rf enable recv
 * 
 * @param oldStateData 
 * @param event 
 * @param newStateData 
 */
void rfRecvEnableRecv( void *oldStateData, struct event *event,
      void *newStateData )
{   
    RF_StartRx(g_rxBuffer, RF_PACKET_SIZE, INFINITE);
}

/**
 * @brief rf recv state enter
 * 
 * @param stateData 
 * @param event 
 */
void rfRecvStateEnter( void *stateData, struct event *event )
{
    RF_StartRx(g_rxBuffer, RF_PACKET_SIZE, INFINITE);
    // rfTimerEnable();
}

/**
 * @brief rf recv state exit
 * 
 * @param stateData 
 * @param event 
 */
void rfRecvStateExit( void *stateData, struct event *event )
{
    rfExitRx();
}
