#include "recur.h"
#include <stdio.h>

/* Sum of the ints in a[low..high). Shrinks the range by one element per call. */
long sum_range(const int* a, size_t low, size_t high) {
    if (low == high) { 
        return 0; 
    }
    return a[low] + sum_range(a, low+1, high);
}

/* Print the ints in a[low..high) last to first, space-separated, no newline. */
void print_backwards(const int* a, size_t low, size_t high) {
    if (low == high) {
        return;
    }
    print_backwards(a, low+1, high);
    printf(" %d", a[low]);
}

/* Largest int in a[low..high). The range must hold at least one element.
   Halves the range per call. */
int max_range(const int* a, size_t low, size_t high) {
    // base case: one element left
    if (low == high - 1) { 
        return a[low];
    }
    size_t mid = (low + high) / 2;
    int left = max_range(a, low, mid);
    int right = max_range(a, mid, high);
    return left > right ? left : right;
}

/* Binary search for target in the sorted, inclusive range a[low..high].
   The range must hold at least one element (high is a real index).
   Returns a borrowed pointer to a matching element, or NULL if absent. */
const int* search_range(const int* a, size_t low, size_t high, int target) {
    // [1], target = 10
    // [1, 2], target = 1
    if (low > high) {
        return NULL;
    }
    size_t mid = (low + high) / 2;

    if (a[mid] == target) {
        return &a[mid];
    }
    if (target > a[mid]) {
        return search_range(a, mid+1, high, target);
    }

    // to prevent size_t underflow
    if (mid == 0) {
        return NULL;
    }
    return search_range(a, low, mid-1, target);
}
