#include <stdlib.h>
#include <stdio.h>

void dfs(int** grid, int i, int j, int gridRowSize, int gridColSize, int *sum) {

	grid[i][j]++;

	if (j == 0 || grid[i][j-1] == 0) {
		(*sum)++;
	} else if (grid[i][j-1] == 1) {
		dfs(grid, i, j-1, gridRowSize, gridColSize, sum);
	}
	if (i == 0 || grid[i-1][j] == 0) {
		(*sum)++;
	} else if (grid[i-1][j] == 1) {
		dfs(grid, i-1, j, gridRowSize, gridColSize, sum);
	}
	if (j == gridColSize-1 || grid[i][j+1] == 0) {
		(*sum)++;
	} else if (grid[i][j+1] == 1) {
		dfs(grid, i, j+1, gridRowSize, gridColSize, sum);
	}
	if (i == gridRowSize-1 || grid[i+1][j] == 0) {
		(*sum)++;
	} else if (grid[i+1][j] == 1) {
		dfs(grid, i+1, j, gridRowSize, gridColSize, sum);
	}
}

int islandPerimeter(int** grid, int gridRowSize, int gridColSize) {

	int i, j, sum = 0, flag;

	for (i = 0; i < gridRowSize; i++) {
		flag = 0;
		for (j = 0; j < gridColSize; j++) {
			if (grid[i][j]) {
				flag = 1;
				break;
			}
		}
		if (flag) break;
	}
	dfs(grid, i, j, gridRowSize, gridColSize, &sum);
	return sum;
}

int main() {
	int map[][4] = {
					{0,1,0,0},
					{1,1,1,0},
					{0,1,0,0},
					{1,1,0,0}
				};
	int **pp;
	int i, j, ans;

	if (( pp = malloc( 4*sizeof( int* ))) == NULL ) { /* error */ }

	for ( i = 0; i < 4; i++ )
	{
		if ( (pp[i] = malloc( 4*sizeof(int))) == NULL ) { /* error */ }
		for ( j = 0; j < 4; j++) {
			pp[i][j] = map[i][j];
		}
	}


	ans = islandPerimeter(pp, 4, 4);

	printf("ans = %d\n", ans);

	return 0;
}
