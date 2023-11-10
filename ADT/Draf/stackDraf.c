#include "stackDraf.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Perintah/perintah.c"

StackDraf dbDrafUser[20];

void CreateEmpty(StackDraf *S) {
    IDXTOP(*S) = Nil;
}

boolean IsEmpty(StackDraf S) {
    return IDXTOP(S) == Nil;
}

boolean IsFull(StackDraf S) {
    return IDXTOP(S) == MaxEl - 1;
}

void Push(StackDraf *S, Draf X) {
    if (IsEmpty(*S))
    {
        IDXTOP(*S) = 0;
        LASTDRAF(*S) = X;
    }
    else
    {
        IDXTOP(*S)++;
        LASTDRAF(*S) = X;
    }
}

void Pop(StackDraf *S, Draf *X) {
    *X = LASTDRAF(*S);
    IDXTOP(*S) -= 1;
}

void CreateDraf(int User) {
    Draf D;
    StackDraf SD;

    CreateEmpty(&SD);

    // SD = dbDrafUser[User];

    printf("Masukkan draf:\n");
    TEXT(D) = perintah();

    time_t t = time(NULL);
    struct tm date = *localtime(&t);
    CreateDatetime(&DATETIME(D), date);

    Push(&SD, D);
    DisplayDatetime(DATETIME(D));

    printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");
}

void DisplayDraf(int User) {
    StackDraf SD;
    SD = GETSTACK(User);
    printf("Ini draf terakhir anda:\n");
    printf("| "); DisplayDatetime(DATETIME(LASTDRAF(SD)));
    //printf("\n| "); printf(TEXT(LASTDRAF(User)));

    printf("Apakah anda ingin mengubah, menghapus, atau menerbitkan draf ini? (KEMBALI jika ingin kembali)\n");
    STARTWORD;
}
void DeleteDraf(int User) {
    Draf D;
    StackDraf SD;

    SD = GETSTACK(User);
    Pop(&SD, &D);

    GETSTACK(User) = SD;

    printf("Draf telah berhasil dihapus!\n");
}
void EditDraf(int User) {
    DeleteDraf(User);
    Draf D;
    StackDraf SD;

    SD = GETSTACK(User);
    printf("Masukkan draf yang baru:\n");

    TEXT(D) = "isiDraf";
    time_t t = time(NULL);
    struct tm date = *localtime(&t);
    CreateDatetime(&DATETIME(D), date);

    Push(&SD, D);

    printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");
    STARTWORD;
}
void PublishDraf(int User) {
    //tunggu fungsi publish kicauan
}