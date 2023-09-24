#include "event.h"
#include <stdlib.h>

/*----------------------------------------------------------------
 *  FUNCTION DEFINE
 *--------------------------------------------------------------*/
/**
 * @brief event actuator
 * 
 * @param None
 * @retval None
 */
void event_actuator(struct msgQueue *mq)
{
    if (mq == NULL)
    {
        /* code */
        return;
    }

    struct msg *msg;
    while (msg = mq_pop(mq))
    {
        stateM_handleEvent(&mq, (struct event *)msg);
    }
}