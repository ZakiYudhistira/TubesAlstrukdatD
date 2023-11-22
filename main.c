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

int main() {
    // Inisialisasi BurBir
    databaseprofil dp;
    Matrix_pertemanan mt;
    Matrix_Permintaan mp;
    ListDinKicau lk;
    ListDinBalasan lb;

    // Fungsi load config
    Word path, pathPengguna, pathKicauan, pathBalasan;
    printf("Silahkan masukan folder konfigurasi untuk dimuat: ");
    perintah(300, false);
    ADV();
    printf("\n");
    path = currentWord;
    StringToWord(concatString("./Konfigurasi/", WordToString(path)), &path);
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