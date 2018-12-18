/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
struct TreeNode* invertTree(struct TreeNode* root) {
	if (root) {
		/* Exchange Pointers */
		struct TreeNode* temp;
		temp = root->left;
		root->left = root->right;
		root->right = temp;

		/* Recursive */
		invertTree(root->left);
		invertTree(root->right);
	}
	return root;
}

int main() {
	return 0;
}
