#include <iostream>
using namespace std;
#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
	Solution() {
		const clock_t begin_time = clock();
		vector<int> nums1 = {1, 2, 2, 1};
		vector<int> nums2 = {2, 2};
		intersection(nums1, nums2);
		std::cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC << endl;
	}

	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

		vector<int> ans;
		ans.reserve(100);
		unordered_set<int> set1(nums1.begin(), nums1.end());
		unordered_set<int> set2(nums2.begin(), nums2.end());

		for (auto val : set2) {
			if (set1.count(val)) {
				ans.push_back(val);
			}
		}
		//cout << "size = " << ans.size() << endl;
		return ans;
	}
};

int main() {
	Solution s;
	return 0;
}
