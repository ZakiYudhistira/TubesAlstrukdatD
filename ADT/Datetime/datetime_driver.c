#include "datetime.h"
#include "datetime.c"
#include "../Time/time.c"

int main() {
    DATETIME D;

    GetLocalDATETIME(&D);

    TulisDATETIME(D);

    return 0;
}