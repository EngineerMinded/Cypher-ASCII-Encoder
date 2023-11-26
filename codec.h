// Wayne Mack
// wamj283@gmail.com
// (443) 627-1117


/* codec.h */

#ifndef CODEC_H
#define CODEC_H

char codeCharacter (char, int, int );
char* codeString(const char*, int );
void directAccessErrorMessage(int );
void textOption(int, char**, int);
void fileOption(char* ,  char* , int);
void helpOption();



#endif