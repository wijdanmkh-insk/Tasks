#include <stdio.h>

int f(int x){
    return x;
}

int fy(int a, int b, int k, int x){
    if(k==0){
        return f(x);
    }else{
        int y = a*fy(a,b,k-1,f(x))+b;
        return y;
    }

}
int main(){

}