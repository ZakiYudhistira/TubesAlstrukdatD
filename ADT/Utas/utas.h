#ifndef utas_H
#define utas_H

#include "../boolean.h"
#include "../Perintah/wordmachine.h"
#include "../Kicauan/kicauan.h"
#include "../Datetime/datetime.h"

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

Address newNodeUtas(Word val, DATETIME date);

typedef struct utas {
    int idKicauan;
    int length;
    Address First;
} Utas;


#define IDX_UNDEF_UTAS (-1)
#define FIRST(U) (U).First
#define LENGTH(U) (U).length
#define IDKicau(U) (U).idKicauan

typedef struct listdinutas{
   Utas* buffer; /* memori tempat penyimpan elemen (container) */
   int nEff;       /* >=0, banyaknya elemen efektif */
   int capacity;   /* ukuran elemen */
} ListDinUtas;

/* ********** SELEKTOR ********** */
#define NEFF_UTAS(l) (l).nEff
#define BUFFER_UTAS(l) (l).buffer
#define ELMT_UTAS(l, i) (l).buffer[i]
#define CAPACITY_UTAS(l) (l).capacity

void CreateEmptyUtas(Utas* U, int IDKicau, ListDinUtas *dbUtasUser, ListDinKicau* l);
void insertFirstUtas(Utas *U, Word val, DATETIME D);
void insertAtUtas(Utas *U, Word val, DATETIME D, int idx);
void insertLastUtas(Utas *U, Word val, DATETIME D);
void deleteFirstUtas(Utas *U, Word *val);
void deleteAtUtas(Utas *U, Word *val, int idx);
void deleteLastUtas(Utas *U, Word *val);

void initListDinUtas(ListDinUtas *dbUtasUser);
void InsertLastListUtas(Utas *val, ListDinUtas *dbUtasUser);
void ExpandListUtas(int num, ListDinUtas *dbUtasUser);

void displayUtas(int idx, ListDinUtas *dbUtasUser, ListDinKicau* l);

void LoadUtas(ListDinUtas *dbUtasUser, Word path);

#endif