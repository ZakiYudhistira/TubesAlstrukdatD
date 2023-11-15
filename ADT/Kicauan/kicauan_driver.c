#include "kicauan.h"
#include "kicauan.c"
#include "../Perintah/perintah.h"
#include "../Perintah/perintah.c"
#include "../Mesin Kata/wordmachine.h"
#include "../Mesin Karakter/charmachine.h"
#include "../Mesin Kata/wordmachine.c"
#include "../Mesin Karakter/charmachine.c"
#include "../Datetime/datetime.h"
#include "../Datetime/datetime.c"
#include "../Time/time.h"
#include "../Time/time.c"

int main() {
    boolean end = false;
    ListDinKicau l;
    CreateListKicauan(&l, 10);

    LoadKicauan(&l, "../../Konfigurasi/config-1/kicauan.config");

    int id = ListKicauMaxId(l) + 1;

    while (!end) {
        char* option = perintah();
        ADV();

        if (isValid(option, "KICAU")) {
            HandleKicau(&l, "Bacin", &id);
        }
        else if (isValid(option, "KICAUAN")) {
            HandleKicauan(SortedKicauan(l));
        }
        else if (isSuka(option)) {
            char* id_kicau = sliceString(option, 13, lengthString(option));
            int id_kicauan = atoi(id_kicau);
            HandleSukaKicau(&l, id_kicauan);
        }
        else if (isUbah(option)) {
            char* id_kicau = sliceString(option, 13, lengthString(option));
            int id_kicauan = atoi(id_kicau);
            HandleUbahKicau(&l, "Bacin", id_kicauan);
        }
        else {
            printf("Perintah tidak valid\n");
        }
    }

    return 0;
}