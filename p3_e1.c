#include <stdio.h>
#include <stdlib.h>
#include "elements.h"
#include "maze.h"
#include "sorted_queue.h"

#define SIZE 10


int main(){

    SortedQueue *intQueue = NULL;
    SortedQueue* stringQueue = NULL;
    SortedQueue *charQueue = NULL;
    SortedQueue *pointQueue = NULL;
    int i = 0;
    int num = 24;
    char* string= "wow";
    char newChar = 'c';
    Point *newPoint = point_new(1, 4, WALL);
    char charArray[SIZE] = {'e', 'a', 'r', 't', 'h', 'm', 'z', 'j', 's', 'x'};
    int intArray[SIZE] = {4, 5, 12, 21, 29, 35, 40, 42, 48, 3};
    char *stringArray[SIZE] = {"hello", "good", "morning", "spain", "it", "is", "very", "hot", "right", "now"};
    Point *pointArray[SIZE];
    
    /*INTERGER TEST*/

    printf("Testing SortedQueue with integers:\n");

    intQueue = squeue_new();

    for (i = 0; i < SIZE; i++) {
        squeue_push(intQueue, &intArray[i], int_cmp);
    }
    squeue_print(stdout, intQueue, int_print);
    printf("\nInserting number 24 into the SortedQueue\n");
    squeue_push(intQueue, &num, int_cmp);
    squeue_print(stdout, intQueue, int_print);
    squeue_free(intQueue);


    /*STRING TEST*/

    printf("\nTesting SortedQueue with strings:\n");
    stringQueue = squeue_new();
    for (i = 0; i < SIZE; i++) {
        squeue_push(stringQueue, stringArray[i], string_cmp);
    }
    squeue_print(stdout, stringQueue, string_print);
    printf("\nInserting string 'wow' into queue:\n");
    squeue_push(stringQueue, string, string_cmp);
    squeue_print(stdout, stringQueue, string_print);
    squeue_free(stringQueue);


    /*CHAR TEST*/

    printf("\nTesting SortedQueue with characters:\n");
    charQueue = squeue_new();
    for (i = 0; i < SIZE; i++) {
        squeue_push(charQueue, &charArray[i], char_cmp);
    }
    squeue_print(stdout, charQueue, char_print);
    printf("\nInserting character 'c' into queue:\n");
    squeue_push(charQueue, &newChar, char_cmp);
    squeue_print(stdout, charQueue, char_print);
    squeue_free(charQueue);


    /*POINT TEST*/

    printf("\nTesting SortedQueue with Points:\n");
    pointQueue = squeue_new();
    pointArray[0] = point_new(1, 2, WALL);
    pointArray[1] = point_new(2, 1, IN);
    pointArray[2] = point_new(4, 3, SPACE);
    pointArray[3] = point_new(2, 3, IN);
    pointArray[4] = point_new(1, 5, WALL);
    pointArray[5] = point_new(4, 2, WALL);
    pointArray[6] = point_new(8, 3, IN);
    pointArray[7] = point_new(6, 4, WALL);
    pointArray[8] = point_new(12, 3, SPACE);
    pointArray[9] = point_new(21, 5, WALL);

    for (i = 0; i < SIZE; i++) {
        squeue_push(pointQueue, pointArray[i], point_cmp);
    }
    squeue_print(stdout, pointQueue, point_print);
    printf("\nInserting a new Point [(1,4): +] into queue:\n");
    squeue_push(pointQueue, newPoint, point_cmp);
    squeue_print(stdout, pointQueue, point_print);
    squeue_free(pointQueue);


    
    return 0;
}