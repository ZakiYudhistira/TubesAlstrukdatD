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

void loadQueuePertemanan(Queue_Teman *q, int array[][3], int jumlah_permintaan_pertemanan, id_user id)
{
    int i;
    for(i = 0 ; i < jumlah_permintaan_pertemanan ; i++){
        if(array[i][0] == id){
            enqueueQT(q, array[i][1], array[i][2]); 
        }
    }
}

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

void DisplayQueueQT(Queue_Teman q, nama_user array)
/* Proses : Menuliskan isi Queue, ditulis di antara kurung siku; antara dua elemen 
    dipisahkan dengan separator "koma", tanpa tambahan karakter di depan, di tengah, 
    atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
{
    printf("Terdapat %d permintaan pertemanan untuk Anda\n",q.length);
    boolean first = true;
    Address_teman p = HEAD_TEMAN(q);
    while(p != NULL){
        if(first){
            printf("| %s \n| jumlah teman: %d\n\n",array[INFO_TEMAN(p)],JUMLAH_TEMAN(p));
            first = false;
        p = NEXT_TEMAN(p);
        } else {
            printf("| %s \n| jumlah teman: %d\n\n",array[INFO_TEMAN(p)],JUMLAH_TEMAN(p));
        p = NEXT_TEMAN(p);
        }
    }
}

boolean isTeman(Matrix_pertemanan m, id_user id1, id_user id2);
/*Mengeluarkan true bila user dengan id1 merupakan teman user dengan id2*/

