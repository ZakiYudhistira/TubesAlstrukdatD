#ifndef DRAF_H
#define DRAF_H

#include "../../ADT/boolean.h"
#include "../../ADT/Mesin Kata/wordmachine.h"

typedef int infotype;
typedef int address;

typedef struct {
    int datetime;
    Word text;
} Draf;

#define DATETIME(D) (D).datetime
#define TEXT(D) (D).text

#endif