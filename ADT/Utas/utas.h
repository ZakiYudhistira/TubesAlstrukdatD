#ifndef utas_H
#define utas_H

#include "../boolean.h"
#include "../Perintah/wordmachine.h"
#include "../Kicauan/kicauan.h"
#include "../Datetime/datetime.h"
#include "../Pengguna/pengguna.h"

/* Definisi Node : */
typedef struct nodeUtas* Address;
typedef struct nodeUtas {
    Word info;
    Address next;
    DATETIME date;
} Node;

#define INFO(p) (p)->info
#define NEXT(p) (p)->next
#define DATE(p) (p)->date

Address newNode_Utas(Word val, DATETIME date);

typedef struct utas {
    int idKicauan;
    int length;
    Address First;
    Word Author;
} Utas;


#define IDX_UNDEF_UTAS (-1)
#define FIRST_UTAS(U) (U).First
#define LENGTH_UTAS(U) (U).length
#define AUTHOR_UTAS(U) (U).Author
#define IDKICAU_UTAS(U) (U).idKicauan

typedef struct listdinutas{
   Utas* buffer; /* memori tempat penyimpan elemen (container) */
   int nEff;       /* >=0, banyaknya elemen efektif */
   int capacity;   /* ukuran elemen */
} ListDinUtas;

/* ********** SELEKTOR ********** */
#define NEFF_LISTUTAS(l) (l).nEff
#define BUFFER_LISTUTAS(l) (l).buffer
#define ELMT_LISTUTAS(l, i) (l).buffer[i]
#define CAPACITY_LISTUTAS(l) (l).capacity

// Untuk input == "UTAS [IDKicau]"
void createEmptyUtas(Word User, int IDKicau, ListDinUtas *dbUtasUser, ListDinKicau* l);
// Untuk input == "CETAK_UTAS [IDUtas]"
void displayUtas(Word User, int IDUtas, ListDinUtas *dbUtasUser, ListDinKicau* l, databaseprofil db, Matrix_pertemanan m);
// Untuk input == "SAMBUNG_UTAS [IDUtas] [index]"
void sambungUtas(Word User, int IDUtas, int index, ListDinUtas *dbUtasUser);
// Untuk input == "HAPUS_UTAS [IDUtas] [index]"
void deleteUtas(Word User, int IDUtas, int index, ListDinUtas *dbUtasUser);

/* Primitive Function Utas */
void insertFirstUtas(Utas *U, Word val, DATETIME D);
void insertAtUtas(Utas *U, Word val, DATETIME D, int idx);
void insertLastUtas(Utas *U, Word val, DATETIME D);
void deleteFirstUtas(Utas *U);
void deleteAtUtas(Utas *U, int idx);
void deleteLastUtas(Utas *U);

/* Primitive Function ListDin Utas*/
void initListDinUtas(ListDinUtas *dbUtasUser);
void insertLastListUtas(Utas *val, ListDinUtas *dbUtasUser);
void expandListUtas(int num, ListDinUtas *dbUtasUser);

void loadUtas(ListDinUtas *dbUtasUser, Word path);

// Fungsi Bantuan
int getIDUtas(int IDKicau, ListDinUtas dbUtasUser);
#endif