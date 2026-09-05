# C fundamentals for CS107 Resources

## Knowledge

### The target (defines what "enough" means)
- [CS107 Syllabus, archive 1268](https://web.stanford.edu/class/archive/cs/cs107/cs107.1268/syllabus.html)
  Prerequisite statement, lecture list (weeks 1-4 are C), required text. Use for: deciding what NOT to pre-teach.
- [CS107 Style Guide](https://web.stanford.edu/class/archive/cs/cs107/cs107.1268/styleguide.html)
  What "well-decomposed, readable code" means to the course. Use for: the code-quality bar in every exercise.
- [CS107 Testing Strategies](https://web.stanford.edu/class/archive/cs/cs107/cs107.1268/testing.html)
  Use for: how to write the test program that ships with each ADT.
- [CS107 Debugging Guide](https://web.stanford.edu/class/archive/cs/cs107/cs107.1268/resources/debugging.html), [GDB Guide](https://web.stanford.edu/class/archive/cs/cs107/cs107.1268/resources/gdb.html), [Valgrind Guide](https://web.stanford.edu/class/archive/cs/cs107/cs107.1268/resources/valgrind.html), [Unix Guide](https://web.stanford.edu/class/archive/cs/cs107/cs107.1268/resources/unix.html)
  The exact tool guides CS107 students are given. Use for: lessons 1 and 3 (toolchain, memory errors).
- [CS107 C Standard Library Guide](https://web.stanford.edu/class/archive/cs/cs107/cs107.1268/guide/stdlib.html)
  Curated list of the libc functions the course expects you to know. Use for: which string/stdlib functions to reach for, and which to avoid.

### Course scaffolds (topic order only, not C sources)
- [boot.dev: Learn Data Structures and Algorithms (Python)](https://www.boot.dev/courses/learn-data-structures-and-algorithms-python)
  16 chapters. Gives Phase 2 its ORDER. Chapters used: 4 Sorting, 7 Stacks, 8 Queues, 9 Linked Lists, 10 Binary Trees, 12 Hashmaps, 14 Graphs, 15 BFS/DFS. Skipped: 1-3, 5-6, 11, 16 (13 Tries optional). Use for: exercise ideas per structure.
- [boot.dev: Learn Memory Management in C](https://www.boot.dev/courses/learn-memory-management-c)
  11 chapters. Gives Phase 1 its C prerequisites. Chapters used: 1 C Basics, 2 Structs, 3 Pointers, 6 Stack and Heap, 7 Advanced Pointers. Skipped: 4 Enums (mention only), 5 Unions, 9-11 Objects and garbage collectors. Use for: sequencing the pointer/heap material.

### C reference
- [Beej's Guide to C Programming](https://beej.us/guide/bgc/html/split/)
  Free, current, conversational and technically careful. Mapped chapters: 5 Pointers, 6 Arrays, 7 Strings, 8 Structs, 11 Pointers II (arithmetic), 12 Manual Memory Allocation, 17 Multifile Projects, 23 Pointers III (pointers to pointers). Use for: the primary reading recommended in each Phase 1 lesson.
- [Modern C, 3rd edition (C23), Jens Gustedt. Free PDF](https://hal.inria.fr/hal-02383654)
  Rigorous and standards-based. Use for: the precise rule when Beej is too informal (array-to-pointer decay, sizeof, undefined behaviour).
- [cppreference.com: C language and library](https://en.cppreference.com/w/c)
  Authoritative function-by-function reference. Use for: exact signatures, return values and failure modes of malloc, realloc, strcmp, strdup, qsort.

## Wisdom (Communities)
- [r/C_Programming](https://www.reddit.com/r/C_Programming/)
  Active and well moderated; welcomes beginner questions when code is shown. Use for: review of a finished ADT, "is this idiomatic C" questions.
- boot.dev Discord (only if the user holds a boot.dev membership; not verified this session)
  Use for: questions specific to the two scaffold courses.
- Stack Overflow, [c] tag
  Search first, ask rarely. Use for: a specific compiler error or undefined-behaviour question.

## Gaps
- No autograder. Each lesson ships its own test program plus AddressSanitizer; establish a `make test` convention in lesson 1.
- No verified community for the scaffold courses unless the user has a boot.dev membership.
