#include <stdio.h>
#include "../Pengguna/pengguna.h"
#include "../Pertemanan/pertemanan.h"
#include "../Perintah/perintah.h"
#include "../Mesin Karakter/charmachine.h"
#include "../Kicauan/kicauan.h"
#include "../boolean.h"
#include "../Datetime/datetime.h"
#include "simpan.h"
#include "../Balasan/balasan.h"


#define nl(file) fprintf(file,"\n")

void createLDB(LDBalasan* l, int capacity) {
    BUFFER_LDB(*l) = (ElTypeLDBalasan*)malloc(capacity * sizeof(ElTypeLDBalasan));
    CAPACITY_LDB(*l) = capacity;
    NEFF_LDB(*l) = 0;
}

int LDBLength(LDBalasan l) {
    return NEFF_LDB(l);
}

void insertLastLDB(LDBalasan* l, ElTypeLDBalasan val) {
    if (NEFF_LDB(*l) == CAPACITY_LDB(*l)) {
        expandLDB(l, 1);
    }
    BUFFER_LDB(*l)[NEFF_LDB(*l)] = val;
    NEFF_LDB(*l)++;
}

void expandLDB(LDBalasan* l, int num) {
    ElTypeLDBalasan* new_buffer = (ElTypeLDBalasan*)malloc((CAPACITY_LDB(*l) + num) * sizeof(ElTypeLDBalasan));
    for (int i = 0; i < CAPACITY_LDB(*l); i++) {
        new_buffer[i] = BUFFER_LDB(*l)[i];
    }
    free(BUFFER_LDB(*l));
    BUFFER_LDB(*l) = new_buffer;
    CAPACITY_LDB(*l) += num;
}

LDBalasan sortLDBOnIdBalasan(LDBalasan l) {
    LDBalasan sorted;
    createLDB(&sorted, CAPACITY_LDB(l));
    for (int i = 0; i < LDBLength(l); i++) {
        insertLastLDB(&sorted, ELMT_LDB(l, i));
    }
    for (int i = 0; i < LDBLength(sorted); i++) {
        for (int j = i + 1; j < LDBLength(sorted); j++) {
            if (ID_BALASAN(ELMT_LDB(sorted, i)) > ID_BALASAN(ELMT_LDB(sorted, j))) {
                Balasan temp = ELMT_LDB(sorted, i);
                ELMT_LDB(sorted, i) = ELMT_LDB(sorted, j);
                ELMT_LDB(sorted, j) = temp;
            }
        }
    }
    return sorted;
}

LDBalasan treeToLDB(Tree* t) {
    LDBalasan l;
    createLDB(&l, 10);
    if (t != NULL) {
        insertLastLDB(&l, BALASAN(t));
        Tree* child = CHILD_NODE(t);
        while (child != NULL) {
            LDBalasan temp = treeToLDB(child);
            for (int i = 0; i < LDBLength(temp); i++) {
                insertLastLDB(&l, ELMT_LDB(temp, i));
            }
            child = NEXT_NODE(child);
        }
    }
    return l;
}


void writePertemananConfig(Matrix_pertemanan matrix_teman, Matrix_Permintaan matrix_permintaan, databaseprofil database, Word path) {
    int jumlah_pengguna = matrix_teman.colEff;
    char* path_config = WordToString(path);
    FILE* file = fopen(concatString(path_config, "/pengguna.config"), "w+");
    char random[300];
    fprintf(file, "%s", intToString(jumlah_pengguna));
    nl(file);
    for (int i = 0; i < jumlah_pengguna; i++) {
        fprintf(file, "%s\n", WordToString(nama(database, i)));
        fprintf(file, "%s\n", WordToString(password(database, i)));
        fprintf(file, "%s\n", WordToString(bio(database, i)));
        fprintf(file, "%s\n", WordToString(hp(database, i)));
        fprintf(file, "%s\n", WordToString(weton(database, i)));
        if (jenis(database, i)) {
            fprintf(file, "Privat\n");
        }
        else {
            fprintf(file, "Publik\n");
        }
        for (int j = 0; j < 5; j++) {
            boolean first = true;
            for (int k = 0; k < 5; k++) {
                if (first) {
                    fprintf(file, "%c", database.contents[i].profil.mem[j][k].warna);
                    fprintf(file, " ");
                    fprintf(file, "%c", database.contents[i].profil.mem[j][k].simbol);
                    first = false;
                }
                else {
                    fprintf(file, " ");
                    fprintf(file, "%c", database.contents[i].profil.mem[j][k].warna);
                    fprintf(file, " ");
                    fprintf(file, "%c", database.contents[i].profil.mem[j][k].simbol);
                }
            }
            nl(file);
        }
    }

    for (int i = 0; i < jumlah_pengguna; i++) {
        boolean first = true;
        for (int j = 0; j < jumlah_pengguna; j++) {
            if (first) {
                fprintf(file, "%s", intToString(matrix_teman.buffer[i][j]));
                first = false;
            }
            else {
                fprintf(file, " ");
                fprintf(file, "%s", intToString(matrix_teman.buffer[i][j]));
            }
        }
        nl(file);
    }

    fprintf(file, "%d\n", matrix_permintaan.length);
    for (int i = 0; i < matrix_permintaan.length; i++) {
        boolean first = true;
        for (int j = 0; j < 3; j++) {
            if (first) {
                fprintf(file, "%s", intToString(matrix_permintaan.permintaan_teman[i][j]));
                first = false;
            }
            else {
                fprintf(file, " ");
                fprintf(file, "%s", intToString(matrix_permintaan.permintaan_teman[i][j]));
            }
        }
        nl(file);
    }
    fclose(file);
}


