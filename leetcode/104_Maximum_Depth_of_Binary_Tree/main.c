#include <stdio.h>
#include <stdlib.h>

inline int max(int a, int b) {
	if (a > b) {
		return a;
	} else {
		return b;
	}
}
/**
 * Definition for a binary tree node. **/
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode* root) {

	if (root == NULL) return 0;

	return max(maxDepth(root->left)+1, maxDepth(root->right)+1);
}

int main() {
	return 0;
}
