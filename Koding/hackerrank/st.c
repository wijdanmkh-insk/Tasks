#include <stdio.h>

int main(){
    int n; scanf("%d", &n);

    for(int a=0;a<=n-1;a++){
        for(int b=n;b>=0;b--){
            if(b>a){
                printf(" ");
            }else{
                printf("#");
            }
        }
        printf("\n");
    }
}