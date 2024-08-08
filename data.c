/* Builds the suburb_t struct from the .csv data. */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
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
    assert(suburb->name);
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
    assert(suburb->stateIDs);
    strcpy(suburb->stateIDs, token);

    // Get "Official Name State" value(s) from line => string.
    nextChar = token + strlen(token) + 1;
    if (*nextChar == '\"') {
        token = strtok(NULL, "\"");       
    } else {
        token = strtok(NULL, ",");
    }
    suburb->stateNames = malloc(strlen(token) + 1);
    assert(suburb->stateNames);
    strcpy(suburb->stateNames, token);

    // Get "Official Code Local Government Area" value(s) from line => string.
    nextChar = token + strlen(token) + 1;
    if (*nextChar == '\"') {
        token = strtok(NULL, "\"");
    } else {
        token = strtok(NULL, ",");
    }
    suburb->governmentIDs = malloc(strlen(token) + 1);
    assert(suburb->governmentIDs);
    strcpy(suburb->governmentIDs, token);

    // Get "Official Name Local Government Area" value(s) from line => string.
    if (*nextChar == '\"') {
        token = strtok(NULL, "\""); 
        token = strtok(NULL, "\""); 
    } else {
        token = strtok(NULL, ",");
    }
    suburb->governmentNames = malloc(strlen(token) + 1);
    assert(suburb->governmentNames);
    strcpy(suburb->governmentNames, token);

    // Get "Latitude" value from line => double.
    token = strtok(NULL, ",");
    suburb->latitude = atof(token);

    // Get "Longitude" value from line => double.
    token = strtok(NULL, ",");
    suburb->longitude = atof(token);
    
    // printf("suburb = %d %d %s %d %s %s %s %s %lf %lf\n", suburb->code, suburb->id, suburb->name, suburb->year, suburb->stateIDs, suburb->stateNames, suburb->governmentIDs, suburb->governmentNames, suburb->latitude, suburb->longitude);

    return suburb;
}