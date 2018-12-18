#include <stdio.h>

int addDigits(int num) {
	int sum = num;
	while(sum >= 10)  {
		sum = sum/10 + sum%10;
	}
	return sum;  
}

int main() {
	printf("%d\n", addDigits(38));
	return 0;
}
