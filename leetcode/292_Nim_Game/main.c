#include <stdio.h>
#include <stdbool.h>

inline bool canWinNim(int n) {
	return ( n & 0x3 );
}

int main() {
	int n = 500;
	if (canWinNim(n)) {
		printf("n = %d, win\n", n);
	} else {
		printf("n = %d, lose\n", n);
	}
	return 0;
}
