#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
	Solution() {
		vector<unsigned char> vec = {0xFF, 0xFE, 0xFE, 3, 1, 3, 0xFF};
		cout << (int)singleNumber(vec);
		cout << endl;
	}
	
	char singleNumber(vector<unsigned char>& nums) {
		unsigned char result = 0;
		for (auto i : nums)
		{
			result ^= i;
		}
		return result;
	}
};

int main() {
	Solution s;
	return 0;
}
