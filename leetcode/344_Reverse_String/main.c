#include <string.h>
#include <stdio.h>
char* reverseString(char* s) {
	int i, j, len = strlen(s);
	char temp;
	for (i = 0, j = len-1; j > i; i++, j--) {
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
	return s;
}

int main() {
	char s[] = "12345678";
	printf("%s\n", reverseString(s));
	return 0;
}
