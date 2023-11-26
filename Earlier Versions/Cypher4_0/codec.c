// encode.c

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include "codec.h"

#define NUMBER_OF_CODES 4

char codeCharacter (char c, int codeKeyNumber, int codeOrDecode) {
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
                if (c == key[x] && codeOrDecode == 0) {
                    fclose(codekey);
                    return encrypt[x];
                }
                else if (c == encrypt[x] && codeOrDecode == 1) {
                    fclose(codekey);
                    return key[x];
                }
            }
        }
    }

    fclose(codekey);
    return c;
}

// Function to invert a string


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
    printf ("opening %s, writing to %s", inputFileName, outputFileName);
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

char decodeCharacter (char c, int codeKeyNumber, int zeroCodeOneDecode) {
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
                if (c == encrypt[x]) {
                      fclose(codekey);
                      return key[x];
                }
            }
        }
    }

    fclose(codekey);
    return c;
}

char* codeString(const char* input, int encodeOrDecode) {
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