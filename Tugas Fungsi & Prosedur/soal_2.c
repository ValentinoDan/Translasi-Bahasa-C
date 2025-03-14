// Program yang menerima input sebuah tanggal dan memberikan output tanggal berikutnya
#include <stdio.h>

typedef struct { // type bentukan, yaitu tanggal
    int DD, MM, YY;
} Tanggal;

int TahunKabisat(int year) { // Fungsi untuk mengecek tahun kabisat (khusus bulan 2), menghasilkan int karena return 0 (false) atau 1 (true)
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
} 

Tanggal NextDay (Tanggal T){ // Fungsi yang menerima masukkan tanggal dan menghasilkan tanggal berikutnya
    if(T.MM == 2){
        if(TahunKabisat(T.YY)){
            if(T.DD == 29){
                T.DD = 1;
                T.MM += 1;
            } else {
                T.DD += 1;
            }
        } else {
            if(T.DD == 28){
                T.DD = 1;
                T.MM += 1;
            } else {
                T.DD += 1;
            }
        }
        
    } else if (T.MM == 12){
        if(T.DD == 31){
            T.DD = 1;
            T.MM = 1;
            T.YY += 1;
        } else {
            T.DD += 1;
        }
    } else if (T.MM == 1 || T.MM == 3 || T.MM == 5 || T.MM == 7 || T.MM == 8 || T.MM == 10){
        if(T.DD == 31){
            T.DD = 1;
            T.MM += 1;
        } else {
            T.DD += 1;
        }
    } else {
        if(T.DD == 30){
            T.DD = 1;
            T.MM += 1;
        }
    }
    return T;
}
// Program Utama
int main(){
    // KAMUS
    Tanggal Date;
    printf("Masukkan sebuah tanggal <DD,MM,YYYY> : ");
    scanf("<%d,%d,%d>", &Date.DD, &Date.MM, &Date.YY);

    Tanggal NextDate = NextDay(Date);
    printf("Tanggal berikutnya : <%d,%d,%d>", NextDate.DD, NextDate.MM, NextDate.YY);
}