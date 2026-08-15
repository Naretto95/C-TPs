#ifndef TP6_H
#define TP6_H

#include <stdio.h>

#define BOARD_SIZE 5
#define WIN_LENGTH 4
#define EMPTY (-1)
#define PLAYER_ONE 1
#define PLAYER_TWO 2

/** Fills the board with EMPTY cells. */
void init_board(int board[BOARD_SIZE][BOARD_SIZE]);

/** Prints the board, using X and O for the two players. */
void print_board(int board[BOARD_SIZE][BOARD_SIZE]);

/**
 * Drops a disc for `player` into `col`, letting it fall to the lowest empty
 * row (gravity). Returns 1 on success, 0 if the column is full.
 */
int drop_disc(int board[BOARD_SIZE][BOARD_SIZE], int player, int col);

/**
 * Returns the winning player (PLAYER_ONE or PLAYER_TWO), 0 for a draw
 * (board full, nobody won), or EMPTY if the game must go on.
 */
int check_winner(int board[BOARD_SIZE][BOARD_SIZE]);

/** Runs the game loop until there is a winner or a draw. */
void play_game(int board[BOARD_SIZE][BOARD_SIZE]);

#endif
