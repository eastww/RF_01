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
#include <stdint.h>

/*----------------------------------------------------------------
 *  PARAMETER DEFINITION
 *--------------------------------------------------------------*/
static uint8_t txBuffer[256] = { 0 };
static uint32_t bufferSize = 0;

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

}

/**
 * @brief rf send state enter
 * 
 * @param stateData 
 * @param event 
 */
void rfSendStateEnter( void *stateData, struct event *event )
{
	bufferSize = uartGetData(BSP_TTL_CHANNEL1, txBuffer + 1, 256);
	if (bufferSize)
	{
		/* send the buffer data to uart1 */
        // uartSendData(BSP_TTL_CHANNEL1, txBuffer, bufferSize);
        // HAL_Delay_nMs(1000);

		/* reset the value */
		// bufferSize = 0;
        txBuffer[0] = bufferSize + 1;
        RF_StartTx(txBuffer,  txBuffer[0] , INFINITE);
		uartResetData(BSP_TTL_CHANNEL1);
		mq_push(&mq, &(struct msg){rfProcessEvent, NULL});
	}
}

/**
 * @brief rf send state exit
 * 
 * @param stateData 
 * @param event 
 */
void rfSendStateExit( void *stateData, struct event *event )
{
   bufferSize = 0;
   mq_push(&mq, &(struct msg){rfProcessEvent, NULL});
   RF_StartRx(g_rxBuffer, RF_PACKET_SIZE, INFINITE);
   rfTimerEnable();
}

/**
 * @brief rf default state, will alway get in, beside triggle other state
 * 
 * @param oldStateData 
 * @param event 
 * @param newStateData 
 */
void rfSendDefaultStateAction( void *oldStateData, struct event *event,
      void *newStateData )
{   
    RF_Process();
    mq_push(&mq, &(struct msg){rfProcessEvent, NULL});
}