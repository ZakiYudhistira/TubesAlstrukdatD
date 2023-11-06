#include "..\ADT\Mesin Kata\wordmachine.h" /*BTW, INI MARKNYA udah diganti jadi TITIK KOMA*/
#include "..\ADT\Mesin Karakter\charmachine.h"
#include <stdio.h>
#include <stdlib.h>
#include "..\ADT\boolean.h"

/*bedanya dengan copyword pada persyaratan looping, jadi boleh ada BLANK atau SPASI*/
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
    // ini isinya sama kayak algoritma STARTWORD, cuman karena  pakainya simpanword() dan bukan copyword, jadi gw tulis ulang aja
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
    char *result = (char *)malloc(currentWord.Length + 1);

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

int lengthString (char *s){
   int count =  0;
   int i = 0;

   while (s[i] != '\0') {
      ++count;
      ++i;
   }
   return count;
}

boolean isValid(char *s, char *valid){
    boolean check = (lengthString(s) == lengthString(valid));
    if (check){
        int i =0;
        while (s[i] != '\0' && check){
            if(s[i] != valid[i]){
                check = false;
            }
            i++;
        }
    }
    return check;
}


/*Contoh Pemakaian*/
// int main() {
//     char *test = perintah();

//     if (test != NULL) {
//         if (isValid(test, "MASUK")) {
//             printf("%s\n", test);
//         }

//         free(test); // Jangan lupa membebaskan memori yang dialokasikan
//     }

//     return 0;
// }