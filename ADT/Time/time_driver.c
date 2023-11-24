#include "time.h"
#include "time.c"

int main() {
    TIME T;
    int HH, MM, SS;

    printf("Masukkan jam: ");
    scanf("%d", &HH);
    printf("Masukkan menit: ");
    scanf("%d", &MM);
    printf("Masukkan detik: ");
    scanf("%d", &SS);

    CreateTime(&T, HH, MM, SS);

    TulisTIME(T);

    return 0;
}