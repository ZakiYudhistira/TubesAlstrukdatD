#include <stdio.h>
#include <stdlib.h>
#include "Fitur\perintah.h"

int main() {
    char *test = perintah();

    if (test != NULL) {
        if (isValid(test, "tubes")) {
            printf("Hello %s\n", test);
        }

        free(test); // Jangan lupa membebaskan memori yang dialokasikan
    }

    return 0;
    
    
}