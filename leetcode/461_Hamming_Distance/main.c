#include <stdio.h>

unsigned int cal_bits(int value) {

	unsigned int u_value = (unsigned int) value;
	unsigned int num_of_bits = 0;

	while (u_value) {
		u_value &= (u_value - 1);
		++num_of_bits;
	}

	return num_of_bits;
}

int hammingDistance(int x, int y) {
	return cal_bits(x ^ y);
}

int main(void) {

	int test_val_1 = 0b10010011001;
	int test_val_2 = 0b00101011101;

	hammingDistance(test_val_1, test_val_2);

	printf("Num of bits set for %x is %u\n", test_val_1, cal_bits(test_val_1));
	printf("Num of bits set for %x is %u\n", test_val_2, cal_bits(test_val_2));
	printf("The hamming distance for %x and %x is %u\n", test_val_1, test_val_2, hammingDistance(test_val_1, test_val_2));

	return 0;
}
