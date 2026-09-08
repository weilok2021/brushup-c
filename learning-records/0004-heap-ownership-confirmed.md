# Heap ownership and realloc semantics confirmed

Lesson 3 was completed on 2026-09-08. The final exercise built warning-free under AddressSanitizer and UndefinedBehaviorSanitizer, produced the expected zeroed values and sum, and passed Valgrind with no errors or leaks.

## Evidence

- Allocated zeroed integer storage with `calloc` and checked for `NULL` before dereferencing it.
- Resized through a temporary pointer, preserved the original owner on failure, initialized the newly grown region, and freed the successful result exactly once.
- Deliberately freed the pre-`realloc` pointer after a successful resize. AddressSanitizer identified the attempt as a double-free and showed that `realloc` had already freed the original 16-byte block.
- Explained that successful `realloc` invalidates use of the input pointer while failed `realloc` leaves the original block alive and owned by the caller.
- Added the module's own header to `ints.c` and correctly described how including it lets the compiler check definitions against the public declarations.

## Friction observed

The initial cleanup treated the old and returned `realloc` pointers as two separately owned blocks. The sanitizer report corrected that model: one ownership obligation continues through a successful resize. This concept is now decision-grade.

The exercise still uses `sizeof(int)` in `ints_new` rather than sizing from a local pointee, and its first output line has trailing whitespace. Both are non-blocking because the allocation is correctly sized and the observable values are correct. Continue reinforcing `sizeof *p` and output verification during reviews.

## Implications

Proceed to pointer-to-pointer and strings. Ownership should now be stated explicitly for every returned pointer and every function that may free or replace one. The successful-`realloc` rule does not need reteaching, but it should be exercised again when the dynamic-array stack grows in lesson 7.
