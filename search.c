#include "search.h"
#include "stack.h"
#include "queue.h"
#include <stdio.h>

Point *maze_dfs(Maze *m) {
    int i;
    Point *entry;
    Point *exit;
    Stack *s;
    Point *p;
    Point *pn;
    direction dirs[4] = {RIGHT, UP, LEFT, DOWN};

    if (m == NULL) {
        fprintf(stderr, "Maze is NULL\n");
        return NULL;
    }

    entry = maze_getIn(m);
    exit = maze_getOut(m);

    if (entry == NULL || exit == NULL) {
        fprintf(stderr, "Entry or exit point is NULL\n");
        return NULL;
    }

    s = stack_new(100); 
    if (s == NULL) {
        fprintf(stderr, "Failed to create stack\n");
        return NULL;
    }

    p = NULL;
    stack_push(s, entry);

    while (p != exit && !stack_isEmpty(s)) {
        p = stack_pop(s);

        if (!point_getVisited(p)) {
            point_setVisited(p, true);
            point_print(stdout, p);

            for (i = 0; i < 4; i++) {
                pn = maze_getNeighbor(m, p, dirs[i]);
                if (pn != NULL && !point_getVisited(pn) &&
                    point_getSymbol(pn) != WALL) {
                    stack_push(s, pn);
                }
            }
        }
    }

    stack_free(s);

    if (p == exit) {
        return p;
    } else {
        return NULL;
    }
}

Point *maze_bfs(Maze *m) {

    int i;
    Point *entry;
    Point *exit;
    Queue *q;
    Point *p;
    Point *pn;

    direction dirs[4] = {RIGHT, UP, LEFT, DOWN};


    if (m == NULL) {
        fprintf(stderr, "Maze is NULL\n");
        return NULL;
    }

    entry = maze_getIn(m);
    exit = maze_getOut(m);

    if (entry == NULL || exit == NULL) {
        fprintf(stderr, "Entry or exit point is NULL\n");
        return NULL;
    }

    q = queue_new(100);
    if (q == NULL) {
        fprintf(stderr, "Failed to create queue\n");
        return NULL;
    }

    p = NULL;
    queue_push(q, entry);

    while (p != exit && !queue_isEmpty(q)) {
        p = queue_pop(q);

        if (!point_getVisited(p)) {
            point_setVisited(p, true);
            point_print(stdout, p);

            for (i = 0; i < 4; i++) {
                pn = maze_getNeighbor(m, p, dirs[i]);
                if (pn != NULL && !point_getVisited(pn) &&
                    point_getSymbol(pn) != WALL) {
                    queue_push(q, pn);
                }
            }
        }
    }

    queue_free(q);

    if (p == exit) {
        return p;
    } else {
        return NULL;
    }
}