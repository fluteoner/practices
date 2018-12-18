#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

#define MAX(a, b) (a)>(b)?(a):(b)
#define MIN(a, b) (a)>(b)?(b):(a)

#if 0
struct cost_node {
    int index;
    int cost;
};

int cmp_func(const void *a, const void *b) {
    const struct cost_node *c1 = a, *c2 = b;
    return c1->cost - c2->cost;
}

int *two_sum(int *cost, int num_cost, int money) {
    int *ans = malloc(sizeof(int)*2);
    struct cost_node *cost_table;
    
    int i, j, sum;
    
    cost_table = malloc(sizeof(struct cost_node)*num_cost);
    
    for (i = 0; i < num_cost; i++) {
        cost_table[i].index = i+1;
        cost_table[i].cost = cost[i];
    }
    
    qsort(cost_table, num_cost, sizeof(struct cost_node), cmp_func);

    i = 0, j = num_cost-1;
    
    while (i < j) {
        sum = cost_table[i].cost + cost_table[j].cost;
        if (sum == money) {
            ans[0] = MIN(cost_table[i].index, cost_table[j].index);
            ans[1] = MAX(cost_table[i].index, cost_table[j].index);
            break;
        } else if (sum < money) {
            i++;
        } else {
            j--;
        }
    }
    free(cost_table);
    return ans;
}
#else
int *two_sum(int *cost, int num_cost, int money) {
    int *ans = malloc(sizeof(int)*2);
    int hash[10000];
    memset(hash, 0x00, sizeof(int)*10000);
    int i;

    for (i = 0; i < num_cost; i++) {
        if (cost[i] > money) continue;
        if (hash[cost[i]] == 0) {
            hash[money - cost[i]] = i+1;
        } else {
            ans[0] = MIN(i+1, hash[cost[i]]);
            ans[1] = MAX(i+1, hash[cost[i]]);
            break;
        }
    }

    return ans;
}
#endif

int main() {
    int t; 
    int *ans;
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++){
        int m; 
        scanf("%d",&m);
        int n; 
        scanf("%d",&n);
        int *a = malloc(sizeof(int) * n);
        for(int a_i = 0; a_i < n; a_i++){
           scanf("%d",&a[a_i]);
        }
        ans = two_sum(a, n, m);
        printf("%d %d\n", ans[0], ans[1]);
        free(ans);
        free(a);
    }
    return 0;
}

