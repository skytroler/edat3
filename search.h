#ifndef SEARCH_H
#define SEARCH_H

#include "maze.h"

/**
 * @brief Perform Depth-First Search (DFS) on the maze.
 * 
 * @param m Pointer to the maze.
 * @return Pointer to the exit point if path exists, NULL otherwise.
 */
Point *maze_dfs(Maze *m);

#endif /* SEARCH_H */
