#include <stdlib.h>
#include "words.h"
#include <string.h>

char** words_find(char** words, size_t n, const char* target) {
    for(char** p = words; p < words + n; p++) {
        // compare string in each pointer slot to target, return address of the slot if found
        if (strcmp(*p, target) == 0) {
            return p;
        }
    }
    return NULL;
}

int word_replace(char** slot, const char* replacement) {
    char* replacement_slot = strdup(replacement);
    if (replacement_slot == NULL) {
        return 0;
    } 
    free(*slot);
    *slot = replacement_slot;
    return 1;
}

const char* words_longest(char** words, size_t n) {    
    char* longest_word = *words;
    for (char** p = words + 1; p < words + n; p++) {
        if (strlen(*p) > strlen(longest_word)) {
            longest_word = *p;
        }
    }
    return longest_word;
}

void words_free(char** words, size_t n) {
    for (char** p = words; p < words + n; p++) {
        free(*p);
        *p = NULL;
    }
    free(words);
}