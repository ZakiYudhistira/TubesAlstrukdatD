#include "pengguna.h"
#include "../Matrix/matrix.h"
#include "../Mesin Kata/wordmachine.h"
#include "../Mesin Karakter/charmachine.h"
#include <stdio.h>
int main() {
    Word author;
    Pengguna p;
    databaseprofil data;
    int length;
    int index;
    createDatabase(&data);
    ReadPengguna(&p, &data);
    insertLast(&data, p);
    ReadPengguna(&p, &data);
    insertLast(&data, p);
    length = listLength(&data);
    printf("%d\n",length);
    index = login(&data);
    printf("Anda memiliki id %d\n",index);
    cekProfil(index,&data);
    return 0;
}