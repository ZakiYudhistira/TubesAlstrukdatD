/* File : pengguna.h */

#ifndef PENGGUNA_H
#define PENGGUNA_H


#include "../boolean.h"
#include "../Mesin Kata/wordmachine.h"
#include "../Matrix/matrix.h"

/* Definisi elemen dan address */
typedef struct {
   Word nama;
   Word password;
   Word bio;
   Word hp;
   Word weton;
   Word jenis;
   Matrix profil;
} Pengguna;


/* ********* AKSES (Selektor) ********* */
/* Jika p adalah Pengguna, maka akses elemen : */
#define NAMA(p) (p).nama
#define PASSWORD(p) (p).password
#define BIO(p) (p).bio
#define HP(p) (p).hp
#define WETON(p) (p).weton
#define JENIS(p) (p).jenis
#define PROFIL(p) (p).profil

/* *** Kreator *** */
void CreatePengguna(Pengguna* p);
/* I.S. sembarang */
/* F.S. Sebuah p kosong terbentuk dengan isi masing-masing berupa Word kosong */

void ReadPengguna(Pengguna* p);
/* I.S. sembarang */
/* F.S. Sebuah p terbentuk dengan isi masing-masing berupa Word yang diakuisisi
   dari stdin */

   /* *** Display Pengguna *** */
void displayPengguna(Pengguna p);
/* Proses : Menuliskan isi Pengguna dengan traversal. Informasi pengguna
   ditulis satu persatu dan diakhiri dengan newline */

#endif
