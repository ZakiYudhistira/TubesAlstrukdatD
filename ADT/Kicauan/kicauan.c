#include "kicauan.h"
#include "../Perintah/wordmachine.h"
#include "../Mesin Karakter/charmachine.h"
#include "../Perintah/perintah.h"
#include "../Pertemanan/pertemanan.h"
#include "../Pengguna/pengguna.h"
#include <stdio.h>
#include <stdlib.h>

/* *** Kreator *** */
void CreateKicauan(Kicauan* k) {
    DATETIME D;
    ID_KICAU(*k) = 0;
    TEXT_KICAU(*k) = currentWord;
    LIKE_KICAU(*k) = 0;
    AUTHOR_KICAU(*k) = currentWord;
    GetLocalDATETIME(&D);
    DATETIME_KICAU(*k) = D;
}
/* I.S. sembarang */
/* F.S. Sebuah k kosong dan datetime now*/

void LoadKicauan(ListDinKicau* l, Word path) {
    FILE* file = fopen(path.TabWord, "r");
    char line[300];

    if (file == NULL) {
        printf("File tidak ditemukan\n");
        exit(EXIT_FAILURE);
    }

    fgets(line, 300, file);
    StringToWord(line, &currentWord);
    int banyak_kicau = WordToInt(removeNewline(currentWord));
    for (int i = 0; i < banyak_kicau; i++) {
        Kicauan k;
        CreateKicauan(&k);

        fgets(line, 300, file);
        StringToWord(line, &currentWord);
        ID_KICAU(k) = WordToInt(removeNewline(currentWord));

        fgets(line, 300, file);
        StringToWord(line, &currentWord);
        TEXT_KICAU(k) = removeNewline(currentWord);

        fgets(line, 300, file);
        StringToWord(line, &currentWord);
        LIKE_KICAU(k) = WordToInt(removeNewline(currentWord));

        fgets(line, 300, file);
        StringToWord(line, &currentWord);
        AUTHOR_KICAU(k) = removeNewline(currentWord);

        fgets(line, 300, file);
        StringToWord(line, &currentWord);
        DATETIME_KICAU(k) = WordToTime(removeNewline(currentWord));

        InsertLastKicau(l, k);
    }

    fclose(file);
}
/* I.S. sembarang */
/* F.S. Sebuah k yang diload dari kicauan.config*/

/* *** Display Pengguna *** */
void DisplayKicauan(Kicauan k) {
    printf("| ID = %d\n", ID_KICAU(k));
    printf("| ");
    printWord(AUTHOR_KICAU(k));
    printf("\n");
    printf("| ");
    printWord(TimeToWord(DATETIME_KICAU(k)));
    printf("\n");
    printf("| ");
    printWord(TEXT_KICAU(k));
    printf("\n");
    printf("| Disukai: %d\n", LIKE_KICAU(k));
}
/* Proses : Menuliskan isi Kicauan dengan traversal. Informasi kicauan
   ditulis satu persatu dan diakhiri dengan newline */


void CreateListKicauan(ListDinKicau* l, int capacity) {
    BUFFER_KICAU(*l) = malloc(capacity * sizeof(ElTypeKicau));
    CAPACITY_KICAU(*l) = capacity;
    NEFF_KICAU(*l) = 0;
}
/* I.S. sembarang */
/* F.S. Terbentuk ListDinKicau kosong dengan kapasitas capacity */

   /* ********** SELEKTOR (TAMBAHAN) ********** */
   /* *** Banyaknya elemen *** */
int ListKicauLength(ListDinKicau l) {
    return NEFF_KICAU(l);
}
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */

boolean isIdKicauValid(ListDinKicau l, int idKicau) {
    int i = 0;
    while (ID_KICAU(ELMT_KICAU(l, i)) != idKicau && i < ListKicauLength(l)) {
        i++;
    }

    return i != ListKicauLength(l);
}
// I.S. l terdefinisi
// F.S. mengembalikan true jika idKicau ada di list kicauan

int ListKicauMaxId(ListDinKicau l) {
    int max = 0;
    for (int i = 0; i < ListKicauLength(l); i++) {
        if (ID_KICAU(ELMT_KICAU(l, i)) > max) {
            max = ID_KICAU(ELMT_KICAU(l, i));
        }
    }
    return max;
}
/* Mengirimkan nilai id terbesar dari list l */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void InsertLastKicau(ListDinKicau* l, ElTypeKicau val) {
    if (NEFF_KICAU(*l) == CAPACITY_KICAU(*l)) {
        ExpandListKicau(l, 10);
    }
    ELMT_KICAU(*l, NEFF_KICAU(*l)) = val;
    NEFF_KICAU(*l)++;
}
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void ExpandListKicau(ListDinKicau* l, int num) {
    BUFFER_KICAU(*l) = realloc(BUFFER_KICAU(*l), (CAPACITY_KICAU(*l) + num) * sizeof(ElTypeKicau));
    CAPACITY_KICAU(*l) += num;
}
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */


boolean isSuka(Word option) {
    char* suka = "SUKA_KICAUAN";
    int i = 0;

    if (option.Length > 13) {
        for (i = 0; i < 12; i++) {
            if (option.TabWord[i] != suka[i]) {
                return false;
            }
        }
    }
    else {
        return false;
    }
    return true;
}
// I.S. option terdefinisi
// F.S. mengembalikan true jika option adalah "SUKA_KICAUAN [IDKicau]"

