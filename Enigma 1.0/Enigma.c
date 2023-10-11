// Wayne Mack
// 6425 ******* ****** ****
// G*** ******, MD 2****
// (443) - *** - ****

/////////////////////////////////////////////////
// Enigma: Message Encoder and Decoder         //
// Written in: C (GCC [MACOS/LINUX])           //
// DON'T TAKE THIS PROGRAM SERIOUS. IT IS JUST //
// A CHALLENGE EXERCISE. I JUST WANT TO BUILD  //
// SOMETHING IN RAW C.                         //
/////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* PROGRAM TITLE : USED ONCE AND WHEN PROGRAM IS EXECUTED WITH NO ARGUMENTS */
void program_title () {
    printf("\e[1;1H\e[2J"); // Clear screen
    printf("    ______      _                      \n");
    printf("   / ____/___  (_)___ _____ ___  ____ _\n");
    printf("  / __/ / __ \\/ / __ `/ __ `__ \\/ __ `/\n");
    printf(" / /___/ / / / / /_/ / / / / / / /_/ / \n");
    printf("/_____/_/ /_/_/\\__, /_/ /_/ /_/\\__,_/  \n");
    printf("              /____/                   \n");
    printf("\nVersion 1.0\n");
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

int main(int argc, char **argv) {
    if (argc < 2) { // If there are No arguments, Ask for input
        program_title();
        char input[150];
        printf ("Input code you would like to translate : ");
        scanf("%149[0-9a-zA-Z ]", input);
        char *output = invertString(input);
        printf ("\n\n%s\n\n", output);
        return 0;
    } else {
        char *new_code[argc];
        for (int z = 1; z < argc; z++) {
            new_code[z] = invertString(argv[z]);
            printf("%s ", new_code[z]);
        }
        printf("\n\n");
        return 0;
}
    }
    //program_title();
    