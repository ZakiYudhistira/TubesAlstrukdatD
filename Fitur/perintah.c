#include "wordmachine.h" //BTW, INI MARKNYA MASIH TITIK YA, BULUM TITIK KOMA//
#include "charmachine.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Untuk menggunakan strcmp

//bedanya dengan copyword pada persyaratan looping, jadi boleh ada BLANK atau SPASI//
void simpanword(){
    int i = 0;
    while ((currentChar != MARK) && i != NMax){
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    currentWord.Length = (i<NMax) ? i : NMax;
}

char* perintah(){
    // ini isinya sama kayak algoritma STARTWORD, cuman karena  pakainya simpanword() dan bukan copyword, jadi gw tulis ulang aja//
    START();
    IgnoreBlanks();
    if (currentChar == MARK){
        EndWord = true;
        printf("Input Kosong!!!");
    } else {
        EndWord = false;
        simpanword(); /*copyword() diganti*/
    }

// Mengalokasikan memori untuk string perintah dengan panjang yang sesuai
    char *perintah = (char *)malloc(currentWord.Length + 1);

    if (perintah == NULL) {
        printf("Gagal mengalokasikan memori\n");
        return NULL;
    }

    // Null-terminator sebagai penanda akhir dalam string
    perintah[currentWord.Length] = '\0';

    // Menggabungkan karakter-karakter dalam list menjadi sebuah string
    for (int i = 0; i < currentWord.Length; i++) {
        perintah[i] = currentWord.TabWord[i];
    }

    return perintah;
}

int main() {
    char *test = perintah();

    if (test != NULL) {
        if (strcmp(test, "MASUK") == 0) {
            printf("%s\n", test);
        }

        free(test); //dialokasikan
    }

    return 0;
}