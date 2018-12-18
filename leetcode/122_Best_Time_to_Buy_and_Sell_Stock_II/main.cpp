#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
	Solution() {
		const clock_t begin_time = clock();
		vector<int> prices = {10, 11, 10, 12, 10, 13};
		maxProfit(prices);
		std::cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC << endl;
	}

	int maxProfit(vector<int>& prices) {

		int profit = 0;

		for (auto it = prices.begin(); it != prices.end(); it++) {

			vector<int>::iterator it_next = next(it, 1);

			if (it_next == prices.end()) {
				break;		
			}

			if ( (*it_next - *it) > 0) profit += *it_next - *it;
		}
		//cout << "Profit = " << profit << endl;
		return profit;
	}

};

int main() {
	Solution s;
	return 0;
}
