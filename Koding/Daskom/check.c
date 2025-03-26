#include <stdio.h>
#include <string.h>

int main(){
    char check[7]="DASKOM";
    char c; printf("Huruf yang ingin diperiksa :"); scanf("%c", &c);
    int a=0;

    while(a < strlen(check)){
        if(check[a]==c){
            printf("Huruf %c terdapat di kata %s", c, check);
            break;
        }
        a++;    
    }
}