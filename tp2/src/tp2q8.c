/**
 * @file tp2q8.c
 * @brief Computes how many years it takes for the yearly interest on a
 *        principal (compounded at 3.5% per year) to reach 1000.
 * @author Lilian Naretto
 */

#include <stdio.h>

int main(void) {
    int capital;
    int years = 0;
    float interest = 0;

    printf("Enter the starting capital: ");
    scanf("%d", &capital);

    while (interest <= 1000) {
        interest = (capital * 3.5f) / 100.f;
        capital += (int)interest;
        years++;
    }

    printf("Number of years needed: %d\n", years);
    return 0;
}
