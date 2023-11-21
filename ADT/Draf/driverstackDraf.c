#include "stackDraf.h"
#include <stdio.h>

int main() {
    listStackDraf lsd;
    ListDinKicau l;
    databaseprofil db;

    lsd.nEff = 0;

    perintah(50, 0);
    Word input = currentWord;
    ADV();

    LoadDraf(&lsd, input);

    perintah(50, 0);
    input = currentWord;
    ADV();
    DisplayDraf(input, lsd, &l, db);
    
    return 0;
}