#include <stdio.h>

int main(){
    int n, *input; scanf("%d", &n);
    int (*data)[n]; 

    for(int a=1; a<=n; a++){
        scanf("%d", &input);
        if(*input==n){
            (*data)[n] = *input; 
        }
        printf("%d ", data[n]);
    }
}