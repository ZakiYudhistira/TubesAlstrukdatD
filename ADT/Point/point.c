#include "point.h"
#include <stdio.h>
#include <math.h>


void CreatePoint(POINT* P, float X, float Y) {
    Absis(*P) = X;
    Ordinat(*P) = Y;
}


void BacaPOINT(POINT* P) {
    float X, Y;
    scanf("%f %f", &X, &Y);
    CreatePoint(P, X, Y);
}

void TulisPOINT(POINT P) {
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}


boolean EQ(POINT P1, POINT P2) {
    return (Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2));
}

boolean NEQ(POINT P1, POINT P2) {
    return (Absis(P1) != Absis(P2)) || (Ordinat(P1) != Ordinat(P2));
}


boolean IsOrigin(POINT P) {
    return (Absis(P) == 0 && Ordinat(P) == 0);
}

boolean IsOnSbX(POINT P) {
    return Ordinat(P) == 0;
}

boolean IsOnSbY(POINT P) {
    return Absis(P) == 0;
}

int Kuadran(POINT P) {
    float X, Y;
    X = Absis(P);
    Y = Ordinat(P);
    return 1 * (X > 0 && Y > 0) + 2 * (X < 0 && Y > 0) + 3 * (X < 0 && Y < 0) + 4 * (X > 0 && Y < 0);
}


POINT NextX(POINT P) {
    Absis(P)++;
    return P;
}

POINT NextY(POINT P) {
    Ordinat(P)++;
    return P;
}

POINT PlusDelta(POINT P, float deltaX, float deltaY) {
    Absis(P) += deltaX;
    Ordinat(P) += deltaY;
    return P;
}

POINT MirrorOf(POINT P, boolean SbX) {
    if (SbX) {
        Ordinat(P) = -Ordinat(P);
    }
    else {
        Absis(P) = -Absis(P);
    }
    return P;
}

float Jarak0(POINT P) {
    return sqrt(Absis(P) * Absis(P) + Ordinat(P) * Ordinat(P));
}

float Panjang(POINT P1, POINT P2) {
    float diffX, diffY;
    diffX = Absis(P1) - Absis(P2);
    diffY = Ordinat(P1) - Ordinat(P2);
    return sqrt(diffX * diffX + diffY * diffY);
}

void Geser(POINT* P, float deltaX, float deltaY) {
    Absis(*P) += deltaX;
    Ordinat(*P) += deltaY;
}

void GeserKeSbX(POINT* P) {
    Ordinat(*P) = 0;
}

void GeserKeSbY(POINT* P) {
    Absis(*P) = 0;
}

void Mirror(POINT* P, boolean SbX) {
    if (SbX) {
        Ordinat(*P) = -Ordinat(*P);
    }
    else {
        Absis(*P) = -Absis(*P);
    }
}

void Putar(POINT* P, float Sudut) {
    float X, Y;
    X = Absis(*P);
    Y = Ordinat(*P);
    Sudut = (360 - Sudut) * 3.1415926535 / 180;
    Absis(*P) = X * cos(Sudut) - Y * sin(Sudut);
    Ordinat(*P) = X * sin(Sudut) + Y * cos(Sudut);
}

void PersamaanLinearDuaVariabel(POINT P1, POINT P2) {
    float a = (Ordinat(P2) - Ordinat(P1)) / (Absis(P2) - Absis(P1));
    float b = Ordinat(P2) - a * Absis(P2);
    printf("(%d,%d)", (int)a, (int)b);
}