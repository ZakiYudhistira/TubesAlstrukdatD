#include "pertemanan.h"
#include "../boolean.h"
#include "ADTRequirements/queuelinked.h"
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
    char nama[4][20] = {"Joko","Santoso","Budi","Sugemi"};
    // int array[19][3] = {{1,2,2},{0,2,5},{0,3,8}};
    Matrix_pertemanan ini;
    Matrix_Permintaan dua = {
        {{1,2,2},{0,2,5},{0,3,8}},
        3
    };
    createMatrixTeman(&ini);
    addPengguna(&ini);
    addPengguna(&ini);
    addPengguna(&ini);
    addPengguna(&ini);
    tulisMatriksPertemanan(ini);
    endif;
    tambahTeman(&ini, 1,2);
    tambahTeman(&ini, 1,3);
    tambahTeman(&ini, 1,0);
    tulisMatriksPertemanan(ini);
    endif;
    daftarTeman(ini,1,nama);
    endif;
    daftarTeman(ini,2,nama);
    Queue_Teman queue_0;
    CreateQueueQT(&queue_0);
    loadQueuePertemanan(&queue_0, dua, 0);
    DisplayQueueQT(queue_0, nama);
    displayMP(dua);
    endif;
    hapusBaris(&dua,0,3);
    displayMP(dua);
    endif;
    loadQueuePertemanan(&queue_0, dua, 0);
    DisplayQueueQT(queue_0, nama);
    endif;
}