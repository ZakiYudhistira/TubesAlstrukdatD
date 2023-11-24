#include "balasan.h"
#include "../Perintah/wordmachine.h"
#include "../Mesin Karakter/charmachine.h"
#include "../Perintah/perintah.h"
#include <stdio.h>
#include <stdlib.h>
#include "../Pertemanan/pertemanan.h"
#include "../Pengguna/pengguna.h"

void createBalasan(Balasan* b) {
    DATETIME D;
    ID_BALASAN(*b) = 0;
    TEXT_BALASAN(*b) = currentWord;
    AUTHOR_BALASAN(*b) = currentWord;
    GetLocalDATETIME(&D);
    DATETIME_BALASAN(*b) = D;
}

void createListBalasan(ListDinBalasan* l, int capacity) {
    BUFFER_BALASAN(*l) = (ElTypeBalasan*)malloc(capacity * sizeof(ElTypeBalasan));
    CAPACITY_BALASAN(*l) = capacity;
    NEFF_BALASAN(*l) = 0;
}

int listBalasanLength(ListDinBalasan l) {
    return NEFF_BALASAN(l);
}

void insertLastBalasan(ListDinBalasan* l, ElTypeBalasan val) {
    if (NEFF_BALASAN(*l) == CAPACITY_BALASAN(*l)) {
        expandListBalasan(l, 1);
    }
    ELMT_BALASAN(*l, NEFF_BALASAN(*l)) = val;
    NEFF_BALASAN(*l)++;
}

void expandListBalasan(ListDinBalasan* l, int num) {
    BUFFER_BALASAN(*l) = (ElTypeBalasan*)realloc(BUFFER_BALASAN(*l), (CAPACITY_BALASAN(*l) + num) * sizeof(ElTypeBalasan));
    CAPACITY_BALASAN(*l) += num;
}

void deleteBalasanAt(ListDinBalasan* l, int idx) {
    for (int i = idx; i < NEFF_BALASAN(*l) - 1; i++) {
        ELMT_BALASAN(*l, i) = ELMT_BALASAN(*l, i + 1);
    }
    NEFF_BALASAN(*l)--;
}

int getIdxFromIdKicau(ListDinBalasan l, int idKicau) {
    for (int i = 0; i < listBalasanLength(l); i++) {
        if (ID_BALASAN(BALASAN(ELMT_BALASAN(l, i))) == idKicau) {
            return i;
        }
    }
    return -1;
}

Tree* getTreeFromIdKicau(ListDinBalasan l, int idKicau) {
    for (int i = 0; i < listBalasanLength(l); i++) {
        if (ID_BALASAN(BALASAN(ELMT_BALASAN(l, i))) == idKicau) {
            return ELMT_BALASAN(l, i);
        }
    }
    return NULL;
}

Tree* newRoot(Kicauan k) {
    Tree* n = (Tree*)malloc(sizeof(Tree));
    if (n != NULL) {
        DATETIME D;
        GetLocalDATETIME(&D);
        BALASAN(n) = (Balasan){ -ID_KICAU(k), 0,  currentWord, currentWord, D };
        NEXT_NODE(n) = NULL;
        CHILD_NODE(n) = NULL;
    }
    return n;
}

Tree* newNode(Balasan data) {
    Tree* n = (Tree*)malloc(sizeof(Tree));
    if (n != NULL) {
        BALASAN(n) = data;
        NEXT_NODE(n) = NULL;
        CHILD_NODE(n) = NULL;
    }
    return n;
}

boolean isTreeEmpty(Tree* n) {
    return CHILD_NODE(n) == NULL && NEXT_NODE(n) == NULL;
}

Tree* addSibling(Tree* n, Balasan data) {
    if (n == NULL) {
        return NULL;
    }

    while (NEXT_NODE(n) != NULL) {
        n = NEXT_NODE(n);
    }

    return (NEXT_NODE(n) = newNode(data));
}

Tree* addChild(Tree* n, Balasan data) {
    if (n == NULL) {
        return NULL;
    }

    if (CHILD_NODE(n)) {
        return addSibling(CHILD_NODE(n), data);
    }
    else {
        return (CHILD_NODE(n) = newNode(data));
    }
}

Tree* getParentFromChild(Tree* root, Tree* child) {
    if (root == NULL || child == NULL) {
        return NULL;
    }

    if (CHILD_NODE(root) == child) {
        return root;
    }

    Tree* current = CHILD_NODE(root);

    while (current != NULL) {
        if (NEXT_NODE(current) == child) {
            return root;
        }
        current = NEXT_NODE(current);
    }

    current = CHILD_NODE(root);

    while (current != NULL) {
        Tree* parent = getParentFromChild(current, child);
        if (parent != NULL) {
            return parent;
        }
        current = NEXT_NODE(current);
    }

    return NULL;
}

