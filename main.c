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
#include "ADT/Time/time.h"
#include "ADT/Time/time.c"
#include <sys/stat.h>

Word isDirectoryExists(){
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
    while(!(S_ISDIR(stats.st_mode))){
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
    databaseprofil dp;
    Matrix_pertemanan mt;
    Matrix_Permintaan mp;
    ListDinKicau lk;
    ListDinBalasan lb;
     const char *asciiArt ={
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
    // printf("Silahkan masukan folder konfigurasi untuk dimuat: ");
    // perintah(300, false);
    // ADV();
    // printf("\n");
    // path = currentWord;
    // StringToWord(concatString("./Konfigurasi/", WordToString(path)), &path);
    // while(isDirectoryExists(path) == 0){
    //     printf("File tidak ditemukan\n");
    //     printf("Silahkan masukan folder konfigurasi untuk dimuat: ");
    //     perintah(300, false);
    //     ADV();
    //     printf("\n");
    //     path = currentWord;
    //     StringToWord(concatString("./Konfigurasi/", WordToString(path)), &path);
    // }

    path = isDirectoryExists(); /* Pengecekan direktori pake function ini yang ngereturn variable path*/
    StringToWord(concatString(WordToString(path), "/pengguna.config"), &pathPengguna);
    LoadPengguna(&dp, pathPengguna);
    loadMatrixTemanandPermintaanTeman(&mt, &mp, pathPengguna);
    StringToWord(concatString(WordToString(path), "/kicauan.config"), &pathKicauan);
    LoadKicauan(&lk, pathKicauan);
    StringToWord(concatString(WordToString(path), "/balasan.config"), &pathBalasan);
    LoadBalasan(&lb, pathBalasan);

    printf("File konfigurasi berhasil dimuat! Selamat Berkicau!\n");

    boolean end = false;
    boolean isLoggedIn = false;
    int idPengguna;

    while (!end) {
        perintah(300, true);
        ADV();

        if (isValid(currentWord, "TUTUP_PROGRAM")) {
            end = true;
        }
    }

    return 0;
}