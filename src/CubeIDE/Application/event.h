/**
 * @file event.h
 * @author Marshall (eastww@hotmail.com)
 * @brief This is the event handler
 * @version 0.1
 * @date 2023-09-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef __EVENT_H
#define __EVENT_H

/*----------------------------------------------------------------
 *  INCLUDE
 *--------------------------------------------------------------*/
#include "messageQueue.h"
#include "stateMachine.h"

/*----------------------------------------------------------------
 *  STRUCTURE DEFINE
 *--------------------------------------------------------------*/
enum eventType
{
    uartEvent = 0u,

    eventAmount,
};

/*----------------------------------------------------------------
 *  FUNCTION INTERFACE
 *--------------------------------------------------------------*/
void event_actuator(struct msgQueue *mq);

#endif