#include "stateActuator.h"
#include <stdlib.h>

/*----------------------------------------------------------------
 *  FUNCTION DECLARATION
 *--------------------------------------------------------------*/
static bool compareStr( void *str, struct event *event );

/*----------------------------------------------------------------
 *  STATE DEFINITION
 *--------------------------------------------------------------*/
struct state checkGroupState = {
   .parentState = NULL,
   .entryState = &rfRecvState,
   .transitions = (struct transition[]){
      { uartRecvEvent, NULL, NULL, &rfUartGetMessage, &rfSendState },
      { rfProcessEvent, (void*)'R', *compareStr, &checkGroupStateAction, &rfRecvState },
      { rfProcessEvent, (void*)'T', *compareStr, &checkGroupStateAction, &rfSendState },
   },
   .numTransitions = 3,
   .data = "group",
   .entryAction = &checkGroupStateEnter,
   .exitAction = &checkGroupStateExit,
};

struct state rfRecvState = {
   .parentState = &checkGroupState,
   .entryState = NULL,
   .transitions = (struct transition[]){
      { rfRecvEvent, NULL, NULL, &rfRecvStateAction, &rfRecvState },
      { rfRecvErrorEvent, NULL, NULL, &rfRecvEnableRecv, &rfRecvState },
      { rfRecvTimeoutEvent, NULL, NULL, &rfRecvEnableRecv, &rfRecvState },
   },
   .numTransitions = 3,
   .data = "rfRecv",
   .entryAction = &rfRecvStateEnter,
   .exitAction = &rfRecvStateExit,
};

struct state rfSendState = {
   .parentState = &checkGroupState,
   .entryState = NULL,
   .transitions = (struct transition[]){
      { rfSendEvent, NULL, NULL, &rfSendStateAction, &rfRecvState },
   },
   .numTransitions = 1,
   .data = "rfSend",
   .entryAction = &rfSendStateEnter,
   .exitAction = &rfSendStateExit,
};

struct state errorState = {
	.data = "errorState",
	.entryAction = &errorStateHandler,
};

/*----------------------------------------------------------------
 *  PARAMETER DEFINITION
 *--------------------------------------------------------------*/
struct stateMachine m;
struct msgQueue mq;

/*----------------------------------------------------------------
 *  FUNCTION DEFINE
 *--------------------------------------------------------------*/

/**
 * @brief compare string
 * 
 * @param str 
 * @param event 
 * @return true 
 * @return false 
 */
static bool compareStr( void *str, struct event *event )
{
   if ( event->type != rfProcessEvent )
      return false;

   return str == event->data;
}

/**
 * @brief state actuator
 * 
 * @param None
 * @retval None
 */
void stateActuator(void)
{
    struct msg *msg;
    stateM_init(&m, &rfRecvState, &errorState);
    mq_init(&mq);
    
    /* triggle state machine */
    mq_push(&mq, &(struct msg){rfProcessEvent, (void*)'R'});

    while ( 1 )
    {
        if ((msg = mq_pop( &mq )) != NULL)
        {
            stateM_handleEvent(&m, (struct event *)msg);
        }
    }
}
