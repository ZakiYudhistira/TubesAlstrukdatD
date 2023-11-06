#ifndef STACKDRAF_H
#define STACKDRAF_H

#include "draf.h"
#include "../../ADT/boolean.h"
#include "../../ADT/Stack/stack.h"

typedef struct {
    int user;
    Stack stackOfDraf;
} StackDraf;

extern StackDraf arrayStack[20];

#define USER(SD) (SD).User
#define STACKDRAF(SD) (SD).stackOfDraf
#define GETSTACK(USER) STACKDRAF(arrayStack[(USER)])
#define LASTDRAF(USER) InfoTop(STACKDRAF(arrayStack[(USER)]))

void CreateDraf(int User);
void DisplayDraf(int User);
void HapusDraf(int User);
void DeleteDraf(int User);
void PublishDraf(int User);

#endif