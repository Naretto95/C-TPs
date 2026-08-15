/**
 * @file question1.c
 * @brief Reads an integer from stdin and returns it; exits the program if the
 *        value entered is zero.
 * @author Lilian Naretto
 */

#include <stdio.h>
#include <stdlib.h>

int read_integer(void) {
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);

    if (n == 0) {
        exit(1);
    }

    return n;
}

int main(void) {
    int number = read_integer();
    printf("%d\n", number);
    return 0;
}
