#include <stdio.h>
#include <stdlib.h>
#include "utas.h"
#include "../Perintah/perintah.h"
#include "../Kicauan/kicauan.h"
#include "../Pengguna/pengguna.h"
#include "../Pertemanan/pertemanan.h"

Address newNode_Utas(Word val, DATETIME date) {
    Address p = (Address)malloc(sizeof(Node));
    if (p != NULL) {
        INFO(p) = val;
        DATE(p) = date;
        NEXT(p) = NULL;
    }
    return p;
}

// Untuk input == "UTAS [IDKicau]"
void createEmptyUtas(Word User, int IDKicau, ListDinUtas* dbUtasUser, ListDinKicau* l) {
    int IDUtas = getIDUtas(IDKicau, *dbUtasUser);

    if (!isIdKicauValid(*l, IDKicau)) {
        printf("Kicauan tidak ditemukan.\n");
    }
    else if (!isSame(User, AUTHOR_KICAU(ELMT_KICAU(*l, IDKicau - 1)))) {
        printf("Kicauan ini bukan milik anda!\n");
    }
    else if (IDUtas != -1) {
        printf("Kicauan telah memiliki utas dengan IDUtas %d!\n", IDUtas);
    }
    else {
        Utas U;

        LENGTH_UTAS(U) = 0;
        IDKICAU_UTAS(U) = IDKicau;
        FIRST_UTAS(U) = NULL;
        AUTHOR_UTAS(U) = User;

        printf("Utas berhasil dibuat!\n");

        boolean lanjut = true;

        while (lanjut) {
            printf("Masukkan kicauan:\n");

            Word text;
            perintah(100, 0);
            ADV();
            text = currentWord;

            DATETIME D;
            GetLocalDATETIME(&D);
            insertLastUtas(&U, text, D);
            LENGTH_UTAS(U) += 1;

            printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK)\n");

            perintah(100, 0);
            ADV();
            text = currentWord;

            if (isValid(text, "NO")) {
                lanjut = false;
            }
            else {
                printf("GAS LANJUT\n");
            }
        }

        insertLastListUtas(&U, dbUtasUser);

        printf("Utas selesai!\n");
    }
}
// Untuk input == "CETAK_UTAS [IDUtas]"
void displayUtas(Word User, int IDUtas, ListDinUtas* dbUtasUser, ListDinKicau* l, databaseprofil db, Matrix_pertemanan m) {
    if (IDUtas > NEFF_LISTUTAS(*dbUtasUser)) {
        printf("Utas tidak ditemukan\n");
    }
    else {
        Utas U = ELMT_LISTUTAS(*dbUtasUser, IDUtas - 1);

        int idCurrUser = getId(&db, User);
        int idAuthor = getId(&db, AUTHOR_UTAS(U));

        if (!isTeman(m, idCurrUser, idAuthor) && (jenis(db, idAuthor) == 1)) {
            printf("Akun yang membuat utas ini adalah akun privat! Ikuti dahulu akun ini untuk melihat utasnya!\n");
        }
        else {
            Kicauan k;
            Word author;

            int idKicauan = IDKICAU_UTAS(U);

            DisplayKicauan(ELMT_KICAU(*l, idKicauan - 1));

            Address p = FIRST_UTAS(U);
            for (int i = 0; i < LENGTH_UTAS(U); i++) {
                printf("\n    | INDEX = %d", (i + 1));
                printf("\n    | "); printWord(AUTHOR_UTAS(U));
                printf("\n    | "); TulisDATETIME(DATE(p));
                printf("\n    | "); printWord(INFO(p));
                printf("\n");
                p = NEXT(p);
            }
        }

    }
}
// Untuk input == "SAMBUNG_UTAS [IDUtas] [index]"
void sambungUtas(Word User, int IDUtas, int index, ListDinUtas* dbUtasUser) {
    if (IDUtas > NEFF_LISTUTAS(*dbUtasUser)) {
        printf("Utas tidak ditemukan\n");
    }
    else {
        Utas U;
        U = ELMT_LISTUTAS(*dbUtasUser, IDUtas);

        if (index > LENGTH_UTAS(U)) {
            printf("Index terlalu tinggi!\n", index);
        }
        else if (!isSame(User, AUTHOR_UTAS(U))) {
            printf("Anda tidak bisa menghapus kicauan dalam utas ini!\n");
        }
        else {
            deleteAtUtas(&U, index);
            printf("Masukkan kicauan:\n");

            Word text;
            perintah(100, 0);
            ADV();
            text = currentWord;

            DATETIME D;
            GetLocalDATETIME(&D);
            insertAtUtas(&U, text, D, index + 1);
            LENGTH_UTAS(U) += 1;
        }
    }
}
// Untuk input == "HAPUS_UTAS [IDUtas] [index]"
void deleteUtas(Word User, int IDUtas, int index, ListDinUtas* dbUtasUser) {
    if (IDUtas > NEFF_LISTUTAS(*dbUtasUser)) {
        printf("Utas tidak ditemukan\n");
    }
    else if (index == 0) {
        printf("Anda tidak bisa menghapus kicauan utama!\n");
    }
    else {
        Utas U;
        U = ELMT_LISTUTAS(*dbUtasUser, IDUtas);

        if (index > LENGTH_UTAS(U)) {
            printf("Kicauan sambungan dengan index %d tidak ditemukan pada utas!\n", index);
        }
        else if (!isSame(User, AUTHOR_UTAS(U))) {
            printf("Anda tidak bisa menghapus kicauan dalam utas ini!\n");
        }
        else {
            deleteAtUtas(&U, index);
        }
    }
}

