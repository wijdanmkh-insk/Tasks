#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//DECLARE GLOBAL VARIABLES HERE
int choice; 

//DECLARE FUNCTIONS HERE
void user(){
    printf("PILIH PENGGUNA : \n");
    printf("1) LOGISTICIAN\n2) CASHIER\n3) ACCOUNTANT\nPILIH : ");
    scanf("%d", &choice);


    
    switch(choice){
        case 1 :
        //logistician_role();
        break;
        case 2 :
        //cashier_role();
        break;
        case 3 : 
        //accountant_role();
        default : 
        system("cls");
        printf("PILIHAN SALAH!\nSILAHKAN COBA LAGI\n");
        user();
    }
}

void logistician_role(){
    printf("")
}

int main(){
    user();
}

//DECLARE FUNCTIONS EXPLANATIONS