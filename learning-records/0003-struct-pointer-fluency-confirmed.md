# Struct and pointer fluency confirmed

Lesson 2 was completed on 2026-09-07. The final program built warning-free under `-Wall -Wextra` with AddressSanitizer and UndefinedBehaviorSanitizer, printed the exact expected result, and passed Valgrind with no errors or leaks.

## Evidence

- Allocated a heap array with `malloc(sizeof *rectangles * N)` and freed the owning pointer.
- Read and changed struct members through pointer parameters with the correct `->` operator and `const` contract.
- Walked the array from `rs + 1` to a one-past-the-end pointer with no index variable.
- Returned a pointer into the caller's array and converted its distance from the start to an index using `ptrdiff_t` and `%td`.
- Completed the planted allocation-sizing and member-access bug experiments.
- Correctly explained after discussion that `const rect_t *p` allows `p` to move while preventing writes to a rectangle through `p`.

## Friction observed

The first two outputs were wrong because the rectangle height was transcribed as `N + 1`, then `N - 1`, instead of `N - i`. The required `largest:` prefix was also initially omitted. These were specification-checking mistakes rather than pointer mistakes; comparing the actual line with the expected line found them.

The user prefers `rect_t* p` over the course's `rect_t *p` convention because it makes pointers visually prominent. This is valid C and should be accepted. Mention the declarator rule only where a declaration such as `rect_t* a, b` could mislead.

## Implications

Proceed to lesson 3 without reteaching struct pointers or pointer arithmetic. Continue using `const T *` parameters as interface contracts. Reinforce checking exact expected output before declaring an exercise complete.
