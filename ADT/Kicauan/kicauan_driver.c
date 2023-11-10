#include "kicauan.h"
#include "kicauan.c"
#include "../Perintah/perintah.c"

int main() {
    Kicauan k;

    char* option = perintah();
    printf("%s\n", option);
    // printf("%d\n", strcmp(option, "register"));
    // ReadKicauan(&k);
    // displayKicauan(k);
    return 0;
}