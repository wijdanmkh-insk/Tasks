#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n; printf("Jumlah string : "); scanf("%d", &n); getchar();
    char nama[n][100], temp[100];

    for(int a = 0; a<n; a++){
        printf("String %d : ", a+1);
        fflush(stdin);
        scanf("%s", &nama[a]);
    }

    for(int a=0;a<n-1;a++){
        for(int b=a+1;b<n;b++){
            if(strcmp(nama[a], nama[b])>0){
                strcpy(temp, nama[a]);
                strcpy(nama[a], nama[b]);
                strcpy(nama[b], temp);
            }
        }
    }

    printf("\nHasil pengurutan : ");
    for(int a=0;a<n;a++){
        printf("%s ", nama[a]);
    }
}