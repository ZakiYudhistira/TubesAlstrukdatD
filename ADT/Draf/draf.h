#ifndef DRAF_H
#define DRAF_H

#include "../Datetime/datetime.h"

typedef struct {
    DATETIME datetime;
    Word text;
} Draf;

#define DATETIME_DRAF(D) (D).datetime
#define TEXT_DRAF(D) (D).text

#endif