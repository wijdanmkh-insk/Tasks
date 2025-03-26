#include <stdio.h>

int main(){
   int angka1, angka2, def; 
   printf("Masukkan angka 1 : "); scanf("%d",&angka1);
   printf("Masukkan angka 2 : "); scanf("%d",&angka2);

   //def = ((angka1 < angka2) ? angka1 : angka2);

   /*
   do{
    if(angka1 % def == 0 && angka2 % def == 0){;
        def--;
        break;
    }
   }while(def > 0);

    printf("FPB dari %d dan %d adalah %d",angka1,angka2,def);
   */

  do{
    def = angka1%angka2;
    angka1 = angka2;
    angka2 = def;
  }while(angka2!=0);

  printf("%d",angka1);
}