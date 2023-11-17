/* File : balasan.h */

#ifndef BALASAN_H
#define BALASAN_H

#define _XOPEN_SOURCE

#include "../boolean.h"
#include "../Mesin Kata/wordmachine.h"
#include "../Kicauan/kicauan.h"
#include <time.h>
#include "../Datetime/datetime.h"
#include "../Time/time.h"

/* Definisi elemen dan address */
typedef struct {
   int id;
   int idParent;
   char* text;
   char* author;
   DATETIME datetime;
} Balasan;


/* ********* AKSES (Selektor) ********* */
#define ID(b) (b).id
#define IDPARENT(b) (b).idParent
#define TEXT(b) (b).text
#define AUTHOR(b) (b).author
#define DATETIME(b) (b).datetime

/*  Kamus Umum */
#define IDX_MIN_BALAS 0
/* Indeks minimum list */
#define IDX_UNDEF_BALAS -1
/* Indeks tak terdefinisi*/

typedef Balasan ElTypeBalasan; /* type elemen list */
typedef struct
{
   ElTypeBalasan* buffer; /* memori tempat penyimpan elemen (container) */
   int nEff;       /* >=0, banyaknya elemen efektif */
   int capacity;   /* ukuran elemen */
} ListDinBalasan;

/* ********** SELEKTOR ********** */
#define NEFF_BALAS(l) (l).nEff
#define BUFFER_BALAS(l) (l).buffer
#define ELMT_BALAS(l, i) (l).buffer[i]
#define CAPACITY_BALAS(l) (l).capacity

/* *** Kreator *** */
void CreateBalasan(Balasan* b);
/* I.S. sembarang */
/* F.S. Sebuah b kosong dan datetime now*/

void LoadBalasan(ListDinBalasan* l, char* path);
/* I.S. sembarang */
/* F.S. Sebuah b yang diload dari balasan.config*/

/* *** Display Pengguna *** */
void DisplayKicauan(Balasan b);
/* Proses : Menuliskan isi Kicauan dengan traversal. Informasi kicauan
   ditulis satu persatu dan diakhiri dengan newline */

void CreateListKicauan(ListDinKicau* l, int capacity);
/* I.S. sembarang */
/* F.S. Terbentuk ListDinKicau kosong dengan kapasitas capacity */


#endif
