#include "vec.h"

int vec_sum(const int *a, size_t n) {
    int total = 0;
    for (size_t i = 0; i < n; i++) {
        total += a[i];
    }
    return total;
}