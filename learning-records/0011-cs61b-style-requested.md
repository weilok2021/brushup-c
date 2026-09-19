# Lesson 7's text traces were unreadable; the user asked for the CS61B style

On 2026-09-19, with lesson 7 started (`exercises/07-partition/` created, `partition.h` and the Makefile in place, `partition.c` and `main.c` still empty), the user said: "I couldn't really understand the writing, like those pseudocode are really hard to follow." They asked that DSA concepts and algorithms be explained with reference to UC Berkeley CS61B materials, mimicking how Josh Hug teaches, and that lessons be written in that style where possible.

## Evidence

- The parts of lesson 7 the user could not follow were the monospace traces (`i=1 j=7  i stops at a[2]=15; j stops at a[7]=4  swap`), the four-region diagram written as `lo  lo+1 .. i-1  i .. j  j+1 .. hi-1`, and the quoted language-free pseudocode (`do i := i + 1 while A[i] < pivot`). All three compress the mechanism into notation before the reader has seen it happen.
- This is the same failure as lesson 2's `ptrdiff_t` paragraph (NOTES, 2026-09-05) and the M2-style lesson bloat (CLAUDE.md, 2026-09-12): explanation in symbols and prose where the user needs a picture and one step per sentence.
- CS61B's treatment of the same material was checked at the source (RESOURCES.md, "Teaching model"): the textbook states the definition as a three-line list, asks "which of A to D is not a valid partition", and the Hoare demo slides let two pointers L and G speak in the first person ("Hello, lovely 15.", "Grrr…… 19", "I dislike 17.", "Time to swap.", "Swapped."), one caption per click.

## Decision

Lesson 7 was rewritten in place, same file name, same exercise, same expected output and planted bugs. New shape:

1. Definition as a three-line list, on the lesson's own array, then four arrangements A to D with one invalid (a `<details>` answer).
2. Hug's six L and G rules quoted, then an in-page click-through demo: six arrays (the three `main` calls, `9 1 2 3`, six 7s, and CS61B's `17 15 19 32 2 26 41 17 17` so the user can run Hug's deck beside it), Next and Back buttons, arrow keys, a planted-bug toggle (L loves equal items), and an every-step list that expands for print. The captions are in the pointers' voice.
3. The C with one comment per rule in the demo's words, then three Q&A blocks (the guard, "or equal", move by one).
4. The checker, one level of quicksort by hand drawn as cell rows, then the merge rule in CS61B's words and a second demo with the scratch row filling in.
5. The closed-range section, steps, reports, quiz and Read Next kept; Read Next now leads with Hug's demo and the textbook sections, then Weiss.

The demo's trace generator mirrors the C line for line and was checked in node against the C program's output for all six arrays and both bug states (pivot lands at 3, 6, 2, 3, 3, 4; with the bug 4 and 5; merges `4 4 5 9 9 15 26 35` and `2 15 17 17 17 19 26 32 41`).

## Implications

- Every DSA lesson from here on follows this recipe (NOTES.md, Preferences): concrete array as cells, definition as a short list, a "find the invalid one" question, pointers that speak, a click-through demo generated from code that mirrors the C and is checked against it, then the C annotated per rule, then Q&A. No text traces, no pseudocode, no `i=3 j=6` shorthand.
- Lessons 8 to 15 were issued on 2026-09-12 in the old style. Rewrite each before the user reaches it, starting with lesson 8; RESOURCES.md maps the CS61B chapters and demos to use.
- The reference sheet keeps its compact code and tables (that is what a cheat sheet is for) but now opens the partition section with the L and G rules.
- Do not treat this as a request to teach Java or CS61B's own content. The mission is unchanged: C, the CS107 prerequisite structures, sanitizer-clean. CS61B supplies the explanations and pictures, the exercises stay in C.
