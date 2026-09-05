#include "vec.h"
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int* four_ints = malloc(sizeof(*four_ints) * 4);
    for (int i = 0; i < 4; i++) {
        four_ints[i] = i + 1;
    }
    printf("vector total: %d\n", vec_sum(four_ints, (size_t) 4));
    free(four_ints);
}
