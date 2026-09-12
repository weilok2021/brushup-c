#include "words.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char** slots = calloc(3, sizeof *slots);  
    if (slots == NULL) {
        return 1;
    }

    slots[0] = strdup("pear");
    if(slots[0] == NULL) {
        words_free(slots, 0);
        return 1;
    }
    slots[1] = strdup("fig");
    if(slots[1] == NULL) {
        words_free(slots, 1);
        return 1;
    }
    slots[2] = strdup("banana");
    if(slots[2] == NULL) {
        words_free(slots, 2);
        return 1;
    }

    printf("before: %s %s %s\n", slots[0], slots[1], slots[2]);

    char** word_to_replace = words_find(slots, 3, "fig");
    if (word_to_replace == NULL) {
        words_free(slots, 3);
        return 1;
    }
    if (word_replace(word_to_replace, "watermelon") == 0) {
        words_free(slots, 3);
        return 1;
    }
    printf("after: %s %s %s\n", slots[0], slots[1], slots[2]);
    const char* longest_word = words_longest(slots, 3);
    printf("longest: %s (%zu)\n", longest_word, strlen(longest_word));
    words_free(slots, 3);
    return 0;
}