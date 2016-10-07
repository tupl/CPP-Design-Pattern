// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

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
    // if p, q are in one subtree descendant
    TreeNode* visit(TreeNode* root, TreeNode* p, TreeNode* q) {
        // return lowest common ancestor between two node
        if (!root) return nullptr;
        if (root == p || root == q) {
            return root;
        }
        TreeNode* left = visit(root->left, p, q);
        TreeNode* right = visit(root->right, p, q);
        if (left && right) return root;
        return left ? left : right;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return visit(root, p, q);
    }
};
