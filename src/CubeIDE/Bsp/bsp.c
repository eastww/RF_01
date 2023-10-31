#include "bsp.h"

/*----------------------------------------------------------------
 *  FUNCTION DEFINITION
 *--------------------------------------------------------------*/
void bspInit(void)
{
    uartInit(BSP_TTL_CHANNEL1);
    uartInit(BSP_TTL_CHANNEL2);
    
    RF_Init();
    /* check rf is inited ok */
//    if (Cmt2300_IsExist())
//    {
//        led1On();
//    }
//    else
//    {
//        led2On();
//    }

    /* level7: 20dbm */
    Cmt2300_ConfigTxPower(7);
    /* rate:1.2kbps */
    Cmt2300_ConfigDataRate(rf_rate_1K2);
    /* packet type */
    Cmt2300_ConfigPktLenthType(CMT2300_PKT_TYPE_VARIABLE);
    /* packet mode */
    Cmt2300_ConfigDataMode(CMT2300_DATA_MODE_PACKET);
    /* enable fifo */
    Cmt2300_EnableFifoMerge(true);

    /* disable rf time */
    RF_StartRx(g_rxBuffer, RF_PACKET_SIZE, INFINITE);
    rfTimerEnable();
    led2Off();
    led2Off();
}
