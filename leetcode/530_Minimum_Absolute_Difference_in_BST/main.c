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

int getMinimumDifferenceRecursive(struct TreeNode* root, int *last_trav) {
	int min_left = INT_MAX, min_mid = INT_MAX, min_right = INT_MAX;

	if (root->left) min_left = getMinimumDifferenceRecursive(root->left, last_trav);

	if (*last_trav != INT_MAX) min_mid = root->val - (*last_trav);
	(*last_trav) = root->val;

	if (root->right) min_right = getMinimumDifferenceRecursive(root->right, last_trav);

	return min2(min_left, min_mid, min_right);
}

int getMinimumDifference(struct TreeNode* root) {
	int last_trav = INT_MAX;
	return getMinimumDifferenceRecursive(root, &last_trav);
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
