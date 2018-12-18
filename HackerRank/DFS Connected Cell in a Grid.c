#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int grid[10][10];

int find_largest_recursive(int i, int j, int n, int m) {
    int count = 0;
    
    if (i < 0 || j < 0 || i >= n || j >= m) return 0;
    
    if (grid[i][j] <= 0) return 0;
    
    count +=1;
    grid[i][j] = -1;
    
    count += find_largest_recursive(i-1, j-1, n, m);
    count += find_largest_recursive(i, j-1, n, m);
    count += find_largest_recursive(i+1, j-1, n, m);
    count += find_largest_recursive(i+1, j, n, m);
    count += find_largest_recursive(i+1, j+1, n, m);
    count += find_largest_recursive(i, j+1, n, m);
    count += find_largest_recursive(i-1, j+1, n, m);

    return count;
}

int find_largest(int n, int m) {
    int max_region = 0;
    int temp;
    for(int grid_i = 0; grid_i < n; grid_i++){
       for(int grid_j = 0; grid_j < m; grid_j++){
          temp = find_largest_recursive(grid_i, grid_j, n, m);
          if (temp > max_region) {
              max_region = temp;
          }
       }
    }
    return max_region;
}


int main(){
    int n; 
    scanf("%d",&n);
    int m; 
    scanf("%d",&m);

    for(int grid_i = 0; grid_i < n; grid_i++){
       for(int grid_j = 0; grid_j < m; grid_j++){
          
          scanf("%d",&grid[grid_i][grid_j]);
       }
    }
    printf("%d", find_largest(n, m));
    return 0;
}