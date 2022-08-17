/*
 *@name     Queue.h
 *@author   Abdelrahman Belkasy
 *@date     16 August 2022
 *Version   1.0
*/
#ifndef _STACK_H
#define _STACK_H
/*
------------------------------------------------------------------
!-                        Queue defines
------------------------------------------------------------------
*/
#define QUEUE_SIZE 1000

typedef struct QUEUE {
    int *queue_elements;
    int queue_front ;
    int queue_rear ;
} queue_st;

/*
------------------------------------------------------------------
!-                        Queue Prototypes
------------------------------------------------------------------
*/
/* *@defgroup Queue main fuctions */
queue_st *Queue_create(void);
int Queue_enqueue(queue_st *queue, int data);
int Queue_dequeue(queue_st *queue, int *data);
void Queue_clear(queue_st *queue);

/* *@defgroup Queue helper functions */
void Queue_print(queue_st *queue);
int Queue_get_front(queue_st *queue);
int Queue_get_rear(queue_st *queue);
int Queue_is_full(queue_st *queue);
int Queue_is_empty(queue_st *queue);    
void Queue_validity(queue_st *queue);


#endif /* _STACK_H */