/**
 * @file main.c
 * @brief A command-line tool that converts plain PPM/PGM (netpbm) images to
 *        grayscale (PGM) and/or black & white (PBM) via thresholding.
 * @author Lilian Naretto
 */

#include "main.h"

/** Skips whitespace and '#' comments, positioning the stream at the next token. */
static void skip_whitespace_and_comments(FILE *file) {
    int c;
    while ((c = fgetc(file)) != EOF) {
        if (c == '#') {
            while ((c = fgetc(file)) != EOF && c != '\n') {
                /* discard the rest of the comment line */
            }
        } else if (!isspace(c)) {
            ungetc(c, file);
            return;
        }
    }
}

/** Reads the next whitespace/comment-delimited integer from a netpbm header. */
static int read_int(FILE *file) {
    skip_whitespace_and_comments(file);
    int value = 0;
    fscanf(file, "%d", &value);
    return value;
}

/** Reads the 2-character netpbm magic number (e.g. "P3") from the file. */
static void read_magic(FILE *file, char magic[3]) {
    magic[0] = (char)fgetc(file);
    magic[1] = (char)fgetc(file);
    magic[2] = '\0';
}

PpmImage *load_ppm(const char *path) {
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        printf("Image not found\n");
        return NULL;
    }

    char magic[3];
    read_magic(file, magic);
    if (strcmp(magic, "P3") != 0) {
        fclose(file);
        printf("Invalid format\n");
        return NULL;
    }

    PpmImage *image = malloc(sizeof(PpmImage));
    image->width = read_int(file);
    image->height = read_int(file);
    image->range = read_int(file);
    image->pixels = malloc((size_t)image->width * (size_t)image->height * sizeof(Pixel));

    for (int i = 0; i < image->width * image->height; i++) {
        for (int channel = 0; channel < 3; channel++) {
            image->pixels[i].channels[channel] = read_int(file);
        }
    }

    fclose(file);
    return image;
}

PgmImage *load_pgm(const char *path) {
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        printf("Image not found\n");
        return NULL;
    }

    char magic[3];
    read_magic(file, magic);
    if (strcmp(magic, "P2") != 0) {
        fclose(file);
        printf("Invalid format\n");
        return NULL;
    }

    PgmImage *image = malloc(sizeof(PgmImage));
    image->width = read_int(file);
    image->height = read_int(file);
    image->range = read_int(file);
    image->pixels = malloc((size_t)image->width * (size_t)image->height * sizeof(Pixel));

    for (int i = 0; i < image->width * image->height; i++) {
        image->pixels[i].channels[0] = read_int(file);
    }

    fclose(file);
    return image;
}

void free_ppm(PpmImage *image) {
    free(image->pixels);
    free(image);
}

void free_pgm(PgmImage *image) {
    free(image->pixels);
    free(image);
}

void free_pbm(PbmImage *image) {
    free(image->pixels);
    free(image);
}

/** Number of decimal digits needed to print `value` (at least 1). */
static int digit_count(int value) {
    int count = 0;
    do {
        value /= 10;
        count++;
    } while (value != 0);
    return count;
}

void save_ppm(const char *path, const PpmImage *image) {
    FILE *file = fopen(path, "w");
    if (file == NULL) {
        printf("Cannot open file\n");
        return;
    }

    fprintf(file, "P3\n%d %d\n%d\n", image->width, image->height, image->range);
    int width = digit_count(image->range);

    for (int i = 0; i < image->width * image->height; i++) {
        for (int channel = 0; channel < 3; channel++) {
            fprintf(file, "%*d ", width, image->pixels[i].channels[channel]);
        }
        fprintf(file, (i % image->width == image->width - 1) ? "\n" : "   ");
    }

    fclose(file);
}

void save_pgm(const char *path, const PgmImage *image) {
    FILE *file = fopen(path, "w");
    if (file == NULL) {
        printf("Cannot open file\n");
        return;
    }

    fprintf(file, "P2\n%d %d\n%d\n", image->width, image->height, image->range);
    int width = digit_count(image->range);

    for (int i = 0; i < image->width * image->height; i++) {
        fprintf(file, "%*d ", width, image->pixels[i].channels[0]);
        if (i % image->width == image->width - 1) {
            fprintf(file, "\n");
        }
    }

    fclose(file);
}

void save_pbm(const char *path, const PbmImage *image) {
    FILE *file = fopen(path, "w");
    if (file == NULL) {
        printf("Cannot open file\n");
        return;
    }

    fprintf(file, "P1\n%d %d\n", image->width, image->height);

    for (int i = 0; i < image->width * image->height; i++) {
        fprintf(file, "%d ", image->pixels[i].channels[0]);
        if (i % image->width == image->width - 1) {
            fprintf(file, "\n");
        }
    }

    fclose(file);
}

