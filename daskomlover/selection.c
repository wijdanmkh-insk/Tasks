#include <stdio.h>

void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n){
    int i, j, min_idx;

    for (i = 0; i < n-1; i++){
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;

           if(min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }

    for (i=0; i < n; i++)
        printf("%d ", arr[i]);
}

int main(){
    printf("Banyak data: "); int n; scanf("%d", &n);
    int arr[n];

    for(int i=0;i<n;i++){
        printf("Data ke-%d: ", i+1);
        scanf("%d", &arr[i]);
    }
    selectionSort(arr, n);
}


