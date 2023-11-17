#include "pengguna.h"
#include "../Matrix/matrix.h"
#include "../Mesin Kata/wordmachine.h"
#include "../Mesin Karakter/charmachine.h"
#include "../Perintah/perintah.h"
#include <stdio.h>
int main() {
    Word author;
    databaseprofil data;
    int length;
    boolean selesai;
    int index;
    createDatabase(&data);
    selesai = false;
    int id = -1;
    while(selesai == false) {
        char* command = perintah();
        if (isValid(command,"DAFTAR")) {
            Pengguna p;
            ReadPengguna(&p,&data);
            ADV();
        }

        else if (isValid(command,"MASUK")) {
            id = login(&data);
            ADV();
        }

        else if (isValid(command,"KELUAR")) {
            id = -1;
            ADV();
        }

        else if (isChangeProfile(command)
    }
    
    
    return 0;
}