# Baseline C fluency confirmed: heap basics and module split are not rusty

Lesson 1 (2026-09-05) asked for vec.c and main.c written from memory. Both compiled warning-free under -Wall -Wextra on the first build I saw, produced the right answer, and passed valgrind with no leaks. The user also chose `#pragma once` over the taught include guard, which shows prior header experience rather than copying. Syntax and basic heap use need no re-teaching.

## Evidence
- `malloc(sizeof(*four_ints) * 4)`: sizes taken from the pointer, unprompted.
- `for (size_t i = 0; i < n; i++)` in vec_sum: correct counter type, const parameter respected.
- Matching `free`; the planted leak and off-by-one were both found from the reports and fixed.
- Conceptual question about the Makefile mapped it correctly to build scripts in other languages.

## Not yet evidenced
Pointer-to-pointer, struct pointers and `->`, pointer arithmetic, `realloc`, C strings. These are the lesson 2-4 material and should be checked, not assumed.

## Implications
- Lesson 2 can skip "what is a pointer" and go straight to structs, `->`, arrays decaying to pointers, and pointer arithmetic, at a brisk pace. Consider folding planned lessons 2 and 3 into one if lesson 2 goes as smoothly.
- Style habits to reinforce in every review, not to teach as lessons: a count that appears more than once becomes a named constant; `int *p` not `int* p`; explicit `return 0;` in main.
