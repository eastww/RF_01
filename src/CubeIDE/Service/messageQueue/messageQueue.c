#include "messageQueue.h"
#include <stdlib.h>

/**
 * @brief 
 * 
 * @param queue 
 * @return void* 
 */
struct msgQueue *mq_init(uint32_t size, uint32_t listSize)
{

}

/**
 * @brief 
 * 
 * @param queue 
 * @return void* 
 */
void *mq_deinit(struct msgQueue *queue)
{

}

/**
 * @brief 
 * 
 * @param queue 
 * @return true 
 * @return false 
 */
bool mq_lock(struct msgQueue *queue)
{

}

/**
 * @brief 
 * 
 * @param queue 
 * @return true 
 * @return false 
 */
bool mq_unlock(struct msgQueue *queue)
{

}

/**
 * @brief 
 * 
 * @param queue 
 * @return true 
 * @return false 
 */
bool mq_isEmpty(struct msgQueue *queue)
{

}

/**
 * @brief 
 * 
 * @param queue 
 * @return uint32_t 
 */
uint32_t mq_getCurrentSize(struct msgQueue *queue)
{

}

/**
 * @brief 
 * 
 * @param queue 
 * @return uint32_t 
 */
uint32_t mq_getQueueSize(struct msgQueue *queue)
{

}

/**
 * @brief 
 * 
 * @param queue 
 * @param msg 
 * @return uint32_t 
 */
uint32_t mq_push(struct msgQueue *queue, struct msg *msg)
{

}

/**
 * @brief 
 * 
 * @param queue 
 * @return struct msg* 
 */
struct msg *mq_pop(struct msgQueue *queue)
{

}
