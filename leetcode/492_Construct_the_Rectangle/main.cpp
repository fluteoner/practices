#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
	Solution() {
		const clock_t begin_time = clock();
		constructRectangle(500000000);
		std::cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC << endl;
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
