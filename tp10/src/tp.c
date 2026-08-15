/**
 * @file tp.c
 * @brief Solves quadratic and cubic equations, including their complex roots.
 * @author Lilian Naretto
 */

#include "tp.h"

void solve_quadratic(double a, double b, double c) {
    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("root1 = %lf and root2 = %lf\n", root1, root2);
    } else if (discriminant == 0) {
        double root = -b / (2 * a);
        printf("root1 = root2 = %lf\n", root);
    } else {
        complex_t root = {-b / (2 * a), sqrt(-discriminant) / (2 * a)};
        printf("root1 = %lf+%lfi and root2 = %lf-%lfi\n", root.re, root.im, root.re, root.im);
    }
}

void prompt_quadratic(void) {
    double a, b, c;
    printf("a: ");
    scanf("%lf", &a);
    printf("b: ");
    scanf("%lf", &b);
    printf("c: ");
    scanf("%lf", &c);
    solve_quadratic(a, b, c);
}

/** Cube root that preserves the sign of `x` (pow() alone can't handle negative bases). */
static double signed_cbrt(double x) {
    return (x < 0) ? -pow(-x, 1.0 / 3.0) : pow(x, 1.0 / 3.0);
}

void solve_cubic(double a, double b, double c, double d) {
    if (a == 0 || d == 0) {
        printf("Error\n");
        return;
    }

    /* normalize to x^3 + bx^2 + cx + d = 0, then apply Cardano's method */
    b /= a;
    c /= a;
    d /= a;

    double q = (3.0 * c - (b * b)) / 9.0;
    double r = -(27.0 * d) + b * (9.0 * c - 2.0 * (b * b));
    r /= 54.0;
    double discriminant = q * q * q + r * r;
    double term1 = b / 3.0;

    if (discriminant > 0) {
        double s = signed_cbrt(r + sqrt(discriminant));
        double t = signed_cbrt(r - sqrt(discriminant));

        double real_root = -term1 + s + t;
        double repeated_real = -(term1 + (s + t) / 2.0);
        double imaginary = sqrt(3.0) * (s - t) / 2.0;

        printf("( %lf , %lf+%lfi , %lf-%lfi )\n", real_root, repeated_real, imaginary, repeated_real, imaginary);
        return;
    }

    if (discriminant == 0) {
        double r13 = signed_cbrt(r);
        double root1 = -term1 + 2.0 * r13;
        double double_root = -(r13 + term1);
        printf("( %lf , %lf , %lf )\n", root1, double_root, double_root);
        return;
    }

    q = -q;
    double angle = acos(r / sqrt(q * q * q));
    double r13 = 2.0 * sqrt(q);
    double root1 = -term1 + r13 * cos(angle / 3.0);
    double root2 = -term1 + r13 * cos((angle + 2.0 * PI) / 3.0);
    double root3 = -term1 + r13 * cos((angle + 4.0 * PI) / 3.0);
    printf("( %lf , %lf , %lf )\n", root1, root2, root3);
}

void prompt_cubic(void) {
    double a, b, c, d;
    printf("a: ");
    scanf("%lf", &a);
    printf("b: ");
    scanf("%lf", &b);
    printf("c: ");
    scanf("%lf", &c);
    printf("d: ");
    scanf("%lf", &d);
    solve_cubic(a, b, c, d);
}

int main(void) {
    printf("QUADRATIC\n");
    prompt_quadratic();
    printf("CUBIC\n");
    prompt_cubic();
    return 0;
}
