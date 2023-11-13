#include "../Mesin Kata/wordmachine.h" /*BTW, INI MARKNYA udah diganti jadi TITIK KOMA*/
#include "../Mesin Karakter/charmachine.h"
#include <stdio.h>
#include <stdlib.h>
#include "../boolean.h"

/*bedanya dengan copyword pada persyaratan looping, jadi boleh ada BLANK atau SPASI*/
void simpanword() {
    int i = 0;
    while ((currentChar != MARK) && i != NMax) {
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    currentWord.Length = (i < NMax) ? i : NMax;
}

char* perintah() {
    // ini isinya sama kayak algoritma STARTWORD, cuman karena  pakainya simpanword() dan bukan copyword, jadi gw tulis ulang aja
    START();
    IgnoreBlanks();
    if (currentChar == MARK) {
        EndWord = true;
        printf("Input Kosong!!!");
    }
    else {
        EndWord = false;
        simpanword(); /*copyword() diganti*/
    }

    // Mengalokasikan memori untuk string perintah dengan panjang yang sesuai
    char* result = (char*)malloc(currentWord.Length + 1);

    if (result == NULL) {
        printf("Gagal mengalokasikan memori\n");
        return NULL;
    }

    // Null-terminator sebagai penanda akhir dalam string
    result[currentWord.Length] = '\0';

    // Menggabungkan karakter-karakter dalam list menjadi sebuah string
    for (int i = 0; i < currentWord.Length; i++) {
        result[i] = currentWord.TabWord[i];
    }

    return result;
}

int lengthString(char* s) {
    int count = 0;
    int i = 0;

    while (s[i] != '\0') {
        ++count;
        ++i;
    }
    return count;
}

boolean isValid(char* s, char* valid) {
    boolean check = (lengthString(s) == lengthString(valid));
    if (check) {
        int i = 0;
        while (s[i] != '\0' && check) {
            if (s[i] != valid[i]) {
                check = false;
            }
            i++;
        }
    }
    return check;
}

char* concatString(char* s1, char* s2){
    int length1 = lengthString(s1);
    int length2 = lengthString(s2);
    char* s3[length1+length2];
    int i = 0, j = 0;
    while(s1[i] != '\0'){
        s3[0] = s1[i];
        i++;
    }
    while(s2 != '\0'){
        s3[i] = s2[j];
        j++;
    }
    return s3;
}