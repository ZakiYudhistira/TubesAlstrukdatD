#include <stdio.h>
#include "../Pengguna/pengguna.h"
#include "../Pertemanan/pertemanan.h"
#include "../Perintah/perintah.h"
#include "../Mesin Karakter/charmachine.h"
#include "../boolean.h"

#define nl(file) fprintf(file,"\n")

void writePertemananConfig(Matrix_pertemanan matrix_teman, Matrix_Permintaan matrix_permintaan, databaseprofil database, Word path){
    int jumlah_pengguna = matrix_teman.colEff;
    char* path_config = WordToString(path);
    FILE *file = fopen(path_config,"w+");
    char random[300];
    fprintf(file,"%s",intToString(jumlah_pengguna));
    nl(file);
    printf("%d\n",jumlah_pengguna);
    for(int i = 0 ; i < jumlah_pengguna ; i++){
        fprintf(file, "%s\n", WordToString(nama(database, i)));
        fprintf(file, "%s\n", WordToString(password(database, i)));
        fprintf(file, "%s\n", WordToString(bio(database, i)));
        fprintf(file, "%s\n", WordToString(hp(database, i)));
        fprintf(file, "%s\n", WordToString(weton(database, i)));
        if(jenis(database,i)){
            fprintf(file, "Privat\n");
        } else {
            fprintf(file, "Publik\n");
        }
        for(int j = 0 ; j < 5 ; j++){
            boolean first = true;
            for(int k = 0 ; k < 5 ; k++){
                if(first){
                    fprintf(file,"%c",database.contents[i].profil.mem[j][k].warna);
                    fprintf(file," ");
                    fprintf(file,"%c",database.contents[i].profil.mem[j][k].simbol);
                    first = false;
                } else {
                    fprintf(file," ");
                    fprintf(file,"%c",database.contents[i].profil.mem[j][k].warna);
                    fprintf(file," ");
                    fprintf(file,"%c",database.contents[i].profil.mem[j][k].simbol);
                }
            }
            nl(file);
        }
    }

    for(int i = 0 ; i < jumlah_pengguna ; i++){
        boolean first = true;
        for(int j = 0 ; j < jumlah_pengguna ; j++){
            if(first){
                fprintf(file,"%s",intToString(matrix_teman.buffer[i][j]));
                first = false;
            } else {
                fprintf(file, " ");
                fprintf(file,"%s",intToString(matrix_teman.buffer[i][j]));
            }
        }
        nl(file);
    }

    fprintf(file,"%d\n",matrix_permintaan.length);
    for(int i = 0 ; i < matrix_permintaan.length ; i++){
        boolean first = true;
        for(int j = 0 ; j < 3 ; j++){
            if(first){
                fprintf(file,"%s", intToString(matrix_permintaan.permintaan_teman[i][j]));
                first = false;
            } else {
                fprintf(file," ");
                fprintf(file,"%s", intToString(matrix_permintaan.permintaan_teman[i][j]));
            }
        }
        nl(file);
    }
    fclose(file);
}