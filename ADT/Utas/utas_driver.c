#include "utas.h"
#include "../Draf/stackDraf.h"
#include "../Pengguna/pengguna.h"
#include "../Kicauan/kicauan.h"
#include "../Perintah/perintah.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    Utas U;
    ListDinUtas dbUtasUser;
    listStackDraf lsd;
    ListDinKicau l;
    databaseprofil db;
    Draf D;

    initListStackDraf(&lsd);
    initListDinUtas(&dbUtasUser);

    printf("Masukkan path file: ");
    perintah(50, 0);
    Word input = currentWord;
    ADV();

    LoadDraf(&lsd, input);

    printf("Masukkan nama User: ");
    perintah(50, 0);
    input = currentWord;
    ADV();
    DisplayDraf(input, lsd, &l, db);

    printf("Masukkan path file: ");
    perintah(50, 0);
    input = currentWord;
    ADV();

    LoadUtas(&dbUtasUser, input);

    printf("Masukkan idUtas: ");
    perintah(50, 0);
    int inputangka = WordToInt(currentWord);
    ADV();
    displayUtas(inputangka, &dbUtasUser, &l);

    return 0;
}