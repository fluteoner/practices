#include <stdio.h>

int findMaxConsecutiveOnes(int* nums, int numsSize) {
	int i;
	int last_zero = -1;
	int max = 0;

	for (i = 0; i < numsSize; i++) {
		if (nums[i] == 0) {
			if (i - last_zero - 1 > max) {
				max = i - last_zero - 1;
			}
			if (max > numsSize - i - 2) return max;
			last_zero = i;
		}
	}
	
	if (i - last_zero - 1 > max) {
		max = i - last_zero - 1;
	}

	return max;
}

int main() {

	int array[] = {1,1,0,1,1,1};
	int ans = findMaxConsecutiveOnes(array, 6);
	printf("ans = %d\n", ans);
	return 0;
}
