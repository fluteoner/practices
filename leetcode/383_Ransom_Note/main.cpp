#include <iostream>
using namespace std;
#include <unordered_map>

class Solution {
public:
	Solution() {
		const clock_t begin_time = clock();
		cout << "ANSWER : " << canConstruct("aa", "aab") << endl;
		std::cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC << endl;
	}

	bool canConstruct(string ransomNote, string magazine) {
		unordered_map<char, int> map;
		for (auto c : magazine) {
			map[c]++;
		}

		for (auto c : ransomNote) {
			cout << c;
			if (map.find(c) == map.end()) return false;
			if (--map[c] == 0) map.erase(c);
		}

		return true;
	}
};

int main() {
	Solution s;
	return 0;
}
