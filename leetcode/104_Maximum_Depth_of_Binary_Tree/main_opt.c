#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for a binary tree node. **/
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

inline int max(int a, int b) {
	return a > b ? a : b;
}
int maxDepth(struct TreeNode* root) {

	if (root == NULL) return 0;

	if (root->left == NULL) {
		if (root->right == NULL) {
			return 1;
		} else {
			return maxDepth(root->right)+1;
		}
	} else {
		if (root->right == NULL) {
			return maxDepth(root->left)+1;
		} else {
			return max(maxDepth(root->left), maxDepth(root->right))+1;
		}
	}
}

int main() {
	return 0;
}
