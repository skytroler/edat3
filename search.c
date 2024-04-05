#include "search.h"
#include "stack.h"
#include <stdio.h>

Point *maze_dfs(Maze *m) {
    if (m == NULL) {
        fprintf(stderr, "Maze is NULL\n");
        return NULL;
    }

    Point *entry = maze_getIn(m);
    Point *exit = maze_getOut(m);

    if (entry == NULL || exit == NULL) {
        fprintf(stderr, "Entry or exit point is NULL\n");
        return NULL;
    }

    Stack *s = stack_new(100); // Pass the capacity argument
    if (s == NULL) {
        fprintf(stderr, "Failed to create stack\n");
        return NULL;
    }

    Point *p = NULL;
    stack_push(s, entry);

    while (p != exit && !stack_isEmpty(s)) {
        p = stack_pop(s);

        if (!point_getVisited(p)) {
            point_setVisited(p, true);
            point_print(stdout, p);

            direction dirs[4] = {UP, RIGHT, DOWN, LEFT};
            for (int i = 0; i < 4; i++) {
                Point *pn = maze_getNeighbor(m, p, dirs[i]);
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
