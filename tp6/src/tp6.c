/**
 * @file tp6.c
 * @brief A two-player Connect Four style game on a 5x5 board.
 * @author Lilian Naretto
 */

#include "tp6.h"

void init_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            board[row][col] = EMPTY;
        }
    }
}

void print_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    printf("   ");
    for (int col = 0; col < BOARD_SIZE; col++) {
        printf(" %d  ", col);
    }
    printf("\n");

    for (int row = 0; row < BOARD_SIZE; row++) {
        printf("  +---+---+---+---+---+\n");
        printf("%d ", row);
        for (int col = 0; col < BOARD_SIZE; col++) {
            char symbol = ' ';
            if (board[row][col] == PLAYER_ONE) {
                symbol = 'X';
            } else if (board[row][col] == PLAYER_TWO) {
                symbol = 'O';
            }
            printf("| %c ", symbol);
        }
        printf("|\n");
    }
    printf("  +---+---+---+---+---+\n");
}

int drop_disc(int board[BOARD_SIZE][BOARD_SIZE], int player, int col) {
    for (int row = BOARD_SIZE - 1; row >= 0; row--) {
        if (board[row][col] == EMPTY) {
            board[row][col] = player;
            return 1;
        }
    }
    return 0;
}

/** Counts how many consecutive cells starting at (row, col) belong to `player`. */
static int count_in_direction(int board[BOARD_SIZE][BOARD_SIZE], int row, int col,
                               int row_step, int col_step, int player) {
    int count = 0;
    while (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE &&
           board[row][col] == player) {
        count++;
        row += row_step;
        col += col_step;
    }
    return count;
}

int check_winner(int board[BOARD_SIZE][BOARD_SIZE]) {
    static const int directions[4][2] = {
        {0, 1},  /* horizontal  */
        {1, 0},  /* vertical    */
        {1, 1},  /* diagonal \  */
        {1, -1}, /* diagonal /  */
    };

    int empty_cells = 0;
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            int player = board[row][col];
            if (player == EMPTY) {
                empty_cells++;
                continue;
            }
            for (int d = 0; d < 4; d++) {
                int run = count_in_direction(board, row, col, directions[d][0], directions[d][1], player);
                if (run >= WIN_LENGTH) {
                    return player;
                }
            }
        }
    }

    return empty_cells == 0 ? 0 : EMPTY;
}

/** Asks the current player for a valid, non-full column and plays it. */
static void play_turn(int board[BOARD_SIZE][BOARD_SIZE], int player) {
    int col;
    printf("player%d, choose a column: ", player);
    scanf("%d", &col);

    while (col < 0 || col >= BOARD_SIZE || !drop_disc(board, player, col)) {
        printf("Invalid move, try again\n");
        printf("player%d, choose a column: ", player);
        scanf("%d", &col);
    }
}

void play_game(int board[BOARD_SIZE][BOARD_SIZE]) {
    int current_player = PLAYER_ONE;

    while (check_winner(board) == EMPTY) {
        play_turn(board, current_player);
        print_board(board);
        current_player = (current_player == PLAYER_ONE) ? PLAYER_TWO : PLAYER_ONE;
    }

    int result = check_winner(board);
    if (result == PLAYER_ONE) {
        printf("player1 wins!\n");
    } else if (result == PLAYER_TWO) {
        printf("player2 wins!\n");
    } else {
        printf("It's a draw!\n");
    }
}

int main(void) {
    int board[BOARD_SIZE][BOARD_SIZE];
    init_board(board);
    print_board(board);
    play_game(board);
    return 0;
}
