#include "kicauan.h"
#include "kicauan.c"
#include "../Perintah/perintah.h"
#include "../Perintah/perintah.c"
#include "../Perintah/wordmachine.h"
#include "../Mesin Karakter/charmachine.h"
#include "../Mesin Karakter/charmachine.c"
#include "../Datetime/datetime.h"
#include "../Datetime/datetime.c"
#include "../Time/time.h"
#include "../Time/time.c"

int main() {
    boolean end = false;

    Word path;
    StringToWord("../../Konfigurasi/config-1/kicauan.config", &path);

    Word id_kicau;

    ListDinKicau l;

    CreateListKicauan(&l, 10);

    LoadKicauan(&l, path);

    int id = ListKicauMaxId(l) + 1;

    while (!end) {
        perintah(300, true);
        ADV();


        if (isValid(currentWord, "KICAU")) {
            perintah(300, true);
            ADV();
            HandleKicau(&l, currentWord, &id);
        }
        else if (isValid(currentWord, "KICAUAN")) {
            HandleKicauan(SortedKicauan(l));
        }
        else if (isSuka(currentWord)) {
            id_kicau = sliceWord(currentWord, 13, currentWord.Length);
            HandleSukaKicau(&l, WordToInt(id_kicau));
        }
        else if (isUbah(currentWord)) {
            id_kicau = sliceWord(currentWord, 13, currentWord.Length);
            perintah(300, true);
            ADV();
            HandleUbahKicau(&l, currentWord, WordToInt(id_kicau));
        }
        else {
            printf("Perintah tidak valid\n");
        }
    }

    return 0;
}