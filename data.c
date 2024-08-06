#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"

// Parse the given .csv line into a suburb_t struct.
suburb_t *readSuburb(char *line) {
    suburb_t *suburb = (suburb_t *)malloc(sizeof(suburb_t));
    char *token;

    // Get "COMP20003 code" value from line => integer
    token = strtok(line, ",");
    suburb->code = atoi(token);

    // Get "Official Code Suburb" value from line => integer
    token = strtok(NULL, ",");
    suburb->id = atoi(token);

    // Get "Official Name Suburb" value from line => string
    token = strtok(NULL, ",");
    suburb->name = (char *)malloc(strlen(token) + 1);
    strcpy(suburb->name, token);

    // Get "Year" value from line => int
    token = strtok(NULL, ",");
    suburb->year = atoi(token);

    // Get "Official Code State" value(s) from line => string
    char *nextChar = token + strlen(token) + 1;
    if (*nextChar == '\"') {
        token = strtok(NULL, "\"");
    } else {
        token = strtok(NULL, ",");
    }
    suburb->stateIDs = malloc(strlen(token) + 1);
    strcpy(suburb->stateIDs, token);

    // Get "Official Name State" value(s) from line => string.
    nextChar = token + strlen(token) + 1;
    if (*nextChar == '\"') {
        token = strtok(NULL, "\"");       
    } else {
        token = strtok(NULL, ",");
    }
    suburb->stateNames = malloc(strlen(token) + 1);
    strcpy(suburb->stateNames, token);

    // Get "Official Code Local Government Area" value(s) from line => string.
    nextChar = token + strlen(token) + 1;
    if (*nextChar == '\"') {
        token = strtok(NULL, "\"");
        nextChar = token + strlen(token) + 2;
    } else {
        token = strtok(NULL, ",");
        nextChar = token + strlen(token) + 1;
    }
    suburb->governmentIDs = malloc(strlen(token) + 1);
    strcpy(suburb->governmentIDs, token);

    // Get "Official Name Local Government Area" value(s) from line => string.
    
    
    // problem is that strtok reads till the end of the list of numbers => next char is the closing quote.
    // it then satisfies the condition, so the next token would be the comma in between the quote marks.

    // this currently solves it but should really try to shift nextChar over the comma to run the loop again...
    if (*nextChar == '\"') {
        printf("token = %s\n", token);
        token = strtok(NULL, "\""); // token here will be the comma between the two speech marks
        printf("token = %s\n", token); // ITS A COMMA
        token = strtok(NULL, "\""); // call strtok again to read to next quotation mark, which will be the government names
        printf("token = %s\n", token);
    } else {
        token = strtok(NULL, ",");
    }
    suburb->governmentNames = malloc(strlen(token) + 1);
    strcpy(suburb->governmentNames, token);

    // Get "Latitude" value from line => double.
    token = strtok(NULL, ",");
    suburb->latitude = atof(token);

    // Get "Longitude" value from line => double.
    token = strtok(NULL, ",");
    suburb->longitude = atof(token);
    
    printf("suburb = %d %d %s %d %s %s %s %s %lf %lf\n\n", suburb->code, suburb->id, suburb->name, suburb->year, suburb->stateIDs, suburb->stateNames, suburb->governmentIDs, suburb->governmentNames, suburb->latitude, suburb->longitude);

    return suburb;
}