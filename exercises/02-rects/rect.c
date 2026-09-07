#include "rect.h"

int rect_area(const rect_t *r) {
    return r->w * r->h;
}

void rect_move(rect_t *r, int dx, int dy) {
    r->x += dx;
    r->y += dy;
}

// rect_largest sets end, walks p from rs to end
const rect_t *rect_largest(const rect_t *rs, size_t n) {
    const rect_t* end = rs + n;
    const rect_t* largest = rs;

    for(const rect_t* p = rs + 1; p < end; p++) {
        if (rect_area(p) > rect_area(largest)) {
            largest = p;
        }
    }
    return largest;
}