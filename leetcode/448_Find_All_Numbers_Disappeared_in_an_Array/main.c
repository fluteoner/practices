#include <stdlib.h>
#include <stdio.h>
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
	int i, count = 0;
	int *ans;

	for (i = 0; i < numsSize; i++) {
		if (nums[abs(nums[i])-1] > 0) {
			nums[abs(nums[i])-1] *= (-1);
			(*returnSize)++;
		}
	}

	(*returnSize) = numsSize - (*returnSize);

	ans = malloc(sizeof(int)*(*returnSize));

	for (i = 0; i < numsSize; i++) {
		if (nums[i] > 0) {
			ans[count++] = i+1;
		}
	}
	return ans;
}

int main() {
	int test[] = {4,3,2,7,8,2,3,1};
	int i, count = 0;
	int *ans = findDisappearedNumbers(test, sizeof(test)/sizeof(test[0]), &count);
	for (i = 0; i < count; i++) {
		printf("%d,", ans[i]);
	}
	free(ans);
	return 0;
}
