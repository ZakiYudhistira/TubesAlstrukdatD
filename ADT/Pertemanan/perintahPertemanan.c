#include <stdio.h>
#include "pertemanan.h"
#include "../Pengguna/pengguna.h"
#include "../Perintah/perintah.h"
#define endif printf("\n");


Word ya = {
    .TabWord = "YA",
    .Length = 2
};

/*===============================================Perintah pertemanan===============================================*/
void perintahDisplayPermintaanPertemanan(Queue_Teman q, databaseprofil *array)
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong, menampilkan daftar permintaan teman yang datang*/
{
    printf("Terdapat %d permintaan pertemanan untuk Anda\n",q.length);
    boolean first = true;
    Address_teman p = HEAD_TEMAN(q);
    while(p != NULL){
        printf("| ");
        printWord(nama(*array,INFO_TEMAN(p)));
        endif;
        printf("| jumlah teman: %d", JUMLAH_TEMAN(p));
        p = NEXT_TEMAN(p);
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
        printWord(nama(array, id));
        printf(" memiliki %d teman\n",count);
        printf("Daftar teman ");
        printWord(nama(array, id));
        endif;
        for(i = 0 ; i < colEffT(m) ; i++){
            if((m).buffer[id][i]){
                printf("| ");
                printWord(nama(array,i));
                endif;
            }
        }
    } else {
        printWord(nama(array, id));
        printf(" belum memiliki teman\n");
    }   
}

void perintahTambahTeman(Matrix_Permintaan *pm, id_user id, databaseprofil *array, Queue_Teman queue, Matrix_pertemanan m)
/*I.S. sembarang*/
/*F.S. dikirimkan permintaan pertemanan kepada pengguna target*/
{
    if(isEmptyQT(queue)){
        printf("Masukkan nama pengguna:\n");
        perintah(300, true);
        ADV();
        int jumlah_teman_user;
        id_user id_tambah = getId(array ,currentWord);
        if(id_tambah == -1){
            printf("Pengguna bernama %s tidak ditemukan.\n");
        } else {
            boolean isSent = false;
            int i;
            if(isTeman(m, id, id_tambah)){
                printWord(nama(*array, id_tambah));
                printf(" sudah merupakan teman Anda\n");
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
                    prinf("Permintaan terkirim.\n");
                } else {
                    printf("Anda sudah mengirimkan permintaan pertemanan kepada . Silakan tunggu hingga permintaan Anda disetujui.\n");
                    printWord(nama(*array, id_tambah));
                    printf(". Silakan tunggu hingga permintaan Anda disetujui.\n");
                }
            }
        }  
    } else {
        printf("Terdapat permintaan pertemanan yang belum Anda setujui. Silakan kosongkan daftar permintaan pertemanan untuk Anda terlebih dahulu.\n");
    }
}

void perintahHapusTeman(Matrix_pertemanan *m, id_user id, databaseprofil *array)
{
    printf("Masukkan nama pengguna:\n");
    perintah(300, true);
    ADV();
    id_user id_hapus = getId(array, currentWord);
    if(id_hapus == -1){
        printf("User tidak ditemukan, pastikan user terdaftar.\n");
    } else {
        if(isTeman(*m, id, id_hapus)){
            printf("Apakah anda yakin ingin menghapus  dari daftar teman anda? (YA/TIDAK) : ");
            perintah(5, true);
            ADV();
            boolean cont = isWordEqual(currentWord, ya);
            if(cont){
                hapusTeman(m, id, id_hapus);
                printWord(nama(*array, id_hapus));
                printf(" berhasil dihapus dari daftar teman Anda.\n");
            } else {
                printf("Penghapusan teman dibatalkan.\n");
            }
        } else {
            printWord(nama(*array, id_hapus));
            printf(" bukan teman Anda.\n");
        }
    }
}

void perintahSetujuiPertemanan(Matrix_pertemanan *m, Queue_Teman *q, id_user id, databaseprofil array, Matrix_Permintaan *mp)
/*Menyetujui pertemanan yang ada di antrian pertemanan*/
{
    if(isEmptyQT(*q)){
        printf("Anda tidak memiliki permintaan pertemanan masuk.\n\n");
    } else {
        id_user id2;
        int jumlah_teman_id2;
        dequeueQT(q, &id2, &jumlah_teman_id2);
        printf("Permintaan teman teratas dari ");
        printWord(nama(array, id));
        endif;
        printf("| ");
        printWord(nama(array,id2));
        printf("| jumlah teman : %d\n\n", jumlah_teman_id2);

        printf("Apakah Anda ingin menyetujui permintaan pertemanan ini ?\n(YA/TIDAK) ");
        perintah(5, true);
        boolean setuju = isWordEqual(currentWord, ya);
        printf("\n\n");
        if(setuju){
            tambahTeman(m, id, id2);
            hapusBaris(mp, id, id2);
            printf("Permintaan pertemanan dari ");
            printWord(nama(array,id2));
            printf(" telah disetujui. Selamat ! Anda telah berteman dengan ");
            printWord(nama(array,id2));
            endif;
            endif;
        } else {
            printf("Permintaan pertemanan dari ");
            printWord(nama(array,id2));
            printf(" telah ditolak.");
            endif;
            endif;
        }
    }
}