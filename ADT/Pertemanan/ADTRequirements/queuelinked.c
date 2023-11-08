#include "queuelinked.h"
#include <stdio.h>
#include <stdlib.h>

/* Prototype manajemen memori */
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
}
void DisplayQueueQT(Queue_Teman q)
/* Proses : Menuliskan isi Queue, ditulis di antara kurung siku; antara dua elemen 
    dipisahkan dengan separator "koma", tanpa tambahan karakter di depan, di tengah, 
    atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
{
    boolean first = true;
    Address_teman p = HEAD_TEMAN(q);
    while(p != NULL){
        if(first){
            printf("ID : %d | jumlah teman : %d\n",INFO_TEMAN(p),JUMLAH_TEMAN(p));
            first = false;
        p = NEXT_TEMAN(p);
        } else {
            printf("ID : %d | jumlah teman : %d\n",INFO_TEMAN(p),JUMLAH_TEMAN(p));
        p = NEXT_TEMAN(p);
        }
    }
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
}
void dequeueQT(Queue_Teman *q, IDTeman *id)
/* Proses: Menghapus x pada bagian HEAD dari q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi deleteFirst */
/* I.S. q tidak mungkin kosong */
/* F.S. x = nilai elemen HEAD pd I.S., HEAD "mundur" */
{
    *id = TEMAN(*q);
    if(lengthQT(*q) == 1){
        free(HEAD_TEMAN(*q));
        HEAD_TEMAN(*q) = NULL;
        TAIL_TEMAN(*q) = NULL;
    } else {
        Address_teman p = HEAD_TEMAN(*q);
        HEAD_TEMAN(*q) = NEXT_TEMAN(p);
        free(p);
    }
}

// int main(){
//     Queue l;
//     CreateQueue(&l);
//     enqueue(&l,5);
//     enqueue(&l,5);
//     enqueue(&l,5);
//     enqueue(&l,5);
//     DisplayQueue(l);
//     return 0;
// }