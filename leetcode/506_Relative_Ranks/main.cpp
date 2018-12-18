#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <string>

class Solution {
public:
	Solution() {
		vector<int> scores = {1};
		vector<string> ans;;
		ans = findRelativeRanks(scores);
		for (auto str : ans) {
			cout << str << ",";
		}
		return;
	}

	vector<string> findRelativeRanks(vector<int>& nums) {

		vector<string> ans(nums.size());
		map<int, int, std::greater<int>> map;

		for (int i = 0; i < nums.size(); i++) {
			map[nums[i]] = i;
		}

		auto it = map.begin();

		if (it == map.end()) return ans;
		ans[it->second] = "Gold Medal";
		it++;
		if (it == map.end()) return ans;
		ans[it->second] = "Silver Medal";
		it++;
		if (it == map.end()) return ans;
		ans[it->second] = "Bronze Medal";
		it++;

		for (int r = 4; r <= map.size(); r++, it++) {
			ans[it->second] = to_string(r);
		}

		return ans;
	}
};

int main() {
	Solution s;
	return 0;
}

