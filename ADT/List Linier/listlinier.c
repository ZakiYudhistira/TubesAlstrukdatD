#include "listlinier.h"
#include "stdio.h"
#include "stdlib.h"

Address newNode(ElType val) {
    Address P = (Address)malloc(sizeof(Node));
    INFO(P) = val;
    NEXT(P) = NULL;
    return P;
}

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List* l) {
    FIRST(*l) = NULL;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l) {
    return FIRST(l) == NULL;
}
/* Mengirim true jika list kosong */

/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx) {
    Address P = FIRST(l);
    int i = 0;
    while (i < idx) {
        P = NEXT(P);
        i++;
    }
    return INFO(P);
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

void setElmt(List* l, int idx, ElType val) {
    Address P = FIRST(*l);
    int i = 0;
    while (i < idx) {
        P = NEXT(P);
        i++;
    }
    INFO(P) = val;
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */

int indexOf(List l, ElType val) {
    Address P = FIRST(l);
    int i = 0;
    while (P != NULL) {
        if (INFO(P) == val) {
            return i;
        }
        P = NEXT(P);
        i++;
    }

    return IDX_UNDEF;
}
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List* l, ElType val) {
    Address N = newNode(val);
    if (N != NULL) {
        NEXT(N) = FIRST(*l);
        FIRST(*l) = N;
    }
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void insertLast(List* l, ElType val) {
    Address N = newNode(val);
    if (isEmpty(*l)) {
        insertFirst(l, val);
    }
    else {
        Address P = newNode(val);
        Address last = FIRST(*l);
        while (NEXT(last) != NULL) {
            last = NEXT(last);
        }
        NEXT(last) = P;
    }
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void insertAt(List* l, ElType val, int idx) {
    if (idx == 0) {
        insertFirst(l, val);
    }
    else {
        Address N = newNode(val);
        Address P = FIRST(*l);
        int i = 0;
        while (i < idx - 1) {
            P = NEXT(P);
            i++;
        }
        NEXT(N) = NEXT(P);
        NEXT(P) = N;
    }
}
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List* l, ElType* val) {
    Address P = FIRST(*l);
    *val = INFO(P);
    FIRST(*l) = NEXT(P);
    free(P);
}
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
void deleteLast(List* l, ElType* val) {
    Address p = *l;
    Address loc = NULL;
    while (NEXT(p) != NULL) {
        loc = p;
        p = NEXT(p);
    }
    if (loc == NULL) {
        *l = NULL;
    }
    else {
        NEXT(loc) = NULL;
    }
    *val = INFO(p);
    free(p);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */

void deleteAt(List* l, int idx, ElType* val) {
    if (idx == 0) {
        deleteFirst(l, val);
    }
    else {
        Address P = FIRST(*l);
        int i = 0;
        while (i < idx - 1) {
            P = NEXT(P);
            i++;
        }
        Address nextP = NEXT(P);
        *val = INFO(nextP);
        NEXT(P) = NEXT(nextP);
        free(nextP);
    }
}
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */


/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l) {
    Address P = FIRST(l);
    printf("[");
    int count = 0;
    while (P != NULL) {
        if (count == 0) {
            printf("%d", INFO(P));
            count++;
        }
        else {
            printf(",%d", INFO(P));
        }
        P = NEXT(P);
    }
    printf("]");
}
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

int length(List l) {
    int count = 0;
    Address P = FIRST(l);
    while (P != NULL) {
        count++;
        P = NEXT(P);
    }
    return count;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2) {
    List l3;
    CreateList(&l3);
    Address P = FIRST(l1);
    while (P != NULL) {
        insertLast(&l3, INFO(P));
        P = NEXT(P);
    }
    P = FIRST(l2);
    while (P != NULL) {
        insertLast(&l3, INFO(P));
        P = NEXT(P);
    }
    return l3;
}
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */