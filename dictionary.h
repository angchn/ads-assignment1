#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_

#include "data.h"

// Data definitions.
typedef struct node {
    suburb_t *ptr;
    struct node* next;
} node_t;

// Function definitions.
void appendNode(node_t **head, suburb_t *suburbPtr);
void printList(node_t *node);
void freeList(node_t *head);

#endif