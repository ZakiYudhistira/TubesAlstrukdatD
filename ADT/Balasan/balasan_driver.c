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

    ListDinListBalasan l;
    CreateListListBalasan(&l, 10);

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
                if (isIdKicauInBalasan(l, WordToInt(id_kicau))) {
                    printf("\n");
                    DisplayListListBalasan(l, WordToInt(id_kicau));
                    printf("\n");
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
                if (isIdKicauInBalasan(l, WordToInt(id_kicau))) {
                    DataBalasan b;
                    ListDinBalasan li;
                    CreateListBalasan(&li, 10);

                    TreeToListBalasan(&li, GetTreeFromIdKicau(l, WordToInt(id_kicau)));

                    if (isIdBalasanInBalasan(li, WordToInt(id_balasan)) || WordToInt(id_balasan) == -1) {
                        CreateBalasan(&b);
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
                        ID_BALASAN(b) = ListBalasanMaxId(li) + 1;
                        IDPARENT_BALASAN(b) = WordToInt(id_balasan);

                        printf("Selamat! balasan telah diterbitkan!\n");
                        printf("Detil balasan:\n");
                        DisplayBalasan(b, 0);

                        InsertLastBalasan(&li, b);
                        ROOT_LIST_BALASAN(ELMT_LIST_BALASAN(l, GetIdxListBalasan(l, WordToInt(id_kicau)))) = ListBalasanToTree(li);
                    }
                    else {
                        printf("Wah, tidak terdapat balasan yang ingin Anda balas!\n");
                    }
                }
                else {
                    ListDinBalasan li;
                    CreateListBalasan(&li, 10);

                    DataBalasan b;
                    CreateBalasan(&b);
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
                    IDPARENT_BALASAN(b) = -1;

                    printf("Selamat! balasan telah diterbitkan!\n");
                    printf("Detil balasan:\n");
                    DisplayBalasan(b, 0);

                    InsertLastBalasan(&li, b);

                    ElTypeListBalasan lb;
                    ID_KICAU_LIST_BALASAN(lb) = WordToInt(id_kicau);

                    ROOT_LIST_BALASAN(lb) = ListBalasanToTree(li);

                    InsertLastListBalasan(&l, lb);
                }
            }
            else {
                printf("Wah, tidak terdapat kicauan yang ingin Anda balas!\n");
            }
        }
        else if (isHapusBalasan(currentWord)) {
            split3Word(currentWord, &temp, &id_kicau, &id_balasan);
            if (isIdKicauInBalasan(l, WordToInt(id_kicau))) {
                ListDinBalasan li;
                CreateListBalasan(&li, 10);

                TreeToListBalasan(&li, GetTreeFromIdKicau(l, WordToInt(id_kicau)));

                if (isIdBalasanInBalasan(li, WordToInt(id_balasan))) {
                    while (isIdParentExist(li, WordToInt(id_balasan))) {
                        DeleteBalasanAt(&li, GetIdxBalasanFromParentId(li, WordToInt(id_balasan)));
                    }
                    DeleteBalasanAt(&li, GetIdxBalasan(li, WordToInt(id_balasan)));
                    printf("Balasan berhasil dihapus\n");
                }
                else {
                    printf("Balasan tidak ditemukan\n");
                }

                ROOT_LIST_BALASAN(ELMT_LIST_BALASAN(l, GetIdxListBalasan(l, WordToInt(id_kicau)))) = ListBalasanToTree(li);
            }
            else {
                printf("Tidak terdapat balasan pada kicauan dengan id tersebut!\n");
            }
        }
    }

    return 0;
}