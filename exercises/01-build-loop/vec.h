#pragma once

#include <stddef.h>   /* size_t */

/* Sum of the first n elements of a. a must point to at least n ints. */
int vec_sum(const int *a, size_t n);

