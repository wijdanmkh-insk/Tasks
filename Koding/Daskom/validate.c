#include <stdio.h>

int main(){
    char nama[127];
    char c;
    char mk[127];
    int grd;

    printf("Nama : "); gets(nama);
    printf("Kelas : "); scanf("%c",&c);
    printf("Mata pelajaran : "); gets(mk);
    printf("Nilai : "); scanf("%d",&grd); 

    printf("Nama : %s", nama);
    printf("Kelas : %c",c);
    printf("Mata pelajaran : %s",mk);
}