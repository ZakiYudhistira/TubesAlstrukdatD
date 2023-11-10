/* File : pengguna.h */

#ifndef PENGGUNA_H
#define PENGGUNA_H


#include "../../boolean.h"
#include "../Mesin Kata/wordmachine.h"
#include "../Matrix/matrix.h"

#define CAPACITY 20 /* Kapasitas penyimpanan */
#define IDX_MIN 0 /* Indeks minimum list */
#define IDX_UNDEF -1
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

typedef Pengguna Type;
typedef struct {
   Type contents[CAPACITY]; /* memori tempat penyimpan elemen (container) */
} databaseprofil;


/* ********* AKSES (Selektor) ********* */
/* Jika p adalah Pengguna, maka akses elemen : */
#define nama(l,i) (l).contents[i].nama
#define password(l,i) (l).contents[i].password
#define bio(l,i) (l).contents[i].bio
#define hp(l,i) (l).contents[i].hp
#define weton(l,i) (l).contents[i].weton
#define jenis(l,i) (l).contents[i].jenis
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

void ReadPengguna(Pengguna* p, databaseprofil *l);
/* I.S. sembarang */
/* F.S. Sebuah p terbentuk dengan isi masing-masing berupa Word yang diakuisisi
   dari stdin */

   /* *** Display Pengguna *** */
void displayPengguna(Pengguna p);
/* Proses : Menuliskan isi Pengguna dengan traversal. Informasi pengguna
   ditulis satu persatu dan diakhiri dengan newline */

boolean isWordEqual(Word uname1, Word uname2);
// Validasi kata

void createDatabase (databaseprofil *l);
// Membuat database profil yang isinya kosong

int listLength (databaseprofil *l);
// Menentukan panjang dari sebuah database profil

void insertLast(databaseprofil *l, Pengguna val);
// Memasukkan di paling belakang

int login(databaseprofil *data);
// Mendapatkan nilai dari indeks username dan password sesuai
void cekProfil (int idx, databaseprofil *data);
// Pengguna cek profil

void ubahProfil(databaseprofil *data);
// Mengubah profil

boolean inputHP(Word nomor);
/* Validasi nomor HP */

Word inputusername();
/* Input username */

Word inputbio();
/* Inpur Bio */

int getId(databaseprofil *l, Word username);
#endif
