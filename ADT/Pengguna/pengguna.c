#include "pengguna.h"
#include "../Matrix/matrix.c"
#include "../Mesin Kata/wordmachine.c"
#include "../Mesin Karakter/charmachine.c"
#include <stdio.h>

/* *** Kreator *** */
void CreatePengguna(Pengguna* p) {
    int i;
    Word empty;
    for (i = 0; i < NMax; i++) {
        empty.TabWord[i] = '\0';
    }
    empty.Length = 0;
    NAMA(*p) = empty;
    PASSWORD(*p) = empty;
    BIO(*p) = empty;
    HP(*p) = empty;
    WETON(*p) = empty;
    JENIS(*p) = empty;
    createMatrix(5, 10, &PROFIL(*p));
    for (i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j = j + 2) {
            ELMT(PROFIL(*p), i, j) = 'R';
            ELMT(PROFIL(*p), i, j + 1) = '*';
        }
    }
}
/* I.S. sembarang */
/* F.S. Sebuah p kosong terbentuk dengan isi masing-masing berupa Word kosong dan profil berupa matriks
   kosong yang berisi R dan * */

void ReadPengguna(Pengguna* p) {
    CreatePengguna(p);
    STARTWORD();
    NAMA(*p) = currentWord;
    ADVWORD();
    PASSWORD(*p) = currentWord;
    ADVWORD();
    BIO(*p) = currentWord;
    ADVWORD();
    HP(*p) = currentWord;
    ADVWORD();
    WETON(*p) = currentWord;
    ADVWORD();
    JENIS(*p) = currentWord;
}
/* I.S. sembarang */
/* F.S. Sebuah p terbentuk dengan isi masing-masing berupa Word yang diakuisisi
   dari stdin */

   /* *** Display Pengguna *** */
void displayPengguna(Pengguna p) {
    printf("Nama: ");
    for (int i = 0; i < NAMA(p).Length; i++) {
        printf("%c", NAMA(p).TabWord[i]);
    }
    printf("\n");
    printf("Password: ");
    for (int i = 0; i < PASSWORD(p).Length; i++) {
        printf("%c", PASSWORD(p).TabWord[i]);
    }
    printf("\n");
    printf("Bio: ");
    for (int i = 0; i < BIO(p).Length; i++) {
        printf("%c", BIO(p).TabWord[i]);
    }
    printf("\n");
    printf("HP: ");
    for (int i = 0; i < HP(p).Length; i++) {
        printf("%c", HP(p).TabWord[i]);
    }
    printf("\n");
    printf("Weton: ");
    for (int i = 0; i < WETON(p).Length; i++) {
        printf("%c", WETON(p).TabWord[i]);
    }
    printf("\n");
    printf("Jenis: ");
    for (int i = 0; i < JENIS(p).Length; i++) {
        printf("%c", JENIS(p).TabWord[i]);
    }
    printf("\n");
    printf("Profil: \n");
    displayMatrixChar(PROFIL(p));
}
/* Proses : Informasi pengguna ditulis satu persatu dan diakhiri dengan newline */