# Lesson 8 confirmed: merge sort and quicksort written from memory, one function each

On 2026-09-21 the user finished lesson 8 (`exercises/08-recursive-sorts/`), closed range, the day after lesson 7.

## Evidence

- `merge_sort(a, lo, hi)` and `quick_sort(a, lo, hi)` written by the user with lesson 7's `merge` and `partition` as static helpers. Expected five lines printed; `make check` 17 allocs, 17 frees, 0 errors. Extra cases run by the agent all passed: pivot landing at `lo`, six equal keys, one item, sub-range `[1, 8]` of a longer array, sorted and reversed input.
- Before writing, the user asked three conceptual questions and answered each correctly in their own words afterwards: whether quicksort could recurse first and partition after (no: quicksort splits by value, so partition creates the subproblems); whether merge "sorts and merges at the same time" (yes: merge is the only place items are compared, one-item ranges are sorted for free); and whether the `(a, n)` wrapper is redundant (they chose the one-function form; lesson and sheet updated to match).
- The user reported the "merge sort feels like magic" circularity and accepted the bottom-up argument (one item sorted for free, merging two sorted runs gives a bigger sorted run).
- Break 1 (`merge_sort(a, mid, hi)`): the user ran it, saw the stack overflow, and said they expected the sort to still work "as long as the sub problem did reduce". Correct instinct; the two-item range is where it does not reduce. Lesson 6b's second check, now seen failing.
- Break 2 (guard deleted): the user predicted the cause (p == 0, `p - 1` wraps) but expected a stack overflow. Corrected: the wrapped call dies in `partition` on the first read of `a[SIZE_MAX]`, 4 bytes before the block. Takeaway given: "before the region" means an unsigned subtraction went below zero.
- Break 3 (`free(left)` deleted) was not reported as done; the user asked to close the lesson. Not blocking.

## Implications

- Lesson 9 (dynamic-array stack) was already completed on 2026-09-16 (record 0007, commit e758929), before the recursion bridge. Next is lesson 10, the singly linked list.
- Lesson 10 onward must be rewritten in the CS61B style before the user reaches each one (record 0011). Lesson 10 is next.
- Preference confirmed twice now: the smallest correct structure. No wrappers, no scratch parameter. Do not add layers a lesson does not need; when a layer is optional, say so and let the user choose.
- Review style: bugs only, one line each, no repeated cosmetic points.
