#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"
#include "list.h"

struct _Queue {
    List *pl;
};

Queue *queue_new() {
    Queue *queue;
    queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        fprintf(stderr, "Error: No se pudo asignar memoria para la cola.\n");
        exit(EXIT_FAILURE);
    }
    queue->pl = list_new(); 
    return queue;
}

void queue_free(Queue *queue) {
    
    if (queue == NULL) return;
    list_free(queue->pl); 
    free(queue);
}

bool queue_isEmpty(const Queue *queue) {
    if (queue == NULL) return true;
    return list_isEmpty(queue->pl); 
}

Status queue_push(Queue *queue, void *ele) {
    if (queue == NULL) return ERROR;
    return list_pushBack(queue->pl, ele);
}

void *queue_pop(Queue *queue) {
    if (queue == NULL) return NULL;
    return list_popFront(queue->pl);
}

void *queue_getFront(const Queue *queue) {
    if (queue == NULL) return NULL;
    return list_getFront(queue->pl);
}

void *queue_getBack(const Queue *queue) {
    if (queue == NULL) return NULL;
    return list_getBack(queue->pl);
}

size_t queue_size(const Queue *queue) {
    if (queue == NULL) return 0;
    return list_size(queue->pl);
}

int queue_print(FILE *fp, const Queue *queue, p_list_ele_print print_elem) {
    if (queue == NULL || fp == NULL || print_elem == NULL) return -1;
    return list_print(fp, queue->pl, print_elem);
}
