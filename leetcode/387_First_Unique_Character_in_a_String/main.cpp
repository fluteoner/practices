#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
	Solution() {
		const clock_t begin_time = clock();
		int index = firstUniqChar("");
		std::cout << "index = " << index << endl;
		std::cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC << endl;
	}

	int firstUniqChar(string s) {

		size_t found;
        for (string::iterator it = s.begin(); it != s.end(); it++) {
			found = s.find_first_of(*it);
			if (found == s.find_last_of(*it)) {
				return found;
			}
		}
		return -1;
    }
};

int main() {
	Solution s;
	return 0;
}
