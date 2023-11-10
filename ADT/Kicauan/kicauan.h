/* File : kicauan.h */

#ifndef KICAUAN_H
#define KICAUAN_H

#define _XOPEN_SOURCE

#include "../boolean.h"
#include "../Mesin Kata/wordmachine.h"
#include <time.h>

/* Definisi elemen dan address */
typedef struct {
   int id;
   char[] text;
   int like;
   char[] author;
   time_t datetime;
} Kicauan;

/* ********* AKSES (Selektor) ********* */
/* Jika k adalah Kicauan, maka akses elemen : */
#define ID(k) (k).id
#define TEXT(k) (k).text
#define LIKE(k) (k).like
#define AUTHOR(k) (k).author
#define DATETIME(k) (k).datetime

/*  Kamus Umum */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/

typedef Kicauan ElType; /* type elemen list */
typedef struct
{
   ElType* buffer; /* memori tempat penyimpan elemen (container) */
   int nEff;       /* >=0, banyaknya elemen efektif */
   int capacity;   /* ukuran elemen */
} ListDinKicau;

/* ********** SELEKTOR ********** */
#define NEFF(l) (l).nEff
#define BUFFER(l) (l).buffer
#define ELMT(l, i) (l).buffer[i]
#define CAPACITY(l) (l).capacity


/* *** Kreator *** */
void CreateKicauan(Kicauan* k);
/* I.S. sembarang */
/* F.S. Sebuah k kosong dan datetime now*/

void CreateListKicauan(ListDinKicau* l, int capacity);
/* I.S. sembarang */
/* F.S. Terbentuk ListDinKicau kosong dengan kapasitas capacity */

void ReadKicauan(Kicauan* k);
/* I.S. sembarang */
/* F.S. Sebuah k terbentuk dengan isi masing-masing berupa Word dan int yang diakuisisi
   dari stdin */

   /* *** Operasi Lain *** */
const char* TimeToString(time_t t);
/* Mengubah time_t menjadi string dengan format "DD-MM-YYYY HH:MM:SS" */

time_t StringToTime(const char* s);
/* Mengubah string dengan format "DD-MM-YYYY HH:MM:SS" menjadi time_t */

/* *** Display Pengguna *** */
void displayKicauan(Kicauan k);
/* Proses : Menuliskan isi Kicauan dengan traversal. Informasi kicauan
   ditulis satu persatu dan diakhiri dengan newline */

#endif
