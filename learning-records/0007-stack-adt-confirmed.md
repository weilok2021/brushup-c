# Dynamic-array stack ADT confirmed

Lesson 7 was completed on 2026-09-16. The final exercise built warning-free under AddressSanitizer and UndefinedBehaviorSanitizer, printed the five expected lines exactly, and passed Valgrind with 5 allocations, 5 frees, no errors and no leaks.

## Evidence

- Defined an opaque `stack_t` in the public header and kept its members private to `stack.c`.
- Allocated the stack struct and its items block separately, including cleanup of the struct if the second allocation fails.
- Implemented a `static` growth helper that doubles capacity with `realloc` through a temporary pointer, preserving the old allocation on failure.
- Checked `stack_new` and every `stack_push` result in the client.
- Implemented and exercised count, successful peek, LIFO pop order, and the empty case.
- Freed the owned items block before the owning struct.

## Friction observed

The first submission handled the successful path but did not check the items allocation or the result of `stack_new`. It also placed resizing directly in `stack_push` and did not exercise `stack_peek`. Review separated passing the happy-path memory checks from satisfying failure-path contracts. The final version corrected the allocation cleanup, caller check, helper decomposition, and peek test.

The client drains the stack with a saved-count loop rather than `while (stack_pop(...))`, and it checks emptiness with `stack_peek` rather than one additional `stack_pop`. Both status-return operations are implemented correctly. Clearing the vacated item slot during pop is harmless but unnecessary because `count` defines the live range.

## Implications

Opaque-struct module organization, two-level ownership, LIFO behavior, and safe `realloc` growth are ready for reuse in later ADTs. Return to lesson 6 next for the recursion exercise before continuing toward the recursive BST lesson.