PgmImage *to_grayscale(const PpmImage *image) {
    PgmImage *result = malloc(sizeof(PgmImage));
    result->width = image->width;
    result->height = image->height;
    result->range = image->range;
    result->pixels = malloc((size_t)result->width * (size_t)result->height * sizeof(Pixel));

    for (int i = 0; i < result->width * result->height; i++) {
        double luminosity = image->pixels[i].channels[0] * 0.299 +
                             image->pixels[i].channels[1] * 0.587 +
                             image->pixels[i].channels[2] * 0.144;
        int value = (int)round(luminosity);
        result->pixels[i].channels[0] = (value < result->range) ? value : result->range;
    }

    return result;
}

PbmImage *threshold(const PgmImage *image, int value) {
    PbmImage *result = malloc(sizeof(PbmImage));
    result->width = image->width;
    result->height = image->height;
    result->pixels = malloc((size_t)result->width * (size_t)result->height * sizeof(Pixel));

    for (int i = 0; i < result->width * result->height; i++) {
        result->pixels[i].channels[0] = (image->pixels[i].channels[0] > value) ? 0 : 1;
    }

    return result;
}

char *get_extension(const char *file_name) {
    const char *dot = strrchr(file_name, '.');
    if (dot == NULL || dot == file_name) {
        return NULL;
    }
    size_t length = strlen(dot + 1);
    char *extension = malloc(length + 1);
    memcpy(extension, dot + 1, length + 1);
    return extension;
}

static char *concat_strings(const char *a, const char *b) {
    size_t len_a = strlen(a);
    size_t len_b = strlen(b);
    char *result = malloc(len_a + len_b + 1);
    memcpy(result, a, len_a);
    memcpy(result + len_a, b, len_b + 1);
    return result;
}

/** Loads a PPM, optionally saving a grayscale (.pgm) and thresholded (.pbm) version. */
static void process_ppm(const char *input, const char *output, boolean grayscale, int threshold_value) {
    PpmImage *image = load_ppm(input);
    if (image == NULL) {
        return;
    }

    if (grayscale || threshold_value != -1) {
        PgmImage *gray = to_grayscale(image);
        char *gray_path = concat_strings(output, ".pgm");
        save_pgm(gray_path, gray);
        free(gray_path);

        if (threshold_value >= 0) {
            PbmImage *bw = threshold(gray, threshold_value);
            char *bw_path = concat_strings(output, ".pbm");
            save_pbm(bw_path, bw);
            free(bw_path);
            free_pbm(bw);
        }

        free_pgm(gray);
    }

    free_ppm(image);
}

/** Loads a PGM, optionally saving a thresholded (.pbm) version. */
static void process_pgm(const char *input, const char *output, int threshold_value) {
    PgmImage *image = load_pgm(input);
    if (image == NULL) {
        return;
    }

    if (threshold_value >= 0) {
        PbmImage *bw = threshold(image, threshold_value);
        char *bw_path = concat_strings(output, ".pbm");
        save_pbm(bw_path, bw);
        free(bw_path);
        free_pbm(bw);
    }

    free_pgm(image);
}

int main(int argc, char **argv) {
    boolean grayscale = 0;
    char *input = NULL;
    char *output = NULL;
    int threshold_value = -1;
    int expecting = -1; /* 0 = -in, 1 = -out, 2 = -threshold */

    for (int i = 1; i < argc; i++) {
        if (expecting != -1) {
            if (expecting == 0) {
                input = argv[i];
            } else if (expecting == 1) {
                output = argv[i];
            } else if (expecting == 2) {
                threshold_value = (int)strtol(argv[i], NULL, 10);
            }
            expecting = -1;
        } else if (strcmp(argv[i], "-in") == 0) {
            expecting = 0;
        } else if (strcmp(argv[i], "-out") == 0) {
            expecting = 1;
        } else if (strcmp(argv[i], "-grayscale") == 0) {
            grayscale = 1;
        } else if (strcmp(argv[i], "-threshold") == 0) {
            expecting = 2;
        }
    }

    if (input == NULL || output == NULL) {
        if (input == NULL) {
            printf("missing -in <file>\n");
        }
        if (output == NULL) {
            printf("missing -out <file>\n");
        }
        return 1;
    }

    char *extension = get_extension(input);
    if (extension == NULL) {
        printf("invalid -in file name\n");
        return 1;
    }

    if (strcmp(extension, "ppm") == 0) {
        process_ppm(input, output, grayscale, threshold_value);
    } else if (strcmp(extension, "pgm") == 0) {
        process_pgm(input, output, threshold_value);
    } else {
        printf("unsupported input file extension: %s\n", extension);
    }

    free(extension);
    return 0;
}
