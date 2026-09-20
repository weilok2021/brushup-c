# Lesson 7 confirmed: Hoare partition and merge written from memory

On 2026-09-20 the user finished lesson 7 (`exercises/07-partition/`), closed-range form.

## Evidence

- `partition` (Hoare, two scans), `partition_one_scan`, `is_partitioned` and `merge` all written by the user. Program prints the expected lines; `make check` gives 7 allocs, 7 frees, 0 errors.
- `merge` took three rounds. Round 1 had the right shape but three bugs (wrong target array in a copy loop, read past an emptied run, result left in the extra buffer). Round 2 fixed all three and left `k = 0` instead of `k = lo`, caught by a test with `lo = 1`. Round 3 is clean and uses the standard three-loop shape.
- The user asked why the C version passes indices instead of splitting into two arrays like the visualizations they had seen. After the explanation (one array plus ranges avoids a malloc and free at every level) they summarised it back correctly.
- The three planted breaks were done by the user without supervision.

## Implications

- Ready for lesson 8. Lesson 8 must be rewritten first: it still teaches `merge` with a scratch parameter (see record 0012, loose ends).
- Review feedback: the user asked for short reviews and asked not to have cosmetic points repeated once they said correctness was unaffected. Keep reviews to bugs, one line each.
