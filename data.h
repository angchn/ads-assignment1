#ifndef _DATA_H_
#define _DATA_H_

// Constant definitions.
#define MAX_LINE_LEN 511

// Data definitions.
typedef struct suburb {
    int code;
    int id; 
    char *name;
    int year;
    char *stateIDs;
    char *stateNames;
    char *governmentIDs;
    char *governmentNames;
    double latitude;
    double longitude;
} suburb_t;

// Function definitions.
suburb_t *readSuburb(char *line);


#endif
