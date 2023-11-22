#include "pertemanan.h"
#include "../boolean.h"
#include "ADTRequirements/queuelinked.h"
#include "../Perintah/perintah.h"
#include "../Pengguna/pengguna.h"

#include <stdio.h>

/*===============================================ADT Pertemanan===============================================*/

boolean isFull(Matrix_pertemanan m)
/*Mengembalikan nilai benar bila matriks pertemanan penuh*/
{
    return rowEffT(m) == 20 && colEffT(m) == 20;
}

boolean isIdValid(id_user id, Matrix_pertemanan m)
/*Validasi id*/
{
    return id < colEffT(m) && id < rowEffT(m);
}

boolean isTeman(Matrix_pertemanan m, id_user id1, id_user id2)
/*Mengeluarkan true bila user dengan id1 merupakan teman user dengan id2*/
{
    return m.buffer[id1][id2] && m.buffer[id2][id1];
}

void createMatrixTeman(Matrix_pertemanan *m)
/* I.S. sembarang */
/* F.S. Sebuah m kosong, berisikan boolean False pada semua elemen matriks*/
{
    rowEffT(*m) = 0;
    colEffT(*m) = 0;
    int i,j;
    for(i = 0 ; i < 20 ; i++){
        for(j = 0 ; j < 20 ; j++){
            (*m).buffer[i][j] = false;
        }
    }
}

void createMatrixPermintaan(Matrix_Permintaan *m){
    (*m).length = 0;
}

void addPengguna(Matrix_pertemanan *m)
/*I.S. matrix pertemanan terdefinisi, bisa kosong bisa penuh*/
/*F.S. rowEff dan colEff bertambah 1, menandakan dibuatkannya 1 akun baru*/
{
    if(!isFull(*m)){
        rowEffT(*m)++;
        colEffT(*m)++;
    } else {
        printf("Pengguna penuh\n");
    }
}

void hapusTeman(Matrix_pertemanan *m, id_user id1, id_user id2)
/*I.S. sembarang*/
/*F.S. dihapus hubungan antar suatu elemen dengan elemen lainnya dengan mengenolkan bilik matriks*/
{
    (*m).buffer[id1][id2] = false;
    (*m).buffer[id2][id1] = false;
}

void tambahTeman(Matrix_pertemanan *m, id_user id1, id_user id2)
/*I.S. sembarang*/
/*F.S. menghubungkan id1 dan id2 dalam matriks pertemnanan*/
{
    (*m).buffer[id1][id2] = true;
    (*m).buffer[id2][id1] = true;
}

void tulisMatriksPertemanan(Matrix_pertemanan m){
/*Menuliskan matriks pertemanan ke layar*/
    int i,j;
    for(i = 0 ; i < rowEffT(m) ; i++){
        for(j = 0 ; j < colEffT(m) ; j++){
            printf("%d ",(m).buffer[i][j]);
        }
        printf("\n");
    }
}

void hapusBaris(Matrix_Permintaan *array, id_user id, id_user id_hapus)
/*Menghapus baris dari matriks_permintaan*/
{
    int i;
    for(i = 0 ; i < (*array).length ; i++){
        if((*array).permintaan_teman[i][0] == id && (*array).permintaan_teman[i][1] == id_hapus){
            break;
        }
    }
    int j;
    for(j = i ; j < (*array).length - 1 ; j++){
        (*array).permintaan_teman[j][0] = (*array).permintaan_teman[j+1][0];
        (*array).permintaan_teman[j][1] = (*array).permintaan_teman[j+1][1];
        (*array).permintaan_teman[j][2] = (*array).permintaan_teman[j+1][2];
    }
    (*array).length--;
}

/*===============================================Save dan load config pertemanan===============================================*/

void loadMatrixTemanandPermintaanTeman(Matrix_pertemanan *m, Matrix_Permintaan *pm, Word path)
/*I.S. sembarang*/
/*F.S. matriks pertemanan terisi berdasarkan file config*/
{
    FILE* file = fopen(path.TabWord, "r");
    char line[300];

    if(file == NULL){
        printf("File tidak ditemukan\n");
        exit(EXIT_FAILURE);
    }

    fgets(line, 300, file);
    StringToWord(line, &currentWord);
    int banyak_pengguna = WordToInt(removeNewline(currentWord));
    rowEffT(*m) = banyak_pengguna;
    colEffT(*m) = banyak_pengguna;

    int i;
    for(i = 0 ; i <= banyak_pengguna*11 ; i++){
        fgets(line, 300, file);
    }
    StringToWord(line, &currentWord);
    currentWord = removeNewline(currentWord);

    for(i = 0 ; i < banyak_pengguna ; i++){
        int j;
        int count = 0;
        for(j = 0 ; j < currentWord.Length ; j++){
            if(currentWord.TabWord[j] != ' ' ){
                (*m).buffer[i][count] = currentWord.TabWord[j] - '0';
                count++;
            }
        }
        fgets(line, 300, file);
        StringToWord(line, &currentWord);
        currentWord = removeNewline(currentWord);
    }

    int banyak_permintaan = WordToInt(currentWord);
    pm->length = banyak_permintaan;
    for(i = 0 ; i < banyak_permintaan ; i++){
        int count = 0;
        fgets(line, 300, file);
        StringToWord(line, &currentWord);
        currentWord = removeNewline(currentWord);
        int j;
        for(j = 0 ; j < currentWord.Length ; j++){
            if(currentWord.TabWord[j] != ' ' ){
                pm->permintaan_teman[i][count] = currentWord.TabWord[j] - '0';
                count++;
            }
        }
    }
    fclose(file);
}

void loadQueuePertemanan(Queue_Teman *q, Matrix_Permintaan array, id_user id)
{
    CreateQueueQT(q);
    int i;
    for(i = 0 ; i < array.length ; i++){
        if(array.permintaan_teman[i][1] == id){
            enqueueQT(q, array.permintaan_teman[i][0], array.permintaan_teman[i][2]); 
        }
    }
}

void writetoConfigPertemanan(Matrix_Permintaan m, Matrix_Permintaan pm)
{
    
}