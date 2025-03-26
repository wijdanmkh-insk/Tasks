#include <stdio.h>
#include <string.h>

int pal(char input[], int fst, int lst){
    //int fst=0, lst=strlen(input); 
    if(input[fst]==input[lst]){
        fst+=1; lst-=1;
        return pal(input, fst+1, lst-1);
    }
}

int main(){
    char input[120]; gets(input); 
    int a=0, b=strlen(input)-1;
    //printf("%d", pal(input,a,b));

    if(pal(input, a, b)){
        printf("YA");
    }else{
        printf("BUKAN");
    }
}