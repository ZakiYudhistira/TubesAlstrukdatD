#ifndef UTAS_H
#define UTAS_H

#include "../../ADT/boolean.h"
#include "../../ADT/Mesin Kata/wordmachine.h"
#include "../LinkedList/linkedlist.h"

typedef int infotype;
typedef int address;

typedef struct {
    int id;
    int idKicau;
    List firstUtas;
} Utas;

extern Utas arrayUtas[20];

#define ID(U) (U).id
#define IDKICAU(U) (U).idKicau
#define ADDRESS(U) (U).firstUtas

void CreateUtas(Utas* U, int idKicau);
void SambungUtas(Utas* U);
void CetakUtas(Utas* U);
void HapusUtas(Utas* U);

#endif