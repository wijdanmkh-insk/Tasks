#include <stdio.h>
char string[255];
int main(){
    FILE *f_teks;
    f_teks = fopen("contoh.txt", "a");
    gets(string);
    fprintf(f_teks,"%s\n",string);
    fclose (f_teks);
    return 0;
}

