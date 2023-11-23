#include "pengguna.h"
#include "../Matrix/matrix.h"
#include "../Mesin Kata/wordmachine.h"
#include "../Mesin Karakter/charmachine.h"
#include "../Pertemanan/pertemanan.h"
#include "../PColor/pcolor.h"
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
    JENIS(*p) = 0;
    PROFIL(*p) = createphoto();
}
/* I.S. sembarang */
/* F.S. Sebuah p kosong terbentuk dengan isi masing-masing berupa Word kosong dan profil berupa matriks
   kosong yang berisi R dan * */
Word inputusername() {
    Word kata;
    kata.Length = 0;
    STARTWORDPengguna();
    ADV();
    int panjang = currentWord.Length;
    if (panjang >= 20) {
        while (kata.Length < 20) {
            kata.TabWord[kata.Length] = currentWord.TabWord[kata.Length];
            kata.Length += 1;
        }
    }
    else {
        kata = currentWord;
    }
    return kata;
}

Word inputpass() {
    Word kat;
    kat.Length = 0;
    STARTWORDPengguna();
    ADV();
    int panjang = currentWord.Length;
    if (panjang >= 20) {
        while (kat.Length < 20) {
            kat.TabWord[kat.Length] = currentWord.TabWord[kat.Length];
            kat.Length += 1;
        }
    }
    else {
        kat = currentWord;
    }
    return kat;
}

Word inputbio() {
    Word kat;
    kat.Length = 0;
    STARTWORDPengguna();
    ADV();
    int panjang = currentWord.Length;
    if (panjang >= 135) {
        while (kat.Length < 135) {
            kat.TabWord[kat.Length] = currentWord.TabWord[kat.Length];
            kat.Length += 1;
        }
    }
    else {
        kat = currentWord;
    }
    return kat;
}

