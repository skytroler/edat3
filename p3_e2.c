#include <stdio.h>
#include <stdlib.h>
#include "maze.h"
#include "search.h"

int main(int argc, char *argv[]) {
    Maze *maze;
    Point *result;


    if (argc != 2) {
        fprintf(stderr, "Usage: %s <maze_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    maze = maze_readFromFile(argv[1]);
    if (maze == NULL) {
        fprintf(stderr, "Error reading maze from file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    printf("Reading maze from file %s\n", argv[1]);
    printf("Maze: %d rows %d columns\n", maze_getNrows(maze), maze_getNcols(maze));
    maze_printPoints(stdout, maze);

    printf("\nBreadth First Search (BFS):\n");
    result = maze_bfs(maze);

    if (result != NULL) {
        printf("\nA path from entry point to exit point has been found!\n");
        printf("Found path:\n");
        maze_print(stdout, maze);
    } else {
        printf("\nNo path from entry point to exit point found.\n");
    }

    maze_free(maze);
    return EXIT_SUCCESS;
}
