#include "stateActuator.h"
#include <stdlib.h>

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
    stateM_init( &m, &rfRecvState, &errorState );

    struct msgQueue *mq = mq_init();
    struct msg *msg;
    while ( (msg = mq_pop( mq ) ) != NULL )
    {
        stateM_handleEvent( &m, (struct event *)msg );
    }
}