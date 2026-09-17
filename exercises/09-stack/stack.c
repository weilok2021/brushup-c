#include "stack.h"
#include <stdlib.h>

/* A last-in, first-out stack of ints. The members are private to stack.c. */
struct stack {
    int* items;
    size_t count;
    size_t capacity;
};

#define INITIAL_CAPACITY 2

/* Create an empty stack on the heap. Returns NULL if allocation fails.
   The caller owns the result and must pass it to stack_free. */
stack_t* stack_new(void) {
    stack_t* s = malloc(sizeof *s);
    if (s == NULL) { return NULL; }
    // allocate INITIAL_CAPACITY of blocks
    s->capacity = INITIAL_CAPACITY;
    s->items = malloc(sizeof *(s->items) * INITIAL_CAPACITY);
    if (s->items == NULL) {
        free(s);
        return NULL;
    }
    s->count = 0;
    return s;
}

/* Free the stack and everything it owns. Accepts NULL. Consumes ownership. */
void stack_free(stack_t* s) {
    if (s == NULL) { return; }
    free(s->items);
    free(s);
}

static int stack_grow(stack_t* s) {
    int* temp = realloc(s->items, sizeof *(s->items) * s->capacity * 2);
    if (temp == NULL) {
        return 0;
    }
    s->items = temp;
    s->capacity *= 2;
    return 1;
}

/* Push value on top. Returns 1 on success.
   On allocation failure, returns 0 and leaves the stack unchanged. */
int stack_push(stack_t* s, int value) {
    // check does count >= capacity, if not resize the items array, and capacity
    if (s->count >= s->capacity && !stack_grow(s)) {
        return 0;
    }
    s->items[s->count] = value;
    s->count++;
    return 1;
}

/* Remove the top value and write it to *out. Returns 1 if a value was popped.
   On an empty stack, returns 0 and leaves *out unchanged. */
int stack_pop(stack_t* s, int* out) {
    if (s->count == 0) {
        return 0;
    }
    *out = s->items[s->count - 1];
    s->items[s->count - 1] = 0; // remove the value at top
    s->count--;
    return 1;
}


// /* Copy the top value to *out without removing it. Returns 1 if there is one.
//    On an empty stack, returns 0 and leaves *out unchanged. */
int stack_peek(const stack_t* s, int* out) {
    if (s->count == 0) {
        return 0;
    }
    *out = s->items[s->count - 1];
    return 1;
}

// /* Number of values currently on the stack. */
size_t stack_count(const stack_t* s) {
    return s->count;
}