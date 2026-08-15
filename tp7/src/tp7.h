#ifndef TP7_H
#define TP7_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 6

/** Sorts `array` in place using insertion sort. */
void insertion_sort(int array[ARRAY_SIZE]);

/** Allocates and returns a copy of src[start..end] (inclusive). */
int *copy_subarray(const int *src, int start, int end);

/** Merges two sorted arrays (a, b) into a single sorted array `result`. */
void merge(const int *a, int size_a, const int *b, int size_b, int *result);

/** Sorts `array` (of length `size`) in place using merge sort. */
void merge_sort(int *array, int size);

/** Finds the min and max values of `array` (of length `size`). */
void find_min_max(const int *array, int size, int *min, int *max);

/** Sorts `array` (of length `size`) in place using counting sort. */
void counting_sort(int *array, int size);

#endif
