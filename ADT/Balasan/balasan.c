#include "balasan.h"
#include "../Perintah/wordmachine.h"
#include "../Mesin Karakter/charmachine.h"
#include "../Perintah/perintah.h"
#include <stdio.h>
#include <stdlib.h>

/* *** Kreator *** */
void CreateBalasan(DataBalasan* b) {
    DATETIME D;
    ID_BALASAN(*b) = 0;
    TEXT_BALASAN(*b) = currentWord;
    AUTHOR_BALASAN(*b) = currentWord;
    GetLocalDATETIME(&D);
    DATETIME_BALASAN(*b) = D;
}
/* I.S. sembarang */
/* F.S. Sebuah b kosong dan datetime now*/

void CreateListBalasan(ListDinBalasan* l, int capacity) {
    BUFFER_BALASAN(*l) = (DataBalasan*)malloc(capacity * sizeof(DataBalasan));
    CAPACITY_BALASAN(*l) = capacity;
    NEFF_BALASAN(*l) = 0;
}
/* I.S. sembarang */
/* F.S. Terbentuk ListDinBalasan kosong dengan kapasitas capacity */

void CreateListListBalasan(ListDinListBalasan* l, int capacity) {
    BUFFER_LIST_BALASAN(*l) = (ElTypeListBalasan*)malloc(capacity * sizeof(ElTypeListBalasan));
    CAPACITY_LIST_BALASAN(*l) = capacity;
    NEFF_LIST_BALASAN(*l) = 0;
}
/* I.S. sembarang */
/* F.S. Terbentuk ListDinListBalasan kosong dengan kapasitas capacity */

void CreateElTypeListBalasan(ElTypeListBalasan* l, int idKicau, struct TreeNode* root) {
    ID_KICAU_LIST_BALASAN(*l) = idKicau;
    ROOT_LIST_BALASAN(*l) = root;
}
/* I.S. sembarang */
/* F.S. Terbentuk ElTypeListBalasan dengan idKicau dan root */

   /* ********** SELEKTOR (TAMBAHAN) ********** */
   /* *** Banyaknya elemen *** */
int ListBalasanLength(ListDinBalasan l) {
    return NEFF_BALASAN(l);
}
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

int ListListBalasanLength(ListDinListBalasan l) {
    return NEFF_LIST_BALASAN(l);
}
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

int ListBalasanMaxId(ListDinBalasan l) {
    int max = 0;
    for (int i = 0; i < NEFF_BALASAN(l); i++) {
        if (ID_BALASAN(ELMT_BALASAN(l, i)) > max) {
            max = ID_BALASAN(ELMT_BALASAN(l, i));
        }
    }
    return max;
}
/* Mengirimkan nilai id terbesar dari list l */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void InsertLastBalasan(ListDinBalasan* l, ElTypeBalasan val) {
    if (NEFF_BALASAN(*l) == CAPACITY_BALASAN(*l)) {
        ExpandListBalasan(l, 1);
    }
    ELMT_BALASAN(*l, NEFF_BALASAN(*l)) = val;
    NEFF_BALASAN(*l)++;
}
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

void InsertLastListBalasan(ListDinListBalasan* l, ElTypeListBalasan val) {
    if (NEFF_LIST_BALASAN(*l) == CAPACITY_LIST_BALASAN(*l)) {
        ExpandListListBalasan(l, 1);
    }
    ELMT_LIST_BALASAN(*l, NEFF_LIST_BALASAN(*l)) = val;
    NEFF_LIST_BALASAN(*l)++;
}
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

boolean isIdKicauInBalasan(ListDinListBalasan l, int idKicau) {
    int i = 0;
    while (ID_KICAU_LIST_BALASAN(ELMT_LIST_BALASAN(l, i)) != idKicau && i < ListListBalasanLength(l)) {
        i++;
    }
    return i != ListListBalasanLength(l);
}
// I.S. l terdefinisi
// F.S. mengembalikan true jika idKicau ada di list balasan

