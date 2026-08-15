# TP10 — Quadratic & Cubic Equation Solver

Solves `ax^2 + bx + c = 0` directly from the discriminant, and
`ax^3 + bx^2 + cx + d = 0` with Cardano's method (trigonometric form for the
three-real-roots case). Both real and complex roots are printed.

## Build & run

```sh
make
./bin/tp10
make clean
```

The program first asks for the coefficients of a quadratic equation, then for
a cubic one, and prints their roots.

See [rapport.pdf](rapport.pdf) for the original lab report.
