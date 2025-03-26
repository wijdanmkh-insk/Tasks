#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int jm, mm, dm, jk, mk, dk;

    printf("Jam Masuk : "); scanf("%d",&jm);
    printf("Menit masuk : "); scanf("%d", &mm);
    printf("Detik masuk : "); scanf("%d", &dm);
    printf("Jam keluar : "); scanf("%d", &jk);
    printf("Menit keluar : "); scanf("%d",&mk);
    printf("Detik keluar : "); scanf("%d", &dk);

    printf("Lama waktu parkir : Jam : Menit : Detik\n%02d : %02d : %02d", abs(jk-jm), abs(mk-mm), abs(dk-dm));
}