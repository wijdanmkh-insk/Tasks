#include <stdio.h>
#include <limits.h>

void c(){
    printf("c");
    c();
}

int main(){
    c();
}