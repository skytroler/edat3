#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "list.h"

typedef struct _Node{
    void *data;
    struct _Node *next;
} Node;

struct _List{
    Node *front;
};

List *list_new(){
    List *list;
    list = (List*)malloc(sizeof(List));
    if(!list){
        fprintf(stderr, "Error creating the list");
        return NULL;
    }

    list->front = NULL;

    return list;
}

bool list_isEmpty(const List *pl){
    if(!pl || pl->front == NULL){
        return true;
    }

    return false;
}

Status list_pushFront(List *pl, const void *e){
    Node *newnode;
    if (!pl){
        return ERROR;
    }

    newnode = (Node*)malloc(sizeof(Node));
    if(!newnode){
        fprintf(stderr, "Error");
        return ERROR;
    }

    newnode->data = (void*)e;
    newnode->next = pl->front;
    pl->front = newnode;

    return OK;

}

Status list_pushBack(List *pl, const void *e){
    Node *newnode;
    Node *current;

    if (!pl){
        return ERROR;
    }

    newnode = (Node*)malloc(sizeof(Node));
    if(!newnode){
        fprintf(stderr, "Error");
        return ERROR;
    }

    newnode->data = (void*)e;
    newnode->next = NULL;

    if (list_isEmpty(pl)) {
        pl->front = newnode;
    } else {
        current = pl->front;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newnode;
    }
    return OK;

}

void *list_popFront(List *pl) {
    Node *temp;
    void *data;
    if (list_isEmpty(pl)) return NULL;

    temp = pl->front;
    data = temp->data;
    pl->front = pl->front->next;
    free(temp);
    return data;
}

void *list_popBack(List *pl) {
    Node *current;
    void *data;

    if (list_isEmpty(pl)) return NULL;

    if (pl->front->next == NULL) {
        data = pl->front->data;
        free(pl->front);
        pl->front = NULL;
        return data;
    }

    current = pl->front;
    while (current->next->next != NULL) {
        current = current->next;
    }
    data = current->next->data;
    free(current->next);
    current->next = NULL;
    return data;
}

void *list_getFront(List *pl) {
    if (list_isEmpty(pl)) return NULL;
    return pl->front->data;
}

void *list_getBack(List *pl) {
    Node *current;
    if (list_isEmpty(pl)) return NULL;

    current = pl->front;
    while (current->next != NULL) {
        current = current->next;
    }
    return current->data;
}

void list_free(List *pl) {
    if (pl == NULL) return;

    while (!list_isEmpty(pl)) {
        list_popFront(pl);
    }
    free(pl);
}

int list_size(const List *pl) {
    Node *current;
    int count;
    if (pl == NULL) return -1;

    count = 0;
    current = pl->front;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int list_print(FILE *fp, const List *pl, p_list_ele_print f) {
    int totalChars;
    Node *current;
    if (pl == NULL || f == NULL) return -1;

    totalChars = 0;
    current = pl->front;
    while (current != NULL) {
        totalChars += f(fp, current->data);
        current = current->next;
    }
    return totalChars;
}