#include "sort.h"

void swap_ints(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertion_sort(int* a, size_t n) {
    for (size_t i = 1; i < n; i++) {
        for (size_t j = i; j > 0 && a[j] < a[j-1]; j--) {
            swap_ints(&a[j], &a[j-1]);
        }
    }
}

int is_sorted(const int* a, size_t n) {
    for(size_t i = 1; i < n; i++) {
        if (a[i] < a[i-1]) {
            return 0;
        }
    }
    return 1;
}

const int* search_sorted(const int* a, size_t n, int target) {
    // Prevent n - 1 from wrapping when n is 0.
    if (n == 0) {
        return NULL;
    }
    size_t low = 0;
    size_t high = n - 1;
    size_t mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (target == a[mid]) {
            return &a[mid];
        }
        if (target > a[mid]) {
            low = mid + 1;
        }
        if (target < a[mid]) {
            // Prevent mid - 1 from wrapping when mid is 0.
            if (mid == 0) {
                return NULL;
            }
            high = mid - 1;
        }
    }
    return NULL;
}
