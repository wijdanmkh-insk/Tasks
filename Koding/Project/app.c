#include <stdio.h>

int main(){
    int on_off = 1,menu;

    do{
    do{
        printf("\n\n");
        printf("Menu sederhana program C\n");
        printf("1. Draw simple pattern\n");
        printf("2. Complex pattern\n");
        printf("3. Up counter\n");
        printf("4. Down counter\n");
        printf("input (1-4) untuk memilih menu: ");
        scanf("%d", &menu);
        printf("\n\n");

        switch(menu){
            int num;
            case 1 : 
            printf("1. Draw simple pattern\n");

            /*
                        
            *
            **
            ***
            ****
            *****

            */ 
           printf("Masukan jumlah baris/kolom: ");
           scanf("%d",&num);

           for(int row=1;row<=num;row++){
            for(int col=1;col<=row;col++){
                printf("*");
            }
            printf("\n");
           }
           break;

           case 2 :
           printf("Draw complex pattern\n");
           /*
                        
            *
            &*
            ***
            &*&*
            *****
            &*&*&*
            */
        
           printf("Masukan jumlah baris/kolom: ");
           scanf("%d",&num);

           for(int row=1;row<=num;row++){
            for(int col=1;col<=row;col++){
                if(row%2==0){
                    if(col%2==0){
                        printf("*");
                    }else{
                        printf("&");
                    }
                }else{
                    printf("*");
                }
            }
            printf("\n");
           }
           break;

           case 3 : 
           printf("3. Up counter\n");
           break;

           case 4 :
           printf("4. Down counter\n");
           break;

           default :
           printf("Pilihan salah! Silahkan pilih lagi!\n");
        }

    }while(menu != 1 && menu != 2 && menu != 3 && menu != 4);
    
    do{
        printf("Pilih 1 untuk melanjutkan atau pilih 0 untuk berhenti : ");
        scanf("%d", &on_off);

        if(on_off!=1 && on_off!=0){
            printf("Pilihan salah!\n");
            if(on_off==0){
                break;
            }
        }
    }while(on_off!=1 && on_off!=0);
    }while(on_off==1);
}