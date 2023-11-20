/* File : balasan.h */

#ifndef BALASAN_H
#define BALASAN_H

#define _XOPEN_SOURCE

#include "../boolean.h"
#include "../Perintah/wordmachine.h"
#include "../Perintah/perintah.h"
#include "../Kicauan/kicauan.h"
#include <time.h>
#include "../Datetime/datetime.h"
#include "../Time/time.h"

/* Definisi elemen dan address */
typedef struct {
   int id;
   int idParent;
   Word text;
   Word author;
   DATETIME datetime;
} DataBalasan;


/* ********* AKSES (Selektor) ********* */
#define ID_BALASAN(b) (b).id
#define IDPARENT_BALASAN(b) (b).idParent
#define TEXT_BALASAN(b) (b).text
#define AUTHOR_BALASAN(b) (b).author
#define DATETIME_BALASAN(b) (b).datetime

typedef struct TreeNode {
   DataBalasan* dataBalasan;
   struct TreeNode* firstChild;
   struct TreeNode* nextSibling;
} TreeNode;

#define DATA_BALASAN(t) (t)->dataBalasan
#define FIRST_CHILD(t) (t)->firstChild
#define NEXT_SIBLING(t) (t)->nextSibling

/*  Kamus Umum */
#define IDX_MIN_BALASAN 0
/* Indeks minimum list */
#define IDX_UNDEF_BALASAN -1
/* Indeks tak terdefinisi*/

typedef DataBalasan ElTypeBalasan; /* type elemen list */
typedef struct {
   ElTypeBalasan* buffer; /* memori tempat penyimpan elemen (container) */
   int nEff;       /* >=0, banyaknya elemen efektif */
   int capacity;   /* ukuran elemen */
} ListDinBalasan;

/* ********** SELEKTOR ********** */
#define NEFF_BALASAN(l) (l).nEff
#define BUFFER_BALASAN(l) (l).buffer
#define ELMT_BALASAN(l, i) (l).buffer[i]
#define CAPACITY_BALASAN(l) (l).capacity

typedef struct {
   int idKicau;
   struct TreeNode* root;
} ElTypeListBalasan;

#define ID_KICAU_LIST_BALASAN(l) (l).idKicau
#define ROOT_LIST_BALASAN(l) (l).root

typedef struct {
   ElTypeListBalasan* bufferBalasan; /* memori tempat penyimpan elemen (container) */
   int nEffBalasan;       /* >=0, banyaknya elemen efektif */
   int capacityBalasan;   /* ukuran elemen */
} ListDinListBalasan;

#define NEFF_LIST_BALASAN(l) (l).nEffBalasan
#define BUFFER_LIST_BALASAN(l) (l).bufferBalasan
#define ELMT_LIST_BALASAN(l, i) (l).bufferBalasan[i]
#define CAPACITY_LIST_BALASAN(l) (l).capacityBalasan


/* *** Kreator *** */
void CreateBalasan(DataBalasan* b);
/* I.S. sembarang */
/* F.S. Sebuah b kosong dan datetime now*/

void CreateListBalasan(ListDinBalasan* l, int capacity);
/* I.S. sembarang */
/* F.S. Terbentuk ListDinBalasan kosong dengan kapasitas capacity */

void CreateListListBalasan(ListDinListBalasan* l, int capacity);
/* I.S. sembarang */
/* F.S. Terbentuk ListDinListBalasan kosong dengan kapasitas capacity */

void CreateElTypeListBalasan(ElTypeListBalasan* l, int idKicau, struct TreeNode* root);
/* I.S. sembarang */
/* F.S. Terbentuk ElTypeListBalasan dengan idKicau dan root */

   /* ********** SELEKTOR (TAMBAHAN) ********** */
   /* *** Banyaknya elemen *** */
int ListBalasanLength(ListDinBalasan l);
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

int ListListBalasanLength(ListDinListBalasan l);
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

int ListBalasanMaxId(ListDinBalasan l);
/* Mengirimkan nilai id terbesar dari list l */


/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void InsertLastBalasan(ListDinBalasan* l, ElTypeBalasan val);
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

void InsertLastListBalasan(ListDinListBalasan* l, ElTypeListBalasan val);
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

boolean isIdKicauInBalasan(ListDinListBalasan l, int idKicau);
// I.S. l terdefinisi
// F.S. mengembalikan true jika idKicau ada di list balasan

boolean isIdBalasanInBalasan(ListDinBalasan l, int idBalasan);

/* ********* MENGUBAH UKURAN ARRAY ********* */
void ExpandListBalasan(ListDinBalasan* l, int num);
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

void ExpandListListBalasan(ListDinListBalasan* l, int num);
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

boolean isIdParentExist(ListDinBalasan l, int idParent);

void DeleteBalasanAt(ListDinBalasan* l, int idx);

int GetIdxBalasan(ListDinBalasan l, int idBalasan);

int GetIdxBalasanFromParentId(ListDinBalasan l, int idParent);

int GetIdxListBalasan(ListDinListBalasan l, int idKicau);

struct TreeNode* CreateTreeNode(DataBalasan* b);
/* I.S. sembarang */
/* F.S. Sebuah TreeNode kosong dengan data b */

void AddChildBalasan(struct TreeNode* parent, struct TreeNode* child);
/* I.S. sembarang */
/* F.S. Sebuah TreeNode kosong dengan data b */

TreeNode* SearchTreeNode(struct TreeNode* root, int id);

TreeNode* DeleteTreeNode(struct TreeNode* root, int idParent);

TreeNode* GetTreeFromIdKicau(ListDinListBalasan l, int idKicau);

/* *** Display Balasan *** */
void DisplayBalasan(DataBalasan b, int depth);
/* Proses : Menuliskan isi DataBalasan dengan traversal. Informasi balasan
   ditulis satu persatu dan diakhiri dengan newline */

void DisplayListBalasan(ListDinBalasan l);

void DisplayListListBalasan(ListDinListBalasan l, int idKicau);

void DisplayTreeBalasan(struct TreeNode* root, int depth);

// void CreateListKicauan(ListDinKicau* l, int capacity);
// /* I.S. sembarang */
// /* F.S. Terbentuk ListDinKicau kosong dengan kapasitas capacity */

void TreeToListBalasan(ListDinBalasan* l, struct TreeNode* root);

TreeNode* ListBalasanToTree(ListDinBalasan l);

void LoadBalasan(ListDinListBalasan* li, Word path);
/* I.S. sembarang */
/* F.S. Sebuah b yang diload dari balasan.config*/


boolean isBalas(Word option);
// I.S. option terdefinisi
// F.S. mengembalikan true jika option adalah "BALAS [IDKicau] [IDBalasan]"

boolean isBalasan(Word option);
// I.S. option terdefinisi
// F.S. mengembalikan true jika option adalah "BALASAN [IDKicau]"

boolean isHapusBalasan(Word option);
// I.S. option terdefinisi
// F.S. mengembalikan true jika option adalah "HAPUS_BALASAN [IDKicau] [IDBalasan]"

#endif
