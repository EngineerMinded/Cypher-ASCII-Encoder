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

// TODO: MAKE SURE THIS IS EXCLUSIVELY A DIRECT FROM MENU PROGRAM (NO MORE AUTOMATED ACCESS). UPDATE HELP MENU


// SYSTEM HEADER FILES 
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h> // for malloc
// CUSTOM HEADER FILES
#include "codec.h"

void program_title();
void userMenu();
void userInputOption();

int main(int argc, char **argv) {
    userMenu();
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




void userMenu () {
    program_title();
    printf ("\n\nMain Menu:"  
            "\n\n(1) Manually enter code to be encoded."
            "\n\n(2) Manually enter code to be decoded."
            "\n\n(3) Enter a file to be encoded."
            "\n\n(4) Enter a file to be decoded."
            "\n\n(5) Help on direct commands from console." 
            "\n\n(0) Quit. ");
    int option;
    scanf("%d", &option);
    if (option == 1) {
         userInputOption(0);
    }
    else if (option == 2) {
        userInputOption(1);
    }
    else if (option == 3) {
        fileOption("none","none",0);
    }
    else if (option == 4) {
        fileOption("none", "none", 1);

    }else if (option == 5) {
        helpOption();
    } else {
        // nothing  
    }
}

// FOR ALLOWING USER INPUT
void userInputOption (int encodeOrDecode) {
    char input[150];
        printf ("Input code you would like to translate : \n");
        scanf(" %149[0-9a-zA-Z /,.!-_?&:;]", input);
        char *output = codeString(input, encodeOrDecode);
        printf ("\n\n%s\n\n", output);
        printf("\n\nEnd of Translation!");
}

