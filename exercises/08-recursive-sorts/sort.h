#pragma once

#include <stddef.h>

/* Exchange the two ints at a and b. */
void swap_ints(int* a, int* b);

/* Return 1 if the n ints at a are in ascending order, else 0. */
int is_sorted(const int* a, size_t n);

/* Sort a[lo..hi] into ascending order. Closed range: hi is the last index,
   so a whole array of n items is (a, 0, n - 1); n must be at least 1.
   Stable. Each merge copies its two runs to heap buffers it frees. */
void merge_sort(int* a, size_t lo, size_t hi);

/* Sort a[lo..hi] into ascending order, in place. Same range rule. */
void quick_sort(int* a, size_t lo, size_t hi);