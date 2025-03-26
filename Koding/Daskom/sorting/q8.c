#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct product{
    char nama[120];
    char kode[3];
    int jumlah;
};

void swap(struct product *p, struct product *q){
    struct product temp = *p;
    *p = *q; 
    *q = temp;
}

int main(){
    char temp[120];
    int banyakbrg; printf("Banyak barang : "); scanf("%d", &banyakbrg); getchar();
    struct product d[banyakbrg];

    for(int a=0; a<banyakbrg; a++){
        printf("Data %d\n", a+1);
        printf("Nama barang\t: "); gets(d[a].nama);
        printf("Kode barang\t: "); scanf("%s", &d[a].kode); 
        printf("Jumlah\t: "); scanf("%d", &d[a].jumlah); getchar();
    }

    printf("\n");

    for(int a=0; a<banyakbrg; a++){
        for(int b=0; b<banyakbrg; b++){
            if(strcmp(d[a].nama,d[b].nama)>0){
                swap(&d[a],&d[b]);
            }
        }
    }

    system("cls");
    for(int a=0; a<banyakbrg; a++){
        printf("Data %d\n",a+1);
        printf("Nama barang\t: %s\n", d[a].nama);
        printf("Kode barang\t: %s\n", d[a].kode);
        printf("Jumlah barang\t: %d\n", d[a].jumlah);
        printf("\n");
    }

    //Sampel jawabannya salah kak
}