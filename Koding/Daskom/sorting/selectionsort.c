#include <stdio.h>

int main(){
    int temp;
    int n, arr[120]; scanf("%d", &n);
    for(int a=0; a<n; a++){
        scanf("%d", &arr[a]);
    }
    printf("\n");

    for(int i=0; i<n; i++){
        int min = i;
        for(int j=0; j<n; j++){
            if(arr[j]>arr[min]){
                min = j;
                temp = arr[min];
                arr[min]=arr[i];
                arr[i]=temp;
            }
        }
    }

    for(int a=0; a<n; a++){
        printf("%d ", arr[a]);
    }

}