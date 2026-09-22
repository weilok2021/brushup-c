#include "list.h"
#include <stdio.h>

int main(void) {
    list_t* ll = list_new();
    if (list_push_front(ll, 7) == 0) {
        list_free(ll);
        return 1;
    }
    if (list_push_front(ll, 3) == 0) {
        list_free(ll);
        return 1;
    }
    if (list_push_front(ll, 1) == 0) {
        list_free(ll);
        return 1;
    }
    printf("push: ");
    list_print(ll);

    if (list_insert_sorted(ll, 5) == 0) {
        list_free(ll);
        return 1;
    }
    if (list_insert_sorted(ll, 0) == 0) {
        list_free(ll);
        return 1;
    }   
    if (list_insert_sorted(ll, 9) == 0) {
        list_free(ll);
        return 1;
    }

    printf("sorted: ");
    list_print(ll);
    printf("count: %zu\n", list_count(ll));

    printf("remove 0: %s\n", list_remove(ll, 0) ? "yes" : "no");
    printf("remove 5: %s\n", list_remove(ll, 5) ? "yes" : "no");
    printf("remove 4: %s\n", list_remove(ll, 4) ? "yes" : "no");

    printf("after: ");
    list_print(ll);
    list_reverse(ll);
    printf("reversed: ");
    list_print(ll);
    printf("count: %zu\n", list_count(ll));

    list_free(ll);
    return 0;
}
