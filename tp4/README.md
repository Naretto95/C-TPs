# TP4 — Numerical Approximation Methods

Six classic numerical methods, picked from a menu at run time, approximating
either pi or sqrt(2):

| # | Function | Approximates |
| --- | --- | --- |
| 1 | `monte_carlo_pi` | pi, via random sampling of a unit square |
| 2 | `madhava_pi` | pi, via the Madhava-Leibniz series |
| 3 | `wallis_pi` | pi, via the Wallis product |
| 4 | `newton_sqrt2` | sqrt(2), via Newton's method |
| 5 | `halley_sqrt2` | sqrt(2), via Halley's method |
| 6 | `theon_sqrt2` | sqrt(2), via Theon of Smyrna's ladder |

## Build & run

```sh
make
./bin/tp4
make clean
```

The program asks for a method number (1-6) and an iteration count, then
prints the approximation. See [rapport.pdf](rapport.pdf) for the original
lab report.
