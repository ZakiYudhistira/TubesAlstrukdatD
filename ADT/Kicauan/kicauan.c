#include "kicauan.h"
#include "../Mesin Kata/wordmachine.c"
#include "../Mesin Karakter/charmachine.c"
#include <stdio.h>

/* *** Kreator *** */
void CreateKicauan(Kicauan* k) {
    int i;
    Word empty;
    for (i = 0; i < NMax; i++) {
        empty.TabWord[i] = '\0';
    }
    empty.Length = 0;

    ID(*k) = 0;
    TEXT(*k) = empty;
    LIKE(*k) = 0;
    AUTHOR(*k) = empty;
    DATETIME(*k) = time(NULL);
}
/* I.S. sembarang */
/* F.S. Sebuah k kosong dan datetime now*/

void ReadKicauan(Kicauan* k) {
    CreateKicauan(k);
    STARTWORD();
    ID(*k) = 0;
    TEXT(*k) = currentWord;
    ADVWORD();
    LIKE(*k) = 0;
    AUTHOR(*k) = currentWord;
    ADVWORD();
    DATETIME(*k) = time(NULL);
}
/* I.S. sembarang */
/* F.S. Sebuah k terbentuk dengan isi masing-masing berupa Word dan int yang diakuisisi
   dari stdin */

const char* TimeToString(time_t t) {
    struct tm tm;
    localtime_r(&t, &tm);
    static char buf[20];
    strftime(buf, sizeof(buf), "%d-%m-%Y %H:%M:%S", &tm);
    return buf;
}


time_t StringToTime(const char* str) {
    struct tm tm;
    strptime(str, "%d-%m-%Y %H:%M:%S", &tm);
    return mktime(&tm);
}

/* *** Display Pengguna *** */
void displayKicauan(Kicauan k) {
    printf("ID: ");
    printf("%d\n", ID(k));
    printf("Text: ");
    for (int i = 0; i < TEXT(k).Length; i++) {
        printf("%c", TEXT(k).TabWord[i]);
    }
    printf("\n");
    printf("Like: ");
    printf("%d\n", LIKE(k));
    printf("Author: ");
    for (int i = 0; i < AUTHOR(k).Length; i++) {
        printf("%c", AUTHOR(k).TabWord[i]);
    }
    printf("\n");

    printf("Datetime: %s\n", TimeToString(DATETIME(k)));
}
/* Proses : Menuliskan isi Kicauan dengan traversal. Informasi kicauan
   ditulis satu persatu dan diakhiri dengan newline */