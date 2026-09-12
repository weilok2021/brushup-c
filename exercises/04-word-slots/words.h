#pragma once

#include <stddef.h>

/* Find target among the n strings at words.
   Returns the address of the matching pointer slot, or NULL if absent. */
char** words_find(char** words, size_t n, const char* target);

/* Replace the owned string at *slot with a heap copy of replacement.
   Returns 1 on success. On failure, returns 0 and leaves *slot unchanged. */
int word_replace(char** slot, const char* replacement);

/* Return the longest of n strings. n must be at least 1.
   Returns a borrowed pointer owned by the array. */
const char* words_longest(char** words, size_t n);

/* Free n owned strings, then free their pointer array. Consumes ownership. */
void words_free(char** words, size_t n);