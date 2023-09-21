/**
 * @file messageQueue.h
 * @author Marshall (eastww@hotmail.com)
 * @brief This is the message queue implementation.
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

/* message argument */
union msgArgument
{
    uint8_t u8Arg;
    int8_t s8Arg;

    uint16_t u16Arg;
    int16_t s16Arg;

    uint32_t u32Arg;
    int32_t s32Arg;

    void *pArg;
};

/* message */
struct msg
{
    uint32_t type;
    union msgArgument data;
};

/* message queue */
struct msgQueue
{
    uint8_t lock;
    uint32_t size;
    uint32_t head;
    uint32_t tail;
    struct msg *list;
};

/* function definition */
struct msgQueue *mq_init(uint32_t size, uint32_t listSize);
void *mq_deinit(struct msgQueue *queue);
bool mq_lock(struct msgQueue *queue);
bool mq_unlock(struct msgQueue *queue);
bool mq_isEmpty(struct msgQueue *queue);
uint32_t mq_getCurrentSize(struct msgQueue *queue);
uint32_t mq_getQueueSize(struct msgQueue *queue);
uint32_t mq_push(struct msgQueue *queue, struct msg *msg);
struct msg *mq_pop(struct msgQueue *queue);

#endif
