#include <stdio.h>
#include <stdlib.h>
#include "elements.h"
#include "maze.h"
#include "sorted_queue.h"

#define SIZE 10


int main(){

    SortedQueue *charQueue = NULL;
    SortedQueue *pointsQueue = NULL;
    SortedQueue *intsQueue = NULL;
    SortedQueue* stringsQueue = NULL;
    
    int i = 0, num = 57;
    char* string= "bye";
    char newChar = 'z';
    char charArray[SIZE] = {'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y'};
    int intArray[SIZE] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    char *stringArray[SIZE] = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "kiwi", "lemon"};

    Point *newPoint = point_new(3, 7, WALL);
    Point *pointArray[SIZE];
    

    printf("Testing SortedQueue with ints:\n");

    intsQueue = squeue_new();

    for (i = 0; i < SIZE; i++) 
    {
        squeue_push(intsQueue, &intArray[i], int_cmp);
    }
    squeue_print(stdout, intsQueue, int_print);

    printf("\nInserting 57 into the SortedQueue\n");
    squeue_push(intsQueue, &num, int_cmp);
    squeue_print(stdout, intsQueue, int_print);
    squeue_free(intsQueue);

    printf("\nTesting SortedQueue with strings:\n");

    stringsQueue = squeue_new();
    for (i = 0; i < SIZE; i++) 
    {
        squeue_push(stringsQueue, stringArray[i], string_cmp);
    }
    squeue_print(stdout, stringsQueue, string_print);

    printf("\nInserting 'bye' into queue:\n");
    squeue_push(stringsQueue, string, string_cmp);
    squeue_print(stdout, stringsQueue, string_print);
    squeue_free(stringsQueue);

    printf("\nTesting SortedQueue with chars:\n");

    charQueue = squeue_new();
    for (i = 0; i < SIZE; i++) {
        squeue_push(charQueue, &charArray[i], char_cmp);
    }
    squeue_print(stdout, charQueue, char_print);

    printf("\nInserting 'z' into queue:\n");
    squeue_push(charQueue, &newChar, char_cmp);
    squeue_print(stdout, charQueue, char_print);
    squeue_free(charQueue);

    printf("\nTesting SortedQueue with Points:\n");

    pointArray[0] = point_new(5, 3, WALL);
    pointArray[1] = point_new(3, 1, IN);
    pointArray[2] = point_new(7, 5, SPACE);
    pointArray[3] = point_new(8, 4, IN);
    pointArray[4] = point_new(2, 5, WALL);
    pointArray[5] = point_new(4, 6, WALL);
    pointArray[6] = point_new(6, 2, IN);
    pointArray[7] = point_new(1, 2, WALL);
    pointArray[8] = point_new(4, 3, SPACE);
    pointArray[9] = point_new(3, 7, WALL);

    for (i = 0; i < SIZE; i++) 
    {
        squeue_push(pointsQueue, pointArray[i], point_cmp);
    }

    squeue_print(stdout, pointsQueue, point_print);
    
    printf("\nInserting Point [(3,7): +] into queue:\n");
    squeue_push(pointsQueue, newPoint, point_cmp);
    squeue_print(stdout, pointsQueue, point_print);
    squeue_free(pointsQueue);
    
    return 0;
}