#include "stateActuator.h"
#include <stdlib.h>

/*----------------------------------------------------------------
 *  PARAMETER DEFINITION
 *--------------------------------------------------------------*/
struct state rfRecvState = {
   .parentState = NULL,
   .entryState = NULL,
   .transitions = (struct transition[]){
      { rfRecvEvent, NULL, NULL, &rfRecvStateAction, &rfRecvState },
      { uartRecvEvent, NULL, NULL, NULL, &rfSendState },
      { rfRecvErrorEvent, NULL, NULL, &rfRecvEnableRecv, &rfRecvState },
      { rfRecvTimeoutEvent, NULL, NULL, &rfRecvEnableRecv, &rfRecvState },
   },
   .numTransitions = 4,
   .data = "rfRecv",
   .entryAction = &rfRecvStateEnter,
   .exitAction = &rfRecvStateExit,
};

struct state rfSendState = {
   .parentState = NULL,
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
 *  FUNCTION DEFINE
 *--------------------------------------------------------------*/
/**
 * @brief state actuator
 * 
 * @param None
 * @retval None
 */
void stateActuator(void)
{
    struct stateMachine m;
    stateM_init(&m, &rfRecvState, &errorState);

    struct msgQueue *mq = mq_init();
    struct msg *msg;
    while ( 1 )
    {
        if ((msg = mq_pop( mq )) != NULL)
        {
            stateM_handleEvent(&m, (struct event *)msg);
        }
    }
}