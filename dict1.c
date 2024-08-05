#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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
    

}