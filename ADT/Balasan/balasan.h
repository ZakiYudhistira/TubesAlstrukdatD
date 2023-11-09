/* File : balasan.h */

#ifndef BALASAN_H
#define BALASAN_H

#define _XOPEN_SOURCE

#include "../boolean.h"
#include "../Mesin Kata/wordmachine.h"
#include "../Kicauan/kicauan.h"
#include <time.h>

/* Definisi elemen dan address */
typedef struct {
    Kicauan kicauan;
} Balasan;


/* ********* AKSES (Selektor) ********* */
/* Jika k adalah Kicauan, maka akses elemen : */
// #define ID(k) (k).id
// #define TEXT(k) (k).text
// #define LIKE(k) (k).like
// #define AUTHOR(k) (k).author
// #define DATETIME(k) (k).datetime

/* *** Kreator *** */
// void CreateKicauan(Kicauan* k);
/* I.S. sembarang */
/* F.S. Sebuah k kosong dan datetime now*/

// void ReadKicauan(Kicauan* k);
/* I.S. sembarang */
/* F.S. Sebuah k terbentuk dengan isi masing-masing berupa Word dan int yang diakuisisi
   dari stdin */


   /* *** Display Pengguna *** */
// void displayKicauan(Kicauan k);
/* Proses : Menuliskan isi Kicauan dengan traversal. Informasi kicauan
   ditulis satu persatu dan diakhiri dengan newline */

#endif
