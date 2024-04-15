#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sorted_queue.h"
#include "maze.h"

int int_cmp(const void *a, const void *b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    return(ia-ib);
}

int point_cmp(const void *p1, const void *p2) {
    const Point *point1 = (const Point *)p1;
    const Point *point2 = (const Point *)p2;

    double raiz1 = sqrt(pow(point_getX(point1), 2) + pow(point_getY(point1), 2));

    double raiz2 = sqrt(pow(point_getX(point2), 2) + pow(point_getY(point2), 2));

    if(raiz1 < raiz2){
        return -1;
        else if(raiz2 < raiz1)
        return -1;
    } else{
        char symbol
    }


    
}

int string_cmp(const void *s1, const void *s2) {
    return strcmp((char *)s1, (char *)s2);
}

void test_sorted_queue() {
    SortedQueue *int_queue;
    SortedQueue *point_queue;
    SortedQueue *string_queue;
    Point *p1, *p2, *p3;
    char *strings[5] = {"banana", "apple", "orange", "grape", "pear"};
    int nums[5] = {5, 3, 8, 1, 6};
    int i;

    int_queue = squeue_new();
    for (i = 0; i < 5; i++) {
        squeue_push(int_queue, &nums[i], int_cmp);
    }
    printf("Sorted Queue of Integers: ");
    squeue_print(stdout, int_queue, int_print);
    printf("\n");
    squeue_free(int_queue);

    point_queue = squeue_new();
    p1 = point_new(1, 2, WALL);
    p2 = point_new(3, 4, SPACE);
    p3 = point_new(5, 6, IN);
    squeue_push(point_queue, p1, point_cmp);
    squeue_push(point_queue, p2, point_cmp);
    squeue_push(point_queue, p3, point_cmp);
    printf("Sorted Queue of Points: ");
    squeue_print(stdout, point_queue, point_print);
    printf("\n");
    squeue_free(point_queue);
    point_free(p1);
    point_free(p2);
    point_free(p3);

    string_queue = squeue_new();
    for (i = 0; i < 5; i++) {
        squeue_push(string_queue, strings[i], string_cmp);
    }
    printf("Sorted Queue of Strings: ");
    squeue_print(stdout, string_queue, char_print);
    printf("\n");
    squeue_free(string_queue);
}

int main() {
    test_sorted_queue();
    return 0;
}
