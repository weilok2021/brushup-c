#include "ints.h"
#include <stdlib.h>

int* ints_new(size_t n) {
    return calloc(n, sizeof(int));
}

int* ints_resize(int* values, size_t n) {
    int* new_ptr = realloc(values, n * sizeof *values);
    return new_ptr;
}

/* Return the sum of the n ints at values. Borrows values; does not free it. */
int ints_sum(const int* values, size_t n) {
    int total = 0;
    for(const int* p = values; p < values + n; p++) {
        total += *p;
    }
    return total;
}