#include "pengguna.h"
#include "../Matrix/matrix.h"
#include "../Mesin Kata/wordmachine.h"
#include "../Mesin Karakter/charmachine.h"
#include "../Perintah/perintah.h"
#include <stdio.h>
int main() {
    Word author;
    databaseprofil data;
    Matrix_pertemanan teman;
    int length;
    boolean selesai;
    int index;
    createDatabase(&data);
    selesai = false;
    int id = -1;
    // LoadPengguna(&data,)
    while(selesai == false) {
        perintah(300,true);
        if (isValid(currentWord,"DAFTAR")) {
            ADV();
            Pengguna p;
            if (listLength(&data) == 20) {
                printf("Jumlah pengguna sudah penuh\n");
            }
            else {
                ReadPengguna(&p,&data);
            }
        }

        else if (isValid(currentWord,"MASUK")) {
            ADV();
            id = login(&data);
        }

        else if (isValid(currentWord,"KELUAR")) {
            ADV();
            if (id != -1) {
                id = -1;
                printf("Terima kasih telah menggunakan layanan BurBir\n");
            }
            else {
                printf("Masuk terlebih dahulu\n");
            }
        }
        
        else if (isValid(currentWord,"ATUR_JENIS_AKUN")) {
            ADV();
            if (id != -1) {
                if(jenis(data,id) == 0) {
                    printf("Anda saat ini akun Publik, ingin menjadi akun Privat?\n");
                    printf("Ketik Y untuk mengganti, ketik N untuk tidak\n");
                    STARTWORD();
                    ADV();
                    if (isValid(currentWord,"Y")) {
                        jenis(data,id) = 1;
                        printf("Akun telah diubah menjadi akun Privat\n");
                    }
                }
                else {
                    printf("Anda saat ini akun Privat, ingin menjadi akun Publik?\n");
                    printf("Ketik Y untuk mengganti, ketik N untuk tidak\n");
                    STARTWORD();
                    ADV();
                    if (isValid(currentWord,"Y")) {
                        jenis(data,id) = 0;
                        printf("Akun telah diubah menjadi akun Publik\n");
                    }
                }
            }
            else {
                printf("Masuk terlebih dahulu\n");
            }
        }

        else if (isValid(currentWord,"GANTI_PROFIL")) {
            ADV();
            if (id != -1) {
                ubahProfil(&data,id);
            }
            else {
                printf("Masuk terlebih dahulu\n");
            }
        }

        else if(isValid(currentWord,"TUTUP_PROGRAM")) {
            ADV();
            selesai = true;
        }

        else if(isCheck(currentWord)) {
            ADV();
            Word user = getUser(currentWord);
            printWord(user);
            printf("\n");
            int idprofil = getId(&data,user);
            if (jenis(data,idprofil) == 1) {
                if (isTeman(teman,id,idprofil)) {
                    cekProfil(idprofil,&data);
                }
            }
            cekProfil(idprofil,&data);
        }

        else if(isValid(currentWord,"GANTI_FOTO_PROFIL")) {
            ADV();
            if (id != -1) {
                ubahfotoprofil(&data,id);
            }
            else {
                printf("Masuk terlebih dahulu\n");
            }
        }

        else {
            ADV();
        }
    }
    
    
    return 0;
}