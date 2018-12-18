#include <iostream>
using namespace std;
#include <unordered_map>

class Solution {
public:

	Solution() {
		string s = "abcde";
		string t = "cdxbac";
		cout << findTheDifference(s, t);
		cout << endl;
	}

    char findTheDifference(string s, string t) {
		unordered_map<char, int> map;
		for (auto c : s) {
			map[c]++;
		}

		for (auto c : t) {
			if (map.find(c) == map.end()) return c;
			if (--map[c] == 0) map.erase(c);
		}
		return 0;
    }
};

int main() {
	Solution s;
	return 0;
}
