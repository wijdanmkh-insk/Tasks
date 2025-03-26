#include <stdio.h>

int main(){
    char nama[120], kelas[5], jurusan[120], nis[10];
    int input; printf("Masukkan banyak siswa yang ingin diinput : "); scanf("%d",&input); getchar();

    for(int a = 1; a <= input; a++){
        printf("Data %d\n", a);
        printf("Nama : "); gets(nama);
        printf("Kelas : "); gets(kelas);
        printf("Jurusan : "); gets(jurusan);
        printf("NIS : "); gets(nis);
        printf("\n");
    }
}