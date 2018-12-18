#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
    int arrayPairSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int sum = 0, count = 0;
        for (int value : nums) {
            ++count;
            if (count == 1) {
                sum += value;
            } else {
                count = 0;
            }
        }
        return sum;
    }
};

int main() {
    Solution s;
    std::vector<int> nums = {1, 4, 3, 2};
    std::cout << s.arrayPairSum(nums) << std::endl;
    return 0;
}
