#ifndef DATETIME_H
#define DATETIME_H

#include <time.h>

/* *** Definisi TYPE DATETIME <DD/MM/YY HH:MM:SS> *** */
typedef struct
{
    int DD;
    int MM;
    int YYYY;
    int hh;
    int mm;
    int ss;
} DATETIME;

/* *** Notasi Akses: selektor DATETIME *** */
#define Day(D) (D).DD
#define Month(D) (D).MM
#define Year(D) (D).YYYY
#define Hour(D) (D).hh
#define Minute(D) (D).mm
#define Second(D) (D).ss

void CreateDatetime(DATETIME* D, struct tm date);
void DisplayDatetime(DATETIME D);

#endif