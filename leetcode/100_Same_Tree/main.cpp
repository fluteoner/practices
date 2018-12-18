#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <unordered_set>

/* Definition for a binary tree node.*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	Solution() {
		const clock_t begin_time = clock();
		isSameTree(0, 0);
		std::cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC << endl;
	}

	bool isSameTree(TreeNode* p, TreeNode* q) {

		if (p == 0 && q == 0) return true;
		if (p != 0 && q != 0) {
			if (p->val != q->val) {
				return false;
			} else {
				return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
			}
		} else {
			return false;
		}
	}
};

int main() {
	Solution s;
	return 0;
}
