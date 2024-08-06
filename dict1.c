#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "data.h"

int main(int argc, char **argv) {
    // Process command line arguments.
    char *stageNum = argv[1];
    printf("%s\n", stageNum);
    
    FILE *inFile = fopen(argv[2], "r");
    if (inFile == NULL) {
        return EXIT_FAILURE;
    }

    FILE *outFile = fopen(argv[3], "w");
    if (outFile == NULL) {
        fclose(inFile);
        return EXIT_FAILURE;
    }

    // Skip the first line of the .csv file.
    char line[MAX_LINE_LEN];
    fgets(line, sizeof(line), inFile);


    while (fgets(line, sizeof(line), inFile)) {
        suburb_t *suburb_ptr = readSuburb(line);
    }

}