#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
	Solution() {
		const clock_t begin_time = clock();
		titleToNumber("Z");
		std::cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC << endl;
	}

	int titleToNumber(string s) {
		int ans = 0;
		
		for (auto it = s.begin(); it != s.end(); it++) {
			ans *= 26;
			ans += *it - 'A' + 1;
			//cout << *it - 'A';
		}
		cout << ans << endl;
		return ans;
	}
};

int main() {
	Solution s;
	return 0;
}
