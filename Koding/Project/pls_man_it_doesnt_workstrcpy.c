#include <stdio.h>

int main(){
    int on_off = 1; //switch untuk menghidupkan/mematikan
    int ind = 0;

    do{
        int menu; 
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
                case 1 :
                printf("1. Draw simple pattern\n");
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
                    case 2 : printf("2. Complex pattern\n");

                        /*
                        
                        *
                        &*
                        ***
                        &*&*
                        *****
                        &*&*&*
                        */
                        int num, co1;
                        printf("Masukan jumlah baris/kolom: ");
                        scanf("%d", &num);

                        for(int row = 1; row <= num; row++){
                            if (row%2!=0){
                                for(co1=1 ; co1 <= row; co1++){
                                    printf("*");
                                }
                                printf("\n");
                            }
                            else{
                                for(co1=1 ; co1 <= row; co1++){
                                    if (co1%2!=0){
                                        printf("&");
                                    }
                                    else{
                                        printf("*");
                                    }
                                }
                                printf("\n");
                            }
                        }
                        break;
                    case 3: printf("3. Up counter\n");
                        break;
                    case 4:  printf("4. Down counter\n");
                        break;
                    default: 
                        printf("PILIHAN SALAH! MOHON PILIH KEMBALI!\n");
                }
    
                if(on_off != 1 && on_off != 0){
                printf("\nPilih 1 untuk mengulangi atau pilih 0 untuk berhenti : ");
                scanf("%d", &on_off);
            }
    }while(menu != 1 && menu != 2 && menu != 3 && menu != 4);
        
    }while(on_off);
}