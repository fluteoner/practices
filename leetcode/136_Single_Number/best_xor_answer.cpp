#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
	Solution() {
		vector<int> vec = {, 2, 2, 3, 1, 3, 5};
		cout << singleNumber(vec);
		/*for (auto i : ans) {
			cout << i << ",";
		}*/
		cout << endl;
	}
	
	int singleNumber(vector<int>& nums) {
		int result = 0;
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
