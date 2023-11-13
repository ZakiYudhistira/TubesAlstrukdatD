#include "kicauan.h"
#include "kicauan.c"
#include "../Perintah/perintah.h"
#include "../Perintah/perintah.c"
#include "../Mesin Kata/wordmachine.h"
#include "../Mesin Karakter/charmachine.h"
#include "../Mesin Kata/wordmachine.c"
#include "../Mesin Karakter/charmachine.c"

int main() {
    boolean end = false;
    int id = 0;
    ListDinKicau l;
    CreateListKicauan(&l, 10);

    while (!end) {
        char* option = perintah();
        ADV();

        if (isValid(option, "KICAU")) {
            Kicauan k;
            CreateKicauan(&k);
            printf("Masukan kicauan:\n");
            char* kicau = perintah();
            ADV();

            ID_KICAU(k) = id;
            TEXT_KICAU(k) = kicau;
            LIKE_KICAU(k) = 0;
            AUTHOR_KICAU(k) = "user";
            DATETIME_KICAU(k) = time(NULL);
            printf("\n");
            printf("Selamat! kicauan telah diterbitkan!\n");
            printf("Detil kicauan:\n");
            DisplayKicauan(k);
            printf("\n");
            InsertLastKicau(&l, k);
            id++;
        }
        else if (isValid(option, "KICAUAN")) {
            for (int i = 0; i < ListKicauLength(l); i++) {
                DisplayKicauan(ELMT_KICAU(l, i));
                printf("\n");
            }
        }
        else if (isSuka(option)) {
            printf("%s\n", option);
        }
        else if (isUbah(option)) {
            printf("%s\n", option);
        }
        else {
            printf("Perintah tidak valid\n");
        }
    }

    return 0;
}