#include "timer.h"

///* 定时标志位 */
// volatile bool time10ms_flag;
// volatile bool time100ms_flag;

// /*定时器句柄及中断标志位*/
// extern TIM_HandleTypeDef htim14; /* 10ms中断一次 */
// extern TIM_HandleTypeDef htim16; /* 100ms中断一次 */

/*----------------------------------------------------------------
 *  EXTERN VARIABLE
 *--------------------------------------------------------------*/
extern TIM_HandleTypeDef htim17;

/* exter function definition */
extern void uartTimerIrqHandler(TIM_HandleTypeDef *htim);

/*----------------------------------------------------------------
 *  VARIABLE DEFINITION
 *--------------------------------------------------------------*/
/* systickcount define */
volatile uint32_t g_nSysTickCount = 0;
///**
//  * @brief  使能定时器
//  * @param	htim:	定时器句柄
//  * @retval	None
//  */
// void BSPTimerEnable(TIM_HandleTypeDef *htim)
//{
//	if(htim->Instance == htim14.Instance)
//	{
//		HAL_TIM_Base_Start_IT(&htim14);
//	}
//	if(htim->Instance == htim16.Instance)
//	{
//		HAL_TIM_Base_Start_IT(&htim16);
//	}
//}
//
///**
//  * @brief  关闭定时器
//  * @param	htim:	定时器句柄
//  * @retval	None
//  */
// void BSPTimerDisable(TIM_HandleTypeDef *htim)
//{
//	if(htim->Instance == htim14.Instance)
//	{
//		HAL_TIM_Base_Stop_IT(&htim14);
//	}
//	if(htim->Instance == htim16.Instance)
//	{
//		HAL_TIM_Base_Stop_IT(&htim16);
//	}
//}

// /**
//   * @brief  定时器的回调函数
//   * 		定时器6定时为10ms一次
//   * 		定时器16定时为100ms一次
//   * 		定时器17定时为3.6ms一次，确保串口数据接收完成
//   * @param	htim:	定时器句柄
//   * @retval	None
//   */
/*----------------------------------------------------------------
 *  FUNCTION DEFINITION
 *--------------------------------------------------------------*/
/**
 * @brief Timer interrupt callback function
 * 
 * @param htim timer handler
 * @retval None
 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    //	if(htim->Instance == htim14.Instance)
    //	{
    //		time10ms_flag = 1;
    //		timer10InterruptHandler();
    //	}
    //	if(htim->Instance == htim16.Instance)
    //	{
    //		time100ms_flag = 1;
    //		timer100InterruptHandler();
    //	}
    if (htim->Instance == htim17.Instance) {
        uartTimerIrqHandler(htim);
    }
}

/*----------------------------------------------------------------
 *  INTERRUPT CALLBACK
 *--------------------------------------------------------------*/
/**
 * @brief systick callback function, this used by rf
 * 
 * @param None
 * @retval None
 */
void HAL_SysTick_Handler(void)
{
	g_nSysTickCount++;
}
