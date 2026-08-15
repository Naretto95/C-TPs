# C-TPs

A collection of C practical assignments ("TPs") from an introductory
programming course, reworked into small, self-contained, buildable projects.
Each `tpN/` folder is a standalone program (or set of programs) with its own
Makefile.

## Contents

| Folder | Topic |
| --- | --- |
| [tp2](tp2) | Introduction to C: I/O, variables, conditionals, loops, arrays |
| [tp3](tp3) | Functions, parameter passing, variable scope |
| [tp4](tp4) | Numerical methods approximating pi and sqrt(2) |
| [tp6](tp6) | Connect Four game (2 players, terminal) |
| [tp7](tp7) | Sorting algorithms: insertion, merge, counting sort |
| [tp8](tp8) | Classic ciphers: Caesar, Vigenere, Scytale |
| [tp9](tp9) | Conway's Game of Life |
| [tp10](tp10) | Quadratic & cubic equation solver (Cardano's method) |
| [tp11](tp11) | PPM/PGM/PBM image processing (grayscale, thresholding) |

Each folder's own README describes what the program does and how to run it.

## Build

Every TP has its own Makefile with the same interface:

```sh
cd tp6
make          # builds into bin/
./bin/tp6
make clean
```

Programs requiring `libm` link against it automatically; no external
dependencies beyond a C11 compiler (`gcc`/`clang`) and `make` are needed.

## Notes

This code was originally written in 2019 as coursework; it has since been
cleaned up (consistent style, English naming/comments, a handful of bug
fixes) while keeping each exercise's original idea and behavior intact. Some
folders include the original lab report (`rapport.pdf`) for context.

## License

This repository is licensed under the MIT License. See [LICENSE](LICENSE) for
details.
