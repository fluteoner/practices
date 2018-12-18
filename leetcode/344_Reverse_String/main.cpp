#include <iostream>
using namespace std;
#include <string>
#include <algorithm>

class Solution {
public:
	Solution() {
		string ans = reverseString("abcdefg");
		cout << ans << endl;
	}

	string reverseString(string s) {
		reverse(s.rbegin(), s.rend());
		return s;
	}
};

int main() {
	Solution s;
	return 0;
}
