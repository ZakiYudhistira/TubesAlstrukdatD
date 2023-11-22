/* File: perintah.h */
/* Definisi Perintah (input mesin kata) */

#ifndef PERINTAH_H
#define PERINTAH_H

#include "../boolean.h"
#include "wordmachine.h"

void IgnoreBlanks();

void STARTWORD();

void ADVWORD();

void CopyWord();

//bedanya dengan copyword pada persyaratan looping, jadi boleh ada BLANK atau SPASI//
void simpanword(int max);

void perintah(int max, boolean user);

void printWord(Word word);

int lengthString(char* s);

boolean isValid(Word s, char* valid);

const char* concatString(char* s1, char* s2);

void CopyString(char* st1, char* st2);

Word removeNewline(Word s);

boolean isBlanks(Word s);

Word sliceWord(Word str, int start, int end);

void StringToWord(char* str, Word* w);

int WordToInt(Word w);

boolean isSame(Word w1, Word w2);

void splitWord(Word w, Word* w1, Word* w2);

void splitWordBackward(Word w, Word* w1, Word* w2);

void split3Word(Word w, Word* w1, Word* w2, Word* w3);

#endif