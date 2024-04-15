#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sorted_queue.h"
#include "maze.h"

// Function to compare two integers
int int_cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to compare two points based on their symbols
int point_cmp(const void *p1, const void *p2) {
    const Point *point1 = (const Point *)p1;
    const Point *point2 = (const Point *)p2;

    return (point_getSymbol(point1) - point_getSymbol(point2));
}

// Function to compare two strings
int string_cmp(const void *s1, const void *s2) {
    return strcmp((char *)s1, (char *)s2);
}

// Test function for SortedQueue with different types of data
void test_sorted_queue() {
    // Testing with integers
    SortedQueue *int_queue = squeue_new();
    int nums[] = {5, 3, 8, 1, 6};
    int i; // Declare 'i' outside the loop for C90 compatibility
    for (i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
        squeue_push(int_queue, &nums[i], int_cmp);
    }
    printf("Sorted Queue of Integers: ");
    squeue_print(stdout, int_queue, int_print);
    printf("\n");
    squeue_free(int_queue);

    // Testing with points
    SortedQueue *point_queue = squeue_new();
    Point *p1 = point_new(1, 2, 'A');
    Point *p2 = point_new(3, 4, 'B');
    Point *p3 = point_new(5, 6, 'C');
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

    // Testing with strings
    SortedQueue *string_queue = squeue_new();
    char *strings[] = {"banana", "apple", "orange", "grape", "pear"};
    for (i = 0; i < sizeof(strings) / sizeof(strings[0]); i++) {
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
