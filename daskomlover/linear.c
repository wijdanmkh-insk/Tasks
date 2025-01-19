// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min(int n[], int max){
    int minE = INT_MAX, maxE = INT_MIN;
    for(int i = 0; i < max; i++){
        if(n[i] < minE){
            minE = n[i];
        }
        
        if(n[i] > maxE){
            maxE = n[i];
        }
    }
    return minE;
}

int main() {
    int n; long int def_kupon;
    
    scanf("%d %d", &n, &def_kupon);
    int kupon[n];
    
    for(int a=0;a<n;a++){
        scanf("%d", &kupon[a]);
        kupon[a] = abs(kupon[a]);
        kupon[a] = abs(kupon[a]-def_kupon);
    }
    
    int ans = min(&kupon[n], n);
    printf("%d", ans+def_kupon);
}