Word inputWeton() {
    STARTWORDPengguna();
    ADV();
    Word hari;
    hari.Length = 0;
    boolean valid = false;
    while (valid == false) {
        if (currentWord.Length > 0) {
            if (currentWord.TabWord[0] == 'p' || currentWord.TabWord[0] == 'P') {
                hari.Length += 1;
                hari.TabWord[0] = 'P';
                if (currentWord.TabWord[1] == 'A' || currentWord.TabWord[1] == 'a') {
                    hari.Length += 1;
                    hari.TabWord[1] = 'a';
                    if (currentWord.TabWord[2] == 'H' || currentWord.TabWord[2] == 'h') {
                        hari.Length += 1;
                        hari.TabWord[2] = 'h';
                        if (currentWord.TabWord[3] == 'I' || currentWord.TabWord[3] == 'i') {
                            hari.Length += 1;
                            hari.TabWord[3] = 'i';
                            if (currentWord.TabWord[4] == 'N' || currentWord.TabWord[4] == 'n') {
                                hari.Length += 1;
                                hari.TabWord[4] = 'n';
                                if (currentWord.TabWord[5] == 'G' || currentWord.TabWord[5] == 'g') {
                                    hari.Length += 1;
                                    hari.TabWord[5] = 'g';
                                    if (currentWord.Length == 6) {
                                        return hari;
                                    }
                                }
                            }
                        }
                    }
                }
                else if (currentWord.TabWord[1] == 'O' || currentWord.TabWord[1] == 'o') {
                    hari.Length += 1;
                    hari.TabWord[1] = 'o';
                    if (currentWord.TabWord[2] == 'N' || currentWord.TabWord[2] == 'n') {
                        hari.Length += 1;
                        hari.TabWord[2] = 'n';
                        if (currentWord.Length == 3) {
                            return hari;
                        }
                    }
                }
            }
            if (currentWord.TabWord[0] == 'K' || currentWord.TabWord[0] == 'k') {
                hari.Length += 1;
                hari.TabWord[0] = 'K';
                if (currentWord.TabWord[1] == 'L' || currentWord.TabWord[1] == 'l') {
                    hari.Length += 1;
                    hari.TabWord[1] = 'l';
                    if (currentWord.TabWord[2] == 'I' || currentWord.TabWord[2] == 'i') {
                        hari.Length += 1;
                        hari.TabWord[2] = 'i';
                        if (currentWord.TabWord[3] == 'W' || currentWord.TabWord[3] == 'w') {
                            hari.Length += 1;
                            hari.TabWord[3] = 'w';
                            if (currentWord.TabWord[4] == 'O' || currentWord.TabWord[4] == 'o') {
                                hari.Length += 1;
                                hari.TabWord[4] = 'o';
                                if (currentWord.TabWord[5] == 'N' || currentWord.TabWord[5] == 'n') {
                                    hari.Length += 1;
                                    hari.TabWord[5] = 'n';
                                    if (currentWord.Length == 6) {
                                        return hari;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (currentWord.TabWord[0] == 'L' || currentWord.TabWord[0] == 'l') {
                hari.Length += 1;
                hari.TabWord[0] = 'L';
                if (currentWord.TabWord[1] == 'E' || currentWord.TabWord[1] == 'e') {
                    hari.Length += 1;
                    hari.TabWord[1] = 'e';
                    if (currentWord.TabWord[2] == 'G' || currentWord.TabWord[2] == 'g') {
                        hari.Length += 1;
                        hari.TabWord[2] = 'g';
                        if (currentWord.TabWord[3] == 'I' || currentWord.TabWord[3] == 'i') {
                            hari.Length += 1;
                            hari.TabWord[3] = 'i';
                            if (currentWord.Length == 4) {
                                return hari;
                            }
                        }
                    }
                }
            }
            if (currentWord.TabWord[0] == 'W' || currentWord.TabWord[0] == 'w') {
                hari.Length += 1;
                hari.TabWord[0] = 'W';
                if (currentWord.TabWord[1] == 'A' || currentWord.TabWord[1] == 'a') {
                    hari.Length += 1;
                    hari.TabWord[1] = 'a';
                    if (currentWord.TabWord[2] == 'G' || currentWord.TabWord[2] == 'g') {
                        hari.Length += 1;
                        hari.TabWord[2] = 'g';
                        if (currentWord.TabWord[3] == 'E' || currentWord.TabWord[3] == 'e') {
                            hari.Length += 1;
                            hari.TabWord[3] = 'e';
                            if (currentWord.Length == 4) {
                                return hari;
                            }
                        }
                    }
                }
            }
            printf("Hari yang anda masukkan salah, masukkan kembali\n");
            hari.Length = 0;
            printf("Masukkan weton: ");
            currentWord.Length = 0;
            STARTWORDPengguna();
            ADV();
        }
        else {
            return hari;
        }
    }
}

boolean inputHP(Word nomor) {
    boolean valid = true;
    for (int i = 0; i < nomor.Length; i++) {
        int angka = (int)(nomor.TabWord[i]);
        if ((48 <= angka) && (angka <= 57)) {
            valid = true;
        }
        else {
            return false;
        }
    }
    return true;
}

void ReadPengguna(Pengguna* p, databaseprofil* l) {
    CreatePengguna(p);
    boolean namavalid = false;
    while (namavalid == false)
    {
        printf("Silahkan masukkan username: ");
        Word kata = inputusername();
        int sama = 0;
        for (int i = 0; i < listLength(l); i++) {
            Word name = nama(*l, i);
            if (isWordEqual(name, kata)) {
                sama += 1;
            }
        }
        if (sama > 0) {
            printf("Username telah digunakan, silahkan masukkan yang lain\n");
            return;
        }
        else {
            NAMA(*p) = kata;
            namavalid = true;
        }
    }
    printf("Silahkan masukkan password: ");
    Word password = inputpass();
    PASSWORD(*p) = password;
    JENIS(*p) = 0;
    insertLast(l, *p);
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
    printf("Profil: \n");
    displayphoto(PROFIL(p));
}
/* Proses : Informasi pengguna ditulis satu persatu dan diaFkhiri dengan newline */

boolean isWordEqual(Word uname1, Word uname2) {
    int count = 0;
    if (uname1.Length != uname2.Length) {
        return false;
        printf("%d\n", uname1.Length);
        printf("%d\n", uname2.Length);
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

void insertLast(databaseprofil* l, Pengguna val) {
    l->contents[listLength(l)] = val;
}

int listLength(databaseprofil* l) {
    boolean ketemu = false;
    int length = 0;
    while (length < CAPACITY && ketemu == false) {
        if (nama(*l, length).Length == 0) {
            ketemu = true;
        }
        else {
            length += 1;
        }
    }
    return length;
}

void listLengthvoid(databaseprofil* l, int* val) {
    boolean ketemu = false;
    int length = 0;
    while (length < CAPACITY && ketemu == false) {
        if (nama(*l, length).TabWord[0] == ' ') {
            ketemu = true;
        }
        else {
            length += 1;
        }
    }
    *val = length;
}

void createDatabase(databaseprofil* l) {
    int i;
    for (i = 0; i < CAPACITY; i++) {
        nama(*l, i).Length = 0;
    }
}

int login(databaseprofil* data) {
    Word uname;
    printf("Silahkan masukkan username: ");
    STARTWORDPengguna();
    ADV();
    for (int i = 0; i < listLength(data); i++) {
        if (isWordEqual(currentWord, nama(*data, i))) {
            boolean passwordbetul = false;
            while (passwordbetul == false) {
                printf("Silahkan masukkan password: ");
                // printf("\n");
                STARTWORDPengguna();
                ADV();
                if (isWordEqual(currentWord, password(*data, i))) {
                    printf("Selamat datang, ");
                    printWord(nama(*data,i));
                    printf("\n");
                    return i;
                }
                else {
                    printf("Salah bos ulang kembali mengisi password\n");
                }
            }
        }
    }
    printf("Maaf, username yang anda masukan tidak ada\n");
    return -1;
}


void cekProfil(int idx, databaseprofil* data) {
    if (idx == -1) {
        printf("Username tidak ditemukan\n");
    }
    else {
        displayPengguna(data->contents[idx]);
    }
}

int getId(databaseprofil* l, Word username) {
    for (int i = 0; i < listLength(l); i++) {
        if (isWordEqual(nama(*l, i), username)) {
            return i;
        }
    }
    return -1;
}

void ubahProfil(databaseprofil* l, int id) {
    Word biobefore;
    Word hpbefore;
    Word kata;
    printf("Masukkan bio: ");
    kata.Length = 0;
    currentWord.Length = 0;
    kata = inputbio();
    biobefore = bio(*l,id);
    if (kata.Length > 0) {
        bio(*l, id) = kata;
    }
    else {
        bio(*l,id) = biobefore;
    }
    printf("Masukkan weton: ");
    kata.Length = 0;
    kata = inputWeton();
    if (kata.Length > 0) {
        weton(*l, id) = kata;
    }
    printf("Masukkan No HP: ");
    hpbefore = hp(*l,id);
    STARTWORDPengguna();
    ADV();
    boolean isValid = inputHP(currentWord);
    while (isValid == false) {
        printf("No HP salah, masukkan no HP kembali\n");
        printf("Masukkan No HP: ");
        STARTWORDPengguna();
        ADV();
        isValid = inputHP(currentWord);
    }
    
    if (isValid == true) {
        if(currentWord.Length > 0) {
            if (currentWord.Length > 15) {
                hp(*l,id).Length = 0;
                for (int i = 0; i < 15; i++) {
                    hp(*l,id).TabWord[i] = currentWord.TabWord[i];
                    hp(*l,id).Length += 1;
                }
            }
            else {
                hp(*l,id) = currentWord;
            }
        }
        else {
            hp(*l, id) = hpbefore;
        }
    }
}

void STARTWORDPengguna()
{
    /* I.S. : currentChar sembarang
       F.S. : EndWord = true, dan currentChar = MARK;
              atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
              currentChar karakter pertama sesudah karakter terakhir kata */
    START();
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWordPengguna();
    }
}

void CopyWordPengguna() {
    /* Mengakuisisi kata, menyimpan dalam currentWord
       I.S. : currentChar adalah karakter pertama dari kata
       F.S. : currentWord berisi kata yang sudah diakuisisi;
              currentChar = BLANK atau currentChar = MARK;
              currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
              Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
    currentWord.Length = 0;
    while (currentChar != MARK)
    {
        if (currentWord.Length < NMax)
        { // jika lebih akan terpotong
            currentWord.TabWord[currentWord.Length++] = currentChar;
            ADV();
        }
        else
            break;
    }
}

boolean isCheck(Word s) {
    char* kata = "LIHAT_PROFIL";
    if (s.Length > 12) {
        for (int i = 0; i < 12; i++) {
            if (s.TabWord[i] != kata[i]) {
                return false;
            }
        }
    }
    else {
        return false;
    }
    return true;
}

Word getUser(Word kata) {
    Word username;
    username.Length = 0;
    for (int i = 13; i < kata.Length; i++) {
        username.TabWord[username.Length] = kata.TabWord[i];
        username.Length += 1;
    }
    return username;
}

void ubahfotoprofil(databaseprofil* l, int id) {
    STARTWORDPengguna();
    ADV();
    int idx = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            profil(*l, id).mem[i][j].warna = currentWord.TabWord[idx];
            idx += 2;
            profil(*l, id).mem[i][j].simbol = currentWord.TabWord[idx];
            idx += 2;
        }
    }
}

void LoadPengguna(databaseprofil* l, Word path) {
    FILE* file = fopen(path.TabWord, "r");
    char line[300];

    if (file == NULL) {
        printf("File tidak ditemukan\n");
        exit(EXIT_FAILURE);
    }

    fgets(line, 300, file);
    StringToWord(line, &currentWord);
    int banyak_pengguna = WordToInt(removeNewline(currentWord));
    for (int i = 0; i < banyak_pengguna; i++) {
        Pengguna user;
        CreatePengguna(&user);

        fgets(line, 300, file);
        StringToWord(line, &currentWord);
        NAMA(user) = removeNewline(currentWord);

        fgets(line, 300, file);
        StringToWord(line, &currentWord);
        PASSWORD(user) = removeNewline(currentWord);

        fgets(line, 300, file);
        StringToWord(line, &currentWord);
        BIO(user) = removeNewline(currentWord);

        fgets(line, 300, file);
        StringToWord(line, &currentWord);
        HP(user) = removeNewline(currentWord);

        fgets(line, 300, file);
        StringToWord(line, &currentWord);
        WETON(user) = removeNewline(currentWord);

        fgets(line, 300, file);
        StringToWord(line, &currentWord);
        Word status;
        status = removeNewline(currentWord);
        if (isValid(status,"Privat")) {
            JENIS(user) = 1;
        }
        else {
            JENIS(user) = 0;
        }
        int idx = 0;
        fgets(line, 300, file);
        StringToWord(line,&currentWord);
        for(int i = 0; i < 5; i++) {
            PROFIL(user).mem[0][i].warna = currentWord.TabWord[idx];
            idx += 2;
            PROFIL(user).mem[0][i].simbol = currentWord.TabWord[idx];
            idx += 2;
        }
        idx = 0;
        fgets(line, 300, file);
        StringToWord(line,&currentWord);
        for(int i = 0; i < 5; i++) {
            PROFIL(user).mem[1][i].warna = currentWord.TabWord[idx];
            idx += 2;
            PROFIL(user).mem[1][i].simbol = currentWord.TabWord[idx];
            idx += 2;
        }
        idx = 0;
        fgets(line, 300, file);
        StringToWord(line,&currentWord);
        for(int i = 0; i < 5; i++) {
            PROFIL(user).mem[2][i].warna = currentWord.TabWord[idx];
            idx += 2;
            PROFIL(user).mem[2][i].simbol = currentWord.TabWord[idx];
            idx += 2;
        }
        idx = 0;
        fgets(line, 300, file);
        StringToWord(line,&currentWord);
        for(int i = 0; i < 5; i++) {
            PROFIL(user).mem[3][i].warna = currentWord.TabWord[idx];
            idx += 2;
            PROFIL(user).mem[3][i].simbol = currentWord.TabWord[idx];
            idx += 2;
        }
        idx = 0;
        fgets(line, 300, file);
        StringToWord(line,&currentWord);
        for(int i = 0; i < 5; i++) {
            PROFIL(user).mem[4][i].warna = currentWord.TabWord[idx];
            idx += 2;
            PROFIL(user).mem[4][i].simbol = currentWord.TabWord[idx];
            idx += 2;
        }
        idx = 0;

        insertLast(l, user);
    }

    fclose(file);
}
// boolean isChangeValid(Word kata) {
//     int beda = 0;
//     for (int i = 0; i < )
// }