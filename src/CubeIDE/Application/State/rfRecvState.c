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

/*----------------------------------------------------------------
 *  PARAMETER DEFINITION
 *--------------------------------------------------------------*/
struct state rfRecvState = {
   .parentState = NULL,
   .entryState = NULL,
   .transitions = (struct transition[]){
      { rfRecvEvent, NULL, NULL, &rfRecvStateAction, &rfRecvState },
      { uartRecvEvent, NULL, NULL, NULL, &rfSendState },
      { rfRecvErrorEvent, NULL, NULL, NULL, &rfRecvState },
      { rfRecvTimeoutEvent, NULL, NULL, NULL, &rfRecvState },
   },
   .numTransitions = 2,
   .data = "rfRecv",
   .entryAction = &rfRecvStateEnter,
   .exitAction = &rfRecvStateExit,
};

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
   puts( "Resetting" );
   //todo: use uart send interface to send data
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
}

/**
 * @brief rf recv state exit
 * 
 * @param stateData 
 * @param event 
 */
void rfRecvStateExit( void *stateData, struct event *event )
{
   printf( "Entering %s state\n", (char *)stateData );
}