Tree* getTreeFromIdParent(Tree* root, int idParent) {
    if (root == NULL) {
        return NULL;
    }

    if (ID_BALASAN(BALASAN(root)) == idParent) {
        return root;
    }

    Tree* current = CHILD_NODE(root);

    while (current != NULL) {
        Tree* parent = getTreeFromIdParent(current, idParent);
        if (parent != NULL) {
            return parent;
        }
        current = NEXT_NODE(current);
    }

    return NULL;
}

int treeMaxId(Tree* root) {
    if (root == NULL) {
        return -1;
    }

    int max = ID_BALASAN(BALASAN(root));

    Tree* current = CHILD_NODE(root);

    while (current != NULL) {
        int id = treeMaxId(current);
        if (id > max) {
            max = id;
        }
        current = NEXT_NODE(current);
    }

    return max;
}

void removeNode(Tree* parent, Tree* target) {
    if (parent == NULL || target == NULL) {
        return;
    }

    if (parent == target) {
        free(parent);
        return;
    }

    if (CHILD_NODE(parent) == target) {
        CHILD_NODE(parent) = NEXT_NODE(target);
        free(target);
        return;
    }

    Tree* current = CHILD_NODE(parent);

    while (current != NULL && NEXT_NODE(current) != target) {
        current = NEXT_NODE(current);
    }

    if (current != NULL) {
        NEXT_NODE(current) = NEXT_NODE(target);
        free(target);
    }
}

void printBalasan(Balasan b, int depth, Word username, Matrix_pertemanan m, databaseprofil p) {
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("| ID = %d\n", ID_BALASAN(b));

    if (isTeman(m, getId(&p, username), getId(&p, AUTHOR_BALASAN(b))) || jenis(p, getId(&p, AUTHOR_BALASAN(b))) == 0) {
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

    }
    else {
        for (int i = 0; i < depth; i++) {
            printf("  ");
        }
        printf("| PRIVAT\n");
        for (int i = 0; i < depth; i++) {
            printf("  ");
        }
        printf("| PRIVAT\n");
        for (int i = 0; i < depth; i++) {
            printf("  ");
        }
        printf("| PRIVAT");
    }
    printf("\n\n");
}

void printTreeWithoutRoot(Tree* n, int depth, Word username, Matrix_pertemanan m, databaseprofil p) {
    if (ID_BALASAN(BALASAN(n)) >= 0) {
        printBalasan(BALASAN(n), depth, username, m, p);
    }

    if (CHILD_NODE(n) != NULL) {
        printTreeWithoutRoot(CHILD_NODE(n), depth + 1, username, m, p);
    }

    if (NEXT_NODE(n) != NULL) {
        printTreeWithoutRoot(NEXT_NODE(n), depth, username, m, p);
    }
}


void LoadBalasan(ListDinBalasan* l, Word path) {
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

        Kicauan k;
        CreateKicauan(&k);
        ID_KICAU(k) = idKicau;

        Tree* root = newRoot(k);

        fgets(line, 300, file);
        StringToWord(line, &currentWord);
        int banyak_balasan = WordToInt(removeNewline(currentWord));

        for (int j = 0; j < banyak_balasan; j++) {
            Balasan b;
            createBalasan(&b);

            fgets(line, 300, file);
            StringToWord(line, &currentWord);

            Word idBalasan, idParent;
            splitWord(currentWord, &idBalasan, &idParent);
            ID_PARENT_BALASAN(b) = WordToInt(idBalasan);
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

            if (j == 0) {
                Tree* t = addChild(root, b);
            }
            else {
                Tree* t = addChild(getTreeFromIdParent(root, ID_PARENT_BALASAN(b)), b);
            }
        }

        insertLastBalasan(l, root);
    }

    fclose(file);
}


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


