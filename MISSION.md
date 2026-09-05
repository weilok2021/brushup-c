# Mission: C fundamentals for Stanford CS107

## Why
Self-study Stanford CS107 (Computer Organization & Systems, archive 1268) from a real-but-rusty C background. CS107 assumes CS106B-level fluency: recursion, pointer-based data structures, classic algorithms, written as clean, well-decomposed code. Close that gap in C first, so CS107 time goes to bits, memory, assembly and the heap allocator instead of fighting pointers.

## Success looks like
- Implement from a blank file, in C, warning-free under `gcc -Wall -Wextra -g -fsanitize=address,undefined` in WSL: a dynamic-array stack, a singly linked list, a linked-list queue, a binary search tree, a chained hashmap with string keys, and an adjacency-list graph with BFS and DFS.
- Write recursive merge sort, quicksort, BST operations and DFS without reference material.
- Every structure shipped as an abstract data type: `.h` interface, `.c` implementation, opaque struct, small functions, a test program, a Makefile.
- No memory errors from AddressSanitizer and no leaks from valgrind (`make check`) on any exercise.
- Explain, unprompted, where each byte of a program lives (stack, heap, static) and who owns and frees it.

## Constraints
- Windows 11 host; build and run inside WSL Ubuntu (gcc 13.3 present; make/gdb/valgrind still to install).
- Only the C fundamentals the CS107 prerequisite actually needs. No tour of the whole language.
- Do not pre-teach CS107's own material (bits and integers, C-string internals, `void *` generics, function pointers, assembly, heap allocator) beyond the minimum needed to build the structures above.
- Time budget: TBC (hours per week, and target date to start CS107).

## Out of scope
- boot.dev DSA chapters: Math, Big-O deep dive, Exponential Time, Red-Black Trees, P vs NP. Tries optional at the very end.
- boot.dev Memory Management in C chapters: Unions, Objects, Refcounting GC, Mark-and-Sweep GC.
- C++, Windows-native toolchains (MSVC, MinGW), CMake.
