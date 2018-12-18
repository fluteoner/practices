#include <iostream>
using namespace std;
#include <vector>
#include <set>
#include <algorithm>

class Solution {
public:
	Solution() {
		const clock_t begin_time = clock();
		vector<int> nums1 = {};
		vector<int> nums2 = {1};
		intersection(nums1, nums2);
		std::cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC << endl;
	}

	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

		vector<int> ans;
		set<int> int_set;

		for (auto it2 = nums2.begin(); it2 != nums2.end(); ++it2) {

			if (find(nums1.begin(), nums1.end(), *it2) != nums1.end()) {
				int_set.insert(*it2);
			}
		}
		ans.assign(int_set.begin(), int_set.end());
		cout << "size = " << ans.size() << endl;
		return ans;
	}
};

int main() {
	Solution s;
	return 0;
}
