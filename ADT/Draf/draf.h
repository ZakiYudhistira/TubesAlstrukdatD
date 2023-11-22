#ifndef DRAF_H
#define DRAF_H

#include "../Datetime/datetime.h"

typedef struct {
    DATETIME datetime;
    Word text;
} Draf;

#define DATETIME(D) (D).datetime
#define TEXT(D) (D).text

#endif