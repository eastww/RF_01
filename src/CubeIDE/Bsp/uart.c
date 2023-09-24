#include "uart.h"
#include "messageQueue.h"
#ifdef USE_CUBEIDE
#include "uart_cfg.h"
#endif

/*----------------------------------------------------------------
 *  EXTERN VARIABLE
 *--------------------------------------------------------------*/
extern TIM_HandleTypeDef htim17;
extern UART_HandleTypeDef huart1;

/*----------------------------------------------------------------
 *  KFIFO DEFINITION
 *--------------------------------------------------------------*/
static uint8_t uart_rx_byte[UART_ENABLED_CHANNEL];
static uint8_t uart_rx_buffer[UART_ENABLED_CHANNEL][UART_BUFFER_SIZE];
static struct kfifo uart_rx_fifo[UART_ENABLED_CHANNEL];

static uint16_t uart_rx_counter[UART_ENABLED_CHANNEL];
static uint16_t uart_rx_size[UART_ENABLED_CHANNEL];

/*----------------------------------------------------------------
 *  VARIABLE DEFINITION
 *--------------------------------------------------------------*/
/* uart state definition */
volatile static uartStatus_t uart_tx_status[UART_ENABLED_CHANNEL];
volatile static uartStatus_t uart_rx_status[UART_ENABLED_CHANNEL];

/* connect uart and timer */
static uartParamDef uartPara[UART_ENABLED_CHANNEL] = {
    [BSP_TTL_CHANNEL1] = { USART1, &huart1, TIM17, &htim17 },
};

/*----------------------------------------------------------------
 *  FUNCTION DEFINITION
 *--------------------------------------------------------------*/
/**
 * @brief Init uart fifo
 * 
 * @param None
 * @retval None
 */
static void uartInitRxFifo(uartChannel_t channel)
{
    kfifo_init(&uart_rx_fifo[channel], uart_rx_buffer[channel], UART_BUFFER_SIZE);
}

/**
 * @brief uart receive one byte data, enabel uart rx interrupt
 * 
 * @param huart uart instance
 * @param pData data
 * @param Size size
 * @return HAL_StatusTypeDef return handle status
 */
static HAL_StatusTypeDef UART_Receive_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size)
{
    HAL_StatusTypeDef status = HAL_OK;

    status = HAL_UART_Receive_IT(huart, pData, Size);
    if (status != HAL_OK) {
        /* strategy1 */
        // if (HAL_UART_STATE_READY == huart->RxState && HAL_LOCKED == huart->Lock) {
        // {
        // 	__HAL_UNLOCK(huart);
        // }
        /* strategy2 */
        huart->RxState = HAL_UART_STATE_READY;
        __HAL_UNLOCK(huart);
    }

    return status;
}

/**
 * @brief Uart init
 * 
 * @param channel uart channel
 * @retval None
 */
void uartInit(uartChannel_t channel)
{
    uartInitRxFifo(channel);
    uart_rx_counter[channel] = 0;
    uart_rx_size[channel] = 0;
    uart_tx_status[UART_ENABLED_CHANNEL] = BSP_UART_IDLE;
    uart_rx_status[UART_ENABLED_CHANNEL] = BSP_UART_IDLE;
    UART_Receive_IT(uartPara[channel].uart_handle_addr, &uart_rx_byte[channel], 1);
}

/**
 * @brief uart recovery mode
 * 
 * @param channel 
 * @retval None
 */
static void uartRecovery(uartChannel_t channel)
{
    HAL_UART_DeInit(uartPara[channel].uart_handle_addr);
    uartInit(channel);
}

/**
 * @brief Uart send handle
 * 
 * @param channel
 * @param data
 * @param length
 * @retval None
 */
void uartSendData(uartChannel_t channel, uint8_t data[], uint16_t length)
{
    uart_tx_status[channel] = BSP_UART_TX_START;
	// if (HAL_UART_Transmit_DMA(uartPara[channel].uart_handle_addr, data, length) != HAL_OK)
	/* use IT mode send data */
	// if (HAL_UART_Transmit_IT( uartPara[channel].uart_handle_addr, data, length ) != HAL_OK)
	/* use poll mode send data */
	if (HAL_UART_Transmit(uartPara[channel].uart_handle_addr, data, length, 0xFFFF) != HAL_OK)
    {
        uartRecovery(channel);
    }
}

