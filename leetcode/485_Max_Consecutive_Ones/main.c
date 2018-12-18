#include <stdio.h>

int findMaxConsecutiveOnes(int* nums, int numsSize) {
	int i;
	int count = 0;
	int max = 0;

	for (i = 0; i < numsSize; i++) {
		if (nums[i]) {
			count++;
		} else {
			if (count > max) {
				max = count;
				if (max > (numsSize - i)) return max;
			}
			count = 0;
		}
	}
	if (count > max) max = count;

	return max;
}

int main() {

	int array[] = {1,1,0,1,1,1};
	int ans = findMaxConsecutiveOnes(array, 6);
	printf("ans = %d\n", ans);
	return 0;
}
