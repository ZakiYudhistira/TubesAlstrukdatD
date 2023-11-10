#include "datetime.h"
#include <stdio.h>

void CreateDatetime(DATETIME* D, struct tm date) {
    Day(*D) = date.tm_mday;
    Month(*D) = date.tm_mon+1;
    Year(*D) = date.tm_year+1900;
    Hour(*D) = date.tm_hour;
    Minute(*D) = date.tm_min;
    Second(*D) = date.tm_sec;
}

void DisplayDatetime(DATETIME D) {
    printf("%02d/%02d/%04d %02d:%02d:%02d", Day(D), Month(D), Year(D), Hour(D), Minute(D), Second(D));
}