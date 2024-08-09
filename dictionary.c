/* Builds the linked list (dictionary) */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "data.h"
#include "dictionary.h"

// Append a new node with the given suburbPtr to the end of the linked list.
void appendNode(node_t **head, suburb_t *suburbPtr) {
    // Construct a new node.
    node_t *newNode = (node_t *)malloc(sizeof(node_t));
    assert(newNode);

    newNode->ptr = suburbPtr;
    newNode->next = NULL;

    // If the list is empty, then the newNode is also the head node.
    if (*head == NULL) {
        *head = newNode;
        return;
    } else {
        // Traverse to the end of the list.
        node_t *lastNode = *head;
        while (lastNode->next != NULL) {
            lastNode = lastNode->next;
        }

        // Add the newNode to the end of the list.
        lastNode->next = newNode;
    }

}

// Traverse the list and print out the suburb struct.
void printList(node_t *node) {
    while (node != NULL) {
        printf("suburb = %d %d %s %d %s %s %s %s %lf %lf\n", node->ptr->code, node->ptr->id, node->ptr->name, node->ptr->year, node->ptr->stateIDs, node->ptr->stateNames, node->ptr->governmentIDs, node->ptr->governmentNames, node->ptr->latitude, node->ptr->longitude);
        node = node->next;
    }
}

// Free the list.
void freeList(node_t *head) {
    node_t *currentNode = head; 
    node_t *nextNode = NULL;

    while (currentNode != NULL) {
        nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }
}
