#include <stdio.h>
#include <stdlib.h>
#include "utas.h"
#include "../Perintah/perintah.h"

ListDinUtas dbUtasUser;

Address newNode(ElType val) {
    Address p = (Address)malloc(sizeof(Node));
    if (p!=NULL){
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}

void CreateEmptyUtas(Utas* U, int IDKicau) {
    LENGTH(*U) = 0;
    IDKicau(*U) = IDKicau;
    FIRST(*U) = NULL;

    printf("Utas berhasil dibuat!\n");

    boolean lanjut = true;

    while (lanjut) {
        printf("Masukkan kicauan:\n");

        char* text;
        text = perintah();

        int len = LENGTH(*U);
        len += 1;
        
        insertAtUtas(U, text, len);

        printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK)\n");
        text = perintah();

        if (isValid(text, "NO")) {
            lanjut = false;
        } else {
            printf("hehe");
        }
    }

    InsertLastListUtas(*U);

    printf("Utas selesai!\n");
}

void insertFirstUtas(Utas *U, ElType val) {
    Address p = newNode(val);

    if (LENGTH(*U) == 0) {
        FIRST(*U) = p;    
    } else {
        Address f = FIRST(*U);
        NEXT(p) = NEXT(f);
        FIRST(*U) = p;
    }
}
void insertAtUtas(Utas *U, ElType val, int idx) {
    if (idx == 1) {
        insertFirstUtas(U, val);
    } else {
        Address new = newNode(val);
        Address p = FIRST(*U);

        for (int i = 2; i < idx; i++) {
            p = NEXT(p);
        }

        NEXT(new) = NEXT(p);
        NEXT(p) = new;
    }
}

void deleteFirstUtas(Utas *U, ElType *val) {
    Address p = FIRST(*U);
    *val = INFO(p);

    FIRST(*U) = NEXT(p);
    free(p);
}

void deleteAtUtas(Utas *U, ElType *val, int idx) {
    if (idx == 1) {
        deleteFirstUtas(U, val);
    } else {
        Address p1 = FIRST(*U);
        Address p2 = NEXT(p1);

        for (int i = 2; i < idx; i++) {
            p1 = NEXT(p1);
            p2 = NEXT(p2);
        }

        *val = INFO(p2);
        NEXT(p1) = NEXT(p2);
        free(p2);
    }
}

void displayUtas(int idx) {
    Utas U = dbUtasUser.buffer[idx];
    Address p = FIRST(U);

    for (int i = 0; i < LENGTH(U); i++) {
        printf("%s\n", INFO(p));
        p = NEXT(p);
    }
}

void ExpandListUtas(int num) {
    BUFFER_UTAS(dbUtasUser) = realloc(BUFFER_UTAS(dbUtasUser), (CAPACITY_UTAS(dbUtasUser) + num) * sizeof(Utas));
    CAPACITY_UTAS(dbUtasUser) += num;
}

void InsertLastListUtas(Utas val) {
    if (dbUtasUser.nEff == dbUtasUser.capacity) {
        ExpandListUtas(10);
    }
    dbUtasUser.buffer[NEFF_UTAS(dbUtasUser)] = val;
    dbUtasUser.nEff += 1;
}
