#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    const int nums[5]= {10,20,30,40,50};
    stack_t* num_stack = stack_new();
    if (num_stack == NULL) {
        return 1;
    }
    for (int i = 0; i < 5; i++) {
        if (stack_push(num_stack, nums[i]) == 0) {
            stack_free(num_stack);
            return 1;
        }
    }
    printf("count: %zu\n", stack_count(num_stack));
    int peek = -1;
    stack_peek(num_stack, &peek);
    printf("peek: %d\n", peek);
    printf("popped:");
    size_t before_count = stack_count(num_stack);
    for (size_t i = 0; i < before_count; i++) {
        int popped = -1;
        stack_pop(num_stack, &popped);
        printf(" %d", popped);
    }
    printf("\ncount: %zu\n", stack_count(num_stack));

    if (!stack_peek(num_stack, &peek)) {
        printf("empty: yes\n");
    }

    stack_free(num_stack);
}