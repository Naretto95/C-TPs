/**
 * @file question3.c
 * @brief Demonstrates that C passes arguments by value: swap() only swaps its
 *        own local copies, so the caller's variables are left unchanged.
 * @author Lilian Naretto
 */

#include <stdio.h>

void swap(int a, int b) {
    int tmp;
    printf("before swap: a=%d b=%d\n", a, b);
    tmp = a;
    a = b;
    b = tmp;
    printf("after swap: a=%d b=%d\n", a, b);
}

int main(void) {
    int a = 5;
    int b = 7;

    printf("before calling swap: a=%d b=%d\n", a, b);
    swap(a, b);
    printf("after calling swap: a=%d b=%d (unchanged, passed by value)\n", a, b);
    return 0;
}
