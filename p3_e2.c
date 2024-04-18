#include <stdio.h>
#include <stdlib.h>
#include "maze.h"
#include "search.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <maze_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    Maze *maze = maze_read(file);
    fclose(file);

    if (maze == NULL) {
        fprintf(stderr, "Error reading maze from file\n");
        return EXIT_FAILURE;
    }

    printf("Reading maze from %s\n", argv[1]);
    printf("Maze: %d rows %d cols\n", maze_rows(maze), maze_cols(maze));
    maze_print(stdout,maze);

    printf("BFS:\n");
    Point *exit_point = maze_bfs(maze);

    if (exit_point != NULL) {
        printf("Exit found at (%d, %d)\n", point_get_row(exit_point), point_get_col(exit_point));
        point_destroy(exit_point);
    } else {
        printf("No exit found.\n");
    }

    maze_destroy(maze);

    return EXIT_SUCCESS;
}
