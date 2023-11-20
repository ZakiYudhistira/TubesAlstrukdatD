#include "perintah.c"
#include <stdio.h>

int main() {
    perintah(20, true);//true buat PERINTAH dari user ke fitur jadi ada ">>"

    if (isValid(currentWord, "hai")) {
        printWord(currentWord);
    }
    else if (isBlanks(currentWord)) {
        printf("Valid\n");
    }

    return 0;
}