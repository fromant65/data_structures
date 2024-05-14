#include "gqueue.h"
#include "stdlib.h"

/**
 * @brief Creates a new empty queue 
*/
Queue newQueue(int max_longitude){
    GArray arr = newGArray();
    while(max_longitude>arr.size){
        arr = expandGArray(arr);
    }
    Queue q = {arr, 0, 0, max_longitude};
    return q;
}

/**
 * @brief Adds a new element at the end of the queue if it is not full
 * Otherwise does nothing
*/
Queue enQueue(Queue q, void* data){
    //Queue is full if q.last+1 == q.first (mod q.max_size)
    if((q.last+1)%q.max_size == q.first%q.max_size){
        return q;
    }
    q.array.data[(q.last+1)%q.max_size]=data;
    q.last=(q.last+1)%q.max_size;
    return q;
}

/**
 * @brief Removes the last element from the queue
*/
Queue deQueue(Queue q, DestructorFunction d){
    d(q.array.data[q.last]);
    if(q.last==0) q.last=q.max_size-1;
    else q.last--;
    return q;
}

/**
 * @return 1 if the queue is empty, 0 otherwise
*/
int QueueEmpty(Queue q){
    //Queue is empty if q.last==q.first
    return q.last==q.first;
}

/**
 * @return the first element of the queue without dequeueing it
*/
void* QueueStart(Queue q){
    return q.array.data[q.first];
}

/**
 * @brief destroys the queue
*/
void destroyQueue(Queue q, DestructorFunction d){
    if(q.first<q.last){
        for(int i=q.first; i<=q.last;i++){
            d(q.array.data[i]);
        }
    }else{
        for(int i=q.first; i<q.last+q.max_size;i++){
            d(q.array.data[i%q.max_size]);
        }
    }
}
