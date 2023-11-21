#include "balasan.h"
#include "balasan.c"
#include "../Perintah/perintah.h"
#include "../Perintah/perintah.c"
#include "../Perintah/wordmachine.h"
#include "../Mesin Karakter/charmachine.h"
#include "../Mesin Karakter/charmachine.c"
#include "../Datetime/datetime.h"
#include "../Datetime/datetime.c"
#include "../Time/time.h"
#include "../Time/time.c"
#include "../Kicauan/kicauan.h"
#include "../Kicauan/kicauan.c"

int main() {
    boolean end = false;

    ListDinBalasan l;
    createListBalasan(&l, 10);

    Word path;
    StringToWord("../../Konfigurasi/config-1/balasan.config", &path);

    LoadBalasan(&l, path);

    ListDinKicau l_kicau;
    CreateListKicauan(&l_kicau, 10);

    StringToWord("../../Konfigurasi/config-1/kicauan.config", &path);

    LoadKicauan(&l_kicau, path);
    HandleKicauan(l_kicau);

    Word id_kicau, id_balasan, temp;

    while (!end) {
        perintah(300, true);
        ADV();

        if (isBalasan(currentWord)) {
            id_kicau = sliceWord(currentWord, 8, currentWord.Length);

            if (isIdKicauValid(l_kicau, WordToInt(id_kicau))) {
                if (getTreeFromIdKicau(l, -WordToInt(id_kicau)) != NULL) {
                    printf("\n");
                    printTreeWithoutRoot(getTreeFromIdKicau(l, -WordToInt(id_kicau)), 0);
                }
                else {
                    printf("Belum terdapat balasan apapun pada kicauan tersebut. Yuk balas kicauan tersebut!\n");
                }
            }
            else {
                printf("Tidak terdapat kicauan dengan id tersebut!\n");
            }
        }
        else if (isBalas(currentWord)) {
            split3Word(currentWord, &temp, &id_kicau, &id_balasan);
            if (isIdKicauValid(l_kicau, WordToInt(id_kicau))) {
                Tree* t = getTreeFromIdKicau(l, -WordToInt(id_kicau));
                if (t != NULL) {
                    Tree* t2 = getTreeFromIdParent(t, WordToInt(id_balasan));
                    if (t2 != NULL) {
                        Balasan b;
                        createBalasan(&b);

                        printf("Masukkan balasan:\n");
                        perintah(280, true);
                        ADV();
                        TEXT_BALASAN(b) = currentWord;
                        Word username;
                        StringToWord("admin", &username);
                        AUTHOR_BALASAN(b) = username;
                        DATETIME D;
                        GetLocalDATETIME(&D);
                        DATETIME_BALASAN(b) = D;
                        ID_BALASAN(b) = treeMaxId(t) + 1;
                        ID_PARENT_BALASAN(b) = WordToInt(id_balasan);

                        printf("Selamat! balasan telah diterbitkan!\n");
                        printf("Detil balasan:\n");
                        printBalasan(b, 0);

                        addChild(t2, b);
                    }
                    else {
                        printf("Wah, tidak terdapat balasan yang ingin Anda balas!\n");
                    }
                }
                else {
                    if (WordToInt(id_balasan) == -1) {
                        Balasan b;
                        createBalasan(&b);

                        printf("Masukkan balasan:\n");
                        perintah(280, true);
                        ADV();
                        TEXT_BALASAN(b) = currentWord;
                        Word username;
                        StringToWord("admin", &username);
                        AUTHOR_BALASAN(b) = username;
                        DATETIME D;
                        GetLocalDATETIME(&D);
                        DATETIME_BALASAN(b) = D;
                        ID_BALASAN(b) = 1;
                        ID_PARENT_BALASAN(b) = -1;

                        printf("Selamat! balasan telah diterbitkan!\n");
                        printf("Detil balasan:\n");
                        printBalasan(b, 0);

                        addChild(getTreeFromIdKicau(l, WordToInt(id_balasan)), b);
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
        else if (isHapusBalasan(currentWord)) {
            split3Word(currentWord, &temp, &id_kicau, &id_balasan);

            Tree* t = getTreeFromIdKicau(l, -WordToInt(id_kicau));
            if (t != NULL) {
                Tree* t2 = getTreeFromIdParent(t, WordToInt(id_balasan));
                if (t2 != NULL) {
                    removeNode(getParentFromChild(t, t2), t2);
                    printf("Balasan berhasil dihapus\n");
                }
                else {
                    printf("Balasan tidak ditemukan\n");
                }

                if (isTreeEmpty(t)) {
                    deleteBalasanAt(&l, getIdxFromIdKicau(l, WordToInt(id_kicau)));
                }
            }
            else {
                printf("Tidak terdapat balasan pada kicauan dengan id tersebut!\n");
            }
        }
    }
}