// Wayne Mack
// wamj283@gmail.com
// (443) 627-1117

/* encode.c */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include "codec.h"

int main (int argc, char** argv) {
    if (argc < 2) {
        directAccessErrorMessage(1);
        return 1;
    }
    int opt;
    while ((opt = getopt( argc, argv, "fht" )) != -1) {
    
            switch (opt) {
                case 'f': /* FILE READ AND CREATION OPTION */
                    if (argc == 3) {
                        fileOption( argv[2], "none", 0);
                    } else if (argc >= 4) {
                        fileOption (argv[2], argv[3], 0);
                    } else {
                        fileOption("none","none", 0);
                    }
                    break;
                case 't': /* READ AND TRANSLATE TEXT */
      	            textOption(argc, argv, 0);
      	            break;
                case 'h': /* HELP OPTION*/
                    helpOption();
                    break;
                default: /* AT THIS POINT THE OPTION IS INVALID */
                    directAccessErrorMessage(1);
                    return 0;
            }
        }
}

