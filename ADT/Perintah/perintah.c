#include "perintah.h"
#include <stdio.h>
<<<<<<< Updated upstream
=======
#include "perintah.h"
>>>>>>> Stashed changes
#include <stdlib.h>
#include "../Mesin Karakter/charmachine.c"



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
    if (user) {
        printf(">> ");
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

char* concatString(char* s1, char* s2) {
    static char s3[300];
    int i = 0;
    int j = 0;
    while (s1[i] != '\0') {
        s3[i] = s1[i];
        i++;
    }
    while (s2[j] != '\0') {
        s3[i] = s2[j];
        i++;
        j++;
    }
    s3[i] = '\0';
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
    s.Length--;
    return s;
}

boolean isBlanks(Word s) {
    int i = 0;
    boolean check = true;

    while (i < s.Length && check) {
        if (s.TabWord[i] != ' ') {
            check = false;
        }
        i++;
    }
    return check;
}

Word sliceWord(Word str, int start, int end) {
    Word newWord;
    int i = 0;
    while (i < end - start) {
        newWord.TabWord[i] = str.TabWord[start + i];
        i++;
    }
    newWord.Length = i;
    return newWord;
}

void StringToWord(char* str, Word* w) {
    int i = 0;
    while (str[i] != '\0') {
        w->TabWord[i] = str[i];
        i++;
    }
    w->Length = i;
}

int WordToInt(Word w) {
    int i = 0;
    int result = 0;
    boolean isNegative = false;

    if (w.TabWord[0] == '-') {
        isNegative = true;
        i++;
    }

    while (i < w.Length) {
        result = result * 10 + (w.TabWord[i] - '0');
        i++;
    }

    if (isNegative) {
        result = -result;
    }

    return result;
}

<<<<<<< Updated upstream
=======
char* WordToString(Word w) {
    static char s[300];
    int i = 0;
    while (i < w.Length) {
        s[i] = w.TabWord[i];
        i++;
    }
    s[i] = '\0';
    return s;
}

>>>>>>> Stashed changes
boolean isSame(Word w1, Word w2) {
    boolean check = (w1.Length == w2.Length);
    if (check) {
        int i = 0;
        while (w1.TabWord[i] != '\0' && check) {
            if (w1.TabWord[i] != w2.TabWord[i]) {
                check = false;
            }
            i++;
        }
    }
    return check;
}

void splitWord(Word w, Word* w1, Word* w2) {
    int i = 0;
    while (w.TabWord[i] != ' ') {
        w1->TabWord[i] = w.TabWord[i];
        i++;
    }
    w1->Length = i;
    i++;
    int j = 0;
    while (i < w.Length) {
        w2->TabWord[j] = w.TabWord[i];
        i++;
        j++;
    }
    w2->Length = j;
}

void splitWordBackward(Word w, Word* w1, Word* w2) {
    int i = w.Length - 1;
    while (w.TabWord[i] != ' ') {
        // w1->TabWord[i] = w.TabWord[i];
        i--;
    }

    int j = 0;
    while (j < i) {
        w1->TabWord[j] = w.TabWord[j];
        j++;
    }
    w1->Length = i;

    i++;

    j = 0;
    w2->Length = w.Length - i;
    while (i < w.Length) {
        w2->TabWord[j] = w.TabWord[i];
        i++;
        j++;
    }
}

void split3Word(Word w, Word* w1, Word* w2, Word* w3) {
    int i = 0;
    while (w.TabWord[i] != ' ') {
        w1->TabWord[i] = w.TabWord[i];
        i++;
    }
    w1->Length = i;
    i++;
    int j = 0;
    while (w.TabWord[i] != ' ') {
        w2->TabWord[j] = w.TabWord[i];
        i++;
        j++;
    }
    w2->Length = j;
    i++;
    j = 0;
    while (i < w.Length) {
        w3->TabWord[j] = w.TabWord[i];
        i++;
        j++;
    }
    w3->Length = j;
}
