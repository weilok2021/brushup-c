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

### Algorithms in C (Phase 2 primary readings)
User preference (2026-09-12): the Read Next list in every Phase 2 lesson must be C code or C-based teaching. Java or Python sources may back a claim inline, but they are not assigned reading.
- [Weiss, Data Structures and Algorithm Analysis in C, 2nd ed., author's source files](http://users.cis.fiu.edu/~weiss/dsaa_c2e/files.html)
  Every figure from the book as a standalone `.c` file, free from the author's FIU page (the book text is not free). Verified 2026-09-12: `sort.c` (InsertionSort shift form, Shellsort, Mergesort, Quicksort with insertion-sort cutoff), `fig2_9.c` (BinarySearch, closed form, signed int), `list.c`, `stackar.c`, `stackli.c`, `queue.c`, `tree.c`. Old-style C (`int` sizes, `ElementType` typedef) so read for the algorithm, not the style. Use for: the primary C reading in lessons 5-10.
- [CS50 Shorts, Doug Lloyd (Harvard, video)](https://www.youtube.com/playlist?list=PLDUCVu96aqJax03b583k6JMaP3ejXwyJ7)
  Five to ten minute walkthroughs from a C-based course: [Insertion Sort](https://video.cs50.io/O0VbBkUvriI), [Binary Search](https://video.cs50.io/T98PIp4omUA), Selection Sort, Bubble Sort, Merge Sort, plus data-structure shorts (linked lists, stacks, queues, hash tables, tries). Hand traces, no code. Use for: the "watch first" option in Phase 2 lessons. Note: the current CS50x shorts index no longer lists insertion sort; link the video directly.
- [Beej's Guide to C Library Reference](https://beej.us/guide/bgclr/html/split/)
  Companion volume to Beej's Guide. Verified 2026-09-12: `stdlib.html` sections 24.17 `bsearch()` and 24.18 `qsort()` with examples. Use for: when a lesson reaches the library versions (CS107 lecture 8 assigns them).
- [CS107 calendar, archive 1268](https://web.stanford.edu/class/archive/cs/cs107/cs107.1268/calendar.html)
  Lecture 8 "Generic Operations: void *" and lecture 9 "Function Pointers" assign K&R 5.11 and the man pages for `qsort`, `lfind`, `bsearch`. Use for: telling the user where each Phase 2 topic lands in the target course.

### Algorithms reference (claims, not reading)
- [Algorithms, 4th ed. booksite, Sedgewick & Wayne (Princeton)](https://algs4.cs.princeton.edu/home/)
  Free companion site to the textbook; Java code, but the invariants and cost claims are language-neutral and precisely stated. Mapped sections: 1.1 (binary search), 2.1 Elementary Sorts (insertion), 2.2 Mergesort, 2.3 Quicksort, 1.3 Bags, Queues, Stacks, 3.2 Binary Search Trees, 3.4 Hash Tables, 4.1 Undirected Graphs. Use for: citing an invariant or a cost inline. Do not assign as reading (Java; user preference above).
  Java listings per section, fetched and checked 2026-09-12 by the lesson 6 to 10 authors: [Merge.java](https://algs4.cs.princeton.edu/22mergesort/Merge.java.html) (aux allocated once in the public `sort`), [Quick.java](https://algs4.cs.princeton.edu/23quicksort/Quick.java.html) (partition scans stop on equal keys), [ResizingArrayStack.java](https://algs4.cs.princeton.edu/13stacks/ResizingArrayStack.java.html) (the only page stating "constant amortized time" in words), [Queue.java](https://algs4.cs.princeton.edu/13stacks/Queue.java.html) (`last = null` reset in dequeue; worst-case constant time), [BST.java](https://algs4.cs.princeton.edu/32bst/BST.java.html) (height convention: empty -1, one node 0). Use for: the exact reference implementation when the section prose is ambiguous.
- Khan Academy algorithms articles (insertion sort, binary search): page content did not load for the fetch tool on 2026-09-12; not cited until verified.

### C reference
- [Beej's Guide to C Programming](https://beej.us/guide/bgc/html/split/)
  Free, current, conversational and technically careful. Mapped chapters: 4 Functions (4.1 passing by value), 5 Pointers, 6 Arrays, 7 Strings, 8 Structs, 11 Pointers II (arithmetic), 12 Manual Memory Allocation, 17 Multifile Projects, 23 Pointers III (pointers to pointers; 23.1 gives the `p` to `&p` type step only, not the motivation, which lesson 8 supplies), 35 Incomplete Types (the rule behind opaque structs). Beej has no chapter on recursion or on opaque structs as a pattern. Use for: the primary reading recommended in each Phase 1 lesson.
- [Modern C, 3rd edition (C23), Jens Gustedt. Free PDF](https://hal.inria.fr/hal-02383654)
  Rigorous and standards-based. Note (2026-09-12): the hal.inria.fr link returns an HTML landing page to the fetch tool and the PDF could not be read from WSL (no pdftotext); not cited in lessons 6 to 10. Use for: the precise rule when Beej is too informal (array-to-pointer decay, sizeof, undefined behaviour).
- [cppreference.com: C language and library](https://en.cppreference.com/w/c)
  Authoritative function-by-function reference. Use for: exact signatures, return values and failure modes of malloc, realloc, strcmp, strdup, qsort. Pages return 403 to the fetch tool; use `curl -L -A "Mozilla/5.0"`. Also cited: `free` (post-free access is undefined) and the incomplete-types section of the Type page.

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
