# TP11 — PPM/PGM/PBM Image Processing

A command-line tool that reads plain netpbm images (PPM color or PGM
grayscale) and can produce a grayscale (PGM) and/or black & white (PBM)
version via thresholding, using a hand-written parser for the netpbm text
format (including `#` comments).

## Build & run

```sh
make
./bin/tp11 -in photo.ppm -out photo -grayscale -threshold 128
make clean
```

| Flag | Description |
| --- | --- |
| `-in <file>` | Input image, `.ppm` (P3) or `.pgm` (P2). Required. |
| `-out <name>` | Output base name; `.pgm`/`.pbm` is appended automatically. Required. |
| `-grayscale` | Also write a grayscale `.pgm` version (implied by `-threshold` for PPM input). |
| `-threshold <n>` | Write a black & white `.pbm` version, splitting pixels at value `n`. |

Grayscale conversion uses the luminosity weights `0.299 R + 0.587 G + 0.144 B`.
