#include <stdio.h>

void moveZeroes(int* nums, int numsSize) {
	int first_zero = 0;
	int first_nonzero = 0;
	int temp;

	do {
		while (nums[first_zero] != 0) {
			first_zero++;
			if (first_zero >= numsSize) return;
		}

		first_nonzero = first_zero+1;
		if (first_nonzero >= numsSize) return;

		while (nums[first_nonzero] == 0) {
			first_nonzero++;
			if (first_nonzero >= numsSize) return;
		}

		if (first_zero > first_nonzero) return;

		/* Swap */
		temp = nums[first_zero];
		nums[first_zero] = nums[first_nonzero];
		nums[first_nonzero] = temp;

		//first_zero++;
		//first_nonzero++;

	} while (first_zero < numsSize && first_nonzero < numsSize);
}

int main() {
	int nums[] = {1,0};
	int i;

	moveZeroes(nums, sizeof(nums)/sizeof(nums[0]));

	for (i = 0; i < sizeof(nums)/sizeof(nums[0]); i++) {
		printf("%d,", nums[i]);
	}
	printf("\n");
	return 0;
}
