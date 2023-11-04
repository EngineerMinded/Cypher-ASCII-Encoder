// Wayne Mack
// wamj283@gmail.com
// (443) - 627 - 1117

/////////////////////////////////////////////////
// Cypher: Message Encoder and Decoder         //
// Written in: C (GCC [MACOS/LINUX])           //
// DON'T TAKE THIS PROGRAM SERIOUS. IT IS JUST //
// A CHALLENGE EXERCISE. I JUST WANT TO BUILD  //
// SOMETHING IN RAW C.                         //
/////////////////////////////////////////////////

/*
    Change log:
    1.0 initial testing with input from command line
    1.5 Beta with unfinished menu
    2.0 Reads and generate files that are encrypted
    2.5 Reads a key from another file to allow multiple cyphers, included stdlib.h to clean up all warnings
*/

 
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h> // for malloc

void program_title();
char codeCharacter(char, int, int);
char* codeString(const char*, char*);
void helpOption();
void userMenu();
void userInputOption();
void fileOption(char*, char*);
void textOption(int, char**);
void fileOption(char* ,  char* );
void againOption();
int determineCodeNumber(char *fileName);

int main(int argc, char **argv) {

    int opt; // for option flag
    if (argc < 2) { // If there are No arguments, Ask for input
        userMenu();
   
    } else {
        while ((opt = getopt( argc, argv, "fht" )) != -1) {
    
            switch (opt) {
                case 'f': /* FILE READ AND CREATION OPTION */
                    if (argc == 3) {
                        fileOption( argv[2], "none");
                    } else if (argc >= 4) {
                        fileOption (argv[2], argv[3]);
                    } else {
                        fileOption("none","none");
                    }
                    break;
                case 't': /* READ AND TRANSLATE TEXT */
      	            textOption(argc, argv);
      	            break;
                case 'h': /* HELP OPTION*/
                    helpOption();
                    break;
                default: /* AT THIS POINT THE OPTION IS INVALID */
                    userMenu();
                    return 0;
            }
        }
    }
    return 0;
}

/* PROGRAM TITLE : USED ONCE AND WHEN PROGRAM IS EXECUTED WITH NO ARGUMENTS */
void program_title () {
    printf("\e[1;1H\e[2J"); // Clear screen
    printf("   ___        ___        __  __  \n");
    printf("  / __\\/\\_/\\ / _ \\/\\  /\\/__\\/__\\ \n");
    printf(" / /   \\_ _// /_)/ /_/ /_\\ / \\// \n");
    printf("/ /___  / \\/ ___/ __  //__/ _  \\ \n");
    printf("\\____/  \\_/\\/   \\/ /_/\\__/\\/ \\_/ \n\n");
    printf("\nVersion 2.5 (BETA)\n");
    printf("\n\nSimple ASCII encoder and encoder\nWayne Mack.\n\n\n"); 
}

// Function to invert a single character
char codeCharacter (char c, int codeKeyNumber, int zeroCodeOneDecode) {
    // access file code.key
    char newChar;
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
        inverted[i] = codeCharacter(input[i],determineCodeNumber(filename),0); // Invert each character
    }
    inverted[length] = '\0'; // Null-terminate the inverted string

    return inverted;
}

void helpOption () {
    printf ("Welcome to Cypher!\n"
            "---------------------------\n"
            "Cypher is a simple encoder of decoder.\n"
            "For conveince of automated tasks, flags along\n"
            "with variables can be used for conveince. \n\n"
            "./Cypher -h                              : Help menu\n"
            "./Cypher -f                              : Read and write file.\n"
            "./Cypher -f  <filename>                  : Read from filename, will ask what file to write to.\n"
            "./Cypher -f  <filename> <outputfilename> : Reads from file and writes to new file with given name.\n"
            "./Cypher -t                              : Asks what text to input and output is coded text.\n"
            "./Cypher -t  <text>                      : Outputs the text or sentence that is in input\n\n."

            );
}

void userMenu () {
    program_title();
    printf ("\n\nMain Menu:"  
            "\n\n(1) Enter code to be translated."
            "\n\n(2) Read from file and write to file."
            "\n\n(3) Help"
            "\n\n(0) Quit. ");
    int option;
    scanf("%d", &option);
    if (option == 1) {
        userInputOption(); 
    }
    else if (option == 2) {
        fileOption("none","none"); 
    }
    else if (option == 3) {
        helpOption();  
    }
    else {
        // nothing  
    }
}

// FOR ALLOWING USER INPUT
void userInputOption () {
    char input[150];
        printf ("Input code you would like to translate : \n");
        scanf(" %149[0-9a-zA-Z /,.!-_?&:;]", input);
        char *output = codeString(input);
        printf ("\n\n%s\n\n", output);
        printf("HERE!");
        againOption();
}

// OPTION FOR TRANSLATING TEXT FROM FILE
void fileOption(char* inputFileName , char* outputFileName) {
    
    if (inputFileName == "none") {
        inputFileName = malloc(50);
        printf("\nEnter the name of the file you want to open! :");
        scanf ("%s", inputFileName);
    }
    if (outputFileName == "none") {
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
        fputc(codeCharacter(c,determineCodeNumber(inputFile),0), outputFile);
    }

    // Close the input and output files
    fclose(inputFile);
    fclose(outputFile);
}

// FOR TEXT THAT HAS ALREADY BEEN INPUTTED AT COMMAND LINE
void textOption (int argc, char **argv ) {
    
    char *new_code[argc];
        for (int z = 2; z < argc; z++) {
            new_code[z] = codeString(argv[z]);
            printf("%s ", new_code[z]);
        }
        printf("\n\n");
}

// ASKING THE USER IF THEY WOULD LIKE TO MAKE ANOTHER OPTION
void againOption () {
    return;
}  

int determineCodeNumber (char *fileName) {
    return 8;
}