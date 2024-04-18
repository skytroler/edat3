#include "sorted_queue.h"
#include "elements.h"
#include "types.h"
#include "maze.h"



Status squeue_push(SortedQueue *q, void *elem, compare_elem_fn cmp) {
    Queue *tempQueue = NULL;
    if (q == NULL || elem == NULL) {
        return ERROR; 
    }

    if (squeue_isEmpty(q)) {
        queue_push(q, elem);
        return OK;
    }

    tempQueue = queue_new();
    if (tempQueue == NULL) {
        return ERROR; 
    }

    while (!squeue_isEmpty(q) && cmp(queue_getFront(q), elem) < 0) {
        if(queue_push(tempQueue, queue_pop(q)) == ERROR){
            queue_free(tempQueue);
            return ERROR;
        }
       
    }
    
    queue_push(tempQueue, elem);

    while (!squeue_isEmpty(q)) {
        if(queue_push(tempQueue, queue_pop(q)) == ERROR){
            queue_free(tempQueue);
            return ERROR;
        }
    }

    while (!squeue_isEmpty(tempQueue)) {
       if(queue_push(q, queue_pop(tempQueue)) == ERROR){
            queue_free(tempQueue);
            return ERROR;
        }
    }

    queue_free(tempQueue);
    

    return OK;
}

    
SortedQueue *squeue_new(){
    return queue_new();
}
void squeue_free(SortedQueue *q){
    queue_free(q);
    return;
}
bool squeue_isEmpty(const SortedQueue *q){
    return queue_isEmpty(q);
}
void *squeue_pop(SortedQueue *q){
    return queue_pop(q);
}
void *squeue_getFront(const SortedQueue *q){
    return queue_getFront(q);
}
void *squeue_getBack(const SortedQueue *q){
    return queue_getBack(q);
}
size_t squeue_size(const SortedQueue *q){
    return queue_size(q);
}
int squeue_print(FILE *fp, const SortedQueue *q, print_elem_fn print_elem){
    return queue_print(fp, q, print_elem);
}