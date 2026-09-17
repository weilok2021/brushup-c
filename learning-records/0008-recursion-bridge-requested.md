# Recursion bridge requested before the recursive sorts

On 2026-09-17 the user, with lessons 1 to 5 and the stack lesson complete, looked at the recursive-sorts lesson (then numbered 6) and said it "requires particular amount of understanding on using recursion and partition problems" that they did not yet have. They asked for one or two lessons of learning and practice on those two things first, and for every later lesson to be renumbered.

## Evidence

- The recursive-sorts lesson asked for four new things at once: recursion on half-open ranges, work placed after the recursive call (merge), a two-scan partition with its guards and equal-key stops, and a wrapper that owns a scratch block. Learning record 0006 had already flagged that half-open ranges felt less intuitive than inclusive ones.
- The user identified the gap themselves before starting the exercise, rather than after a failed attempt. That is the right moment to insert a bridge.

## Decision

Two bridge lessons were inserted and everything after them shifted by two:

- Lesson 6, Shrink, Then Trust (`exercises/06-recursion/`): base case, shrink, trust; four recursive shapes over `[lo, hi)` (shrink by one, work after the call, halve, halve and keep one side); a gdb backtrace of the frames; the stack-overflow column as the signature of a range that never shrank.
- Lesson 7, Scan, Stop, Swap (`exercises/07-partition/`): Hoare's two-scan partition with a postcondition checker, the equal-key stops, the one bounds guard, one level of quicksort done by hand in `main`, and the merge loop with `main` as the scratch owner.
- Old lessons 6 to 13 became 8 to 15; `exercises/07-stack/` became `exercises/09-stack/`. Learning records 0006 and 0007 keep their original numbering in their text ("lesson 7 was completed" there means the stack lesson, now lesson 9).

## Implications

- Lesson 8 (recursive sorts) now assumes `partition` and `merge` are known loops and asks the user to rewrite them from memory, then compare with the lesson 7 versions. Its `merge_sort_range` is lesson 6's `max_range` shape.
- Prefer this pattern in future: when a lesson bundles two or more new mechanisms, and the user says so, split the mechanisms out into short warm-up lessons rather than thinning the target lesson.
- Do not mark lesson 8 done until `exercises/08-recursive-sorts/` exists and builds; the same rule as before the renumbering.
