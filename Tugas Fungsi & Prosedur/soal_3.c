#include <stdio.h>

void TUKAR (int *a, int *b){ // Pass by reference bukan value
    int temp = *a;
    *a = *b;
    *b = temp;
}

void PUTAR3BIL (int *a, int *b, int *c){ // Pass by reference bukan value
    TUKAR(a,c); // a = C, b = B, c = A
    TUKAR(b,c); // a = C, b = A, c = B
}


int main(){
    int a,b,c;
    printf("Masukkan 3 bilangan bulat (a b c) yang ingin ditukar : ");
    scanf("%d %d %d", &a, &b, &c);

    PUTAR3BIL(&a,&b,&c);
    printf("Sekarang, a bernilai %d\n", a);
    printf("Sekarang, b bernilai %d\n", b);
    printf("Sekarang, c bernilai %d\n", c);

    return 0;
}