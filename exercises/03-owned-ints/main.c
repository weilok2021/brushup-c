#include "ints.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int* four_ints = ints_new(4);
    if (four_ints == NULL) {
        free(four_ints);
        return 1;
    }
    printf("initial zeros: ");
    int num = 1;
    for (int* p = four_ints; p < four_ints + 4; p++) {
        printf("%d ", *p);
        *p += num;
        num++;
    }
    puts("");

    int* seven_ints = ints_resize(four_ints, 7);
    if (seven_ints == NULL) {
        free(four_ints);
        return 1;
    }

    seven_ints[4] = 5;
    seven_ints[5] = 6;
    seven_ints[6] = 7;

    printf("grown sum: %d\n", ints_sum(seven_ints, 7));
    free(seven_ints);
    return 0;
}