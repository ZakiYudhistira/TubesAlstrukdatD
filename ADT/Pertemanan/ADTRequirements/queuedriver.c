#include "queuelinked.h"
#include <stdio.h>

int main(){
    Queue_Teman q;
    CreateQueueQT(&q);
    enqueueQT(&q,0,2);
    enqueueQT(&q,1,5);
    enqueueQT(&q,2,3);
    enqueueQT(&q,3,11);
    enqueueQT(&q,7,3);
    DisplayQueueQT(q);
    IDTeman id;
    dequeueQT(&q,&id);
    printf("remove id : %d\n",id);
    dequeueQT(&q,&id);
    printf("remove id : %d\n",id);
    dequeueQT(&q,&id);
    printf("remove id : %d\n",id);
    dequeueQT(&q,&id);
    printf("remove id : %d\n",id);
    DisplayQueueQT(q);
    return 0;
}