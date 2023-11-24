#include "charmachine.h"
#include "charmachine.c"

int main(){
    
    START();
    while(!EOP){
        printf("%c", currentChar);
        ADV();
    }

    return 0;
}