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
   Word text;
   int like;
   Word author;
   time_t datetime;
} Kicauan;


/* ********* AKSES (Selektor) ********* */
/* Jika k adalah Kicauan, maka akses elemen : */
#define ID(k) (k).id
#define TEXT(k) (k).text
#define LIKE(k) (k).like
#define AUTHOR(k) (k).author
#define DATETIME(k) (k).datetime

/* *** Kreator *** */
void CreateKicauan(Kicauan* k);
/* I.S. sembarang */
/* F.S. Sebuah k kosong dan datetime now*/

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
