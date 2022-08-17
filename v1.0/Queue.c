/*
 *@file     Queue.c
 *@author   Abdelrahman Belkasy
 *@date     16 August 2022
 *Version   1.0
*/
#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

/* 
------------------------------------------------------------------
!-                     Queue main fuctions
------------------------------------------------------------------
*/
queue_st *Queue_create(void)
{
    /* allocating a new queue with type queue_st*/
    queue_st *queue = (queue_st *) malloc(sizeof(queue_st));
    
    /* check allocating validity */
    Queue_validity(queue);
    
    /* intialize the queue front and rear with -1 */
    queue->queue_front  = -1;
    queue->queue_rear   = -1;

    /* allocating the queue elements */
    queue->queue_elements = (int *) malloc((QUEUE_SIZE)*sizeof(int));

    /* return the queue*/
    return queue;

}    /* Queue_create() */

int Queue_enqueue(queue_st *queue, int data)
{
    Queue_validity(queue);
    if (Queue_is_full(queue))
    {
        printf("Queue_enqueue: queue is full\n");
        return 1;
    }
    else if (Queue_is_empty(queue))
    {
        queue->queue_front  += 1;
        queue->queue_rear   += 1;
        queue->queue_elements[queue->queue_rear] = data; 
        return 0;
    }
    else
    {
        queue->queue_rear   += 1;
        queue->queue_elements[queue->queue_rear] = data; 
        return 0;
    }

}/* Queue_enqueue() */

int Queue_dequeue(queue_st *queue, int *data)
{
    Queue_validity(queue);
    if (Queue_is_empty(queue))
    {
        data = NULL;
        printf("Queue_dequeue : queue is empty\n");
        return 1;

    }
    else if (queue->queue_rear == queue->queue_front)
    {
        *data = queue->queue_elements[queue->queue_front];
        queue->queue_front  = -1;
        queue->queue_rear   = -1;
    }
    else
    {
        *data = queue->queue_elements[queue->queue_front];
        queue->queue_front  += 1;
    }
    return 0;

}/* Queue_dequeue() */
void Queue_clear(queue_st *queue);


void Queue_print(queue_st *queue)
{
    Queue_validity(queue);
    if (Queue_is_empty(queue))
    {
        printf("Queue is empty\n");
    }
    else
    {
        for (int i = 0; i <= queue->queue_rear;  i++)
        {
            printf("%d\n", queue->queue_elements[i]);
        }
    }
} /* Queue_print */

int Queue_get_front(queue_st *queue)
{
    return queue->queue_front;
} /* Queue_get_front */

int Queue_get_rear( queue_st *queue)
{
    return queue->queue_rear;

} /* Queue_get_rear */

int Queue_is_full(queue_st *queue)
{
    return (queue->queue_rear == ((QUEUE_SIZE)-1));
}   /* Queue_is_empty */ 

int Queue_is_empty(queue_st *queue)
{
    return (queue->queue_front == -1) & (queue->queue_rear == -1);
}   /* Queue_is_empty */ 

void Queue_validity(queue_st *queue)
{
    if (queue == NULL) 
    {
        printf("Queue not valid\n");
        exit(1);
    }
    else 
    {
    }
}/* Queue_validity() */
