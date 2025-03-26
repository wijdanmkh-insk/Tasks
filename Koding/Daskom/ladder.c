#include <stdio.h>

int main(){
    int input; scanf("%d",&input);

    for(int a=input; a >= 0;a--){
        for(int b=1; b <= a;b++){
            printf("%d",a);
        }
        printf("\n");
    }
}