#include "pertemanan.h"
#include "../boolean.h"
#include "ADTRequirements/queuelinked.h"
#include "../Pengguna/pengguna.h"
#include "../Matrix/matrix.h"
#include "../Pengguna/pengguna.c"
#include "pertemanan.c"
#include "ADTRequirements/queuelinked.c"
#include "../Matrix/matrix.c"
#include "../Mesin Karakter/charmachine.c"
#include "../Mesin Karakter/charmachine.h"
#include "../Perintah/perintah.c"
#include <stdio.h>
#define endif printf("\n")

void displayMP(Matrix_Permintaan array){
    int i,j;
    for(i = 0 ; i < array.length ; i++){
        for(j = 0 ; j < 3 ; j++){
            printf("%d ", array.permintaan_teman[i][j]);
        }
        endif;
    }
}


// typedef struct {
//    Word nama;
//    Word password;
//    Word bio;
//    Word hp;
//    Word weton;
//    Word jenis;
//    Matrix profil;
// } Pengguna;
int main(){
    databaseprofil array;
    Pengguna Pengguna1;
    Pengguna Pengguna2;
    Pengguna Pengguna3;
    createDatabase(&array);
    CreatePengguna(&Pengguna1);
    CreatePengguna(&Pengguna2);
    CreatePengguna(&Pengguna3);

    perintah(300, true);
    ADV();
    printWord(currentWord);
    endif;
    perintah(300, true);
    ADV();
    printWord(currentWord);
}