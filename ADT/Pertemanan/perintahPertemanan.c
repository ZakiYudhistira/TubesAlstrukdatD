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
void perintahDisplayDaftarTeman(Matrix_pertemanan m, id_user id, databaseprofil array)
/*Menampilkan daftar pertemanan suatu user dengan id tertentu*/
{
    int i, count = 0;
    for(i = 0 ; i < colEffT(m) ; i++){
        if((m).buffer[id][i] && i != id){
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
            if((m).buffer[id][i] && i != id){
                printf("| ");
                printWord(nama(array,i));
                endif;
            }
        }
        endif;
    } else {
        printWord(nama(array, id));
        printf(" belum memiliki teman\n");
    }   
}

void perintahHapusTeman(Matrix_pertemanan *m, id_user id, databaseprofil *array, Matrix_Permintaan *mp)
{
    printf("Masukkan nama pengguna:\n");
    perintah(300, false);
    ADV();

    id_user id_hapus = getId(array, currentWord);

    if(id_hapus == -1){
        printf("User tidak ditemukan, pastikan user terdaftar.\n");
    } else if (id_hapus == id) {
        printf("Tidak bisa menghapus diri sendiri.\n");
    } else {
        if(isTeman(*m, id, id_hapus)){
            printf("Apakah anda yakin ingin menghapus  dari daftar teman anda? (YA/TIDAK) : ");
            perintah(5, false);
            ADV();
            boolean cont = isWordEqual(currentWord, ya);
            if(cont){
                hapusTeman(m, id, id_hapus);
                printWord(nama(*array, id_hapus));
                printf(" berhasil dihapus dari daftar teman Anda.\n");
                int i;
                for(i = 0 ; i < (*mp).length ; i++){
                    if((*mp).permintaan_teman[i][0] == id_hapus){
                        (*mp).permintaan_teman[i][2]--;
                    }
                    if((*mp).permintaan_teman[i][0] == id){
                        (*mp).permintaan_teman[i][2]--;
                    }
                }
            } else {
                printf("Penghapusan teman dibatalkan.\n");
            }
        } else {
            printWord(nama(*array, id_hapus));
            printf(" bukan teman Anda.\n");
        }
    }
}

void perintahTambahTeman(Matrix_Permintaan *pm, id_user id, databaseprofil *array, Queue_Teman queue, Matrix_pertemanan m)
/*I.S. sembarang*/
/*F.S. dikirimkan permintaan pertemanan kepada pengguna target*/
{
    if(isEmptyQT(queue)){
        printf("Masukkan nama pengguna:\n");
        perintah(300, false);
        ADV();
        int i, count = 0;
        for(i = 0 ; i < colEffT(m) ; i++){
            if((m).buffer[id][i] && i != id){
                count++;
            }
        }
        id_user id_tambah = getId(array ,currentWord);
        if(id_tambah == -1){
            printf("Pengguna bernama "); 
            printWord(currentWord);
            printf(" tidak ditemukan.\n");
        } else {
            boolean isSent = false;
            int i;
            if(isTeman(m, id, id_tambah) && id != id_tambah){
                printWord(nama(*array, id_tambah));
                printf(" sudah merupakan teman Anda.\n");
            } else if (id == id_tambah){
                printf("Anda sudah berteman dengan diri sendiri.\n");
            } else {
                for(i = 0 ; i < (*pm).length ; i++){
                    if((*pm).permintaan_teman[i][1] == id_tambah && (*pm).permintaan_teman[i][0] == id){
                        isSent = true;
                        break;
                    }
                }
                if(!isSent){
                    (*pm).permintaan_teman[(*pm).length][0] = id;
                    (*pm).permintaan_teman[(*pm).length][1] = id_tambah;
                    (*pm).permintaan_teman[(*pm).length][2] = count;
                    (*pm).length++;
                    printf("Permintaan terkirim.\n");
                } else {
                    printf("Anda sudah mengirimkan permintaan pertemanan kepada ");
                    printWord(nama(*array, id_tambah));
                    printf(" Silakan tunggu hingga permintaan Anda disetujui.\n");
                }
            }
        }  
    } else {
        printf("Terdapat permintaan pertemanan yang belum Anda setujui. Silakan kosongkan daftar permintaan pertemanan untuk Anda terlebih dahulu.\n");
    }
}

void perintahDisplayPermintaanPertemanan(Queue_Teman q, databaseprofil *array)
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong, menampilkan daftar permintaan teman yang datang*/
{
    printf("Terdapat %d permintaan pertemanan untuk Anda.\n",q.length);
    Address_teman p = HEAD_TEMAN(q);
    while(p != NULL){
        printf("| ");
        printWord(nama(*array,INFO_TEMAN(p)));
        endif;
        printf("| jumlah teman: %d", JUMLAH_TEMAN(p));
        endif;
        endif;
        p = NEXT_TEMAN(p);
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
        endif;
        printf("| jumlah teman : %d\n\n", jumlah_teman_id2);

        printf("Apakah Anda ingin menyetujui permintaan pertemanan ini ? (YA/TIDAK) ");
        perintah(5, false);
        ADV();
        boolean setuju = isWordEqual(currentWord, ya);
        endif;
        if(setuju){
            tambahTeman(m, id, id2);
            hapusBaris(mp, id, id2);
            printf("Permintaan pertemanan dari ");
            printWord(nama(array,id2));
            printf(" telah disetujui. Selamat ! Anda telah berteman dengan ");
            printWord(nama(array,id2));
            int i;
            for(i = 0 ; i < (*mp).length ; i++){
                if((*mp).permintaan_teman[i][0] == id2){
                    (*mp).permintaan_teman[i][2]++;
                }
                if((*mp).permintaan_teman[i][0] == id){
                    (*mp).permintaan_teman[i][2]++;
                }
            }
            endif;
            endif;
        } else {
            printf("Permintaan pertemanan dari ");
            printWord(nama(array,id2));
            hapusBaris(mp, id, id2);
            printf(" telah ditolak.");
            endif;
            endif;
        }
    }
}