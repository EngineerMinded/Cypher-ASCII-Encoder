// CYPHER PROGRAM
// Header File for Codec program

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