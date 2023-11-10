#include <stdio.h>
#include <stdlib.h>
#include "utas.h"

Utas dbUtasUser[20];
int lastID = 0;

Address newNode(ElType val) {
    Address p = (Address)malloc(sizeof(Node));
    if (p!=NULL){
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}

void CreateEmptyUtas(int IDKicau) {
    Utas U;
    LENGTH(U) = 0;
    IDKicau(U) = IDKicau;
    FIRST(U) = NULL;

    printf("Utas berhasil dibuat!\n");
    dbUtasUser[lastID] = U;

    boolean lanjut = true;

    // while (lanjut) {
    //     printf("Masukkan kicauan:\n");
    //     char b = 'a';
    //     printf("xs");
    //     LENGTH(U) = LENGTH(U) + 1;
    //     insertAtUtas(&U, b, LENGTH(U));

    //     printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK)\n");

    //     if (b == 'a') {
    //         lanjut = false;
    //     } else {
    //         printf("hehe");
    //     }
    // }

    printf("Utas selesai!\n");
}

void insertFirstUtas(Utas *U, ElType val) {
    Address p = newNode(val);

    if (LENGTH(*U) == 0) {
        FIRST(*U) = p;    
    } else {
        NEXT(p) = NEXT(FIRST(*U));
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

// void displayUtas(Utas U);