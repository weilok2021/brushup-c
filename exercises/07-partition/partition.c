#include "partition.h"
#include <stdio.h>
#include <stdlib.h>

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

/* Rearrange a[lo..hi] around the pivot a[lo], in place (Hoare's scheme).
   Closed range: hi is the last index; the range holds at least one item.
   Returns the pivot's final index p, with a[lo..p-1] <= a[p] <= a[p+1..hi]. */
size_t partition(int* a, size_t lo, size_t hi) {
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

/* Same contract as partition, by a one-pointer scan (exploration). One
   pointer looks at each item; a large item is swapped to the right end.
   Every step fills one slot from one end, so after hi - lo steps the two
   regions meet at one slot, and the pivot goes there. */
size_t partition_one_scan(int* a, size_t lo, size_t hi) {
    int pivot = a[lo];
    size_t i = lo + 1;      /* next item to look at; a[lo+1..i-1] <= pivot */
    size_t j = hi;          /* next free slot at the right; a[j+1..hi] > pivot */
    while (i <= j) {
        if (a[i] <= pivot) {
            i++;                        /* small or equal: stays, i moves on */
        } else {
            swap_ints(&a[i], &a[j]);    /* large: send it to the right end ... */
            j--;                        /* ... and look at what came back */
        }
    }
    /* i == j + 1 here: a[lo+1..j] <= pivot and a[j+1..hi] > pivot.
       Slot j holds the last small-or-equal item; the pivot swaps into it. */
    swap_ints(&a[lo], &a[j]);
    return j;
}

/* Return 1 if a[lo..p-1] <= a[p] <= a[p+1..hi], else 0.
   Closed range: hi is the last index, so the count is hi - lo + 1.
   Requires lo <= p <= hi. */
int is_partitioned(const int* a, size_t lo, size_t hi, size_t p) {
    for (size_t i = lo; i < p; i++) {
        if (a[i] > a[p]) {
            return 0;
        }
    }
    for (size_t j = p+1; j <= hi; j++) {
        if (a[p] > a[j]) {
            return 0;
        }
    }
    return 1;
}

// compare each element in 
// first sorted subarray and right sorted subarray
// then merge them 
void merge(int* a, size_t lo, size_t mid, size_t hi) {    
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