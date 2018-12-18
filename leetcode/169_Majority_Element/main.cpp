#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
	Solution() {
		const clock_t begin_time = clock();
		vector<int> vec = {1, 2, 1, 1, 3, 4, 1};
		majorityElement(vec);
		std::cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC << endl;
	}

	int majorityElement(vector<int>& nums) {
		unordered_map<int, int> map;
		int maj = nums.size()/2;
		for (auto v : nums) {
			map[v]++;
			if (map[v] > maj) {
				cout << "majority = " << v << endl;
				return v;
			}
		}

		//for (auto m : map) {
		//	if ( m.second > maj ) {
		//		return m.first;
		//	}
		//}
		return -1;
	}
};

int main() {
	Solution s;
	return 0;
}