void HandleBalas(Word idKicau, Word idBalas, ListDinKicau k, ListDinBalasan* b, Word username, Matrix_pertemanan m, databaseprofil p) {
    if (isIdKicauValid(k, WordToInt(idKicau))) {
        Tree* t = getTreeFromIdKicau(*b, -WordToInt(idKicau));
        if (t != NULL) {
            Tree* t2 = getTreeFromIdParent(t, WordToInt(idBalas));
            if (t2 != NULL) {
                if (isTeman(m, getId(&p, username), getId(&p, AUTHOR_BALASAN(BALASAN(t2)))) || jenis(p, getId(&p, AUTHOR_BALASAN(BALASAN(t2)))) == 0) {
                    Balasan ba;
                    createBalasan(&ba);

                    printf("Masukkan balasan:\n");
                    perintah(280, true);
                    ADV();
                    TEXT_BALASAN(ba) = currentWord;
                    AUTHOR_BALASAN(ba) = username;
                    DATETIME D;
                    GetLocalDATETIME(&D);
                    DATETIME_BALASAN(ba) = D;
                    ID_BALASAN(ba) = treeMaxId(t) + 1;
                    ID_PARENT_BALASAN(ba) = WordToInt(idBalas);

                    printf("Selamat! balasan telah diterbitkan!\n");
                    printf("Detil balasan:\n");
                    printBalasan(ba, 0, username, m, p);

                    addChild(t2, ba);
                }
                else {
                    printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman akun tersebut!\n");
                }
            }
            else {
                printf("Wah, tidak terdapat balasan yang ingin Anda balas!\n");
            }
        }
        else {
            if (WordToInt(idBalas) == -1) {
                if (isTeman(m, getId(&p, username), getId(&p, AUTHOR_KICAU(ELMT_KICAU(k, WordToInt(idKicau) - 1)))) || jenis(p, getId(&p, AUTHOR_KICAU(ELMT_KICAU(k, WordToInt(idKicau) - 1))))) {
                    Balasan ba;
                    createBalasan(&ba);

                    printf("Masukkan balasan:\n");
                    perintah(280, true);
                    ADV();
                    TEXT_BALASAN(ba) = currentWord;
                    AUTHOR_BALASAN(ba) = username;
                    DATETIME D;
                    GetLocalDATETIME(&D);
                    DATETIME_BALASAN(ba) = D;
                    ID_BALASAN(ba) = 1;
                    ID_PARENT_BALASAN(ba) = -1;

                    printf("Selamat! balasan telah diterbitkan!\n");
                    printf("Detil balasan:\n");
                    printBalasan(ba, 0, username, m, p);

                    addChild(getTreeFromIdKicau(*b, WordToInt(idBalas)), ba);
                }
                else {
                    printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman akun tersebut!\n");
                }
            }
            else {
                printf("Wah, tidak terdapat balasan yang ingin Anda balas!\n");
            }
        }
    }
    else {
        printf("Wah, tidak terdapat kicauan yang ingin Anda balas!\n");
    }
}

void HandleBalasan(Word idKicau, ListDinKicau k, ListDinBalasan b, Word username, Matrix_pertemanan m, databaseprofil p) {
    if (isTeman(m, getId(&p, username), getId(&p, AUTHOR_KICAU(ELMT_KICAU(k, WordToInt(idKicau) - 1)))) || jenis(p, getId(&p, AUTHOR_KICAU(ELMT_KICAU(k, WordToInt(idKicau) - 1))))) {
        if (isIdKicauValid(k, WordToInt(idKicau))) {
            if (getTreeFromIdKicau(b, -WordToInt(idKicau)) != NULL) {
                printf("\n");
                printTreeWithoutRoot(getTreeFromIdKicau(b, -WordToInt(idKicau)), 0, username, m, p);
            }
            else {
                printf("Belum terdapat balasan apapun pada kicauan tersebut. Yuk balas kicauan tersebut!\n");
            }
        }
        else {
            printf("Tidak terdapat kicauan dengan id tersebut!\n");
        }
    }
    else {
        printf("Wah, kicauan tersebut dibuat oleh pengguna dengan akun privat!\n");
    }
}

void HandleHapusBalasan(Word idKicau, Word idBalas, ListDinBalasan* b, Word username) {
    Tree* t = getTreeFromIdKicau(*b, -WordToInt(idKicau));
    if (t != NULL) {
        Tree* t2 = getTreeFromIdParent(t, WordToInt(idBalas));
        if (t2 != NULL) {
            if (isSame(AUTHOR_BALASAN(BALASAN(t2)), username)) {
                removeNode(getParentFromChild(t, t2), t2);
                printf("Balasan berhasil dihapus\n");
            }
            else {
                printf("Hei, ini balasan punya siapa? Jangan dihapus ya!\n");
            }
        }
        else {
            printf("Balasan tidak ditemukan\n");
        }

        if (isTreeEmpty(t)) {
            deleteBalasanAt(b, getIdxFromIdKicau(*b, WordToInt(idKicau)));
        }
    }
    else {
        printf("Tidak terdapat balasan pada kicauan dengan id tersebut!\n");
    }
}