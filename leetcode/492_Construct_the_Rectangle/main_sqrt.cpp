#include <iostream>
using namespace std;
#include <vector>
#include <math.h>

class Solution {
public:
	Solution() {
		clock_t begin_time = clock();
		for (int i = 1; i < 100000; i++) {
			constructRectangleOPT(i);
		}
		std::cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC << endl;
		begin_time = clock();
		for (int i = 1; i < 100000; i++) {
			constructRectangle(i);
		}
		std::cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC << endl;
	}

	vector<int> constructRectangleOPT(int area) {

		vector<int> ans;

		for (int i = ceil(sqrt(area)), j = area/i; i >= j; i++, j = area/i) {
			if (area % i == 0) {
				//cout << "[ l=" << i << ",w=" << j << " ]" << endl;
				ans.push_back(i);
				ans.push_back(j);
				return ans;
			}
		}
		return ans;
	}

	vector<int> constructRectangle(int area) {

		vector<int> ans;
		int w;
		int l;

		for (int i = 1, j = area; i <= j; i++, j = area/i) {
			if (area % i == 0) {
				w = i;
				l = j;
				//cout << "[ l=" << l << ",w=" << w << " ]" << endl;
			}
		}
		ans.push_back(l);
		ans.push_back(w);

		return ans;
	}
};

int main() {
	Solution s;
	return 0;
}
