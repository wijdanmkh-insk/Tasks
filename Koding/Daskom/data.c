#include <stdio.h>

int main(){
    int input; printf("Masukkan banyak siswa yang ingin diinput : "); scanf("%d",&input);
    char nama[120], kelas[4], jurusan[40], nis[6];

    for(int a=1; a<=input; a++){
        printf("Data %d", a);
        printf("\nNama : "); scanf("%s",nama);
        printf("\nKelas : "); scanf("%s", kelas);
        printf("\nJurusan : "); scanf("%s", jurusan);
        printf("\nNIS : "); scanf("%d", nis);

        if(a == input){
            printf("Data %d", a);
            printf("\nNama : %s", nama);
            printf("\nKelas : %s", kelas); 
            printf("\nJurusan : %s", jurusan); 
            printf("\nNIS : %s", nis); 
        }
    }
}