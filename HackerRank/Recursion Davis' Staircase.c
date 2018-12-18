#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int cache[36+1];

int stairscase(int n) {
    int sum = 0, temp;
    switch(n) {
        case 1: return 1;
        case 2: return 2;
        case 3: return 4;
        default:
            if (cache[n-1] == 0) {
                cache[n-1] = stairscase(n-1);
            }
            if (cache[n-2] == 0) {
                cache[n-2] = stairscase(n-2);
            }
            if (cache[n-3] == 0) {
                cache[n-3] = stairscase(n-3);
            }
            return cache[n-1]+cache[n-2]+cache[n-3];
    }
}

int main(){
    int s; 
    scanf("%d",&s);
    for(int a0 = 0; a0 < s; a0++){
        int n; 
        scanf("%d",&n);
        printf("%d\n", stairscase(n));
    }
    return 0;
}

