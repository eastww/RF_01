#include "dial_switch.h"

/*----------------------------------------------------------------
 *  EXTERN VARIABLE
 *--------------------------------------------------------------*/

/*----------------------------------------------------------------
 *  VARIABLE DEFINITION
 *--------------------------------------------------------------*/
#define DS_PORT2_VALUE      HAL_GPIO_ReadPin(GPIO_DS_PIN1_GPIO_Port, GPIO_DS_PIN1_Pin)
#define DS_PORT1_VALUE      HAL_GPIO_ReadPin(GPIO_DS_PIN2_GPIO_Port, GPIO_DS_PIN2_Pin)

/*----------------------------------------------------------------
 *  FUNCTION DEFINITION
 *--------------------------------------------------------------*/
/**
 * @brief Get the Ds Value object
 * 
 * @return dsRet_t 
 */
dsRet_t getDsValue(void)
{
    return DS_PORT2_VALUE << 1 | DS_PORT1_VALUE;
}
