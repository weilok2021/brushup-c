/* Throwaway test for is_partitioned, closed range [low, high]. Not part of
   the lesson; delete when done.

   Contract under test (closed form, from lesson 7's "Closed range" table):
     is_partitioned(a, low, high, p) returns 1 when
       a[low..p-1] <= a[p] <= a[p+1..high],  else 0.
   high is the last index in the range, so the count is high - low + 1.

   Build and run from exercises/07-partition/:
     gcc -std=gnu11 -Wall -Wextra -g -fsanitize=address,undefined \
         -o test_partitioned test_partitioned.c partition.c && ./test_partitioned

   One line per case, PASS or FAIL, exit status 1 if any case fails.
   Each array is copied to a heap block of exactly n ints, so a read past
   high (when high == n - 1) is a heap-buffer-overflow that ASan reports. */
#include "partition.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 8

struct test_case {
    const char* name;
    int a[MAX_N];
    size_t n;
    size_t low, high, p;    /* closed range: high is the last index */
    int expected;           /* 1 = yes, 0 = no */
};

static const struct test_case cases[] = {
    /* valid partitions */
    {"lesson line 1, sides unsorted",      {5, 4, 4, 9, 26, 9, 35, 15}, 8, 0, 7, 3, 1},
    {"sorted array, any p",                {1, 2, 3, 4, 5},             5, 0, 4, 2, 1},
    {"equal keys on both sides",           {9, 4, 9, 15, 9},            5, 0, 4, 2, 1},
    {"six 7s, pivot at the end",           {7, 7, 7, 7, 7, 7},          6, 0, 5, 5, 1},
    /* each loop must say no */
    {"large item at low",                  {10, 4, 4, 9, 15, 26, 35, 15}, 8, 0, 7, 3, 0},
    {"small item on the right (wrong p)",  {5, 4, 4, 9, 26, 9, 35, 15}, 8, 0, 7, 4, 0},
    {"reversed, both sides wrong",         {5, 4, 3, 2, 1},             5, 0, 4, 2, 0},
    /* boundary indices */
    {"violator at p-1 only",               {2, 1, 10, 9},               4, 0, 3, 3, 0},
    {"violator at p+1 only",               {4, 4, 5, 9, 8, 15, 26, 35}, 8, 0, 7, 3, 0},
    {"violator at high only",              {4, 4, 5, 9, 15, 26, 35, 8}, 8, 0, 7, 3, 0},
    /* a side of zero length */
    {"pivot at low, left loop runs 0 times",   {3, 5, 4, 9},            4, 0, 3, 0, 1},
    {"pivot at high, right loop runs 0 times", {2, 1, 3, 9},            4, 0, 3, 3, 1},
    {"one element, low == high == p",      {42},                        1, 0, 0, 0, 1},
    /* sub-range: items outside [low, high] must be ignored */
    {"sub-range, distractors outside",     {99, 4, 9, 26, 0},           5, 1, 3, 2, 1},
    {"sub-range, violator at low",         {0, 10, 4, 9, 15, 26},       6, 1, 5, 3, 0},
};

int main(void) {
    size_t count = sizeof cases / sizeof cases[0];
    int failures = 0;
    for (size_t t = 0; t < count; t++) {
        const struct test_case* c = &cases[t];
        int* heap = malloc(c->n * sizeof *heap);
        if (heap == NULL) {
            return 2;
        }
        memcpy(heap, c->a, c->n * sizeof *heap);
        int got = is_partitioned(heap, c->low, c->high, c->p);
        free(heap);
        int ok = (got != 0) == (c->expected != 0);
        printf("%s  %-40s [%zu, %zu] p=%zu  expected %-3s got %s\n",
               ok ? "PASS" : "FAIL", c->name, c->low, c->high, c->p,
               c->expected ? "yes" : "no", got ? "yes" : "no");
        if (!ok) {
            failures++;
        }
    }
    printf("%zu cases, %d failed\n", count, failures);
    return failures ? 1 : 0;
}
