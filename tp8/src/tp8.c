/**
 * @file tp8.c
 * @brief Three classic ciphers selectable from the command line: Caesar,
 *        Vigenere and Scytale.
 * @author Lilian Naretto
 */

#define _POSIX_C_SOURCE 200809L /* for getline() */

#include "tp8.h"

void print_usage(void) {
    printf("Invalid argument\n");
    printf("Available ciphers:\n");
    printf("Cesar\n");
    printf("Vigenere\n");
    printf("Scytale\n");
}

/** Shifts a single letter by `shift` positions, leaving other characters untouched. */
static char shift_letter(char c, int shift) {
    if (c >= 'A' && c <= 'Z') {
        return (char)('A' + (c - 'A' + shift + 26 * 100) % 26);
    }
    if (c >= 'a' && c <= 'z') {
        return (char)('a' + (c - 'a' + shift + 26 * 100) % 26);
    }
    return c;
}

void caesar_cipher(void) {
    char *word = NULL;
    size_t buf_size = 0;
    int shift;

    printf("Enter a word: ");
    ssize_t length = getline(&word, &buf_size, stdin);
    if (length < 0) {
        free(word);
        return;
    }

    printf("Enter the shift: ");
    scanf("%d", &shift);

    char *encoded = malloc((length + 1) * sizeof(char));
    for (ssize_t i = 0; i < length; i++) {
        encoded[i] = shift_letter(word[i], shift);
    }
    encoded[length] = '\0';

    printf("Encoded word: %s\n", encoded);

    free(word);
    free(encoded);
}

void vigenere_cipher(void) {
    char *word = NULL, *key = NULL;
    size_t word_buf = 0, key_buf = 0;

    printf("Enter a word: ");
    ssize_t word_len = getline(&word, &word_buf, stdin);
    printf("Enter a key: ");
    ssize_t key_len = getline(&key, &key_buf, stdin);
    if (word_len < 0 || key_len < 1) {
        free(word);
        free(key);
        return;
    }

    /* key_len - 1 excludes the key's own trailing newline */
    ssize_t effective_key_len = key_len - 1;
    char *encoded = malloc((word_len + 1) * sizeof(char));

    for (ssize_t i = 0; i < word_len; i++) {
        int shift = tolower(key[i % effective_key_len]) - 'a';
        encoded[i] = shift_letter(word[i], shift);
    }
    encoded[word_len] = '\0';

    printf("Encoded word: %s\n", encoded);

    free(word);
    free(key);
    free(encoded);
}

void scytale_cipher(void) {
    char *word = NULL;
    size_t buf_size = 0;

    printf("Enter a word: ");
    ssize_t length = getline(&word, &buf_size, stdin);
    if (length < 1) {
        free(word);
        return;
    }
    length--; /* drop the trailing newline */

    int side = 1;
    while (side * side < length) {
        side++;
    }

    char **grid = malloc(side * sizeof(char *));
    for (int row = 0; row < side; row++) {
        grid[row] = malloc(side * sizeof(char));
    }

    int pos = 0;
    for (int row = 0; row < side; row++) {
        for (int col = 0; col < side; col++) {
            grid[row][col] = (pos < length) ? word[pos] : ' ';
            pos++;
        }
    }

    printf("Encoded word: ");
    for (int col = 0; col < side; col++) {
        for (int row = 0; row < side; row++) {
            printf("%c", grid[row][col]);
        }
    }
    printf("\n");

    for (int row = 0; row < side; row++) {
        free(grid[row]);
    }
    free(grid);
    free(word);
}

/** Case-insensitive string comparison (portable stand-in for strcasecmp). */
static int equals_ignore_case(const char *a, const char *b) {
    while (*a && *b) {
        if (tolower((unsigned char)*a) != tolower((unsigned char)*b)) {
            return 0;
        }
        a++;
        b++;
    }
    return *a == *b;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        print_usage();
        return 1;
    }

    if (equals_ignore_case(argv[1], "cesar")) {
        caesar_cipher();
    } else if (equals_ignore_case(argv[1], "vigenere")) {
        vigenere_cipher();
    } else if (equals_ignore_case(argv[1], "scytale")) {
        scytale_cipher();
    } else {
        print_usage();
        return 1;
    }

    return 0;
}
