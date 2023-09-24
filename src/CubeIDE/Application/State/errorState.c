/**
 * @file errorState.c
 * @author Marshall (eastww@hotmail.com)
 * @brief error state handler
 * @version 0.1
 * @date 2023-09-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "stateActuator.h"

/*----------------------------------------------------------------
 *  PARAMETER DEFINITION
 *--------------------------------------------------------------*/

/*----------------------------------------------------------------
 *  FUNCTION DEFINITION
 *--------------------------------------------------------------*/
/**
 * @brief error state handler
 * 
 * @param stateData 
 * @param event 
 */
void errorStateHandler(void *stateData, struct event *event )
{
   puts( "ENTERED ERROR STATE!" );
}
