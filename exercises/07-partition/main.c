#include "partition.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int *copy_array(const int *src, size_t n);

/* Partition a[lo..hi], then print the range, the pivot, where it landed,
   the whole array of n ints, and the checker's verdict. */
static void run_partition(int* a, size_t n, size_t lo, size_t hi) {
    int pivot = a[lo];
    size_t p = partition(a, lo, hi);
    if (p < lo || p > hi) {
        printf("[%zu, %zu] pivot %d: bad index %zu\n", lo, hi, pivot, p);
        return;
    }
    printf("[%zu, %zu] pivot %d lands at %zu:", lo, hi, pivot, p);
    for (size_t i = 0; i < n; i++) {
        printf(" %d", a[i]);
    }
    printf("\npartitioned: %s\n", is_partitioned(a, lo, hi, p) ? "yes" : "no");
}

int main(void) {
    /* data sorted: 4 4 5 9 9 15 26 35 */
    int data[]   = {9, 4, 15, 9, 26, 5, 35, 4};
    int small[]  = {9, 1, 2, 3};
    int large[]  = {1, 5, 4, 9};
    int sevens[] = {7, 7, 7, 7, 7, 7};
    int one[]    = {42};

    run_partition(data, 8, 0, 7);     /* the lesson's first call */
    run_partition(data, 8, 0, 3);     /* a sub-range at the left end */
    run_partition(data, 8, 5, 7);     /* a sub-range at the right end */
    run_partition(small, 4, 0, 3);    /* everything goes left */
    run_partition(large, 4, 0, 3);    /* everything goes right */
    run_partition(sevens, 6, 0, 5);   /* equal keys */
    run_partition(one, 1, 0, 0);      /* one element */
    
    const int a1[] = {9, 4, 15, 9, 26, 5, 35, 4};

    const int a2[] = {9, 1, 2, 3};

    const int a3[] = {7, 7, 7, 7, 7, 7};

    const int a4[] = {4, 9, 9, 15, 4, 5, 26, 35};

    int* copy1 = copy_array(a1, 8); 
    int* copy2 = copy_array(a2, 4);
    int* copy3 = copy_array(a3, 6);
    int* copy4 = copy_array(a4, 8);

    if (copy1 == NULL || copy2 == NULL || copy3 == NULL || copy4 == NULL) {
        free(copy1);
        free(copy2);
        free(copy3);
        free(copy4);
        return 1;
    }

    merge(copy4, 0, 3, 7);
    printf("merged: ");
    for (int i = 0; i < 8; i++) {
        printf("%d ", copy4[i]);
    }
    puts("");
    if (is_sorted(copy4, 8)) {
        printf("sorted: yes\n");
    }

    free(copy1);
    free(copy2);
    free(copy3);
    free(copy4);
    return 0;
}

static int *copy_array(const int *src, size_t n) {
    int *copy = malloc(n * sizeof *copy);

    if (copy == NULL) {
        return NULL;
    }

    memcpy(copy, src, n * sizeof *copy);
    return copy;
}