#include <stdio.h>
#include "datetime.h"
#include "../Time/time.h"
#include <time.h>

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
int GetMaxDay(int M, int Y) {
    if (M == 2) {
        if (Y % 400 == 0) {
            return 29;
        }
        else if (Y % 100 == 0) {
            return 28;
        }
        else if (Y % 4 == 0) {
            return 29;
        }
        else {
            return 28;
        }
    }
    else if (M == 4 || M == 6 || M == 9 || M == 11) {
        return 30;
    }
    else {
        return 31;
    }
}
/* Mengirimkan jumlah hari maksimum pada bulan M dan tahun Y */
/* Prekondisi: 1 <= M <= 12*/
/* Hint: Perhatikan Leap Year. Leap Year adalah tahun dengan 29 hari pada bulan Februari */
/* Aturan Leap Year: */
/* 1. Jika angka tahun itu habis dibagi 400, maka tahun itu sudah pasti tahun kabisat. 8*/
/* 2. Jika angka tahun itu tidak habis dibagi 400 tetapi habis dibagi 100, maka tahun itu sudah pasti bukan merupakan tahun kabisat. */
/* 3. Jika angka tahun itu tidak habis dibagi 400, tidak habis dibagi 100 akan tetapi habis dibagi 4, maka tahun itu merupakan tahun kabisat. */
/* 4. Jika angka tahun tidak habis dibagi 400, tidak habis dibagi 100, dan tidak habis dibagi 4, maka tahun tersebut bukan merupakan tahun kabisat. */

boolean IsDATETIMEValid(int D, int M, int Y, int h, int m, int s) {
    if (D < 1 || D > GetMaxDay(M, Y)) {
        return false;
    }
    else if (M < 1 || M > 12) {
        return false;
    }
    else if (Y < 1900 || Y > 2030) {
        return false;
    }
    else if (h < 0 || h > 23) {
        return false;
    }
    else if (m < 0 || m > 59) {
        return false;
    }
    else if (s < 0 || s > 59) {
        return false;
    }
    else {
        return true;
    }
}
/* Mengirim true jika D,M,Y,h,m,s dapat membentuk D yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah DATETIME */

/* *** Konstruktor: Membentuk sebuah DATETIME dari komponen-komponennya *** */
void CreateDATETIME(DATETIME* D, int DD, int MM, int YYYY, int hh, int mm, int ss) {
    Day(*D) = DD;
    Month(*D) = MM;
    Year(*D) = YYYY;
    CreateTime(&Time(*D), hh, mm, ss);
}
/* Membentuk sebuah DATETIME dari komponen-komponennya yang valid */
/* Prekondisi : DD, MM, YYYY, h, m, s valid untuk membentuk DATETIME */