void writeKicauanConfig(ListDinKicau k, Word path) {
    char* path_config = WordToString(path);
    FILE* file = fopen(concatString(path_config, "/kicauan.config"), "w+");

    int jumlah_kicauan = NEFF_KICAU(k);
    fprintf(file, "%s", intToString(jumlah_kicauan));
    nl(file);
    for (int i = 0; i < jumlah_kicauan; i++) {
        fprintf(file, "%s\n", intToString(ID_KICAU(ELMT_KICAU(k, i))));
        fprintf(file, "%s\n", WordToString(TEXT_KICAU(ELMT_KICAU(k, i))));
        fprintf(file, "%s\n", intToString(LIKE_KICAU(ELMT_KICAU(k, i))));
        fprintf(file, "%s\n", WordToString(AUTHOR_KICAU(ELMT_KICAU(k, i))));
        fprintf(file, "%s\n", WordToString(TimeToWord(DATETIME_KICAU(ELMT_KICAU(k, i)))));
    }
    fclose(file);
}

void writeBalasanConfig(ListDinBalasan l, Word path) {
    char* path_config = WordToString(path);
    FILE* file = fopen(concatString(path_config, "/balasan.config"), "w+");

    int jumlah_kicauan = listBalasanLength(l);
    fprintf(file, "%s", intToString(jumlah_kicauan));
    nl(file);
    for (int i = 0; i < jumlah_kicauan; i++) {
        LDBalasan ldb;
        createLDB(&ldb, 10);
        Tree* t = ELMT_BALASAN(l, i);
        ldb = treeToLDB(t);
        ldb = sortLDBOnIdBalasan(ldb);

        fprintf(file, "%s\n", intToString(-ID_BALASAN(ELMT_LDB(ldb, 0))));
        int jumlah_balasan = LDBLength(ldb);
        fprintf(file, "%s\n", intToString(jumlah_balasan - 1));
        for (int j = 1; j < jumlah_balasan; j++) {
            fprintf(file, "%s %s\n", intToString(ID_PARENT_BALASAN(ELMT_LDB(ldb, j))), intToString(ID_BALASAN(ELMT_LDB(ldb, j))));
            fprintf(file, "%s\n", WordToString(TEXT_BALASAN(ELMT_LDB(ldb, j))));
            fprintf(file, "%s\n", WordToString(AUTHOR_BALASAN(ELMT_LDB(ldb, j))));
            fprintf(file, "%s\n", WordToString(TimeToWord(DATETIME_BALASAN(ELMT_LDB(ldb, j)))));
        }
    }
    fclose(file);
}

void writeDrafConfig(listStackDraf lsd, Word path) {
    StackDraf SD;
    Draf D;

    char* path_config = WordToString(path);
    FILE* file = fopen(concatString(path_config, "/draf.config"), "w+");

    int banyak_userDraf = NEFF_LISTSTACK(lsd);
    fprintf(file, "%s\n", intToString(banyak_userDraf));

    for (int i = 0; i < banyak_userDraf; i++) {
        SD = GET_LISTSTACK(lsd, i);

        int banyak_draf = LengthStackDraf(SD);
        fprintf(file, "%s %s\n", WordToString(AUTHOR_SD(SD)), intToString(banyak_draf));

        for (int j = 0; j < banyak_draf; j++) {
            D = LASTDRAF_SD(SD);

            fprintf(file, "%s\n", WordToString(TEXT_DRAF(D)));
            fprintf(file, "%s\n", WordToString(TimeToWord(DATETIME_DRAF(D))));

            PopStackDraf(&SD, &D);
        }
    }
    fclose(file);
}

void writeUtasConfig(ListDinUtas dbUtasUser, Word path) {
    Utas U;
    Address p;

    char* path_config = WordToString(path);
    FILE* file = fopen(concatString(path_config, "/utas.config"), "w+");

    int banyak_utas = NEFF_LISTUTAS(dbUtasUser);
    fprintf(file, "%s\n", intToString(banyak_utas));

    for (int i = 0; i < banyak_utas; i++) {
        U = ELMT_LISTUTAS(dbUtasUser, i);

        int banyak_sambungDraf = LENGTH_UTAS(U);
        fprintf(file, "%s\n", intToString(IDKICAU_UTAS(U)));
        fprintf(file, "%s\n", intToString(banyak_sambungDraf));

        p = FIRST_UTAS(U);
        for (int j = 0; j < banyak_sambungDraf; j++) {

            fprintf(file, "%s\n", WordToString(INFO(p)));
            fprintf(file, "%s\n", WordToString(AUTHOR_UTAS(U)));
            fprintf(file, "%s\n", WordToString(TimeToWord(DATE(p))));

            p = NEXT(p);
        }
    }
    fclose(file);
}