#include "rf_cfg.h"
#include "./../../Radio/inc/radio.h"

/*----------------------------------------------------------------
 *  FUNCTION DEFINITION
 *--------------------------------------------------------------*/
/**
 * @brief rf recv done callback
 * 
 */
void rfRecvDoneCallback(void)
{
    mq_push(&mq, &(struct msg){rfRecvEvent, NULL});
}

/**
 * @brief rf send done callback
 * 
 */
void rfSendDoneCallback(void)
{
    mq_push(&mq, &(struct msg){rfSendEvent, NULL});
}

/**
 * @brief 
 * 
 */
void rfRecvTimeoutCallback(void)
{
    mq_push(&mq, &(struct msg){rfRecvTimeoutEvent, NULL});
}

/**
 * @brief 
 * 
 */
void rfRecvErrorCallback(void)
{
    mq_push(&mq, &(struct msg){rfRecvErrorEvent, NULL});
}

/**
 * @brief timer16 callback,10ms
 *
 */
void HAL_Timer16Callback(void)
{
	RF_Process();
}
