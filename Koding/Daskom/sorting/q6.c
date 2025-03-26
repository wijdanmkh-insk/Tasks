#include <stdio.h>

int main(){
    int n=5, min, temp; 
    int data[n];

    for(int i=0; i<n;i++){
        printf("Kelereng anak ke %d : ", i+1);
        scanf("%d", &data[i]);
    }

    for(int i=0;i<n;i++){
        min = i;
        for(int j=0;j<n;j++){
            if(data[j]>data[min]){
                min = j;
                temp = data[min];
                data[min]=data[i];
                data[i]=temp;
            }
        }
    }

    printf("Hasil pengurutan : ");
    for(int i=0; i<n;i++){
        printf("%d ", data[i]);
    }
}