boolean isIdBalasanInBalasan(ListDinBalasan l, int idBalasan) {
    int i = 0;
    while (ID_BALASAN(ELMT_BALASAN(l, i)) != idBalasan && i < ListBalasanLength(l)) {
        i++;
    }
    return i != ListBalasanLength(l);
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void ExpandListBalasan(ListDinBalasan* l, int num) {
    DataBalasan* temp = (DataBalasan*)malloc((CAPACITY_BALASAN(*l) + num) * sizeof(DataBalasan));
    for (int i = 0; i < CAPACITY_BALASAN(*l); i++) {
        temp[i] = ELMT_BALASAN(*l, i);
    }
    free(BUFFER_BALASAN(*l));
    BUFFER_BALASAN(*l) = temp;
    CAPACITY_BALASAN(*l) += num;
}
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

void ExpandListListBalasan(ListDinListBalasan* l, int num) {
    ElTypeListBalasan* temp = (ElTypeListBalasan*)malloc((CAPACITY_LIST_BALASAN(*l) + num) * sizeof(ElTypeListBalasan));
    for (int i = 0; i < CAPACITY_LIST_BALASAN(*l); i++) {
        temp[i] = ELMT_LIST_BALASAN(*l, i);
    }
    free(BUFFER_LIST_BALASAN(*l));
    BUFFER_LIST_BALASAN(*l) = temp;
    CAPACITY_LIST_BALASAN(*l) += num;
}
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */


boolean isIdParentExist(ListDinBalasan l, int idParent) {
    int i = 0;
    while (IDPARENT_BALASAN(ELMT_BALASAN(l, i)) != idParent && i < ListBalasanLength(l)) {
        i++;
    }
    return i != ListBalasanLength(l);
}

void DeleteBalasanAt(ListDinBalasan* l, int idx) {
    for (int i = idx; i < NEFF_BALASAN(*l) - 1; i++) {
        ELMT_BALASAN(*l, i) = ELMT_BALASAN(*l, i + 1);
    }
    NEFF_BALASAN(*l)--;
}

int GetIdxBalasan(ListDinBalasan l, int idBalasan) {
    int i = 0;
    while (ID_BALASAN(ELMT_BALASAN(l, i)) != idBalasan && i < ListBalasanLength(l)) {
        i++;
    }
    return i;
}

int GetIdxBalasanFromParentId(ListDinBalasan l, int idParent) {
    int i = 0;
    while (IDPARENT_BALASAN(ELMT_BALASAN(l, i)) != idParent && i < ListBalasanLength(l)) {
        i++;
    }
    return i;
}

int GetIdxListBalasan(ListDinListBalasan l, int idKicau) {
    int i = 0;
    while (ID_KICAU_LIST_BALASAN(ELMT_LIST_BALASAN(l, i)) != idKicau && i < ListListBalasanLength(l)) {
        i++;
    }
    return i;
}

struct TreeNode* CreateTreeNode(DataBalasan* b) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    DATA_BALASAN(node) = b;
    FIRST_CHILD(node) = NULL;
    NEXT_SIBLING(node) = NULL;
    return node;
}
/* I.S. sembarang */
/* F.S. Sebuah TreeNode kosong dengan data b */

void AddChildBalasan(struct TreeNode* parent, struct TreeNode* child) {
    if (FIRST_CHILD(parent) == NULL) {
        FIRST_CHILD(parent) = child;
    }
    else {
        struct TreeNode* temp = FIRST_CHILD(parent);
        while (NEXT_SIBLING(temp) != NULL) {
            temp = NEXT_SIBLING(temp);
        }
        NEXT_SIBLING(temp) = child;
    }
}

TreeNode* SearchTreeNode(struct TreeNode* root, int id) {
    if (root == NULL) {
        return NULL;
    }
    if (ID_BALASAN(*DATA_BALASAN(root)) == id) {
        return root;
    }
    TreeNode* temp = SearchTreeNode(FIRST_CHILD(root), id);
    if (temp != NULL) {
        return temp;
    }
    return SearchTreeNode(NEXT_SIBLING(root), id);
}

TreeNode* DeleteTreeNode(struct TreeNode* root, int idParent) {
    ListDinBalasan l;
    CreateListBalasan(&l, 10);
    TreeToListBalasan(&l, root);
}

TreeNode* GetTreeFromIdKicau(ListDinListBalasan l, int idKicau) {
    for (int i = 0; i < NEFF_LIST_BALASAN(l); i++) {
        if (ID_KICAU_LIST_BALASAN(ELMT_LIST_BALASAN(l, i)) == idKicau) {
            return ROOT_LIST_BALASAN(ELMT_LIST_BALASAN(l, i));
        }
    }
    return NULL;
}

/* *** Display Balasan *** */
void DisplayBalasan(DataBalasan b, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("| ID = %d\n", ID_BALASAN(b));
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("| ");
    printWord(AUTHOR_BALASAN(b));
    printf("\n");
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("| ");
    printWord(TimeToWord(DATETIME_BALASAN(b)));
    printf("\n");
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("| ");
    printWord(TEXT_BALASAN(b));
    printf("\n\n");
}
/* Proses : Menuliskan isi DataBalasan dengan traversal. Informasi balasan
   ditulis satu persatu dan diakhiri dengan newline */

void DisplayListBalasan(ListDinBalasan l) {
    for (int i = 0; i < NEFF_BALASAN(l); i++) {
        if (IDPARENT_BALASAN(ELMT_BALASAN(l, i)) == -1) {
            DisplayBalasan(ELMT_BALASAN(l, i), 0);
        }
        else {
            DisplayBalasan(ELMT_BALASAN(l, i), IDPARENT_BALASAN(ELMT_BALASAN(l, i)));
        }
    }
}

void DisplayListListBalasan(ListDinListBalasan l, int idKicau) {
    for (int i = 0; i < NEFF_LIST_BALASAN(l); i++) {
        if (ID_KICAU_LIST_BALASAN(ELMT_LIST_BALASAN(l, i)) == idKicau) {
            ListDinBalasan li;
            CreateListBalasan(&li, 10);
            TreeToListBalasan(&li, ROOT_LIST_BALASAN(ELMT_LIST_BALASAN(l, i)));
            DisplayListBalasan(li);
            break;
        }
    }
}