void GetLocalDATETIME(DATETIME* D) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    CreateDATETIME(D, tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaDATETIME(DATETIME* D) {
    int DD, MM, YYYY, hh, mm, ss;
    do {
        scanf("%d %d %d %d %d %d", &DD, &MM, &YYYY, &hh, &mm, &ss);
        if (!IsDATETIMEValid(DD, MM, YYYY, hh, mm, ss)) {
            printf("DATETIME tidak valid\n");
        }
    } while (!IsDATETIMEValid(DD, MM, YYYY, hh, mm, ss));
    CreateDATETIME(D, DD, MM, YYYY, hh, mm, ss);
}
/* I.S. : D tidak terdefinisi */
/* F.S. : D terdefinisi dan merupakan DATETIME yang valid */
/* Proses : mengulangi membaca komponen DD, MM, YY, h, m, s sehingga membentuk D */
/* yang valid. Tidak mungkin menghasilkan D yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen DD, MM, YY, h, m, s
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
   /* Jika DATETIME tidak valid maka diberikan pesan: "DATETIME tidak valid", dan pembacaan
       diulangi hingga didapatkan DATETIME yang valid. */
       /* Contoh:
           32 13 2023 12 34 56
           DATETIME tidak valid
           31 12 2023 12 34 56
           --> akan terbentuk DATETIME <31,12,2023,12,34,56> */

void TulisDATETIME(DATETIME D) {
    printf("%d/%d/%d %02d:%02d:%02d", Day(D), Month(D), Year(D), Hour(Time(D)), Minute(Time(D)), Second(Time(D)));
}
/* I.S. : D sembarang */
/* F.S. : Nilai D ditulis dg format DD/MM/YYYY HH:MM:SS */
/* Proses : menulis nilai setiap komponen D ke layar dalam format DD/MM/YYYY HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/

   /* ***************************************************************** */
   /* KELOMPOK OPERASI TERHADAP TYPE                                    */
   /* ***************************************************************** */
   /* *** Kelompok operasi relasional terhadap DATETIME *** */
boolean DEQ(DATETIME D1, DATETIME D2) {
    return (Day(D1) == Day(D2) && Month(D1) == Month(D2) && Year(D1) == Year(D2) && TEQ(Time(D1), Time(D2)));
}
/* Mengirimkan true jika D1=D2, false jika tidak */
boolean DNEQ(DATETIME D1, DATETIME D2) {
    return (!DEQ(D1, D2));
}

boolean IsKabisat(int Y)
{
    if (Y % 400 == 0)
        return true;

    if (Y % 100 == 0)
        return false;

    return Y % 4 == 0;
}

long long int DATETIMEToDetik(DATETIME D)
{
    long long int total = 0;

    // Time
    total += TIMEToDetik(Time(D));

    // Day
    total += (Day(D) - 1) * 24 * 3600;

    // Month
    int i;
    for (i = 1; i < Month(D); i++)
    {
        total += GetMaxDay(i, Year(D)) * 24 * 3600;
    }

    // Year
    int j;
    for (j = 1900; j < Year(D); j++)
    {
        total += (IsKabisat(j) ? 366 : 365) * 24 * 3600;
    }

    return total;
}

/* Mengirimkan true jika D1 tidak sama dengan D2 */
boolean DLT(DATETIME D1, DATETIME D2) {
    return DATETIMEToDetik(D1) < DATETIMEToDetik(D2);
}
/* Mengirimkan true jika D1<D2, false jika tidak */
boolean DGT(DATETIME D1, DATETIME D2) {
    return DATETIMEToDetik(D1) > DATETIMEToDetik(D2);
}
/* Mengirimkan true jika D1>D2, false jika tidak */

DATETIME DetikToDATETIME(long long int N)
{
    // Get year
    int year = 1900;
    while (N >= (IsKabisat(year) ? 366 : 365) * 24 * 3600)
    {
        N -= (IsKabisat(year) ? 366 : 365) * 24 * 3600;
        year++;
    }

    // Get month
    int month = 1;
    while (N >= GetMaxDay(month, year) * 24 * 3600)
    {
        N -= GetMaxDay(month, year) * 24 * 3600;
        month++;
    }

    // Get day
    int day = 1;
    while (N >= 24 * 3600)
    {
        N -= 24 * 3600;
        day++;
    }

    // Get time
    TIME time = DetikToTIME(N);

    // Create datetime
    DATETIME datetime;
    CreateDATETIME(&datetime, day, month, year, Hour(time), Minute(time), Second(time));

    return datetime;
}


DATETIME DATETIMENextNDetik(DATETIME D, int N) {
    long long int total = DATETIMEToDetik(D) + (long long int)N;
    return DetikToDATETIME(total);
}
/* Mengirim salinan D dengan detik ditambah N */

DATETIME DATETIMEPrevNDetik(DATETIME D, int N) {
    long long int total = DATETIMEToDetik(D) - (long long int)N;
    return DetikToDATETIME(total);
}
/* Mengirim salinan D dengan detik dikurang N */

/* *** Kelompok Operator Aritmetika terhadap DATETIME *** */
long int DATETIMEDurasi(DATETIME DAw, DATETIME DAkh) {
    return (long int)(DATETIMEToDetik(DAkh) - DATETIMEToDetik(DAw));
}
/* Mengirim DAkh-DAw dlm Detik, dengan kalkulasi */
/* Prekondisi: DAkh > DAw */