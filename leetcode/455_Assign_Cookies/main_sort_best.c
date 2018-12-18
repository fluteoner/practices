#include <stdio.h>
#include <limits.h>

#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof(arr[0]))

int cmpfunc (const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}

int findContentChildren(int* g, int gSize, int* s, int sSize) {
	int gi, sj = 0, count = 0;

	qsort(g, gSize, sizeof(int), cmpfunc);
	qsort(s, sSize, sizeof(int), cmpfunc);

	for (gi = 0; gi < gSize; gi++) {
		for (sj; sj < sSize; sj++) {
			if (s[sj] >= g[gi]) {
				count++;
				sj++;
				break;
			}
		}
	}

	return count;
}

int main() {
	int g[] = {1,2,3};
	int s[] = {3};
	int count;
	int i; 

	count = findContentChildren(g, ARRAY_SIZE(g), s, ARRAY_SIZE(s));
	printf("count = %d\n", count);
	return 0;
}
