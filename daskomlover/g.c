#include <stdio.h>
    char string[255];
    int main(){
    FILE *f_teks;
    f_teks = fopen("contoh.txt", "r");
    while(fgets(string,sizeof(string),
    f_teks)!=NULL)
    printf("%s",string);
    fclose (f_teks);
    return 0;
}