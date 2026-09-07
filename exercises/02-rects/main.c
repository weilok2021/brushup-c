#include <stdio.h>
#include "rect.h"
#include <stdlib.h>

#define N 5          /* number of rects */

int main(void) {
    rect_t* rectangles = malloc(sizeof *rectangles * N);
    for (int i = 0; i < N; i++) {
        rectangles[i] = (rect_t){.x = i, .y = 0, .w = i + 1, .h = N - i};
        rect_move(&rectangles[i], 10, 10);
    }
    const rect_t* largest_ptr = rect_largest(rectangles, N);
    ptrdiff_t index_largest = largest_ptr - rectangles;
    printf("largest: %d x %d at (%d, %d), index %td\n", largest_ptr->w, largest_ptr->h, largest_ptr->x, largest_ptr->y, index_largest);
    free(rectangles);
    return 0;
}
