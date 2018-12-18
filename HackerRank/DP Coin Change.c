#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

#define GET_ARRAY(array, rsize, money, coin_index) (*(array+(rsize*money)+coin_index))

long long count_change_ways_r(int money, int *coins, int mth_coin, long long *cached, int rsize) {
    long long count = 0;
    int coin_num = 0;
    
    if (money <= 0 || mth_coin < 0) {
        return 0;
    }
    
    if (GET_ARRAY(cached, rsize, money, mth_coin) >= 0) return GET_ARRAY(cached, rsize, money, mth_coin);
    
    while (coins[mth_coin] * coin_num <= money) {
        if (money == coins[mth_coin]*coin_num) {
            count += 1;
        }
        count += count_change_ways_r(money - coins[mth_coin]*coin_num, coins, mth_coin-1, cached, rsize);
        coin_num++;
    }
    
    GET_ARRAY(cached, rsize, money, mth_coin) = count;
    
    return count;
}

long long int count_change_ways(int money, int *coins, int m) {
    long long *cached = calloc((m+1)*(money+1), sizeof(long long));
    long long i, j, ret;
    
    for (i = 0; i <= money; i++) {
        for (j = 0; j <= m; j++) {
            GET_ARRAY(cached, m, i, j) = -1;
        }
    }
    
    ret = count_change_ways_r(money, coins, m, cached, m);
    free(cached);
    return ret;
}

int main() {
    int n; 
    int m;
    long long result;
    scanf("%d %d",&n,&m);
    int *coins = malloc(sizeof(int) * m);
    for(int coins_i = 0; coins_i < m; coins_i++){
       scanf("%d",&coins[coins_i]);
    }
    result = count_change_ways(n, coins , m-1);
    printf("%lld", result);
    return 0;
}

