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
 *  STRUCTURE DEFINE
 *--------------------------------------------------------------*/
enum event
{
    uartEvent = 0u,

    eventAmount,
};

/*----------------------------------------------------------------
 *  FUNCTION DEFINE
 *--------------------------------------------------------------*/
void event_actuator(struct msgQueue *mq);

#endif