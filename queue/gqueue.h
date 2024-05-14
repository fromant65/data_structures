#ifndef __GQUEUE_H__
#define __GQUEUE_H__

#include "../array/garray.h"
typedef struct{
    GArray array;
    int first; //<! index of the first element of the queue
    int last; //<! index of the last element of the queue
    int max_size;
}Queue;

/**
 * @brief Creates a new empty queue 
*/
Queue newQueue(int);

/**
 * @brief Adds a new element at the end of the queue if it is not full
 * Otherwise does nothing
*/
Queue enQueue(Queue, void*);

/**
 * @brief Removes the last element from the queue
*/
Queue deQueue(Queue, DestructorFunction);

/**
 * @return 1 if the queue is empty, 0 otherwise
*/
int QueueEmpty(Queue);

/**
 * @return the first element of the queue without dequeueing it
*/
void* QueueStart(Queue);

/**
 * @brief Destroys the queue
*/
void destroyQueue(Queue, DestructorFunction);

#endif