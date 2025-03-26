#include <stdio.h>

int main(){

    int repeat = 1;

    while(repeat == 1){
        do{
            int reps = 1;

        int menu;
        printf("\n\n");
        printf("Menu sederhana program C\n");
        printf("1. Draw simple pattern\n");
        printf("2. Complex pattern\n");
        printf("3. Up counter\n");
        printf("4. Down counter\n");
        printf("input (1-4) untuk memilih menu: ");
        scanf("%d", &menu);
        printf("\n\n");

        /*if(menu == 1){
             printf("1. Draw simple pattern\n");
        }

        if(menu == 2){
            printf("2. Complex pattern\n");
        }

        if(menu == 3){
             printf("3. Up counter\n");
        }

        if (menu == 4){
             printf("4. Down counter\n");
        }*/

        switch(menu){
            case 1: printf("1. Draw simple pattern\n");
                    /*
                    
                    *
                    **
                    ***
                    ****
                    *****

                    */

                    int numberOfItem;
                    printf("Masukan jumlah baris/kolom: ");
                    scanf("%d", &numberOfItem);

                    for(int row = 1; row <= numberOfItem; row++){
                        for(int coulumn = 1; coulumn <= row; coulumn++){
                            printf("*");
                        }
                        printf("\n");
                    }
                break;

            case 2: printf("2. Complex pattern\n");

                    /*
                    
                    *
                    &*
                    ***
                    &*&*
                    *****
                    &*&*&*
                    */

                   printf("Masukan jumlah baris/kolom: ");
                        int num;
                        scanf("%d", &num);

                        for(int row = 1; row <= num; row++){
                            for(int col=1; col <= row; col++){
                                if(row%2!=0){
                                    printf("*");
                                }else{
                                    if(col%2==0){
                                        printf("*");
                                    }else{
                                        printf("&");
                                    }
                                }
                            }
                            printf("\n");
                        }
                        break;
            case 3: printf("3. Up counter\n");
                break;
            case 4:  printf("4. Down counter\n");
                break;
        }

        printf("\n\n");
        printf("Pilih 1 untuk mengulangi atau pilih 0 untuk berhenti: ");
        scanf("%d", &repeat);
    }   while(reps )
    }
    return 0;
}