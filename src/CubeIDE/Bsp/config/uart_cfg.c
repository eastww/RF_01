#include "uart_cfg.h"

/*----------------------------------------------------------------
 *  FUNCTION DEFINITION
 *--------------------------------------------------------------*/
/**
 * @brief uart recv done callback
 * 
 */
void uartRecvDoneCallback(void)
{
    mq_push(&mq, &(struct msg){uartRecvEvent, NULL});
}

/**
 * @brief uart send done callback
 * 
 */
void uartSendDoneCallback(void)
{

}
