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
#include "ADT/Utas/utas.h"
#include "ADT/Utas/utas.c"
#include "ADT/Simpan/configPengguna.c"
#include <sys/stat.h>

int main(){
    Word pathPengguna;
    StringToWord("./Konfigurasi/config-1/pengguna.config", &pathPengguna); 
    Word pathw;
    StringToWord("aaa.config", &pathw);
    Matrix_Permintaan mp;
    Matrix_pertemanan mt;
    databaseprofil kkk;
    createMatrixPermintaan(&mp);
    createMatrixTeman(&mt);
    createDatabase(&kkk);
    loadMatrixTemanandPermintaanTeman(&mt, &mp, pathPengguna);
    LoadPengguna(&kkk, pathPengguna);
    writePertemananConfig(mt, mp, kkk, pathw);
    return 0;
}