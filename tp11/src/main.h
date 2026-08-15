#ifndef MAIN_H
#define MAIN_H

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int boolean;

/** A single pixel; PBM/PGM images only use channels[0]. */
typedef struct {
    int channels[3];
} Pixel;

typedef struct {
    Pixel *pixels;
    int width;
    int height;
    int range;
} PpmImage;

typedef struct {
    Pixel *pixels;
    int width;
    int height;
    int range;
} PgmImage;

typedef struct {
    Pixel *pixels;
    int width;
    int height;
} PbmImage;

/** Loads a plain PPM (P3) color image from `path`, or NULL on failure. */
PpmImage *load_ppm(const char *path);

/** Loads a plain PGM (P2) grayscale image from `path`, or NULL on failure. */
PgmImage *load_pgm(const char *path);

void free_ppm(PpmImage *image);
void free_pgm(PgmImage *image);
void free_pbm(PbmImage *image);

void save_ppm(const char *path, const PpmImage *image);
void save_pgm(const char *path, const PgmImage *image);
void save_pbm(const char *path, const PbmImage *image);

/** Converts a color image to grayscale using the luminosity weights. */
PgmImage *to_grayscale(const PpmImage *image);

/** Converts a grayscale image to black & white using a threshold. */
PbmImage *threshold(const PgmImage *image, int value);

/** Returns a newly allocated copy of the filename's extension, or NULL. */
char *get_extension(const char *file_name);

#endif
