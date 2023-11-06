#include "stackDraf.h"
#include <stdio.h>
#include <time.h>

void CreateDraf(int User) {
    Draf D;
    StackDraf SD;

    SD = arrayStack[User];

    printf("Masukkan draf:\n");
    STARTWORD;
    TEXT(D) = currentWord;
    DATETIME(D) = 1;

    Push(&STACKDRAF(SD), D);

    printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");
    STARTWORD;
}
void DisplayDraf(int User) {
    printf("Ini draf terakhir anda:\n");
    printf("| "); printf(DATETIME(LASTDRAF(User)));
    //printf("\n| "); printf(TEXT(LASTDRAF(User)));

    printf("Apakah anda ingin mengubah, menghapus, atau menerbitkan draf ini? (KEMBALI jika ingin kembali)\n");
    STARTWORD;
}
void DeleteDraf(int User) {
    Draf D;
    Stack SD;

    SD = GETSTACK(User);
    Pop(&SD, &D);

    GETSTACK(User) = SD;

    printf("Draf telah berhasil dihapus!\n");
}
void EditDraf(int User) {
    DeleteDraf(User);
    Draf D;
    StackDraf SD;

    SD = arrayStack[User];
    printf("Masukkan draf yang baru:\n");

    STARTWORD;
    TEXT(D) = currentWord;
    DATETIME(D) = 1;

    Push(&STACKDRAF(SD), D);

    printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");
    STARTWORD;
}
void PublishDraf(int User) {
    //tunggu fungsi publish kicauan
}