#include <stdlib.h>
#include <stdio.h>

inline int is_perimeter(int** grid, int i, int j, int gridRowSize, int gridColSize) {
	if (i < 0 || j < 0 || i >= gridRowSize || j >= gridColSize || grid[i][j] == 0) return 1;
	return 0;
}

inline int islandPerimeter(int** grid, int gridRowSize, int gridColSize) {

	int i, j, sum = 0;

	for (i = 0; i < gridRowSize; i++) {
		for (j = 0; j < gridColSize; j++) {
			if (grid[i][j] == 0) continue;
			sum += is_perimeter(grid, i-1, j,   gridRowSize, gridColSize) + 
			       is_perimeter(grid, i,   j-1, gridRowSize, gridColSize) + 
			       is_perimeter(grid, i+1, j,   gridRowSize, gridColSize) + 
			       is_perimeter(grid, i,   j+1, gridRowSize, gridColSize);
			
		}
	}
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
