// Program untuk mengecek nilai maksimum
#include <stdio.h>

// Deklarasi fungsi max2 dan max3
float Max2 (float a, float b){
    if(a > b){
        return a;
    } else if (b > a){
        return b;
    } else {
        return a;
    }
}
float Max3 (float a, float b, float c){
    return Max2(Max2(a,b), c);
}
// Program Utama
int main(){
    // KAMUS
    float a,b,c;
    printf("Masukkan tiga bilangan : ");
    scanf("%f %f %f", &a, &b, &c);
  
    printf("Nilai maksimum dari 2 bilangan pertama : %.2f\n", Max2(a,b));
    printf("Nilai maksimum dari bilangan pertama dan ketiga : %.2f\n", Max2(a,c));
    printf("Nilai maksimum dari bilangan kedua dan ketiga : %.2f\n", Max2(b,c));
    printf("Nilai maksimum dari 3 bilangan : %.2f\n", Max3(a,b,c));

    return 0;
}