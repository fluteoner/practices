#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

/**
 * Definition for a binary tree node.*/
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

inline int min2(int v1, int v2) {
	return v1>v2 ? v2 : v1;
}

inline int min3(int v1, int v2, int v3) {
	return min2(v1, min2(v2, v3));
}

int getMinimumDifferenceRecursive(struct TreeNode* root, int parent_val) {

	int min_diff;

	if (root == 0) return INT_MAX;

	min_diff = abs(parent_val - root->val);

	//if (root->left == 0 && root->right == 0) return min_diff;
	//if (root->left == 0) return min2(min_diff, getMinimumDifferenceRecursive(root->right, root->val));
	//if (root->right == 0) return min2(min_diff, getMinimumDifferenceRecursive(root->left, root->val));
	return min3(min_diff, getMinimumDifferenceRecursive(root->right, root->val), getMinimumDifferenceRecursive(root->left, root->val));
}

int getMinimumDifference(struct TreeNode* root) {
    if (root == NULL) return -1;

	return min2(getMinimumDifferenceRecursive(root->left, root->val), 
				getMinimumDifferenceRecursive(root->right, root->val));
}

void insertBinaryTree(struct TreeNode **tree, int val) {
	if (*tree == NULL) {
		(*tree) = malloc(sizeof(struct TreeNode));
		(*tree)->val = val;
		(*tree)->left = (*tree)->right = 0;
		return;
	} else {
		if (val > (*tree)->val) insertBinaryTree(&(*tree)->right, val);
		else insertBinaryTree(&(*tree)->left, val);
	}
}

void displayBinaryTree(struct TreeNode *tree) {
	if (tree != NULL) {
		displayBinaryTree(tree->left);
		printf("%d, ", tree->val);
		displayBinaryTree(tree->right);
	}
}

int main() {
	struct TreeNode *tree = 0;

	int i, array[] = {236,104,701,227,911};

	printf("%p\n", *(&tree));
	for (i = 0; i < sizeof(array)/sizeof(array[0]); i++) {
		insertBinaryTree(&tree, array[i]);
	}

	displayBinaryTree(tree);

	printf("min = %d\n", getMinimumDifference(tree));
	return 0;
}
