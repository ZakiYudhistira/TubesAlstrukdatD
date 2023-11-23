#include <stdio.h>
#include <stdlib.h>
#include "utas.h"
#include "../Perintah/perintah.h"
#include "../Kicauan/kicauan.h"

Address newNodeUtas(Word val, DATETIME date) {
    Address p = (Address)malloc(sizeof(Node));
    if (p != NULL) {
        INFO(p) = val;
        DATE(p) = date;
        NEXT(p) = NULL;
    }
    return p;
}

void CreateEmptyUtas(Utas* U, int IDKicau, ListDinUtas* dbUtasUser, ListDinKicau* l) {
    LENGTH(*U) = 0;
    IDKicau(*U) = IDKicau;
    FIRST(*U) = NULL;

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
        insertLastUtas(U, text, D);
        LENGTH(*U) += 1;

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

    InsertLastListUtas(U, dbUtasUser);

    printf("Utas selesai!\n");
}



void insertFirstUtas(Utas* U, Word val, DATETIME D) {
    Address p = newNodeUtas(val, D);

    if (LENGTH(*U) == 0) {
        FIRST(*U) = p;
    }
    else {
        Address f = FIRST(*U);
        NEXT(p) = NEXT(f);
        FIRST(*U) = p;
    }

    LENGTH(*U)++;
}
void insertAtUtas(Utas* U, Word val, DATETIME D, int idx) {
    if (idx == 0) {
        insertFirstUtas(U, val, D);
    }
    else {
        Address new = newNodeUtas(val, D);
        Address p = FIRST(*U);

        for (int i = 2; i < idx; i++) {
            p = NEXT(p);
        }

        NEXT(new) = NEXT(p);
        NEXT(p) = new;

        LENGTH(*U)++;
    }
}

void insertLastUtas(Utas* U, Word val, DATETIME D) {
    insertAtUtas(U, val, D, LENGTH(*U));
}

void deleteFirstUtas(Utas* U, Word* val) {
    Address p = FIRST(*U);
    *val = INFO(p);

    FIRST(*U) = NEXT(p);
    free(p);

    LENGTH(*U)--;
}

void deleteAtUtas(Utas* U, Word* val, int idx) {
    if (idx + 1 == 1) {
        deleteFirstUtas(U, val);
    }
    else {
        Address p1 = FIRST(*U);
        Address p2 = NEXT(p1);

        for (int i = 2; i < idx; i++) {
            p1 = NEXT(p1);
            p2 = NEXT(p2);
        }

        *val = INFO(p2);
        NEXT(p1) = NEXT(p2);
        free(p2);

        LENGTH(*U)--;
    }
}

void deleteLastUtas(Utas* U, Word* val) {
    deleteAtUtas(U, val, LENGTH(*U));
}

void displayUtas(int idx, ListDinUtas* dbUtasUser, ListDinKicau* l) {
    Utas U = BUFFER_UTAS(*dbUtasUser)[idx];
    Address p = FIRST(U);
    Kicauan k;
    Word author;

    int idKicauan = IDKicau(U);
    int i = 0;
    while (ID_KICAU(ELMT_KICAU(*l, i)) != idKicauan && i < ListKicauLength(*l)) {
        i++;
    }

    k = (Kicauan)ELMT_KICAU(*l, i);
    DisplayKicauan(ELMT_KICAU(*l, i));
    author = AUTHOR_KICAU(k);

    for (int i = 0; i < LENGTH(U); i++) {
        printf("    | INDEX = %d\n", i + 1);
        printf("    | "); printWord(author);
        printf("\n    | "); TulisDATETIME(DATE(p));
        printf("\n    | "); printWord(INFO(p));
        printf("\n\n");
        p = NEXT(p);
    }
}

void initListDinUtas(ListDinUtas* dbUtasUser) {
    NEFF_UTAS(*dbUtasUser) = 0;
}

void ExpandListUtas(int num, ListDinUtas* dbUtasUser) {
    BUFFER_UTAS(*dbUtasUser) = realloc(BUFFER_UTAS(*dbUtasUser), (CAPACITY_UTAS(*dbUtasUser) + num) * sizeof(Utas));
    CAPACITY_UTAS(*dbUtasUser) += num;
}

void InsertLastListUtas(Utas* val, ListDinUtas* dbUtasUser) {
    if (NEFF_UTAS(*dbUtasUser) == CAPACITY_UTAS(*dbUtasUser)) {
        ExpandListUtas(10, dbUtasUser);
    }
    BUFFER_UTAS(*dbUtasUser)[NEFF_UTAS(*dbUtasUser)] = *val;
    NEFF_UTAS(*dbUtasUser) += 1;
}

void LoadUtas(ListDinUtas* dbUtasUser, Word path) {
    FILE* file = fopen(WordToString(path), "r");
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
        IDKicau(U) = idKicau;
        LENGTH(U) = 0;

        for (int j = 0; j < banyak_utas; j++) {

            fgets(line, 300, file);
            StringToWord(line, &currentWord);
            Word text = removeNewline(currentWord);

            fgets(line, 300, file);
            StringToWord(line, &currentWord);
            Word author = removeNewline(currentWord);

            fgets(line, 300, file);
            StringToWord(line, &currentWord);
            DATETIME date = WordToTime(removeNewline(currentWord));

            insertLastUtas(&U, text, date);
        }

        InsertLastListUtas(&U, dbUtasUser);
    }

    fclose(file);
}