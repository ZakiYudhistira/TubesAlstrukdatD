#include <stdio.h>
#include "ADT/Mesin Karakter/charmachine.h"
#include "ADT/Mesin Kata/wordmachine.h"

typedef struct {
    Word nama;
    Word password;
    Word bio;
    Word nohp;
    Word weton;
    Word jenisakun;
} profil;
#define CAPACITY 20
typedef int ElType;
typedef struct {
    profil contents[CAPACITY];
    int length;
} dataprofil;


#define nama(p) (p).nama
#define pass(p) (p).password
#define bio(p) (p).bio
#define nohp(p) (p).nohp
#define weton(p) (p).weton
#define akun(p) (p).jenisakun

int main() {
    profil haikal;
    int i, progress;
    progress = 0;
    dataprofil database;
    database.length = 0;
    database.contents[i].nama
    
    
    

    
    
    return 0;
    
    
}