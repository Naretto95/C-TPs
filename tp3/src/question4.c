/**
 * @file question4.c
 * @brief Small menu offering a multiplication table, a cubic-equation root
 *        finder (bisection method) and a factorial function.
 * @author Lilian Naretto
 */

#include <stdio.h>

void print_multiplication_table(int n) {
    if (n > 10) {
        printf("Number too large\n");
        return;
    }
    for (int i = 1; i < 10; i++) {
        printf("%d * %d = %d\n", i, n, i * n);
    }
}

float cubic(float n) {
    return n * n * n + 12 * n * n + 1;
}

/** Finds a root of cubic() between -15 and -10 using bisection. */
double solve_cubic_bisection(void) {
    float a = -15, b = -10, m = a;
    while ((b - a) > 0.00001) {
        m = (a + b) / 2;
        if (cubic(a) * cubic(m) < 0) {
            b = m;
        } else {
            a = m;
        }
    }
    return m;
}

int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main(void) {
    int n, choice;
    printf("Choose an exercise (1-3): ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 3) {
        printf("Invalid choice\n");
        return 0;
    }

    switch (choice) {
        case 1:
            printf("Enter a number: ");
            scanf("%d", &n);
            print_multiplication_table(n);
            break;
        case 2:
            printf("%lf\n", solve_cubic_bisection());
            break;
        case 3:
            printf("Enter a number: ");
            scanf("%d", &n);
            printf("%d\n", factorial(n));
            break;
    }

    return 0;
}
