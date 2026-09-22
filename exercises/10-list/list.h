#pragma once

#include <stddef.h>

typedef struct list list_t;

/* Create an empty list on the heap. Returns NULL if allocation fails. */
list_t* list_new(void);

/* Free every node, then the list itself. Consumes ownership. NULL is allowed. */
void list_free(list_t* ll);

/* Insert v as the new first value. Returns 1, or 0 if allocation fails. */
int list_push_front(list_t* ll, int v);

/* Insert v before the first value that is >= v. Keeps a sorted list sorted.
   Returns 1, or 0 if allocation fails (list unchanged). */
int list_insert_sorted(list_t* ll, int v);

/* Remove the first node holding v. Returns 1 if removed, 0 if absent. */
int list_remove(list_t* ll, int v);

/* Reverse the order of the nodes in place. No allocation. */
void list_reverse(list_t* ll);

/* Print the values, space separated, on one line ending in a newline. */
void list_print(const list_t* ll);

/* Number of values in the list. */
size_t list_count(const list_t* ll);