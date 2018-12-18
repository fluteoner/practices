#include <iostream>
using namespace std;
#include <unordered_map>

class Solution {
public:
	Solution() {
		const clock_t begin_time = clock();
		cout << "ANSWER : " << canConstruct("aa", "ab") << endl;
		std::cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC << endl;
	}

	bool canConstruct(string ransomNote, string magazine) {

		for (auto c : ransomNote) {
			//cout << c;
			size_t str_index;
			if ( (str_index = magazine.find(c)) == string::npos) return false;
			magazine[str_index] = '-';
		}

		return true;
	}
};

int main() {
	Solution s;
	return 0;
}
