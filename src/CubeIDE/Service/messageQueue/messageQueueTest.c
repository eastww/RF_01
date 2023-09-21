/**
 * @file messageQueueTest.c
 * @author Marshall (eastww@hotmail.com)
 * @brief This is message queue test code
 * @version 0.1
 * @date 2023-09-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "messageQueue.h"

uint8_t msg1Data[64] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
struct msg msg1;

uint8_t msg2Data[64] = {15, 14, 13, 12, 11, 10, 9, 8, 7, 6};
struct msg msg2;

/**
 * @brief msg queue test
 * 
 * @param None
 * @retval None
 */
void messageQueueTest(void)
{
    struct msgQueue *mq = mq_init();
    if (mq_isEmpty(mq))
    {
        mq_lock(mq);
    }
    else
    {
        mq_unlock(mq);
    }
    uint32_t size = mq_getCurrentSize(mq);
    uint32_t totalSize = mq_getQueueSize(mq);

    msg1.type = 10;
    msg1.data = (void *)msg1Data;
    mq_push(mq, &msg1);
    msg2.type = 10;
    msg2.data = (void *)msg2Data;
    mq_push(mq, &msg2);

    struct msg *msg1 = mq_pop(mq);
    struct msg *msg2 = mq_pop(mq);
}