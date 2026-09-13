# Sorting and binary search confirmed

Lesson 5 was completed on 2026-09-13. The final exercise built warning-free under AddressSanitizer and UndefinedBehaviorSanitizer, printed the six expected lines exactly, and passed Valgrind with no errors or leaks. Additional assertions covered empty, singleton, boundary, absent, and duplicate-key searches.

## Evidence

- Implemented insertion sort with `size_t` indices and guarded `j - 1` by testing `j > 0` first.
- Implemented `is_sorted` as a checked postcondition.
- Allocated the working array on the heap, checked the allocation, copied from a named `static const` source array, and freed the owner once.
- Returned a borrowed `const int*` from binary search and converted successful results to indices with pointer subtraction and `%td`.
- Chose an inclusive binary-search range `[low, high]`. Explicit `n == 0` and `mid == 0` checks prevent unsigned wraparound at `n - 1` and `mid - 1`.
- Completed the planted `j >= 0` insertion-sort experiment and understood why an unsigned value cannot become negative.

## Friction observed

The half-open range initially felt less intuitive than the familiar inclusive form. Discussion separated the algorithm from C's unsigned arithmetic: inclusive binary search is valid, but `size_t` requires explicit checks before subtracting one at zero. A Python comparison made the distinction concrete because Python integers can represent `-1`.

The overflow-resistant midpoint `low + (high - low) / 2` was demonstrated with a small fixed-width example. The user understands that `(low + high) / 2` can overflow when both bounds are large, but is retaining that form for now because it matches their current mental model. Revisit the safer form when a later exercise uses larger ranges; do not block current progress on it.

The user chose to omit the unsafe closed-search experiment because its failure had already been traced during implementation. They also omitted the print helper as unrelated to the lesson's main concepts.

## Implications

Proceed to recursive sorting. Keep half-open ranges in lesson 6's merge sort because they define the recursive subarrays and scratch-copy bounds, but derive each range from concrete indices rather than assuming lesson 5's notation feels natural. Continue allowing the guarded inclusive form for standalone binary search.
