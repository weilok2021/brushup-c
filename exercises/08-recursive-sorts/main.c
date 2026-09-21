#include <stdio.h>
#include "sort.h"
#include <stdlib.h>
#include <string.h>

static int *copy_array(const int *src, size_t n);

int main(void) {
    const int a[] = {9,4,15,9,26,5,35,4};
    int* arr = copy_array(a, 8);
    int* arr2 = copy_array(a, 8);

    if (arr == NULL) {
        return 1;
    }

    if (arr2 == NULL) {
        free(arr);
        return 1;
    }

    printf("before: ");
    for (int i = 0; i < 8; i++) {
        printf("%d ", arr[i]);
    }
    puts("");
    merge_sort(arr, 0, 7);
    printf("after merge: ");
    for (int i = 0; i < 8; i++) {
        printf("%d ", arr[i]);
    }
    puts("");

    if (is_sorted(arr, 8)) {
        printf("sorted: yes\n");
    }

    printf("before: ");
    for (int i = 0; i < 8; i++) {
        printf("%d ", arr2[i]);
    }
    puts("");
    quick_sort(arr2, 0, 7);
    printf("after quick: ");
    for (int i = 0; i < 8; i++) {
        printf("%d ", arr2[i]);
    }
    puts("");

    if (is_sorted(arr2, 8)) {
        printf("sorted: yes\n");
    }
    free(arr);
    free(arr2);
}

static int *copy_array(const int *src, size_t n) {
    int *copy = malloc(n * sizeof *copy);

    if (copy == NULL) {
        return NULL;
    }

    memcpy(copy, src, n * sizeof *copy);
    return copy;
}