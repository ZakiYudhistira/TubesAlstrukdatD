#include "perintah.h"
#include "perintah.c"
#include "../Mesin Karakter/charmachine.c"
#include <stdio.h>

int main() {
    perintah(3, true);//true kalo misal buat perintah ke fitur biar ada ">>"

    if (isValid(currentWord, "hai")) {
        printWord(currentWord);
    }
    else if(isBlanks(currentWord)){
        printf("valid\n");
    }

    return 0;
}