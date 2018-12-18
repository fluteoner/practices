#include <cstddef>
/**
Definition for a binary tree node.*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode* t3;

        if (t1 == NULL && t2 == NULL) return NULL;

        t3 = new TreeNode(0);

        if (t1 != NULL && t2 != NULL) {
            t3->left = mergeTrees(t1->left, t2->left);
            t3->right = mergeTrees(t1->right, t2->right);
            t3->val += t1->val + t2->val;
        } else if (t1 != NULL && t2 == NULL) {
            t3->left = mergeTrees(t1->left, NULL);
            t3->right = mergeTrees(t1->right, NULL);
            t3->val += t1->val;
        } else if (t1 == NULL && t2 != NULL) {
            t3->left = mergeTrees(NULL, t2->left);
            t3->right = mergeTrees(NULL, t2->right);
            t3->val += t2->val;
        } else {
            return NULL;
        }
        return t3;
    }
};

int main() {
    Solution s;
    s.mergeTrees(NULL, NULL);
    return 0;
}
