# TP3 — Functions & Scope

Exercises on functions, parameter passing, variable scope and a second lab
session covering recursion-adjacent algorithms (factorial, Armstrong numbers,
binary representation, binomial coefficient).

| File | Description |
| --- | --- |
| [question1.c](src/question1.c) | Reads an integer via a function; exits if it is zero. |
| [question2.c](src/question2.c) | Demonstrates that same-named local variables in different functions are independent. |
| [question3.c](src/question3.c) | Demonstrates pass-by-value: a `swap()` function cannot affect the caller's variables. |
| [question4.c](src/question4.c) | Menu: multiplication table, cubic root via bisection, factorial. |
| [session2.c](src/session2.c) | Menu: ASCII tree drawing, largest factorial below a bound, Armstrong number check, binary representation, binomial coefficient. |

## Build & run

```sh
make               # builds every exercise into bin/
./bin/question1
make clean
```

`photos/` contains terminal screenshots from the original lab session, and
[rapport.pdf](rapport.pdf) is the original lab report.
