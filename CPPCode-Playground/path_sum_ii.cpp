// https://leetcode.com/problems/path-sum-ii/

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
    void visit(vector<vector<int>>& ans, int& total, vector<int>& solu, TreeNode* root, int sum) {
        if (!root) return;
        if (!root->left && !root->right) {
            // is leaf
            if (total + root->val == sum) {
                solu.push_back(root->val);
                ans.push_back(solu);
                solu.pop_back();
            }
        } else {
            total += root->val;
            solu.push_back(root->val);
            visit(ans, total, solu, root->left, sum);
            visit(ans, total, solu, root->right, sum);
            solu.pop_back();
            total -= root->val;
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> solu;
        int total = 0;
        visit(ans, total, solu, root, sum);
        return ans;
    }
};
