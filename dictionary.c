/* Builds the linked list (dictionary) */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "data.h"
#include "dictionary.h"

void appendNode(node_t **head, suburb_t *suburbPtr) {
    // Construct a new node.
    node_t *newNode = (node_t *)malloc(sizeof(node_t));
    newNode->ptr = suburbPtr; 
    newNode->next = NULL;

    // If the list is empty, then the newNode is also the head node.
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Traverse to the end of the list.
    node_t *lastNode = *head;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }

    // Add the newNode to the end of the list.
    lastNode->next = newNode;
}

