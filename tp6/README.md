# TP6 — Connect Four

A two-player Connect Four style game played in the terminal on a 5x5 board:
players take turns dropping a disc into a column, and the first to line up
4 discs horizontally, vertically or diagonally wins.

## Build & run

```sh
make
./bin/tp6
make clean
```

Each turn, enter the column number (0-4) to drop your disc into. Player 1
plays `X`, player 2 plays `O`.

See [rapport.pdf](rapport.pdf) for the original lab report, and
[Doxyfile](Doxyfile) to regenerate the Doxygen documentation with `doxygen`.
