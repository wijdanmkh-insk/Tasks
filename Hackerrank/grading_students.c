#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_round(int x){
    int result, round_down;
    if (x < 38){
        result = x;
    }else{
        round_down = x / 5;
        round_down += 1; 
        
        
        if(abs(x-(round_down*5)) < 3){
            result = round_down * 5;
        }else{
            result = x;
        }
    }
    
    return result;
}

int main(){
    int n; scanf("%d", &n); int arr[n];
    
    for(int a = 0; a < n; a++){
        scanf("%d", &arr[n]);
        arr[n] = find_round(arr[n]);
        printf("%d\n", arr[n]);
    }
}
