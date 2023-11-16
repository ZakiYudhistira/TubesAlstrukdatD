/* File: perintah.h */
/* Definisi Perintah (input mesin kata) */

#ifndef PERINTAH_H
#define PERINTAH_H

#include "../boolean.h"

void simpanword();

char* perintah();

int lengthString(char* s);

boolean isValid(char* s, char* valid);

const char* concatString(char* s1, char* s2);

void CopyString(char* st1, char* st2);

char* removeNewline(char* s);

boolean isBlanks(char* s);

char* sliceString(char* str, int start, int end);

#endif