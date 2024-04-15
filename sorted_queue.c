#include <stdio.h>
#include <stdlib.h>

#include "sorted_queue.h"
#define MAX_QUEUE 8

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
    if (!q) {
        return ERROR;
    }

    while (!queue_isEmpty(q) && cmp(queue_getFront(q), elem) < 0) {
        void *front_elem = queue_pop(q);
        queue_push(q, front_elem);
    }

    queue_push(q, elem);
    
    while (!queue_isEmpty(q) && cmp(queue_getFront(q), elem) >= 0) {
        void *front_elem = queue_pop(q);
        queue_push(q, front_elem);
    }

    return OK;
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