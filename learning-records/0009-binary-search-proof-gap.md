# Binary search: the user wants a proof, not a feeling

On 2026-09-18, partway through lesson 6, the user said the recursive binary search felt "particularly hard to implement 100% correct with common sense knowledge", and that they could not prove the edge cases or that "split in half will work correctly 100%".

## Evidence

- The draft `search_range` in `exercises/06-recursion/recur.c` mixed conventions: a half-open header (`a[low..high)`) over a closed body (`low > high` as the stop, `mid - 1` for the left half, `int mid = (low + high) / 2`). Built and run, AddressSanitizer reported `stack-buffer-underflow` at recur.c:44, a read 4 bytes before the array: `mid - 1` wrapped at `mid == 0` under `size_t`, and the `int mid` turned the wrapped value into -1.
- The draft `main.c` searched an unsorted array (`5 2 3 4 0`) and printed a `long` with `%d`.
- Learning record 0006 already showed the user chose a guarded closed range in lesson 5 because it felt more intuitive. The half-open form still has no intuition behind it for them; that is the gap, and it is the gap Bentley documented (90 percent of professional programmers wrong; Knuth's "surprisingly tricky").
- The three other functions in the draft (`sum_range`, `print_backwards`, `max_range`) were already correct in shape. `print_backwards` prints a trailing newline from inside the recursion (`if (low == 0) puts("")`), which the lesson 6 spec puts in `main`.

## Decision

Issued an interlude, lesson 6b `lessons/0006b-binary-search-invariant.html` (Say Where It Must Be), rather than renumbering again or answering in chat only. It teaches the invariant method in the user's own terms: the promise ("sorted, and if target is anywhere then it is in [lo, hi)"), three checks (first call, every call, every return), the arithmetic fact `lo <= mid < hi` for every `k = hi - lo >= 1` with a table for sizes 1 to 8, the user's own draft judged line by line, and Bentley's exhaustive small-case test as a `check_search` cross-check against a linear scan (306 cases). Planted bugs: `lo > hi` (stack overflow on the search for 7) and `hi - lo <= 1` (all six hand-test lines right, the check reports 8 failures, exit 1). Sources: Bentley 1983, Pfenning's CMU 15-122 lecture 6 (C-like with contracts, half-open), Bloch 2006, Wikipedia's implementation-issues section, Aspnes 5.3.3.1.

Glossary gained precondition, invariant and postcondition. The recursion reference gained a section, "The promise: proving the answer".

## Implications

- The user's standard for "done" on index-heavy code is a proof, not a passing run. Give every later range function its promise in one sentence and a checker: `is_partitioned` (7), `is_sorted` (8), and for the BST (12) the promise "if the key is anywhere, it is in this subtree".
- Amended 2026-09-19: the user chose half-open for `search_range` after seeing the count and split table, but stated a preference for the closed range and its count `N = high - low + 1` in future lessons, as more intuitive for counting. Respect it: lessons give both counts, the closed form is accepted in exercises with the lesson 5 `size_t` guards and a matching header, and reviews check for one convention per function. The trap seen here was mixing, not the closed form itself. Details in NOTES.md, Preferences.
- Lesson 6 is not done until `exercises/06-recursion/` builds with the seven expected lines (six from lesson 6 plus the check line) and passes valgrind. Mark lessons 6 and 6b done together.
- If the user asks the same "how do I know it is right" question about partition in lesson 7, point at the three checks first and the checker second; do not write a fourth bridge lesson.
