#include "pertemanan.h"
#include "../boolean.h"
#include "ADTRequirements/queuelinked.h"
#include "../Pengguna/pengguna.h"
#include "../Matrix/matrix.h"
#include "../Pengguna/pengguna.c"
#include "pertemanan.c"
#include "perintahPertemanan.c"
#include "ADTRequirements/queuelinked.c"
#include "../Matrix/matrix.c"
#include "../Mesin Karakter/charmachine.c"
#include "../Mesin Karakter/charmachine.h"
#include "../Perintah/perintah.c"
#include <stdio.h>

// void loadPengguna(databaseprofil *profil ,Word path){
//     FILE* file = fopen(path.TabWord, "r");
//     char line[300];

//     if(file == NULL){
//         printf("File tidak ditemukan\n");
//         exit(EXIT_FAILURE);
//     }

//     fgets(line, 300, file);
//     StringToWord(line, &currentWord);
//     int banyak_pengguna = WordToInt(removeNewline(currentWord));

//     Pengguna temp;
//     CreatePengguna(&temp);

// }

void displayMP(Matrix_Permintaan array){
    int i,j;
    for(i = 0 ; i < array.length ; i++){
        for(j = 0 ; j < 3 ; j++){
            printf("%d ", array.permintaan_teman[i][j]);
        }
        endif;
    }
}

Word path = {
    "../../Konfigurasi/config-1/pengguna.config",
    300
};

int main(){
    Matrix_Permintaan b;
    Matrix_pertemanan a;
    loadMatrixTemanandPermintaanTeman(&a, &b, path);
    databaseprofil array;
    Pengguna Pengguna1;
    Pengguna Pengguna2;
    Pengguna Pengguna3;
    CreatePengguna(&Pengguna1);
    CreatePengguna(&Pengguna2);
    CreatePengguna(&Pengguna3);
    Queue_Teman queue;
    CreateQueueQT(&queue);
    loadQueuePertemanan(&queue, b, 1);
    Word nama1;
    StringToWord("joko sembung", &nama1);
    Word nama2;
    StringToWord("Nianda", &nama2);
    Word nama3;
    StringToWord("Banaman", &nama3);
    createDatabase(&array);

    Pengguna1.nama = nama1;
    Pengguna2.nama = nama2;
    Pengguna3.nama = nama3;
    array.contents[0] = Pengguna1;
    array.contents[1] = Pengguna2;
    array.contents[2] = Pengguna3;
    perintahDisplayPermintaanPertemanan(queue, &array);
    perintahSetujuiPertemanan(&a, &queue, 1, array, &b);
    displayMP(b);
    endif;
    tulisMatriksPertemanan(a);
    endif;
    perintahSetujuiPertemanan(&a, &queue, 1, array, &b);
    tulisMatriksPertemanan(a);
    displayMP(b);
    perintahHapusTeman(&a, 1, &array);
    tulisMatriksPertemanan(a);
    // perintahHapusTeman(&a, 1, &array);
    // tulisMatriksPertemanan(a);
    perintahTambahTeman(&b, 1, &array, queue, a);
    displayMP(b);
}