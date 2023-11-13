#include "kicauan.h"
#include "../Mesin Kata/wordmachine.h"
#include "../Mesin Karakter/charmachine.h"
#include "../Perintah/perintah.h"
#include <stdio.h>
#include <stdlib.h>

/* *** Kreator *** */
void CreateKicauan(Kicauan* k) {
    ID_KICAU(*k) = 0;
    TEXT_KICAU(*k) = NULL;
    LIKE_KICAU(*k) = 0;
    AUTHOR_KICAU(*k) = NULL;
    DATETIME_KICAU(*k) = time(NULL);
}
/* I.S. sembarang */
/* F.S. Sebuah k kosong dan datetime now*/

const char* TimeToString(time_t t) {
    struct tm tm;
    localtime_r(&t, &tm);
    static char buf[20];
    strftime(buf, sizeof(buf), "%d-%m-%Y %H:%M:%S", &tm);
    return buf;
}


time_t StringToTime(const char* str) {
    struct tm tm;
    strptime(str, "%d-%m-%Y %H:%M:%S", &tm);
    return mktime(&tm);
}

/* *** Display Pengguna *** */
void DisplayKicauan(Kicauan k) {
    printf("| ID = %d\n", ID_KICAU(k));
    printf("| %s\n", AUTHOR_KICAU(k));
    printf("| %s\n", TimeToString(DATETIME_KICAU(k)));
    printf("| %s\n", TEXT_KICAU(k));
    printf("| Disukai: %d\n", LIKE_KICAU(k));
}
/* Proses : Menuliskan isi Kicauan dengan traversal. Informasi kicauan
   ditulis satu persatu dan diakhiri dengan newline */


void CreateListKicauan(ListDinKicau* l, int capacity) {
    BUFFER_KICAU(*l) = malloc(capacity * sizeof(ElTypeKicau));
    CAPACITY_KICAU(*l) = capacity;
    NEFF_KICAU(*l) = 0;
}
/* I.S. sembarang */
/* F.S. Terbentuk ListDinKicau kosong dengan kapasitas capacity */

   /* ********** SELEKTOR (TAMBAHAN) ********** */
   /* *** Banyaknya elemen *** */
int ListKicauLength(ListDinKicau l) {
    return NEFF_KICAU(l);
}
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void InsertLastKicau(ListDinKicau* l, ElTypeKicau val) {
    if (NEFF_KICAU(*l) == CAPACITY_KICAU(*l)) {
        ExpandListKicau(l, 10);
    }
    ELMT_KICAU(*l, NEFF_KICAU(*l)) = val;
    NEFF_KICAU(*l)++;
}
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void ExpandListKicau(ListDinKicau* l, int num) {
    BUFFER_KICAU(*l) = realloc(BUFFER_KICAU(*l), (CAPACITY_KICAU(*l) + num) * sizeof(ElTypeKicau));
    CAPACITY_KICAU(*l) += num;
}
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */


boolean isSuka(char* option) {
    char* suka = "SUKA_KICAUAN";
    int i = 0;

    if (lengthString(option) > 13) {
        for (i = 0; i < 12; i++) {
            if (option[i] != suka[i]) {
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
// F.S. mengembalikan true jika option adalah "SUKA_KICAUAN [IDKicau]"

boolean isUbah(char* option) {
    char* ubah = "UBAH_KICAUAN";
    int i = 0;

    if (lengthString(option) > 13) {
        for (i = 0; i < 12; i++) {
            if (option[i] != ubah[i]) {
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
// F.S. mengembalikan true jika option adalah "UBAH_KICAUAN [IDKicau]"