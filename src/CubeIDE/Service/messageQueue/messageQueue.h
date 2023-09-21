/**
 * @file messageQueue.h
 * @author Marshall (eastww@hotmail.com)
 * @brief This is the message queue implementation.
 *        v0.1
 *        mq use definited argument, cost lots of ram
 * @version 0.1
 * @date 2023-09-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef __MESSAGE_H
#define __MESSAGE_H

#include <stdint.h>
#include <stdbool.h>

/* define msg queue size */
#define MSGQUEUESIZE                        8
#define MSGQUEUEDATASIZE                    32

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

/* function definition */
struct msgQueue *mq_init(void);
void mq_deinit(struct msgQueue *queue);
bool mq_lock(struct msgQueue *queue);
bool mq_unlock(struct msgQueue *queue);
bool mq_isEmpty(struct msgQueue *queue);
uint32_t mq_getCurrentSize(struct msgQueue *queue);
uint32_t mq_getQueueSize(struct msgQueue *queue);
uint32_t mq_push(struct msgQueue *queue, struct msg *msg);
struct msg *mq_pop(struct msgQueue *queue);

#endif
