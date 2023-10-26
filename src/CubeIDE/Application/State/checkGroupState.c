/**
 * @file checkGroupState.c
 * @author Marshall (eastww@hotmail.com)
 * @brief Group state, used to check uart receiver event and rf state
 * @version 0.1
 * @date 2023-10-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/*----------------------------------------------------------------
 *  INCLUDE
 *--------------------------------------------------------------*/
#include "stateActuator.h"
#include <stddef.h>

/*----------------------------------------------------------------
 *  PARAMETER DEFINITION
 *--------------------------------------------------------------*/

/*----------------------------------------------------------------
 *  FUNCTION DEFINITION
 *--------------------------------------------------------------*/
/**
 * @brief rf send state get uart message
 * 
 * @param oldStateData 
 * @param event 
 * @param newStateData 
 */
void rfUartGetMessage( void *oldStateData, struct event *event,
      void *newStateData )
{
	led2Toggle();
    bufferSize = uartGetData(BSP_TTL_CHANNEL1, txBuffer + 1, 256);
	if (bufferSize)
	{
		/* send the buffer data to uart1 */
        // uartSendData(BSP_TTL_CHANNEL1, txBuffer, bufferSize);
        // HAL_Delay_nMs(1000);

		/* reset the value */
		// bufferSize = 0;
        txBuffer[0] = bufferSize + 1;
        uartResetData(BSP_TTL_CHANNEL1);
        // RF_StartTx(txBuffer, txBuffer[0] , INFINITE);
        rfEntryTx();
	}
}

/**
 * @brief rf default state, will alway get in, beside triggle other state
 * 
 * @param oldStateData 
 * @param event 
 * @param newStateData 
 */
void checkGroupStateAction( void *oldStateData, struct event *event,
      void *newStateData )
{   
    // RF_Process();
    // mq_push(&mq, &(struct msg){rfProcessEvent, NULL});
}

/**
 * @brief check group state enter
 * 
 * @param stateData 
 * @param event 
 */
void checkGroupStateEnter( void *stateData, struct event *event )
{
    // RF_StartRx(g_rxBuffer, RF_PACKET_SIZE, INFINITE);
    // rfTimerEnable();
}

/**
 * @brief check group state exit
 * 
 * @param stateData 
 * @param event 
 */
void checkGroupStateExit( void *stateData, struct event *event )
{
    // rfTimerDisable();
    rfEntryRx();
    bufferSize = 0;
}