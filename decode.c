// CYPHER PROGRAM
// Direct execuatable from Console for decoding

/* decode.c */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include "codec.h"


int main (int argc, char** argv) {
    if (argc < 2) {
        directAccessErrorMessage(0);
        return 1;
    }
    int opt;
    while ((opt = getopt( argc, argv, "fht" )) != -1) {
    
            switch (opt) {
                case 'f': /* FILE READ AND CREATION OPTION */
                    if (argc == 3) {
                        fileOption( argv[2], "none", 1);
                    } else if (argc >= 4) {
                        fileOption (argv[2], argv[3], 1);
                    } else {
                        fileOption("none","none", 1);
                    }
                    break;
                case 't': /* READ AND TRANSLATE TEXT */
      	            textOption(argc, argv, 1);
      	            break;
                case 'h': /* HELP OPTION*/
                    helpOption();
                    break;
                default: /* AT THIS POINT THE OPTION IS INVALID */
                    directAccessErrorMessage(0);
                    return 0;
            }
        }
}


