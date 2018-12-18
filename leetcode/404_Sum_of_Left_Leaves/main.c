/**
 * Definition for a binary tree node.
*/
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int sumOfLeftLeavesRecur(struct TreeNode* root, int is_left) {

	int sum = 0;

	if (root->left == 0 && root->right == 0) {
		/* Leaves */
		if (is_left)
			return root->val;
		else
			return 0;
	}
	if (root->left) sum += sumOfLeftLeavesRecur(root->left, 1);
	if (root->right) sum += sumOfLeftLeavesRecur(root->right, 0);


	return sum;
}
int sumOfLeftLeaves(struct TreeNode* root) {
	if (root == 0)
		return 0;
	else
		return sumOfLeftLeavesRecur(root, 0);
}

int main() {
	sumOfLeftLeaves(0);
	return 0;
}
