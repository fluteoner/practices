#include <iostream>
using namespace std;
#include <unordered_map>

class Solution {
public:

	Solution() {
		string s = "abcde";
		string t = "cdxbae";
		cout << findTheDifference(s, t);
		cout << endl;
	}

    char findTheDifference(string s, string t){
        char result = 0;
        for(int i = 0; i < s.size(); ++i)
            result ^= (s[i] ^ t[i]);
        return result ^ t[s.size()];
    }

};

int main() {
	Solution s;
	return 0;
}
