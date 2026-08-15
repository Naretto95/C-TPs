/**
 * @file tp9.c
 * @brief Conway's Game of Life on a small, wrapping (toroidal) grid.
 * @author Lilian Naretto
 */

#include "tp9.h"

void create_grid(int grid[GRID_HEIGHT][GRID_WIDTH]) {
    for (int row = 0; row < GRID_HEIGHT; row++) {
        for (int col = 0; col < GRID_WIDTH; col++) {
            int value;
            printf("value of cell %d - %d: ", row, col);
            scanf("%d", &value);
            while (value != DEAD && value != ALIVE) {
                printf("Invalid value, try again (0 or 1)\n");
                printf("value of cell %d - %d: ", row, col);
                scanf("%d", &value);
            }
            grid[row][col] = value;
        }
    }
}

void print_grid(int grid[GRID_HEIGHT][GRID_WIDTH]) {
    for (int row = 0; row < GRID_HEIGHT; row++) {
        for (int col = 0; col < GRID_WIDTH; col++) {
            printf(grid[row][col] == ALIVE ? "V " : ". ");
        }
        printf("\n");
    }
}

/** Wraps an index into the range [0, size), so the grid edges connect. */
static int wrap(int index, int size) {
    return (index + size) % size;
}

int count_alive_neighbors(int grid[GRID_HEIGHT][GRID_WIDTH], int row, int col) {
    int count = 0;
    for (int dr = -1; dr <= 1; dr++) {
        for (int dc = -1; dc <= 1; dc++) {
            if (dr == 0 && dc == 0) {
                continue;
            }
            int neighbor_row = wrap(row + dr, GRID_HEIGHT);
            int neighbor_col = wrap(col + dc, GRID_WIDTH);
            if (grid[neighbor_row][neighbor_col] == ALIVE) {
                count++;
            }
        }
    }
    return count;
}

int next_cell_state(int grid[GRID_HEIGHT][GRID_WIDTH], int row, int col) {
    int neighbors = count_alive_neighbors(grid, row, col);
    if (grid[row][col] == ALIVE) {
        return (neighbors == 2 || neighbors == 3) ? ALIVE : DEAD;
    }
    return (neighbors == 3) ? ALIVE : DEAD;
}

void compute_next_generation(int grid[GRID_HEIGHT][GRID_WIDTH]) {
    int next[GRID_HEIGHT][GRID_WIDTH];
    for (int row = 0; row < GRID_HEIGHT; row++) {
        for (int col = 0; col < GRID_WIDTH; col++) {
            next[row][col] = next_cell_state(grid, row, col);
        }
    }
    for (int row = 0; row < GRID_HEIGHT; row++) {
        for (int col = 0; col < GRID_WIDTH; col++) {
            grid[row][col] = next[row][col];
        }
    }
}

void run_game_of_life(int grid[GRID_HEIGHT][GRID_WIDTH], int generations) {
    for (int step = 0; step < generations; step++) {
        compute_next_generation(grid);
        print_grid(grid);
        printf("\n");
    }
}

int main(void) {
    int grid[GRID_HEIGHT][GRID_WIDTH];
    int generations;

    create_grid(grid);
    printf("\n");
    print_grid(grid);

    printf("Number of generations to simulate: ");
    scanf("%d", &generations);
    printf("\n");

    run_game_of_life(grid, generations);
    return 0;
}
