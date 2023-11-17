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
#include "../Mesin Kata/wordmachine.c"
#include "../Mesin Kata/wordmachine.h"
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
    Pengguna profil1 = {
        "zaki",
        "123",
        "",
        "",
        "",
        "public",
        {1,2},
    };
    Pengguna profil2 = {
        "naufal",
        "123",
        "",
        "",
        "",
        "public",
        {1,2},
    };

    Matrix_pertemanan ini;
    createMatrixTeman(&ini);
    databaseprofil profiles;
    profiles.contents[0] = profil1;
    profiles.contents[1] = profil2;


    addPengguna(&ini);
    addPengguna(&ini);
    tulisMatriksPertemanan(ini);
    endif;
    tambahTeman(&ini, 0,1);
    tulisMatriksPertemanan(ini);
    endif;
    daftarTeman(ini,0,profiles);
    endif;
    daftarTeman(ini,1,profiles);
    // Queue_Teman queue_0;
    // CreateQueueQT(&queue_0);
    // loadQueuePertemanan(&queue_0, dua, 0);
    // DisplayQueueQT(queue_0, nama);
    // displayMP(dua);
    // endif;
    // hapusBaris(&dua,0,3);
    // displayMP(dua);
    // endif;
    // loadQueuePertemanan(&queue_0, dua, 0);
    // DisplayQueueQT(queue_0, nama);
    // endif;
}