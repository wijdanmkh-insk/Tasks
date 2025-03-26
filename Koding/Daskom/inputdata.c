#include <stdio.h>

int main(){
    int input; scanf("%d",&input);

    char nama[120], kelas[4], jurusan[120], nis[20];

    for(int a=0;a<input; a++){
        printf("Nama : "); scanf("%[^\n]", nama);
        printf("Kelas : "); scanf("%[^\n]", kelas);
        printf("Jurusan : "); scanf("%[^\n]", jurusan);
        printf("NIS : "); scanf("%[^\n]", nis);

        printf("%s %s %s %s",nama, kelas, jurusan, nis);
    }
}