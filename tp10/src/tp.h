#ifndef TP10_H
#define TP10_H

#include <math.h>
#include <stdio.h>

#define PI 3.14159265359

/** A + Bi complex number, used for the non-real roots of the quadratic. */
typedef struct {
    double re;
    double im;
} complex_t;

/** Solves ax^2 + bx + c = 0 and prints its roots (real or complex). */
void solve_quadratic(double a, double b, double c);

/** Reads a, b, c from stdin and solves the resulting quadratic equation. */
void prompt_quadratic(void);

/** Solves ax^3 + bx^2 + cx + d = 0 and prints its three roots. */
void solve_cubic(double a, double b, double c, double d);

/** Reads a, b, c, d from stdin and solves the resulting cubic equation. */
void prompt_cubic(void);

#endif
