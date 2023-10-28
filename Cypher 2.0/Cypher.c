// Wayne Mack
// 6425 ******* ****** ****
// G*** ******, MD 2****
// (443) - *** - ****

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
*/

 
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

void program_title();
char invertCharacter(char);
char* invertString(const char*);
void helpOption();
void userMenu();
void userInputOption();
void fileOption(char*, char*);
void textOption(int, char**);
void fileOption(char* ,  char* );

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
    printf("\nVersion 2.0\n");
    printf("\n\nSimple ASCII encoder and encoder\nWayne Mack.\n\n\n"); 
}

// Function to invert a single character
char invertCharacter(char c) {
    char f;
    if (isalpha(c)) {
        if (c > 64 && c < 97) {                // char c is uppercase
            if (c < 78) {                      // char c is 'M' or lower
                f = (77 + (78 - c));
            } else {                           // char is 'N' or higher
                f = (78 - (c - 77));
            }
        } else {                               // char c is lowercase
            if (c < 110) {                     // char c is 'm' or lower
                f = (109 + (110 - c));
            } else {                           // char is 'n' or higher
                f = (110 - (c - 109));
            }
        }
        return f;                              // return the newly encoded letter
    }
    return c;                                  // At this point, it is not a letter. Return as is
}

// Function to invert a string
char* invertString(const char* input) {
    size_t length = strlen(input);
    char* inverted = malloc(length + 1); // Allocate memory for the inverted string
    if (inverted == NULL) {
        return NULL; // Memory allocation failed
    }

    for (size_t i = 0; i < length; i++) {
        inverted[i] = invertCharacter(input[i]); // Invert each character
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
            );
}

void userMenu () {
    program_title();
    printf ("\n\nMain Menu:"  
            "\n\n(1) Enter code to be translated."
            "\n\n(2) Read from file and write to file. (Coming Soon)"
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
        char *output = invertString(input);
        printf ("\n\n%s\n\n", output);
        printf("HERE!");
        againOption();
}

// OPTION FOR TRANSLATING TEXT FROM FILE
void fileOption(char* inputFileName , char* outputFileName) {
    printf ("%s, %s", inputFileName, outputFileName);
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
        fputc(invertCharacter(c), outputFile);
    }

    // Close the input and output files
    fclose(inputFile);
    fclose(outputFile);
}

// FOR TEXT THAT HAS ALREADY BEEN INPUTTED AT COMMAND LINE
void textOption (int argc, char **argv ) {
    
    char *new_code[argc];
        for (int z = 2; z < argc; z++) {
            new_code[z] = invertString(argv[z]);
            printf("%s ", new_code[z]);
        }
        printf("\n\n");
}

// ASKING THE USER IF THEY WOULD LIKE TO MAKE ANOTHER OPTION
void againOption () {
    return;
}    