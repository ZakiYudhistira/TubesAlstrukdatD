#include <stdio.h>
#include "matrix.h"
#include "../PColor/pcolor.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void createMatrix(int nRows, int nCols, Matrix* m) {
    ROW_EFF(*m) = 5;
    COL_EFF(*m) = 5;
}
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */


Matrix createphoto() {
    Matrix matriks;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matriks.mem[i][j].simbol = '*';
            matriks.mem[i][j].warna = 'R';
        }
    }
    return matriks; 
}

void displayphoto(Matrix photo) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if(photo.mem[i][j].warna == 'R') {
                print_red(photo.mem[i][j].simbol);
            }
            else if(photo.mem[i][j].warna == 'G') {
                print_green(photo.mem[i][j].simbol);
            }
            else if(photo.mem[i][j].warna == 'B') {
                print_blue(photo.mem[i][j].simbol);
            }
            if (j != 4) {
                printf(" ");
            }
        }
        printf("\n");
    }
}
/* *** Selektor "Dunia Matrix" *** */

/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */