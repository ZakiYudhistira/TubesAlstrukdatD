/* File: perintah.h */
/* Definisi Perintah (input mesin kata) */

#ifndef PERINTAH_H
#define PERINTAH_H

#include "../boolean.h"

void simpanword();

char* perintah();

int lengthString (char *s);

boolean isValid(char *s, char *valid);

char* concatString(char* s1, char* s2);

#endif