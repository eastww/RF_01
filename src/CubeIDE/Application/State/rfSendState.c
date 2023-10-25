/**
 * @file rfSendState.c
 * @author Marshall (eastww@hotmail.com)
 * @brief Use rf interface to send data when uart recv data
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
#include <stdint.h>

/*----------------------------------------------------------------
 *  PARAMETER DEFINITION
 *--------------------------------------------------------------*/

/*----------------------------------------------------------------
 *  FUNCTION DEFINITION
 *--------------------------------------------------------------*/

/**
 * @brief rf send action
 * 
 * @param oldStateData 
 * @param event 
 * @param newStateData 
 */
void rfSendStateAction( void *oldStateData, struct event *event,
      void *newStateData )
{
//    while (1)
//    {
//
//    }
    
}

/**
 * @brief rf send state enter
 * 
 * @param stateData 
 * @param event 
 */
void rfSendStateEnter( void *stateData, struct event *event )
{
	
}

/**
 * @brief rf send state exit
 * 
 * @param stateData 
 * @param event 
 */
void rfSendStateExit( void *stateData, struct event *event )
{
   mq_push(&mq, &(struct msg){rfProcessEvent, NULL});
   RF_StartRx(g_rxBuffer, RF_PACKET_SIZE, INFINITE);
   rfTimerEnable();
}
