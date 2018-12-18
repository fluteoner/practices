#include <stdio.h>

int findComplement(int num) {
	int mask = 0x01 << ( sizeof(int)*8-1 );

	while ( !(num & mask)) {
		mask = mask >> 1;
	}

	return (~num) & (~mask);
}

int main() {
	printf("result = %d", findComplement(1));
	findComplement(1);
	return 0;
}
