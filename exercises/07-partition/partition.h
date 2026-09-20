#pragma once

#include <stddef.h>

/* Exchange the two ints at a and b. */
void swap_ints(int* a, int* b);

/* Return 1 if the n ints at a are in ascending order, else 0. */
int is_sorted(const int* a, size_t n);

/* Rearrange a[lo..hi] around the pivot a[lo], in place (Hoare's scheme).
   Closed range: hi is the last index; the range holds at least one item.
   Returns the pivot's final index p, with a[lo..p-1] <= a[p] <= a[p+1..hi]. */
size_t partition(int* a, size_t lo, size_t hi);

/* Return 1 if a[lo..p-1] <= a[p] <= a[p+1..hi], else 0.
   Closed range: hi is the last index, so the count is hi - lo + 1.
   Requires lo <= p <= hi. */
int is_partitioned(const int* a, size_t lo, size_t hi, size_t p);

/* Merge the sorted runs a[lo..mid] and a[mid+1..hi] into ascending order,
   using scratch[lo..hi] as workspace. Closed range: mid is the last index of
   the left run. scratch is borrowed, never freed. */
void merge(int* a, size_t lo, size_t mid, size_t hi, int* scratch);

/* Same contract as partition, by a one-pointer scan (exploration, not the
   lesson's scheme). Equal keys all go left, so on equal keys p == hi. */
size_t partition_one_scan(int* a, size_t lo, size_t hi);
