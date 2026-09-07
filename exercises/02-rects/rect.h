#pragma once
#include <stddef.h>   /* size_t */

/* An axis-aligned rectangle: bottom-left corner and size, in whole units. */
typedef struct Rectangle {
    int x, y;
    int w, h;
} rect_t;

/* Area of r. */
int rect_area(const rect_t *r);

/* Move r by dx, dy, in place. */
void rect_move(rect_t *r, int dx, int dy);

/* The rectangle with the largest area among the n at rs. n must be at least 1.
   Returns a pointer into the caller's array, not a copy. */
const rect_t *rect_largest(const rect_t *rs, size_t n);