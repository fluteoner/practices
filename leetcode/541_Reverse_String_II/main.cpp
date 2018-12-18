#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <unordered_set>

class Solution {
public:
	Solution() {
		const clock_t begin_time = clock();
		reverseStr("+---+---+---+", 2);
		std::cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC << endl;
	}

	string reverseStr(string s, int k) {

		string::iterator it;
		string::iterator it_end;
		for (it = s.begin(); distance(it, s.end()) > 2*k; advance(it, 2*k)) {
			it_end = it;
			advance(it_end, k);
			reverse(it, it_end);
		}

		it_end = it;

		int dist = distance(it, s.end());

		if (dist >= k) {
			advance(it_end, k);
		} else {
			advance(it_end, dist);
		}

		cout << "dist = " << dist << ", it = " << *it << ", it_end = " << *it_end << endl;

		reverse(it, it_end);

		cout << s << endl;
		return s;
	}
};

int main() {
	Solution s;
	return 0;
}
