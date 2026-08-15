/**
 * @file question2.c
 * @brief Demonstrates that a local variable is scoped to its own function:
 *        `n` in main() and `n` in dummy() are two independent variables that
 *        merely share a name, even though dummy() is called from main().
 * @author Lilian Naretto
 */

#include <stdio.h>

void dummy(void) {
    int n; /* unrelated to main's n, even though it has the same name */
    printf("%d\n", n); /* uninitialized on purpose: shows this is a distinct variable */
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("%d", n);
}

int main(void) {
    int n; /* uninitialized on purpose, see dummy() above */
    printf("%d\n", n);
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("%d", n);

    dummy();

    printf("%d\n", n); /* still main's own value: dummy() could not change it */
    return 0;
}
