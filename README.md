# DataStructure_Queue
An implementation for queue data structure using C Programing
Version 1.0 at 16 Aug 2022

# Files
    v1.0  -> Queue.c
          -> Queue.h
          -> Queue.c 
      
# Implement functions	
	  Main functions:	
        queue_st *Queue_create(void);
        int Queue_enqueue(queue_st *queue, int data);
        int Queue_dequeue(queue_st *queue, int *data);
        void Queue_clear(queue_st *queue);
	  Utalities Functions:	
        void Queue_print(queue_st *queue);
        int Queue_get_front(queue_st *queue);
        int Queue_get_rear(queue_st *queue);
        int Queue_is_full(queue_st *queue);
        int Queue_is_empty(queue_st *queue);    
        void Queue_validity(queue_st *queue);
