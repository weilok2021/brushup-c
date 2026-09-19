#include "recur.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int *copy_array(const int *src, size_t n);

int main(void) {
    const int a1[] = {9, 4, 15, 9, 26, 5, 35, 4};
    const int a2[] = {4, 4, 5, 9, 9, 15, 26, 35};

    size_t n = sizeof a1 / sizeof a1[0];

    int *copy1 = copy_array(a1, n);
    int *copy2 = copy_array(a2, n);

    if (copy1 == NULL || copy2 == NULL) {
        free(copy1);
        free(copy2);
        return 1;
    }
    printf("sum: %ld\n", sum_range(copy1, 0, 8));
    printf("backwards:");
    print_backwards(copy1, 0, 8);
    printf("\n");
    printf("max: %d\n", max_range(copy1, 0, 8));
    printf("max of [0, 4): %d\n", max_range(copy1, 0, 4));

    const int* num = search_range(copy2, 0, 7, 26);
    if (num != NULL) {
        printf("found %d at index %td\n", *num, num - copy2);
    } else {
        printf("found 26: no\n");
    }

    const int* num2 = search_range(copy2, 0, 7, 7);
    if (num2 != NULL) {
        printf("found %d at index %td\n", *num2, num2 - copy2);
    } else {
        printf("found 7: no\n");
    }

    free(copy1);
    free(copy2);
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