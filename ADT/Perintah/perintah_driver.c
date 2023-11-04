#include "perintah.c"
#include <string.h> // Untuk menggunakan strcmp

int main() {
    char* test = perintah();

    if (test != NULL) {
        if (strcmp(test, "MASUK") == 0) {
            printf("%s\n", test);
        }

        free(test); //dialokasikan
    }

    return 0;
}