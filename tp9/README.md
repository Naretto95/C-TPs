# TP9 — Conway's Game of Life

A terminal implementation of Conway's Game of Life on a 5x5 grid that wraps
around at the edges (a torus): each cell is either alive or dead, and evolves
generation after generation following the standard rules — a live cell
survives with 2 or 3 live neighbors, and a dead cell is born with exactly 3.

## Build & run

```sh
make
./bin/tp9
make clean
```

You'll be prompted to set each cell to alive (`1`) or dead (`0`), then asked
how many generations to simulate.

See [Rapport.pdf](Rapport.pdf) for the original lab report.
