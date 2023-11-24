/* File : pertemanan.h */
/* ADT fungsi dan prosedur terkait pertemanan  */

#ifndef PERTEMANAN_H
#define PERTEMANAN_H

#include "../boolean.h"
#include "../Mesin Karakter/charmachine.h"
#include "../Perintah/wordmachine.h"
#include "../Perintah/perintah.h"
#include "../Pengguna/pengguna.h"
#include "ADTRequirements/queuelinked.h"

typedef int id_user;
typedef struct {
    int permintaan_teman[190][3];
    int length;
} Matrix_Permintaan;
typedef struct {
    boolean buffer[20][20] ;
    int rowEff;
    int colEff;
} Matrix_pertemanan;

#define rowEffT(p) (p).rowEff
#define colEffT(p) (p).colEff

boolean isFull(Matrix_pertemanan m);
/*Mengeluarkan true jika matriks pertemanan sudah penuh*/

boolean isIdValid(id_user id, Matrix_pertemanan m);

void createMatrixTeman(Matrix_pertemanan *m);
/* I.S. sembarang */
/* F.S. Sebuah m kosong, berisikan boolean False pada semua elemen matriks*/

void addPengguna(Matrix_pertemanan *m);
/*I.S. matrix pertemanan terdefinisi, bisa kosong bisa penuh*/
/*F.S. rowEff dan colEff bertambah 1, menandakan dibuatkannya 1 akun baru*/

void hapusTeman(Matrix_pertemanan *m, id_user id1, id_user id2);
/*I.S. sembarang*/
/*F.S. dihapus hubungan antar suatu elemen dengan elemen lainnya dengan mengenolkan bilik matriks*/

void tambahTeman(Matrix_pertemanan *m, id_user id1, id_user id2);
/*I.S. sembarang*/
/*F.S. menghubungkan id1 dan id2 dalam matriks pertemnanan*/

void daftarPermintaanPertemanan(Queue_Teman q, id_user id);
/*menampilkan daftar permintaan pertemanan seorang user*/

void tulisMatriksPertemanan(Matrix_pertemanan m);
/*Menuliskan kondisi matriks pertemanan program saat ini*/

boolean isTeman(Matrix_pertemanan m, id_user id1, id_user id2);
/*Mengeluarkan true bila user dengan id1 merupakan teman user dengan id2*/

void hapusBaris(Matrix_Permintaan *array, id_user id, id_user id_hapus);
/*I.S. matriks_permintaan tidak kosong*/
/*F.S  dihapus satu baris dari matriks pertemanan*/

void loadMatrixTeman(Matrix_pertemanan *m, char* folder);
/*I.S. sembarang*/
/*F.S. matriks pertemanan terisi berdasarkan file config*/

void loadQueuePertemanan(Queue_Teman *q, Matrix_Permintaan array, id_user id);
/*I.S. q sembarang, array terisi permintaan pertemanan*/
/*F.S. q terisi urutan permintaan pertemanan user tertentu*/

void createMatrixPermintaan(Matrix_Permintaan *m);

void loadMatrixTemanandPermintaanTeman(Matrix_pertemanan *m, Matrix_Permintaan *pm, Word path);

#endif