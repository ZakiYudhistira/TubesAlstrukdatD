#ifndef utas_H
#define utas_H

#include "../boolean.h"

/* Definisi Node : */
typedef char* ElType;
typedef struct node* Address;
typedef struct node {
    ElType info;
    Address next;
} Node;

#define INFO(p) (p)->info
#define NEXT(p) (p)->next

Address newNode(ElType val);

typedef struct utas {
    int idKicauan;
    int length;
    Address First;
} Utas;


#define IDX_UNDEF (-1)
#define FIRST(U) (U).First
#define LENGTH(U) (U).length
#define IDKicau(U) (U).idKicauan

typedef struct listdinutas{
   Utas* buffer; /* memori tempat penyimpan elemen (container) */
   int nEff;       /* >=0, banyaknya elemen efektif */
   int capacity;   /* ukuran elemen */
} ListDinUtas;

extern ListDinUtas dbUtasUser;

/* ********** SELEKTOR ********** */
#define NEFF_UTAS(l) (l).nEff
#define BUFFER_UTAS(l) (l).buffer
#define ELMT_UTAS(l, i) (l).buffer[i]
#define CAPACITY_UTAS(l) (l).capacity

void CreateEmptyUtas(Utas* U, int IDKicau);
void insertFirstUtas(Utas *U, ElType val);
void insertAtUtas(Utas *U, ElType val, int idx);
void deleteFirstUtas(Utas *U, ElType *val);
void deleteAtUtas(Utas *U, ElType *val, int idx);

void InsertLastListUtas(Utas val);
void ExpandListUtas(int num);

void displayUtas(int idx);

#endif