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
    LED1_ON;
    LED2_ON;

    /* delay 1s */
    HAL_Delay_nMs(1000);
    /* led off */
    LED1_OFF;
    LED2_OFF;
    HAL_Delay_nMs(1000);
}

/**
 * @brief uart test
 * @param None
 * @retval None
 */
static void uartTest(void)
{
    uint8_t buffer[10] = "1234567890";
    HAL_UART_Transmit(&huart1, buffer, 10, 0xFFFF);
    HAL_Delay_nMs(1000);
}

/**
 * @brief bsp test api
 * @param None
 * @retval None
 */
void bspTest(void)
{
    /* led test */
    ledTest();
    uartTest();
}
#endif
