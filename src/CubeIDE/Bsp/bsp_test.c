#include "bsp_test.h"

/**
 * @brief led test
 * @param None
 * @retval None
 */
static void led_test(void)
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
 * @brief bsp test api
 * @param None
 * @retval None
 */
void bsp_test(void)
{
    /* led test */
    led_test();
}
