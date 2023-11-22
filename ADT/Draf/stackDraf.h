#ifndef STACKDRAF_H
#define STACKDRAF_H

#include "draf.h"
#include "../boolean.h"
#include "../Perintah/perintah.h"
#include "../Kicauan/kicauan.h"
#include "../Pengguna/pengguna.h"

#define MaxEl 100

typedef int address;

typedef struct {
    Word Author_Draf;
    Draf T[MaxEl];
    address IDXTOP;
} StackDraf;

#define IDXTOP(SD) (SD).IDXTOP
#define LASTDRAF(SD) (SD).T[IDXTOP(SD)]
#define AUTHORDRAF(SD) (SD).Author_Draf

typedef struct {
    int nEff;
    StackDraf list[20];
} listStackDraf;

#define NEFF_LIST(lsd) (lsd).nEff
#define GET_LIST(lsd, idx) (lsd).list[idx]

/* Primitive Function Stack */
void CreateEmpty(StackDraf *S, Word namaAuthor);
boolean IsEmpty(StackDraf S);
boolean IsFull(StackDraf S);
void Push(StackDraf *S, Draf X);
void Pop(StackDraf *S, Draf *X);
void InverseStackDraf(StackDraf* SD);
void InitStackDraf(Word User, listStackDraf *lsd);

/* Primitive Function List of Stack */
int getIdxUser(listStackDraf lsd, Word User);
void insertLastListStack(listStackDraf *lsd, StackDraf SD);

/* Primitive Function Draf */
// Untuk input == 'BUAT_DRAF'
void CreateDraf(Word User, listStackDraf *lsd, ListDinKicau *l, databaseprofil db);
// Untuk input == 'LIHAT_DRAF'
void DisplayDraf(Word User, listStackDraf lsd, ListDinKicau *l, databaseprofil db);
// Untuk input == 'HAPUS'
void DeleteDraf(Word User, listStackDraf *lsd);
// Untuk input == 'UBAH'
void EditDraf(Word User, listStackDraf *lsd, ListDinKicau *l, databaseprofil db);
// Untuk input == 'TERBIT'
void PublishDraf(Word User, listStackDraf *lsd, ListDinKicau *l, databaseprofil db);

void LoadDraf(listStackDraf *lsd, Word path);

#endif