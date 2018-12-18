#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
	Solution() {
		vector<int> vec = {1, 2, 2, 3, 1, 3, 5};
		cout << singleNumber(vec);
		/*for (auto i : ans) {
			cout << i << ",";
		}*/
		cout << endl;
	}
	
	int singleNumber(vector<int>& nums) {
		unordered_set<string> set;
		for (auto i : nums) {
			map[i]++;
		}
		for (auto i : map) {
			if (i.second == 1) return i.first;
		}
		return -1;
	}
};

int main() {
	Solution s;
	return 0;
}
