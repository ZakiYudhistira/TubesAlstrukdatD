#include "kicauan.h"
#include "../Mesin Kata/wordmachine.h"
#include "../Mesin Karakter/charmachine.h"
#include "../Perintah/perintah.c"
#include <stdio.h>

/* *** Kreator *** */
void CreateKicauan(Kicauan* k) {
    ID(*k) = 0;
    TEXT(*k) = NULL;
    LIKE(*k) = 0;
    AUTHOR(*k) = NULL;
    DATETIME(*k) = time(NULL);
}
/* I.S. sembarang */
/* F.S. Sebuah k kosong dan datetime now*/

void ReadKicauan(Kicauan* k) {
    CreateKicauan(k);
    printf("ID: ");
    scanf("%d", &ID(*k));
    printf("Text: ");
    scanf("%s", TEXT(*k));
    printf("Like: ");
    scanf("%d", &LIKE(*k));
    printf("Author: ");
    scanf("%s", AUTHOR(*k));
    printf("Datetime: ");
    scanf("%s", TimeToString(DATETIME(*k)));
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
    // printf("ID: ");
    // printf("%d\n", ID(k));
    // printf("Text: ");
    // for (int i = 0; i < TEXT(k).Length; i++) {
    //     printf("%c", TEXT(k).TabWord[i]);
    // }
    // printf("\n");
    // printf("Like: ");
    // printf("%d\n", LIKE(k));
    // printf("Author: ");
    // for (int i = 0; i < AUTHOR(k).Length; i++) {
    //     printf("%c", AUTHOR(k).TabWord[i]);
    // }
    // printf("\n");

    printf("Datetime: %s\n", TimeToString(DATETIME(k)));
}
/* Proses : Menuliskan isi Kicauan dengan traversal. Informasi kicauan
   ditulis satu persatu dan diakhiri dengan newline */