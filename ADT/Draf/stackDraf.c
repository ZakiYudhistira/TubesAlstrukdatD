#include "stackDraf.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Perintah/perintah.c"
#include "../Kicauan/kicauan.h"

StackDraf dbDrafUser[20];

void CreateEmpty(StackDraf *S) {
    IDXTOP(*S) = -1;
}

boolean IsEmpty(StackDraf S) {
    return IDXTOP(S) == -1;
}

boolean IsFull(StackDraf S) {
    return IDXTOP(S) == MaxEl - 1;
}

void Push(StackDraf *S, Draf X) {
    IDXTOP(*S)++;
    LASTDRAF(*S) = X;
}

void Pop(StackDraf *S, Draf *X) {
    *X = LASTDRAF(*S);
    IDXTOP(*S) -= 1;
}

void InitStackDraf(int User) {
    StackDraf SD;
    
    CreateEmpty(&SD);
    dbDrafUser[User] = SD;
}

void CreateDraf(int User) {
    Draf D;
    StackDraf SD;
    char* input;

    SD = dbDrafUser[User];

    printf("Masukkan draf:\n");
    TEXT(D) = perintah();
    ADV();
    GetLocalDATETIME(&DATETIME(D));

    Push(&SD, D);
    dbDrafUser[User] = SD;

    printf("\nApakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");
    input = perintah();
    ADV();

    if (isValid(input, "TERBIT")) {
        PublishDraf(D);
        printf("\nSelamat telah terbit!\n");
    } else if (isValid(input, "HAPUS")) {
        DeleteDraf(User);
        printf("\nDihapus\n");
    } else if (isValid(input, "SIMPAN")) {
        printf("\nDraf telah berhasil disimpan!\n");
    } else {
        printf("\nMasukkan input yang valid!\n");
    }
}

void DisplayDraf(int User) {
    StackDraf SD;
    char* input;

    SD = dbDrafUser[User];
    if (IsEmpty(SD)) {
        printf("Yah, anda belum memiliki draf apapun! Buat dulu ya :D\n");
    } else {
        Draf D = LASTDRAF(SD);

        printf("Ini draf terakhir anda:");
        printf("\n| "); printf("ID = %d", IDXTOP(SD)+1);
        printf("\n| "); TulisDATETIME(DATETIME(D));
        printf("\n| "); printf(TEXT(D));

        printf("\n\nApakah anda ingin mengubah, menghapus, atau menerbitkan draf ini? (KEMBALI jika ingin kembali)\n");
        input = perintah();
        ADV();

        if (isValid(input, "TERBIT")) {
            PublishDraf(D);
            printf("\nSelamat telah terbit!\n");
        } else if (isValid(input, "HAPUS")) {
            DeleteDraf(User);
            printf("\nDraf telah berhasil dihapus!\n");
        } else if (isValid(input, "UBAH")) {
            EditDraf(User);
        } else {
            printf("\nMasukkan input yang valid!\n");
        }
    }
}
void DeleteDraf(int User) {
    Draf D;
    StackDraf SD;

    SD = dbDrafUser[User];
    Pop(&SD, &D);

    dbDrafUser[User] = SD;
}

void EditDraf(int User) {
    DeleteDraf(User);
    CreateDraf(User);
}
void PublishDraf(Draf D) {
    Kicauan kicau;
    CreateKicauan(&kicau);
    TEXT_KICAU(kicau) = TEXT(D);

    InsertLastKicau()
}