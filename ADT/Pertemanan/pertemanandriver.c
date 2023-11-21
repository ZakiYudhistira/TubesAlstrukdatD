#include "pertemanan.h"
#include "../boolean.h"
#include "ADTRequirements/queuelinked.h"
// #include "../Pengguna/pengguna.h"
#include "../Matrix/matrix.h"
// #include "../Pengguna/pengguna.c"
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

int main(){
    // databaseprofil array;
    // Pengguna Pengguna1;
    // Pengguna Pengguna2;
    // Pengguna Pengguna3;
    // createDatabase(&array);
    // CreatePengguna(&Pengguna1);
    // CreatePengguna(&Pengguna2);
    // CreatePengguna(&Pengguna3);
    Matrix_Permintaan b;
    Matrix_pertemanan a;
    Word path = {
        "../../Konfigurasi/config-1/pengguna.config",
        300
    };


    // perintah(300, true);
    // ADV();
    // printWord(currentWord);
    // endif;
    // perintah(300, true);
    // ADV();
    // printWord(currentWord);
    createMatrixTeman(&a);
    loadMatrixTemanandPermintaanTeman(&a, &b, path);
    tulisMatriksPertemanan(a);
    displayMP(b);
}