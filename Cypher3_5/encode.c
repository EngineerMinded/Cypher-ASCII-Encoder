// encode.c

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include "encode.h"

char codeCharacter (char c, int codeKeyNumber, int zeroCodeOneDecode) {
    // access file code.key
    FILE* codekey = fopen("code.key", "r");
    if (codekey == NULL) {
        printf("code.key file cannot be opened");
        return 1;
    }
    
    char  number[8], key[53], encrypt[53];

    while ((fscanf(codekey, "%s",number) == 1) && (fscanf(codekey, "%s", key) == 1) && (fscanf(codekey, "%s", encrypt) == 1)) {
        //printf(" %s %s %s\n", number, key, encrypt);
        if (codeKeyNumber == atoi(number)) {
            for (int x = 0; x < 52; x++) {
                if (c == key[x]) {
                      fclose(codekey);
                      return encrypt[x];
                }
            }
        }
    }

    fclose(codekey);
    return c;
}

// Function to invert a string
char* codeString(const char* input) {
    size_t length = strlen(input);
    char* inverted = malloc(length + 1); // Allocate memory for the inverted string
    if (inverted == NULL) {
        return NULL; // Memory allocation failed
    }

    for (size_t i = 0; i < length; i++) {
        inverted[i] = codeCharacter(input[i],8,0); // Invert each character
    }
    inverted[length] = '\0'; // Null-terminate the inverted string

    return inverted;
}