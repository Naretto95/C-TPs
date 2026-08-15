/**
 * @file tp4.c
 * @brief Six numerical methods approximating pi or sqrt(2).
 * @author Lilian Naretto
 */

#include "tp4.h"

float monte_carlo_pi(int iterations) {
    int inside = 0;
    srand((unsigned int)time(NULL));

    for (int i = 0; i < iterations; i++) {
        float x = (float)rand() / (float)RAND_MAX;
        float y = (float)rand() / (float)RAND_MAX;
        if (x * x + y * y < 1) {
            inside++;
        }
    }

    return (4.0f * inside) / iterations;
}

float madhava_pi(int terms) {
    float sum = 1.0f;
    float term = 1.0f;
    for (int i = 1; i < terms; i++) {
        term /= -3.0f;
        sum += term / (2 * i + 1);
    }
    return sqrtf(12.0f) * sum;
}

float wallis_pi(int terms) {
    float product = 1.0f;
    for (int k = 1; k <= terms; k++) {
        float even = 2.0f * k;
        product *= (even / (even - 1)) * (even / (even + 1));
    }
    return product * 2;
}

float newton_sqrt2(int iterations) {
    float root = 1;
    for (int i = 1; i < iterations; i++) {
        root = ((2 / root) + root) / 2;
    }
    return root;
}

float halley_sqrt2(int iterations) {
    float root = 1;
    for (int i = 1; i < iterations; i++) {
        root = root * ((root * root + 6) / (3 * root * root + 2));
    }
    return root;
}

float theon_sqrt2(int iterations) {
    float root = 1;
    for (int i = 1; i < iterations; i++) {
        root = (root + 2) / (root + 1);
    }
    return root;
}

int main(void) {
    int iterations, choice;

    printf("Choose a method (1-6): ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 6) {
        printf("Invalid choice\n");
        return 0;
    }

    printf("Number of iterations: ");
    scanf("%d", &iterations);

    switch (choice) {
        case 1:
            printf("pi = %f\n", monte_carlo_pi(iterations));
            break;
        case 2:
            printf("pi = %f\n", madhava_pi(iterations));
            break;
        case 3:
            printf("pi = %f\n", wallis_pi(iterations));
            break;
        case 4:
            printf("sqrt(2) = %f\n", newton_sqrt2(iterations));
            break;
        case 5:
            printf("sqrt(2) = %f\n", halley_sqrt2(iterations));
            break;
        case 6:
            printf("sqrt(2) = %f\n", theon_sqrt2(iterations));
            break;
    }

    return 0;
}
