/**
 * @file messageQueue.h
 * @author Marshall (eastww@hotmail.com)
 * @brief This is the message queue implementation.
 *        v0.1
 *        mq use definited argument, cost lots of ram
 *        v0.2
 *        mq use void pointer to transfer arguments
 * @version 0.2
 * @date 2023-09-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef __MESSAGE_QUEUE_H
#define __MESSAGE_QUEUE_H

/*----------------------------------------------------------------
 *  INCLUDE
 *--------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>

/*----------------------------------------------------------------
 *  MACRO DEFINITION
 *--------------------------------------------------------------*/
/* define msg queue size */
#define MSGQUEUESIZE                                        16

/*----------------------------------------------------------------
 *  PARAMETER DEFINITION
 *--------------------------------------------------------------*/
/* message */
struct msg
{
    uint32_t type;
    void* data;
};

/* message queue */
struct msgQueue
{
    uint8_t lock;
    uint32_t size;
    uint32_t head;
    uint32_t tail;
    struct msg list[MSGQUEUESIZE];
};

/*----------------------------------------------------------------
 *  FUNCTION INTERFACE
 *--------------------------------------------------------------*/
void mq_init(struct msgQueue *queue);
void mq_deinit(struct msgQueue *queue);
bool mq_lock(struct msgQueue *queue);
bool mq_unlock(struct msgQueue *queue);
bool mq_isEmpty(struct msgQueue *queue);
uint32_t mq_getCurrentSize(struct msgQueue *queue);
uint32_t mq_getQueueSize(struct msgQueue *queue);
uint32_t mq_push(struct msgQueue *queue, struct msg *msg);
struct msg *mq_pop(struct msgQueue *queue);

#endif
