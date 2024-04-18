#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "elements.h"
#include "maze.h"

/****************************************
 *
 *  DEFAULT PRINT FUNCTIONS
 *
 ***************************************
 */

int char_print(FILE *fp, const void *p) {
    char c;
    if (!fp || !p) {
        fprintf(stderr, "Wrong arguments to function char_print\n");
        return -1;
    }
    c = *(char *)p;
    return fprintf(fp, "%c ", c);
}

int int_print(FILE *fp, const void *p) {
    if (!fp || !p) {
        fprintf(stderr, "Wrong arguments to function int_print\n");
        return -1;
    }
    return fprintf(fp, "%d ", *((int *)p));
}

int string_print(FILE *fp, const void *s) {
    if (!fp || !s) {
        fprintf(stderr, "Wrong arguments to function string_print\n");
        return -1;
    }
    return fprintf(fp, "%s ", (const char *)s);
}

/*****************************************************************************
 *
 *  COMPARISON FUNCTIONS
 *
 *  Functions of type compare_elem_fn, i.e.
 *  int (*cmp) (const void* elem1, const void* elem2)
 *****************************************************************************
 */

int int_cmp(const void *elem1, const void *elem2) {
    const int *num1 = (const int *)elem1;
    const int *num2 = (const int *)elem2;
    
    if (*num1 < *num2)
        return -1;
    else if (*num1 > *num2)
        return 1;
    else
        return 0;
}

int point_cmp(const void *p1, const void *p2) {
    const Point *point1 = (const Point *)p1;
    const Point *point2 = (const Point *)p2;
    
    double dist1 = sqrt(point_getX(point1)*point_getX(point1) + point_getY(point1)*point_getY(point1));
    double dist2 = sqrt(point_getX(point2)*point_getX(point2) + point_getY(point2)*point_getY(point2));
    
    if (dist1 < dist2)
        return -1;
    else if (dist1 > dist2)
        return 1;
    else
        return (point_getX(point1) - point_getX(point2)); 
}

int string_cmp(const void *s1, const void *s2) {
    return strcmp((const char *)s1, (const char *)s2);
}

int char_cmp(const void *c1, const void *c2) {
    const char *char1 = (const char *)c1;
    const char *char2 = (const char *)c2;
    
    if (*char1 < *char2)
        return -1;
    else if (*char1 > *char2)
        return 1;
    else
        return 0;
}