#include <stdio.h>
#include <stdlib.h>
#include "maze.h"
#include "search.h"

int main(int argc, char *argv[]) {
    Maze *maze;
    
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
    maze_print(stdout, maze);

    printf("\nBFS:\n");
    maze_bfs(maze);
    printf("\n");

    maze_free(maze);
    return EXIT_SUCCESS;
}
