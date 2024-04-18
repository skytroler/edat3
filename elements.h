#ifndef _ELEMENTS_H
#define _ELEMENTS_H

#include "types.h"
#include <stdio.h>

/* function type to print an element */
typedef int (*print_elem_fn)(FILE *, const void *elem);

/* function type to compare two elements */
typedef int (*compare_elem_fn)(const void *elem1, const void *elem2);

/* ADD ADDITIONAL FUNCTION TYPES HERE AS NEEDED */
/* you might want to consider functions to initialize, copy, free elements... In
the first two cases, should they allocate memory or not? or should we have two
versions to allow for both options? */

/* HERE ARE TWO EXAMPLES */
/* function type to convert strings to elements of the appropriate type */
/* the functions should allocate memory for the element */
typedef void *(*elem_from_string_fn)(const char *str);

/* generic function type to process an element */
typedef void (*process_elem_fn)(const void *element);

/* PROTOTYPES FOR SPECIFIC FUNCTIONS OF THESE TYPES*/
int int_print(FILE *pf, const void *a);
int char_print(FILE *pf, const void *a);
int string_print(FILE *pf, const void *s);
int int_cmp(const void *elem1, const void *elem2);
int point_cmp(const void *p1, const void *p2);
int string_cmp(const void *s1, const void *s2);
int char_cmp(const void *c1, const void *c2);

#endif