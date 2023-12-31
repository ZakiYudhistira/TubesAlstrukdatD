/* File : kicauan.h */

#ifndef KICAUAN_H
#define KICAUAN_H

#define _XOPEN_SOURCE

#include "../boolean.h"
#include "../Perintah/wordmachine.h"
#include <time.h>
#include "../Datetime/datetime.h"
#include "../Time/time.h"
#include "../Pertemanan/pertemanan.h"
#include "../Pengguna/pengguna.h"

/* Definisi elemen dan address */
typedef struct {
   int id;
   Word text;
   int like;
   Word author;
   DATETIME datetime;
} Kicauan;

/* ********* AKSES (Selektor) ********* */
/* Jika k adalah Kicauan, maka akses elemen : */
#define ID_KICAU(k) (k).id
#define TEXT_KICAU(k) (k).text
#define LIKE_KICAU(k) (k).like
#define AUTHOR_KICAU(k) (k).author
#define DATETIME_KICAU(k) (k).datetime

/*  Kamus Umum */
#define IDX_MIN_KICAU 0
/* Indeks minimum list */
#define IDX_UNDEF_KICAU -1
/* Indeks tak terdefinisi*/

typedef Kicauan ElTypeKicau; /* type elemen list */
typedef struct
{
   ElTypeKicau* buffer; /* memori tempat penyimpan elemen (container) */
   int nEff;       /* >=0, banyaknya elemen efektif */
   int capacity;   /* ukuran elemen */
} ListDinKicau;

/* ********** SELEKTOR ********** */
#define NEFF_KICAU(l) (l).nEff
#define BUFFER_KICAU(l) (l).buffer
#define ELMT_KICAU(l, i) (l).buffer[i]
#define CAPACITY_KICAU(l) (l).capacity


/* *** Kreator *** */
void CreateKicauan(Kicauan* k);
/* I.S. sembarang */
/* F.S. Sebuah k kosong dan datetime now*/


void LoadKicauan(ListDinKicau* l, Word path);
/* I.S. sembarang */
/* F.S. Sebuah k yang diload dari kicauan.config*/

/* *** Display Pengguna *** */
void DisplayKicauan(Kicauan k);
/* Proses : Menuliskan isi Kicauan dengan traversal. Informasi kicauan
   ditulis satu persatu dan diakhiri dengan newline */


void CreateListKicauan(ListDinKicau* l, int capacity);
/* I.S. sembarang */
/* F.S. Terbentuk ListDinKicau kosong dengan kapasitas capacity */

   /* ********** SELEKTOR (TAMBAHAN) ********** */
   /* *** Banyaknya elemen *** */
int ListKicauLength(ListDinKicau l);
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

int ListKicauMaxId(ListDinKicau l);
/* Mengirimkan nilai id terbesar dari list l */

boolean isIdKicauValid(ListDinKicau l, int idKicau);
// I.S. l terdefinisi
// F.S. mengembalikan true jika idKicau ada di list kicauan

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void InsertLastKicau(ListDinKicau* l, ElTypeKicau val);
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void ExpandListKicau(ListDinKicau* l, int num);
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */


boolean isSuka(Word option);
// I.S. option terdefinisi
// F.S. mengembalikan true jika option adalah "SUKA_KICAUAN [IDKicau]"

boolean isUbah(Word option);
// I.S. option terdefinisi
// F.S. mengembalikan true jika option adalah "UBAH_KICAUAN [IDKicau]"

ListDinKicau SortedKicauan(ListDinKicau l);
// I.S. l terdefinisi
// F.S. mengembalikan list kicauan yang sudah terurut berdasarkan waktu terbaru


// Command Handler
void HandleKicau(ListDinKicau* l, Word username, int* idKicauan);

void HandleKicauan(ListDinKicau l, Word username, Matrix_pertemanan m, databaseprofil p);

void HandleSukaKicau(ListDinKicau* l, int idKicauan, Word username, Matrix_pertemanan m, databaseprofil p);

void HandleUbahKicau(ListDinKicau* l, Word username, int idKicauan);

#endif
