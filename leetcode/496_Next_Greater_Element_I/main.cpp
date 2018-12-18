#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <iterator>

class Solution {
public:
	Solution() {
		vector<int> sub = {4,1,2};
		vector<int> set = {1,3,4,2};
		vector<int> ans = nextGreaterElement(sub, set);
		for (auto i : ans) {
			cout << i << ",";
		}
		cout << endl;
	}

	vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {

		vector<int> result;

		for (auto i : findNums) {

			auto it = find(nums.begin(), nums.end(), i);
			int target = *it;

			auto found = find_if(next(it, 1), nums.end(),
				[target](const int &val)
				{
					return val > target;
				}
			);

			if (found != nums.end()) {
				result.push_back(*found);
			} else {
				result.push_back(-1);
			}

		}

		return result;
	}
};

int main() {
	Solution s;
	return 0;
}
