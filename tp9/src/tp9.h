#ifndef TP9_H
#define TP9_H

#include <stdio.h>

#define GRID_HEIGHT 5
#define GRID_WIDTH 5
#define ALIVE 1
#define DEAD 0

/** Prompts the user for each cell's initial state (0 or 1). */
void create_grid(int grid[GRID_HEIGHT][GRID_WIDTH]);

/** Prints the grid, using 'V' for alive cells and '.' for dead ones. */
void print_grid(int grid[GRID_HEIGHT][GRID_WIDTH]);

/** Counts the living neighbors of (row, col) on a wrapping (toroidal) grid. */
int count_alive_neighbors(int grid[GRID_HEIGHT][GRID_WIDTH], int row, int col);

/** Applies Conway's rules to a single cell and returns its next state. */
int next_cell_state(int grid[GRID_HEIGHT][GRID_WIDTH], int row, int col);

/** Advances the grid by one generation. */
void compute_next_generation(int grid[GRID_HEIGHT][GRID_WIDTH]);

/** Runs and prints `generations` steps of the Game of Life. */
void run_game_of_life(int grid[GRID_HEIGHT][GRID_WIDTH], int generations);

#endif
