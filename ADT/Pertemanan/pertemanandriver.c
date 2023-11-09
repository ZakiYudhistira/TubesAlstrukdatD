#include "pertemanan.h"
#include "../../boolean.h"
#include "ADTRequirements/queuelinked.h"
#include <stdio.h>
#define endif printf("\n")

int main(){
    char nama[4][20] = {"Joko","Santoso","Budi","Sugemi"};
    Matrix_pertemanan ini;
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
}