/**
 * @brief uart send done callback function
 * 
 * @param huart 
 * @retval None
 */
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
    for (uint8_t i = 0; i < UART_ENABLED_CHANNEL; i++) 
	{
        if (uartPara[i].uart_instance == huart->Instance) 
        {
            uart_tx_status[i] = BSP_UART_TX_COMPLETED; 
            break;
        }
    }
}

/**
 * @brief Get uart fifo data
 * 
 * @param channel 
 * @param data 
 * @param length 
 * @retval uint32_t 
 */
uint32_t uartGetData(uartChannel_t channel, uint8_t data[], uint16_t length)
{
    uint32_t ret = 0;

    if (BSP_UART_RX_COMPLETED == uart_rx_status[channel]) 
	{
		ret = kfifo_out(&uart_rx_fifo[channel], data, length);
	}    
	else
	{
		ret = 0;
	}

    return ret;
}

/**
 * @brief Reset uart fifo data
 * 
 * @param channel 
 * @retval None
 */
void uartResetData(uartChannel_t channel)
{
    kfifo_reset(&uart_rx_fifo[channel]);
    uart_rx_size[channel] = 0;
    uart_rx_status[channel] = BSP_UART_IDLE;
}

/**
 * @brief Get rx status
 * 
 * @param channel 
 * @retval uartStatus_t 
 */
uartStatus_t uartReadRxStatus(uartChannel_t channel)
{
    return uart_rx_status[channel];
}

/**
 * @brief Get tx status
 * 
 * @param channel 
 * @retval uartStatus_t 
 */
uartStatus_t uartReadTxStatus(uartChannel_t channel)
{
    return uart_tx_status[channel];
}

/**
 * @brief Set rx status
 * 
 * @param channel 
 * @param status 
 * @retval None
 */
void uartSetRxStatus(uartChannel_t channel, uartStatus_t status)
{
    if (BSP_UART_IDLE == status) 
	{
        uart_rx_status[channel] = BSP_UART_IDLE;
    }
}

/*----------------------------------------------------------------
 *  INTERRUPT CALLBACK
 *--------------------------------------------------------------*/
/**
 * @brief Uart rx callback
 * 
 * @param huart 
 * @retval None
 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    for (uint8_t i = 0; i < UART_ENABLED_CHANNEL; i++) 
    {
        if (uartPara[i].uart_instance == huart->Instance) 
		{
            uart_rx_status[i] = BSP_UART_RX_START; 
            uartPara[i].tim_instance->SR = 0; 
            uartPara[i].tim_instance->CNT = 1;
            HAL_TIM_Base_Start_IT(uartPara[i].tim_handle_addr); 
            kfifo_in(&uart_rx_fifo[i], &uart_rx_byte[i], sizeof(uart_rx_byte[i]));
            uart_rx_counter[i]++;
            UART_Receive_IT(uartPara[i].uart_handle_addr, &uart_rx_byte[i], 1);
            return;
        }
    }
}

/**
 * @brief Uart rx timeout callback
 * 
 * @param htim 
 * @retval None
 */
void uartTimerIrqHandler(TIM_HandleTypeDef *htim)
{
    for (uint8_t i = 0; i < UART_ENABLED_CHANNEL; i++)
    {
        if (uartPara[i].tim_instance == htim->Instance)
		{
            HAL_TIM_Base_Stop_IT(uartPara[i].tim_handle_addr); 
            uart_rx_status[i] = BSP_UART_RX_COMPLETED;
            uart_rx_size[i] += uart_rx_counter[i];
            /* uart fifo overflow, discard one package */
            if (uart_rx_size[i] > UART_BUFFER_SIZE)
            {
            	uart_rx_size[i] = uart_rx_counter[i];
            	kfifo_reset(&uart_rx_fifo[i]);
            	uart_rx_size[i] = 0;
            }
            uart_rx_counter[i] = 0;

#ifdef USE_CUBEIDE
            uartRecvDoneCallback();
#endif
//            UART_Receive_IT(uartPara[i].uart_handle_addr, &uart_rx_byte[i], 1);
            break;
        }
    }
}

/**
 * @brief uart error callback
 * 
 * @param huart
 * @retval None 
 */
void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
{
    for (uint8_t i = 0; i < UART_ENABLED_CHANNEL; i++)
    {
        if (uartPara[i].uart_instance == huart->Instance)
        {
            uartRecovery(i);
        }
    }
}
