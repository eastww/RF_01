/**
 * @file stateActuator.h
 * @author Marshall (eastww@hotmail.com)
 * @brief This is the event handler
 * @version 0.1
 * @date 2023-09-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef __STATE_ACTUATOR_H
#define __STATE_ACTUATOR_H

/*----------------------------------------------------------------
 *  INCLUDE
 *--------------------------------------------------------------*/
#include "messageQueue.h"
#include "stateMachine.h"
#include "bsp.h"
#include "global.h"

/*----------------------------------------------------------------
 *  STRUCTURE DEFINE
 *--------------------------------------------------------------*/
enum eventType
{
    uartRecvEvent = 0,
    rfRecvEvent,
	rfProcessEvent,
    rfSendEvent,
    rfRecvErrorEvent,
    rfRecvTimeoutEvent,

    eventAmount,
};

/*----------------------------------------------------------------
 *  EXTERN DEFINITION
 *--------------------------------------------------------------*/
extern uint8_t g_rxBuffer[128];
extern struct stateMachine m;
extern struct msgQueue mq;

extern struct state rfRecvState;
extern void rfRecvStateAction( void *oldStateData, struct event *event, void *newStateData );
extern void rfRecvEnableRecv( void *oldStateData, struct event *event, void *newStateData );
extern void rfRecvStateEnter( void *stateData, struct event *event );
extern void rfRecvStateExit( void *stateData, struct event *event );
extern void rfRecvDefaultStateAction( void *oldStateData, struct event *event, void *newStateData );

extern struct state rfSendState;
extern void rfSendStateAction( void *oldStateData, struct event *event, void *newStateData );
extern void rfSendStateEnter( void *stateData, struct event *event );
extern void rfSendStateExit( void *stateData, struct event *event );
extern void rfSendDefaultStateAction( void *oldStateData, struct event *event, void *newStateData );

extern struct state errorState;
extern void errorStateHandler(void *stateData, struct event *event );

/*----------------------------------------------------------------
 *  FUNCTION INTERFACE
 *--------------------------------------------------------------*/
void stateActuator(void);

#endif
