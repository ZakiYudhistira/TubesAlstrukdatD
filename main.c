#include <stdio.h>
#include <stdlib.h>
#include "ADT/Balasan/balasan.h"
#include "ADT/Balasan/balasan.c"
#include "ADT/Datetime/datetime.h"
#include "ADT/Datetime/datetime.c"
#include "ADT/Kicauan/kicauan.h"
#include "ADT/Kicauan/kicauan.c"
#include "ADT/Matrix/matrix.h"
#include "ADT/Matrix/matrix.c"
#include "ADT/Mesin Karakter/charmachine.h"
#include "ADT/Mesin Karakter/charmachine.c"
#include "ADT/PColor/pcolor.h"
#include "ADT/PColor/pcolor.c"
#include "ADT/Pengguna/pengguna.h"
#include "ADT/Pengguna/pengguna.c"
#include "ADT/Perintah/perintah.h"
#include "ADT/Perintah/perintah.c"
#include "ADT/Pertemanan/pertemanan.h"
#include "ADT/Pertemanan/pertemanan.c"
#include "ADT/Pertemanan/perintahPertemanan.h"
#include "ADT/Pertemanan/perintahPertemanan.c"
#include "ADT/Pertemanan/ADTRequirements/queuelinked.h"
#include "ADT/Pertemanan/ADTRequirements/queuelinked.c"
#include "ADT/Draf/stackDraf.h"
#include "ADT/Draf/stackDraf.c"
#include "ADT/Simpan/simpan.h"
#include "ADT/Simpan/simpan.c"
#include "ADT/Time/time.h"
#include "ADT/Time/time.c"
#include "ADT/Utas/utas.h"
#include "ADT/Utas/utas.c"
#include <sys/stat.h>

Word isDirectoryExists() {
    Word path;
    printf("Silahkan masukan folder konfigurasi untuk dimuat: ");
    perintah(300, false);
    ADV();
    printf("\n");
    path = currentWord;
    StringToWord(concatString("./Konfigurasi/", WordToString(path)), &path);

    struct stat stats;
    stat(path.TabWord, &stats);
    // Check for file existence
    while (!(S_ISDIR(stats.st_mode))) {
        printf("Folder tidak ditemukan, mohon masukkan folder yang valid.\n\n");
        printf("Silahkan masukan folder konfigurasi untuk dimuat: ");
        perintah(300, false);
        ADV();
        printf("\n");
        path = currentWord;
        StringToWord(concatString("./Konfigurasi/", WordToString(path)), &path);
        stat(path.TabWord, &stats);
    }

    return path;
}

