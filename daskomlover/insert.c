#include <stdio.h>

void insertionSort(int arr[], int n){
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    for (i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int n; printf("Banyak data: "); scanf("%d", &n);
    int arr[n]; 

    for(int i=0;i<n;i++){
        printf("Data ke-%d: ", i+1);
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, n);
}


