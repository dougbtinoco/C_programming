#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Complete the sockMerchant function below.
int sockMerchant(int n, int* ar) {
    int i_count=0, j_count=1;
    int couple=0;

    while (i_count < n){
        if(ar[i_count] == 0){
            i_count++;
            j_count++;
        }
        else{
            while(j_count < n){
                if(ar[j_count] == 0){
                    j_count++;
                }
                else{
                    if(ar[i_count] == ar[j_count]){
                        couple++;
                        ar[i_count] = 0;
                        ar[j_count] = 0;
                    }
                    else{
                        j_count++;
                    }
                }
            }
            i_count++;
            j_count = i_count + 1;
        }
    }
    return(couple);
}

int main(){

    int n, *ar;
    
    scanf("%d", &n);
    ar = malloc(n * sizeof(int));
    for(int i=0; i< n; i++){
      scanf("%d", &ar[i]);
    }
    int result = sockMerchant(n, ar);

    printf("%d \n", result);

    return 0;
}
