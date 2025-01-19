#include <stdio.h>
int i, j, total, max, min, idx;

int main (){
    printf("Banyak data: "); scanf("%d", &total);
    int DATA[total];
    
    for (i = 0; i < total; i++) {
        printf("Data ke-%d: ", i+1);
        scanf("%d", &DATA[i]);
        if (i == 0){
            max = DATA[i]; min = DATA[i];
        }
        else {
            if (DATA[i] > max) max = DATA[i]; 
            if (DATA[i] < min) min = DATA[i];
            }
        }
    int TEMP[max - min + 1];

    for (i = min; i <= max; i++)
    TEMP[i - min] = 0;

    for (i = 0; i < total; i++)
    TEMP[DATA[i] - min]++;

    idx = 0;
    for (i = max; i >= min; i--){
        for (j = 1; j <= TEMP[i - min]; j++){
            DATA[idx] = i;
            idx++;
        }
    }
    for (i = 0; i < total; i++){ printf("%d ", DATA[i]); }
}
