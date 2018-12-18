#include <stdio.h>

int getSum(int a, int b) {
	int mask = 0x01;
	int result = a;
	
	while (mask) {
		if ((a&mask) && (b&mask)) {
			result |= (mask<<1);
		} else if ((a&mask) && (result&mask)) {
			result |= (mask<<1);
		} else if ((result&mask) && (b&mask)) {
			result |= (mask<<1);
		}

		if ((a ^ b ^ result) & mask) {
			result |= (a ^ b ^ result) & mask;
		} else {
			result &= (a ^ b ^ result) | ~mask;
		}

		mask = mask << 1;

	}
	return result;
}

int main() {
	printf("sum = %d\n", getSum(-1,1));
	return 0;
}
