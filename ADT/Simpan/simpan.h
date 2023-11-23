/* File: perintah.h */
/* Definisi Perintah (input mesin kata) */

#ifndef SIMPAN_H
#define SIMPAN_H

#include "../Pengguna/pengguna.h"
#include "../Pertemanan/pertemanan.h"
#include "../Perintah/perintah.h"
#include "../Mesin Karakter/charmachine.h"
#include "../boolean.h"
#include "../Kicauan/kicauan.h"
#include "../Balasan/balasan.h"


typedef Balasan ElTypeLDBalasan; /* type elemen list */
typedef struct {
    ElTypeLDBalasan* bufferLDB; /* memori tempat penyimpan elemen (container) */
    int nEffLDB;       /* >=0, banyaknya elemen efektif */
    int capacityLDB;   /* ukuran elemen */
} LDBalasan;

/* ********** SELEKTOR ********** */
#define NEFF_LDB(l) (l).nEffLDB
#define BUFFER_LDB(l) (l).bufferLDB
#define ELMT_LDB(l, i) (l).bufferLDB[i]
#define CAPACITY_LDB(l) (l).capacityLDB


void createLDB(LDBalasan* l, int capacity);

int LDBLength(LDBalasan l);

void insertLastLDB(LDBalasan* l, ElTypeLDBalasan val);

void expandLDB(LDBalasan* l, int num);

LDBalasan sortLDBOnIdBalasan(LDBalasan l);

LDBalasan treeToLDB(Tree* t);



void writePertemananConfig(Matrix_pertemanan matrix_teman, Matrix_Permintaan matrix_permintaan, databaseprofil database, Word path);

void writeKicauanConfig(ListDinKicau k, Word path);

void writeBalasanConfig(ListDinBalasan l, Word path);

#endif