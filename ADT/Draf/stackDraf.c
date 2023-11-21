#include "stackDraf.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Perintah/perintah.h"
#include "../Kicauan/kicauan.h"
#include "../Pengguna/pengguna.h"

/* Primitive Function Stack */
void CreateEmpty(StackDraf *S, Word namaAuthor) {
    IDXTOP(*S) = -1;
    AUTHORDRAF(*S) = namaAuthor;
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
void InverseStackDraf(StackDraf* SD) {
    StackDraf S1, S2;
    Draf D;

    IDXTOP(S1) = -1;
    IDXTOP(S2) = -1;

    while (!IsEmpty(*SD)) {
        Pop(SD, &D);
        Push(&S1, D);
    }
    while (!IsEmpty(S1)) {
        Pop(&S1, &D);
        Push(&S2, D);
    }
    while (!IsEmpty(S2)) {
        Pop(&S2, &D);
        Push(SD, D);
    }
}
void InitStackDraf(Word User, listStackDraf *lsd) {
    StackDraf SD;
    
    CreateEmpty(&SD, User);

    insertLastListStack(lsd, SD);
}

/* Primitive Function List of Stack */
int getIdxUser(listStackDraf lsd, Word User) {
    for (int i = 0; i < lsd.nEff; i++) {
        if (isSame(lsd.list->Author_Draf, User)) {
            return i;
        }
    }

    return -1;
}
void insertLastListStack(listStackDraf *lsd, StackDraf SD) {
    int neff = NEFF_LIST(*lsd);
    GET_LIST(*lsd, neff) = SD;
    NEFF_LIST(*lsd) += 1;
}

/* Primitive Function Draf */
// Untuk input == 'BUAT_DRAF'
void CreateDraf(Word User, listStackDraf *lsd, ListDinKicau *l, databaseprofil db) {
    Draf D;
    StackDraf SD;

    Word input;
    int idxUser = getIdxUser(*lsd, User);

    SD = GET_LIST(*lsd, idxUser);

    printf("Masukkan draf:\n");
    perintah(100, 0);
    TEXT(D) = currentWord;
    ADV();

    GetLocalDATETIME(&DATETIME(D));

    Push(&SD, D);
    GET_LIST(*lsd, idxUser) = SD;

    printf("\nApakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");
    perintah(20, 0);
    input = currentWord;
    ADV();

    if (isValid(input, "TERBIT")) {
        PublishDraf(User, lsd, l, db);
        printf("\nSelamat! Draf kicauan telah diterbitkan!\n");
    } else if (isValid(input, "HAPUS")) {
        DeleteDraf(User, lsd);
        printf("\nDraf telah berhasil dihapus!\n");
    } else if (isValid(input, "SIMPAN")) {
        printf("\nDraf telah berhasil disimpan!\n");
    } else {
        printf("\nMasukkan input yang valid!\n");
    }
}
// Untuk input == 'LIHAT_DRAF'
void DisplayDraf(Word User, listStackDraf lsd, ListDinKicau *l, databaseprofil db) {
    StackDraf SD;
    Word input;

    int idxUser = getIdxUser(lsd, User);

    SD = lsd.list[idxUser];

    if (IsEmpty(SD)) {
        printf("Yah, anda belum memiliki draf apapun! Buat dulu ya :D\n");
    } else {
        Draf D = LASTDRAF(SD);

        printf("Ini draf terakhir anda:");
        printf("\n| "); TulisDATETIME(DATETIME(D));
        printf("\n| "); printWord(TEXT(D));

        printf("\n\nApakah anda ingin mengubah, menghapus, atau menerbitkan draf ini? (KEMBALI jika ingin kembali)\n");
        perintah(20, 0);
        input = currentWord;
        ADV();

        if (isValid(input, "TERBIT")) {
            PublishDraf(User, &lsd, l, db);
            printf("\nSelamat! Draf kicauan telah diterbitkan!\n");
        } else if (isValid(input, "HAPUS")) {
            DeleteDraf(User, &lsd);
            printf("\nDraf telah berhasil dihapus!\n");
        } else if (isValid(input, "UBAH")) {
            EditDraf(User, &lsd);
        } else if (isValid(input, "KEMBALI")) {
            /* do nothing */
        } else {
            printf("\nMasukkan input yang valid!\n");
        }
    }
}
// Untuk input == 'HAPUS'
void DeleteDraf(Word User, listStackDraf *lsd) {
    Draf D;
    StackDraf SD;

    int idxUser = getIdxUser(*lsd, User);

    SD = lsd->list[idxUser];

    Pop(&SD, &D);

    lsd->list[idxUser] = SD;
}
// Untuk input == 'UBAH'
void EditDraf(Word User, listStackDraf *lsd) {
    DeleteDraf(User, lsd);
    CreateDraf(User, lsd);
}
// Untuk input == 'TERBIT'
void PublishDraf(Word User, listStackDraf *lsd, ListDinKicau *l, databaseprofil db) {
    Draf D;
    StackDraf SD;

    int idxUser = getIdxUser(*lsd, User);

    SD = GET_LIST(*lsd, idxUser);

    Pop(&SD, &D);

    ElTypeKicau kicau;
    CreateKicauan(&kicau);
    TEXT_KICAU(kicau) = TEXT(D);
    AUTHOR_KICAU(kicau) = nama(db, getIdxUser(*lsd, User));
    ID_KICAU(kicau) = ListKicauMaxId(*l) + 1;

    InsertLastKicau(l, kicau);
}

void LoadDraf(listStackDraf *lsd, Word path) {
    FILE* file = fopen(path.TabWord, "r");
    char line[300];

    if (file == NULL) {
        printf("File tidak ditemukan\n");
        exit(EXIT_FAILURE);
    }

    fgets(line, 300, file);
    StringToWord(line, &currentWord);
    int banyak_pengguna_draf = WordToInt(removeNewline(currentWord));
    for (int i = 0; i < banyak_pengguna_draf; i++) {
        StackDraf SD;
        Word namaUser, banyakDraf;

        int banyakDrafInt;

        fgets(line, 300, file);
        StringToWord(line, &currentWord);
        splitWordBackward(currentWord, &namaUser, &banyakDraf);
        banyakDrafInt = WordToInt(removeNewline(banyakDraf));
        
        CreateEmpty(&SD, namaUser);

        for (int j = 0; j < banyakDrafInt; j++) {
            Draf D;

            fgets(line, 300, file);
            StringToWord(line, &currentWord);
            D.text = removeNewline(currentWord);

            fgets(line, 300, file);
            StringToWord(line, &currentWord);
            D.datetime = WordToTime(removeNewline(currentWord));

            Push(&SD, D);
        }

        InverseStackDraf(&SD);
        insertLastListStack(lsd, SD);
    }

    fclose(file);
}