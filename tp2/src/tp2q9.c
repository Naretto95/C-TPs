/**
 * @file tp2q9.c
 * @brief Reads a list of integers and prints its minimum and maximum values.
 * @author Lilian Naretto
 */

#include <stdio.h>

int main(void) {
    int size;

    printf("List size: ");
    scanf("%d", &size);

    int list[size];
    printf("Enter the elements of the list:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &list[i]);
    }

    int min = list[0];
    int max = list[0];
    for (int i = 1; i < size; i++) {
        if (list[i] < min) {
            min = list[i];
        }
        if (list[i] > max) {
            max = list[i];
        }
    }

    printf("min: %d, max: %d\n", min, max);
    return 0;
}
