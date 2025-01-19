#include <stdio.h>
int main(){
FILE *f_struktur;
struct {
char Menu[30]; double Harga;
} daftar;
f_struktur = fopen("Daftar Harga.dat","rb");

while(fread(&daftar,sizeof(daftar),1,f_struktur)==1){
    printf("Menu : %s\n", daftar.Menu);
    printf("Harga : %lf\n", daftar.Harga);
}
fclose(f_struktur);
return 0;
}