/**
 * @file tp2q1.c
 * @brief Reads an integer from standard input and prints it back.
 * @author Lilian Naretto
 */

#include <stdio.h>

int main(void) {
    int number;

    printf("Enter an integer: ");
    scanf("%d", &number);

    printf("You entered: %d\n", number);
    return 0;
}
