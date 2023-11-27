// CYPHER PROGRAM
// Encoding program central to encoding and decoding

// encode.c

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include "codec.h"
#include "linkedlist.h"
#include "codekey.h"

#define NUMBER_OF_CODES 4

// NEW CODE CHARACTER FUNCTION FOR VERSION 5.0 AND ABOVE IS FUNCTIONAL CALL FOR 
// GETNEWCHARACTER FUNCTION IN CODEKEY.C

char codeCharacter (char c, int codeKeyNumber, int codeOrDecode) {
    // codeKeyNumber is deprecated
    return  getNewCharacter(c, codeOrDecode);
}

// File Option
void fileOption(char* inputFileName , char* outputFileName, int encodeOrDecode) {
    
    if (strcmp(inputFileName,"none") == 0){
        inputFileName = malloc(50);
        printf("\nEnter the name of the file you want to open! :");
        scanf ("%s", inputFileName);
    }
    if (strcmp(outputFileName,"none") == 0){
        outputFileName = malloc(50);
        printf("\nEnter the name of the file you want to create! :");
        scanf ("%s", outputFileName);
    }
    printf ("opening %s, writing to %s/n/n", inputFileName, outputFileName);
    // Open the input file for reading
    FILE* inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        return;
    }

    // Open the output file for writing
    FILE* outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);
        return;
    }

    // Copy data from the input file to the output file
    int c;
    while ((c = fgetc(inputFile) ) != EOF) {
        fputc(codeCharacter(c,8,encodeOrDecode), outputFile);
    }

    // Close the input and output files
    fclose(inputFile);
    fclose(outputFile);
    printf ("Work is complete . . . \n\n");
}

// textOption
void textOption (int argc, char **argv , int encodeOrDecode) {
    
    char *new_code[argc];
        for (int z = 2; z < argc; z++) {
            new_code[z] = codeString(argv[z], encodeOrDecode);
            printf("%s ", new_code[z]);
        }
        printf("\n\n");
}

// FUNCTION FOR ENCODING AND DECODING STRINGS IN FILES
char* codeString(const char* input, int encodeOrDecode) {
    size_t length = strlen(input);
    char* inverted = malloc(length + 1); // Allocate memory for the inverted string
    if (inverted == NULL) {
        return NULL; // Memory allocation failed
    }

    for (size_t i = 0; i < length; i++) {
        inverted[i] = codeCharacter(input[i],8,encodeOrDecode); // Invert each character
    }
    inverted[length] = '\0'; // Null-terminate the inverted string

    return inverted;
}

// DIRECT ACCESS ERROR MESSAGE
void directAccessErrorMessage(int encodeOrDecode) {
    char *progType = "encode";
    if (encodeOrDecode == 1) {
        progType = "decode";
    }
    printf("Error, no arguments used for %s function. \n", progType);
    printf("see ./cypher -h for direct access parameters.");
    
}

void helpOption () {
    printf ("Welcome to Cypher!\n"
            "---------------------------\n"
            "Cypher is a simple encoder of decoder.\n"
            "Automated execution can be achieve by using\n"
            "commands along with the following criterias \n\n"
            "\n\nencode - encodes text and files"
            "\n\ndecode - decodes text and files "
            "\n\n Use these commands with the flags below."
            "./prog -h                              : Help menu\n"
            "./<command> -f                              : Read and write file.\n"
            "./<command> -f  <filename>                  : Read from filename, will ask what file to write to.\n"
            "./<command> -f  <filename> <outputfilename> : Reads from file and writes to new file with given name.\n"
            "./<command> -t                              : Asks what text to input and output is coded text.\n"
            "./<command> -t  <text>                      : Outputs the text or sentence that is in input\n\n."

            );
}