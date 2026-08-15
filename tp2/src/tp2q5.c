/**
 * @file tp2q5.c
 * @brief Reads a numerator and a denominator and prints their integer division.
 * @author Lilian Naretto
 */

#include <stdio.h>

int main(void) {
    int numerator, denominator;

    printf("Enter the numerator and the denominator: ");
    scanf("%d", &numerator);
    scanf("%d", &denominator);

    if (denominator != 0) {
        printf("%d / %d = %d\n", numerator, denominator, numerator / denominator);
    } else {
        printf("Division by zero is not allowed.\n");
    }

    return 0;
}