int main() {
    // Inisialisasi BurBir
    databaseprofil list_database;
    createDatabase(&list_database);
    Matrix_pertemanan matriks_pertemanan;
    createMatrixTeman(&matriks_pertemanan);
    Matrix_Permintaan matriks_permintaan;
    createMatrixPermintaan(&matriks_permintaan);
    ListDinKicau list_kicau;
    CreateListKicauan(&list_kicau, 10);
    ListDinBalasan list_balasan;
    createListBalasan(&list_balasan, 10);
    ListDinUtas list_utas;
    initListDinUtas(&list_utas);

    // Data Pengguna
    int idPengguna = -1;
    Word temp, idKicauan, idBalasan;

    printf("\n");
    const char* asciiArt = {
        " /$$$$$$$                      /$$       /$$          \n"
        "| $$__  $$                    | $$      |__/          \n"
        "| $$  \\ $$ /$$   /$$  /$$$$$$ | $$$$$$$  /$$  /$$$$$$ \n"
        "| $$$$$$$ | $$  | $$ /$$__  $$| $$__  $$| $$ /$$__  $$\n"
        "| $$__  $$| $$  | $$| $$  \\__/| $$  \\ $$| $$| $$  \\__/\n"
        "| $$  \\ $$| $$  | $$| $$      | $$  | $$| $$| $$      \n"
        "| $$$$$$$/|  $$$$$$/| $$      | $$$$$$$/| $$| $$      \n"
        "|_______/  \\______/ |__/      |_______/ |__/|__/      \n"
        "                                                      \n"
    };
    printf("%s", asciiArt);

    printf("Selamat datang di BurBir.\nAplikasi untuk studi kualitatif mengenai perilaku manusia dengan menggunakan metode\n(pengambilan data berupa) Focused Group Discussion kedua di zamannya.\n\n");

    // Fungsi load config
    Word path, pathPengguna, pathKicauan, pathBalasan;

    path = isDirectoryExists(); /* Pengecekan direktori pake function ini yang ngereturn variable path*/
    StringToWord(concatString(WordToString(path), "/pengguna.config"), &pathPengguna);
    LoadPengguna(&list_database, pathPengguna);
    loadMatrixTemanandPermintaanTeman(&matriks_pertemanan, &matriks_permintaan, pathPengguna);
    StringToWord(concatString(WordToString(path), "/kicauan.config"), &pathKicauan);
    LoadKicauan(&list_kicau, pathKicauan);
    StringToWord(concatString(WordToString(path), "/balasan.config"), &pathBalasan);
    LoadBalasan(&list_balasan, pathBalasan);
    StringToWord(concatString(WordToString(path), "/utas.config"), &pathBalasan);
    LoadUtas(&list_utas, pathBalasan);


    // Data Setelah Load
    int idKicau = ListKicauMaxId(list_kicau) + 1;

    printf("File konfigurasi berhasil dimuat! Selamat Berkicau!\n");

    boolean end = false;
    boolean isLoggedIn = false;

    while (!end) {
        perintah(300, true);
        ADV();

        // Perintah ADT Pengguna
        if (isValid(currentWord, "DAFTAR")) {
            if (isLoggedIn) {
                printf("Anda sudah masuk. Keluar terlebih dahulu untuk melakukan daftar.\n");
            }
            else {
                Pengguna p;
                if (listLength(&list_database) == 20) {
                    printf("Jumlah pengguna sudah penuh\n");
                }
                else {
                    ReadPengguna(&p, &list_database);
                }
            }
        }

        else if (isValid(currentWord, "MASUK")) {
            if (isLoggedIn) {
                printf("Wah Anda sudah masuk. Keluar dulu yuk!\n");
            }
            else {
                idPengguna = login(&list_database);
                if (idPengguna != -1) {
                    isLoggedIn = true;
                }
            }
        }

        else if (isValid(currentWord, "KELUAR")) {
            if (isLoggedIn) {
                idPengguna = -1;
                isLoggedIn = false;
                printf("Terima kasih telah menggunakan layanan BurBir\n");
            }
            else {
                printf("Masuk terlebih dahulu\n");
            }
        }

        else if (isValid(currentWord, "TUTUP_PROGRAM")) {
            printf("Anda telah keluar dari program BurBir. Sampai jumpa di penjelajahan berikutnya.\n");
            end = true;
        }

        // Perintah Bagian Profil
        else if (isValid(currentWord, "ATUR_JENIS_AKUN")) {
            if (isLoggedIn) {
                printf("%d\n", jenis(list_database, idPengguna));
                if (jenis(list_database, idPengguna) == 0) {
                    printf("Anda saat ini akun Publik, ingin menjadi akun Privat?\n");
                    printf("Ketik Y untuk mengganti, ketik N untuk tidak\n");
                    perintah(300, false);
                    ADV();
                    if (isValid(currentWord, "Y")) {
                        jenis(list_database, idPengguna) = 1;
                        printf("Akun telah diubah menjadi akun Privat\n");
                    }
                }
                else {
                    printf("Anda saat ini akun Privat, ingin menjadi akun Publik?\n");
                    printf("Ketik Y untuk mengganti, ketik N untuk tidak\n");
                    perintah(300, false);
                    ADV();
                    if (isValid(currentWord, "Y")) {
                        jenis(list_database, idPengguna) = 0;
                        printf("Akun telah diubah menjadi akun Publik\n");
                    }
                }
            }
            else {
                printf("Masuk terlebih dahulu\n");
            }
        }

        else if (isValid(currentWord, "GANTI_PROFIL")) {
            if (isLoggedIn) {
                ubahProfil(&list_database, idPengguna);
            }
            else {
                printf("Masuk terlebih dahulu\n");
            }
        }

        else if (isCheck(currentWord)) {
            Word user = getUser(currentWord);
            int idprofil = getId(&list_database, user);
            if (jenis(list_database, idprofil) == 1) {
                if (isTeman(matriks_pertemanan, idPengguna, idprofil)) {
                    cekProfil(idprofil, &list_database);
                }
                else {
                    printf("Ikuti user ini agar mendapat profil mengenai dirinya\n");
                }
            }
            else {
                cekProfil(idprofil, &list_database);
            }
        }

        else if (isValid(currentWord, "UBAH_FOTO_PROFIL")) {
            if (isLoggedIn) {
                ubahfotoprofil(&list_database, idPengguna);
            }
            else {
                printf("Masuk terlebih dahulu\n");
            }
        }

        // Perintah ADT Teman
        else if (isValid(currentWord, "DAFTAR_TEMAN")) {
            if (isLoggedIn) {
                perintahDisplayDaftarTeman(matriks_pertemanan, idPengguna, list_database);
            }
            else {
                printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
            }
        }

        // Perintah Permintaan Pertemanan
        else if (isValid(currentWord, "HAPUS_TEMAN")) {
            if (isLoggedIn) {
                perintahHapusTeman(&matriks_pertemanan, idPengguna, &list_database);
            }
            else {
                printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
            }
        }

        else if (isValid(currentWord, "TAMBAH_TEMAN")) {
            if (isLoggedIn) {
                Queue_Teman q;
                CreateQueueQT(&q);
                loadQueuePertemanan(&q, matriks_permintaan, idPengguna);
                perintahTambahTeman(&matriks_permintaan, idPengguna, &list_database, q, matriks_pertemanan);
                freeQueueQT(&q);
            }
            else {
                printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
            }
        }

        else if (isValid(currentWord, "DAFTAR_PERMINTAAN_PERTEMANAN")) {
            if (isLoggedIn) {
                Queue_Teman q;
                CreateQueueQT(&q);
                loadQueuePertemanan(&q, matriks_permintaan, idPengguna);
                perintahDisplayPermintaanPertemanan(q, &list_database);
                freeQueueQT(&q);
            }
            else {
                printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
            }
        }

        else if (isValid(currentWord, "SETUJUI_PERTEMANAN")) {
            if (isLoggedIn) {
                Queue_Teman q;
                CreateQueueQT(&q);
                loadQueuePertemanan(&q, matriks_permintaan, idPengguna);
                perintahSetujuiPertemanan(&matriks_pertemanan, &q, idPengguna, list_database, &matriks_permintaan);
                freeQueueQT(&q);
            }
            else {
                printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
            }
        }

        // Perintah ADT Kicauan
        else if (isValid(currentWord, "KICAU")) {
            if (isLoggedIn) {
                HandleKicau(&list_kicau, nama(list_database, idPengguna), &idKicau);
            }
            else {
                printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
            }
        }

        else if (isValid(currentWord, "KICAUAN")) {
            if (isLoggedIn) {
                HandleKicauan(SortedKicauan(list_kicau), nama(list_database, idPengguna), matriks_pertemanan, list_database);
            }
            else {
                printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
            }
        }

        else if (isSuka(currentWord)) {
            idKicauan = sliceWord(currentWord, 13, currentWord.Length);
            if (isLoggedIn) {
                HandleSukaKicau(&list_kicau, WordToInt(idKicauan), nama(list_database, idPengguna), matriks_pertemanan, list_database);
            }
            else {
                printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
            }
        }

        else if (isUbah(currentWord)) {
            idKicauan = sliceWord(currentWord, 13, currentWord.Length);
            if (isLoggedIn) {
                HandleUbahKicau(&list_kicau, nama(list_database, idPengguna), WordToInt(idKicauan));
            }
            else {
                printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
            }
        }

        // Perintah ADT Balasan
        else if (isBalasan(currentWord)) {
            if (isLoggedIn) {
                idKicauan = sliceWord(currentWord, 8, currentWord.Length);
                HandleBalasan(idKicauan, list_kicau, list_balasan, nama(list_database, idPengguna), matriks_pertemanan, list_database);
            }
            else {
                printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");

            }
        }

        else if (isBalas(currentWord)) {
            if (isLoggedIn) {
                split3Word(currentWord, &temp, &idKicauan, &idBalasan);
                HandleBalas(idKicauan, idBalasan, list_kicau, &list_balasan, nama(list_database, idPengguna), matriks_pertemanan, list_database);
            }
            else {
                printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");

            }
        }

        else if (isHapusBalasan(currentWord)) {
            if (isLoggedIn) {
                split3Word(currentWord, &temp, &idKicauan, &idBalasan);
                HandleHapusBalasan(idKicauan, idBalasan, &list_balasan, nama(list_database, idPengguna));
            }
            else {
                printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");

            }
        }

        // Perintah ADT Draf
        else if (isValid(currentWord, "BUAT_DRAF")) {
            if (isLoggedIn) {
                printf("Logic\n");
            }
            else {
                printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");

            }
        }

        else if (isValid(currentWord, "LIHAT_DRAF")) {
            if (isLoggedIn) {
                printf("Logic\n");
            }
            else {
                printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");

            }
        }

        else if (isValid(currentWord, "LIHAT_DRAF")) {
            if (isLoggedIn) {
                printf("Logic\n");
            }
            else {
                printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");

            }
        }

        else if (isValid(currentWord, "LIHAT_DRAF")) {
            if (isLoggedIn) {
                printf("Logic\n");
            }
            else {
                printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");

            }
        }

        else if (isValid(currentWord, "LIHAT_DRAF")) {
            if (isLoggedIn) {
                printf("Logic\n");
            }
            else {
                printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");

            }
        }

        else if (isValid(currentWord, "LIHAT_DRAF")) {
            if (isLoggedIn) {
                printf("Logic\n");
            }
            else {
                printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");

            }
        }

        // Perintah Simpan dan Muat
        else if (isValid(currentWord, "SIMPAN")) {
            printf("Masukkan nama folder penyimpanan\n");
            perintah(300, false);
            ADV();

            if (isValid(currentWord, "test")) {
                StringToWord(concatString("./Konfigurasi/", WordToString(currentWord)), &path);
                writePertemananConfig(matriks_pertemanan, matriks_permintaan, list_database, path);
                writeKicauanConfig(list_kicau, path);
                writeBalasanConfig(list_balasan, path);
            }
        }

        else if (isValid(currentWord, "MUAT")) {
            if (isLoggedIn) {
                printf("Anda harus keluar terlebih dahulu untuk melakukan pemuatan.\n");
            }
            else {
                printf("Masukkan nama folder yang hendak dimuat.\n");
                perintah(300, false);
                ADV();

                StringToWord(concatString("./Konfigurasi/", WordToString(currentWord)), &path);

                struct stat stats;
                stat(path.TabWord, &stats);
                // Check for file existence
                if (!(S_ISDIR(stats.st_mode))) {
                    printf("Tidak ada folder yang dimaksud!\n");
                }
                else {
                    printf("Anda akan melakukan pemuatan dari ");
                    printWord(currentWord);
                    printf(".\n\n");

                    printf("Mohon tunggu...\n");
                    printf("1...\n");
                    printf("2...\n");
                    printf("3...\n\n");

                    StringToWord(concatString(WordToString(path), "/pengguna.config"), &pathPengguna);
                    LoadPengguna(&list_database, pathPengguna);
                    loadMatrixTemanandPermintaanTeman(&matriks_pertemanan, &matriks_permintaan, pathPengguna);
                    StringToWord(concatString(WordToString(path), "/kicauan.config"), &pathKicauan);
                    LoadKicauan(&list_kicau, pathKicauan);
                    StringToWord(concatString(WordToString(path), "/balasan.config"), &pathBalasan);
                    LoadBalasan(&list_balasan, pathBalasan);
                    StringToWord(concatString(WordToString(path), "/utas.config"), &pathBalasan);
                    LoadUtas(&list_utas, pathBalasan);

                    printf("Pemuatan selesai!\n");
                }
            }
        }

        else {
            printf("Perintah tidak dikenali, mohon masukkan perintah yang valid.\n");
        }
    }


    return 0;
}