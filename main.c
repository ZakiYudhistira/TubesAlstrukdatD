#include <stdio.h>
#include "ADT/Perintah/perintah.h"
#include "ADT/Perintah/perintah.c"
#include <dirent.h>

<<<<<<< Updated upstream
boolean cekFolder(Word word) {
    DIR *directory;
    struct dirent *entry;
=======
int main() {
    // Inisialisasi BurBir
    databaseprofil dp;
    Matrix_pertemanan mt;
    Matrix_Permintaan mp;
    ListDinKicau lk;
    ListDinBalasan lb;
    const char *asciiArt ={
        " /$$$$$$$                      /$$       /$$          \n"
        "| $$__  $$                    | $$      |__/          \n"
        "| $$  \\ $$ /$$   /$$  /$$$$$$ | $$$$$$$  /$$  /$$$$$$ \n"
        "| $$$$$$$ | $$  | $$ /$$__  $$| $$__  $$| $$ /$$__  $$\n"
        "| $$__  $$| $$  | $$| $$  \\__/| $$  \\ $$| $$| $$  \\__/\n"
        "| $$  \\ $$| $$  | $$| $$      | $$  | $$| $$| $$      \n"
        "| $$$$$$$/|  $$$$$$/| $$      | $$$$$$$/| $$| $$      \n"
        "|_______/  \\______/ |__/      |_______/ |__/|__/      \n"
        "                                                      \n"
    };
    printf("%s", asciiArt);


>>>>>>> Stashed changes

    directory = opendir("Konfigurasi/"); // Ganti dengan path menuju folder konfigurasi Anda

    if (directory == NULL) {
        perror("Error opening directory");
        return false;
    }

    while ((entry = readdir(directory)) != NULL) {
        if (entry->d_type == DT_DIR) {
            if (isValid(word, entry->d_name)) {
                closedir(directory);
                return true;
            }
        }
    }

    closedir(directory);
    return false;
}
int main() {
    const char *asciiArt =
        " /$$$$$$$                      /$$       /$$          \n"
        "| $$__  $$                    | $$      |__/          \n"
        "| $$  \\ $$ /$$   /$$  /$$$$$$ | $$$$$$$  /$$  /$$$$$$ \n"
        "| $$$$$$$ | $$  | $$ /$$__  $$| $$__  $$| $$ /$$__  $$\n"
        "| $$__  $$| $$  | $$| $$  \\__/| $$  \\ $$| $$| $$  \\__/\n"
        "| $$  \\ $$| $$  | $$| $$      | $$  | $$| $$| $$      \n"
        "| $$$$$$$/|  $$$$$$/| $$      | $$$$$$$/| $$| $$      \n"
        "|_______/  \\______/ |__/      |_______/ |__/|__/      \n"
        "                                                      \n";
    
    printf("%s", asciiArt);
    printf("Selamat datang di BurBir.\nAplikasi untuk studi kualitatif mengenai perilaku manusia dengan menggunakan\nmetode (pengambilan data berupa) Focused Group Discussion kedua di zamannya.\n");

    printf("\nSilahkan masukan folder konfigurasi untuk dimuat: ");
    perintah(300, false);
    while(!cekFolder(currentWord)){
        printf("\nFolder Tidak Ditemukan.\nSilahkan masukan folder konfigurasi untuk dimuat: ");
        perintah(300, false);
        printWord(currentWord);
    }
    printf("File konfigurasi berhasil dimuat! Selamat berkicau!");
    //mengecek apakah ada nama folder tersebut di dalam folder konfigurasi
    return 0;
}
