#ifndef STACKDRAF_H
#define STACKDRAF_H

#include "draf.h"
#include "../boolean.h"
#include "../Perintah/perintah.h"
#include "../Kicauan/kicauan.h"

#define MaxEl_Draf 100

typedef int address;

typedef struct {
    Word Author_Draf;
    Draf T[MaxEl_Draf];
    address IDXTOP_SD;
} StackDraf;

#define IDXTOP_SD(SD) (SD).IDXTOP_SD
#define LASTDRAF_SD(SD) (SD).T[IDXTOP(SD)]
#define AUTHOR_SD(SD) (SD).Author_Draf

typedef struct {
    int nEff;
    StackDraf list[20];
} listStackDraf;

#define NEFF_LISTSTACK(lsd) (lsd).nEff
#define GET_LISTSTACK(lsd, idx) (lsd).list[idx]

/* Primitive Function Stack */
void CreateEmptyStackDraf(StackDraf *S, Word namaAuthor);
boolean IsEmptyStackDraf(StackDraf S);
boolean IsFullStackDraf(StackDraf S);
void PushStackDraf(StackDraf *S, Draf X);
void PopStackDraf(StackDraf *S, Draf *X);
void InverseStackDraf(StackDraf* SD);
void InitStackDraf(Word User, listStackDraf *lsd);

/* Primitive Function List of Stack */
void initListStackDraf(listStackDraf *lsd);
int getIdxUserListStackDraf(listStackDraf lsd, Word User);
void insertLastListStack(listStackDraf *lsd, StackDraf SD);

/* Primitive Function Draf */
// Untuk input == 'BUAT_DRAF'
void CreateDraf(Word User, listStackDraf *lsd, ListDinKicau *l);
// Untuk input == 'LIHAT_DRAF'
void DisplayDraf(Word User, listStackDraf lsd, ListDinKicau *l);
// Untuk input == 'HAPUS'
void DeleteDraf(Word User, listStackDraf *lsd);
// Untuk input == 'UBAH'
void EditDraf(Word User, listStackDraf *lsd, ListDinKicau *l);
// Untuk input == 'TERBIT'
void PublishDraf(Word User, listStackDraf *lsd, ListDinKicau *l);

void LoadDraf(listStackDraf *lsd, Word path);

#endif