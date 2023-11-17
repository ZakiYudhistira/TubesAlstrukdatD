#include "../Mesin Karakter/charmachine.c"
#include <stdio.h>
#include <stdlib.h>
#include "wordmachine.h"

boolean EndWord;
Word currentWord;

void IgnoreBlanks()
{
    /* Mengabaikan satu atau beberapa BLANK
       I.S. : currentChar sembarang
       F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    while (currentChar == BLANK)
    {
        ADV();
    }
}

void STARTWORD()
{
    /* I.S. : currentChar sembarang
       F.S. : EndWord = true, dan currentChar = MARK;
              atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
              currentChar karakter pertama sesudah karakter terakhir kata */
    START();
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWord();
    }
}

void ADVWORD()
{
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
       F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
              currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
              Jika currentChar = MARK, EndWord = true.
       Proses : Akuisisi kata menggunakan procedure CopyWord */
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWord();
        IgnoreBlanks();
    }
}

void CopyWord()
{
    /* Mengakuisisi kata, menyimpan dalam currentWord
       I.S. : currentChar adalah karakter pertama dari kata
       F.S. : currentWord berisi kata yang sudah diakuisisi;
              currentChar = BLANK atau currentChar = MARK;
              currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
              Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
    currentWord.Length = 0;
    while (currentChar != BLANK && currentChar != MARK)
    {
        if (currentWord.Length < NMax)
        { // jika lebih akan terpotong
            currentWord.TabWord[currentWord.Length++] = currentChar;
            ADV();
        }
        else
            break;
    }
}
//bedanya dengan copyword pada persyaratan looping, jadi boleh ada BLANK atau SPASI//
void simpanword(int max) {
    int i = 0;
    while ((currentChar != MARK) && i != max) {
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    currentWord.Length = (i < max) ? i : max;
}

void perintah(int max, boolean user) {
    // ini isinya sama kayak algoritma STARTWORD, cuman karena  pakainya simpanword() dan bukan copyword, jadi gw tulis ulang aja//
    if(user){
        printf(">>");
    }
    START();
    IgnoreBlanks();
    if (currentChar == MARK) {
        EndWord = true;
    }
    else {
        EndWord = false;
        simpanword(max); /*copyword() diganti, sama itu max buat kapasitas inputnya, jadi sebanyak apapun inputnya, bakal kepotong sesuai nilai int max*/
    }
}

void printWord(Word word) {
   int i;
   for (i = 0; i < word.Length; i++) {
      printf("%c", word.TabWord[i]);
   }
}

int lengthString(char* s) {
    int count = 0;
    int i = 0;

    while (s[i] != '\0') {
        ++count;
        ++i;
    }
    return count;
}

boolean isValid(Word s, char* valid) {
    boolean check = (s.Length == lengthString(valid));
    if (check) {
        int i = 0;
        while (valid[i] != '\0' && check) {
            if (s.TabWord[i] != valid[i]) {
                check = false;
            }
            i++;
        }
    }
    return check;
}

const char* concatString(char* s1, char* s2) {
    static char s3[300];
    int i = 0, j = 0;
    while (s1[i] != '\0') {
        s3[i] = s1[i];
        i++;
    }
    while (s2[j] != '\0') {
        s3[i] = s2[j];
        i++;
        j++;
    }

    return s3;
}

void CopyString(char* st1, char* st2)
{
    int i = 0;

    for (i = 0; st1[i] != '\0'; i++)
    {
        st2[i] = st1[i];
    }
    st2[i] = '\0';
}

Word removeNewline(Word s) {
    int i = 0;
    while (i < s.Length) {
        if (s.TabWord[i] == '\n') {
            s.TabWord[i] = '\0';
        }
        i++;
    }
    return s;
}

boolean isBlanks(Word s) {
    int i = 0;
    boolean check = true;

    while (i <s.Length && check) {
        if (s.TabWord[i] != ' ') {
            check = false;
        }
        i++;
    }
    return check;
}

char* sliceString(char* str, int start, int end)
{

    int i;
    int size = (end - start) + 2;
    char* output = (char*)malloc(size * sizeof(char));

    for (i = 0; start <= end; start++, i++)
    {
        output[i] = str[start];
    }

    output[size] = '\0';


    return output;
}