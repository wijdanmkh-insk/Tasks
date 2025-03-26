#include <stdio.h>

int main(){
    FILE *file;
    file = fopen("dataa.txt","r");

    if(file == NULL){
        printf("FILE ERROR");
    }

    fclose(file);


}