#include "messageQueue.h"
#include <stdlib.h>
#include <string.h>

/*----------------------------------------------------------------
 *  FUNCTION DEFINITION
 *--------------------------------------------------------------*/
/**
 * @brief message queue initialization
 * 
 * @param None
 * @return struct msgQueue   
 */
struct msgQueue *mq_init(void)
{
    struct msgQueue *mq = (struct msgQueue *)malloc(sizeof(struct msgQueue));
    if (mq == NULL)
    {
        return NULL;
    }
    mq->lock = 0;
    mq->size = MSGQUEUESIZE;
    mq->head = 0;
    mq->tail = 0;
    for (uint8_t i = 0; i < MSGQUEUESIZE; i++)
    {
        memset(&(mq->list[i]), 0, sizeof(struct msgQueue));
    }
    return mq;
}

/**
 * @brief msg queue deinitialization
 * 
 * @param queue 
 * @return None 
 */
void mq_deinit(struct msgQueue *queue)
{
    queue->lock = 0;
    queue->head = 0;
    queue->tail = 0;
    queue->size = 0;
    free(queue);
    queue = NULL;
}

/**
 * @brief msg queue lock
 * 
 * @param msg queue
 * @return true 
 * @return false 
 */
bool mq_lock(struct msgQueue *queue)
{
    if (queue != NULL)
    {
        queue->lock = 1;
        return true;
    }

    return false;
}

/**
 * @brief msg queue unlock
 * 
 * @param msg queue 
 * @return true 
 * @return false 
 */
bool mq_unlock(struct msgQueue *queue)
{
    if (queue != NULL)
    {
        queue->lock = 0;
        return true;
    }
    
    return false;
}

/**
 * @brief check the size of msg queue is empty
 * 
 * @param msg queue 
 * @return true 
 * @return false 
 */
bool mq_isEmpty(struct msgQueue *queue)
{
    if (queue != NULL && mq_getCurrentSize(queue))
    {
        return true;
    }
    return false;
}

/**
 * @brief 
 * 
 * @param queue 
 * @return uint32_t 
 */
uint32_t mq_getCurrentSize(struct msgQueue *queue)
{
    if (queue == NULL)
    {
        return 0;
    }
    if (queue->head - queue->tail)
    {
        return queue->head - queue->tail;
    } 
    else if (queue->tail - queue->head)
    {
        return queue->head + MSGQUEUESIZE - queue->tail;
    }
    else
    {
        return 0;
    }
}

/**
 * @brief get msg queue size
 * 
 * @param msg queue 
 * @return uint32_t msg queue size 
 */
uint32_t mq_getQueueSize(struct msgQueue *queue)
{
    if (queue != NULL)
    {
        return queue->size;
    }
    return 0;
}

/**
 * @brief msg queue push
 * 
 * @param queue 
 * @param msg 
 * @return uint32_t 
 */
uint32_t mq_push(struct msgQueue *queue, struct msg *msg)
{
    if (queue == NULL || msg == NULL)
    {
        return 0;
    }
    if ((queue->head - queue->tail) == MSGQUEUESIZE - 1)
    {
        queue->head -= MSGQUEUESIZE - 1;
    }

    uint8_t index = queue->head & (MSGQUEUESIZE - 1);
    queue->list[index].type = msg->type;
    queue->list[index].data = msg->data;
    queue->head++;

    return queue->head;
}

/**
 * @brief msg queue pop
 * 
 * @param queue 
 * @return struct msg* 
 */
struct msg *mq_pop(struct msgQueue *queue)
{
    if (queue == NULL)
    {
        return NULL;
    }

    if (queue->head == queue->tail)
    {
        return NULL;
    }

    if (queue->tail == MSGQUEUESIZE - 1)
    {
        queue->tail = 0;
    }
    
    uint8_t index = queue->tail & (MSGQUEUESIZE - 1);
    queue->tail++;
    return &(queue->list[index]);
}
