#include <stdio.h>
int main(){
FILE *f_struktur;
int n, i;
struct {
char Menu [30]; double Harga;
} daftar;
f_struktur = fopen("Daftar Harga.dat", "ab");
printf("Silahkan masukkan banyaknya menu tambahan: ");
scanf("%d", &n);
getchar();
for (i=1; i<=n; i++){
printf("Menu : "); gets(daftar.Menu);
printf("Harga : "); scanf("%lf", &daftar.Harga);
getchar();
fwrite(&daftar, sizeof (daftar), 1, f_struktur);
}
fclose(f_struktur);
}
