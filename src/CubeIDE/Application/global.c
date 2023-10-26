#include "global.h"

/*----------------------------------------------------------------
 *  PARAMETER DEFINITION
 *--------------------------------------------------------------*/
uint8_t g_rxBuffer[RF_PACKET_SIZE];
uint8_t txBuffer[RF_PACKET_SIZE];
uint32_t bufferSize;

/*----------------------------------------------------------------
 *  FUNCTION DEFINITION
 *--------------------------------------------------------------*/
/**
 * @brief rf entry rx status
 * 
 */
void rfEntryRx(void)
{
    RF_StartRx(g_rxBuffer, RF_PACKET_SIZE, INFINITE);
    rfTimerEnable();
}

/**
 * @brief rf exit rx status
 * 
 */
void rfExitRx(void)
{
    rfTimerDisable();
}

/**
 * @brief rf entry tx status
 * 
 */
void rfEntryTx(void)
{
    RF_StartTx(txBuffer, txBuffer[0] , INFINITE);
    rfTimerEnable();
}

/**
 * @brief rf exit tx status
 * 
 */
void rfExitTx(void)
{
    rfTimerDisable();
}
