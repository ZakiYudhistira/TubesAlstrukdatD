#include "pengguna.h"
#include "../Matrix/matrix.h"
#include "../Mesin Kata/wordmachine.h"
#include "../Mesin Karakter/charmachine.h"
#include <stdio.h>
Word author;
/* *** Kreator *** */
void CreatePengguna(Pengguna* p) {
    int i;
    Word empty;
    for (i = 0; i < NMax; i++) {
        empty.TabWord[i] = '\0';
    }
    empty.Length = 0;
    NAMA(*p) = empty;
    PASSWORD(*p) = empty;
    BIO(*p) = empty;
    HP(*p) = empty;
    WETON(*p) = empty;
    JENIS(*p) = empty;
    createMatrix(5, 10, &PROFIL(*p));
    for (i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j = j + 2) {
            ELMT(PROFIL(*p), i, j) = 'R';
            ELMT(PROFIL(*p), i, j + 1) = '*';
        }
    }
}
/* I.S. sembarang */
/* F.S. Sebuah p kosong terbentuk dengan isi masing-masing berupa Word kosong dan profil berupa matriks
   kosong yang berisi R dan * */
Word inputusername() {
    Word kata;
    STARTWORD();
    kata = currentWord;
    if (kata.Length > 15) {
        kata.Length = 15;
    }
    return kata;
}

Word inputbio() {
    Word kata;
    STARTWORD();
    kata = currentWord;
    if (kata.Length > 135) {
        kata.Length = 135;
    }
    return kata;
}

boolean inputHP(nomor) {
    boolean valid = true;
    for (int i = 0; i < nomor.length)

}

void ReadPengguna(Pengguna *p, databaseprofil *l) {
    CreatePengguna(p);
    boolean namavalid = false;
    while (namavalid == false)
    {
        printf("Silahkan masukkan username: ");
        Word kata = inputusername();
        int sama = 0;
        for (int i = 0; i < listLength(l); i++) {
            Word name = nama(*l,i);
            if (isWordEqual(name, kata)) {
                sama += 1;
            }
        }
        if (sama > 0) {
            printf("Username telah digunakan, silahkan masukkan yang lain\n");
        }
        else {
            NAMA(*p) = currentWord;
            namavalid = true;
        }
    }
    printf("Silahkan masukkan password: ");
    Word password = inputusername();
    PASSWORD(*p) = currentWord;
    JENIS(*p) = UbahPublik();
}
/* I.S. sembarang */
/* F.S. Sebuah p terbentuk dengan isi masing-masing berupa Word yang diakuisisi
   dari stdin */

   /* *** Display Pengguna *** */
void displayPengguna(Pengguna p) {
    printf("Nama: ");
    for (int i = 0; i < NAMA(p).Length; i++) {
        printf("%c", NAMA(p).TabWord[i]);
    }
    printf("\n");
    printf("Password: ");
    for (int i = 0; i < PASSWORD(p).Length; i++) {
        printf("%c", PASSWORD(p).TabWord[i]);
    }
    printf("\n");
    printf("Bio: ");
    for (int i = 0; i < BIO(p).Length; i++) {
        printf("%c", BIO(p).TabWord[i]);
    }
    printf("\n");
    printf("HP: ");
    for (int i = 0; i < HP(p).Length; i++) {
        printf("%c", HP(p).TabWord[i]);
    }
    printf("\n");
    printf("Weton: ");
    for (int i = 0; i < WETON(p).Length; i++) {
        printf("%c", WETON(p).TabWord[i]);
    }
    printf("\n");
    printf("Jenis: ");
    for (int i = 0; i < JENIS(p).Length; i++) {
        printf("%c", JENIS(p).TabWord[i]);
    }
    printf("\n");
    printf("Profil: \n");
    displayMatrixChar(PROFIL(p));
}
/* Proses : Informasi pengguna ditulis satu persatu dan diakhiri dengan newline */

boolean isWordEqual(Word uname1, Word uname2) {
    int count = 0;
    if (uname1.Length != uname2.Length) {
       return false;
    }
    else {
        for (int i = 0; i < uname1.Length; i++) {
            if (uname1.TabWord[i] == uname2.TabWord[i]) {
            count += 1;
            }
        }
        if (count == uname1.Length) {
            return true;
        }
        else {
            return false;
        }
    }
}

void insertLast(databaseprofil *l, Pengguna val) {
    l->contents[listLength(l)] = val;
}

int listLength(databaseprofil *l) {
    boolean ketemu = false;
    int length = 0;
    while (length < CAPACITY && ketemu == false) {
        if (nama(*l,length).Length == 0) {
            ketemu = true;
        }
        else {
            length += 1;
        }
    }
    return length;
}

void listLengthvoid(databaseprofil *l, int *val) {
    boolean ketemu = false;
    int length = 0;
    while (length < CAPACITY && ketemu == false) {
        if (nama(*l,length).TabWord[0] == ' ') {
            ketemu = true;
        }
        else {
            length += 1;
        }
    }
    *val = length;
}

void createDatabase(databaseprofil *l) {
    int i;
    for (i = 0; i < CAPACITY; i++) {
        nama(*l,i).Length = 0;
    }
}

int login(databaseprofil *data) {
    Word uname;
    printf("Silahkan masukkan username: ");
    STARTWORD();
    for (int i = 0; i < listLength(data); i++) {
    if(isWordEqual(currentWord, nama(*data,i))) {
        boolean passwordbetul = false;
        while (passwordbetul == false) {
            printf("Silahkan masukkan password: ");
            // printf("\n");
            STARTWORD();
            if(isWordEqual(currentWord, password(*data,i))) {
                printf("Selamat datang\n");
                return i;
            }
            else {
                printf("Salah bos ulang kembali mengisi password\n");
            }
        }
    }
        
}   
}


void cekProfil (int idx, databaseprofil *data) {
    if(idx == -1) {
        printf("Login terlebih dahulu");
    }
    else {
        displayPengguna(data->contents[idx]);
    }
}

int getId(databaseprofil *l, Word username) {
    for (int i = 0; i < listLength(l)) {
        if (isWordEqual(nama(*l,i)) == username) {
            return i;
        }
    }
    return -1;
}