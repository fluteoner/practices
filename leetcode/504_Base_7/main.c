#include <stdio.h>

char* convertToBase7(int num) {
	char ans[10];
	while (num != 0) {
		printf("%d", num % 7);
		num /= 7;
	}
	return NULL;
}

int main() {
	convertToBase7(100);
	return 0;
}
