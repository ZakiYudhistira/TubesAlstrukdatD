#include "pengguna.h"
#include "pengguna.c"

int main() {
    Pengguna p;
    ReadPengguna(&p);
    displayPengguna(p);

    return 0;
}