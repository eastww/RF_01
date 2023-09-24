#include "rf_cfg.h"

/*----------------------------------------------------------------
 *  FUNCTION DEFINITION
 *--------------------------------------------------------------*/
/**
 * @brief rf recv done callback
 * 
 */
void rfRecvDoneCallback(void)
{
    struct msg msg = { 
        .type = uartRecvEvent,
        .data = NULL,
    };

    mq_push(&mq, &msg);
}

/**
 * @brief rf send done callback
 * 
 */
void rfSendDoneCallback(void)
{
    struct msg msg = { 
        .type = rfSendEvent,
        .data = NULL,
    };

    mq_push(&mq, &msg);
}

/**
 * @brief 
 * 
 */
void rfRecvTimeoutCallback(void)
{
    struct msg msg = { 
        .type = rfRecvTimeoutEvent,
        .data = NULL,
    };

    mq_push(&mq, &msg);
}

/**
 * @brief 
 * 
 */
void rfRecvErrorCallback(void)
{
    struct msg msg = { 
        .type = rfRecvErrorEvent,
        .data = NULL,
    };

    mq_push(&mq, &msg);
}