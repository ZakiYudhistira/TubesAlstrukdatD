#include "queuelinked.h"
#include <stdio.h>
#include <stdlib.h>

Address_teman newNodeQueueTeman(IDTeman id, int jumlah_teman)
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x, 
   atau NIL jika alokasi gagal */
{
    Address_teman p;
    p = (Address_teman)malloc(sizeof(Node_teman));
    if(p != NULL){
        INFO_TEMAN(p) = id;
        JUMLAH_TEMAN(p) = jumlah_teman;
        NEXT_TEMAN(p) = NULL;
    }
    return p;
}
boolean isEmptyQT(Queue_Teman q)
/* Mengirim true jika q kosong: ADDR_HEAD(q)=NULL and ADDR_TAIL(q)=NULL */
{
    return HEAD_TEMAN(q) == NULL && TAIL_TEMAN(q) == NULL;
}
int lengthQT(Queue_Teman q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong */
{
    int count = 0;
    Address_teman p = HEAD_TEMAN(q);
    while(p != NULL){
        count++;
        p = NEXT_TEMAN(p);
    }
    return count;
}

/*** Kreator ***/
void CreateQueueQT(Queue_Teman *q)
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk */
{
    HEAD_TEMAN(*q) = NULL;
    TAIL_TEMAN(*q) = NULL;
    (*q).length = 0;
}

/*** Primitif Enqueue/Dequeue ***/
void enqueueQT(Queue_Teman *q, IDTeman id, int jumlah_teman)
/* Proses: Mengalokasi x dan menambahkan x pada bagian Tail dari q
           jika alokasi berhasil; jika alokasi gagal q tetap */
/* Pada dasarnya adalah proses insertLast */
/* I.S. q mungkin kosong */
/* F.S. x menjadi Tail, Tail "maju" */
{
    Address_teman new = newNodeQueueTeman(id, jumlah_teman);
    if(new != NULL){
        if(isEmptyQT(*q)){
            HEAD_TEMAN(*q) = new;
            TAIL_TEMAN(*q) = new;
        } else {
            Address_teman p = HEAD_TEMAN(*q);
            Address_teman loc = NULL;
            while(p != NULL && JUMLAH_TEMAN(p) > jumlah_teman){
                loc = p;
                p = NEXT_TEMAN(p);
            }
            if(loc == NULL){
                NEXT_TEMAN(new) = HEAD_TEMAN(*q);
                HEAD_TEMAN(*q) = new;
            } else {
                NEXT_TEMAN(loc) = new;
                NEXT_TEMAN(new) = p;
            }
        }
    }
    (*q).length++;
}
void dequeueQT(Queue_Teman *q, IDTeman *id, int *jumlah_teman)
/* Proses: Menghapus x pada bagian HEAD dari q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi deleteFirst */
/* I.S. q tidak mungkin kosong */
/* F.S. x = nilai elemen HEAD pd I.S., HEAD "mundur" */
{
    Address_teman p = HEAD_TEMAN(*q);
    *id = INFO_TEMAN(p);
    *jumlah_teman = JUMLAH_TEMAN(p);
    if(lengthQT(*q) == 1){
        free(HEAD_TEMAN(*q));
        HEAD_TEMAN(*q) = NULL;
        TAIL_TEMAN(*q) = NULL;
    } else {
        HEAD_TEMAN(*q) = NEXT_TEMAN(p);
        free(p);
    }
    (*q).length--;
}