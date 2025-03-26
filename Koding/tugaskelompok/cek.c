#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE* tes;
    tes = fopen("C:\\Users\\Wijdan\\Documents\\Koding\\tugaskelompok\\files\\haii.txt", "r");

    if(tes==NULL){
        printf("Keluar");
    }
}