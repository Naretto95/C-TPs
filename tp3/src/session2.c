/**
 * @file session2.c
 * @brief Second session of TP3: a small menu with a tree drawing, a search
 *        for the largest factorial below a bound, an Armstrong number check,
 *        a binary representation printer and a binomial coefficient.
 * @author Lilian Naretto
 */

#include <stdio.h>

/** Draws an ASCII Christmas tree of the given height. */
void draw_tree(int n) {
    if (n <= 1) {
        printf("Invalid number\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < 1 + 2 * (n - 1); k++) {
            putchar(k >= n - 1 - i && k <= n - 1 + i ? '*' : ' ');
        }
        printf("\n");
    }

    for (int i = 0; i < 3; i++) {
        for (int k = 0; k < 1 + 2 * n; k++) {
            putchar(k >= n - 2 && k <= n ? '@' : ' ');
        }
        printf("\n");
    }
}

int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

/** Prints the largest n such that n! is strictly less than k. */
void print_largest_factorial_below(int k) {
    if (k <= 1) {
        printf("Invalid number\n");
        return;
    }
    int i = 1;
    while (factorial(i) < k) {
        i++;
    }
    printf("%d! is the largest factorial below %d\n", i - 1, k);
}

float power(float base, int exponent) {
    float result = 1;
    if (exponent < 0) {
        for (int i = 0; i < -exponent; i++) {
            result *= base;
        }
        return 1 / result;
    }
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

/** An Armstrong number equals the sum of the cubes of its digits. */
void check_armstrong(int n) {
    int sum = 0;
    for (int r = n; r != 0; r /= 10) {
        sum += (int)power(r % 10, 3);
    }

    if (n == sum) {
        printf("%d is an Armstrong number\n", n);
    } else {
        printf("%d is not an Armstrong number\n", n);
    }
}

/** Prints the binary representation of an unsigned integer. */
void print_binary(unsigned int n) {
    const int bit_count = sizeof(int) * 8;
    char bits[bit_count + 1];
    bits[bit_count] = '\0';

    for (int i = 0; i < bit_count; i++) {
        bits[bit_count - 1 - i] = (n % 2 == 0) ? '0' : '1';
        n /= 2;
    }

    printf("Binary representation: %s\n", bits);
}

/** Complexity: O(2^n) — computed directly from factorials. */
int binomial_coefficient(int n, int p) {
    if (n < 0 || p < 0 || n - p < 0) {
        printf("Invalid numbers\n");
        return -1;
    }
    return factorial(n) / (factorial(n - p) * factorial(p));
}

int main(void) {
    int n, p, choice;
    printf("Choose an exercise (1-5): ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 5) {
        printf("Invalid choice\n");
        return 0;
    }

    switch (choice) {
        case 1:
            printf("Enter a number: ");
            scanf("%d", &n);
            draw_tree(n);
            break;
        case 2:
            printf("Enter a number: ");
            scanf("%d", &n);
            print_largest_factorial_below(n);
            break;
        case 3:
            printf("Enter a number: ");
            scanf("%d", &n);
            check_armstrong(n);
            break;
        case 4:
            printf("Enter a number: ");
            scanf("%d", &n);
            print_binary(n);
            break;
        case 5:
            printf("Enter two numbers n and p: ");
            scanf("%d", &n);
            scanf("%d", &p);
            printf("Binomial coefficient: %d\n", binomial_coefficient(n, p));
            break;
    }

    return 0;
}
