# TP7 — Sorting Algorithms

Three classic sorting algorithms, each demonstrated on a randomly generated array:

| # | Function | Algorithm | Complexity |
| --- | --- | --- | --- |
| 1 | `insertion_sort` | Insertion sort | O(n^2) |
| 2 | `merge_sort` | Merge sort (divide & conquer) | O(n log n) |
| 3 | `counting_sort` | Counting sort | O(n + range) |

## Build & run

```sh
make
./bin/tp7
make clean
```

The program generates two random arrays, then asks which algorithm to run
and prints the sorted result.

See [rapport.pdf](rapport.pdf) for the original lab report.
