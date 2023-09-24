/**
 * @file initState.c
 * @author Marshall (eastww@hotmail.com)
 * @brief idle state
 * @version 0.1
 * @date 2023-09-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/*----------------------------------------------------------------
 *  INCLUDE
 *--------------------------------------------------------------*/
#include "event.h"

/*----------------------------------------------------------------
 *  PARAMETER DEFINITION
 *--------------------------------------------------------------*/
struct state initState = {
   .parentState = NULL,
   .entryState = NULL,
   .transitions = (struct transition[]){
      { Event_keyboard, (void *)(intptr_t)'h', &compareKeyboardChar, NULL,
         &hState },
   },
   .numTransitions = 1,
   .data = "init",
   .entryAction = &initStateEnter,
   .exitAction = &initStateExit,
};

/*----------------------------------------------------------------
 *  FUNCTION DEFINITION
 *--------------------------------------------------------------*/

/**
 * @brief init state enter
 * 
 * @param stateData 
 * @param event 
 */
void initStateEnter( void *stateData, struct event *event )
{
   printf( "Entering %s state\n", (char *)stateData );
}

/**
 * @brief init state exit
 * 
 * @param stateData 
 * @param event 
 */
void initStateExit( void *stateData, struct event *event )
{
   printf( "Entering %s state\n", (char *)stateData );
}