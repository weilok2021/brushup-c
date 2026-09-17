#pragma once

#include <stddef.h>

/* A last-in, first-out stack of ints. The members are private to stack.c. */
typedef struct stack stack_t;

/* Create an empty stack on the heap. Returns NULL if allocation fails.
   The caller owns the result and must pass it to stack_free. */
stack_t* stack_new(void);

/* Free the stack and everything it owns. Accepts NULL. Consumes ownership. */
void stack_free(stack_t* s);

/* Push value on top. Returns 1 on success.
   On allocation failure, returns 0 and leaves the stack unchanged. */
int stack_push(stack_t* s, int value);

/* Remove the top value and write it to *out. Returns 1 if a value was popped.
   On an empty stack, returns 0 and leaves *out unchanged. */
int stack_pop(stack_t* s, int* out);

/* Copy the top value to *out without removing it. Returns 1 if there is one.
   On an empty stack, returns 0 and leaves *out unchanged. */
int stack_peek(const stack_t* s, int* out);

/* Number of values currently on the stack. */
size_t stack_count(const stack_t* s);