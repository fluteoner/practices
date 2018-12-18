#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	const vector<unordered_set<char>> row_vec = {
		{ 'z','x','c','v','b','n','m'},
		{ 'a','s','d','f','g','h','j','k','l'},
		{ 'q','w','e','r','t','y','u','i','o', 'p'}
	};

	Solution() {
		vector<string > s = { "Hello","Alaska","DaD","Peace" };
		vector<string > result = findWords(s);

		for (vector<string>::const_iterator it = result.begin() ; it != result.end(); ++it) {
			cout << *it << endl;
		}
	}

	vector<std::string> findWords(vector<string>& words) {
		vector<string > result;

		for (vector<string>::const_iterator it = words.begin() ; it != words.end(); ++it) {
			std::string::const_iterator first_it = (*it).begin();

			vector<unordered_set<char>>::const_iterator target_row_it;

			for (vector<unordered_set<char>>::const_iterator row_it = row_vec.begin() ; row_it != row_vec.end(); ++row_it) {
				if ( (row_it->find(tolower(*first_it))) != row_it->end() ) {
					target_row_it = row_it;
					break;
				}
			}

			bool all_match = true;

			for ( std::string::const_iterator str_it=(*it).begin()+1; str_it!=(*it).end(); ++str_it) {
				if ( (target_row_it->find(tolower(*str_it))) != target_row_it->end() ) {
					continue;
				} else {
					all_match = false;
					break;
				}
			}
			if (all_match) {
				result.push_back(*it);
			}
		}

		return result;
	}
};

int main() {
	Solution s;
	return 0;
}
