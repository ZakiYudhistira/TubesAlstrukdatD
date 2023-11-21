#ifndef PERINTAHPERTEMANAN_H
#define PERINTAHPERTEMANAN_H

#include <stdio.h>
#include "pertemanan.h"
#include "../Pengguna/pengguna.h"
#include "../Perintah/perintah.h"

void perintahDisplayDaftarTeman(Matrix_pertemanan m, id_user id, databaseprofil array);
/*Menampilkan daftar pertemanan suatu user dengan id tertentu*/

void perintahDisplayPermintaanPertemanan(Queue_Teman q, databaseprofil array);
/*Menampilkan antrean pertemanan*/

void perintahTambahTeman(Matrix_Permintaan *pm, id_user id, databaseprofil array, Queue_Teman queue, Matrix_pertemanan m);
/*I.S. id terdaftar, queue pertemnan harus kosong*/
/*F.S. mengirimkan permintaan pertemanan kepada seorang user terdaftar*/

void perintahHapusTeman(Matrix_pertemanan *m, id_user id, databaseprofil array);
/*I.S. sembarang*/
/*F.S. menghapus relasi pertemanan antar pengguna*/

void perintahSetujuiPertemanan(Matrix_pertemanan *m, Queue_Teman *q, id_user id, databaseprofil array, Matrix_Permintaan *mp);
/*I.S. Sembarang*/
/*F.S Menyetujui pertemanan yang ada di antrian pertemanan, head queue dihapus dan matrix pertemanan diperbarui*/

#endif