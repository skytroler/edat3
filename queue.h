#ifndef QUEUE_H
#define QUEUE_H

#include "elements.h"
#include "types.h"
#include <stdbool.h>
#include <stdio.h>

/**
 * @brief Data type to declare a queue variable.
 *
 **/
typedef struct _Queue Queue;

/**
 * @brief This function creates and initializes a queue.
 *
 * @return A pointer to the queue if it could be created or NULL in case of
 * error.
 *  */
Queue *queue_new();

/**
 * @brief This function frees the memory used by the queue, but not the elements
 * that it may contain.
 *
 * @param q A pointer to the queue to be freed.
 *  */
void queue_free(Queue *q);

/**
 * @brief Checks whether the queue is empty or not.
 *
 * @param q A pointer to the queue.
 *
 * @return TRUE if the queue is empty, FALSE if it is not.
 */
bool queue_isEmpty(const Queue *q);

/**
 * @brief This function is used to insert an element at the back position of a
 * queue. A reference to the element is added to the queue container and the
 * size is increased by 1. Time complexity: O(1).
 *
 * @param q A pointer to the queue.
 * @param ele A pointer to the element to be inserted.
 *
 * @return OK on success, ERROR otherwise.
 *  */
Status queue_push(Queue *q, void *ele);

/**
 * @brief This function is used to extract an element from the front position of
 * a queue. A reference to the element is returned and the size is decreased
 * by 1. Time complexity: O(1).
 *
 * @param s q pointer to the queue.
 *
 * @return A pointer to the extracted element on success, NULL in case of error.
 * */
void *queue_pop(Queue *q);

/**
 * @brief This function is used to get a reference to the element in the front
 * position of a queue.
 *
 * @param q A pointer to the queue.
 *
 * @return A pointer to the element in the front position, NULL in case of
 * error.
 * */
void *queue_getFront(const Queue *q);

/**
 * @brief This function is used to get a reference to the element in the back
 * position of a queue.
 *
 * @param q A pointer to the queue.
 *
 * @return A pointer to the element in the back position, NULL in case of error.
 * */
void *queue_getBack(const Queue *q);

/**
 * @brief This function returns the size of a queue. Note that the function
 * returns 0 if it is called with a NULL pointer. Time complexity: O(1).
 *
 * @param q A pointer to the queue.
 *
 * @return The queue size, 0 in case of error.
 */
size_t queue_size(const Queue *q);

/**
 * @brief  This function prints the queue content to an output stream.
 *
 * @param fp A pointer to the stream.
 * @param q A pointer to the queue to be printed.
 * @param f A pointer to the function used to print each queue element.
 *
 * @return On success this function returns the number of characters printed. In
 * case of error it returns a negative value.
 *  */
int queue_print(FILE *fp, const Queue *q, print_elem_fn print_elem);

#endif /* QUEUE_H */
