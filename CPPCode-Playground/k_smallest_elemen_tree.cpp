// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
// count how many element we process so far

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
    void visit(int& r, int& count, int k, TreeNode* root) {
        if (!root) return;
        visit(r, count, k, root->left);
        ++count;
        if (count == k) {
            // left tree has taken us k - 1 element
            r = root->val;
        }
        visit(r, count, k, root->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        int res = 0, count = 0;
        visit(res, count, k, root);
        return res;
    }
};