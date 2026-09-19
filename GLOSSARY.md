# C fundamentals for CS107 Glossary

The working vocabulary of this workspace. A term is added only once the user has used the idea correctly in code or in the chat. Lessons and reviews use these words and no synonyms.

## Modules

**Header (`.h`)**:
The file that states what a module offers: prototypes, shared struct declarations, and a one-line contract per function. Clients include the header and never the `.c`.
_Avoid_: interface file, declarations file

**Include guard**:
The `#ifndef X_H` / `#define X_H` / `#endif` wrapper (or `#pragma once`) that makes a second inclusion of a header expand to nothing.
_Avoid_: header guard, pragma

**Prototype**:
A function's declaration without its body. It is the contract the compiler checks every caller and the definition against.
_Avoid_: signature, forward declaration

## Memory

**Heap block**:
A region of memory returned by `malloc` (or `calloc`, `realloc`) that stays alive until it is passed to `free`. Every heap block has exactly one owner responsible for freeing it.
_Avoid_: allocation, buffer, dynamic memory

**Leak**:
A heap block that is never freed. Valgrind reports it as “definitely lost” when nothing points to it at exit.
_Avoid_: memory leak, lost memory

**Off-by-one**:
A loop or index that runs exactly one element too far or too few. Past the end of a heap block it shows up as a `heap-buffer-overflow` located “0 bytes after” the block.
_Avoid_: fencepost error

## Types

**`size_t`**:
The unsigned integer type for counts, sizes and indices. It is what `sizeof`, `malloc` and `strlen` speak. From `<stddef.h>`.
_Avoid_: unsigned int, length type

**`const` pointer parameter** (`const int *a`):
A promise that the function only reads through `a`. It binds the function, not the caller; the pointer itself may still move.
_Avoid_: read-only pointer, constant pointer

## Structs and arrays

**Struct**:
A value composed of named members, declared once where every file that uses the type can see the same declaration.
_Avoid_: record, object

**Member**:
One named value inside a struct, reached with `.` on a struct value or `->` through a pointer.
_Avoid_: field, property

**Arrow operator** (`p->member`):
Member access through a pointer to a struct. It means the same thing as `(*p).member`.
_Avoid_: pointer dot

**Array decay**:
The implicit conversion of an array expression to a pointer to its first element. A function therefore receives a pointer and needs the element count separately.
_Avoid_: array becomes a pointer

**Pointer arithmetic**:
Adding to or subtracting from a pointer in units of pointed-to elements. `p + 1` addresses the next element, not the next byte.
_Avoid_: address math

**One-past-the-end pointer**:
The pointer `rs + n` for an array of `n` elements. Code may form and compare it, but must not dereference it.
_Avoid_: sentinel element

**`ptrdiff_t`**:
The signed integer type produced by subtracting two pointers into the same array. Print it with `%td`.
_Avoid_: pointer index type

## Ownership and lifetime

**Owner**:
The one pointer or code path responsible for eventually freeing a heap block.
_Avoid_: main pointer, original pointer

**Borrower**:
A pointer allowed to access a live heap block without taking responsibility for freeing it.
_Avoid_: secondary owner, safe alias

**Ownership transfer**:
Moving responsibility for the eventual `free` from one pointer or caller to another. A successful `realloc` transfers that responsibility to its returned pointer.
_Avoid_: pointer replacement

**Dangling pointer**:
A stale pointer to an object whose lifetime has ended. It must not be dereferenced or freed.
_Avoid_: freed pointer, bad address

**Use-after-free**:
Reading or writing a heap block after its lifetime ended. AddressSanitizer reports the bad access, the earlier `free`, and the allocation as a timeline.
_Avoid_: stale read

**Double-free**:
Ending one heap block's lifetime twice. It often means that ownership was unclear or that an old pointer was used after successful `realloc`.
_Avoid_: duplicate cleanup

**`realloc`**:
An operation that changes an owned heap block's size. Success returns the only pointer to continue using; failure returns `NULL` and leaves the original block owned and unchanged.
_Avoid_: resize in place

## Reasoning about code

**Precondition**:
What must be true when a function is called, stated in its header comment. `search_range` requires the array to be sorted; `max_range` requires at least one element. A proof starts from it, so a test that breaks it proves nothing.
_Avoid_: assumption, requirement, input contract

**Invariant**:
One sentence that is true at the start of every call (or every loop pass) and is kept true by every step. For binary search: if the target is anywhere in the array, it is in `[lo, hi)`.
_Avoid_: loop condition, property, assertion

**Postcondition**:
What is true when a function returns, given its precondition. A checker such as `is_sorted` or a cross-check against a linear scan tests it at run time.
_Avoid_: output contract, result guarantee
