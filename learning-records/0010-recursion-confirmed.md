# Recursion and the closed-range binary search confirmed

Lessons 6 and 6b were completed on 2026-09-19. `exercises/06-recursion/` builds warning-free under AddressSanitizer and UndefinedBehaviorSanitizer (and under `-Wconversion`), prints lesson 6's six expected lines exactly, and passes Valgrind with 0 errors, 3 allocations and 3 frees.

## Evidence

- `sum_range` (shrink by one), `print_backwards` (work after the call) and `max_range` (halve, use both) were written by the user in the lesson's shapes over half-open ranges with the right base cases.
- `search_range` was written in the closed form `[low, high]` with a `size_t` midpoint `(low + high) / 2`, `low > high` as the empty test and a `mid == 0` guard before `mid - 1`. Verified by the teacher with an exhaustive cross-check over every sub-range of the 8-element sorted array and every target 3 to 36: 1224 cases, 0 failures, ASan clean. The header now says inclusive and requires at least one element; the earlier mismatch (half-open header over a closed body) was the only real bug, found by probing a target above the last element.
- The gdb session was done in the user's own terminal and matched the reference backtrace (frames `low` 3, 2, 1, 0, then `main`; 64 bytes per frame). The user asked why `up` moves down the printed list; answered with the three views (listing, frame number, address) and the stack growing toward lower addresses.
- The small fixes (header comment, `size_t mid`, trailing space, `%ld`) were applied by the teacher at the user's request after the user had done the substantive work.

## Not confirmed

- Lesson 6 step 7, the three planted bugs, and lesson 6b's `check_search` and its two planted bugs. The user declared the lesson done without reporting them. Do not re-open; the closed-range search was verified exhaustively by the teacher instead, and the user saw the `a[8]` overflow from the mismatched convention, which was the point of 6b.

## Friction observed

- The user's intuition is closed-range: "N = high - low + 1" reads as the natural count. They rewrote the search twice and chose closed both times. Half-open stays where the lessons need it for splitting (merge sort, partition), and the user accepts that.
- The user asked why the stack behaves the way it does (growth direction, frames), beyond knowing stack from heap. That is CS107's own material; pointed at the calendar rather than pre-teaching.

## Implications

- Next: lesson 7 (partition and merge), then 8. Both hand out half-open range functions; state both counts side by side per the NOTES preference.
- Any new binary search the user writes will be closed; check for the two guards and a matching header, nothing else.
