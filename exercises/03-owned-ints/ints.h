#pragma once

#include <stddef.h>

/* Allocate n zeroed ints. n must be at least 1.
   Returns an owned heap block, or NULL on failure. */
int* ints_new(size_t n);

/* Resize values to hold n ints. n must be at least 1.
   On success, returns the owning pointer and the input pointer must not be used.
   On failure, returns NULL and the caller still owns values. */
int* ints_resize(int* values, size_t n);

/* Return the sum of the n ints at values. Borrows values; does not free it. */
int ints_sum(const int* values, size_t n);