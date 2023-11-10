/* File : pertemanan.h */
/* ADT fungsi dan prosedur terkait pertemanan  */

#ifndef PERTEMANAN_H
#define PERTEMANAN_H

#include "../../boolean.h"
#include "../Mesin Kata/wordmachine.h"
#include "ADTRequirements/queuelinked.h"

typedef int id_user;
typedef char nama_user[20][20];
typedef struct {
    int permintaan_teman[19][3];
    int length;
} Matrix_Permintaan;
typedef struct {
    boolean buffer[20][20] ;
    int rowEff;
    int colEff;
} Matrix_pertemanan;

#define rowEffT(p) (p).rowEff
#define colEffT(p) (p).colEff
#define name(p,id) (p)[id]

boolean isFull(Matrix_pertemanan m);
/*Mengeluarkan true jika matriks pertemanan sudah penuh*/

boolean isIdValid(id_user id, Matrix_pertemanan m);

void createMatrixTeman(Matrix_pertemanan *m);
/* I.S. sembarang */
/* F.S. Sebuah m kosong, berisikan boolean False pada semua elemen matriks*/

void addPengguna(Matrix_pertemanan *m);
/*I.S. matrix pertemanan terdefinisi, bisa kosong bisa penuh*/
/*F.S. rowEff dan colEff bertambah 1, menandakan dibuatkannya 1 akun baru*/

void loadMatrixTeman(Matrix_pertemanan *m);
/*I.S. sembarang*/
/*F.S. matriks pertemanan terisi berdasarkan file config*/

void loadMatrixPermintaanTeman(Matrix_Permintaan *pm);

void loadQueuePertemanan(Queue_Teman *q, Matrix_Permintaan array, id_user id);
/*I.S. q sembarang, array terisi permintaan pertemanan*/
/*F.S. q terisi urutan permintaan pertemanan user tertentu*/

void daftarTeman(Matrix_pertemanan m, id_user id, nama_user array);
/*Menampilkan daftar pertemanan suatu user dengan id tertentu*/

void hapusTeman(Matrix_pertemanan *m, id_user id1, id_user id2);
/*I.S. sembarang*/
/*F.S. dihapus hubungan antar suatu elemen dengan elemen lainnya dengan mengenolkan bilik matriks*/

void tambahTeman(Matrix_pertemanan *m, id_user id1, id_user id2);
/*I.S. sembarang*/
/*F.S. menghubungkan id1 dan id2 dalam matriks pertemnanan*/

void daftarPermintaanPertemanan(Queue_Teman q, id_user id);
/*menampilkan daftar pertemanan seorang user*/

void setujuiPertemanan(Matrix_pertemanan *m, Queue_Teman *q, id_user id, nama_user array);
/*Menyetujui pertemanan yang ada di antrian pertemanan*/

void tulisMatriksPertemanan(Matrix_pertemanan m);
/*Menuliskan kondisi matriks pertemanan program saat ini*/

void DisplayQueueQT(Queue_Teman q, nama_user array);

boolean isTeman(Matrix_pertemanan m, id_user id1, id_user id2);
/*Mengeluarkan true bila user dengan id1 merupakan teman user dengan id2*/

void perintahTambahTeman(Matrix_Permintaan *array, id_user id);
/**/

void perintahHapusTeman(Matrix_pertemanan *m, id_user id);

void hapusBaris(Matrix_Permintaan *array, id_user id);

#endif