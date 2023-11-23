#include "stackDraf.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Perintah/perintah.h"
#include "../Kicauan/kicauan.h"

/* Primitive Function Stack */
void CreateEmptyStackDraf(StackDraf *SD, Word namaAuthor) {
    IDXTOP_SD(*SD) = -1;
    AUTHOR_SD(*SD) = namaAuthor;
}
boolean IsEmptyStackDraf(StackDraf SD) {
    return IDXTOP_SD(SD) == -1;
}
boolean IsFullStackDraf(StackDraf SD) {
    return IDXTOP_SD(SD) == MaxEl_Draf - 1;
}
void PushStackDraf(StackDraf *SD, Draf X) {
    IDXTOP_SD(*SD)++;
    LASTDRAF_SD(*SD) = X;
}
void PopStackDraf(StackDraf *SD, Draf *X) {
    *X = LASTDRAF_SD(*SD);
    IDXTOP_SD(*SD) -= 1;
}
void InverseStackDraf(StackDraf* SD) {
    StackDraf S1, S2;
    Draf D;

    IDXTOP_SD(S1) = -1;
    IDXTOP_SD(S2) = -1;

    while (!IsEmptyStackDraf(*SD)) {
        PopStackDraf(SD, &D);
        PushStackDraf(&S1, D);
    }
    while (!IsEmptyStackDraf(S1)) {
        PopStackDraf(&S1, &D);
        PushStackDraf(&S2, D);
    }
    while (!IsEmptyStackDraf(S2)) {
        PopStackDraf(&S2, &D);
        PushStackDraf(SD, D);
    }
}

/* Primitive Function List of Stack */
void initListStackDraf(listStackDraf *lsd) {
    NEFF_LISTSTACK(*lsd) = 0;
}

int getIdxUserListStackDraf(listStackDraf lsd, Word User) {
    for (int i = 0; i < lsd.nEff; i++) {
        if (isSame(AUTHOR_SD(GET_LISTSTACK(lsd, i)), User)) {
            return i;
        }
    }

    return -1;
}
void insertLastListStack(listStackDraf *lsd, StackDraf SD) {
    int neff = NEFF_LIST(*lsd);
    GET_LISTSTACK(*lsd, neff) = SD;
    NEFF_LISTSTACK(*lsd) += 1;
}

/* Primitive Function Draf */
// Untuk input == 'BUAT_DRAF'
void CreateDraf(Word User, listStackDraf *lsd, ListDinKicau *l) {
    Draf D;
    StackDraf SD;

    Word input;
    int idxUser = getIdxUserListStackDraf(*lsd, User);

    if (idxUser == -1) {
        CreateEmptyStackDraf(&SD, User);
    } else {
        SD = GET_LISTSTACK(*lsd, idxUser);
    }

    printf("Masukkan draf:\n");
    perintah(100, 0);
    TEXT_DRAF(D) = currentWord;
    ADV();

    GetLocalDATETIME(&DATETIME_DRAF(D));

    PushStackDraf(&SD, D);
    GET_LISTSTACK(*lsd, idxUser) = SD;

    printf("\nApakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");
    perintah(20, 0);
    input = currentWord;
    ADV();

    if (isValid(input, "TERBIT")) {
        PublishDraf(User, lsd, l);
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
void DisplayDraf(Word User, listStackDraf lsd, ListDinKicau *l) {
    StackDraf SD;
    Word input;

    int idxUser = getIdxUserListStackDraf(lsd, User);

    if (idxUser == -1) {
        CreateEmptyStackDraf(&SD, User);
    } else {
        SD = GET_LISTSTACK(lsd, idxUser);
    }

    if (IsEmptyStackDraf(SD)) {
        printf("Yah, anda belum memiliki draf apapun! Buat dulu ya :D\n");
    } else {
        Draf D = LASTDRAF_SD(SD);

        printf("Ini draf terakhir anda:");
        printf("\n| "); TulisDATETIME(DATETIME_DRAF(D));
        printf("\n| "); printWord(TEXT_DRAF(D));

        printf("\n\nApakah anda ingin mengubah, menghapus, atau menerbitkan draf ini? (KEMBALI jika ingin kembali)\n");
        perintah(20, 0);
        input = currentWord;
        ADV();

        if (isValid(input, "TERBIT")) {
            PublishDraf(User, &lsd, l);
            printf("\nSelamat! Draf kicauan telah diterbitkan!\n");
        } else if (isValid(input, "HAPUS")) {
            DeleteDraf(User, &lsd);
            printf("\nDraf telah berhasil dihapus!\n");
        } else if (isValid(input, "UBAH")) {
            EditDraf(User, &lsd, l);
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

    int idxUser = getIdxUserListStackDraf(*lsd, User);

    SD = GET_LISTSTACK(*lsd, idxUser);

    PopStackDraf(&SD, &D);

    GET_LISTSTACK(*lsd, idxUser) = SD;
}
// Untuk input == 'UBAH'
void EditDraf(Word User, listStackDraf *lsd, ListDinKicau *l) {
    DeleteDraf(User, lsd);
    CreateDraf(User, lsd, l);
}
// Untuk input == 'TERBIT'
void PublishDraf(Word User, listStackDraf *lsd, ListDinKicau *l) {
    Draf D;
    StackDraf SD;

    int idxUser = getIdxUserListStackDraf(*lsd, User);

    SD = GET_LISTSTACK(*lsd, idxUser);

    PopStackDraf(&SD, &D);

    ElTypeKicau kicau;
    CreateKicauan(&kicau);
    TEXT_KICAU(kicau) = TEXT_DRAF(D);
    AUTHOR_KICAU(kicau) = AUTHOR_SD(SD);
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
        
        CreateEmptyStackDraf(&SD, namaUser);

        for (int j = 0; j < banyakDrafInt; j++) {
            Draf D;

            fgets(line, 300, file);
            StringToWord(line, &currentWord);
            TEXT_DRAF(D) = removeNewline(currentWord);

            fgets(line, 300, file);
            StringToWord(line, &currentWord);
            DATETIME(D) = WordToTime(removeNewline(currentWord));

            PushStackDraf(&SD, D);
        }

        InverseStackDraf(&SD);
        insertLastListStack(lsd, SD);
    }

    fclose(file);
}