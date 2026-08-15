/**
 * @file tp2q7.c
 * @brief Reads a Richter scale value (1-9) and prints the matching description.
 * @author Lilian Naretto
 */

#include <stdio.h>

int main(void) {
    int magnitude;

    printf("Enter a Richter scale value (1-9): ");
    scanf("%d", &magnitude);

    if (magnitude < 1 || magnitude > 9) {
        printf("Invalid value.\n");
        return 0;
    }

    switch (magnitude) {
        case 1:
            printf("Micro earthquake, not felt.\n");
            break;
        case 2:
            printf("Very minor. Not felt but detected.\n");
            break;
        case 3:
            printf("Minor. Rarely causes damage.\n");
            break;
        case 4:
            printf("Light. Noticeable shaking of objects indoors.\n");
            break;
        case 5:
            printf("Moderate. Slight damage to well-built structures.\n");
            break;
        case 6:
            printf("Strong. Destructive in areas up to 180 km across, if populated.\n");
            break;
        case 7:
            printf("Major. Moderate to severe damage over larger areas.\n");
            break;
        case 8:
            printf("Great. Serious damage over areas of hundreds of kilometers.\n");
            break;
        case 9:
            printf("Devastating. Devastates areas over thousands of kilometers.\n");
            break;
    }

    return 0;
}
