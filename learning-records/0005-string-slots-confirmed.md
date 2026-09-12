# Pointer-to-pointer and owned strings confirmed

Lesson 4 was completed on 2026-09-12. The final exercise built warning-free under AddressSanitizer and UndefinedBehaviorSanitizer, printed the three expected lines exactly, and passed Valgrind with 6 allocations, 6 frees, no errors and no leaks.

## Evidence

- Built a two-level owned structure: `calloc` for the slot array, `strdup` for each string, with a `NULL` check after every allocation.
- On a failed allocation, called `words_free(slots, k)` with `k` equal to the number of strings created so far. Partial cleanup applied unprompted.
- `words_find` returns the address of the matching slot. `word_replace` allocates the copy first, returns 0 with the slot untouched on failure, then frees the old string and assigns. Correct order for the "unchanged on failure" contract.
- `words_longest` returns a borrowed `const char*` and `main` never frees it.
- `words_free` frees inner strings before the outer array.
- Used `%zu` for `size_t` after review, matching the `%td` habit from lesson 2.

## Friction observed

The first draft of `word_replace` showed three model gaps, all resolved in discussion before the rewrite:

1. Tried to recover an array length from a `char**` with `sizeof`. Resolved: a pointer carries no length; length travels as a count, a sentinel, or a contract.
2. Tried to free a string one character at a time. Resolved: one `malloc` is one block, freed whole by its start pointer; count allocations, not bytes.
3. Stored the borrowed `replacement` pointer directly into the slot. Resolved: "heap copy" is what makes the slot the owner.

The user said the pattern of a finder returning a slot address, consumed by a second function, was new and needed time to digest. They also asked to defer `char* const*`; the exercise and lesson now use `char**` for read-only array parameters.

The planted bug experiments (inverted `strcmp`, `free(slot)` versus `free(*slot)`, use after freeing the owner) were skipped at the user's choice.

## Implications

- Phase 1 (C fundamentals) is complete. Proceed to phase 2, DSA in C, starting with arrays and sorting.
- The "return the address of the thing to change" pattern is understood but fresh. Lesson 8 (`Node **` in the linked list) should re-derive it with a diagram rather than assume it.
- Reintroduce `char* const*` only when a cast error makes it concrete.
- Because the use-after-free-of-owner experiment was skipped, a later lesson that returns borrowed pointers (BST min, hashmap get) should include one deliberate use-after-free so the sanitizer report is seen at least once.
