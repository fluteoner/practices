#include <stdio.h>
#include <limits.h>

#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof(arr[0]))

int cmpfunc (const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}

int findContentChildren(int* g, int gSize, int* s, int sSize) {
	int i, j = 0, count = 0;

	printf("sSize = %d, gSize = %d\n", sSize, gSize);
	//qsort(g, gSize, sizeof(int), cmpfunc);
	//qsort(s, sSize, sizeof(int), cmpfunc);
	return 10000;

	for (i = 0; i < sSize; i++) {

		int min = INT_MAX;
		int min_index_j = gSize;

		for (j = 0; j < gSize; j++) {
			if (g[j] < 0) continue;
			//printf("check cookie(%d) > child(%d)\n", s[i], g[j]);
			if (s[i] >= g[j]) {
				if (s[i] - g[j] < min) {
					min = s[i] - g[j];
					min_index_j = j;
					if (min == 0) break;
				}
			}
		}
		if ((min_index_j < gSize) && (min != INT_MAX)) {
			count++;
			//printf("match cookie %d -> %d child!!\n", s[i], g[min_index_j]);
			g[min_index_j] = -g[min_index_j];
		} else {
			//printf("## cookie %d not found\n", s[i]);
		}
	}
	return count;
}

int main() {
	int g[10000];
	int s[10000];
	int count;
	int i; 

	for (i = 0; i < 10000; i++) {
		g[i] = rand() % 10000;
		s[i] = rand() % 10000+10000;
	}

	count = findContentChildren(g, ARRAY_SIZE(g), s, ARRAY_SIZE(s));
	printf("count = %d\n", count);
	return 0;
}
