#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Required for memcpy

#define N 8

int main(void) {
    int* nums = calloc(N, sizeof *nums);
    if (nums == NULL) {
        return 1;
    }
    static const int source[N] = {31,4,15,9,26,5,35,8};

    // Copy the entire block of memory
    // (destination, source, total bytes to copy)
    memcpy(nums, source, N * sizeof *nums);
    printf("before:");
    for (int i = 0; i < N; i++) {
        printf(" %d", nums[i]);
    }
    puts("");

    printf("after:");
    insertion_sort(nums, N);
    for (int i = 0; i < N; i++) {
        printf(" %d", nums[i]);
    }
    puts("");

    printf("sorted: ");
    if (!is_sorted(nums, N)) {
        printf("no\n");
    } else {
        printf("yes\n");
    }

    const int *result;

    result = search_sorted(nums, N, 26);
    if (result != NULL) {
        printf("find 26: index %td\n", result - nums);
    } else {
        printf("find 26: absent\n");
    }

    result = search_sorted(nums, N, 4);
    if (result != NULL) {
        printf("find 4: index %td\n", result - nums);
    } else {
        printf("find 4: absent\n");
    }

    result = search_sorted(nums, N, 2);
    if (result != NULL) {
        printf("find 2: index %td\n", result - nums);
    } else {
        printf("find 2: absent\n");
    }

    free(nums);
    return 0;
}
