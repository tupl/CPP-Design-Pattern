// https://leetcode.com/problems/house-robber-iii/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <algorithm>
#include <utility>
#include <fstream>
#include <cmath>
 
class Solution {
public:
    pair<int, int> recur(TreeNode* root) {
        if (!root) return {0, 0}; // with Root, no Root
        int val = root->val;
        int withRoot = val;
        int noRoot = 0;
        auto left_pair = recur(root->left);
        auto right_pair = recur(root->right);
        withRoot += left_pair.second + right_pair.second;
        noRoot += max(left_pair.first, left_pair.second) + max(right_pair.first, right_pair.second);
        return {withRoot, noRoot};
    }

    int rob(TreeNode* root) {
        pair<int, int> res = recur(root);
        return max(res.first, res.second);
    }
};