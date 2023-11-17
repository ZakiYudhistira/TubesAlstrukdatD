#include <stdio.h>
#include "pertemanan.h"
#include "../Pengguna/pengguna.h"

/*===============================================Perintah pertemanan===============================================*/
void perintahDisplayPermintaanPertemanan(Queue_Teman q, databaseprofil array)
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong, menampilkan daftar permintaan teman yang datang*/
{
    printf("Terdapat %d permintaan pertemanan untuk Anda\n",q.length);
    boolean first = true;
    Address_teman p = HEAD_TEMAN(q);
    while(p != NULL){
        if(first){
            printf("| %s \n| jumlah teman: %d\n\n",nama(array, INFO_TEMAN(p)),JUMLAH_TEMAN(p));
            first = false;
        p = NEXT_TEMAN(p);
        } else {
            printf("| %s \n| jumlah teman: %d\n\n",nama(array, INFO_TEMAN(p)),JUMLAH_TEMAN(p));
        p = NEXT_TEMAN(p);
        }
    }
}

void perintahDisplayDaftarTeman(Matrix_pertemanan m, id_user id, databaseprofil array)
/*Menampilkan daftar pertemanan suatu user dengan id tertentu*/
{
    int i, count = 0;
    for(i = 0 ; i < colEffT(m) ; i++){
        if((m).buffer[id][i]){
            count++;
        }
    }
    if(count != 0){
        printf("%s memiliki %d teman\n",nama(array,id),count);
        printf("Daftar teman %s\n",nama(array,id));
        for(i = 0 ; i < colEffT(m) ; i++){
            if((m).buffer[id][i]){
                printf("| %s\n",nama(array,i));
            }
        }
    } else {
        printf("%s belum memiliki teman\n",nama(array,id));
    }   
}

void perintahTambahTeman(Matrix_Permintaan *pm, id_user id, databaseprofil array, Queue_Teman queue, Matrix_pertemanan m)
/*I.S. sembarang*/
/*F.S. dikirimkan permintaan pertemanan kepada pengguna target*/
{
    if(isEmptyQT(queue)){
        printf("Masukkan nama pengguna:\n");
        // nanti minta input di sini
        int jumlah_teman_user;
        id_user id_tambah;
        if(id_tambah == -1){
            printf("Pengguna bernama %s tidak ditemukan.\n");
        } else {
            boolean isSent = false;
            int i;
            if(isTeman(m, id, id_tambah)){
                printf("%s sudah merupakan teman Anda\n",nama(array, id_tambah));
            } else {
                for(i = 0 ; i < (*pm).length ; i++){
                    if((*pm).permintaan_teman[0] == id_tambah && (*pm).permintaan_teman[0][1] == id){
                        isSent = true;
                        break;
                    }
                }
                if(!isSent){
                    (*pm).permintaan_teman[(*pm).length][0] = id_tambah;
                    (*pm).permintaan_teman[(*pm).length][1] = id;
                    (*pm).permintaan_teman[(*pm).length][2] = jumlah_teman_user;
                    (*pm).length++;
                } else {
                    printf("Anda sudah mengirimkan permintaan pertemanan kepada %s. Silakan tunggu hingga permintaan Anda disetujui.\n",nama(array, id_tambah));
                }
            }
        }  
    } else {
        printf("Terdapat permintaan pertemanan yang belum Anda setujui. Silakan kosongkan daftar permintaan pertemanan untuk Anda terlebih dahulu.\n");
    }
}

void perintahHapusTeman(Matrix_pertemanan *m, id_user id, databaseprofil array)
{
    printf("Masukkan nama pengguna:\n");
    // diisi nama pengguna
    char* nama_hapus;
    id_user id_hapus;
    if(id_hapus == -1){
        printf("User tidak ditemukan, pastikan user terdaftar.\n");
    } else {
        if(isTeman(*m, id, id_hapus)){
            printf("Apakah anda yakin ingin menghapus Bob dari daftar teman anda? (YA/TIDAK) : ");
            boolean cont;
            if(cont){
                printf("%s berhasil dihapus dari daftar teman Anda.\n", nama(array, id_hapus));
                hapusTeman(m, id, id_hapus);
            } else {
                printf("Penghapusan teman dibatalkan.\n");
            }
        } else {
            printf("%s bukan teman Anda.\n", nama(array, id_hapus));
        }
    }
}

void perintahSetujuiPertemanan(Matrix_pertemanan *m, Queue_Teman *q, id_user id, databaseprofil array, Matrix_Permintaan *mp)
/*Menyetujui pertemanan yang ada di antrian pertemanan*/
{
    if(isEmptyQT(*q)){
        printf("Anda tidak memiliki permintaan pertemanan masuk.\n\n");
    } else {
        boolean setuju = false;
        id_user id2;
        int jumlah_teman_id2;
        dequeueQT(q, &id2, &jumlah_teman_id2);
        printf("Permintaan pertemanan teratas dari Bob\n| %s\n| Jumlah teman : %d\n\n",nama(array,id2), jumlah_teman_id2);
        printf("Apakah Anda ingin menyetujui permintaan pertemanan ini ?\n(YA/TIDAK) ");
        printf("\n\n");
        if(setuju){
            printf("Permintaan pertemnan dari %s telah disetujui. Selamat! Anda telah berteman dengan %s.\n\n",nama(array,id2), nama(array,id2));
            tambahTeman(m, id, id2);
            hapusBaris(mp, id, id2);
        } else {
            printf("Permintaan pertemanan dari %s telah ditolak.\n\n",nama(array,id2));
        }
    }
}