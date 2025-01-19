#include <stdio.h>

int main(){
    FILE *f_struktur;
    int no_struct;
    long int offset_byte;
struct {
char Menu[30]; double Harga;
} daftar;

f_struktur = fopen("Daftar Harga.dat", "rb");
printf("Silahkan masukkan nomor urutan yang ada pada menu: ");
scanf("%d", &no_struct);
offset_byte = (no_struct - 1) * sizeof(daftar);

fseek(f_struktur, offset_byte,SEEK_SET);

if (fread(&daftar,sizeof(daftar),1,f_struktur) == 0){
printf("Menu yang dicari tidak dapat ditemukan pada daftar.\n");
printf("Nilai fseek : %d\n", fseek(f_struktur, 0, SEEK_CUR));
} else {
    printf("Nilai fseek : %d\n", fseek(f_struktur, 0, SEEK_CUR));
    printf("Menu : %s\n",daftar.Menu);
    printf("Harga: %lf\n",daftar.Harga);
}
fclose(f_struktur);
return 0;
}