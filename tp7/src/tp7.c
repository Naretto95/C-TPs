/**
 * @file tp7.c
 * @brief Three sorting algorithms: insertion sort, merge sort and counting sort.
 * @author Lilian Naretto
 */

#include "tp7.h"

void insertion_sort(int array[ARRAY_SIZE]) {
    for (int i = 1; i < ARRAY_SIZE; i++) {
        int value = array[i];
        int j = i;
        while (j > 0 && array[j - 1] > value) {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = value;
    }
}

int *copy_subarray(const int *src, int start, int end) {
    int size = end - start + 1;
    int *dest = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        dest[i] = src[start + i];
    }
    return dest;
}

void merge(const int *a, int size_a, const int *b, int size_b, int *result) {
    int i = 0, j = 0, k = 0;
    while (k < size_a + size_b) {
        if (j >= size_b || (i < size_a && a[i] <= b[j])) {
            result[k++] = a[i++];
        } else {
            result[k++] = b[j++];
        }
    }
}

void merge_sort(int *array, int size) {
    if (size < 2) {
        return;
    }

    int left_size = size / 2;
    int right_size = size - left_size;
    int *left = copy_subarray(array, 0, left_size - 1);
    int *right = copy_subarray(array, left_size, size - 1);

    merge_sort(left, left_size);
    merge_sort(right, right_size);
    merge(left, left_size, right, right_size, array);

    free(left);
    free(right);
}

void find_min_max(const int *array, int size, int *min, int *max) {
    *min = array[0];
    *max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > *max) {
            *max = array[i];
        } else if (array[i] < *min) {
            *min = array[i];
        }
    }
}

void counting_sort(int *array, int size) {
    int min, max;
    find_min_max(array, size, &min, &max);

    int range = max - min + 1;
    int *counts = calloc(range, sizeof(int));
    for (int i = 0; i < size; i++) {
        counts[array[i] - min]++;
    }

    int pos = 0;
    for (int value = 0; value < range; value++) {
        for (int occurrence = 0; occurrence < counts[value]; occurrence++) {
            array[pos++] = value + min;
        }
    }

    free(counts);
}

static void print_array(const int *array, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d,", array[i]);
    }
    printf("]\n");
}

int main(void) {
    int insertion_data[ARRAY_SIZE], merge_data[ARRAY_SIZE];
    int choice;

    srand((unsigned int)time(NULL));

    printf("insertion sort input  = ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        insertion_data[i] = rand() % 20;
    }
    print_array(insertion_data, ARRAY_SIZE);

    printf("merge/counting sort input = ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        merge_data[i] = rand() % 20;
    }
    print_array(merge_data, ARRAY_SIZE);

    printf("insertion sort = 1\n");
    printf("merge sort     = 2\n");
    printf("counting sort  = 3\n");
    printf("Choose a sort: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            insertion_sort(insertion_data);
            printf("result = ");
            print_array(insertion_data, ARRAY_SIZE);
            break;
        case 2:
            merge_sort(merge_data, ARRAY_SIZE);
            printf("result = ");
            print_array(merge_data, ARRAY_SIZE);
            break;
        case 3:
            counting_sort(merge_data, ARRAY_SIZE);
            printf("result = ");
            print_array(merge_data, ARRAY_SIZE);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}
