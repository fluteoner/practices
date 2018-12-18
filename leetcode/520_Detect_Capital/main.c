#include <stdio.h>
#include <stdbool.h>

bool detectCapitalUse(char* word) {

	char *p = word;

	if (isupper(*p)) {
		p++;
		if (*p == 0) return true;

		if (isupper(*p)) {
			while (*p) {
				if (islower(*p)) return false;
				p++;
			}
		 } else {
			while (*p) {
				if (isupper(*p)) return false;
				p++;
			}
		}

	} else {
		/* axxxx */
		while (*p) {
			if (isupper(*p)) return false;
			p++;
		}
	}
	return true;
}

int main() {
	printf("%u\n", detectCapitalUse("Abcde"));
	printf("%u\n", detectCapitalUse("AbAde"));
	printf("%u\n", detectCapitalUse("abAde"));
	printf("%u\n", detectCapitalUse("abcde"));
	return 0;
}
