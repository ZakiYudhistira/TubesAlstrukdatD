#include "perintah.h"
#include "perintah.c"


int main() {
    perintah(3, true);//true buat PERINTAH dari user ke fitur jadi ada ">>"

    if (isValid(currentWord, "hai")) {
        printWord(currentWord);
    }
    else if(isBlanks(currentWord)){
        printf("Valid\n");
    }

    return 0;
}