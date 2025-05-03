#include <stdio.h>

int main(){
    int n, k; scanf("%d %d", &n, &k);
    int arr[n]; 
    
    for(int a = 0; a < n; a++){
        scanf("%d", &arr[a]);
    }
    int count = 0;
    for(int a = 0; a < n; a++){
        for(int b = a+1; b < n; b++){
            if((arr[a]+arr[b]) % k == 0){
                //printf("%d %d : %d\n", arr[a], arr[b], arr[a]+arr[b]);
                count++;
            }
        }
    }
    
    printf("%d", count);
}