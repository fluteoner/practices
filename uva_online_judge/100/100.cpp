#include <iostream>

int cache[1000001];

int get_cycle_len(const int value)
{
	int n = value;
	int len = 1;

	/* Cache hit!! */
	if (cache[value] != 0) return cache[value];

	while (n != 1) {

		if (n & 0x01) {
			/* Odd */
			n = 3*n + 1;
			n = n >> 1;
			len += 2;
		} else {
			/* Even */
			n = n >> 1;
			++len;
		}
	}

	cache[value] = len;

	return len;
}

int main()
{
	int input1;
	int input2;
	int start_value;
	int end_value;
	int max_len;
	int len;

	while (std::cin >> input1 >> input2) {

		max_len = -1;

		if (input1 > input2) {
			start_value = input2;
			end_value = input1;
		} else {
			start_value = input1;
			end_value = input2;
		}

		for (int i = start_value; i <= end_value; i++) {
			len = get_cycle_len(i);
			if (len > max_len) max_len = len;
		}

		std::cout << input1 << " " << input2 << " " << max_len << std::endl;
		
	}

	return 0;
}