void DisplayTreeBalasan(struct TreeNode* root, int depth) {
    if (root == NULL) {
        return;
    }
    DisplayBalasan(*DATA_BALASAN(root), depth);
    DisplayTreeBalasan(FIRST_CHILD(root), depth + 1);
    DisplayTreeBalasan(NEXT_SIBLING(root), depth);
}

void TreeToListBalasan(ListDinBalasan* l, struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    InsertLastBalasan(l, *DATA_BALASAN(root));
    TreeToListBalasan(l, FIRST_CHILD(root));
    TreeToListBalasan(l, NEXT_SIBLING(root));
}

TreeNode* ListBalasanToTree(ListDinBalasan l) {
    TreeNode* root = NULL;
    for (int i = 0; i < NEFF_BALASAN(l); i++) {
        if (IDPARENT_BALASAN(ELMT_BALASAN(l, i)) == -1) {
            TreeNode* node = CreateTreeNode(&ELMT_BALASAN(l, i));
            if (root == NULL) {
                root = node;
            }
            else {
                AddChildBalasan(root, node);
            }
        }
        else {
            TreeNode* parent = SearchTreeNode(root, IDPARENT_BALASAN(ELMT_BALASAN(l, i)));
            TreeNode* node = CreateTreeNode(&ELMT_BALASAN(l, i));
            if (FIRST_CHILD(parent) == NULL) {
                FIRST_CHILD(parent) = node;
            }
            else {
                AddChildBalasan(parent, node);
            }
        }
    }
    return root;
}


void LoadBalasan(ListDinListBalasan* li, Word path) {
    FILE* file = fopen(path.TabWord, "r");
    char line[300];

    if (file == NULL) {
        printf("File tidak ditemukan\n");
        exit(EXIT_FAILURE);
    }

    fgets(line, 300, file);
    StringToWord(line, &currentWord);
    int banyak_kicau = WordToInt(removeNewline(currentWord));
    for (int i = 0; i < banyak_kicau; i++) {
        fgets(line, 300, file);
        StringToWord(line, &currentWord);
        int idKicau = WordToInt(removeNewline(currentWord));

        fgets(line, 300, file);
        StringToWord(line, &currentWord);
        int banyak_balasan = WordToInt(removeNewline(currentWord));

        ListDinBalasan l;
        CreateListBalasan(&l, 10);

        for (int j = 0; j < banyak_balasan; j++) {
            DataBalasan b;
            CreateBalasan(&b);

            fgets(line, 300, file);
            StringToWord(line, &currentWord);

            Word idBalasan, idParent;
            splitWord(currentWord, &idBalasan, &idParent);
            IDPARENT_BALASAN(b) = WordToInt(idBalasan);
            ID_BALASAN(b) = WordToInt(removeNewline(idParent));

            fgets(line, 300, file);
            StringToWord(line, &currentWord);
            TEXT_BALASAN(b) = removeNewline(currentWord);

            fgets(line, 300, file);
            StringToWord(line, &currentWord);
            AUTHOR_BALASAN(b) = removeNewline(currentWord);

            fgets(line, 300, file);
            StringToWord(line, &currentWord);
            DATETIME_BALASAN(b) = WordToTime(removeNewline(currentWord));

            InsertLastBalasan(&l, b);
        }

        ElTypeListBalasan el;
        CreateElTypeListBalasan(&el, idKicau, ListBalasanToTree(l));

        InsertLastListBalasan(li, el);
    }

    fclose(file);
}
/* I.S. sembarang */
/* F.S. Sebuah b yang diload dari balasan.config*/

boolean isBalas(Word option) {
    char* suka = "BALAS";
    int i = 0;

    if (option.Length > 6) {
        for (i = 0; i < 5; i++) {
            if (option.TabWord[i] != suka[i]) {
                return false;
            }
        }
    }
    else {
        return false;
    }
    return true;
}
// I.S. option terdefinisi
// F.S. mengembalikan true jika option adalah "BALAS [IDKicau] [IDBalasan]"

boolean isBalasan(Word option) {
    char* suka = "BALASAN";
    int i = 0;

    if (option.Length > 8) {
        for (i = 0; i < 7; i++) {
            if (option.TabWord[i] != suka[i]) {
                return false;
            }
        }
    }
    else {
        return false;
    }
    return true;
}
// I.S. option terdefinisi
// F.S. mengembalikan true jika option adalah "BALASAN [IDKicau]"

boolean isHapusBalasan(Word option) {
    char* suka = "HAPUS_BALASAN";
    int i = 0;

    if (option.Length > 14) {
        for (i = 0; i < 13; i++) {
            if (option.TabWord[i] != suka[i]) {
                return false;
            }
        }
    }
    else {
        return false;
    }
    return true;
}
// I.S. option terdefinisi
// F.S. mengembalikan true jika option adalah "HAPUS_BALASAN [IDKicau] [IDBalasan]"