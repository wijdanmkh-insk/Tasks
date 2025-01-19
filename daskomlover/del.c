#include <stdio.h>
#include <string.h>
int main(){
FILE *f_struktur;
FILE *f_struktur2;
char dicari[50];
struct {
char Menu[30];
double Harga;
} daftar;
f_struktur = fopen("Daftar Harga.dat", "rb");
f_struktur2 = fopen("Daftar Harga2.dat", "wb");
printf("Silahkan masukkan nama menu yang akan dihapus: ");
gets(dicari);
while (fread(&daftar,sizeof (daftar),1, f_struktur)==1){
if (strcmp(daftar.Menu, dicari)!=0){
fwrite(&daftar, sizeof(daftar), 1, f_struktur2);
}
}
fclose(f_struktur);
fclose(f_struktur2);
remove("Daftar Harga.dat");
rename("Daftar Harga2.dat","Daftar Harga.dat");
return 0;
}