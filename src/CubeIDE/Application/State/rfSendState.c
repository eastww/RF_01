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

/*----------------------------------------------------------------
 *  PARAMETER DEFINITION
 *--------------------------------------------------------------*/
struct state rfSendState = {
   .parentState = NULL,
   .entryState = NULL,
   .transitions = (struct transition[]){
      { rfRecvEvent, NULL, NULL, &rfSendStateAction, &rfRecvState },
   },
   .numTransitions = 1,
   .data = "rfSend",
   .entryAction = &rfSendStateEnter,
   .exitAction = &rfSendStateExit,
};

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
   puts( "Resetting" );
   //todo: use uart send interface to send data
}

/**
 * @brief rf send state enter
 * 
 * @param stateData 
 * @param event 
 */
void rfSendStateEnter( void *stateData, struct event *event )
{
   printf( "Entering %s state\n", (char *)stateData );
}

/**
 * @brief rf send state exit
 * 
 * @param stateData 
 * @param event 
 */
void rfSendStateExit( void *stateData, struct event *event )
{
   printf( "Entering %s state\n", (char *)stateData );
}
