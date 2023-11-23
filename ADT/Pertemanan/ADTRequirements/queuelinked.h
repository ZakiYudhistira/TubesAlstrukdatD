/* File: queuelinked.h */

#ifndef QUEUELINKED_H
#define QUEUELINKED_H
#include "../../boolean.h"
#include <stdlib.h>

#define NIL NULL
/* Deklarasi infotype */
typedef int IDTeman;
/* Queue dengan representasi berkait dengan pointer */
typedef struct node_teman* Address_teman;
typedef struct node_teman { 
    IDTeman info_id;
    int jumlah_teman;
    Address_teman next_id; 
} Node_teman; 
/* Type queue dengan ciri HEAD dan TAIL: */
typedef struct {
    Address_teman addrHeadTeman; /* alamat penghapusan */
    Address_teman addrTailTeman; /* alamat penambahan */
    int length;
} Queue_Teman;

/* Selektor */
#define   INFO_TEMAN(p) (p)->info_id
#define JUMLAH_TEMAN(p) (p)->jumlah_teman
#define   NEXT_TEMAN(p) (p)->next_id

#define HEAD_TEMAN(q) (q).addrHeadTeman
#define TAIL_TEMAN(q) (q).addrTailTeman
#define      TEMAN(q) (q).addrHeadTeman->info_id

/* Prototype manajemen memori */
Address_teman newNodeQueueTeman(IDTeman id, int jumlah_teman);
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x, 
   atau NIL jika alokasi gagal */
boolean isEmptyQT(Queue_Teman q);
/* Mengirim true jika q kosong: ADDR_HEAD(q)=NULL and ADDR_TAIL(q)=NULL */
int lengthQT(Queue_Teman q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong */

/*** Kreator ***/
void CreateQueueQT(Queue_Teman *q);
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk */

/*** Primitif Enqueue/Dequeue ***/
void enqueueQT(Queue_Teman *q, IDTeman id, int jumlah_teman);
/* Proses: Mengalokasi x dan menambahkan x pada bagian Tail dari q
           jika alokasi berhasil; jika alokasi gagal q tetap */
/* Pada dasarnya adalah proses insertLast */
/* I.S. q mungkin kosong */
/* F.S. x menjadi Tail, Tail "maju" */
void dequeueQT(Queue_Teman *q, IDTeman *id, int *jumlah_teman);
/* Proses: Menghapus x pada bagian HEAD dari q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi deleteFirst */
/* I.S. q tidak mungkin kosong */
/* F.S. x = nilai elemen HEAD pd I.S., HEAD "mundur" */

void freeQueueQT(Queue_Teman *q);
/* Proses : Mengosongkan Queue secara keseluruhan , nilai queue dibuang*
/* I.S. q bisa kosong */
/* F.S. q kosong */

void displayQueueQT(Queue_Teman);
/* Mendisplay isi queue */

#endif