#include <iostream>
#include <string>
#include <unordered_map>
class Solution {
public:
    bool judgeCircle(std::string moves) {
        int x = 0, y = 0;
        int len = moves.size();
        std::unordered_map<char, std::pair<int,int>> shift;
        shift['U'] = std::make_pair(0, 1);
        shift['D'] = std::make_pair(0, -1);
        shift['R'] = std::make_pair(1, 0);
        shift['L'] = std::make_pair(-1, 0);

        for (int i = 0; i < len; i++) {
            x += shift[moves.at(i)].first;
            y += shift[moves.at(i)].second;
        }
        if (x == 0 && y == 0)
            return true;
        else
            return false;
    }
};

int main() {
    Solution s;
    std::cout << s.judgeCircle("LDRRLRUULR") << std::endl;
    return 0;
}
