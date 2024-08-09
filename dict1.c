#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "data.h"
#include "dictionary.h"

int main(int argc, char **argv) {
    // Process command line arguments.
    char *stageNum = argv[1];
    
    FILE *inFile = fopen(argv[2], "r");
    if (inFile == NULL) {
        return EXIT_FAILURE;
    }

    FILE *outFile = fopen(argv[3], "w");
    if (outFile == NULL) {
        fclose(inFile);
        return EXIT_FAILURE;
    }

    // Initialise the head of an empty linked list.
    node_t *head = NULL;

    // Skip the first line of the .csv file.
    char line[MAX_LINE_LEN];
    fgets(line, sizeof(line), inFile);

    // Loop through the lines in the .csv file. 
    while (fgets(line, sizeof(line), inFile)) {
        suburb_t *suburbPtr = readSuburb(line);
        // Add the suburb_t pointer to the linked list.
        appendNode(&head, suburbPtr);
    }
    assert(head!= NULL);
    printList(head);

    // REMEMBER TO FREE EVERYTHING IN THE END + CLOSE THE FILES.

    freeList(head);

}