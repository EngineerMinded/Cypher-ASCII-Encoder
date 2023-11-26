// CYPHER PROGRAM
// Code key file for encoding and decoding for version 5.0 and up


/* Codekey.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "codekey.h"



int offset = 0;


char getNewCharacter (char input, int oneForDecode) {
    
    int value = getValue(input); 

    // IF VALID LETTER
    if (value < 0) {
        return input;
    } 
    
    offset++;
    if (offset >= 53) {
        offset = 1;
    }
    //printf ("offset: %d\nmake", offset);
    int newValue = value - offset;
    if (oneForDecode == 0) {
        newValue = value + offset;
    } 
    while (newValue > 53) {
        newValue = newValue - 53;
    }
    while (newValue < 0) {
        newValue = newValue + 53;
    }
    return CODE_KEY[newValue];
}

int getValue (char letter) {
    for (int u = 0; u < 53; u++) {
        if (letter == CODE_KEY[u]) {
            return u;
        }
    }
    return -1;
}
