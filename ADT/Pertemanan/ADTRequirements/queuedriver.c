#include "queuelinked.h"
#include <stdio.h>

int main(){
    int i;
    Queue_Teman q;
    CreateQueueQT(&q);
    for(i = 0 ; i < 5 ; i ++){
        enqueueQT(&q, i+1, i+2);
    }
    displayQueueQT(q);
    freeQueueQT(&q);
    displayQueueQT(q);
}