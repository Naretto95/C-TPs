/**
 * @file tp2q3.c
 * @brief Reads two integers and prints them back.
 * @author Lilian Naretto
 */

#include <stdio.h>

int main(void) {
    int x, y;

    printf("Enter a first number: ");
    scanf("%d", &x);
    printf("Enter a second number: ");
    scanf("%d", &y);

    printf("The numbers are: %d %d\n", x, y);
    return 0;
}
