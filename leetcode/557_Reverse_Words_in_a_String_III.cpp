#include <iostream>
#include <algorithm>

class Solution {
public:
    std::string reverseWords(std::string s) {
        std::string::iterator begin = s.begin();
        std::string::iterator end = s.begin();
        for (end = s.begin(); end != s.end(); end++) {
            if (*end == ' ') {
                std::reverse(begin, end);
                begin = end + 1;
            }
        }
        std::reverse(begin, end);
        return s;
    }
};

int main() {
    Solution s;
    std::cout << s.reverseWords("Let's take LeetCode contest") << std::endl;
    return 0;
}
