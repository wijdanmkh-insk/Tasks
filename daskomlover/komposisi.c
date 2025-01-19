#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int fungsi(int a, int b, int k, int x){
    if (k==0){
        return x;
    }
    else{
        int u = abs(fungsi(a,b,k-1,x));
        int y = a*u+b;
        return y;
    }
}

int main() {
    int a,b,k,x; scanf("%d %d %d %d", &a,&b,&k,&x);
    printf("%d",fungsi(a,b,k,x));
}