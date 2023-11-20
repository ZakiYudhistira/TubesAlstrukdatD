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


typedef struct {
    int idBalasan;
    int idParent;
    Word text;
    Word author;
    DATETIME date;
} Balasan;

#define ID_BALASAN(b) (b).idBalasan
#define ID_PARENT_BALASAN(b) (b).idParent
#define TEXT_BALASAN(b) (b).text
#define AUTHOR_BALASAN(b) (b).author
#define DATETIME_BALASAN(b) (b).date

struct node {
    Balasan data;
    struct node* next;
    struct node* child;
};

typedef struct node Tree;

#define BALASAN(n) (n)->data
#define NEXT_NODE(n) (n)->next
#define CHILD_NODE(n) (n)->child


/*  Kamus Umum */
#define IDX_MIN_BALASAN 0
/* Indeks minimum list */
#define IDX_UNDEF_BALASAN -1
/* Indeks tak terdefinisi*/

typedef Tree* ElTypeBalasan; /* type elemen list */
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



void createBalasan(Balasan* b);

void createListBalasan(ListDinBalasan* l, int capacity);

int listBalasanLength(ListDinBalasan l);

void insertLastBalasan(ListDinBalasan* l, ElTypeBalasan val);

void expandListBalasan(ListDinBalasan* l, int num);

void deleteBalasanAt(ListDinBalasan* l, int idx);

int getIdxFromIdKicau(ListDinBalasan l, int idKicau);

Tree* getTreeFromIdKicau(ListDinBalasan l, int idKicau);


Tree* newRoot(Kicauan k);

Tree* newNode(Balasan data);

boolean isTreeEmpty(Tree* n);

Tree* addSibling(Tree* n, Balasan data);

Tree* addChild(Tree* n, Balasan data);

Tree* getParentFromChild(Tree* root, Tree* child);

Tree* getTreeFromIdParent(Tree* root, int idParent);

int treeMaxId(Tree* root);

void removeNode(Tree* n, Tree* newN);

void printBalasan(Balasan b, int depth);

void printTreeWithoutRoot(Tree* n, int depth);


void LoadBalasan(ListDinBalasan* l, Word path);


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
