#include "bsp_test.h"
#include "main.h"

#if BSP_TEST_ENABLE
/* external variables */
extern UART_HandleTypeDef huart1;

/**
 * @brief led test
 * @param None
 * @retval None
 */
static void ledTest(void)
{
    /* led on */
	led1On();
	led2On();

    /* delay 1s */
    HAL_Delay_nMs(1000);
    /* led off */
    led1Off();
    led2Off();
    HAL_Delay_nMs(1000);
}

/**
 * @brief uart tx test
 * @param None
 * @retval None
 */
static void uartTxTest(void)
{
    uint8_t buffer[10] = "1234567890";
    HAL_UART_Transmit(&huart1, buffer, 10, 0xFFFF);
    HAL_Delay_nMs(1000);
}

/**
 * @brief uart rx test
 * @param None
 * @retval None
 */
static void uartRxTest(uint8_t *buffer, uint32_t bufferSize)
{
    bufferSize = uartGetData(BSP_TTL_CHANNEL1, buffer, 256);
	if (bufferSize)
	{
		/* send the buffer data to uart1 */
		uartSendData(BSP_TTL_CHANNEL1, buffer, bufferSize);
		HAL_Delay_nMs(1000);

		/* reset the value */
		bufferSize = 0;
		uartResetData(BSP_TTL_CHANNEL1);
	}
}

/**
 * @brief rf send test
 * @param None
 * @retval None
 */
static void rfTxTest(void)
{
    uint8_t g_txBuffer[]={0x09,0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07}; /* RF Tx buffer */
    RF_StartTx(g_txBuffer,  g_txBuffer[0], INFINITE); 

    while ( 1 )
    {
        switch (RF_Process())
        {
        case RF_IDLE:
    
            RF_StartTx(g_txBuffer,  g_txBuffer[0] , INFINITE);//发射数据
        
            break;
        
        case RF_TX_DONE: //发射完成
            led1Toggle();
            break;
    
        default:
            break;
        }
    }
}

/**
 * @brief bsp test api
 * @param None
 * @retval None
 */
void bspTest(void)
{
    /* led test */
#if 0
    ledTest();
#endif
#if 0
    uartTest();
#endif
#if 1
    rfTxTest();
#endif
}
#endif
