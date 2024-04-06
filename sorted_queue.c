#include <stdio.h>
#include <stdlib.h>

#include "sorted_queue.h"
#define MAX_QUEUE 8

struct Queue{
    void *data[MAX_QUEUE];
    int front;
    int rear;
};

SortedQueue *squeue_new(){
    
    SortedQueue *p = queue_new();
    if(!p){
        return NULL;
    }

    return p;
}

void squeue_free(SortedQueue *q){
    
    if(!q) return;

    queue_free(q);
}

bool squeue_isEmpty(const SortedQueue *q){
    
    if(!q){
        return false;
    }

    return queue_isEmpty(q);
}

Status squeue_push(SortedQueue *q, void *elem, compare_elem_fn cmp){

}

void *squeue_pop(SortedQueue *q){
    void *elem;
    if(!q || squeue_isEmpty(q)==true){
        return NULL;
    }

    elem = queue_pop(q);

    return elem;
}

void *squeue_getFront(const SortedQueue *q){
    void *elem;
    if(!q) return NULL;

    elem = queue_getFront(q);
    return elem;
}

void *squeue_getBack(const SortedQueue *q){
    void *elem;
    if(!q) return NULL;

    elem = queue_getBack(q);
    return elem;
}

size_t squeue_size(const SortedQueue *q){
    if(!q){
        return 0;
    }

    return queue_size(q);
}

int squeue_print(FILE *fp, const SortedQueue *q, print_elem_fn print_elem){
    if(!q){
        return 0;
    }

    return queue_print(fp, q, print_elem);
}