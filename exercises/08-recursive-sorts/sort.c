#include "sort.h"
#include <stdlib.h>

static void merge(int* a, size_t lo, size_t mid, size_t hi);
static size_t partition(int* a, size_t lo, size_t hi);

/* Exchange the two ints at a and b. */
void swap_ints(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Return 1 if the n ints at a are in ascending order, else 0. */
int is_sorted(const int* a, size_t n) {
    for (size_t i = 1; i < n; i++) {
        if (a[i-1] > a[i]) {
            return 0;
        }
    }
    return 1;
}

void merge_sort(int* a, size_t lo, size_t hi) {
    size_t N = hi - lo + 1;
    if (N < 2) {
        return;
    }
    size_t mid = (lo + hi) / 2;
    merge_sort(a, lo, mid);
    merge_sort(a, mid+1, hi);
    merge(a, lo, mid, hi);
}

void quick_sort(int* a, size_t lo, size_t hi) {
    if (lo >= hi) {
        return;
    }

    size_t pivot = partition(a, lo, hi);
    if (pivot > lo) {
        quick_sort(a, lo, pivot - 1);
    }
    quick_sort(a, pivot+1, hi);
}

static void merge(int* a, size_t lo, size_t mid, size_t hi) {    
    size_t i = 0;
    size_t j = 0;
    size_t k = lo;

    // left array has [lo..mid]
    size_t left_size = mid - lo + 1;
    int* left_arr = malloc(left_size * sizeof *left_arr);
    for (size_t x = 0, y = lo; x < left_size; x++, y++) {
        left_arr[x] = a[y];
    }

    // right array has [mid+1..hi]
    size_t right_size = hi - (mid + 1) + 1; 
    int* right_arr = malloc(right_size * sizeof *right_arr);
    for (size_t x = 0, y = mid+1; x < right_size; x++, y++) {
        right_arr[x] = a[y];
    }

    while (i < left_size && j < right_size) {
        if (left_arr[i] <= right_arr[j]) {
            a[k] = left_arr[i];
            i++;
        } else {
            a[k] = right_arr[j];
            j++;
        }
        k++;
    }

    while (i < left_size) { 
        a[k++] = left_arr[i++]; 
    }
    while (j < right_size) { 
        a[k++] = right_arr[j++]; 
    }
    free(left_arr);
    free(right_arr);
}

static size_t partition(int* a, size_t lo, size_t hi) {
    int pivot = a[lo];              /* leftmost item is the pivot */
    size_t L = lo + 1;              /* L starts just right of the pivot */
    size_t G = hi;                  /* G starts at the right end */
    while (1) {
        while (L <= hi && a[L] < pivot) {
            L++;                    /* L walks past small items; the guard stops it at hi + 1 */
        }
        while (G >= lo && a[G] > pivot) {
            G--;                    /* G walks past large items; the pivot itself stops it */
        }
        if (L > G) {
            break;                  /* crossed: done walking (on a meet, one extra round) */
        }
        swap_ints(&a[L], &a[G]);   /* both stopped: swap ... */
        L++;
        G--;                        /* ... and move both by one */
    }
    swap_ints(&a[G], &a[lo]);       /* swap the pivot with G */
    return G;
}