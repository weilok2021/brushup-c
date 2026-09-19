#pragma once

#include <stddef.h>

/* Sum of the ints in a[low..high). Shrinks the range by one element per call. */
long sum_range(const int* a, size_t low, size_t high);

/* Print the ints in a[low..high) last to first, space-separated, no newline. */
void print_backwards(const int* a, size_t low, size_t high);

/* Largest int in a[low..high). The range must hold at least one element.
   Halves the range per call. */
int max_range(const int* a, size_t low, size_t high);

/* Binary search for target in the sorted, inclusive range a[low..high].
   The range must hold at least one element (high is a real index).
   Returns a borrowed pointer to a matching element, or NULL if absent. */
const int* search_range(const int* a, size_t low, size_t high, int target);
