#include "perintah.c"
#include "../Mesin Kata/wordmachine.c" /*BTW, INI MARKNYA udah diganti jadi TITIK KOMA*/
#include "../Mesin Karakter/charmachine.c"
#include <stdio.h>

int main() {
    char* test = perintah();

    if (test != NULL) {
        if (isValid(test, "hai")) {
            printf("Valid\n");
        }
    }

    return 0;
}