/* Primitive Function Utas */
void insertFirstUtas(Utas* U, Word val, DATETIME D) {
    Address p = newNode_Utas(val, D);

    if (LENGTH_UTAS(*U) == 0) {
        FIRST_UTAS(*U) = p;
    }
    else {
        Address f = FIRST_UTAS(*U);
        NEXT(p) = NEXT(f);
        FIRST_UTAS(*U) = p;
    }

    LENGTH_UTAS(*U)++;
}
void insertAtUtas(Utas* U, Word val, DATETIME D, int idx) {
    if (idx == 0) {
        insertFirstUtas(U, val, D);
    }
    else {
        Address new = newNode_Utas(val, D);
        Address p = FIRST_UTAS(*U);

        for (int i = 1; i < idx; i++) {
            p = NEXT(p);
        }

        NEXT(new) = NEXT(p);
        NEXT(p) = new;

        LENGTH_UTAS(*U)++;
    }
}
void insertLastUtas(Utas* U, Word val, DATETIME D) {
    insertAtUtas(U, val, D, LENGTH_UTAS(*U));
}
void deleteFirstUtas(Utas* U) {
    Address p = FIRST_UTAS(*U);

    FIRST_UTAS(*U) = NEXT(p);
    free(p);

    LENGTH_UTAS(*U)--;
}
void deleteAtUtas(Utas* U, int idx) {
    if (idx + 1 == 1) {
        deleteFirstUtas(U);
    }
    else {
        Address p1 = FIRST_UTAS(*U);
        Address p2 = NEXT(p1);

        for (int i = 2; i < idx; i++) {
            p1 = NEXT(p1);
            p2 = NEXT(p2);
        }

        NEXT(p1) = NEXT(p2);
        free(p2);

        LENGTH_UTAS(*U)--;
    }
}
void deleteLastUtas(Utas* U) {
    deleteAtUtas(U, LENGTH_UTAS(*U));
}

/* Primitive Function ListDin Utas*/
void initListDinUtas(ListDinUtas* dbUtasUser) {
    NEFF_LISTUTAS(*dbUtasUser) = 0;
}
void expandListUtas(int num, ListDinUtas* dbUtasUser) {
    BUFFER_LISTUTAS(*dbUtasUser) = realloc(BUFFER_LISTUTAS(*dbUtasUser), (CAPACITY_LISTUTAS(*dbUtasUser) + num) * sizeof(Utas));
    CAPACITY_LISTUTAS(*dbUtasUser) += num;
}
void insertLastListUtas(Utas* val, ListDinUtas* dbUtasUser) {
    if (NEFF_LISTUTAS(*dbUtasUser) == CAPACITY_LISTUTAS(*dbUtasUser)) {
        expandListUtas(10, dbUtasUser);
    }
    BUFFER_LISTUTAS(*dbUtasUser)[NEFF_LISTUTAS(*dbUtasUser)] = *val;
    NEFF_LISTUTAS(*dbUtasUser) += 1;
}

void loadUtas(ListDinUtas* dbUtasUser, Word path) {
    FILE* file = fopen(path.TabWord, "r");
    char line[300];

    if (file == NULL) {
        printf("File tidak ditemukan\n");
        exit(EXIT_FAILURE);
    }

    fgets(line, 300, file);
    StringToWord(line, &currentWord);
    int banyak_kicauan_utas = WordToInt(removeNewline(currentWord));
    for (int i = 0; i < banyak_kicauan_utas; i++) {
        fgets(line, 300, file);
        StringToWord(line, &currentWord);
        int idKicau = WordToInt(removeNewline(currentWord));

        fgets(line, 300, file);
        StringToWord(line, &currentWord);
        int banyak_utas = WordToInt(removeNewline(currentWord));

        Utas U;
        IDKICAU_UTAS(U) = idKicau;
        LENGTH_UTAS(U) = 0;

        for (int j = 0; j < banyak_utas; j++) {

            fgets(line, 300, file);
            StringToWord(line, &currentWord);
            Word text = removeNewline(currentWord);

            fgets(line, 300, file);
            StringToWord(line, &currentWord);
            Word author = removeNewline(currentWord);
            AUTHOR_UTAS(U) = author;

            fgets(line, 300, file);
            StringToWord(line, &currentWord);
            DATETIME date = WordToTime(removeNewline(currentWord));

            insertLastUtas(&U, text, date);
        }

        insertLastListUtas(&U, dbUtasUser);
    }

    fclose(file);
}

// Fungsi Bantuan
int getIDUtas(int IDKicau, ListDinUtas dbUtasUser) {
    for (int i = 0; i < NEFF_LISTUTAS(dbUtasUser); i++) {
        Utas U;
        U = ELMT_LISTUTAS(dbUtasUser, i);

        if (IDKICAU_UTAS(U) == IDKicau) {
            return i;
        }
    }

    return -1;
}
boolean isUtas(Word option) {
    char* suka = "UTAS";
    int i = 0;

    if (option.Length > 5) {
        for (i = 0; i < 4; i++) {
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
boolean isSambungUtas(Word option) {
    char* suka = "SAMBUNG_UTAS";
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
boolean isHapusUtas(Word option) {
    char* suka = "HAPUS_UTAS";
    int i = 0;

    if (option.Length > 11) {
        for (i = 0; i < 10; i++) {
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
boolean isCetakUtas(Word option) {
    char* suka = "CETAK_UTAS";
    int i = 0;

    if (option.Length > 11) {
        for (i = 0; i < 10; i++) {
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