boolean isUbah(Word option) {
    char* ubah = "UBAH_KICAUAN";
    int i = 0;

    if (option.Length > 13) {
        for (i = 0; i < 12; i++) {
            if (option.TabWord[i] != ubah[i]) {
                return false;
            }
        }
    }
    else {
        return false;
    }

    return true;

}
// I.S. option terdefinisi
// F.S. mengembalikan true jika option adalah "UBAH_KICAUAN [IDKicau]"

ListDinKicau SortedKicauan(ListDinKicau l) {
    ListDinKicau sorted;
    CreateListKicauan(&sorted, CAPACITY_KICAU(l));
    for (int i = 0; i < ListKicauLength(l); i++) {
        InsertLastKicau(&sorted, ELMT_KICAU(l, i));
    }
    for (int i = 0; i < ListKicauLength(sorted); i++) {
        for (int j = i + 1; j < ListKicauLength(sorted); j++) {
            if (DLT(DATETIME_KICAU(ELMT_KICAU(sorted, i)), DATETIME_KICAU(ELMT_KICAU(sorted, j)))) {
                Kicauan temp = ELMT_KICAU(sorted, i);
                ELMT_KICAU(sorted, i) = ELMT_KICAU(sorted, j);
                ELMT_KICAU(sorted, j) = temp;
            }
        }
    }
    return sorted;
}
// I.S. l terdefinisi
// F.S. mengembalikan list kicauan yang sudah terurut berdasarkan waktu terbaru

// Command Handler
void HandleKicau(ListDinKicau* l, Word username, int* idKicauan) {
    Kicauan k;
    DATETIME D;
    CreateKicauan(&k);

    printf("Masukan kicauan:\n");
    currentWord.TabWord[0] = '\0';
    currentWord.Length = 0;
    perintah(280, false);
    ADV();

    while (isBlanks(currentWord)) {
        printf("\n");
        printf("Kicauan tidak boleh hanya berisi spasi!\n\n");
        printf("Masukan kicauan:\n");
        perintah(280, false);
        ADV();
    }

    ID_KICAU(k) = *idKicauan;
    TEXT_KICAU(k) = currentWord;
    LIKE_KICAU(k) = 0;
    AUTHOR_KICAU(k) = username;
    GetLocalDATETIME(&D);
    DATETIME_KICAU(k) = D;
    printf("\n");
    printf("Selamat! kicauan telah diterbitkan!\n");
    printf("Detil kicauan:\n");
    DisplayKicauan(k);
    printf("\n");
    InsertLastKicau(l, k);
    *idKicauan = *idKicauan + 1;
}

void HandleKicauan(ListDinKicau l, Word username, Matrix_pertemanan m, databaseprofil p) {
    for (int i = 0; i < ListKicauLength(l); i++) {
        if (isTeman(m, getId(&p, username), getId(&p, AUTHOR_KICAU(ELMT_KICAU(l, i))))) {
            DisplayKicauan(ELMT_KICAU(l, i));
            printf("\n");
        }
    }
}

void HandleSukaKicau(ListDinKicau* l, int idKicauan, Word username, Matrix_pertemanan m, databaseprofil p) {
    int i = 0;
    while (ID_KICAU(ELMT_KICAU(*l, i)) != idKicauan && i < ListKicauLength(*l)) {
        i++;
    }

    if (i == ListKicauLength(*l)) {
        printf("Tidak ditemukan kicauan dengan ID = %d\n\n", idKicauan);
    }
    else {
        if (isTeman(m, getId(&p, username), getId(&p, AUTHOR_KICAU(ELMT_KICAU(*l, i)))) || jenis(p, getId(&p, AUTHOR_KICAU(ELMT_KICAU(*l, i)))) == 0) {
            LIKE_KICAU(ELMT_KICAU(*l, i))++;
            printf("Selamat! Kicauan telah disukai!\n");
            printf("Detil kicauan:\n");
            DisplayKicauan(ELMT_KICAU(*l, i));
            printf("\n");
        }
        else {
            printf("Wah, kicauan tersebut dibuat oleh akun privat! Ikuti akun itu dulu ya\n");
        }
    }
}

void HandleUbahKicau(ListDinKicau* l, Word username, int idKicauan) {
    int i = 0;
    while (ID_KICAU(ELMT_KICAU(*l, i)) != idKicauan && i < ListKicauLength(*l)) {
        i++;
    }

    if (i == ListKicauLength(*l)) {
        printf("Tidak ditemukan kicauan dengan ID = %d\n\n", idKicauan);
    }
    else {
        if (isSame(AUTHOR_KICAU(ELMT_KICAU(*l, i)), username)) {
            DATETIME D;
            printf("Masukan kicauan baru:\n");
            currentWord.TabWord[0] = '\0';
            currentWord.Length = 0;
            perintah(280, false);
            ADV();

            while (isBlanks(currentWord)) {
                printf("\n");
                printf("Kicauan tidak boleh hanya berisi spasi!\n\n");
                printf("Masukan kicauan baru:\n");
                perintah(280, false);
                ADV();
            }

            TEXT_KICAU(ELMT_KICAU(*l, i)) = currentWord;
            GetLocalDATETIME(&D);
            DATETIME_KICAU(ELMT_KICAU(*l, i)) = D;
            printf("\n");
            printf("Selamat! kicauan telah diterbitkan!\n");
            printf("Detil kicauan:\n");
            DisplayKicauan(ELMT_KICAU(*l, i));
            printf("\n");
        }
        else {
            printf("Kicauan dengan ID = %d bukan milikmu!\n", idKicauan);
        }
    }
}