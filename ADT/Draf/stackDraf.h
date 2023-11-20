#ifndef STACKDRAF_H
#define STACKDRAF_H

#include "draf.h"
#include "../boolean.h"

#define MaxEl 100

typedef int address;

typedef struct {
    Draf T[MaxEl];
    address IDXTOP;
} StackDraf;

extern StackDraf dbDrafUser[20];

#define IDXTOP(SD) (SD).IDXTOP
#define LASTDRAF(SD) (SD).T[IDXTOP(SD)]

void InitStackDraf(int User);
void CreateDraf(int User);
void DisplayDraf(int User);
void HapusDraf(int User);
void EditDraf(int User);
void DeleteDraf(int User);
void PublishDraf(Draf D);

void CreateEmpty(StackDraf* S);
boolean IsEmpty(StackDraf S);
boolean IsFull(StackDraf S);
void Push(StackDraf* S, Draf X);
void Pop(StackDraf* S, Draf* X);

#endif