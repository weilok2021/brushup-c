#include "list.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct node node_t;          /* private to list.c */

struct node {
    int     value;                   /* 4 bytes, then 4 bytes of padding */
    node_t* next;                    /* 8 bytes: the slot that leads onward */
};                                   /* 16 bytes per node */

struct list {
    node_t* head;                    /* the slot that leads to the first node */
    size_t  count;
};                                   /* 16 bytes, one per list */

/* Create an empty list on the heap. Returns NULL if allocation fails. */
list_t* list_new(void) {
    list_t* ll = malloc(sizeof *ll);
    if (ll == NULL) { return NULL; }
    ll->head = NULL;
    ll->count = 0;
    return ll;
}

/* Free every node, then the list itself. Consumes ownership. NULL is allowed. */
void list_free(list_t* ll) {
    node_t* curr = ll->head;
    while (curr != NULL) {
        node_t* temp = curr->next;
        free(curr);
        curr = temp;
    }
    free(ll);
}

/* Insert v as the new first value. Returns 1, or 0 if allocation fails. */
int list_push_front(list_t* ll, int v) {
    node_t* new_node = malloc(sizeof *new_node);
    if (new_node == NULL) { return 0; }
    new_node->value = v;
    new_node->next = ll->head;
    ll->head = new_node;
    ll->count++;
    return 1;
}

/* Insert v before the first value that is >= v. Keeps a sorted list sorted.
   Returns 1, or 0 if allocation fails (list unchanged). */
int list_insert_sorted(list_t* ll, int v) {
    node_t* new_node = malloc(sizeof *new_node);
    if (new_node == NULL) { return 0; }
    new_node->value = v; 
    new_node->next = NULL;

    node_t* curr = ll->head;
    // empty list case, insert as new head
    if (curr == NULL) {
        ll->head = new_node;
        ll->count++;
        return 1;
    }

    // v smaller than head, so insert as new head
    if (v < curr->value) {
        ll->head = new_node;
        new_node->next = curr;
        ll->count++;
        return 1;  
    }

    // we need to place new node before the k >= v to preserve list order
    node_t* before = NULL;
    while (curr != NULL && curr->value < v) {
        before = curr;
        curr = curr->next;
    }
    before->next = new_node;
    new_node->next = curr;
    ll->count++;
    return 1;
}

/* Remove the first node holding v. Returns 1 if removed, 0 if absent. */
int list_remove(list_t* ll, int v) {
    node_t** link = &ll->head;
    while (*link != NULL) {
        if ((*link)->value == v) {
            node_t* curr = *link;
            *link = (*link)->next;
            free(curr);
            ll->count--;
            return 1;
        }
        link = &(*link)->next;
    }
    return 0;
}

/* Reverse the order of the nodes in place. No allocation. */
void list_reverse(list_t* ll) {
    if (ll->count < 2) {
        return;
    }
    // flip the current next to previous node, 
    // then go to next node and do the same thing
    // so I need a temp pointer to go to next node also
    node_t* prev = NULL;
    node_t* curr = ll->head;
    node_t* rest = NULL;

    while (curr != NULL) {
        rest = curr->next;
        curr->next = prev;
        prev=curr;
        curr = rest;
    }
    // prev is the last reversed node, so set it as new head
    ll->head = prev;
}

/* Print the values, space separated, on one line ending in a newline. */
void list_print(const list_t* ll) {
    for(node_t* curr = ll->head; curr != NULL; curr = curr->next) {
        printf("%d ", curr->value);
    }
    puts("");
}

/* Number of values in the list. */
size_t list_count(const list_t* ll) {
    return ll->count;
}