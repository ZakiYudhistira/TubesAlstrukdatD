#include "pertemanan.h"
#include "../../boolean.h"
#include "ADTRequirements/queuelinked.h"
#include <stdio.h>

boolean isFull(Matrix_pertemanan m)
{
    return rowEffT(m) == 20 && colEffT(m) == 20;
}

boolean isIdValid(id_user id, Matrix_pertemanan m)
{
    return id < colEffT(m) && id < rowEffT(m);
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

void loadMatrixTeman(Matrix_pertemanan *m);
/*I.S. sembarang*/
/*F.S. matriks pertemanan terisi berdasarkan file config*/

void daftarTeman(Matrix_pertemanan m, id_user id, nama_user array)
/*Menampilkan daftar pertemanan suatu user dengan id tertentu*/
{
    int i, count = 0;
    for(i = 0 ; i < colEffT(m) ; i++){
        if((m).buffer[id][i]){
            count++;
        }
    }
    if(count != 0){
        printf("%s memiliki %d teman\n",name(array,id),count);
        printf("Daftar teman %s\n",name(array,id));
        for(i = 0 ; i < colEffT(m) ; i++){
            if((m).buffer[id][i]){
                printf("| %s\n",name(array,i));
            }
        }
    } else {
        printf("%s belum memiliki teman\n",name(array,id));
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

void daftarPermintaanPertemanan(Queue_Teman q, id_user id);
/*menampilkan daftar pertemanan seorang user*/

void setujuiPertemanan(Matrix_pertemanan *m, Queue_Teman *q, id_user id);
/*Menyetujui pertemanan yang ada di antrian pertemanan*/

void tulisMatriksPertemanan(Matrix_pertemanan m){
    int i,j;
    for(i = 0 ; i < rowEffT(m) ; i++){
        for(j = 0 ; j < colEffT(m) ; j++){
            printf("%d ",(m).buffer[i][j]);
        }
        printf("\n");
    }
}

boolean isTeman(Matrix_pertemanan m, id_user id1, id_user id2);
/*Mengeluarkan true bila user dengan id1 merupakan teman user dengan id2*/

