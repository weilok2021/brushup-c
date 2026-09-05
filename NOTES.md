# Notes

## How to resume
- The `teach` skill is user-invocation only (`disable-model-invocation: true`). Start each study session by typing `/teach` in this directory.

## Preferences (from the user)
- Tooling (gcc flags, make syntax) is scaffolding, not curriculum: give it as copy-paste templates, label it as such, never quiz on it. The user asked whether it was on-goal (2026-09-05); CS107 teaches it in week 1 itself. On-goal parts of lesson 1: header/.c split (data abstraction) and reading sanitizer reports (finding pointer bugs).
- Only the most relevant C fundamentals. No full language tour. (2026-09-05)
- Scaffold: follow the boot.dev DSA course order, re-implemented in C; pull the C prerequisites from boot.dev Memory Management in C. Both trimmed against the CS107 prerequisite statement.
- Has C fundamentals but has not used them for a while. Depth unverified; calibrate with a short diagnostic in lesson 1.

## Environment
- Windows 11 host, Git Bash + PowerShell. No native gcc, clang, MSVC, make.
- WSL Ubuntu 24.04: gcc 13.3.0, GNU Make 4.3, gdb 15.1, valgrind 3.22 present (installed by user 2026-09-05). No clang/cmake; not needed.
- Repo path inside WSL: /mnt/c/Users/weilok.chia/Desktop/personal/brushup-c
- Standard flags for every exercise: `gcc -std=gnu11 -Wall -Wextra -g -fsanitize=address,undefined`. gnu11 rather than c11 so POSIX functions (strdup, getline) are declared without feature macros.

## Planned lesson sequence (trimmed; revise as the zone of proximal development becomes clear)
Phase 1: C fundamentals (source: boot.dev Memory Management in C, ch 1-3, 6-7)
1. Two files, two bugs: header/.c split with include guard, const pointer params, size_t, first program written from memory, reading ASan/LSan reports. Makefile given as paste-once scaffolding, not taught.
2. Structs and pointers: `.` vs `->`, `&` and `*`, pass-by-pointer, arrays decay to pointers, pointer arithmetic, `sizeof`.
3. Stack vs heap: `malloc`/`calloc`/`realloc`/`free`, ownership rules, dangling pointer, leak, double free, and what each looks like under ASan.
4. Pointer-to-pointer and strings as data: `Node **`, arrays of pointers, `char *` keys, `strlen`/`strcmp`/`strdup`. Just enough for hashmap keys.

Phase 2: DSA rebuilt in C (source: boot.dev DSA order, ch 4, 7-10, 12, 14-15)
5. Arrays and sorting I: insertion sort, binary search, swap through pointers.
6. Sorting II (recursion): merge sort with heap-allocated scratch, in-place quicksort.
7. Stack ADT: dynamic array with realloc growth, opaque struct, .h/.c, test program.
8. Singly linked list: push/insert/delete via `Node **`, iterative and recursive reverse, free.
9. Queue ADT: linked list with head and tail pointers, O(1) enqueue and dequeue.
10. Binary search tree: insert, search, min, height, in-order traversal, free. All recursive.
11. Hashmap: string keys, djb2 or FNV-1a, separate chaining, load factor and resize. Set = hashmap without values.
12. Graph: adjacency list, BFS using lesson 9's queue, recursive DFS, connected components.
Optional 13. Trie (array of 26 child pointers), only if time allows.

## Working notes
- 2026-09-05: repo initialised on `main`, C `.gitignore` added, workspace scaffolded. MISSION time budget still TBC.

## Working arrangement (agreed 2026-09-05)
- Conversation happens in the Windows Claude Code session; the user writes and compiles code in WSL Ubuntu.
- The agent compiles and runs the user's code from this session via WSL, passing a script on stdin to avoid quoting issues:
  `wsl -d Ubuntu -- bash -s <<'EOF' ... EOF` with `cd /mnt/c/Users/weilok.chia/Desktop/personal/brushup-c` inside.
- Verified 2026-09-05: `gcc -std=c11 -Wall -Wextra -g -fsanitize=address,undefined` builds and runs from WSL against the /mnt/c path.
- Line endings: global `core.autocrlf=true` would give CRLF Makefiles in WSL ("missing separator"). Repo pinned to LF via `.gitattributes` (`* text=auto eol=lf`) and repo-local `core.autocrlf=false`.

## Conventions
- Exercises live in `exercises/NN-slug/` with `.h`, `.c`, `Makefile`. `.gitignore` whitelists sources there so binaries of any name stay untracked.
- Every lesson ships with a reference sheet in `reference/`; lessons link to it, and it is what the user revisits.

## Lessons issued
- 0001 Two Files, Two Bugs (2026-09-05; trimmed same day at the user's request, tooling teaching removed, file renamed from 0001-the-build-loop.html). Exercise `exercises/01-build-loop/`: vec.h/vec.c/main.c/Makefile, sum of four heap ints = 10; two planted bugs (off-by-one, missing free). Status: COMPLETED 2026-09-05. Built and reviewed from here: warning-free, output 10, valgrind clean. Learning record 0002 written; GLOSSARY.md started. Next: issue lesson 2 (structs and pointers), brisk pace per LR 0002.

## Findings
- 2026-09-05, LeakSanitizer misses leaks at -O0. User's lesson-1 program with `free` removed ran silent under `-fsanitize=address`; valgrind reported 16 bytes definitely lost. Cause verified: stale copies of the pointer in dead stack frames are picked up by LSan's exit-time stack scan, so the block counts as reachable. Reported correctly at -O1 or after scrubbing the stack. Decision: ASan stays for overflow/UAF (immediate, precise); leaks are checked with valgrind via a `make check` target on a plain build. Makefile template updated in lesson 1, reference sheet and the user's exercise folder.
