#include <stdio.h>

int main(){
    FILE *test;

    test=fopen("C:\\Users\\Wijdan\\Documents\\Koding\\file\\store\\test", "r");

    if(test==NULL){
        printf("keluar");
    }
}