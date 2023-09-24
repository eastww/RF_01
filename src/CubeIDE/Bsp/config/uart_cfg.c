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
    struct msg msg = { 
        .type = uartRecvEvent,
        .data = NULL,
    };

    mq_push(&mq, &msg);
}

/**
 * @brief uart send done callback
 * 
 */
void uartSendDoneCallback(void)
{

}
