#include "kicauan.h"
#include "kicauan.c"

int main() {
    Kicauan k;
    ReadKicauan(&k);
    displayKicauan(k);
    return 0;
}