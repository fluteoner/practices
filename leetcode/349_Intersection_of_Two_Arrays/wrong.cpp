#include <iostream>
using namespace std;
#include <vector>
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
		int max_dist = 0, dist;
		vector<int>::iterator ans_begin, ans_end;
		for (auto it = nums1.begin(); it != nums1.end(); ++it) {

			//cout << *it << endl;

			for (auto ite = nums1.rbegin(); it != ite.base(); ++ite) {
				if (max_dist > distance(it, ite.base())) break;
				auto res = search(begin(nums2), end(nums2), it, ite.base());
				//cout << *it << "<->" << *ite << endl;
				if (res != nums2.end()) {
					dist = distance(it, ite.base());
					if (dist > max_dist) {
						//cout << *it << "<->" << *ite << " found, length = " << dist << endl;
						max_dist = dist;
						ans_begin = it;
						ans_end = ite.base();
					}
				}
			}
		}
		ans.assign(ans_begin, ans_end);
		return ans;
	}
};

int main() {
	Solution s;
	return 0;
}
