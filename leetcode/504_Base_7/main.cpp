#include <iostream>
using namespace std;
#include <vector>
#include <stack>

class Solution {
public:
	Solution() {
		const clock_t begin_time = clock();
		convertToBase7(100);
		convertToBase7(-7);
		convertToBase7(0);
		std::cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC << endl;
	}

	string convertToBase7(int num) {
		stack<char> stack;
		bool is_neg = false;
		string ans;

		if (num == 0) {
			ans.push_back('0');
			return ans;
		}

		if (num < 0) {
			num = -num;
			is_neg = true;
		}

		while (num != 0) {
			stack.push(char(num%7 + 48));
			num /= 7;
		}

		if (is_neg) {
			ans.push_back('-');
		}

		while (!stack.empty()) {
			ans.push_back(stack.top());
			stack.pop();
		}

		return ans;
	}
};

int main() {
	Solution s;
	return 0;
}
