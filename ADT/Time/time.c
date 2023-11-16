#include "time.h"
#include <stdio.h>
#include <math.h>

boolean IsTIMEValid(int H, int M, int S) {
    return (H >= 0 && H <= 23) && (M >= 0 && M <= 59) && (S >= 0 && S <= 59);
}

void CreateTime(TIME* T, int HH, int MM, int SS) {
    Hour(*T) = HH;
    Minute(*T) = MM;
    Second(*T) = SS;
}

void BacaTIME(TIME* T) {
    int HH, MM, SS;
    do {
        scanf("%d %d %d", &HH, &MM, &SS);
        if (!IsTIMEValid(HH, MM, SS)) {
            printf("Jam tidak valid\n");
        }
    } while (!IsTIMEValid(HH, MM, SS));
    CreateTime(T, HH, MM, SS);
}

void TulisTIME(TIME T) {
    int HH, MM, SS;
    HH = Hour(T);
    MM = Minute(T);
    SS = Second(T);
    printf("%02d:%02d:%02d", HH, MM, SS);
}

long TIMEToDetik(TIME T) {
    long detik;
    detik = Hour(T) * 3600 + Minute(T) * 60 + Second(T);
    return detik;
}

TIME DetikToTIME(long N) {
    TIME T;
    int HH, MM, SS;
    N %= 86400;
    while (N < 0) {
        N += 86400;
    }
    HH = N / 3600;
    N %= 3600;
    MM = N / 60;
    N %= 60;
    SS = N;
    CreateTime(&T, HH, MM, SS);
    return T;
}


boolean TEQ(TIME T1, TIME T2) {
    return (Hour(T1) == Hour(T2)) && (Minute(T1) == Minute(T2)) && (Second(T1) == Second(T2));
}

boolean TNEQ(TIME T1, TIME T2) {
    return (Hour(T1) != Hour(T2)) || (Minute(T1) != Minute(T2)) || (Second(T1) != Second(T2));
}

boolean TLT(TIME T1, TIME T2) {
    long d1, d2;
    d1 = TIMEToDetik(T1);
    d2 = TIMEToDetik(T2);
    return d1 < d2;
}

boolean TGT(TIME T1, TIME T2) {
    long d1, d2;
    d1 = TIMEToDetik(T1);
    d2 = TIMEToDetik(T2);
    return d1 > d2;
}

TIME NextDetik(TIME T) {
    return DetikToTIME((TIMEToDetik(T) + 1) % 86400);
}

TIME NextNDetik(TIME T, int N) {
    return DetikToTIME((TIMEToDetik(T) + N) % 86400);
}

TIME PrevDetik(TIME T) {
    return DetikToTIME((TIMEToDetik(T) - 1) % 86400);
}

TIME PrevNDetik(TIME T, int N) {
    return DetikToTIME((TIMEToDetik(T) - N) % 86400);
}

long Durasi(TIME TAw, TIME TAkh) {
    long d1, d2;
    d1 = TIMEToDetik(TAw);
    d2 = TIMEToDetik(TAkh);
    return (d2 > d1) * (d2 - d1) + (d1 > d2) * (d2 - d1 + (24 * 3600));
}
