// https://leetcode.com/problems/sum-root-to-leaf-numbers/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void visit(int& total, int solu, TreeNode* root) {
        if (!root) return;
        int val = solu * 10 + root->val;
        if (!root->left && !root->right) {
            // is leaf
            total += val;
        } else {
            visit(total, val, root->left);
            visit(total, val, root->right);
        }

    }

    int sumNumbers(TreeNode* root) {
        int total = 0;
        visit(total, 0, root);
        return total;
    }
};
