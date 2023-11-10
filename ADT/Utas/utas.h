#ifndef utas_H
#define utas_H

#include "../../boolean.h"

/* Definisi Node : */
typedef char ElType;
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

extern Utas dbUtasUser[20];
extern int lastID;

#define IDX_UNDEF (-1)
#define FIRST(U) (U).First
#define LENGTH(U) (U).length
#define IDKicau(U) (U).idKicauan

void CreateEmptyUtas(int IDKicau);

void insertFirstUtas(Utas *U, ElType val);
void insertAtUtas(Utas *U, ElType val, int idx);

void deleteFirstUtas(Utas *U, ElType *val);
void deleteAtUtas(Utas *U, ElType *val, int idx);

// void displayUtas(Utas U);

#endif