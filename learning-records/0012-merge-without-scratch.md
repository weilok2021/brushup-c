# Lesson 7's scratch-buffer merge was not intuitive; the user asked for the left/right copy version

On 2026-09-20 the user wrote their first `merge` for lesson 7 by copying the two runs into `left_arr` and `right_arr` and merging from those. Reviewing it, the header's `scratch` parameter came up, and the user said: "Honestly I don't know what's the scratch is for. I always prefer the most intuitive and easy to understand method." They asked to remove scratch from the lesson and teach the left/right subarray approach, accepting the extra allocations.

## Evidence

- The user's draft had the right shape (copy runs out, compare fronts, write the smaller) and three bugs: the right-run copy loop wrote into `left_arr`, the merge loop read past a run once it emptied, and the result stayed in the extra buffer instead of going back into `a`. None of the bugs came from the approach; they came from writing it against a header that described a different approach.
- The scratch version saves two mallocs per merge but adds a concept (a borrowed workspace with an owner elsewhere) on top of the merge rule itself. CLRS teaches merge with two copied subarrays; CS61B's demo draws two source rows and a result row. The copy version is the textbook one.

## Decision

Lesson 7 rewritten in place for `void merge(int* a, size_t lo, size_t mid, size_t hi)`:

1. `merge` copies `a[lo..mid)` into `left` and `a[mid..hi)` into `right`, merges back into `a[lo..k)`, frees both. One paragraph says why the copies exist (writing `a[k]` would clobber unread items).
2. The click-through demo now shows three rows: `left`, `right`, and `a` filling in. Trace checked in node: `4 4 5 9 9 15 26 35` and `2 15 17 17 17 19 26 32 41`.
3. Closed-range table rows for merge updated (`nl`, `nr`, right copy reads `a[mid + 1 + x]`).
4. Steps: no scratch block in `main`; Valgrind expects 7 allocs, 7 frees.
5. Planted bug 3 changed. The old one (drop the right tail loop) now produces correct output by accident, because `a[6..8)` already held `26 35`. The new one is "delete `free(right)`": LeakSanitizer reports 16 bytes in 1 object allocated in `merge`; Valgrind reports 7 allocs, 6 frees, definitely lost. Verified against a real build.
6. `partition.h` in the exercise updated to the new signature. The user's `partition.c` merge is left for them to rewrite.

## Loose ends

- Lesson 8 (`0008-merge-sort-and-quicksort.html`) still teaches `merge` with a scratch parameter, has `merge_sort` own the scratch block, and plants "delete `free(scratch)`" as a bug. It must be rewritten to the copy version before the user reaches it, or it will contradict lesson 7. The scratch version can stay there as an optional "one allocation instead of 2n" aside.
- The reference sheet, if it shows `merge`, needs the same signature change.
