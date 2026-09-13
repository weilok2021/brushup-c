#pragma once

#include <stddef.h>

/* Exchange the two ints at a and b. */
void swap_ints(int* a, int* b);

/* Sort the n ints at a into ascending order, in place. */
void insertion_sort(int* a, size_t n);

/* Return 1 if the n ints at a are in ascending order, else 0. */
int is_sorted(const int* a, size_t n);

/* Binary search the n sorted ints at a for target.
   Returns a borrowed pointer to a matching element, or NULL if absent. */
const int* search_sorted(const int* a, size_t n, int target);
